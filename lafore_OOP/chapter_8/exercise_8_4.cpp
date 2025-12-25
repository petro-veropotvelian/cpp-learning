// exercise_8_4.cpp
// Create a class Int based on Exercise 1 in Chapter 6. Overload four integer
// arithmetic operators (+, -, *, and /) so that they operate on objects of
// type Int. If the result of any such arithmetic operation exceeds the normal
// range of ints (in a 32-bit environment)— from 2,147,483,648 to
// –2,147,483,647—have the operator print a warning and terminate the program.
// Such a data type might be useful where mistakes caused by arithmetic overflow
// are unacceptable. Hint: To facilitate checking for overflow, perform the
// calculations using type long double. Write a program to test this class.
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Int
{
private:
   int data;
public:
   Int(): data(0)
   {}
   Int(int val) : data(val)
   {}
   void set_data(const int val);
   void clear_data(void);
   void show_data() const;
   int get_data() const;
   Int operator+(Int) const;
   Int operator-(Int) const;
   Int operator*(Int) const;
   Int operator/(Int) const;
};
//---------------------------------------------------------------------------------------
void Int::set_data(const int val)
{
   data = val;
}
//---------------------------------------------------------------------------------------
void Int::clear_data(void)
{
   data = 0;
}
//---------------------------------------------------------------------------------------
void Int::show_data() const
{
   cout << data;
}
//---------------------------------------------------------------------------------------
int Int::get_data() const
{
   return data;
}
//---------------------------------------------------------------------------------------
Int Int::operator+(Int obj) const 
{
   long double sum = (double)data + (double)obj.data;
   //cout << "DEBUG: sum = " << sum << endl;
   if (sum > INT_MAX || sum < INT_MIN)
   {
      cout << "\nError! The results exceeds mormal range of ints.";
      exit(1);
   }
   return Int((int)sum);
}
//---------------------------------------------------------------------------------------
Int Int::operator-(Int obj) const
{
   long double diff = (double)data - (double)obj.data;
   if (diff < INT_MIN)
   {
      cout << "\nError! The results exceeds mormal range of ints.";
      exit(1);
   }
   return Int((int)diff);
}
//---------------------------------------------------------------------------------------
Int Int::operator*(Int obj) const
{
   long double mult = (double)data * (double)obj.data;
   if (mult > INT_MAX || mult < INT_MIN)
   {
      cout << "\nError! The results exceeds mormal range of ints.";
      exit(1);
   }
   return Int((int)mult);
}
//---------------------------------------------------------------------------------------
Int Int::operator/(Int obj) const
{
   long double div = (double)data / (double)obj.data;
   if (div > INT_MAX || div < INT_MIN)
   {
      cout << "\nError! The results exceeds mormal range of ints.";
      exit(1);
   }
   return Int((int)div);
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Int a, b, c;
   a.set_data(5);
   b.set_data(45);
   c = a + b;
   cout << "Here are the values:\n";
   cout << "a = ";
   a.show_data();
   cout << "\nb = ";
   b.show_data();
   cout << "\nc = a + b = ";
   a.show_data();
   cout << " + ";
   b.show_data();
   cout << " = ";
   c.show_data();
   cout << endl;
   c = a - b;
   cout << "\nc = a - b = ";
   a.show_data();
   cout << " - ";
   b.show_data();
   cout << " = ";
   c.show_data();
   cout << endl;
   c = a * b;
   cout << "\nc = a * b = ";
   a.show_data();
   cout << " * ";
   b.show_data();
   cout << " = ";
   c.show_data();
   cout << endl;
   c = b / a;
   cout << "\nc = b / a = ";
   b.show_data();
   cout << " / ";
   a.show_data();
   cout << " = ";
   c.show_data();
   cout << endl;
   return 0;
}