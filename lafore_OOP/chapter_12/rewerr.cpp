// rewerr.cpp
// handles errors during input and output
#include <fstream>                                                   // for file streams
#include <iostream>
#include <process.h>                                                 // for exit()
using namespace std;

const int MAX = 1000;
int buff[MAX];

int main(int argc, char* argv[])
{
   for (int j=0; j<MAX; j++)                                         // fill buffer with data
   {
      buff[j] = j;
   }
   ofstream os;                                                      // create output stream
   os.open("a_edata.dat", ios::trunc | ios::binary);                 // open it
   if (!os)
   {
      cerr << "Could not open output file\n";
      exit(1);
   }
   cout << "Writing...\n";                                           // write buffer to it
   os.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));
   if (!os)
   {
      cerr << "Could not write to file\n";
      exit(1);
   }
   os.close();                                                       // must close it

   for (int j=0; j<MAX; j++)
   {
      buff[j] = 0;                                                   // clear buffer
   }
   ifstream is;                                                      // create input stream
   is.open("a_edata.dat", ios::binary);
   if (!is)
   {
      cerr << "Could not open input file\n";
      exit(1);
   }
   cout << "Reading...\n";
   is.read(reinterpret_cast<char*>(buff), MAX*sizeof(int));          // read file
   if (!is)
   {
      cerr << "Could not read from file\n";
      exit(1);
   }
   for (int j=0; j<MAX; j++)
   {
      //cout << "buff["<<j<<"] = " << buff[j] << endl;
      if (buff[j] != j)                                              // check data
      {
         cerr << "\nData is incorrect\n";
         exit(1);
      }
   }
   cout << "Data is correct\n";
   return 0;
}