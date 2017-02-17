#ifndef HopperSubsystem_H
#define HopperSubsystem_H

#include <Commands/Subsystem.h>
//#include <Robot.h>
#include <Victor.h>
//#include <DigitalInput.h>
class HopperSubsystem : public Subsystem {
private:
	std::shared_ptr<Victor> hopperVictor;
	//std::shared_ptr<DigitalInput> limitSwitch;

public:
	HopperSubsystem();
	void InitDefaultCommand();
	void RunHopperVictor(float speed);
};

#endif
