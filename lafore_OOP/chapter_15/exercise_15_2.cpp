// exercise_15_2.cpp
// Apply the sort() algorithm to an array of words entered by the user, and display
// the result. Use push_back() to insert the words, and the [] operator and size()
// to display them.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char*argv[])
{
   vector <string> v_strings;
   string str;
   char chAnsw;
   int nIndex = 0;
   do
   {
      cout << "Please, enter a word: ";
      cin >> str;
      nIndex++;
      v_strings.push_back(str);
      cout << "Do you want to continue (y/n)? ";
      cin >> chAnsw;
      str.clear();
   } while (chAnsw!='n' && chAnsw!='N');
   cout << "\nArray of strings before sorting:\n";
   vector<string>::iterator iter;
   for (iter=v_strings.begin(); iter!=v_strings.end(); iter++)
   {
      cout << *iter << endl;
   }
   sort(v_strings.begin(), v_strings.begin()+nIndex);
   cout << "\nArray of string after sorting:\n";
   for (iter=v_strings.begin(); iter!=v_strings.end(); iter++)
   {
      cout << *iter << endl;
   }
   return 0;
}