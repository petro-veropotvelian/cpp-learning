// exercise_10_4.cpp
// Add a destructor to the LINKLIST program. It should delete all the links
// when a linklist object is destroyed. It can do this by following along
// the chain, deleting each link as it goes. You can test the destructor by
// having it display a message each time it deletes a link; it should delete
// the same number of links that were added to the list. (A destructor is 
// called automatically by the system for any existing objects when the program
// exits.)
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
////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
   linklist li;       //make linked list

   li.additem(25);    //add four items to list
   li.additem(36);
   li.additem(49);
   li.additem(64);

   li.display();      //display entire list

   return 0;
}