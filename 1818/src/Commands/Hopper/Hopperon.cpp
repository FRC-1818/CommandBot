#include "Hopperon.h"

Hopperon::Hopperon() {
	Requires(Robot::hopperSubsystem.get());
	timer.reset(new Timer());
	timer->Start();
	timer->Reset();
	//inputSpeed = speed;
//	isDone = false;
}

void Hopperon::Initialize() {
	//isDone = false;
	timer->Start();
	timer->Reset();
}

void Hopperon::Execute() {
    if(timer->Get() < 4.00){
    	Robot::hopperSubsystem->RunHopperVictor(0.5);
    } else {
    	if(timer->Get() > 4.00 && timer->Get() < 5.00){
    		Robot::hopperSubsystem->RunHopperVictor(0.0);
    	} else {
    	  if(timer->Get() > 5.00 && timer->Get() < 9.00){
    		  Robot::hopperSubsystem->RunHopperVictor(-0.5);
    	  } else {
    		  if(timer->Get > 9.00){
    			 Robot::hopperSubsystem->RunHopperVictor(0.0);
    		}
    	 }
      }
    }

}

bool Hopperon::IsFinished() {
	//bool temp;
	//temp = Robot::upLimit->Get();
	//printf(temp ? "true" : "false");
	//return temp;
	return false;

}

void Hopperon::End() {
	timer->Stop();
	//Robot::hopperSubsystem->RunHopperVictor(0.0);
}

void Hopperon::Interrupted() {
	//Robot::hopperSubsystem->RunHopperVictor(0.0);
	//isDone = true;
	timer->Stop();
}
