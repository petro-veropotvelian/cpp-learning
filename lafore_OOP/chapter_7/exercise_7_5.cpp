// exercise_7_5.cpp
// Start with the fraction class from Exercises 11 and 12 in Chapter 6. Write a
// main() program that obtains an arbitrary number of fractions from the user,
// stores them in an array of type fraction, averages them, and displays the
// result.
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include <vector>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
const char cDeletionSymbol = '/';
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
   void setNumerator(const int nNum);
   void setDenominator(const int nDen);
   int getNumerator() const;
   int getDenominator() const;
   void SetFraction();
   void GetFraction();
   fraction addFraction(const fraction& frc);
   fraction subtactFraction(const fraction& frc);
   fraction multiplyFraction(const fraction& frc);
   fraction divideFraction(const fraction& frc);
   void lowterms();
};

/////////////////////////////////////////////////////////////////////////////////////////
void fraction::setNumerator(const int nNum)
{
   n_Numerator = nNum;
}
//---------------------------------------------------------------------------------------
void fraction::setDenominator(const int nDen)
{
   n_Denominator = nDen;
}
//---------------------------------------------------------------------------------------
int fraction::getNumerator() const
{
   return n_Numerator;
}
//---------------------------------------------------------------------------------------
int fraction::getDenominator() const
{
   return n_Denominator;
}
//---------------------------------------------------------------------------------------
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
   n_Numerator = n_Numerator / gcd;                // divide both num and den by gcd
   n_Denominator = n_Denominator / gcd;            // to reduce frac to lowest terms
}
//---------------------------------------------------------------------------------------
//const int SIZE = 100;
int main(int argc, char* argv[])
{
   fraction fraArr[100];
   int n = 0;
   char cAnsw;
   cout << endl;
   fraction total;
   do
   {
      cout << "Enter fraction number " << n+1 << "\n";
      fraArr[n].SetFraction();
      if (0==n)
      {
         total = fraArr[n];
      }
      else
      {
         total  = total.addFraction(fraArr[n]);
      }
      n++;
      cout << "Enter another (y/n)?: ";
      cin >> cAnsw;
   } while (cAnsw != 'n' && cAnsw != 'N');
   for (int j=0; j<n; j++)       // display all distances
   {
      cout << "\nFraction number " << j + 1 << " is ";
      fraArr[j].GetFraction();
   }
   cout << endl;
   cout << "Total = ";
   total.lowterms();
   total.GetFraction();
   cout << endl;
   fraction divider, medium;
   divider.setNumerator(n);
   divider.setDenominator(1);
   medium = total.divideFraction(divider);
   medium.lowterms();
   cout << "Medium fraction: ";
   medium.GetFraction();
   cout << endl;
   return 0;
}