// exercise_4_10.cpp
// Create a structure called sterling that stores money amounts in the
// old-style British system discussed in Exercises 8 and 11 in Chapter 3,
// "Loops and Decisions." The members could be called pounds, shillings, and
// pence, all of type int. The program should ask the user to enter a money
// amount in new-style decimal pounds (type double), convert it to the
// old-style system, store it in a variable of type struct sterling, and then
// display this amount in pounds-shillings-pence format.
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;

///////////////////////////////////////////////////////////////////////////////
struct sterling
{
   int pounds;
   int shillings;
   int pence;
};
///////////////////////////////////////////////////////////////////////////////
void SetPounds(sterling &st);

void GetPounds(const sterling &st);

int main(int argc, char* argv[])
{
   sterling St;
   SetPounds(St);
   cout << "You specified: ";
   GetPounds(St);
   cout << endl;
   return 0;
}


void SetPounds(sterling &st)
{
   cout << "Specify anmount (pounds.pence): " << '\x9c';
   double dModernPounds;
   cin >> dModernPounds;
   st.pounds = static_cast<int>(dModernPounds);
   double dDecimalFraction = dModernPounds - st.pounds;
   st.shillings = dDecimalFraction * nShillingsInPound;
   double dPence = nShillingsInPound * nPenceInShilling * dDecimalFraction - st.shillings* nPenceInShilling;
   dPence = dPence + 0.5 - (dPence<0);
   st.pence = int (dPence);
}

void GetPounds(const sterling &st)
{
   cout << '\x9c' << st.pounds << '.' << st.shillings << '.' << st.pence;
}