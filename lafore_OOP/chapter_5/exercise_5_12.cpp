// exercise_5_12.cpp
// Revise the four-function fraction calculator from Exercise 12, Chapter 4, so
// that it uses functions for each of the four arithmetic operations. They can
// be called fadd(), fsub(), fmul(), and fdiv(). Each of these functions should
// take two arguments of type struct fraction, and return an argument of the
// same type.
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
struct fraction
{
   int numerator;
   int denominator;
};
///////////////////////////////////////////////////////////////////////////////

   const char cDeletionSymbol = '/';
   const char cPlusSymbol = '+';
   const char cMinusSymbol = '-';
   const char cMultiplySymbol = '*';
   const char cEqualSymbol = '=';

void SetFraction(fraction &fr, const char* szText);
void GetFraction(const fraction &fr);

fraction fadd(const fraction &fr1, const fraction &fr2);
fraction fsub(const fraction &fr1, const fraction &fr2);
fraction fmul(const fraction &fr1, const fraction &fr2);
fraction fdel(const fraction &fr1, const fraction &fr2);
void ShowResult(const fraction &fr1, const fraction &fr2, const fraction &res, char cAction);
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
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
      SetFraction(fr1, "first");
      cout << "Specify the operation (+, -, * or /): ";
      cin >> cOperation;
      SetFraction(fr2, "second");
      bool bValidOperation = true;
      switch(cOperation)
      {
         case(cPlusSymbol):
            result =  fadd(fr1, fr2);
            break;
         case (cMinusSymbol):
            result = fsub(fr1, fr2);
            break;
         case (cMultiplySymbol):
            result = fmul(fr1, fr2);
            break;
         case (cDeletionSymbol):
            result = fdel(fr1, fr2);
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
         system("CLS");
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

fraction fadd(const fraction &fr1, const fraction &fr2)
{
   fraction result;
   result.numerator = (fr1.numerator*fr2.denominator + fr2.numerator*fr1.denominator);
   result.denominator = fr1.denominator*fr2.denominator;
   return result;
}

fraction fsub(const fraction &fr1, const fraction &fr2)
{
   fraction result;
   result.numerator = (fr1.numerator*fr2.denominator - fr2.numerator*fr1.denominator);
   result.denominator = fr1.denominator*fr2.denominator;
   return result;
}

fraction fmul(const fraction &fr1, const fraction &fr2)
{
   fraction result;
   result.numerator = fr1.numerator * fr2.numerator;
   result.denominator = fr1.denominator * fr2.denominator;
   return result;
}

fraction fdel(const fraction &fr1, const fraction &fr2)
{
   fraction result;
   result.numerator = fr1.numerator * fr2.denominator;
   result.denominator = fr1.denominator * fr2.numerator;
   return result;
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