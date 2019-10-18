#ifndef _QUIT_COMMAND_
#define _QUIT_COMMAND_

#include <iostream>

#include "ICommand.h"

class QuitCommand : public ICommand {

public:
	virtual bool execute() override;

};


#endif // _FILE_CREATOR_COMMAND_
