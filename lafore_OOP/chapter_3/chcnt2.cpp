// chcnt2.cpp
// counts characters and words typed in
#include <iostream>
#include <conio.h>               // for getche()
using namespace std;
int main(int argc, char* argv[])
{
   int chcount = 0;
   int wdcount = 1;                       // space between two words
   char ch;

   while ((ch = getche()) != '\r')        // loop until Enter typed
   {
      if (ch == ' ')                   // if it's a space
         wdcount++;                    // count a word
      else                             // otherwise,
         chcount++;                    // count a character
   }                                   // display results
   cout << "\nWords = " << wdcount << endl
        << "Letters = " << chcount << endl;
   return 0;
}