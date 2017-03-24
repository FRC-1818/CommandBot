#include <Commands/Climber/Climbon.h>

Climbon::Climbon() {
	Requires(Robot::climberSubsystem.get());
	inputSpeed = 0;
}

void Climbon::Initialize() {
	inputSpeed = 0;
}

void Climbon::Execute() {
	inputSpeed = Robot::oi->GetLeftTrigger();

    Robot::climberSubsystem->RunClimbVictor(-inputSpeed);
}

bool Climbon::IsFinished() {
	return false;
}

void Climbon::End() {
}

void Climbon::Interrupted() {
}
