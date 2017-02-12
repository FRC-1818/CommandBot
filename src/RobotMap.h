#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <Victor.h>
#include <XboxController.h>
#include <I2C.h>
//#include <VictorSP.h>

class RobotMap{
public:
	static void init();
	static std::shared_ptr<Victor> driveBaseSubsystemfrontLeftVictor;
	static std::shared_ptr<Victor> driveBaseSubsystemfrontRightVictor;
	static std::shared_ptr<Victor> driveBaseSubsystembackLeftVictor;
	static std::shared_ptr<Victor> driveBaseSubsystembackRightVictor;
	static std::shared_ptr<RobotDrive> myRobot;
	static std::shared_ptr<Victor> climberSubsystemClimbVictor;
	static std::shared_ptr<XboxController> joystick;
	static std::shared_ptr<Victor> hopperSubsystemhopperVictor;
	static std::shared_ptr<I2C> i2c;

};


#endif  // ROBOTMAP_H
