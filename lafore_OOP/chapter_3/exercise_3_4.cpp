// exercise_3_4.cpp
// Create the equivalent of a four-function calculator. The program should ask
// the user to enter a number, an operator, and another number. (Use floating
// point.) It should then carry out the specified arithmetical operation:
// adding, subtracting, multiplying, or dividing the two numbers. Use a switch
// statement to select the operation. Finally, display the result.
// When it finishes the calculation, the program should ask whether the user
// wants to do another calculation. The response can be 'y' or 'n'. Some sample
// interaction with the program might look like this:
//    Enter first number, operator, second number: 10 / 3
//    Answer = 3.333333
//    Do another (y/n)? y
//    Enter first number, operator, second number: 12 + 100
//    Answer = 112
//    Do another (y/n)? n
#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[])
{
   double dFirstOperand, dSecondOperand, dResult;
   char cOperation;
   char cResponse;
   do
   {
      cout <<"\nEnter first number, operator, second number: ";
      cin >> dFirstOperand >> cOperation >> dSecondOperand;
      switch (cOperation)
      {
         case '+':
            dResult = dFirstOperand + dSecondOperand;

            break;
         case '-':
            dResult = dFirstOperand - dSecondOperand;
           // cout << "Answer = " << dResult << endl;
            break;
         case '*':
            dResult = dFirstOperand * dSecondOperand;
            ///cout << "Answer = " << dResult << endl;
            break;
         case '/':
            if (dSecondOperand == 0)
            {
               cout << "Error! You cannot divide by zero!" << endl;
            }
            else
            {
               dResult = dFirstOperand / dSecondOperand;
            //   cout << "Answer = " << dResult << endl;
            }
            break;
         default:
            cout << "Wrong operation specified. Only +, -, * or / are allowed.\n";
            break;
      }
      cout << "Answer = " << dResult << endl;
      cout << "Do another (y/n)? ";
   } while ((cResponse=getche())!= 'n');
   return 0;
}