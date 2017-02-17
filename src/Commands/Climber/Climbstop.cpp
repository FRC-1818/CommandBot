#include "Climbstop.h"

Climbstop::Climbstop() {
	Requires(Robot::climberSubsystem.get());
}

void Climbstop::Initialize() {

}

void Climbstop::Execute() {
	 Robot::climberSubsystem->RunClimbVictor(0.0);
}

bool Climbstop::IsFinished() {
	return false;
}

void Climbstop::End() {
	 Robot::climberSubsystem->RunClimbVictor(0.0);
}

void Climbstop::Interrupted() {
	 Robot::climberSubsystem->RunClimbVictor(0.0);
}
