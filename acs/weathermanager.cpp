#include "weathermanager.h"
std::wstring *WeatherManager::getLastWeatherName(WeatherManager *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->lastCustomWeatherName, 0, 0xFFFFFFFF);
  return result;
}
void WeatherManager::WeatherManager(WeatherManager *this, Sim *a_sim)
{
  std::wstring v3; // [esp-1Ch] [ebp-24h] BYREF
  Game *v4; // [esp-4h] [ebp-Ch]

  v4 = a_sim->game;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, L"WEATHER_MANAGER", 0xFu);
  GameObject::GameObject(this, v3, v4);
  this->__vftable = (WeatherManager_vtbl *)&WeatherManager::`vftable';
  this->lastCustomWeatherName._Myres = 7;
  this->lastCustomWeatherName._Mysize = 0;
  this->lastCustomWeatherName._Bx._Buf[0] = 0;
  this->sim = a_sim;
}
WeatherManager *WeatherManager::`scalar deleting destructor'(WeatherManager *this, unsigned int a2)
{
  this->__vftable = (WeatherManager_vtbl *)&WeatherManager::`vftable';
  if ( this->lastCustomWeatherName._Myres >= 8 )
    operator delete(this->lastCustomWeatherName._Bx._Ptr);
  this->lastCustomWeatherName._Myres = 7;
  this->lastCustomWeatherName._Mysize = 0;
  this->lastCustomWeatherName._Bx._Buf[0] = 0;
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void WeatherManager::applyCustomWeather(WeatherManager *this, const std::wstring *name)
{
  const std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  Game *v6; // eax
  std::wstring *v7; // eax
  bool v8; // zf
  std::wstring *v9; // eax
  float no_pp_mult; // [esp+14h] [ebp-D0h]
  std::wstring result; // [esp+18h] [ebp-CCh] BYREF
  std::wstring filenameCC; // [esp+30h] [ebp-B4h] BYREF
  std::wstring filename; // [esp+48h] [ebp-9Ch] BYREF
  std::wstring v14; // [esp+60h] [ebp-84h] BYREF
  std::wstring key; // [esp+78h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+90h] [ebp-54h] BYREF
  int v17; // [esp+E0h] [ebp-4h]

  if ( name->_Myres < 8 )
    v3 = name;
  else
    v3 = (const std::wstring *)name->_Bx._Ptr;
  _printf("Loading custom weather: %S\n", v3->_Bx._Buf);
  v4 = std::operator+<wchar_t>(&result, L"content/weather/", name);
  v17 = 0;
  std::operator+<wchar_t>(&filename, v4, L"/weather.ini");
  LOBYTE(v17) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v5 = std::operator+<wchar_t>(&v14, L"content/weather/", name);
  LOBYTE(v17) = 3;
  std::operator+<wchar_t>(&filenameCC, v5, L"/colorCurves.ini");
  LOBYTE(v17) = 5;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Bx._Buf[0] = 0;
  v6 = this->game;
  v14._Myres = 7;
  v14._Mysize = 0;
  no_pp_mult = FLOAT_1_0;
  if ( !v6->graphics->videoSettings.ppHDREnabled )
  {
    INIReader::INIReader(&ini, &filenameCC);
    LOBYTE(v17) = 6;
    if ( ini.ready )
    {
      std::wstring::wstring(&key, L"HDR_OFF_MULT");
      LOBYTE(v17) = 7;
      std::wstring::wstring(&result, L"HEADER");
      LOBYTE(v17) = 8;
      no_pp_mult = INIReader::getFloat(&ini, &result, &key);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    LOBYTE(v17) = 5;
    INIReader::~INIReader(&ini);
  }
  if ( Path::fileExists((unsigned int)_printf, &filename, 0) )
  {
    WeatherGenerator::loadPreset(&filename, this->game->graphics, no_pp_mult);
  }
  else
  {
    v7 = &filename;
    if ( filename._Myres >= 8 )
      v7 = (std::wstring *)filename._Bx._Ptr;
    _printf("ERROR: Could not find: %S\n", v7->_Bx._Buf);
  }
  v8 = Path::fileExists((unsigned int)_printf, &filenameCC, 0) == 0;
  v9 = &filenameCC;
  if ( v8 )
  {
    if ( filenameCC._Myres >= 8 )
      v9 = (std::wstring *)filenameCC._Bx._Ptr;
    _printf("ERROR: Could not find: %S\n", v9->_Bx._Buf);
  }
  else
  {
    GraphicsManager::loadLightingSettings(this->game->graphics, &filenameCC);
  }
  if ( &this->lastCustomWeatherName != name )
    std::wstring::assign(&this->lastCustomWeatherName, name, 0, 0xFFFFFFFF);
  if ( filenameCC._Myres >= 8 )
    operator delete(filenameCC._Bx._Ptr);
  filenameCC._Myres = 7;
  filenameCC._Mysize = 0;
  filenameCC._Bx._Buf[0] = 0;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
