#include<Robot.h>
//#include <memory>
//#include<timer.h>
//#include <Commands/Command.h>
//#include <Commands/Scheduler.h>
//#include <IterativeRobot.h>
//#include <LiveWindow/LiveWindow.h>
//#include <SmartDashboard/SendableChooser.h>
//#include <SmartDashboard/SmartDashboard.h>
//#include <XboxController.h>
//#include "CommandBase.h"
//#include <Victor.h>
#include "Commands/Autonomous/AutonomousCenter.h"
#include "Commands/Drive/DriveCommand.h"
#include "Commands/Drive/Camera.h"


std::shared_ptr<DriveBaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<HopperSubsystem> Robot::hopperSubsystem;
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<I2C> Robot::i2c;
std::shared_ptr<CameraSubsystem> Robot::cameraSubsystem;
std::shared_ptr<DigitalInput> Robot::upLimit;
std::shared_ptr<DigitalInput> Robot::downLimit;
//DriverStation::Alliance Robot::currentAlliance;


	void Robot::RobotInit(){
		RobotMap::init();
		drivebaseSubsystem.reset(new DriveBaseSubsystem());
		climberSubsystem.reset(new ClimberSubsystem());
		hopperSubsystem.reset(new HopperSubsystem());
		elevatorSubsystem.reset(new ElevatorSubsystem());
		cameraSubsystem.reset(new CameraSubsystem());
		oi.reset(new OI());
		driveCommand.reset(new DriveCommand());
		cameraCommand.reset(new Camera());
		//currentAlliance = DriverStation::GetInstance().GetAlliance();
		//SmartDashboard::PutBoolean("Do Boiler", &doBoiler);
		//autoChooser.AddDefault("AutonomousCenter", new AutonomousCenter());
		//SmartDashboard::PutData("Auto Mode Chooser", &autoChooser);
	}

	void Robot::DisabledInit(){

	}

	void Robot::DisabledPeriodic(){
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::AutonomousInit(){
		selectedMode.reset(autoChooser.GetSelected());
			if(selectedMode != nullptr){
				selectedMode->Start();
			}
	}

	void Robot::AutonomousPeriodic(){
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit(){
		if (selectedMode != nullptr) {
				selectedMode->Cancel();
			}
		driveCommand->Start();
	}

	void Robot::TeleopPeriodic(){
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic(){

	}

START_ROBOT_CLASS(Robot)
