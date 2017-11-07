// Controller.h
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Annotate.h"
#include <string>

class Controller
{
    private:
    	Annotate annotator;
    	std::string dataPath;
        void readData(std::string videos[]);
        void shuffleData(std::string videos[], int length);
    public:
    	/**
    	 * Controller constructor.
    	 *
    	 * @param   dataPath    path to dataset
	 *                      @pre must end in '/'
    	 * @param   beginFrame  beginning frame of display video
    	 *			@pre >= 0 & <= total number of frames
    	 * @param   endFrame    ending frame of display video
    	 *			@pre >= beginFrame & <= total number of frames
         * @param   fileName    name of video annotations text file
    	 *
    	 */
    	Controller(const std::string& dataPath, int beginFrame, int endFrame, 
            int delay, const std::string& fileName);
	
        /**
         * Sets annotion file.
         *
         * @param   fileName    name of file to store annotation labels
         *
         * @return  nothing
         */
        void setAnnotationFile(const std::string& fileName);

        /**
    	 * Set displaying frame ranges.
    	 *
    	 * @param   beginFrame	beginning frame to display video
    	 *		    	@pre >= 0 & <= total number of frames
    	 * @param   endFrame	end frame of displaying video
    	 *  			@pre >= beginFrame & <= total number of frame
    	 *
    	 * @return  nothing
    	 */
    	void setFrameRanges(int beginFrame, int endFrame);

    	/**
    	 * Set delay between displaying frames.
    	 *
    	 * @param   delay   delay between frames [ms]
    	 *		    @pre >= 0
    	 *
    	 * @return  nothing
    	 */
    	void setDelay(int delay);

    	/**
    	 * Set path of dataset.
    	 *
    	 * @param   dataPath_	path to dataset being used.
    	 *			@pre must contain 'positive' & 'negative'
    	 *			    subfolders
    	 *
    	 * @return  nothing
    	 */
    	void setDataPath(const std::string& dataPath_);
    	
    	/**
    	 * Run annotator on all videos in dataset.
    	 *
    	 * @param   none
    	 *
    	 * @return  nothing
    	 */
    	void run();

};

#endif /* CONTROLLER_H_ */
