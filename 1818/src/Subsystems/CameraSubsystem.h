#ifndef CameraSubsystem_H
#define CameraSubsystem_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <AHRS.h>

class CameraSubsystem : public Subsystem {
private:
std::shared_ptr<Servo> servo;
std::shared_ptr<AHRS> adjustedYaw;

public:
	CameraSubsystem();
	void InitDefaultCommand();
	void RunServo(float angle);
	void ServoRange(float range);
	void ServoMax();
	void ServoMin();
	float GetYawValue();
};

#endif
