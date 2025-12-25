// eimpl_io.cpp
// performs file I/O on employee objects
// handles different sized objects
#include <fstream>                                                   // for file-stream functions
#include <iostream>
#include <typeinfo>                                                  // for typeid()
#include <process.h>                                                 // for exit()
using namespace std;

const int LEN = 32;                                                  // maximum length of last names
const int MAXEM = 100;                                               // maximum numbers of employees

enum employee_type {tmanager, tscientist, tlaborer};
///////////////////////////////////////////////////////////////////////////////
class employee                                                       // employee class
{
private:
   char name[LEN];                                                   // employee name
   unsigned long number;                                             // employee number
   static int n;                                                     // current number of employees
   static employee* arrap[];                                         // array of pointers to emps
public:
   virtual void getdata()
   {
      cin.ignore(10, '\n');
      cout << "   Enter last name: ";
      cin >> name;
      cout << "   Enter number: ";
      cin >> number;
   }
   virtual void putdata() const
   {
      cout << "\n   Name: " << name;
      cout << "\n   Number: " << number;
   }
   virtual employee_type get_type();                                 // get type
   static void add();                                                // add an employee
   static void display();                                            // display all employees
   static void read();                                               // read from disk file
   static void write();                                              // write to disk file
};
//-----------------------------------------------------------------------------
// static variables
int employee::n;                                                     // current number of employees
employee* employee::arrap[MAXEM];                                    // array of pointers to emps
///////////////////////////////////////////////////////////////////////////////
class manager : public employee                                      // managament class
{
private:
   char title[LEN];                                                  // "vice-president" etc.
   double dues;                                                      // golf club dues
public:
   void getdata()
   {
      employee::getdata();
      cout << "   Enter title: ";
      cin >> title;
      cout << " Enter golf club dues: ";
      cin >> dues;
   }
   void putdata() const
   {
      employee::putdata();
      cout << "\n   Title: " << title;
      cout << "\n   Golf club dues: " << dues;
   }
};
///////////////////////////////////////////////////////////////////////////////
class scientist : public employee                                    // scientist class
{
private:
   int pubs;                                                         // number of pulications
public:
   void getdata()
   {
      employee::getdata();
      cout << "   Enter number of publications: ";
      cin >> pubs;
   }
   void putdata()
   {
      employee::putdata();
      cout << "\n   Number of publications: " << pubs;
   }
};
///////////////////////////////////////////////////////////////////////////////
class laborer : public employee                                      // laborer class
{
};
///////////////////////////////////////////////////////////////////////////////
// add employee to list in memory
void employee::add()
{
   char ch;
   cout << "'m' to add a manager"
           "\n's' to add a scientist"
           "\n'l' to add a laborer"
           "\nEnter selection: ";
   cin >> ch;
   switch (ch)                                                       // create specified employee type
   {
      case 'm': arrap[n] = new manager;      break;
      case 's': arrap[n] = new scientist;    break;
      case 'l': arrap[n] = new laborer;      break;
      default: cout << "\nUnknown employee type\n";    return;
   }
   arrap[n++]->getdata();                                            // get employee data from user
}
//-------------------------------------------------------------------
// display all employees
void employee::display()
{
   for (int j=0; j<n; j++)
   {
      cout << (j+1);                                                 // display number
      switch (arrap[j]->get_type())                                  // display type
      {
         case tmanager:
            cout << ". Type: Manager";
            break;
         case tscientist:
            cout << ". Type: Scientist";
            break;
         case tlaborer:
            cout << ". Type: Laborer";
            break;
         default:
            cout << ". Unknown type";
      }
      arrap[j]->putdata();                                           // display employee data
      cout << endl;
   }
}
//-------------------------------------------------------------------
// return the type of this object
employee_type employee::get_type()
{
   if (typeid(*this) == typeid(manager))
   {
      return tmanager;
   }
   else if (typeid(*this) == typeid(scientist))
   {
      return tscientist;
   }
   else if (typeid(*this) == typeid(laborer))
   {
      return tlaborer;
   }
   else
   {
      cerr << "\nBad employee type";
      exit(1);
   }
   return tmanager;
}
//-------------------------------------------------------------------
// write all current memory objects to file
void employee::write()
{
   int size;
   cout << "Writing " << n << " employees.\n";
   ofstream ouf;                                                     // open ofstream in binary
   employee_type etype;                                              // type of each employee object

   ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
   if (!ouf)
   {
      cout << "\nCan't open file\n";
      return;
   }
   for (int j=0; j<n; j++)                                           // for every employee object
   {
      etype = arrap[j]->get_type();                                  // get its type
      ouf.write((char*)&etype, sizeof(etype));                       // write type to file
      switch (etype)
      {
         case tmanager:
            size = sizeof(manager);
            break;
         case tscientist:
            size = sizeof(scientist);
            break;
         case tlaborer:
            size = sizeof(laborer);
            break;
      }
      ouf.write((char*)(arrap[j]), size);                            // write employee object to file
      if (!ouf)
      {
         cout << "\nCan't write to file\n";
         return;
      }
   }
}
//-------------------------------------------------------------------
// read data for all employees from file into memory
void employee::read()
{
   int size;                                                         // size of employee object
   employee_type etype;                                              // type of employee
   ifstream inf;                                                     // open ifstream in binary
   inf.open("EMPLOY.DAT", ios::binary);
   if (!inf)
   {
      cout << "\nCan't open file\n";
      return;
   }
   n = 0;                                                            // no employees in memory yet
   while (true)
   {
      inf.read((char*)&etype, sizeof(etype));                        // read type on next employee
      if (inf.eof())
      {
         break;                                                      // quit loop on eof
      }
      if (!inf)
      {
         cout << "\nCan't read type from file\n";                    // error reading type
         return;
      }
      switch (etype)                                                 // make new employee
      {                                                              // of a correct type
         case tmanager:
            arrap[n] = new manager;
            size = sizeof(manager);
            break;
         case tscientist:
            arrap[n] = new scientist;
            size = sizeof(scientist);
            break;
         case tlaborer:
            arrap[n] = new laborer;
            size = sizeof(laborer);
            break;
         default:
            cout << "\nUnknown type in file\n";
            return;
      }
      inf.read((char*)arrap[n], size);                               // read data from file into it
      if (!inf)
      {
         cout << "\nCan't read data from file\n";                    // error but not eof
         return;
      }
      n++;                                                           // count employee
   }                                                                 // end while
   cout << "Rading " << n << " employees\n";
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char ch;
   while (true)
   {
      cout << "'a'  -- add data for an employee"
              "\n'd'  -- display data for all employess"
              "\n'w'  -- write all employee data to file"
              "\n'r'  -- read all employee data from file"
              "\n'x'  -- exit"
              "\nEnter selection: ";
      cin >> ch;
      switch (ch)
      {
         case 'a':
            employee::add();                                         // add an amployee to lost
            break;
         case 'd':
            employee::display();                                     // display all employees
            break;
         case 'w':
            employee::write();                                       // write employees to file
            break;
         case 'r':
            employee::read();                                        // read all employees from file
            break;
         case 'x':
            exit(0);                                                 // exit program
         default:
            cout << "\nUnknown command";
      } // endl switch
   } // end while
   return 0;
}