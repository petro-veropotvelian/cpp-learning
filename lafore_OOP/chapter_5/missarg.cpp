// missarg.cpp
// demonstrates missing and default argument
#include <iostream>
using namespace std;

void repchar(char = '*', int = 45);                // declaration with
                                                   // default arguments

int main(int argc, char* argv[])
{
   repchar();                                      // prints 45 asterisks
   repchar('=');                                   // prints 45 equal singns
   repchar('+', 30);                               // prints 30 plus sings
   return 0;
}
//---------------------------------------------------------------------------------------
// repchar()
// displays line of characters
void repchar(char ch, int n)                       // defaults supplied
{                                                  // if necessary
   for (int j=0; j < n; j++)                       // loops n times
   {
      cout << ch;                                  // prints ch
   }
   cout << endl;
}