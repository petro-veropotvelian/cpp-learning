// exercise_2_12.cpp
// Write the inverse of Exercise 10, so that the user enters an amount in
// Great Britain's new decimal-pounds notation (pounds and pence), and the
// program converts it to the old pounds-shillings-pence notation. An example
// of interaction with the program might be:
//     Enter decimal pounds: 3.51
//     Equivalent in old notation = £3.10.2.
// Make use of the fact that if you assign a floating-point value (say 12.34)
// to an integer variable, the decimal fraction (0.34) is lost; the integer
// value is simply 12. Use a cast to avoid a compiler warning. You can use 
// statements like:
//    float decpounds; // input from user (new-style pounds)
//    int pounds; // old-style (integer) pounds
//    float decfrac; // decimal fraction (smaller than 1.0)
//    pounds = static_cast<int>(decpounds); // remove decimal fraction
//    decfrac = decpounds - pounds; // regain decimal fraction
// You can then multiply decfrac by 20 to find shillings. A similar operation
// obtains pence.
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   const int nShillingsInPound = 20;
   const int nPencesInShilling = 12;
   cout << "Enter decimal pounds: ";
   double dDecimalPounds;
   cin >> dDecimalPounds;
   int nOldPouns = static_cast<int> (dDecimalPounds);
   double dDecimalFraction = dDecimalPounds - nOldPouns;
   int nOldShillings = dDecimalFraction * nShillingsInPound;
   int nOldPences = nShillingsInPound * nPencesInShilling * dDecimalFraction - nOldShillings* nPencesInShilling;
   cout << "Equivalent in old notation = "<<'\x9c' <<nOldPouns<<"."<<nOldShillings << "." << nOldPences<<endl;
   return 0;
}