// exercise_12_3.cpp
// Write a program that returns the size in bytes of a program (file)
// enterd on the command line
#include <iostream>
#include <fstream>
#include <process.h>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "\nFormat: exercise_12_3 filename";
        exit(-1);
    }
    ifstream infile;
    infile.open(argv[1]);
    if (!infile)
    {
        cerr << 
        "\nCan't open " << argv[1];
        exit(-1);
    }
    infile.seekg(0, ios::end);                                       // go to 0 bytes from end
    int endposition = infile.tellg();                                // find current position
    cout << "\nSize of " << argv[1] << " "
         << endposition << " bytes." << endl;
    return 0;
}