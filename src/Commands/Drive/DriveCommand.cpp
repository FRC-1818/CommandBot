#include "DriveCommand.h"

DriveCommand::DriveCommand() {
	Requires(Robot::drivebaseSubsystem.get());
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	adjustedYaw = 0;
}

void DriveCommand::Initialize() {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	adjustedYaw = 0;
}

void DriveCommand::Execute() {
	xAxis = Robot::oi->GetLeftXAxisDriver();
	yAxis = Robot::oi->GetLeftYAxisDriver();
	rotAxis = Robot::oi->GetRightXAxisDriver();
	adjustedYaw = 0;

	//Robot::drivebaseSubsystem->MecanumDrive(Robot::oi->GetLeftXAxisDriver(),
	                                        //Robot::oi->GetLeftYAxisDriver(),
	                                        //Robot::oi->GetRightXAxisDriver(), 0);
   Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, rotAxis, adjustedYaw);
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}

