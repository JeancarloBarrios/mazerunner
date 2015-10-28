/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"                          // Include ab drive Headers
#include "ping.h"                            // Include ping Headers
////////////////////////////////////////////////////////////////////////////////


/*  Telling the parallax to move n distance in milimeeters */

void moveDistance(double mm)
{
  double ticks;
  ticks = mm/3.25;
  ticks = mm;
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

int checkRight()
{
  int left;
  freqout(0, 1, 38000);
  left = input(1);
  return left;
}    

int checkLeft()
{
  int right;
  freqout(13, 1, 38000);
  right = input(11);
  return right;
} 

void turnLeftH()
{
  moveDistance(80);
  turnLeft();
  if(ping_cm(8)>= 32)
    moveDistance(80);
}     

void turnRightH()
{
  moveDistance(80);
  turnRight();
  if(ping_cm(8)>= 32)
    moveDistance(80);
}     


int main()                                    // Main function
{
  low(26);
  low(27);
  int irLeft, irRight;
  // Add startup code here.
 
  int leftDist, rightDist;

  while(1)
  {
    drive_setRampStep(10);
    drive_ramp(64, 64);
    
    while(1)
    {
      
      irLeft = checkLeft();
      irRight = checkRight();
      irRight = ping_cm(8);
      print ("left = %d,  right = %d \n", irLeft, irRight);
      if(irLeft == 1)
      {
        high(26);
      }
      else
      {
        low(26);
      }        
      if(ping_cm(8)<=10)
      {
        high(27);
      }
      else
      {
        low(27);
      }                        
      if(irLeft == 1)
      {
        
        drive_ramp(0, 0);
        turnLeftH();
        print (" Left empty hall detected");
        break;
      } 
      if (ping_cm(8)<=9)
      {
        drive_ramp(0, 0);
        turnBack();
        print (" End of the line");
        break;
      }               
    }      
  }    
    
     
}
