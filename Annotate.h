// Annotate.h
#ifndef ANNOTATE_H_
#define ANNOTATE_H_

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class Annotate
{
	private:
		std::string videoPath; // path of video
		cv::VideoCapture cap;  // videocapture object
		int beginFrame;		   // start displaying video at this frame
		int stopFrame;		   // stop displaying video at this frame
		bool openVideo();
		bool readFrame(cv::Mat& frame);
	public:
		/**
		 * Annotate constructor
		 *
		 * @param videoPath_		path to video
		 *
		 */
		Annotate(std::string videoPath_);

		/**
		 * Annotate constructor.
		 *
		 * @param videoPath_		path to video
		 * @param beginFrame_	display video starting at this frame index
		 *						@pre >=0 & <= total frames in video
		 * @param stopFrame_		stop displaying video at this frame index
		 *							video
		 */
		Annotate(std::string videoPath_, int beginFrame_, int stopFrame_);

		/**
		 * Set the range of frames to display.
		 *
		 * @param beginFrame_		display video starting at this frame index
		 *							@pre >= 0 & <= total frames in video
		 * @param stopFrame_		stop displaying video at this frame index
		 *							@pre >= beginFrame_ & <= total frames in
		 *							video
		 * @returns		nothing
		 */
		void setFrameRanges(int beginFrame_, int stopFrame_);

		/**
		 * Displays selected range of video frames.
		 *
		 * @returns		nothing
		 */
		void displayVideo();

};

#endif /* ANNOTATE_H_ */
