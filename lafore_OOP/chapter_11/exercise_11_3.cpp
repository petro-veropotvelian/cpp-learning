// exercise_11_3.cpp
// As we saw earlier, it's possible to make a class that acts like an array.
// The CLARRAY example shown here is a complete program that shows one way to
// create your own array class:
//    clarray.cpp
//    creates array class
//    #include <iostream>
//    using namespace std;
////////////////////////////////////////////////////////////////
//    class Array //models a normal C++ array
//    {
//    private:
//       int* ptr; //pointer to Array contents
//       int size; //size of Array
//    public:
//       Array(int s) //one-argument constructor
//       {
//          size = s; //argument is size of Array
//          ptr = new int[s]; //make space for Array
//       }
//       ~Array() //destructor
//       { delete[] ptr; }
//       int& operator [] (int j) //overloaded subscript operator
//       { return *(ptr+j); }
//    };
////////////////////////////////////////////////////////////////
//    int main()
//    {
//       const int ASIZE = 10; //size of array
//       Array arr(ASIZE); //make an array
//       for(int j=0; j<ASIZE; j++) //fill it with squares
//          arr[j] = j*j;
//       for(j=0; j<ASIZE; j++) //display its contents
//          cout << arr[j] << ' ';
//       cout << endl;
//       return 0;
//    }
// The output of this program is
//    0 1 4 9 16 25 36 49 64 81
// Starting with CLARRAY, add an overloaded assignment operator and an
// overloaded copy   constructor to the Array class. Then add statements such
// as
//     Array arr2(arr1);
// and
//     arr3 = arr1;
// to the main() program to test whether these overloaded operators work. The
// copy constructor should create an entirely new Array object with its own
// memory for storing array elements. Both the copy constructor and the
// assignment operator should copy the contents of the old Array object to the
// new one. What happens if you assign an Array of one size to an Array of a
// different size?
// creates array class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Array //models a normal C++ array
{
private:
int* ptr; //pointer to Array contents
int size; //size of Array
public:
Array(int s) //one-argument constructor
{
size = s; //argument is size of Array
ptr = new int[s]; //make space for Array
}
~Array() //destructor
{
   delete[] ptr;
}
Array(Array &a)         //copy constructor
{
   size = a.size;
   ptr = new int[size];
   for (int i=0; i<size; i++)
   {
      ptr[i] = a.ptr[i];
   }
}
Array& operator= (Array &a)
{
   if (this==&a)
   {
      return *this;
   }

   delete [] ptr;
   size = a.size;
   ptr = new int[size];
   for (int i=0; i<size; i++)
   {
      ptr[i] = a.ptr[i];
   }
   return *this;
}
int& operator[] (int j) //overloaded subscript operator
{
   return *(ptr+j);
}
};
////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   const int ASIZE = 10; //size of array
   const int MINSIZE = 5;
   Array arr(ASIZE); //make an array
   for (int j=0; j<ASIZE; j++)
   {   //fill it with squares
      arr[j] = j*j;
   }
   cout << "Display array arr:\n";
   for (int j=0; j<ASIZE; j++)
   {   //display its contents
      cout << arr[j] << ' ';
   }
   cout << endl;
   Array arr1(MINSIZE);
   for (int j=0; j<MINSIZE; j++)
   {
      if (j==0)
      {
         arr1[j] = 1;
      }
      else
      {
         arr1[j] = j* 3;
      }
   }
   cout << "Display array arr1:\n";
   for (int j=0; j<MINSIZE; j++)
   {
      cout << arr1[j] << ' ';
   }
   cout << endl;
   Array arr2(arr);
   cout << "Display array arr2:\n";
   for (int j=0; j<ASIZE; j++)
   {
      cout << arr2[j] << ' ';
   }
   cout << endl;
   arr1 = arr;
   cout << "Display array arr1:\n";
   for (int j=0; j<ASIZE; j++)
   {
      cout << arr1[j] << ' ';
   }
   cout << endl;
return 0;
}
