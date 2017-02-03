/*
 * RobotMap.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Joseph
 */

#include "RobotMap.h"


std::shared_ptr<Victor> RobotMap::driveBaseSubsystemFrontLeftVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystemFrontRightVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystemBackLeftVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystemBackRightVictor;

std::shared_ptr<frc::RobotDrive> RobotMap::myRobot;





void RobotMap::init() {

    driveBaseSubsystemFrontLeftVictor.reset(new Victor(1));
    driveBaseSubsystemFrontRightVictor.reset(new Victor(2));
    driveBaseSubsystemBackLeftVictor.reset(new Victor(3));
    driveBaseSubsystemBackRightVictor.reset(new Victor(4));
    myRobot.reset(new frc::RobotDrive(driveBaseSubsystemFrontLeftVictor, driveBaseSubsystemBackLeftVictor, driveBaseSubsystemFrontRightVictor, driveBaseSubsystemBackRightVictor));



    myRobot->SetSafetyEnabled(false);

    myRobot->SetExpiration(0.1);

    myRobot->SetSensitivity(0.5);

    myRobot->SetMaxOutput(1.0);



    myRobot->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);

    myRobot->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);












    //pdp.reset(new frc::PowerDistributionPanel());



    //robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    //tigerDrive.reset(new TigerDrive(robotIMU.get()));

}


