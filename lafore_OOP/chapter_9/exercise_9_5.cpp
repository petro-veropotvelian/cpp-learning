// exercise_9_5.cpp
// Derive a class called employee2 from the employee class in the EMPLOY
// program in this chapter. This new class should add a type double data item
// called compensation, and also an enum type called period to indicate whether
// the employee is paid hourly, weekly, or monthly. For simplicity you can
// change the manager, scientist, and laborer classes so they are derived from
// employee2 instead of employee. However, note that in many circumstances it
// might be more in the spirit of OOP to create a separate base class called
// compensation and three new classes manager2, scientist2, and laborer2, and
// use multiple inheritance to derive these three classes from the original
// manager, scientist, and laborer classes and from compensation. This way none
// of the original classes needs to be modified.
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
class manager : private employee                                      // managament class
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
class scientist: private employee                                     // scientist class
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
class laborer : private employee                                      // laborer class
{
public:
   void getdata()
   {
      employee::getdata();
   }
   void putdata() const
   {
      employee::putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
class salary
{
private:
   enum comptype {HOURLY, WEEKLY, MONTHLY};
   comptype period;
   double compensation;
public:
   void getdata()
   {
      cout <<"   Enter employee's compensation, $: ";
      cin >> compensation;
      cout << "   Specify compensation period (Hourly, Weekly, Monthly): ";
      char cPeriod;
      cin >> cPeriod;
      switch (cPeriod)
      {
         case 'h':
         case 'H':
            period = comptype::HOURLY;
            break;
         case 'w':
         case 'W':
            period = comptype::WEEKLY;
            break;
         case 'm':
         case 'M':
            period = comptype::MONTHLY;
            break;
      }
   }
   
   void putdata() const
   {
      cout << "\n   Compensation, $ " << compensation;
      cout << "\n   Salary period: ";
      switch (period)
      {
         case comptype::HOURLY:
            cout << "hourly";
         break;
         case comptype::WEEKLY:
            cout << "weekly";
         break;
         case comptype::MONTHLY:
            cout << "monthly";
         break;
      }
   }
};
///////////////////////////////////////////////////////////////////////////////
class manager2 : private manager, private salary
{
public:
   void getdata()
   {
      manager::getdata();
      salary::getdata();
   }
   void putdata() const
   {
      manager::putdata();
      salary::putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
class scientist2 : private scientist, private salary
{
public:
   void getdata()
   {
      scientist::getdata();
      salary::getdata();
   }
   void putdata() const
   {
      scientist::putdata();
      salary::putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
class laborer2 : private laborer, private salary
{
public:
   void getdata()
   {
      laborer::getdata();
      salary::getdata();
   }
   void putdata() const
   {
      laborer::putdata();
      salary::putdata();
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   manager2 m1;
   scientist2 s1;
   laborer2 l1;

   cout << endl;                                                     // get data for several employees
   cout << "\nEnter data for manager 1";
   m1.getdata();

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

                                                                     // display data for several employees
   cout << "\nData on manager 1";
   m1.putdata();

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   cout << endl;
   return 0;
}