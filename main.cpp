#include "Controller.h"
#include <string>

int main(int argc, char* argv[])
{
    int beginFrame = 40;
    int endFrame = 60;
    int delay = 33;
    std::string videoPath = "/home/gary/datasets/accv/positive/000310.mp4";
    std::string dataPath = "/home/gary/datasets/accv/";
    std::string fileName = "annotations.txt";
    Controller ctr(dataPath, beginFrame, endFrame, delay, fileName);
    ctr.run();
    return 0;
}
