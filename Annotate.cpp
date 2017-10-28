// Annotate.cpp
#include "Annotate.h"
#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

Annotate::Annotate(const std::string& VideoPath)
{
	label.setVideoPath(VideoPath);
	beginFrame = -1;
	stopFrame = -1;
	delay = 0;
}

Annotate::Annotate(const std::string& videoPath, int beginFrame_, int stopFrame_, int
		delay_)
{
	label.setVideoPath(videoPath);
	beginFrame = beginFrame_;
	stopFrame = stopFrame_;
	delay = delay_;
}

/**
 * Open videos located at videoPath.
 *
 * @return	true if the video is opened, else false
 */
bool Annotate::openVideo()
{
	// open video
	cap.open(label.getVideoPath());
	// check if we succeeded
	if (!cap.isOpened())
	{ 
		std::cout << "Could not open video." << std::endl;
		return false;
	}
	else
	{
		std::cout << "Video opened." << std::endl;
		return true;
	}
}

/**
 * Reads next video frame.
 *
 * @param[out]	frame	stores current frame at this location
 *
 * @return		true if next frame is read, else false
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

/**
 * Grabs keyboard video controls from user.
 *
 * @param[out]	pause	true if user paused video, else false
 *
 * @return		return false if user presses 'q', else return true
 */
bool Annotate::userVideoControls(bool& pause)
{
	char key = cv::waitKey(delay);
	if (key == char('q'))
	{
		std::cout << "Video closed." << std::endl;
		return false;
	}
	else if (key == char('p'))
	{
		if (!pause) { std::cout << "Video paused." << std::endl; }
		else { std::cout << "Video unpaused." << std::endl; }
		pause = !pause;
		return true;
	}
	else { return true; }
}

/**
 * Check if we have reached stopFrame.
 *
 * @param	findex		current frame index
 *						@pre >= 0 and <= total number of frames
 *
 * @return	false if we are currently at stopFrame, else true
 */
bool Annotate::checkFrame(int findex)
{
	if (findex == stopFrame)
	{
		std::cout << "Reached stop frame." << std::endl;
		return false;
	}
	else { return true; }
}

/**
 * Release video and display resources.
 *
 * @param	none
 *
 * @return	nothing
 */
void Annotate::release()
{
	cv::destroyAllWindows();
	cap.release();
}

/**
 * Displays selected range of video frames to user.
 *
 * @return	nothing
 */
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
	cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
	// count frame index
	int fcount = beginFrame;
	// pause flag
	bool pause = false;
	while (fcount != stopFrame)
	{
		// check if video is paused
		if (!pause) {
			// read new frame
			if (!readFrame(frame)) { break; }
			// increase frame index
			fcount++;
			// check if we reached stopFrame
			if (!checkFrame(fcount)) { break; }
			// display frame
			cv::imshow("Frame", frame);
		}
		// grab user's input
		if (!userVideoControls(pause)) { break; }
	}
	// release resources
	release();
}

/**
 * Grab annotation from user.
 *
 * @param	none
 *
 * @return	nothing
 */
int Annotate::getAnnotation()
{
	int label = 0;
	std::string s;
	// wait for user to enter a correct range of labels
	for (;;)
	{
		std::cout << "Enter annotation label [1-4]: ";
		getline(std::cin, s);	
		std::stringstream(s) >> label;
		if (label == 1 || label == 2 || label == 3 || label == 4) { break; }
		else { std::cout << "Please try again..." << std::endl; }
	}
	return label;
}

void Annotate::setFrameRanges(int beginFrame_, int stopFrame_)
{
	beginFrame = beginFrame_;
	stopFrame = stopFrame_;
}

void Annotate::setVideoPath(const std::string& videoPath)
{
	label.setVideoPath(videoPath);
}

void Annotate::setDelay(int delay_)
{
	delay = delay_;
}

void Annotate::run()
{
	// display video and grab user video control inputs
	displayVideo();
	// get video annotation from user
	int category = getAnnotation();
	// store label information in Label object
	label.setCategory(category);
}
