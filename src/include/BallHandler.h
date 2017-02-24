/*
 * BallHandler.h
 *
 */

#ifndef BALLHANDLER_H_
#define BALLHANDLER_H_

#include "OperatorActuator.h"

//EXP
class BallHandler : public OperatorActuator
{
public:
	BallHandler(RobotMap::limitSwitchChannel limitSwitchChannel,
				RobotMap::upperMotorChannel boosterChannel,
				RobotMap::upperMotorChannel actuatorChannel);
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
