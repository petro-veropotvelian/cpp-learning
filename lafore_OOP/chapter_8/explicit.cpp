// explicit.cpp
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                             // English Distance class
{
private:
   const float MTF;                                        // meters to feet
   int feet;
   float inches;
public:                                                    // constructor (no args)
   Distance(): feet(0), inches(0.0), MTF(3.280833F)
   {}
                                                           // EXPLICIT one-arg constructor
   explicit Distance(float meters) : MTF(3.280833F)
   {
      float fltfeet = MTF * meters;                       // convert to float feet
      feet = int(fltfeet);                                // feet is integer part
      inches = 12 * (fltfeet - feet);                     // inches is what's left
   }

   void showdist()                                      // display distance
   {
      cout << feet << "\'-" << inches << "\"";
   }

   operator float() const                         // conversion operator
   {                                                   // converts Distance to meters
      float fracfeet = inches/12;                      // convert the inches
      fracfeet += static_cast<float>(feet);            // add the feet
      return fracfeet/MTF;                             // convert to meters
   }
};
////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   void fancyDist(Distance);                          // declaration
   Distance dist1(2.35F);                             // uses 1-arg constructor to 
                                                      // convert meters to Distance
   //Distance dist = 2.35F;                           // ERROR if constructor is explicit
   cout << "\ndist1 =";
   dist1.showdist();

   float mtrs = 3.0F;
   cout << "\ndist1 ";
   //fancyDist(mtrs);                                // ERROR is constructor is explicit

   return 0;
}
//-----------------------------------------------------------------------------
void fancyDist(Distance d)
{
   cout << "(in feet and inches) = ";
   d.showdist();
   cout << endl;
}