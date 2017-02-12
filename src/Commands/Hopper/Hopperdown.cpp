#include "Hopperdown.h"

Hopperdown::Hopperdown() {
	Requires(Robot::hopperSubsystem.get());
}

void Hopperdown::Initialize() {

}

void Hopperdown::Execute() {
	Robot::hopperSubsystem->RunHopperVictor();
}

bool Hopperdown::IsFinished() {
	return false;
}

void Hopperdown::End() {

}

void Hopperdown::Interrupted() {

}
