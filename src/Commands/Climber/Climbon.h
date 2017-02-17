#ifndef Climber_H
#define Climber_H

#include "CommandBase.h"
#include <Robot.h>

class Climbon : public CommandBase {
public:
	Climbon();
	void Initialize();
	void Execute(float speed);
	bool IsFinished();
	void End();
	void Interrupted();
//private:
	//float inputSpeed;


};

#endif  // Climber_H
