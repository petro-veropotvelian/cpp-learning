// exercise_14_3.cpp
// Add exceptions to the queue template in Exercise 2. Throw two exceptions: one if
// the capacity of the queue is exceeded, the other if the program tries to remove
// an item from an empty queue. One way to handle this is to add a new data member
// to the queue: a count of the number of items currently in the queue. Increment
// the count when you insert an item, and decrement it when you remove an item. 
// Throw an exception if this count exceeds the capacity of the queue, or if it becomes
// less than 0.
// You might try making the main() part of this exercise interactive, so the user
// can put values on a queue and take them off. This makes it easier to exercise 
// the queue. Following an exception, the program should allow the user to recover from
// a mistake without corrupting the contents of the queue.
#include <iostream>
using namespace std;
const int MAX = 5;
////////////////////////////////////////////////////////////////////////////////////////
template <class cType>
class Queue
{
private:
   cType que[MAX];
   int head;
   int tail;
   int counter;
public:
   class QueueException
   {
   public:
      string strInfo;
      QueueException(string additionlInfo)
      : strInfo(additionlInfo)
      {}
   };

   Queue()
   : head(-1), tail(-1), counter(0)
   {};
   void put(cType item)
   {
      if (counter < MAX)
      {
         que[++tail] = item;
         ++counter;
         if (tail>= MAX -1)
         {
            tail = -1;
         }
      }
      else
      {
         throw QueueException("Error: the capacity of the queue is exceeded!");
      }
   }
   cType get(void)
   {
      if (counter > 0)
      {
         cType value = que[++head];
         --counter;
         if (head >= MAX -1 )
         {
            head = -1;
         }
         return value;
      }
      else
      {
         throw QueueException("Error: the queue is empty!");
      }
   }
};

//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   Queue<float> flQue;
   char chResp;
   float fData;
   do
   {
      cout << "Do you want to input data (p), get data(g) or exit(x)? ";
      cin >> chResp;
      try
      {
         if (chResp == 'p' || chResp=='P')
         {
            cout << "Input the value to put: ";
            cin >> fData;
            flQue.put(fData);
         }
         if (chResp == 'g' || chResp == 'G')
         {
            fData = flQue.get();
            cout << "You get " << fData << " from the queue" << endl;
         }
      }
      catch (Queue<float>::QueueException Q_Ex)
      {
         cout << Q_Ex.strInfo << endl;
      }
   }
   while (chResp!='x' && chResp!='X');
   cout << "Bye!" << endl;
   return 0;
}