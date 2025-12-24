// exercise_2_1.cpp
// Assuming there are 7.481 gallons in a cubic foot, write a program that asks
// the user to enter a number of gallons, and then displays the equivalent in
// cubic feet.
#include <iostream>
using namespace std;
int main(int argc, char*argv[])
{
   const double dGallondsInCubicFoot = 7.481;
   double dGallons, dCubicFeet;
   cout << "Please, specify number of gallons: ";
   cin >> dGallons;
   dCubicFeet = dGallons / dGallondsInCubicFoot;
   cout <<"\n" << dGallons <<" gallons is equal to " << dCubicFeet << " cubic feet "<<endl;
   return 0;
}