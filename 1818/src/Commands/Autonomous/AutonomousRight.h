#ifndef DriveStationtoPeg3_H
#define DriveStationtoPeg3_H

#include "CommandBase.h"
#include <Robot.h>

class AutonomousRight : public CommandBase {
public:
	AutonomousRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // DriveStationtoPeg3_H
