#ifndef Climber_H
#define Climber_H

#include "CommandBase.h"
#include <Robot.h>

class Climbon : public CommandBase {
public:
	Climbon();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void stop();
private:
	float inputSpeed;
    //bool isDone;

};

#endif  // Climber_H
