#include "consolecommandlambda.h"
void ConsoleCommandLambda::ConsoleCommandLambda(ConsoleCommandLambda *this, Console *console, const std::wstring *name, std::function<bool __cdecl(std::wstring)> executeFun, std::function<std::wstring __cdecl(void)> helpFun)
{
  std::wstring *v6; // ebp
  std::function<bool __cdecl(std::wstring)> *v7; // esi
  std::_Func_base<bool,std::wstring > *v8; // ecx
  std::_Func_base<bool,std::wstring >_vtbl *v9; // eax
  int v10; // eax
  std::_Func_base<std::wstring > *v11; // esi
  std::_Func_base<std::wstring >_vtbl *v12; // eax
  std::_Func_base<std::wstring > *v13; // eax

  v6 = &this->command;
  this->command._Myres = 7;
  this->command._Mysize = 0;
  this->command._Bx._Buf[0] = 0;
  this->console = console;
  v7 = &this->executeFun;
  this->__vftable = (ConsoleCommandLambda_vtbl *)&ConsoleCommandLambda::`vftable';
  this->executeFun._Impl = 0;
  v8 = executeFun._Impl;
  if ( executeFun._Impl )
  {
    v9 = executeFun._Impl->__vftable;
    if ( (std::function<bool __cdecl(std::wstring)> *)executeFun._Impl == &executeFun )
      v10 = ((int (__stdcall *)(std::function<bool __cdecl(std::wstring)> *))v9->_Copy)(v7);
    else
      v10 = ((int (__stdcall *)(_DWORD))v9->_Copy)(0);
    v8 = executeFun._Impl;
    v7->_Impl = (std::_Func_base<bool,std::wstring > *)v10;
  }
  else
  {
    v7->_Impl = 0;
  }
  this->helpFun._Impl = 0;
  v11 = helpFun._Impl;
  if ( helpFun._Impl )
  {
    v12 = helpFun._Impl->__vftable;
    if ( (std::function<std::wstring __cdecl(void)> *)helpFun._Impl == &helpFun )
      v13 = v12->_Copy(helpFun._Impl, &this->helpFun);
    else
      v13 = v12->_Copy(helpFun._Impl, 0);
    v8 = executeFun._Impl;
    v11 = helpFun._Impl;
    this->helpFun._Impl = v13;
  }
  else
  {
    this->helpFun._Impl = 0;
  }
  if ( v6 != name )
  {
    std::wstring::assign(v6, name, 0, 0xFFFFFFFF);
    v11 = helpFun._Impl;
    v8 = executeFun._Impl;
  }
  if ( v8 )
  {
    ((void (__stdcall *)(bool))v8->_Delete_this)(v8 != (std::_Func_base<bool,std::wstring > *)&executeFun);
    v11 = helpFun._Impl;
    executeFun._Impl = 0;
  }
  if ( v11 )
    v11->_Delete_this(v11, v11 != (std::_Func_base<std::wstring > *)&helpFun);
}
bool ConsoleCommandLambda::execute(ConsoleCommandLambda *this, std::wstring commandline)
{
  std::_Func_base<bool,std::wstring > *v3; // ecx
  bool v4; // bl
  std::wstring v6; // [esp+Ch] [ebp-24h] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  v7 = 0;
  v6._Bx._Buf[0] = 0;
  v6._Myres = 7;
  v6._Mysize = 0;
  std::wstring::assign(&v6, &commandline, 0, 0xFFFFFFFF);
  v3 = this->executeFun._Impl;
  LOBYTE(v7) = 1;
  if ( !v3 )
    std::_Xbad_function_call();
  v4 = v3->_Do_call(v3, &v6);
  if ( v6._Myres >= 8 )
    operator delete(v6._Bx._Ptr);
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  if ( commandline._Myres >= 8 )
    operator delete(commandline._Bx._Ptr);
  return v4;
}
std::wstring *ConsoleCommandLambda::getHelp(ConsoleCommandLambda *this, std::wstring *result)
{
  std::_Func_class<std::wstring,>::operator()(&this->helpFun, result);
  return result;
}
