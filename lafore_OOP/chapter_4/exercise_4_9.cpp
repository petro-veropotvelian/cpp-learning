// exercise_4_9.cpp
// Create a structure called time. Its three members, all type int, should be
// called hours, minutes, and seconds. Write a program that prompts the user to
// enter a time value in hours, minutes, and seconds. This can be in 12:59:59
// format, or each number can be entered at a separate prompt ("Enter hours:",
// and so forth). The program should then store the time in a variable of type
// struct time, and finally print out the total number of seconds represented
// by this time value:
//    long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds
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
void SetTime(time &t1);

void GetTime(const time &t1);

long GetSeconds(const time &t1);

int main(int argc, char* argv[])
{
   time tt;
   SetTime(tt);
   cout << "The total number of seconds is " << GetSeconds(tt) << endl;
   return 0;
}


void SetTime(time &t1)
{
   cout << "Specify time (hours:minutes:seconds): ";
   char cSeparator;
   cin>>t1.hours>>cSeparator>>t1.minutes>>cSeparator>>t1.seconds;
}

void GetTime(const time &t1)
{
   cout << t1.hours << ":" << t1.minutes << ":" << t1.hours;
}

long GetSeconds(const time &t1)
{
   return (t1.hours * 3600 + t1.minutes * 60 + t1.seconds);
}