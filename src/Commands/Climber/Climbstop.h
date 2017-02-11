#ifndef Climbstop_H
#define Climbstop_H

#include "CommandBase.h"
#include <Robot.h>

class Climbstop : public CommandBase {
public:
	Climbstop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Climbstop_H
