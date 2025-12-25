// iterev.cpp
// demostrates reverse iterator
#include <iostream>
#include <list>
using namespace std;
int main(int argc, char* argv[])
{
   int arr[] = { 2, 4, 6, 8, 10 };                                   // array of ints
   list<int> theList;
   for (int j=0; j<5; j++)
   {
      theList.push_back(arr[j]);                                     // transfer aary to list
   }
   list<int>::reverse_iterator revit;                                // reverse iterator
   revit = theList.rbegin();
   while (revit!=theList.rend())                                     // iterate backward
   {                                                                 // throw list
      cout << *revit++ << ' ';                                       // displaying output
   }
   cout << endl;
   return 0;
}