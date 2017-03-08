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
	upperStick(RobotMap::kUpperStructureJoystickChannel),
	driver(RobotMap::leftMotorChannel, RobotMap::rightMotorChannel),

	// Upper Structure
//	ball(),
//	gear(),
//	climber()
	ballButtomLastState(false),
	gearButtomLastState(false)
{}


/* RobotInit() - Initializer after the constructor
 * ----------------------------
 * It is called after the constructor is called.
 *
 */
void Robot::RobotInit()
{
	chooser.AddDefault(autoReachLine, autoReachLine);
	chooser.AddObject(autoPutGear, autoPutGear);
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

	if (autoSelected == autoPutGear)
	{

	}
	else // Drive straitly and reach the line for default
	{

	}
}

// Periodically called in auto stage
void Robot::AutonomousPeriodic()
{
	if (autoSelected == autoPutGear)
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
	while (IsOperatorControl())
	{
		// Climb
		if (upperStick.GetRawButton(RobotMap::climbBoosterONButton))
			climber.startClimb();
		else
			if (upperStick.GetRawButton(RobotMap::climbBoosterOFFButton))
				climber.stopClimb();
		// Ball
		// TESTME 反没？
		ball.setBallBoosterPower(upperStick.GetRawAxis(RobotMap::ballBoosterONOFFSlider) >= 0.5 ? 1.0l : 0.0l);
		ballButtomLastState = upperStick.GetRawButton(RobotMap::ballActuatorTriggerButton);
		if ((ballButtomLastState == false) && (upperStick.GetRawButton(RobotMap::ballActuatorTriggerButton) == true))
			ball.changeBallActuatorPosition();
		ballButtomLastState = !ballButtomLastState;

		// Gear
		if ((ballButtomLastState == false) && (upperStick.GetRawButton(RobotMap::gearActuatorTriggerButton) == true))
			gear.changeGearActuatorPosition();
		gearButtomLastState = !gearButtomLastState;

/*
		driver.OperatorDrive(&rotateStick, &moveStick);
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
*/
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
