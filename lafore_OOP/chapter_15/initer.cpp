// initer.cpp
// demonstrates istream_iterator
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
   list<float> fList(5);                                             // uninitialized list
   cout << "\nEnter 5 floating-point nubers: ";
   istream_iterator<float> cin_iter(cin);                            // istream iterator (cin)
   istream_iterator<float> end_of_stream;                            // istream iterator (eos)
   copy(cin_iter, end_of_stream, fList.begin());                     // copy from cin to fList
   cout << endl;
   ostream_iterator<float> ositer(cout, "--");
   copy(fList.begin(), fList.end(), ositer);                         // display list
   cout << endl;
   return 0;
}