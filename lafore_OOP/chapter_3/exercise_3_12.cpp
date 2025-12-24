// exercise_3_12.cpp
// Create a four-function calculator for fractions. (See Exercise 9 in Chapter
// 2, and Exercise 4 in this chapter.) Here are the formulas for the four
// arithmetic operations applied to fractions:
//    Addition: a/b + c/d = (a*d + b*c) / (b*d)
//    Subtraction: a/b - c/d = (a*d - b*c) / (b*d)
//    Multiplication: a/b * c/d = (a*c) / (b*d)
//    Division: a/b / c/d = (a*d) / (b*c)
// The user should type the first fraction, an operator, and a second fraction.
// The program should then display the result and ask whether the user wants
// to continue.
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool InputFraction(int &nFractrionNumerator, int &nFractionDenominator, const char* szFraction);

int main(int argc, char* argv[])
{
   int nFirstFractionNumerator, nFirstFractionDenominator,
   nSecondFractionNumerator, nSecondFractionDenominator,
   nResultFractionNumerator, nResultFractionDenominator;
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
      if (InputFraction(nFirstFractionNumerator, nFirstFractionDenominator, "first"))
      {
         cout << "Specify the operation: ";
         cin >> cOperation;
      }
      if (InputFraction(nSecondFractionNumerator, nSecondFractionDenominator, "second"))
      {
         switch (cOperation)
         {
            case cPlusSymbol:
               nResultFractionNumerator = (nFirstFractionNumerator * nSecondFractionDenominator + nSecondFractionNumerator * nFirstFractionDenominator);
               nResultFractionDenominator = nFirstFractionDenominator * nSecondFractionDenominator;
               break;
            case cMinusSymbol:
               nResultFractionNumerator =(nFirstFractionNumerator * nSecondFractionDenominator - nSecondFractionNumerator * nFirstFractionDenominator);
               nResultFractionDenominator = nFirstFractionDenominator * nSecondFractionDenominator;
               break;
            case cMultiplySymbol:
               nResultFractionNumerator = nFirstFractionNumerator * nSecondFractionNumerator;
               nResultFractionDenominator = nFirstFractionDenominator * nSecondFractionDenominator;
               break;
            case cDeletionSymbol:
               nResultFractionNumerator = nFirstFractionNumerator * nSecondFractionDenominator;
               nResultFractionDenominator = nSecondFractionNumerator * nFirstFractionDenominator;
               break;
            default: 
               cout << "Unknown operation." << endl;
               break;
         }
      }
      cout << nFirstFractionNumerator << cDeletionSymbol << nFirstFractionDenominator << " "
           << cOperation << " " << nSecondFractionNumerator << cDeletionSymbol << nSecondFractionDenominator
           << " = " << nResultFractionNumerator << cDeletionSymbol << nResultFractionDenominator << endl;
      cout << "Do another (y/n)? ";
      bFirst = false;
   } while ((cResponse=getche())!= 'n');
   return 0;
}


bool InputFraction(int &nFractrionNumerator, int &nFractionDenominator, const char* szFraction)
{
   char cDummyChar;
   bool bResult = false;
   do
   {
      cout << "Please, specify the " << szFraction <<" fraction: ";
      cin >> nFractrionNumerator >> cDummyChar >> nFractionDenominator;
      if (nFractionDenominator == 0)
      {
         cout << "Error! You cannot divide by zero!\n";
      }
      else
      {
         bResult = true;
      }
   } while (!bResult);
   
   return bResult;
}