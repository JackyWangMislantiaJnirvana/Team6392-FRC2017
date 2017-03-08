/*
 * BallHandler.h
 *
 */

#ifndef BALLHANDLER_H_
#define BALLHANDLER_H_

#include "OperatorActuator.h"

class BallHandler : public OperatorActuator
{
public:
	BallHandler();

	void setBallBoosterPower(double power);
	void changeBallActuatorPosition();

private:
	const double ballHandlerWaitTime = 0.2l;
	const double ballBoosterSpeed = 1.0l;

	void toIntakePosition();
	void toOutputPosition();
};

#endif /* BALLHANDLER_H_ */
