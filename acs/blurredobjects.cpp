#include "blurredobjects.h"
void BlurredObjects::BlurredObjects(BlurredObjects *this, CarAvatar *acar)
{
  std::vector<DRSWingConnection> *v3; // edi
  BlurredObjects *v4; // esi
  std::wstring *v5; // eax
  CarAvatar *v6; // ecx
  int v7; // ebx
  Game *v8; // ebp
  std::wostream *v9; // eax
  const std::wstring *v10; // eax
  bool v11; // bl
  const std::wstring *v12; // eax
  const std::wstring *v13; // eax
  const std::wstring *v14; // eax
  const std::wstring *v15; // eax
  Game *v16; // ebp
  CarAvatar *v17; // eax
  int v18; // ebx
  int v19; // esi
  int v20; // eax
  BlurredObjects *v21; // edi
  int v22; // eax
  int v23; // eax
  Node **v24; // esi
  unsigned int v25; // edx
  int v26; // ebp
  DRSWingConnection *v27; // eax
  int v28; // ebx
  _OWORD *v29; // eax
  const __m128i *v30; // ebx
  __m128i v31; // xmm0
  std::wostream *v32; // eax
  std::wostream *v33; // eax
  std::wostream *v34; // eax
  std::wostream *v35; // eax
  std::wstring *v36; // eax
  bool v37; // cf
  std::wostream *v38; // eax
  std::wostream *v39; // eax
  std::wostream *v40; // eax
  std::wstring *v41; // eax
  int v42; // eax
  std::wstring v43; // [esp-12h] [ebp-3A4h] BYREF
  unsigned int v44; // [esp+6h] [ebp-38Ch]
  char v45; // [esp+2Dh] [ebp-365h]
  int v46; // [esp+2Eh] [ebp-364h]
  BlurredObjects *v47; // [esp+32h] [ebp-360h]
  std::vector<Node *> objects; // [esp+36h] [ebp-35Ch] BYREF
  Game *v49; // [esp+42h] [ebp-350h]
  Game *v50; // [esp+46h] [ebp-34Ch]
  unsigned int v51; // [esp+4Ah] [ebp-348h]
  __m128i v52; // [esp+4Eh] [ebp-344h] BYREF
  float maxsp; // [esp+5Eh] [ebp-334h]
  float minsp; // [esp+62h] [ebp-330h]
  std::vector<BlurredNode> *v55; // [esp+66h] [ebp-32Ch]
  BlurredObjects *v56; // [esp+6Ah] [ebp-328h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v57; // [esp+6Eh] [ebp-324h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v58; // [esp+11Eh] [ebp-274h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v59; // [esp+1CEh] [ebp-1C4h] BYREF
  std::wstring v60; // [esp+27Eh] [ebp-114h] BYREF
  std::wstring v61; // [esp+296h] [ebp-FCh] BYREF
  std::wstring key; // [esp+2AEh] [ebp-E4h] BYREF
  std::wstring _Left; // [esp+2C6h] [ebp-CCh] BYREF
  std::wstring name; // [esp+2DEh] [ebp-B4h] BYREF
  std::wstring v65; // [esp+2F6h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+30Eh] [ebp-84h] BYREF
  std::wstring ininame; // [esp+326h] [ebp-6Ch] BYREF
  INIReader r; // [esp+33Eh] [ebp-54h] BYREF
  int v69; // [esp+38Ah] [ebp-8h]
  int v70; // [esp+38Eh] [ebp-4h]
  void *retaddr; // [esp+392h] [ebp+0h]

  v47 = this;
  v46 = 0;
  v56 = this;
  v44 = (unsigned int)acar->game;
  v43._Myres = 7;
  v43._Mysize = 0;
  v43._Bx._Buf[0] = 0;
  std::wstring::assign(&v43, L"BLURRED_OBJECT", 0xEu);
  GameObject::GameObject(this, v43, (Game *)v44);
  v3 = (std::vector<DRSWingConnection> *)&this->blurredNodes;
  this->__vftable = (BlurredObjects_vtbl *)&BlurredObjects::`vftable';
  v70 = 0;
  v55 = &this->blurredNodes;
  this->blurredNodes._Myfirst = 0;
  this->blurredNodes._Mylast = 0;
  this->blurredNodes._Myend = 0;
  v44 = 13;
  LOBYTE(v70) = 1;
  v43._Myres = (unsigned int)L"content/cars/";
  this->car = acar;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, (const wchar_t *)v43._Myres, v44);
  v4 = this;
  LOBYTE(v70) = 2;
  v5 = std::operator+<wchar_t>(&result, &_Left, &this->car->unixName);
  LOBYTE(v70) = 3;
  std::operator+<wchar_t>(&ininame, v5, L"/data/blurred_objects.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v70) = 6;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v6 = this->car;
  _Left._Bx._Buf[0] = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  CarAvatar::openINI(v6, &r, &ininame);
  LOBYTE(v70) = 7;
  if ( r.ready )
  {
    v7 = v46;
    v8 = 0;
    v45 = 1;
    v49 = 0;
    do
    {
      *(_DWORD *)v57.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v57.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v57.gap68);
      LOBYTE(v70) = 8;
      v46 = v7 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v57, &v57.gap10[8], 0);
      v70 = 9;
      *(_DWORD *)&v57.gap0[*(_DWORD *)(*(_DWORD *)v57.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(BlurredObjects **)((char *)&v56 + *(_DWORD *)(*(_DWORD *)v57.gap0 + 4)) = (BlurredObjects *)(*(_DWORD *)(*(_DWORD *)v57.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v57.gap10[8]);
      *(_DWORD *)&v57.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v57.gap10[64] = 0;
      *(_DWORD *)&v57.gap10[68] = 0;
      v44 = (unsigned int)v8;
      LOBYTE(v70) = 11;
      v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v57.gap10, "OBJECT_");
      std::wostream::operator<<(v9, v44);
      v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v60);
      LOBYTE(v70) = 12;
      v11 = INIReader::hasSection(&r, v10);
      LOBYTE(v70) = 11;
      if ( v60._Myres >= 8 )
        operator delete(v60._Bx._Ptr);
      if ( v11 )
      {
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"NAME", 4u);
        LOBYTE(v70) = 13;
        v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v65);
        LOBYTE(v70) = 14;
        INIReader::getString(&r, &name, v12, &key);
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        v65._Myres = 7;
        v65._Mysize = 0;
        v65._Bx._Buf[0] = 0;
        LOBYTE(v70) = 17;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        v61._Myres = 7;
        v61._Mysize = 0;
        v61._Bx._Buf[0] = 0;
        std::wstring::assign(&v61, L"MIN_SPEED", 9u);
        LOBYTE(v70) = 18;
        v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v60);
        LOBYTE(v70) = 19;
        minsp = INIReader::getFloat(&r, v13, &v61);
        if ( v60._Myres >= 8 )
          operator delete(v60._Bx._Ptr);
        v60._Myres = 7;
        v60._Mysize = 0;
        v60._Bx._Buf[0] = 0;
        LOBYTE(v70) = 17;
        if ( v61._Myres >= 8 )
          operator delete(v61._Bx._Ptr);
        v61._Myres = 7;
        v61._Mysize = 0;
        v61._Bx._Buf[0] = 0;
        std::wstring::assign(&v61, L"MAX_SPEED", 9u);
        LOBYTE(v70) = 20;
        v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v60);
        LOBYTE(v70) = 21;
        maxsp = INIReader::getFloat(&r, v14, &v61);
        if ( v60._Myres >= 8 )
          operator delete(v60._Bx._Ptr);
        v60._Myres = 7;
        v60._Mysize = 0;
        v60._Bx._Buf[0] = 0;
        LOBYTE(v70) = 17;
        if ( v61._Myres >= 8 )
          operator delete(v61._Bx._Ptr);
        v61._Myres = 7;
        v61._Mysize = 0;
        v61._Bx._Buf[0] = 0;
        std::wstring::assign(&v61, L"WHEEL_INDEX", 0xBu);
        LOBYTE(v70) = 22;
        v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &v60);
        LOBYTE(v70) = 23;
        v16 = (Game *)INIReader::getInt(&r, v15, &v61);
        v50 = v16;
        if ( v60._Myres >= 8 )
          operator delete(v60._Bx._Ptr);
        v60._Myres = 7;
        v60._Mysize = 0;
        v60._Bx._Buf[0] = 0;
        LOBYTE(v70) = 17;
        if ( v61._Myres >= 8 )
          operator delete(v61._Bx._Ptr);
        if ( (unsigned int)v16 > 4 )
        {
          *(_DWORD *)v58.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v58.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v58.gap68);
          v7 = v46 | 4;
          LOBYTE(v70) = 30;
          v46 |= 4u;
          std::wiostream::basic_iostream<wchar_t>(&v58, &v58.gap10[8], 0);
          v70 = 31;
          *(_DWORD *)&v58.gap0[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v57.gap68[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v58.gap0 + 4) - 104;
          std::wstreambuf::wstreambuf(&v58.gap10[8]);
          *(_DWORD *)&v58.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v58.gap10[64] = 0;
          *(_DWORD *)&v58.gap10[68] = 0;
          v44 = (unsigned int)v16;
          v43._Myres = (unsigned int)" HAS INVALID WHEELINDEX=";
          LOBYTE(v70) = 33;
          v43._Mysize = (unsigned int)&name;
          v38 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v58.gap10, "BLURRED NODE ");
          v39 = std::operator<<<wchar_t>(v38, (const std::wstring *)v43._Mysize);
          v40 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v39, (const char *)v43._Myres);
          std::wostream::operator<<(v40, v44);
          v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v58, &v60);
          v37 = v41->_Myres < 8;
          LOBYTE(v70) = 34;
          if ( !v37 )
            v41 = (std::wstring *)v41->_Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v41->_Bx._Buf);
          ksGenerateCrash();
          if ( v60._Myres >= 8 )
            operator delete(v60._Bx._Ptr);
          LOBYTE(v70) = 17;
          *(_DWORD *)&v58.gap0[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v57.gap68[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v58.gap0 + 4) - 104;
          *(_DWORD *)&v58.gap10[8] = &std::wstringbuf::`vftable';
          std::wstringbuf::_Tidy((std::wstringbuf *)&v58.gap10[8]);
          std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v58.gap10[8]);
          std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v58.gap10[16]);
          std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v58.gap68);
        }
        else
        {
          objects._Myfirst = 0;
          objects._Mylast = 0;
          objects._Myend = 0;
          v17 = v4->car;
          v44 = 0;
          v43._Myres = (unsigned int)&SuspensionAnimator `RTTI Type Descriptor';
          v43._Mysize = (unsigned int)&ISuspensionAvatar `RTTI Type Descriptor';
          *(_QWORD *)&v43._Bx._Alias[8] = (unsigned int)v17->suspensionAvatar;
          LOBYTE(v70) = 24;
          v18 = __RTDynamicCast(
                  *(_DWORD *)&v43._Bx._Alias[8],
                  0,
                  &ISuspensionAvatar `RTTI Type Descriptor',
                  &SuspensionAnimator `RTTI Type Descriptor',
                  0);
          if ( v18 )
          {
            v19 = 0;
            v20 = (char *)v47->car->lodManager->lods._Mylast - (char *)v47->car->lodManager->lods._Myfirst;
            if ( v20 >= 0 && (v20 & 0xFFFFFFC0) != 0 )
            {
              v21 = v47;
              do
              {
                v22 = (*(int (**)(int, int, Game *))(*(_DWORD *)v18 + 28))(v18, v19, v16);
                (*(void (**)(int, std::wstring *, std::vector<Node *> *))(*(_DWORD *)v22 + 24))(
                  v22,
                  &name,
                  &objects);
                ++v19;
              }
              while ( v19 < v21->car->lodManager->lods._Mylast - v21->car->lodManager->lods._Myfirst );
              v3 = (std::vector<DRSWingConnection> *)v55;
            }
          }
          else
          {
            v23 = (int)v4->car->suspensionAvatar->getWheelTransform(v4->car->suspensionAvatar, (int)v16);
            (*(void (**)(int, std::wstring *, std::vector<Node *> *))(*(_DWORD *)v23 + 24))(
              v23,
              &name,
              &objects);
          }
          v24 = objects._Myfirst;
          if ( objects._Mylast - objects._Myfirst )
          {
            v25 = (unsigned int)((char *)objects._Mylast - (char *)objects._Myfirst + 3) >> 2;
            v26 = 0;
            if ( objects._Myfirst > objects._Mylast )
              v25 = 0;
            v51 = v25;
            if ( v25 )
            {
              v52.m128i_i64[1] = __PAIR64__(LODWORD(maxsp), LODWORD(minsp));
              v52.m128i_i32[1] = (int)v50;
              while ( 1 )
              {
                v52.m128i_i32[0] = (int)*v24;
                v27 = v3->_Mylast;
                if ( &v52 >= (__m128i *)v27 || v3->_Myfirst > (DRSWingConnection *)&v52 )
                {
                  if ( v27 == v3->_Myend )
                  {
                    std::vector<VisualDamageManager::ScratchablePart>::_Reserve(v3, 1u);
                    v25 = v51;
                  }
                  v29 = v3->_Mylast;
                  if ( !v29 )
                    goto LABEL_49;
                  v31 = _mm_loadu_si128(&v52);
                }
                else
                {
                  v28 = (char *)&v52 - (char *)v3->_Myfirst;
                  if ( v27 == v3->_Myend )
                  {
                    std::vector<VisualDamageManager::ScratchablePart>::_Reserve(v3, 1u);
                    v25 = v51;
                  }
                  v29 = v3->_Mylast;
                  v30 = (const __m128i *)((char *)v3->_Myfirst + (v28 & 0xFFFFFFF0));
                  if ( !v29 )
                    goto LABEL_49;
                  v31 = _mm_loadu_si128(v30);
                }
                *v29 = v31;
LABEL_49:
                ++v3->_Mylast;
                ++v26;
                ++v24;
                if ( v26 == v25 )
                {
                  v24 = objects._Myfirst;
                  break;
                }
              }
            }
            v7 = v46;
          }
          else
          {
            *(_DWORD *)v59.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v59.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v59.gap68);
            v7 = (unsigned int)v47 | 2;
            LOBYTE(retaddr) = 25;
            v47 = (BlurredObjects *)((unsigned int)v47 | 2);
            std::wiostream::basic_iostream<wchar_t>(&v59.gap0[4], &v59.gap10[12], 0);
            v69 = 26;
            *(_DWORD *)&v58.gap68[*(_DWORD *)(*(_DWORD *)&v58.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v58.gap68[*(_DWORD *)(*(_DWORD *)&v58.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v58.gap68[68]
                                                                                               + 4)
                                                                                   - 104;
            std::wstreambuf::wstreambuf(&v59.gap10[4]);
            *(_DWORD *)&v59.gap10[4] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v59.gap10[60] = 0;
            *(_DWORD *)&v59.gap10[64] = 0;
            v43._Myres = (unsigned int)"]: CANNOT LOCATE OBJECT";
            v43._Mysize = (unsigned int)v16;
            *(_DWORD *)&v43._Bx._Alias[12] = ") WHEELINDEX[";
            LOBYTE(v69) = 28;
            *(_DWORD *)&v43._Bx._Alias[8] = &_Left._Myres;
            v32 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
                    (std::wostream *)((char *)&v59._Chcount + 4),
                    "BLURRED NODE (");
            v33 = std::operator<<<wchar_t>(v32, *(const std::wstring **)&v43._Bx._Alias[8]);
            v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v33, *(const char **)&v43._Bx._Alias[12]);
            v35 = (std::wostream *)std::wostream::operator<<(v34, v43._Mysize);
            std::operator<<<wchar_t,std::char_traits<wchar_t>>(v35, (const char *)v44);
            v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v60);
            v37 = v36->_Myres < 8;
            LOBYTE(v70) = 29;
            if ( !v37 )
              v36 = (std::wstring *)v36->_Bx._Ptr;
            _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v36->_Bx._Buf);
            ksGenerateCrash();
            if ( v60._Myres >= 8 )
              operator delete(v60._Bx._Ptr);
            LOBYTE(v70) = 24;
            *(_DWORD *)&v59.gap0[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v58.gap68[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v59.gap0 + 4)
                                                                             - 104;
            *(_DWORD *)&v59.gap10[8] = &std::wstringbuf::`vftable';
            std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
            std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[8]);
            std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[16]);
            std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v59.gap68);
            v24 = objects._Myfirst;
          }
          LOBYTE(v70) = 17;
          if ( v24 )
          {
            std::_Container_base0::_Orphan_all(&objects);
            operator delete(objects._Myfirst);
            objects._Myfirst = 0;
            objects._Mylast = 0;
            objects._Myend = 0;
          }
          v4 = v47;
        }
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        v8 = v49;
      }
      else
      {
        v7 = v46;
        v45 = 0;
      }
      v8 = (Game *)((char *)v8 + 1);
      v49 = v8;
      LOBYTE(v70) = 7;
      *(_DWORD *)&v57.gap0[*(_DWORD *)(*(_DWORD *)v57.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(BlurredObjects **)((char *)&v56 + *(_DWORD *)(*(_DWORD *)v57.gap0 + 4)) = (BlurredObjects *)(*(_DWORD *)(*(_DWORD *)v57.gap0 + 4) - 104);
      *(_DWORD *)&v57.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v57.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v57.gap10[8]) )
          std::wstreambuf::epptr(&v57.gap10[8]);
        else
          std::wstreambuf::egptr(&v57.gap10[8]);
        std::wstreambuf::eback(&v57.gap10[8]);
        v42 = std::wstreambuf::eback(&v57.gap10[8]);
        operator delete(v42);
      }
      std::wstreambuf::setg(&v57.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v57.gap10[8], 0, 0);
      *(_DWORD *)&v57.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v57.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v57.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v57.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v57.gap68);
    }
    while ( v45 );
  }
  LOBYTE(v70) = 6;
  INIReader::~INIReader(&r);
  if ( ininame._Myres >= 8 )
    operator delete(ininame._Bx._Ptr);
}
BlurredObjects *BlurredObjects::`scalar deleting destructor'(BlurredObjects *this, unsigned int a2)
{
  this->__vftable = (BlurredObjects_vtbl *)&BlurredObjects::`vftable';
  if ( this->blurredNodes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->blurredNodes);
    operator delete(this->blurredNodes._Myfirst);
    this->blurredNodes._Myfirst = 0;
    this->blurredNodes._Mylast = 0;
    this->blurredNodes._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void BlurredObjects::update(BlurredObjects *this, float deltaT)
{
  float v3; // xmm0_4
  BlurredNode *v4; // ecx
  BlurredNode *i; // eax
  float v6; // xmm1_4
  bool v7; // bl
  Node *v8; // edx
  float v9; // [esp+0h] [ebp-4h]

  v9 = FLOAT_1_0;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
  {
    v3 = this->car->sim->replayManager->timeMult;
    v9 = v3;
    if ( v3 == 0.0 )
    {
      v3 = FLOAT_1_0;
      v9 = FLOAT_1_0;
    }
  }
  else
  {
    v3 = FLOAT_1_0;
  }
  v4 = this->blurredNodes._Mylast;
  for ( i = this->blurredNodes._Myfirst; i != v4; v8->isActive = v7 )
  {
    LODWORD(v6) = COERCE_UNSIGNED_INT(this->car->physicsState.wheelAngularSpeed[i->wheelIndex] * v3) & _xmm;
    v7 = v6 >= i->minAngularSpeed && i->maxAngularSpeed >= v6;
    v8 = i->node;
    ++i;
    v3 = v9;
  }
}
