// empcont.cpp
// containership with employees and degrees
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class student
{
private:
   string school;                                                 // name of school or university
   string degree;                                                 // highest degree earned
public:
   void getedu()
   {
      cout << "   Enter name of school or university: ";
      cin >> school;
      cout << "   Enter highest degree earned\n";
      cout << "   (Highschool, Bachelor's, Master's, PhD): ";
      cin >> degree;
   }
   void putedu() const
   {
      cout << "\n   School or university: " << school;
      cout << "\n   Highest degree earned: " << degree;
   }
};
///////////////////////////////////////////////////////////////////////////////
class employee                                                       // employee class
{
private:
   string name;                                                      // employee name
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
class manager                                                        // managament class
{
private:
   string title;                                                     // "vice-president" etc.
   double dues;                                                      // golf club dues
   employee emp;                                                     // object of class employee
   student stu;                                                      // object of class student
public:
   void getdata()
   {
      emp.getdata();
      cout << "   Enter title: ";
      cin >> title;
      cout << " Enter golf club dues: ";
      cin >> dues;
      stu.getedu();
   }
   void putdata() const
   {
      emp.putdata();
      cout << "\n   Title: " << title;
      cout.setf(ios::fixed, ios::floatfield);
      cout << "\n   Golf club dues: " << std::setprecision(0) <<dues;
      stu.putedu();
   }
};
///////////////////////////////////////////////////////////////////////////////
class scientist                                                      // scientist class
{
private:
   int pubs;                                                         // number of pulications
   employee emp;                                                     // object of class employee
   student stu;                                                      // object of class student
public:
   void getdata()
   {
      emp.getdata();
      cout << "   Enter number of publications: ";
      cin >> pubs;
      stu.getedu();
   }
   void putdata() const
   {
      emp.putdata();
      cout << "\n   Number of publications: " << pubs;
      stu.putedu();
   }
};
///////////////////////////////////////////////////////////////////////////////
class laborer                                                        // laborer class
{
private:
   employee emp;                                                     // object of class employee
public:
   void getdata()
   {
      emp.getdata();
   }
   void putdata() const
   {
      emp.putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   manager m1;
   scientist s1, s2;
   laborer l1;

   cout << endl;                                                     // get data for several employees
   cout << "\nEnter data for manager 1";
   m1.getdata();

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for scientist 2";
   s2.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

                                                                     // display data for several employees
   cout << "\nData on manager 1";
   m1.putdata();

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on scientist 2";
   s2.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   cout << endl;
   return 0;
}