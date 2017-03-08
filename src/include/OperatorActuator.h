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
#include <VictorSP.h>
#include <RobotMap.h>

class OperatorActuator
{
public:
	enum Position {UpperPosition = 0, LowerPosition = 1};

	OperatorActuator(RobotMap::limitSwitchChannel limitSwitchChannel,
			 	 	 RobotMap::upperMotorChannel boosterChannel,
					 RobotMap::upperMotorChannel actuatorChannel);

	void setBoosterSpeed(double speed);
	void setActuatorPosition(Position pos);
	void switchActuatorPosition();

private:
	frc::VictorSP booster, actuator;
	frc::DigitalInput limitSwitch;

	const double actuatorSpeed = 0.1l;

	double currentSpeed;
	Position currentPosition;

	bool isReached()
	{
		switch (limitSwitch.Get())
		{
		case RobotMap::kTriggered:
			return true;
			break;
		case RobotMap::kFree:
			return false;
			break;
		}
	}

	double getSpeed()
	{
		return currentSpeed;
	}

	Position getPosition()
	{
		return currentPosition;
	}

};

#endif /* OPERATORACTUATOR_H_ */
