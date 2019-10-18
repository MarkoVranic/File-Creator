#include "HistoryCommand.h"

HistoryCommand::HistoryCommand(HISTORY_LIST& history)
	:m_historyList(history)
{
}

bool HistoryCommand::execute()
{
	for (auto historyItem : m_historyList)
	{
		std::cout << "file content: " << historyItem.first.data()
			<< ", " << "file name: " << historyItem.second.data()
			<< std::endl;
	}

	if (m_historyList.empty())
	{
		std::cout << "No history available, please try some command." << std::endl;
	}

	return true;
}