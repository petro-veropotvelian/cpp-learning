// exercise_7_9.cpp
// A queue is a data storage device much like a stack. The difference is that
// in a stack the last data item stored is the first one retrieved, while in a
// queue the first data item stored is the first one retrieved. That is, a
// stack uses a last-in-first-out (LIFO) approach, while a queue uses
// first-in-first-out (FIFO). A queue is like a line of customers in a bank:
// The first one to join the queue is the first one served.
// Rewrite the STAKARAY program from this chapter to incorporate a class called
// queue instead of a class called stack. Besides a constructor, it should have
// two functions: one called put() to put a data item on the queue, and one
// called get() to get data from the queue. These are equivalent to push() and
// pop() in the stack class.
// Both a queue and a stack use an array to hold the data. However, instead of
// a single int variable called top, as the stack has, you'll need two
// variables for a queue: one called head to point to the head of the queue,
// and one called tail to point to the tail. Items are placed on the queue at
// the tail (like the last customer getting in line at the bank) and removed
// from the queue at the head. The tail will follow the head along the array as
// items are added and removed from the queue. This results in an added
// complexity:
// When either the tail or the head gets to the end of the array, it must wrap
// around to the beginning. Thus you'll need a statement like
//    if(tail == MAX-1)
//       tail = -1;
// to wrap the tail, and a similar one for the head. The array used in the
// queue is sometimes called a circular buffer, because the head and tail
// circle around it, with the data between them.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Queue
{
private:
   enum { MAX = 10 };               // (non-standard syntax)
   int st[MAX];                     // queue: array of integers
   int tail;                        // number of start of the queue
   int head;                        // number of end of the queue
public:
   Queue()                          // constructor
   : head(-1), tail(-1)
   {
   }
   void put(int var)               // put number to queue
   {
      if (tail==MAX-1 /*&& head==0*/)
      {
         cout << "Queue is full!\n";
         tail=-1;
      }

      if (head == -1)
      {
         head++;
      }
      st[++tail] = var;

//      cout << "Head = " << head << " tail = " << tail << endl;
//      cout << "Item " << var << " has been added." << endl;
   }

   int get()                        // get number to queue
   {
      if (head ==-1 && tail == -1)
      {
         cout << "Queue is empty!" << endl;
         return -1;
      }
      else
      {
         int value = st[head];
         if (head == 0 && tail == 0)
         {
            head = tail = -1;
         }
         else
         {
            for (int i=0; i<tail; i++)
            {
               st[i] = st[head+1+i];
            }
            tail--;
         }
         return value;
      }
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Queue q1;
//   Stack s1;

   q1.put(11);
   q1.put(22);
   q1.put(33);
   q1.put(44);
   cout << "11, 22, 33 and 44 were put into the queue\n";
   cout << "getting two items from queue:\n";
   cout << "First item: " << q1.get() << endl;
   cout << "Second item: " << q1.get() << endl;
   q1.put(55);
   q1.put(66);
   q1.put(77);
   q1.put(88);
   q1.put(99);
   cout << "55, 66, 77, 88 and 99 were put into the queue\n";
   cout << "getting four items from queue:\n";
   cout << "First item: " << q1.get() << endl;
   cout << "Second item: " << q1.get() << endl;
   cout << "Third item: " << q1.get() << endl;
   cout << "Fourth item: " << q1.get() << endl;
   q1.put(101);
   q1.put(102);
   q1.put(103);
   cout << "101, 102 and 103 were put into the queue\n";
   cout << "getting four items from queue:\n";
   cout << "First item: " << q1.get() << endl;
   cout << "Second item: " << q1.get() << endl;
   cout << "Third item: " << q1.get() << endl;
   cout << "Fourth item: " << q1.get() << endl;
   cout << "getting next two items from queue:\n";
   cout << "First item: " << q1.get() << endl;
   cout << "Second item: " << q1.get() << endl;
   cout << "Getting another item: "<< q1.get() << endl;
   q1.put(21);
   q1.put(22);
   q1.put(23);
   q1.put(24);
   q1.put(25);
   q1.put(26);
   q1.put(27);
   q1.put(28);
   q1.put(29);
   q1.put(20);
   q1.put(31);
   q1.put(32);
   cout << "21, 22, 23, 24, 25, 26, 27, 28, 29, 20 31, 32 were put into the queue\n";
   cout << "Getting items from queue:\n";
   cout << "First item: " << q1.get() << endl;
   cout << "Second item: " << q1.get() << endl;
   cout << "Third item: " << q1.get() << endl;
   cout << "Fourth item: " << q1.get() << endl;
   cout << "Fifth item: " << q1.get() << endl;
   cout << "Sixth item: " << q1.get() << endl;
   cout << "Seventh item: " << q1.get() << endl;
   cout << "Eighth item: " << q1.get() << endl;
   cout << "Ninth item: " << q1.get() << endl;
   cout << "Tenth item: " << q1.get() << endl;
   cout << "Eleventh item: " << q1.get() << endl;
   cout << "Twelveth item: " << q1.get() << endl;
   return 0;
}