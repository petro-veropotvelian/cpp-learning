// exercise_10_5.cpp
// Suppose you have a main() with three local arrays, all the same size and
// type (say float). The first two are already initialized to values. Write a
// function called addarrays() that accepts the addresses of the three arrays
// as arguments; adds the contents of the first two arrays together, element by
// element; and places the results in the third array before returning. A
// fourth argument to this function can carry the size of the arrays. Use
// pointer notation throughout; the only place you need brackets is in defining
// the arrays.
#include <iostream>
using namespace std;
const int SIZE = 5;

void showarr(const float* flar, int N)
{
   for (int i=0; i<N; i++)
   {
      cout << flar[i] << "   ";
   }
   cout << endl;
}
//---------------------------------------------------------------
void addarrays(const float* arr1, const float* arr2, float* arr3, int N)
{
   for (int i=0; i<N; i++)
   {
      arr3[i] = arr1[i] + arr2[i];
   }
}

////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   cout << "First array:\n";
   float flarr1[SIZE] = { 1.1, 3.14, 5.25, 0.75, 19.5 };
   showarr(flarr1, SIZE);
   cout << "Second array:\n";
   float flarr2[SIZE] = { 2.2, 1.4, 1.25, 3, -5.25};
   showarr(flarr2, SIZE);
   float flarr3[SIZE];
   addarrays(flarr1, flarr2, flarr3, SIZE);
   cout << "Third array:\n";
   showarr(flarr3, SIZE);
   return 0;
}