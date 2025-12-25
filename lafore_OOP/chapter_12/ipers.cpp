// ipers.cpp
// reads person object from disk
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
int main(int argc, char* argv[])
{
   person pers;                                                      // create person variable
   ifstream infile("PERSON.DAT", ios::binary);                       // create streambuf
   infile.read(reinterpret_cast<char*>(&pers), sizeof(person));        // read stream
   pers.showData();                                                  // display person
   return 0;
}