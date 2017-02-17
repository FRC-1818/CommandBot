#include "Camera.h"

Camera::Camera() {
	Requires(Robot::cameraSubsystem.get());
	//inputAngle = angle;
}

void Camera::Initialize() {

}

void Camera::Execute() {

   /*for(inputAngle = Robot::cameraSubsystem->ServoMin();
       inputAngle < Robot::cameraSubsystem->ServoMax();
   	   inputAngle += Robot::cameraSubsystem->ServoRange / 10.0)
   {
	   Robot::cameraSubsystem->RunServo(inputAngle);
	   Wait(.1);
   }*/

	Robot::cameraSubsystem->RunServo(30);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(60);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(90);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(150);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(180);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(150);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(90);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(60);
	Wait(.1);
	Robot::cameraSubsystem->RunServo(30);
	Wait(.1);
}

bool Camera::IsFinished() {
	return false;
}

void Camera::End() {

}

void Camera::Interrupted() {

}
