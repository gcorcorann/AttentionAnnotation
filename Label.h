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
		Label(std::string);
		Label(int, std::string);
		void storeCategory(int cat);
		void storeVideoPath(std::string path);
		int getCategory() { return category; }
		std::string getVideoPath() { return videoPath; }
};

#endif /* LABEL_H_ */
