#ifndef ClimberSubsystem_H
#define ClimberSubsystem_H

#include <Commands/Subsystem.h>
#include <Victor.h>

class ClimberSubsystem : public Subsystem {
private:

	std::shared_ptr<Victor> climbVictor;

public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void RunClimbVictor(float speed);
	//void ReverseClimbVictor(float speed);
	//void StopClimbVictor(float speed);
};

#endif  // ClimberSubsystem_H
