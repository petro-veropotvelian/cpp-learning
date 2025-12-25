// iterfind.cpp
// find() returns a list iterator
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
   list<int> theList(5);                                               // empty list holds 5 ints
   list<int>::iterator iter;                                           // iterator
   int data = 0;
   for (iter = theList.begin(); iter != theList.end(); iter++)
   {
      *iter = data += 2;                                               // fill list with data
   }
   iter = find(theList.begin(), theList.end(), 8);
   if (iter != theList.end())
   {
      cout << "\nFound 8.\n";
   }
   else
   {
      cout << "\nDid not find 8.\n";
   }
   return 0;
}