
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <assert.h>
#include <chrono>
#include <atomic>
#include "Queue.h"
#include "ICommand.h"

class WorkerThread
{
public:
	WorkerThread(Queue<ICommand*>* commandQueuePtr);

	WorkerThread(const WorkerThread&) = delete;
	WorkerThread& operator=(const WorkerThread&) = delete;

	~WorkerThread();

	void work();

private:

	bool  m_running;
	Queue<ICommand*>*  m_commandQueuePtr;
	std::thread        m_threadHandler;
};

