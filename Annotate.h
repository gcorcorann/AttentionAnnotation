// Annotate.h
#ifndef ANNOTATE_H_
#define ANNOTATE_H_

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class Annotate
{
    private:
        std::string vidPath;
        std::string fname;      // video annotations file
    	cv::VideoCapture cap;  	// videocapture object
    	int beginFrame;		// start displaying video at this frame
    	int stopFrame;		// stop displaying video at this frame
    	int delay;	        // delay between displaying frames [ms]
    	bool openVideo();
    	bool readFrame(cv::Mat& frame);
    	bool userVideoControls(bool& pause);    // grabs usersvideo controls
    	bool setBeginFrame();           // sets beginning frame of video
    	bool checkFrame(int findex);    // check if current frame == stopFrame
    	void displayVideo();
    	void release();		// release video and display resources
    	int getAnnotation();	// grabs user's annotation for video
    public:
        /**
         * Annotate constructor.
         *
         * @param   none
         *
         */
        Annotate() { };
        
        /**
         * Annotate constructor
         *
	 * @param   videoPath_  path to video
	 *
	 */
	Annotate(const std::string& videoPath);

        /**
         * Annotate constructor.
         *
         * @param   videoPath_  path to video
         * @param   beginFrame_     display video starting at this frame 
         *                          index @pre >=0 & <= total frames in
         *                          video
         * @param   stopFrame_  stop displaying video at this frame index
         *				video
         */
        Annotate(const std::string& videoPath, int beginFrame_, 
            int stopFrame_, int delay_);

	/**
         * Set the range of frames to display.
         *
         * @param   beginFrame_ display video starting at frame index
         *	    	        @pre >= 0 & <= total frames in video
         * @param   stopFrame_  stop displaying video at this frame index
         *		        @pre >= beginFrame_ & <= total frames in
         *		        video
         * @return  nothing
         */
    	void setFrameRanges(int beginFrame_, int stopFrame_);

        /**
         * Set video path.
         *
         * @param   videoPath_  path of video file
         *
         * @return  nothing
         */
        void setVideoPath(const std::string& videoPath_);

        /**
         * Set frame delay.
         *
         * @param   delay_  delay between frames [ms]
         *		    @pre >= 0
         *
         * @return  nothing
         */
        void setDelay(int delay_);

        /**
         * Set video annotation file name.
         *
         * @param fileName  video annotation file name
         *
         * @return  nothing
         */
        void setAnnotationFile(const std::string& fileName);

        /**
         * Run annotation for video stored in videoPath.
         *
         * @param   none
         *
         * @return  nothing
         */
        void run();
};

#endif /* ANNOTATE_H_ */
