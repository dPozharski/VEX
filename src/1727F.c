/*
 * 1727F.c
 *
 *  Created on: Sep 23, 2016
 *      Author: rexadmin
 */

#include"C:\Users\Denis\Desktop\Vex\include\FTEAM.h"

float armTarget = 0;
float armTarget_Auto = 0;
float clawTarget = 0;
float lclawTarget_Auto = 0;
float rclawTarget_Auto = 0;
float gyroTarget = 0;

void drivetrain(void *params)
{
	float leftPower;
	float rightPower;
	while(1)
	//Sqaure drive for OpControlk
	{
		leftPower = (joyMain.leftVertical.axisValue*(abs(joyMain.leftVertical.axisValue)))*driveFactor/(127.0*127.0)*127;
		rightPower = (joyMain.rightVertical.axisValue*(abs(joyMain.rightVertical.axisValue)))*driveFactor/(127.0*127.0)*127;
		motorSet(RL, leftPower);
		motorSet(RR, -rightPower);
		motorSet(FR, -rightPower);
		motorSet(FL, leftPower);
		delay(20);
	}
}


void lift(void *params)
{
	while(1)
	{
		motorSet(RYCARM, ((joyMain.leftBumper.axisValue == JOY_UP)*127) + ((joyMain.leftBumper.axisValue == JOY_DOWN)*-127));
		motorSet(RARMINV, ((joyMain.leftBumper.axisValue == JOY_UP)*-127) + ((joyMain.leftBumper.axisValue == JOY_DOWN)*127));
		motorSet(LYCARM, ((joyMain.leftBumper.axisValue == JOY_UP)*-127) + ((joyMain.leftBumper.axisValue == JOY_DOWN)*127));
		motorSet(LARMINV, ((joyMain.leftBumper.axisValue == JOY_UP)*127) + ((joyMain.leftBumper.axisValue == JOY_DOWN)*-127));
		delay(20);

	}
}


void claw(void*params)
{
	while(1)
	{
		motorSet(RCLAW, ((joyMain.rightBumper.axisValue == JOY_UP)*-127)+((joyMain.rightBumper.axisValue == JOY_DOWN)*127));
		motorSet(LCLAW, ((joyMain.rightBumper.axisValue == JOY_UP||analogRead(LCLAW_POT)<LCLAW_MAX)*127)+((joyMain.rightBumper.axisValue == JOY_DOWN)*-127));
		delay(20);
	}
}
void driveChange(void*params){
 driveFactor=1;
 while(true){
 if(joyMain.rightDpad.axisValue == JOY_UP){
	 driveFactor=1;
 }
	else if(joyMain.rightDpad.axisValue == JOY_DOWN){
		driveFactor=.8;
	}
delay(20);
}
}


void musicPlay(void*params){

	while(true){
		if(joyMain.leftDpad.axisValue == JOY_LEFT){
			speakerPlayRtttl("JC:d=4,o=5,b=90:16d#,16c#,16b4,16a#4,8g#4,16b6,16p,16a#6,16f#6,16p,8g#6,16g#4,8g#4,8g#4,8b4,8g#4,8g#6,16a#6,16f#6,16p,8g#6,16g#4,8g#4,8g#4,8d#5,8g#4,16b6,16p,16a#6,16f#6,16p,8g#6.,8b4,16g#4,16g#4,16b4,16c#,8g#4,8g#6,16a#6,16f#6,16p,8g#6,16b4,8g#4,16b4,16g#4,16b4,16c#,8g#4,2p,1p");
		}
		else if(joyMain.leftDpad.axisValue==JOY_RIGHT){
			for(int i = 0;i<=3;i++)
			speakerPlayRtttl("Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6");
			delay(20);
		}
		else if(joyMain.leftDpad.axisValue == JOY_UP){
			speakerPlayRtttl("1812:d=4,o=5,b=200:8c,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8e6,8p,8c6,8p,c.6,8g,8c,16g4,16g4,8c,8d,8e,8d,8c,8d,8e,8p,8c,8p,2c,8p,16a,16a,8d6,8e6,8d6,8a,8f,8a,8d6,8a,8f,8a,d.6,8g,8c,16g,16g,8c6,8d6,8c6,8g,8e,8g,8c6,8g,8e,8g,c.6,8p,1g4,2a4,2a4,2g.4,e4,1c4,1c5,2b4,2a4,1g4,2a.4,p,1f4,2g4,2g4,2e.4,e4,f4,f#4,g4,a4,2g4,g.4,8g4,2g,2g4,8c6,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8c6,16g,16g,8c6,8d6,8c6,8g,8e,8g,1c6,1c4,1p");
		}
		else if(joyMain.leftDpad.axisValue == JOY_DOWN){
			speakerPlayRtttl("Win:d=4,o=5,b=140:f,f,16d,16p,f,16d,16p,8f,8d,16c,16p,2f,8d,8c6,8d6,8c6,8d6,8c.6,16c,16a#,16a,8g,2f,p,16f6,2p");
			delay(500);
			speakerPlayRtttl("LU:d=4,o=5,b=140:16e,16e,16e,8b,2p");
			delay(500);
			speakerPlayRtttl("Evolve:d=4,o=5,b=500:8c,8d,8e,8f,8g,8g#,2a.,2f.,1c.,a#,a#,a#,g,g,a#,1a.,f6,1p,1p");
		}
		else if(joyMain.leftDpad.axisValue == JOY_DOWN && joyMain.leftDpad.axisValue == JOY_RIGHT){
			speakerPlayRtttl("TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#");
		}
			delay(20);
		}
}






