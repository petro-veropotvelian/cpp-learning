// sstrio.cpp
// string class input/output_iterator
#include <iostream>
#include <string>                                                    // for string class
using namespace std;
int main(int argc, char* argv[])
{
   string full_name, nickname, address;                              // objects of string class
   string greeting("Hello, ");

   cout <<"Enter your full name: ";
   getline(cin, full_name);                                          // reads embedded blanks
   cout << "Your full name is: " << full_name << endl;

   cout << "Enter you nickname: ";
   cin >> nickname;                                                  // input to striing object

   greeting += nickname;                                             // append name to greeting
   cout << greeting << endl;                                         // output: "Hello, Jim"

   cout << "Enter your address on separate lines\n";
   cout << "Terminate with '$'\n";
   getline(cin, address, '$');                                       // reads multiple lines
   cout << "Your address is: " << address << endl;
   return 0;
}