// arrover3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get
#include <iostream>
#include <process.h>                                                           // for exit()
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
class safearray
{
private:
   int arr[LIMIT];
public:
   int& operator[](int n)                                            // not: return by reference
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
   safearray sa1;
   for (int j=0; j<LIMIT; j++)                                       // insert elements
   {
      sa1[j] = j*10;                                                 // *left" side of equal sign
   }
   for (int j=0; j<LIMIT; j++)                                       // display elements
   {
      int temp = sa1[j];                                             // *right* sign of equal sign
      cout << "Element " << j << " is " << temp << endl;
   }
   return 0;
}