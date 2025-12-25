// englio.cpp
// overloaded << and >> operators
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class Distance                                                       // English Distance class
{
private:
   int feet;
   float inches;
public:
   Distance():feet(0), inches(0.0)                                   // constructor (no args)
   {
   }
   Distance(int ft, float in) : feet(ft), inches(in)                 // constructor (two args)
   {
   }
   friend istream& operator>>(istream& s, Distance& d);
   friend ostream& operator<<(ostream& s, Distance& d);
};
//-----------------------------------------------------------------------------
istream& operator>>(istream& s, Distance& d)                         // get Distance from
{                                                                    // user using 
   cout << "\nEnter feet: ";                                         // overloaded >> operator
   s >> d.feet;
   cout << "\nEnter inches: ";
   s >> d.inches;
   return s;
}
//-----------------------------------------------------------------------------
ostream& operator<<(ostream& s, Distance& d)                         // display Distance
{                                                                    // using overloaded
   s << d.feet << "\'-" << d.inches << '\"';                         // << operator
   return s;
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Distance dist1, dist2;                                            // define Distances
   Distance dist3(11, 6.25);                                         // define, initialize dist3
   cout << "\nEnter two values of distances: ";
   cin >> dist1 >> dist2;                                            // get values fro user
   cout << "\ndist1 = "<< dist1 << "\ndist2 = " << dist2;            // display distances
   cout << "\ndist3 = " << dist3 << endl;
   return 0;
}
