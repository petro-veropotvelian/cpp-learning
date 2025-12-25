// exercise_14_7.cpp
// Start with the frac class and the four-function fraction calculator of Exercise 7
// in Chapter 8. Make the frac class into a template so it can be instantiated using
// different data types for the numerator and denominator. These must be integer
// types, which pretty much restricts you to char, short, int, and long (unless you
// develop an integer type of your own). In main(), instantiate a class frac<char>
// and use it for the four-function calculator.
// Class frac<char> will take less memory than frac<int>, but won't be able to
// handle large fractions.
#include <iostream>
#include <string>
#include <limits>
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
template <class csType>
class fraction
{
private:
   csType n_Numerator;
   csType n_Denominator;
   void checkRange(long long value) const
   {
      if (value < std::numeric_limits<csType>::min() || 
          value > std::numeric_limits<csType>::max())
      {
         string strError = "Value " + std::to_string(value) + " is out of range for the " + 
                            typeid(csType).name() + " type.";
         throw RangeException(strError.c_str());
      }
   }
public:
   class RangeException
   {
   public:
      string str_message;
      RangeException()
      : str_message("")
      {}
      RangeException(const char* szMessage)
      : str_message(szMessage)
      {}
   };
   fraction()
   : n_Numerator(0), n_Denominator(0)
   {}
   fraction(long long nNum, long long nDen)
   {
      checkRange(nNum);
      n_Numerator = static_cast<csType>(nNum);
      checkRange(nDen);
      n_Denominator = static_cast<csType>(nDen);
   }

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
template <class csType>
void fraction<csType>::SetFraction()
{
   bool bResult = false;
   long long lNumerator, lDenominator;
   do
   {
      cout << "Please, specify the fraction: ";
      char cDummyChar;
      cin >> lNumerator >> cDummyChar >> lDenominator;
      cin.get();
      checkRange(lNumerator);
      n_Numerator = static_cast<csType>(lNumerator);
      checkRange(lDenominator);
      n_Denominator = static_cast<csType>(lDenominator);
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
template <class csType>
void fraction<csType>::GetFraction()
{
   if (n_Numerator!= 0 && n_Denominator!=1)
   {
      cout << (int)n_Numerator << cDeletionSymbol <<(int) n_Denominator;
   }
   else if (n_Denominator ==1)
   {
      cout << (int)n_Numerator;
   }
   else
   {
      cout << 0;
   }
}
//---------------------------------------------------------------------------------------
template <class csType>
fraction<csType> fraction<csType>::operator+(fraction frc) const
{
   fraction<csType> result;
   long long interimNum, interimDenom;
   interimNum = ((long long)this->n_Numerator * (long long)frc.n_Denominator + (long long)frc.n_Numerator * (long long)this->n_Denominator);
   checkRange(interimNum);
   result.n_Numerator = static_cast<csType>(interimNum);
   interimDenom = (long long)this->n_Denominator * (long long)frc.n_Denominator;
   checkRange(interimDenom);
   result.n_Denominator = static_cast<csType>(interimDenom);
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
template <class csType>
fraction<csType> fraction<csType>::operator-(fraction frc) const
{
   fraction<csType> result;
   long long interimNum, interimDenom;
   interimNum = ((long long)this->n_Numerator * (long long)frc.n_Denominator - (long long)frc.n_Numerator * (long long)this->n_Denominator);
   checkRange(interimNum);
   result.n_Numerator = static_cast<csType>(interimNum);
   interimDenom = (long long)this->n_Denominator * (long long)frc.n_Denominator;
   checkRange(interimDenom);
   result.n_Denominator = static_cast<csType>(interimDenom);
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
template <class csType>
fraction<csType> fraction<csType>::operator*(fraction frc) const
{
   fraction<csType> result;
   long long interimNum, interimDenom;
   interimNum = (long long)this->n_Numerator * (long long)frc.n_Numerator;
   checkRange(interimNum);
   result.n_Numerator = static_cast<csType>(interimNum);
   interimDenom = (long long)this->n_Denominator * (long long)frc.n_Denominator;
   checkRange(interimDenom);
   result.n_Denominator = static_cast<csType>(interimDenom);
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
template <class csType>
fraction<csType> fraction<csType>::operator/(fraction frc) const
{
   fraction<csType> result;
   long long interimNum, interimDenom;
   interimNum = (long long)this->n_Numerator * (long long)frc.n_Denominator;
   checkRange(interimNum);
   result.n_Numerator = static_cast<csType>(interimNum);
   interimDenom = (long long)this->n_Denominator * (long long)frc.n_Numerator;
   checkRange(interimDenom);
   result.n_Denominator = static_cast<csType>(interimDenom);
   result.lowterms();
   return result;
}
//---------------------------------------------------------------------------------------
template <class csType>
void fraction<csType>::lowterms()                                    // change ourself to lowest terms
{
   csType tnum, tden, temp, gcd;
   tnum = abs(n_Numerator);                                          // use non-negative copies
   tden = abs(n_Denominator);                                        // (needs cmath)
   if (tden == 0)                                                    // check for n/0
   {
      cout << "Illegal fraction: division by 0";
      exit(1);
   }
   else if (tnum == 0)                                               // check for 0/n
   {
      n_Numerator = 0;
      n_Denominator = 1;
      return;
   }
   // this whil loop find the gcd  of thum and tden
   while (tnum!=0)
   {
      if (tnum < tden)                                               // ensure numerator larger
      {
         temp = tnum;                                                // swap them
         tnum = tden;
         tden = temp;
      }
      tnum = tnum - tden;                                            // substract them
   }
   gcd = tden;                                                       // this is greatest common divisor
   n_Numerator = n_Numerator / gcd;                                  // divide both num and den by gcd
   n_Denominator = n_Denominator / gcd;                              // to reduce frac to lowest terms
}
//---------------------------------------------------------------------------------------
template <class csType>
bool fraction<csType>::operator==(fraction frc) const
{
   fraction tmp(n_Numerator, n_Denominator);
   tmp.lowterms();
   frc.lowterms();
   return (tmp.n_Numerator == frc.n_Numerator && tmp.n_Denominator == frc.n_Denominator);
}
//---------------------------------------------------------------------------------------
template <class csType>
bool fraction<csType>::operator!=(fraction frc) const
{
   fraction tmp(n_Numerator, n_Denominator);
   tmp.lowterms();
   frc.lowterms();
   return (tmp.n_Numerator != frc.n_Numerator || tmp.n_Denominator!=frc.n_Denominator);
}
//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   try
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
         fraction<char> fr1, fr2, result;
         fr1.SetFraction();
         if (fr1 == fraction<char>(0, 1))
         {
            cout << "Fraction should be different than 0/1!"<< endl;
            cin.get();
            continue;
         }
         cout << "Specify the operation (+, -, * or /): ";
         cin >> cOperation;
         cin.get();
         fr2.SetFraction();
         if (fr2 == fraction<char>(0, 1))
         {
            cout << "Fraction should be different than 0/1!"<< endl;
            cin.get();
            continue;
         }
         bool bValidOperation = true;
         switch (cOperation)
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
            fr1.GetFraction();
            cout <<" " << cOperation << " ";
            fr2.GetFraction();
            cout << " " << cEqualSymbol << " ";
            result.lowterms();
            result.GetFraction();
            cout << endl;
         }
         cout << "Do another (y/n)? ";
         bFirst = false;
      } while ((cResponse=getche())!= 'n');
   }
   catch (fraction<char>::RangeException RE)
   {
      cout << RE.str_message << endl;
   }
   return 0;
}