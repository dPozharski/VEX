/*
 * 1727F.h
 *
 *  Created on: Sep 23, 2016
 *      Author: rexadmin
 */
#ifndef _1727F_H_
#define _1727F_H_
#include <C:\Users\Denis\Desktop\Vex\include\API.h>
#include"C:\Users\Denis\Desktop\Vex\include\rexAPI.h"

#define RL		          1
#define RYCARM	        2
#define RARMINV		      3
#define FR		          4
#define LCLAW		        5
#define RCLAW		        6
#define FL		          7
#define LARMINV         8
#define LYCARM		      9
#define RR		          10
#define ARM_POT         1
#define ARM_SPEED       50
#define ARM_MAX         100
#define ARM_MIN         0
#define LCLAW_POT       2
#define RCLAW_POT       3
#define LCLAW_MAX       4000
#define BLUE_FAR_AUTO   0
#define BLUE_NEAR_AUTO  1
#define RED_NEAR_AUTO   2
#define RED_FAR_AUTO    3
#define NO_AUTO         4
#define AUTON_SKILLS    5
#define MPI            3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034
#define DEGREES_TO_TICKS 3.6

TaskHandle joystick_task;  //RAPI

TaskHandle drivetrain_task;  //DRIVE TELEOP

TaskHandle lift_task;  //ARM TELEOP (OUTDATED)

TaskHandle claw_task;  //CLAW TELEOP (OUTDATED)

TaskHandle driveChange_task;  //DRIVE TELEOP

TaskHandle musicPlay_task;  //FLUFF

TaskHandle armPID_task;  //ARM TELEOP

TaskHandle armTarget_task;  //ARM TELEOP

TaskHandle clawTarget_task; //CLAW TELEOP

TaskHandle clawPID_task;  //CLAW TELEOP

TaskHandle rightDrive_auto_task; //DRIVE AUTO

TaskHandle leftDrive_auto_task; //DRIVE AUTO

TaskHandle lClawAutoPID_task;  //CLAW AUTO

TaskHandle rClawAutoPID_task;  //CLAW AUTO

TaskHandle armAutoPID_task;  //ARM AUTO

void setClawTarget(void *ignore); //CLAW TELEOP

void setAutoLClawTarget(float degrees); // CLAW AUTO

void setAutoRClawTarget(float degrees); //CLAW AUTO

void drivetrain(void *params); //DRIVE TELEOP

void lift(void *params); //OUTDATED

void claw(void *params); //OUTDATED

void driveChange(void*params); //DRIVE TELEOP

void musicPlay(void*params);  //FLUFF

void setArmTarget(void *ignore); // ARM TELEOP

void setArmTarget_Auto(float degrees); //ARM AUTO

void setTargetForward(float inches);  //DRIVE AUTO

void setTargetRotate(float degrees);  //DRIVE AUTO

void resetDriveTargets();  //DRIVE AUTO

void setGyroTarget(float target);  //DRIVE AUTO

void setAutoLClawTarget(float degrees);  // CLAW AUTO

void setAutoRClawTarget(float degrees);  // CLAW AUTO

float getArmInput();  //ARM TELEOP

float getArmTarget_Auto();  //ARM AUTO

float getArmTarget();  //ARM TELEOP

float getClawTarget();  //CLAW TELEOP

float getClawInput();  //CLAW TELEOP

float getLClawInput();  //CLAW AUTO

float getRClawInput();  //CLAW AUTO

float getLClawTarget();  //CLAW AUTO

float getRClawTarget();  //CLAW AUTO

float getLeftDriveTarget(); //DRIVE AUTO

float getRightDriveTarget(); //DRIVE AUTO

float getRightDrive(); //DRIVE AUTO

float getLeftDrive(); //DRIVE AUTO

float getGyro(); //DRIVE  AUTO

float getGyroTarget(); //DRIVE  AUTO

float getRClaw(); //CLAW  AUTO

float getLClaw(); //CLAW  AUTO

int selectAuton();  //AUTO SELECTER

int selectedAuton;  //AUTO SELECTER

int leftDriveTarget;  //DRIVE AUTO

int rightDriveTarget;  //DRIVE AUTO

void BNS();   //AUTO SEQUENCE

void BFS();  //AUTO SEQUENCE

void RFS();  //AUTO SEQUENCE

void RNS();  //AUTO SEQUENCE

void progSkills();  //AUTO SEQUENCE

Encoder leftDrive;
Encoder rightDrive;
Gyro gyro;

float driveFactor; // DRIVE TELEOP
#endif /* 1727F_H_ */
