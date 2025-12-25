// exercise_10_1.cpp
// Write a program that reads a group of numbers from the user and places them
// in an array of type float. Once the numbers are stored in the array, the
// program should average them and print the result. Use pointer notation
// wherever possible.
#include <iostream>
using namespace std;

const int ARSIZE = 128;

int main(int argc, char* arg[])
{
   float flarr[ARSIZE];
   char cResp;
   float fAverage, fSumm;
   int nIndx = 0;
   do
   {
      cout << "Specify " << (nIndx + 1) << " element of the array: ";
      cin >> flarr[nIndx];
      fSumm += flarr[nIndx];
      cout << "Enter another element (y/n)? ";
      cin >> cResp;
      nIndx++;
   }
   while (cResp=='y' || cResp=='Y');
   fAverage = fSumm/ nIndx;
   cout << "The average value is: " << fAverage << endl;
   return 0;
}