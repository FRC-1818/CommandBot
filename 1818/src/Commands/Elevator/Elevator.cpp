#include "Elevator.h"

Elevator::Elevator(float speed) {
	Requires(Robot::elevatorSubsystem.get());
	inputSpeed = speed;
	//isDone = false;
}

void Elevator::Initialize() {
	//isDone = false;
}

void Elevator::Execute() {

	Robot::elevatorSubsystem->RunElevatorVictor(inputSpeed);
	//isDone = true;
}

bool Elevator::IsFinished() {
	//return isDone;
	return false;
}

void Elevator::End() {
	Robot::elevatorSubsystem->RunElevatorVictor(0);
}

void Elevator::Interrupted() {
	Robot::elevatorSubsystem->RunElevatorVictor(0);
}
