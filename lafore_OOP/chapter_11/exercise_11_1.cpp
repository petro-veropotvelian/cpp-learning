// exercise_11_1.cpp
// Imagine the same publishing company described in Exercise 1 in Chapter 9
// that markets both book and audiocassette versions of its works. As in that
// exercise, create a class called publication that stores the title (a string)
// and price (type float) of a publication.
// From this class derive two classes: book, which adds a page count (type
// int); and tape, which adds a playing time in minutes (type float). Each of
// the three classes should have a getdata() function to get its data from the
// user at the keyboard, and a putdata() function to display the data.
// Write a main() program that creates an array of pointers to publication.
// This is similar to the VIRTPERS example in this chapter. In a loop, ask the
// user for data about a particular book or tape, and use new to create an
// object of type book or tape to hold the data. Put the pointer to the object
// in the array. When the user has finished entering the data for all books and
// tapes, display the resulting data for all the books and tapes entered, using
// a for loop and a single statement such as
//    pubarr[j]->putdata();
// to display the data from each object in the array.
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
   virtual void getdata()
   {
      cout << "\nPlease, specify the title: ";
      getline(cin, title);
      //cin.get();
      cout << "Please, enter the price, $: ";
      cin >> price;
      cin.get();

   }
   virtual void putdata()const
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
      cout << "   Playing time: " << playing_time << " minutes.\n";
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   publication* pubArr[100];
   int n = 0;                                                           // number of publications in array
   char choice;
   do
   {
      cout << "Enter book or tape (b/t): ";
      cin >> choice;
      cin.get();
      if (choice == 'b' || choice == 'B')
      {
         pubArr[n] = new book;
      }
      else
      {
         pubArr[n] = new tape;
      }
      pubArr[n++]->getdata();
      cout << "Enter another (y/n)? ";
      cin >> choice;
      cin.get();
   } while(choice =='y' || choice =='Y');
   for (int i=0; i<n; i++)
   {
      pubArr[i]->putdata();
   }
   return 0;
}