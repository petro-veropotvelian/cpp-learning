// exercise_9_11.cpp
// Various situations require that pairs of numbers be treated as a unit. For
// example, each screen coordinate has an x (horizontal) component and a y
// (vertical) component. Represent such a pair of numbers as a structure called
// pair that comprises two int member variables.
// Now, assume you want to be able to store pair variables on a stack. That is,
// you want to be able to place a pair (which contains two integers) onto a
// stack using a single call to a push() function with a structure of type pair
// as an argument, and retrieve a pair using a single call to a pop() function,
// which will return a structure of type pair. Start with the Stack2 class in
// the STAKEN program in this chapter, and from it derive a new class called
// pairStack. This new class need contain only two members: the overloaded
// push() and pop() functions. The pairStack::push() function will need to make
// two calls to Stack2::push() to store the two integers in its pair, and the
// pairStack::pop() function will need to make two calls to Stack2::pop()
// (although not necessarily in the same order).
#include <iostream>
#include <process.h>                               // for exit()
//using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
struct Pair
{
   Pair()
   : nX(0), nY(0)
   {
   }
   Pair(int xVal, int yVal)
   : nX(xVal), nY(yVal)
   {
   }
   int nX;
   int nY;
};
/////////////////////////////////////////////////////////////////////////////////////////
class Stack
{
protected:                          // NOTE: can't be private
   enum { MAX = 6 };                // size of stack array
   int st[MAX];                     // stack: array of integers
   int top;                         // number of top of stack
public:
   Stack()                          // constructor
   {
      top = -1;
   }
   void push(int var)               // push number on stack
   {
      st[++top] = var;
   }
   int pop()                        // take number off stack
   {
      return st[top--];
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
class Stack2 : public Stack
{
public:
   void push(int var)                              // put number on stack
   {
      if (top >= MAX-1)                            // error if stack full
      {
         std::cout << "\nError: stack is full";
         exit(1);
      }
      Stack::push(var);                         // call push() in Stack class
   }
   int pop()                                       // take number off stack
   {
      if (top < 0)                                 // error if stack empty
      {
         std::cout << "\nError: stack is empty\n";
         exit(1);
      }
      return Stack::pop();                         // call pop() in Stack class
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
class pairStack : public Stack2
{
public:
   void push(Pair pr)
   {
      Stack2::push(pr.nX);
      Stack2::push(pr.nY);
   }

   Pair pop()
   {
      Pair pr;
      pr.nY = Stack2::pop();
      pr.nX = Stack2::pop();
      return pr;
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
void printPair(const Pair &pr)
{
   std::cout << "nX = " << pr.nX << "; nY = " << pr.nY << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   pairStack ps;

   Pair p1(1, 2);
   Pair p2(2, 4);
   Pair p3(3, 6);
   ps.push(p1);
   ps.push(p2);
   ps.push(p3);

   Pair tmp = ps.pop();
   printPair(tmp);
   tmp = ps.pop();
   printPair(tmp);
   tmp = ps.pop();
   printPair(tmp);
   return 0;
}