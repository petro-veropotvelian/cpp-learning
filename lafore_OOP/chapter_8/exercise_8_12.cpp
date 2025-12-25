// exercise_8_12.cpp
// Write a program that incorporates both the bMoney class from Exercise 8 and
// the sterling class from Exercise 11. Write conversion operators to convert
// between bMoney and sterling, assuming that one pound (£1.0.0) equals fifty
// dollars ($50.00). This was the approximate exchange rate in the 19th century
// when the British Empire was at its height and the pounds-shillings-pence
// format was in use. Write a main() program that allows the user to enter an
// amount in either currency and then converts it to the other currency and
// displays the result. Minimize any modifications to the existing bMoney and
// sterling classes.
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int NSIZE = 256;
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;
const double dUsdInPound = 50.0;
/////////////////////////////////////////////////////////////////////////////////////////
class sterling;
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
   operator sterling() const;
};
///////////////////////////////////////////////////////////////////////////////
class sterling
{
private:
   int pounds;
   int shillings;
   int pence;
   double toDouble() const;
public:
   sterling()
   : pounds(0), shillings(0), pence(0)
   {}
   sterling(int pnd, int shl, int pnc)
   : pounds(pnd), shillings(shl), pence(pnc)
   {}
   sterling(double strl)
   {
      pounds = static_cast<int>(strl);
      double dDecimalFraction = strl - pounds;
      shillings = dDecimalFraction * nShillingsInPound;
      double dPence = nShillingsInPound * nPenceInShilling * dDecimalFraction - shillings * nPenceInShilling;
      dPence = dPence + 0.5 -(dPence < 0);
      pence = (int) dPence;
   }
   void getSterling();
   void putSterling();
   operator double() const;

   sterling operator+(sterling str) const;
   sterling operator-(sterling str) const;
   sterling operator/(sterling str) const;
   sterling operator*(double dVal) const;
   sterling operator/(double dVal) const;
   operator bMoney() const;
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
//---------------------------------------------------------------------------------------
bMoney::operator sterling() const
{
   double dPoundsFromUSD = money / dUsdInPound;
   return sterling(dPoundsFromUSD);
}
//---------------------------------------------------------------------------------------
double sterling::toDouble() const
{
   double dPounds = 0.0;
   dPounds = double((pounds* nShillingsInPound * nPenceInShilling )+ 
   (shillings * nPenceInShilling) + pence)/ double(nShillingsInPound * nPenceInShilling);
   return dPounds;
}
//-----------------------------------------------------------------------------
void sterling::getSterling()
{
   int nPence;
   do
   {
      cout << "Specify amount of pence: ";
      cin >> nPence;
      if (nPence >= nPenceInShilling || nPence < 0)
      {
         system("CLS");
         cout << "Amount of pence shoud be from 0 to " << (nPenceInShilling - 1) << endl;
      }
      else
      {
         pence = nPence;
      }
   } while (nPence >= nPenceInShilling || nPence < 0);
   int nShillings;
   do
   {
      cout << "Specify amount of shillings: ";
      cin >> nShillings;
      if (nShillings >= nShillingsInPound || nShillings < 0)
      {
         system("CLS");
         cout << "Amount of shillings should be from 0 to " << (nShillingsInPound - 1) << endl;
      }
      else
      {
         shillings = nShillings;
      }
   } while (nShillings >= nShillingsInPound || nShillings < 0);
   int nPounds;
   do
   {
      cout << "Specify amout of pounds: ";
      cin >> nPounds;
      if (nPounds < 0)
      {
         system("CLS");
         cout << "Amount of pounds should not be less than 0" << endl;
      }
      else
      {
         pounds = nPounds;
      }
   } while (nPounds < 0);
}
//-----------------------------------------------------------------------------
void sterling::putSterling()
{
   cout << '\x9C'<< pounds << '.' << shillings << '.' << pence;
}
//-----------------------------------------------------------------------------
sterling::operator double() const
{
   double dModernPounds = toDouble();
   return dModernPounds;
}
//-----------------------------------------------------------------------------
sterling sterling::operator+(sterling str) const
{
   double dModPounds = toDouble();
   dModPounds += (double) str;
   return sterling(dModPounds);
}
//-----------------------------------------------------------------------------
sterling sterling::operator-(sterling str) const
{
   double dModPounds = toDouble();
   dModPounds -= (double) str;
   return sterling(dModPounds);
}
//-----------------------------------------------------------------------------
sterling sterling::operator/(sterling str) const
{
   double dModPounds = toDouble();
   dModPounds /= (double) str;
   return sterling(dModPounds);
}
//-----------------------------------------------------------------------------
sterling sterling::operator*(double dVal) const
{
   double dModPounds = toDouble();
   dModPounds *= dVal;
   return sterling(dModPounds);
}
//-----------------------------------------------------------------------------
sterling sterling::operator/(double dVal) const
{
   double dModPounds = toDouble();
   dModPounds /= dVal;
   return sterling(dModPounds);
}
//-----------------------------------------------------------------------------
sterling::operator bMoney() const
{
   long double dPoundsAmount = toDouble();
   dPoundsAmount*=dUsdInPound;
   return bMoney(dPoundsAmount);
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   cout << "Please specify a currency you want to convert\n"
            "u - if you want to specify $ USD;\n"
            "p - if you want to specify "<< '\x9C' << " pounds;\n";
   cout << "Your choice: ";
   char cAnsw;
   cin >> cAnsw;
   if (cAnsw=='u' || cAnsw=='U')
   {
      bMoney usd;
      usd.putmoney();
      sterling gpd = (sterling) usd;
      usd.getmoney();
      cout << " is equeal to ";
      gpd.putSterling();
      cout << endl;
   }
   else if (cAnsw=='p' || cAnsw=='P')
   {
      sterling pnds;
      pnds.getSterling();
      bMoney usd = (bMoney) pnds;
      pnds.putSterling();
      cout << " is equal to ";
      usd.getmoney();
   }
   else
   {
      cout << "You have chose wrong option!";
   }
   return 0;
}