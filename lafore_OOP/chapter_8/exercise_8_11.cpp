// exercise_8_11.cpp
// Remember the sterling structure? We saw it in Exercise 10 in Chapter 2,
// "C++ Programming Basics," and in Exercise 11 in Chapter 5, among other
// places. Turn it into a class, with pounds (type long), shillings (type int),
// and pence (type int) data items.
// Create the following member functions:
// • no-argument constructor
// • one-argument constructor, taking type double (for converting from decimal
//   pounds)
// • three-argument constructor, taking pounds, shillings, and pence
// • getSterling() to get an amount in pounds, shillings, and pence from the
//   user, format £9.19.11
// • putSterling() to display an amount in pounds, shillings, and pence,
//   format £9.19.11
// • addition (sterling + sterling) using overloaded + operator
// • subtraction (sterling - sterling) using overloaded - operator
// • multiplication (sterling * double) using overloaded * operator
// • division (sterling / sterling) using overloaded / operator
// • division (sterling / double) using overloaded / operator
// • operator double (to convert to double)
// To perform arithmetic, you could (for example) add each object's
// data separately: Add the pence, carry, add the shillings, carry, and so on.
// However, it's easier to use the conversion operator to convert both sterling
// objects to type double, perform the arithmetic on the doubles, and convert
// back to sterling. Thus the overloaded + operator looks like this:
//    sterling sterling::operator + (sterling s2)
//    {
//       return sterling( double(sterling(pounds, shillings, pence))
//                        + double(s2) );
//    }
// This creates two temporary double variables, one derived from the object of
// which the function is a member, and one derived from the argument s2. These
// double variables are then added, and the result is converted back to
// sterling and returned.
// Notice that we use a different philosophy with the sterling class than with
// the bMoney class. With sterling we use conversion operators, thus giving up
// the ability to catch illegal math operations but gaining simplicity in
// writing the overloaded math operators.
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;

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
//-----------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{



   sterling str1, str2;
   str1.getSterling();
   str1.putSterling();
   cout << endl;
   double dStr = (double)str1;
   str2.getSterling();
   str2.putSterling();
   cout << endl;
   sterling str3 = str1 + str2;
   cout << "str3 = ";
   str1.putSterling();
   cout << " + ";
   str2.putSterling();
   cout << " = ";
   str3.putSterling();
   cout << endl;
   sterling str4 = str1 - str2;
   cout << "str4 = ";
   str1.putSterling();
   cout << " - ";
   str2.putSterling();
   cout << " = ";
   str4.putSterling();
   cout << endl;
   sterling str5 = str1 / str2;
   cout << "str5 = ";
   str1.putSterling();
   cout << " / ";
   str2.putSterling();
   cout << " = ";
   str5.putSterling();
   cout << endl;
   double dVal = 2.0;
   sterling str6 = str1 * dVal;
   cout << "str6 = ";
   str1.putSterling();
   cout << " * " << dVal;
   cout << " = ";
   str6.putSterling();
   cout << endl;
   sterling str7 = str1 / dVal;
   cout << "str7 = ";
   str1.putSterling();
   cout << " / " << dVal;
   cout << " = ";
   str7.putSterling();
   cout << endl;
   return 0;
}
