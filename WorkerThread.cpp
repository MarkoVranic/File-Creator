#include "WorkerThread.h"

WorkerThread::WorkerThread(Queue<ICommand*>* commandQueuePtr)
	: m_running(true)
	, m_commandQueuePtr(commandQueuePtr)
	, m_threadHandler(&WorkerThread::work, this)
{
}

WorkerThread::~WorkerThread()
{
	if (m_threadHandler.joinable())
		m_threadHandler.join();
}

void WorkerThread::work()
{
	while (m_running)
	{
		try {
			ICommand* currCommand = m_commandQueuePtr->pop();
			if (currCommand)
			{
				if (!currCommand->execute())
				{
					//stop worker
					m_running = false;
				}
			}
		}
		catch (Err& err)
		{
			std::cout << "Error: " << err.message() << " on: " << err.file() << " " << err.function() << " " << err.line() << std::endl;
		}
		catch (...)
		{
			std::cout << "Unknown error!";
		}
	}
}
