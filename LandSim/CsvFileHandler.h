#pragma once
#include "FileHandler.h"

class CsvFileHandler : public FileHandler
{
public:
	void processFile(File* _file) override;
};

