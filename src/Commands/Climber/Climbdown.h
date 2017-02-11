#ifndef Climbdown_H
#define Climbdown_H

#include "CommandBase.h"
#include <Robot.h>

class Climbdown : public CommandBase {
public:
	Climbdown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Climbdown_H
