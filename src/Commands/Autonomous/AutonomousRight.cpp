#include "AutonomousRight.h"

AutonomousRight::AutonomousRight() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void AutonomousRight::Initialize() {
	timer->Reset();
	timer->Start();
}

void AutonomousRight::Execute() {
	if(timer->Get() < 2.35)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	if(timer->Get() > 2.35 && timer->Get() < 3.25)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.5, 0.0);
	if(timer->Get() > 3.25 && timer->Get() < 3.90 )
	Robot::drivebaseSubsystem->MecanumDrive(-0.5, 0.0, 0.0, 0.0);
}

bool AutonomousRight::IsFinished() {
	return false;
}

void AutonomousRight::End() {
	timer->Stop();
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
}

void AutonomousRight::Interrupted() {
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
}
