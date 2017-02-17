#ifndef Elevator_H
#define Elevator_H

#include "CommandBase.h"
#include "Robot.h"

class Elevator : public CommandBase {
public:
	Elevator();
	void Initialize();
	void Execute(float speed);
	bool IsFinished();
	void End();
	void Interrupted();
//private:
	//float inputSpeed;

};

#endif
