/*
 * BallHandler.cpp
 *
 */

#include "BallHandler.h"

void BallHandler::intake()
{
	setBoosterSpeed(ballBoosterSpeed);
	waitUntilSpeedIsEnough();
	setActuatorPosition(OperatorActuator::LowerPosition);
}

void BallHandler::output()
{

}
