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

std::shared_ptr<DriveBaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<Joystick> Robot::joystick;
std::unique_ptr<OI> Robot::oi;
bool Robot::doBoiler;
DriverStation::Alliance Robot::currentAlliance;


	void Robot::RobotInit(){
		RobotMap::init();
		drivebaseSubsystem.reset(new DriveBaseSubsystem());
		climberSubsystem.reset(new ClimberSubsystem());
		oi.reset(new OI());
		currentAlliance = DriverStation::GetInstance().GetAlliance();
		doBoiler = true;
		SmartDashboard::PutBoolean("Do Boiler", &doBoiler);
		autoChooser.AddDefault("AutonomousCenter", new AutonomousCenter());
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
		//climberCommand(new Climber(1.0, 0.5));
	}

	void Robot::TeleopPeriodic(){
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic(){

	}

/*private:
	std::unique_ptr<frc::Command> autonomousCommand;
	//std::unique_ptr<frc::Command> climberCommand;
	frc::SendableChooser<frc::Command*> chooser;
	frc::RobotDrive myRobot { 1, 2, 3, 4 };
	frc::Joystick leftstick { 0 };
	frc::Timer timer;
	frc::Victor climber;
	I2C* i2c; //Declare i2c
	Servo*servo; //not necessary unless you need servo. I used this for testing purpose
	SmartDashboard * dash; // not necessary
*/

START_ROBOT_CLASS(Robot)
