// elev_app.cpp
// client supplied file
#include "elev.h"                                                              // for class declarations

int main(int argc, char* argv[])
{
   //SetConsoleOutputCP(437);
   //SetConsoleOutputCP(65001);
   building theBuilding;
   while (true)
   {
      theBuilding.master_tick();                                               // send time tick to all cars
      wait(1000);                                                              // pause
      theBuilding.record_floor_reqs();                                         // get floor request from user
   }
   return 0;
}