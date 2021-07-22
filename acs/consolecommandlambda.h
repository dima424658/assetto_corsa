#pragma once

class ConsoleCommandLambda
{
void ConsoleCommandLambda(Console *console, const std::wstring *name, std::function<bool __cdecl(std::wstring)> executeFun, std::function<std::wstring __cdecl(void)> helpFun);
bool execute(std::wstring commandline);
std::wstring *getHelp(std::wstring *result);

};