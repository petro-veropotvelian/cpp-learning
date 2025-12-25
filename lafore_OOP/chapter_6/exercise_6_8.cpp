// exercise_6_8.cpp
// Create a class that includes a data member that holds a "serial number" for
// each object created from the class. That is, the first object created will
// be numbered 1, the second 2, and so on.
// To do this, you'll need another data member that records a count of how many
// objects have been created so far. (This member should apply to the class as
// a whole; not to individual objects. What keyword specifies this?) Then, as
// each object is created, its constructor can examine this count member
// variable to determine the appropriate serial number for the new object.
// Add a member function that permits an object to report its own serial
// number. Then write a main() program that creates three objects and queries
// each one about its serial number. They should respond I am object number 2,
// and so on.
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class MyObject
{
private:
   int nData;
   int nSerialNumber;
   static int nCounter;
public:

   MyObject():nData(0)
   {
      ++nCounter;
      nSerialNumber = nCounter;
   }
   ~MyObject()
   {
      --nCounter;
   }
   void SetData(const int nDt);
   void Show() const;
};
//---------------------------------------------------------------------------------------
int MyObject::nCounter = 0;
//---------------------------------------------------------------------------------------
void MyObject::SetData(const int nDt)
{
   nData = nDt;
}
//---------------------------------------------------------------------------------------
void MyObject::Show() const
{
   cout << "Serial number: " << nSerialNumber << endl;
   cout << "Data: " << nData << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   MyObject mOb1, mOb2, mOb3;
   mOb1.SetData(100);
   mOb2.SetData(200);
   mOb3.SetData(300);
   mOb1.Show();
   mOb2.Show();
   mOb3.Show();
   return 0;
}