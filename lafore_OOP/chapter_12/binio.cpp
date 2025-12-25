// binio.cpp
// binary input and output with integers
#include <fstream>                                                   // binary input and output with integers
#include <iostream>
using namespace std;
const int MAX = 100;                                                 // size of buffer
int buff[MAX];                                                       // buffer of integers

int main(int argc, char*argv[])
{
   for (int j=0; j < MAX; j++)                                       // fill buffer with data
   {
      buff[j] = j;                                                   // (0, 1, 2 ...)
   }
   ofstream os("edata.dat", ios::binary);                            // create output streambuf
   os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));       // write to iter_swap
   os.close();                                                       // must close it

   for (int j=0; j<MAX; j++)
   {
      buff[j] = 0;                                                   // erase buffer
   }
   ifstream is("edata.dat", ios::binary);                            // create input stream
   is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
   for (int j=0; j < MAX; j++)
   {
      if (buff[j] != j)                                              // check data
      {
         cerr << "Data is incorrect\n";
         return 1;
      }
   }
   cout << "Data is correct\n";
   return 0;
}