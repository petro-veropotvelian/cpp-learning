// arrover2.cpp
// creates safe array (index values are checked before access)
// uses one access() function for both put and get
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
   int& access(int n)                                                // not: return by reference
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
      sa1.access(j) = j*10;                                           // *left" side of equal sign
   }
   for (int j=0; j<LIMIT; j++)                                       // display elements
   {
      int temp = sa1.access(j);                                      // *right* sign of equal sing
      cout << "Element " << j << " is " << temp << endl;
   }
   return 0;
}