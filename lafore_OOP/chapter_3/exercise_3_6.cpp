// exercise_3_6.cpp
// Modify the FACTOR program in this chapter so that it repeatedly asks for a
// number and calculates its factorial, until the user enters 0, at which point
// it terminates. You can enclose the relevant statements in FACTOR in a while
// loop or a do loop to achieve this effect.
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   unsigned int numb;
   do
   {
      unsigned long fact = 1;                            // long for larger numbers
      cout << "Enter a positive number (0 to exit): ";
      cin >> numb;                                       // get number
      if (numb > 0)
      {
         for (int j=numb; j>0; j--)                      // multiply 1 by
         {
            fact *= j;
         }
         cout << "Factorial is " << fact << endl;
      }
      else
      {
         cout << "Bye!" << endl;
      }
   } while (numb!=0);
   return 0;
}