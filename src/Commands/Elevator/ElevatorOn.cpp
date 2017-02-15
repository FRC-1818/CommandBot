#include "ElevatorOn.h"

ElevatorOn::ElevatorOn() {
	Requires(Robot::elevatorSubsystem.get());
}

void ElevatorOn::Initialize() {

}

void ElevatorOn::Execute() {

	Robot::elevatorSubsystem->RunElevatorVictor(-1.0);
}

bool ElevatorOn::IsFinished() {
	return false;
}

void ElevatorOn::End() {

}

void ElevatorOn::Interrupted() {

}
