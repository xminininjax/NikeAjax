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

task autonomous()
{
  // ..........................................................................
 		//accelerate flyeheel over 5 seconds	
	while(time1[T3]<5000){
		for(int i = 0; i <= 5; i++){
			motor[flywheel1] = (i*25.4);
			motor[flywheel2] = (i*25.4);
			wait1Msec(1000);
		}
	}
	clearTimer(T3);
	motor[flywheel1] = 127;
	motor[flywheel2] = 127;//not sure if this will keep the motors running until otherwise told
	
	//forward 2 tiles and collect ball
	motor[rightDrive] = 127;
	motor[leftDrive] = 127;
	motor[intake] = 127;

	wait1Msec(2300);

	//backward 2 tiles
	motor[rightDrive] = -127;
	motor[leftDrive] = -127;
	motor [intake] = 63;

	wait1Msec(2300);
	
	//turn 90 degrees
	//color dependent
	motor[rightDrive] = 127;
	motor[leftDrive] = -127;

	wait1Msec(500);//theta

	//forward 2 tiles
	while(time1[T1]<2300){
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
	}
	clearTimer(T1);
	
	//fire
	while(time1[T2]<2300){
		motor[intake] = 127;
		motor[indexer] = 127;
		motor[flywheel1] = 127;
		motor[flywheel2] = 127;
	}
	clearTimer(T2);
	
	wait1Msec(2000);
	
	//deaccelerate flywheel over 10 seconds	
	while(time1[T4]<10000){
		for(int i = 10; i >= 0; i--){
			motor[flywheel1] = (i*12.7);
			motor[flywheel2] = (i*12.7);
			wait1Msec(1000);
		}
	}
	//clearTimer[T4];????
	
	//backward 1 tile
	motor[rightDrive] = -127;
	motor[leftDrive] = -127;

	wait1Msec(1150);
	
	//turn -90 degrees
	//color dependent
	motor[rightDrive] = -127;
	motor[leftDrive] = 127;
	wait1Msec(500);//theta

	//forward 2 tiles and flip cap
	motor[rightDrive] = 127;
	motor[leftDrive] = 127;
	motor[intake] = 127;

	wait1Msec(2300);
	
	//turn 90 degrees
	motor[rightDrive] = 127;
	motor[leftDrive] = -127;
	
	wait1Msec(500);//theta
	
	//forward 1 tile
	motor[rightDrive] = 127;
	motor[leftDrive] = 127;

	wait1Msec(1150);
	
	//backward 1 tile
	motor[rightDrive] = -127;
	motor[leftDrive] = -127;

	wait1Msec(1150);
	
	//swerve
	motor[rightDrive] = -127;
	motor[leftDrive] = -63;

	wait1Msec(500);//theta2
	
	motor[rightDrive] = -63;
	motor[leftDrive] = -127;

	wait1Msec(500);//theta2
	
	//park
	motor[rightDrive] = -127;
	motor[leftDrive] = -127;

	wait1Msec(1000);//tbd
	
}
  // ..........................................................................
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
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();
  }
}
