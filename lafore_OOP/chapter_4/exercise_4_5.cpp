// exercise_4_5.cpp
// Create a structure of type date that contains three members: the month,
// the day of the month, and the year, all of type int. (Or use day-month-year
// order if you prefer.) Have the user enter a date in the format 12/31/2001,
// store it in a variable of type struct date, then retrieve the values from
// the variable and print them out in the same format.
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////
struct date
{
   int day;
   int month;
   int year;
};
////////////////////////////////////////////////////////////
const char cDummyChar = '/';
int main(int argc, char* argv[])
{
   date myDate;
   char cDummy;
   cout << "Please specyfy a date (day/month/year): ";
   cin >> myDate.day >> cDummy >> myDate.month >> cDummy >> myDate.year;
   cout << "Thanks!\n";
   cout << "You entered: " << myDate.day << cDummyChar << myDate.month << cDummyChar << myDate.year;
   cout << endl;
   return 0;
}