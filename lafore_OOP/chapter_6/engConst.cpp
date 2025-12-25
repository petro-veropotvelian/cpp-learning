// engConst.cpp
// const member functions and const arguments to member functions
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

   void get_dist()                                       // get length from user
   {
      cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;
   }

   void showdist() const                                  // display distance
   {
      cout << feet << "\'-" << inches << "\"";
   }

   Distance add_dist(const Distance&) const;              // add
};
//---------------------------------------------------------------------------------------
// add this distance to t2, return the sum
Distance Distance::add_dist(const Distance &d2) const
{
   Distance temp;                                     // temporary variable
   temp.inches = inches + d2.inches;                  // add the inches
   if (temp.inches>=12.0)                             // if total exceeds 12.0
   {                                                  // then decrease inches
      temp.inches -= 12.0;                            // by 12.0 and 
      temp.feet =1;                                   // increase feet
   }                                                  // by 1
   temp.feet += feet + d2.feet;                       // add the feet
   return temp;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
   Distance dist1, dist3;                             // define two length
   Distance dist2(11, 6.25);                          // define and initialize dist2

   dist1.get_dist();                                  // get dist1 from user
   dist3 = dist1.add_dist(dist2);                     // dist3 = dist1 + dist2
                                                      // display all length
   cout << "\ndist1 = ";
   dist1.showdist();
   cout << "\ndist2 = ";
   dist2.showdist();
   cout << "\ndist3 = ";
   dist3.showdist();
   return 0;
}
