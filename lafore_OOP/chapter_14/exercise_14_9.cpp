// exercise_14_9.cpp
// Modify the exception class in Exercise 8 (adapted from ARROVER3) so that
// the error message in the catch block reports the value of the index that
// caused the exception.
#include <iostream>
#include <string>
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
class safearray
{
private:
   int arr[LIMIT];
public:
   class OutOfBoundsExc
   {
   public:
      string message;
      int indx;
      OutOfBoundsExc(string strMes, int nIndx)
      : message(strMes), indx(nIndx)
      {}
   };
   int& operator[](int n)                                            // note: return by reference
   {
      if (n<0 || n>= LIMIT)
      {
         throw OutOfBoundsExc("is out of bounds!", n);              // throw exception
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
   catch (safearray::OutOfBoundsExc obexc)
   {
      cout << "Index "<< obexc.indx<< " " << obexc.message << endl;
   }
   return 0;
}