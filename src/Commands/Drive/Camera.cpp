#include "Camera.h"

Camera::Camera() {
	//Requires(Robot::cameraSubsystem.get());
}

void Camera::Initialize() {

}

void Camera::Execute() {
   //Robot::cameraSubsystem->RunServo();
}

bool Camera::IsFinished() {
	return false;
}

void Camera::End() {

}

void Camera::Interrupted() {

}
