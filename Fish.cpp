#include<iostream>
#include<sstream>
#include "Fish.h"
#include "FishTank.h"
#include<unistd.h>
#include <cstring>

using namespace std;



//
// A constructor that initializes a fish's bitmap to all spaces, its size
// and speed numbers to 0, its name to an empty string
//
Fish::Fish()
{
  for(int row = 0; row < MAX_HGT ; row++)
    for(int col = 0; col < MAX_WID; col++){
      Fish_pic[row][col] = ' ';
    }
  Fish_hgt = 0;
  Fish_wid = 0;
  verticalSpeed = 0;
  horizontalSpeed = 0;
  Fish_name = "";

}

//
// readFish()
// purpose: reads the fish (i.e. its size,velocity,name,picture)
// returns: returns true if it recognizes a fish (according to input format)
//          else returns false
//   Note: uses getline function to account for "empty" spaces in pictures of fishes
//

bool Fish::readFish()
{
  string first_word;

    cin >> first_word;
    if (first_word != "fish"){
      return false;
    }
    else if (first_word == "fish") {
      cin >> Fish_hgt;
      cin >> Fish_wid;
      cin >> horizontalPosition;
      cin >> verticalPosition;
      cin >> verticalSpeed;
      cin >> horizontalSpeed;
      cin >> Fish_name;
      verticalPosition = verticalPosition + 2;// fixes the starting position
      if( Fish_hgt > MAX_HGT || Fish_wid > MAX_WID //reject fishes bigger than tank
        || Fish_hgt < 0 || Fish_wid < 0){
        return false;
          }
      else
      {
        cin.getline(line,1); // fixes an error of inputing spaces in the first line.

        for(int i = 0; i< Fish_hgt;i++){
          cin.getline(Fish_pic[i],Fish_wid +1 );
        }

        return true;
      }
    }
}

// used to allow user to get the private value of name
string Fish::getName()
{
  return Fish_name;
}

// exists for user to set the name of a fish
void Fish::setName(string name)
{
  Fish_name = name;
}

// exists for user to set the horizontal speed of a fish
void Fish::setHSpeed(float new_speed)
{
  horizontalSpeed = new_speed;
}

// exists for user to set the vertical speed of a fish
void Fish::setVSpeed(float new_speed)
{
  verticalSpeed = new_speed;
}

// exists for user to set the position of a fish
void Fish::setPos(int row, int col)
{
  horizontalPosition = row;
  verticalPosition = col;
}

// used to allow user to get the private value of height
int Fish::getHeight()
{
  return Fish_hgt;
}

// used to allow user to get the private value of width
int Fish::getWidth()
{
  return Fish_wid;
}

//
// move
// purpose: updates the fish's position according to its current position
//          and horizontal and vertical speeds
// arguments: integers that represents Tank Height and Tank Width
// returns: nothing
//

void Fish::move(int tankHeight, int tankWidth)
{

  horizontalPosition = horizontalPosition + horizontalSpeed;
  verticalPosition = verticalPosition + verticalSpeed;
    if(horizontalPosition < 0){
        horizontalPosition = tankWidth;// if fish is moving to
          //the left, it resets to the right (end of the tank)
    }
    if(verticalPosition < 0){
      verticalPosition = tankHeight;
    }

}

//
// draw
// purpose: draws the fish's picture in the tank
// arguments: a pointer which points at the Fish Tank
// returns: nothing
//
void Fish::draw(FishTank *tank)
{
  int tank_hgt;
  int tank_wid;
  for(int row = 0; row < Fish_hgt;row++){
    int HorizontalPosition = (int) horizontalPosition;
    int VerticalPosition = (int) verticalPosition; //resets the values so that
    //the picture is drawn in the next spot compared to the original spot

      for(int col = 0; col < Fish_wid; col++){
        HorizontalPosition = horizontalPosition + col;
        VerticalPosition = verticalPosition + row;
        tank_hgt = tank -> getHeight();
        tank_wid = tank -> getWidth();
        HorizontalPosition = HorizontalPosition % tank_wid; //resets pos to zero when it's
        VerticalPosition = VerticalPosition % tank_hgt; // when it's equal to tank size
        tank -> updateAt( VerticalPosition, HorizontalPosition, Fish_pic[row][col]);
      }
  }

}
