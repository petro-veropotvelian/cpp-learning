// dinsiter.cpp
// demostrates insert iterators wih queues
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
   int arr1[] = { 1, 3, 5, 7, 9 };                                   // initialize d1
   int arr2[] = { 2, 4, 6 };                                         // initialize d2
   deque<int> d1;
   deque<int>d2;

   for (int i=0; i<5; i++)                                           // transfer arrays to deques
   {
      d1.push_back(arr1[i]);
   }
   for (int j=0; j<3; j++)
   {
      d2.push_back(arr2[j]);
   }
   //copy(d1.begin(), d1.end(), back_inserter(d2));
   //copy(d1.begin(), d1.end(), front_inserter(d2));
   copy(d1.begin(), d1.end(), inserter(d2, d2.begin()));
   cout << "\nd2: ";
   for (int k=0; k<d2.size(); k++)
   {
      cout << d2[k] << ' ';                                          // display d2
   }
   cout << endl;
   return 0;
}