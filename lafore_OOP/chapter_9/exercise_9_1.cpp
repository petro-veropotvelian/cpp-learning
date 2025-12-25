// exercise_9_1.cpp
// Imagine a publishing company that markets both book and audiocassette
// versions of its works. Create a class publication that stores the title (a
// string) and price (type float) of a publication. From this class derive two
// classes: book, which adds a page count (type int), and tape, which adds a
// playing time in minutes (type float). Each of these three classes should
// have a getdata() function to get its data from the user at the keyboard,
// and a putdata() function to display its data.
// Write a main() program to test the book and tape classes by creating
// instances of them, asking the user to fill in data with getdata(), and then
// displaying the data with putdata().
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
///////////////////////////////////////////////////////////////////////////////
class book : public publication
{
private:
   int pages;
public:
   void getdata()
   {
      publication::getdata();
      cout << "\nEnter the number of pages: ";
      cin >> pages;
      cin.get();
   }
   void putdata() const
   {
      publication::putdata();
      cout << "   Number of pages: " << pages<< "\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
class tape : public publication
{
private:
   float playing_time;
public:
   void getdata()
   {
      publication::getdata();
      cout << "\nSpecify playing time, minutes: ";
      cin >> playing_time;
      cin.get();
   }
   void putdata() const
   {
      publication::putdata();
      cout << "\n   Playing time: " << playing_time << " minutes.\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   publication p1;
   book b1;
   tape t1;
   cout << endl;
   cout << "Enter data for publication 1";
   p1.getdata();
   cout << "Enter data for book 1";
   b1.getdata();
   cout << "Enter data for tape 1";
   t1.getdata();
   cout << "\nData on publication 1";
   p1.putdata();
   cout << "\nData on book 1";
   b1.putdata();
   cout << "\nData on tape 1";
   t1.putdata();
   cout << endl;
   return 0;
}