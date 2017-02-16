/*
 * Climber.h
 *
 */

#ifndef CLIMBER_H_
#define CLIMBER_H_

#include "OperatorActuator.h"

class Climber : OperatorActuator
{
private:
	const float climbSpeed = 0.0l;
	const float climbTime = 0.0l;
public:
	void startClimb();
	void waitUntilClimbIsComplete()
	{
		frc::Wait(climbTime);
	}
};

#endif /* CLIMBER_H_ */
