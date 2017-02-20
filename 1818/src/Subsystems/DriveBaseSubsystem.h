#ifndef DriveBaseSubsystem_H
#define DriveBaseSubsystem_H
#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include <Victor.h>
#include <AHRS.h>

class DriveBaseSubsystem: public frc::Subsystem {
private:
	    std::shared_ptr<Victor> frontLeftVictor;
		std::shared_ptr<Victor> frontRightVictor;
		std::shared_ptr<Victor> backLeftVictor;
		std::shared_ptr<Victor> backRightVictor;
		std::shared_ptr<RobotDrive> robotDrive;
		std::shared_ptr<AHRS> adjustedYaw;

public:
	DriveBaseSubsystem();
	void InitDefaultCommand() override;
	void MecanumDrive(float x, float y, float rot, float gyro);
	//void MecanumDrive(frc::XboxController*joystick);
	double GetAngle();
};

#endif  // DriveBaseSubsystem_H
