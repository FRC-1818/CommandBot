#include "OI.h"

#include <WPILib.h>
#include "Commands/Climber/Climbup.h"
#include "Commands/Climber/Climbdown.h"
#include "Commands/Climber/Climbstop.h"
#include "Commands/Hopper/Hopperup.h"
#include "Commands/Hopper/Hopperdown.h"
#include "Commands/Elevator/ElevatorOn.h"
#include "Commands/Elevator/ElevatorOff.h"

OI::OI() {
	joystick.reset(new XboxController(0));

	climbupOperator.reset(new JoystickButton(joystick.get(), 5));
	climbdownOperator.reset(new JoystickButton(joystick.get(), 4));
	climbstopOperator.reset(new JoystickButton(joystick.get(), 2));

	hopperupOperator.reset(new JoystickButton(joystick.get(),3));
	hopperdownOperator.reset(new JoystickButton(joystick.get(),2));

	climbupOperator->WhenPressed(new Climbup);
	climbdownOperator->WhenPressed(new Climbdown);
	climbstopOperator->WhenPressed(new Climbstop);

	hopperupOperator->WhenPressed(new Hopperup);
	hopperdownOperator->WhenPressed(new Hopperdown);

	elevatorOnOperator->WhenPressed(new ElevatorOn);
	elevatorOffOperator->WhenPressed(new ElevatorOff);

}

double OI::GetLeftXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick.get()->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick.get()->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick.get()->GetRawAxis(4));
	return joystickValue;
}

double OI::GetRightYAxisDriver(){
	double joystickValue = OI::DeadBandJoystick(joystick.get()->GetRawAxis(5));
	return joystickValue;
}

float OI::DeadBandJoystick(float axis) {
	if(axis > -0.20 && axis < 0.20)
	{
		axis = 0;
	}
	else
	{
		axis = axis * fabs(axis);
	}
	return axis;
}
