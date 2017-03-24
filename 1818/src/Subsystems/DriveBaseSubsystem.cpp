#include "DriveBaseSubsystem.h"
#include "../RobotMap.h"

DriveBaseSubsystem::DriveBaseSubsystem() : Subsystem("DriveBaseSubsystem") {
	printf("start drive\n");
	frontLeftVictor = RobotMap::driveBaseSubsystemfrontLeftVictor;
	printf("frontleft\n");
	frontRightVictor = RobotMap::driveBaseSubsystemfrontRightVictor;
	printf("frontright\n");
	backLeftVictor = RobotMap::driveBaseSubsystembackLeftVictor;
	printf("backleft\n");
	backRightVictor = RobotMap::driveBaseSubsystembackRightVictor;
	printf("backright\n");
	robotDrive = RobotMap::myRobot;
	printf("finish drive\n");
}

void DriveBaseSubsystem::InitDefaultCommand() {

}

void DriveBaseSubsystem::MecanumDrive(float x, float y, float rot, float gyro){
	robotDrive->MecanumDrive_Cartesian(x,y,rot,gyro);
}


