#include <Driver.h>

Driver::Driver(RobotMap::driveMotorChannel leftMotorC, RobotMap::driveMotorChannel rightMotorC):
	leftBaseMotor(leftMotorC),
	rightBaseMotor(rightMotorC),
	baseEncoder(RobotMap::AChannel, RobotMap::BChannel)
{
	//initialize member objects
	navigator = new AHRS(frc::SPI::Port::kMXP);

	/* Defines the number of samples to average when determining the rate.
	 * On a quadrature encoder, values range from 1-255; larger values
	 *   result in smoother but potentially less accurate rates than lower
	 *   values.
	 */
	baseEncoder.SetSamplesToAverage(SamplesToAverage);

	/* Defines how far the mechanism attached to the encoder moves per pulse.
	 * In this case, we assume that a 360 count encoder is directly attached
	 * to a 3 inch diameter (1.5inch radius) wheel, and that we want to
	 * measure distance in inches.
	 */
	baseEncoder.SetDistancePerPulse(DistancePerPulse);

	/* Defines the lowest rate at which the encoder will not be considered
	 *   stopped, for the purposes of the GetStopped() method.
	 * Units are in distance / second, where distance refers to the units
	 *   of distance that you are using, in this case inches.
	 */
	baseEncoder.SetMinRate(MinRate);
}

Driver::~Driver()
{
	delete navigator;
}

// KISS driver algorithms copied from Tang's code for FRC2016
void Driver::OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick)
{
	// TODO Test this.
	double rawMoveValue, rawRotateValue;
	double leftBaseMotorPower, rightBaseMotorPower;
		// EXP Is that OK? Using GetAxis() ??
	rawMoveValue = -moveJoystick->GetAxis(frc::Joystick::kYAxis);
	rawRotateValue = rotateJoystick->GetAxis(frc::Joystick::kXAxis);
	leftBaseMotorPower = rawMoveValue + Driver::driveParameter * rawRotateValue;
	rightBaseMotorPower = rawMoveValue - Driver::driveParameter * rawRotateValue;
		// Perform motor actions
	leftBaseMotor.Set(RobotMap::isRightLeftReflection ? leftBaseMotorPower : -leftBaseMotorPower);
	rightBaseMotor.Set(RobotMap::isRightLeftReflection ? rightBaseMotorPower: -rightBaseMotorPower);
}

void Driver::autoMove(Driver::direction direct, double distance)
{
	//TODO finish this (using Encoders)
}
void Driver::autoTurn(Driver::direction direct, double angle)
{
	//TODO finish this (using NavX Gyro)
}
