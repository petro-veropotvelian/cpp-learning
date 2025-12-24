// exercise_4_11.cpp
// Use the time structure from Exercise 9, and write a program that obtains two
// time values from the user in 12:59:59 format, stores them in struct time
// variables, converts each one to seconds (type int), adds these quantities,
// converts the result back to hours-minutes-seconds, stores the result in a
// time structure, and finally displays the result in 12:59:59 format.
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct time
{
   int hours;
   int minutes;
   int seconds;
};
///////////////////////////////////////////////////////////////////////////////

void secondsToTime(const long seconds, time &tt);
long timeToSeconds(const time &tt);
void SetTime(time &tt);
void GetTime(const time &tt);

int main(int argc, char*argv[])
{
   time tA, tB;
   cout << "Enter the first time.\n";
   SetTime(tA);
   cout << "Enter the second time.\n";
   SetTime(tB);
   long lResSeconds = timeToSeconds(tA) + timeToSeconds(tB);
   time tRes;
   secondsToTime(lResSeconds, tRes);
   cout << "The result is ";
   GetTime(tRes);
   cout << endl;
   return 0;
}


void secondsToTime(const long seconds, time &tt)
{
   tt.hours = seconds/3600;
   tt.minutes = (seconds - tt.hours * 3600)/60;
   tt.seconds = seconds - tt.hours*3600 - tt.minutes*60;
}

void SetTime(time &tt)
{
   cout << "Specify time (hours:minutes:seconds): ";
   char cSeparator;
   cin>>tt.hours>>cSeparator>>tt.minutes>>cSeparator>>tt.seconds;
}

void GetTime(const time &tt)
{
   if (tt.hours < 10)
   {
      cout << "0";
   }
   cout << tt.hours << ":";
   if (tt.minutes < 10)
   {
      cout << "0";
   }
   cout<< tt.minutes << ":";
   if (tt.seconds < 10)
   {
      cout << "0";
   }
   cout << tt.seconds;
}

long timeToSeconds(const time &tt)
{
   return (tt.hours * 3600 + tt.minutes * 60 + tt.seconds);
}