// exercise_3_2.cpp
// Write a temperature-conversion program that gives the user the option of
// converting Fahrenheit to Celsius or Celsius to Fahrenheit. Then carry out
// the conversion. Use floating-point numbers. Interaction with the program
// might look like this:
//    Type 1 to convert Fahrenheit to Celsius,
//         2 to convert Celsius to Fahrenheit: 1
//    Enter temperature in Fahrenheit: 70
//    In Celsius that's 21.111111
#include <iostream>
#include <conio.h>
using namespace std;

const unsigned char cDegreeSym = 248;
void FahrenheitToCelsius();
void CelsiusToFahrenheit();

int main(int argc, char* argv[])
{
   char choice='x';
   do
   {
      cout << "Type 1 to convert Fahrenheit to Celsius,"
           << "\n     2 to convert Celsius to Fahrenheit: ";
      choice = getche();
      if (choice == '1')
      {
         FahrenheitToCelsius();
         break;
      }
      else if (choice=='2')
      {
         CelsiusToFahrenheit();
         break;
      }
      else if (choice=='\r')
      {
         cout << "\nBye!\n";
      }
      else
      {
         cout << "\nWrong choice!\n";
      }
   }
   while (choice!='\r');
   return 0;
}

void FahrenheitToCelsius()
{
   cout << "\nEnter temperature in Fahrenheit: ";
   double tempFahren;
   cin >> tempFahren;
   cout << "In Celsius that's " << ((tempFahren - 32.0) * 5.0 / 9.0) << cDegreeSym << endl;
}

void CelsiusToFahrenheit()
{
   cout << "\nEnter temperature in Celsius: ";
   double tempCelsius;
   cin >> tempCelsius;
   cout << "In Fahrenheit that's " << ((tempCelsius * 9.0)/5.0 + 32.0) << cDegreeSym << endl;
}