#include "Hopperdown.h"

Hopperdown::Hopperdown(float speed) {
	Requires(Robot::hopperSubsystem.get());
	inputSpeed = speed;
}

void Hopperdown::Initialize() {

}

void Hopperdown::Execute() {

		Robot::hopperSubsystem->RunHopperVictor(inputSpeed);

}

bool Hopperdown::IsFinished() {
	//if(Robot::downLimit->Get()){
		//Robot::hopperSubsystem->RunHopperVictor(0);
	//}
	return false;
}

void Hopperdown::End() {
	Robot::hopperSubsystem->RunHopperVictor(0);
}

void Hopperdown::Interrupted() {
	Robot::hopperSubsystem->RunHopperVictor(0);
}
