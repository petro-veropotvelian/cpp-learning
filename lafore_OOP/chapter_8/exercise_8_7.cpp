// exercise_8_7.cpp
// Modify the fraction class in the four-function fraction calculator from
// Exercise 11 in Chapter 6 so that it uses overloaded operators for addition,
// subtraction, multiplication, and division. (Remember the rules for fraction
// arithmetic in Exercise 12 in Chapter 3, "Loops and Decisions.") Also
// overload the == and != comparison operators, and use them to exit from the
// loop if the user enters 0/1, 0/1 for the values of the two input fractions.
// You may want to modify the lowterms() function so that it returns the value
// of its argument reduced to lowest terms. This makes it more useful in the
// arithmetic functions, where it can be applied just before the answer is
// returned.
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
const char cDeletionSymbol = '/';
const char cPlusSymbol     = '+';
const char cMinusSymbol    = '-';
const char cMultiplySymbol = '*';
const char cEqualSymbol    = '=';
/////////////////////////////////////////////////////////////////////////////////////////
class fraction
{
private:
   int n_Numerator;
   int n_Denominator;
public:
   fraction()
   : n_Numerator(0), n_Denominator(0)
   {}
   fraction(int nNum, int nDen)
   : n_Numerator(nNum), n_Denominator(nDen)
   {}
   fraction(const fraction& frc)
   {
      n_Numerator = frc.n_Numerator;
      n_Denominator = frc.n_Denominator;
   }
   void SetFraction();
   void GetFraction();
   fraction operator+(fraction frc) const;
   fraction operator-(fraction frc) const;
   fraction operator*(fraction frc) const;
   fraction operator/(fraction frc) const;
   void lowterms();
   bool operator==(fraction frc) const;
   bool operator!=(fraction frc) const;
};

/////////////////////////////////////////////////////////////////////////////////////////
void fraction::SetFraction()
{
   bool bResult = false;
   do
   {
      cout << "Please, specify the fraction: ";
      char cDummyChar;
      cin >> n_Numerator >> cDummyChar >> n_Denominator;
      if (n_Denominator == 0)
      {
         system("CLS");
         cout << "Error! You cannot divide by zero!\n";
      }
      else
      {
         bResult = true;
      }
   } while (!bResult);
}
//---------------------------------------------------------------------------------------
void fraction::GetFraction()
{
   if (n_Numerator!= 0 && n_Denominator!=1)
   {
      cout << n_Numerator << cDeletionSymbol << n_Denominator;
   }
   else if (n_Denominator ==1)
   {
      cout << n_Numerator;
   }
   else
   {
      cout << 0;
   }
}
//---------------------------------------------------------------------------------------
fraction fraction::operator+(fraction frc) const
{
   fraction result;
   result.n_Numerator   = (this->n_Numerator * frc.n_Denominator + frc.n_Numerator * this->n_Denominator);
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::operator-(fraction frc) const
{
   fraction result;
   result.n_Numerator   = (this->n_Numerator * frc.n_Denominator - frc.n_Numerator * this->n_Denominator);
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::operator*(fraction frc) const
{
   fraction result;
   result.n_Numerator   = this->n_Numerator * frc.n_Numerator;
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::operator/(fraction frc) const
{
   fraction result;
   result.n_Numerator   = this->n_Numerator * frc.n_Denominator;
   result.n_Denominator = this->n_Denominator * frc.n_Numerator;
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
void fraction::lowterms()                          // change ourself to lowest terms
{
   long tnum, tden, temp, gcd;
   tnum = labs(n_Numerator);                               // use non-negative copies
   tden = labs(n_Denominator);                               // (needs cmath)
   if (tden == 0)                                  // check for n/0
   {
      cout << "Illegal fraction: division by 0";
      exit(1);
   }
   else if (tnum == 0)                               // check for 0/n
   {
      n_Numerator = 0;
      n_Denominator = 1;
      return;
   }
   // this whil loop find the gcd  of thum and tden
   while (tnum!=0)
   {
      if (tnum < tden)                             // ensure numerator larger
      {
         temp = tnum;                              // swap them
         tnum = tden;
         tden = temp;
      }
      tnum = tnum - tden;                          // substract them
   }
   gcd = tden;                                     // this is greatest common divisor
   n_Numerator = n_Numerator / gcd;                                // divide both num and den by gcd
   n_Denominator = n_Denominator / gcd;                                // to reduce frac to lowest terms
}
//---------------------------------------------------------------------------------------
bool fraction::operator==(fraction frc) const
{
   fraction tmp(n_Numerator, n_Denominator);
   tmp.lowterms();
   frc.lowterms();
   return (tmp.n_Numerator == frc.n_Numerator && tmp.n_Denominator == frc.n_Denominator);
}
//---------------------------------------------------------------------------------------
bool fraction::operator!=(fraction frc) const
{
   fraction tmp(n_Numerator, n_Denominator);
   tmp.lowterms();
   frc.lowterms();
   return (tmp.n_Numerator != frc.n_Numerator || tmp.n_Denominator!=frc.n_Denominator);
}
//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   char cOperation;
   char cResponse = 'y';
   bool bFirst = true;
   do
   {
      system("CLS");
      if (!bFirst)
      {
         cout << endl;
      }
      fraction fr1, fr2, result;
      fr1.SetFraction();
      if (fr1 == fraction(0, 1))
      {
         cout << "Fraction should be different than 0/1!"<< endl;
         cin.get();
         continue;
      }
      cout << "Specify the operation (+, -, * or /): ";
      cin >> cOperation;
      fr2.SetFraction();
      if (fr2 == fraction(0, 1))
      {
         cout << "Fraction should be different than 0/1!"<< endl;
         cin.get();
         continue;
      }
      bool bValidOperation = true;
      switch(cOperation)
      {
         case(cPlusSymbol):
            result =  fr1 + fr2;
            break;
         case (cMinusSymbol):
            result = fr1 - fr2;
            break;
         case (cMultiplySymbol):
            result = fr1 * fr2;
            break;
         case (cDeletionSymbol):
            result = fr1 / fr2;
            break;
         default: 
            cout << "Error! Unknown operation. Press <ENTER> to continue..." << endl;
            bValidOperation = false;
            cin.get();
            system("CLS");
         break;
      }
      if (bValidOperation)
      {
         //ShowResult(fr1, fr2, result, cOperation);
         fr1.GetFraction();
         cout <<" " << cOperation << " ";
         fr2.GetFraction();
         cout << " " << cEqualSymbol << " ";
         result.lowterms();
         result.GetFraction();
         cout << endl;
      }
      cout << "Do another (y/n)? ";
      //cin >> cResponse;
      bFirst = false;
   } while ((cResponse=getche())!= 'n');
   return 0;
}
