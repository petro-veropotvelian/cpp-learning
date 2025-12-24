// exercise_2_4.cpp
// Write a program that displays your favorite poem. Use an appropriate escape
// sequence for the line breaks. If you don’t have a favorite poem, you can
// borrow this one by Ogden Nash:
//    Candy is dandy,
//    But liquor is quicker.
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
   cout << "There was an alligator sitting on a log,\n"
        << "Down in the pool he saw a little frog\n"
        << "In jumped the alligator, and around went the log -\n"
        << "Splash went the water, and away swam the frog."
        << endl;
   return 0;
}