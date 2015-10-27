/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"
////////////////////////////////////////////////////////////////////////////////


/*  Telling the parallax to move n distance in milimeeters */

void moveDistance(double mm)
{
  double ticks;
  ticks = mm/3.25;
  drive_goto(ticks, ticks);
}

void turnLeft()
{
  drive_goto(-26, 25);
}  

void turnRight()
{
  drive_goto(25, -26);
}  

void turnBack()
{
  drive_goto(-52, 50);
}  

int main()                                    // Main function
{
  // Add startup code here.
  moveDistance(160);
  pause(1000);
  moveDistance(160);
  moveDistance(160);
  pause(1000);
  moveDistance(160);
  pause(1000);
  while(1)
  {
    // Add main loop code here.
    
    
  }  
}
