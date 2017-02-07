// Include Protection
#ifndef DRIVER_H_
#define DRIVER_H_

#include <iostream>

#include <AHRS.h>
#include <Spark.h>

#include "RobotMap.h"


class Driver
{
private:
	const double driveParameter = 0.7;
	const double Pi = 3.1415;
	const int SamplesToAverage = 5;
	const double DistancePerPulse = (1.0 / 360.0) * 2.0 * Pi * 1.5;
	const double MinRate = 1.0;

	frc::Spark leftBaseMotor, rightBaseMotor;
	frc::Encoder baseEncoder;
	AHRS *navigator;

public:
	enum direction {turnLeft = 0, turnRight = 1, forward = 2, back = 3};

	Driver(RobotMap::baseMotorChannel leftMotor, RobotMap::baseMotorChannel rightMotor);
	~Driver();
	void OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick);
	void autoMove(direction direct, double distance);
	void autoTurn(direction direct, double angle);
};

#endif // Include Protection
