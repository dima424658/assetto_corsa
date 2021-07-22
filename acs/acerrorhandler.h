#pragma once

class ACErrorHandler
{
void ACErrorHandler(Console *aconsole);
void ~ACErrorHandler();
void writeLine(std::wstring s);
void writeWarning(std::wstring s);

};