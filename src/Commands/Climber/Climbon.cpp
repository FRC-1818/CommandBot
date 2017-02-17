#include <Commands/Climber/Climbon.h>

Climbon::Climbon() {
	Requires(Robot::climberSubsystem.get());
	//inputSpeed = speed;

}

void Climbon::Initialize() {

}

void Climbon::Execute(float speed) {
    Robot::climberSubsystem->RunClimbVictor(speed);
}

bool Climbon::IsFinished() {
	return false;
}

void Climbon::End() {
	Robot::climberSubsystem->RunClimbVictor(0.0);
}

void Climbon::Interrupted() {
	Robot::climberSubsystem->RunClimbVictor(0.0);
}
