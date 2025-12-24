// exercise_5_8.cpp
// Write a function called swap() that interchanges two int values passed to it
// by the calling program. (Note that this function swaps the values of the
// variables in the calling program, not those in the function.) You'll need to
// decide how to pass the arguments. Create a main() program to exercise the
// function.
#include <iostream>
using namespace std;

void swap(int &nFrst, int &nScnd);

/////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
   int nA, nB;
   cout << "Please, specify the first variable: ";
   cin >> nA;
   cout << "Please, specify the second variable: ";
   cin >> nB;
   swap(nA, nB);
   cout << "SWAP!" << endl;
   cout << "And now the first variable = " << nA;
   cout << " and the second variable = " << nB;
   return 0;
}

//---------------------------------------------------------------------------------------
void swap(int &nFrst, int &nScnd)
{
   int tmp = nFrst;
   nFrst = nScnd;
   nScnd = tmp;
}