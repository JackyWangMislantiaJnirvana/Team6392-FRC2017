/*
 * OperatorActuator.cpp
 *
 */

#include "OperatorActuator.h"

OperatorActuator::OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
									RobotMap::upperMotorChannel actuatorChannel):
		booster(boosterChannel), actuator(actuatorChannel), limitSwitch(0),
		currentPosition(OperatorActuator::UpperPosition), currentSpeed(0.0L)
{}

void OperatorActuator::setSpeed(double speed)
{
	// TODO finish setSpeed
}

double OperatorActuator::getSpeed()
{
	return currentSpeed;
}

void OperatorActuator::setPosition(Position pos)
{
	// TODO finish setPos
}

OperatorActuator::Position OperatorActuator::getPosition()
{
	return currentPosition;
}
