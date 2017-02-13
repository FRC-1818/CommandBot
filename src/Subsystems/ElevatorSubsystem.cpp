#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ElevatorSubsystem") {
	elevatorVictor = RobotMap::elevatorSubsystemelevatorVictor;
}

void ElevatorSubsystem::InitDefaultCommand() {

}

void ElevatorSubsystem::RunElevatorVictor(){
	elevatorVictor->SetSpeed(1.0);
}

void ElevatorSubsystem::StopElevatorVictor(){
	elevatorVictor->SetSpeed(0.0);
}
