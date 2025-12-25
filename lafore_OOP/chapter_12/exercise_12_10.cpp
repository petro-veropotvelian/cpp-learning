// exercise_12_10.cpp
// Add error checking to the extraction (>>) operator of the frac class in Exercise 9. With
// error checking it's probably better to prompt for the first fraction, then for the operator,
// and then for the second fraction, rather than using a single statement as shown in
// Exercise 9. This makes the format more comprehensible when it is interspersed with
// error messages.
// Enter first fraction: 5/0
// Denominator cannot be 0
// Enter fraction again: 5/1
// Enter operator (+, -, *, /): +
// Enter second fraction: one third
// Input error
// Enter fraction again: 1/3
// Answer is --------------------- 16/3
// Do another (y/n)?
// As implied in this sample interaction, you should check for ios error flags and also for
// a denominator of 0. If there's an error, prompt the user to enter the fraction again.
#include <limits>
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
   friend istream& operator >>(istream &is, fraction &frc);
   friend ostream& operator <<(ostream &os, fraction &frc);
};
/////////////////////////////////////////////////////////////////////////////////////////
istream& operator >> (istream &is, fraction &frc)
{
   bool bResult = false;
   do
   {
      is.clear();
      cout << "Please, specify the fraction: ";
      char cDummyChar;
      is.unsetf(ios::skipws);
      is >> frc.n_Numerator;
      if (is.good())
      {
         is.unsetf(ios::skipws);
         is >> cDummyChar;
         if (cDummyChar=='/')
         {
            is.unsetf(ios::skipws);
            is >> frc.n_Denominator;
            if (is.good())
            {
               if (frc.n_Denominator == 0)
               {
                  is.clear();
                  cerr << "\nError! You cannot divide by zero!\nPress <ENTER> to continue..." << endl;
                  is.ignore(numeric_limits<streamsize>::max(),'\n');
                  is.ignore(numeric_limits<streamsize>::max(),'\n');
                  system("CLS");
                  continue;
               }
               else
               {
                  bResult =  true;
                  is.ignore(numeric_limits<streamsize>::max(),'\n');
                  break;
               }
            }
            else
            {
               is.clear();
               cerr << "\nError! Incorrect input of the denominator.\nPress <ENTER> to continue..." << endl;
               is.ignore(numeric_limits<streamsize>::max(),'\n');
               is.ignore(numeric_limits<streamsize>::max(),'\n');
               system("CLS");
               continue;
            }
         }
         else
         {
            is.clear();
            cerr << "\nIt should be a slash (/) symbol beetwen numerator and denominator!\nPress <ENTER> to continue..." << endl;
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            system("CLS");
            continue;
         }
      }
      else
      {
         is.clear();
         cerr << "\nError! Incorrect input of the numerator.\nPress <ENTER> to continue..." << endl;
         is.ignore(numeric_limits<streamsize>::max(),'\n');
         is.ignore(numeric_limits<streamsize>::max(),'\n');
         system("CLS");
         continue;
      }
      is.ignore(numeric_limits<streamsize>::max(),'\n');
   } while (!bResult);
   return is;
}
//-----------------------------------------------------------------------------
ostream& operator << (ostream &os, fraction &frc)
{
   if (frc.n_Numerator != 0 && frc.n_Denominator !=1)
   {
      os << frc.n_Numerator << cDeletionSymbol << frc.n_Denominator;
   }
   else if (frc.n_Denominator == 1)
   {
      os << frc.n_Numerator;
   }
   else
   {
      os << 0;
   }
   return os;
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
      cin >> fr1;
      if (fr1 == fraction(0, 1))
      {
         cout << "Fraction should be different than 0/1!"<< endl;
         cin.get();
         continue;
      }
      cout << "Specify the operation (+, -, * or /): ";
      cin >> cOperation;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin >> fr2;
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
         cout << fr1;
         cout <<" " << cOperation << " ";
         cout << fr2;
         cout << " " << cEqualSymbol << " ";
         result.lowterms();
         cout << result;
         cout << endl;
      }
      cout << "Do another (y/n)? ";
      bFirst = false;
   } while ((cResponse=getche())!= 'n');
   return 0;
}
