// exercise_8_10.cpp
// For math buffs only: Create a class Polar that represents the points on the
// plain as polar coordinates (radius and angle). Create an overloaded
// +operator for addition of two Polar quantities. "Adding" two points on the
// plain can be accomplished by adding their X coordinates and then adding
// their Y coordinates. This gives the X and Y coordinates of the "answer."
// Thus you'll need to convert two sets of polar coordinates to rectangular
// coordinates, add them, then convert the resulting rectangular
// representation back to polar.
#include <iostream>
#include <cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Rectangular
{
private:
   double dX;
   double dY;
public:
   Rectangular()
   : dX(0.0), dY(0.0)
   {}
   Rectangular(double Xcoord, double Ycoord)
   : dX(Xcoord), dY(Ycoord)
   {}
   void show();
   double getX() const { return dX; }
   double getY() const { return dY; }
};
/////////////////////////////////////////////////////////////////////////////////////////
class Polar
{
private:
   double dAngle;
   double dRadius;
public:
   Polar()
   : dAngle(0.0), dRadius(0.0)
   {}
   Polar(double Angl, double Rad)
   : dAngle(Angl), dRadius(Rad)
   {}
   Polar(Rectangular rec)
   {
      dRadius = sqrt(rec.getX()*rec.getX() + rec.getY() * rec.getY());
      dAngle = atan2(rec.getY(), rec.getX()) * 180/M_PI;
   }
   void show();
    operator Rectangular() const;
   Polar operator+(Polar) const;
};
/////////////////////////////////////////////////////////////////////////////////////////
void Polar::show()
{
   cout << "Radius: " << dRadius << " Angle: " << dAngle << endl;
}
//---------------------------------------------------------------------------------------
Polar::operator Rectangular() const
{
   double dXcoord = dRadius * cos(dAngle * (M_PI/180));
   double dYcoord = dRadius * sin(dAngle * (M_PI/180));
   return Rectangular(dXcoord, dYcoord);
}
//---------------------------------------------------------------------------------------
Polar Polar::operator+(Polar pl) const
{
   Rectangular rc1((dRadius * cos(dAngle)), (dRadius * sin(dAngle)));
   //cout << "rc1 = ";
   //rc1.show();
   Rectangular rc2 = (Rectangular) pl;
   //cout << "rc2 = ";
   //c2.show();
   Rectangular rcRez((rc1.getX() + rc2.getX()), (rc1.getY() + rc2.getY()));
   return Polar(rcRez);
}
//---------------------------------------------------------------------------------------
void Rectangular::show()
{
   cout << "x: " << dX << " y: " << dY << endl;
}
//---------------------------------------------------------------------------------------
int main(int argc, char*argv[])
{
   Polar pl1(45, 4);
   cout << "pl1 - ";
   pl1.show();
   Polar pl2(35, 6);
   cout << "pl2 - ";
   pl2.show();
   Polar pl3 = pl1 + pl2;
   cout << "pl3 - ";
   pl3.show();
   //cout << atan2(1,1) << endl;
   return 0;
}