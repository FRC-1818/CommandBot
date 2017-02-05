#ifndef Climber_H
#define Climber_H
#include "Commands/Command.h"
#include "../CommandBase.h"


class Climber : public CommandBase {
public:
	Climber(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	float inputSpeed;
	bool isDone;
};

#endif  // Climber_H
