#include "DriveStationtoPeg2.h"

DriveStationtoPeg2::DriveStationtoPeg2() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void DriveStationtoPeg2::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveStationtoPeg2::Execute() {
	if(timer->Get() < 2.35)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	if(timer->Get() > 2.35 && timer->Get() < 3.25)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, -0.5, 0.0);
	if(timer->Get() > 3.25 && timer->Get() < 3.90 )
	Robot::drivebaseSubsystem->MecanumDrive(0.5, 0.0, 0.0, 0.0);
}

bool DriveStationtoPeg2::IsFinished() {
	return false;
}

void DriveStationtoPeg2::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStationtoPeg2::Interrupted() {

}
