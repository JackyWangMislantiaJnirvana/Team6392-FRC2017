/*
 * Robot.h
 * header file for Robot.cpp
 *
 */
#pragma once

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

	frc::Joystick *moveStick;
	frc::Joystick *rotateStick;
	frc::RobotDrive *drive;

public:
	Robot();
	void RobotInit();
	void AutonomousInit() override;
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};
