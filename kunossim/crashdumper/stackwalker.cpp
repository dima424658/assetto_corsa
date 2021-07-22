#include "stackwalker.h
void StackWalker::StackWalker(StackWalker *this, int options, const char *szSymPath, unsigned int dwProcessId, void *hProcess)
{
  StackWalkerInternal *v6; // eax
  StackWalkerInternal *v7; // eax

  this->m_options = options;
  this->__vftable = (StackWalker_vtbl *)&StackWalker::`vftable';
  this->m_modulesLoaded = 0;
  this->m_hProcess = hProcess;
  v6 = (StackWalkerInternal *)operator new(68);
  if ( v6 )
    StackWalkerInternal::StackWalkerInternal(v6, this, this->m_hProcess);
  else
    v7 = 0;
  this->m_sw = v7;
  this->m_dwProcessId = dwProcessId;
  if ( szSymPath )
  {
    this->m_szSymPath = __strdup(szSymPath);
    this->m_options |= 0x10u;
  }
  else
  {
    this->m_szSymPath = 0;
  }
  this->m_MaxRecursionCount = 1000;
}
void StackWalker::~StackWalker(StackWalker *this)
{
  char *v2; // eax
  StackWalkerInternal *v3; // esi
  int (__stdcall *v4)(void *); // eax
  char *v5; // eax

  v2 = this->m_szSymPath;
  this->__vftable = (StackWalker_vtbl *)&StackWalker::`vftable';
  if ( v2 )
    _free(v2);
  v3 = this->m_sw;
  this->m_szSymPath = 0;
  if ( v3 )
  {
    v4 = v3->pSC;
    if ( v4 )
      v4(v3->m_hProcess);
    if ( v3->m_hDbhHelp )
      FreeLibrary(v3->m_hDbhHelp);
    v5 = v3->m_szSymPath;
    v3->m_hDbhHelp = 0;
    v3->m_parent = 0;
    if ( v5 )
      _free(v5);
    v3->m_szSymPath = 0;
    operator delete(v3);
  }
  this->m_sw = 0;
}
StackWalker *StackWalker::`vector deleting destructor'(StackWalker *this, unsigned int a2)
{
  StackWalker::~StackWalker(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int __usercall StackWalker::LoadModules@<eax>(StackWalker *this@<ecx>, int a2@<ebp>)
{
  int result; // eax
  char *v4; // esi
  char *v5; // eax
  char *v6; // eax
  char v7; // cl
  int v8; // edi
  void *v9; // esi
  StackWalkerInternal *v10; // edi
  char v11; // [esp+7h] [ebp-405h] BYREF
  char szTemp[1024]; // [esp+8h] [ebp-404h] BYREF

  if ( !this->m_sw )
  {
    SetLastError(0x45Au);
    return 0;
  }
  if ( this->m_modulesLoaded )
    return 1;
  v4 = 0;
  if ( (this->m_options & 0x10) != 0 )
  {
    v5 = (char *)_malloc(0x1000u);
    v4 = v5;
    if ( !v5 )
    {
      SetLastError(8u);
      return 0;
    }
    *v5 = 0;
    if ( this->m_szSymPath )
    {
      _strcat_s(v5, 0x1000u, this->m_szSymPath);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
    }
    _strcat_s(v4, 0x1000u, ".;");
    if ( GetCurrentDirectoryA(0x400u, szTemp) )
    {
      szTemp[1023] = 0;
      _strcat_s(v4, 0x1000u, szTemp);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
    }
    if ( GetModuleFileNameA(0, szTemp, 0x400u) )
    {
      szTemp[1023] = 0;
      v6 = &v11 + strlen(szTemp);
      if ( v6 >= szTemp )
      {
        while ( 1 )
        {
          v7 = *v6;
          if ( *v6 == 92 || v7 == 47 || v7 == 58 )
            break;
          if ( --v6 < szTemp )
            goto LABEL_20;
        }
        *v6 = 0;
      }
LABEL_20:
      if ( strlen(szTemp) )
      {
        _strcat_s(v4, 0x1000u, szTemp);
        _strcat_s(v4, 0x1000u, Str._Bx._Buf);
      }
    }
    if ( GetEnvironmentVariableA("_NT_SYMBOL_PATH", szTemp, 0x400u) )
    {
      szTemp[1023] = 0;
      _strcat_s(v4, 0x1000u, szTemp);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
    }
    if ( GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", szTemp, 0x400u) )
    {
      szTemp[1023] = 0;
      _strcat_s(v4, 0x1000u, szTemp);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
    }
    if ( GetEnvironmentVariableA("SYSTEMROOT", szTemp, 0x400u) )
    {
      szTemp[1023] = 0;
      _strcat_s(v4, 0x1000u, szTemp);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
      _strcat_s(szTemp, 0x400u, "\\system32");
      _strcat_s(v4, 0x1000u, szTemp);
      _strcat_s(v4, 0x1000u, Str._Bx._Buf);
    }
    if ( (this->m_options & 0x20) != 0 )
    {
      if ( GetEnvironmentVariableA("SYSTEMDRIVE", szTemp, 0x400u) )
      {
        szTemp[1023] = 0;
        _strcat_s(v4, 0x1000u, "SRV*");
        _strcat_s(v4, 0x1000u, szTemp);
        _strcat_s(v4, 0x1000u, "\\websymbols");
        _strcat_s(v4, 0x1000u, "*http://msdl.microsoft.com/download/symbols;");
      }
      else
      {
        _strcat_s(v4, 0x1000u, "SRV*c:\\websymbols*http://msdl.microsoft.com/download/symbols;");
      }
    }
  }
  v8 = StackWalkerInternal::Init(this->m_sw, a2, (int)v4, v4);
  if ( v4 )
    _free(v4);
  if ( !v8 )
  {
    ((void (*)(StackWalker *, const char *, _DWORD, _DWORD, _DWORD))this->OnDbgHelpErr)(
      this,
      "Error while initializing dbghelp.dll",
      0,
      0,
      0);
    SetLastError(0x45Au);
    return 0;
  }
  v9 = this->m_hProcess;
  v10 = this->m_sw;
  if ( StackWalkerInternal::GetModuleListTH32(v10, v9, this->m_dwProcessId) )
  {
    result = 1;
  }
  else
  {
    result = (int)StackWalkerInternal::GetModuleListPSAPI(v10, v9);
    if ( !result )
      return result;
  }
  this->m_modulesLoaded = 1;
  return result;
}
void StackWalker::OnCallstackEntry(StackWalker *this, StackWalker::CallstackEntryType eType, StackWalker::CallstackEntry *entry)
{
  char buffer[1024]; // [esp+Ch] [ebp-404h] BYREF

  if ( eType != lastEntry && entry->offset )
  {
    if ( !entry->name[0] )
      _strcpy_s(entry->name, 0x400u, "(function-name not available)");
    if ( entry->undName[0] )
    {
      if ( strlen(entry->undName) >= 0x400 )
      {
        _strncpy_s(entry->name, 0x400u, entry->undName, 0x400u);
        entry->name[1023] = 0;
      }
      else
      {
        _strcpy_s(entry->name, 0x400u, entry->undName);
      }
    }
    if ( entry->undFullName[0] )
    {
      if ( strlen(entry->undFullName) >= 0x400 )
      {
        _strncpy_s(entry->name, 0x400u, entry->undFullName, 0x400u);
        entry->name[1023] = 0;
      }
      else
      {
        _strcpy_s(entry->name, 0x400u, entry->undFullName);
      }
    }
    if ( entry->lineFileName[0] )
    {
      _snprintf_s<1024>(
        (char (*)[1024])buffer,
        0x400u,
        "%s (%d): %s\n",
        entry->lineFileName,
        entry->lineNumber,
        entry->name);
    }
    else
    {
      _strcpy_s(entry->lineFileName, 0x400u, "(filename not available)");
      if ( !entry->moduleName[0] )
        _strcpy_s(entry->moduleName, 0x400u, "(module-name not available)");
      _snprintf_s<1024>(
        (char (*)[1024])buffer,
        0x400u,
        "%p (%s): %s: %s\n",
        (const void *)LODWORD(entry->offset),
        entry->moduleName,
        entry->lineFileName,
        entry->name);
    }
    buffer[1023] = 0;
    this->OnOutput(this, buffer);
  }
}
void StackWalker::OnDbgHelpErr(StackWalker *this, const char *szFuncName, unsigned int gle, unsigned __int64 addr)
{
  char buffer[1024]; // [esp+Ch] [ebp-404h] BYREF

  _snprintf_s<1024>(
    (char (*)[1024])buffer,
    0x400u,
    "ERROR: %s, GetLastError: %d (Address: %p)\n",
    szFuncName,
    gle,
    (const void *)addr);
  this->OnOutput(this, buffer);
}
void StackWalker::OnLoadModule(StackWalker *this, const char *img, const char *mod, unsigned __int64 baseAddr, unsigned int size, unsigned int result, const char *symType, const char *pdbName, unsigned __int64 fileVersion)
{
  char buffer[1024]; // [esp+18h] [ebp-404h] BYREF

  if ( fileVersion )
    _snprintf_s<1024>(
      (char (*)[1024])buffer,
      0x400u,
      "%s:%s (%p), size: %d (result: %d), SymType: '%s', PDB: '%s', fileVersion: %d.%d.%d.%d\n",
      img,
      mod,
      (const void *)baseAddr,
      size,
      result,
      symType,
      pdbName,
      HIWORD(fileVersion),
      WORD2(fileVersion),
      WORD1(fileVersion),
      (unsigned __int16)fileVersion);
  else
    _snprintf_s<1024>(
      (char (*)[1024])buffer,
      0x400u,
      "%s:%s (%p), size: %d (result: %d), SymType: '%s', PDB: '%s'\n",
      img,
      mod,
      (const void *)baseAddr,
      size,
      result,
      symType,
      pdbName);
}
void StackWalker::OnOutput(StackWalker *this, const char *buffer)
{
  _printf(buffer);
  _fflush(0);
}
void StackWalker::OnSymInit(StackWalker *this, const char *szSearchPath, unsigned int symOptions, const char *szUserName)
{
  _OSVERSIONINFOEXA ver; // [esp+4h] [ebp-4A0h] BYREF
  char buffer[1024]; // [esp+A0h] [ebp-404h] BYREF

  _snprintf_s<1024>(
    (char (*)[1024])buffer,
    0x400u,
    "SymInit: Symbol-SearchPath: '%s', symOptions: %d, UserName: '%s'\n",
    szSearchPath,
    symOptions,
    szUserName);
  memset(&ver, 0, sizeof(ver));
  ver.dwOSVersionInfoSize = 156;
  if ( GetVersionExA((LPOSVERSIONINFOA)&ver) )
  {
    _snprintf_s<1024>(
      (char (*)[1024])buffer,
      0x400u,
      "OS-Version: %d.%d.%d (%s) 0x%x-0x%x\n",
      ver.dwMajorVersion,
      ver.dwMinorVersion,
      ver.dwBuildNumber,
      ver.szCSDVersion,
      ver.wSuiteMask,
      ver.wProductType);
    this->OnOutput(this, buffer);
  }
}
int StackWalker::ShowCallstack(StackWalker *this, void *hThread, const _CONTEXT *context, int (__stdcall *readMemoryFunction)(void *, unsigned __int64, void *, unsigned int, unsigned int *, void *), void *pUserData)
{
  DWORD v6; // eax
  DWORD v7; // eax
  DWORD v8; // eax
  _DWORD v9[3]; // [esp+0h] [ebp-22D4h] BYREF
  SIZE_T NumberOfBytesRead; // [esp+Ch] [ebp-22C8h] BYREF
  HANDLE hProcess[2]; // [esp+14h] [ebp-22C0h] BYREF
  int v12; // [esp+1Ch] [ebp-22B8h]
  char *szSrc; // [esp+20h] [ebp-22B4h]
  SIZE_T nSize; // [esp+24h] [ebp-22B0h]
  unsigned int *v15; // [esp+28h] [ebp-22ACh]
  unsigned int v16; // [esp+2Ch] [ebp-22A8h]
  SYM_TYPE v17; // [esp+30h] [ebp-22A4h]
  BOOL v18; // [esp+34h] [ebp-22A0h]
  int i; // [esp+38h] [ebp-229Ch]
  int v20; // [esp+3Ch] [ebp-2298h]
  void *Block; // [esp+40h] [ebp-2294h]
  char v22; // [esp+47h] [ebp-228Dh]
  StackWalker *v23; // [esp+48h] [ebp-228Ch]
  unsigned __int64 v24; // [esp+4Ch] [ebp-2288h] BYREF
  char szDest[1024]; // [esp+54h] [ebp-2280h] BYREF
  char v26[1024]; // [esp+454h] [ebp-1E80h] BYREF
  char v27[1024]; // [esp+854h] [ebp-1A80h] BYREF
  __int64 v28; // [esp+C54h] [ebp-1680h] BYREF
  int v29; // [esp+C5Ch] [ebp-1678h] BYREF
  int v30; // [esp+C60h] [ebp-1674h]
  char v31[1028]; // [esp+C64h] [ebp-1670h] BYREF
  const char *v32; // [esp+1068h] [ebp-126Ch]
  char v33[1024]; // [esp+106Ch] [ebp-1268h] BYREF
  unsigned __int64 v34; // [esp+146Ch] [ebp-E68h]
  char v35[1024]; // [esp+1474h] [ebp-E60h] BYREF
  StackWalkerInternal::IMAGEHLP_MODULE64_V3 pModuleInfo; // [esp+1874h] [ebp-A60h] BYREF
  _CONTEXT Context; // [esp+1EFCh] [ebp-3D8h] BYREF
  unsigned __int64 baseAddr[33]; // [esp+21C8h] [ebp-10Ch] BYREF
  int savedregs; // [esp+22D4h] [ebp+0h] BYREF

  v23 = this;
  Block = 0;
  v22 = 1;
  v20 = 0;
  if ( !this->m_modulesLoaded )
    StackWalker::LoadModules(v23, (int)&savedregs);
  if ( !v23->m_sw->m_hDbhHelp )
  {
    _printf("DLL NON LOADED\n");
    SetLastError(0x45Au);
    return 0;
  }
  s_readMemoryFunction = readMemoryFunction;
  s_readMemoryFunction_UserData = pUserData;
  if ( context )
  {
    qmemcpy(&Context, context, sizeof(Context));
  }
  else if ( hThread == GetCurrentThread() )
  {
    memset(&Context, 0, sizeof(Context));
    Context.ContextFlags = 65543;
    strcpy((char *)&v9[2], "[<q");
    Context.Eip = v9[2];
    Context.Ebp = (unsigned int)&savedregs;
    Context.Esp = (unsigned int)&NumberOfBytesRead;
  }
  else
  {
    SuspendThread(hThread);
    memset(&Context, 0, sizeof(Context));
    Context.ContextFlags = 65543;
    if ( !GetThreadContext(hThread, &Context) )
    {
      ResumeThread(hThread);
      return 0;
    }
  }
  memset(baseAddr, 0, sizeof(baseAddr));
  v16 = 332;
  baseAddr[0] = Context.Eip;
  HIDWORD(baseAddr[1]) = 3;
  baseAddr[4] = Context.Ebp;
  HIDWORD(baseAddr[5]) = 3;
  baseAddr[6] = Context.Esp;
  HIDWORD(baseAddr[7]) = 3;
  Block = _malloc(0x420u);
  if ( Block )
  {
    memset(Block, 0, 0x420u);
    *(_DWORD *)Block = 32;
    *((_DWORD *)Block + 6) = 1024;
    hProcess[1] = 0;
    v12 = 0;
    szSrc = 0;
    nSize = 0;
    v15 = 0;
    hProcess[0] = (HANDLE)24;
    memset(&pModuleInfo, 0, sizeof(pModuleInfo));
    pModuleInfo.SizeOfStruct = 1672;
    for ( i = 0; ; ++i )
    {
      if ( !v23->m_sw->pSW(
              v16,
              v23->m_hProcess,
              hThread,
              (_tagSTACKFRAME64 *)baseAddr,
              &Context,
              StackWalker::myReadProcMem,
              v23->m_sw->pSFTA,
              v23->m_sw->pSGMB,
              0) )
      {
        ((void (*)(StackWalker *, const char *, _DWORD, _DWORD, _DWORD))v23->OnDbgHelpErr)(
          v23,
          "StackWalk64",
          0,
          baseAddr[0],
          HIDWORD(baseAddr[0]));
        goto cleanup_0;
      }
      v24 = baseAddr[0];
      szDest[0] = 0;
      *((_BYTE *)&savedregs + (_DWORD)&loc_711DDA - 7421018) = 0;
      v27[0] = 0;
      v28 = 0i64;
      v29 = 0;
      v31[0] = 0;
      v30 = 0;
      *((_BYTE *)&savedregs + (_DWORD)&loc_712DF7 - 7421015) = 0;
      v33[0] = 0;
      if ( baseAddr[0] == baseAddr[2] )
      {
        if ( v23->m_MaxRecursionCount > 0 && v20 > v23->m_MaxRecursionCount )
        {
          ((void (*)(StackWalker *, const char *, _DWORD, _DWORD, _DWORD))v23->OnDbgHelpErr)(
            v23,
            "StackWalk64-Endless-Callstack!",
            0,
            baseAddr[0],
            HIDWORD(baseAddr[0]));
          goto cleanup_0;
        }
        ++v20;
      }
      else
      {
        v20 = 0;
      }
      if ( baseAddr[0] )
      {
        if ( ((int (__stdcall *)(void *, _DWORD, _DWORD, __int64 *, void *))v23->m_sw->pSGSFA)(
               v23->m_hProcess,
               baseAddr[0],
               HIDWORD(baseAddr[0]),
               &v28,
               Block) )
        {
          MyStrCpy(szDest, 0x400u, (const char *)Block + 28);
          v23->m_sw->pUDSN((char *)Block + 28, v26, 1024u, 4096u);
          v23->m_sw->pUDSN((char *)Block + 28, v27, 1024u, 0);
        }
        else
        {
          *(_QWORD *)&v9[1] = baseAddr[0];
          v6 = GetLastError();
          ((void (*)(StackWalker *, const char *, DWORD, _DWORD, _DWORD))v23->OnDbgHelpErr)(
            v23,
            "SymGetSymFromAddr64",
            v6,
            v9[1],
            v9[2]);
        }
        if ( v23->m_sw->pSGLFA )
        {
          if ( ((int (__stdcall *)(void *, _DWORD, _DWORD, int *, HANDLE *))v23->m_sw->pSGLFA)(
                 v23->m_hProcess,
                 baseAddr[0],
                 HIDWORD(baseAddr[0]),
                 &v29,
                 hProcess) )
          {
            v30 = v12;
            MyStrCpy(v31, 0x400u, szSrc);
          }
          else
          {
            *(_QWORD *)&v9[1] = baseAddr[0];
            v7 = GetLastError();
            ((void (*)(StackWalker *, const char *, DWORD, _DWORD, _DWORD))v23->OnDbgHelpErr)(
              v23,
              "SymGetLineFromAddr64",
              v7,
              v9[1],
              v9[2]);
          }
        }
        if ( StackWalkerInternal::GetModuleInfo(v23->m_sw, v23->m_hProcess, baseAddr[0], &pModuleInfo) )
        {
          v17 = pModuleInfo.SymType;
          switch ( pModuleInfo.SymType )
          {
            case SymNone:
              v32 = "-nosymbols-";
              break;
            case SymCoff:
              v32 = "COFF";
              break;
            case SymCv:
              v32 = "CV";
              break;
            case SymPdb:
              v32 = "PDB";
              break;
            case SymExport:
              v32 = "-exported-";
              break;
            case SymDeferred:
              v32 = "-deferred-";
              break;
            case SymSym:
              v32 = "SYM";
              break;
            case SymDia:
              v32 = "DIA";
              break;
            case SymVirtual:
              v32 = "Virtual";
              break;
            default:
              v32 = 0;
              break;
          }
          MyStrCpy(v33, 0x400u, pModuleInfo.ModuleName);
          v34 = pModuleInfo.BaseOfImage;
          MyStrCpy(v35, 0x400u, pModuleInfo.LoadedImageName);
        }
        else
        {
          *(_QWORD *)&v9[1] = baseAddr[0];
          v8 = GetLastError();
          ((void (*)(StackWalker *, const char *, DWORD, _DWORD, _DWORD))v23->OnDbgHelpErr)(
            v23,
            "SymGetModuleInfo64",
            v8,
            v9[1],
            v9[2]);
        }
      }
      v18 = i != 0;
      v22 = 0;
      v23->OnCallstackEntry(v23, (StackWalker::CallstackEntryType)v18, (StackWalker::CallstackEntry *)&v24);
      if ( !baseAddr[2] )
        break;
    }
    v22 = 1;
    v23->OnCallstackEntry(v23, lastEntry, (StackWalker::CallstackEntry *)&v24);
    SetLastError(0);
  }
cleanup_0:
  if ( Block )
    _free(Block);
  if ( !v22 )
    v23->OnCallstackEntry(v23, lastEntry, (StackWalker::CallstackEntry *)&v24);
  if ( !context )
    ResumeThread(hThread);
  return 1;
}
