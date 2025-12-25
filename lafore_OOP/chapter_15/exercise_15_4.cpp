// exercise_15_4.cpp
// Start with the person class, and create a multiset to hold pointers to
// person objects.
// Define the multiset with the comparePersons function object, so it will
// be sorted automatically by names of persons. Define a half-dozen persons,
// put them in the multiset, and display its contents. Several of the persons
// should have the same name, to verify that the multiset stores multiple
// objects with the same key.
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
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
//---------------------------------------------------------------------------------------
bool operator<(const person &p1, const person &p2)
{
   if (p1.lastName == p2.lastName)
   {
      return (p1.firstName < p2.firstName) ? true : false;
   }
   return (p1.lastName < p2.lastName) ? true : false;
}
//---------------------------------------------------------------------------------------
bool operator==(const person &p1, const person &p2)
{
   return (p1.lastName == p2.lastName &&
           p1.firstName == p2.firstName) ? true : false; 
}
//---------------------------------------------------------------------------------------
class comparePersons
{
public:
   bool operator()(const person* ptr1, const person* ptr2) const
   {
      return *ptr1<*ptr2;
   }
};
class displayPerson
{
public:
   void operator()(const person* ptr) const
   {
      ptr->display();
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   multiset<person*, comparePersons> personsMSet;
   multiset<person*, comparePersons>::iterator iter;
   person* ptr1 = new person("Doe", "John", 12345678);
   person* ptr2 = new person("Deniels", "Jack", 10012297);
   person* ptr3 = new person("Black", "Africa", 89091234);
   person* ptr4 = new person("Doe", "Jane", 787904571);
   person* ptr5 = new person("Murray", "William", 6167801);
   person* ptr6 = new person("Baldwin", "Michael", 78442210);
   person* ptr7 = new person("Deniels", "Jack", 99933311);
   person* ptr8 = new person("Heep", "Uriah", 90801001);

   personsMSet.insert(ptr1);
   personsMSet.insert(ptr2);
   personsMSet.insert(ptr3);
   personsMSet.insert(ptr4);
   personsMSet.insert(ptr5);
   personsMSet.insert(ptr6);
   personsMSet.insert(ptr7);
   personsMSet.insert(ptr8);
   cout << "List of persons sorted on creation:";
   for_each(personsMSet.begin(), personsMSet.end(), displayPerson());
   iter = personsMSet.begin();
   while (iter!=personsMSet.end())
   {
      delete *iter;
      personsMSet.erase(iter++);
   }
   cout << "\nBye!" << endl;
   return 0;
}