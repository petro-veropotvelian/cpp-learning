// exercise_8_8.cpp
// Modify the bMoney class from Exercise 12 in Chapter 7, "Arrays and Strings,"
// to include the following arithmetic operations, performed with overloaded
// operators:
//    bMoney = bMoney + bMoney
//    bMoney = bMoney - bMoney
//    bMoney = bMoney * long double (price per widget times number of widgets)
//    long double = bMoney / bMoney (total price divided by price per widget)
//    bMoney = bMoney / long double (total price divided by number of widgets)
// Notice that the / operator is overloaded twice. The compiler can distinguish
// between the two usages because the arguments are different. Remember that
// it's easy to perform arithmetic operations on bMoney objects by performing
// the same operation on their long double data.
// Make sure the main() program asks the user to enter two money strings and a
// floatingpoint number. It should then carry out all five operations and
// display the results. This should happen in a loop, so the user can enter
// more numbers if desired.
// Some money operations don't make sense: bMoney * bMoney doesn't represent
// anything real, since there is no such thing as square money; and you can't
// add bMoney to long double (what's dollars plus widgets?). To make it
// impossible to compile such illegal operations, don't include conversion
// operators for bMoney to long double or long double to bMoney. If you do, and
// you write an expression like
//    bmon2 = bmon1 + widgets; // doesn't make sense
// then the compiler will automatically convert widgets to bMoney and carry out
// the addition. Without them, the compiler will flag such conversions as
// errors, making it easier to catch conceptual mistakes. Also, make any
// conversion constructors explicit.
// There are some other plausible money operations that we don't yet know how
// to perform with overloaded operators, since they require an object on the
// right side of the operator but not the left:
//    long double * bMoney // can't do this yet: bMoney only on right
//    long double / bMoney // can't do this yet: bMoney only on right
// We'll learn how to handle this situation when we discuss friend functions
// in Chapter 11.
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
   cout << amount << endl;
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
   result = money / ld;
   return result;
}
//---------------------------------------------------------------------------------------
long double bMoney::operator/(bMoney div)
{
   long double res;
   res = money/ div.money;
   return res;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   cout << "Enter the first sum\n";
   bMoney m1;
   m1.putmoney();
   cout <<"Enter the second sum\n";
   bMoney m2;
   m2.putmoney();
   cout << "Enter the price of the one widget\n";
   bMoney wp;
   wp.putmoney();
   cout << "Enter a quantity of widgets: ";
   long double quant;
   cin >> quant;
   cin.get();
   bMoney res = m1 + m2;
   m1.getmoney();
   cout << " + ";
   m2.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   res = m1 -m2;
   m1.getmoney();
   cout << " - ";
   m2.getmoney();
   cout << " = ";
   res.getmoney();
   cout << endl;
   bMoney total = wp * quant;
   cout <<"Total cost of " << quant << " widgets = ";
   total.getmoney();
   cout << endl;
   bMoney perwidget = total / quant;
   cout << "Price per widget = ";
   perwidget.getmoney();
   cout << endl;
   long double Numb = total / perwidget;
   cout << "Quantity of widgets: " << Numb << endl;
   return 0;
}