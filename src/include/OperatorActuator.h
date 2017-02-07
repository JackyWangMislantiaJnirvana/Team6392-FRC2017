/*
 * OperatorActuator.h
 *
 *  Created on: 2017Äê2ÔÂ7ÈÕ
 *      Author: Jacky Wang
 */

#ifndef OPERATORACTUATOR_H_
#define OPERATORACTUATOR_H_

#include <PIDController.h>
#include <DigitalInput.h>
#include <Spark.h>

class OperatorActuator
{
private:
	frc::Spark booster, actuator;
	frc::DigitalInput limitSwitch;

	enum Position {UpperPosition, LowerPosition};

	Position currentPosition;
	double currentSpeed;

	void setSpeed(double speed);
	double getSpeed();
	void setPosition(Position pos);
	Position getPosition();
public:
	OperatorActuator(RobotMap::upperMotorChannel boosterChannel, RobotMap::upperMotorChannel actuatorChannel);
};



#endif /* OPERATORACTUATOR_H_ */
