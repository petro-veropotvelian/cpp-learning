// exercise_11_8.cpp
// Let's put a little twist into the HORSE example of Chapter 10 by making a
// class of extracompetitive horses. We'll assume that any horse that's ahead
// by the halfway point in the race starts to feel its oats and becomes almost
// unbeatable. From the horse class, derive a class called comhorse (for
// competitive horse). Overload the horse_tick() function in this class so that
// each horse can check if it's the front-runner and if there's another horse
// close behind it (say 0.1 furlong). If there is, it should speed up a bit.
// Perhaps not enough to win every time, but enough to give it a decided
// advantage.
// How does each horse know where the other horses are? It must access the
// memory that holds them, which in the HORSE program is hArray. Be careful,
// however. You want to create comhorses, not horses. So the comhorse class
// will need to overload hArray. You may need to derive a new track class,
// comtrack, to create the comhorses.
// You can continuously check if your horse is ahead of the (otherwise) leading
// horse, and if it's by a small margin, accelerate your horse a bit.
// models a horse race
#include "msoftcon.h"                                  // for console graphics
#include <iostream>                                    // for I/O
#include <cstdlib>                                     // for random()
#include <ctime>                                       // for time()
using namespace std;
const int CPF = 5;                                     // columns per furlong
const int maxHorses = 7;                               // maximum number of horses
class track;                                           // for forward references
/////////////////////////////////////////////////////////////////////////////////////////
class horse
{
protected:
   const track* ptrTrack;                              // pointer to track
   const int horse_number;                             // this horse's number
   float finish_time;                                  // this horse's finish time
   float distance_run;                                 // distance run so far
public:
   horse(const int n, const track* ptrT)
      : horse_number(n), ptrTrack(ptrT),
      distance_run(0.0)                                // haven't moved yet
   {}
   virtual ~horse()                                            // destroy the horse
   { /*empty*/
   }
   virtual void display_horse(const float elaplse_time);       // display the horse
   float get_distance_run(void) const { return distance_run; }
   void draw_clean_line();
}; // end class horse
/////////////////////////////////////////////////////////////////////////////////////////
class comhorse : public horse
{
/**protected:
   const track* ptrTrack;                              // pointer to track
   const int horse_number;                             // this horse's number
   float finish_time;                                  // this horse's finish time
   float distance_run;                                 // distance run so far*/
public:
   comhorse(const int n, const track* ptrT)
   : horse(n, ptrT)                  // haven't moved yet
   {}
   ~comhorse()                                            // destroy the horse
   { /*empty*/
   }
   void display_horse(const float elaplse_time);       // display the horse
}; // end class comhorse
/////////////////////////////////////////////////////////////////////////////////////////
class track
{
private:
   horse* hArray[maxHorses];                           // array of ptrs-to-horses
   int total_horses;                                   // total number of horses
   int horse_count;                                    // horses created so far
   const float track_length;                           // track length in furlongs
   float elapsed_time;                                 // time since start to race
public:
   track(float lenT, int nH);                          // 2-arg constructor
   ~track();                                           // destructor
   void display_track();                               // display track
   void run();                                         // run the race
   float get_track_len() const;                        // return total track length
   int get_horse_count() const;
   bool check_leading(int nHorseNumber) const;
}; // end class track
//---------------------------------------------------------------------------------------
void horse::draw_clean_line()
{
   set_cursor_pos(5, 2 + horse_number * 2);
   clear_line();
   set_color(cWHITE);
   for (int i = 0; i <= ptrTrack->get_track_len(); i++)                                     // for each furlong
   {
      for (int r = 0; r < ptrTrack->get_horse_count() * 2 + 1; r++)                              // and screen row
      {
         if (r == horse_number)
         {
            set_cursor_pos(i * CPF + 5, 2 + r * 2);
            if (i == 0 || i == ptrTrack->get_track_len())
            {
               cout << '\xDE';                                                        // draw start or finish line
            }
            else
            {
               cout << '\xB3';                                                        // draw furlong marker
            }
         }
      }
   }
}
//---------------------------------------------------------------------------------------
void horse::display_horse(float elapsed_time)          // for each horse
{
   draw_clean_line();
   set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);   // display horse & number

   set_color(static_cast<color>(cBLUE + horse_number));                 // horse 0 is blue
   char horse_char = '0' + static_cast<char>(horse_number);             // draw horse
   _putch(' ');
   _putch('\xDB');
   _putch(horse_char);
   _putch('\xDB');
   if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)            // until finish,
   {
      if (rand() % 3)                                                   // skip about 1 of 3 ticks
      {
         distance_run += 0.2F;                                          // advance 0.2 furlongs
      }
      finish_time = elapsed_time;                                       // update finish time
   }
   else                                                                 // display finish time
   {
      int mins = int(finish_time) / 60;
      int secs = int(finish_time) - mins * 60;
      cout << "  Time=" << mins << ":";
      if (secs < 10)
      {
         cout << '0';
      }
      cout << secs;
   }
   set_cursor_pos(5, maxHorses * 2 + horse_number + 1);
   cout << "Horse number: " << horse_number << " distance run: " << distance_run;
}// end dislplay_horse()
//---------------------------------------------------------------------------------------
void comhorse::display_horse(float elapsed_time)          // for each horse
{
   draw_clean_line();
   bool bHalfPassed = false;
   bool bIsLeading = false;
   set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);   // display horse & number

   set_color(static_cast<color>(cBLUE + horse_number));                 // horse 0 is blue
   char horse_char = '0' + static_cast<char>(horse_number);             // draw horse
   _putch(' ');
   _putch('\xDB');
   _putch(horse_char);
   _putch('\xDB');
   if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)            // until finish,
   {
      if (distance_run >= (ptrTrack->get_track_len()/2 + 1.0 / CPF))
      {
         bHalfPassed = true;
         bIsLeading = ptrTrack->check_leading(horse_number);
      }
      else
      {
         bHalfPassed = false;
      }
      if (rand() % 3)                                                   // skip about 1 of 3 ticks
      {
         distance_run += 0.2F;                                          // advance 0.2 furlongs
      }
      if (bHalfPassed && bIsLeading)
      {
         distance_run += 0.2F;
      }
      finish_time = elapsed_time;                                       // update finish time
   }
   else                                                                 // display finish time
   {
      int mins = int(finish_time) / 60;
      int secs = int(finish_time) - mins * 60;
      cout << "  Time=" << mins << ":";
      if (secs < 10)
      {
         cout << '0';
      }
      cout << secs;
   }
   set_cursor_pos(5, maxHorses * 2 + horse_number + 1);
   cout << "It's a comhorse!!! Horse number : " << horse_number << " distance run : " << distance_run;
   if (bHalfPassed)
   {
      cout << " Halfway passed!";
      if (bIsLeading)
      {
         cout << "Is leading!";
      }
   }
} // end dislplay_horse()
 //---------------------------------------------------------------------------------------
