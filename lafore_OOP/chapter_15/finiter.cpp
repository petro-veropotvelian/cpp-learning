// finiter.cpp
// demonstrates istream_iterator with files
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
   list<int> iList;                                                  // empty list
   ifstream infile("ITER.DAT");                                      // creat input file object
                                                                     // (ITER.DAT must already exist)
   // istream_iterators:
   istream_iterator<int> file_iter(infile);                          // file
   istream_iterator<int> end_of_stream;                              // eos
   copy(file_iter, end_of_stream, back_inserter(iList));             // copy from infile to iList
   cout << endl;                                                     // display list
   ostream_iterator<int> ositer(cout, "--");
   copy(iList.begin(), iList.end(), ositer);
   cout << endl;
   return 0;
}