// ptrobjs.cpp
// array of pointers to objects
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class person                                                   // class of persons
{
protected:
   char name[40];                                              // person's name
public:
   void setName()                                              // set the name
   {
      cout << "Enter name: ";
      cin >> name;
   }
   void printName()                                            // get the name
   {
      cout << "\n   Name is: " << name;
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   person* persPtr[100];                                       // array of pointers to persons
   int n = 0;                                                  // number of persons in array
   char choice;
   do                                                          // put persons in array
   {
      persPtr[n]= new person;                                  // make new objects
      persPtr[n]->setName();                                   // set persons's name
      n++;                                                     // count new person
      cout << "Enter another (y/n)? ";                         // enter another
      cin >> choice;                                           // person?
   } while (choice =='y' || choice =='Y');                     // quit on 'n'
   for (int j=0; j<n; j++)                                     // print names of
   {
      cout << "\nPerson number " << j+1;                       // all persons
      persPtr[j]->printName();
   }
   cout << endl;
   return 0;
}