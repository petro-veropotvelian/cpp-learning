// exercise_15_5.cpp
// Fill an array with even numbers and a set with odd numbers. Use the merge()
// algorithm to merge these containers into a vector.
// Display the vector contents to show that all went well.
#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

const int NSIZE = 5;
int main(int argc, char*argv[])
{
   set<int> s_odds  = {1, 3, 5, 7, 9, 11} ;
   array<int, NSIZE> a_evens = { 2, 4, 6, 8, 10};
   vector<int> v_numbers;
   v_numbers.reserve(s_odds.size() + a_evens.size());
   merge(s_odds.begin(), s_odds.end(), a_evens.begin(), a_evens.end(), back_inserter(v_numbers));
   for (int i : v_numbers)
   {
      cout << i << ' ';
   }
   cout << endl;
   return 0;
}