// extern.cpp
// demonstrates global variables
#include <iostream>
#include <conio.h>                                 // for getch()
using namespace std;

char ch = 'a';                                     // global variables

void getachar();                                   // function declarations
void putachar();

int main(int argc, char*argv[])
{
   while (ch!='\r')                                // main() accesses ch
   {
      getachar();
      putachar();
   }
   cout << endl;
   return 0;
}
//---------------------------------------------------------------------------------------
void getachar()                                    // getachar() accesses ch
{
   ch = getch();
}
//---------------------------------------------------------------------------------------
void putachar()                                    // putachar() accesses ch
{
   cout << ch;
}