#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> joystick;
public:
	OI();

	std::shared_ptr<Joystick> GetJoystick();

	std::shared_ptr<JoystickButton> climbupOperator;
	std::shared_ptr<JoystickButton> climbdownOperator;
	std::shared_ptr<JoystickButton> climbstopOperator;

	double GetLeftXAxisDriver();
	double GetLeftYAxisDriver();
	double GetRightXAxisDriver();
	double GetRightYAxisDriver();
	float DeadBandJoystick(float axis);



};

#endif  // OI_H
