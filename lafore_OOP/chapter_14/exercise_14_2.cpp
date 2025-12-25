// exercise_14_2.cpp
// A queue is a data-storage device. It's like a stack, except that, instead of being
// last-infirst-out, itls first-in-first-out, like the line at a bank teller's window.
// If you put in 1, 2, 3, you get back 1, 2, 3 in that order.
// A stack needs only one index to an array (top in the STAKARAY program in Chapter 7).
// A queue, on the other hand, must keep track of two indexes to an array: one to the
// tail, where new items are added, and one to the head, where old items are removed.
// The tail follows the head through the array as items are added and removed. If
// either the tail orthe head reaches the end of the array, it is reset to the 
// beginning.
// Write a class template for a queue class. Assume that the programmer using the
// queue won't make any mistakes, like exceeding the capacity of the queue or trying
// to remove an item when the queue is empty. Define several queues of different data
// types and insert and remove data from them.
#include <iostream>
using namespace std;
const int MAX = 6;
/////////////////////////////////////////////////////////////////////////////////////////
template <class cType>
class Queue
{
private:
   cType que[MAX];
   int head;
   int tail;
public:
   Queue()
   : head(-1), tail(-1)
   {};
   void put(cType item)
   {
      que[++tail] = item;
      if (tail>= MAX - 1)
      {
         tail = -1;
      }
   }
   cType get(void)
   {
      cType value = que[++head];
      if (head >= MAX -1)
      {
         head = -1;
      }
      return value;
   }
};
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
   Queue<float> flQ;
   flQ.put(1111.1F);
   flQ.put(2222.2F);
   flQ.put(3333.3F);
   flQ.put(4444.4F);
   flQ.put(5555.5F);
   flQ.put(6666.6F);
   cout << "Float queue 1-st item: " << flQ.get() << endl;
   cout << "Float queue 2-nd item: " << flQ.get() << endl;
   cout << "Float queue 3-rd item: " << flQ.get() << endl;
   cout << "Float queue 4-th item: " << flQ.get() << endl;
   cout << "Float queue 5-th item: " << flQ.get() << endl;
   cout << "Float queue 6-th item: " << flQ.get() << endl;
   Queue<int> inQ;
   inQ.put(123);
   inQ.put(345);
   inQ.put(567);
   cout << "Int queue 1-st item: " << inQ.get() << endl;
   cout << "Int queue 2-nd item: " << inQ.get() << endl;
   cout << "Int queue 3-rd item: " << inQ.get() << endl;
   inQ.put(789);
   inQ.put(999);
   inQ.put(1001);
   cout << "Int queue 1-st item: " << inQ.get() << endl;
   cout << "Int queue 2-nd item: " << inQ.get() << endl;
   cout << "Int queue 3-rd item: " << inQ.get() << endl;
   return 0;
}