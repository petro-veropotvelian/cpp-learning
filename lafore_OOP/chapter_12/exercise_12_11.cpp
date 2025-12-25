// exercise_12_11.cpp
// Start with the bMoney class, last seen in Exercise 5 in Chapter 11. Overload the insertion
// (<<) and extraction (>>) operators to perform I/O on bMoney quantities. Perform some
// sample I/O in main().
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <limits>

using namespace std;
const int NSIZE = 256;
/////////////////////////////////////////////////////////////////////////////////////////
class bMoney
{
private:
   long double money;
   int ldtoms(const long double ldnum, char buf[], const int nSize);
   long double mstold(const char txt[], const int nSize);
public:
   bMoney();
   bMoney(const char s[]);
   bMoney(long double ld);
   bMoney operator+(bMoney m2) const;
   bMoney operator-(bMoney m2) const;
   bMoney operator*(long double mult) const;
   long double operator/(bMoney m2);
   bMoney operator/(long double ld);
   friend bMoney operator*(bMoney m1, bMoney m2);
   friend bMoney operator/(bMoney m1, bMoney m2);
   friend istream& operator >> (istream &is, bMoney &Mn);
   friend ostream& operator << (ostream &os, bMoney &Mn); 
};
//---------------------------------------------------------------------------------------
bMoney::bMoney()
: money(0)
{
}
//---------------------------------------------------------------------------------------
bMoney::bMoney(const char s[])
{
   money = mstold(s, NSIZE);
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
long double bMoney::mstold(const char txt[], const int nSize)
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
//---------------------------------------------------------------------------------------
istream& operator >> (istream &is, bMoney &Mn)
{
   do
   {
      is.clear();
      char amount[NSIZE];
      memset(amount, '\0', sizeof(char)*NSIZE);
      cout << "Enter amount of money in the following format $1,234,567.89: ";
      is >> amount;
      if (is.good())
      {
         try
         {
            Mn.money = Mn.mstold(amount, NSIZE);
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            break;
         }
         catch(const std::exception& e)
         {
            is.clear();
            cerr << "\nError! Incorrect input!\nPress <ENTER> to continue..." << endl;
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            system("CLS");
            continue;
         }    
      }
      is.clear();
      cerr << "\nError! Incorrect input!\nPress <ENTER> to continue..." << endl;
      is.ignore(numeric_limits<streamsize>::max(),'\n');
      is.ignore(numeric_limits<streamsize>::max(),'\n');
      system("CLS");
      continue;

   } while (true);
   return is;  
}
//---------------------------------------------------------------------------------------
ostream& operator << (ostream &os, bMoney &Mn)
{
   char amount[NSIZE];
   memset(amount, '\0', sizeof(char)*NSIZE);
   Mn.ldtoms(Mn.money, amount, NSIZE);
   os << amount;
   return os;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   bMoney m1;
   cin >> m1;
   cout << "You have entered: " << m1 << endl;
   return 0;
}