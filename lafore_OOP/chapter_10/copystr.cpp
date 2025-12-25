// copystr.cpp
// copies one string to another with pointers
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   void copystr(char*, const char*);                        // prototype
   char* str1 = "Self-conquest is the greatest victory.";
   char str2[80];                                           // empty string

   copystr(str2, str1);                                     // copy str1 to str2
   cout << str2 << endl;
   return 0;
}
//------------------------------------------------------------------------------------
void copystr(char* dest, const char* src)
{
   while (*src)                                             // until null character,
   {
      *dest++ = *src++;                                     // copy chars from src to dest
   }
   *dest = '\0';                                            // terminated dest
}
