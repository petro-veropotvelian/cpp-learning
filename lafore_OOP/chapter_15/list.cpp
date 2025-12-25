// list.cpp
// demostrates push_from(), front(), pop_front()
#include <iostream>
#include <list>
using namespace std;
int main(int argc, char* argv[])
{
   list<int> ilist;
   ilist.push_back(30);                                              // push items on back
   ilist.push_back(40);
   ilist.push_front(20);                                             // push items on front
   ilist.push_front(10);
   int size = ilist.size();
   for (int j=0; j<size; j++)
   {
      cout << ilist.front() << ' ';                                  // read item from front
      ilist.pop_front();                                             // pop item off front
   }
   cout << endl;
   return 0;
}