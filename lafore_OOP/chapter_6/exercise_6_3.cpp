// exercise_6_3.cpp
// Create a class called time that has separate int member data for hours,
// minutes, and seconds. One constructor should initialize this data to 0, and
// another should initialize it to fixed values. Another member function should
// display it, in 11:59:59 format. The final member function should add two
// objects of type time passed as arguments.
// A main() program should create two initialized time objects (should they be
// const?) and one that isn't initialized. Then it should add the two
// initialized values together, leaving the result in the third time variable.
// Finally it should display the value of this third variable.
// Make appropriate member functions const.
#include <iostream>
#include <windows.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class time
{
private:
   int hours;
   int minutes;
   int seconds;
public:
   time():hours(0), minutes(0), seconds(0)
   {}
   time(const int hrs, const int min, const int sec)
   : hours(hrs), minutes(min), seconds(sec)
   {}
   void show_time() const;
   time add_time(const time &t2);
   void set_time();
};
//---------------------------------------------------------------------------------------
void time::show_time() const
{
   cout << hours << ":";
   if (minutes < 10)
   {
      cout << "0";
   }
   cout << minutes << ":";
   if (seconds < 10)
   {
      cout << "0";
   }
   cout << seconds;
}
//---------------------------------------------------------------------------------------
time time::add_time(const time &t2)
{
   time tmp;
   if (seconds + t2.seconds >= 60)
   {
      tmp.seconds += (seconds +t2.seconds)/60;
      tmp.minutes++;
   }
   else
   {
      tmp.seconds = seconds +t2.seconds;
   }
   if (tmp.minutes + minutes + t2.minutes >= 60)
   {
      tmp.minutes = (tmp.minutes + minutes + t2.minutes)/60;
      tmp.hours++;
   }
   else
   {
      tmp.minutes += (minutes + t2.minutes);
   }
   tmp.hours += (hours + t2.hours);
   return tmp;
}
void time::set_time()
{
   int nSeconds;
   do
   {
      cout << "Enter the number of seconds: ";
      cin >> nSeconds;
      if (nSeconds >= 60 || nSeconds < 0)
      {
         system("CLS");
         cout << "Amount of seconds should be from 0 to 59" << endl;
      }
      else
      {
         seconds = nSeconds;
      }
   } while (nSeconds >= 60 || nSeconds < 0);
   int nMinutes;
   do
   {
      cout << "Enter the number of minutes: ";
      cin >> nMinutes;
       if (nMinutes >= 60 || nMinutes < 0)
      {
         system("CLS");
         cout << "Amount of minutes should be from 0 to 59" << endl;
      }
      else
      {
         minutes = nMinutes;
      }
   } while (nMinutes >= 60 || nMinutes < 0);
   int nHours;
   do
   {
      cout << "Enter the number of hours: ";
      cin >> nHours;
      if (nHours < 0)
      {
         system("CLS");
         cout << "Amount of hours should not be less than 0" << endl;
      }
      else
      {
         hours = nHours;
      }
   } while (nHours < 0);
}
/////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
int main(int argc, char* argv[])
{
   time t1(0, 15, 45);
   time t2(1, 45, 16);
   time t3 = t1.add_time(t2);
   cout << "t1 = ";
   t1.show_time();
   cout << endl;
   cout << "t2 = ";
   t2.show_time();
   cout << endl;
   cout << "t3 = ";
   t3.show_time();
   cout << endl;
   return 0;
}