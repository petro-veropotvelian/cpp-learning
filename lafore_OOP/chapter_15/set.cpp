// set.cpp
// set stores string objects
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char*argv[])
{
   string names[] = { "Juanita", "Robert",
                       "Mary", "Amanda", "Marie" };                  // array of string objects
   set<string, less<string>> nameSet(names, names+5);                // initialize set to array
   set<string, less<string>>::iterator iter;                         // iterator to set
   nameSet.insert("Yvette");                                         // insert more names
   nameSet.insert("Larry");
   nameSet.insert("Barry");
   nameSet.erase("Mary");                                            // erase a name
   cout << "\nSize = " << nameSet.size() << endl;                    // display size of set
   iter = nameSet.begin();                                           // display members of set
   while (iter!=nameSet.end())
   {
      cout << *iter++ << "\n";
   }
   string searchName;                                                // get name from user
   cout << "\nEnter name to search for: ";
   cin >> searchName;
   iter = nameSet.find(searchName);                                  // find matching name in set
   if (iter == nameSet.end())
   {

      cout << "The name " << searchName << " is NOT in the set.";
   }
   else
   {
      cout << "The name " << *iter << " IS in the set.";
   }
   cout << endl;
   return 0;
}