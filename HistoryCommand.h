#ifndef _HISTORY_COMMAND_
#define _HISTORY_COMMAND_

#include <iostream>
#include <vector>

#include "ICommand.h"

class HistoryCommand : public ICommand {

public:
	HistoryCommand(HISTORY_LIST& history);

	virtual bool execute() override;

private:
	HISTORY_LIST m_historyList;
};

#endif // _HISTORY_COMMAND_
