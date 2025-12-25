// exercise_14_8.cpp
// Add an exception class to the ARROVER3 program in Chapter 8 so that an out-of-bounds
// index will trigger the exception. The catch block can print an error message for the user.
#include <iostream>
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
class safearray
{
private:
   int arr[LIMIT];
public:
   class OutOfBoundsExc
   {};
   int& operator[](int n)                                            // note: return by reference
   {
      if (n<0 || n>= LIMIT)
      {
         throw OutOfBoundsExc();
      }
      return arr[n];
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   safearray sa1;
   try
   {
      for (int j=0; j<LIMIT; j++)                                    // insert elements
      {
         sa1[j] = j*10;                                              // *left" side of equal sign
      }
      for (int j=0; j<LIMIT; j++)                                    // display elements
      {
         int temp = sa1[j];                                          // *right* sign of equal sign
         cout << "Element " << j << " is " << temp << endl;
      }
      cout << "Element " << LIMIT << " is " << sa1[LIMIT] << endl;   // try to print element with out off bounds
   }                                                                 // index
   catch (safearray::OutOfBoundsExc)
   {
      cout << "Exception: index is out of bounds!" << endl;
   }
   return 0;
}