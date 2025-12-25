// exercise_9_10.cpp
// There is only one kind of manager in the EMPMULT program in this chapter.
// Any serious company has executives as well as managers. From the manager
// class derive a class called executive. (We’ll assume an executive is a
// high-end kind of manager.) The additional data in the executive class will
// be the size of the employee’s yearly bonus and the number of shares of
// company stock held in his or her stock-option plan. Add the appropriate
// member functions so these data items can be input and displayed along with
// the other manager data.
#include <iostream>
#include <iomanip>
using namespace std;
const int LEN=80;                                                    // maximum length of namespace
///////////////////////////////////////////////////////////////////////////////
class student
{
private:
   char school[LEN];                                                 // name of school or university
   char degree[LEN];                                                 // highest degree earned
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
class manager : private employee, private student                    // managament class
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
      cout << "   Enter golf club dues: ";
      cin >> dues;
      student::getedu();
   }
   void putdata() const
   {
      employee::putdata();
      cout << "\n   Title: " << title;
      cout.setf(ios::fixed, ios::floatfield);
      cout << "\n   Golf club dues: " << std::setprecision(0) <<dues;
      student::putedu();
   }
};
///////////////////////////////////////////////////////////////////////////////
class scientist: private employee, private student                   // scientist class
{
private:
   int pubs;                                                         // number of pulications
public:
   void getdata()
   {
      employee::getdata();
      cout << "   Enter number of publications: ";
      cin >> pubs;
      student::getedu();
   }
   void putdata() const
   {
      employee::putdata();
      cout << "\n   Number of publications: " << pubs;
      student::putedu();
   }
};
///////////////////////////////////////////////////////////////////////////////
class laborer : public employee                                      // laborer class
{
};
///////////////////////////////////////////////////////////////////////////////
class executive : private manager
{
private:
   double dYearlyBonus;
   int nNumberOfShares;
public:
   void getdata()
   {
      manager::getdata();

      cout << "   Enter the size of the employee's yearly bonus: $";
      cin >> dYearlyBonus;

      cout << "   Enter the number of shares of company stock: ";
      cin >> nNumberOfShares;
   }
   void putdata() const
   {
      manager::putdata();
      cout << "\n   Size of the employee's yearly bonus: $" << dYearlyBonus;
      cout << "\n   The number of company stock held in employee's stock-option plan: " << nNumberOfShares << endl;
   }

};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   manager m1;
   scientist s1;
   laborer l1;
   executive e1;

   cout << endl;                                                     // get data for several employees
   cout << "\nEnter data for manager 1";
   m1.getdata();

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

   cout << "\nEnter data for executive 1";
   e1.getdata();

                                                                     // display data for several employees
   cout << "\nData on manager 1";
   m1.putdata();

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();

   cout << "\nData on executive 1";
   e1.putdata();

   cout << endl;
   return 0;
}