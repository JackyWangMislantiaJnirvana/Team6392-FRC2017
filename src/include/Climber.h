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
	const float climbSpeed = 1.0l;
public:
	Climber();

	void startClimb();
	void stopClimb();
};

#endif /* CLIMBER_H_ */
