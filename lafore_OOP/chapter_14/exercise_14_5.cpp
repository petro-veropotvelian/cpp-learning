// exercise_14_5.cpp
// Create a function called amax() that returns the value of the largest element
// in an array.
// The arguments to the function should be the address of the array and its size.
// Make this function into a template so it will work with an array of any numerical
// type. Write a main() program that applies this function to arrays of various types.
#include <iostream>
using namespace std;

const int ARSIZE = 5;

//-----------------------------------------------------------------------------
template <class cType>
cType amax(cType* arr, const int nArsize)
{
   cType maxVal = arr[0];
   for (int i=0; i<nArsize; i++)
   {
      if (arr[i]>maxVal)
      {
         maxVal = arr[i];
      }
   }
   return maxVal;
}
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
   int intArr[] = { 20, -1, 34, 27, 5 };
   float fltArr[] = { 13.5, 21.3, -0.34, 28.78, 25.32 };
   long lonArr[] = { 1234506L, 7503212L, 7023102L, 1234670L, 8902341L };
   cout << "Maximum value of the intArr = " << amax(intArr, ARSIZE) << endl;
   cout << "Maximum value of the fltArr = " << amax(fltArr, ARSIZE) << endl;
   cout << "Maximum value of the lonArr = " << amax(lonArr, ARSIZE) << endl;
   return 0;
}