// exercise_14_10.cpp
// There are various philosophies about when to use exceptions. Refer to the
// ENGLERR program from Chapter 12, "Streams and Files." Should user-input
// errors be exceptions? For this exercise, let's assume so. Add an exception
// class to the Distance class in that program.
// (See also the XDIST and XDIST2 examples in this chapter.) Throw an exception
// in all the places where ENGLERR displayed an error message. Use an argument
// to the exception constructor to report where the error occurred and the
// specific cause of the error (inches not a number, inches out of range, and
// so on). Also, throw an exception when an error is found within the isint()
// function (nothing entered, too many digits, nondigit character, integer out
// of range). Question: If it throws exceptions, can isint() remain an
// independent function?
// You can insert both the try block and the catch block within the do loop so
// that after an exception you go back to the top of the loop, ready to ask the
// user for more input.
// You might also want to throw an exception in the two-argument constructor,
// in case the programmer initializes a Distance value with its inches member
// out of range.

// input checking with English Distance class
#include <iostream>
#include <string>
#include <cstdlib>                                                   // for atoi(), atof()
using namespace std;
//int isFeet(string);                                                  // declaration
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                                       // English Distance class
{
private:
   int feet;
   float inches;
   void isFeet(string);                                                  // declaration
public:
   enum ExcepType
   {
      feetOutOfRange = 0,
      inchesOutOfRange,
      outOfRangeValue,
      wrongSymbols,
      tooLongInput,
      nothingEntered,
      inputError
   };
   class DistanceException
   {
   public:
      string str_message;
      DistanceException(ExcepType ET)
      {
         switch (ET)
         {
            case ExcepType::feetOutOfRange:
               str_message = "Feet are out of range: feet must be >= 0 and < 1000\n";
               break;
            case ExcepType::inchesOutOfRange:
               str_message = "Inches are out of range: values must be between 0.0 and 11.99\n";
               break;
            case ExcepType::outOfRangeValue:
               str_message = "Out of range: the value should be greater than -999.0 and less than 999.0\n";
               break;
            case ExcepType::wrongSymbols:
               str_message = "Wrong input: only digits or minus are allowed\n";
               break;
            case ExcepType::tooLongInput:
               str_message = "Wrong input: only 5 symbols are allowed\n";
               break;
            case ExcepType::nothingEntered:
               str_message = "Wrong input: nothing entered\n";
               break;
            case ExcepType::inputError:
               str_message = "Wrong input: Input error\n";
               break;
            default:
               str_message = "Unknown error!\n";
               break;
         };
      }
   };
   Distance()                                                        // constructor (no args)
   {   feet = 0;   inches = 0.0;   }
   Distance(int ft, float in)                                        // construct (two args)
   {
      if (ft < -999 || ft > 999)                                                     // is it out of range
      {
         throw Distance::DistanceException(Distance::ExcepType::outOfRangeValue);    // if so, not correct feet
      }
      if (in >= 12.0 || in < 0.0)
      {
         throw Distance::DistanceException(Distance::ExcepType::inchesOutOfRange);
      }
      feet = ft;
      inches = in;
   }
   void showdist()                                                   // display distance
   {   cout << feet <<"\'-" << inches << '\"';   }
   void getdist();                                                   // get length from user
};
//---------------------------------------------------------------------------------------
void Distance::getdist()                                             // get length from user
{
   string instr;                                                     // for input string;
   while (true)
   {
      try
      {
         cout <<"\n\nEnter feet: ";
         cin.unsetf(ios::skipws);                                       // do not skip white space
         cin >> instr;                                                  // get feet as a string
         isFeet(instr);                                                 // is it a correct value?
         cin.ignore(10, '\n');                                          // eat chars, including newline
         feet = atoi(instr.c_str());                                    // convert to integer
         break;                                                         // break out of 'while'
      }
      catch (Distance::DistanceException DeX)
      {
         cin.ignore(10, '\n');
         cout << "Exception! " << DeX.str_message << endl;
         cin.clear();
      }
   }  // end while feet
   while (true)                                                         // cycle until inches are right
   {
      try
      {
         cout << "Enter inches: ";
         cin.unsetf(ios::skipws);                                                    // do not skip white space
         cin >> inches;                                                             // get inches (type float)
         if (inches >= 12.0 || inches < 0.0)
         {
            throw Distance::DistanceException(Distance::ExcepType::inchesOutOfRange);
         }
         if (cin.good())                                                            // check for cin failure
         {                                                                          // (most commonly a non-digit)
            cin.ignore(10, '\n');                                                   // eat the newline
            break;                                                                  // input is OK, exit 'while'
         }
         else
         {
            cin.clear();                                                            // error; clear the error state
            throw Distance::DistanceException(Distance::ExcepType::inputError);
         }
      }
      catch (Distance::DistanceException DeX)
      {
         cin.ignore(10, '\n');
         cout << "Exception! " << DeX.str_message << endl;
         cin.clear();
      }
   }  // end while inches
}
//---------------------------------------------------------------------------------------
void Distance::isFeet(string str)
{
   int slen = str.size();                                                           // get length
   if (slen == 0)
   {
      cin.clear();
      throw Distance::DistanceException(Distance::ExcepType::nothingEntered);
   }
   else if (slen > 5)
   {
      throw Distance::DistanceException(Distance::ExcepType::tooLongInput);
   }
   for (int j=0; j<slen; j++)                                                       // check each character
   {                                                                                // if not a digit or minus
      if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
      {
         throw Distance::DistanceException(Distance::ExcepType::wrongSymbols);      // string is not correct feet
      }
   }
   double n = atof(str.c_str());                                                    // convert to double
   if (n < -999.0 || n > 999.0)                                                     // is it out of range
   {
      throw Distance::DistanceException(Distance::ExcepType::outOfRangeValue);      // if so, not correct feet
   }
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Distance d;                                                       // make a Distance object;
   char ans;
   do
   {
      d.getdist();                                                   // get its value from user
      cout << "\nDistance = ";
      d.showdist();                                                  // display it
      cout << "\nDo another (y/n)? ";
      cin >> ans;
      cin.ignore(10, '\n');                                          // eat chars, including newline
   } while (ans != 'n' && ans != 'N');                               // cycle until 'n' ('N')
   return 0;
}