#ifndef Hopperon_H
#define Hopperon_H

#include "CommandBase.h"
#include <Robot.h>
class Hopperon : public CommandBase {
public:
	Hopperon(); //float speed
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//float inputSpeed;
	std::shared_ptr<Timer> timer;
	//bool limitSwitch1;
	//bool limitSwitch2;

};

#endif
