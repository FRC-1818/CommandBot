#include "DriveCommand.h"
#include "..\..\robotmap.h"

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
	adjustedYaw = Robot::drivebaseSubsystem->GetAngle();

   Robot::drivebaseSubsystem->MecanumDrive(-xAxis, -yAxis, -rotAxis, adjustedYaw );
   //xAxis->Left&Right Slides; yAxis->Forward&Backward; rotAxis->Leftturn&RightTurn
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}

