#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	climbVictor = RobotMap::climberSubsystemClimbVictor;
}

void ClimberSubsystem::InitDefaultCommand() {

}

void ClimberSubsystem::RunClimbVictor(float speed) {
	climbVictor->SetSpeed(speed);
}

