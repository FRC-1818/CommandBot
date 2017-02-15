#include <Commands/Climber/Climbup.h>

Climbup::Climbup() {
	Requires(Robot::climberSubsystem.get());

}

void Climbup::Initialize() {

}

void Climbup::Execute() {
    Robot::climberSubsystem->RunClimbVictor(-1.0);
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
