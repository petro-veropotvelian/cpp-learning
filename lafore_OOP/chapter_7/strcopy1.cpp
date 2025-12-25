// strcopy1.cpp
// copies a string using a for loop
#include <iostream>
#include <cstring>                                                   // fro strlen()
using namespace std;

int main(int argc, char* argv[])
{
   char str1[] = "Oh, Captain, my Captain "                          // initialized string
                 "out fearful trip is done";
   const int MAX = 80;                                               // size of str2 buffer
   char str2[MAX];                                                   // empty string
   int j;
   for (j=0; j < strlen(str1); j++)                                  // copy strlen characters
   {
      str2[j] = str1[j];                                             // from str1 to str2
   }
   str2[j] = '\0';                                                   // insert NULL at end
   cout << str2 << endl;                                             // display str2
   return 0;
}