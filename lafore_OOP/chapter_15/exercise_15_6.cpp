// exercise_15_6.cpp
//In Exercise 3, two ordinary (non-reverse) iterators were used to reverse the contents
// of a container. Now use one forward and one reverse iterator to carry out the same
// task, this time on a vector.
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char*argv[])
{
   vector<int> v_numbers;
   int n_Numb;
   char chAnswer;
   do
   {
      cout << "Please, enter a number, which you want to add to the vector: ";
      cin >> n_Numb;
      v_numbers.push_back(n_Numb);
      cout << "Do you want to continue (y/n)? ";
      cin >> chAnswer;
   } while (chAnswer!='n' && chAnswer!='N');
   vector<int>::iterator f_iter;
   cout << "\nVector items in the straigth direction:\n";
   for (f_iter = v_numbers.begin(); f_iter!=v_numbers.end(); f_iter++)
   {
      cout << *f_iter << endl;
   }
   vector<int>::reverse_iterator rev_iter;
   rev_iter = v_numbers.rbegin();
   f_iter = v_numbers.begin();
   while (f_iter < rev_iter.base())
   {
      swap(*f_iter, *rev_iter);
      f_iter++;
      rev_iter++;
   }
   f_iter = v_numbers.begin();
   cout << "\nVector items in the reverse direction:\n";
   while (f_iter!=v_numbers.end())
   {
      cout << *f_iter++ << endl;
   }
   return 0;
}