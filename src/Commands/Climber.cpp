#include "Climber.h"
#include "..\robot.h"
#include "..\Subsystems\ClimberSubsystem.h"

Climber::Climber(float speed, float time) {
//	Requires(Robot::climberSubsystem.get());
		timer.reset(new Timer());
		isDone = false;
		timeTarget = time;
		timeCurrent = 0;
		inputSpeed = speed;
		timer->Reset();
		timer->Start();
}


void Climber::Initialize() {
	isDone = false;
		timeCurrent = 0;
		timer->Reset();
		timer->Start();
}


void Climber::Execute() {
	timeCurrent = timer->Get();
		if(timeTarget == 0)
		{
			Robot::climberSubsystem->RunClimbVictor(inputSpeed);
			isDone = true;
		}
		else
		{
			if(timeCurrent >= timeTarget)
			{
				Robot::climberSubsystem->RunClimbVictor(0);
				isDone = true;
			}
			else
			{
				Robot::climberSubsystem->RunClimbVictor(inputSpeed);
				isDone = false;
			}
		}
	}



bool Climber::IsFinished() {
	return false;
}


void Climber::End() {
	timer->Stop();
}

void Climber::Interrupted() {
	timer->Stop();
}
