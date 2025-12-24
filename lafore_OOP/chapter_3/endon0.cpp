// endon0.cpp
// demonstrates WHILE loop
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   int n= 99;                    // make sure n isn't initialized to 0
   while (n!=0)
   {
      cin >> n;                  // loop until n is 0
   }
   cout << endl;                 // read a number into n
   return 0;
}