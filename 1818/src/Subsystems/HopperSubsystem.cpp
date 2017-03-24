#include "HopperSubsystem.h"
#include "RobotMap.h"

HopperSubsystem::HopperSubsystem() : Subsystem("HopperSubsystem") {
	hopperVictor = RobotMap::hopperSubsystemhopperVictor;
	//upLimit = RobotMap::upLimit;
}

void HopperSubsystem::InitDefaultCommand() {

}

void HopperSubsystem::RunHopperVictor(float speed){
	hopperVictor->SetSpeed(speed);
}

