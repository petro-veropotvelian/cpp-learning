// constObj.cpp
// const Distance objects
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
};
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
   const Distance football(300, 0);
   cout << "football = ";
   football.showdist();
   cout << endl;
   return 0;
}
