// platters.cpp
// demonstrates SWITCH statement
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   int speed;                          // turntable speed

   cout << "\nEnter 33, 45, or 78: ";
   cin >> speed;                       // user enters speed
   switch (speed)
   {
      case 33:                         // user entered 33
         cout << "LP album\n";
         break;
      case 45:                         // user entered 45
         cout << "Single selection\n";
         break;
      case 78:                         // user entered 78
         cout << "Obsoleter format\n";
         break;
      
   }
   return 0;
}