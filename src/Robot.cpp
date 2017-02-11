#include<Robot.h>
#include <memory>
#include<timer.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <XboxController.h>
#include "CommandBase.h"
#include "Commands/AutonomousCenter.h"

std::shared_ptr<DriveBaseSubsystem> drivebaseSubsystem;
std::shared_ptr<ClimberSubsystem> climerSubsystem;
//std::shared_ptr<ServoSubsystem> servoSubsystem;

#define PIXY_INITIAL_ARRAYSIZE      30
#define PIXY_MAXIMUM_ARRAYSIZE      130
#define PIXY_START_WORD             0xaa55 //for regular color recognition
#define PIXY_START_WORD_CC          0xaa56 //for color code - angle rotation recognition
#define PIXY_START_WORDX            0x55aa //regular color another way around
#define PIXY_MAX_SIGNATURE          7
#define PIXY_DEFAULT_ARGVAL         0xffff

// Pixy x-y position values
#define PIXY_MIN_X                  0L   //x: 0~319 pixels, y:0~199 pixels. (0,0) starts at bottom left
#define PIXY_MAX_X                  319L
#define PIXY_MIN_Y                  0L
#define PIXY_MAX_Y                  199L

// RC-servo values - not needed unless you want to use servo to face the goal instead of moving the whole robot
#define PIXY_RCS_MIN_POS            0L
#define PIXY_RCS_MAX_POS            1000L
#define PIXY_RCS_CENTER_POS         ((PIXY_RCS_MAX_POS-PIXY_RCS_MIN_POS)/2)

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {
		RobotMap::init();
		drivebaseSubsystem.reset(new DriveBaseSubsystem());


		chooser.AddDefault("Default Auto", new AutonomousCenter());
		// chooser.AddObject("My Auto", new MyAutoCommand());
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
		myRobot.SetExpiration(0.1);
		timer.Start();
		CameraServer::GetInstance()->StartAutomaticCapture();
	}


	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}


	void AutonomousInit() override {
		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");

		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		timer.Reset();
		timer.Start();

		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
		climberCommand(new Climber(0.5,0.5));//call the Command and set the speed 0.5
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		myRobot.MecanumDrive_Cartesian(leftstick.GetRawAxis(1), // 0,1 is the X and Y axis of the leftstick
			                           leftstick.GetRawAxis(0),
									   -leftstick.GetRawAxis(4));
		if(leftstick.GetRawButton(5)){
			climberCommand->Start;//command starts
		}
		/*else{
			//climberCommand->Cancel();//command cancles
		}*/
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	std::unique_ptr<frc::Command> climberCommand;
	frc::SendableChooser<frc::Command*> chooser;
	frc::RobotDrive myRobot {1, 2, 3, 4};
	frc::Joystick leftstick {0};
	frc::Timer timer;

};

START_ROBOT_CLASS(Robot)
