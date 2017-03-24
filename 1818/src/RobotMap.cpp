/*
 * RobotMap.cpp

 *
 *  Created on: 2017Äê2ÔÂ9ÈÕ
 *      Author: Zeming
 */
#include "RobotMap.h"
#include <Victor.h>
#include <Jaguar.h>
#include <I2C.h>
#include <Servo.h>
#include <RobotDrive.h>

std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontRightVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackRightVictor;
std::shared_ptr<frc::RobotDrive> RobotMap::myRobot;
std::shared_ptr<frc::Victor> RobotMap::climberSubsystemClimbVictor;
std::shared_ptr<I2C> RobotMap::i2c;
std::shared_ptr<Jaguar> RobotMap::hopperSubsystemhopperVictor;
std::shared_ptr<Victor> RobotMap::elevatorSubsystemelevatorVictor;
std::shared_ptr<Servo> RobotMap::servo;

void RobotMap::init() {
	//i2c.reset(new frc::I2C::Port::0,54);
	printf("start\n");
    servo.reset(new frc::Servo(8));
    printf("servo\n");
	hopperSubsystemhopperVictor.reset(new frc::Jaguar(7));
	printf("hopper\n");
	elevatorSubsystemelevatorVictor.reset(new frc::Victor(6));
	printf("elevator\n");
	climberSubsystemClimbVictor.reset(new frc::Victor(5));
	printf("climb\n");
	driveBaseSubsystemfrontLeftVictor.reset(new frc::Victor(frc::RobotDrive::kFrontLeftMotor));
	printf("a\n");
	driveBaseSubsystemfrontRightVictor.reset(new frc::Victor(frc::RobotDrive::kFrontRightMotor));
	printf("b\n");
	driveBaseSubsystembackLeftVictor.reset(new frc::Victor(frc::RobotDrive::kRearLeftMotor));
	printf("c\n");
	driveBaseSubsystembackRightVictor.reset(new frc::Victor(frc::RobotDrive::kRearRightMotor));
	printf("d\n");

	myRobot.reset(new frc::RobotDrive(driveBaseSubsystemfrontLeftVictor,
	    		                      driveBaseSubsystembackLeftVictor,
				                      driveBaseSubsystemfrontRightVictor,
				                      driveBaseSubsystembackRightVictor));
	printf("e\n");
    myRobot->SetSafetyEnabled(false);
    printf("f\n");

    myRobot->SetExpiration(0.1);
    printf("g\n");
    myRobot->SetSensitivity(0.5);
    printf("h\n");

    myRobot->SetMaxOutput(1.0);
    printf("i\n");
    //myRobot->SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, true);
    printf("j\n");
   myRobot->SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, true);
    printf("k\n");


    //pdp.reset(new frc::PowerDistributionPanel());

    //robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    //printf("finished robotmap init");

}



