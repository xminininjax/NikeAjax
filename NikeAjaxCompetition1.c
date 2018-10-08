#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           indexer,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           flywheel1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           flywheel2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)


#include "Vex_Competition_Includes.c"
#pragma platform(VEX2)
#pragma competitionControl(Competition)

/*
Nike Ajax
54744A
Bishop Kelly High School, Boise, Idaho
*/

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task move(){
	
//code to input distance/degrees to rotate instead of raw time

/*4 in wheel, 12 ft long arena, 6 tiles, 24 in per tile
Circum = 4pi move 2 tiles = 48/4pi = #rev = 12/pi = 3.819revs
100 rpm/ 60 = 5/3 rps
3.819*(3/5) = 2.29
2.291831181 secs per 2 tiles
2.3 secs per 2 tiles
1.14591559 sec per tile
1.15 sec per tile
*/

//double == float
float diameter = 4;
float circumfrence = diameter*PI;

float targetDistance = 1;//placeholder
float linearRevs = targetDistance/circumfrence;
float a = linearRevs*(3/5);//convert rpm to sec
a = a*1000;//convert to Msec

float robotRadius = 8;//CHANGE
float degreesRotate = 1;//placeholder
float arc = (robotRadius*2*PI)/(360/degreesRotate);
float arcRevs= arc/circumfrence;
float b = arcRevs*(3/5);
b = b*1000;
int i = 0;

i = 0;
while (i==0){
	targetDistance = 24;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}


i = 0;
while (i==0){
	targetDistance = -24;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}

i=0;
while (i==0){
	degreesRotate = -90;//set rotation degrees
	if (degreesRotate>0)
		motor[rightDrive] = -127;
		motor[leftDrive] = 127;
	if (degreesRotate<0)
		motor[rightDrive] = 127;
		motor[leftDrive] = -127;
		
	sleep(b);
	i++;
}

i = 0;
while (i==0){
	targetDistance = 24;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}

i = 0;
while (i==0){
	targetDistance = -12;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}

i=0;
while (i==0){
	degreesRotate = 90;//set rotation degrees
	if (degreesRotate>0)
		motor[rightDrive] = -127;
		motor[leftDrive] = 127;
	if (degreesRotate<0)
		motor[rightDrive] = 127;
		motor[leftDrive] = -127;
		
	sleep(b);
	i++;
}

i = 0;
while (i==0){
	targetDistance = 24;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}

i=0;
while (i==0){
	degreesRotate = -90;//set rotation degrees
	if (degreesRotate>0)
		motor[rightDrive] = -127;
		motor[leftDrive] = 127;
	if (degreesRotate<0)
		motor[rightDrive] = 127;
		motor[leftDrive] = -127;
		
	sleep(b);
	i++;
}

i = 0;
while (i==0){
	targetDistance = 12;//set distance
	if (targetDistance>0)
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	if (targetDistance<0)
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
	sleep(a);
	i++;
}
}//end task move


task fire(){
	while(time1[T1]<6000){
	motor[intake] = 127;
	}
	clearTimer(T1);
	//accelerate flyeheel over 5 seconds	
	while(time1[T2]<5000){
		for(int i = 0; i <= 5; i++){
			motor[flywheel1] = (i*(127/5));
			motor[flywheel2] = (i*(127/5));
			wait1Msec(1000);
		}
	}
	clearTimer(T2);
	motor[flywheel1] = 127;
	motor[flywheel2] = 127;
	
	sleep(1000);
	
	//fire
	motor[intake] = 127;
	motor[indexer] = 127;
	motor[flywheel1] = 127;
	motor[flywheel2] = 127;
	sleep(2300);
	
	//deaccelerate flywheel over 10 seconds	
	while(time1[T2]<10000){
		for(int i = 10; i >= 0; i--){
			motor[flywheel1] = (i*(127/10));
			motor[flywheel2] = (i*(127/10));
			sleep(1000);
		}
	}
	clearTimer(T2);
	
}//end task fire

task autonomous(){
	startTask (move);
	startTask (fire);
	sleep(15000);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
 
  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    sleep(20);
  }
}
