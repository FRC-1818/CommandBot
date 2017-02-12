#ifndef Hopperup_H
#define Hopperup_H

#include "CommandBase.h"
#include <Robot.h>
class Hopperup : public CommandBase {
public:
	Hopperup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Hopperup_H
