// exercise_6_9.cpp
// Transform the fraction structure from Exercise 8 in Chapter 4 into a
// fraction class.
// Member data is the fraction's numerator and denominator. Member functions
// should accept input from the user in the form 3/5, and output the fraction's
// value in the same format. Another member function should add two fraction
// values. Write a main() program that allows the user to repeatedly input two
// fractions and then displays their sum. After each operation, ask whether the
// user wants to continue.
#include <iostream>
#include <Windows.h>
#include <conio.h>
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
   : n_Numerator(0), n_Denominator(1)
   {}
   ~fraction()
   {}
   fraction(const fraction& frc)
   {
      n_Numerator = frc.n_Numerator;
      n_Denominator = frc.n_Denominator;
   }
   void setNumerator(const int nNum);
   void setDenominator(const int nDenom);
   void setFraction();
   void getFraction();
   fraction addFraction(const fraction& frc);
};
//---------------------------------------------------------------------------------------
void fraction::setNumerator(const int nNum)
{
   this->n_Numerator = nNum;
}
//---------------------------------------------------------------------------------------
void fraction::setDenominator(const int nDenom)
{
   this->n_Denominator = nDenom;
}
//---------------------------------------------------------------------------------------
void fraction::setFraction()
{
   bool bResult = false;
   do
   {
      cout << "Please, specify the fraction: ";
      char cDummyChar;
      cin >> this->n_Numerator >> cDummyChar >> this->n_Denominator;
      if (this->n_Denominator == 0)
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
void fraction::getFraction()
{
   cout << n_Numerator << cDeletionSymbol << n_Denominator;
}
//---------------------------------------------------------------------------------------
fraction fraction::addFraction(const fraction& frc)
{
   fraction result;
   result.n_Numerator = (this->n_Numerator * frc.n_Denominator + frc.n_Numerator * this->n_Denominator);
   result.n_Denominator = this->n_Denominator * frc.n_Denominator;
   return result;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   fraction first, second;
   first.setFraction();
   second.setFraction();
   fraction result = first.addFraction(second);
   first.getFraction();
   cout << " + ";
   second.getFraction();
   cout << " = ";
   result.getFraction();
   cout << endl;
   return 0;
}