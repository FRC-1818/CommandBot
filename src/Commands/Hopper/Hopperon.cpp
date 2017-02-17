#include "Hopperon.h"

Hopperon::Hopperon(float speed) {
	Requires(Robot::hopperSubsystem.get());
	inputSpeed = speed;
}

void Hopperon::Initialize() {

}

void Hopperon::Execute() {
	Robot::hopperSubsystem->RunHopperVictor(inputSpeed);
}

bool Hopperon::IsFinished() {
	Robot::upLimit->Get();
	return false;

}

void Hopperon::End() {
	Robot::hopperSubsystem->RunHopperVictor(0);
}

void Hopperon::Interrupted() {
	Robot::hopperSubsystem->RunHopperVictor(0);
}
