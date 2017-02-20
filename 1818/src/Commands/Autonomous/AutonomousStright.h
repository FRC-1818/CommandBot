#ifndef AutonomousStright_H
#define AutonomousStright_H

#include "CommandBase.h"
#include <Robot.h>

class AutonomousStright : public CommandBase {
public:
	AutonomousStright();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // AutonomousStright_H
