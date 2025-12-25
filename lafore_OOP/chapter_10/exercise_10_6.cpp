// exercise_10_6.cpp
// Make your own version of the library function strcmp(s1, s2), which compares
// two strings and returns –1 if s1 comes first alphabetically, 0 if s1 and s2
// are the same, and 1 if s2 comes first alphabetically. Call your function
// compstr(). It should take two char* strings as arguments, compare them
// character by character, and return an int. Write a main() program to test
// the function with different combinations of strings. Use pointer notation
// throughout.
#include <iostream>
using namespace std;
int my_strcmp(const char* szFirst, const char* szSecond)
{
   while (*szFirst)
   {
      if (*szFirst!= *szSecond)
      {
         break;
      }
      szFirst++;
      szSecond++;
   }
   return *(const unsigned char*)szFirst - *(const unsigned char*)szSecond;
}

int main(int argc, char* argv[])
{
   char* A = "Apricot";
   char* B = "Africa";
   int nRes = my_strcmp(A, B);
   if (nRes < 0)
   {
      cout << "String \"" << A << "\" is less than \"" << B << "\".\n";
   }
   else if (nRes > 0)
   {
      cout << "String \"" << A << "\" is greater than \"" << B << "\".\n";
   }
   else
   {
      cout << "Strings \"" << A << "\" and \"" << B << "\" are equal.\n";
   }
   return 0;
}