#include "AutonomousLeft.h"

AutonomousLeft::AutonomousLeft() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void AutonomousLeft::Initialize() {
	timer->Reset();
	timer->Start();
}

void AutonomousLeft::Execute() {
	if(timer->Get() < 2.35)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	if(timer->Get() > 2.35 && timer->Get() < 3.25)
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, -0.5, 0.0);
	if(timer->Get() > 3.25 && timer->Get() < 3.90 )
	Robot::drivebaseSubsystem->MecanumDrive(0.5, 0.0, 0.0, 0.0);
}

bool AutonomousLeft::IsFinished() {
	return false;
}

void AutonomousLeft::End() {
	timer->Stop();
	//Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
}

void AutonomousLeft::Interrupted() {
	timer->Stop();
	//Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
}
