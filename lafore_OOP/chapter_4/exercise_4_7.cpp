// exercise_4_7.cpp
// Add a variable of type enum etype (see Exercise 6), and another variable of
// type struct date (see Exercise 5) to the employee class of Exercise 4.
// Organize the resulting program so that the user enters four items of
// information for each of three employees: an employee number, the employee's
// compensation, the employee type, and the date of first employment. The 
// program should store this information in three variables of type employee,
// and then display their contents.
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ARRSIZE = 6;
////////////////////////////////////////////////////////////////////////////////////////////////////
enum etype { laborer, secretary, manager, accountant, executive, researcher };
////////////////////////////////////////////////////////////////////////////////////////////////////
const char* szEmptype[ARRSIZE] = { "laborer", "secretary", "manager", "accountant", "executive", "researcher" };
////////////////////////////////////////////////////////////////////////////////////////////////////
struct date
{
   int day;
   int month;
   int year;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
struct employee
{
   int number;
   float compensation;
   etype type;
   date first_empl_date;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
void FillEmployeeStructure(employee& emp);
void ObtainEmployeeInfo(const employee& emp);
int main(int argc, char* argv[])
{
   employee empA, empB, empC;
   cout << "Please, enter the information about three employees." <<endl;
   cout << "First employee." <<endl;
   FillEmployeeStructure(empA);
   cout << "Second employee." <<endl;
   FillEmployeeStructure(empB);
   cout << "Third employee." <<endl;
   FillEmployeeStructure(empC);
   cout << "You have entered the following data:\n";
   cout << "First employee:\n";
   ObtainEmployeeInfo(empA);
   cout << "Second employee:\n";
   ObtainEmployeeInfo(empB);
   cout << "Third employee:\n";
   ObtainEmployeeInfo(empC);
   return 0;
}

void FillEmployeeStructure(employee& emp)
{
   cout << "Specify employee's number: ";
   cin >> emp.number;
   cout << "Specify compensation of the employee: $";
   cin >> emp.compensation;
   cout << "Enter employee's type (first letter only) (laborer, \n";
   cout << "secretary, manager, accountant, executive, researcher): ";
   char cEmplType;
   cin >> cEmplType;
   short sEmployee;
   switch (cEmplType)
   {
      case 'l':
         emp.type = etype::laborer;
         break;
      case 's':
         emp.type = etype::secretary;
         break;
      case 'm':
         emp.type = etype::manager;
         break;
      case 'a':
         emp.type = etype::accountant;
         break;
      case 'e':
         emp.type = etype::executive;
         break;
      case 'r':
         emp.type = etype::researcher;
         break;
      default:
         break;
   }
   char cDummy;
   cout << "Specify the date of the employee's first employment (day/month/year): ";
   cin >> emp.first_empl_date.day >> cDummy >> emp.first_empl_date.month >> cDummy >> emp.first_empl_date.year;
}
void ObtainEmployeeInfo(const employee& emp)
{
   cout << "Emloyee's number: " << emp.number << endl;
   cout << "Emloyee's compensation: $" << emp.compensation <<  endl;
   cout << "Emloyee type: " << szEmptype[emp.type] << endl;
   const char cDummnyChar = '/';
   cout << "Date of the employee's first employment: ";
   cout << emp.first_empl_date.day << cDummnyChar << emp.first_empl_date.month << cDummnyChar << emp.first_empl_date.year << endl;
}