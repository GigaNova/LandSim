#pragma once
#include "AbstractFileLoader.h"
#include <vector>

class FileLoaderFactory
{
public:
	FileLoaderFactory();

	AbstractFileLoader* getFileLoader(std::string _filePath);
private:
	std::vector<AbstractFileLoader*> m_fileLoaders;
};

