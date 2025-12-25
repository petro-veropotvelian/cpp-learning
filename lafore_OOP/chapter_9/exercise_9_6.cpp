// exercise_9_6.cpp
// Start with the ARROVER3 program in Chapter 8. Keep the safearay class the
// same as in that program, and, using inheritance, derive the capability for
// the user to specify both the upper and lower bounds of the array in a
// constructor. This is similar to Exercise 9 in Chapter 8, except that
// inheritance is used to derive a new class (you can call it safehilo)
// instead of modifying the original class.
#include <iostream>
#include <process.h>                                                           // for exit()
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////////////////////////////
class safearray
{
private:
   int arr[LIMIT];
public:
   int& operator[](int n)                                            // not: return by reference
   {
      if (n<0 || n>= LIMIT)
      {
         cout << "\nIndex out of bounds";
         exit(1);
      }
      return arr[n];
   }
};
///////////////////////////////////////////////////////////////////////////////
class safehilo : public safearray
{
private:
   int nLowBound;
   int nHiBound;
public:
   safehilo(int nLw, int nHg)
   : nLowBound(nLw), nHiBound(nHg)
   {}
   int& operator[](int n)
   {
      if (n < nLowBound || n>= nHiBound)
      {
         cout << "\nIndex out of bounds";
         exit(1);
      }
      else
      {
         return safearray::operator[](n);
      }
   }
};

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   safehilo shl1(3, 20);
   for (int j=3; j<20; j++)                                       // insert elements
   {
      shl1[j] = j*10;                                                 // *left" side of equal sign
   }
   for (int j=3; j<20; j++)                                       // display elements
   {
      int temp = shl1[j];                                             // *right* sign of equal sign
      cout << "Element " << j << " is " << temp << endl;
   }
   cout << "Let's check 0 element: " << shl1[0] << endl;
   return 0;
}