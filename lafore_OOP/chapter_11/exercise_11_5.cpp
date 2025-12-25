// exercise_11_5.cpp
// Start with the program of Exercise 8 in Chapter 8, which overloaded five
// arithmetic operators for money strings. Add the two operators that couldn't
// be overloaded in that exercise. These operations
//    long double * bMoney // number times money
//    long double / bMoney // number divided by money
// require friend functions, since an object appears on the right side of the
// operator while a numerical constant appears on the left. Make sure that the
// main() program allows the user to enter two money strings and a
// floating-point value, and then carries out all seven arithmetic operations
// on appropriate pairs of these values.
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int NSIZE = 256;
/////////////////////////////////////////////////////////////////////////////////////////
class bMoney
{
private:
   long double money;
   int ldtoms(const long double ldnum, char buf[], const int nSize);
   long double mstold(char txt[], const int nSize);
public:
   bMoney();
   bMoney(char s[]);
   bMoney(long double ld);
   void getmoney();
   void putmoney();
   bMoney operator+(bMoney m2) const;
   bMoney operator-(bMoney m2) const;
   bMoney operator*(long double mult) const;
   long double operator/(bMoney m2);
   bMoney operator/(long double ld);
   friend bMoney operator*(bMoney m1, bMoney m2);
   friend bMoney operator/(bMoney m1, bMoney m2);
};
//---------------------------------------------------------------------------------------
bMoney::bMoney()
: money(0)
{
}
//---------------------------------------------------------------------------------------
bMoney::bMoney(char s[])
{
   money = mstold(s,NSIZE);
}
//---------------------------------------------------------------------------------------
bMoney::bMoney(long double ld)
:money(ld)
{
}
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
void bMoney::putmoney()
{
   char amount[NSIZE];
   memset(amount, '\0', sizeof(char)*NSIZE);
   cout << "Enter money amount: ";
   cin >> amount;
   money = mstold(amount, NSIZE);
}
//---------------------------------------------------------------------------------------
void bMoney::getmoney()
{
   char amount[NSIZE];
   memset(amount, '\0', sizeof(char)*NSIZE);
   ldtoms(money, amount, NSIZE);
   cout << amount;
}
//---------------------------------------------------------------------------------------
bMoney bMoney::operator+(bMoney m2) const
{
   bMoney result;
   result.money = money + m2.money;
   return result;
}
//---------------------------------------------------------------------------------------
bMoney bMoney::operator-(bMoney m2) const
{
   bMoney result;
   result.money = money - m2.money;
   return result;
}
//---------------------------------------------------------------------------------------
bMoney bMoney::operator*(long double mult) const
{
   bMoney result;
   result.money = money * mult;
   return result;
}
//---------------------------------------------------------------------------------------
bMoney bMoney::operator/(long double ld)
{
   bMoney result;
   if (ld == 0L)
   {
      cout << "Attempt to divide by zero!" << endl;
      exit(1);
   }
   result = money / ld;
   return result;
}
//---------------------------------------------------------------------------------------
long double bMoney::operator/(bMoney div)
{
   long double res;
   if (div.money == 0L)
   {
      cout << "Attempt to divide by zero!" << endl;
      exit(1);
   }
   res = money/ div.money;
   return res;
}
//---------------------------------------------------------------------------------------
bMoney operator*(bMoney m1, bMoney m2)
{
   long double mult = m1.money * m2.money;
   return bMoney(mult);
}
//---------------------------------------------------------------------------------------

bMoney operator/(bMoney m1, bMoney m2)
{
   if (m2.money == 0L)
   {
      cout << "Attempt to divide by zero!" << endl;
      exit(1);
   }
   return bMoney(m1.money / m2.money);
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   bMoney m1("12.40");
   bMoney m2("6.55");
   long double ldm = 300.45L;
   bMoney res = m1 + m2;
   m1.getmoney();
   cout << " + ";
   m2.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   res = m1 - m2;
   m1.getmoney();
   cout << " - ";
   m2.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   res = ldm / m2;
   cout << "$" << ldm << " / ";
   m2.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   res = ldm * m1;
   cout << "$" << ldm << " * ";
   m1.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   return 0;
}