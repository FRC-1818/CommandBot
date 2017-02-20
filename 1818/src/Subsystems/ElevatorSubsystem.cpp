#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ElevatorSubsystem") {
	elevatorVictor = RobotMap::elevatorSubsystemelevatorVictor;
}

//void ElevatorSubsystem::InitDefaultCommand() {
//	elevatorVictor->SetSpeed(0.0);
//}

void ElevatorSubsystem::RunElevatorVictor(float speed){
	elevatorVictor->SetSpeed(speed);
}

