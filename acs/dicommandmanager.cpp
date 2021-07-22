#include "dicommandmanager.h"
void DICommandManager::DICommandManager(DICommandManager *this, Game *game)
{
  int v3; // esi
  std::wstring v4; // [esp-1Ch] [ebp-BCh] BYREF
  BOOL v5; // [esp-4h] [ebp-A4h]
  char v6; // [esp+13h] [ebp-8Dh]
  DICommandManager *v7; // [esp+18h] [ebp-88h]
  std::wstring key; // [esp+1Ch] [ebp-84h] BYREF
  std::wstring section; // [esp+34h] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+4Ch] [ebp-54h] BYREF
  int v11; // [esp+9Ch] [ebp-4h]

  this->directInput = 0;
  v7 = this;
  this->commands._Myfirst = 0;
  this->commands._Mylast = 0;
  this->commands._Myend = 0;
  v5 = 0;
  this->game = game;
  v11 = 0;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)this, v4, v5);
  LOBYTE(v11) = 1;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"JOY", 3u);
    LOBYTE(v11) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"STEER", 5u);
    LOBYTE(v11) = 3;
    v3 = INIReader::getInt(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v11) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DPAD_INDEX_OVERRIDE", 0x13u);
    LOBYTE(v11) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ADVANCED", 8u);
    LOBYTE(v11) = 5;
    v6 = INIReader::hasKey(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v11) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v6 )
    {
      std::wstring::wstring(&section, L"DPAD_INDEX_OVERRIDE");
      LOBYTE(v11) = 6;
      std::wstring::wstring(&key, L"ADVANCED");
      LOBYTE(v11) = 7;
      v3 = INIReader::getInt(&ini, &key, &section);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v11) = 1;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    if ( v3 != -1 )
    {
      key._Bx._Alias[8] = 0;
      *(_QWORD *)key._Bx._Buf = (unsigned int)v3 | 0xFFFFFFFF00000000ui64;
      key._Mysize = 0;
      key._Myres = 0;
      *(_DWORD *)&key._Bx._Alias[12] = 38;
      std::vector<DICommand>::push_back(&this->commands, (DICommand *)&key);
      key._Bx._Alias[8] = 0;
      *(_QWORD *)key._Bx._Buf = (unsigned int)v3 | 0xFFFFFFFF00000000ui64;
      key._Mysize = 0;
      key._Myres = 18000;
      *(_DWORD *)&key._Bx._Alias[12] = 40;
      std::vector<DICommand>::push_back(&this->commands, (DICommand *)&key);
      key._Bx._Alias[8] = 0;
      *(_QWORD *)key._Bx._Buf = (unsigned int)v3 | 0xFFFFFFFF00000000ui64;
      key._Mysize = 0;
      key._Myres = 27000;
      *(_DWORD *)&key._Bx._Alias[12] = 37;
      std::vector<DICommand>::push_back(&this->commands, (DICommand *)&key);
      key._Bx._Alias[8] = 0;
      *(_QWORD *)key._Bx._Buf = (unsigned int)v3 | 0xFFFFFFFF00000000ui64;
      key._Mysize = 0;
      key._Myres = 9000;
      *(_DWORD *)&key._Bx._Alias[12] = 39;
      std::vector<DICommand>::push_back(&this->commands, (DICommand *)&key);
    }
  }
  LOBYTE(v11) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void DICommandManager::step(DICommandManager *this)
{
  DirectInput *v2; // eax
  DICommand *v3; // esi
  DICommand *i; // edi
  InputDevice *v5; // eax
  int v6; // ecx
  bool v7; // bl

  if ( this->directInput || (DirectInput::singleton(), (this->directInput = v2) != 0) )
  {
    v3 = this->commands._Myfirst;
    for ( i = this->commands._Mylast; v3 != i; ++v3 )
    {
      v5 = DirectInput::getDevice(this->directInput, v3->index);
      if ( v5 )
      {
        v6 = v3->button;
        if ( v6 == -1 )
          v7 = v5->state.pow[v3->powIndex] == v3->powValue;
        else
          v7 = v5->state.buttons[v6] != 0;
        if ( v7 && !v3->status )
          PostMessageA((HWND)this->game->graphics->videoSettings.hWnd, 0x100u, v3->keyCode, 1);
        v3->status = v7;
      }
    }
  }
}
