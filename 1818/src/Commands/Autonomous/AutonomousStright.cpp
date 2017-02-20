#include "AutonomousStright.h"

AutonomousStright::AutonomousStright() {
	Requires(Robot::drivebaseSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

// Called just before this Command runs the first time
void AutonomousStright::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousStright::Execute() {
	if(timer->Get() < 4.0){
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.5, 0.0, 0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousStright::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutonomousStright::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousStright::Interrupted() {
	timer->Stop();
}
