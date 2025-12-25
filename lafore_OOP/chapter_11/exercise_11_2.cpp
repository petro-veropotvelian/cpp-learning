// exercise_11_2.cpp
// In the Distance class, as shown in the FRENGL and FRISQ examples in this
// chapter, create an overloaded * operator so that two distances can be
// multiplied together. Make it a  friend function so that you can use such
// expressions as
//    Wdist1 = 7.5 * dist2;
// You'll need a one-argument constructor to convert floating-point values into
// Distance values. Write a main() program to test this operator in several
// ways.
// friend square() function for Distance
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
   friend Distance operator*(Distance, Distance);       // friend function
};
//---------------------------------------------------------------------------------------
Distance operator*(Distance d1, Distance d2)
{
   float floatfeet1 = d1.feet + d1.inches/12;                   // convert feet and inches
   float floatfeet2 = d2.feet + d2.inches/12;                   // to float
   float multfeet = floatfeet1 * floatfeet2;
   return Distance(multfeet);
}

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   Distance dist1(3, 6.0);                                // two-arg constructor (3'-6")
   Distance dist2(4, 3.0);

   Distance result = dist1 * dist2;                       // result of multiplicatione
   dist1.showdist();
   cout <<" * ";
   dist2.showdist();
   cout << " = ";
   result.showdist();
   cout << endl;
   return 0;
}