#include "acerrorhandler.h"
void ACErrorHandler::ACErrorHandler(ACErrorHandler *this, Console *aconsole)
{
  this->console = aconsole;
  this->__vftable = (ACErrorHandler_vtbl *)&ACErrorHandler::`vftable';
  this->errors._Myfirst = 0;
  this->errors._Mylast = 0;
  this->errors._Myend = 0;
}
void ACErrorHandler::~ACErrorHandler(ACErrorHandler *this)
{
  std::wstring *v1; // eax
  std::vector<std::wstring> *v2; // edi
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  int v5; // ecx
  unsigned int v6; // ebx
  int v7; // esi
  std::wostream *v8; // eax
  _BYTE *v9; // esi
  bool v10; // zf
  std::wstring *v11; // ebx
  wchar_t **i; // esi
  std::wofstream out; // [esp+14h] [ebp-E8h] BYREF
  std::wstring v14; // [esp+BCh] [ebp-40h] BYREF
  std::wstring result; // [esp+D4h] [ebp-28h] BYREF
  int v16; // [esp+F8h] [ebp-4h]

  this->__vftable = (ACErrorHandler_vtbl *)&ACErrorHandler::`vftable';
  v1 = this->errors._Myfirst;
  v2 = &this->errors;
  v16 = 0;
  if ( v1 != this->errors._Mylast )
  {
    v3 = Path::getDocumentPath(&result);
    LOBYTE(v16) = 1;
    v4 = std::operator+<wchar_t>(&v14, v3, L"/Assetto Corsa/logs/errors.txt");
    LOBYTE(v16) = 2;
    std::wofstream::wofstream(&out, v4, 2, 64, 1);
    if ( v14._Myres >= 8 )
      operator delete(v14._Bx._Ptr);
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    LOBYTE(v16) = 5;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v5 = (char *)v2->_Mylast - (char *)v2->_Myfirst;
    v6 = 0;
    result._Bx._Buf[0] = 0;
    result._Myres = 7;
    result._Mysize = 0;
    if ( v5 / 24 )
    {
      v7 = 0;
      do
      {
        v8 = std::operator<<<wchar_t>(&out, &v2->_Myfirst[v7]);
        std::wostream::operator<<(v8);
        ++v6;
        ++v7;
      }
      while ( v6 < v2->_Mylast - v2->_Myfirst );
    }
    v9 = &out.gap0[4];
    if ( *(_DWORD *)&out._Filebuffer[4] )
    {
      if ( !std::wfilebuf::_Endwrite((std::wfilebuf *)&out.gap0[4]) )
        v9 = 0;
      if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
        v9 = 0;
    }
    else
    {
      v9 = 0;
    }
    out._Filebuffer[0] = 0;
    out.gap0[74] = 0;
    std::wstreambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
    if ( !v9 )
      std::wios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
    std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&out.gap58[8]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
  }
  v10 = v2->_Myfirst == 0;
  v16 = -1;
  if ( !v10 )
  {
    std::_Container_base0::_Orphan_all(v2);
    v11 = v2->_Mylast;
    for ( i = (wchar_t **)v2->_Myfirst; i != (wchar_t **)v11; i += 6 )
    {
      if ( (unsigned int)i[5] >= 8 )
        operator delete(*i);
      i[5] = (wchar_t *)7;
      i[4] = 0;
      *(_WORD *)i = 0;
    }
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
}
ACErrorHandler *ACErrorHandler::`scalar deleting destructor'(ACErrorHandler *this, unsigned int a2)
{
  ACErrorHandler::~ACErrorHandler(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACErrorHandler::writeLine(ACErrorHandler *this, std::wstring s)
{
  Console *v3; // eax
  std::wstring *v4; // eax
  std::wstring v5; // [esp-30h] [ebp-4Ch] BYREF
  std::wstring v6; // [esp-18h] [ebp-34h] BYREF
  std::wstring *v7; // [esp+8h] [ebp-14h]
  int v8; // [esp+18h] [ebp-4h]

  v8 = 0;
  v7 = &v6;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"\n", 1u);
  LOBYTE(v8) = 1;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, &s, 0, 0xFFFFFFFF);
  v3 = Console::operator<<(this->console, v5);
  LOBYTE(v8) = 0;
  Console::operator<<(v3, v6);
  v4 = &s;
  if ( s._Myres >= 8 )
    v4 = (std::wstring *)s._Bx._Ptr;
  _printf("ERROR: %S\n", v4->_Bx._Buf);
  std::vector<std::wstring>::push_back(&this->errors, &s);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
}
void ACErrorHandler::writeWarning(ACErrorHandler *this, std::wstring s)
{
  Console *v3; // eax
  Console *v4; // eax
  std::wstring *v5; // eax
  std::wstring v6; // [esp-30h] [ebp-68h] BYREF
  std::wstring v7; // [esp-18h] [ebp-50h] BYREF
  std::wstring v8; // [esp+0h] [ebp-38h] BYREF
  std::wstring *v9; // [esp+20h] [ebp-18h]
  std::wstring *v10; // [esp+24h] [ebp-14h]
  int v11; // [esp+34h] [ebp-4h]

  v11 = 0;
  v10 = &v8;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"\n", 1u);
  LOBYTE(v11) = 1;
  v9 = &v7;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, &s, 0, 0xFFFFFFFF);
  LOBYTE(v11) = 2;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"[WARNING] ", 0xAu);
  v3 = Console::operator<<(this->console, v6);
  LOBYTE(v11) = 1;
  v4 = Console::operator<<(v3, v7);
  LOBYTE(v11) = 0;
  Console::operator<<(v4, v8);
  v5 = &s;
  if ( s._Myres >= 8 )
    v5 = (std::wstring *)s._Bx._Ptr;
  _printf("WARNING: %S\n", v5->_Bx._Buf);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
}
