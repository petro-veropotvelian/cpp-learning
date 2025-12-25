// exercise_12_4.cpp
// In a loop, prompt the user to enter name data consisting of a first name, middle initial,
// last name, and employee number (type unsigned long). Then, using formatted I/O with
// the insertion (<<) operator, write these four data items to an ofstream object. Don't forget
// that strings must be terminated with a space or other whitespace character. When the
// user indicates that no more name data will be entered, close the ofstream object, open
// an ifstream object, read and display all the data in the file, and terminate the program.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char*argv[])
{
    char answer;
    string firstname;
    string middlename;
    string lastname;
    unsigned long empl_number;
    const char chSPACE = ' ';
    ofstream outfile("PERSON.DAT", ios::trunc);
    cout << "Please, enter person data:";
    do 
    {
        cout << "\n    Enter first name: ";
        cin >> firstname;
        cout << "    Enter middle name: ";
        cin >> middlename;
        cout << "    Enter last name: ";
        cin >> lastname;
        cout << "    Enter employee number: ";
        cin >> empl_number;
        outfile << firstname << chSPACE
                << middlename << chSPACE
                << lastname << chSPACE
                << empl_number << endl;
        cout << "Enter another person (y/n)? ";
        cin >> answer;
    } while (answer!='n' && answer!='N');
    ifstream infile("PERSON.DAT");
    cout << "\nDisplaying persons list\n";
    infile >> firstname;
    infile >> middlename;
    infile >> lastname;
    infile >> empl_number;
    while (infile)
    {
        cout << "\n    First name: "      << firstname;
        cout << "\n    Middle name: "     << middlename;
        cout << "\n    Last name: "       << lastname;
        cout << "\n    Employee number: " << empl_number;
        infile >> firstname;
        infile >> middlename;
        infile >> lastname;
        infile >> empl_number;
    }
    return 0;
}