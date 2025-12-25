// counten.cpp
// inheritance with Counter class
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class Counter                                                     // base class 
{
protected:                                                        // NOTE: not private
   unsigned int count;                                            // count
public:
   Counter() : count(0)                                           // constructor no args
   {}
   Counter(int c) : count(c)                                     // constructor, one arg
   {}
   unsigned int get_count()                                       // return count
   {
      return count;
   }
   Counter operator++()                                              // increment (prefix) count
   {
      ++count;                                                       // increment count, then return
      return Counter(count);                                          // an unnamed temporary object
   }                                                                 // initialized to this count
};
///////////////////////////////////////////////////////////////////////////////
class CountDn : public Counter                                       // derived class
{
public:
   Counter operator--()                                              // decrement count (prefix)
   {
      return Counter(--count);
   }
};

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   CountDn c1;                                                       // c1 class of CountDn

   cout << "\nc1 = " << c1.get_count();                              // display c1

   ++c1;
   ++c1;
   ++c1;                                                             // increment c1 3 times
   cout << "\nc1 = " << c1.get_count();                              // display it

   --c1;
   --c1;                                                             // decrement c1 twice
   cout << "\nc1 = " << c1.get_count();                              // display it
   cout << endl;
   return 0;
}