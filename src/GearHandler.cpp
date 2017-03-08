/*
 * GearHandler.cpp
 *
 */
#include "GearHandler.h"

GearHandler::GearHandler():
	OperatorActuator(RobotMap::gearLimitSwitchChannel, RobotMap::gearActuatorChannel, RobotMap::voidMotorChannel)
{

}

//TODO 确保UpperPosition和LowerPosition不会反
void GearHandler::toReciveGearPosition()
{
	setActuatorPosition(LowerPosition);
}

void GearHandler::toReleaseGearPosition()
{
	setActuatorPosition(UpperPosition);
}

void GearHandler::changeGearActuatorPosition()
{
	switchActuatorPosition();
}
