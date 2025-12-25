// exercise_10_12.cpp
// Pointers are complicated, so let's see whether we can make their operation
// more understandable (or possibly more impenetrable) by simulating their
// operation with a class.
// To clarify the operation of our homemade pointers, we'll model the
// computer's memory using arrays. This way, since array access is well
// understood, you can see what's really going on when we access memory with
// pointers.
// We'd like to use a single array of type char to store all types of
// variables. This is what a computer memory really is: an array of bytes
// (which are the same size as type char), each of which has an address (or, in
// array-talk, an index). However, C++ won't ordinarily let us store a float or
// an int in an array of type char. (We could use unions, but that's another
// story.) So we'll simulate memory by using a separate array for each data
// type we want to store. In this exercise we'll confine ourselves to one
// numerical type, float, so we'll need an array of this type; call it fmemory.
// However, pointer values (addresses) are also stored in memory, so we'll need
// another array to store them. Since we're using array indexes to model
// addresses, and indexes for all but the largest arrays can be stored in type
// int, we'll create an array of this type (call it pmemory) to hold these
// "pointers."
// An index to fmemory (call it fmem_top) points to the next available place
// where a float value can be stored. There's a similar index to pmemory (call
// it pmem_top). Don't worry about running out of "memory." We'll assume these
// arrays are big enough so that each time we store something we can simply
// insert it at the next index number in the array.
// Other than this, we won't worry about memory management.
// Create a class called Float. We'll use it to model numbers of type float
// that are stored in fmemory instead of real memory. The only instance data
// in Float is its own "address"; that is, the index where its float value is
// stored in fmemory. Call this instance variable addr. Class Float also needs
// two member functions. The first is a one-argument constructor to initialize
// the Float with a float value. This constructor stores the float value in the
// element of fmemory pointed to by fmem_top, and stores the value of fmem_top
// in addr. This is similar to how the compiler and linker arrange to store an
// ordinary variable in real memory. The second member function is the
// overloaded & operator.
// It simply returns the pointer (really the index, type int) value in addr.
// Create a second class called ptrFloat. The instance data in this class holds
// the address (index) in pmemory where some other address (index) is stored.
// A member function initializes this "pointer" with an int index value. The
// second member function is the overloaded* (dereference, or "contents of")
// operator. Its operation is a tad more complicated.
// It obtains the address from pmemory, where its data, which is also an
// address, is stored. It then uses this new address as an index into fmemory
// to obtain the float value pointed to by its address data.
//    float& ptrFloat::operator*()
//    {
//       return fmemory[ pmemory[addr] ];
//    }
// In this way it models the operation of the dereference operator (*). Notice
// that you need to return by reference from this function so that you can 
// use * on the left side of the equal sign.
// The two classes Float and ptrFloat are similar, but Float stores floats in
// an array representing memory, and ptrFloat stores ints (representing memory
// pointers, but really array index values) in a different array that also
// represents memory.
// Here's a typical use of these classes, from a sample main():
// Float var1 = 1.234; // define and initialize two Floats
// Float var2 = 5.678;
// ptrFloat ptr1 = &var1; // define two pointers-to-Floats,
// ptrFloat ptr2 = &var2; // initialize to addresses of Floats
// cout << " *ptr1=" << *ptr1; // get values of Floats indirectly
// cout << " *ptr2=" << *ptr2; // and display them
// *ptr1 = 7.123; // assign new values to variables
// *ptr2 = 8.456; // pointed to by ptr1 and ptr2
// cout << " *ptr1=" << *ptr1; // get new values indirectly
// cout << " *ptr2=" << *ptr2; // and display them
// Notice that, aside from the different names for the variable types, this 
// looks just the same as operations on real variables. Here’s the output 
//from the program:
// *ptr1=1.234
// *ptr2=2.678
// *ptr1=7.123
// *ptr2=8.456
// This may seem like a roundabout way to implement pointers, but by revealing
// the inner workings of the pointer and address operator, we have provided a
// different perspective on their true nature.
#include <iostream>
using namespace std;

const int ARRSIZE = 1000;

float fmemory[ARRSIZE];
int pmemory[ARRSIZE];
int fmem_top =0;
int pmem_top = 0;

class Float
{
private:
   int addr;
public:
   Float(float fvar)
   {
      //arr = fmem_top;
      fmemory[fmem_top] = fvar;
      addr = fmem_top++;
   }
   int operator&()
   {
      return addr;
   }
};
///////////////////////////////////////////////////////////////////////////////
class ptrFloat
{
private:
   int addr;
public:
   ptrFloat(int nvar)
   {
      pmemory[pmem_top] = nvar;
      addr = pmem_top++;
   }
   float& operator*()
   {
      return fmemory[pmemory[addr]];
   }

};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   Float var1 = 1.234;                           // define and initialize two Floats
   Float var2 = 5.678;

   ptrFloat ptr1 = &var1;                        // define two pointers-to-Floats
   ptrFloat ptr2 = &var2;                        // initialize to addresses to Floats

   cout << " *ptr1 = " << *ptr1;                // get values of Floats indirectrly
   cout << " *ptr2 = " << *ptr2 << endl;        // and display them

   cout << " ptr1 (&var1) = " << &var1;
   cout << " ptr2 (&var2) = " << &var2<< endl;

   *ptr1 = 7.123;                               // assign new values to variables
   *ptr2 = 8.456;                               // pointed to by ptr1 and ptr2

   cout << " *ptr1 = " << *ptr1;                // get new valued indirectly
   cout << " *ptr2 = " << *ptr2 << endl;        // and display them

   cout << " ptr1 (&var1) = " << &var1;
   cout << " ptr2 (&var2) = " << &var2<< endl;

   return 0;
}