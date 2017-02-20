#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	climbVictor = RobotMap::climberSubsystemClimbVictor;
}

//void ClimberSubsystem::InitDefaultCommand() {

//}

void ClimberSubsystem::RunClimbVictor(float speed) {
	climbVictor->SetSpeed(speed);
}

/*void ClimberSubsystem::ReverseClimbVictor(float speed){
	climbVictor->SetSpeed(speed);
}

void ClimberSubsystem::StopClimbVictor(float speed){
	climbVictor->SetSpeed(speed);

}
*/
