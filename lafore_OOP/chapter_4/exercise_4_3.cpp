// exercise_4_3.cpp
// Create a structure called Volume that uses three variables of type Distance
// (from the ENGLSTRC example) to model the volume of a room. Initialize a
// variable of type Volume to specific dimensions, then calculate the volume it
// represents, and print out the result.
// To calculate the volume, convert each dimension from a Distance variable to
// a variable of type float representing feet and fractions of a foot, and then
// multiply the resulting three numbers.
#include <iostream>
using namespace std;
const int nInchesPerFoot = 12;
/////////////////////////////////////////////////////////////
struct Distance                        // English distance
{
   int feet;
   float inches;
};
////////////////////////////////////////////////////////////
struct Volume                          // Volume
{
   Distance length;
   Distance width;
   Distance height;
};
int main(int argc, char* argv[])
{
   Volume vol;
   cout << "Specify length (feet, inches): ";
   cin >> vol.length.feet >> vol.length.inches;
   cout << "Specify width (feet, inches): ";
   cin >> vol.width.feet >> vol.width.inches;
   cout << "Specify height (feet, inches): ";
   cin >> vol.height.feet >> vol.height.inches;
   float fLenght = vol.length.feet + float(vol.length.inches/nInchesPerFoot);
   float fWidth = vol.width.feet + float(vol.width.inches/nInchesPerFoot);
   float fHeight = vol.height.feet + float(vol.height.inches/nInchesPerFoot);
   cout << "The volume is " << fLenght * fWidth * fHeight  << " cubic feet" << endl;
   return 0;
}