// ptrstr.cpp
// displays a string with pointer notation
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   void dispstr(char*);                                           // prototype
   char str[] = "Idle people have the least leisure.";

   dispstr(str);                                                  // display the string
   return 0;
}
//----------------------------------------------------------------------------------
void dispstr(char* ps)
{
   while(*ps)                                                     // until null character,
   {
      cout << *ps++;                                              // print characters
   }
   cout << endl;
}