/*
 * Climber.cpp
 *
 */

#include "Climber.h"

void Climber::startClimb()
{
	setBoosterSpeed(climbSpeed);
	waitUntilClimbIsComplete();
	setBoosterSpeed(0.0l);
}

