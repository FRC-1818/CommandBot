#include "CameraSubsystem.h"
#include "../RobotMap.h"

CameraSubsystem::CameraSubsystem() : Subsystem("CameraSubsystem") {
	servo = RobotMap::servo;
}

void CameraSubsystem::InitDefaultCommand() {

}

void CameraSubsystem::RunServo(){
	servo->SetAngle(1.0);
}
