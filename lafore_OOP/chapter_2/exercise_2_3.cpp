// exercise_2_3.cpp
// Write a program that generates the following output:
// 10
// 20
// 19
// Use an integer constant for the 10, an arithmetic assignment operator to
// generate the 20, and a decrement operator to generate the 19.
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   short nVariable = 10;
   cout << nVariable << endl;
   nVariable *= 2;
   cout << nVariable << endl;
   nVariable--;
   cout << nVariable << endl;
   return 0;
}