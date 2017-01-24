#pragma once

#include <AHRS.h>
#include <Spark.h>
#include <iostream>

class Driver
{
private:
	const double driveParameter = 0.7;
	frc::Spark *leftMotor, *rightMotor;
	AHRS *nav;
public:
	enum driveMotorChannel {rightMotorChannel = 0, leftMotorChannel = 1};
	enum direction {turnLeft = 0, turnRight = 1, forward = 2, back = 3};

	Driver(driveMotorChannel leftMotor, driveMotorChannel rightMotor);
	~Driver();
	void OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick);
	void autoMove(direction direct, double distance);
	void autoTurn(direction direct, double angle);
};
