/*
 * Robot.h
 *
 *  Created on: 2017��2��9��
 *      Author: Zeming
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "RobotMap.h"
#include "OI.h"
#include "Subsystems/DriveBaseSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include <Victor.h>
#include <XboxController.h>
#include <Joystick.h>

class Robot: public IterativeRobot {

public:

	static std::unique_ptr<OI> oi;

	static frc::DriverStation::Alliance currentAlliance;

	static std::shared_ptr<DriveBaseSubsystem> drivebaseSubsystem;
	static std::shared_ptr<ClimberSubsystem> climberSubsystem;
	static std::shared_ptr<Joystick> joystick;
	static std::shared_ptr<RobotDrive> myRobot;
	static bool doBoiler;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	frc::SendableChooser<frc::Command*> autoChooser;
	std::unique_ptr<frc::Command> selectedMode;
};
#endif
