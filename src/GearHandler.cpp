/*
 * GearHandler.cpp
 *
 */
#include "GearHandler.h"

//TODO 确保UpperPosition和LowerPosition不会反
void GearHandler::holdGear()
{
	setActuatorPosition(LowerPosition);
}

void GearHandler::releaseGear()
{
	setActuatorPosition(UpperPosition);
}

void GearHandler::reset()
{
	setActuatorPosition(UpperPosition);
}
