#include "kssecurity.h"
void ksSecurity::ksSecurity(ksSecurity *this)
{
  this->__vftable = (ksSecurity_vtbl *)&ksSecurity::`vftable';
  this->licenses._Myfirst = 0;
  this->licenses._Mylast = 0;
  this->licenses._Myend = 0;
}
void ksSecurity::~ksSecurity(ksSecurity *this)
{
  std::wstring *v2; // eax

  this->__vftable = (ksSecurity_vtbl *)&ksSecurity::`vftable';
  v2 = this->licenses._Myfirst;
  if ( v2 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v2, this->licenses._Mylast);
    operator delete(this->licenses._Myfirst);
    this->licenses._Myfirst = 0;
    this->licenses._Mylast = 0;
    this->licenses._Myend = 0;
  }
}
ksSecurity *ksSecurity::`vector deleting destructor'(ksSecurity *this, unsigned int a2)
{
  std::wstring *v3; // eax

  this->__vftable = (ksSecurity_vtbl *)&ksSecurity::`vftable';
  v3 = this->licenses._Myfirst;
  if ( v3 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v3, this->licenses._Mylast);
    operator delete(this->licenses._Myfirst);
    this->licenses._Myfirst = 0;
    this->licenses._Mylast = 0;
    this->licenses._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *ksSecurity::getMacAddress(ksSecurity *this, std::wstring *result, bool printDebugInfos)
{
  _IP_ADAPTER_INFO *v3; // esi
  unsigned int v4; // eax
  std::wstring *v5; // edi
  std::wstring *v6; // esi
  std::wstring *v7; // ebp
  std::wstring *v8; // edi
  unsigned int v9; // ecx
  unsigned int SizePointer; // [esp+18h] [ebp-5234h] BYREF
  std::vector<std::wstring> v12; // [esp+1Ch] [ebp-5230h] BYREF
  int v13; // [esp+28h] [ebp-5224h]
  std::wstring _Left; // [esp+2Ch] [ebp-5220h] BYREF
  std::wstring _Val; // [esp+44h] [ebp-5208h] BYREF
  std::wstring resulta; // [esp+5Ch] [ebp-51F0h] BYREF
  _IP_ADAPTER_INFO AdapterInfo; // [esp+74h] [ebp-51D8h] BYREF
  wchar_t Buffer[100]; // [esp+5174h] [ebp-D8h] BYREF
  int v19; // [esp+5248h] [ebp-4h]

  v13 = 0;
  v12._Myfirst = 0;
  v12._Mylast = 0;
  v12._Myend = 0;
  v19 = 0;
  SizePointer = 20736;
  if ( GetAdaptersInfo(&AdapterInfo, &SizePointer) )
  {
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
  }
  else
  {
    v3 = &AdapterInfo;
    do
    {
      if ( v3->Type == 6 )
      {
        _swprintf_s(
          Buffer,
          0x64u,
          L"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",
          v3->Address[0],
          v3->Address[1],
          v3->Address[2],
          v3->Address[3],
          v3->Address[4],
          v3->Address[5]);
        v4 = 0;
        _Val._Myres = 7;
        _Val._Mysize = 0;
        _Val._Bx._Buf[0] = 0;
        if ( Buffer[0] )
          v4 = wcslen(Buffer);
        std::wstring::assign(&_Val, Buffer, v4);
        LOBYTE(v19) = 1;
        std::vector<std::wstring>::push_back(&v12, &_Val);
        LOBYTE(v19) = 0;
        if ( _Val._Myres >= 8 )
          operator delete(_Val._Bx._Ptr);
      }
      v3 = v3->Next;
    }
    while ( v3 );
    _Left._Myres = 7;
    _Left._Mysize = 0;
    _Left._Bx._Buf[0] = 0;
    v5 = v12._Myfirst;
    v6 = v12._Myfirst;
    v7 = v12._Mylast;
    LOBYTE(v19) = 2;
    if ( v12._Myfirst != v12._Mylast )
    {
      do
      {
        _Val._Myres = 7;
        _Val._Mysize = 0;
        _Val._Bx._Buf[0] = 0;
        std::wstring::assign(&_Val, v6, 0, 0xFFFFFFFF);
        LOBYTE(v19) = 3;
        v8 = std::operator+<wchar_t>(&resulta, &_Left, &_Val);
        if ( &_Left != v8 )
        {
          if ( _Left._Myres >= 8 )
            operator delete(_Left._Bx._Ptr);
          _Left._Myres = 7;
          _Left._Mysize = 0;
          _Left._Bx._Buf[0] = 0;
          if ( v8->_Myres >= 8 )
          {
            _Left._Bx._Ptr = v8->_Bx._Ptr;
            v8->_Bx._Ptr = 0;
          }
          else if ( v8->_Mysize != -1 )
          {
            _memmove(&_Left, v8, 2 * (v8->_Mysize + 1));
          }
          _Left._Mysize = v8->_Mysize;
          _Left._Myres = v8->_Myres;
          v8->_Myres = 7;
          v8->_Mysize = 0;
          v8->_Bx._Buf[0] = 0;
        }
        if ( resulta._Myres >= 8 )
          operator delete(resulta._Bx._Ptr);
        LOBYTE(v19) = 2;
        if ( _Val._Myres >= 8 )
          operator delete(_Val._Bx._Ptr);
        ++v6;
      }
      while ( v6 != v7 );
      if ( &_Left != &v7[-1] )
        std::wstring::assign(&_Left, v7 - 1, 0, 0xFFFFFFFF);
      v5 = v12._Myfirst;
    }
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    v9 = _Left._Myres;
    if ( _Left._Myres >= 8 )
    {
      result->_Bx._Ptr = _Left._Bx._Ptr;
      _Left._Bx._Ptr = 0;
    }
    else if ( _Left._Mysize != -1 )
    {
      _memmove(result, &_Left, 2 * (_Left._Mysize + 1));
      v9 = _Left._Myres;
    }
    result->_Mysize = _Left._Mysize;
    result->_Myres = v9;
    _Left._Myres = 7;
    _Left._Mysize = 0;
    _Left._Bx._Buf[0] = 0;
    if ( v5 )
    {
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v5, v7);
      operator delete(v5);
    }
  }
  return result;
}
std::wstring *ksSecurity::getRequestCode(ksSecurity *this, std::wstring *result, bool printDebugInfos)
{
  std::wstring v5; // [esp-18h] [ebp-54h] BYREF
  int v6; // [esp+10h] [ebp-2Ch]
  std::wstring c; // [esp+14h] [ebp-28h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  v6 = 0;
  ksSecurity::getMacAddress(this, &c, printDebugInfos);
  v8 = 0;
  if ( c._Mysize )
  {
    v5._Mysize = 0;
    v5._Myres = 7;
    v5._Bx._Buf[0] = 0;
    std::wstring::assign(&v5, &c, 0, 0xFFFFFFFF);
    ksSecurity::keyFromString(this, result, v5);
  }
  else
  {
    v5._Myres = 6;
    result->_Myres = 7;
    result->_Mysize = 0;
    v5._Mysize = (unsigned int)L"NOCODE";
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, (const wchar_t *)v5._Mysize, v5._Myres);
  }
  if ( c._Myres >= 8 )
    operator delete(c._Bx._Ptr);
  return result;
}
std::wstring *ksSecurity::keyFromString(ksSecurity *this, std::wstring *result, std::wstring is)
{
  unsigned int v3; // ebp
  unsigned __int8 v4; // dl
  unsigned int v5; // ecx
  std::wstring *v6; // eax
  char v7; // al
  int v8; // edx
  unsigned int v9; // ecx
  std::wstring *v10; // eax
  int v11; // edx
  std::wstring *v12; // eax
  int v13; // eax
  int v14; // ecx
  unsigned int v15; // ebx
  std::wstring *v16; // eax
  int v17; // edx
  std::wstring *v18; // eax
  int v19; // edx
  int v20; // edx
  std::wstring *v21; // eax
  int v22; // eax
  unsigned int v23; // ecx
  char v24; // dl
  std::wstring *v25; // eax
  char v26; // al
  int v27; // ebx
  unsigned int v28; // edx
  unsigned int v29; // ebp
  std::wstring *v30; // eax
  int v31; // ecx
  std::wstring *v32; // eax
  int v33; // ecx
  int v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // ecx
  char v37; // bp
  std::wstring *v38; // eax
  char v39; // al
  unsigned int v40; // ebp
  std::wstring *v41; // eax
  int v42; // ecx
  unsigned int v43; // ebp
  int v44; // edx
  std::wstring *v45; // eax
  int v46; // edx
  std::wstring *v47; // eax
  int v48; // eax
  unsigned int v49; // ecx
  unsigned __int8 v51; // [esp+14h] [ebp-23Ch]
  unsigned __int8 v52; // [esp+18h] [ebp-238h]
  unsigned __int8 v53; // [esp+1Ch] [ebp-234h]
  int v54; // [esp+20h] [ebp-230h]
  char v55; // [esp+24h] [ebp-22Ch]
  unsigned __int8 v56; // [esp+28h] [ebp-228h]
  unsigned __int8 v57; // [esp+30h] [ebp-220h]
  unsigned int v58; // [esp+34h] [ebp-21Ch]
  std::wstring *v59; // [esp+38h] [ebp-218h]
  wchar_t buffer[256]; // [esp+40h] [ebp-210h] BYREF
  int v61; // [esp+24Ch] [ebp-4h]

  v59 = result;
  v3 = is._Mysize;
  v4 = 0;
  v5 = 0;
  v61 = 0;
  v57 = 0;
  if ( is._Mysize )
  {
    do
    {
      v6 = &is;
      if ( is._Myres >= 8 )
        v6 = (std::wstring *)is._Bx._Ptr;
      v7 = v6->_Bx._Alias[2 * v5++];
      v4 += v7;
    }
    while ( v5 < is._Mysize );
    v57 = v4;
  }
  v8 = 0;
  v9 = 0;
  v56 = 0;
  if ( is._Mysize != 1 )
  {
    do
    {
      v10 = &is;
      if ( is._Myres >= 8 )
        v10 = (std::wstring *)is._Bx._Ptr;
      v11 = v10->_Bx._Alias[2 * v9] * v8;
      v12 = &is;
      if ( is._Myres >= 8 )
        v12 = (std::wstring *)is._Bx._Ptr;
      v13 = v12->_Bx._Alias[2 * v9 + 2];
      v9 += 2;
      v8 = v11 - v13;
    }
    while ( v9 < is._Mysize - 1 );
    v56 = v8;
  }
  v14 = 0;
  v53 = 0;
  v15 = 1;
  if ( is._Mysize - 3 > 1 )
  {
    do
    {
      v16 = &is;
      if ( is._Myres >= 8 )
        v16 = (std::wstring *)is._Bx._Ptr;
      v17 = v16->_Bx._Alias[2 * v15];
      v18 = &is;
      v19 = v14 * v17;
      if ( is._Myres >= 8 )
        v18 = (std::wstring *)is._Bx._Ptr;
      v20 = v19 / (v18->_Bx._Alias[2 * v15 + 2] + 27);
      v21 = &is;
      if ( is._Myres >= 8 )
        v21 = (std::wstring *)is._Bx._Ptr;
      v22 = v21->_Bx._Alias[2 * v15 - 2];
      v15 += 3;
      v53 = -27 - v22 + v20;
      v14 = -27 - v22 + v20;
    }
    while ( v15 < is._Mysize - 3 );
    v3 = is._Mysize;
  }
  v23 = 1;
  v24 = -125;
  v51 = -125;
  if ( v3 > 1 )
  {
    do
    {
      v25 = &is;
      if ( is._Myres >= 8 )
        v25 = (std::wstring *)is._Bx._Ptr;
      v26 = v25->_Bx._Alias[2 * v23++];
      v24 -= v26;
    }
    while ( v23 < v3 );
    v51 = v24;
  }
  v27 = 66;
  v55 = 66;
  v28 = 1;
  if ( v3 - 4 > 1 )
  {
    v29 = v3 - 4;
    do
    {
      v30 = &is;
      if ( is._Myres >= 8 )
        v30 = (std::wstring *)is._Bx._Ptr;
      v31 = v30->_Bx._Alias[2 * v28];
      v32 = &is;
      v33 = v27 * (v31 + 15);
      if ( is._Myres >= 8 )
        v32 = (std::wstring *)is._Bx._Ptr;
      v34 = v32->_Bx._Alias[2 * v28 - 2];
      v28 += 4;
      v27 = v33 * (v34 + 15) + 22;
    }
    while ( v28 < v29 );
    v3 = is._Mysize;
    v55 = v27;
  }
  v35 = v3 - 2;
  v52 = 101;
  v36 = 0;
  v58 = v3 - 2;
  if ( v3 != 2 )
  {
    v37 = 101;
    do
    {
      v38 = &is;
      if ( is._Myres >= 8 )
        v38 = (std::wstring *)is._Bx._Ptr;
      v39 = v38->_Bx._Alias[2 * v36];
      v36 += 2;
      v37 -= v39;
    }
    while ( v36 < v35 );
    v52 = v37;
  }
  v40 = 0;
  v54 = 171;
  if ( v35 )
  {
    do
    {
      v41 = &is;
      if ( is._Myres >= 8 )
        v41 = (std::wstring *)is._Bx._Ptr;
      v42 = v41->_Bx._Alias[2 * v40];
      v40 += 2;
      v54 %= v42;
    }
    while ( v40 < v58 );
    LOBYTE(v27) = v55;
  }
  v43 = 0;
  v44 = 171;
  if ( is._Mysize != 1 )
  {
    do
    {
      v45 = &is;
      if ( is._Myres >= 8 )
        v45 = (std::wstring *)is._Bx._Ptr;
      v46 = v44 / v45->_Bx._Alias[2 * v43];
      v47 = &is;
      if ( is._Myres >= 8 )
        v47 = (std::wstring *)is._Bx._Ptr;
      v48 = v47->_Bx._Alias[2 * v43++ + 2];
      v44 = v48 + v46;
    }
    while ( v43 < is._Mysize - 1 );
    LOBYTE(v27) = v55;
  }
  _swprintf_s(
    buffer,
    0x100u,
    L"%d-%d-%d-%d-%d-%d-%d-%d",
    v57,
    v56,
    v53,
    v51,
    (unsigned __int8)v27,
    v52,
    (unsigned __int8)v54,
    (unsigned __int8)v44);
  v59->_Myres = 7;
  v59->_Mysize = 0;
  v59->_Bx._Buf[0] = 0;
  if ( buffer[0] )
    v49 = wcslen(buffer);
  else
    v49 = 0;
  std::wstring::assign(v59, buffer, v49);
  if ( is._Myres >= 8 )
    operator delete(is._Bx._Ptr);
  return v59;
}
char ksSecurity::validate(ksSecurity *this, std::wstring sfx, int version)
{
  if ( sfx._Myres >= 8 )
    operator delete(sfx._Bx._Ptr);
  return 1;
}
