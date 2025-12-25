// exercise_15_9.cpp
// We listed the function objects corresponding to the C++ operators in
// Table 15.10, and, in the PLUSAIR program earlier in this chapter, we
// showed the function object plus<>() used with the accumulate() algorithm.
// It wasn't necessary to provide arguments to the function objects in that
// example, but sometimes it is. However, you can’t put the argument within
// the parentheses of the function object, as you might expect. Instead, you
// use a function adapter called bind1st or bind2nd to bind the argument to
// the function. For example, suppose you were looking for a particular string
// (call it searchName) in a container of strings (called names). You can say
// ptr = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(),
//               searchName));
// Here equal_to<>() and searchName are arguments to bind2nd(). This
// statement returns an iterator to the first string in the container equal 
// to searchName. Write a program that incorporates this statement or a similar
// one to find a string in a container of strings. Itshould display the
// position of searchName in the container.
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
   vector<string> v_names = {"John", "Katherine", "Marianna", "Jack", "Robert", "Alfred", "Helen", "Petr", "Mark", "Sarah"};
   for (auto s : v_names)
   {
      cout << s << endl;
   }
   cout << "Specify a name, you'd like to find: ";
   string str_SearchName;
   cin >> str_SearchName;
   auto pred = [str_SearchName](const string &s) {return s == str_SearchName; };
   auto iter = find_if(v_names.begin(), v_names.end(), pred);
   if (iter!=v_names.end())
   {
      cout << *iter << " found at position " << (iter - v_names.begin()) << endl;
   }
   else
   {
      cout << str_SearchName << " not found." << endl;
   }
   return 0;
}