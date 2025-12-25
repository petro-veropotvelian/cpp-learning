// exercise_7_8.cpp
// Another weakness of C++ is that it does not automatically check array
// indexes to see whether they are in bounds. (This makes array operations
// faster but less safe.) We can use a class to create a safe array that checks
// the index of all array accesses.
// Write a class called safearay that uses an int array of fixed size (call it
// LIMIT) as its only data member. There will be two member functions. The
// first, putel(), takes an index number and an int value as arguments and
// inserts the int value into the array at the index. The second, getel(),
// takes an index number as an argument and returns the int value of the
// element with that index.
//    safearay sa1; // define a safearay object
//    int temp = 12345; // define an int value
//    sa1.putel(7, temp); // insert value of temp into array at index 7
//    temp = sa1.getel(7); // obtain value from array at index 7
// Both functions should check the index argument to make sure it is not less
// than 0 or greater than LIMIT-1. You can use this array without fear of
// writing over other parts of memory.
// Using functions to access array elements doesn't look as eloquent as using
// the [] operator. In Chapter 8 we'll see how to overload this operator to
// make our safearay class work more like built-in arrays.
#include <iostream>
using namespace std;

const int LIMIT = 100;
class safearay
{
private:
   int arr[LIMIT];
public:
   safearay()
   {}
   ~safearay()
   {}
   void putel(const int indx, const int elem);
   int getel(const int indx);
};
//---------------------------------------------------------------------------------------
void safearay::putel(const int indx, const int elem)
{
   if (indx >=0 && indx <= (LIMIT - 1))
   {
      arr[indx] = elem;
   }
   else
   {
      cout << "Error! Array index must be >= 0 and <= " << LIMIT-1 << endl;
   }
}
//---------------------------------------------------------------------------------------
int safearay::getel(const int indx)
{
   if (indx >=0 && indx <= (LIMIT - 1))
   {
      return arr[indx];
   }
   else
   {
      cout << "Error! Array index must be >= 0 and <= " << LIMIT-1 << endl;
      return -1;
   }
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   safearay sa1;
   int temp = 12345;
   sa1.putel(7, temp);
   temp = sa1.getel(7);
   cout << "7-the element of sa1 = " << temp;
   return 0;
}