track::track(float lenT, int nH)                                        // track constructor
   : track_length(lenT), total_horses(nH),
   horse_count(0), elapsed_time(0.0)
{
   init_graphics();                                                        // start graphics
   time_t aTime;                                                           // initialize random numbers
   srand(static_cast<unsigned>(time(&aTime)));
   total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;   // not more than 7 horses
   int nComHorseIndex = rand() % total_horses;
   for (int j = 0; j < total_horses; j++)                                  // make each horse
   {
      if (j==nComHorseIndex)
      {
         hArray[j] = new comhorse(horse_count++, this);
      }
      else
      {
         hArray[j] = new horse(horse_count++, this);
      }
   }

   display_track();
}// end track constructor
//---------------------------------------------------------------------------------------
track::~track()                                                            // track destructor
{
   for (int j = 0; j < total_horses; j++)
   {
      delete hArray[j];                                                    // delete each horse
   }
}
//---------------------------------------------------------------------------------------
void track::display_track()
{
   clear_screen();                                                         // clear screen
                                                                           // display track
   for (int f = 0; f <= track_length; f++)                                     // for each furlong
   {
      for (int r = 1; r <= total_horses * 2 + 1; r++)                              // and screen row
      {
         set_cursor_pos(f * CPF + 5, r);
         if (f == 0 || f == track_length)
         {
            cout << '\xDE';                                                        // draw start or finish line
         }
         else
         {
            cout << '\xB3';                                                        // draw furlong marker
         }
      }
   }
}// end display_track()
//---------------------------------------------------------------------------------------
void track::run()
{
   while (!_kbhit())
   {
      elapsed_time += 1.75;                                                       // update time
      for (int j = 0; j < total_horses; j++)
      {
         hArray[j]->display_horse(elapsed_time);
      }
      wait(500);
   }
   _getch();                                                                       // eat the keystroke
   cout << endl;
}
//---------------------------------------------------------------------------------------
float track::get_track_len() const
{
   return track_length;
}
//---------------------------------------------------------------------------------------
int track::get_horse_count() const
{
   return total_horses;
}
//---------------------------------------------------------------------------------------
bool track::check_leading(int nHorseNumber) const
{
   bool bReturn = false;
   float fMaxDist = 0.0;
   int nLeaderIndex;
   for (int i = 0; i < total_horses; i++)
   {
      if (hArray[i]->get_distance_run() > fMaxDist)
      {
         fMaxDist = hArray[i]->get_distance_run();
         nLeaderIndex = i;
      }
   }
   if (nHorseNumber == nLeaderIndex)
   {
      bReturn = true;
   }
   return bReturn;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   float length;
   int total;
   cout << "\nEnter track lengh (furlongs; 1 to 12): ";      // get data from user
   cin >> length;
   cout << "\nEnter number of horses (1 to 7): ";
   cin >> total;
   track theTrack(length, total);                            // create the track
   theTrack.run();                                           // run the race
   return 0;
} // end main()