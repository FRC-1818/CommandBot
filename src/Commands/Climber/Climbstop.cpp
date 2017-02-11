#include "Climbstop.h"

Climbstop::Climbstop() {

}

void Climbstop::Initialize() {

}

void Climbstop::Execute() {
	Robot::climberSubsystem->StopClimbVictor();
}

bool Climbstop::IsFinished() {
	return false;
}

void Climbstop::End() {

}

void Climbstop::Interrupted() {

}
