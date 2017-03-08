/*
 * BallHandler.cpp
 *
 */

#include "BallHandler.h"

BallHandler::BallHandler():
			// Call the constructor of its parent class.
			// 备忘:constructor不会被继承!不会被继承！不会！
			OperatorActuator(RobotMap::ballLimitSwitchChannel, RobotMap::ballBoosterChannel, RobotMap::ballActuatorChannel)
{
}

void BallHandler::setBallBoosterPower(double power)
{
	setBoosterSpeed(power);
}

void BallHandler::toIntakePosition()
{
	setActuatorPosition(OperatorActuator::LowerPosition);
}

void BallHandler::toOutputPosition()
{
	setActuatorPosition(OperatorActuator::UpperPosition);
}

void BallHandler::changeBallActuatorPosition()
{
	switchActuatorPosition();
}
