// exercise_4_8.cpp
// Start with the fraction-adding program of Exercise 9 in Chapter 2,
// "C++ Programming Basics." This program stores the numerator and denominator
// of two fractions before adding them, and may also store the answer, which is
// also a fraction. Modify the program so that all fractions are stored in
// variables of type struct fraction, whose two members are the fraction's
// numerator and denominator (both type int). All fractionrelated data should
// be stored in structures of this type.
#include <iostream>
using namespace std;
const char cDeletionSymbol = '/';
////////////////////////////////////////////////////////////////////////////////////////////////////
struct fraction
{
   int numerator;
   int denominator;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
void SetFraction(fraction &fr, const char* szText);
void GetFraction(const fraction &fr);
////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   fraction a, b, res;
   SetFraction(a, "first");
   SetFraction(b, "second");
   res.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
   res.denominator = a.denominator * b.denominator;
   GetFraction(a);
   cout << " + ";
   GetFraction(b);
   cout   << " = ";
   GetFraction(res);
   return 0;
}

void SetFraction(fraction &fr, const char* szText)
{
   cout << "Please, specify the " << szText << " fraction: ";
   char cDummyChar;
   cin >> fr.numerator >> cDummyChar >> fr.denominator;
}

void GetFraction(const fraction &fr)
{
   cout << fr.numerator << cDeletionSymbol << fr.denominator;
}
