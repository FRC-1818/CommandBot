#ifndef DriveCommand_H
#define DriveCommand_H

#include "CommandBase.h"
#include "Robot.h"

class DriveCommand : public CommandBase {
public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	void CallToMecanumDrive();

	float xAxis;
	float yAxis;
	float rotAxis;
	float setSpeed;
	float adjustedYaw;
	float finalAutoRot;

};

#endif  // DriveCommand_H
