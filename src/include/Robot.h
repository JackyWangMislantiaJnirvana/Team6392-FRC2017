/*
 * Robot.h
 *
 * header file for Robot.cpp
 */

// Include Protection
#ifndef ROBOT_H_
#define ROBOT_H_

// Headers from standard library
#include <iostream>
#include <memory>
#include <string>

// Headers from WPILIB
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Joystick.h>							// Joystick Header (general)
#include <RobotDrive.h>
#include <AHRS.h>
#include <Timer.h>
#include "Driver.h"
#include "RobotMap.h"

#include "BallHandler.h"
#include "GearHandler.h"
#include "Climber.h"



class Robot: public frc::IterativeRobot
{
private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoReachLine = "Reach the line";
	const std::string autoPutGear = "Put gear";
	std::string autoSelected;

	frc::Joystick moveStick;
	frc::Joystick rotateStick;
	frc::Joystick upperStick;

	//frc::RobotDrive robotDrive;
	Driver driver;

	BallHandler ball;
	GearHandler gear;
	Climber climber;

	bool ballButtomLastState;
	bool gearButtomLastState;
public:
	Robot();
	void RobotInit();
	void AutonomousInit() override;
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit() override;
	void TestPeriodic() override;
};

#endif // Include Protection
