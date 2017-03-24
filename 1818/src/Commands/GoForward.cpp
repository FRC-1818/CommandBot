#include "GoForward.h"

GoForward::GoForward() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

// Called just before this Command runs the first time
void GoForward::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void GoForward::Execute() {
	if(timer->Get() < 1.5)
		Robot::drivebaseSubsystem->MecanumDrive(0.5, 0.0, 0.0, 0.0);
	else{
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GoForward::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoForward::Interrupted() {
	timer->Stop();
}
