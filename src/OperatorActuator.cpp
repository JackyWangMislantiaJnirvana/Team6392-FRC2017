/*
 * OperatorActuator.cpp
 *
 */

#include "OperatorActuator.h"

OperatorActuator::OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
								   RobotMap::upperMotorChannel actuatorChannel,
								   RobotMap::limitSwitchChannel upperLimitSwitchChannel,
								   RobotMap::limitSwitchChannel lowerLimitSwitchChannel):
		booster(boosterChannel), actuator(actuatorChannel),
		upperLimitSwitch(upperLimitSwitchChannel),
		lowerLimitSwitch(lowerLimitSwitchChannel),
		currentPosition(OperatorActuator::UpperPosition),
		currentSpeed(0.0L)
{
	// empty block
}

void OperatorActuator::setBoosterSpeed(double speed)
{
	booster.Set(speed);
}

void OperatorActuator::setActuatorPosition(Position pos)
{
	if (currentPosition == pos)
		return;

	while (isReached(pos) != true)
	{
		actuator.Set(actuatorSpeed);
		frc::Wait(RobotMap::delayTime);
	}
	actuator.Set(0.0l);

	currentPosition = pos;
}
