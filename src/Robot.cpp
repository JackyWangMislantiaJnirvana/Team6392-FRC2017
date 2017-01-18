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

// Custom Headers
#include <Robot.h>

class Robot: public frc::IterativeRobot
{
private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	// EXP Motor experiment #1
	frc::Spark *motor1 = new frc::Spark(1);
	frc::Joystick *joy = new frc::Joystick(0);

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
		motor1->Set(0);
	}

	void TeleopPeriodic()
	{
		// EXP motor experiment #1
		double Power = joy->GetRawAxis(1);	// Read angle from the motor
		printf("Angle: %f\n", Power);		// DBMSG Print present angle
		motor1->Set(-Power);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
