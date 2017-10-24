// Annotate.h
#ifndef ANNOTATE_H_
#define ANNOTATE_H_

#include "Label.h"
#include <string>
#include <forward_list>

class Annotate
{
	private:
		std::string positivePath;
		std::string negativePath;
		std::forward_list<Label> labels;
		void readAndStore(std::string path);
	public:
		Annotate();
		Annotate(const std::string& dataPath); 
		void readVideos();
};

#endif /* ANNOTATE_H_ */
