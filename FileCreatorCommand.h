#ifndef _FILE_CREATOR_COMMAND_
#define _FILE_CREATOR_COMMAND_

#include <iostream>
#include "ICommand.h"

class FileCreatorCommand : public ICommand {

public:
	FileCreatorCommand(const std::string& content, const std::string& fileName);

	virtual bool execute() override;

private:
	std::string m_content;
	std::string m_fileName;
};


#endif // _FILE_CREATOR_COMMAND_
