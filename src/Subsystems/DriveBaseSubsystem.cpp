#include "DriveBaseSubsystem.h"
#include "../RobotMap.h"

DriveBaseSubsystem::DriveBaseSubsystem() : Subsystem("DriveBaseSubsystem") {
	frontLeftVictor = RobotMap::driveBaseSubsystemfrontLeftVictor;
	frontRightVictor = RobotMap::driveBaseSubsystemfrontRightVictor;
	backLeftVictor = RobotMap::driveBaseSubsystembackLeftVictor;
	backRightVictor = RobotMap::driveBaseSubsystembackRightVictor;
	robotDrive = RobotMap::myRobot;
}

void DriveBaseSubsystem::InitDefaultCommand() {

}

void DriveBaseSubsystem::MecanumDrive(double x, double y, double rot, double gyro){
	robotDrive->MecanumDrive_Cartesian(x,y,rot,gyro);
}

//void DriveBaseSubsystem::MecanumDrive(frc::XboxController*joystick){
	//robotDrive->MecanumDrive_Cartesian(joystick->GetRawAxis(0),joystick->GetRawAxis(1),joystick->GetRawAxis(4), 0);
//}
