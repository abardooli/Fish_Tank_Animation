#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
using namespace std;

#include "Fish.h"
#include "FishTank.h"


//
// Code by: Ahmed Bardooli
// Date: 04/04/2014
// Title: Fish Simulation
// Description: The program runs an animation of fishes in a tank. It uses two classes
//              namely, Fish and FishTank. It takes in one tank and up to 40 fishes
//              from the user, and it outputs the all the fishes added inside the tank
//              with their properties inside the tank. Properties include(size, velocity
//              starting position)

int main()
{
  Fish f;// declare Fish
  string word;
  int hgt, wid;

  cin >> word;
  if(word == "tank"){
     cin >> hgt ;
     cin >> wid ;
  }


  FishTank ft(hgt,wid);   // declare FishTank

  while( !cin.eof()) // as long as there fishes to read, keep reading
    {
      f.readFish();
      ft.addFish(f);
    }

   cout << "\033[2J" ; // clears screen
  ft.simulate(false, 500000); //runs the animation


 return 0;

}

