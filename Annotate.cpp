// Annotate.cpp
#include "Annotate.h"
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Annotate::Annotate() : positivePath(""), negativePath("") {}

Annotate::Annotate(const std::string& dataPath)
{
	positivePath = dataPath + "positive/";
	negativePath = dataPath + "negative/";
}

void Annotate::readAndStore(const std::string path)
{
	for (auto& p : fs::directory_iterator(path))
	{
		Label lab(p.path());
		labels.push_front(lab);
	}
	return;
}

void Annotate::readVideos()
{
	// read and store positive and negative videos
	readAndStore(positivePath);
	readAndStore(negativePath);
	return;
}
