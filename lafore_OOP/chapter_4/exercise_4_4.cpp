// exercise_4_4.cpp
// Create a structure called employee that contains two members: an employee
// number (type int) and the employee’s compensation (in dollars; type float).
// Ask the user to fill in this data for three employees, store it in three
// variables of type struct employee, and then display the information for each
// employee.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////
struct employee
{
   int type;
   float compensation;
};
////////////////////////////////////////////////////////////////////
void fillData(employee& emp, const char* szPos)
{
   cout << "Specify type of the " << szPos << " employee: ";
   cin >> emp.type;
   cout << "Specify compensation of the " << szPos << " employee: $";
   cin >> emp.compensation;
}

void getData(const employee& emp, const char* szPos)
{
   cout <<"Type of the " << szPos << " employee: ";
   cout << emp.type << endl;
   cout << "Compensation of the " << szPos << " employee: ";
   cout << emp.compensation << "$" << endl;
}
////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   employee emp1, emp2, emp3;
   fillData(emp1, "first");
   fillData(emp2, "second");
   fillData(emp3, "third");
   cout << "Here are the results:\n";
   getData(emp1, "first");
   getData(emp2, "second");
   getData(emp3, "third");
   return 0;
}