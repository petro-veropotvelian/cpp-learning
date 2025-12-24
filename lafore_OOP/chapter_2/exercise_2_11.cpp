// exercise_2_11.cpp
// By default, output is right-justified in its field. You can left-justify
// text output using the manipulator setiosflags(ios::left). (For now, don't
// worry about what this new notation means.) Use this manipulator, along with
// setw(), to help generate the following output:
// Last name   First name  Street address      Town         State
// --------------------------------------------------------------
// Jones       Bernard     109 Pine Lane       Littletown   MI
// O'Brian     Coleen      42 E. 99th Ave.     Bigcity      NY
// Wong        Harry       121-A Alabama St.   Lakeville    IL
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char* argv[])
{
   const short nLNW = 12;  // Last name width
   const short nFNW = 12;  // First name width
   const short nSAW = 18;  // Street adress width
   const short nTW = 12;   // Town width
   const short nSW = 6;    // State width
   cout << setiosflags(ios::left);
   cout << setw(nLNW)<<"Last name" << setw(nFNW) << "First name" 
   << setw(nSAW) << "Street adress" << setw(nTW)<< "Town" << setw(nSW) << "State" << endl;
   cout << resetiosflags(ios::right);
   cout << setfill('.') << setw(nLNW) <<'.' << setw(nFNW)<< '.'<< setw(nSAW) << '.'
   << setw(nTW) << '.' << setw (nSW) << '.' << endl;
   cout << setfill(' ');
   cout << setiosflags(ios::left);
   cout << setw(nLNW) << "Jones" << setw(nFNW) << "Bernard" << setw(nSAW) 
   << "109 Pine Lane" << setw(nTW) << "Littletown" << setw(nSW) << "MI" << endl;
   cout << setw(nLNW) << "O'Brian" << setw(nFNW) << "Coleen" << setw(nSAW) 
   << "42 E. 99th Ave." << setw(nTW) << "Bigcity" << setw(nSW) << "NY" << endl;
   cout << setw(nLNW) << "Wong" << setw(nFNW) << "Harry" << setw(nSAW) 
   << "121-A Alabama St." << setw(nTW) << "Lakeville" << setw(nSW) << "IL" << endl;
   return 0;
}