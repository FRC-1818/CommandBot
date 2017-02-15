#include "ElevatorOff.h"

ElevatorOff::ElevatorOff() {
	Requires(Robot::elevatorSubsystem.get());
}

void ElevatorOff::Initialize() {

}

void ElevatorOff::Execute() {
	Robot::elevatorSubsystem->StopElevatorVictor(0.0);
}

bool ElevatorOff::IsFinished() {
	return false;
}

void ElevatorOff::End() {

}

void ElevatorOff::Interrupted() {

}
