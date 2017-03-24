#include "Hopperon.h"

Hopperon::Hopperon() {
	Requires(Robot::hopperSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
	//limitSwitch1 = false;
	//limitSwitch2 = false;
}

void Hopperon::Initialize() {
	timer->Reset();
	timer->Start();
	//limitSwitch1 = Robot::upLimit->Get();
	//limitSwitch2 = Robot::downLimit->Get();
}

void Hopperon::Execute() {
	if(timer->Get() < 1.00){
	    Robot::hopperSubsystem->RunHopperVictor(-0.5);
	}
	else {
	  //if(timer->Get() > 4.00 && timer->Get() < 5.00){
		  Robot::hopperSubsystem->RunHopperVictor(0.0);

	  /*else {
	    if(timer->Get() > 5.00 && timer->Get() < 9.00){
	      Robot::hopperSubsystem->RunHopperVictor(-0.5);
	      }
	    else{
	      if(timer->Get() > 9.00){
	      Robot::hopperSubsystem->RunHopperVictor(0.0);
	      }
	    }*/
	  }

}


bool Hopperon::IsFinished() {
	/*if(limitSwitch1){
	   Robot::hopperSubsystem->RunHopperVictor(0.0);
	   Wait(1.0);
	   Robot::hopperSubsystem->RunHopperVictor(-0.5);
	}
	else{
		if(limitSwitch2){
			Robot::hopperSubsystem->RunHopperVictor(0.0);
		}
	}*/
	return false;

}

void Hopperon::End() {
	timer->Stop();
}

void Hopperon::Interrupted() {
	timer->Stop();

}
