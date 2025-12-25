// strequal.cpp
// overloaded '==' operator compares strings
#include <iostream>
#include <cstring>                                                   // for strcpy(), strcat()
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
   void display() const                                              // display a String
   {
      cout << str;
   }
   void getstr()                                                     // read a String
   {
      cin.get(str, SZ);
   }
   bool operator== (String ss) const                                // check for equality
   {
      return (strcmp(str, ss.str)==0) ? true : false;
   }

};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   String s1 ="yes";
   String s2 = "no";
   String s3;

   cout << "\nEnter 'yes' or 'no': ";
   s3.getstr();                                                      // get String from user
   if (s3 == s1)
   {
      cout << "You typed yes\n";
   }
   else if (s3 == s2)
   {
      cout << "You typed no\n";
   }
   else
   {
      cout <<"You didn't follow instructions\n";
   }
   return 0;
}