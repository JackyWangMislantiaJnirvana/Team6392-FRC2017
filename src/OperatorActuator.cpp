/*
 * OperatorActuator.cpp
 *
 */

#include "OperatorActuator.h"

OperatorActuator::OperatorActuator(RobotMap::limitSwitchChannel limitSwitchChannel,
								   RobotMap::upperMotorChannel actuatorChannel,
								   RobotMap::upperMotorChannel boosterChannel):
		booster(boosterChannel), actuator(actuatorChannel),
		limitSwitch(limitSwitchChannel),
		currentSpeed(0.0L),
		currentPosition(OperatorActuator::UpperPosition)
{
	// empty block
}

void OperatorActuator::setBoosterSpeed(double speed)
{
	booster.Set(speed);
}

void OperatorActuator::setActuatorPosition(Position pos)
{
	int counter = 0;
	if (currentPosition == pos)
		return;

	while (isReached() != true)
	{
		actuator.Set(actuatorSpeed);
		frc::Wait(RobotMap::delayTime);
		actuator.Set(0.0l);
		counter++;
		if (counter >= 100)
			break;
	}

	currentPosition = pos;
}

void OperatorActuator::switchActuatorPosition()
{
	// 将位置设为与当前位置相反另一个位置，同时更新当前位置
	setActuatorPosition(currentPosition = (Position)!currentPosition);
}
