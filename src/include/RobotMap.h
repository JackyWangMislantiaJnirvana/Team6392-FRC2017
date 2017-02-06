/*
 * RobotMap.h
 *
 * Mapping port number with devices
 */

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

namespace RobotMap
{
	static bool isRightLeftReflection = 1;

	enum joystickAnxisChannel {X = 0, Y = 1, Z = 2, Slider = 3};
	enum joystickChannel {rotateJoystickChannel = 1, moveJoystickChannel = 0};

	enum baseMotorChannel {rightMotorChannel = 0, leftMotorChannel = 1};
	enum upperMotorChannel {ballBooster = 2, ballActuator = 3, gearActuator = 4, climbBooster = 5};

	enum encoderChannels {AChannel = 1, BChannel = 0};
}

#endif //ROBOTMAP_H_
