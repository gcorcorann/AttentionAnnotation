// Annotate.cpp
#include "Annotate.h"
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

Annotate::Annotate(std::string VideoPath_)
{
	videoPath = videoPath;
	beginFrame = -1;
	stopFrame = -1;
}

Annotate::Annotate(std::string videoPath_, int beginFrame_, int stopFrame_)
{
	videoPath = videoPath_;
	beginFrame = beginFrame_;
	stopFrame = stopFrame_;
}

/**
 * Open videos located at videoPath.
 *
 * @returns		true if the video is opened, else false
 */
bool Annotate::openVideo()
{
	// open video
	cap.open(videoPath);
	// check if we succeeded
	if (!cap.isOpened())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**
 * Reads next video frame.
 *
 * @param[out] frame	stores current frame at this location
 *
 * @returns 	true if next frame is read, else false
 */
bool Annotate::readFrame(cv::Mat& frame)
{
	if (!cap.read(frame))
	{
		std::cout << "End of file." << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void Annotate::setFrameRanges(int beginFrame_, int stopFrame_)
{
	beginFrame = beginFrame_;
	stopFrame = stopFrame_;
}

void Annotate::displayVideo()
{
	// check if we can open video
	if (!openVideo()) { return; }

	// set video to start at frame
	if (!cap.set(CV_CAP_PROP_POS_FRAMES, beginFrame))
	{
		std::cout << "Error with beginFrame." << std::endl;
		return;
	}

	// store video frame	
	cv::Mat frame;
	// 
	cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
	
	// count frame index
	int fcount = beginFrame;

	while (fcount != stopFrame)
	{
		// read new frame
		if (!readFrame(frame))
		{
			std::cout << "End of file." << std::endl;
			return;
		}
		// increase frame index
		fcount++;
		if (fcount == stopFrame)
		{
			std::cout << "Reached stop frame." << std::endl;
			return;
		}
		// display frame
		cv::imshow("Frame", frame);
		// wait for user input
		if (cv::waitKey(33) == char('q'))
		{
			std::cout << "Video Closed." << std::endl;
			break;
		}
	}
}
