// exercise_10_9.cpp
// Let's say that you need to store 100 integers so that they're easily
// accessible. However, let's further assume that there's a problem: The
// memory in your computer is so fragmented that the largest array that you
// can use holds only 10 integers. (Such problems actually arise, although
// usually with larger memory objects.) You can solve this problem by defining
// 10 separate int arrays of 10 integers each, and an array of 10 pointers to
// these arrays. The int arrays can have names like a0, a1, a2, and so on. The
// address of each of these arrays can be stored in the pointer array of type
// int*, which can have a name like ap (for array of pointers). You can then
// access individual integers using expressions like ap[j][k], where j steps
// through the pointers in ap and k steps through individual integers in each
// array. This looks as if you're accessing a two-dimensional array, but it's
// really a group of one-dimensional arrays.
// Fill such a group of arrays with test data (say the numbers 0, 10, 20, and so
//  on up to 990). Then display the data to make sure it’s correct.
#include <iostream>
using namespace std;
const int ARSIZE =10;
int main(int argc, char* argv[])
{
   int a0[ARSIZE] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   int a1[ARSIZE] = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91};
   int a2[ARSIZE] = {2, 12, 22, 32, 42, 52, 62, 72, 82, 92};
   int a3[ARSIZE] = {3, 13, 23, 33, 43, 53, 63, 73, 83, 93};
   int a4[ARSIZE] = {4, 14, 24, 34, 44, 54, 64, 74, 84, 94};
   int a5[ARSIZE] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
   int a6[ARSIZE] = {6, 16, 26, 36, 46, 56, 66, 76, 86, 96};
   int a7[ARSIZE] = {7, 17, 27, 37, 47, 57, 67, 77, 87, 97};
   int a8[ARSIZE] = {8, 18, 28, 38, 48, 58, 68, 78, 88, 98};
   int a9[ARSIZE] = {9, 19, 29, 39, 49, 59, 69, 79, 89, 99};
   int* ap[ARSIZE] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};
   for (int i=0; i<ARSIZE; i++)
   {
      for (int j=0; j<ARSIZE; j++)
      {
         cout << ap[i][j] << " ";
      }
      cout << "\n";
   }
   
   return 0;
}