//ARM
//AUTO
void setArmTarget_Auto(float degrees){
	armTarget_Auto = degrees;
}

void setArmTarget(void *ignore)
	{
		while(true)
		{
			if(joyMain.leftBumper.axisValue == JOY_UP)
			{
				armTarget += ARM_SPEED/50.0;
			}
			else if(joyMain.leftBumper.axisValue == JOY_DOWN)
			{
				armTarget -= ARM_SPEED/50.0;
			}
			armTarget = armTarget > ARM_MAX ? ARM_MAX : armTarget;
			armTarget = armTarget < ARM_MIN ? ARM_MIN : armTarget;
			delay(20);
		}
	}


float getArmInput()
{
	return analogRead(ARM_POT);
}


float getArmTarget()
{
	return armTarget;
}


float getArmTarget_Auto(){
	return armTarget_Auto;
}
//CLAW

//TELEOP
void setClawTarget(void *ignore){
	while (true) {
			clawTarget=analogRead(LCLAW_POT);
delay(20);
		}
	}

//TELEOP
float getClawInput(){
	return analogRead(LCLAW_POT);
}

//AUTO
float getLClaw(){
	return analogRead(LCLAW_POT);
}
//AUTO
float getRClaw(){
	return analogRead(RCLAW_POT);
}

//TELEOP
float getClawTarget(){
	return clawTarget;
}

//AUTO
float getLClawTarget(){
	return lclawTarget_Auto;
}

//AUTO
float getRClawTarget(){
	return rclawTarget_Auto;
}

//AUTO
void setAutoLClawTarget(float degrees){
	lclawTarget_Auto = degrees;
}

//AUTO
void setAutoRClawTarget(float degrees){
	rclawTarget_Auto = degrees;
}
// DRIVE
//AUTO ONLY!!!
float getLeftDrive(){
	return encoderGet(leftDrive);
}

float getRightDrive(){
	return encoderGet(rightDrive);
}

float getLeftDriveTarget(){
	return leftDriveTarget;
}

float getRightDriveTarget(){
	return rightDriveTarget;
}

void setTargetForward(float inches){
	leftDriveTarget += (inches*360)/(MPI*4);
	rightDriveTarget += (inches*360)/(MPI*4);
}

void setTargetRotate(float degrees){
leftDriveTarget += degrees*DEGREES_TO_TICKS; 
rightDriveTarget-= degrees*DEGREES_TO_TICKS;
}


float getGyro(){
	return (float)(gyroGet(gyro));
}

float getGyroTarget(){
	return gyroTarget;
}

void setGyroTarget(float target){
	gyroTarget=target;
}
//AUTO SELECTION
int selectAuton(){
	int currentAuton = 0;
	while(true){
		switch (currentAuton) {
			case BLUE_FAR_AUTO:
				lcdPrint(uart1, 1, "BLUE_FAR_AUTO");
				break;
			case BLUE_NEAR_AUTO:
				lcdPrint(uart1, 1, "BLUE_NEAR_AUTO");
				break;
			case RED_FAR_AUTO:
				lcdPrint(uart1, 1, "RED_FAR_AUTO");
				break;
			case RED_NEAR_AUTO:
				lcdPrint(uart1, 1, "RED_NEAR_AUTO");
				break;
			case NO_AUTO:
				lcdPrint(uart1, 1, "NO_AUTO");
				break;
			case AUTON_SKILLS:
				lcdPrint(uart1, 1, "PROGRAMMING_SKILLS");
				break;

		}
		if(lcdReadButtons(uart1)==1){
			currentAuton -=1;
		}
		else if(lcdReadButtons(uart1)==4){
			currentAuton+=1;
		}
		else if(lcdReadButtons(uart1)==2){
				return currentAuton;
		}
		if(currentAuton<0)
			currentAuton=0;

		else if(currentAuton>5)
			currentAuton = 5;

			delay(20);
	}
	return 4;
}
//AUTON SEQUENCES
void BFS()
{

}
void BNS(){

}
void RNS(){

}
void RFS(){

}
void progSkills(){

}
