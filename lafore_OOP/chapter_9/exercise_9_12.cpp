// exercise_9_12.cpp
// Amazing as it may seem, the old British pounds-shillings-pence money
// notation (£9.19.11 - see Exercise 10 in Chapter 4, "Structures") isn't the
// whole story. A penny was further divided into halfpennies and farthings,
// with a farthing being worth 1/4 of a penny. There was a halfpenny coin, a
// farthing coin, and a halffarthing coin. Fortunately all this can be
// expressed numerically in eighths of a penny:
// 1/8 penny is a halffarthing
// 1/4 penny is a farthing
// 3/8 penny is a farthing and a half
// 1/2 penny is a halfpenny (pronounced ha'penny)
// 5/8 penny is a halfpenny plus a halffarthing
// 3/4 penny is a halfpenny plus a farthing
// 7/8 penny is a halfpenny plus a farthing and a half
// Let's assume we want to add to the sterling class the ability to handle such
// fractional pennies. The I/O format can be something like £1.1.1-1/4 or
// £9.19.11-7/8, where the hyphen separates the fraction from the pennies.
// Derive a new class called sterfrac from sterling. It should be able to
// perform the four arithmetic operations on sterling quantities that include
// eighths of a penny. Its only member data is an int indicating the number of
// eighths; you can call it eighths. You'll need to overload many of the
// functions in sterling to handle the eighths. The user should be able to type
// any fraction in lowest terms, and the display should also show fractions in
// lowest terms. It's not necessary to use the full-scale fraction class (see
// Exercise 11 in Chapter 6), but you could try that for extra credit.
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;
const int nHalfFartingInPenny = 8;
///////////////////////////////////////////////////////////////////////////////
class sterling
{
protected:
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
};
///////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////
class sterfrac : public sterling
{
private:
   int eights;
protected:
   double toDouble() const;
public:
   sterfrac()
   : sterling()
   {
      eights =0;
   }
   sterfrac(int pnd, int shl, int pnc, int eiht)
   : sterling(pnd, shl, pnc)
   {
      eights = eiht;
   }
   sterfrac(double strl)
   {
      pounds = static_cast<int>(strl);
      double dDecimalFraction = strl - pounds;
      shillings = dDecimalFraction * nShillingsInPound;
      double dPence = dDecimalFraction * nShillingsInPound - shillings;
      pence = dPence * nPenceInShilling;
      double dPennies = dPence * nPenceInShilling - pence;
      eights = dPennies * nHalfFartingInPenny;
   }

   operator double() const;

   void getSterling();
   void putSterling();
   
   sterfrac operator+(sterfrac str) const;
   sterfrac operator-(sterfrac str) const;
   sterfrac operator/(sterfrac str) const;
   sterfrac operator*(double dVal) const;
   sterfrac operator/(double dVal) const;
};
//-----------------------------------------------------------------------------
void sterfrac::putSterling()
{
   sterling::putSterling();
   if (eights > 0)
   {
      cout << "-" << eights << "/8";
   }
}
//-----------------------------------------------------------------------------
double sterfrac::toDouble() const
{
   double dPounds = 0.0;
   dPounds = double((pounds* nShillingsInPound * nPenceInShilling * nHalfFartingInPenny) + 
   (shillings * nPenceInShilling * nHalfFartingInPenny) + (pence * nHalfFartingInPenny) + eights)/ 
   double(nShillingsInPound * nPenceInShilling * nHalfFartingInPenny);
   return dPounds;
}
//-----------------------------------------------------------------------------
sterfrac::operator double() const
{
   double dModernPounds = toDouble();
   return dModernPounds;
}
//-----------------------------------------------------------------------------
void sterfrac::getSterling()
{
   int nFartings;
   do
   {
      cout << "Specify amount of half-fartings: ";
      cin >> nFartings;
      if (nFartings >= nHalfFartingInPenny || nFartings < 0)
      {
         system("CLS");
         cout << "Amount of half-fartings shoud be from 0 to " << (nHalfFartingInPenny - 1) << endl;
      }
      else
      {
         eights = nFartings;
      }
   } while (nFartings >= nHalfFartingInPenny || nFartings < 0);
   sterling::getSterling();
}
//-----------------------------------------------------------------------------
sterfrac sterfrac::operator+(sterfrac str) const
{
   double dModPounds = toDouble();
   dModPounds += (double) str;
   return sterfrac(dModPounds);
}
//-----------------------------------------------------------------------------
sterfrac sterfrac::operator-(sterfrac str) const
{
   double dModPounds = toDouble();
   dModPounds -= (double) str;
   return sterfrac(dModPounds);
}
//-----------------------------------------------------------------------------
sterfrac sterfrac::operator/(sterfrac str) const
{
   double dModPounds = toDouble();
   dModPounds /= (double) str;
   return sterfrac(dModPounds);
}
//-----------------------------------------------------------------------------
sterfrac sterfrac::operator*(double dVal) const
{
   double dModPounds = toDouble();
   dModPounds *= dVal;
   return sterfrac(dModPounds);
}
//-----------------------------------------------------------------------------
sterfrac sterfrac::operator/(double dVal) const
{
   double dModPounds = toDouble();
   dModPounds /= dVal;
   return sterfrac(dModPounds);
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   sterfrac st1(1, 2, 8, 3);
   sterfrac st2(2, 6, 2, 4);
   sterfrac st3 = st1 + st2;
   st1.putSterling();
   cout << endl;
   st2.putSterling();
   cout << endl;
   st3.putSterling();
   cout << endl;
   return 0;
}

