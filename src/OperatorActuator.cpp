/*
 * OperatorActuator.cpp
 *
 */

#include "OperatorActuator.h"

OperatorActuator::OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
									RobotMap::upperMotorChannel actuatorChannel):
		booster(boosterChannel), actuator(actuatorChannel), limitSwitch(0),
		currentPosition(OperatorActuator::UpperPosition), currentSpeed(0.0L)
{
	// empty block
}

void OperatorActuator::setBoosterSpeed(double speed)
{
	booster.Set(speed);
}

void OperatorActuator::setActuatorPosition(Position pos)
{
	while (isReached() != true)
	{
		actuator.Set(actuatorSpeed);
		frc::Wait(RobotMap::delayTime);
	}

	actuator.Set(0.0l);
}
