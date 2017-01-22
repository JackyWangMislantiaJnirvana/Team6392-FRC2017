// Headers from standard library
#include <iostream>
#include <memory>
#include <string>

// Headers from WPILIB
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Spark.h>								// Motor controller Header (Spark)
#include <Joystick.h>							// Joystick Header (general)
#include <RobotDrive.h>

// Custom Headers
#include <Robot.h>

//TODO confirm joystickAnxisChannel is correct
enum joystickAnxisChannel {X, Y, Z, Slider};

const int rightMotorChannel = 0;
const int leftMotorChannel = 1;
const int rotateJoystickChannel = 0;
const int moveJoystickChannel = 1;

class Robot: public frc::IterativeRobot
{
private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	frc::Joystick *moveStick = new frc::Joystick(rotateJoystickChannel);
	frc::Joystick *rotateStick = new frc::Joystick(moveJoystickChannel);
	frc::RobotDrive *drive = new frc::RobotDrive(leftMotorChannel, rightMotorChannel);

public:
	void RobotInit()
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
	void AutonomousInit() override
	{
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

	void AutonomousPeriodic()
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

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		while (IsOperatorControl())
		{
			// Driving control , powered by wpi RobotDrive::ArcadeDrive algorithms
			drive->ArcadeDrive(moveStick, Y, rotateStick, X);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
