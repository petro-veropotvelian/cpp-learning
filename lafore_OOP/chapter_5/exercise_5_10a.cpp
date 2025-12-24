// exercise_5_10a.cpp
// Write a function that, when you call it, displays a message telling how many
// times it has been called: "I have been called 3 times", for instance. Write
// a main() program that calls this function at least 10 times. Try
// implementing this function in two different ways.
// First, use a global variable to store the count. Second, use a local static
//  variable. Which is more appropriate? Why can't you use a local variable?
// First solution option.
#include <iostream>
using namespace std;

int counter = 0;

void simpleFunction(void)
{
   counter++;
   cout << "simpleFunction() has been called "<< counter <<" times." << endl;
}

int main(int argc, char* argv[])
{
   for (int i=0; i<10; i++)
   {
      simpleFunction();
   }
   return 0;
}