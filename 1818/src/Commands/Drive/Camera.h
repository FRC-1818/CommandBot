#ifndef Camera_H
#define Camera_H

#include "CommandBase.h"
#include <Robot.h>

class Camera : public CommandBase {
public:
	Camera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool buttonAPressed;
	bool buttonBPressed;
	bool buttonXPressed;
	bool buttonYPressed;
};

#endif  // Camera_H
