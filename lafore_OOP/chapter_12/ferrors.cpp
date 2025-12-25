// ferrors.cpp
// checks for errors opening file
#include <fstream>                                                   // for file functions
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   ifstream file;
   file.open("a:test.dat");
   if (!file)
   {
      cout << "\nCan't open a:test.dat";
   }
   else
   {
      cout << "\nFile opened successfully.";
   }
   //cout << "\nfile = " << file;
   cout << "\nError state = " << file.rdstate();
   cout << "\ngood() = " << file.good();
   cout << "\neof() = " << file.eof();
   cout << "\nfail() = " << file.fail();
   cout << "\nbad() = " << file.bad() << endl;
   file.close();
   return 0;
}