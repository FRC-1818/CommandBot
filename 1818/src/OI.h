#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<XboxController> joystick;
	//std::shared_ptr<GenericHID> generic;
public:
	OI();

	std::shared_ptr<XboxController> GetJoystick();
	//std::shared_ptr<JoystickButton> climbupOperator;
	//std::shared_ptr<JoystickButton> climbdownOperator;
	//`std::shared_ptr<JoystickButton> climbstopOperator;

	std::shared_ptr<JoystickButton> hopperupOperator;
	//std::shared_ptr<JoystickButton> hopperdownOperator;
	std::shared_ptr<JoystickButton> hopperstopOperator;

	std::shared_ptr<JoystickButton> elevatorOperator;
	std::shared_ptr<JoystickButton> elevatorStop;

	std::shared_ptr<JoystickButton> cameraOn;

	double GetLeftXAxisDriver();
	double GetLeftYAxisDriver();
	double GetRightXAxisDriver();
	double GetLeftTrigger();
	float DeadBandJoystick(float axis);



};

#endif  // OI_H
