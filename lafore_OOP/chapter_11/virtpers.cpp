// virtpers.cpp
// virtual functions with person class
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class person                                                   // person class 
{
protected:
   char name[40];                                              // person's name
public:
   void getName()
   {
      cout << "Enter name: ";
      cin >> name;
   }
   void putName()                                            // get the name
   {
      cout << "Name is: " << name << endl;
   }
   virtual void getData() = 0;                              // pure virtual function
   virtual bool isOutstanding() = 0;                        // pure virtual function
};
/////////////////////////////////////////////////////////////////////////////////////////
class student: public person                                // student class
{
private:
   float gpa;                                               // grade point average
public:
   void getData()                                           // get student data from user
   {
      person::getName();
      cout << "    Enter student's GPA: ";
      cin >> gpa;
   }
   bool isOutstanding()
   {
      return (gpa > 3.5) ? true : false;
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
class professor : public person                                // professor class
{
private:
   int numPubs;                                                // number of papers published
public:
   void getData()                                              // get professor data from user
   {
      person::getName();
      cout << "    Enter number of professor's publications: ";
      cin >> numPubs;
   }
   bool isOutstanding()
   {
      return (numPubs > 100) ? true : false;
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
      cout << "Enter student of professor (s/p): ";
      cin >> choice;
      if (choice == 's')                                       // put new student
      {
         persPtr[n] = new student;                             // in array
      }
      else                                                     // put new professor
      {
         persPtr[n] = new professor;                           // in array
      }
      persPtr[n++]->getData();                                 // get data for person
      cout << "Enter another (y/n)? ";                         // enter another
      cin >> choice;                                           // person?
   } while (choice =='y' || choice =='Y');                     // quit on 'n'
   for (int j=0; j<n; j++)                                     // print names of all
   {
      persPtr[j]->putName();                                   // persons, and 
      if (persPtr[j]->isOutstanding())                         // say if outstanding
      {
         cout << "    This person is outstanding\n";
      }
   }
   return 0;
}