#include "Elevator.h"

Elevator::Elevator(float speed) {
	Requires(Robot::elevatorSubsystem.get());
	inputSpeed = speed;
}

void Elevator::Initialize() {

}

void Elevator::Execute() {

	Robot::elevatorSubsystem->RunElevatorVictor(inputSpeed);

}

bool Elevator::IsFinished() {

	return false;
}

void Elevator::End() {
	Robot::elevatorSubsystem->RunElevatorVictor(0);
}

void Elevator::Interrupted() {
	Robot::elevatorSubsystem->RunElevatorVictor(0);
}
