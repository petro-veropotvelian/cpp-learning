// exercise_14_11.cpp
// Start with the STRPLUS program in Chapter 8. Add an exception class, and throw
// an exception in the one-argument constructor if the initialization string is
// too long. Throw another in the overloaded + operator if the result will be too
// long when two strings are concatenated. Report which of these errors has occurred.
// overloaded '+' operator concatenates strings
#include <iostream>
#include <cstring>                                                   // for strcpy(), strcat()
#include <cstdlib>                                                   // for exit()
#include <string>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class String                                                         // user-defined string type
{
private:
   enum { SZ = 80 };                                                 // max size of String objects
   char str[SZ];                                                     // holds a string
public:
   class StringException
   {
      public:
         string str_message;
      StringException(string msg)
       : str_message(msg)
      {
      }
   };
   String()                                                          // constructor, no args
   {
      str[0] = '\0';
   }
   String(const char s[])                                            // constructor, one arg
   {
      if (strlen(s)>=80)
      {
         throw String::StringException("Initialization string is too long: only 79 characters are allowed!");
      }
      strcpy(str, s);
   }
   void display() const                                              // display the String
   {
      cout << str;
   }
   String operator+ (String ss) const                                // add Strings
   {
      String temp;                                                   // make a temporary String
      if (strlen(str) + strlen(ss.str) < SZ)
      {
         strcpy(temp.str, str);                                      // copy this string to temp
         strcat(temp.str, ss.str);                                   // add the argument string
      }
      else
      {
         throw String::StringException("String overflow: the resulting string is longer than 79 symbols!");
         //cout << "\nString overflow";
         //exit(1);
      }
      return temp;                                                   // return temp String
   }

};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   try
   {
      String s1 ="\nMerry Christrmas! ";                                 // uses constructor 2
      String s2 = "Happy new year!";                                     // uses constructor 2
      String s3;                                                         // uses constructor 1

      s1.display();                                                     // display strings
      s2.display();
      s3.display();

      s3 = s1 + s2;                                                     // add s2 to s1,
                                                                        // assign to s3
      s3.display();                                                     // display s3

      String s4("Very long initialization string which contains too many different characters and doesn't fit conditios.");
      cout << endl;
   }
   catch (String::StringException StExc)
   {
      std::cerr << "\nString exception!\n" << StExc.str_message << '\n';
   }
   
   return 0;
}