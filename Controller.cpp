// Controller.cpp
#include "Controller.h"
#include <string>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Controller::Controller(const std::string& dataPath, int beginFrame, 
    int endFrame, int delay)
{
    setDataPath(dataPath);
    setFrameRanges(beginFrame, endFrame);
    setDelay(delay);
}

void Controller::setFrameRanges(int beginFrame, int endFrame)
{
    annotator.setFrameRanges(beginFrame, endFrame);
}

void Controller::setDelay(int delay)
{
    annotator.setDelay(delay);
}

void Controller::setDataPath(const std::string& dataPath_)
{
    dataPath = dataPath_;
}

void Controller::run()
{
    // for positive videos
    for (auto& p : fs::directory_iterator(dataPath + "positive/"))
    {
        std::cout << p.path() << std::endl;
	annotator.setVideoPath(p.path());
	annotator.run();
    }
    // for negative videos
    for (auto& p : fs::directory_iterator(dataPath + "negative/"))
    {
    	std::cout << p.path() << std::endl;
    	annotator.setVideoPath(p.path());
    	annotator.run();
    }
}
