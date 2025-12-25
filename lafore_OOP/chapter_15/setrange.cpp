// setrange.cpp
// tests ranges within a set
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
   set<string, less<string>> organic;                                // set of string objects
   set<string, less<string>>::iterator iter;                         // iterator to set
   organic.insert("Curine");                                         // insert organic compounds
   organic.insert("Xanthine");
   organic.insert("Curarine");
   organic.insert("Melamine");
   organic.insert("Cyanimide");
   organic.insert("Phenol");
   organic.insert("Aphrodine");
   organic.insert("Imidazole");
   organic.insert("Cinchonine");
   organic.insert("Palmitamide");
   organic.insert("Cyanimide");
   iter = organic.begin();
   while (iter!=organic.end())                                       // display set
   {
      cout << *iter++ << '\n';
   }
   string lower, upper;                                              // display entries in range
   cout << "\nEnter range (example C Czz): ";
   cin >> lower >> upper;
   iter = organic.lower_bound(lower);
   while (iter!=organic.upper_bound(upper))
   {
      cout << *iter++ << '\n';
   }
   return 0;
}