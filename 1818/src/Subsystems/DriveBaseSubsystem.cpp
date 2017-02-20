#include "DriveBaseSubsystem.h"
#include "../RobotMap.h"

DriveBaseSubsystem::DriveBaseSubsystem() : Subsystem("DriveBaseSubsystem") {
	frontLeftVictor = RobotMap::driveBaseSubsystemfrontLeftVictor;
	frontRightVictor = RobotMap::driveBaseSubsystemfrontRightVictor;
	backLeftVictor = RobotMap::driveBaseSubsystembackLeftVictor;
	backRightVictor = RobotMap::driveBaseSubsystembackRightVictor;
	robotDrive = RobotMap::myRobot;
	adjustedYaw = RobotMap::ahrs;
}

void DriveBaseSubsystem::InitDefaultCommand() {

}

void DriveBaseSubsystem::MecanumDrive(float x, float y, float rot, float gyro){
	robotDrive->MecanumDrive_Cartesian(x,y,rot,gyro);
}

double DriveBaseSubsystem::GetAngle()
{
	return adjustedYaw->GetAngle();
}
