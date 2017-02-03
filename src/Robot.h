/*
 * Robot.h
 *
 *  Created on: Jan 31, 2017
 *      Author: Joseph
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "RobotMap.h"
#include "OI.h"



class Robot : public IterativeRobot {

public:

	static std::unique_ptr<OI> oi;

//    static std::shared_ptr<DrivebaseSubsystem> drivebaseSubsystem;


    static std::shared_ptr<NetworkTable> visionTable;
	static frc::DriverStation::Alliance currentAlliance;

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


#endif /* SRC_ROBOT_H_ */
