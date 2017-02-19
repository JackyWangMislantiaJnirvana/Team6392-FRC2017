/*
 * RobotMap.h
 *
 * Mapping port number with devices
 */

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

namespace RobotMap
{
const bool isRightLeftReflection = 0;
const double delayTime = 0.1l;

enum joystickAnxisChannel
{
	X = 0, Y = 1, Z = 2
};
enum joystickChannel
{
	rotateJoystickChannel = 1,
	moveJoystickChannel = 0,
	upperStructureJoystickChannel = 2
};

enum baseMotorChannel
{
	rightMotorChannel = 1, leftMotorChannel = 0
};
enum upperMotorChannel
{
	ballBoosterChannel = 5,
	ballActuatorChannel = 3,
	gearActuatorChannel = 4,
	climbBoosterChannel = 2,

	// No longer used
	// Channel of a motor which dosen't exist
	voidMotorChannel = 9
};

enum encoderChannels
{
	AChannel = 1, BChannel = 0
};

enum limitSwitchChannel
{
	ballUpperLimitSwitchChannel = 2, ballLowerLimitSwitchChannel = 3,
	gearUpperLimitSwitchChannel = 4, gearLowerLimitSwitchChannel = 5
};

enum limitSwitchStatus
{
	triggered = 1, free = 0
};

// Button Definitions for upper structure
enum upperStructureControls
{
	gearActuatorTriggerButton = 1,
	ballActuatorTriggerButton = 2,
	climbBoosterONButton = 11,
	climbBoosterOFFButton = 12,

	// if slider value is positive, turn on the motor. if not, turn it of.
	ballBoosterONOFFSlider = 3
};
}

#endif //ROBOTMAP_H_
