/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "C:\Users\Denis\Desktop\Vex\include\main.h"
#include "C:\Users\Denis\Desktop\Vex\include\FTEAM.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
pidParams armParams = {&getArmInput, &getArmTarget, -1, 0, 0, 0, {RYCARM, -RARMINV, -LYCARM, LARMINV}};

pidParams armAutoParams = {&getArmInput, &getArmTarget_Auto, -1, 0, 0, 0, {RYCARM, -RARMINV, -LYCARM, LARMINV}};		//same values as above

pidParams clawParams = {&getClawInput, &getClawTarget, -1, 0, 0, 0, {RCLAW}};

pidParams lClawAutoParams = {&getClawInput, &getLClawTarget, -1, 0, 0, 0, {-LCLAW}};

pidParams rClawAutoParams = {&getClawInput, &getRClawTarget, -1, 0, 0, 0, {RCLAW}};				//same values as clawParams

pidParams rightDriveParams = {&getRightDrive,&getRightDriveTarget, -1, 0 , 0 , 0 , {-RL,FL}};

pidParams leftDriveParams = {&getLeftDrive,&getLeftDriveTarget, -1, 0 , 0 , 0 , {-RR,FR}};

void initialize() {

	speakerInit();

	gyro = gyroInit(4, 0);

	leftDrive = encoderInit(12, 11, true);

	rightDrive = encoderInit(1, 2, false);

	lcdInit(uart1);

	lcdSetBacklight(uart1, true);

	armAutoPID_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &armAutoParams, TASK_PRIORITY_DEFAULT);

	joystick_task = taskCreate(getJoysticks, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	drivetrain_task = taskCreate(drivetrain, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	lift_task = taskCreate(lift, TASK_DEFAULT_STACK_SIZE, NULL , TASK_PRIORITY_DEFAULT);

	claw_task = taskCreate(claw, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	driveChange_task = taskCreate(driveChange,TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	musicPlay_task = taskCreate(musicPlay, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	armPID_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &armParams, TASK_PRIORITY_DEFAULT);

	armTarget_task = taskCreate(setArmTarget, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	clawTarget_task = taskCreate(setClawTarget, TASK_DEFAULT_STACK_SIZE,NULL, TASK_PRIORITY_DEFAULT);

	clawPID_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &clawParams, TASK_PRIORITY_DEFAULT);

	lClawAutoPID_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &lClawAutoParams, TASK_PRIORITY_DEFAULT);

	rClawAutoPID_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &rClawAutoParams, TASK_PRIORITY_DEFAULT);

	leftDrive_auto_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &leftDriveParams, TASK_PRIORITY_DEFAULT);

	rightDrive_auto_task = taskCreate(positionPIDControl, TASK_DEFAULT_STACK_SIZE, &rightDriveParams, TASK_PRIORITY_DEFAULT);

	taskSuspend(joystick_task);

	taskSuspend(drivetrain_task);

	taskSuspend(lift_task);

	taskSuspend(claw_task);

	taskSuspend(driveChange_task);

	taskSuspend(musicPlay_task);

	taskSuspend(armTarget_task);

	taskSuspend(armPID_task);

	taskSuspend(clawTarget_task);

	taskSuspend(clawPID_task);

	taskSuspend(leftDrive_auto_task);

	taskSuspend(rightDrive_auto_task);

	taskSuspend(rClawAutoPID_task);

	taskSuspend(lClawAutoPID_task);

	taskSuspend(armAutoPID_task);

	selectedAuton = selectAuton();

	lcdPrint(uart1,1,"Auto Selected");
}
