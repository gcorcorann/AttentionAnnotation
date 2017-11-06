// Controller.cpp
#include "Controller.h"
#include <string>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Controller::Controller(const std::string& dataPath, int beginFrame, 
    int endFrame, int delay, const std::string& fileName)
{
    setDataPath(dataPath);
    setFrameRanges(beginFrame, endFrame);
    setDelay(delay);
    setAnnotationFile(fileName);
}

void Controller::setAnnotationFile(const std::string& fileName)
{
    annotator.setAnnotationFile(fileName);
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
    int count = 0;
    // for positive videos
    for (auto& p : fs::directory_iterator(dataPath + "positive/"))
    {
        count++;
        std::cout << count << std::endl;
        std::cout << p.path() << std::endl;
	annotator.setVideoPath(p.path());
	annotator.run();
    }
    // for negative videos
    for (auto& p : fs::directory_iterator(dataPath + "negative/"))
    {
        count++;
        std::cout << count << std::endl;
    	std::cout << p.path() << std::endl;
    	annotator.setVideoPath(p.path());
    	annotator.run();
    }
}
