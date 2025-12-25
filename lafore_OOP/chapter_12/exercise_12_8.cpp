// exercise_12_8.cpp
// Starting with the LINKLIST program in Chapter 10, "Pointers", create a program that
// gives the user four options, which can be selected by pressing a key.
// - Add a link to the list in memory (the user supplies the data, which is one integer)
// - Display the data from all the links in memory
// - Write the data for all the links to a disk file (creating or truncating the file as necessary)
// - Read all the data back from the file, and construct a new linked list in which to
//   store it
// The first two options can use the member functions already implemented in LINKLIST.
// You'll need to write functions to read to, and write from, the disk file. You can use the
// same file for all reads and writes. The file should store only the data; there's no sense in
// its storing the contents of pointers, which will probably not be relevant when the list is
// read back in.
#include <iostream>
#include <fstream>
#include <process.h>
using namespace std;

////////////////////////////////////////////////////////////////
struct link                           //one element of list
{
   int data;                          //data item
   link* next;                        //pointer to next link
};
////////////////////////////////////////////////////////////////
class linklist                        //a list of links
{
private:
   link* first;                    //pointer to first link
   static const char* filename;
public:
   linklist()                      //no-argument constructor
   { first = NULL; }               //no first link
   ~linklist();
   void clear();
   void additem(int d);            //add data item (one link)
   void display();                 //display all links
   bool writeToFile();
   bool readFromFile();
};
//--------------------------------------------------------------
const char* linklist::filename = "LINKLIST.TXT";
//--------------------------------------------------------------
void linklist::additem(int d)         //add data item
{
   link* newlink = new link;          //make a new link
   newlink->data = d;                 //give it data
   newlink->next = first;             //it points to next link
   first = newlink;                   //now first points to this
}
//--------------------------------------------------------------
void linklist::display()              //display all links
{
   link* current = first;             //set ptr to first link
   while ( current != NULL )           //quit on last link
   {
      cout << current->data << endl;  //print data
      current = current->next;        //move to next link
   }
}
//--------------------------------------------------------------
linklist::~linklist()
{
   while (first != NULL)
   {
      link* current = first;
      cout << "Deleting item " << current->data << endl;
      first = first->next;
      delete current;
   }
}
//--------------------------------------------------------------
void linklist::clear()
{
   while (first != NULL)
   {
      link* current = first;
      first = first->next;
      delete current;
   }
}
//--------------------------------------------------------------
bool linklist::writeToFile()
{
   bool bRet = true;
   ofstream outfile;
   outfile.open(linklist::filename, ios::app);
   char chSPACE = ' ';
   if (!outfile)
   {
      bRet = false;
      cerr << "\nERROR! Can't open " << linklist::filename << endl;
   }
   else
   {
      link* current = first;             //set ptr to first link
      while (current != NULL)           //quit on last link
      {
         outfile << current->data << chSPACE;  // write data
         current = current->next;              // move to next link
      }
      outfile << endl;
   }
   outfile.close();
   return bRet;
}
//--------------------------------------------------------------
bool linklist::readFromFile()
{
   bool bRet = true;
   ifstream infile;
   infile.open(linklist::filename);
   if (!infile)
   {
      bRet = false;
      cerr << "\nERROR! Can't open " << linklist::filename << endl;
   }
   else
   {
      int nData;
      infile >> nData;
      while (!infile.eof())
      {
         this->additem(nData);
         infile >> nData;
      }
   }
   return bRet;
}
////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char ch;
   linklist lList;
   while (true)
   {
      cout << "\nPlease, choose an option:"
           << "\n   'a' - add an item to the linklist"
           << "\n   'd' - display all items it the linklist"
           << "\n   'w' - write linklist to the file"
           << "\n   'r' - read linklist from the file"
           << "\n   'q' - quit the program"
           << "\nPlease, make your choice: ";
      cin >> ch;
      switch (ch)
      {
      case 'a':
         int nNumber;
         cout << "\nPlease, enter the number: ";
         cin >> nNumber;
         lList.additem(nNumber);
         break;
      case 'd':
         lList.display();
         break;
      case 'w':
         if (!lList.writeToFile())
         {
            exit(-1);
         }
         break;
      case 'r':
         lList.clear();
         if (!lList.readFromFile())
         {
            exit(-1);
         }
         break;
      case 'q':
         cout << "\nBye!";
         exit(0);
      default:
            cout << "\nUnknown command";
         break;
      }
   }
   return 0;
}