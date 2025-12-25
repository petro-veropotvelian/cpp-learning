// diskfun.cpp
// reads and writes several objects to disk
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
   void getData()                                                    // get person's data
   {
      cout << "\n    Enter nama: ";
      cin >> name;
      cout << "    Enter age: ";
      cin >> age;
   }
   void showData()                                                   // display person's data
   {
      cout << "\n    Name: " << name;
      cout << "\n    Age: " << age;
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   char ch;
   person pers;                                                      // create person objects
   fstream file;                                                     // create input/output file
                                                                     // open for append
   file.open("GROUP.DAT", ios::app | ios::out |
                                   ios::in | ios::binary);           // data from user to file
   do
   {
      cout << "\nEnter person's data:";
      pers.getData();                                                // get one person's data
                                                                     // write to file
      file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
      cout << "Enter another person (y/n)? ";
      cin >> ch;
   } while (ch=='y' || ch=='Y');                                     // quit on 'n'
   file.seekg(0);                                                    // reset to start to file
                                                                     // read first person
   file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
   while (!file.eof())                                               // quit on EOF
   {
      cout << "\nPerson: ";                                          // display person
      pers.showData();                                               // read another person
      file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
   }
   cout << endl;
   return 0;
}