#ifndef Hopperdown_H
#define Hopperdown_H

#include "CommandBase.h"
#include <Robot.h>

class Hopperdown : public CommandBase {
public:
	Hopperdown(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float inputSpeed;
};

#endif  // Hopperdown_H
