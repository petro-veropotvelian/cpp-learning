// exercise_9_3.cpp
// Start with the publication, book, and tape classes of Exercise 1. Add a base
// class sales that holds an array of three floats so that it can record the
// dollar sales of a particular publication for the last three months. Include
// a getdata() function to get three sales amounts from the user, and a
// putdata() function to display the sales figures. Alter the book and tape
// classes so they are derived from both publication and sales. An object of
// class book or tape should input and output sales data along with its other
// data. Write a main() function to create a book object and a tape object and
// exercise their input/output capabilities.
#include <iostream>
#include <iomanip>
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
class sales
{
private:
   enum {SIZE = 3};
   float sls[SIZE];
public:
   void getdata()
   {
      cout << "\nPlese, specify sales amouts for the last three months\n";
      for (int i=0; i < SIZE; i++)
      {
         cout << "Please, amout of sales for the " << (i+1) << " month $: ";
         cin >> sls[i];
         cin.get();
      }

   }
   void putdata()const
   {
      cout << "Sales amounts for the last three months:\n";
      for (int i=0; i<SIZE; i++)
      {
         cout << std::setw(10) << std::string((i+1), 'I');
      }
      cout << endl;
      for (int i=0; i<SIZE; i++)
      {
         cout << std::setw(10) << sls[i];
      }
   }
};
///////////////////////////////////////////////////////////////////////////////
class book : private publication, private sales
{
private:
   int pages;
public:
   void getdata()
   {
      publication::getdata();
      cout << "Enter the number of pages: ";
      cin >> pages;
      cin.get();
      sales::getdata();
   }
   void putdata() const
   {
      publication::putdata();
      cout << "   Number of pages: " << pages<< "\n";
      sales::putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
class tape : private publication, private sales
{
private:
   float playing_time;
public:
   void getdata()
   {
      publication::getdata();
      cout << "Specify playing time, minutes: ";
      cin >> playing_time;
      cin.get();
      sales::getdata();
   }
   void putdata() const
   {
      publication::putdata();
      cout << "   Playing time: " << playing_time << " minutes.\n";
      sales::putdata();
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
   cout << "\nEnter data for book 1";
   b1.getdata();
   cout << "\nEnter data for tape 1";
   t1.getdata();
   cout << "\nData on publication 1:";
   cout << endl;
   p1.putdata();
   cout << "\nData on book 1:";
   cout << endl;
   b1.putdata();
   cout << "\nData on tape 1:";
   cout << endl;
   t1.putdata();
   cout << endl;
   return 0;
}