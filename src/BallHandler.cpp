/*
 * BallHandler.cpp
 *
 */

#include "BallHandler.h"

BallHandler::BallHandler(RobotMap::limitSwitchChannel limitSwitchChannel,
						 RobotMap::upperMotorChannel boosterChannel,
						 RobotMap::upperMotorChannel actuatorChannel):
			// Call the constructor of its parent class.
			// 备忘:constructor不会被继承!不会被继承！不会！
			OperatorActuator(limitSwitchChannel, boosterChannel, actuatorChannel)
{

}

void BallHandler::intake()
{
	setBoosterSpeed(ballBoosterSpeed);
	waitUntilSpeedIsEnough();
	setActuatorPosition(OperatorActuator::LowerPosition);
}

void BallHandler::output()
{
	setBoosterSpeed(-ballBoosterSpeed);
	waitUntilSpeedIsEnough();
	setActuatorPosition(OperatorActuator::UpperPosition);
}
