// exercise_8_3.cpp
// Modify the time class from Exercise 3 in Chapter 6 so that instead of a
// function add_time() it uses the overloaded + operator to add two times.
// Write a program to test this class.
#include <iostream>
#include <windows.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class ptime
{
private:
   int hours;
   int minutes;
   int seconds;
public:
   ptime()
   : hours(0), minutes(0), seconds(0)
   {}
   ptime(const int hrs, const int min, const int sec)
   : hours(hrs), minutes(min), seconds(sec)
   {}
   void show_time() const;
   ptime operator+(ptime t2) const;
   void set_time();
};
//---------------------------------------------------------------------------------------
void ptime::show_time() const
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
ptime ptime::operator+(ptime t2) const
{
   ptime tmp;
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

void ptime::set_time()
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
int main(int argc, char* argv[])
{
   ptime t1(0, 15, 45);
   ptime t2(1, 45, 16);
   ptime t3 = t1 + t2;
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