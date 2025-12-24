// exercise_5_2.cpp
// Raising a number n to a power p is the same as multiplying n by itself p
// times. Write a function called power() that takes a double value for n and
// an int value for p, and returns the result as a double value. Use a default
// argument of 2 for p, so that if this argument is omitted, the number n will
// be squared. Write a main() function that gets values from the user to test
// this function.
#include <iostream>
using namespace std;

double power(double dValue, int nPower=2);

int main(int argc, char* argv[])
{
   cout << "Specify a value: ";
   double dVal;
   cin >> dVal;
   cout << "Specify a power: ";
   int nPow;
   cin >> nPow;
   cout << dVal << " raised to a power " << nPow << " is equal ";
   cout << power(dVal, nPow) << endl;
   return 0;
}

//---------------------------------------------------------------------------------------
double power(double dValue, int nPower)
{
   if (nPower<0)
   {
      return -1;
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