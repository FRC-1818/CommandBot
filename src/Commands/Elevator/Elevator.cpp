#include "Elevator.h"

Elevator::Elevator() {
	Requires(Robot::elevatorSubsystem.get());
	//inputSpeed = speed;
}

void Elevator::Initialize() {

}

void Elevator::Execute(float speed) {

	Robot::elevatorSubsystem->RunElevatorVictor(speed);
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
