// exercise_7_4.cpp
// Start with a program that allows the user to input a number of integers, and
// then stores them in an int array. Write a function called maxint() that goes
// through the array, element by element, looking for the largest one. The
// function should take as arguments the address of the array and the number of
// elements in it, and return the index number of the largest element. The
// program should call this function and then display the largest element and
// its index number. (See the SALES program in this chapter.)
#include <iostream>
using namespace std;
const int SIZE = 6;
void maxint(double arr[SIZE]);
int main(int argc, char* argv[])
{

   double array[SIZE];
   cout << "Enter 6 values of the array:\n";
   for (int j=0; j<SIZE; j++)
   {
      cin >>array[j];
   }
   maxint(array);
   return 0;
}

void maxint(double arr[SIZE])
{
   double max = arr[0];
   int indx = 0;
   for (int j=0; j<SIZE; j++)
   {
      if (arr[j] > max)
      {
         indx = j;
         max = arr[j];
      }
   }
   cout << "The largest element of the array: " << arr[indx] << endl;
   cout << "It's index = " << indx << endl;
}