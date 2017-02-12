#ifndef HopperSubsystem_H
#define HopperSubsystem_H

#include <Commands/Subsystem.h>
//#include <Robot.h>
#include <Victor.h>
class HopperSubsystem : public Subsystem {
private:
	std::shared_ptr<Victor> hopperVictor;

public:
	HopperSubsystem();
	void InitDefaultCommand();
	void RunHopperVictor();
	void ReverseHopperVictor();
	void StopHopperVictor();
};

#endif
