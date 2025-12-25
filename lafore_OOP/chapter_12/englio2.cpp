// englio2.cpp
// overloaded << and >> operators can work with files
#include <fstream>
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
class Distance                                                       // English Distance class
{
private:
   int feet;
   float inches;
public:
   Distance():feet(0), inches(0.0)                                   // constructor (no args)
   {
   }
   Distance(int ft, float in) : feet(ft), inches(in)                 // constructor (two args)
   {
   }
   friend istream& operator>>(istream& s, Distance& d);
   friend ostream& operator<<(ostream& s, Distance& d);
};
//-----------------------------------------------------------------------------
istream& operator>>(istream& s, Distance& d)                         // get Distance from file
{                                                                    // or keyboard with
  char dummy;                                                        // overloaded >> operator
   s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
   return s;
}
//-----------------------------------------------------------------------------
ostream& operator<<(ostream& s, Distance& d)                         // send Distance to file or
{                                                                    // screen with overloaded
   s << d.feet << "\'-" << d.inches << '\"';                         // << operator
   return s;
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char ch;
   Distance dist1;
   ofstream ofile;                                                   // create and open
   ofile.open("DIST.DAT");                                           // output stream
   do
   {
      cout << "\nEnter distance: ";
      cin >> dist1;                                                  // get distance from user
      ofile << dist1;                                                // write it to output stream
      cout << "Do you want to continue (y/n)? ";
      cin >> ch;
   } while (ch!='n' && ch!='N');
   ofile.close();                                                    // close output stream

   ifstream ifile;                                                   // create and open
   ifile.open("DIST.DAT");                                           // input stream
   cout << "\nContent of the file:\n";
   while (true)
   {
      ifile >> dist1;                                                // read Distance from stream
      if (ifile.eof())                                               // quit on EOF
      {
        break;
      }
      cout << "Distance = " << dist1 << endl;                        // display distance
   }
   return 0;
}
