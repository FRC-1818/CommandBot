#include "AutonomousCenter.h"

AutonomousCenter::AutonomousCenter() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void AutonomousCenter::Initialize() {
	timer->Reset();
	timer->Start();
}

void AutonomousCenter::Execute() {
	if(timer->Get() < 3.0){
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	}
	else{
	Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
	}
}

bool AutonomousCenter::IsFinished() {
	return false;
}

void AutonomousCenter::End() {
	timer->Stop();
}

void AutonomousCenter::Interrupted() {
	timer->Stop();
}
