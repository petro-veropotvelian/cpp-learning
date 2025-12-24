// exercise_5_7.cpp
// Start with the power() function of Exercise 2, which works only with type
// double.
// Create a series of overloaded functions with the same name that, in addition
// to double, also work with types char, int, long, and float. Write a main()
// program that exercises these overloaded functions with all argument types.
#include <iostream>
using namespace std;

double power(double dValue, int nPower=2);
float  power(float fValue, int nPower=2);
int    power(int nValue, int nPower=2);
char   power(char cValue, int nPower=2);
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   cout << "Specify a double value: ";
   double dVal;
   cin >> dVal;
   cout << "Specify a power: ";
   int nPow;
   cin >> nPow;
   cout << dVal << " raised to a power " << nPow << " is equal ";
   cout << power(dVal, nPow) << endl;
   float fVal;
   int nPow1;
   cout << "Specify a float value: ";
   cin >> fVal;
   cout << "Specify a power: ";
   cin >> nPow1;
   cout << fVal << " raised to a power " << nPow1 << " is equal ";
   cout << power(fVal, nPow1) << endl;
   int nVal;
   int nPow2;
   cout << "Specify an int value: ";
   cin >> nVal;
   cout << "Specify a power: ";
   cin >> nPow2;
   cout << nVal << " raised to a power " << nPow2 << " is equal ";
   cout << power(nVal, nPow2) << endl;
   char cVal;
   int nPow3;
   cout << "Specify a char value: ";
   cin >> cVal;
   cout << "Specify a power: ";
   cin >> nPow3;
   cout << cVal << " raised to a power " << nPow3 << " is equal ";
   cout << (short )power(cVal, nPow3) << endl;
   return 0;
}

//---------------------------------------------------------------------------------------
double power(double dValue, int nPower)
{
   cout << " [Double overloaded function called] ";
   if (nPower<0)
   {
      return -1.0;
   }
   double dResult = 1.0;
   if (nPower==0)
   {
      return dResult;
   }
   else
   {
      dResult = dValue;
      for (int i=1; i<nPower; ++i)
      {
         dResult*=dValue;
      }
   }
   return dResult;
}
//---------------------------------------------------------------------------------------
float power(float dValue, int nPower)
{
   cout << " [Float overloaded function called] ";
   if (nPower<0)
   {
      return -1.0;
   }
   float dResult = 1.0;
   if (nPower==0)
   {
      return dResult;
   }
   else
   {
      dResult = dValue;
      for (int i=1; i<nPower; ++i)
      {
         dResult*=dValue;
      }
   }
   return dResult;
}
//---------------------------------------------------------------------------------------
int power(int dValue, int nPower)
{
   cout << " [Int overloaded function called] ";
   if (nPower<0)
   {
      return -1;
   }
   int dResult = 1;
   if (nPower==0)
   {
      return dResult;
   }
   else
   {
      dResult = dValue;
      for (int i=1; i<nPower; ++i)
      {
         dResult*=dValue;
      }
   }
   return dResult;
}
//---------------------------------------------------------------------------------------
char power(char dValue, int nPower)
{
   cout << " [Char overloaded function called] ";
   if (nPower<0)
   {
      return -1;
   }
   char dResult = 1;
   if (nPower==0)
   {
      return dResult;
   }
   else
   {
      dResult = dValue;
      for (int i=1; i<nPower; ++i)
      {
         dResult*=dValue;
      }
   }
   return dResult;
}