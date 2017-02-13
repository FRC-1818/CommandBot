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
	void RunClimbVictor();
	void ReverseClimbVictor();
	void StopClimbVictor();
};

#endif  // ClimberSubsystem_H
