// setpers.cpp
// uses a multiset to hold person objects
#pragma warning (disable:4786)                                       // for set (Microsoft only)
#include <iostream>
#include <set>
#include <string>
using namespace std;

class person
{
private:
   string lastName;
   string firstName;
   long phoneNumber;
public:
   person() : lastName("blank"),                                     // default constructor
              firstName("blank"), phoneNumber(0)
   {}
   person(string lana, string fina, long pho) :                      // 3-arg constructor
          lastName(lana), firstName(fina), phoneNumber(pho)
   {}

   friend bool operator<(const person&, const person&);
   friend bool operator==(const person&, const person&);

   void display() const                                              // display person's data
   {
      cout << endl << lastName << ",\t" << firstName
           <<"\t\tPhone: "<<phoneNumber;
   }
};

bool operator<(const person& p1, const person& p2)
{
   if (p1.lastName == p2.lastName)
   {
      return (p1.firstName < p2.firstName) ? true : false;
   }
   return (p1.lastName < p2.lastName) ? true : false;
}

bool operator==(const person& p1, const person& p2)
{
   return (p1.lastName == p2.lastName &&
           p1.firstName == p2.firstName) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   // create person objects
   person pers1("Deauville", "William", 8435150);
   person pers2("McDonald", "Stacey", 3327563);
   person pers3("Bartoski", "Peter", 6946473);
   person pers4("KuangThu", "Bruce", 4157300);
   person pers5("Wellington", "John", 9207404);
   person pers6("McDonald", "Amanda", 8435150);
   person pers7("Fredericks", "Roger", 7049982);
   person pers8("McDonald", "Stacey", 7764987);
   multiset<person, less<person>> persSet;                           // multiset of persons
   multiset<person, less<person>>::iterator iter;                    // iterator to a multiset of persons

   persSet.insert(pers1);                                            // put persons in multiset
   persSet.insert(pers2);
   persSet.insert(pers3);
   persSet.insert(pers4);
   persSet.insert(pers5);
   persSet.insert(pers6);
   persSet.insert(pers7);
   persSet.insert(pers8);

   cout << "\nNumber of entries = " << persSet.size();
   iter = persSet.begin();                                           // display contents of multiset
   while (iter!=persSet.end())
   {
      (*iter++).display();
   }
   string searchLastName, searchFirstName;                           // get last and first name
   cout << "\n\nEnter last name of person to search for: ";
   cin >> searchLastName;
   cout << "Eter first name: ";
   cin >> searchFirstName;
   person searchPerson(searchLastName, searchFirstName, 0);          // create person with this name
   int cntPersons = persSet.count(searchPerson);                     // get count of such persons
   cout << "Number of persons with this name = " << cntPersons;
   iter = persSet.lower_bound(searchPerson);                         // display all matches
   while (iter != persSet.upper_bound(searchPerson))
   {
      (*iter++).display();
   }
   cout << endl;
   return 0;
}