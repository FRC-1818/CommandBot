#include "AutonomousCenter.h"

AutonomousCenter::AutonomousCenter() {
	AddSequential(new DriveForward);
}
