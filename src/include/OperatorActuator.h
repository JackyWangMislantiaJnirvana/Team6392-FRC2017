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

	OperatorActuator(RobotMap::upperMotorChannel boosterChannel,
					 RobotMap::upperMotorChannel actuatorChannel,
					 RobotMap::limitSwitchChannel upperLimitSwitchChannel,
					 RobotMap::limitSwitchChannel lowerLimitSwitchChannel);

	void setBoosterSpeed(double speed);
	void setActuatorPosition(Position pos);

private:
	frc::VictorSP booster, actuator;
	frc::DigitalInput upperLimitSwitch, lowerLimitSwitch;

	const double actuatorSpeed = 0.1l;

	Position currentPosition;
	double currentSpeed;

	bool isReached(Position pos)
	{
		//TESTME Check Me: 没有break有没有事？
		switch (pos)
		{
		case UpperPosition:
			return upperLimitSwitch.Get();
		case LowerPosition:
			return lowerLimitSwitch.Get();
		default:
			return false;
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
