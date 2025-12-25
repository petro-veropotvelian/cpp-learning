// exercise_8_1.cpp
// To the Distance class in the ENGLPLUS program in this chapter, add an
// overloaded - operator that subtracts two distances. It should allow
// statements like dist3=dist1-dist2;.
// Assume that the operator will never be used to subtract a larger number from
// a smaller one (that is, negative distances are not allowed).
// overloaded '+' operator add two Distances
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                             // English Distance class
{
private:
   int feet;
   float inches;
public:                                                    // constructor (no args)
   Distance(): feet(0), inches(0.0)
   {}
                                                          // constructor (two args)
   Distance(int ft, float in) : feet(ft), inches(in)
   {}

   void getdist()                                        // get length from user
   {
      cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;
   }

   void showdist()                                      // display distance
   {
      cout << feet << "\'-" << inches << "\"";
   }

   Distance operator+ (Distance) const;                 // add 2 distances
   Distance operator- (Distance) const;                 // subtract 2 distances
};
//---------------------------------------------------------------------------------------
                                                      // add this Distance to d2
Distance Distance::operator+(Distance d2) const       // return sum
{
   int f = feet + d2.feet;                            // add the feet
   float i = inches + d2.inches;                      // add the inches
   if (i>=12.0)                                       // of total exceeds 12.0
   {                                                  // then decrease inches
      i -= 12.0;                                      // by 12.0 and
      f++;                                            // increase feet by 1
   }                                                  // return a temporary Distance
   return Distance(f, i);                             // initialized to sum
}
//---------------------------------------------------------------------------------------
                                                      // substract Distance d2 from this
Distance Distance::operator-(Distance d2) const       // Distance, return differenc
{
   int f = feet - d2.feet;                            // subtract  the feet
   float i = inches - d2.inches;                      // subtract the inches
   if (i<0)                                           // if difference is less than 0
   {                                                  // then substract inches from 12.0
      i += 12.0;
      f--;                                            // decrease feet by 1
   }                                                  // return a temporary Distance
   return Distance(f, i);                             // initialized to sum
}
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
   Distance dist1, dist3, dist4;                      // define distances
   dist1.getdist();                                   // get dist1 from user

   Distance dist2(11, 6.25);                          // define and initialize dist2

   dist3 = dist1 + dist2;                             // single '+' operator
   dist4 = dist1 - dist2;                             // single '-' operators
                                                      // display all length
   cout << "dist1 = ";
   dist1.showdist();
   cout << endl;
   cout << "dist2 = ";
   dist2.showdist();
   cout << endl;
   cout << "dist3 = ";
   dist3.showdist();
   cout << endl;
   cout << "dist4 = ";
   dist4.showdist();
   cout << endl;
   return 0;
}
