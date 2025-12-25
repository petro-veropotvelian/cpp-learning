// exercise_9_4.cpp
// Assume that the publisher in Exercises 1 and 3 decides to add a third way to
// distribute books: on computer disk, for those who like to do their reading
// on their laptop. Add adisk class that, like book and tape, is derived from
// publication. The disk class shouldincorporate the same member functions as
// the other classes. The data item unique to this class is the disk type:
// either CD or DVD. You can use an enum type to store this item.
// The user could select the appropriate type by typing c or d.
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
class book : private publication
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
   }
   void putdata() const
   {
      publication::putdata();
      cout << "   Number of pages: " << pages<< "\n";
   }
};

///////////////////////////////////////////////////////////////////////////////
class tape : private publication
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
   }
   void putdata() const
   {
      publication::putdata();
      cout << "   Playing time: " << playing_time << " minutes.\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
class disk : private publication
{
private:
   enum disktype { CD, DVD};
   disktype type;
public:
   void getdata()
   {
      publication::getdata();
      cout << "Specify disk type: ";
      char cType;
      cin >> cType;
      if (cType == 'c' || cType=='C')
      {
         type = disktype::CD;
      }
      else if (cType == 'd' || cType =='D')
      {
         type = disktype::DVD;
      }
   }
   void putdata() const
   {
      publication::putdata();
      cout << "Disk type: ";
      switch(type)
      {
         case disktype::CD:
         cout << "CD";
         break;
         case disktype::DVD:
         cout << "DVD";
         break;
      }
      cout << endl;
   }

};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   publication p1;
   book b1;
   tape t1;
   disk d1;
   cout << endl;
   cout << "Enter data for publication 1";
   p1.getdata();
   cout << "\nEnter data for book 1";
   b1.getdata();
   cout << "\nEnter data for tape 1";
   t1.getdata();
   cout << "Enter data for disk 1";
   d1.getdata();
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
   cout << "\nData on disk 1:";
   cout << endl;
   d1.putdata();
   cout << endl;
   return 0;
}