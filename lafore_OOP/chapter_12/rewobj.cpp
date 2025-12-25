// rewobj.cpp
// person objects to disk I/O
#include <fstream>                                                   // for file streams
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class person                                                         // class of persons
{
protected:
   char name[80];                                                    // person's name
   int age;                                                          // person's age
public:
   void getData(void)                                                // get person's data
   {
      cout << "\n    Enter name: ";
      cin >> name;
      cout << "    Enter age: ";
      cin >> age;
   }
   void showData(void)                                               // display person's data
   {
      cout << "\n    Name: " << name;
      cout << "\n    Age: " << age;
   }
   void diskIn(int);                                                 // read from file
   void diskOut();                                                   // write to file
   static int diskCount();                                           // return number of 
                                                                     // persons in file
};
//-----------------------------------------------------------------------------
void person::diskIn(int pn)                                          // read person number pn
{
   ifstream infile;                                                  // make streambuf
   infile.open("PERSFILE.DAT", ios::binary);                         // open it
   infile.seekg(pn * sizeof(person));                                // move file ptr
   infile.read((char*)this, sizeof(*this));                          // read one person
}
//-----------------------------------------------------------------------------
void person::diskOut()                                               // write person to end of file
{
   ofstream outfile;                                                 // make stream
   outfile.open("PERSFILE.DAT", ios::app | ios::binary);             // open it
   outfile.write((char*)this, sizeof(*this));                        // write to it
}
//-----------------------------------------------------------------------------
int person::diskCount()                                              // return number of persons in file
{
   ifstream infile;
   infile.open("PERSFILE.DAT", ios::binary);
   infile.seekg(0, ios::end);                                        // go to 0 bytes from end
   return (int)infile.tellg()/sizeof(person);                        // calculate number of persons
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   char ch;
   person p;                                                         // make an empty person
   do
   {
      cout << "\nEnter data for person:";
      p.getData();                                                   // get  data
      p.diskOut();                                                   // write to disk
      cout << "Do another (y/n)? ";
      cin >> ch;
   } while (ch=='y' || ch=='Y');                                     // until user enters 'n'

   int n = person::diskCount();                                      // how many persons in file?
   cout << "There are " << n << " persons in file\n";
   for (int j= 0; j < n; j++)                                        // for each one,
   {
      cout << "\nPerson " << (j+1);
      p.diskIn(j);                                                   // read person from disk
      p.showData();                                                  // display person
   }
   cout << endl;
   return 0;
}