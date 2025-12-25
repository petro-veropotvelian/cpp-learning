// exercise_6_10.cpp
// Create a class called ship that incorporates a ship's number and location.
// Use the approach of Exercise 8 to number each ship object as it is created.
// Use two variables of the angle class from Exercise 7 to represent the ship's
// latitude and longitude. A member function of the ship class should get a
// position from the user and store it in the object; another should report the
// serial number and position. Write a main() program that creates three ships,
// asks the user to input the position of each, and then displays each ship's
// number and position.
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
   void set_latitude();
   void set_longitude();
};

/////////////////////////////////////////////////////////////////////////////////////////
class ship
{
private:
   angle m_Latitude;
   angle m_Longitude;
   int nSerialNumber;
   static int nCounter;
public:
   ship()
   {
      nCounter++;
      nSerialNumber = nCounter;
   }
   ~ship()
   {
      --nCounter;
   }
   void setShipData();
   void getShipData();
};
//---------------------------------------------------------------------------------------
int ship::nCounter = 0;
//---------------------------------------------------------------------------------------
void angle::show_angle() const
{
   cout << m_nDegrees << '\xF8' << m_fMinutes << "'"<< m_cDirection;
}
//---------------------------------------------------------------------------------------
void angle::set_latitude()
{
   bool bCorrect;
   do
   {
      bCorrect = true;
      cout << "Specify the direction (S for SOUTH or N for NORTH): ";
      cin >> m_cDirection;
      cin.get();
      if (m_cDirection == 's' || m_cDirection == SOUTH)
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
//---------------------------------------------------------------------------------------
void angle::set_longitude()
{
   bool bCorrect;
   do
   {
      bCorrect = true;
      cout << "Specify the direction (W for WEST or E for EAST): ";
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
      else
      {
         cout << "You have entered incorrect value. Please, press <ENTER> to continue...";
         bCorrect = false;
         cin.get();
         system("CLS");
      }
   } while (!bCorrect);

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
//---------------------------------------------------------------------------------------
void ship::setShipData()
{
   cout << "Specify latitude." << endl;
   m_Latitude.set_latitude();
   cout << "Specify longitude." << endl;
   m_Longitude.set_longitude();
}
//---------------------------------------------------------------------------------------
void ship::getShipData()
{
   cout << "Ship number: " << nSerialNumber;
   cout << "\nLatitude: ";
   m_Latitude.show_angle();
   cout << "\nLongitude: ";
   m_Longitude.show_angle();
   cout << endl;
}
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
   ship boat1, boat2, boat3;
   cout << "Specify information about the first ship.\n";
   boat1.setShipData();
   cout << "Specify information about the second ship.\n";
   boat2.setShipData();
   cout << "Specify information about the third ship.\n";
   boat3.setShipData();
   cout << "\nAnd now let's obtain information about the ships\n";
   boat1.getShipData();
   boat2.getShipData();
   boat3.getShipData();
   return 0;
}