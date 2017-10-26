#include "Annotate.h"
#include <string>

int main(int argc, char* argv[])
{
	int beginFrame = 40;
	int endFrame = 60;
	std::string videoPath = "/home/gary/datasets/accv/positive/000310.mp4";
	// video annotator object
	Annotate annotate(videoPath, beginFrame, endFrame);
	annotate.displayVideo();
	return 0;
}
