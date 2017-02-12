#include "DriveForward.h"

DriveForward::DriveForward() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void DriveForward::Initialize() {
	timer->Reset();
	timer->Start();
}

void DriveForward::Execute() {
	if(timer->Get() < 3.0)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
}

bool DriveForward::IsFinished() {
	return false;
}

void DriveForward::End() {
	timer->Stop();
}

void DriveForward::Interrupted() {

}
