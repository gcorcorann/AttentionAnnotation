#include "Annotate.h"
#include <string>

int main(int argc, char* argv[])
{
	std::string dataPath = "/home/gary/datasets/accv/";
	Annotate ann(dataPath); // video annotation object
	ann.readVideos();
	return 0;
}
