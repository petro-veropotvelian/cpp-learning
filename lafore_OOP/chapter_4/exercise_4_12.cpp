// exercise_4_12.cpp
// Revise the four-function fraction calculator program of Exercise 12 in
// Chapter 3 so that each fraction is stored internally as a variable of type
// struct fraction, as discussed in Exercise 8 in this chapter.
#include <iostream>
#include <conio.h>
using namespace std;
const char cDeletionSymbol = '/';
////////////////////////////////////////////////////////////////////////////////////////////////////
struct fraction
{
   int numerator;
   int denominator;
};
///////////////////////////////////////////////////////////////////////////////
void SetFraction(fraction &fr, const char* szText);
void GetFraction(const fraction &fr);
void AddFractions(const fraction &fr1, const fraction &fr2, fraction &result);
void SubtractFractions(const fraction &fr1, const fraction &fr2, fraction &result);
void MultiplyFractions(const fraction &fr1, const fraction &fr2, fraction &result);
void DivideFractions(const fraction &fr1, const fraction &fr2, fraction &result);
void ShowResult(const fraction &fr1, const fraction &fr2, const fraction &res, char cAction);
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char cOperation;
   const char cDeletionSymbol = '/';
   const char cPlusSymbol = '+';
   const char cMinusSymbol = '-';
   const char cMultiplySymbol = '*';
   const char cEqualSymbol = '=';
   char cResponse = 'y';
   bool bFirst = true;
   do
   {
      if (!bFirst)
      {
         cout << endl;
      }
      fraction fr1, fr2, result;
      SetFraction(fr1, "first");
      cout << "Specify the operation (+, -, * or /): ";
      cin >> cOperation;
      SetFraction(fr2, "second");
      bool bValidOperation = true;
      switch(cOperation)
      {
         case(cPlusSymbol):
            AddFractions(fr1, fr2, result);
            break;
         case (cMinusSymbol):
            SubtractFractions(fr1, fr2, result);
            break;
         case (cMultiplySymbol):
            MultiplyFractions(fr1, fr2, result);
            break;
         case (cDeletionSymbol):
            DivideFractions(fr1, fr2, result);
         default: 
            cout << "Error! Unknown operation." << endl;
            bValidOperation = false;
         break;
      }
      if (bValidOperation)
      {
         ShowResult(fr1, fr2, result, cOperation);
      }
      cout << "Do another (y/n)? ";
      //cin >> cResponse;
      bFirst = false;
   } while ((cResponse=getche())!= 'n');
   return 0;
}
void SetFraction(fraction &fr, const char* szText)
{
   bool bResult = false;
   do
   {
      cout << "Please, specify the " << szText << " fraction: ";
      char cDummyChar;
      cin >> fr.numerator >> cDummyChar >> fr.denominator;
      if (fr.denominator == 0)
      {
         cout << "Error! You cannot divide by zero!\n";
      }
      else
      {
         bResult = true;
      }
   } while (!bResult);
}

void GetFraction(const fraction &fr)
{
   cout << fr.numerator << cDeletionSymbol << fr.denominator;
}
void AddFractions(const fraction &fr1, const fraction &fr2, fraction &result)
{
   result.numerator = (fr1.numerator*fr2.denominator + fr2.numerator*fr1.denominator);
   result.denominator = fr1.denominator*fr2.denominator;
}

void SubtractFractions(const fraction &fr1, const fraction &fr2, fraction &result)
{
   result.numerator = (fr1.numerator*fr2.denominator - fr2.numerator*fr1.denominator);
   result.denominator = fr1.denominator*fr2.denominator;
}

void MultiplyFractions(const fraction &fr1, const fraction &fr2, fraction &result)
{
   result.numerator = fr1.numerator * fr2.numerator;
   result.denominator = fr1.denominator * fr2.denominator;
}

void DivideFractions(const fraction &fr1, const fraction &fr2, fraction &result)
{
   result.numerator = fr1.numerator * fr2.denominator;
   result.denominator = fr1.denominator * fr2.numerator;
}

void ShowResult(const fraction &fr1, const fraction &fr2, const fraction &res, char cAction)
{
   GetFraction(fr1);
   cout << " " << cAction << " ";
   GetFraction(fr2);
   cout << " = ";
   GetFraction(res);
   cout << endl;
}