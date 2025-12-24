// sqrt.cpp
// demonstrates sqrt() library function
#include <iostream>      // for cout, etc.
#include <cmath>        // for sqrt()
using namespace std;

int main()
{
   double number, answer;        // sqrt() requires double type

   cout << "Enter a number: ";
   cin >> number;                // get the number
   answer = sqrt(number);        // find square root
   cout << "Square root is "
   << answer << endl;            // display it
   return 0;
}