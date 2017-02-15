#include "Hopperup.h"

Hopperup::Hopperup() {
	Requires(Robot::hopperSubsystem.get());
}

void Hopperup::Initialize() {

}

void Hopperup::Execute() {
	Robot::hopperSubsystem->RunHopperVictor();
}

bool Hopperup::IsFinished() {
	Robot::upLimit->Get();
	return false;

}

void Hopperup::End() {
	Robot::hopperSubsystem->StopHopperVictor();
}

void Hopperup::Interrupted() {
	Robot::hopperSubsystem->StopHopperVictor();
}
