// exercise_8_2.cpp
// Write a program that substitutes an overloaded += operator for the
// overloaded + operator in the STRPLUS program in this chapter. This operator
// should allow statements like
//    s1 += s2;
// where s2 is added (concatenated) to s1 and the result is left in s1. The
// operator should also permit the results of the operation to be used in other
// calculations, as in
//    s3 = s1 += s2;
// overloaded '+' operator concatenates strings
#include <iostream>
#include <cstring>                                                   // for strcpy(), strcat()
#include <cstdlib>                                                   // for exit()
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class String                                                         // user-defined string type
{
private:
   enum { SZ = 80 };                                                 // max size of String objects
   char str[SZ];                                                     // holds a string
public:
   String()                                                          // constructor, no args
   {
      str[0] = '\0';
   }
   String(const char s[])                                            // constructor, one arg
   {
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
         cout << "\nString overflow";
         exit(1);
      }
      return temp;                                                   // return temp String
   }
   String operator+=(String ss)
   {
      if ((strlen(str) + strlen(ss.str))<SZ)
      {
         strcat(str, ss.str);
      }
      else
      {
         cout << "\nString overflow";
         exit(1);
      }
      return String(str);
   }

};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   String s1 ="\nMerry Christrmas! ";                                 // uses constructor 2
   String s2 = "Happy new year!";                                     // uses constructor 2
   String s3;                                                        // uses constructor 1
   String s4 = "\nHello, World!";

   s1.display();                                                     // display strings
   cout << endl;
   s2.display();
   cout << endl;
   s3.display();
   cout << endl;
   s1 += s2;                                                     // add s2 to s1,
                                                                     // assign to s3
   s1.display();                                                     // display s1
   cout << endl;
   s3 = s2+=s4;
   s3.display();
   cout << endl;
   return 0;
}