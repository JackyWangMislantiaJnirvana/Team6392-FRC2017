#include <Driver.h>

//Driver::Driver(RobotMap::baseMotorChannel leftMotorC, RobotMap::baseMotorChannel rightMotorC):
Driver::Driver(RobotMap::baseMotorChannel leftMotorChannel,
			   RobotMap::baseMotorChannel rightMotorChannel) :
		// No longer used
//		voidMotor(RobotMap::voidMotorChannel),
		leftBaseMotor(leftMotorChannel), rightBaseMotor(rightMotorChannel),
		baseEncoder(RobotMap::AChannel, RobotMap::BChannel),
		turnController(NULL),
		moveController(NULL),
		turnPIDControllerOutput(0.0l),
		movePIDControllerOutput(0.0l)
{
	// initialize IMU
	// if anything bad happened, output the reason into driver station console
	try
	{
		navigator = new AHRS(frc::SPI::Port::kMXP);
	}
	catch (std::exception ex)
	{
		std::string err_string = "Error instantiating NavX-MXP";
		err_string += ex.what();
		frc::DriverStation::ReportError(err_string.c_str());
	}


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
// 模块锁定: 不要再动这个模块了。目前它行为良好，即使逻辑混乱...
void Driver::OperatorDrive(frc::Joystick *rotateJoystick,
						   frc::Joystick *moveJoystick)
{
	double rawMoveValue, rawRotateValue;
	double leftBaseMotorPower, rightBaseMotorPower;
	rawMoveValue = -moveJoystick->GetRawAxis(RobotMap::X);
	rawRotateValue = rotateJoystick->GetRawAxis(RobotMap::Y);

//	std::cout << "[Debug MSG] " << "MoveValue: " << rawMoveValue << "RotateValue: " << rawRotateValue << std::endl;

	leftBaseMotorPower = rawMoveValue + Driver::kDriveGain * rawRotateValue;
	rightBaseMotorPower = rawMoveValue - Driver::kDriveGain * rawRotateValue;

	// Perform motor actions
	leftBaseMotor.Set(	RobotMap::isRightLeftReflection ?
						leftBaseMotorPower : -leftBaseMotorPower);
	rightBaseMotor.Set(	RobotMap::isRightLeftReflection ?
						rightBaseMotorPower : -rightBaseMotorPower);
}

// W.I.P.
// Move straightly to a specified distance
/*void Driver::autoMove(Driver::direction moveDirect, double distance)
{
	double leftBaseMotorPower = 0.0l;
	double rightBaseMotorPower = 0.0l;
	moveController = new frc::PIDController(kMovePGain, kMoveIGain, kMoveDGain, navigator, this);

	// Reset IMU
	navigator->Reset();

	//TESTME Check Me: Min Max反没？
	moveController->SetInputRange(kPIDInputMin, kPIDInputMax);
	moveController->SetOutputRange(kPIDOutputMin, kPIDInputMax);
	moveController->SetAbsoluteTolerance(kToleranceDegrees);

	switch (moveDirect)
	{
	//TODO 如何让机器前进给定距离？量轮子周长？？？？？？？
	//TESTME 确认不会跑反
		case forward:
			break;
		case back:

			break;
		default:
			break;
	}
}
*/
// Rotate to a specified angle
void Driver::autoTurn(Driver::direction turnDirect, double angle)
{
	double leftBaseMotorPower = 0.0l;
	double rightBaseMotorPower = 0.0l;
	turnController = new frc::PIDController(kTurnPGain, kTurnIGain, kTurnDGain, navigator, this);

	// Reset IMU
	navigator->Reset();

	turnController->SetInputRange(kPIDInputMin, kPIDInputMax);
	turnController->SetOutputRange(kPIDOutputMin, kPIDOutputMax);
	turnController->SetContinuous(true);
	turnController->SetAbsoluteTolerance(kToleranceDegrees);
	switch (turnDirect)
	{
		// TESTME 确认不会转反... = =
		case turnClockwise:
			turnController->SetSetpoint(angle);
			break;
		case turnAntiClockwise:
			turnController->SetSetpoint(-angle);
			break;
		default:
			break;
	}

	// Stops the loop if the error is small enough to be ignored.
	while(std::fabs(turnController->GetError()) <= kToleranceDegrees)
	{
		// Perform motor powers
		leftBaseMotor.Set(leftBaseMotorPower);
		rightBaseMotor.Set(rightBaseMotorPower);
	}

}

void Driver::PIDWrite(double output)
{
	turnPIDControllerOutput = output;
}

void Driver::initTestMode(frc::LiveWindow *livewindow)
{
	livewindow->Run();
}

void Driver::updateSmartStashboard()
{
	frc::SmartDashboard::PutNumber("Gyro", navigator->GetYaw());
}
