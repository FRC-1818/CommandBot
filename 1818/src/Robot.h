/*
 * Robot.h
 *
 *  Created on: 2017Äê2ÔÂ9ÈÕ
 *      Author: Zeming
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "RobotMap.h"
#include "OI.h"
#include "Subsystems/DriveBaseSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "Subsystems/HopperSubsystem.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "Subsystems/CameraSubsystem.h"
#include <Victor.h>
#include <Jaguar.h>
#include <XboxController.h>
#include <Joystick.h>
#include <I2C.h>
#include <DigitalInput.h>
#include <Servo.h>
//#include "Commands/Drive/DriveCommand.h"

class Robot: public IterativeRobot {

public:

	static std::unique_ptr<OI> oi;
	static frc::DriverStation::Alliance currentAlliance;
	static std::shared_ptr<DriveBaseSubsystem> drivebaseSubsystem;
	static std::shared_ptr<ClimberSubsystem> climberSubsystem;
	static std::shared_ptr<HopperSubsystem> hopperSubsystem;
	static std::shared_ptr<ElevatorSubsystem> elevatorSubsystem;
	//static std::shared_ptr<XboxController> joystick;
	static std::shared_ptr<RobotDrive> myRobot;
	static std::shared_ptr<I2C> i2c;
	static std::shared_ptr<CameraSubsystem> cameraSubsystem;
	static std::shared_ptr<DigitalInput> upLimit;
	static std::shared_ptr<DigitalInput> downLimit;
	static std::shared_ptr<DigitalInput> switch1;
	static std::shared_ptr<DigitalInput> switch2;
	static std::shared_ptr<DigitalInput> switch3;
	static std::shared_ptr<DigitalInput> switch4;

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
	std::unique_ptr<frc::Command> autonomousCenter;
	std::unique_ptr<frc::Command> autonomousLeft;
	std::unique_ptr<frc::Command> autonomousStright;
	std::unique_ptr<frc::Command> autonomousRight;
	std::unique_ptr<frc::Command> driveCommand;
	std::unique_ptr<frc::Command> cameraCommand;
};
#endif
