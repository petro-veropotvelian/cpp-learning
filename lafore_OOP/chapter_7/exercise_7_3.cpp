// exercise_7_3.cpp
// Write a program that calculates the average of up to 100 English distances
// input by the user. Create an array of objects of the Distance class, as in
// the ENGLARAY example in this chapter. To calculate the average, you can
// borrow the add_dist() member function from the ENGLCON example in Chapter 6.
// You'll also need a member function that divides a Distance value by an
// integer. Here's one possibility:
//    void Distance::div_dist(Distance d2, int divisor)
//    {
//       float fltfeet = d2.feet + d2.inches/12.0;
//       fltfeet /= divisor;
//       feet = int(fltfeet);
//       inches = (fltfeet-feet) * 12.0;
//    }
#include <iostream>
#include <stdio.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
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

   void showdist()                                      // display distance
   {
      cout << feet << "\'-" << inches << "\"";
   }

   void add_dist(Distance, Distance);                  // declaration
   void div_dist(Distance d2, int divisor);
};
//---------------------------------------------------------------------------------------
                                                      // add length d2 and d3
void Distance::add_dist(Distance d2, Distance d3)
{
   inches = d2.inches + d3. inches;                   // add the inches
   feet = 0;                                          // (for possible carry)
   if (inches>=12.0)                                  // if total exceeds 12.0
   {                                                  // then decrease inches
      inches -= 12.0;                                 // by 12.0 and 
      feet++;                                         // increase feet
   }                                                  // by 1
   feet += d2.feet + d3.feet;                         // add the feet
}
//---------------------------------------------------------------------------------------
void Distance::div_dist(Distance d2, int divisor)
{
   float fltfeet = d2.feet + d2.inches/12.0;
   fltfeet /= divisor;
   feet = int(fltfeet);
   inches = (fltfeet - feet) * 12.0;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Distance dist[100];
   int n = 0;
   char cAnsw;
   cout << endl;
   Distance total;
   do
   {
      cout << "Enter distance number " << n+1;
      dist[n].get_dist();
      total.add_dist(total, dist[n]);
      n++;
      cout << "Enter another (y/n)?: ";
      cin >> cAnsw;
   } while (cAnsw != 'n' && cAnsw != 'N');
   for (int j=0; j<n; j++)       // display all distances
   {
      cout << "\nDistance number " << j + 1 << " is ";
      dist[j].showdist();
   }
   cout << endl;
   cout << "Total distance: ";
   total.showdist();
   cout << endl;
   Distance avrg;
   avrg.div_dist(total, n);
   cout << "Average distance: ";
   avrg.showdist();
   cout << endl;
   return 0;
}