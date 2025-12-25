// ptrnote.cpp
// array accessed with pointer notation
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
   int intarray[5] = {31, 54, 77, 52, 93};                  // array
   for (int j=0; j<5; j++)                                  // for each element,
   {                                                        // print value
      cout << *(intarray+j) << endl;
   }
   return 0;
}