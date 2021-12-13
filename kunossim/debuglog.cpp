#include "debuglog.h"
void DebugLog::DebugLog(DebugLog *this)
{
  std::locale::_Locimp *v2; // eax
  std::codecvt_utf8<wchar_t,1114111,0> *v3; // esi
  std::locale::_Locimp *v4; // esi
  std::_Facet_base *v5; // eax
  char v6; // bl
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // esi
  FILE *v15; // eax
  std::codecvt_utf8<wchar_t,1114111,0> *v16; // [esp-4h] [ebp-D4h]
  char v17; // [esp+13h] [ebp-BDh]
  std::locale _Loc; // [esp+14h] [ebp-BCh] BYREF
  DebugLog *v19; // [esp+18h] [ebp-B8h]
  std::wstring section; // [esp+1Ch] [ebp-B4h] BYREF
  std::wstring result; // [esp+34h] [ebp-9Ch] BYREF
  std::wstring filename2; // [esp+4Ch] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+64h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+7Ch] [ebp-54h] BYREF
  int v25; // [esp+CCh] [ebp-4h]

  v19 = this;
  this->__vftable = (DebugLog_vtbl *)&DebugLog::`vftable';
  v2 = (std::locale::_Locimp *)operator new(52);
  v3 = (std::codecvt_utf8<wchar_t,1114111,0> *)v2;
  _Loc._Ptr = v2;
  v25 = 0;
  if ( v2 )
  {
    std::codecvt<wchar_t,char,int>::codecvt<wchar_t,char,int>(v2, 0);
    v3->__vftable = (std::codecvt_utf8<wchar_t,1114111,0>_vtbl *)&std::codecvt_utf8<wchar_t,1114111,0>::`vftable';
  }
  else
  {
    v3 = 0;
  }
  v25 = -1;
  this->codec = v3;
  v4 = std::locale::_Init(1);
  _Loc._Ptr = v4;
  v16 = this->codec;
  v25 = 1;
  std::locale::locale(&this->loc, &_Loc, v16);
  LOBYTE(v25) = 3;
  if ( v4 )
  {
    v5 = v4->_Decref(v4);
    if ( v5 )
      ((void (*)(std::_Facet_base *, int))v5->~_Facet_base)(v5, 1);
  }
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v25) = 4;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v25) = 6;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LOG", 3u);
  LOBYTE(v25) = 7;
  v6 = 1;
  _Loc._Ptr = (std::locale::_Locimp *)1;
  if ( !INIReader::hasSection(&ini, &section) )
    goto LABEL_11;
  filename2._Myres = 7;
  filename2._Mysize = 0;
  filename2._Bx._Buf[0] = 0;
  std::wstring::assign(&filename2, L"SUPPRESS", 8u);
  v25 = 8;
  _Loc._Ptr = (std::locale::_Locimp *)3;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"LOG", 3u);
  v25 = 9;
  v6 = 7;
  _Loc._Ptr = (std::locale::_Locimp *)7;
  v17 = 0;
  if ( !INIReader::getInt(&ini, &result, &filename2) )
LABEL_11:
    v17 = 1;
  if ( (v6 & 4) != 0 )
  {
    v6 &= 0xFBu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  if ( (v6 & 2) != 0 )
  {
    v6 &= 0xFDu;
    if ( filename2._Myres >= 8 )
      operator delete(filename2._Bx._Ptr);
    filename2._Myres = 7;
    filename2._Mysize = 0;
    filename2._Bx._Buf[0] = 0;
  }
  v25 = 6;
  if ( (v6 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v17 )
  {
    v7 = Path::getDocumentPath(&result);
    LOBYTE(v25) = 10;
    v8 = std::operator+<wchar_t>(&section, v7, L"/Assetto Corsa");
    LOBYTE(v25) = 11;
    Path::createFolder(v8);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v9 = Path::getDocumentPath(&result);
    LOBYTE(v25) = 12;
    v10 = std::operator+<wchar_t>(&section, v9, L"/Assetto Corsa/logs");
    LOBYTE(v25) = 13;
    Path::createFolder(v10);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v11 = Path::getDocumentPath(&result);
    LOBYTE(v25) = 14;
    v12 = std::operator+<wchar_t>(&section, v11, L"/Assetto Corsa/out");
    LOBYTE(v25) = 15;
    Path::createFolder(v12);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v13 = Path::getDocumentPath(&section);
    LOBYTE(v25) = 16;
    std::operator+<wchar_t>(&filename2, v13, L"/Assetto Corsa/logs/log.txt");
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v14 = &filename2;
    if ( filename2._Myres >= 8 )
      v14 = (std::wstring *)filename2._Bx._Ptr;
    v15 = ___iob_func();
    __wfreopen(v14->_Bx._Buf, L"w", v15 + 1);
    if ( filename2._Myres >= 8 )
      operator delete(filename2._Bx._Ptr);
  }
  LOBYTE(v25) = 3;
  INIReader::~INIReader(&ini);
}
void DebugLog::~DebugLog(DebugLog *this)
{
  std::locale::_Locimp *v2; // ecx
  std::_Facet_base *v3; // eax

  this->__vftable = (DebugLog_vtbl *)&DebugLog::`vftable';
  _fflush(0);
  v2 = this->loc._Ptr;
  if ( v2 )
  {
    v3 = v2->_Decref(v2);
    if ( v3 )
      ((void (*)(std::_Facet_base *, int))v3->~_Facet_base)(v3, 1);
  }
}
DebugLog *DebugLog::`scalar deleting destructor'(DebugLog *this, unsigned int a2)
{
  std::locale::_Locimp *v3; // ecx
  std::_Facet_base *v4; // eax

  this->__vftable = (DebugLog_vtbl *)&DebugLog::`vftable';
  _fflush(0);
  v3 = this->loc._Ptr;
  if ( v3 )
  {
    v4 = v3->_Decref(v3);
    if ( v4 )
      ((void (*)(std::_Facet_base *, int))v4->~_Facet_base)(v4, 1);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
