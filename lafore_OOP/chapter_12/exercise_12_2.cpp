// exercise_12_2.cpp
// write a program that emulates the DOS COPY command
#include <iostream>
#include <fstream>
#include <process.h>
using namespace std;

int main(int argc, char*argv[])
{
    if (argc!=3)
    {
        cerr << "\nFormat: exercise_12_2 srcfilename.txt dstfilename.txt";
        exit(-1);
    }
    char ch;                                                         // symbol for reading
    ifstream infile;                                                  // create file for input
    infile.open(argv[1]);                                            // open file
    if (!infile)                                                      // check for errors
    {
        cerr << "\nCan't open "<< argv[1];
        exit(-1);
    }
    ofstream outfile;                                                // create steam for output
    outfile.open(argv[2]);
    if (!outfile)
    {
        cerr << "\nCan't open "<< argv[2];
        exit(-1);
    }
    outfile << infile.rdbuf();
    cout << "\nData from " << argv[1] << " succesfully copied "
         << "to " << argv[2] << endl;
    return 0;
}
