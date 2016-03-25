/***********************************************************************
 * Exp3_Turning -- RedBot Experiment 3
 * 
 * Explore turning with the RedBot by controlling the Right and Left motors
 * separately.
 * 
 * Hardware setup:
 * This code requires only the most basic setup: the motors must be
 * connected, and the board must be receiving power from the battery pack.
 * 
 * 23 Sept 2013 N. Seidle/M. Hord
 * 04 Oct 2014 B. Huang
 ***********************************************************************/
#include <RedBot.h>

RedBotMotors motors; // Instantiate the motor control object.


int left_speed;
int right_speed;

int bounded(int amount) {
  if(amount > 255) amount = 255;
  if(amount < -255) amount = -255;
  return amount;
}

void increase_left(int amount) {
  left_speed = bounded(left_speed+amount);
  motors.leftMotor(left_speed);
}

void increase_right(int amount) {
  right_speed = bounded(right_speed+amount);
  motors.rightMotor(right_speed); // Turn CCW at motorPower of 10
}

void increase_both(int amount) {
  increase_left(amount);
  increase_right(amount);
}


void command(char c) {
  int amount = 20;
  if(c == 'w') {
    increase_both(amount);
  } else if(c == 'a') {
    increase_left(-amount);
  } else if(c == 's') {
    increase_both(-amount);    
  } else if(c == 'd') {
    increase_right(-amount);
  } else if(c == 'x') {
    motors.brake();
  }
}


void setup()
{
}

void loop()
{
  command('w');
  delay(500);
  command('a');
  delay(500);
  command('s');
  command('s');
  delay(500);
  command('d');
  delay(500);
}

