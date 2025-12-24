// factor.cpp
// calculates factorials, demonstarates FOR loop
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   unsigned int numb;
   unsigned long fact = 1;                      // long for larger numbers

   cout << "Enter a number: ";
   cin >> numb;                                 // get number
   for (int j = numb; j>0; j--)                 // multiply 1 by
   {
      fact *=  j;                               // numb, numb-1, ..., 2, 1
   }
   cout << "Factorial is " << fact << endl;
   return 0;
}