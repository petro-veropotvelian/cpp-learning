// exercise_12_7.cpp
// Another approach to adding file stream I/O to an object is to make the file stream itself
// a static member of the object. Why do that? Well, it's often conceptually easier to think
// of the stream as being related to the class as a whole than to the individual objects of
// the class. Also, it's more efficient to open a stream only once, then read and write
// objects to it as needed. For example, once the file is opened, each time the read function
// is called it can return the data for the next object in the file. The file pointer will
// progress automatically through the file because the file is not closed between reads.
// Rewrite the program in Exercises 4 and 6 to use an fstream object as a static data item
// of the name class. Keep the same functionality that is in those exercises. Write a static
// function to open this stream, and another static function to reset the file pointer to the
// beginning of the file. You can use this reset function when you're done writing and want
// to read all the records back from the file.
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
   static fstream service_file;
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
   static bool openFile();
   static void closeFile();
   static void resetFilePointer();
};
//-----------------------------------------------------------------------------
fstream name::service_file;
//-----------------------------------------------------------------------------
const char* name::filename = "NAME_FL.TXT";
//-----------------------------------------------------------------------------
bool name::openFile()
{
   bool bIsOK = true;
   name::service_file.open(name::filename, ios::in | ios::out | ios::app);
   if (!name::service_file)
   {
      name::service_file.close();
      cerr << "\nERROR! Can't open " << name::filename << endl;
      bIsOK = false;
   }
   return bIsOK;
}
//-----------------------------------------------------------------------------
void name::closeFile()
{
   name::service_file.close();
}
//-----------------------------------------------------------------------------
void name::resetFilePointer()
{
   name::service_file.seekg(0);
}
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
   if (!name::service_file)
   {
      cerr << "\nERROR! Unable to write record to " << name::filename << endl;
      bRet = false;
   }
   else
   {
      name::service_file << *this;
   }
   return bRet;
}
//-----------------------------------------------------------------------------
bool name::readFromFile(int index)
{
   bool bRet = true;
   if (!name::service_file)
   {
      cerr << "\nERROR! Unable to open " << name::filename << endl;
      bRet = false;
   }
   else
   {
      for (int nCount = 1; nCount <= index; nCount++)
      {
         name::service_file >> *this;
      }
   }
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
   if (!name::openFile())
   {
      cerr << "\nProgram abrnormally terminated." << endl;
      exit(-1);
   }
   else
   {
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
         name::resetFilePointer();
         cout << "\nSpecify the record number to read: ";
         cin >> nIndex;
         if (tmp.readFromFile(nIndex))
         {
           tmp.show();
         }
         cout << "\nContinue (y/n)? ";
         cin >> answer;
      } while (answer=='Y' || answer=='y');
      name::closeFile();
   }
   return 0;
}