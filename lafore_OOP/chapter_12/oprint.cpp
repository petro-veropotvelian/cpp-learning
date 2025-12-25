// oprint.cpp
// imitates PRINT command
#include <fstream>                                                   // for file functions
#include <iostream>
#include <process.h>                                                 // for exit()
using namespace std;

int main(int argc, char*argv[])
{
    if (argc!=2)
    {
        cerr << "\nFormat: oprint filename";
        exit(-1);
    }
    char ch;                                                         // character to read
    ifstream infile;                                                 // create file for input
    infile.open(argv[1]);                                            // open file
    if (!infile)                                                     // check for errors
    {
        cerr <<"\nCan't open " << argv[1];
        exit(-1);
    }
    ofstream outfile;                                                // make file
    outfile.open("PRN");                                             // open it for printer
    //while (infile.get(ch)!=0)                                        // read a characte
    //{
    //    outfile.put(ch);                                             // write character to printer
    //}
    outfile << infile.rdbuf();                                      // corrected way to read data from file
    outfile.put('\x0C');                                            // formfeed to eject page
    return 0;
}