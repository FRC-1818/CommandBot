/*
 * RobotMap.cpp

 *
 *  Created on: 2017Äê2ÔÂ9ÈÕ
 *      Author: Zeming
 */
#include "RobotMap.h"
#include <Victor.h>
#include <Jaguar.h>
#include <XboxController.h>
#include <I2C.h>
#include <Servo.h>
#include <AHRS.h>

std::shared_ptr<AHRS> RobotMap::ahrs;             // navX MXP
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontRightVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackRightVictor;
std::shared_ptr<frc::RobotDrive> RobotMap::myRobot;
std::shared_ptr<frc::Victor> RobotMap::climberSubsystemClimbVictor;
std::shared_ptr<XboxController> RobotMap::joystick;
std::shared_ptr<I2C> RobotMap::i2c;
std::shared_ptr<Jaguar> RobotMap::hopperSubsystemhopperVictor;
std::shared_ptr<Victor> RobotMap::elevatorSubsystemelevatorVictor;
std::shared_ptr<Servo> RobotMap::servo;
std::shared_ptr<DigitalInput> RobotMap::upLimit;
std::shared_ptr<DigitalInput> RobotMap::downLimit;
std::shared_ptr<DigitalInput> RobotMap::switch1;
std::shared_ptr<DigitalInput> RobotMap::switch2;
std::shared_ptr<DigitalInput> RobotMap::switch3;

void RobotMap::init() {
	//i2c.reset(new frc::I2C::Port::0,54);
	ahrs.reset(new AHRS(SerialPort::kMXP));

	upLimit.reset(new frc::DigitalInput(1));
	downLimit.reset(new frc::DigitalInput(2));

	switch1.reset(new frc::DigitalInput(6));
	switch2.reset(new frc::DigitalInput(7));
	switch3.reset(new frc::DigitalInput(8));

    servo.reset(new frc::Servo(8));

	joystick.reset(new frc::XboxController(0));

	hopperSubsystemhopperVictor.reset(new frc::Jaguar(7));

	elevatorSubsystemelevatorVictor.reset(new frc::Victor(6));

	driveBaseSubsystemfrontLeftVictor.reset(new frc::Victor(frc::RobotDrive::kFrontLeftMotor));
	driveBaseSubsystemfrontRightVictor.reset(new frc::Victor(frc::RobotDrive::kFrontRightMotor));
	driveBaseSubsystembackLeftVictor.reset(new frc::Victor(frc::RobotDrive::kRearLeftMotor));
	driveBaseSubsystembackRightVictor.reset(new frc::Victor(frc::RobotDrive::kRearRightMotor));
    //printf("robotmap init drivesubsystem");

	myRobot.reset(new frc::RobotDrive(driveBaseSubsystemfrontLeftVictor,
	    		                      driveBaseSubsystembackLeftVictor,
				                      driveBaseSubsystemfrontRightVictor,
				                      driveBaseSubsystembackRightVictor));
   //printf("robotmap init myrobot");

    myRobot->SetSafetyEnabled(false);
    myRobot->SetExpiration(0.1);
    myRobot->SetSensitivity(0.5);
    myRobot->SetMaxOutput(1.0);

    myRobot->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
    myRobot->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

    climberSubsystemClimbVictor.reset(new frc::Victor(5));

    //pdp.reset(new frc::PowerDistributionPanel());
    //robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));
    //printf("finished robotmap init");

}



