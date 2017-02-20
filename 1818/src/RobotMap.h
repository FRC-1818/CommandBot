#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Victor.h>
#include <XboxController.h>
#include <I2C.h>
#include <Servo.h>
#include <Jaguar.h>
#include <DigitalInput.h>
#include <AHRS.h>

class RobotMap{
public:
	static void init();
	static std::shared_ptr<AHRS> ahrs;             // navX MXP
	static std::shared_ptr<Victor> driveBaseSubsystemfrontLeftVictor;
	static std::shared_ptr<Victor> driveBaseSubsystemfrontRightVictor;
	static std::shared_ptr<Victor> driveBaseSubsystembackLeftVictor;
	static std::shared_ptr<Victor> driveBaseSubsystembackRightVictor;
	static std::shared_ptr<RobotDrive> myRobot;
	static std::shared_ptr<Victor> climberSubsystemClimbVictor;
	static std::shared_ptr<XboxController> joystick;
	static std::shared_ptr<Jaguar> hopperSubsystemhopperVictor;
	static std::shared_ptr<Victor> elevatorSubsystemelevatorVictor;
	static std::shared_ptr<I2C> i2c;
	static std::shared_ptr<Servo> servo;
	static std::shared_ptr<DigitalInput> upLimit;
	static std::shared_ptr<DigitalInput> downLimit;
	static std::shared_ptr<DigitalInput> switch1;
	static std::shared_ptr<DigitalInput> switch2;
	static std::shared_ptr<DigitalInput> switch3;

};


#endif  // ROBOTMAP_H
