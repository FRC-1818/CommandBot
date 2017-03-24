#include<Robot.h>
#include <Commands/Scheduler.h>
#include <Commands/Command.h>
#include "Commands/Autonomous/AutonomousCenter.h"
#include "Commands/Autonomous/AutonomousLeft.h"
#include "Commands/Autonomous/AutonomousRight.h"
#include "Commands/Drive/DriveCommand.h"
#include "Commands/Drive/Camera.h"
#include "Commands/AutoCenter.h"
#include "Commands/GoForward.h"
#include "Commands/Climber/Climbon.h"
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <WPILib.h>

//#include <memory>
//#include <IterativeRobot.h>
//#include <LiveWindow/LiveWindow.h>

std::shared_ptr<DriveBaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<HopperSubsystem> Robot::hopperSubsystem;
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem;
std::unique_ptr<OI> Robot::oi;
//std::shared_ptr<I2C> Robot::i2c;
std::shared_ptr<CameraSubsystem> Robot::cameraSubsystem;
//std::shared_ptr<VisionSubsystem> Robot::visionSubsystem;
//std::shared_ptr<DigitalInput> Robot::upLimit;
//std::shared_ptr<DigitalInput> Robot::downLimit;
std::shared_ptr<DigitalInput> Robot::switch1;
//std::shared_ptr<DigitalInput> Robot::switch2;
//std::shared_ptr<DigitalInput> Robot::switch3;
//DriverStation::Alliance Robot::currentAlliance;


	void Robot::RobotInit(){
		printf("1\n");
		RobotMap::init();
		printf("2\n");
		drivebaseSubsystem.reset(new DriveBaseSubsystem());
		printf("2.1\n");
		climberSubsystem.reset(new ClimberSubsystem());
		printf("2.2\n");
		hopperSubsystem.reset(new HopperSubsystem());
		printf("2.3\n");
		elevatorSubsystem.reset(new ElevatorSubsystem());
		printf("2.4\n");
		cameraSubsystem.reset(new CameraSubsystem());
		printf("2.5\n");
		//visionSubsystem.reset(new VisionSubsystem());
		printf("3\n");
		//i2c.reset(new I2C());
		oi.reset(new OI());
		driveCommand.reset(new DriveCommand());
		cameraCommand.reset(new Camera());
		climberCommand.reset(new Climbon());
		autoCenter.reset(new AutoCenter());
		goForward.reset(new GoForward());
		autonomousLeft.reset(new AutonomousLeft);
		autonomousRight.reset(new AutonomousRight);
		printf("4\n");

		switch1.reset(new frc::DigitalInput(1));
		printf("5\n");
		//switch2.reset(new frc::DigitalInput(2));
		//switch3.reset(new frc::DigitalInput(3));
		//upLimit.reset(new frc::DigitalInput(1));
		//downLimit.reset(new frc::DigitalInput(2));

		CameraServer::GetInstance()->StartAutomaticCapture(0);
		printf("6\n");
		//currentAlliance = DriverStation::GetInstance().GetAlliance();

		autoChooser.AddObject("autonomousCenter", new AutonomousCenter());
		autoChooser.AddObject("autonomousLeft"  , new AutonomousLeft());
		autoChooser.AddObject("autonomousRight" , new AutonomousRight());
		printf("7\n");
		SmartDashboard::PutData("Auto Mode Chooser", &autoChooser);
		printf("8\n");
	}

	void Robot::DisabledInit(){

	}

	void Robot::DisabledPeriodic(){
		printf("disabled\n");
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
			goForward->Start();
		}
		//if(switch2->Get()){
			//goForward->Start();
		//}

	}

	void Robot::TeleopInit(){
		if (selectedMode != nullptr) {
				selectedMode->Cancel();
			}
		//autoCenter->Cancel();    //Cnacle Autonomus
		goForward->Cancel();
		autonomousLeft->Cancel();      //Cnacle Autonomus
		autonomousRight->Cancel();     //Cnacle Autonomus
		driveCommand->Start();         //Jostick Driving starts
		cameraCommand->Start();        //Camera Servo Starts
		climberCommand->Start();       //Joystick Climbing starts
	}

	void Robot::TeleopPeriodic(){
		frc::Scheduler::GetInstance()->Run();

		/*if(oi->GetLeftStickButton())  //Push LeftStick cancle Hopper Command
		{
			frc::Scheduler::GetInstance()->RemoveAll;
		}*/
	}

	void Robot::TestPeriodic(){

	}

START_ROBOT_CLASS(Robot)
