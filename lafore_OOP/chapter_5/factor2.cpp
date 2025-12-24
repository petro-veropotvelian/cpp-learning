// factor2.cpp
// calculates factorials using recursion
#include <iostream>
using namespace std;
unsigned long factfunc(unsigned long);             // declaration

int main(int argc, char* argv[])
{
   int n;                                          // number entered by user
   unsigned long fact;                             // factorials

   cout << "Enter an integer: ";
   cin >> n;
   fact = factfunc(n);
   cout << "Factorial of " << n  << " is " << fact << endl;
   return 0;
}
//---------------------------------------------------------------------------------------
// factfunc()
// calls itself to calculate factorials
unsigned long factfunc(unsigned long n)
{
   if (n > 1)
   {
      return n * factfunc(n-1);                    // self call
   }
   else
   {
      return 1;
   }
}