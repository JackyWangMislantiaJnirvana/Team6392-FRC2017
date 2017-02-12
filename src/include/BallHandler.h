/*
 * BallHandler.h
 *
 */

#ifndef BALLHANDLER_H_
#define BALLHANDLER_H_

#include "OperatorActuator.h"

class BallHandler : OperatorActuator
{
public:
	void intake();
	void output();

private:
	const double ballHandlerWaitTime = 0.2l;
	const double ballBoosterSpeed = 1.0l;

	void waitUntilSpeedIsEnough()
	{
		frc::Wait(ballHandlerWaitTime);
	}
};

#endif /* BALLHANDLER_H_ */
