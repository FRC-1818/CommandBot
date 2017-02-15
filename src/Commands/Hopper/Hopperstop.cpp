#include "Hopperstop.h"

Hopperstop::Hopperstop() {
	Requires(Robot::hopperSubsystem.get());
}

void Hopperstop::Initialize() {

}

void Hopperstop::Execute() {
	Robot::hopperSubsystem->StopHopperVictor();
}

bool Hopperstop::IsFinished() {
	return false;
}

void Hopperstop::End() {

}

void Hopperstop::Interrupted() {

}
