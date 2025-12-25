// ptrinc.cpp
// array accessed with pointer
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
   int intarray[5] = {31, 54, 77, 52, 93};                  // array
   int* ptrint;                                             // pointer to int
   ptrint = intarray;
   for (int j=0; j<5; j++)                                  // for each element,
   {                                                        // print value
      cout << *(ptrint++) << endl;
   }
   return 0;
}