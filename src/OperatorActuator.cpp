/*
 * OperatorActuator.cpp
 *
 */

#include "OperatorActuator.h"

OperatorActuator::OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
									RobotMap::upperMotorChannel actuatorChannel):
		booster(boosterChannel),actuator(actuatorChannel),
		currentSpeed(0.0L), currentPosition(OperatorActuator::UpperPosition)
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
