#include "File.h"
#include <regex>

File::File(const std::string _fileUrl) : m_fileUrl(_fileUrl)
{
	std::cmatch match;
	m_isOnline = std::regex_search(_fileUrl.c_str(), match, URL_REGEX);
}

bool File::isOnline() const
{
	return m_isOnline;
}

std::string File::getFileUrl() const
{
	return m_fileUrl;
}
