#include "DriveCommand.h"

DriveCommand::DriveCommand() {
	Requires(Robot::drivebaseSubsystem.get());
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	setSpeed = 1;
	adjustedYaw = 0;
	//finalAutoRot = 0;
}

void DriveCommand::Initialize() {
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	setSpeed = 1;
	adjustedYaw = 0;
	//finalAutoRot = 0;
}

void DriveCommand::Execute() {
	xAxis = Robot::oi->GetLeftXAxisDriver();
	yAxis = Robot::oi->GetLeftYAxisDriver();
	rotAxis = Robot::oi->GetRightXAxisDriver();
	adjustedYaw = 0;

	Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, rotAxis, adjustedYaw);
	//Robot::drivebaseSubsystem->MecanumDrive(Robot::oi->GetLeftXAxisDriver(), Robot::oi->GetLeftYAxisDriver(), Robot::oi->GetRightXAxisDriver(),adjustedYaw);
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}

/*void DriveCommand::CallToMecanumDrive() {
	if(rotAxis == 0)
	{
		Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, finalAutoRot, adjustedYaw);
	}
	else
	{
		Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, rotAxis,adjustedYaw);
	}
}
*/
