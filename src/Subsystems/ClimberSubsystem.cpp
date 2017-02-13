#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	climbVictor = RobotMap::climberSubsystemClimbVictor;
}

void ClimberSubsystem::InitDefaultCommand() {

}

void ClimberSubsystem::RunClimbVictor(float speed) {
	//float speed;
	climbVictor->SetSpeed(speed);
}

void ClimberSubsystem::ReverseClimbVictor(){
	climbVictor->SetSpeed(-0.5);
}

void ClimberSubsystem::StopClimbVictor(){
	climbVictor->SetSpeed(0.0);

}
