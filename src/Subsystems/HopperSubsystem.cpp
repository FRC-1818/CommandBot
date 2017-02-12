#include "HopperSubsystem.h"
#include "RobotMap.h"

HopperSubsystem::HopperSubsystem() : Subsystem("HopperSubsystem") {
	hopperVictor = RobotMap::hopperSubsystemhopperVictor;
}

void HopperSubsystem::InitDefaultCommand() {

}

void HopperSubsystem::RunHopperVictor(){
	hopperVictor->SetSpeed(0.3);
}

void HopperSubsystem::ReverseHopperVictor(){
	hopperVictor->SetSpeed(-0.3);
}

void HopperSubsystem::StopHopperVictor(){
	hopperVictor->SetSpeed(0.0);
}
