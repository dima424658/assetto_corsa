#include "console.h"
void __userpurge Console::Console(Console *this@<ecx>, unsigned int a2@<ebx>, Sim *isim)
{
  Font *v4; // eax
  Font *v5; // eax
  Console *v6; // eax
  Console *v7; // eax
  Console *v8; // eax
  Event<SessionInfo> *v9; // ecx
  std::wstring *v10; // eax
  const std::wstring *v11; // eax
  char v12; // bl
  _BYTE v13[48]; // [esp-24h] [ebp-90h] BYREF
  Font *v14; // [esp+20h] [ebp-4Ch]
  _BYTE *v15; // [esp+24h] [ebp-48h]
  Console *v16; // [esp+28h] [ebp-44h]
  std::wstring v17; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+44h] [ebp-28h] BYREF
  int v19; // [esp+68h] [ebp-4h]

  v16 = this;
  *(_DWORD *)&v13[44] = isim->game;
  *(_DWORD *)&v13[40] = 7;
  *(_DWORD *)&v13[36] = 0;
  *(_WORD *)&v13[20] = 0;
  std::wstring::assign((std::wstring *)&v13[20], L"CONSOLE", 7u);
  GameObject::GameObject(this, *(std::wstring *)&v13[20], *(Game **)&v13[44]);
  this->IVarCallback::__vftable = (IVarCallback_vtbl *)&IVarCallback::`vftable';
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&IKeyEventListener::`vftable';
  this->GameObject::__vftable = (Console_vtbl *)&Console::`vftable'{for `GameObject'};
  this->IVarCallback::__vftable = (IVarCallback_vtbl *)&Console::`vftable'{for `IVarCallback'};
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&Console::`vftable'{for `IKeyEventListener'};
  this->sim = isim;
  v19 = 0;
  this->vars._Myfirst = 0;
  this->vars._Mylast = 0;
  this->vars._Myend = 0;
  this->lines._Myfirst = 0;
  this->lines._Mylast = 0;
  this->lines._Myend = 0;
  this->history._Myfirst = 0;
  this->history._Mylast = 0;
  this->history._Myend = 0;
  this->commandLine._Myres = 7;
  this->commandLine._Mysize = 0;
  this->commandLine._Bx._Buf[0] = 0;
  this->commands._Myfirst = 0;
  this->commands._Mylast = 0;
  this->commands._Myend = 0;
  this->accumulator._Myres = 7;
  this->accumulator._Mysize = 0;
  this->accumulator._Bx._Buf[0] = 0;
  Console::_singleton = this;
  *(_DWORD *)&v13[44] = 24;
  LOBYTE(v19) = 6;
  this->historyPos = 0;
  this->isActive = 0;
  v4 = (Font *)operator new(*(_DWORD *)&v13[44]);
  v14 = v4;
  LOBYTE(v19) = 7;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 16.0, 0, 0);
  else
    v5 = 0;
  this->font = v5;
  v14 = (Font *)&v13[24];
  this->disableAutoShow = 1;
  LOBYTE(v19) = 6;
  *(_DWORD *)&v13[44] = 7;
  *(_DWORD *)&v13[40] = 0;
  *(_WORD *)&v13[24] = 0;
  std::wstring::assign((std::wstring *)&v13[24], L"\n", 1u);
  LOBYTE(v19) = 8;
  *(_DWORD *)&v13[20] = 7;
  *(_DWORD *)&v13[16] = 0;
  *(_WORD *)v13 = 0;
  std::wstring::assign((std::wstring *)v13, L"AssettoCorsa, Kunos Simulazioni", 0x1Fu);
  v6 = Console::operator<<(this, *(std::wstring *)v13);
  LOBYTE(v19) = 6;
  Console::operator<<(v6, *(std::wstring *)&v13[24]);
  v15 = &v13[24];
  *(_DWORD *)&v13[44] = 7;
  *(_DWORD *)&v13[40] = 0;
  *(_WORD *)&v13[24] = 0;
  std::wstring::assign((std::wstring *)&v13[24], L"\n", 1u);
  LOBYTE(v19) = 9;
  *(_DWORD *)&v13[20] = 7;
  *(_DWORD *)&v13[16] = 0;
  *(_WORD *)v13 = 0;
  std::wstring::assign((std::wstring *)v13, L"Renderer: KS DX11 Renderer", 0x1Au);
  v7 = Console::operator<<(this, *(std::wstring *)v13);
  LOBYTE(v19) = 6;
  Console::operator<<(v7, *(std::wstring *)&v13[24]);
  v15 = &v13[24];
  *(_DWORD *)&v13[44] = 7;
  *(_DWORD *)&v13[40] = 0;
  *(_WORD *)&v13[24] = 0;
  std::wstring::assign((std::wstring *)&v13[24], L"\n", 1u);
  LOBYTE(v19) = 10;
  *(_DWORD *)&v13[20] = 7;
  *(_DWORD *)&v13[16] = 0;
  *(_WORD *)v13 = 0;
  std::wstring::assign((std::wstring *)v13, L"COMMAND CONSOLE", 0xFu);
  v8 = Console::operator<<(this, *(std::wstring *)v13);
  LOBYTE(v19) = 6;
  Console::operator<<(v8, *(std::wstring *)&v13[24]);
  *(_DWORD *)&v13[44] = this;
  *(_DWORD *)&v13[20] = &std::_Func_impl<std::_Callable_obj<_lambda_01ce1ab6eed4adfcbaa8ffbc2f77c412_,0>,std::allocator<std::_Func_class<void,OnNewCarLoadedEvent const &>>,void,OnNewCarLoadedEvent const &>::`vftable';
  *(_DWORD *)&v13[24] = this;
  *(_DWORD *)&v13[36] = &v13[20];
  v9 = (Event<SessionInfo> *)&this->sim->evNewCarLoaded;
  LOBYTE(v19) = 6;
  Event<float>::addHandler(v9, *(std::function<void __cdecl(SessionInfo const &)> *)&v13[20], this);
  this->disableAutoShow = 0;
  v10 = Path::getDocumentPath(&result);
  LOBYTE(v19) = 12;
  v11 = std::operator+<wchar_t>(&v17, v10, L"/Assetto Corsa/cfg/console.ini");
  LOBYTE(v19) = 13;
  v12 = Path::fileExists(a2, v11, 0);
  if ( v17._Myres >= 8 )
    operator delete(v17._Bx._Ptr);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->disableAutoShow = 1;
  if ( v12 )
    this->disableAutoShow = 1;
}
void Console::~Console(Console *this)
{
  Console *v1; // esi
  Font *v2; // edi
  std::vector<SVar *> *v3; // ebx
  unsigned int v4; // ebp
  wchar_t **v5; // esi
  wchar_t *v6; // ecx
  wchar_t *v7; // edi
  wchar_t *v8; // ecx
  std::vector<ConsoleCommand *> *v9; // edi
  unsigned int v10; // ebp
  ConsoleCommand *v11; // esi
  std::vector<std::wstring> *v12; // edi
  std::wstring *v13; // ebp
  std::wstring *i; // esi
  std::vector<std::wstring> *v15; // edi
  std::wstring *v16; // ebp
  std::wstring *j; // esi

  v1 = this;
  this->GameObject::__vftable = (Console_vtbl *)&Console::`vftable'{for `GameObject'};
  this->IVarCallback::__vftable = (IVarCallback_vtbl *)&Console::`vftable'{for `IVarCallback'};
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&Console::`vftable'{for `IKeyEventListener'};
  v2 = this->font;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v2);
    operator delete(v2);
  }
  v3 = &v1->vars;
  v4 = 0;
  if ( v1->vars._Mylast - v1->vars._Myfirst )
  {
    do
    {
      v5 = (wchar_t **)v3->_Myfirst[v4];
      if ( v5 )
      {
        v6 = v5[16];
        v7 = (wchar_t *)(v5 + 12);
        if ( v6 )
        {
          (*(void (__stdcall **)(bool))(*(_DWORD *)v6 + 16))(v6 != v7);
          v5[16] = 0;
        }
        v8 = v5[16];
        if ( v8 )
        {
          (*(void (__stdcall **)(bool))(*(_DWORD *)v8 + 16))(v8 != v7);
          v5[16] = 0;
        }
        if ( (unsigned int)v5[5] >= 8 )
          operator delete(*v5);
        v5[5] = (wchar_t *)7;
        v5[4] = 0;
        *(_WORD *)v5 = 0;
        operator delete(v5);
      }
      ++v4;
    }
    while ( v4 < v3->_Mylast - v3->_Myfirst );
    v1 = this;
  }
  std::_Container_base0::_Orphan_all(v3);
  v9 = &v1->commands;
  v3->_Mylast = v3->_Myfirst;
  v10 = 0;
  if ( v1->commands._Mylast - v1->commands._Myfirst )
  {
    do
    {
      v11 = v9->_Myfirst[v10];
      if ( v11 )
      {
        if ( v11->command._Myres >= 8 )
          operator delete(v11->command._Bx._Ptr);
        v11->command._Myres = 7;
        v11->command._Mysize = 0;
        v11->command._Bx._Buf[0] = 0;
        operator delete(v11);
      }
      ++v10;
    }
    while ( v10 < v9->_Mylast - v9->_Myfirst );
    v1 = this;
  }
  if ( v1->accumulator._Myres >= 8 )
    operator delete(v1->accumulator._Bx._Ptr);
  v1->accumulator._Myres = 7;
  v1->accumulator._Mysize = 0;
  v1->accumulator._Bx._Buf[0] = 0;
  if ( v9->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v9);
    operator delete(v9->_Myfirst);
    v9->_Myfirst = 0;
    v9->_Mylast = 0;
    v9->_Myend = 0;
  }
  if ( v1->commandLine._Myres >= 8 )
    operator delete(v1->commandLine._Bx._Ptr);
  v1->commandLine._Myres = 7;
  v1->commandLine._Mysize = 0;
  v12 = &v1->history;
  v1->commandLine._Bx._Buf[0] = 0;
  if ( v1->history._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v1->history);
    v13 = v1->history._Mylast;
    for ( i = v12->_Myfirst; i != v13; ++i )
    {
      if ( i->_Myres >= 8 )
        operator delete(i->_Bx._Ptr);
      i->_Myres = 7;
      i->_Mysize = 0;
      i->_Bx._Buf[0] = 0;
    }
    operator delete(v12->_Myfirst);
    v1 = this;
    v12->_Myfirst = 0;
    v12->_Mylast = 0;
    v12->_Myend = 0;
  }
  v15 = &v1->lines;
  if ( v1->lines._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v1->lines);
    v16 = v1->lines._Mylast;
    for ( j = v15->_Myfirst; j != v16; ++j )
    {
      if ( j->_Myres >= 8 )
        operator delete(j->_Bx._Ptr);
      j->_Myres = 7;
      j->_Mysize = 0;
      j->_Bx._Buf[0] = 0;
    }
    operator delete(v15->_Myfirst);
    v1 = this;
    v15->_Myfirst = 0;
    v15->_Mylast = 0;
    v15->_Myend = 0;
  }
  if ( v3->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v3);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  GameObject::~GameObject(v1);
}
Console *Console::operator<<(Console *this, const int *v)
{
  std::wstring *v3; // eax
  std::wstring *v4; // esi
  std::wstring *v5; // edi
  int v7; // [esp-4h] [ebp-10Ch]
  int v8; // [esp+14h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v9; // [esp+18h] [ebp-F0h] BYREF
  std::wstring v10; // [esp+C8h] [ebp-40h] BYREF
  std::wstring result; // [esp+E0h] [ebp-28h] BYREF
  int v12; // [esp+104h] [ebp-4h]

  *(_DWORD *)v9.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v9.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v9.gap68);
  v12 = 0;
  v8 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v9, &v9.gap10[8], 0);
  v12 = 1;
  *(_DWORD *)&v9.gap0[*(_DWORD *)(*(_DWORD *)v9.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v8 + *(_DWORD *)(*(_DWORD *)v9.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v9.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v9.gap10[8]);
  *(_DWORD *)&v9.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v9.gap10[64] = 0;
  *(_DWORD *)&v9.gap10[68] = 0;
  v7 = *v;
  v12 = 3;
  std::wostream::operator<<(v9.gap10, v7);
  v3 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v9, &result);
  v4 = &this->accumulator;
  LOBYTE(v12) = 4;
  v5 = std::operator+<wchar_t>(&v10, &this->accumulator, v3);
  if ( &this->accumulator != v5 )
  {
    if ( this->accumulator._Myres >= 8 )
      operator delete(v4->_Bx._Ptr);
    this->accumulator._Myres = 7;
    this->accumulator._Mysize = 0;
    v4->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->accumulator, v5);
  }
  if ( v10._Myres >= 8 )
    operator delete(v10._Bx._Ptr);
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v12 = -1;
  *(_DWORD *)&v9.gap0[*(_DWORD *)(*(_DWORD *)v9.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v8 + *(_DWORD *)(*(_DWORD *)v9.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v9.gap0 + 4) - 104;
  *(_DWORD *)&v9.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v9.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v9.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v9.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v9.gap68);
  return this;
}
Console *Console::operator<<(Console *this, const float *v)
{
  std::wstring *v3; // eax
  std::wstring *v4; // esi
  std::wstring *v5; // edi
  int v7; // [esp+20h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v8; // [esp+24h] [ebp-F0h] BYREF
  std::wstring v9; // [esp+D4h] [ebp-40h] BYREF
  std::wstring result; // [esp+ECh] [ebp-28h] BYREF
  int v11; // [esp+110h] [ebp-4h]

  *(_DWORD *)v8.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v8.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v8.gap68);
  v11 = 0;
  v7 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v8, &v8.gap10[8], 0);
  v11 = 1;
  *(_DWORD *)&v8.gap0[*(_DWORD *)(*(_DWORD *)v8.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v7 + *(_DWORD *)(*(_DWORD *)v8.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v8.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v8.gap10[8]);
  *(_DWORD *)&v8.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v8.gap10[64] = 0;
  *(_DWORD *)&v8.gap10[68] = 0;
  v11 = 3;
  std::wostream::operator<<(v8.gap10);
  v3 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v8, &result);
  v4 = &this->accumulator;
  LOBYTE(v11) = 4;
  v5 = std::operator+<wchar_t>(&v9, &this->accumulator, v3);
  if ( &this->accumulator != v5 )
  {
    if ( this->accumulator._Myres >= 8 )
      operator delete(v4->_Bx._Ptr);
    this->accumulator._Myres = 7;
    this->accumulator._Mysize = 0;
    v4->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->accumulator, v5);
  }
  if ( v9._Myres >= 8 )
    operator delete(v9._Bx._Ptr);
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v11 = -1;
  *(_DWORD *)&v8.gap0[*(_DWORD *)(*(_DWORD *)v8.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v7 + *(_DWORD *)(*(_DWORD *)v8.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v8.gap0 + 4) - 104;
  *(_DWORD *)&v8.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v8.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v8.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v8.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v8.gap68);
  return this;
}
Console *Console::operator<<(Console *this, std::string s)
{
  std::string *v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // esi
  std::wstring *v11; // ebx
  KeyboardManager *v12; // ecx
  std::wstring v14; // [esp+18h] [ebp-40h] BYREF
  std::wstring result; // [esp+30h] [ebp-28h] BYREF
  int v16; // [esp+54h] [ebp-4h]

  v3 = &s;
  v4 = s._Mysize;
  v5 = 1;
  if ( s._Myres >= 0x10 )
    v3 = (std::string *)s._Bx._Ptr;
  v16 = 0;
  if ( !s._Mysize )
    v5 = 0;
  v6 = std::char_traits<char>::compare(v3->_Bx._Buf, "\n", v5);
  v7 = v6 == 0;
  if ( !v6 )
  {
    if ( v4 )
      v8 = v4 != 1;
    else
      v8 = -1;
    v7 = v8 == 0;
  }
  if ( v7 )
  {
    std::vector<std::wstring>::push_back(&this->lines, &this->accumulator);
    std::wstring::assign(&this->accumulator, word_17BE9D8, 0);
  }
  else
  {
    v9 = string2wstring(&result, &s);
    v10 = &this->accumulator;
    LOBYTE(v16) = 1;
    v11 = std::operator+<wchar_t>(&v14, &this->accumulator, v9);
    if ( &this->accumulator != v11 )
    {
      if ( this->accumulator._Myres >= 8 )
        operator delete(v10->_Bx._Ptr);
      this->accumulator._Myres = 7;
      this->accumulator._Mysize = 0;
      v10->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->accumulator, v11);
    }
    if ( v14._Myres >= 8 )
      operator delete(v14._Bx._Ptr);
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    LOBYTE(v16) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( (unsigned int)(this->lines._Mylast - this->lines._Myfirst) > 0xC )
  {
    std::_Move<std::wstring *,std::wstring *>(this->lines._Myfirst + 1, this->lines._Mylast, this->lines._Myfirst);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(this->lines._Mylast - 1, this->lines._Mylast);
    --this->lines._Mylast;
  }
  if ( !this->isActive && !this->disableAutoShow )
  {
    v12 = &this->game->keyboardManager;
    this->isActive = 1;
    CollisionMeshODE::setUserPointer(v12, &this->IKeyEventListener);
  }
  if ( s._Myres >= 0x10 )
    operator delete(s._Bx._Ptr);
  return this;
}
Console *Console::operator<<(Console *this, std::wstring s)
{
  std::wstring *v3; // esi
  std::wstring *v4; // ebx
  KeyboardManager *v5; // ecx
  std::wstring result; // [esp+18h] [ebp-28h] BYREF
  int v8; // [esp+3Ch] [ebp-4h]

  v8 = 0;
  v3 = &this->accumulator;
  if ( std::wstring::compare(&s, 0, s._Mysize, L"\n", 1u) )
  {
    v4 = std::operator+<wchar_t>(&result, &this->accumulator, &s);
    if ( v3 != v4 )
    {
      if ( this->accumulator._Myres >= 8 )
        operator delete(v3->_Bx._Ptr);
      this->accumulator._Myres = 7;
      this->accumulator._Mysize = 0;
      v3->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->accumulator, v4);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  else
  {
    std::vector<std::wstring>::push_back(&this->lines, &this->accumulator);
    std::wstring::assign(&this->accumulator, word_17BE9D8, 0);
  }
  if ( (unsigned int)(this->lines._Mylast - this->lines._Myfirst) > 0xC )
  {
    std::_Move<std::wstring *,std::wstring *>(this->lines._Myfirst + 1, this->lines._Mylast, this->lines._Myfirst);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(this->lines._Mylast - 1, this->lines._Mylast);
    --this->lines._Mylast;
  }
  if ( !this->isActive && !this->disableAutoShow )
  {
    v5 = &this->game->keyboardManager;
    this->isActive = 1;
    CollisionMeshODE::setUserPointer(v5, &this->IKeyEventListener);
  }
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  return this;
}
Console *Console::`scalar deleting destructor'(Console *this, unsigned int a2)
{
  Console::~Console(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Console::addCommand(Console *this, const std::wstring *name, std::function<bool __cdecl(std::wstring)> exeFun, std::function<std::wstring __cdecl(void)> helpFun)
{
  ICollisionObject *v5; // edi
  std::_Func_base<std::wstring >_vtbl *v6; // eax
  std::_Func_base<bool,std::wstring >_vtbl *v7; // eax
  std::_Func_base<bool,std::wstring > *v8; // eax
  ICollisionObject *v9; // eax
  std::function<bool __cdecl(std::wstring)> v10; // [esp-30h] [ebp-5Ch] BYREF
  std::function<std::wstring __cdecl(void)> v11; // [esp-18h] [ebp-44h] BYREF
  std::function<bool __cdecl(std::wstring)> *v12; // [esp+14h] [ebp-18h]
  ICollisionObject *_Val[2]; // [esp+18h] [ebp-14h] BYREF
  int v14; // [esp+28h] [ebp-4h]

  v14 = 1;
  v5 = (ICollisionObject *)operator new(80);
  _Val[0] = v5;
  if ( v5 )
  {
    _Val[1] = (ICollisionObject *)&v11;
    v12 = (std::function<bool __cdecl(std::wstring)> *)&v11;
    v11._Impl = 0;
    LOBYTE(v14) = 3;
    if ( helpFun._Impl )
    {
      v6 = helpFun._Impl->__vftable;
      if ( (std::function<std::wstring __cdecl(void)> *)helpFun._Impl == &helpFun )
        (&v10._Impl)[1] = (std::_Func_base<bool,std::wstring > *)&v11;
      else
        (&v10._Impl)[1] = 0;
      v11._Impl = (std::_Func_base<std::wstring > *)((int (__stdcall *)(std::_Func_base<bool,std::wstring > *))v6->_Copy)((&v10._Impl)[1]);
    }
    else
    {
      v11._Impl = 0;
    }
    v12 = &v10;
    v10._Impl = 0;
    LOBYTE(v14) = 5;
    if ( exeFun._Impl )
    {
      v7 = exeFun._Impl->__vftable;
      if ( (std::function<bool __cdecl(std::wstring)> *)exeFun._Impl == &exeFun )
        v8 = (std::_Func_base<bool,std::wstring > *)((int (__stdcall *)(std::function<bool __cdecl(std::wstring)> *))v7->_Copy)(&v10);
      else
        v8 = (std::_Func_base<bool,std::wstring > *)((int (__stdcall *)(_DWORD))v7->_Copy)(0);
      v10._Impl = v8;
    }
    else
    {
      v10._Impl = 0;
    }
    LOBYTE(v14) = 2;
    ConsoleCommandLambda::ConsoleCommandLambda((ConsoleCommandLambda *)v5, this, name, v10, v11);
  }
  else
  {
    v9 = 0;
  }
  _Val[0] = v9;
  LOBYTE(v14) = 1;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->commands, _Val);
  LOBYTE(v14) = 0;
  if ( exeFun._Impl )
  {
    ((void (__stdcall *)(bool))exeFun._Impl->_Delete_this)(exeFun._Impl != (std::_Func_base<bool,std::wstring > *)&exeFun);
    exeFun._Impl = 0;
  }
  v14 = -1;
  if ( helpFun._Impl )
    ((void (__stdcall *)(bool))helpFun._Impl->_Delete_this)(helpFun._Impl != (std::_Func_base<std::wstring > *)&helpFun);
}
void Console::addVar(Console *this, std::wstring name, float *var, IVarCallback *callback, bool readOnly, float multiplier)
{
  int v7; // esi
  float v8; // xmm0_4
  SVar *nvar[4]; // [esp+Ch] [ebp-10h] BYREF

  nvar[3] = 0;
  v7 = operator new(72);
  if ( v7 )
  {
    *(_DWORD *)(v7 + 20) = 7;
    *(_DWORD *)(v7 + 16) = 0;
    *(_WORD *)v7 = 0;
    *(_DWORD *)(v7 + 64) = 0;
  }
  else
  {
    v7 = 0;
  }
  nvar[0] = (SVar *)v7;
  if ( (std::wstring *)v7 != &name )
    std::wstring::assign((std::wstring *)v7, &name, 0, 0xFFFFFFFF);
  v8 = multiplier;
  *(_DWORD *)(v7 + 24) = var;
  *(_DWORD *)(v7 + 32) = callback;
  *(_BYTE *)(v7 + 28) = readOnly;
  *(float *)(v7 + 36) = v8;
  *(_BYTE *)(v7 + 40) = 0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->vars, (ICollisionObject *const *)nvar);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void Console::addVarLambda(Console *this, std::wstring name, std::function<void __cdecl(SVar *,float)> lambda, bool readyonly, float multiplier)
{
  int v6; // esi
  bool v7; // al
  float v8; // xmm0_4
  int v9; // ecx
  std::_Func_base<void,SVar *,float>_vtbl *v10; // eax
  int v11; // eax
  SVar *nvar; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  v13 = 1;
  v6 = operator new(72);
  if ( v6 )
  {
    *(_DWORD *)(v6 + 20) = 7;
    *(_DWORD *)(v6 + 16) = 0;
    *(_WORD *)v6 = 0;
    *(_DWORD *)(v6 + 64) = 0;
  }
  else
  {
    v6 = 0;
  }
  nvar = (SVar *)v6;
  if ( (std::wstring *)v6 != &name )
    std::wstring::assign((std::wstring *)v6, &name, 0, 0xFFFFFFFF);
  v7 = readyonly;
  v8 = multiplier;
  *(_DWORD *)(v6 + 24) = 0;
  *(_DWORD *)(v6 + 32) = 0;
  *(_BYTE *)(v6 + 28) = v7;
  *(float *)(v6 + 36) = v8;
  if ( (std::function<void __cdecl(SVar *,float)> *)(v6 + 48) != &lambda )
  {
    v9 = *(_DWORD *)(v6 + 64);
    if ( v9 )
    {
      (*(void (__stdcall **)(bool))(*(_DWORD *)v9 + 16))(v9 != v6 + 48);
      *(_DWORD *)(v6 + 64) = 0;
    }
    if ( lambda._Impl )
    {
      v10 = lambda._Impl->__vftable;
      if ( (std::function<void __cdecl(SVar *,float)> *)lambda._Impl == &lambda )
        v11 = ((int (__stdcall *)(int))v10->_Copy)(v6 + 48);
      else
        v11 = ((int (__stdcall *)(_DWORD))v10->_Copy)(0);
      *(_DWORD *)(v6 + 64) = v11;
    }
    else
    {
      *(_DWORD *)(v6 + 64) = 0;
    }
  }
  *(_BYTE *)(v6 + 40) = 1;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->vars,
    (ICollisionObject *const *)&nvar);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  v13 = -1;
  if ( lambda._Impl )
    ((void (__stdcall *)(bool))lambda._Impl->_Delete_this)(lambda._Impl != (std::_Func_base<void,SVar *,float> *)&lambda);
}
void Console::initCommands(Console *this)
{
  CarAvatar *v2; // ebx
  ConsoleSet *v3; // eax
  int v4; // ecx
  int v5; // eax
  Sim *v6; // ecx
  GameObject **v7; // esi
  int v8; // eax
  GameObject **v9; // esi
  int v10; // eax
  GameObject **v11; // esi
  int v12; // eax
  GameObject **v13; // esi
  int v14; // eax
  Sim *v15; // ecx
  CameraForward *v16; // eax
  int v17; // eax
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v18; // edi
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v19; // esi
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v20; // eax
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *i; // eax
  ConsoleCommand **v23; // eax
  std::vector<ConsoleCommand *> *v24; // esi
  int v25; // edi
  int v26; // edi
  ConsoleCommand **v27; // ecx
  ConsoleCommand **v28; // eax
  ConsoleRefreshInstruments *v29; // eax
  int v30; // eax
  int v31; // edi
  ConsoleCommand **v32; // eax
  int v33; // edi
  ConsoleCommand **v34; // ecx
  ConsoleCommand **v35; // eax
  ConsoleRefreshInstruments *v36; // eax
  int v37; // edi
  ConsoleCommand **v38; // eax
  int v39; // edi
  ConsoleCommand **v40; // ecx
  ConsoleCommand **v41; // eax
  _BYTE multiplier[56]; // [esp-34h] [ebp-9Ch] BYREF
  _BYTE *v43; // [esp+24h] [ebp-44h]
  ConsoleRefreshInstruments *v44; // [esp+28h] [ebp-40h]
  ConsoleSet *v45; // [esp+2Ch] [ebp-3Ch]
  int v46; // [esp+30h] [ebp-38h] BYREF
  ConsoleSet *v47; // [esp+34h] [ebp-34h] BYREF
  int v48; // [esp+38h] [ebp-30h] BYREF
  CarAvatar *v49; // [esp+3Ch] [ebp-2Ch]
  std::wstring name; // [esp+40h] [ebp-28h] BYREF
  int v51; // [esp+64h] [ebp-4h]

  v2 = Sim::getCar(this->sim, 0);
  v49 = v2;
  v3 = (ConsoleSet *)operator new(32);
  v45 = v3;
  v51 = 0;
  if ( v3 )
  {
    ConsoleSet::ConsoleSet(v3, this);
    v45 = (ConsoleSet *)v5;
  }
  else
  {
    v45 = 0;
  }
  *(_DWORD *)&multiplier[52] = v4;
  v6 = this->sim;
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  v51 = -1;
  *(_DWORD *)&multiplier[40] = &Sim::getSceneCamera(v6)->fov;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"fov", 3u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"aniso", 5u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = &v2->driverEyesPosition;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"driverEye.x", 0xBu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = &v2->driverEyesPosition.y;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"driverEye.y", 0xBu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = &v2->driverEyesPosition.z;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"driverEye.z", 0xBu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"graphicsOffset.x", 0x10u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"graphicsOffset.y", 0x10u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"graphicsOffset.z", 0x10u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"graphicsPitchRotation", 0x15u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"bias0", 5u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"bias1", 5u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = &this->IVarCallback;
  *(_DWORD *)&multiplier[40] = 0;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"bias2", 5u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 981668463;
  *(_DWORD *)&multiplier[48] = 0;
  v43 = &multiplier[24];
  *(_DWORD *)&multiplier[24] = &std::_Func_impl<std::_Callable_obj<_lambda_5adc8304e19c9a91ea4fcfb6b36124e9_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&multiplier[28] = v2;
  *(_DWORD *)&multiplier[40] = &multiplier[24];
  v51 = 2;
  *(_DWORD *)&multiplier[20] = 7;
  *(_DWORD *)&multiplier[16] = 0;
  *(_WORD *)multiplier = 0;
  std::wstring::assign((std::wstring *)multiplier, L"ffMult", 6u);
  v51 = -1;
  Console::addVarLambda(
    this,
    *(std::wstring *)multiplier,
    *(std::function<void __cdecl(SVar *,float)> *)&multiplier[24],
    multiplier[48],
    *(float *)&multiplier[52]);
  v7 = v2->gameObjects._Myfirst;
  if ( v7 == v2->gameObjects._Mylast )
  {
LABEL_7:
    v8 = 0;
  }
  else
  {
    while ( 1 )
    {
      v8 = __RTDynamicCast(*v7, 0, &GameObject `RTTI Type Descriptor', &DigitalInstruments `RTTI Type Descriptor', 0);
      if ( v8 )
        break;
      if ( ++v7 == v2->gameObjects._Mylast )
        goto LABEL_7;
    }
  }
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = v8 + 52;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"observeDigital", 0xEu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  v9 = v2->gameObjects._Myfirst;
  if ( v9 == v2->gameObjects._Mylast )
  {
LABEL_11:
    v10 = 0;
  }
  else
  {
    while ( 1 )
    {
      v10 = __RTDynamicCast(*v9, 0, &GameObject `RTTI Type Descriptor', &Flames `RTTI Type Descriptor', 0);
      if ( v10 )
        break;
      if ( ++v9 == v2->gameObjects._Mylast )
        goto LABEL_11;
    }
  }
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = v10 + 52;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"observeFlames", 0xDu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  v11 = v2->gameObjects._Myfirst;
  if ( v11 == v2->gameObjects._Mylast )
  {
LABEL_15:
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v12 = __RTDynamicCast(*v11, 0, &GameObject `RTTI Type Descriptor', &DigitalPanels `RTTI Type Descriptor', 0);
      if ( v12 )
        break;
      if ( ++v11 == v2->gameObjects._Mylast )
        goto LABEL_15;
    }
  }
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = v12 + 52;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"observePanel", 0xCu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  v13 = v2->gameObjects._Myfirst;
  if ( v13 == v2->gameObjects._Mylast )
  {
LABEL_19:
    v14 = 0;
  }
  else
  {
    while ( 1 )
    {
      v14 = __RTDynamicCast(*v13, 0, &GameObject `RTTI Type Descriptor', &CarBrakeLights `RTTI Type Descriptor', 0);
      if ( v14 )
        break;
      if ( ++v13 == v2->gameObjects._Mylast )
        goto LABEL_19;
    }
  }
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = v14 + 132;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"observeLights", 0xDu);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  v15 = this->sim;
  *(_DWORD *)&multiplier[52] = 0;
  *(_DWORD *)&multiplier[48] = &CameraForward `RTTI Type Descriptor';
  *(_DWORD *)&multiplier[44] = &Camera `RTTI Type Descriptor';
  *(_DWORD *)&multiplier[40] = 0;
  v16 = Sim::getSceneCamera(v15);
  v17 = __RTDynamicCast(
          v16,
          *(_DWORD *)&multiplier[40],
          *(_DWORD *)&multiplier[44],
          *(_DWORD *)&multiplier[48],
          *(_DWORD *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[44] = 0;
  *(_DWORD *)&multiplier[40] = v17 + 392;
  *(_DWORD *)&multiplier[36] = 7;
  *(_DWORD *)&multiplier[32] = 0;
  *(_WORD *)&multiplier[16] = 0;
  std::wstring::assign((std::wstring *)&multiplier[16], L"maxLayer", 8u);
  Console::addVar(
    this,
    *(std::wstring *)&multiplier[16],
    *(float **)&multiplier[40],
    *(IVarCallback **)&multiplier[44],
    multiplier[48],
    *(float *)&multiplier[52]);
  v18 = this->sim->optionsManager.options._Myhead;
  v19 = v18->_Left;
  if ( v18->_Left != v18 )
  {
    do
    {
      *(_DWORD *)&multiplier[52] = 1065353216;
      *(_DWORD *)&multiplier[48] = 0;
      *(_DWORD *)&multiplier[44] = &this->IVarCallback;
      *(_DWORD *)&multiplier[40] = 0;
      *(_DWORD *)&multiplier[36] = 7;
      *(_DWORD *)&multiplier[32] = 0;
      *(_WORD *)&multiplier[16] = 0;
      std::wstring::assign((std::wstring *)&multiplier[16], &v19->_Myval.first, 0, 0xFFFFFFFF);
      Console::addVar(
        this,
        *(std::wstring *)&multiplier[16],
        *(float **)&multiplier[40],
        *(IVarCallback **)&multiplier[44],
        multiplier[48],
        *(float *)&multiplier[52]);
      if ( !v19->_Isnil )
      {
        v20 = v19->_Right;
        if ( v20->_Isnil )
        {
          for ( i = v19->_Parent; !i->_Isnil; i = i->_Parent )
          {
            if ( v19 != i->_Right )
              break;
            v19 = i;
          }
          v19 = i;
        }
        else
        {
          v19 = v19->_Right;
          for ( j = v20->_Left; !j->_Isnil; j = j->_Left )
            v19 = j;
        }
      }
    }
    while ( v19 != v18 );
    v2 = v49;
  }
  v23 = this->commands._Mylast;
  v24 = &this->commands;
  v25 = (int)v45;
  v47 = v45;
  if ( &v47 >= v23 || v24->_Myfirst > &v47 )
  {
    if ( v23 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v28 = this->commands._Mylast;
    if ( v28 )
      *v28 = (ConsoleCommand *)v25;
  }
  else
  {
    v26 = &v47 - (ConsoleSet **)v24->_Myfirst;
    if ( v23 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v27 = this->commands._Mylast;
    if ( v27 )
      *v27 = v24->_Myfirst[v26];
  }
  ++this->commands._Mylast;
  v29 = (ConsoleRefreshInstruments *)operator new(32);
  v44 = v29;
  v51 = 3;
  if ( v29 )
  {
    ConsoleRefreshInstruments::ConsoleRefreshInstruments(v29, this);
    v31 = v30;
  }
  else
  {
    v31 = 0;
  }
  v32 = this->commands._Mylast;
  v51 = -1;
  v46 = v31;
  if ( &v46 >= (int *)v32 || v24->_Myfirst > (ConsoleCommand **)&v46 )
  {
    if ( v32 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v35 = this->commands._Mylast;
    if ( v35 )
      *v35 = (ConsoleCommand *)v31;
  }
  else
  {
    v33 = ((char *)&v46 - (char *)v24->_Myfirst) >> 2;
    if ( v32 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v34 = this->commands._Mylast;
    if ( v34 )
      *v34 = v24->_Myfirst[v33];
  }
  ++this->commands._Mylast;
  v36 = (ConsoleRefreshInstruments *)operator new(32);
  v37 = (int)v36;
  v44 = v36;
  v51 = 4;
  if ( v36 )
  {
    v36->command._Myres = 7;
    v36->command._Mysize = 0;
    v36->command._Bx._Buf[0] = 0;
    v36->console = this;
    *(_DWORD *)&multiplier[52] = 9;
    *(_DWORD *)&multiplier[48] = L"testCrash";
    LOBYTE(v51) = 5;
    v36->__vftable = (ConsoleRefreshInstruments_vtbl *)&ConsoleCrash::`vftable';
    std::wstring::assign(&v36->command, *(const wchar_t **)&multiplier[48], *(unsigned int *)&multiplier[52]);
  }
  else
  {
    v37 = 0;
  }
  v38 = this->commands._Mylast;
  v51 = -1;
  v48 = v37;
  if ( &v48 >= (int *)v38 || v24->_Myfirst > (ConsoleCommand **)&v48 )
  {
    if ( v38 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v41 = this->commands._Mylast;
    if ( v41 )
      *v41 = (ConsoleCommand *)v37;
  }
  else
  {
    v39 = ((char *)&v48 - (char *)v24->_Myfirst) >> 2;
    if ( v38 == this->commands._Myend )
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->commands, 1u);
    v40 = this->commands._Mylast;
    if ( v40 )
      *v40 = v24->_Myfirst[v39];
  }
  ++this->commands._Mylast;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"saveff", 6u);
  v51 = 6;
  v44 = (ConsoleRefreshInstruments *)&multiplier[32];
  *(_DWORD *)&multiplier[32] = &std::_Func_impl<std::_Callable_obj<_lambda_195a8fc541f28759226bf4d1f39832db_,0>,std::allocator<std::_Func_class<std::wstring,>>,std::wstring,>::`vftable';
  *(_DWORD *)&multiplier[48] = &multiplier[32];
  *(_DWORD *)&multiplier[8] = &std::_Func_impl<std::_Callable_obj<_lambda_5d49014e8dad7e676d58818d1d25ba7c_,0>,std::allocator<std::_Func_class<bool,std::wstring>>,bool,std::wstring>::`vftable';
  *(_DWORD *)&multiplier[12] = v2;
  *(_DWORD *)&multiplier[24] = &multiplier[8];
  Console::addCommand(
    this,
    &name,
    *(std::function<bool __cdecl(std::wstring)> *)&multiplier[8],
    *(std::function<std::wstring __cdecl(void)> *)&multiplier[32]);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void Console::onKeyChar(Console *this, const unsigned int key)
{
  SVar **v3; // eax
  std::wstring *v4; // eax
  Console *v5; // eax
  int v6; // edx
  std::wstring v7; // [esp-30h] [ebp-70h] BYREF
  std::wstring v8; // [esp-18h] [ebp-58h] BYREF
  std::wstring *v9; // [esp+14h] [ebp-2Ch]
  std::wstring result; // [esp+18h] [ebp-28h] BYREF
  int v11; // [esp+3Ch] [ebp-4h]

  if ( this[-1].accumulator._Bx._Alias[4] )
  {
    if ( key == 8 )
    {
      v3 = this->vars._Mylast;
      if ( v3 )
      {
        v4 = std::wstring::substr((std::wstring *)&this->IVarCallback, &result, 0, (unsigned int)v3 - 1);
        std::wstring::operator=((std::wstring *)&this->IVarCallback, v4);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
    }
    else if ( key == 13 )
    {
      v9 = &v8;
      std::wstring::wstring(&v8, L"\n");
      v11 = 0;
      v7._Myres = 7;
      v7._Mysize = 0;
      v7._Bx._Buf[0] = 0;
      std::wstring::assign(&v7, (const std::wstring *)&this->IVarCallback, 0, 0xFFFFFFFF);
      v5 = Console::operator<<((Console *)((char *)this - 56), v7);
      v11 = -1;
      Console::operator<<(v5, v8);
      v8._Myres = 7;
      v8._Mysize = 0;
      v8._Bx._Buf[0] = 0;
      std::wstring::assign(&v8, (const std::wstring *)&this->IVarCallback, 0, 0xFFFFFFFF);
      Console::parse((Console *)((char *)this - 56), v8);
      std::vector<std::wstring>::push_back(
        (std::vector<std::wstring> *)&this->isActive,
        (const std::wstring *)&this->IVarCallback);
      v6 = (unsigned __int64)(715827883 * ((__int64)this->parent - *(_DWORD *)&this->isActive)) >> 32;
      v8._Myres = (unsigned int)word_17BE9D8;
      this->gameObjects._Mylast = (GameObject **)((v6 >> 2) + ((unsigned int)v6 >> 31));
      std::wstring::assign((std::wstring *)&this->IVarCallback, (const wchar_t *)v8._Myres);
    }
    else
    {
      std::wstring::append((std::wstring *)&this->IVarCallback, 1u, (char)key);
    }
  }
}
void Console::onKeyDown(Console *this, const OnKeyEvent *message)
{
  unsigned int v3; // ebx
  const std::wstring *v4; // eax
  unsigned int v5; // edi
  const std::wstring *v6; // eax
  int v7; // ecx

  if ( this[-1].accumulator._Bx._Alias[4] )
  {
    if ( message->keyCode == 38 )
    {
      v3 = (unsigned int)--this->gameObjects._Mylast;
      if ( v3 >= ((int)this->parent - *(_DWORD *)&this->isActive) / 24 )
      {
        this->gameObjects._Mylast = 0;
      }
      else
      {
        v4 = (const std::wstring *)(*(_DWORD *)&this->isActive + 24 * v3);
        if ( &this->IVarCallback != (IVarCallback *)v4 )
          std::wstring::assign((std::wstring *)&this->IVarCallback, v4, 0, 0xFFFFFFFF);
      }
    }
    if ( message->keyCode == 40 )
    {
      v5 = (unsigned int)++this->gameObjects._Mylast;
      if ( v5 >= ((int)this->parent - *(_DWORD *)&this->isActive) / 24 )
      {
        v7 = (int)this->parent - *(_DWORD *)&this->isActive;
        this->gameObjects._Mylast = (GameObject **)(((int)((unsigned __int64)(715827883i64 * v7) >> 32) >> 2)
                                                  + ((unsigned int)((unsigned __int64)(715827883i64 * v7) >> 32) >> 31)
                                                  - 1);
      }
      else
      {
        v6 = (const std::wstring *)(*(_DWORD *)&this->isActive + 24 * v5);
        if ( &this->IVarCallback != (IVarCallback *)v6 )
          std::wstring::assign((std::wstring *)&this->IVarCallback, v6, 0, 0xFFFFFFFF);
      }
    }
  }
}
void Console::onSetVar(Console *this, SVar *var, float value)
{
  wchar_t *v4; // edi
  _DWORD *v5; // esi
  CarAvatar *v6; // ebp
  _DWORD *v7; // edi
  _DWORD *v8; // esi
  const wchar_t *v9; // eax
  int **v10; // eax
  int *j; // eax
  int i; // eax
  int v13; // ebp
  Console *v14; // eax
  Console *v15; // eax
  Console *v16; // eax
  int v17; // ecx
  Console *v18; // eax
  Console *v19; // eax
  Console *v20; // eax
  int v21; // ecx
  Console *v22; // eax
  Console *v23; // eax
  Console *v24; // eax
  float *v25; // eax
  std::wstring v26; // [esp-40h] [ebp-8Ch] BYREF
  float *v27; // [esp-28h] [ebp-74h]
  std::wstring v28; // [esp-24h] [ebp-70h] BYREF
  std::wstring v29; // [esp-Ch] [ebp-58h] BYREF
  Console *v30; // [esp+20h] [ebp-2Ch]
  std::wstring *v31; // [esp+24h] [ebp-28h]
  vec3f b; // [esp+28h] [ebp-24h] BYREF
  vec3f result; // [esp+34h] [ebp-18h] BYREF
  int v34; // [esp+48h] [ebp-4h]

  v30 = this;
  v4 = this->name._Bx._Ptr;
  v5 = (_DWORD *)*((_DWORD *)v4 + 10);
  if ( v5 == *((_DWORD **)v4 + 11) )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = (CarAvatar *)__RTDynamicCast(
                          *v5,
                          0,
                          &GameObject `RTTI Type Descriptor',
                          &CarAvatar `RTTI Type Descriptor',
                          0);
      if ( v6 )
        break;
      if ( ++v5 == *((_DWORD **)v4 + 11) )
        goto LABEL_4;
    }
  }
  v7 = (_DWORD *)*((_DWORD *)this->name._Bx._Ptr + 34);
  v8 = (_DWORD *)*v7;
  if ( (_DWORD *)*v7 == v7 )
  {
LABEL_19:
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"graphicsOffset.x", 0x10u) )
    {
      CarAvatar::getGraphicsOffset(v6, &b);
      b.x = value;
      CarAvatar::setGraphicsOffset(v6, b);
    }
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"graphicsOffset.y", 0x10u) )
    {
      CarAvatar::getGraphicsOffset(v6, &b);
      b.y = value;
      CarAvatar::setGraphicsOffset(v6, b);
    }
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"graphicsOffset.z", 0x10u) )
    {
      CarAvatar::getGraphicsOffset(v6, &b);
      b.z = value;
      *(_QWORD *)&v29._Bx._Alias[12] = *(_QWORD *)&b.x;
      *(float *)&v29._Myres = value;
      CarAvatar::setGraphicsOffset(v6, *(vec3f *)&v29._Bx._Alias[12]);
    }
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"graphicsPitchRotation", 0x15u) )
      CarAvatar::setGraphicsPitchRotation(v6, value * 0.017453);
    v13 = (int)v30;
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"bias0", 5u) )
    {
      GraphicsManager::getShadowMapBias(*(GraphicsManager **)(v30[-1].commandLine._Mysize + 192), &b);
      GraphicsManager::setShadowMapBias(*(GraphicsManager **)(v30[-1].commandLine._Mysize + 192), value, b.y, b.z);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      std::wstring::assign(&v29, L"\n", 1u);
      v34 = 0;
      v30 = (Console *)&v28;
      v28._Myres = 7;
      v28._Mysize = 0;
      v28._Bx._Buf[0] = 0;
      std::wstring::assign(&v28, L"]", 1u);
      LOBYTE(v34) = 1;
      v27 = &value;
      v26._Myres = 7;
      v26._Mysize = 0;
      v26._Bx._Buf[0] = 0;
      std::wstring::assign(&v26, L"[SHADOW BIAS0 set to: ", 0x16u);
      v14 = Console::operator<<((Console *)(v13 - 52), v26);
      v15 = Console::operator<<(v14, v27);
      LOBYTE(v34) = 0;
      v16 = Console::operator<<(v15, v28);
      v34 = -1;
      Console::operator<<(v16, v29);
    }
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"bias1", 5u) )
    {
      GraphicsManager::getShadowMapBias(*(GraphicsManager **)(*(_DWORD *)(v13 - 48) + 192), &b);
      v17 = *(_DWORD *)(v13 - 48);
      v29._Myres = LODWORD(b.z);
      GraphicsManager::setShadowMapBias(*(GraphicsManager **)(v17 + 192), b.x, value, b.z);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      std::wstring::assign(&v29, L"\n", 1u);
      v34 = 2;
      v31 = &v28;
      v28._Myres = 7;
      v28._Mysize = 0;
      v28._Bx._Buf[0] = 0;
      std::wstring::assign(&v28, L"]", 1u);
      LOBYTE(v34) = 3;
      v27 = &value;
      v26._Myres = 7;
      v26._Mysize = 0;
      v26._Bx._Buf[0] = 0;
      std::wstring::assign(&v26, L"[SHADOW BIAS1 set to: ", 0x16u);
      v18 = Console::operator<<((Console *)(v13 - 52), v26);
      v19 = Console::operator<<(v18, v27);
      LOBYTE(v34) = 2;
      v20 = Console::operator<<(v19, v28);
      v34 = -1;
      Console::operator<<(v20, v29);
    }
    if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, L"bias2", 5u) )
    {
      GraphicsManager::getShadowMapBias(*(GraphicsManager **)(*(_DWORD *)(v13 - 48) + 192), &result);
      v21 = *(_DWORD *)(v13 - 48);
      *(float *)&v29._Myres = value;
      GraphicsManager::setShadowMapBias(*(GraphicsManager **)(v21 + 192), result.x, result.y, value);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      std::wstring::assign(&v29, L"\n", 1u);
      v34 = 4;
      v31 = &v28;
      v28._Myres = 7;
      v28._Mysize = 0;
      v28._Bx._Buf[0] = 0;
      std::wstring::assign(&v28, L"]", 1u);
      LOBYTE(v34) = 5;
      v27 = &value;
      v26._Myres = 7;
      v26._Mysize = 0;
      v26._Bx._Buf[0] = 0;
      std::wstring::assign(&v26, L"[SHADOW BIAS2 set to: ", 0x16u);
      v22 = Console::operator<<((Console *)(v13 - 52), v26);
      v23 = Console::operator<<(v22, v27);
      LOBYTE(v34) = 4;
      v24 = Console::operator<<(v23, v28);
      v34 = -1;
      Console::operator<<(v24, v29);
    }
  }
  else
  {
    while ( 1 )
    {
      v9 = (const wchar_t *)(v8 + 4);
      if ( v8[9] >= 8u )
        v9 = *(const wchar_t **)v9;
      if ( !std::wstring::compare(&var->name, 0, var->name._Mysize, v9, v8[8]) )
        break;
      if ( !*((_BYTE *)v8 + 13) )
      {
        v10 = (int **)v8[2];
        if ( *((_BYTE *)v10 + 13) )
        {
          for ( i = v8[1]; !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 4) )
          {
            if ( v8 != *(_DWORD **)(i + 8) )
              break;
            v8 = (_DWORD *)i;
          }
          v8 = (_DWORD *)i;
        }
        else
        {
          v8 = (_DWORD *)v8[2];
          for ( j = *v10; !*((_BYTE *)j + 13); j = (int *)*j )
            v8 = j;
        }
      }
      if ( v8 == v7 )
        goto LABEL_19;
    }
    v25 = std::map<std::wstring,float>::operator[]((std::map<std::wstring,float> *)v30->name._Bx._Ptr + 17, &var->name);
    *v25 = value;
  }
}
void Console::parse(Console *this, std::wstring c)
{
  std::wstring *v3; // eax
  Console *v4; // eax
  ConsoleCommand **v5; // esi
  ConsoleCommand **v6; // edi
  ConsoleCommand *v7; // ebx
  ConsoleCommand_vtbl *v8; // edx
  Console *v9; // eax
  Console *v10; // eax
  Console *v11; // eax
  Console *v12; // eax
  Console *v13; // eax
  bool v14; // zf
  ConsoleCommand **v15; // esi
  ConsoleCommand **v16; // eax
  int v17; // ebx
  unsigned int v18; // ebp
  std::wstring *v19; // eax
  ConsoleCommand *v20; // edi
  std::wstring v21; // [esp-8Eh] [ebp-F4h] BYREF
  std::wstring v22; // [esp-76h] [ebp-DCh] BYREF
  std::wstring v23; // [esp-5Eh] [ebp-C4h] BYREF
  std::wstring v24; // [esp-46h] [ebp-ACh] BYREF
  std::wstring v25; // [esp-2Eh] [ebp-94h] BYREF
  std::wstring v26; // [esp-16h] [ebp-7Ch] BYREF
  int v27; // [esp+16h] [ebp-50h] BYREF
  std::vector<std::wstring> result; // [esp+1Ah] [ebp-4Ch] BYREF
  unsigned int v29; // [esp+26h] [ebp-40h]
  std::wstring *v30; // [esp+2Ah] [ebp-3Ch]
  std::wstring *v31; // [esp+2Eh] [ebp-38h]
  std::wstring *v32; // [esp+32h] [ebp-34h]
  std::wstring *v33; // [esp+36h] [ebp-30h]
  std::wstring *v34; // [esp+3Ah] [ebp-2Ch]
  std::wstring splitter; // [esp+3Eh] [ebp-28h] BYREF
  int v36; // [esp+62h] [ebp-4h]

  v36 = 0;
  splitter._Myres = 7;
  splitter._Mysize = 0;
  splitter._Bx._Buf[0] = 0;
  std::wstring::assign(&splitter, L" \n\r", 3u);
  LOBYTE(v36) = 1;
  ksSplitString(&result, &c, &splitter);
  LOBYTE(v36) = 3;
  if ( splitter._Myres >= 8 )
    operator delete(splitter._Bx._Ptr);
  splitter._Myres = 7;
  splitter._Bx._Buf[0] = 0;
  v3 = result._Myfirst;
  splitter._Mysize = 0;
  if ( result._Myfirst == result._Mylast )
    goto LABEL_20;
  if ( std::wstring::compare(result._Myfirst, 0, result._Myfirst->_Mysize, L"help", 4u) )
  {
    if ( !std::wstring::compare(result._Myfirst, 0, result._Myfirst->_Mysize, L"exit", 4u) )
    {
      this->game->shutdown(this->game);
      goto LABEL_10;
    }
    v15 = this->commands._Myfirst;
    v16 = this->commands._Mylast;
    v17 = 0;
    v18 = (unsigned int)((char *)v16 - (char *)v15 + 3) >> 2;
    if ( v15 > v16 )
      v18 = 0;
    if ( v18 )
    {
      do
      {
        v19 = result._Myfirst;
        v20 = *v15;
        if ( result._Myfirst->_Myres >= 8 )
          v19 = (std::wstring *)result._Myfirst->_Bx._Ptr;
        if ( !std::wstring::compare(
                &(*v15)->command,
                0,
                (*v15)->command._Mysize,
                v19->_Bx._Buf,
                result._Myfirst->_Mysize) )
        {
          v26._Mysize = 0;
          v26._Myres = 7;
          v26._Bx._Buf[0] = 0;
          std::wstring::assign(&v26, &c, 0, 0xFFFFFFFF);
          ((void (*)(ConsoleCommand *, wchar_t *, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int))v20->execute)(
            v20,
            v26._Bx._Ptr,
            *(_DWORD *)&v26._Bx._Alias[4],
            *(_DWORD *)&v26._Bx._Alias[8],
            *(_DWORD *)&v26._Bx._Alias[12],
            v26._Mysize,
            v26._Myres);
        }
        ++v17;
        ++v15;
      }
      while ( v17 != v18 );
    }
    v3 = result._Myfirst;
LABEL_20:
    v14 = v3 == 0;
    goto LABEL_21;
  }
  v31 = &v26;
  std::wstring::wstring(&v26, L"\n");
  LOBYTE(v36) = 4;
  std::wstring::wstring(&v25, L"[ AVAILABLE COMMANDS ]");
  v4 = Console::operator<<(this, v25);
  LOBYTE(v36) = 3;
  Console::operator<<(v4, v26);
  v5 = this->commands._Myfirst;
  v6 = this->commands._Mylast;
  if ( v5 == v6 )
  {
LABEL_10:
    v14 = result._Myfirst == 0;
    goto LABEL_21;
  }
  do
  {
    v7 = *v5;
    v30 = &v26;
    v26._Myres = 7;
    v26._Mysize = 0;
    v26._Bx._Buf[0] = 0;
    std::wstring::assign(&v26, L"\n", 1u);
    LOBYTE(v36) = 5;
    v31 = &v25;
    v25._Myres = 7;
    v25._Mysize = 0;
    v25._Bx._Buf[0] = 0;
    std::wstring::assign(&v25, L">", 1u);
    v8 = v7->__vftable;
    v34 = &v24;
    LOBYTE(v36) = 6;
    v8->getHelp(v7, &v24);
    LOBYTE(v36) = 7;
    v32 = &v23;
    v23._Myres = 7;
    v23._Mysize = 0;
    v23._Bx._Buf[0] = 0;
    std::wstring::assign(&v23, L" <", 2u);
    LOBYTE(v36) = 8;
    v33 = &v22;
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, &v7->command, 0, 0xFFFFFFFF);
    LOBYTE(v36) = 9;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"- ", 2u);
    v9 = Console::operator<<(this, v21);
    LOBYTE(v36) = 8;
    v10 = Console::operator<<(v9, v22);
    LOBYTE(v36) = 7;
    v11 = Console::operator<<(v10, v23);
    LOBYTE(v36) = 6;
    v12 = Console::operator<<(v11, v24);
    LOBYTE(v36) = 5;
    v13 = Console::operator<<(v12, v25);
    LOBYTE(v36) = 3;
    Console::operator<<(v13, v26);
    ++v5;
  }
  while ( v5 != v6 );
  v14 = result._Myfirst == 0;
LABEL_21:
  LOBYTE(v36) = 0;
  if ( !v14 )
  {
    std::_Container_base0::_Orphan_all(&result);
    v26._Myres = v29;
    v26._Mysize = (unsigned int)&v27 + 3;
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(result._Myfirst, result._Mylast);
    operator delete(result._Myfirst);
    result._Myend = 0;
    result._Mylast = 0;
    result._Myfirst = 0;
  }
  if ( c._Myres >= 8 )
    operator delete(c._Bx._Ptr);
}
void Console::renderHUD(Console *this, float dt)
{
  GLRenderer *v3; // esi
  std::wstring *v4; // edi
  std::wstring *v5; // esi
  float y; // xmm0_4
  Sim *v7; // eax
  Game *v8; // eax
  double v9; // xmm0_8
  std::wstring *v10; // esi
  float v11; // [esp+24h] [ebp-5Ch]
  std::wstring result; // [esp+28h] [ebp-58h] BYREF
  std::wstring _Left; // [esp+40h] [ebp-40h] BYREF
  std::wstring v14; // [esp+58h] [ebp-28h] BYREF
  int v15; // [esp+7Ch] [ebp-4h]

  if ( this->isActive )
  {
    v3 = this->game->graphics->gl;
    GLRenderer::begin(v3, eQuads, 0);
    GLRenderer::color3f(v3, 0.40000001, 0.40000001, 0.40000001);
    v11 = 0.0;
    GLRenderer::vertex3f(v3, 0.0, 0.0, 0.0);
    GLRenderer::vertex3f(v3, 0.0, 300.0, 0.0);
    GLRenderer::vertex3f(v3, (float)this->game->graphics->videoSettings.width, 300.0, 0.0);
    GLRenderer::vertex3f(v3, (float)this->game->graphics->videoSettings.width, 0.0, 0.0);
    GLRenderer::end(v3);
    v4 = this->lines._Mylast;
    v5 = this->lines._Myfirst;
    if ( v5 != v4 )
    {
      y = 0.0;
      do
      {
        Font::blitString(this->font, 0.0, y, v5++, 1.0, eAlignLeft);
        y = v11 + 20.0;
        v11 = v11 + 20.0;
      }
      while ( v5 != v4 );
    }
    v7 = this->sim;
    _Left._Myres = 7;
    v8 = v7->game;
    _Left._Mysize = 0;
    v9 = v8->gameTime.now * 0.001;
    _Left._Bx._Buf[0] = 0;
    std::wstring::assign(&_Left, L"ACC> ", 5u);
    v15 = 0;
    std::operator+<wchar_t>(&result, &_Left, &this->commandLine);
    LOBYTE(v15) = 2;
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
    _Left._Myres = 7;
    _Left._Mysize = 0;
    _Left._Bx._Buf[0] = 0;
    if ( (int)v9 % 2 )
    {
      v10 = std::operator+<wchar_t>(&v14, &result, L"_");
      if ( &result != v10 )
      {
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&result, v10);
      }
      if ( v14._Myres >= 8 )
        operator delete(v14._Bx._Ptr);
    }
    Font::blitString(this->font, 0.0, 260.0, &result, 1.0, eAlignLeft);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
}
void Console::show(Console *this, bool mode)
{
  IKeyEventListener *v2; // eax
  Game *v3; // ecx

  this->isActive = mode;
  v2 = &this->IKeyEventListener;
  v3 = this->game;
  if ( mode )
    CollisionMeshODE::setUserPointer(&v3->keyboardManager, v2);
  else
    KeyboardManager::releaseFocus(&v3->keyboardManager, v2);
}
Console *__cdecl Console::singleton()
{
  return Console::_singleton;
}
