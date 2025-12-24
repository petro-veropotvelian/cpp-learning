// chcount.cpp
// counts characters and words typed in 
#include <iostream>
#include <conio.h>                  // for getche()
using namespace std;

int main(int argc, char* argv[])
{
   int chcount = 0;                             // counts non-space characters
   int wdcount = 1;                             // counts spaces between words
   char ch = 'a';                               // ensure it int's '\r'

   cout << "Enter a phrase: ";
   while (ch != '\r')
   {
      ch = getche();
      if (ch==' ')
         wdcount++;
      else
         chcount++;
   }
   cout << "\nWords = " << wdcount << endl;
   cout << "Letters = " << (chcount - 1) << endl;
   return 0;
}