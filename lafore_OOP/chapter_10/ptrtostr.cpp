// ptrtostr.cpp
// an array of pointers to strings
#include <iostream>
using namespace std;
const int DAYS = 7;                                                  // number of pointers in array

int main(int argc, char*argv[])
{
   char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday",            // array of pointers to char
                           "Wednesday", "Thursday",
                           "Friday", "Saturday"};

   for (int j=0; j<DAYS; j++)                                        // display every string
   {
      cout << arrptrs[j] << endl;
   }

   return 0;
}