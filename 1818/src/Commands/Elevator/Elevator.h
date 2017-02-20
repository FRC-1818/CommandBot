#ifndef Elevator_H
#define Elevator_H

#include "CommandBase.h"
#include "Robot.h"

class Elevator : public CommandBase {
public:
	Elevator(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float inputSpeed;
	//bool  isDone;

};

#endif
