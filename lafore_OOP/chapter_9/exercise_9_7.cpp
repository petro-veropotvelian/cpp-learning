// exercise_9_7.cpp
// Start with the COUNTEN2 program in this chapter. It can increment or
// decrement a counter, but only using prefix notation. Using inheritance, add
// the ability to use postfix notation for both incrementing and decrementing.
// (See Chapter 8 for a description of postfix notation.)
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class Counter                                                        // base class 
{
protected:                                                           // NOTE: not private
   unsigned int count;                                               // count
public:
   Counter() : count(0)                                              // constructor no args
   {}
   Counter(int c) : count(c)                                         // constructor, one arg
   {}
   unsigned int get_count()                                          // return count
   {
      return count;
   }
   Counter operator++()                                              // increment (prefix) count
   {
      ++count;                                                       // increment count, then return
      return Counter(count);                                         // an unnamed temporary object
   }                                                                 // initialized to this count
};
///////////////////////////////////////////////////////////////////////////////
class CountDn : public Counter                                       // derived class
{
public:
   CountDn() : Counter()                                             // constructor no args
   {
   }
   CountDn(int c) : Counter(c)                                       // constructor, 1 arg
   {
   }
   CountDn operator--()                                              // decrement count (prefix)
   {
      return CountDn(--count);
   }
};

///////////////////////////////////////////////////////////////////////////////
class CountPr : public CountDn
{
public:
   CountPr() : CountDn()
   {
   }
   CountPr(int c) : CountDn(c)
   {
   }
   CountPr operator++()
   {
      return CountPr(++count);
   }
   CountPr operator--()
   {
      return CountPr(--count);
   }
   CountPr operator++(int)
   {
      return CountPr(count++);
   }
   CountPr operator--(int)
   {
      return CountPr(count--);
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   CountPr c1;                                                       // class CountDn
   CountPr c2(100);

   cout << "\nc1 = " << c1.get_count();                              // display c1
   cout << "\nc2 = " << c2.get_count();                              // display c2

   ++c1;
   ++c1;
   ++c1;                                                             // increment c1 3 times
   cout << "\nc1 = " << c1.get_count();                              // display it

   --c2;
   --c2;                                                             // decrement c2 twice
   cout << "\nc2 = " << c2.get_count();                              // display it

   CountPr c3 = c2--;                                                // create c3 from c2
   cout << "\nc3 = " << c3.get_count();                              // display it
   cout << endl;
   cout << "c2 = " << c2.get_count() << endl;
   return 0;
}