#include "VisionLineup.h"
#include "math.h"

VisionLineup::VisionLineup() {
/*	Requires(Robot::visionSubsystem.get());
	Requires(Robot::drivebaseSubsystem.get());
	leftX = Robot::visionSubsystem->leftX(); //320-X , 200-Y
	rightX = Robot::visionSubsystem->rightX();
	leftWidth = Robot::visionSubsystem->leftWidth();
	rightWidth = Robot::visionSubsystem->rightWidth();
	time = 0;
	*/
}

void VisionLineup::Initialize() {

}

void VisionLineup::Execute() {
/*
	printf("%d",fabs(leftX - rightX));
if(time == 0 or time == 3){
	if(fabs(leftX - rightX) > 100 ){
		Robot::drivebaseSubsystem->MecanumDrive(0.3, 0.0, 0.0, 0.0);
		//drive back
	}

	else if(fabs(leftX - rightX) < 80){
		Robot::drivebaseSubsystem->MecanumDrive(-0.3, 0.0, 0.0, 0.0);
		//drive forward
	}
	else{
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
		time = time + 1;
		//stop
	}
  }

if(time == 1 or time == 4){
	if(leftWidth > rightWidth + 5){
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, -0.3, 0.0);
		//left turn
	}
	else if(leftWidth < rightWidth + 5){
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.3, 0.0);
		//right turn
	}
	else{
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
		//stop
		time = time + 1;
	}
 }

if(time == 2 or time == 5){
	if(leftX > 100){
		Robot::drivebaseSubsystem->MecanumDrive(0.0, -0.3, 0.0, 0.0);
	}
	else if(leftX < 110){
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.3, 0.0, 0.0);
	}
	else{
		Robot::drivebaseSubsystem->MecanumDrive(0.0, 0.0, 0.0, 0.0);
		time = time + 1;
	}
 }
*/
}

bool VisionLineup::IsFinished() {
	return false;
}

void VisionLineup::End() {

}

void VisionLineup::Interrupted() {

}
