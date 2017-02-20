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
#include "Commands/Autonomous/AutonomousLeft.h"
#include "Commands/Autonomous/AutonomousRight.h"
#include "Commands/Autonomous/AutonomousStright.h"
#include "Commands/Drive/DriveCommand.h"
#include "Commands/Drive/Camera.h"
#include "AHRS.h"

std::shared_ptr<DriveBaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<HopperSubsystem> Robot::hopperSubsystem;
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<I2C> Robot::i2c;
std::shared_ptr<CameraSubsystem> Robot::cameraSubsystem;
std::shared_ptr<DigitalInput> Robot::upLimit;
std::shared_ptr<DigitalInput> Robot::downLimit;
std::shared_ptr<DigitalInput> Robot::switch1;
std::shared_ptr<DigitalInput> Robot::switch2;
std::shared_ptr<DigitalInput> Robot::switch3;
std::shared_ptr<DigitalInput> Robot::switch4;
//DriverStation::Alliance Robot::currentAlliance;
//std::shared_ptr<AHRS> ahrs;             // navX MXP


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
		autonomousCenter.reset(new AutonomousCenter());
		autonomousLeft.reset(new AutonomousLeft());
		autonomousRight.reset(new AutonomousRight());
		autonomousStright.reset(new AutonomousStright());

		//upLimit.reset(new frc::DigitalInput(1));
		//downLimit.reset(new frc::DigitalInput(2));
		//switch1.reset(new frc::DigitalInput(6));
		//switch2.reset(new frc::DigitalInput(7));
		//switch3.reset(new frc::DigitalInput(8));
		//switch4.reset(new frc::DigitalInput(9));
		CameraServer::GetInstance()->StartAutomaticCapture(0);

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
		if(switch1->Get()){
			autonomousCenter->Start();
		}

		if(switch2->Get()){
			autonomousLeft->Start();
		}

		if(switch3->Get()){
			autonomousRight->Start();
		}

		if(switch4->Get()){
			autonomousStright->Start();
		}
	}

	void Robot::TeleopInit(){
		if (selectedMode != nullptr) {
				selectedMode->Cancel();
			}
		autonomousCenter->Cancel();
		autonomousLeft->Cancel();
		autonomousRight->Cancel();
		autonomousStright->Cancel();
		driveCommand->Start();
	}

	void Robot::TeleopPeriodic(){
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic(){

	}

START_ROBOT_CLASS(Robot)
