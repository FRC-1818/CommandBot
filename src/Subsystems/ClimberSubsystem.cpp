#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	climbVictor = RobotMap::climberSubsystemClimbVictor;
}

void ClimberSubsystem::InitDefaultCommand() {

}

void ClimberSubsystem::RunClimbVictor() {
	climbVictor->SetSpeed(1.0);
}

void ClimberSubsystem::ReverseClimbVictor(){
	climbVictor->SetSpeed(-0.5);
}

void ClimberSubsystem::StopClimbVictor(){
	climbVictor->SetSpeed(0.0);

}
