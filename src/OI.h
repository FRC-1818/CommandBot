#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<XboxController> joystick;
public:
	OI();

	std::shared_ptr<XboxController> GetJoystick();

	std::shared_ptr<JoystickButton> climbupOperator;
	std::shared_ptr<JoystickButton> climbdownOperator;
	std::shared_ptr<JoystickButton> climbstopOperator;

	std::shared_ptr<JoystickButton> hopperupOperator;
	std::shared_ptr<JoystickButton> hopperdownOperator;

	double GetLeftXAxisDriver();
	double GetLeftYAxisDriver();
	double GetRightXAxisDriver();
	double GetRightYAxisDriver();
	float DeadBandJoystick(float axis);



};

#endif  // OI_H
