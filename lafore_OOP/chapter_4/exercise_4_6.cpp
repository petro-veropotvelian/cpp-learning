// exercise_4_6.cpp
// We said earlier that C++ I/O statements don't automatically understand the
// data types of enumerations. Instead, the (>>) and (<<) operators think of
// such variables simply as integers. You can overcome this limitation by using
// switch statements to translate between the user's way of expressing an
// enumerated variable and the actual values of the enumerated variable. For 
// example, imagine an enumerated type with values that indicate an employee
// type within an organization:
// enum etype { laborer, secretary, manager, accountant, executive,
//              researcher };
// Write a program that first allows the user to specify a type by entering its
// first letter ('l', 's', 'm', and so on), then stores the type chosen as a
//  value of a variable of type enum etype, and finally displays the complete
// word for this type.
//    Enter employee type (first letter only)
//          laborer, secretary, manager,
//          accountant, executive, researcher): a
//    Employee type is accountant.
// You’ll probably need two switch statements: one for input and one for
// output.
#include <iostream>
using namespace std;
const int ARRSIZE = 6;
////////////////////////////////////////////////////////////////////////////////////////////////////
enum etype { laborer, secretary, manager, accountant, executive, researcher };
////////////////////////////////////////////////////////////////////////////////////////////////////
const char* szEmptype[ARRSIZE] = { "laborer", "secretary", "manager", "accountant", "executive",
                                   "researcher" };
////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
   cout << "Enter employee type (first letter only) (laborer, \n";
   cout << "secretary, manager, accountant, executive, researcher): ";
   char cEmplType;
   cin >> cEmplType;
   short sEmployee;
   switch (cEmplType)
   {
      case 'l':
         sEmployee = etype::laborer;
         break;
      case 's':
         sEmployee = etype::secretary;
         break;
      case 'm':
         sEmployee = etype::manager;
         break;
      case 'a':
         sEmployee = etype::accountant;
         break;
      case 'e':
         sEmployee = etype::executive;
         break;
      case 'r':
         sEmployee = etype::researcher;
         break;
      default:
         break;
   }
   cout << "Employee type is " << szEmptype[sEmployee] << "." << endl;
   return 0;
}