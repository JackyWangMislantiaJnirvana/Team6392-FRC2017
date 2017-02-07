/*
 * RobotMap.h
 *
 * Mapping port number with devices
 */

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

namespace RobotMap
{
	static bool isRightLeftReflection = 0;

	enum joystickAnxisChannel {X = 0, Y = 1, Z = 2, Slider = 3};
	enum joystickChannel {rotateJoystickChannel = 0, moveJoystickChannel = 1};

	enum baseMotorChannel {rightMotorChannel = 1, leftMotorChannel = 0};
	enum upperMotorChannel {ballBoosterChannel = 2, ballActuatorChannel = 3,
							gearActuatorChannel = 4, climbBoosterChannel = 5};

	enum encoderChannels {AChannel = 1, BChannel = 0};
	enum limitSwitchChannels {ballLimitChannel = 0, gearLimitChannel = 1};
	enum limitSwitchStatus {triggered = 1, free = 0};
}

#endif //ROBOTMAP_H_
