// adswitch.cpp
// demonstrates SWITCH with adventure program
#include <iostream>
#include <conio.h>                              // for getche()
using namespace std;

int main(int argc, char* argv[])
{
   char dir = 'a';
   int x=10, y=10;

   while (dir!='\r')
   {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nEnter direction (n, s, e, w): ";
      dir = getche();                                          // get character
      switch (dir)
      {
         case 'n': y--; break;                              // go to north
         case 's': y++; break;                              // go to south
         case 'e': x++; break;                              // go to east
         case 'w': x--; break;                              // go to west
         case '\r': cout <<"\nExiting\n"; break;              // Enter key_comp
         default: cout <<"\nTry again\n"; break;              // unknown char
      } // end switch
   }// end while
   return 0;
}// end main