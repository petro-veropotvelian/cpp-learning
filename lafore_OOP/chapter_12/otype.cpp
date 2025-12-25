// otype.cpp
// imitates TYPE command
#include <fstream>                                                   // for file instructions
#include <iostream>
#include <process.h>                                                 // for exit()
using namespace std;

int main(int argc, char*argv[])
{
    if (argc!=2)
    {
        cerr << "\nFormat: otype filename";
        exit(-1);
    }
    char ch;                                                         // character to read
    ifstream infile;                                                  // create a file to input
    infile.open(argv[1]);                                            // open file
    if (!infile)                                                     // check for errors
    {
        cerr << "\nCan't open " << argv[1];
        exit(-1);
    }
    //while (infile.get(ch) != 0)                                      // read a character
    //{
    //    cout << ch;                                                  // display the character
    //}
    cout << infile.rdbuf();                                            // correct way (condition in while() loop doesn't work)
    return 0;
}
