// exercise_6_6.cpp
// Extend the employee class of Exercise 4 to include a date class (see
// Exercise 5) and an etype enum (see Exercise 6 in Chapter 4). An object of
// the date class should be used to hold the date of first employment; that is,
// the date when the employee was hired. The etype variable should hold the
// employee's type: laborer, secretary, manager, and so on.
// These two items will be private member data in the employee definition, just
// like the employee number and salary. You'll need to extend the getemploy()
// and putemploy() functions to obtain this new information from the user and
// display it. These functions will probably need switch statements to handle
// the etype variable. Write a main() program that allows the user to enter
// data for three employee variables and then displays this data.
#include <iostream>
#include <windows.h>
using namespace std;

const int ARRSIZE = 7;
////////////////////////////////////////////////////////////////////////////////////////////////////
enum etype { undefined, laborer, secretary, manager, accountant, executive, researcher };
////////////////////////////////////////////////////////////////////////////////////////////////////
const char* szEmptype[ARRSIZE] = { "undefined", "laborer", "secretary", "manager",
                                   "accountant", "executive", "researcher" };
////////////////////////////////////////////////////////////////////////////////////////////////////
class date
{
private:
   int day;
   int month;
   int year;
public:
   date():day(0), month(0), year(0)
   {}
   date(const int nD, const int nM, const int nY)
      : day(nD), month(nM), year(nY)
   {}
   void getdate();
   void showdate() const;
};
/////////////////////////////////////////////////////////////////////////////////////////
class employee
{
private:
   int m_nNumber;
   float m_fCompensation;
   etype m_EmpType;
   date m_EmploymentDate;
public:
   employee() : m_nNumber(0), m_fCompensation(0.0), m_EmpType(etype::undefined), m_EmploymentDate()
   {}
   employee(const int nNumb, const float fSal, const etype Type, const date &empDate)
   : m_nNumber(nNumb), m_fCompensation(fSal), m_EmpType(Type), m_EmploymentDate(empDate)
   {}
   void getemploy() const;
   void putemploy();
};
//---------------------------------------------------------------------------------------
void date::getdate()
{
   char cDummy;
   cout << "Please specyfy a date (day/month/year): ";
   cin >> day >> cDummy >> month >> cDummy >> year;
}
//---------------------------------------------------------------------------------------
void date::showdate() const
{
   if (month < 10)
   {
      cout << "0";
   }
   cout << month << "/";
   if (day < 10)
   {
      cout << "0";
   }
   cout << day << "/" << year;
}
//---------------------------------------------------------------------------------------
void employee::putemploy()
{
   cout << "Specify number of the employee: ";
   cin >> m_nNumber;
   cout << "Specify compensation of the employee: $";
   cin >> m_fCompensation;
   cout << "Enter employee type (first letter only) (laborer, \n";
   cout << "secretary, manager, accountant, executive, researcher): ";
   char cEmplType;
   cin >> cEmplType;
   switch (cEmplType)
   {
      case 'l':
         m_EmpType = etype::laborer;
         break;
      case 's':
         m_EmpType = etype::secretary;
         break;
      case 'm':
         m_EmpType = etype::manager;
         break;
      case 'a':
         m_EmpType = etype::accountant;
         break;
      case 'e':
         m_EmpType = etype::executive;
         break;
      case 'r':
         m_EmpType = etype::researcher;
         break;
      default:
         m_EmpType = etype::undefined;
         break;
   }
   cout << "Please, enter employment date. ";
   m_EmploymentDate.getdate();
}
//---------------------------------------------------------------------------------------
void employee::getemploy() const
{
   cout <<"Employee number: " << m_nNumber << endl;
   cout <<"Employee's compensation: $" << m_fCompensation << endl;
   cout << "Employee type is " << szEmptype[m_EmpType] << "." << endl;
   cout << "Employment date is: ";
   m_EmploymentDate.showdate();
   cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   employee emp1, emp2, emp3;
   emp1.putemploy();
   emp2.putemploy();
   emp3.putemploy();
   cout << "Employee 1:\n";
   emp1.getemploy();
   cout << "Employee 2:\n";
   emp2.getemploy();
   cout << "Employee 3:\n";
   emp3.getemploy();
   return 0;
}