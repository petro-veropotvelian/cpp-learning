// exercise_9_9.cpp
// Start with the publication, book, and tape classes of Exercise 1. Suppose
// you want to add the date of publication for both books and tapes. From the
// publication class, derive a new class called publication2 that includes this
// member data. Then change book andtape so they are derived from publication2
// instead of publication. Make all the necessary changes in member functions
// so the user can input and output dates along with the other data. For the
// dates, you can use the date class from Exercise 5 in Chapter 6, which stores
// a date as three ints, for month, day, and year.
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class publication
{
private:
   string title;
   float price;
public:
   void getdata()
   {
      cout << "\nPlease, specify the title: ";
      std::getline(std::cin, title);
      cout << "Please, enter the price, $: ";
      cin >> price;
      cin.get();

   }
   void putdata()const
   {
      cout << "   Title: " << title;
      cout << "\n   Price: " << price << " $\n";
   }
};
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
///////////////////////////////////////////////////////////////////////////////
class publication2 : private publication
{
private:
   date pubdate;
public:
   void getdata()
   {
      publication::getdata();
      pubdate.getdate();
   }
   void putdata() const
   {
      publication::putdata();
      cout << "Publication date: ";
      pubdate.showdate();
      cout << endl;
   }
};
////////////////////////////////////////////////////////////////////////////////
class book : private publication2
{
private:
   int pages;
public:
   void getdata()
   {
      publication2::getdata();
      cout << "\nEnter the number of pages: ";
      cin >> pages;
      cin.get();
   }
   void putdata() const
   {
      publication2::putdata();
      cout << "   Number of pages: " << pages<< "\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
class tape : private publication2
{
private:
   float playing_time;
public:
   void getdata()
   {
      publication2::getdata();
      cout << "\nSpecify playing time, minutes: ";
      cin >> playing_time;
      cin.get();
   }
   void putdata() const
   {
      publication2::putdata();
      cout << "\n   Playing time: " << playing_time << " minutes.\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   publication2 p1;
   book b1;
   tape t1;
   cout << endl;
   cout << "Enter data for publication 1";
   p1.getdata();
   cin.get();
   cout << "Enter data for book 1";
   b1.getdata();
   cin.clear();
   cout << "Enter data for tape 1";
   t1.getdata();
   cin.clear();
   cout << "\nData on publication 1\n";
   p1.putdata();
   cout << "\nData on book 1";
   b1.putdata();
   cout << "\nData on tape 1";
   t1.putdata();
   cout << endl;
   return 0;
}