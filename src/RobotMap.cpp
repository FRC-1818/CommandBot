/*
 * RobotMap.cpp

 *
 *  Created on: 2017Äê2ÔÂ9ÈÕ
 *      Author: Zeming
 */
#include "RobotMap.h"
#include <Victor.h>
#include <XboxController.h>
#include <I2C.h>

std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystemfrontRightVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackLeftVictor;
std::shared_ptr<frc::Victor> RobotMap::driveBaseSubsystembackRightVictor;
std::shared_ptr<frc::RobotDrive> RobotMap::myRobot;
std::shared_ptr<frc::Victor> RobotMap::climberSubsystemClimbVictor;
std::shared_ptr<XboxController> RobotMap::joystick;
std::shared_ptr<I2C> RobotMap::i2c;
std::shared_ptr<Victor> RobotMap::hopperSubsystemhopperVictor;
void RobotMap::init() {
	//i2c.reset(new frc::I2C*I2C);
printf("started robotmap init");
	joystick.reset(new frc::XboxController(0));

	hopperSubsystemhopperVictor.reset(new frc::Victor(7));


	driveBaseSubsystemfrontLeftVictor.reset(new frc::Victor(frc::RobotDrive::kFrontLeftMotor));

	driveBaseSubsystemfrontRightVictor.reset(new frc::Victor(frc::RobotDrive::kFrontRightMotor));

	driveBaseSubsystembackLeftVictor.reset(new frc::Victor(frc::RobotDrive::kRearLeftMotor));

	driveBaseSubsystembackRightVictor.reset(new frc::Victor(frc::RobotDrive::kRearRightMotor));
    printf("robotmap init drivesubsystem");

	myRobot.reset(new frc::RobotDrive(driveBaseSubsystemfrontLeftVictor,
	    		                      driveBaseSubsystembackLeftVictor,
				                      driveBaseSubsystemfrontRightVictor,
				                      driveBaseSubsystembackRightVictor));
    printf("robotmap init myrobot");

    myRobot->SetSafetyEnabled(false);

    myRobot->SetExpiration(0.1);

    myRobot->SetSensitivity(0.5);

    myRobot->SetMaxOutput(1.0);

    myRobot->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);

    myRobot->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

    climberSubsystemClimbVictor.reset(new frc::Victor(5));

    //pdp.reset(new frc::PowerDistributionPanel());

    //robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    //tigerDrive.reset(new TigerDrive(robotIMU.get()));
    printf("finished robotmap init");

}



