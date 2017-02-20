#ifndef Hopperon_H
#define Hopperon_H

#include "CommandBase.h"
#include <Robot.h>
class Hopperon : public CommandBase {
public:
	Hopperon();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	//float inputSpeed;
	//bool isDone;
};

#endif
