// exercise_6_1.cpp
// Create a class that imitates part of the functionality of the basic data
// type int. Call the class Int (note different capitalization). The only data
// in this class is an int variable.
// Include member functions to initialize an Int to 0, to initialize it to an
// int value, to display it (it looks just like an int), and to add two Int
// values.
// Write a program that exercises this class by creating one uninitialized and
// two initialized Int values, adding the two initialized values and placing
// the response in the uninitialized value, and then displaying this result.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Int
{
private:
   int data;
public:
   Int(): data(0)
   {}
   void set_data(const int val);
   void clear_data(void);
   void show_data() const;
   int get_data() const;
   Int add(const Int &obj1);
};
//---------------------------------------------------------------------------------------
void Int::set_data(const int val)
{
   data = val;
}

void Int::clear_data(void)
{
   data = 0;
}

void Int::show_data() const
{
   cout << data;
}

int Int::get_data() const
{
   return data;
}

Int Int::add(const Int &obj1)
{
   Int tmp;
   tmp.set_data(data + obj1.get_data());
   return tmp;
}

int main(int argc, char* argv[])
{
   Int a, b, c;
   a.set_data(5);
   b.set_data(15);
   c = a.add(b);
   cout << "Here are the values:\n";
   cout << "a = ";
   a.show_data();
   cout << "\nb = ";
   b.show_data();
   cout << "\nc = ";
   c.show_data();
   cout << endl;
   return 0;
}