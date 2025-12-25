// exercise_11_4.cpp
// Start with the program of Exercise 1 in this chapter, and add a member
// function of type bool called isOversize() to the book and tape classes.
// Let's say that a book with more than 800 pages, or a tape with a playing
// time longer than 90 minutes (which would require two cassettes), is
// considered oversize. You can access this function from main() and display
// the string "Oversize" for oversize books and tapes when you display their
// other data. If book and tape objects are to be accessed using pointers to
// them that are stored in an array of type publication, what do you need to
// add to the publication base class? Can you instantiate members of this
// base class?
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
   virtual bool isOversise() = 0;
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
   bool isOversise()
   {
      return (pages > 800) ? true : false;
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
   bool isOversise()
   {
      return (playing_time > 90) ? true : false;
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
      if (pubArr[i]->isOversise())
      {
         cout << "This is an oversized publication!" << endl;
      }
   }
   return 0;
}