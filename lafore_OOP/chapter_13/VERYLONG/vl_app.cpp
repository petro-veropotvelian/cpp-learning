// vl_app.cpp
// calculates factorials of larger numbers using verylong class
#include "verylong.h"                                                          // verylong header file

int main(int argc, char* argv[])
{
   unsigned long numb, j;
   verylong fact = 1;                                                          // initialize verylong

   cout << "\n\nEnter number: ";                                               // input a long int
   cin >> numb;
   for (j=numb; j>0; j--)
   {
      fact = fact * j;                                                         // factorial is numb * numb -1 *
   }                                                                           // numb -2 * numb -3 and so on
   cout << "Factorial is ";
   fact.putvl();                                                               // display factorial
   cout << endl;
   return 0;
}