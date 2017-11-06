// Label.h
#ifndef LABEL_H_
#define LABAL_H_

#include <string>

class Label
{
    private:
    	int category;
    	std::string videoPath;
    public:
    	Label();
    	void setCategory(const int& cat);
    	void setVideoPath(const std::string& path);
    	int getCategory() { return category; }
    	const std::string& getVideoPath() { return videoPath; }
};

#endif /* LABEL_H_ */
