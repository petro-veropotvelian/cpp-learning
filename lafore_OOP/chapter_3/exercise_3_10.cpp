// exercise_3_10.cpp
// Write another version of the program from Exercise 7 so that, instead of
// finding the final amount of your investment, you tell the program the final
// amount and it figures out how many years it will take, at a fixed rate of
// interest compounded yearly, to reach this amount. What sort of loop is
// appropriate for this problem? (Don’t worry about fractional years; use an
// integer value for the year.)
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   cout << "Enter initial amount: ";
   double dInitialAmount;
   cin >> dInitialAmount;
   cout << "Enter interest rate(percent per year): ";
   double dInterestRate;
   cin >> dInterestRate;
   cout << "Enter the final amount: ";
   double dFinalAmount;
   cin >> dFinalAmount;
   int nYears = 0;
   double dTotal = dInitialAmount;
   while (dTotal <= dFinalAmount)
   {
      dTotal+= dTotal * (dInterestRate/100.0);
      ++nYears;
   }
   cout << "Youl will need " << nYears << " to earn the final amount.\n";
   return 0;
}