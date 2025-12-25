// verylong.h
// class spefifier for very long integer type
#ifndef _VERYLONG_H_
#define _VERYLONG_H_
#include <iostream>
#include <string.h>                                                            // for strlen(), etc.
#include <stdlib.h>                                                            // for ltoa()
using namespace std;

const int SZ = 1000;                                                           // maximum digits in verylongs

class verylong
{
private:
   char vlstr[SZ];                                                             // verylong number, as a string
   int vlen;                                                                   // length of verylong string
   bool bIsNegative;
   verylong multdigit(const int) const;                                        // prototypes for private functions
   verylong mult10(const verylong) const;
public:
   verylong() : vlen(0), bIsNegative(false)                                    // no-arg constructor
   {
      vlstr[0]='\0';
   }
   verylong(const char s[SZ])                                                  //one-arg constructor
   {                                                                           // for string
      if (s[0]=='-')
      {
         bIsNegative = true;
         strcpy(vlstr, s+1);
      }
      else
      {
         bIsNegative = false;
         strcpy(vlstr, s);
      }
      vlen = strlen(vlstr);
   }
   verylong(const long long n)                                                 // one-arg constructor
   {                                                                           // for long int
      if (n<0)
      {
         bIsNegative = true;
      }
      ltoa(n, vlstr, 10);                                                      // convert to string
      strrev(vlstr);                                                           // reverse it
      vlen = strlen(vlstr);                                                    // find length
   }
   void putvl() const;                                                         // display verylong
   void getvl();                                                               // get verylong from user
   verylong operator + (const verylong);                                       // add verylongs
   verylong operator * (const verylong);                                       // multiply verylongs
   verylong operator - (const verylong);                                       // substract verylongs
};

#endif // _VERYLONG_H_