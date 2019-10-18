#include "CommandBuilder.h"
#include "FileCreatorCommand.h"
#include "HistoryCommand.h"
#include "QuitCommand.h"

#include <sstream>

CommandBuilder::CommandBuilder(const HISTORY_LIST& hList)
	:m_hList(hList),
	m_running(true)
{
}

ICommand* CommandBuilder::createCommand()
{
	switch (m_type) 
	{
	case CommandType::FILE_CREATOR:
		{
		    auto size = m_hList.size();
			if (size)
			{
				auto filePair = m_hList[size-1];
				return new FileCreatorCommand(filePair.second, filePair.first);
			} 
		}
	case CommandType::HISTORY:
		{
			return new HistoryCommand(m_hList);
		}
	case CommandType::QUIT:
		{
		    m_running = false;
			return new QuitCommand();
		}
	}

	THROW_MESSAGE(ERR_NOT_IMPLEMENTED, "Non known Command detected");
}


std::istream& operator >> (std::istream& in, CommandBuilder& cb)
{
	std::string command;
	in >> command;
	
	if (command == "history")
	{
		cb.m_type = CommandType::HISTORY;
		return in;
	}
	else if (command == "quit")
	{
		cb.m_type = CommandType::QUIT;
		return in;
	}

	else if (command == "file-create")
	{
		std::string fileContent;
		std::string fileName;
		in >> fileContent >> fileName ;
		cb.m_type = CommandType::FILE_CREATOR;

		cb.m_hList.push_back(std::make_pair(fileContent, fileName));
		
		return in;

	}
	
	THROW_MESSAGE(ERR_NOT_IMPLEMENTED, "Non known Command detected");
}