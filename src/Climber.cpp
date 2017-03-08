/*
 * Climber.cpp
 *
 */

#include "Climber.h"

Climber::Climber():
	OperatorActuator(RobotMap::voidSwitchChannel, RobotMap::climbBoosterChannel, RobotMap::voidMotorChannel)
{

}

void Climber::startClimb()
{
	setBoosterSpeed(climbSpeed);
}

void Climber::stopClimb()
{
	setBoosterSpeed(0.0l);
}

