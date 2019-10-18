#include "FileCreatorCommand.h"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <fstream>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

FileCreatorCommand::FileCreatorCommand(const std::string& content, const std::string& fileName)
: m_content(content),
m_fileName(fileName)
{
}

bool FileCreatorCommand::execute() 
{
	if (!fs::exists("codelathe"))
	{
		fs::create_directory("codelathe");
	}
	auto newFilePath = "codelathe/" + m_fileName + ".txt";
	std::ofstream newFile(newFilePath);
	newFile << m_content;

	return true;
}