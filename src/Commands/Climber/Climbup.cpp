#include <Commands/Climber/Climbup.h>

Climbup::Climbup() {
	Requires(Robot::climberSubsystem.get());

}

void Climbup::Initialize() {

}

void Climbup::Execute() {
    Robot::climberSubsystem->RunClimbVictor();
}

bool Climbup::IsFinished() {
	return false;
}

void Climbup::End() {
	//Robot::climberSubsystem->StopClimbVictor();
}

void Climbup::Interrupted() {
	//Robot::climberSubsystem->StopClimbVictor();
}
