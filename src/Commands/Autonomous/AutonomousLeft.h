#ifndef AutonomousLeft_H
#define AutonomousLeft_H

#include "CommandBase.h"
#include <Robot.h>

class AutonomousLeft : public CommandBase {
public:
	AutonomousLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif
