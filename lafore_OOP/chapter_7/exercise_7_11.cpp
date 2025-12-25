// exercise_7_11.cpp
// Refer back to the discussion of money strings in Exercise 6. Write a
// function called ldtoms() to convert a number represented as type long double
// to the same value represented as a money string. First you should check that
// the value of the original long double is not too large. We suggest that you
// don't try to convert any number greater than 9,999,999,999,999,990.00.
// Then convert the long double to a pure string (no dollar sign or commas)
// stored in memory, using an ostrstream object, as discussed earlier in this
// chapter. The resulting formatted string can go in a buffer called ustring.
// You'll then need to start another string with a dollar sign; copy one digit
// from ustring at a time, starting from the left, and inserting a comma into
// the new string every three digits.
// Also, you'll need to suppress leading zeros. You want to display $3,124.95,
// for example, not $0,000,000,000,003,124.95. Don't forget to terminate the
// string with a '\0' character.
// Write a main() program to exercise this function by having the user
// repeatedly input numbers in type long double format, and printing out the
// result as a money string.
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <Windows.h>
using namespace std;

//#define debug
const int ARSIZE = 256;
int ldtoms(const long double ldnum, char* buf, const int nSize)
{
   memset(buf, '\0', sizeof(char)*nSize);
   sprintf(buf, "%Lf", ldnum);
#ifdef debug
   cout << "buf = " << buf << endl;
#endif
   char* pch;
   int nIndex;
   pch = strchr(buf, '.');
   nIndex = pch - buf +1;
#ifdef debug
   cout << "nIndex = " << nIndex << endl;
#endif
   buf[nIndex+2] = '\0';
   char tmp[nSize];
   int j=0;
   int x=0;
   char fractBuf[4];
   for (int i=strlen(buf)-1; i>=nIndex-1; i--)
   {
      fractBuf[j++]=buf[i];
   }
   fractBuf[j] = '\0';
#ifdef debug
   cout << "fractBuf = " << fractBuf << endl;
#endif
   j=0;
   char tmpBuf[nSize];
   for (int i=nIndex-2; i>=0; i--)
   {

      tmpBuf[j]=buf[i];
      j++;
      if (++x % 3 == 0  && i!=0)
      {
         tmpBuf[j]='\'';
         j++;
      }

   }
   tmpBuf[j]='\0';
#ifdef debug
   cout << "tmpBuf = " << tmpBuf << endl;
#endif
   memset(buf, '\0', sizeof(char)*nSize);
   x=0;
   buf[x++]='$';
   for (j=strlen(tmpBuf)-1; j>=0; j--)
   {
      buf[x++]=tmpBuf[j];
   }
   for (int i=strlen(fractBuf)-1; i>=0; i--)
   {
      buf[x++]=fractBuf[i];
   }
   buf[x] = '\0';
   return 0 ;
}
int main(int argc, char* argv[])
{
   char charBuf[ARSIZE];
   char cAnsw;
   long double ld;
   do
   {
      cout << "Enter amount of money: ";
      cin >> ld;
      if (ld <=0)
      {
         cout << "Error! It should be not less than 0!" << endl;
         cin.get();
         system("CLS");
      }
      else
      {
         int nRes = ldtoms(ld, charBuf, ARSIZE);
         cout << "After conversion: " << charBuf << endl;
         cout << "Convert another (y/n)?: ";
         cin >> cAnsw;
      }
   } while (cAnsw != 'n' && cAnsw != 'N');
   return 0;
}