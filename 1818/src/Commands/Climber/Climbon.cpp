#include <Commands/Climber/Climbon.h>

Climbon::Climbon() {
	Requires(Robot::climberSubsystem.get());
	inputSpeed = 0;
	//isDone = false;
}

void Climbon::Initialize() {
	//isDone = false;
	inputSpeed = 0;
}

void Climbon::Execute() {

	inputSpeed = Robot::oi->GetLeftTrigger();
    Robot::climberSubsystem->RunClimbVictor(-inputSpeed);
    //isDone = true;
}

bool Climbon::IsFinished() {
	//return isDone;
	return false;
}

void Climbon::End() {
	//Robot::climberSubsystem->RunClimbVictor(0.0);
}

void Climbon::Interrupted() {
	//Robot::climberSubsystem->RunClimbVictor(0.0);
}

//void Climbon::Stop()
//{
	//inDone = true;
//}
