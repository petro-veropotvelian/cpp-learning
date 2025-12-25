// exercise_12_1.cpp
#include <iostream>
#include <fstream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class Distance                                             // English Distance class
{
private:
   int feet;
   float inches;
public:                                                    // constructor (no args)
   Distance(): feet(0), inches(0.0)
   {}
                                                          // constructor (two args)
   Distance(int ft, float in) : feet(ft), inches(in)
   {}

   void get_dist()                                       // get length from user
   {
      cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;
   }

   void showdist()                                      // display distance
   {
      cout << feet << "\'-" << inches << "\"";
   }
};
/////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    char ch;
    Distance dist;
    fstream file;
    file.open("DIST.DAT", ios::app|ios::out|ios::in|ios::binary);    // open for addend data from user to file
    do
    {
        cout << "\nEnter a distance:";
        dist.get_dist();
        file.write(reinterpret_cast<char*>(&dist), sizeof(dist));
        cout << "Enter another distance (y/n)? ";
        cin >> ch;
    } while (ch=='y' || ch=='Y');                                    // quit on 'n'
    file.seekg(0);                                                   // reset to start of the file
    file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
    while (!file.eof())
    {
       cout << "\nDistance: ";
       dist.showdist();
       file.read(reinterpret_cast<char*>(&dist), sizeof(dist)); 
    }
    cout << endl;
    return 0;
}