// exercise_3_11.cpp
// Create a three-function calculator for old-style English currency, where
// money amounts are specified in pounds, shillings, and pence. (See Exercises
// 10 and 12 in Chapter 2.) The calculator should allow the user to add or
// subtract two money amounts, or to multiply a money amount by a
// floating-point number. (It doesn't make sense to multiply two money amounts;
// there is no such thing as square money. We'll ignore division. Use the
// general style of the ordinary four-function calculator in Exercise 4 in this
// chapter.)
#include <iostream>
#include <conio.h>
using namespace std;
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;

double PoundsToDecimal(const int nInPonds, const int nInShillings, const int nInPence);

bool DecimalToPounds(const double dInDecimal, int &nOutPounds, int &nOutShillings, int &nOutPence);

/*void DecimalToPounds(const double dInDecimal);*/

int main(int argc, char* argv[])
{

   int nInuptPounds, nInputShillings, nInputPence, nOutputPounds, nOutputShillings, nOutputPence;
   char cDelimiter, cResponse, cOperation;
   double dNumber, dSecondAmount, dTotalAmount;
   do
   {
      cout << "\nEnter first amount: " << '\x9c';
      cin >> nInuptPounds >> cDelimiter >> nInputShillings >> cDelimiter >> nInputPence;
      double dFirstAmount = PoundsToDecimal(nInuptPounds, nInputShillings, nInputPence);
      cin.get();
      cout << "Enter operator: ";
      cin >> cOperation;
      cin.get();
      switch (cOperation)
      {
         case '+':
            cout << "Enter second amount: "<< '\x9c';
            cin >> nInuptPounds >> cDelimiter >> nInputShillings >> cDelimiter >> nInputPence;
            cin.get();
            dSecondAmount = PoundsToDecimal(nInuptPounds, nInputShillings, nInputPence);
            dTotalAmount = dFirstAmount + dSecondAmount;
            break;
         case '-':
            cout << "Enter second amount: "<< '\x9c';
            cin >> nInuptPounds >> cDelimiter >> nInputShillings >> cDelimiter >> nInputPence;
            dSecondAmount = PoundsToDecimal(nInuptPounds, nInputShillings, nInputPence);
            dTotalAmount = dFirstAmount - dSecondAmount;
            break;
         case '*':
            cout << "Enter the number on which you want to multiply: ";
            cin >> dNumber;
            dTotalAmount = dFirstAmount * dNumber;
            break;
         case '/':
            cout << "Enter the number on which you want to divide: ";
            cin >> dNumber;
            if (dNumber == 0)
            {
               cout << "Error! You cannot divide by zero!" << endl;
            }
            else
            {
               dTotalAmount = dFirstAmount / dNumber;
            }
            break;
         default:
            cout << "Wrong operation specified. Only +, -, * or / are allowed.\n";
            break;
      }
      //DecimalToPounds(dTotalAmount);
      if (DecimalToPounds(dTotalAmount, nOutputPounds, nOutputShillings, nOutputPence))
      {
         cout << "The result is: " << '\x9c' << nOutputPounds << "."<< nOutputShillings 
              << "." << nOutputPence << endl;
      }
      cout << "Do another (y/n)? ";
   } while ((cResponse=getche())!='n');
   return 0;
}

double PoundsToDecimal(const int nInPonds, const int nInShillings, const int nInPence)
{
   double dResult = 0.0;
   dResult = double((nInPonds * nShillingsInPound * nPenceInShilling )+ 
   (nInShillings * nPenceInShilling) + nInPence)/ double(nShillingsInPound * nPenceInShilling);

   return dResult;
}




bool DecimalToPounds(const double dInDecimal, int &nOutPounds, int &nOutShillings, int &nOutPence)
{
   bool bResult = false;
   nOutPounds = nOutShillings = nOutPence =0;
   nOutPounds = static_cast<int>(dInDecimal);
   double dDecimalFraction = dInDecimal - nOutPounds;
   nOutShillings = dDecimalFraction * nShillingsInPound;
   double dPence = nShillingsInPound * nPenceInShilling * dDecimalFraction - nOutShillings * nPenceInShilling;
   dPence = dPence + 0.5 - (dPence<0);
   nOutPence = int (dPence);
   bResult = true;
   return bResult;
}