// circarea.cpp
// working with variables of real typed
#include <iostream>
using namespace std;
int main()                                   // для cout и т.д.
{
   float rad;                                // переменная вещественного типа
   const float PI = 3.14159F;                // вещественная константа
   cout << "Enter a radius of a circle: ";   // запрос
   cin >> rad;                               // получение радиуса
   float area = PI * rad * rad;              // вычисление площади круга
   cout << "The area of the circle is " << area << endl; // вывод результата на экран
   return 0;
}