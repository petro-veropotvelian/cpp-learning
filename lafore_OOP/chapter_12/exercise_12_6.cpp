// chapter_12_6.cpp
// Make a class called name from the data in Exercise 4 (first name, middle initial, last
// name, employee number). Create member functions for this class that read and write an
// object's data to a disk file, using ofstream, and read it back using ifstream. Use formatted
// data with the << and >> operators. The read and write member functions should
// be self-contained: they should include statements to open the appropriate stream and
// read or write a record.
// The write function can simply append its data to the end of the file. The read function
// will need a way to select which record it's going to read. One way to do this is to call it
// with a parameter representing the record number. Once it knows which record it should
// read, how does the read function find the record? You might think you could use the
// seekg() function, but that isn't much help because in formatted I/O the records are all
// different lengths (depending on the number of characters in the strings and the number
// of digits in the integer). So you'll need to actually read records until you've skipped forward
// to the one you want.
// In main(), call these member functions to allow the user to enter data for a number of
// objects that are written to a file as they are entered. The program then displays all this
// data by reading it from the file.
#include <iostream>
#include <fstream>
#include <string>
#include <process.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class name
{
private:
   string firstname;
   string middlename;
   string lastname;
   unsigned long empl_number;
   static const char* filename;
public:
   name()
   : empl_number(0)
   {}

   name(const string &fn, const string &mn, const string &ln, unsigned long en)
   : firstname(fn), middlename(mn), lastname(ln), empl_number(en)
   {}

   bool writeToFile();
   bool readFromFile(int index);
   void show();

   friend istream& operator >> (istream &is, name &nm);
   friend ostream& operator << (ostream &os, name &nm);

   static int getTotalNumberOfRecords();
};
//-----------------------------------------------------------------------------
const char* name::filename = "NAME.TXT";
//-----------------------------------------------------------------------------
void name::show()
{
    cout << "\n    First name: "      << firstname;
    cout << "\n    Middle name: "     << middlename;
    cout << "\n    Last name: "       << lastname;
    cout << "\n    Employee number: " << empl_number;
}
//-----------------------------------------------------------------------------
istream& operator >> (istream &is, name &nm)
{
    is >> nm.firstname;
    is >> nm.middlename;
    is >> nm.lastname;
    is >> nm.empl_number;
    return is;
}
//-----------------------------------------------------------------------------
ostream& operator << (ostream &os, name &nm)
{
   char chSPACE=' ';
   os << nm.firstname << chSPACE 
      << nm.middlename << chSPACE
      << nm.lastname << chSPACE
      << nm.empl_number << endl;
   return os;
}
//-----------------------------------------------------------------------------
bool name::writeToFile()
{
    bool bRet = true;
    ofstream outfile;
    outfile.open(name::filename, ios::app);
    if (!outfile)
    {
        cerr << "\nERROR! Unable to open " << name::filename << endl;
        outfile.close();
        bRet = false;
    }
    else
    {
        outfile << *this;
        outfile.close();
    }
    return bRet;
}
//-----------------------------------------------------------------------------
bool name::readFromFile(int index)
{
   bool bRet = true;
   ifstream ifile;
   ifile.open(name::filename);
   if (!ifile)
   {
      cerr << "\nERROR! Unable to open " << name::filename <<endl;
      ifile.close();
      bRet = false;
   }
   for (int nCount = 1; nCount <= index; nCount++)
   {
      ifile >> *this;
   }
   ifile.close();
   return bRet;
}
//-----------------------------------------------------------------------------
int name::getTotalNumberOfRecords()
{
    int nCount = 0;
    ifstream ifile;
    ifile.open(name::filename);
    if (!ifile)
    {
       cerr << "\nERROR! Unable to open " << name::filename <<endl;
       ifile.close();
    }
    name tmp;
    ifile >> tmp;
    while (!ifile.eof())
    {
        ifile >> tmp;
        nCount++;
    }
    ifile.close();
    return nCount;
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char answer;
   do 
   {
       string fname, mname, lname;
       unsigned long emp_n;
       cout << "\n    Enter first name: ";
       cin >> fname;
       cout << "    Enter middle name: ";
       cin >> mname;
       cout << "    Enter last name: ";
       cin >> lname;
       cout << "    Enter employee number: ";
       cin >> emp_n;
       name person(fname, mname, lname, emp_n);
       if (person.writeToFile())
       {
          cout << "\nEntered data has been successfully written to file.";
       }
       cout << "\nEnter another person (y/n)? ";
       cin >> answer;
   } while (answer!='n' && answer!='N');
   name tmp;
   int nTotal = name::getTotalNumberOfRecords();
   cout << "\nThere are "<< nTotal << " person's records currently in the file.";
   int nIndex;
   do
   {
      cout << "\nSpecify the record number to read: ";
      cin >> nIndex;
      if (tmp.readFromFile(nIndex))
      {
        tmp.show();
      }
      cout << "\nContinue (y/n)? ";
      cin >> answer;
   } while (answer=='Y' || answer=='y');
   return 0;
}