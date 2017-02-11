#ifndef Climber_H
#define Climber_H

#include "CommandBase.h"
#include <Robot.h>

class Climbup : public CommandBase {
public:
	Climbup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:


};

#endif  // Climber_H
