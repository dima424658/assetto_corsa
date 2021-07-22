#include "startingtracksemaphore.h"
void StartingTrackSemaphore::StartingTrackSemaphore(StartingTrackSemaphore *this, Sim *aSim)
{
  StartingTrackSemaphore *v2; // edi
  std::vector<StartingTrackSemaphore::SemaphoreElement> *v3; // ebx
  TrackAvatar *v4; // ecx
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  double v7; // st7
  bool v8; // cf
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  StartingTrackSemaphore::SemaphoreElement *v12; // ecx
  StartingTrackSemaphore::SemaphoreElement *v13; // eax
  unsigned int v14; // esi
  StartingTrackSemaphore::LightGroup *v15; // edi
  int v16; // ebx
  std::wostream *v17; // eax
  const std::wstring *v18; // eax
  bool v19; // bl
  const std::wstring *v20; // eax
  std::wstring *v21; // esi
  Sim *v22; // eax
  Node **v23; // esi
  Node **i; // edi
  Node *v25; // eax
  int v26; // ebx
  const std::wstring *v27; // eax
  const std::wstring *v28; // eax
  int v29; // eax
  Material *v30; // eax
  Material *v31; // eax
  std::_Ref_count_base *v32; // ebx
  MaterialVar *v33; // ecx
  Material *v34; // eax
  float v35; // edx
  int v36; // ecx
  std::wstring *v37; // eax
  std::wostream *v38; // eax
  std::wstring v39; // [esp-1Ch] [ebp-210h] BYREF
  int v40; // [esp-4h] [ebp-1F8h]
  char v41; // [esp+1Bh] [ebp-1D9h] BYREF
  int v42; // [esp+1Ch] [ebp-1D8h]
  MaterialVar *var; // [esp+20h] [ebp-1D4h] BYREF
  StartingTrackSemaphore *v44; // [esp+24h] [ebp-1D0h]
  Game *v45; // [esp+28h] [ebp-1CCh]
  int v46; // [esp+2Ch] [ebp-1C8h]
  int v47; // [esp+30h] [ebp-1C4h]
  std::shared_ptr<Material> mat; // [esp+34h] [ebp-1C0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v49; // [esp+3Ch] [ebp-1B8h] BYREF
  std::vector<Node *> nodes; // [esp+ECh] [ebp-108h] BYREF
  int v51; // [esp+F8h] [ebp-FCh]
  int v52; // [esp+FCh] [ebp-F8h]
  unsigned int v53; // [esp+100h] [ebp-F4h]
  std::wstring key; // [esp+104h] [ebp-F0h] BYREF
  std::wstring section; // [esp+11Ch] [ebp-D8h] BYREF
  std::wstring v56; // [esp+134h] [ebp-C0h] BYREF
  std::wstring v57; // [esp+14Ch] [ebp-A8h] BYREF
  std::wstring result; // [esp+164h] [ebp-90h] BYREF
  std::wstring v59; // [esp+17Ch] [ebp-78h] BYREF
  INIReader ini; // [esp+194h] [ebp-60h] BYREF
  int v61; // [esp+1F0h] [ebp-4h]

  v2 = this;
  v44 = this;
  var = 0;
  v45 = (Game *)this;
  v40 = (int)aSim->game;
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  std::wstring::assign(&v39, L"STARTING_TRACK_SEMAPHORE", 0x18u);
  GameObject::GameObject(v2, v39, (Game *)v40);
  v3 = &v2->semaphore;
  v2->__vftable = (StartingTrackSemaphore_vtbl *)&StartingTrackSemaphore::`vftable';
  v61 = 0;
  v2->semaphore._Myfirst = 0;
  v2->semaphore._Mylast = 0;
  v2->semaphore._Myend = 0;
  v2->sim = aSim;
  v2->intensity = 1.0;
  v2->disqualifiedOn = 0;
  v2->customStart = 0.0;
  v4 = aSim->track;
  LOBYTE(v61) = 1;
  v5 = TrackAvatar::getDataFolder(v4, &result);
  LOBYTE(v61) = 2;
  v6 = std::operator+<wchar_t>(&v59, v5, L"/data/semaphore.ini");
  LOBYTE(v61) = 3;
  INIReader::INIReader(&ini, v6);
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  LOBYTE(v61) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"INTENSITY", 9u);
    LOBYTE(v61) = 7;
    v53 = 7;
    v52 = 0;
    LOWORD(nodes._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&nodes, L"COLOR", 5u);
    LOBYTE(v61) = 8;
    v7 = INIReader::getFloat(&ini, (const std::wstring *)&nodes, &key);
    v8 = v53 < 8;
    v2->intensity = v7;
    if ( !v8 )
      operator delete(nodes._Myfirst);
    v53 = 7;
    v52 = 0;
    LOWORD(nodes._Myfirst) = 0;
    LOBYTE(v61) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISQUALIFIED", 0xCu);
    LOBYTE(v61) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GROUPS", 6u);
    LOBYTE(v61) = 10;
    v9 = INIReader::getInt(&ini, &section, &key);
    nodes._Mylast = 0;
    nodes._Myend = 0;
    v51 = 0;
    LOBYTE(v61) = 11;
    nodes._Myfirst = 0;
    std::vector<StartingTrackSemaphore::LightGroup>::resize(
      (std::vector<StartingTrackSemaphore::LightGroup> *)&nodes._Mylast,
      v9);
    LOBYTE(v61) = 12;
    std::vector<StartingTrackSemaphore::SemaphoreElement>::push_back(
      &v2->semaphore,
      (StartingTrackSemaphore::SemaphoreElement *)&nodes);
    LOBYTE(v61) = 10;
    if ( nodes._Mylast )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&nodes._Mylast);
      v40 = (int)v45;
      v39._Myres = (unsigned int)&v41;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
        (DRSDetection *)nodes._Mylast,
        (DRSDetection *)nodes._Myend);
      operator delete(nodes._Mylast);
      nodes._Mylast = 0;
      nodes._Myend = 0;
      v51 = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v61) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"READY", 5u);
    LOBYTE(v61) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GROUPS", 6u);
    LOBYTE(v61) = 14;
    v10 = INIReader::getInt(&ini, &section, &key);
    nodes._Mylast = 0;
    nodes._Myend = 0;
    v51 = 0;
    LOBYTE(v61) = 15;
    nodes._Myfirst = (Node **)1;
    std::vector<StartingTrackSemaphore::LightGroup>::resize(
      (std::vector<StartingTrackSemaphore::LightGroup> *)&nodes._Mylast,
      v10);
    LOBYTE(v61) = 16;
    std::vector<StartingTrackSemaphore::SemaphoreElement>::push_back(
      &v2->semaphore,
      (StartingTrackSemaphore::SemaphoreElement *)&nodes);
    LOBYTE(v61) = 14;
    if ( nodes._Mylast )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&nodes._Mylast);
      v40 = (int)v45;
      v39._Myres = (unsigned int)&v41;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
        (DRSDetection *)nodes._Mylast,
        (DRSDetection *)nodes._Myend);
      operator delete(nodes._Mylast);
      nodes._Mylast = 0;
      nodes._Myend = 0;
      v51 = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v61) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"START", 5u);
    LOBYTE(v61) = 17;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GROUPS", 6u);
    LOBYTE(v61) = 18;
    v11 = INIReader::getInt(&ini, &section, &key);
    nodes._Mylast = 0;
    nodes._Myend = 0;
    v51 = 0;
    LOBYTE(v61) = 19;
    nodes._Myfirst = (Node **)2;
    std::vector<StartingTrackSemaphore::LightGroup>::resize(
      (std::vector<StartingTrackSemaphore::LightGroup> *)&nodes._Mylast,
      v11);
    LOBYTE(v61) = 20;
    std::vector<StartingTrackSemaphore::SemaphoreElement>::push_back(
      &v2->semaphore,
      (StartingTrackSemaphore::SemaphoreElement *)&nodes);
    LOBYTE(v61) = 18;
    if ( nodes._Mylast )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&nodes._Mylast);
      v40 = (int)v45;
      v39._Myres = (unsigned int)&v41;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
        (DRSDetection *)nodes._Mylast,
        (DRSDetection *)nodes._Myend);
      operator delete(nodes._Mylast);
      nodes._Mylast = 0;
      nodes._Myend = 0;
      v51 = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v61) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v12 = v2->semaphore._Mylast;
    v13 = v3->_Myfirst;
    if ( v3->_Myfirst != v12 )
    {
      do
      {
        v14 = 0;
        v15 = v13->groups._Myfirst;
        if ( v13->groups._Mylast - v15 )
        {
          v16 = 0;
          do
          {
            v15[v16++].order = v14++;
            v15 = v13->groups._Myfirst;
          }
          while ( v14 < v13->groups._Mylast - v15 );
        }
        ++v13;
      }
      while ( v13 != v12 );
      v2 = v44;
    }
    v46 = 0;
    *(_DWORD *)v49.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v49.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v49.gap68);
    LOBYTE(v61) = 21;
    var = (MaterialVar *)1;
    std::wiostream::basic_iostream<wchar_t>(&v49, &v49.gap10[8], 0);
    v61 = 22;
    *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(std::_Ref_count_base **)((char *)&mat._Rep + *(_DWORD *)(*(_DWORD *)v49.gap0 + 4)) = (std::_Ref_count_base *)(*(_DWORD *)(*(_DWORD *)v49.gap0 + 4) - 104);
    std::wstreambuf::wstreambuf(&v49.gap10[8]);
    *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v49.gap10[64] = 0;
    *(_DWORD *)&v49.gap10[68] = 0;
    v40 = 0;
    LOBYTE(v61) = 24;
    v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v49.gap10, "OBJECT_");
    std::wostream::operator<<(v17, v40);
    while ( 1 )
    {
      v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &v57);
      LOBYTE(v61) = 25;
      v19 = INIReader::hasSection(&ini, v18);
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      if ( !v19 )
        break;
      nodes._Myfirst = 0;
      nodes._Mylast = 0;
      nodes._Myend = 0;
      LOBYTE(v61) = 26;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"NAME", 4u);
      LOBYTE(v61) = 27;
      v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &v56);
      LOBYTE(v61) = 28;
      v21 = INIReader::getString(&ini, &section, v20, &key);
      v22 = v2->sim;
      LOBYTE(v61) = 29;
      v22->trackNode->findChildrenByName(v22->trackNode, v21, &nodes);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v56._Myres >= 8 )
        operator delete(v56._Bx._Ptr);
      v56._Myres = 7;
      v56._Mysize = 0;
      v56._Bx._Buf[0] = 0;
      LOBYTE(v61) = 26;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v23 = nodes._Myfirst;
      for ( i = nodes._Mylast; v23 != i; ++v23 )
      {
        v25 = *v23;
        v40 = 0;
        v39._Myres = (unsigned int)&Mesh `RTTI Type Descriptor';
        v39._Mysize = (unsigned int)&Node `RTTI Type Descriptor';
        *(_QWORD *)&v39._Bx._Alias[8] = (unsigned int)v25;
        v25->isActive = 1;
        v26 = __RTDynamicCast(
                *(_DWORD *)&v39._Bx._Alias[8],
                *(_DWORD *)&v39._Bx._Alias[12],
                v39._Mysize,
                v39._Myres,
                v40);
        var = (MaterialVar *)v26;
        if ( v26 )
        {
          v40 = 4;
          *(_BYTE *)(v26 + 189) = 1;
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"TYPE", v40);
          LOBYTE(v61) = 30;
          v27 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &v56);
          LOBYTE(v61) = 31;
          v42 = INIReader::getInt(&ini, v27, &section);
          if ( v56._Myres >= 8 )
            operator delete(v56._Bx._Ptr);
          v56._Myres = 7;
          v56._Mysize = 0;
          v56._Bx._Buf[0] = 0;
          LOBYTE(v61) = 26;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          section._Bx._Buf[0] = 0;
          v42 = (int)&v44->semaphore._Myfirst[v42];
          section._Myres = 7;
          section._Mysize = 0;
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"ORDER", 5u);
          LOBYTE(v61) = 32;
          v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v49, &v57);
          LOBYTE(v61) = 33;
          v29 = INIReader::getInt(&ini, v28, &key);
          v47 = *(_DWORD *)(v42 + 4) + 16 * v29;
          if ( v57._Myres >= 8 )
            operator delete(v57._Bx._Ptr);
          v57._Myres = 7;
          v57._Mysize = 0;
          v57._Bx._Buf[0] = 0;
          LOBYTE(v61) = 26;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          v30 = (Material *)operator new(104);
          v42 = (int)v30;
          LOBYTE(v61) = 34;
          if ( v30 )
            Material::Material(v30, *(const Material **)(v26 + 248));
          else
            v31 = 0;
          LOBYTE(v61) = 26;
          mat._Ptr = 0;
          mat._Rep = 0;
          std::shared_ptr<Material>::_Resetp<Material>(&mat, v31);
          v32 = mat._Rep;
          LOBYTE(v61) = 35;
          if ( mat._Rep )
            _InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Uses, 1u);
          v33 = var;
          v34 = mat._Ptr;
          v35 = var[1].mValue.M43;
          LODWORD(var[1].mValue.M43) = v32;
          v42 = LODWORD(v35);
          LODWORD(v33[1].mValue.M42) = v34;
          if ( v35 != 0.0 && !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v35) + 4), 0xFFFFFFFF) )
          {
            (**(void (***)(float))LODWORD(v35))(COERCE_FLOAT(LODWORD(v35)));
            v36 = v42;
            if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v42 + 8), 0xFFFFFFFF) )
              (*(void (**)(int))(*(_DWORD *)v36 + 4))(v36);
          }
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"ksEmissive", 0xAu);
          LOBYTE(v61) = 36;
          var = Material::getVar((Material *)LODWORD(var[1].mValue.M42), &section);
          LOBYTE(v61) = 35;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          std::vector<SpinnerData *>::push_back(
            (std::vector<ICollisionObject *> *)(v47 + 4),
            (ICollisionObject *const *)&var);
          LOBYTE(v61) = 26;
          if ( v32 )
          {
            if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v32->_Uses, 0xFFFFFFFF) )
            {
              v32->_Destroy(v32);
              if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v32->_Weaks, 0xFFFFFFFF) )
                v32->_Delete_this(v32);
            }
          }
        }
      }
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, word_17BE9D8, 0);
      LOBYTE(v61) = 37;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v49.gap10[8]);
      v40 = *(_DWORD *)&v49.gap10[68];
      v37 = &key;
      v39._Myres = key._Mysize;
      if ( key._Myres >= 8 )
        v37 = (std::wstring *)key._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v49.gap10[8], v37->_Bx._Buf, v39._Myres, v40);
      LOBYTE(v61) = 26;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v40 = ++v46;
      v38 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v49.gap10, "OBJECT_");
      std::wostream::operator<<(v38, v40);
      v2 = v44;
      LOBYTE(v61) = 24;
      if ( nodes._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&nodes);
        operator delete(nodes._Myfirst);
        nodes._Myfirst = 0;
        nodes._Mylast = 0;
        nodes._Myend = 0;
      }
    }
    LOBYTE(v61) = 6;
    *(_DWORD *)&v49.gap0[*(_DWORD *)(*(_DWORD *)v49.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(std::_Ref_count_base **)((char *)&mat._Rep + *(_DWORD *)(*(_DWORD *)v49.gap0 + 4)) = (std::_Ref_count_base *)(*(_DWORD *)(*(_DWORD *)v49.gap0 + 4) - 104);
    *(_DWORD *)&v49.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v49.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v49.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v49.gap68);
  }
  LOBYTE(v61) = 1;
  INIReader::~INIReader(&ini);
}
void StartingTrackSemaphore::~StartingTrackSemaphore(StartingTrackSemaphore *this)
{
  this->__vftable = (StartingTrackSemaphore_vtbl *)&StartingTrackSemaphore::`vftable';
  if ( this->semaphore._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->semaphore);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::SemaphoreElement>>>(
      this->semaphore._Myfirst,
      this->semaphore._Mylast);
    operator delete(this->semaphore._Myfirst);
    this->semaphore._Myfirst = 0;
    this->semaphore._Mylast = 0;
    this->semaphore._Myend = 0;
  }
  GameObject::~GameObject(this);
}
StartingTrackSemaphore *StartingTrackSemaphore::`scalar deleting destructor'(StartingTrackSemaphore *this, unsigned int a2)
{
  StartingTrackSemaphore::~StartingTrackSemaphore(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double StartingTrackSemaphore::getTimeToSessionStart(StartingTrackSemaphore *this)
{
  Sim *v2; // eax
  ACClient *v4; // ecx
  double v5; // xmm1_8
  float timeToStart; // [esp+4h] [ebp-44h]
  RemoteSession ses; // [esp+Ch] [ebp-3Ch] BYREF

  v2 = this->sim;
  if ( this->customStart != 0.0 )
    return this->customStart - v2->game->gameTime.now;
  v4 = v2->client;
  timeToStart = 0.0;
  if ( !v4 )
    return RaceManager::getTimeToSessionStart(v2->raceManager);
  ACClient::getCurrentSession(v4, &ses);
  if ( ses.type == Race )
  {
    v5 = this->game->gameTime.now;
    if ( ses.startTime > v5 )
      timeToStart = ses.startTime - v5;
  }
  if ( ses.name._Myres >= 8 )
    operator delete(ses.name._Bx._Ptr);
  return timeToStart;
}
void StartingTrackSemaphore::resetLights(StartingTrackSemaphore *this)
{
  StartingTrackSemaphore::SemaphoreElement *v1; // eax
  StartingTrackSemaphore::SemaphoreElement *v2; // ecx
  StartingTrackSemaphore::LightGroup *v3; // ebp
  StartingTrackSemaphore::LightGroup *v4; // edi
  MaterialVar **v5; // esi
  MaterialVar **v6; // ebx
  __int64 v7; // xmm0_8
  MaterialVar *v8; // eax
  ShaderVariable *v9; // ecx
  float *v10; // eax
  StartingTrackSemaphore::SemaphoreElement *v11; // [esp+18h] [ebp-3Ch]
  StartingTrackSemaphore::LightGroup *v12; // [esp+20h] [ebp-34h]
  StartingTrackSemaphore::SemaphoreElement *i; // [esp+24h] [ebp-30h]
  __int64 v14; // [esp+28h] [ebp-2Ch]
  int v15; // [esp+30h] [ebp-24h]
  StartingTrackSemaphore::LightGroup g; // [esp+34h] [ebp-20h] BYREF
  int v17; // [esp+50h] [ebp-4h]

  v1 = this->semaphore._Myfirst;
  v2 = this->semaphore._Mylast;
  v11 = v1;
  for ( i = v2; v1 != v2; v11 = v1 )
  {
    v3 = v1->groups._Mylast;
    v4 = v1->groups._Myfirst;
    v12 = v3;
    if ( v4 != v3 )
    {
      do
      {
        g.order = v4->order;
        std::vector<Mesh *>::vector<Mesh *>(
          (std::vector<TyreThermalPatch *> *)&g.vars,
          (const std::vector<TyreThermalPatch *> *)&v4->vars);
        v5 = g.vars._Myfirst;
        v6 = g.vars._Mylast;
        v17 = 0;
        if ( g.vars._Myfirst != g.vars._Mylast )
        {
          v14 = 0i64;
          v7 = 0i64;
          v15 = 0;
          do
          {
            v8 = *v5;
            *(_QWORD *)&v8->fValue3.x = v7;
            v8->fValue3.z = 0.0;
            v9 = v8->var;
            switch ( v9->type )
            {
              case 0:
                v10 = &v8->fValue;
                goto LABEL_11;
              case 1:
                v10 = &v8->fValue2.x;
                goto LABEL_11;
              case 2:
                ShaderVariable::set(v9, &v8->fValue3.x);
                goto LABEL_12;
              case 3:
                v10 = &v8->fValue4.x;
                goto LABEL_11;
              case 4:
                v10 = &v8->mValue.M11;
LABEL_11:
                ShaderVariable::set(v9, v10);
LABEL_12:
                v7 = v14;
                break;
              default:
                break;
            }
            ++v5;
          }
          while ( v5 != v6 );
          v5 = g.vars._Myfirst;
          v3 = v12;
        }
        v17 = -1;
        if ( v5 )
        {
          std::_Container_base0::_Orphan_all(&g.vars);
          operator delete(g.vars._Myfirst);
          g.vars._Myfirst = 0;
          g.vars._Mylast = 0;
          g.vars._Myend = 0;
        }
        ++v4;
      }
      while ( v4 != v3 );
      v1 = v11;
      v2 = i;
    }
    ++v1;
  }
}
void StartingTrackSemaphore::setCustomStartTime(StartingTrackSemaphore *this, long double startTime)
{
  this->customStart = startTime;
}
void StartingTrackSemaphore::update(StartingTrackSemaphore *this, float dt)
{
  StartingTrackSemaphore *v2; // ebp
  StartingTrackSemaphore::SemaphoreElement *v3; // ebx
  StartingTrackSemaphore::SemaphoreElement *v4; // ebp
  StartingTrackSemaphore::LightGroup *v5; // edi
  StartingTrackSemaphore::LightGroup *v6; // ebp
  MaterialVar **v7; // esi
  MaterialVar **v8; // ebx
  MaterialVar *v9; // edx
  float v10; // eax
  ShaderVariable *v11; // ecx
  float *v12; // eax
  StartingTrackSemaphore::SemaphoreElement *v13; // ebx
  int v14; // eax
  StartingTrackSemaphore::LightGroup *v15; // edi
  StartingTrackSemaphore::LightGroup *v16; // ebx
  double v17; // st7
  MaterialVar **v18; // esi
  unsigned int v19; // ebp
  int l; // edi
  MaterialVar *v21; // ecx
  float v22; // eax
  StartingTrackSemaphore::SemaphoreElement *v23; // ebp
  StartingTrackSemaphore::LightGroup *v24; // ebx
  StartingTrackSemaphore::LightGroup *v25; // ebp
  MaterialVar **v26; // esi
  MaterialVar **v27; // edi
  MaterialVar *v28; // edx
  float v29; // eax
  ShaderVariable *v30; // ecx
  float *v31; // eax
  StartingTrackSemaphore::SemaphoreElement *i; // [esp+1Ch] [ebp-4Ch]
  float v34; // [esp+1Ch] [ebp-4Ch]
  StartingTrackSemaphore::SemaphoreElement *v35; // [esp+20h] [ebp-48h]
  StartingTrackSemaphore::LightGroup *v36; // [esp+20h] [ebp-48h]
  float v37; // [esp+24h] [ebp-44h]
  StartingTrackSemaphore::LightGroup *v38; // [esp+28h] [ebp-40h]
  float v39; // [esp+28h] [ebp-40h]
  float k; // [esp+28h] [ebp-40h]
  StartingTrackSemaphore::LightGroup *j; // [esp+28h] [ebp-40h]
  StartingTrackSemaphore::LightGroup *v42; // [esp+2Ch] [ebp-3Ch]
  StartingTrackSemaphore::SemaphoreElement s; // [esp+3Ch] [ebp-2Ch] BYREF
  StartingTrackSemaphore::LightGroup g; // [esp+4Ch] [ebp-1Ch] BYREF
  int v45; // [esp+64h] [ebp-4h]

  v2 = this;
  if ( this->semaphore._Myfirst != this->semaphore._Mylast )
  {
    StartingTrackSemaphore::resetLights(this);
    if ( v2->disqualifiedOn )
    {
      v3 = v2->semaphore._Myfirst;
      v4 = v2->semaphore._Mylast;
      v35 = v3;
      for ( i = v4; v3 != v4; v35 = v3 )
      {
        s.type = v3->type;
        std::vector<StartingTrackSemaphore::LightGroup>::vector<StartingTrackSemaphore::LightGroup>(
          &s.groups,
          &v3->groups);
        v5 = s.groups._Myfirst;
        v45 = 0;
        if ( s.type == eSemaphoreDisqualified )
        {
          v6 = s.groups._Mylast;
          v38 = s.groups._Mylast;
          if ( s.groups._Myfirst != s.groups._Mylast )
          {
            do
            {
              g.order = v5->order;
              std::vector<Mesh *>::vector<Mesh *>(
                (std::vector<TyreThermalPatch *> *)&g.vars,
                (const std::vector<TyreThermalPatch *> *)&v5->vars);
              v7 = g.vars._Myfirst;
              v8 = g.vars._Mylast;
              LOBYTE(v45) = 1;
              if ( g.vars._Myfirst != g.vars._Mylast )
              {
                do
                {
                  v9 = *v7;
                  v10 = this->intensity;
                  *(_QWORD *)&v9->fValue3.x = _mm_unpacklo_ps((__m128)LODWORD(v10), (__m128)LODWORD(v10)).m128_u64[0];
                  v9->fValue3.z = v10;
                  v11 = v9->var;
                  switch ( v11->type )
                  {
                    case 0:
                      v12 = &v9->fValue;
                      goto LABEL_13;
                    case 1:
                      v12 = &v9->fValue2.x;
                      goto LABEL_13;
                    case 2:
                      ShaderVariable::set(v11, &v9->fValue3.x);
                      break;
                    case 3:
                      v12 = &v9->fValue4.x;
                      goto LABEL_13;
                    case 4:
                      v12 = &v9->mValue.M11;
LABEL_13:
                      ShaderVariable::set(v11, v12);
                      break;
                    default:
                      break;
                  }
                  ++v7;
                }
                while ( v7 != v8 );
                v7 = g.vars._Myfirst;
                v6 = v38;
              }
              LOBYTE(v45) = 0;
              if ( v7 )
              {
                std::_Container_base0::_Orphan_all(&g.vars);
                operator delete(g.vars._Myfirst);
                g.vars._Myfirst = 0;
                g.vars._Mylast = 0;
                g.vars._Myend = 0;
              }
              ++v5;
            }
            while ( v5 != v6 );
            v5 = s.groups._Myfirst;
            v3 = v35;
          }
          v4 = i;
        }
        v45 = -1;
        if ( v5 )
        {
          std::_Container_base0::_Orphan_all(&s.groups);
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<StartingTrackSemaphore::LightGroup>>>(
            (DRSDetection *)s.groups._Myfirst,
            (DRSDetection *)s.groups._Mylast);
          operator delete(s.groups._Myfirst);
          s.groups._Myfirst = 0;
          s.groups._Mylast = 0;
          s.groups._Myend = 0;
        }
        ++v3;
      }
    }
    else
    {
      v39 = StartingTrackSemaphore::getTimeToSessionStart(v2);
      if ( v39 <= 0.0 )
      {
        v23 = v2->semaphore._Myfirst;
        v24 = v23[2].groups._Myfirst;
        v25 = v23[2].groups._Mylast;
        for ( j = v25; v24 != v25; ++v24 )
        {
          v26 = v24->vars._Myfirst;
          v27 = v24->vars._Mylast;
          if ( v26 != v27 )
          {
            do
            {
              v28 = *v26;
              v29 = this->intensity;
              *(_QWORD *)&v28->fValue3.x = _mm_unpacklo_ps((__m128)LODWORD(v29), (__m128)LODWORD(v29)).m128_u64[0];
              v28->fValue3.z = v29;
              v30 = v28->var;
              switch ( v30->type )
              {
                case 0:
                  v31 = &v28->fValue;
                  goto LABEL_47;
                case 1:
                  v31 = &v28->fValue2.x;
                  goto LABEL_47;
                case 2:
                  ShaderVariable::set(v30, &v28->fValue3.x);
                  break;
                case 3:
                  v31 = &v28->fValue4.x;
                  goto LABEL_47;
                case 4:
                  v31 = &v28->mValue.M11;
LABEL_47:
                  ShaderVariable::set(v30, v31);
                  break;
                default:
                  break;
              }
              ++v26;
            }
            while ( v26 != v27 );
            v25 = j;
          }
        }
      }
      else
      {
        v13 = v2->semaphore._Myfirst;
        v14 = v13[1].groups._Mylast - v13[1].groups._Myfirst;
        v15 = v13[1].groups._Myfirst;
        v16 = v13[1].groups._Mylast;
        v36 = v15;
        v42 = v16;
        v34 = (float)(unsigned int)v14;
        for ( k = 4000.0 / v34; v15 != v16; v36 = v15 )
        {
          g.order = v15->order;
          std::vector<Mesh *>::vector<Mesh *>(
            (std::vector<TyreThermalPatch *> *)&g.vars,
            (const std::vector<TyreThermalPatch *> *)&v15->vars);
          v45 = 2;
          v17 = StartingTrackSemaphore::getTimeToSessionStart(v2);
          v18 = g.vars._Myfirst;
          v37 = v17 - 3000.0;
          if ( (float)(k * v34) > v37 )
          {
            v19 = (unsigned int)((char *)g.vars._Mylast - (char *)g.vars._Myfirst + 3) >> 2;
            if ( g.vars._Myfirst > g.vars._Mylast )
              v19 = 0;
            if ( v19 )
            {
              for ( l = 0; l != v19; ++l )
              {
                v21 = *v18;
                v22 = this->intensity;
                *(_QWORD *)&v21->fValue3.x = _mm_unpacklo_ps((__m128)LODWORD(v22), (__m128)LODWORD(v22)).m128_u64[0];
                v21->fValue3.z = v22;
                MaterialVar::set(v21);
                ++v18;
              }
              v18 = g.vars._Myfirst;
              v15 = v36;
              v16 = v42;
            }
            v2 = this;
          }
          v45 = -1;
          v34 = v34 - 1.0;
          if ( v18 )
          {
            std::_Container_base0::_Orphan_all(&g.vars);
            operator delete(g.vars._Myfirst);
            g.vars._Myfirst = 0;
            g.vars._Mylast = 0;
            g.vars._Myend = 0;
          }
          ++v15;
        }
      }
    }
  }
}
