/*
 * Robot.h
 *
 * header file for Robot.cpp
 */

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

// Include Protection
#ifndef ROBOT_H_
#define ROBOT_H_

enum joystickAnxisChannel {X = 0, Y = 1, Z = 2, Slider = 3};
enum joystickChannel {rotateJoystickChannel = 1, moveJoystickChannel = 0};

class Robot: public frc::IterativeRobot
{
private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	frc::Joystick moveStick;
	frc::Joystick rotateStick;

public:
	Robot();
	void RobotInit();
	void AutonomousInit() override;
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif // Include Protection
