// foutiter.cpp
// demonstrates ostream_iterator with files
#include <fstream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main(int argc, char*argv[])
{
   int arr[] = { 11, 21, 31, 41, 51 };
   list<int> theList;
   for (int j=0; j<5; j++)
   {
      theList.push_back(arr[j]);                                     // transfer array to list
   }
   ofstream outfile("ITER.DAT");                                     // create file object
   ostream_iterator<int> ositer(outfile, " ");                       // iterator
   copy(theList.begin(), theList.end(), ositer);                     // write list to file
   return 0;
   return 0;
}