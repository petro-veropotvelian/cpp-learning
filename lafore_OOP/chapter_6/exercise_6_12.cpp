// exercise_6_12.cpp
// Note that one advantage of the OOP approach is that an entire class can be
// used, without modification, in a different program. Use the fraction class
// from Exercise 11 in a program that generates a multiplication table for
// fractions. Let the user input a denominator, and then generate all
// combinations of two such fractions that are between 0 and 1, and multiply
// them together. Here's an example of the output if the denominator is 6:
//       1/6      1/3      1/2     2/3      5/6
// -----------------------------------------------
// 1/6   1/36     1/18     1/12    1/9      5/36
// 1/3   1/18     1/9      1/6     2/9      5/18
// 1/2   1/12     1/6      1/4     1/3      5/12
// 2/3   1/9      2/9      1/3     4/9      5/9
// 5/6   5/36     5/18     5/12    5/9     25/36
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
int main(int argc, char* argv[])
{
   int nDen;
   bool bCorrect;
   do
   {
      bCorrect = true;
      cout << "Specify denominator of the fracton (from 2 to 9): ";
      cin >> nDen;
      cin.get();
      if (nDen <2 || nDen > 9)
      {
         cout << "You have entered incorrect value. It should be between 2 and 9. Please, press <ENTER> to continue...";
         bCorrect = false;
         cin.get();
         system("CLS");
      }
   } while(!bCorrect);
   vector<fraction> vFractions;
   for (int i=1; i<nDen; i++)
   {
      fraction tmpFr(i, nDen);
      tmpFr.lowterms();
      vFractions.push_back(tmpFr);
   }
   for (unsigned i = 0; i < vFractions.size(); i++)
   {
      if (i==0)
      {
         for (vector<fraction>::iterator it = vFractions.begin(); it!=vFractions.end(); ++it)
         {
            cout << "\t";
            it->GetFraction();
         }
         cout << endl;
         cout << "--------";
         for (vector<fraction>::iterator it = vFractions.begin(); it!=vFractions.end(); ++it)
         {
            cout << "---------";
         }
         cout << endl;
      }
      vFractions.at(i).GetFraction();
      for (unsigned j = 0; j < vFractions.size(); j++)
      {
         fraction nFract = vFractions.at(i).multiplyFraction(vFractions.at(j));
         nFract.lowterms();
         cout << "\t";
         nFract.GetFraction();
      }
      cout << endl;
   }
   cout << "The end." <<endl;
   return 0;
}