#pragma once
#include <string>
#include <regex>

class File
{
public:
	const std::regex URL_REGEX = std::regex(R"(http:\/\/|https:\/\/|www.)");

	File(std::string _fileUrl);

	bool isOnline() const;
	std::string getFileUrl() const;
private:
	std::string m_fileUrl;
	bool m_isOnline;
};
