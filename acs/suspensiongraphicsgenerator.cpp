#include "suspensiongraphicsgenerator.h
void SuspensionGraphicsGenerator::SuspensionGraphicsGenerator(SuspensionGraphicsGenerator *this, CarAvatar *acar)
{
  this->car = acar;
  this->__vftable = (SuspensionGraphicsGenerator_vtbl *)&SuspensionGraphicsGenerator::`vftable';
  this->susGraphics._Myfirst = 0;
  this->susGraphics._Mylast = 0;
  this->susGraphics._Myend = 0;
}
void SuspensionGraphicsGenerator::~SuspensionGraphicsGenerator(SuspensionGraphicsGenerator *this)
{
  std::vector<std::shared_ptr<SuspensionGraphics>> *v1; // esi

  this->__vftable = (SuspensionGraphicsGenerator_vtbl *)&SuspensionGraphicsGenerator::`vftable';
  v1 = &this->susGraphics;
  if ( this->susGraphics._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->susGraphics);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::shared_ptr<Material>>>>(
      (std::shared_ptr<Material> *)v1->_Myfirst,
      (std::shared_ptr<Material> *)v1->_Mylast);
    operator delete(v1->_Myfirst);
    v1->_Myfirst = 0;
    v1->_Mylast = 0;
    v1->_Myend = 0;
  }
}
SuspensionGraphicsGenerator *SuspensionGraphicsGenerator::`vector deleting destructor'(SuspensionGraphicsGenerator *this, unsigned int a2)
{
  this->__vftable = (SuspensionGraphicsGenerator_vtbl *)&SuspensionGraphicsGenerator::`vftable';
  if ( this->susGraphics._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->susGraphics);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::shared_ptr<Material>>>>(
      (std::shared_ptr<Material> *)this->susGraphics._Myfirst,
      (std::shared_ptr<Material> *)this->susGraphics._Mylast);
    operator delete(this->susGraphics._Myfirst);
    this->susGraphics._Myfirst = 0;
    this->susGraphics._Mylast = 0;
    this->susGraphics._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionGraphicsGenerator::generateConnections(SuspensionGraphicsGenerator *this)
{
  int v2; // edi
  CarAvatar *v3; // eax
  std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  unsigned int v6; // esi
  std::wostream *v7; // eax
  const std::wstring *v8; // eax
  char v9; // al
  const std::wstring *v10; // eax
  const std::wstring *v11; // eax
  const std::wstring *v12; // eax
  std::wstring *v13; // eax
  CarAvatar *v14; // ecx
  const std::wstring *v15; // eax
  const std::wstring *v16; // eax
  ICollisionObject *v17; // eax
  ICollisionObject *v18; // eax
  ICollisionObject *v19; // edi
  CarAvatar *v20; // esi
  Console *v21; // esi
  const std::wstring *v22; // eax
  Console *v23; // eax
  Console *v24; // eax
  const std::wstring *v25; // eax
  Console *v26; // eax
  Console *v27; // eax
  const std::wstring *v28; // eax
  Console *v29; // eax
  Console *v30; // eax
  int v31; // eax
  std::wstring v32; // [esp-3Eh] [ebp-24Ch] BYREF
  std::wstring v33; // [esp-26h] [ebp-234h] BYREF
  std::wstring v34; // [esp-Eh] [ebp-21Ch] BYREF
  int v35; // [esp+1Eh] [ebp-1F0h]
  ICollisionObject *_Val; // [esp+22h] [ebp-1ECh] BYREF
  std::wstring *v37; // [esp+26h] [ebp-1E8h]
  __int64 v38; // [esp+2Ah] [ebp-1E4h]
  SuspensionGraphicsDesc desc; // [esp+32h] [ebp-1DCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v40; // [esp+56h] [ebp-1B8h] BYREF
  vec3f v41; // [esp+106h] [ebp-108h] BYREF
  vec3f v42; // [esp+112h] [ebp-FCh] BYREF
  std::wstring key; // [esp+11Eh] [ebp-F0h] BYREF
  std::wstring v44; // [esp+136h] [ebp-D8h] BYREF
  std::wstring v45; // [esp+14Eh] [ebp-C0h] BYREF
  std::wstring _Left; // [esp+166h] [ebp-A8h] BYREF
  std::wstring result; // [esp+17Eh] [ebp-90h] BYREF
  INIReader r; // [esp+196h] [ebp-78h] BYREF
  std::wstring filename; // [esp+1E2h] [ebp-2Ch] BYREF
  int v50; // [esp+20Ah] [ebp-4h]

  v2 = 0;
  v37 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v3 = this->car;
  v50 = 0;
  v4 = std::operator+<wchar_t>(&result, &_Left, &v3->unixName);
  LOBYTE(v50) = 1;
  std::operator+<wchar_t>(&filename, v4, L"/data/suspension_graphics.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v50) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v5 = this->car;
  _Left._Bx._Buf[0] = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  CarAvatar::openINI(v5, &r, &filename);
  LOBYTE(v50) = 5;
  if ( r.ready )
  {
    v6 = 0;
    BYTE2(v35) = 1;
    LODWORD(v38) = 0;
    do
    {
      *(_DWORD *)v40.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v40.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v40.gap68);
      LOBYTE(v50) = 6;
      v2 |= 1u;
      v37 = (std::wstring *)v2;
      std::wiostream::basic_iostream<wchar_t>(&v40, &v40.gap10[8], 0);
      v50 = 7;
      *(_DWORD *)&v40.gap0[*(_DWORD *)(*(_DWORD *)v40.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&desc.pivotOnDst.z + *(_DWORD *)(*(_DWORD *)v40.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v40.gap0
                                                                                                 + 4)
                                                                                     - 104;
      std::wstreambuf::wstreambuf(&v40.gap10[8]);
      *(_DWORD *)&v40.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v40.gap10[64] = 0;
      *(_DWORD *)&v40.gap10[68] = 0;
      v34._Myres = v6;
      LOBYTE(v50) = 9;
      v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v40.gap10, "CONNECTION_");
      std::wostream::operator<<(v7, v34._Myres);
      v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
      LOBYTE(v50) = 10;
      v9 = INIReader::hasSection(&r, v8);
      HIBYTE(v35) = v9;
      LOBYTE(v50) = 9;
      if ( v44._Myres >= 8 )
      {
        operator delete(v44._Bx._Ptr);
        v9 = HIBYTE(v35);
      }
      if ( v9 )
      {
        desc.pivotOnDst.y = 0.0;
        desc.pivotOnDst.z = 0.0;
        desc.dstNode = 0;
        *(_OWORD *)&desc.pivotOnSrc.x = 0i64;
        desc.objectNode = 0;
        desc.srcNode = 0;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"DST_OBJECT", 0xAu);
        LOBYTE(v50) = 11;
        v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v45);
        LOBYTE(v50) = 12;
        INIReader::getString(&r, &v34, v10, &key);
        desc.dstNode = SuspensionGraphicsGenerator::getNodeFromName(this, v34);
        if ( v45._Myres >= 8 )
          operator delete(v45._Bx._Ptr);
        v45._Myres = 7;
        v45._Mysize = 0;
        v45._Bx._Buf[0] = 0;
        LOBYTE(v50) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"SRC_OBJECT", 0xAu);
        LOBYTE(v50) = 13;
        v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v45);
        LOBYTE(v50) = 14;
        INIReader::getString(&r, &v34, v11, &key);
        desc.srcNode = SuspensionGraphicsGenerator::getNodeFromName(this, v34);
        if ( v45._Myres >= 8 )
          operator delete(v45._Bx._Ptr);
        v45._Myres = 7;
        v45._Mysize = 0;
        v45._Bx._Buf[0] = 0;
        LOBYTE(v50) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"TARGET_OBJECT", 0xDu);
        LOBYTE(v50) = 15;
        v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
        LOBYTE(v50) = 16;
        v13 = INIReader::getString(&r, &v45, v12, &key);
        v14 = this->car;
        LOBYTE(v50) = 17;
        desc.objectNode = v14->bodyTransform->findChildByName(v14->bodyTransform, v13, 1);
        if ( v45._Myres >= 8 )
          operator delete(v45._Bx._Ptr);
        v45._Myres = 7;
        v45._Mysize = 0;
        v45._Bx._Buf[0] = 0;
        if ( v44._Myres >= 8 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        LOBYTE(v50) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"DST_POINT", 9u);
        LOBYTE(v50) = 18;
        v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
        LOBYTE(v50) = 19;
        desc.pivotOnDst = *INIReader::getFloat3(&r, &v41, v15, &key);
        if ( v44._Myres >= 8 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        LOBYTE(v50) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"SRC_POINT", 9u);
        LOBYTE(v50) = 20;
        v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
        LOBYTE(v50) = 21;
        desc.pivotOnSrc = *INIReader::getFloat3(&r, &v42, v16, &key);
        if ( v44._Myres >= 8 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        LOBYTE(v50) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        if ( desc.dstNode && desc.srcNode && desc.objectNode )
        {
          v17 = (ICollisionObject *)operator new(184);
          _Val = v17;
          LOBYTE(v50) = 22;
          if ( v17 )
          {
            SuspensionGraphics::SuspensionGraphics((SuspensionGraphics *)v17, this->car, &desc);
            v19 = v18;
          }
          else
          {
            v19 = 0;
          }
          v20 = this->car;
          LOBYTE(v50) = 9;
          _Val = v19;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&v20->gameObjects, &_Val);
          v19[9].__vftable = (ICollisionObject_vtbl *)v20;
          v2 = (int)v37;
          v6 = v38 + 1;
          LODWORD(v38) = v38 + 1;
        }
        else
        {
          v21 = Console::singleton();
          if ( !desc.dstNode )
          {
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            std::wstring::assign(&key, L"DST_OBJECT", 0xAu);
            LOBYTE(v50) = 23;
            _Val = (ICollisionObject *)&v34;
            v34._Myres = 7;
            v34._Mysize = 0;
            v34._Bx._Buf[0] = 0;
            std::wstring::assign(&v34, L"\n", 1u);
            LOBYTE(v50) = 24;
            v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
            LOBYTE(v50) = 25;
            v37 = &v33;
            INIReader::getString(&r, &v33, v22, &key);
            LOBYTE(v50) = 26;
            v32._Myres = 7;
            v32._Mysize = 0;
            v32._Bx._Buf[0] = 0;
            std::wstring::assign(&v32, L"[ERROR]: SUS GRAPHICS cannot find: ", 0x23u);
            v23 = Console::operator<<(v21, v32);
            LOBYTE(v50) = 25;
            v24 = Console::operator<<(v23, v33);
            LOBYTE(v50) = 27;
            Console::operator<<(v24, v34);
            if ( v44._Myres >= 8 )
              operator delete(v44._Bx._Ptr);
            v44._Myres = 7;
            v44._Mysize = 0;
            v44._Bx._Buf[0] = 0;
            LOBYTE(v50) = 9;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
          }
          if ( !desc.srcNode )
          {
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            std::wstring::assign(&key, L"SRC_OBJECT", 0xAu);
            LOBYTE(v50) = 28;
            HIDWORD(v38) = &v34;
            v34._Myres = 7;
            v34._Mysize = 0;
            v34._Bx._Buf[0] = 0;
            std::wstring::assign(&v34, L"\n", 1u);
            LOBYTE(v50) = 29;
            v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
            LOBYTE(v50) = 30;
            _Val = (ICollisionObject *)&v33;
            INIReader::getString(&r, &v33, v25, &key);
            LOBYTE(v50) = 31;
            v32._Myres = 7;
            v32._Mysize = 0;
            v32._Bx._Buf[0] = 0;
            std::wstring::assign(&v32, L"[ERROR]: SUS GRAPHICS cannot find: ", 0x23u);
            v26 = Console::operator<<(v21, v32);
            LOBYTE(v50) = 30;
            v27 = Console::operator<<(v26, v33);
            LOBYTE(v50) = 32;
            Console::operator<<(v27, v34);
            if ( v44._Myres >= 8 )
              operator delete(v44._Bx._Ptr);
            v44._Myres = 7;
            v44._Mysize = 0;
            v44._Bx._Buf[0] = 0;
            LOBYTE(v50) = 9;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
          }
          if ( !desc.objectNode )
          {
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            std::wstring::assign(&key, L"TARGET_OBJECT", 0xDu);
            LOBYTE(v50) = 33;
            HIDWORD(v38) = &v34;
            v34._Myres = 7;
            v34._Mysize = 0;
            v34._Bx._Buf[0] = 0;
            std::wstring::assign(&v34, L"\n", 1u);
            LOBYTE(v50) = 34;
            v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
            LOBYTE(v50) = 35;
            _Val = (ICollisionObject *)&v33;
            INIReader::getString(&r, &v33, v28, &key);
            LOBYTE(v50) = 36;
            v32._Myres = 7;
            v32._Mysize = 0;
            v32._Bx._Buf[0] = 0;
            std::wstring::assign(&v32, L"[ERROR]: SUS GRAPHICS cannot find: ", 0x23u);
            v29 = Console::operator<<(v21, v32);
            LOBYTE(v50) = 35;
            v30 = Console::operator<<(v29, v33);
            LOBYTE(v50) = 37;
            Console::operator<<(v30, v34);
            if ( v44._Myres >= 8 )
              operator delete(v44._Bx._Ptr);
            v44._Myres = 7;
            v44._Mysize = 0;
            v44._Bx._Buf[0] = 0;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
          }
          v6 = v38 + 1;
          LODWORD(v38) = v38 + 1;
        }
      }
      else
      {
        BYTE2(v35) = 0;
      }
      LOBYTE(v50) = 5;
      *(_DWORD *)&v40.gap0[*(_DWORD *)(*(_DWORD *)v40.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&desc.pivotOnDst.z + *(_DWORD *)(*(_DWORD *)v40.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v40.gap0
                                                                                                 + 4)
                                                                                     - 104;
      *(_DWORD *)&v40.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v40.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v40.gap10[8]) )
          std::wstreambuf::epptr(&v40.gap10[8]);
        else
          std::wstreambuf::egptr(&v40.gap10[8]);
        std::wstreambuf::eback(&v40.gap10[8]);
        v31 = std::wstreambuf::eback(&v40.gap10[8]);
        operator delete(v31);
      }
      std::wstreambuf::setg(&v40.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v40.gap10[8], 0, 0);
      *(_DWORD *)&v40.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v40.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v40.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v40.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v40.gap68);
    }
    while ( BYTE2(v35) );
  }
  LOBYTE(v50) = 4;
  INIReader::~INIReader(&r);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
