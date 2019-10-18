#include "FileCreatorCommand.h"
#include "CommandBuilder.h"
#include "WorkerThread.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <atomic>


int main(int argc, char** argv)
{
	std::unique_ptr<Queue<ICommand*>> commandQueuePtr(new Queue<ICommand*>);
	HISTORY_LIST historyList;
	WorkerThread worker(commandQueuePtr.get());


	std::cout << "Please choose one of following command: " << std::endl;
	std::cout << "file-create <file-content> <file-name> " << std::endl;
	std::cout << "history - to see command history" << std::endl;
	std::cout << "quit - to quit the app" << std::endl;


	CommandBuilder builder(historyList);
	while (builder.isRunning())
	{
		std::cin >> builder;
		ICommand* command = builder.createCommand();
		commandQueuePtr->push(command);
	}

}