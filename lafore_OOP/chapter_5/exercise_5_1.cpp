// exercise_5_1.cpp
// Refer to the CIRCAREA program in Chapter 2, "C++ Programming Basics."
// Write a function called circarea() that finds the area of a circle in a
// similar way. It should take an argument of type float and return an argument
// of the same type. Write a main() function that gets a radius value from the
// user, calls circarea(), and displays the result.
#include <iostream>
using namespace std;

float circarea(float fRadius);

int main(int argc, char* argv[])
{
   float rad;
   cout << "Enter readius of circle: ";
   cin >> rad;
   cout << "Area is " << circarea(rad) << endl;
   return 0;
}

float circarea(float fRadius)
{
   const float PI = 3.14159F;
   return (PI * fRadius * fRadius);
}