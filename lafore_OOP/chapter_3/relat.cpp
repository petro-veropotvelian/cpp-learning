// relat.cpp 
// demonstrates relation operators
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   int numb;
   cout << "Enter a number: ";
   cin >> numb;
   cout << "numb < 10 is " << (numb < 10) << endl;
   cout << "numb > 10 is " << (numb > 10) << endl;
   cout << "numb == 10 is " << (numb == 10) << endl;
   return 0;
}