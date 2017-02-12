#ifndef DriveStationtoPeg2_H
#define DriveStationtoPeg2_H

#include "CommandBase.h"
#include <Robot.h>

class DriveStationtoPeg2 : public CommandBase {
public:
	DriveStationtoPeg2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // DriveStationtoPeg2_H
