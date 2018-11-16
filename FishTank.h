//
// Interface File
//

#ifndef FishTank_h
#define FishTank_h

#include <string>
#include "Fish.h"

using std::string;


class FishTank
{
 public:
         FishTank();// sets int value to 0 and fills tank pic with blanks
         FishTank(int hgt, int wid);// sets height and width to given values
         // otherwise behaves like nullary constructor above
         void setHeight(int hgt);
         void setWidth(int wid);
         int getHeight();
         int getWidth();
         int getMaxFish();
         int getNumFish();
         bool addFish(Fish f); // adds fish to the tank if there is space
         // available (returns true), doesn't modify tank (returns false)
         void clearTank(); // clear tank, fills tank  with spaces
         void showTank();// prints the character map on cout
         void updateAt(int row, int col, char newChar);// update the given
         // character map with the new character
         void simulate(bool singleStep, int fps);// runs tank simulation.
         // fps is the number of frames per second


private:

         static const int MAX_FISH = 40;
         static const int MAX_HGT = 50;
         static const int MAX_WID = 200;

         int tank_wid;
         int tank_hgt;
         int num_fish_in_tank;
         Fish Fish_array[MAX_FISH]; // stores all the fishes
         char FishTank_pic[MAX_HGT][MAX_WID];
};

#endif