Node *SuspensionGraphicsGenerator::getNodeFromName(SuspensionGraphicsGenerator *this, std::wstring nname)
{
  Node *v3; // esi
  bool v4; // zf
  CarAvatar *v5; // eax

  if ( std::wstring::compare(&nname, 0, nname._Mysize, L"WHEEL_LF", 8u) )
  {
    if ( std::wstring::compare(&nname, 0, nname._Mysize, L"WHEEL_RF", 8u) )
    {
      if ( std::wstring::compare(&nname, 0, nname._Mysize, L"WHEEL_LR", 8u) )
      {
        v4 = !std::operator==<wchar_t>(&nname, L"WHEEL_RR");
        v5 = this->car;
        if ( v4 )
          v3 = v5->bodyTransform;
        else
          v3 = v5->suspensionAvatar->getSusTransform(v5->suspensionAvatar, 3);
      }
      else
      {
        v3 = this->car->suspensionAvatar->getSusTransform(this->car->suspensionAvatar, 2);
      }
    }
    else
    {
      v3 = this->car->suspensionAvatar->getSusTransform(this->car->suspensionAvatar, 1);
    }
  }
  else
  {
    v3 = this->car->suspensionAvatar->getSusTransform(this->car->suspensionAvatar, 0);
  }
  if ( nname._Myres >= 8 )
    operator delete(nname._Bx._Ptr);
  return v3;
}
