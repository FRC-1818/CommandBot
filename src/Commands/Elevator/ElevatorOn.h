#ifndef ElevatorOn_H
#define ElevatorOn_H

#include "CommandBase.h"
#include "Robot.h"

class ElevatorOn : public CommandBase {
public:
	ElevatorOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorOn_H
