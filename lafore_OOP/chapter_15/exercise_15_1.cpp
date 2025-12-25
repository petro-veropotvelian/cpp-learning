// exercise_15_1.cpp
// Write a program that applies the sort() algorithm to an array of floating point values
// entered by the user, and displays the result.
#include <iostream>
#include <algorithm>
using namespace std;

const int ARSIZE = 100;
int main(int argc, char*argv[])
{
   float fitm, farr[ARSIZE];
   char chAnsw;
   int nIndex = 0;
   do
   {
      cout << "Please, specify the " << (nIndex+1) << " item of array: ";
      cin >> fitm;
      farr[nIndex++] = fitm;
      cout << "Do you want to continue (y/n)? ";
      cin >> chAnsw;
   } while (chAnsw!='n' && chAnsw != 'N');

   cout << "\nArray before sorting:\n";
   for (int i=0; i<nIndex; i++)
   {
      cout << farr[i] << ' ';
   }
   cout << endl;
   sort(farr, farr+nIndex);
   cout << "\nArray after sorting:\n";
   for (int i=0; i<nIndex; i++)
   {
      cout << farr[i] << ' ';
   }
   cout << endl;
   return 0;
}