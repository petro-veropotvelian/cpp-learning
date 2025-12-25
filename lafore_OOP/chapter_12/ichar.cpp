// ichar.cpp
// file input with characters
#include <fstream>                                                   // for file functions
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   char ch;                                                          // character to read
   ifstream infile("TEST1.TXT");                                     // create file for input
   while (infile)                                                    // read until EOR or error
   {
      infile.get(ch);                                                // read character
      cout << ch;                                                    // display it
   }
   cout << endl;
   return 0;
}