#pragma once
#include "File.h"

class FileHandler
{
public:
	FileHandler() = default;
	virtual ~FileHandler() = default;

	void setHandler(FileHandler* _fileHandler)
	{
		m_nextHandler = _fileHandler;
	}

	virtual void processFile(File* _file) = 0;

protected:
	FileHandler* m_nextHandler;
};
