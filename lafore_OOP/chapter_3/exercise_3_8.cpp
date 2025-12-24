// exercise_3_8.cpp
// Write a program that repeatedly asks the user to enter two money amounts
// expressed in old-style British currency: pounds, shillings, and pence.
// (See Exercises 10 and 12 in Chapter 2, "C++ Programming Basics.") The
// program should then add the two amounts and display the answer, again in
// pounds, shillings, and pence. Use a do loop that asks the user whether the
// program should be terminated. Typical interaction might be:
//    Enter first amount: £5.10.6
//    Enter second amount: £3.2.6
//    Total is £8.13.0
//    Do you wish to continue (y/n)?
// To add the two amounts, you'll need to carry 1 shilling when the pence value
// is greater than 11, and carry 1 pound when there are more than 19 shillings.
#include <iostream>
#include <conio.h>
using namespace std;
int main(int argc, char* argv[])
{
   const int nShillingsInPound = 20;
   const int nPenceInShilling = 12;
   int nInuptPounds, nInputShillings, nInputPence;
   char cDelimiter;
   char cResponse;
   cout << "Welcome!";
   do 
   {
      cout << endl;
      nInuptPounds = nInputShillings = nInputPence = 0;
      cout << "Enter first amount: " << '\x9c';
      cin >> nInuptPounds >> cDelimiter >> nInputShillings >> cDelimiter >> nInputPence;
      int nFirstAmountInPence = nInuptPounds * nShillingsInPound * nPenceInShilling + nInputShillings * nPenceInShilling + nInputPence;
      nInuptPounds = nInputShillings = nInputPence = 0;
      cout << "Enter second amount: " << '\x9c';
      cin >> nInuptPounds >> cDelimiter >> nInputShillings >> cDelimiter >> nInputPence;
      int nSecondAmountInPence = nInuptPounds * nShillingsInPound * nPenceInShilling + nInputShillings * nPenceInShilling + nInputPence;
      int nTotalAmount = nFirstAmountInPence + nSecondAmountInPence;
      int nTotalPounds = nTotalAmount/(nShillingsInPound * nPenceInShilling);
      int nTotalShillings = (nTotalAmount - nTotalPounds*nShillingsInPound*nPenceInShilling)/nPenceInShilling;
      int nTotalPence = nTotalAmount - (nTotalPounds*nShillingsInPound*nPenceInShilling) - (nTotalShillings*nPenceInShilling);
      cout << "Total is " << '\x9c' << nTotalPounds << "." << nTotalShillings << "." << nTotalPence << endl;
      cout << "Do you wish to continue (y/n)?";
   } while ((cResponse = getche())!= 'n');
   cout << "\nBye!" << endl;
   return 0;
}