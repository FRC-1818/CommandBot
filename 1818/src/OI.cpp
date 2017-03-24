#include "OI.h"
#include <Joystick.h>
#include <XboxController.h>
#include <WPILib.h>
#include <Commands/Elevator/Elevator.h>
#include <Commands/Hopper/Hopperon.h>
#include <Commands/Drive/Camera.h>

OI::OI() {
	joystick.reset(new XboxController(0));

	YButton.reset(new JoystickButton(joystick.get(),4));
	XButton.reset(new JoystickButton(joystick.get(),3));
	BButton.reset(new JoystickButton(joystick.get(),2));
	AButton.reset(new JoystickButton(joystick.get(),1));

	YButton->WhenPressed(new Camera(0.0714/2));
	XButton->WhenPressed(new Camera(0.2857/2));
	BButton->WhenPressed(new Camera(0.1429/2));
	AButton->WhenPressed(new Camera(0.2143/2));

	//hopperupOperator.reset(new JoystickButton(joystick.get(),5));   //LeftBumper
	//hopperstopOperator.reset(new JoystickButton(joystick.get(),6)); //RightBumper

	//elevatorOperator.reset(new JoystickButton(joystick.get(),8));   //StartButton
	//elevatorStop.reset(new JoystickButton(joystick.get(),7));       //BackButton

	//hopperupOperator->WhenPressed(new Hopperon);                    //hopper up,down,stop
	//hopperstopOperator->CancelWhenPressed(new Hopperon);            //cancle Hopper command

	//elevatorOperator->WhenPressed(new Elevator(-1.0));              //elevatoron
	//elevatorStop->WhenPressed(new Elevator(0.0));                   //elevatoroff

}


double OI::GetLeftXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(0));
	return joystickValue;
}
//used in DriveCommand.cpp drive front-back

double OI::GetLeftYAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(1));
	return joystickValue;
}
//used in DriveCommand.cpp drive Sli deLeft-SlideRight

double OI::GetRightXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(4));
	return joystickValue;
}
//used in DriveCommand.cpp drive left-right

double OI::GetLeftTrigger(){
	double joystickValue = OI::DeadBandJoystick(joystick->GetRawAxis(2));
	return joystickValue;
}
//used in Climbon.cpp Set Climber Motor

float OI::DeadBandJoystick(float axis) {
	 if(axis > -0.20 && axis < 0.20){
		 axis = 0;
	 }
	 else{
	 		axis = axis * fabs(axis);
	 }
	return axis;
}
//DeadZone Adjust


bool OI::GetAButton(){
	return joystick->GetRawButton(1); //used in Camera.cpp Servo BackPosition
}

bool OI::GetBButton(){
	return joystick->GetRawButton(2); //used in Camera.cpp Servo LeftPosition
}

bool OI::GetXButton(){
	return joystick->GetRawButton(3); //used in Camera.cpp Servo RightPosition
}

bool OI::GetYButton(){
	return joystick->GetRawButton(4); //used in Camera.cpp Servo FrontPosition
}

bool OI::GetLeftBumper(){
	return joystick->GetRawButton(5);
}

bool OI::GetRightBumper(){
	return joystick->GetRawButton(6);
}

bool OI::GetBackButton(){
	return joystick->GetRawButton(7);
}

bool OI::GetStartButton(){
	return joystick->GetRawButton(8);
}

bool OI::GetLeftStickButton(){
	return joystick->GetRawButton(9); //used in Robot.cpp TeleopInit Cancel all Commands
}

bool OI::GetRightStickButton(){
	return joystick->GetRawButton(10);
}


