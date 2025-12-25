// opers.cpp
// saves person object to disk
#include <fstream>                                                   // for file streams
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class person                                                         // class of persons
{
protected:
   char name[80];                                                    // person's name
   short age;                                                        // person's age
public:
   void getData()                                                    // get person's data
   {
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter age: ";
      cin >> age;
   }
   void showData()                                                   // display person's data
   {
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   person pers;                                                      // create a peson
   pers.getData();                                                   // get data for person
   ofstream outfile("PERSON.DAT", ios::binary);                     // create ofsteam object
   outfile.write(reinterpret_cast<char*>(&pers), sizeof(person));      // write to it
   return 0;
}