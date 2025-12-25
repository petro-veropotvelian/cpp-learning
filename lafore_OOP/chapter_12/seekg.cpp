// seekg.cpp
// seeks particular person in file
#include <fstream>                                                   //for file streams
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class person                                                         // class of persons
{
protected:
   char name[80];                                                    // person's name
   int age;                                                          // preson's age
public:
   void getData()                                                    // get person's data
   {
      cout << "\n   Enter name: ";
      cin >> name;
      cout <<"   Enter age: ";
      cin >> age;
   }
   void showData()                                                   // display person's data
   {
      cout << "\n   Name: " << name;
      cout << "\n   Age: " << age;
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   person pers;                                                      // create person object
   ifstream infile;                                                  // create input file
   infile.open("GROUP.DAT", ios::in | ios::binary);                  // open file

   infile.seekg(0, ios::end);                                        // got to 0 bytes from end
   int endposition = infile.tellg();                                 // find where we are
   int n = endposition / sizeof(person);                             // number of persons
   cout << "\nThere are " << n <<" persons in file";

   cout <<"\nEnter person number: ";
   cin >> n;
   int position = (n-1) * sizeof(person);                            // number times size
   infile.seekg(position);                                           // bytes from start
   infile.read(reinterpret_cast<char*>(&pers), sizeof(person));      // read one person
   pers.showData();                                                  // display the person
   cout << endl;
   return 0;
}