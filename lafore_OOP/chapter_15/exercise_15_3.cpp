// exercise_15_3.cpp
// Start with a list of int values. Use two normal (not reverse) iterators,
// one moving forward through the list and one moving backward, in a while loop,
// to reverse the contents of the list. You can use the swap() algorithm to save
// a few statements. (Make sure your solution works for both even and odd numbers
// of items.) To see how the experts do it, look at the reverse() function
// in your compiler's ALGORITHM header file.
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[])
{
   list<int> nList;
   int n_Numb;
   char chAnswer;
   do
   {
      cout << "Please, enter a number, which you want to add to the list: ";
      cin >> n_Numb;
      nList.push_back(n_Numb);
      cout << "Do you want to continue (y/n)? ";
      cin >> chAnswer;
   } while (chAnswer!='n' && chAnswer!='N');
   list<int>::iterator f_iter, b_iter;
   cout << "\nList items in the straigth direction:\n";
   for (f_iter = nList.begin(); f_iter!=nList.end(); f_iter++)
   {
      cout << *f_iter << endl;
   }
   f_iter = nList.begin();
   b_iter = nList.end();
   b_iter--;
   while (f_iter!=b_iter)
   {
      swap(*f_iter, *b_iter);
      ++f_iter;
      if (b_iter == f_iter)
      {
         break;
      }
      --b_iter;
   }
   b_iter = nList.begin();
   cout << "\nList items in the reverse direction:\n";
   while (b_iter!=nList.end())
   {
      cout << *b_iter++ << endl;
   }

   return 0;
}