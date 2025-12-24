// exercise_5_4.cpp
// Write a function that takes two Distance values as arguments and returns the
// larger one.
// Include a main() program that accepts two Distance values from the user,
// compares them, and displays the larger. (See the RETSTRC program for hints.)
#include <iostream>
using namespace std;

const int nInchesInFoot = 12;
/////////////////////////////////////////////////////////////////////////////////////////
struct Distance
{
   int feet;
   float inches;
};
/////////////////////////////////////////////////////////////////////////////////////////
void SetDistance(Distance& dst);

Distance GetMax(const Distance &frst, const Distance &scnd);

void EnglDisp(const Distance &dst);
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   Distance First, Second, Maximum;
   cout << "Please, specify the first distance.\n";
   SetDistance(First);
   cout << "Plese, specify the second distance.\n";
   SetDistance(Second);
   Maximum = GetMax(First, Second);
   cout << "The larger distance is " ;
   EnglDisp(Maximum);
   cout << endl;
   return 0;
}

//---------------------------------------------------------------------------------------
void SetDistance(Distance& dst)
{
   cout << "Enter feet: ";
   cin >> dst.feet;
   cout << "Enter inches: ";
   cin >> dst.inches;
}
//---------------------------------------------------------------------------------------
Distance GetMax(const Distance &frst, const Distance &scnd)
{
   Distance ret;
   if ((frst.feet * nInchesInFoot + frst.inches) >= 
       (scnd.feet * nInchesInFoot + scnd.inches))
   {
      ret.feet = frst.feet;
      ret.inches = frst.inches;
   }
   else
   {
      ret.feet = scnd.feet;
      ret.inches = scnd.inches;
   }
   return ret;
}
//---------------------------------------------------------------------------------------
void EnglDisp(const Distance &dst)
{
   cout << dst.feet << "\'-" << dst.inches << "\"";
}