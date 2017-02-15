#ifndef ElevatorSubsystem_H
#define ElevatorSubsystem_H

#include <Commands/Subsystem.h>
#include <Victor.h>
//#include <Robot.h>

class ElevatorSubsystem : public Subsystem {
private:
	std::shared_ptr<Victor> elevatorVictor;
public:
	ElevatorSubsystem();
	void InitDefaultCommand();
	void RunElevatorVictor(float speed);
	void StopElevatorVictor(float speed);
};

#endif  // ElevatorSubsystem_H
