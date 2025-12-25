// exercise_12_5.cpp
// Create a time class that includes integer member values for hours, minutes, and seconds.
// Make a member function get_time() that gets a time value from the user, and a function
// put_time() that displays a time in 12:59:59 format. Add error checking to the get_time()
// function to minimize user mistakes. This function should request hours, minutes, and seconds
// separately, and check each one for ios error status flags and the correct range. Hours
// should be between 0 and 23, and minutes and seconds between 0 and 59. Don't input these
// values as strings and then convert them; read them directly as integers. This implies that
// you won't be able to screen out entries with superfluous decimal points, as does the
// ENGL_IO program in this chapter, but we'll assume that's not important.
#include <iostream>
using namespace std;
const int MAXHOURS = 23;
const int MAXMINSEC = 59;
/////////////////////////////////////////////////////////////////////////////////////////
class my_time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    my_time()
    : hours(0), minutes(0), seconds(0)
    {}
    my_time(int hrs, int mnt, int sec)
    : hours(hrs), minutes(mnt), seconds(sec)
    {}
    void get_time();
    void put_time();
};
//---------------------------------------------------------------------------------------
void my_time::put_time()
{
    if (hours < 10)
    {
        cout << "0";
    }
    cout << hours << ":";
    if (minutes < 10)
    {
        cout << "0";
    }
    cout  << minutes << ":";
    if (seconds < 10)
    {
        cout << "0";
    }
    cout << seconds << endl;
}
//---------------------------------------------------------------------------------------
void my_time::get_time()
{
    while (true)
    {
        cout <<"\nEnter hours: ";
        cin.unsetf(ios::skipws);
        cin >> hours;
        if (hours >= 0 && hours <= MAXHOURS)
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.ignore(10, '\n');
        cout << "Hours should be between 0 and 23\n";
    }
    while (true)
    {
        cout << "\nEnter minutes: ";
        cin.unsetf(ios::skipws);
        cin >> minutes;
        if (minutes >= 0 && minutes <= MAXMINSEC)
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.ignore(10, '\n');
        cout << "Minutes should be between 0 and 59\n";
    }
    while (true)
    {
        cout << "\nEnter seconds: ";
        cin.unsetf(ios::skipws);
        cin >> seconds;
        if (seconds >= 0 && seconds <= MAXMINSEC)
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.ignore(10, '\n');
        cout << "Seconds should be between 0 and 59\n";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
    my_time mTime;
    char ans;
    do
    {
        mTime.get_time();
        cout << "\nTime = ";
        mTime.put_time();
        cout << "\nDo another (y/n)? ";
        cin >> ans;
        cin.ignore(10, '\n');
    } while (ans!='n' && ans!='N');
    return 0;
}