#include "Climbdown.h"

Climbdown::Climbdown() {
	Requires(Robot::climberSubsystem.get());
}

void Climbdown::Initialize() {

}

void Climbdown::Execute() {
	Robot::climberSubsystem->ReverseClimbVictor(0.5);
}

bool Climbdown::IsFinished() {
	return false;
}

void Climbdown::End() {

}

void Climbdown::Interrupted() {

}
