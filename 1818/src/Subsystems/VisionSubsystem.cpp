#include <Subsystems/VisionSubsystem.h>

VisionSubsystem::VisionSubsystem() : Subsystem("VisionSubsystem") {

	uint16_t numBlocks = 0;

		printf("blocks: ");
	numBlocks = getBlocks(3);
		printf("%d", numBlocks);
		printf("\n");

		blocks[0].print();
		blocks[1].print();
		printf("\n");

		increment_since_last_find++;

		if(numBlocks > 0) {
			 LeftX = blocks[0].x;
			 LeftWidth = blocks[0].width;

			 RightX = blocks[1].x;
			 RightWidth = blocks[1].width;

			increment_since_last_find = 0;
         }
}

void VisionSubsystem::InitDefaultCommand() {

}

void VisionSubsystem::getBlock(){
	uint16_t numBlocks = getBlocks(3);
	printf("blocks: ");
	printf("%d", numBlocks);
	printf("\n");

	blocks[0].print();
	blocks[1].print();
	printf("\n");

	increment_since_last_find++;
}

int VisionSubsystem::leftX(){
	int x1 = LeftX;
	return x1;
}

int VisionSubsystem::leftWidth(){
	int w1 = LeftWidth;
	return w1;
}

int VisionSubsystem::rightX(){
	int x2 = RightX;
	return x2;
}

int VisionSubsystem::rightWidth(){
	int w2 = RightWidth;
	return w2;
}
