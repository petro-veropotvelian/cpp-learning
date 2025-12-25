// englref.cpp
// dereferencing the pointer returned by new
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                           // English Distance class
{
private:
   int feet;
   float inches;
public:
   void getdist()                                        // get lenght from user
   {
      cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;
   }
   void showdist()                                       // display distance
   {
      cout << feet << "\'-" << inches <<'\"';
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   Distance& dist = *(new Distance);                     // create Distance object
                                                         // alias as "dist"
   dist.getdist();                                       // access object members
   dist.showdist();                                      // with  dot  operator

   return 0;
}