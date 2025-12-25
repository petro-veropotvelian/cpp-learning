// exercise_8_5.cpp
// Augment the time class referred to in Exercise 3 to include overloaded
// increment (++) and decrement (--) operators that operate in both prefix and
// postfix notation and return values. Add statements to main() to test these
// operators.
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
   ptime(int hrs, int min, int sec)
   : hours(hrs), minutes(min), seconds(sec)
   {
      if (seconds>=60)
      {
         seconds = seconds%60;
         ++minutes;
      }
      if (minutes>=60)
      {
         minutes = minutes%60;
         ++hours;
      }
      if (seconds<0)
      {
         seconds=60+seconds;
         --minutes;
      }
      if (minutes<0)
      {
         minutes=60+minutes;
         --hours;
      }
      if (hours<0)
      {
         hours = 0;
      }
   }
   void show_time() const;
   ptime operator+(ptime t2) const;
   void set_time();
   ptime operator++();
   ptime operator++(int);
   ptime operator--();
   ptime operator--(int);
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
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
ptime ptime::operator++()
{
   int sec = seconds;
   int min = minutes;
   int hrs = hours;
   return ptime(hrs, min, ++sec);
}
//---------------------------------------------------------------------------------------
ptime ptime::operator++(int)
{
   int sec = seconds;
   int min = minutes;
   int hrs = hours;
   return ptime(hrs, min, sec++);
}
//---------------------------------------------------------------------------------------
ptime ptime::operator--()
{
   int sec = seconds;
   int min = minutes;
   int hrs = hours;
   return ptime(hrs, min, --sec);
}
//---------------------------------------------------------------------------------------
ptime ptime::operator--(int)
{
   int sec = seconds;
   int min = minutes;
   int hrs = hours;
   return ptime(hrs, min, sec--);
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
   ptime t4 = ++t3;
   cout << "++t3; t4 = ";
   t4.show_time();
   cout << endl;
   ptime t5 = t4++;
   cout << "t4++; t5 = ";
   t5.show_time();
   cout << endl;
   ptime t6 = --t3;
   cout << "--t3; t6 = ";
   t6.show_time();
   cout << endl;
   ptime t7 = --t6;
   cout << "--t6; t7 = ";
   t7.show_time();
   cout << endl;
   return 0;
}