// exercise_6_4.cpp
// Create an employee class, basing it on Exercise 4 of Chapter 4. The member
// data should comprise an int for storing the employee number and a float for
// storing the employee's compensation. Member functions should allow the user
// to enter this data and display it.
// Write a main() that allows the user to enter data for three employees and
// display it.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class employee
{
private:
   int m_nNumber;
   float m_fCompensation;
public:
   employee() : m_nNumber(0), m_fCompensation(0.0)
   {}
   employee(const int nNumb, const float fSal)
   : m_nNumber(nNumb), m_fCompensation(fSal)
   {}
   void show_employee() const;
   void set_number(const int nNumb);
   void set_compensation(const float fCompensation);
   void set_employee();
   int get_number() const;
   float get_compensation() const;
};
//---------------------------------------------------------------------------------------
void employee::show_employee() const
{
   cout <<"Employee number: " << m_nNumber << endl;
   cout <<"Employee's compensation: $" << m_fCompensation << endl;
}
//---------------------------------------------------------------------------------------
void employee::set_employee()
{
   cout << "Specify number of the employee: ";
   cin >> m_nNumber;
   cout << "Specify compensation of the employee: $";
   cin >> m_fCompensation;
}
//---------------------------------------------------------------------------------------
void employee::set_number(const int nNumb)
{
   m_nNumber = nNumb;
}
//---------------------------------------------------------------------------------------
void employee::set_compensation(const float fCompensation)
{
   m_fCompensation = fCompensation;
}
//---------------------------------------------------------------------------------------
int employee::get_number() const
{
   return m_nNumber;
}
//---------------------------------------------------------------------------------------
float employee::get_compensation() const
{
   return m_fCompensation;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   employee emp1;
   emp1.set_number(13);
   emp1.set_compensation(1345.78);
   employee emp2(118, 2310.17);
   employee emp3;
   emp3.set_employee();
   cout << "Employee 1:\n";
   emp1.show_employee();
   cout << "Employee 2:\n";
   emp2.show_employee();
   cout << "Employee 3:\n";
   emp3.show_employee();
   return 0;
}