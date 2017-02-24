/*
 * Robot.cpp
 *
 * Main file of robot code
 */

// Custom Headers
#include <Robot.h>
#include <Driver.h>

/*	Robot() - Constructor for Robot class
 * ----------------------------
 * It is called once when the program is booted
 * Initialize objects and variables
 *
 */
Robot::Robot():
	moveStick(RobotMap::kMoveJoystickChannel),
	rotateStick(RobotMap::kRotateJoystickChannel),
	//EXP
//	robotDrive(RobotMap::leftMotorChannel, RobotMap::rightMotorChannel),
	driver(RobotMap::leftMotorChannel, RobotMap::rightMotorChannel),

	// Upper Structure
	//TODO 改变成员:将upper和lower switch改成一个
	ball(RobotMap::ballLimitSwitchChannel, RobotMap::ballActuatorChannel, RobotMap::ballBoosterChannel)
{}


/* RobotInit() - Initializer after the constructor
 * ----------------------------
 * It is called after the constructor is called.
 *
 */
void Robot::RobotInit()
{
	chooser.AddDefault(autoNameDefault, autoNameDefault);
	chooser.AddObject(autoNameCustom, autoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

/*
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString line to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the
 * SendableChooser make sure to add them to the chooser code above as well.
 */


// Initialization before auto stage
void Robot::AutonomousInit()
{
	driver.autoTurn(Driver::turnClockwise, 180);
	autoSelected = chooser.GetSelected();
	// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
	std::cout << "Auto selected: " << autoSelected << std::endl;

	if (autoSelected == autoNameCustom)
	{
		// Custom Auto goes here
	}
	else
	{
		// Default Auto goes here
	}
}

// Periodically called in auto stage
void Robot::AutonomousPeriodic()
{
	if (autoSelected == autoNameCustom)
	{
		// Custom Auto goes here
	}
	else
	{
		// Default Auto goes here
	}
}

// Initialization before TELEOP stage
void Robot::TeleopInit()
{


}

// Periodically called in TELEOP stage
void Robot::TeleopPeriodic()
{
	// Ball

	// Gear

	// Climb

	while (IsOperatorControl())
	{
		//EXP Driving control , powered by wpi RobotDrive::ArcadeDrive algorithms
		//robotDrive.ArcadeDrive(moveStick.GetRawAxis(Joystick::kDefaultYAxis), -rotateStick.GetRawAxis(Joystick::kDefaultXAxis));
//		driver.OperatorDrive(&rotateStick, &moveStick);
		if (moveStick.GetRawButton(3))
		{
			std::cout << "get3!" << std::endl;
			ball.setActuatorPosition(OperatorActuator::LowerPosition);
		}
		if (moveStick.GetRawButton(4))
		{
			std::cout << "get4" << std::endl;
			ball.setActuatorPosition(OperatorActuator::UpperPosition);
		}
		frc::Wait(0.5);
	}
}

void Robot::TestInit()
{
}
// Periodically called in Test mode
void Robot::TestPeriodic()
{
	driver.initTestMode(lw);
	lw->Run();
}

START_ROBOT_CLASS(Robot)
