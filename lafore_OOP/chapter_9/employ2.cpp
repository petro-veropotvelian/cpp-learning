// employ2.cpp
// multiple levels of inheritance
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
class foreman: public laborer                                        // foreman class
{
private:
   float quotas;                                                     // percent of quotas met successfully
public:
   void getdata()
   {
      laborer::getdata();
      cout << "   Enter quotas: ";
      cin >> quotas;
   }
   void putdata() const
   {
      laborer::putdata();
      cout << "\n   Quotas: " << quotas;
   }
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{

   laborer l1;
   foreman f1;

   cout << endl;                                                     // get data for several employees
   cout << "\nEnter data for laborer 1";
   l1.getdata();
   cout << "\nEnter data for foreman 1";
   f1.getdata();

                                                                     // display data for several employees
   cout << endl;
   cout << "\nData on laborer 1";
   l1.putdata();
   cout << "\nData on foreman 1";
   f1.putdata();
   cout << endl;
   return 0;
}