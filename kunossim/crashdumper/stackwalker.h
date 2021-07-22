#pragma once

class StackWalker
{
void StackWalker::StackWalker(int options, const char *szSymPath, unsigned int dwProcessId, void *hProcess);
void StackWalker::~StackWalker();
StackWalker *StackWalker::`vector deleting destructor'(unsigned int a2);
void StackWalker::OnCallstackEntry(StackWalker::CallstackEntryType eType, StackWalker::CallstackEntry *entry);
void StackWalker::OnDbgHelpErr(const char *szFuncName, unsigned int gle, unsigned __int64 addr);
void StackWalker::OnLoadModule(const char *img, const char *mod, unsigned __int64 baseAddr, unsigned int size, unsigned int result, const char *symType, const char *pdbName, unsigned __int64 fileVersion);
void StackWalker::OnOutput(const char *buffer);
void StackWalker::OnSymInit(const char *szSearchPath, unsigned int symOptions, const char *szUserName);
int StackWalker::ShowCallstack(void *hThread, const _CONTEXT *context, int (__stdcall *readMemoryFunction)(void *, unsigned __int64, void *, unsigned int, unsigned int *, void *), void *pUserData);

};