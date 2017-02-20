#include "Climbdown.h"

Climbdown::Climbdown() {
	Requires(Robot::climberSubsystem.get());
}

void Climbdown::Initialize() {

}

void Climbdown::Execute() {
	 Robot::climberSubsystem->RunClimbVictor(0.5);
}

bool Climbdown::IsFinished() {
	//return false;
	return false;
}

void Climbdown::End() {
	Robot::climberSubsystem->RunClimbVictor(0.0);
}

void Climbdown::Interrupted() {
	Robot::climberSubsystem->RunClimbVictor(0.0);
}
