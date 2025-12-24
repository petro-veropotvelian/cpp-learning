// ifdemo.cpp
// demonstrates IF statement
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   int x;
   cout << "Enter a number: ";
   cin >> x;
   if (x > 100)
      cout << "That number is greater than 100\n";
   return 0;
}