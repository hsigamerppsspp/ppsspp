#include "ThreadPools.h"

#include "../Core/Config.h"
#include "Common/MakeUnique.h"

std::unique_ptr<ThreadPool> GlobalThreadPool::pool;
std::once_flag GlobalThreadPool::init_flag;

void GlobalThreadPool::Loop(const std::function<void(int,int)>& loop, int lower, int upper, int minSize) {
	std::call_once(init_flag, Inititialize);
	pool->ParallelLoop(loop, lower, upper, minSize);
}

void GlobalThreadPool::Memcpy(void *dest, const void *src, int size) {
	std::call_once(init_flag, Inititialize);
	pool->ParallelMemcpy(dest, src, size);
}

void GlobalThreadPool::Memset(void *dest, uint8_t val, int size) {
	std::call_once(init_flag, Inititialize);
	pool->ParallelMemset(dest, val, size);
}

void GlobalThreadPool::Inititialize() {
	pool = make_unique<ThreadPool>(g_Config.iNumWorkerThreads);
}
