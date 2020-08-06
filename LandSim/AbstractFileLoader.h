#pragma once
#include <fstream>

class AbstractFileLoader
{
public:
	AbstractFileLoader(std::string _extension) : m_extension(_extension) {};
	virtual ~AbstractFileLoader() = default;

	virtual void loadFile(std::ifstream& _file) = 0;

	std::string m_extension;
};
