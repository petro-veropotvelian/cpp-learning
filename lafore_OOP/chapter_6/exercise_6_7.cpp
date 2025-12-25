// exercise_6_7.cpp
// In ocean navigation, locations are measured in degrees and minutes of
// latitude and longitude.
// Thus if you're lying off the mouth of Papeete Harbor in Tahiti, your
// location is 149 degrees 34.8 minutes west longitude, and 17 degrees
// 31.5 minutes south latitude. This is written as 149°34.8' W, 17°31.5' S.
// There are 60 minutes in a degree. (An older system also divided a minute
// into 60 seconds, but the modern approach is to use decimal minutes instead.)
// Longitude is measured from 0 to 180 degrees, east or west from Greenwich,
// England, to the international dateline in the Pacific. Latitude is measured
// from 0 to 90 degrees, north or south from the equator to the poles.
// Create a class angle that includes three member variables: an int for
// degrees, a float for minutes, and a char for the direction letter (N, S, E,
// or W). This class can hold either a latitude variable or a longitude
// variable. Write one member function to obtain an angle value (in degrees and
// minutes) and a direction from the user, and a second to display the angle
// value in 179°59.9' E format. Also write a three-argument constructor. Write
// a main() program that displays an angle initialized with the constructor,
// and then, within a loop, allows the user to input any angle value, and then
// displays the value. You can use the hex character constant '\xF8', which
// usually prints a degree (°) symbol.
#include <iostream>
#include <Windows.h>
using namespace std;
#define NORTH 'N'
#define SOUTH 'S'
#define EAST  'E'
#define WEST  'W'
/////////////////////////////////////////////////////////////////////////////////////////
class angle
{
private:
   int   m_nDegrees;
   float m_fMinutes;
   char  m_cDirection;
public:
   angle() : m_nDegrees(0), m_fMinutes(0.0), m_cDirection('\0')
   {}

   angle(const int nDeg, const float fMin, const char cDir)
   : m_nDegrees(nDeg), m_fMinutes(fMin), m_cDirection(cDir)
   {}

   void show_angle() const;

   void set_angle();
};

void angle::show_angle() const
{
   cout << m_nDegrees << '\xF8' << m_fMinutes << "'"<< m_cDirection;
}

void angle::set_angle()
{
   bool bCorrect;
   do
   {
      bCorrect = true;
      cout << "Specify the direction (W for WEST, S for SOUTH, E for EAST or N for NORTH: ";
      cin >> m_cDirection;
      cin.get();
      if (m_cDirection == 'w' || m_cDirection == WEST)
      {
         m_cDirection = WEST;
      }
      else if (m_cDirection == 'e' || m_cDirection == EAST)
      {
         m_cDirection = EAST;
      }
      else if (m_cDirection == 's' || m_cDirection == SOUTH)
      {
         m_cDirection = SOUTH;
      }
      else if (m_cDirection == 'n' || m_cDirection == NORTH)
      {
         m_cDirection = NORTH;
      }
      else
      {
         cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
         bCorrect = false;
         cin.get();
         system("CLS");
      }
   } while (!bCorrect);
   if (m_cDirection == WEST || m_cDirection == EAST) // logitude
   {
      do
      {
          bCorrect = true;
         cout << "Specify degrees of longitude [0..180): ";
         cin >> m_nDegrees;
         cin.get();
         if (m_nDegrees <0 || m_nDegrees >=180)
         {
            cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
            bCorrect = false;
            cin.get();
            system("CLS");
         }
      } while(!bCorrect);
   }
   else if (m_cDirection == SOUTH || m_cDirection == NORTH) // latitude
   {
      do
      {
         bCorrect = true;
         cout << "Specify degrees of latitude [0..90): ";
         cin >> m_nDegrees;
         cin.get();
         if (m_nDegrees <0 || m_nDegrees >=90)
         {
            cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
            bCorrect = false;
            cin.get();
            system("CLS");
         }
      } while(!bCorrect);
   }
   do
   {
      bCorrect = true;
      cout << "Specify minutes [0..60): ";
      cin >> m_fMinutes;
      cin.get();
      if (m_fMinutes <0 || m_fMinutes >=60)
      {
         cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
         bCorrect = false;
         cin.get();
         system("CLS");
      }
   } while(!bCorrect);
}

int main(int argc, char* argv[])
{
   angle ang(145, 45.3, WEST);
   cout << "Current angle: ";
   ang.show_angle();
   cout << endl;
   bool bAgree = true;
   do
   {
      cout << "Do you want to set another angle (y/n)? ";
      char cResp;
      cin >> cResp;
      if (cResp=='Y' || cResp=='y')
      {
         bAgree = true;
         ang.set_angle();
         cout << "Current angle: ";
         ang.show_angle();
         cout << endl;
         cout << "Please, press <ENTER> to continue...";
         cin.get();
         system("CLS");
      }
      else if (cResp=='N' || cResp=='n')
      {
         bAgree = false;
      }
      else
      {
         cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
         bAgree = true;
         cin.get();
         system("CLS");
      }
   } while (bAgree);
   cout << "Bye!\n";
   return 0;
}