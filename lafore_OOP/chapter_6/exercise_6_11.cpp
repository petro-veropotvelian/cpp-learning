// exercise_6_11.cpp
// Modify the four-function fraction calculator of Exercise 12 in Chapter 5
// to use a fraction class rather than a structure. There should be member
// functions for input and output, as well as for the four arithmetical
// operations. While you're at it, you might as well install the capability to
// reduce fractions to lowest terms. Here's a member function that will reduce
// the fraction object of which it is a member to lowest terms. It finds the
// greatest common divisor (gcd) of the fraction's numerator and denominator,
// and uses this gcd to divide both numbers.
//    void fraction::lowterms() // change ourself to lowest terms
//    {
//       long tnum, tden, temp, gcd;
//       tnum = labs(num); // use non-negative copies
//       tden = labs(den); // (needs cmath)
//       if (tden==0 ) // check for n/0
//       { cout << “Illegal fraction: division by 0”; exit(1); }
//       else if ( tnum==0 ) // check for 0/n
//       { num=0; den = 1; return; }
//       // this 'while' loop finds the gcd of tnum and tden
//       while(tnum != 0)
//       {
//          if(tnum < tden) // ensure numerator larger
//          { temp=tnum; tnum=tden; tden=temp; } // swap them
//          tnum = tnum - tden; // subtract them
//       }
//       gcd = tden; // this is greatest common divisor
//       num = num / gcd; // divide both num and den by gcd
//       den = den / gcd; // to reduce frac to lowest terms
//    }
// You can call this function at the end of each arithmetic function, or just
// before you perform output. You'll also need the usual member functions:
// four arithmetic operations, input, and display. You may find a two-argument
// constructor useful.
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
const char cDeletionSymbol = '/';
const char cPlusSymbol     = '+';
const char cMinusSymbol    = '-';
const char cMultiplySymbol = '*';
const char cEqualSymbol    = '=';
/////////////////////////////////////////////////////////////////////////////////////////
class fraction
{
private:
   int n_Numerator;
   int n_Denominator;
public:
   fraction()
   : n_Numerator(0), n_Denominator(0)
   {}
   fraction(int nNum, int nDen)
   : n_Numerator(nNum), n_Denominator(nDen)
   {}
   fraction(const fraction& frc)
   {
      n_Numerator = frc.n_Numerator;
      n_Denominator = frc.n_Denominator;
   }
   void SetFraction();
   void GetFraction();
   fraction addFraction(const fraction& frc);
   fraction subtactFraction(const fraction& frc);
   fraction multiplyFraction(const fraction& frc);
   fraction divideFraction(const fraction& frc);
   void lowterms();
};

/////////////////////////////////////////////////////////////////////////////////////////
void fraction::SetFraction()
{
   bool bResult = false;
   do
   {
      cout << "Please, specify the fraction: ";
      char cDummyChar;
      cin >> n_Numerator >> cDummyChar >> n_Denominator;
      if (n_Denominator == 0)
      {
         system("CLS");
         cout << "Error! You cannot divide by zero!\n";
      }
      else
      {
         bResult = true;
      }
   } while (!bResult);
}
//---------------------------------------------------------------------------------------
void fraction::GetFraction()
{
   cout << n_Numerator << cDeletionSymbol << n_Denominator;
}
//---------------------------------------------------------------------------------------
fraction fraction::addFraction(const fraction& frc)
{
   fraction result;
   result.n_Numerator   = (this->n_Numerator * frc.n_Denominator + frc.n_Numerator * this->n_Denominator);
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::subtactFraction(const fraction& frc)
{
   fraction result;
   result.n_Numerator   = (this->n_Numerator * frc.n_Denominator - frc.n_Numerator * this->n_Denominator);
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::multiplyFraction(const fraction& frc)
{
   fraction result;
   result.n_Numerator   = this->n_Numerator * frc.n_Numerator;
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   return result;
}
//---------------------------------------------------------------------------------------
fraction fraction::divideFraction(const fraction& frc)
{
   fraction result;
   result.n_Numerator   = this->n_Numerator * frc.n_Denominator;
   result.n_Denominator = this->n_Denominator * frc.n_Numerator;
   return result;
}
//---------------------------------------------------------------------------------------
void fraction::lowterms()                          // change ourself to lowest terms
{
   long tnum, tden, temp, gcd;
   tnum = labs(n_Numerator);                               // use non-negative copies
   tden = labs(n_Denominator);                               // (needs cmath)
   if (tden == 0)                                  // check for n/0
   {
      cout << "Illegal fraction: division by 0";
      exit(1);
   }
   else if (tnum == 0)                               // check for 0/n
   {
      n_Numerator = 0;
      n_Denominator = 1;
      return;
   }
   // this whil loop find the gcd  of thum and tden
   while (tnum!=0)
   {
      if (tnum < tden)                             // ensure numerator larger
      {
         temp = tnum;                              // swap them
         tnum = tden;
         tden = temp;
      }
      tnum = tnum - tden;                          // substract them
   }
   gcd = tden;                                     // this is greatest common divisor
   n_Numerator = n_Numerator / gcd;                                // divide both num and den by gcd
   n_Denominator = n_Denominator / gcd;                                // to reduce frac to lowest terms
}
//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   char cOperation;
   char cResponse = 'y';
   bool bFirst = true;
   do
   {
      system("CLS");
      if (!bFirst)
      {
         cout << endl;
      }
      fraction fr1, fr2, result;
      fr1.SetFraction();
      cout << "Specify the operation (+, -, * or /): ";
      cin >> cOperation;
      fr2.SetFraction();
      bool bValidOperation = true;
      switch(cOperation)
      {
         case(cPlusSymbol):
            result =  fr1.addFraction(fr2);
            break;
         case (cMinusSymbol):
            result = fr1.subtactFraction(fr2);
            break;
         case (cMultiplySymbol):
            result = fr1.multiplyFraction(fr2);
            break;
         case (cDeletionSymbol):
            result = fr1.divideFraction(fr2);
            break;
         default: 
            cout << "Error! Unknown operation. Press <ENTER> to continue..." << endl;
            bValidOperation = false;
            cin.get();
            system("CLS");
         break;
      }
      if (bValidOperation)
      {
         //ShowResult(fr1, fr2, result, cOperation);
         fr1.GetFraction();
         cout <<" " << cOperation << " ";
         fr2.GetFraction();
         cout << " " << cEqualSymbol << " ";
         result.lowterms();
         result.GetFraction();
         cout << endl;
      }
      cout << "Do another (y/n)? ";
      //cin >> cResponse;
      bFirst = false;
   } while ((cResponse=getche())!= 'n');
   return 0;
}
