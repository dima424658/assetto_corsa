#pragma once

class ThreadPool
{
void ThreadPool(int inumThreads, std::function<void __cdecl(int)> initFun);
ThreadPool *`vector deleting destructor'(unsigned int a2);
void ~ThreadPool();
void addTask(Task *task);

};