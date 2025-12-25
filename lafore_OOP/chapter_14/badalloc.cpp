// badalloc.cpp
// demonstrates bad_alloc exception
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   const unsigned long SIZE = 1000000000;                            // memory size
   char* ptr;                                                        // pointer to memory
   try
   {
      ptr = new char[SIZE];                                          // allocate SIZE bytes
   }
   catch (bad_alloc)                                                 // exception handler
   {
      cout << "\nbad_alloc exception: can't allocate memory.\n";
      return (1);
   }
   delete[] ptr;
   cout << "\nMemory use is successful.\n";
   return 0;
}