// exercise_4_1.cpp
//A phone number, such as (212) 767-8900, can be thought of as having three
// parts: the area code (212), the exchange (767), and the number (8900).
// Write a program that uses a structure to store these three parts of a phone
// number separately. Call the structure phone. Create two structure variables
// of type phone. Initialize one, and have the user input a number for the
// other one. Then display both numbers. The interchange might look like this:
//    Enter your area code, exchange, and number: 415 555 1212
//    My number is (212) 767-8900
//    Your number is (415) 555-1212
#include <iostream>
using namespace std;
struct phone
{
   int nAreaCode;
   int nExchange;
   int nNumber;
};

void printPhone(const phone& phn);

int main(int artc, char* argv[])
{
   phone myNumber { 212, 767, 8900 };
   phone yourNumber;
   cout << "Enter your area code, exchange, and number: ";
   cin >> yourNumber.nAreaCode >> yourNumber.nExchange >> yourNumber.nNumber;
   cout << "My number is ";
   printPhone(myNumber);
   cout << "Your number is ";
   printPhone(yourNumber);
   return 0;
}

void printPhone(const phone& phn)
{
   cout << "(" << phn.nAreaCode << ") " << phn.nExchange <<"-"<<phn.nNumber << endl;
}