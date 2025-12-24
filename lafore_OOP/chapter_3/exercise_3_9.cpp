// exercise_3_9.cpp
// Suppose you give a dinner party for six guests, but your table seats only
// four. In how many ways can four of the six guests arrange themselves at the
// table? Any of the six guests can sit in the first chair. Any of the
// remaining five can sit in the second chair. Any of the remaining four can
// sit in the third chair, and any of the remaining three can sit in the fourth
// chair. (The last two will have to stand.) So the number of possible
// arrangements of six guests in four chairs is 6*5*4*3, which is 360.
// Write a program that calculates the number of possible arrangements for any
// number of guests and any number of chairs. (Assume there will never be
// fewer guests than chairs.) Don't let this get too complicated.
// A simple for loop should do it.
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   cout << "Please, enter a number of guests: ";
   int nNumberOfGuests;
   cin >> nNumberOfGuests;
   cout << "Please, enter a number of chairs: ";
   int nNumberOfChairs;
   cin >> nNumberOfChairs;
   int nTotalArrangements = 1;
   for (int i=nNumberOfChairs, j=0; i>0; --i, ++j)
   {
      nTotalArrangements*= (nNumberOfGuests - j);
   }
   cout << "The number of possible arrangements is: " << nTotalArrangements << endl;
   return 0;
}