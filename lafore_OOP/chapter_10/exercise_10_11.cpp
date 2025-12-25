// exercise_10_11.cpp
// Create a class that allows you to treat the 10 separate arrays in
// Exercise 10 as a single one-dimensional array, using array notation with a
// single index. That is, statements in main() can access their elements using
// expressions like a[j], even though the class member functions must access
// the data using the two-step approach. Overload the subscript operator []
// (see Chapter 9, "Inheritance") to achieve this result. Fill the arrays with
// test data and then display it. Although array notation is used in the class
// interface in main() to access “array” elements, you should use only pointer
// notation for all the operations in the implementation (within the class
// member functions).
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <process.h>
using namespace std;

const int MAXSIZE =10;
const int NARRAYS = 10;
///////////////////////////////////////////////////////////////////////////////
class MyArray
{
public:
   MyArray();
   ~MyArray();
   int& operator[](int n);
private:
   int** pp;
};
//-----------------------------------------------------------------------------
MyArray::MyArray()
{
   pp = new int* [NARRAYS];
   for (int i=0; i<NARRAYS; i++)
   {
      pp[i] = new int[MAXSIZE];
   }
}
//-----------------------------------------------------------------------------
MyArray::~MyArray()
{
   for (int i=0; i<NARRAYS; i++)
   {
      delete [] pp[i];
   }
   delete []pp;
}
//-----------------------------------------------------------------------------
int& MyArray::operator[](int n)
{
   if (n<0 || n >= NARRAYS*MAXSIZE)
   {
      cout << "\nIndex out of bounds";
      exit(1);
   }
   int i = n / NARRAYS;
   int j = n % NARRAYS;
   return *(*(pp+i) + j);
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   MyArray mArr;
   mArr[0]=101;
   mArr[1]=99;
   mArr[2]=88;
   mArr[3]=77;
   mArr[4]=66;
   mArr[5]=55;
   mArr[6]=44;
   mArr[7]= 33;
   mArr[8]=22;
   mArr[9]=11;
   mArr[10]=-101;
   mArr[11]=-202;
   for (int i=0; i < 12; i++)
   {
      cout << mArr[i] << " ";
   }
   cout << endl;
   return 0;
}