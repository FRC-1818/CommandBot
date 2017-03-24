#include "CameraSubsystem.h"
#include "../RobotMap.h"

CameraSubsystem::CameraSubsystem() : Subsystem("CameraSubsystem") {
	servo = RobotMap::servo;
}

void CameraSubsystem::InitDefaultCommand() {

}

void CameraSubsystem::RunServo(float angle){
	servo->Set(angle);
}

void CameraSubsystem::ServoRange(float range){
	range = servo->GetMaxAngle() - servo->GetMinAngle();
}

void CameraSubsystem::ServoMax(){
	servo->GetMaxAngle();
}

void CameraSubsystem::ServoMin(){
	servo->GetMinAngle();
}


