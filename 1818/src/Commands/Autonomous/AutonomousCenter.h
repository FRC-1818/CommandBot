#ifndef DriveForward_H
#define DriveForward_H

#include "CommandBase.h"
#include <Robot.h>

class AutonomousCenter : public CommandBase {
public:
	AutonomousCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // DriveForward_H
