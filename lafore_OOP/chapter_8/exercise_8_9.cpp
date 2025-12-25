// exercise_8_9.cpp
// Augment the safearay class in the ARROVER3 program in this chapter so that
// the user can specify both the upper and lower bound of the array (indexes
// running from 100 to 200, for example). Have the overloaded subscript
// operator check the index each time the array is accessed to ensure that it
// is not out of bounds. You'll need to add a twoargument constructor that
// specifies the upper and lower bounds. Since we have not yet learned how to
// allocate memory dynamically, the member data will still be an array that
// starts at 0 and runs up to 99, but perhaps you can map the indexes for the
// safearay into different indexes in the real int array. For example, if the
// client selects a range from 100 to 175, you could map this into the range
// from arr[0] to arr[75].
#include <iostream>
#include <process.h>                                                           // for exit()
#include <windows.h>
using namespace std;

// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
class safearray
{
private:
   int arr[LIMIT];
   int nLowerBound;
   int nUpperBound;
   int nDiff;
   int nModulus;
public:
   safearray(int lowerbound, int upperbound);
   int& operator[](int n)                                            // not: return by reference
   {
      if (n+nModulus<nLowerBound || n+nModulus> nUpperBound)
      {
         cout << "\nIndex out of bounds";
         exit(1);
      }
      return arr[n+nModulus];
   }
};
//-----------------------------------------------------------------------------
safearray::safearray(int lowerbound, int upperbound)
{
   nDiff = upperbound - lowerbound;
   nLowerBound = 0;
   nUpperBound = nLowerBound + nDiff;
   nModulus = nLowerBound - lowerbound;
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   int nLowBound, nUpBound;
   do
   {
      cout << "Enter the lower bound of array: ";
      cin >> nLowBound;
      if (nLowBound < 0)
      {
         system("CLS");
         cout << "The lower bound should not be less than 0" << endl;
         cin.get();
         continue;
      }
      cout << "Enter the upper bound of array: ";
      cin >> nUpBound;
      if (nUpBound < nLowBound || (nUpBound-nLowBound) > LIMIT)
      {
         system("CLS");
         cout << "The upper bound should not be less than "<< nLowBound <<" and greater than "<<nLowBound + LIMIT << endl;
         cin.get();
         nLowBound = -1;
         continue;
      }
   } while (nLowBound < 0 && (( nUpBound-nLowBound) > LIMIT));
   int nMinutes;
   safearray sa1(nLowBound, nUpBound);
   for (int j=nLowBound; j<nUpBound; j++)                                       // insert elements
   {
      sa1[j] = j*10;                                                 // *left" side of equal sign
   }
   for (int j=nLowBound; j<nUpBound; j++)                                       // display elements
   {
      int temp = sa1[j];                                             // *right* sign of equal sign
      cout << "Element " << j << " is " << temp << endl;
   }
   cout << "Elemetn " << nUpBound+2 << " is " << sa1[nUpBound+2] << endl;
   return 0;
}