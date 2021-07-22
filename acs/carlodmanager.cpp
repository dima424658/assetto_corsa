#include "carlodmanager.h
void CarLodManager::CarLodManager(CarLodManager *this, CarAvatar *car)
{
  int v3; // edi
  std::vector<CarLodDef> *v4; // esi
  Font *v5; // eax
  Font *v6; // eax
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  float v9; // ebp
  double v10; // st7
  bool v11; // cf
  double v12; // st7
  std::wostream *v13; // eax
  const std::wstring *v14; // eax
  bool v15; // bl
  const std::wstring *v16; // eax
  CarLodDef *v17; // edi
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  CarLodDef *v20; // ecx
  CarLodDef *v21; // ebx
  CarLodDef *v22; // edx
  unsigned int v23; // edi
  int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // edx
  int v27; // ebx
  const std::vector<TyreThermalPatch *> *v28; // edi
  CarLodDef *v29; // edx
  int v30; // ecx
  unsigned int v31; // edx
  unsigned int v32; // edx
  CarLodDef *v33; // ecx
  CarLodDef *v34; // edi
  CarLodDef *v35; // esi
  CarLodManager *i; // ebx
  Console *v37; // eax
  Event<SessionInfo> *v38; // ecx
  _BYTE v39[36]; // [esp-18h] [ebp-21Ch] BYREF
  float multiplier; // [esp+Ch] [ebp-1F8h]
  char v41; // [esp+2Fh] [ebp-1D5h]
  Font *v42; // [esp+30h] [ebp-1D4h]
  CarLodDef *v43; // [esp+34h] [ebp-1D0h]
  CarLodDef *v44; // [esp+38h] [ebp-1CCh]
  CarLodManager *v45; // [esp+3Ch] [ebp-1C8h]
  CarAvatar *v46; // [esp+40h] [ebp-1C4h]
  CarLodManager *v47; // [esp+44h] [ebp-1C0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > lod_name; // [esp+48h] [ebp-1BCh] BYREF
  std::wstring key; // [esp+F8h] [ebp-10Ch] BYREF
  std::wstring section; // [esp+110h] [ebp-F4h] BYREF
  std::wstring v51; // [esp+128h] [ebp-DCh] BYREF
  CarLodDef ld; // [esp+140h] [ebp-C4h] BYREF
  std::wstring v53; // [esp+180h] [ebp-84h] BYREF
  std::wstring result; // [esp+198h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+1B0h] [ebp-54h] BYREF
  int v56; // [esp+200h] [ebp-4h]

  v45 = this;
  v3 = 0;
  v42 = 0;
  v47 = this;
  v46 = car;
  multiplier = *(float *)&car->game;
  *(_DWORD *)&v39[32] = 7;
  *(_DWORD *)&v39[28] = 0;
  *(_WORD *)&v39[12] = 0;
  std::wstring::assign((std::wstring *)&v39[12], L"CAR_LOD_MANAGER", 0xFu);
  GameObject::GameObject(this, *(std::wstring *)&v39[12], (Game *)LODWORD(multiplier));
  v4 = &this->lods;
  this->__vftable = (CarLodManager_vtbl *)&CarLodManager::`vftable';
  v56 = 0;
  this->lods._Myfirst = 0;
  this->lods._Mylast = 0;
  this->lods._Myend = 0;
  this->car = car;
  this->proViewNodes._Myfirst = 0;
  this->proViewNodes._Mylast = 0;
  this->proViewNodes._Myend = 0;
  LOBYTE(v56) = 2;
  v5 = (Font *)operator new(24);
  v42 = v5;
  LOBYTE(v56) = 3;
  if ( v5 )
    Font::Font(v5, eFontMonospaced, 24.0, 0, 0);
  else
    v6 = 0;
  this->font = v6;
  LODWORD(multiplier) = &car->unixName;
  LOBYTE(v56) = 2;
  *(_DWORD *)&v39[32] = L"content/cars/";
  *(_DWORD *)&v39[28] = &result;
  this->debugMode = 0.0;
  this->currentLod = 0;
  v7 = std::operator+<wchar_t>(
         *(std::wstring **)&v39[28],
         *(const wchar_t **)&v39[32],
         (const std::wstring *)LODWORD(multiplier));
  LOBYTE(v56) = 4;
  v8 = std::operator+<wchar_t>(&v53, v7, L"/data/lods.ini");
  LOBYTE(v56) = 5;
  CarAvatar::openINI(car, &ini, v8);
  if ( v53._Myres >= 8 )
    operator delete(v53._Bx._Ptr);
  v53._Myres = 7;
  v53._Mysize = 0;
  v53._Bx._Buf[0] = 0;
  LOBYTE(v56) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  v9 = 0.0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v43 = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DISTANCE_SWITCH", 0xFu);
  LOBYTE(v56) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"COCKPIT_HR", 0xAu);
  LOBYTE(v56) = 10;
  v10 = INIReader::getFloat(&ini, &section, &key);
  v11 = section._Myres < 8;
  this->cockpitHRDistance = v10;
  if ( !v11 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v56) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->cockpitHRDistance == 0.0 )
    this->cockpitHRDistance = 2.0;
  LODWORD(multiplier) = 15;
  this->driverHRDistance = 15.0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DISTANCE_SWITCH", LODWORD(multiplier));
  LOBYTE(v56) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DRIVER_HR", 9u);
  LOBYTE(v56) = 12;
  v41 = INIReader::hasKey(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v56) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v41 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE_SWITCH", 0xFu);
    LOBYTE(v56) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DRIVER_HR", 9u);
    LOBYTE(v56) = 14;
    v12 = INIReader::getFloat(&ini, &section, &key);
    v11 = section._Myres < 8;
    this->driverHRDistance = v12;
    if ( !v11 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v56) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  while ( 1 )
  {
    *(_DWORD *)lod_name.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)lod_name.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(lod_name.gap68);
    LOBYTE(v56) = 15;
    v42 = (Font *)(v3 | 1);
    std::wiostream::basic_iostream<wchar_t>(&lod_name, &lod_name.gap10[8], 0);
    v56 = 16;
    *(_DWORD *)&lod_name.gap0[*(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(CarLodManager **)((char *)&v47 + *(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4)) = (CarLodManager *)(*(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4) - 104);
    std::wstreambuf::wstreambuf(&lod_name.gap10[8]);
    *(_DWORD *)&lod_name.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&lod_name.gap10[64] = 0;
    *(_DWORD *)&lod_name.gap10[68] = 0;
    multiplier = v9;
    LOBYTE(v56) = 18;
    v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)lod_name.gap10, "LOD_");
    std::wostream::operator<<(v13, LODWORD(multiplier));
    v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&lod_name, &v51);
    LOBYTE(v56) = 19;
    v15 = INIReader::hasSection(&ini, v14);
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    if ( !v15 )
      break;
    ld.filename._Myres = 7;
    ld.filename._Mysize = 0;
    ld.filename._Bx._Buf[0] = 0;
    ld.nodes._Myfirst = 0;
    ld.nodes._Mylast = 0;
    ld.nodes._Myend = 0;
    ld.in = 0.0;
    ld.out = 10000.0;
    ld.index = 0;
    *(_OWORD *)&ld.cockpitHR = 0i64;
    LOBYTE(v56) = 20;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FILE", 4u);
    LOBYTE(v56) = 21;
    v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&lod_name, &v51);
    LOBYTE(v56) = 22;
    v17 = (CarLodDef *)INIReader::getString(&ini, &section, v16, &key);
    if ( &ld != v17 )
    {
      if ( ld.filename._Myres >= 8 )
        operator delete(ld.filename._Bx._Ptr);
      ld.filename._Myres = 7;
      ld.filename._Mysize = 0;
      ld.filename._Bx._Buf[0] = 0;
      if ( v17->filename._Myres >= 8 )
      {
        ld.filename._Bx._Ptr = v17->filename._Bx._Ptr;
        v17->filename._Bx._Ptr = 0;
      }
      else if ( v17->filename._Mysize != -1 )
      {
        _memmove(&ld, v17, 2 * (v17->filename._Mysize + 1));
      }
      ld.filename._Mysize = v17->filename._Mysize;
      ld.filename._Myres = v17->filename._Myres;
      v17->filename._Myres = 7;
      v17->filename._Mysize = 0;
      v17->filename._Bx._Buf[0] = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    LOBYTE(v56) = 20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"IN", 2u);
    LOBYTE(v56) = 23;
    v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&lod_name, &v51);
    LOBYTE(v56) = 24;
    ld.in = INIReader::getFloat(&ini, v18, &key);
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    LOBYTE(v56) = 20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OUT", 3u);
    LOBYTE(v56) = 25;
    v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&lod_name, &v51);
    LOBYTE(v56) = 26;
    ld.out = INIReader::getFloat(&ini, v19, &key);
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    LOBYTE(v56) = 20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v20 = v4->_Mylast;
    *(float *)&ld.index = v9;
    if ( &ld >= v20 || (v21 = v4->_Myfirst, v4->_Myfirst > &ld) )
    {
      v29 = v4->_Myend;
      if ( v20 == v29 && !(v29 - v20) )
      {
        v30 = v20 - v4->_Myfirst;
        if ( v30 == 0x3FFFFFF )
LABEL_73:
          std::_Xlength_error("vector<T> too long");
        v31 = v29 - v4->_Myfirst;
        if ( 0x3FFFFFF - (v31 >> 1) >= v31 )
          v32 = (v31 >> 1) + v31;
        else
          v32 = 0;
        if ( v32 < v30 + 1 )
          v32 = v30 + 1;
        std::vector<CarLodDef>::_Reallocate(v4, v32);
      }
      v33 = v4->_Mylast;
      v44 = v33;
      v43 = v33;
      LOBYTE(v56) = 29;
      if ( v33 )
        CarLodDef::CarLodDef(v33, &ld);
    }
    else
    {
      v22 = v4->_Myend;
      v23 = (char *)&ld - (char *)v21;
      if ( v20 == v22 && !(v22 - v20) )
      {
        v24 = v20 - v21;
        if ( v24 == 0x3FFFFFF )
          goto LABEL_73;
        v25 = v22 - v21;
        if ( 0x3FFFFFF - (v25 >> 1) >= v25 )
          v26 = (v25 >> 1) + v25;
        else
          v26 = 0;
        if ( v26 < v24 + 1 )
          v26 = v24 + 1;
        std::vector<CarLodDef>::_Reallocate(v4, v26);
        v9 = *(float *)&v43;
      }
      v27 = (int)v4->_Mylast;
      v28 = (const std::vector<TyreThermalPatch *> *)((char *)v4->_Myfirst + (v23 & 0xFFFFFFC0));
      v43 = (CarLodDef *)v27;
      v44 = (CarLodDef *)v27;
      LOBYTE(v56) = 27;
      if ( v27 )
      {
        *(_DWORD *)(v27 + 20) = 7;
        multiplier = NAN;
        *(_DWORD *)&v39[32] = 0;
        *(_DWORD *)(v27 + 16) = 0;
        *(_DWORD *)&v39[28] = v28;
        *(_WORD *)v27 = 0;
        std::wstring::assign(
          (std::wstring *)v27,
          *(const std::wstring **)&v39[28],
          *(unsigned int *)&v39[32],
          LODWORD(multiplier));
        *(_DWORD *)(v27 + 24) = v28[2]._Myfirst;
        *(_DWORD *)(v27 + 28) = v28[2]._Mylast;
        *(_DWORD *)(v27 + 32) = v28[2]._Myend;
        LOBYTE(v56) = 28;
        std::vector<Mesh *>::vector<Mesh *>((std::vector<TyreThermalPatch *> *)(v27 + 36), v28 + 3);
        *(_DWORD *)(v27 + 48) = v28[4]._Myfirst;
        *(_DWORD *)(v27 + 52) = v28[4]._Mylast;
        *(_DWORD *)(v27 + 56) = v28[4]._Myend;
        *(_DWORD *)(v27 + 60) = v28[5]._Myfirst;
      }
    }
    ++v4->_Mylast;
    CarLodDef::~CarLodDef(&ld);
    v43 = (CarLodDef *)++LODWORD(v9);
    LOBYTE(v56) = 8;
    *(_DWORD *)&lod_name.gap0[*(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(CarLodManager **)((char *)&v47 + *(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4)) = (CarLodManager *)(*(_DWORD *)(*(_DWORD *)lod_name.gap0 + 4) - 104);
    *(_DWORD *)&lod_name.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&lod_name.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&lod_name.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&lod_name.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(lod_name.gap68);
    v3 = (int)v42;
  }
  LOBYTE(v56) = 8;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&lod_name);
  v34 = v4->_Mylast;
  v35 = v4->_Myfirst;
  for ( i = v45; v35 != v34; ++v35 )
    CarLodManager::loadLod(i, v35);
  if ( !CarAvatar::getGuid(v46) )
  {
    multiplier = 1.0;
    *(_DWORD *)&v39[32] = 0;
    *(_DWORD *)&v39[28] = 0;
    *(_DWORD *)&v39[24] = &i->debugMode;
    v44 = (CarLodDef *)v39;
    std::wstring::wstring((std::wstring *)v39, L"lodDebug");
    LOBYTE(v56) = 30;
    v37 = Console::singleton();
    LOBYTE(v56) = 8;
    Console::addVar(v37, *(std::wstring *)v39, *(float **)&v39[24], *(IVarCallback **)&v39[28], v39[32], multiplier);
  }
  LODWORD(multiplier) = i;
  *(_DWORD *)&v39[12] = &std::_Func_impl<std::_Callable_obj<_lambda_ac02608daa2391f10995d2b317287be5_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v39[16] = i;
  *(_DWORD *)&v39[28] = &v39[12];
  v38 = (Event<SessionInfo> *)&i->game->evOnPostUpdate;
  LOBYTE(v56) = 8;
  Event<float>::addHandler(v38, *(std::function<void __cdecl(SessionInfo const &)> *)&v39[12], i);
  LOBYTE(v56) = 2;
  INIReader::~INIReader(&ini);
}
void CarLodManager::~CarLodManager(CarLodManager *this)
{
  Font *v2; // edi

  this->__vftable = (CarLodManager_vtbl *)&CarLodManager::`vftable';
  v2 = this->font;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v2);
    operator delete(v2);
  }
  if ( this->proViewNodes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->proViewNodes);
    operator delete(this->proViewNodes._Myfirst);
    this->proViewNodes._Myfirst = 0;
    this->proViewNodes._Mylast = 0;
    this->proViewNodes._Myend = 0;
  }
  if ( this->lods._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lods);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<CarLodDef>>>(this->lods._Myfirst, this->lods._Mylast);
    operator delete(this->lods._Myfirst);
    this->lods._Myfirst = 0;
    this->lods._Mylast = 0;
    this->lods._Myend = 0;
  }
  GameObject::~GameObject(this);
}
CarLodManager *CarLodManager::`vector deleting destructor'(CarLodManager *this, unsigned int a2)
{
  CarLodManager::~CarLodManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarLodManager::initNoBodyNodes(CarLodManager *this)
{
  CarLodDef *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  CarAvatar *v5; // eax
  std::wstring *v6; // eax
  _FILETIME v7; // rdi
  CarLodDef *v8; // eax
  int v9; // edi
  Node *v10; // eax
  Node **v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // ebp
  std::vector<Node *> *v14; // ebx
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  bool v17; // cf
  std::wostream *v18; // eax
  int v19; // edi
  Node *v20; // eax
  Node **v21; // esi
  Node **v22; // eax
  unsigned int v23; // ebp
  std::vector<Node *> *v24; // ebx
  CarLodDef *v25; // [esp-1Ch] [ebp-1A4h]
  std::wofstream out; // [esp+14h] [ebp-174h] BYREF
  std::wstring v27; // [esp+BCh] [ebp-CCh] BYREF
  std::wstring result; // [esp+D4h] [ebp-B4h] BYREF
  std::wstring iniPath; // [esp+ECh] [ebp-9Ch] BYREF
  std::wstring v30; // [esp+104h] [ebp-84h] BYREF
  std::wstring mainLodPath; // [esp+11Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+134h] [ebp-54h] BYREF
  int v33; // [esp+184h] [ebp-4h]

  v2 = this->lods._Myfirst;
  if ( v2 != this->lods._Mylast && v2->nodes._Myfirst != this->lods._Myfirst->nodes._Mylast )
  {
    v3 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
    v33 = 0;
    v4 = std::operator+<wchar_t>(&v27, v3, L"/");
    v25 = this->lods._Myfirst;
    LOBYTE(v33) = 1;
    std::operator+<wchar_t>(&mainLodPath, v4, &v25->filename);
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    LOBYTE(v33) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    v5 = this->car;
    result._Mysize = 0;
    v6 = std::operator+<wchar_t>(&v30, L"content/cars/", &v5->unixName);
    LOBYTE(v33) = 5;
    std::operator+<wchar_t>(&iniPath, v6, L"/data/proview_nodes.ini");
    LOBYTE(v33) = 7;
    if ( v30._Myres >= 8 )
      operator delete(v30._Bx._Ptr);
    v30._Myres = 7;
    v30._Bx._Buf[0] = 0;
    v30._Mysize = 0;
    if ( Path::fileExists((unsigned int)this, &iniPath, 0)
      && (v7 = Path::getLastModificationTime(&iniPath),
          *(_QWORD *)&v7 > *(unsigned __int64 *)&Path::getLastModificationTime(&mainLodPath)) )
    {
      CarAvatar::openINI(this->car, &ini, &iniPath);
      v8 = this->lods._Myfirst;
      v9 = 0;
      LOBYTE(v33) = 8;
      v10 = *v8->nodes._Myfirst;
      v11 = v10->nodes._Myfirst;
      v12 = (unsigned int)v10->nodes._Mylast;
      v13 = (v12 - (unsigned int)v11 + 3) >> 2;
      if ( (unsigned int)v11 > v12 )
        v13 = 0;
      if ( v13 )
      {
        v14 = &this->proViewNodes;
        do
        {
          loadNode(&ini, v14, *v11, 0);
          ++v9;
          ++v11;
        }
        while ( v9 != v13 );
      }
      LOBYTE(v33) = 7;
      INIReader::~INIReader(&ini);
    }
    else
    {
      _printf("CREATING proview_nodes.ini\n");
      v15 = std::operator+<wchar_t>(&v27, L"content/cars/", &this->car->unixName);
      LOBYTE(v33) = 9;
      v16 = std::operator+<wchar_t>(&result, v15, L"/data/proview_nodes.ini");
      v17 = v16->_Myres < 8;
      LOBYTE(v33) = 10;
      if ( !v17 )
        v16 = (std::wstring *)v16->_Bx._Ptr;
      std::wofstream::wofstream(&out, v16->_Bx._Buf, 2, 64, 1);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v33) = 13;
      if ( v27._Myres >= 8 )
        operator delete(v27._Bx._Ptr);
      v27._Myres = 7;
      v27._Bx._Buf[0] = 0;
      v27._Mysize = 0;
      v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "[NODES]");
      std::wostream::operator<<(v18);
      v19 = 0;
      v20 = *this->lods._Myfirst->nodes._Myfirst;
      v21 = v20->nodes._Myfirst;
      v22 = v20->nodes._Mylast;
      v23 = (unsigned int)((char *)v22 - (char *)v21 + 3) >> 2;
      if ( v21 > v22 )
        v23 = 0;
      if ( v23 )
      {
        v24 = &this->proViewNodes;
        do
        {
          writeNode(&out, v24, *v21, 0);
          ++v19;
          ++v21;
        }
        while ( v19 != v23 );
      }
      std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&out.gap58[8]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
    }
    if ( iniPath._Myres >= 8 )
      operator delete(iniPath._Bx._Ptr);
    iniPath._Myres = 7;
    iniPath._Mysize = 0;
    iniPath._Bx._Buf[0] = 0;
    if ( mainLodPath._Myres >= 8 )
      operator delete(mainLodPath._Bx._Ptr);
  }
}
void CarLodManager::loadLod(CarLodManager *this, CarLodDef *lod)
{
  CarAvatar *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  Game *v6; // eax
  CarAvatar *v7; // ecx
  std::wstring *v8; // esi
  CarAvatar *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  Node *v13; // eax
  Game *v14; // ecx
  std::vector<Node *> *v15; // edi
  Node *v16; // ebx
  CarAvatar *v17; // eax
  std::wstring *v18; // eax
  const std::wstring *v19; // eax
  CarAvatar *v20; // ecx
  int i; // ebp
  Node *v22; // esi
  Node **v23; // ecx
  int v24; // esi
  Node **v25; // ecx
  Node **v26; // eax
  Node *v27; // esi
  Node **v28; // ecx
  int v29; // esi
  Node **v30; // ecx
  Node **v31; // eax
  Node *v32; // esi
  Node **v33; // ecx
  int v34; // esi
  Node **v35; // ecx
  Node **v36; // eax
  Node_vtbl *v37; // eax
  Node *v38; // esi
  Node **v39; // eax
  int v40; // esi
  Node **v41; // ecx
  Node **v42; // eax
  CarLodManager *v43; // esi
  Node_vtbl *v44; // eax
  int v45; // ebp
  const __m128i *v46; // eax
  Node *v47; // ecx
  const __m128i *v48; // eax
  CarAvatar *v49; // ecx
  float *v50; // esi
  Node **v51; // ecx
  int v52; // esi
  Node **v53; // ecx
  Node **v54; // eax
  Console *v55; // eax
  Console *v56; // eax
  Console *v57; // eax
  Node_vtbl *v58; // eax
  int v59; // ebp
  float *v60; // esi
  Node **v61; // ecx
  int v62; // esi
  Node **v63; // ecx
  Node **v64; // eax
  Node_vtbl *v65; // eax
  int v66; // eax
  bool v67; // cf
  CarLodDef *v68; // ebp
  Node_vtbl *v69; // eax
  int v70; // eax
  std::wstring v71; // [esp+10h] [ebp-260h] BYREF
  std::wstring v72; // [esp+28h] [ebp-248h] BYREF
  std::wstring v73; // [esp+40h] [ebp-230h] BYREF
  CarLodDef *v74; // [esp+6Ch] [ebp-204h]
  CarLodManager *v75; // [esp+70h] [ebp-200h]
  Node *steer_obj; // [esp+74h] [ebp-1FCh] BYREF
  Node *raxle; // [esp+78h] [ebp-1F8h] BYREF
  int v78; // [esp+7Ch] [ebp-1F4h] BYREF
  Node *disc_node; // [esp+80h] [ebp-1F0h] BYREF
  Node *modelLink; // [esp+84h] [ebp-1ECh] BYREF
  Node *wheel_node; // [esp+88h] [ebp-1E8h] BYREF
  Node *sus_node[3]; // [esp+8Ch] [ebp-1E4h] BYREF
  char v83[64]; // [esp+98h] [ebp-1D8h] BYREF
  std::wstring v84; // [esp+D8h] [ebp-198h] BYREF
  std::wstring v85; // [esp+F0h] [ebp-180h] BYREF
  std::wstring v86; // [esp+108h] [ebp-168h] BYREF
  std::wstring s; // [esp+120h] [ebp-150h] BYREF
  std::wstring _Left; // [esp+138h] [ebp-138h] BYREF
  std::wstring result; // [esp+150h] [ebp-120h] BYREF
  std::wstring v90; // [esp+168h] [ebp-108h] BYREF
  std::wstring filename; // [esp+180h] [ebp-F0h] BYREF
  std::wstring v92; // [esp+198h] [ebp-D8h] BYREF
  KN5IO kn; // [esp+1B0h] [ebp-C0h] BYREF
  INIReader sus_ini; // [esp+21Ch] [ebp-54h] BYREF
  int v95; // [esp+26Ch] [ebp-4h]

  v75 = this;
  v74 = lod;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v3 = this->car;
  v95 = 0;
  v4 = std::operator+<wchar_t>(&result, &_Left, &v3->unixName);
  LOBYTE(v95) = 1;
  v5 = std::operator+<wchar_t>(&v90, v4, L"/");
  LOBYTE(v95) = 2;
  std::operator+<wchar_t>(&filename, v5, &lod->filename);
  if ( v90._Myres >= 8 )
    operator delete(v90._Bx._Ptr);
  v90._Myres = 7;
  v90._Mysize = 0;
  v90._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v95) = 6;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  v6 = this->game;
  _Left._Mysize = 0;
  KN5IO::KN5IO(&kn, v6->graphics);
  v7 = this->car;
  LOBYTE(v95) = 7;
  v8 = CarAvatar::getCurrentSkin(v7, &v92);
  LOBYTE(v95) = 8;
  v85._Myres = 7;
  v85._Mysize = 0;
  v85._Bx._Buf[0] = 0;
  std::wstring::assign(&v85, L"content/cars/", 0xDu);
  v9 = this->car;
  LOBYTE(v95) = 9;
  v10 = std::operator+<wchar_t>(&s, &v85, &v9->unixName);
  LOBYTE(v95) = 10;
  v11 = std::operator+<wchar_t>(&v86, v10, L"/skins/");
  LOBYTE(v95) = 11;
  v12 = std::operator+<wchar_t>(&v84, v11, v8);
  LOBYTE(v95) = 12;
  KN5IO::addTextureFolder(&kn, v12);
  if ( v84._Myres >= 8 )
    operator delete(v84._Bx._Ptr);
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  if ( v86._Myres >= 8 )
    operator delete(v86._Bx._Ptr);
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( v85._Myres >= 8 )
    operator delete(v85._Bx._Ptr);
  v85._Myres = 7;
  v85._Mysize = 0;
  v85._Bx._Buf[0] = 0;
  LOBYTE(v95) = 7;
  if ( v92._Myres >= 8 )
    operator delete(v92._Bx._Ptr);
  v13 = KN5IO::load(&kn, &filename);
  v14 = this->game;
  modelLink = v13;
  GraphicsManager::compile(v14->graphics, v13);
  v15 = &lod->nodes;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&lod->nodes,
    (ICollisionObject *const *)&modelLink);
  v16 = modelLink;
  this->car->bodyTransform->addChild(this->car->bodyTransform, modelLink);
  v85._Myres = 7;
  v85._Mysize = 0;
  v85._Bx._Buf[0] = 0;
  std::wstring::assign(&v85, L"content/cars/", 0xDu);
  v17 = this->car;
  LOBYTE(v95) = 13;
  v18 = std::operator+<wchar_t>(&v86, &v85, &v17->unixName);
  LOBYTE(v95) = 14;
  v19 = std::operator+<wchar_t>(&s, v18, L"/data/suspensions.ini");
  v20 = this->car;
  LOBYTE(v95) = 15;
  CarAvatar::openINI(v20, &sus_ini, v19);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( v86._Myres >= 8 )
    operator delete(v86._Bx._Ptr);
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  LOBYTE(v95) = 19;
  if ( v85._Myres >= 8 )
    operator delete(v85._Bx._Ptr);
  v85._Myres = 7;
  v85._Bx._Buf[0] = 0;
  v85._Mysize = 0;
  _printf("INIT LOD:%d\n", v74->index);
  for ( i = 0; i < 4; ++i )
  {
    v22 = v16->findChildByName(v16, &wheelNames[i], 1);
    wheel_node = v22;
    if ( v22 )
    {
      v23 = lod->nodes._Mylast;
      if ( &wheel_node >= v23 || v15->_Myfirst > &wheel_node )
      {
        if ( v23 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v26 = lod->nodes._Mylast;
        if ( v26 )
          *v26 = v22;
      }
      else
      {
        v24 = &wheel_node - v15->_Myfirst;
        if ( v23 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v25 = lod->nodes._Mylast;
        if ( v25 )
          *v25 = v15->_Myfirst[v24];
      }
      ++lod->nodes._Mylast;
    }
    v27 = v16->findChildByName(v16, &susNames[i], 1);
    sus_node[0] = v27;
    if ( v27 )
    {
      v28 = lod->nodes._Mylast;
      if ( sus_node >= v28 || v15->_Myfirst > sus_node )
      {
        if ( v28 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v31 = lod->nodes._Mylast;
        if ( v31 )
          *v31 = v27;
      }
      else
      {
        v29 = sus_node - v15->_Myfirst;
        if ( v28 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v30 = lod->nodes._Mylast;
        if ( v30 )
          *v30 = v15->_Myfirst[v29];
      }
      ++lod->nodes._Mylast;
    }
    v32 = v16->findChildByName(v16, &discNames[i], 1);
    disc_node = v32;
    if ( v32 )
    {
      v33 = lod->nodes._Mylast;
      if ( &disc_node >= v33 || v15->_Myfirst > &disc_node )
      {
        if ( v33 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v36 = lod->nodes._Mylast;
        if ( v36 )
          *v36 = v32;
      }
      else
      {
        v34 = &disc_node - v15->_Myfirst;
        if ( v33 == lod->nodes._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
        v35 = lod->nodes._Mylast;
        if ( v35 )
          *v35 = v15->_Myfirst[v34];
      }
      ++lod->nodes._Mylast;
    }
  }
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"REAR_AXLE", 9u);
  v37 = v16->__vftable;
  LOBYTE(v95) = 20;
  v38 = v37->findChildByName(v16, &v84, 1);
  raxle = v38;
  LOBYTE(v95) = 19;
  if ( v84._Myres >= 8 )
    operator delete(v84._Bx._Ptr);
  if ( v38 )
  {
    v39 = lod->nodes._Mylast;
    if ( &raxle >= v39 || v15->_Myfirst > &raxle )
    {
      if ( v39 == lod->nodes._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
      v42 = lod->nodes._Mylast;
      if ( v42 )
        *v42 = v38;
    }
    else
    {
      v40 = &raxle - v15->_Myfirst;
      if ( v39 == lod->nodes._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
      v41 = lod->nodes._Mylast;
      if ( v41 )
        *v41 = v15->_Myfirst[v40];
    }
    ++lod->nodes._Mylast;
  }
  v43 = v75;
  if ( !v74->index )
  {
    CarLodManager::initNoBodyNodes(v75);
    if ( !v74->index )
    {
      v84._Myres = 7;
      v84._Mysize = 0;
      v84._Bx._Buf[0] = 0;
      std::wstring::assign(&v84, L"STEER_HR", 8u);
      v44 = v16->__vftable;
      LOBYTE(v95) = 21;
      v45 = (int)v44->findChildByName(v16, &v84, 1);
      v78 = v45;
      LOBYTE(v95) = 19;
      if ( v84._Myres >= 8 )
        operator delete(v84._Bx._Ptr);
      if ( v45 )
      {
        v46 = (const __m128i *)(*(int (**)(int, char *))(*(_DWORD *)v45 + 32))(v45, v83);
        v47 = v75->car->steerTransformHR;
        *(__m128i *)&v47->matrix.M11 = _mm_loadu_si128(v46);
        *(__m128i *)&v47->matrix.M21 = _mm_loadu_si128(v46 + 1);
        *(__m128i *)&v47->matrix.M31 = _mm_loadu_si128(v46 + 2);
        *(__m128i *)&v47->matrix.M41 = _mm_loadu_si128(v46 + 3);
        v48 = (const __m128i *)(*(int (**)(int, char *))(*(_DWORD *)v45 + 32))(v45, v83);
        v49 = v43->car;
        *(__m128i *)&v49->orgSteerMatrix.M11 = _mm_loadu_si128(v48);
        *(__m128i *)&v49->orgSteerMatrix.M21 = _mm_loadu_si128(v48 + 1);
        *(__m128i *)&v49->orgSteerMatrix.M31 = _mm_loadu_si128(v48 + 2);
        *(__m128i *)&v49->orgSteerMatrix.M41 = _mm_loadu_si128(v48 + 3);
        v50 = &v43->car->orgSteerMatrix.M11;
        _printf("|%f %f %f %f|\n", *v50, v50[4], v50[8], v50[12]);
        _printf("|%f %f %f %f|\n", v50[1], v50[5], v50[9], v50[13]);
        _printf("|%f %f %f %f|\n", v50[2], v50[6], v50[10], v50[14]);
        _printf("|%f %f %f %f|\n", v50[3], v50[7], v50[11], v50[15]);
        mat44f::loadIdentity((mat44f *)(v45 + 4));
        v51 = lod->nodes._Mylast;
        if ( &v78 >= (int *)v51 || v15->_Myfirst > (Node **)&v78 )
        {
          if ( v51 == lod->nodes._Myend )
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
          v54 = lod->nodes._Mylast;
          if ( v54 )
            *v54 = (Node *)v45;
        }
        else
        {
          v52 = ((char *)&v78 - (char *)v15->_Myfirst) >> 2;
          if ( v51 == lod->nodes._Myend )
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
          v53 = lod->nodes._Mylast;
          if ( v53 )
            *v53 = v15->_Myfirst[v52];
        }
        v43 = v75;
        ++lod->nodes._Mylast;
        v43->car->steerTransformHR->addChild(v43->car->steerTransformHR, (Node *)v45);
        v74->steerHR = (Node *)v45;
      }
      else
      {
        modelLink = (Node *)&v73;
        v73._Myres = 7;
        v73._Mysize = 0;
        v73._Bx._Buf[0] = 0;
        std::wstring::assign(&v73, L"\n", 1u);
        LOBYTE(v95) = 22;
        sus_node[1] = (Node *)&v72;
        *(_QWORD *)&v72._Mysize = 0x700000000i64;
        v72._Bx._Buf[0] = 0;
        std::wstring::assign(&v72, &filename, 0, 0xFFFFFFFF);
        LOBYTE(v95) = 23;
        sus_node[2] = (Node *)&v71;
        v71._Myres = 7;
        v71._Mysize = 0;
        v71._Bx._Buf[0] = 0;
        std::wstring::assign(&v71, L"ERROR: CANNOT FIND STEER_HR IN FILE: ", 0x25u);
        LOBYTE(v95) = 24;
        v55 = Console::singleton();
        LOBYTE(v95) = 23;
        v56 = Console::operator<<(v55, v71);
        LOBYTE(v95) = 22;
        v57 = Console::operator<<(v56, v72);
        LOBYTE(v95) = 19;
        Console::operator<<(v57, v73);
      }
    }
  }
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"STEER_LR", 8u);
  v58 = v16->__vftable;
  LOBYTE(v95) = 25;
  v59 = (int)v58->findChildByName(v16, &v84, 1);
  steer_obj = (Node *)v59;
  LOBYTE(v95) = 19;
  if ( v84._Myres >= 8 )
    operator delete(v84._Bx._Ptr);
  if ( v59 )
  {
    v60 = (float *)(*(int (**)(int, char *))(*(_DWORD *)v59 + 32))(v59, v83);
    _printf("|%f %f %f %f|\n", *v60, v60[4], v60[8], v60[12]);
    _printf("|%f %f %f %f|\n", v60[1], v60[5], v60[9], v60[13]);
    _printf("|%f %f %f %f|\n", v60[2], v60[6], v60[10], v60[14]);
    _printf("|%f %f %f %f|\n", v60[3], v60[7], v60[11], v60[15]);
    *(_DWORD *)(v59 + 4) = 1065353216;
    *(_DWORD *)(v59 + 8) = 0;
    *(_DWORD *)(v59 + 12) = 0;
    *(_DWORD *)(v59 + 16) = 0;
    *(_DWORD *)(v59 + 20) = 0;
    *(_DWORD *)(v59 + 24) = 1065353216;
    *(_DWORD *)(v59 + 28) = 0;
    *(_DWORD *)(v59 + 32) = 0;
    *(_DWORD *)(v59 + 36) = 0;
    *(_DWORD *)(v59 + 40) = 0;
    *(_DWORD *)(v59 + 44) = 1065353216;
    *(_DWORD *)(v59 + 48) = 0;
    *(_DWORD *)(v59 + 52) = 0;
    *(_DWORD *)(v59 + 56) = 0;
    *(_DWORD *)(v59 + 60) = 0;
    *(_DWORD *)(v59 + 64) = 1065353216;
    v61 = lod->nodes._Mylast;
    if ( &steer_obj >= v61 || v15->_Myfirst > &steer_obj )
    {
      if ( v61 == lod->nodes._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
      v64 = lod->nodes._Mylast;
      if ( v64 )
        *v64 = (Node *)v59;
    }
    else
    {
      v62 = &steer_obj - v15->_Myfirst;
      if ( v61 == lod->nodes._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)v15, 1u);
      v63 = lod->nodes._Mylast;
      if ( v63 )
        *v63 = v15->_Myfirst[v62];
    }
    v43 = v75;
    ++lod->nodes._Mylast;
    v43->car->steerTransformHR->addChild(v43->car->steerTransformHR, (Node *)v59);
    v74->steerLR = (Node *)v59;
  }
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"COCKPIT_HR", 0xAu);
  v65 = v16->__vftable;
  LOBYTE(v95) = 26;
  v66 = (int)v65->findChildByName(v16, &v84, 1);
  v67 = v84._Myres < 8;
  v68 = v74;
  LOBYTE(v95) = 19;
  v74->cockpitHR = (Node *)v66;
  if ( !v67 )
    operator delete(v84._Bx._Ptr);
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"COCKPIT_LR", 0xAu);
  v69 = v16->__vftable;
  LOBYTE(v95) = 27;
  v70 = (int)v69->findChildByName(v16, &v84, 1);
  v67 = v84._Myres < 8;
  v68->cockpitLR = (Node *)v70;
  LOBYTE(v95) = 19;
  if ( !v67 )
    operator delete(v84._Bx._Ptr);
  ConstrainedObjectsManager::addModel(v43->car->constrainedObjectManager, v16);
  v43->car->suspensionAvatar->addModel(v43->car->suspensionAvatar, v16);
  LOBYTE(v95) = 7;
  INIReader::~INIReader(&sus_ini);
  LOBYTE(v95) = 6;
  KN5IO::~KN5IO(&kn);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void CarLodManager::renderHUD(CarLodManager *this, float deltaT)
{
  CameraForward *v3; // eax
  CameraForward *v4; // edi
  CarAvatar *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  Font *v17; // ecx
  std::wstring *v18; // eax
  Font *v19; // ecx
  Game *v20; // eax
  int y; // [esp+18h] [ebp-128h]
  const char *ya; // [esp+18h] [ebp-128h]
  const std::wstring *v23; // [esp+1Ch] [ebp-124h]
  std::wstring *ascale; // [esp+20h] [ebp-120h]
  vec4f cc; // [esp+3Ch] [ebp-104h] BYREF
  float v26; // [esp+4Ch] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v27; // [esp+50h] [ebp-F0h] BYREF
  std::wstring v28; // [esp+100h] [ebp-40h] BYREF
  int v29; // [esp+118h] [ebp-28h]
  std::wstring result; // [esp+124h] [ebp-1Ch] BYREF
  int v31; // [esp+13Ch] [ebp-4h]

  v26 = 0.0;
  if ( this->debugMode != 0.0 )
  {
    v3 = Sim::getSceneCamera(this->car->sim);
    *(_DWORD *)v27.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    v4 = v3;
    *(_DWORD *)v27.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v27.gap68);
    LODWORD(v27._Chcount) = 1;
    std::wiostream::basic_iostream<wchar_t>((char *)&v27._Chcount + 4, &v27.gap10[20], 0);
    *(_DWORD *)((char *)&v27._Chcount + *(_DWORD *)(HIDWORD(v27._Chcount) + 4) + 4) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v27._Chcount + *(_DWORD *)(HIDWORD(v27._Chcount) + 4)) = *(_DWORD *)(HIDWORD(v27._Chcount) + 4)
                                                                                - 104;
    std::wstreambuf::wstreambuf(&v27.gap10[20]);
    *(_DWORD *)&v27.gap10[20] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v27.gap10[76] = 0;
    *(_DWORD *)v27.gap60 = 0;
    v5 = this->car;
    v6 = v5->bodyMatrix.M42;
    v7 = v5->bodyMatrix.M43;
    cc.w = v5->bodyMatrix.M41;
    v26 = v6;
    *(float *)v27.gap0 = v7;
    vec3f::toString((vec3f *)&cc.w, &result);
    v8 = v4->matrix.M42;
    v9 = v4->matrix.M43;
    cc.w = v4->matrix.M41;
    v26 = v8;
    *(float *)v27.gap0 = v9;
    ascale = vec3f::toString((vec3f *)&cc.w, (std::wstring *)&v28._Bx._Alias[12]);
    y = this->currentLod;
    v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
            (std::wostream *)&v27.gap10[12],
            &stru_893418._Bx._Alias[4]);
    v11 = (std::wostream *)std::wostream::operator<<(v10, y);
    v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, ya);
    v13 = std::operator<<<wchar_t>(v12, &stru_893418);
    v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, (const char *)ascale);
    v15 = (std::wostream *)std::wostream::operator<<(v14);
    v16 = std::operator<<<wchar_t>(v15, &stru_893418);
    std::wostream::operator<<(v16);
    if ( v28._Myres >= 8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    LOBYTE(v31) = 3;
    if ( *(_DWORD *)&result._Bx._Alias[8] >= 8u )
      operator delete(v29);
    v17 = this->font;
    cc = (vec4f)_xmm;
    Font::setColor(v17, &cc);
    v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v27, &v28);
    v19 = this->font;
    v23 = v18;
    v20 = this->game;
    LOBYTE(v31) = 6;
    Font::blitString(v19, 0.0, (float)v20->graphics->videoSettings.height * 0.5, v23, 1.0, eAlignLeft);
    if ( v28._Myres >= 8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Bx._Buf[0] = 0;
    v28._Mysize = 0;
    v31 = -1;
    *(_DWORD *)&v27.gap0[*(_DWORD *)(*(_DWORD *)v27.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v26 + *(_DWORD *)(*(_DWORD *)v27.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v27.gap0 + 4) - 104;
    *(_DWORD *)&v27.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v27.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v27.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v27.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v27.gap68);
  }
}
void CarLodManager::update(CarLodManager *this, float dt)
{
  Node **v2; // eax
  Node **v3; // edx
  int v4; // ecx
  unsigned int v5; // esi
  int v6; // eax

  v2 = this->proViewNodes._Mylast;
  v3 = this->proViewNodes._Myfirst;
  v4 = 0;
  v5 = (unsigned int)((char *)v2 - (char *)v3 + 3) >> 2;
  if ( v3 > v2 )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      v6 = (int)*v3++;
      ++v4;
      *(_BYTE *)(v6 + 184) = 1;
    }
    while ( v4 != v5 );
  }
}
void CarLodManager::updateLodVisibility(CarLodManager *this)
{
  CameraForward *v2; // eax
  CarAvatar *v3; // edx
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  Sim *v10; // ecx
  CarLodDef *v11; // ecx
  CarLodDef *v12; // esi
  char *v13; // edx
  int v14; // edi
  unsigned int v15; // ebx
  int v16; // eax
  Node *v17; // eax
  Node *v18; // eax
  Node *v19; // eax
  Node *v20; // eax
  Node *v21; // eax
  Node **v22; // edx
  int v23; // edi
  unsigned int v24; // ebx
  Node *v25; // eax
  char v26; // [esp+Ah] [ebp-Ah]
  bool v27; // [esp+Bh] [ebp-9h]
  CarLodDef *v28; // [esp+Ch] [ebp-8h]
  float v29; // [esp+10h] [ebp-4h]

  v2 = Sim::getSceneCamera(this->car->sim);
  v3 = this->car;
  v4 = CarLodManager::lodDistDivisor;
  if ( v3->sim->cameraManager->mode == eTrack )
    v4 = CarLodManager::lodDistDivisor * 10.0;
  v5 = v2->matrix.M41 - v3->bodyMatrix.M41;
  v6 = (float)((float)(v2->matrix.M42 - v3->bodyMatrix.M42) * (float)(v2->matrix.M42 - v3->bodyMatrix.M42))
     + (float)(v5 * v5);
  v7 = 0.0;
  v8 = v6 + (float)((float)(v2->matrix.M43 - v3->bodyMatrix.M43) * (float)(v2->matrix.M43 - v3->bodyMatrix.M43));
  if ( v8 != 0.0 )
    v7 = fsqrt(v8);
  v9 = v2->fov;
  this->currentLod = -1;
  v10 = v3->sim;
  v27 = v10->useProView && ACCameraManager::isCameraOnBoard(v10->cameraManager, v3);
  v11 = this->lods._Myfirst;
  v12 = this->lods._Mylast;
  v28 = v11;
  if ( v11 != v12 )
  {
    v29 = (float)((float)(v9 * v7) * 0.016666668) / v4;
    while ( 1 )
    {
      if ( v29 < v11->in || v11->out <= v29 )
      {
        v26 = 0;
      }
      else
      {
        v26 = 1;
        this->currentLod = v11->index;
      }
      v13 = (char *)v11->nodes._Myfirst;
      v14 = 0;
      v15 = (unsigned int)((char *)v11->nodes._Mylast - v13 + 3) >> 2;
      if ( (Node **)v13 > v11->nodes._Mylast )
        v15 = 0;
      if ( v15 )
      {
        do
        {
          v16 = *(_DWORD *)v13;
          v13 += 4;
          ++v14;
          *(_BYTE *)(v16 + 184) = v26;
        }
        while ( v14 != v15 );
        v11 = v28;
      }
      v17 = v11->cockpitHR;
      if ( this->cockpitHRDistance < v29 )
      {
        if ( v17 && v11->cockpitLR )
        {
          v17->isActive = 0;
          v20 = v11->cockpitLR;
          goto LABEL_34;
        }
        v20 = v11->cockpitLR;
        if ( v20 )
LABEL_34:
          v20->isActive = 1;
        v21 = v11->steerHR;
        if ( v21 && v11->steerLR )
        {
          v21->isActive = 0;
          v11->steerLR->isActive = 1;
        }
        goto LABEL_38;
      }
      if ( !v17 )
        goto LABEL_25;
      if ( !v11->cockpitLR )
        break;
      v17->isActive = 1;
      v11->cockpitLR->isActive = 0;
LABEL_27:
      v19 = v11->steerHR;
      if ( v19 && v11->steerLR )
      {
        v19->isActive = 1;
        v11->steerLR->isActive = 0;
      }
LABEL_38:
      this->car->isDriverHR = this->driverHRDistance >= v29;
      if ( !v11->index && v27 )
      {
        v22 = this->proViewNodes._Myfirst;
        v23 = 0;
        v24 = (unsigned int)((char *)this->proViewNodes._Mylast - (char *)v22 + 3) >> 2;
        if ( v22 > this->proViewNodes._Mylast )
          v24 = 0;
        if ( v24 )
        {
          do
          {
            v25 = *v22++;
            ++v23;
            v25->isActive = 0;
          }
          while ( v23 != v24 );
        }
      }
      v28 = ++v11;
      if ( v11 == v12 )
        return;
    }
    v17->isActive = 1;
LABEL_25:
    v18 = v11->cockpitLR;
    if ( v18 )
      v18->isActive = 1;
    goto LABEL_27;
  }
}
