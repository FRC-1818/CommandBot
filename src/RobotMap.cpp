#include "RobotMap.h"

std::shared_ptr<Victor> RobotMap::driveBaseSubsystemfrontLeftVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystemfrontRightVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystembackLeftVictor;
std::shared_ptr<Victor> RobotMap::driveBaseSubsystembackRightVictor;
std::shared_ptr<frc::RobotDrive> RobotMap::myRobot;
std::shared_ptr<Victor> RobotMap::climberSubsystemClimbVictor;
//std::shared_ptr<Servo> RobotMap::myServo;


void RobotMap::init() {

	//myServo.reset(new frc::Servo(servoSubsystemServo));

    driveBaseSubsystemfrontLeftVictor.reset(new Victor(frc::RobotDrive::kFrontLeftMotor));

    driveBaseSubsystemfrontRightVictor.reset(new Victor(frc::RobotDrive::kFrontRightMotor));

    driveBaseSubsystembackLeftVictor.reset(new Victor(frc::RobotDrive::kRearLeftMotor));

    driveBaseSubsystembackRightVictor.reset(new Victor(frc::RobotDrive::kRearRightMotor));

    myRobot.reset(new frc::RobotDrive(driveBaseSubsystemfrontLeftVictor,
    		                          driveBaseSubsystembackLeftVictor,
			                          driveBaseSubsystemfrontRightVictor,
			                          driveBaseSubsystembackRightVictor));

    myRobot->SetSafetyEnabled(false);

    myRobot->SetExpiration(0.1);

    myRobot->SetSensitivity(0.5);

    myRobot->SetMaxOutput(1.0);

    myRobot->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);

    myRobot->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);


    climberSubsystemClimbVictor.reset(new Victor(5));

    //pdp.reset(new frc::PowerDistributionPanel());

    //robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));

    //tigerDrive.reset(new TigerDrive(robotIMU.get()));

}







