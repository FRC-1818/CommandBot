#ifndef VisionLineup_H
#define VisionLineup_H

#include "CommandBase.h"
#include "Robot.h"

class VisionLineup : public CommandBase {
public:
	VisionLineup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	/*int leftX;
	int rightX;
	int leftWidth;
	int rightWidth;
	int time;*/
};

#endif  // VisionLineup_H
