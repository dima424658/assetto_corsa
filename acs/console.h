#pragma once

class Console
{
// void __userpurge Console::Console(@<ecx>, unsigned int a2@<ebx>, Sim *isim);
void Console::~Console();
Console *Console::operator<<(const int *v);
Console *Console::operator<<(const float *v);
Console *Console::operator<<(std::string s);
Console *Console::operator<<(std::wstring s);
void Console::addCommand(const std::wstring *name, std::function<bool __cdecl(std::wstring)> exeFun, std::function<std::wstring __cdecl(void)> helpFun);
void Console::addVar(std::wstring name, float *var, IVarCallback *callback, bool readOnly, float multiplier);
void Console::addVarLambda(std::wstring name, std::function<void __cdecl(SVar *,float)> lambda, bool readyonly, float multiplier);
void Console::initCommands();
void Console::onKeyChar(const unsigned int key);
void Console::onKeyDown(const OnKeyEvent *message);
void Console::onSetVar(SVar *var, float value);
void Console::parse(std::wstring c);
void Console::renderHUD(float dt);
void Console::show(bool mode);

};