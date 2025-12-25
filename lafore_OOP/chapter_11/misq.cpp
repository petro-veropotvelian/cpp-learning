// misq.cpp
// member square() function for Distance
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                           // English Distance class
{
private:
   int feet;
   float inches;
public:
   Distance() : feet(0), inches(0.0)                     // constructor (no args)
   {}
   Distance(float fltfeet)                               // convert float to Distance
   {
      feet = static_cast<int>(fltfeet);
      inches = 12*(fltfeet-feet);                        // inches is what's left
   }
   Distance(int ft, float in)                            // constructor (two args)
   {
      feet = ft;
      inches = in;
   }
   void showdist()                                       // display distance
   {
      cout << feet << "\'-" << inches <<'\"';
   }
   float square();                                       // member function
};
//---------------------------------------------------------------------------------------
float Distance::square()                                 // return square of 
{                                                        // this Distance
   float fltfeet = feet + inches/12;                     // convert to float
   float feetsqrd = fltfeet * fltfeet;                   // find the square
   return feetsqrd;                                      // return square feet
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   Distance dist(3, 6.0);                                // two-arg constructor (3'-6")
   float sqft;
   sqft = dist.square();                                 // return square of dist
                                                         // display distance and square
   cout << "\nDistance = ";
   dist.showdist();
   cout << "\nSquare = " << sqft << " square feet\n";
   return 0;
}