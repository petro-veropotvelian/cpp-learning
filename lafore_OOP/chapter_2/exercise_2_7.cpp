// exercise_2_7.cpp
// You can convert temperature from degrees Celsius to degrees Fahrenheit by
// multiplying by 9/5 and adding 32. Write a program that allows the user to
// enter a floating-point number representing degrees Celsius, and then
// displays the corresponding degrees Fahrenheit.
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   cout << "Enter the value in Celsius degrees: ";
   double dCelsius;
   cin >> dCelsius;
   cout << dCelsius << " Celsius degrees is equal to "
   << ((dCelsius * 9/5) + 32) << " Fahrenheit degrees." << endl;
   return 0;
}