#include "DriveStationtoPeg3.h"

DriveStationtoPeg3::DriveStationtoPeg3() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Start();
	timer->Reset();
}

void DriveStationtoPeg3::Initialize() {
	timer->Reset();
	timer->Start();
}

void DriveStationtoPeg3::Execute() {
	if(timer->Get() < 2.35)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	if(timer->Get() > 2.35 && timer->Get() < 3.25)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.5, 0.0);
	if(timer->Get() > 3.25 && timer->Get() < 3.90 )
	Robot::drivebaseSubsystem->MecanumDrive(-0.5, 0.0, 0.0, 0.0);
}

bool DriveStationtoPeg3::IsFinished() {
	return false;
}

void DriveStationtoPeg3::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStationtoPeg3::Interrupted() {

}
