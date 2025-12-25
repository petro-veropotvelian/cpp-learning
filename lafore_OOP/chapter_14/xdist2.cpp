// xdist2.cpp
// exceptions with arguments
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                                       // English Distance class
{
private:
   int feet;
   float inches;
public:
//---------------------------------------------------------------------------------------
   class InchesEx                                                    // exception class
   {
   public:
      string origin;                                                 // for name of routine
      float iValue;                                                  // for faulty inches value
      InchesEx(string org, float inch)                                  // 2-arg constructor
      {
         origin = org;                                                // store string
         iValue = inch;                                                // store inches
      }
   };
//---------------------------------------------------------------------------------------
   Distance() : feet(0), inches(0.0)                                 // constructor (no args)
   {}
//---------------------------------------------------------------------------------------
   Distance(int ft, float in)                                        // constructor (two args)
   {
      if (in >= 12.0)                                                // if inches too big
      {
         throw InchesEx("2-arg constructor", in);                    // throw exception
      }
      feet = ft;
      inches = in;
   }
//---------------------------------------------------------------------------------------
   void getdist()                                                    // get length from user
   {
      cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;
      if (inches >=12.0)                                             // if inches too big,
      {
         throw InchesEx("getdist() function", inches);               // throw exception
      }
   }
//---------------------------------------------------------------------------------------
   void showdist()                                       // display distance
   {
      cout << feet << "\'-" << inches <<'\"';
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   try
   {
      Distance dist1(17, 3.5);                                       // 2-arg constructor
      Distance dist2;                                                // no-arg constructor
      dist2.getdist();                                               // get distance from user
      // display distances
      cout << "\ndist1 = ";
      dist1.showdist();
      cout << "\ndist2 = ";
      dist2.showdist();
   }
   catch (Distance::InchesEx ix)                                     // exception handler
   {
      cout << "\nInitialization error in " << ix.origin
           << "\nInches value of " << ix.iValue 
           << " is too large.";
   }
   cout << endl;
   return 0;
}