// exercise_9_2.cpp
// Recall the STRCONV example from Chapter 8. The String class in this example
// has a flaw: It does not protect itself if its objects are initialized to
// have too many characters.
// (The SZ constant has the value 80.) For example, the definition
//    String s = "This string will surely exceed the width of the "
//               "screen, which is what the SZ constant represents.";
// will cause the str array in s to overflow, with unpredictable consequences,
// such as crashing the system.
// With String as a base class, derive a class Pstring (for "protected string")
// that prevents buffer overflow when too long a string constant is used in a
// definition. A new constructor in the derived class should copy only SZ–1
// characters into str if the string constant is longer, but copy the entire
// constant if it's shorter. Write a main() program to test different lengths
// of strings.

// convert between ordinary strings and class String
#include <iostream>
#include <cstring>                                                   // for strcpy(), strcat()
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class String                                                         // user-defined string type
{
protected:
   enum { SZ = 80 };                                                 // max size of String objects
   char str[SZ];                                                     // holds a string
public:
   String()                                                          // constructor, no args
   {
      str[0] = '\0';
   }
   String(const char* s)                                            // constructor, one arg
   {
      strcpy(str, s);
   }
   void display() const                                              // display a String
   {
      cout << str;
   }
   operator char*()                                                  // conversion operator
   {
                                                                     // convert String to C-string
      return str;
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
class Pstring : public String
{
public:
   Pstring(const char* s)
   {
      if (strlen(s) < SZ-1)
      {
         //cout << "Constructor Pstring(s), s = " << s << endl;
         String(s);
         //strcpy(str, s);
      }
      else
      {
         int i;
         for (i=0; i<SZ-1; i++)
         {
            str[i] = s[i];
         }
         str[i] = '\0';
      }
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char regstr[] = "Regular string";
   char longstr[] = "This string will surely exceed the width of the screen, which is what the SZ constant represents.";
   Pstring s1(regstr);
   //cout << static_cast<char*>(s1);
   s1.display();
   cout << endl;
   Pstring s2(longstr);
   s2.display();
   cout << endl;
   return 0;
}