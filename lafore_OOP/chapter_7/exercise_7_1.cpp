// exercise_7_1.cpp
// Write a function called reversit() that reverses a C-string (an array of
// char). Use a for loop that swaps the first and last characters, then the
// second and next-to-last characters, and so on. The string should be passed
// to reversit() as an argument.
// Write a program to exercise reversit(). The program should get a string from
// the user, call reversit(), and print out the result. Use an input method
// that allows embedded blanks. Test the program with Napoleon's famous phrase,
// "Able was I ere I saw Elba."
#include <iostream>
#include <cstring>
using namespace std;

void reversit(char* arr);

int main(int argc, char* argv[])
{
   const int MAX = 2000;
   char charr[MAX];
   cout << "Please, enter a string: ";
   cin.get(charr, MAX);
   reversit(charr);
   cout << "Reversed string: ";
   cout << charr << endl;
   return 0;
}

void reversit(char* arr)
{
   int len = strlen(arr);
   for (int i=0; i<len/2; i++)
   {
      char tmp = arr[i];
      arr[i] = arr[len -1 -i];
      arr[len -1 -i] = tmp;
   }
}