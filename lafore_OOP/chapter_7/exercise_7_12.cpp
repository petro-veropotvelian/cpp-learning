// exercise_7_12.cpp
// Create a class called bMoney. It should store money amounts as long doubles.
// Use the function mstold() to convert a money string entered as input into a
// long double, and the function ldtoms() to convert the long double to a
// money string for display. (See Exercises 6 and 10.) You can call the input
// and output member functions getmoney() and putmoney(). Write another member
// function that adds two bMoney amounts; you can call it madd(). Adding bMoney
// objects is easy: Just add the long double member data amounts in two bMoney
// objects. Write a main() program that repeatedly asks the user to enter two
// money strings, and then displays the sum as a money string. Here's how the
// class specifier might look:
//    class bMoney
//    {
//    private:
//       long double money;
//    public:
//       bMoney();
//       bMoney(char s[]);
//       void madd(bMoney m1, bMoney m2);
//       void getmoney();
//       void putmoney();
//    };
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int NSIZE = 256;
class bMoney
{
private:
   long double money;
   int ldtoms(const long double ldnum, char buf[], const int nSize);
   long double mstold(char txt[], const int nSize);
public:
   bMoney();
   bMoney(char s[]);
   void madd(bMoney m1, bMoney m2);
   void getmoney();
   void putmoney();
};

bMoney::bMoney()
: money(0)
{
}

bMoney::bMoney(char s[])
{
   money = mstold(s,NSIZE);
}

int bMoney::ldtoms(const long double ldnum, char buf[], const int nSize)
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
   return 0;
}

long double bMoney::mstold(char txt[], const int nSize)
{
   char tmp[nSize];
   int length = strlen(txt);
   int indx = 0;
   for (int i=0; i<length; i++)
   {
      if ((txt[i]>='0' && txt[i]<='9')|| txt[i]=='.')
      {
         tmp[indx++] = txt[i];
      }
   }
   tmp[indx] = '\0';
#ifdef debug
   cout << tmp << endl;
#endif
   return stold(tmp);
}

void bMoney::putmoney()
{
   char amount[NSIZE];
   memset(amount, '\0', sizeof(char)*NSIZE);
   cout << "Enter money amount: ";
   cin >> amount;
   money = mstold(amount, NSIZE);
}

void bMoney::getmoney()
{
   char amount[NSIZE];
   memset(amount, '\0', sizeof(char)*NSIZE);
   ldtoms(money, amount, NSIZE);
   cout << amount << endl;
}

void bMoney::madd(bMoney m1, bMoney m2)
{
   money  = m1.money + m2.money;
}


int main(int argc, char* argv[])
{
   char cAnsw;
   do
   {
      bMoney mon1;
      mon1.putmoney();
      cout << "Do you want to enter another amount of money (y/n)?: ";
      cin >> cAnsw;
      if (cAnsw == 'y' || cAnsw == 'Y')
      {
         bMoney mon2, monR;
         mon2.putmoney();
         monR.madd(mon1, mon2);
         mon1.getmoney();
         cout << "+";
         mon2.getmoney();
         cout << "=";
         monR.getmoney();
      }
      else
      {
         mon1.getmoney();
      }
      cout << "Do you want to continue (y/n)?: ";
      cin >> cAnsw;
   } while (cAnsw != 'n' && cAnsw != 'N');
   return 0;
}