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
#include "Commands/Drive/DriveCommand.h"
#include "Commands/Drive/Camera.h"


std::shared_ptr<DriveBaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<HopperSubsystem> Robot::hopperSubsystem;
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<I2C> Robot::i2c;
std::shared_ptr<CameraSubsystem> Robot::cameraSubsystem;

//std::shared_ptr<DigitalInput> Robot::upLimit;
//std::shared_ptr<DigitalInput> Robot::downLimit;
//std::shared_ptr<DigitalInput> Robot::switch1;
//std::shared_ptr<DigitalInput> Robot::switch2;
//std::shared_ptr<DigitalInput> Robot::switch3;

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
		autonomousCenter.reset(new AutonomousCenter);
		autonomousLeft.reset(new AutonomousLeft);
		autonomousRight.reset(new AutonomousRight);

		//switch1.reset(new frc::DigitalInput(1));
		//switch2.reset(new frc::DigitalInput(2));
		//switch3.reset(new frc::DigitalInput(3));
		//upLimit.reset(new frc::DigitalInput(1));
		//downLimit.reset(new frc::DigitalInput(2));

		CameraServer::GetInstance()->StartAutomaticCapture(0);

		//currentAlliance = DriverStation::GetInstance().GetAlliance();

		autoChooser.AddObject("autonomousCenter", new AutonomousCenter());
		autoChooser.AddObject("autonomousLeft"  , new AutonomousLeft());
		autoChooser.AddObject("autonomousRight" , new AutonomousRight());

		SmartDashboard::PutData("Auto Mode Chooser", &autoChooser);
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
		//autonomousCenter->Cancel();
		//autonomousLeft->Cancel();
		//autonomousRight->Cancel();
		driveCommand->Start();
		cameraCommand->Start();
	}

	void Robot::TeleopPeriodic(){
		frc::Scheduler::GetInstance()->Run();

		if(oi->GetLeftStickButton())
		{
			frc::Scheduler::GetInstance()->Remove(new Hopperon);
		}

		if(oi->GetRightStickButton())
		{
			frc::Scheduler::GetInstance()->Remove(new Elevator);
		}
	}

	void Robot::TestPeriodic(){

	}

START_ROBOT_CLASS(Robot)
