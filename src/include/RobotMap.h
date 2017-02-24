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
	kRotateJoystickChannel = 1,
	kMoveJoystickChannel = 0,
	kUpperStructureJoystickChannel = 2
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

	// 保证此PWM端口什么都不接
	voidMotorChannel = 9
};

enum encoderChannels
{
	AChannel = 1, BChannel = 0
};

enum limitSwitchChannel
{
	ballLimitSwitchChannel = 3,
	gearLimitSwitchChannel = 2
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
