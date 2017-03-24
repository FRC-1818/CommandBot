#include <Commands/AutoCenter.h>
#include <Commands/Autonomous/AutonomousCenter.h>
#include <Commands/Vision/VisionLineup.h>
#include <Commands/GoForward.h>

AutoCenter::AutoCenter() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());

	AddSequential(new AutonomousCenter());
	AddSequential(new VisionLineup());
	AddSequential(new GoForward());


	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
