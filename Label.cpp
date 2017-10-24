// Label.cpp
#include "Label.h"
#include <string>

Label::Label() : category(-1), videoPath("") {}

Label::Label(std::string path) : category(-1), videoPath(path) {}

Label::Label(int cat, std::string path) : category(cat), videoPath(path) {}

void Label::storeCategory(int cat)
{
	category = cat;
}

void Label::storeVideoPath(std::string vid)
{
	videoPath = vid;
}				
