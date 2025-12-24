// exercise_2_8.cpp
// When a value is smaller than a field specified with setw(), the unused
// locations are, by default, filled in with spaces. The manipulator setfill()
// takes a single character as an argument and causes this character to be
// substituted for spaces in the empty parts of a field. Rewrite the WIDTH
// program so that the characters on each line between the location name and
// the population number are filled in with periods instead of spaces, as in
// Portcity.....2425785
#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char* argv[])
{
   long pop1 = 2425785, pop2 = 47, pop3 = 9761;
   cout << setw(8) << "LOCATION" << setw(12)
        << "POPULATION" << endl
   << setfill('.') << setw(8) << "Portcity" << setfill('.')
   << setw(12) << pop1 << endl
   << setfill('.') << setw(8) << "Hightown" << setfill('.')
   << setw(12) << pop2 << endl
   << setfill('.') << setw(8) << "Lowville" << setfill('.')
   << setw(12) << pop3 << endl;
   return 0;
}