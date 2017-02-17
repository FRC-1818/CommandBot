#ifndef Camera_H
#define Camera_H

#include "CommandBase.h"
#include <Robot.h>

class Camera : public CommandBase {
public:
	Camera();
	//Camera(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
//private:
	//float inputAngle;
};

#endif  // Camera_H
