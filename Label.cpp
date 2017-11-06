// Label.cpp
#include "Label.h"
#include <string>

Label::Label() : category(-1), videoPath("") {}

void Label::setCategory(const int& cat)
{
    category = cat;
}

void Label::setVideoPath(const std::string& vid)
{
    videoPath = vid;
}				
