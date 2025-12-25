// exercise_15_7.cpp
// We showed the four-argument version of the accumulate() algorithm in
// the PLUSAIR example. Rewrite this example using the three-argument version.
#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>                                                   // for accumulate()
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class airtime
{
private:
   int hours;                                                        // 0 to 23
   int minutes;                                                      // 0 to 59
public:
   airtime() : hours(0), minutes(0)                                  // default constructor
   {}
   airtime(int h, int m) : hours(h), minutes(m)                      // 2-arg constructor
   {}
   void display() const                                              // output to screen
   {
      cout << hours << ':' << minutes;
   }
   void get()                                                        // input from user
   {
      char dummy;
      cout << "\nEnter airtime (fomat 12:59): ";
      cin >> hours >> dummy >> minutes;
   }
   airtime operator+(const airtime right) const                      // overloaded + operator
   {
      int temph = hours + right.hours;                               // add members
      int tempm = minutes + right.minutes;
      if (tempm>=60)                                                 // check for carry
      {
         temph++;
         tempm -= 60;
      }
      return airtime(temph, tempm);                                  // return sum
   }
   bool operator==(const airtime& at2) const                         // overloaded == oparator
   {
      return (hours == at2.hours) && (minutes == at2.minutes);
   }
   bool operator<(const airtime& at2) const                          // overloaded < operator
   {
      return (hours < at2.hours) || 
             (hours==at2.hours && minutes < at2.minutes);
   }
   bool operator!=(const airtime& at2) const                         // overloaded != operator
   {
      return !(*this==at2);
   }
   bool operator>(const airtime& at2) const                          // overloaded > operator
   {
      return !(*this<at2) && !(*this==at2);
   }
};
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char*argv[])
{
   char answer;
   airtime temp, sum;
   list <airtime> airlist;                                           // list of airtimes
   do
   {
      temp.get();                                                    // get airtimes from user
      airlist.push_back(temp);
      cout << "Enter another(y/n)?";
      cin >> answer;
   } while (answer!='n');
   sum = accumulate(airlist.begin(), airlist.end(), airtime(0,0));   // sum all the airtimes
   cout << "\nsum = ";
   sum.display();                                                    // display sum
   cout << endl;
   return 0;
}