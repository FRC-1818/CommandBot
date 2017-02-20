#include "Camera.h"

Camera::Camera() {
	Requires(Robot::cameraSubsystem.get());
	timer.reset(new Timer());
	//inputAngle = angle;
	adjustedYaw = 0;
}

void Camera::Initialize() {
	adjustedYaw = 0;
	timer->Reset();
	timer->Start();
}

void Camera::Execute() {

	/*for(inputAngle = Robot::cameraSubsystem->ServoMin();
	 inputAngle < Robot::cameraSubsystem->ServoMax();
	 inputAngle += Robot::cameraSubsystem->ServoRange / 10.0)
	 {
	 Robot::cameraSubsystem->RunServo(inputAngle);
	 Wait(.1);
	 }*/
	adjustedYaw = Robot::cameraSubsystem->GetYawValue();

	if (timer->Get() < 5.0) {
		Robot::cameraSubsystem->RunServo(0.0);
	} else if (timer->Get() < 10) {
		Robot::cameraSubsystem->RunServo(0.5);
	} else if (timer->Get() < 15.0) {
		Robot::cameraSubsystem->RunServo(1.0);
	}

}

bool Camera::IsFinished() {
	if (timer->Get() > 20) {
		return true;
	} else {
		return false;
	}

}

void Camera::End() {
timer->Stop();
}

void Camera::Interrupted() {
	timer->Stop();
}
