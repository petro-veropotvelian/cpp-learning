// exercise_5_5.cpp
// Write a function called hms_to_secs() that takes three int values—for hours,
// minutes, and seconds—as arguments, and returns the equivalent time in
// seconds (type long).
// Create a program that exercises this function by repeatedly obtaining a time
// value in hours, minutes, and seconds from the user (format 12:59:59),
// calling the function, and displaying the value of seconds it returns.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
long hms_to_secs(int hours, int minutes, int seconds);

void get_hms(int &hours, int &minutes, int &seconds);
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   short nRet;
   int nHours, nMinutes, nSeconds;
   do
   {
      get_hms(nHours, nMinutes, nSeconds);
      cout << nHours << " hours " << nMinutes
           << " minutes " << nSeconds << " seconds is equal to "
           << hms_to_secs(nHours, nMinutes, nSeconds) << " seconds." << endl;
      cout << "Do you want to continue (0 - for exit)? ";
      cin >> nRet;
   }
   while (nRet!=0);
   return 0;
}

//---------------------------------------------------------------------------------------
long hms_to_secs(int hours, int minutes, int seconds)
{
   const int nMinutesInHour = 60;
   const int nSecondsInMinute = 60;
   long lRet = hours * nMinutesInHour * nSecondsInMinute +
               minutes * nSecondsInMinute + seconds;
   return lRet;
}
//---------------------------------------------------------------------------------------
void get_hms(int &hours, int &minutes, int &seconds)
{
   hours = minutes = seconds = 0;
   cout << "Please, specify hours: ";
   cin >> hours;
   cout << "Plese, specify minutes: ";
   cin >> minutes;
   cout <<"Specify seconds, please: ";
   cin >> seconds;
}