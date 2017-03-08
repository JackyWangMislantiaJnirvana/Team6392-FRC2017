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
	GearHandler();

	void changeGearActuatorPosition();

private:
	const double gearActuatorSpeed = 0.1l;

	void toReleaseGearPosition();
	void toReciveGearPosition();
};

#endif /* GEARHANDLER_H_ */
