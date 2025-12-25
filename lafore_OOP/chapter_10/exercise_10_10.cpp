// exercise_10_10.cpp
// As presented, Exercise 9 is rather inelegant because each of the 10 int
// arrays is declared in a different program statement, using a different name.
// Each of their addresses must also be obtained using a separate statement.
// You can simplify things by using new, which allows you to allocate the
// arrays in a loop and assign pointers to them at the same time:
//    for(j=0; j<NUMARRAYS; j++)     // allocate NUMARRAYS arrays
//       *(ap+j) = new int[MAXSIZE]; // each MAXSIZE ints long
// Rewrite the program in Exercise 9 to use this approach. You can access the
// elements of the individual arrays using the same expression mentioned in
// Exercise 9, or you can use pointer notation: *(*(ap+j)+k).
// The two notations are equivalent.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
using namespace std;

const int MAXSIZE =10;
const int MINSIZE = 1;
int main(int agrc, char* argv[])
{
   int nARRAYS;
   srand (time(NULL));
   do
   {
      cout << "Specify number of arrays: ";
      cin >> nARRAYS;
      if (nARRAYS >= MAXSIZE || nARRAYS < MINSIZE)
      {
         system("CLS");
         cout << "Amount of arrays should be from "<< MINSIZE << " to " << (MAXSIZE - 1) << endl;
      }
   } while (nARRAYS >= MAXSIZE || nARRAYS < MINSIZE);
   int** pp;
   pp = new int* [nARRAYS];
   for (int i=0; i<nARRAYS; i++)
   {
      pp[i] = new int[MAXSIZE];
   }
   for (int i=0; i<nARRAYS; i++)
   {
      for (int j=0; j<MAXSIZE; j++)
      {
         pp[i][j] = rand() % (nARRAYS * MAXSIZE);
      }
   }
   for (int i=0; i<nARRAYS; i++)
   {
      for (int j=0; j<MAXSIZE; j++)
      {
         cout << pp[i][j] << " ";
      }
      cout << "\n";
   }
   for (int i=0; i<nARRAYS; i++)
   {
      delete [] pp[i];
   }
   delete []pp;
   return 0;
}