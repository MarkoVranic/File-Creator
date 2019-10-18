#ifndef _ICOMMAND_
#define _ICOMMAND_

#include "Common.h"

enum class CommandType
{
	FILE_CREATOR,
	HISTORY,
	QUIT
};

class ICommand {

public:
	virtual bool execute() = 0;

	virtual ~ICommand() {}

};


#endif // _ICOMMAND_
