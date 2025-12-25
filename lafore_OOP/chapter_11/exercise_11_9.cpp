// exercise_11_9.cpp
// Exercise 4 in Chapter 10 involved adding an overloaded destructor to the
// linklist class.
// Suppose we fill an object of such a destructor-enhanced class with data, and
// then assign the entire class with a statement such as
//    list2 = list1;
// using the default assignment operator. Now, suppose we later delete the
// list1 object.
// Can we still use list2 to access the same data? No, because when list1 was
// deleted, its destructor deleted all its links. The only data actually
// contained in a linklist object is a pointer to the first link. Once the
// links are gone, the pointer in list2 becomes invalid, and attempts to
// access the list lead to meaningless values or a program crash.
// One way to fix this is to overload the assignment operator so that it copies
// all the data links, as well as the linklist object itself. You'll need to
// follow along the chain, copying each link in turn. As we noted earlier,
// you should overload the copy constructor as well. To make it possible to
// delete linklist objects in main(), you may want to create them using
// pointers and new. That makes it easier to test the new routines. Don't worry
// if the copy process reverses the order of the data.
// Notice that copying all the data is not very efficient in terms of memory
// usage. Contrast this approach with that used in the STRIMEM example in
// Chapter 10, which used only one set of data for all objects, and kept track
// of how many objects pointed to this data.
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
struct link                           //one element of list
   {
   int data;                          //data item
   link* next;                        //pointer to next link
   };
////////////////////////////////////////////////////////////////
class linklist                        //a list of links
   {
   private:
      link* first;                    //pointer to first link
   public:
      linklist()                      //no-argument constructor
         { first = NULL; }            //no first link
      ~linklist();
      linklist(const linklist &l);
      linklist& operator=(const linklist &l);
      void additem(int d);            //add data item (one link)
      void display();                 //display all links
   };
//--------------------------------------------------------------
void linklist::additem(int d)         //add data item
   {
   link* newlink = new link;          //make a new link
   newlink->data = d;                 //give it data
   newlink->next = first;             //it points to next link
   first = newlink;                   //now first points to this
   }
//--------------------------------------------------------------
void linklist::display()              //display all links
   {
   link* current = first;             //set ptr to first link
   while( current != NULL )           //quit on last link
      {
      cout << current->data << endl;  //print data
      current = current->next;        //move to next link
      }
   }
//--------------------------------------------------------------
linklist::~linklist()
{
   while (first != NULL)
   {
      link* current = first;
      cout << "Deleting item " << current->data << endl;
      first = first->next;
      delete current;
   }
}


//--------------------------------------------------------------
linklist& linklist::operator=(const linklist &l)
{
   cout << "Assingnment operator called" << endl;
   if (this->first != l.first)
   {
      while (first != NULL)
      {
         link* current = first;
         cout << "Deleting item " << current->data << endl;
         first = first->next;
         delete current;
      }
      link* cur_item = l.first;
      while (cur_item != NULL)
      {
         this->additem(cur_item->data);
         cur_item = cur_item->next;
      }
   }
   return *this;
}
//--------------------------------------------------------------
linklist::linklist(const linklist &l)
{
   first = NULL;
   cout << "Copy constructor called" << endl;
   link* current = l.first;
   while ( current != NULL )
   {
      this->additem(current->data);
      current = current->next;        //move to next link
   }
}
////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
   cout << "Let's test"<< endl;
   linklist li;       //make linked list

   li.additem(25);    //add four items to list
   li.additem(36);
   li.additem(49);
   li.additem(64);
   li.additem(77);
   cout << "Dislplay linklist li:" << endl;
   li.display();      //display entire list

   linklist l2(li);
   cout << "Dislplay linklist l2:" << endl;
   l2.display();
   linklist l3;
   l3.additem(101);
   l3.additem(102);
   l3.additem(103);
  cout << "Dislplay linklist l3:" <<endl;
  l3.display();
   cout << "~~~~~~~~~" << endl;
   l3 = l2;
   cout << "++++" << endl;
   cout << "Dislplay linklist l3:" <<endl;
   l3.display();
   l3.additem(88);
   l3.additem(99);
   cout << "Dislplay linklist l3 again:" << endl;
   l3.display();
   return 0;
}