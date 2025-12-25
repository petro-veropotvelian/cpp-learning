// exercise_14_1.cpp
// Write a template function that returns the average of all the elements of an array.
// The arguments to the function should be the array name and the size of the array 
// (type int).
// In main(), exercise the function with arrays of type int, long, double, and char.
#include <iostream>
using namespace std;

const int ARRSIZE = 10;
template <class cType>
cType get_average(cType* array, int size)
{
   cType sum = 0;
   for (int i=0; i<size; i++)
   {
      sum+=array[i];
   }
   return (cType)sum/size;
}
//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   int intArr[] = {91, 45, 132, 180, 35, 404, 21, 504, 465, 337};
   long longArr[] = {1000001, 2000002, 3000003, 4000004, 5000005, 6000006, 770077, 8000008, 9000009, 1010101};
   double doubleArr [] = {2.5, 7.34, 24.52, 4.47, 5.57, 8.89, 99.12, 832.31, 1023.98, 123.536};
   char charArr[] = {1, 5, 7, 9, 11, 20, 27, 14, 19, 8};
   cout << "\nThe average value of a intArray = "    << get_average(intArr, ARRSIZE);
   cout << "\nThe average value of a longArray = "   << get_average(longArr, ARRSIZE);
   cout << "\nThe average value of a doubleArray = " << get_average(doubleArr, ARRSIZE);
   cout << "\nThe average value of a charArray = "   << (int)get_average(charArr, ARRSIZE);
   cout << endl;
   return 0;
}