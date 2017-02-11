#include "Climbdown.h"

Climbdown::Climbdown() {

}

void Climbdown::Initialize() {

}

void Climbdown::Execute() {
	Robot::climberSubsystem->ReverseClimbVictor();
}

bool Climbdown::IsFinished() {
	return false;
}

void Climbdown::End() {

}

void Climbdown::Interrupted() {

}
