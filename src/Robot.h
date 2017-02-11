/*
 * Robot.h
 *
 *  Created on: 2017Äê2ÔÂ4ÈÕ
 *      Author: Zeming
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "RobotMap.h"
#include "OI.h"
#include "Subsystems/DriveBaseSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"



class Robot : public IterativeRobot{

public:

	static std::unique_ptr<OI> oi;

	static frc::DriverStation::Alliance currentAlliance;

	static std::shared_ptr<DriveBaseSubsystem> drivebaseSubsystem;
	//static std::shared_ptr<ServoSubsystem> servoSubsystem;
	static std::shared_ptr<ClimberSubsystem> climberSubsystem;

	static bool doBoiler;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};



#endif
