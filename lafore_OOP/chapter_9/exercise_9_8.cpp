// exercise_9_8.cpp
// Operators in some computer languages, such as Visual Basic, allow you to
// select parts of an existing string and assign them to other strings. (The
// Standard C++ string class offers a different approach.) Using inheritance,
// add this capability to the Pstring class of Exercise 2. In the derived
// class, Pstring2, incorporate three new functions: left(), mid(), and
// right().
//    s2.left(s1, n) // s2 is assigned the leftmost n characters from s1
//    s2.mid(s1, s, n) // s2 is assigned the middle n characters
//                     // from s1, starting at character number s
//                     // (leftmost character is 0)
//    s2.right(s1, n) // s2 is assigned the rightmost n characters from s1
// You can use for loops to copy the appropriate parts of s1, character by
// character, to a   temporary Pstring2 object, which is then returned. For
// extra credit, have these functions return by reference, so they can be used
// on the left side of the equal sign to change parts of an existing string.
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
      if (strlen(s) < SZ-1)
      {
         strcpy(str, s);
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
   Pstring()
   : String()
   {}
   Pstring(const char *s)
   : String(s)
   {}
   void left(const Pstring &s1, int n)
   {
      int i, j;
      j = strlen(str);
      for (i=0; i < n && j < SZ-1; i++)
      {
         str[j] = s1.str[i];
         j++;
      }
      str[j] = '\0';
   }
   void mid(const Pstring &s1, int s=0, int n=1)
   {
      int j=strlen(str);
      for (int i=s; i< s+n && j<SZ-1; i++)
      {
         str[j] = s1.str[i];
         j++;
      }
      str[j] ='\0';
   }
   void right(const Pstring &s1, int n)
   {
      int j=strlen(str);
      for (int i= SZ-n-1; j<SZ-1; i++)
      {
         str[j] = s1.str[i];
         j++;
      }
      str[j]='\0';
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
   //s1.left(s2, 6);
   //s1.mid(s2, 24, 6);
   s1.right(s2, 7);
   s1.display();
   return 0;
}