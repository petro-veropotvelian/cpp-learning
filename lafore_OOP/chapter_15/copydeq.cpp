// copydeq.cpp
// demostrates normal copy with queues
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
   int arr1[] = { 1, 3, 5, 7, 9 };
   int arr2[] = { 2, 4, 6, 8, 10 };
   deque<int> d1;
   deque<int> d2;
   for (int j=0; j<5; j++)
   {                                                                 // transfer arrays to deques
      d1.push_back(arr1[j]);
      d2.push_back(arr2[j]);
   }
   copy(d1.begin(), d1.end(), d2.begin());                           // copy d1 to d2

   for (int k=0; k<d2.size(); k++)
   {
      cout << d2[k] << ' ';                                          // display d2
   }
   cout << endl;
   return 0;
}