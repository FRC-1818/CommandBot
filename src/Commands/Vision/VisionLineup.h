#ifndef VisionLineup_H
#define VisionLineup_H

#include "CommandBase.h"

class VisionLineup : public CommandBase {
public:
	VisionLineup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // VisionLineup_H
