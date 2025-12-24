// exercise_2_6.cpp
// On a certain day the British pound was equivalent to $1.487 U.S., the French
// franc was $0.172, the German deutschemark was $0.584, and the Japanese yen
// was $0.00955.
// Write a program that allows the user to enter an amount in dollars, and then
// displays this value converted to these four other monetary units.
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   const double dPound4Usd = 1.487;
   const double dFrank4Usd = 0.172;
   const double dMark4Usd  = 0.584;
   const double dYen4Usd   = 0.00955;
   cout << "Enter amount in USD: ";
   double dUSD;
   cin >> dUSD;
   cout << dUSD << " dollars is equal to "
   <<"\n\t" << dUSD / dPound4Usd << " pounds"
   <<"\n\t" << dUSD / dFrank4Usd << " franks"
   <<"\n\t" << dUSD / dMark4Usd << " marks"
   <<"\n\t" << dUSD / dYen4Usd << " yens" << endl;
   return 0;
}