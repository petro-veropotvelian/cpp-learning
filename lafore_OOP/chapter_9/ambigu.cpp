// amgigu.cpp
// demonstrates ambiguity in multiple inheriance
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class A
{
public:
   void show()
   {
      cout << "Class A\n";
   }
};
class B
{
public:
   void show()
   {
      cout << "Class B\n";
   }
};
class C : public A, public B
{
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* agv[])
{
   C objC;                                                  // object of class Class
   //objC.show();                                           // ambiguous - will nit compile
   objC.A::show();                                          // OK
   objC.B::show();                                          // OK
   return 0;
}