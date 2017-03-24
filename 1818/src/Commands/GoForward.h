#ifndef GoForward_H
#define GoForward_H

#include "CommandBase.h"
#include "Robot.h"

class GoForward : public CommandBase {
public:
	GoForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
};

#endif  // GoForward_H
