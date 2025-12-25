// typeid].cpp
// demonstrates typeid() function
// RTTI must be enabled in compiler
#include <iostream>
#include <typeinfo>                                      // for typeid()
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class Base
{
   virtual void vertFunc()                               // needed for typeid
   {}
   
};
class Derv1 : public Base
{
};
class Derv2 : public Base
{
};
///////////////////////////////////////////////////////////////////////////////
void displayName(Base* pB)
{
   cout << "pointer to and obhect of ";                  // display name of class
   cout << typeid(*pB).name() << endl;                   // pointed to by pB
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Base* pBase = new Derv1;
   displayName(pBase);                                   // pointer to an object of class Derv1

   pBase = new Derv2;
   displayName(pBase);                                   // pointer to an object of class Derv2
   return 0;
}