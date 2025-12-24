// exercise_5_3.cpp
// Write a function called zeroSmaller() that is passed two int arguments by
// reference and then sets the smaller of the two numbers to 0. Write a main()
// program to exercise this function.
#include <iostream>
using namespace std;

void zeroSmaller(int &nFirst, int &nSecond);

int main(int argc, char* argv[])
{
   int nFrst, nScnd;
   cout << "Specify the first number: ";
   cin >> nFrst;
   cout << "Specify the second number: ";
   cin >> nScnd;
   zeroSmaller(nFrst, nScnd);
   cout << "And now the first number = " << nFrst
        << " and the second number = " << nScnd;
   return 0;
}

//---------------------------------------------------------------------------------------
void zeroSmaller(int &nFirst, int &nSecond)
{
   if (nFirst > nSecond)
   {
      nSecond = 0;
   }
   else if (nSecond > nFirst)
   {
      nFirst = 0;
   }
}