#ifndef Hopperstop_H
#define Hopperstop_H

#include "CommandBase.h"
#include <Robot.h>

class Hopperstop : public CommandBase {
public:
	Hopperstop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Hopperstop_H
