// Controller.cpp
#include "Controller.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
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

void Controller::readData(std::string videos[])
{
    int index = 0;
    // read positive videos
    for (auto& p : fs::directory_iterator(dataPath + "positive/"))
    {
        videos[index] = p.path();
        index++;
    }
    // read negative videos
    for (auto& p : fs::directory_iterator(dataPath + "negative/"))
    {
        videos[index] = p.path();
        index++;
    }
}

void Controller::shuffleData(std::string videos[], int length)
{
    srand(time(0)); // initialize seed "randomly"
    for (int i = 0; i < length; ++i)
    {
        int r = rand() % length;
        std::string temp = videos[i];
        videos[i] = videos[r];
        videos[r] = temp;
    }
}

void Controller::run()
{
    const int VIDEOS_SIZE = 1750;
    std::string videos[VIDEOS_SIZE];
    readData(videos);
    shuffleData(videos, VIDEOS_SIZE);
    for (int i = 0; i < VIDEOS_SIZE; ++i)
    {
        std::cout << i << std::endl;
        std::cout << videos[i] << std::endl;
	annotator.setVideoPath(videos[i]);
	annotator.run();
    }
}
