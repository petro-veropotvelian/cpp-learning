// exercise_5_9.cpp
// Repeat Exercise 8, but instead of two int variables, have the swap()
// function interchange two struct time values (see Exercise 6).
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
void swap(time &tA, time &tB);
/*long time_to_secs(const time &tt);
time secs_to_time(long lSecs);*/

/////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
   time tA;
   cout << "Enter the first time.\n";
   SetTime(tA);
   time tB;
   cout << "Enter the second time.\n";
   SetTime(tB);
   swap(tA, tB);
   cout << "SWAP!" << endl;
   cout << "And now the first time: ";
   GetTime(tA);
   cout << " and the second time: ";
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
void swap(time &tA, time &tB)
{
   time tmp;
   tmp.hours   = tA.hours;
   tmp.minutes = tA.minutes;
   tmp.seconds = tA.seconds;
   tA.hours    = tB.hours;
   tA.minutes  = tB.minutes;
   tA.seconds  = tB.seconds;
   tB.hours    = tmp.hours;
   tB.minutes  = tmp.minutes;
   tB.seconds  = tmp.seconds;
}