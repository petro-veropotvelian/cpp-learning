// vl_app.cpp (exercise 13.1)
// calculates factorials of larger numbers using verylong class
#include "verylong.h"                                                          // verylong header file

int main(int argc, char* argv[])
{
   long long numb1, numb2;
   //verylong fact = 1;                                                          // initialize verylong

   cout << "\n\nEnter number: ";                                               // input a long int
   cin >> numb1;
   //for (j=numb; j>0; j--)
   //{
   //   fact = fact * j;                                                         // factorial is numb * numb -1 *
   //}                                                                           // numb -2 * numb -3 and so on
   verylong vln1(numb1);
   cout << "\n\nEnter another number: ";                                               // input a long int
   cin >> numb2;
   verylong vln2(numb2);
   verylong res = vln1 + vln2;
   vln1.putvl();
   cout << " + ";
   vln2.putvl();
   cout << " = ";
   res.putvl();
   //cout << "You entered: ";
   //vln.putvl();                                                               // display factorial
   cout << endl;
   return 0;
}