#include "Climbstop.h"

Climbstop::Climbstop() {
	Requires(Robot::climberSubsystem.get());
}

void Climbstop::Initialize() {

}

void Climbstop::Execute() {
	Robot::climberSubsystem->StopClimbVictor(0.0);
}

bool Climbstop::IsFinished() {
	return false;
}

void Climbstop::End() {

}

void Climbstop::Interrupted() {

}
