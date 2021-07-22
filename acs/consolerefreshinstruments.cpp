#include "consolerefreshinstruments.h"
void ConsoleRefreshInstruments::ConsoleRefreshInstruments(ConsoleRefreshInstruments *this, Console *con)
{
  std::wstring *v3; // ecx

  v3 = &this->command;
  v3->_Myres = 7;
  v3->_Mysize = 0;
  v3->_Bx._Buf[0] = 0;
  this->console = con;
  this->__vftable = (ConsoleRefreshInstruments_vtbl *)&ConsoleRefreshInstruments::`vftable';
  std::wstring::assign(v3, L"refresh_instruments", 0x13u);
}
char ConsoleRefreshInstruments::execute(ConsoleRefreshInstruments *this, std::wstring commandLine)
{
  Console *v3; // ecx
  CarAvatar *v4; // ebx
  GameObject **v5; // esi
  DigitalInstruments *v6; // edi
  Console *v7; // eax
  std::wstring v9; // [esp-30h] [ebp-58h] BYREF
  std::wstring v10; // [esp-18h] [ebp-40h] BYREF
  std::wstring *v11; // [esp+14h] [ebp-14h]
  int v12; // [esp+24h] [ebp-4h]

  v3 = this->console;
  v12 = 0;
  v4 = Sim::getCar(v3->sim, 0);
  v5 = v4->gameObjects._Myfirst;
  if ( v5 == v4->gameObjects._Mylast )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = (DigitalInstruments *)__RTDynamicCast(
                                   *v5,
                                   0,
                                   &GameObject `RTTI Type Descriptor',
                                   &DigitalInstruments `RTTI Type Descriptor',
                                   0);
      if ( v6 )
        break;
      if ( ++v5 == v4->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  v11 = &v10;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"\n", 1u);
  LOBYTE(v12) = 1;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"REFRESHING digital_instruments.ini", 0x22u);
  v7 = Console::operator<<(this->console, v9);
  LOBYTE(v12) = 0;
  Console::operator<<(v7, v10);
  FileChangeObserver::reset(&v6->observer);
  INIReader::clearCache();
  DigitalInstruments::initInstruments(v6);
  if ( commandLine._Myres >= 8 )
    operator delete(commandLine._Bx._Ptr);
  return 1;
}
std::wstring *ConsoleRefreshInstruments::getHelp(ConsoleRefreshInstruments *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, L"refresh_instruments: no parameters needed", 0x29u);
  return result;
}
