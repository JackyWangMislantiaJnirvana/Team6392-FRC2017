#include <Driver.h>
#include <AHRS.h>

Driver::Driver(driveMotorChannel leftMotorC, driveMotorChannel rightMotorC)
{
	leftMotor = new frc::Spark(leftMotorC);
	rightMotor = new frc::Spark(rightMotorC);
	nav = new AHRS(SerialPort::kMXP);
}

Driver::~Driver()
{
	delete nav;
}

void Driver::OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick)
{
	// TODO Copy the control algorithms from Tang's code
}

void Driver::autoMove(Driver::direction direct, double distance)
{
	//TODO finish this (using Encoders)
}
void Driver::autoTurn(Driver::direction direct, double angle)
{
	//TODO finish this (using NavX Gyro)
}
