// exercise_6_5.cpp
// Start with the date structure in Exercise 5 in Chapter 4 and transform it
// into a date class. Its member data should consist of three ints: month, day,
// and year. It should also have two member functions: getdate(), which allows
// the user to enter a date in 12/31/02 format, and showdate(), which displays
// the date.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class date
{
private:
   int day;
   int month;
   int year;
public:
   date():day(0), month(0), year(0)
   {}
   date(const int nD, const int nM, const int nY)
      : day(nD), month(nM), year(nY)
   {}
   void getdate();
   void showdate() const;
};
//---------------------------------------------------------------------------------------
void date::getdate()
{
   char cDummy;
   cout << "Please specyfy a date (day/month/year): ";
   cin >> day >> cDummy >> month >> cDummy >> year;
}
//---------------------------------------------------------------------------------------
void date::showdate() const
{
   if (month < 10)
   {
      cout << "0";
   }
   cout << month << "/";
   if (day < 10)
   {
      cout << "0";
   }
   cout << day << "/" << year;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   date dt1(23, 05, 1943);
   date dt2;
   dt2.getdate();
   cout << "dt1 = ";
   dt1.showdate();
   cout << "\ndt2 = ";
   dt2.showdate();
   cout << endl;
   return 0;
}