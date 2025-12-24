// exercise_5_6.cpp
// Start with the program from Exercise 11 in Chapter 4, "Structures," which
// adds two struct time values. Keep the same functionality, but modify the
// program so that it uses two functions. The first, time_to_secs(), takes as
// its only argument a structure of type time, and returns the equivalent in
// seconds (type long). The second function, secs_to_time(), takes as its only
// argument a time in seconds (type long), and returns a structure of type
// time.
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
struct time
{
   int hours;
   int minutes;
   int seconds;
};
/////////////////////////////////////////////////////////////////////////////////////////
void SetTime(time &tt);
void GetTime(const time &tt);
long time_to_secs(const time &tt);
time secs_to_time(long lSecs);

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   time tA;
   cout << "Enter the first time.\n";
   SetTime(tA);
   cout << "The time ";
   GetTime(tA);
   cout << " is equal to ";
   long lSecs = time_to_secs(tA);
   cout << lSecs << " seconds." << endl;
   cout << "And vice versa: " << lSecs << " seconds";
   time tB;
   cout << " is equal to ";
   tB = secs_to_time(lSecs);
   GetTime(tB);
   cout << endl;
   return 0;
}
//---------------------------------------------------------------------------------------
void SetTime(time &tt)
{
   cout << "Specify time (hours:minutes:seconds): ";
   char cSeparator;
   cin>>tt.hours>>cSeparator>>tt.minutes>>cSeparator>>tt.seconds;
}
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
long time_to_secs(const time &tt)
{
   return (tt.hours * 3600 + tt.minutes * 60 + tt.seconds);
}
//---------------------------------------------------------------------------------------
time secs_to_time(long lSecs)
{
   time tt;
   tt.hours = lSecs / 3600;
   tt.minutes = (lSecs - tt.hours * 3600) / 60;
   tt.seconds = lSecs - tt.hours * 3600 - tt.minutes * 60;
   return tt;
}