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
	return false;
}

void Hopperup::End() {

}

void Hopperup::Interrupted() {

}
