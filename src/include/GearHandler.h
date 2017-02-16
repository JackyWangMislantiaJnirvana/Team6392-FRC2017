/*
 * GearHandler.h
 *
 */

#ifndef GEARHANDLER_H_
#define GEARHANDLER_H_

#include "OperatorActuator.h"

class GearHandler : OperatorActuator
{
public:
	void releaseGear();
	void holdGear();
	void reset();
private:
	const double gearActuatorSpeed = 0.1l;
};

#endif /* GEARHANDLER_H_ */
