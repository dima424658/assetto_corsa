#pragma once

class TimerProcess
{
void TimerProcess(int interval, std::function<void __cdecl(void)> callback);
void ~TimerProcess();
void step();

};