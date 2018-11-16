#include<iostream>
#include<unistd.h>
#include <cstdlib>
#include "FishTank.h"

using namespace std;

//
// A constructor that sets the integer values to 0 and fills the tank picture
// with all blanks
//

FishTank::FishTank()
{
  tank_wid = 0;
  tank_hgt = 0;
  num_fish_in_tank = 0;

  for(int row = 0; row < MAX_HGT ; row++)
    for(int col = 0; col < MAX_WID; col++){
      FishTank_pic[row][col] = ' ';
    }
}

//
// A constructor that sets the height and width of the tank, otherwise
//  it behaves like the constructor above
//
FishTank::FishTank(int hgt, int wid)
{
    tank_hgt = hgt;
    tank_wid = wid;

    for(int row = 0; row < tank_hgt ; row++)
      for(int col = 0; col < tank_wid; col++){
        FishTank_pic[row][col] = ' ';
      }
}

// exists for user to set the height of the tank
void FishTank::setHeight(int hgt)
{
  tank_hgt = hgt;
}

// exists for user to set the width of the tank
void FishTank::setWidth(int wid)
{
  tank_wid = wid;
}

// used to allow user to get the private value of tank height
int  FishTank::getHeight()
{
	  return tank_hgt;
	}

	// used to allow user to get the private value of tank width
	int FishTank::getWidth()
	{
	  return tank_wid;
	}

	// used to allow user to get the private value of Maximum number of
	// fishes that can be entered
	int FishTank::getMaxFish()
	{
	  return MAX_FISH;
	}
	// used to allow user to get the private value of number of fishes in
	// the tank
	int FishTank::getNumFish()
	{
	  return num_fish_in_tank;
	}

	//
	// addFish
	// purpose: adds the given fish to the tank if there is room in the tank
	// arguments: a class fish (includes all the fishes properties)
	// returns: true if there is space available for more fishes,
	//          and returns false of fish tank is full
	//
	bool FishTank::addFish(Fish f)
	{

	  getNumFish();
	  if(num_fish_in_tank > MAX_FISH)
	  {
	    return false;
	  }
	  else
	  {
	    Fish_array[num_fish_in_tank] = f;
	    num_fish_in_tank++;
	    return true;
	  }

	}

	//
	// clearTank
	// purpose: clears the character map, fills it with spaces
	void FishTank::clearTank()
	{
	  for(int row = 0; row < MAX_HGT ; row++)
	      for(int col = 0; col < MAX_WID; col++){
	        FishTank_pic[row][col] = ' ';
	      }
	}
	//
	// showTank
	// purpose: prints the character map on cout.
	void FishTank::showTank()
	{
	  for(int row = 0; row < tank_hgt ; row++){
	      for(int col = 0; col < tank_wid ; col++){
	              cout << FishTank_pic[row][col];
	            }
	            cout << endl;
	    }
	}
	//
	// updateAt
	// purpose: updates the character map at the given row
	//          and column with the new character
	void FishTank::updateAt(int row, int col, char newChar)
	{
	  if (newChar != ' '){ // so that user can see through fishes
	  FishTank_pic[row][col] = newChar;
	  }
	}
	//
	// simulate
	// purpose: runs the tank simulation
	// arguments:an integer fps (the number of frames per second),
	//           and a boolean to select how the simulation is run
	//           if singleStep is set to true, he simulation pauses after displaying
	//           each frame until the user types a carriage return
	void FishTank::simulate(bool singleStep, int fps)
	{
	  cout << "\033[2J" ; // clears screen
	  this -> FishTank_pic[tank_hgt][tank_wid] = FishTank_pic[tank_hgt][tank_wid];
	  for(;;) // infinite loop to run animation until user quits
	  {
	      clearTank();
	      for(int i = 0; i < num_fish_in_tank ; i++){
	        Fish_array[i].draw(this);
	        Fish_array[i].move(tank_hgt, tank_wid);
	        }
	      cout << "\33[H"; // home cursor

	      showTank();
	      if(singleStep == false){
	          usleep(fps);
	      }
	      if(singleStep == true)
	      {
	        if (system("read x < /dev/tty") != 0)
	                exit(0);
	      }
	  }
	}
