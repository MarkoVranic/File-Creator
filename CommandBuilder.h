#ifndef _COMMAND_BUILDER_H
#define _COMMAND_BUILDER_H

#include <iostream>
#include <stdio.h>
#include <atomic>

#include "ICommand.h"

class CommandBuilder {
public:
	CommandBuilder(const HISTORY_LIST& hList);

	ICommand* createCommand();
	bool isRunning() const { return m_running; }

	friend std::istream& operator >> (std::istream& in, CommandBuilder& cb);	

private:
	CommandType  m_type;
	HISTORY_LIST m_hList;
	std::atomic<bool> m_running;
};

#endif //_COMMAND_BUILDER_