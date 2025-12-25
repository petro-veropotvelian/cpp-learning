// exercise_10_2.cpp
// Start with the String class from the NEWSTR example in this chapter. Add a
// member function called upit() that converts the string to all uppercase. You
// can use the toupper() library function, which takes a single character as an
// argument and returns a character that has been converted (if necessary) to
// uppercase. This function uses the CCTYPE header file. Write some code in
// main() to test upit().
#include <iostream>
#include <cstring>                                                   // for strcpy(), etc.
#include <cctype>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////
class String                                                         // user-defined string type
{
private:
   char* str;                                                        // pointer to string
public:
   String(char* s)                                                   // constructor, one arg
   {
      int length = strlen(s);                                        // length of string argument
      str = new char[length + 1];                                    // get memory
      strcpy(str, s);                                                // copy argument to it
   }
   ~String()                                                         // destructor
   {
      cout << "Deleting str.\n";
      delete[] str;                                                  // release memory
   }
   void display()                                                    // display the String
   {
      cout << str << endl;
   }
   void upit()
   {
      for (int i=0; i<strlen(str); i++)
      {
         str[i] = std::toupper(str[i]);
      }
   }
};
//////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   String s1 = "Who knows nothing doubts nothing.";                  // uses 1-arg constructor
   cout << "Before using upit() function:\n";
   cout << "s1 = ";                                                  // display string
   s1.display();
   s1.upit();
   cout << "After using of upit() function:\n";
   cout << "s1 = ";
   s1.display();
   return 0;
}