// employ.cpp
// models employee database using inheritance
#include <iostream>
#include <iomanip>
using namespace std;
const int LEN=80;                                                    // maximum length of namespace
///////////////////////////////////////////////////////////////////////////////
class employee                                                       // employee class
{
private:
   char name[LEN];                                                   // employee name
   unsigned long number;                                             // employee number
public:
   void getdata()
   {
      cout << "\n   Enter last name: ";
      cin >> name;
      cout << "   Enter number: ";
      cin >> number;
   }
   void putdata() const
   {
      cout << "\n   Name: " << name;
      cout << "\n   Number: " << number;
   }
};
///////////////////////////////////////////////////////////////////////////////
class manager : public employee                                      // managament class
{
private:
   char title[LEN];                                                  // "vice-president" etc.
   double dues;                                                      // golf club dues
public:
   void getdata()
   {
      employee::getdata();
      cout << "   Enter title: ";
      cin >> title;
      cout << " Enter golf club dues: ";
      cin >> dues;
   }
   void putdata() const
   {
      employee::putdata();
      cout << "\n   Title: " << title;
      cout.setf(ios::fixed, ios::floatfield);
      //std::setprecision(0);
      cout << "\n   Golf club dues: " << std::setprecision(0) <<dues;
   }
};
///////////////////////////////////////////////////////////////////////////////
class scientist: public employee                                     // scientist class
{
private:
   int pubs;                                                         // number of pulications
public:
   void getdata()
   {
      employee::getdata();
      cout << "   Enter number of publications: ";
      cin >> pubs;
   }
   void putdata() const
   {
      employee::putdata();
      cout << "\n   Number of publications: " << pubs;
   }
};
///////////////////////////////////////////////////////////////////////////////
class laborer : public employee                                      // laborer class
{
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   manager m1, m2;
   scientist s1;
   laborer l1;

   cout << endl;                                                     // get data for several employees
   cout << "\nEnter data for manager 1";
   m1.getdata();

   cout << "\nEnter data for manager 2";
   m2.getdata();

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

                                                                     // display data for several employees
   cout << "\nData on manager 1";
   m1.putdata();

   cout << "\nData on manager 2";
   m2.putdata();

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   cout << endl;
   return 0;
}