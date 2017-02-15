#ifndef ElevatorOff_H
#define ElevatorOff_H

#include "CommandBase.h"
#include <Robot.h>

class ElevatorOff : public CommandBase {
public:
	ElevatorOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorOff_H
