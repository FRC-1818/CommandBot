#ifndef AutonomousCenter_H
#define AutonomousCenter_H

#include "CommandBase.h"

class AutonomousCenter : public CommandBase {
public:
	AutonomousCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousCenter_H
