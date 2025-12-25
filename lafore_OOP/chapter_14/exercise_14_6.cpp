// exercise_14_6.cpp
// Start with the safearay class from the ARROVER3 program in Chapter 8. Make 
// this class into a template, so the safe array can store any kind of data. 
// In main(), create safe arrays of at least two different types, and store 
// some data in them.
#include <iostream>
#include <process.h>                                                 // for exit()
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
template <class cType>
class safearray
{
private:
   cType arr[LIMIT];
public:
   cType& operator[](int n)                                            // not: return by reference
   {
      if (n<0 || n>= LIMIT)
      {
         cout << "\nIndex out of bounds";
         exit(1);
      }
      return arr[n];
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   safearray<int> sa1;
   cout << "safearray<int>:\n";
   for (int j=0; j<LIMIT; j++)                                       // insert elements
   {
      sa1[j] = j*10;                                                 // *left" side of equal sign
   }
   for (int j=0; j<LIMIT; j++)                                       // display elements
   {
      int temp = sa1[j];                                             // *right* sign of equal sign
      cout << "Element " << j << " is " << temp << endl;
   }
   cout << endl;
   safearray<float> sa2;
   cout << "safearray<float>:\n";
   for (int i=0; i<LIMIT; i++)
   {
      sa2[i] = (float)(3.14 * i);
   }
   for (int i=0; i<LIMIT; i++)
   {
      float ftmp = sa2[i];
      cout << "Element "<< i << " is "<< ftmp << endl;
   }
   cout << endl;
   return 0;
}