#include "FileLoaderFactory.h"

FileLoaderFactory::FileLoaderFactory()
{
	m_fileLoaders = {

	};
}

AbstractFileLoader* FileLoaderFactory::getFileLoader(std::string _filePath)
{
	return nullptr;
}
