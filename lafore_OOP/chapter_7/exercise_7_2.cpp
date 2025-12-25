// exercise_7_2.cpp
// Create a class called employee that contains a name (an object of class
// string) and an employee number (type long). Include a member function called
// getdata() to get data from the user for insertion into the object, and
// another function called putdata() to display the data. Assume the name has
// no embedded blanks.
// Write a main() program to exercise this class. It should create an array of
// type employee, and then invite the user to input data for up to 100
// employees. Finally, it should print out the data for all the employees.
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class employee
{
private:
   string name;
   long   number;
public:
   void getdata();
   void putdata();
};
//---------------------------------------------------------------------------------------
void employee::getdata()
{
   cout << "\nSpecify employee's name: ";
   getline(cin, name);
   cout << "Enter employee's number: ";
   cin >> number;
   cin.get();
}
//---------------------------------------------------------------------------------------
void employee::putdata()
{
   cout << "Name: " << name << "   Number: " << number;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   employee emp[100];                                                // array of employees
   char ans;
   int n = 0;
   do
   {
      cout << "Enter employee number " << n+1;
      emp[n++].getdata();
      //cin.get();
      cout << "Enter another (y/n)?: ";
      cin >> ans;
      cin.get();
   } while (ans!='n' && ans!='N');
   for (int i=0; i<n; i++)
   {
      cout <<"\nEmploee number " << i+1 << endl;
      emp[i].putdata();
      cout << endl;
   }
   return 0;
}