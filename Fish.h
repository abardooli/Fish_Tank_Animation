#ifndef Fish_H
#define Fish_H

#include <string>
using std::string;

//
// "header file" for Fish
//

class FishTank;

class Fish
{
 public:
         Fish();

         bool readFish(); // reads a fish specification from cin
         string getName(); // return's the fish's name
         void setName(string name); // sets the fish's name to name
         void setHSpeed(float new_speed); //sets the horizontal speed of fish
         void setVSpeed(float new_speed);//sets the vertical speed of fish
         void setPos(int row, int col);//sets the position of fish
         int getHeight();//return the height of fish's char map picture
         int getWidth();//return the width of fish's char map picture
         void move(int tankHeight, int tankWidth);//updates fish's position
         // according to its speed in x and y directions
         void draw(FishTank *tank);


private:
     // includes element that represent the state of a Fish
         static const int MAX_HGT = 30;
         static const int MAX_WID = 60;

         float horizontalPosition;
         float verticalPosition;
         float horizontalSpeed;
         float verticalSpeed;
         int Fish_hgt;
         int Fish_wid;
         string Fish_name;
         char Fish_pic[MAX_HGT][MAX_WID];
         char line[1]; // useless variable to fix an error of reading
                       // a line of spaces initially

};

#endif
