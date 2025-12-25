// replay.cpp
// gets four ages from user, displyas them
#include <iostream>
using namespace std;
int main(int argc, char*argv[])
{
   int age[4];                                        // array 'age' of 4 units
   for (int j=0; j<4; j++)                            // get 4 ages
   {
      cout << "Enter an age: ";
      cin >> age[j];                                  // access array element
   }
   for (int j=0; j<4; j++)                                // displya 4 ages
   {
      cout << "You entered "<< age[j] << endl;
   }
   return 0;
}