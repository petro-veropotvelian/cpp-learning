// advenand.cpp
// demonstrates AND logical operator
#include <iostream>
#include <conio.h>         // for getche()
#include <process.h>       // for exit()
using namespace std;

int main(int argc, char* argv[])
{
   char dir='a';
   int x=10, y=10;

   while (dir != '\r')
   {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nEnter direction (n, s, e, w): ";
      dir = getche();               // get direction
      switch (dir)
      {
         case 'n': y--; break;            // update coordinates
         case 's': y++; break;
         case 'e': x++; break;
         case 'w': x--; break;
      }
      if (x==7 && y==11)                  // if x is 7 and y is 11
      {
         cout << "\nYou found the treasure!\n";
         exit(0);                         // exit from program
      }
   } // end while
   return 0;
} // end main