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
