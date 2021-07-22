#include "consoleset.h"
void ConsoleSet::ConsoleSet(ConsoleSet *this, Console *con)
{
  std::wstring *v3; // ecx

  v3 = &this->command;
  v3->_Myres = 7;
  v3->_Mysize = 0;
  v3->_Bx._Buf[0] = 0;
  this->console = con;
  this->__vftable = (ConsoleSet_vtbl *)&ConsoleSet::`vftable';
  std::wstring::assign(v3, L"set", 3u);
}
ConsoleSet *ConsoleSet::`vector deleting destructor'(ConsoleSet *this, unsigned int a2)
{
  this->__vftable = (ConsoleSet_vtbl *)&ConsoleSet::`vftable';
  if ( this->command._Myres >= 8 )
    operator delete(this->command._Bx._Ptr);
  this->command._Myres = 7;
  this->command._Mysize = 0;
  this->command._Bx._Buf[0] = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
char ConsoleSet::execute(ConsoleSet *this, std::wstring commandLine)
{
  ConsoleSet *v2; // ebx
  std::wstring *v3; // esi
  std::wstring *v4; // ebp
  Console *v5; // eax
  Console *v6; // edi
  int v7; // ebp
  const std::wstring **v8; // esi
  const std::wstring **i; // edi
  const std::wstring *v10; // ebx
  Console *v11; // eax
  Console *v12; // eax
  Console *v13; // ecx
  Console *v14; // edi
  const wchar_t **v15; // esi
  SVar **v16; // edi
  wchar_t *v17; // ebx
  const wchar_t *v18; // eax
  double v19; // st7
  int v20; // ecx
  Console *v21; // eax
  Console *v22; // eax
  Console *v23; // eax
  Console *v24; // eax
  Console *v25; // ecx
  std::wstring *v26; // esi
  std::wstring *v27; // esi
  float *v28; // eax
  float v29; // xmm0_4
  Console *v30; // eax
  Console *v31; // eax
  Console *v32; // eax
  Console *v33; // eax
  Console *v34; // eax
  std::wstring *v35; // edi
  std::wstring *v36; // esi
  std::wstring v38; // [esp-84h] [ebp-F4h] BYREF
  std::wstring v39; // [esp-6Ch] [ebp-DCh] BYREF
  std::wstring v40; // [esp-54h] [ebp-C4h] BYREF
  std::wstring v41; // [esp-3Ch] [ebp-ACh] BYREF
  std::wstring v42; // [esp-24h] [ebp-94h] BYREF
  std::wstring v43; // [esp-Ch] [ebp-7Ch] BYREF
  float v44; // [esp+20h] [ebp-50h] BYREF
  wchar_t *EndPtr; // [esp+24h] [ebp-4Ch] BYREF
  std::vector<std::wstring> result; // [esp+28h] [ebp-48h] BYREF
  std::wstring *v47; // [esp+34h] [ebp-3Ch]
  ConsoleSet *v48; // [esp+38h] [ebp-38h]
  std::wstring *v49; // [esp+3Ch] [ebp-34h]
  std::wstring *v50; // [esp+40h] [ebp-30h]
  std::wstring *v51; // [esp+44h] [ebp-2Ch]
  std::wstring splitter; // [esp+48h] [ebp-28h] BYREF
  int v53; // [esp+6Ch] [ebp-4h]

  v2 = this;
  v48 = this;
  v53 = 0;
  splitter._Myres = 7;
  splitter._Mysize = 0;
  splitter._Bx._Buf[0] = 0;
  std::wstring::assign(&splitter, L" ", 1u);
  LOBYTE(v53) = 1;
  ksSplitString(&result, &commandLine, &splitter);
  LOBYTE(v53) = 3;
  if ( splitter._Myres >= 8 )
    operator delete(splitter._Bx._Ptr);
  v3 = result._Mylast;
  v4 = result._Myfirst;
  splitter._Bx._Buf[0] = 0;
  splitter._Myres = 7;
  splitter._Mysize = 0;
  if ( (unsigned int)(result._Mylast - result._Myfirst) > 1 )
  {
    if ( !std::wstring::compare(result._Myfirst + 1, 0, result._Myfirst[1]._Mysize, L"help", 4u) )
    {
      EndPtr = (wchar_t *)&v43;
      std::wstring::wstring(&v43, L"\n");
      LOBYTE(v53) = 4;
      std::wstring::wstring(&v42, L"[ HELP FOR SET ]");
      v5 = Console::operator<<(v2->console, v42);
      LOBYTE(v53) = 3;
      Console::operator<<(v5, v43);
      v6 = v2->console;
      v7 = 0;
      v8 = (const std::wstring **)v6->vars._Myfirst;
      for ( i = (const std::wstring **)v6->vars._Mylast; v8 != i; ++v8 )
      {
        v10 = *v8;
        EndPtr = (wchar_t *)&v43;
        v43._Myres = 7;
        v43._Mysize = 0;
        v43._Bx._Buf[0] = 0;
        std::wstring::assign(&v43, L"     ", 5u);
        LOBYTE(v53) = 5;
        v44 = COERCE_FLOAT(&v42);
        v42._Myres = 7;
        v42._Mysize = 0;
        v42._Bx._Buf[0] = 0;
        std::wstring::assign(&v42, v10, 0, 0xFFFFFFFF);
        LOBYTE(v53) = 6;
        v41._Myres = 7;
        v41._Mysize = 0;
        v41._Bx._Buf[0] = 0;
        std::wstring::assign(&v41, L" -", 2u);
        v2 = v48;
        v11 = Console::operator<<(v48->console, v41);
        LOBYTE(v53) = 5;
        v12 = Console::operator<<(v11, v42);
        LOBYTE(v53) = 3;
        Console::operator<<(v12, v43);
        if ( v7 == 8 )
        {
          v43._Myres = 7;
          v43._Mysize = 0;
          v43._Bx._Buf[0] = 0;
          std::wstring::assign(&v43, L"\n", 1u);
          Console::operator<<(v2->console, v43);
          v7 = 0;
        }
        else
        {
          ++v7;
        }
      }
      v43._Myres = 7;
      v43._Mysize = 0;
      v43._Bx._Buf[0] = 0;
      std::wstring::assign(&v43, L"\n", 1u);
      v13 = v2->console;
      goto LABEL_43;
    }
    v3 = result._Mylast;
    v4 = result._Myfirst;
  }
  if ( (unsigned int)(v3 - v4) <= 2
    || (v14 = v2->console,
        v15 = (const wchar_t **)v14->vars._Myfirst,
        v16 = v14->vars._Mylast,
        v15 == (const wchar_t **)v16) )
  {
LABEL_41:
    v50 = &v43;
    v43._Myres = 7;
    v43._Mysize = 0;
    v43._Bx._Buf[0] = 0;
    std::wstring::assign(&v43, L"\n", 1u);
    LOBYTE(v53) = 17;
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    std::wstring::assign(&v42, L"[error: set var is unknown]", 0x1Bu);
    v25 = v2->console;
    goto LABEL_42;
  }
  while ( 1 )
  {
    v17 = (wchar_t *)*v15;
    if ( *((_DWORD *)*v15 + 5) < 8u )
      v18 = *v15;
    else
      v18 = *(const wchar_t **)v17;
    if ( std::wstring::compare(v4 + 1, 0, v4[1]._Mysize, v18, *((_DWORD *)v17 + 4)) )
      goto LABEL_21;
    if ( *((_DWORD *)v17 + 6) )
      break;
    if ( *((_DWORD *)v17 + 8) )
    {
      v26 = result._Myfirst + 2;
      if ( result._Myfirst[2]._Myres >= 8 )
        v26 = (std::wstring *)v26->_Bx._Ptr;
      *__errno() = 0;
      v44 = _wcstod(v26->_Bx._Buf, &EndPtr);
      if ( v26 == (std::wstring *)EndPtr )
        std::_Xinvalid_argument("invalid stof argument");
      if ( *__errno() == 34 )
        std::_Xout_of_range("stof argument out of range");
      (***((void (****)(_DWORD, wchar_t *, _DWORD))v17 + 8))(
        *((_DWORD *)v17 + 8),
        v17,
        *((float *)v17 + 9) * v44);
      goto LABEL_44;
    }
    if ( *((_BYTE *)v17 + 40) )
    {
      v19 = std::stof((const std::wstring *)result._Myfirst + 2, 0) * *((float *)v17 + 9);
      v20 = *((_DWORD *)v17 + 16);
      EndPtr = v17;
      v44 = v19;
      if ( !v20 )
        std::_Xbad_function_call();
      (*(void (**)(int, wchar_t **, float *))(*(_DWORD *)v20 + 8))(v20, &EndPtr, &v44);
      v47 = &v43;
      std::wstring::wstring(&v43, L"\n");
      LOBYTE(v53) = 12;
      EndPtr = (wchar_t *)&v42;
      std::wstring::wstring(&v42, L" ]");
      v44 = COERCE_FLOAT(&v41);
      LOBYTE(v53) = 13;
      v41._Myres = 7;
      v41._Mysize = 0;
      v41._Bx._Buf[0] = 0;
      std::wstring::assign(&v41, (const std::wstring *)result._Myfirst + 2, 0, 0xFFFFFFFF);
      LOBYTE(v53) = 14;
      v51 = &v40;
      std::wstring::wstring(&v40, L" = ");
      v49 = &v39;
      LOBYTE(v53) = 15;
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      std::wstring::assign(&v39, (const std::wstring *)result._Myfirst + 1, 0, 0xFFFFFFFF);
      LOBYTE(v53) = 16;
      std::wstring::wstring(&v38, L"[ ");
      v21 = Console::operator<<(v48->console, v38);
      LOBYTE(v53) = 15;
      v22 = Console::operator<<(v21, v39);
      LOBYTE(v53) = 14;
      v23 = Console::operator<<(v22, v40);
      LOBYTE(v53) = 13;
      v24 = Console::operator<<(v23, v41);
      LOBYTE(v53) = 12;
      v25 = v24;
      goto LABEL_42;
    }
LABEL_21:
    if ( ++v15 == (const wchar_t **)v16 )
    {
      v2 = v48;
      goto LABEL_41;
    }
    v4 = result._Myfirst;
  }
  v27 = result._Myfirst + 2;
  if ( result._Myfirst[2]._Myres >= 8 )
    v27 = (std::wstring *)v27->_Bx._Ptr;
  *__errno() = 0;
  v44 = _wcstod(v27->_Bx._Buf, &EndPtr);
  if ( v27 == (std::wstring *)EndPtr )
    std::_Xinvalid_argument("invalid stof argument");
  if ( *__errno() == 34 )
    std::_Xout_of_range("stof argument out of range");
  v28 = (float *)*((_DWORD *)v17 + 6);
  v29 = *((float *)v17 + 9) * v44;
  v50 = &v43;
  v42._Myres = 1;
  v42._Mysize = (unsigned int)L"\n";
  *v28 = v29;
  v43._Myres = 7;
  v43._Mysize = 0;
  v43._Bx._Buf[0] = 0;
  std::wstring::assign(&v43, (const wchar_t *)v42._Mysize, v42._Myres);
  LOBYTE(v53) = 7;
  v49 = &v42;
  v42._Myres = 7;
  v42._Mysize = 0;
  v42._Bx._Buf[0] = 0;
  std::wstring::assign(&v42, L" ]", 2u);
  v51 = &v41;
  LOBYTE(v53) = 8;
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  std::wstring::assign(&v41, (const std::wstring *)result._Myfirst + 2, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 9;
  v47 = &v40;
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  std::wstring::assign(&v40, L" = ", 3u);
  EndPtr = (wchar_t *)&v39;
  LOBYTE(v53) = 10;
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  std::wstring::assign(&v39, (const std::wstring *)result._Myfirst + 1, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 11;
  v38._Myres = 7;
  v38._Mysize = 0;
  v38._Bx._Buf[0] = 0;
  std::wstring::assign(&v38, L"[ ", 2u);
  v30 = Console::operator<<(v48->console, v38);
  LOBYTE(v53) = 10;
  v31 = Console::operator<<(v30, v39);
  LOBYTE(v53) = 9;
  v32 = Console::operator<<(v31, v40);
  LOBYTE(v53) = 8;
  v33 = Console::operator<<(v32, v41);
  LOBYTE(v53) = 7;
  v25 = v33;
LABEL_42:
  v34 = Console::operator<<(v25, v42);
  LOBYTE(v53) = 3;
  v13 = v34;
LABEL_43:
  Console::operator<<(v13, v43);
LABEL_44:
  LOBYTE(v53) = 0;
  if ( result._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&result);
    v35 = result._Mylast;
    v36 = result._Myfirst;
    if ( result._Myfirst != result._Mylast )
    {
      do
      {
        if ( v36->_Myres >= 8 )
          operator delete(v36->_Bx._Ptr);
        v36->_Myres = 7;
        v36->_Mysize = 0;
        v36->_Bx._Buf[0] = 0;
        ++v36;
      }
      while ( v36 != v35 );
      v36 = result._Myfirst;
    }
    operator delete(v36);
    result._Myfirst = 0;
    result._Mylast = 0;
    result._Myend = 0;
  }
  if ( commandLine._Myres >= 8 )
    operator delete(commandLine._Bx._Ptr);
  return 1;
}
std::wstring *ConsoleSet::getHelp(ConsoleSet *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, L"usage: 'set [var] [value]'", 0x1Au);
  return result;
}
