// prime.cpp
// demonstrates IF statement with prime numbers
#include <iostream>
#include <process.h>                                            // for exit()
using namespace std;
int main(int argc, char* argv[])
{
   int n;
   cout << "Enter a number: ";
   cin >> n;                                                   // get number to test
   for (int j=2; j <= n/2; j++)                                // divide be every integer from
      if (n%j == 0 )                                           // 2 on up; if remainder is 0,
      {                                                        // it's divisible by j
         cout << "It's not prime; divisible by " << j << endl;
         exit(0);                                              // exit from the program
      }
   cout << "It's prime\n";
   return 0;
}