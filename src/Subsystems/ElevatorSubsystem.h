#ifndef ElevatorSubsystem_H
#define ElevatorSubsystem_H

#include <Commands/Subsystem.h>
#include <Victor.h>

class ElevatorSubsystem : public Subsystem {
private:
	std::shared_ptr<Victor> elevatorVictor;
public:
	ElevatorSubsystem();
	void InitDefaultCommand();
	void RunElevatorVictor();
	void StopElevatorVictor();
};

#endif  // ElevatorSubsystem_H
