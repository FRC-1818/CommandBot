#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <RobotDrive.h>
#include <Timer.h>
#include "WPILib.h"
#include <DigitalInput.h>

class Robot: public frc::IterativeRobot {
public:
	Robot() {
		myRobot.SetExpiration(0.1);
		timer.Start();

	}

private:
	frc::RobotDrive myRobot { 1,2,3,4 };  // Robot drive system
	frc::Joystick stick { 0 };         // Only joystick
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	frc::Timer timer;


	void AutonomousInit() override {
		timer.Reset();
		timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		if (timer.Get() < 2.0) {
			myRobot.Drive(-0.5, 0.0);  // Drive forwards half speed
		} else {
			myRobot.Drive(0.0, 0.0);  // Stop robot
		}
	}

	void TeleopInit() override {

	}

	void TeleopPeriodic() override {
		// Drive with arcade style (use right stick)
		myRobot.ArcadeDrive(stick);
	}

	void TestInit() override {
		DigitalInput* Switch1;
		DigitalInput* Switch2;
		DigitalInput* Switch3;
		DigitalInput* Switch4;

		Switch1 = new DigitalInput(6);
		Switch2 = new DigitalInput(9);
		Switch3 = new DigitalInput(7);
		Switch4 = new DigitalInput(8);


		printf("switch1 %d", Switch1->Get() );
		printf("switch2 %d", Switch2->Get() );
		printf("switch3 %d", Switch3->Get() );
		printf("switch4 %d", Switch4->Get() );
	}

	void TestPeriodic() override {

		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
