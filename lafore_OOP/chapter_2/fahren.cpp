// fahren.cpp
// применение cin и \name
#include <iostream>
using namespace std;
int main()
{
   int ftemp;                                         // температура по Фаренгейту
   cout << "Enter the temperature in Fahrenheit: ";
   cin >> ftemp;
   int ctemp = (ftemp-32)*5/9;
   cout << "The Celsius temperature is " << ctemp << '\n';
   return 0;
}