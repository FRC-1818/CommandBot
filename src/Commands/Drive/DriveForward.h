#ifndef DriveForward_H
#define DriveForward_H

#include "CommandBase.h"
#include <Robot.h>

class DriveForward : public CommandBase {
public:
	DriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // DriveForward_H
