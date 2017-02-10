/*Driver.h --- 自动和遥控驾驶
 *
 * Realized by Driver.cpp
 * Use UTF-8 to view this file, in order to show Chinese properly.
 * */

// Include Protection: DRIVER_H_
#ifndef DRIVER_H_
#define DRIVER_H_

#include <iostream>

#include "AHRS.h"
#include <Spark.h>
#include "PIDController.h"

#include "RobotMap.h"

/* 提示：
 * 		为何Driver类要继承PIDOutput类？
 * -----------------------------------------------------------------------------
 * 	为了自定义如何处理PID运算结果
 *
 * PIDController类的构造函数原型:
 * 	PIDController(double kP, double kI, double kD, PIDSource* input, PIDOutput* output)
 * 它的最后一个参数的类型是PIDOutput
 * PIDController类型的对象工作的时候会调用那个PIDOutput对象的PIDWrite()方法，
 * 把PID算法的计算结果作为参数递给这个方法
 * 所以让使用PID的类继承PIDOutput类能让它作为PIDOutput类型的对象递给PIDOutput，
 * (因为继承了某个类意味着具有了某个类的“特点”。)
 * (从语法上讲，一个对象可以被强制类型转换成它的父类)
 * 然后用重写PIDWrite方法，拿着计算结果想干嘛干嘛 XD
 * 最后初始化PIDController的时候只用这样做：
 * 	PIDController controller = new PIDController(kP, kI, kD, 传感器对象, this);
*/
class Driver final : public frc::PIDOutput
{
private:
	const double kDriveGain = 0.7;
	const double Pi = 3.1415;
	const int SamplesToAverage = 5;
	const double DistancePerPulse = (1.0 / 360.0) * 2.0 * Pi * 1.5;
	const double MinRate = 1.0;

	double kTurnPGain = 0;
	double kTurnIGain = 0;
	double kTurnDGain = 0;
	const double kPIDInputMax = 180.0l;
	const double kPIDInputMin = -180.0l;
	const double kPIDOutputMax = 1.0l;
	const double kPIDOutputMin = -1.0l;
	const double kToleranceDegrees = 2.0l;

	// No longer used. See help message above the class for why.
	// A motor which doesn't exist, used to cheat PIDController as the output of PID control.
	// The real output will be gotten from PIDController Class directly.
//	frc::Spark voidMotor;

	frc::Spark leftBaseMotor;
	frc::Spark rightBaseMotor;
	frc::Encoder baseEncoder;
	AHRS *navigator;
	frc::PIDController *turnController;

	double turnPIDControllerOutput;

public:
	enum direction {turnAntiClockwise = 0, turnClockwise = 1, forward = 2, back = 3};

	//Driver(RobotMap::baseMotorChannel leftMotor, RobotMap::baseMotorChannel rightMotor);
	Driver(RobotMap::baseMotorChannel leftMotor, RobotMap::baseMotorChannel rightMotor);
	~Driver();
	void OperatorDrive(frc::Joystick *rotateJoystick, frc::Joystick *moveJoystick);
	void autoMove(direction direct, double distance);
	void autoTurn(direction direct, double angle);

	// Inherited from PIDOutput
	void PIDWrite(double output) final;

	void initTestMode(frc::LiveWindow *livewindow);
};

#endif // DRIVER_H_
