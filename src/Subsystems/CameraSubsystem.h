#ifndef CameraSubsystem_H
#define CameraSubsystem_H

#include <Commands/Subsystem.h>
#include <Servo.h>

class CameraSubsystem : public Subsystem {
private:
std::shared_ptr<Servo> servo;

public:
	CameraSubsystem();
	void InitDefaultCommand();
	void RunServo(float angle);
	void ServoRange(float range);
	void ServoMax();
	void ServoMin();
};

#endif
