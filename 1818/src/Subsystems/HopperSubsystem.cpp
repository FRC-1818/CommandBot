#include "HopperSubsystem.h"
#include "RobotMap.h"

HopperSubsystem::HopperSubsystem() : Subsystem("HopperSubsystem") {
	hopperVictor = RobotMap::hopperSubsystemhopperVictor;
}

void HopperSubsystem::InitDefaultCommand() {

}

void HopperSubsystem::RunHopperVictor(float speed){
	hopperVictor->SetSpeed(speed);
}

