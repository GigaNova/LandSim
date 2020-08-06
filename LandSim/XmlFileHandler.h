#pragma once
#include "FileHandler.h"

class XmlFileHandler : public FileHandler
{
public:
	void processFile(File* _file) override;
};

