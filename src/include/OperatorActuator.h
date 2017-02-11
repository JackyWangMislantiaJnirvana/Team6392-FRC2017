/*
 * OperatorActuator.h -- 动作执行器基类
 *
 * 被收发球类，收放齿轮类，攀爬类继承
 */

#ifndef OPERATORACTUATOR_H_
#define OPERATORACTUATOR_H_

#include <PIDController.h>
#include <DigitalInput.h>
#include <Spark.h>
#include <RobotMap.h>

class OperatorActuator
{
private:
	frc::Spark booster, actuator;
	frc::DigitalInput limitSwitch;

	enum Position {UpperPosition = 0, LowerPosition = 1};
	const double actuatorSpeed = 0.1l;

	Position currentPosition;
	double currentSpeed;

	void setBoosterSpeed(double speed);
	void setActuatorPosition(Position pos);

	bool isReached()
	{
		return limitSwitch.Get();
	}

	double getSpeed()
	{
		return currentSpeed;
	}

	Position getPosition()
	{
		return currentPosition;
	}

public:
	OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
					 RobotMap::upperMotorChannel actuatorChannel);
};

#endif /* OPERATORACTUATOR_H_ */
