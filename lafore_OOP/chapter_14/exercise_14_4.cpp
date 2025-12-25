// exercise_14_4.cpp
// Create a function called swaps() that interchanges the values of the two arguments
// sent to it.
// (You will probably want to pass these arguments by reference.) Make the function
// into a template, so it can be used with all numerical data types (char, int, float,
//  and soon). Write a main() program to exercise the function with several types.
#include <iostream>
using namespace std;
template <class Type>
void swaps(Type &a, Type &b)
{
   Type tmp = a;
   a = b;
   b = tmp;

}
int main(int argc, char* argv[])
{
   float fA = 3.145;
   float fB = 5.56;
   swaps<float>(fA, fB);
   cout << "fA = " << fA << "; fB = " << fB << endl;
   char chA = 'A';
   char chB = 'B';
   swaps<char>(chA, chB);
   cout << "chA = " << chA << "; chB = " << chB << endl;
   return 0;
}