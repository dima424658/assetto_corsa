#pragma once

class ConsoleRefreshInstruments
{
void ConsoleRefreshInstruments(Console *con);
char execute(std::wstring commandLine);
std::wstring *getHelp(std::wstring *result);

};