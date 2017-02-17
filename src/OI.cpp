#include "OI.h"
#include <Joystick.h>
#include <XboxController.h>
#include <WPILib.h>
#include <Commands/Climber/Climbon.h>
#include <Commands/Climber/Climbdown.h>
#include <Commands/Climber/Climbstop.h>
#include <Commands/Elevator/Elevator.h>
#include <Commands/Hopper/Hopperon.h>
#include <Commands/Hopper/Hopperdown.h>

OI::OI() {
	joystick.reset(new XboxController(0));

	climbupOperator.reset(new JoystickButton(joystick.get(), 5));
	climbdownOperator.reset(new JoystickButton(joystick.get(), 6));
	climbstopOperator.reset(new JoystickButton(joystick.get(), 1));

	hopperupOperator.reset(new JoystickButton(joystick.get(),3));
	hopperdownOperator.reset(new JoystickButton(joystick.get(),2));
	hopperstopOperator.reset(new JoystickButton(joystick.get(),4));

	elevatorOperator.reset(new JoystickButton(joystick.get(),8));
	elevatorStop.reset(new JoystickButton(joystick.get(),7));

	climbupOperator->WhenPressed(new Climbon(-1.0));   //climbup
	climbdownOperator->WhenPressed(new Climbon(0.5));  //climbdown
	climbstopOperator->WhenPressed(new Climbon(0));  //climbstop

	hopperupOperator->WhenPressed(new Hopperon(0.5));    //hopperup
	hopperdownOperator->WhenPressed(new Hopperdown(-0.5)); //hopperdown
	hopperstopOperator->WhenPressed(new Hopperon(0));  //hopperstop


	elevatorOperator->WhenPressed(new Elevator(-1.0)); //elevatoron
	elevatorStop->WhenPressed(new Elevator(0)); //elevatoroff


}


double OI::GetLeftXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(4));
	return joystickValue;
}


float OI::DeadBandJoystick(float axis) {
	 if(axis > -0.20 && axis < 0.20){
		 axis = 0;
	 }
	 else{
	 		axis = axis * fabs(axis);
	 }
	return axis;
}//DeadZone Adjust

