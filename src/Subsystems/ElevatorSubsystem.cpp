#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ElevatorSubsystem") {
	elevatorVictor = RobotMap::elevatorSubsystemelevatorVictor;
}

void ElevatorSubsystem::InitDefaultCommand() {

}

void ElevatorSubsystem::RunElevatorVictor(float speed){
	elevatorVictor->SetSpeed(speed);
}

void ElevatorSubsystem::StopElevatorVictor(float speed){
	elevatorVictor->SetSpeed(speed);
}
