// arrover1.cpp
// creates safe array (index values are checked before access)
// uses separate put and get functions
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
   void putel(int n, int elvalue)                                    // set value of element
   {
      if (n<0 || n>=LIMIT)
      {
         cout << "\nIndex out of bounds";
         exit(1);
      }
      arr[n] = elvalue;
   }
   int getel(int n) const                                            // get value of element
   {
      if (n<0 || n>=LIMIT)
      {
         cout <<"\nIndex out of bounds";
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
      sa1.putel(j, j*10);
   }
   for (int j=0; j<LIMIT; j++)                                       // display elements
   {
      int temp = sa1.getel(j);
      cout << "Element " << j << " is " << temp << endl;
   }
   return 0;
}