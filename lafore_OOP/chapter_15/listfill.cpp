// listfill.cpp
// uses iterator to fill list with data
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char*argv[])
{
   list<int> iList(5);                                               // empty list holds 5 ints
   list<int>::iterator it;                                           // iterator
   int data = 0;
   for (it = iList.begin(); it != iList.end(); it++)
   {
      *it = data += 2;                                               // fill list with data
   }
   for (it = iList.begin(); it != iList.end(); it++)
   {
      cout << *it << ' ';                                            // display list
   }
   cout << endl;
   return 0;
}