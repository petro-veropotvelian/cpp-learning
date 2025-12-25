// strequal.cpp
// convert between ordinary strings and class String
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
   operator char*()                                                  // conversion operator
   {
                                                                     // convert String to C-string
      return str;
   }

};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   String s1;                                               // uses no-arg constructor
                                                            // create and initialize C-string
   char xstr[] = "Joyeux Noel!";

   s1 = xstr;                                               // uses 1-arg constructor
                                                            // to convert C-string to String
   s1.display();                                            // display String
   String s2 = "Bonne Annee!";                              // uses 1-arg constructor
                                                            // to initialize String
   cout << static_cast<char*>(s2);                          // use conversion operator
   cout << endl;                                            // to convert String to C-string
                                                            // before sending to << op
   return 0;
}