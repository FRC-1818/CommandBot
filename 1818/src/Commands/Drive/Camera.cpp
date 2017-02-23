#include "Camera.h"

Camera::Camera() {
	Requires(Robot::cameraSubsystem.get());
	buttonAPressed = false;
	buttonBPressed = false;
	buttonXPressed = false;
	buttonYPressed = false;
}

void Camera::Initialize() {
	buttonAPressed = Robot::oi->GetAButton();
	buttonBPressed = Robot::oi->GetBButton();
	buttonXPressed = Robot::oi->GetXButton();
	buttonYPressed = Robot::oi->GetYButton();
}

void Camera::Execute() {
 if (buttonYPressed){

	Robot::cameraSubsystem->RunServo(0.0714/2);

 } else {
	if(buttonBPressed){

	Robot::cameraSubsystem->RunServo(0.1429/2);

	} else {
		if(buttonAPressed){

		Robot::cameraSubsystem->RunServo(0.2143/2);
		}
		else{
		 if(buttonXPressed){

		Robot::cameraSubsystem->RunServo(0.2857/2);

			}
		 }
	  }
   }
}

bool Camera::IsFinished() {
	return false;
}

void Camera::End() {

}

void Camera::Interrupted() {

}
