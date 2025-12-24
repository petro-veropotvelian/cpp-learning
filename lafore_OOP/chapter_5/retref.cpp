// retref.cpp
// returning reference values
#include <iostream>
using namespace std;
int x;                                             // global variable
int& setx();                                       // function declaration

int main(int argc, char* argv[])
{
   setx() = 92;                                    // set x to a value, using function call
                                                   // on left side
   cout << "x = " << x << endl;                    // display new value in x
   return 0;
}
//---------------------------------------------------------------------------------------
int& setx()
{
   return x;                                       // returns the value to be modified
}