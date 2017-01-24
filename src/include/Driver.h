#pragma once

#include <AHRS.h>
#include <Spark.h>
#include <iostream>

class Driver
{
private:
	frc::Spark *leftMotor, *rightMotor;
	AHRS *nav;
public:
	enum driveMotorChannel {rightMotorChannel = 0, leftMotorChannel = 1};


	Driver(driveMotorChannel leftMotor, driveMotorChannel rightMotor);
	~Driver();
	//TODO finish function below
	void OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick);
	void Move();
	void Turn();
};
