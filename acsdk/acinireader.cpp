#include "acinireader.h
void ACINIReader::ACINIReader(ACINIReader *this)
{
  this->__vftable = (ACINIReader_vtbl *)&ACINIReader::`vftable';
  this->ini = 0;
}
void ACINIReader::~ACINIReader(ACINIReader *this)
{
  INIReader *v1; // ecx

  this->__vftable = (ACINIReader_vtbl *)&ACINIReader::`vftable';
  v1 = this->ini;
  if ( v1 )
    ((void (*)(INIReader *, int))v1->~INIReader)(v1, 1);
}
ACINIReader *ACINIReader::`scalar deleting destructor'(ACINIReader *this, unsigned int a2)
{
  INIReader *v3; // ecx

  v3 = this->ini;
  this->__vftable = (ACINIReader_vtbl *)&ACINIReader::`vftable';
  if ( v3 )
    ((void (*)(INIReader *, int))v3->~INIReader)(v3, 1);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double ACINIReader::getFloat(ACINIReader *this, const std::wstring *section, const std::wstring *key)
{
  INIReader *v3; // ecx
  double result; // st7

  v3 = this->ini;
  if ( v3 )
    result = INIReader::getFloat(v3, section, key);
  else
    result = 0.0;
  return result;
}
int ACINIReader::getInt(ACINIReader *this, const std::wstring *section, const std::wstring *key)
{
  INIReader *v3; // ecx
  int result; // eax

  v3 = this->ini;
  if ( v3 )
    result = INIReader::getInt(v3, section, key);
  else
    result = 0;
  return result;
}
unsigned int ACINIReader::getString(ACINIReader *this, const std::wstring *section, const std::wstring *key, wchar_t *buffer, int bufferSize)
{
  INIReader *v5; // ecx
  std::wstring *v6; // eax
  unsigned int v7; // esi
  std::wstring s; // [esp+4h] [ebp-1Ch] BYREF

  v5 = this->ini;
  if ( !v5 )
    return -1;
  INIReader::getString(v5, &s, section, key);
  v6 = &s;
  if ( s._Myres >= 8 )
    v6 = (std::wstring *)s._Bx._Ptr;
  _wcscpy_s(buffer, bufferSize, v6->_Bx._Buf);
  v7 = s._Mysize;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  return v7;
}
bool ACINIReader::open(ACINIReader *this, std::wstring filename)
{
  INIReader *v3; // ecx
  INIReader *v4; // eax
  INIReader *v5; // eax
  bool v6; // bl

  v3 = this->ini;
  if ( v3 )
    ((void (*)(INIReader *, int))v3->~INIReader)(v3, 1);
  v4 = (INIReader *)operator new(68);
  if ( v4 )
    INIReader::INIReader(v4, &filename);
  else
    v5 = 0;
  this->ini = v5;
  v6 = v5->ready;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  return v6;
}
