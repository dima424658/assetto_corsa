#include "damagedisplayer.h"
void __userpurge DamageDisplayer::DamageDisplayer(DamageDisplayer *this@<ecx>, Font *a2@<ebx>, Sim *aSim)
{
  double v4; // st7
  bool v5; // cf
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int v9; // eax
  Font *v10; // eax
  Font *v11; // eax
  bool v12; // bl
  int v13; // eax
  Game *v14; // eax
  Texture *v15; // ebx
  DamageDisplayer::DamageItem *v16; // eax
  Game *v17; // eax
  Texture *v18; // ebx
  DamageDisplayer::DamageItem *v19; // eax
  Game *v20; // eax
  Texture *v21; // ebx
  DamageDisplayer::DamageItem *v22; // eax
  Game *v23; // eax
  Texture *v24; // ebx
  DamageDisplayer::DamageItem *v25; // eax
  Game *v26; // eax
  Texture *v27; // ebx
  DamageDisplayer::DamageItem *v28; // eax
  Game *v29; // eax
  Texture *v30; // ebx
  DamageDisplayer::DamageItem *v31; // eax
  Game *v32; // eax
  Texture *v33; // ebx
  DamageDisplayer::DamageItem *v34; // eax
  Game *v35; // eax
  Texture *v36; // ebx
  DamageDisplayer::DamageItem *v37; // eax
  Game *v38; // eax
  Texture *v39; // ebx
  DamageDisplayer::DamageItem *v40; // eax
  Game *v41; // eax
  Texture *v42; // ebx
  DamageDisplayer::DamageItem *v43; // eax
  Game *v44; // eax
  Texture *v45; // ebx
  DamageDisplayer::DamageItem *v46; // eax
  Game *v47; // eax
  Texture *v48; // ebx
  DamageDisplayer::DamageItem *v49; // eax
  Game *v50; // eax
  Texture *v51; // ebx
  DamageDisplayer::DamageItem *v52; // eax
  Game *v53; // eax
  Texture *v54; // ebx
  DamageDisplayer::DamageItem *v55; // eax
  Game *v56; // eax
  Texture *v57; // ebx
  DamageDisplayer::DamageItem *v58; // eax
  Game *v59; // eax
  Texture *v60; // ebx
  DamageDisplayer::DamageItem *v61; // eax
  Game *v62; // eax
  Texture *v63; // ebx
  DamageDisplayer::DamageItem *v64; // eax
  Game *v65; // eax
  Texture *v66; // ebx
  DamageDisplayer::DamageItem *v67; // eax
  Event<OnReplayStatusChanged> *v68; // ecx
  std::wstring v69; // [esp-10h] [ebp-124h] BYREF
  unsigned int v70; // [esp+8h] [ebp-10Ch]
  std::allocator<DamageDisplayer::DamageItem> v71; // [esp+23h] [ebp-F1h] BYREF
  DamageDisplayer::{ctor}::__l12::<lambda_30a1869c666cb33e5541a92d257d58d8> v72; // [esp+24h] [ebp-F0h] BYREF
  Font *v73; // [esp+28h] [ebp-ECh]
  DamageDisplayer *v74; // [esp+2Ch] [ebp-E8h]
  std::wstring key; // [esp+30h] [ebp-E4h] BYREF
  Texture section; // [esp+48h] [ebp-CCh] BYREF
  std::wstring ifilename; // [esp+64h] [ebp-B0h] BYREF
  INIReader ini; // [esp+7Ch] [ebp-98h] BYREF
  INIReaderDocuments gameplayIni; // [esp+C0h] [ebp-54h] BYREF
  int v80; // [esp+110h] [ebp-4h]

  v72.__this = 0;
  v74 = this;
  v70 = (unsigned int)aSim->game;
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  std::wstring::assign(&v69, L"DAMAGE_DISPLAYER", 0x10u);
  GameObject::GameObject(this, v69, (Game *)v70);
  this->__vftable = (DamageDisplayer_vtbl *)&DamageDisplayer::`vftable';
  this->enabled = 1;
  this->sim = aSim;
  v80 = 0;
  this->items._Myfirst = 0;
  this->items._Mylast = 0;
  this->items._Myend = 0;
  LOBYTE(v80) = 1;
  this->oldCarIndex = Sim::getFocusedCarIndex(aSim);
  this->initialized = 0;
  this->renderTimer = 0.0;
  this->maxRenderTimer = 4.0;
  this->maxDamageKMH = 60.0;
  this->font._Myptr = 0;
  v70 = 31;
  LOBYTE(v80) = 2;
  v69._Myres = (unsigned int)L"system/cfg/damage_displayer.ini";
  this->printValues = 0;
  this->xOff = 0.0;
  this->yOff = 0.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v69._Myres, v70);
  LOBYTE(v80) = 3;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v80) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"TIME", 4u);
    LOBYTE(v80) = 6;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"MAIN", 4u);
    LOBYTE(v80) = 7;
    v4 = INIReader::getFloat(&ini, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->maxRenderTimer = v4;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_DAMAGE_KMH", 0xEu);
    LOBYTE(v80) = 8;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"MAIN", 4u);
    LOBYTE(v80) = 9;
    v6 = INIReader::getFloat(&ini, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->maxDamageKMH = v6;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POSITION_X", 0xAu);
    LOBYTE(v80) = 10;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"MAIN", 4u);
    LOBYTE(v80) = 11;
    v7 = INIReader::getFloat(&ini, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->xOff = v7;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE_FROM_CENTER_Y", 0x16u);
    LOBYTE(v80) = 12;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"MAIN", 4u);
    LOBYTE(v80) = 13;
    v8 = INIReader::getFloat(&ini, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->yOff = v8;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PRINT_VALUES", 0xCu);
    LOBYTE(v80) = 14;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"MAIN", 4u);
    LOBYTE(v80) = 15;
    v9 = INIReader::getInt(&ini, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->printValues = v9 == 1;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( this->printValues )
  {
    v10 = (Font *)operator new(24);
    v73 = v10;
    LOBYTE(v80) = 16;
    if ( v10 )
      Font::Font(v10, eFontProportional, 15.0, 0, 0);
    else
      v11 = 0;
    a2 = this->font._Myptr;
    LOBYTE(v80) = 5;
    this->font._Myptr = v11;
    if ( a2 )
    {
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)a2);
      operator delete(a2);
    }
  }
  v70 = 0;
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  std::wstring::assign(&v69, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&gameplayIni, (unsigned int)a2, v69, v70);
  LOBYTE(v80) = 17;
  v12 = 0;
  if ( gameplayIni.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DAMAGE_DISPLAYER", 0x10u);
    LOBYTE(v80) = 18;
    v72.__this = (DamageDisplayer *)1;
    if ( INIReader::hasSection(&gameplayIni, &key) )
      v12 = 1;
  }
  v80 = 17;
  if ( ((int)v72.__this & 1) != 0 && key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v12 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"IS_ACTIVE", 9u);
    LOBYTE(v80) = 19;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"DAMAGE_DISPLAYER", 0x10u);
    LOBYTE(v80) = 20;
    v13 = INIReader::getInt(&gameplayIni, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->enabled = v13 > 0;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v80) = 17;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/texture/damage/engine.png", 0x21u);
  v14 = this->game;
  LOBYTE(v80) = 21;
  v15 = ResourceStore::getTexture(v14->graphics->resourceStore._Myptr, &section, &key, 0);
  v16 = this->items._Mylast;
  LOBYTE(v80) = 22;
  v72.__this = this;
  if ( v16 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_30a1869c666cb33e5541a92d257d58d8_>(
    &v71,
    this->items._Mylast,
    v15,
    &v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/texture/damage/gearbox.png", 0x22u);
  v17 = this->game;
  LOBYTE(v80) = 23;
  v18 = ResourceStore::getTexture(v17->graphics->resourceStore._Myptr, &section, &key, 0);
  v19 = this->items._Mylast;
  LOBYTE(v80) = 24;
  v72.__this = this;
  if ( v19 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_4e62b6f27ff38ab122926485f437fe23_>(
    &v71,
    this->items._Mylast,
    v18,
    (DamageDisplayer::{ctor}::__l13::<lambda_4e62b6f27ff38ab122926485f437fe23> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 23;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/front.png");
  v20 = this->game;
  LOBYTE(v80) = 25;
  v21 = ResourceStore::getTexture(v20->graphics->resourceStore._Myptr, &section, &key, 0);
  v22 = this->items._Mylast;
  LOBYTE(v80) = 26;
  v72.__this = this;
  if ( v22 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_bd8907cf0c4bc79371c4c7ff25425663_>(
    &v71,
    this->items._Mylast,
    v21,
    (DamageDisplayer::{ctor}::__l14::<lambda_bd8907cf0c4bc79371c4c7ff25425663> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 25;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/rear.png");
  v23 = this->game;
  LOBYTE(v80) = 27;
  v24 = ResourceStore::getTexture(v23->graphics->resourceStore._Myptr, &section, &key, 0);
  v25 = this->items._Mylast;
  LOBYTE(v80) = 28;
  v72.__this = this;
  if ( v25 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_1ca8cfb881c0023f537e770f14165781_>(
    &v71,
    this->items._Mylast,
    v24,
    (DamageDisplayer::{ctor}::__l15::<lambda_1ca8cfb881c0023f537e770f14165781> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 27;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/left.png");
  v26 = this->game;
  LOBYTE(v80) = 29;
  v27 = ResourceStore::getTexture(v26->graphics->resourceStore._Myptr, &section, &key, 0);
  v28 = this->items._Mylast;
  LOBYTE(v80) = 30;
  v72.__this = this;
  if ( v28 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_cae6ad10d45ca8522f6c261413b078d6_>(
    &v71,
    this->items._Mylast,
    v27,
    (DamageDisplayer::{ctor}::__l16::<lambda_cae6ad10d45ca8522f6c261413b078d6> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 29;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/right.png");
  v29 = this->game;
  LOBYTE(v80) = 31;
  v30 = ResourceStore::getTexture(v29->graphics->resourceStore._Myptr, &section, &key, 0);
  v31 = this->items._Mylast;
  LOBYTE(v80) = 32;
  v72.__this = this;
  if ( v31 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_7be6e65ebd593868a58d06268892c077_>(
    &v71,
    this->items._Mylast,
    v30,
    (DamageDisplayer::{ctor}::__l17::<lambda_7be6e65ebd593868a58d06268892c077> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 31;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/tyre_fl.png");
  v32 = this->game;
  LOBYTE(v80) = 33;
  v33 = ResourceStore::getTexture(v32->graphics->resourceStore._Myptr, &section, &key, 0);
  v34 = this->items._Mylast;
  LOBYTE(v80) = 34;
  v72.__this = this;
  if ( v34 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_364ca66356ebdb2f67bff6a58eb49cf1_>(
    &v71,
    this->items._Mylast,
    v33,
    (DamageDisplayer::{ctor}::__l18::<lambda_364ca66356ebdb2f67bff6a58eb49cf1> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 33;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/tyre_fr.png");
  v35 = this->game;
  LOBYTE(v80) = 35;
  v36 = ResourceStore::getTexture(v35->graphics->resourceStore._Myptr, &section, &key, 0);
  v37 = this->items._Mylast;
  LOBYTE(v80) = 36;
  v72.__this = this;
  if ( v37 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_eb4eb79c5a2ae639bb085cd5a46fce76_>(
    &v71,
    this->items._Mylast,
    v36,
    (DamageDisplayer::{ctor}::__l19::<lambda_eb4eb79c5a2ae639bb085cd5a46fce76> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 35;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/tyre_rl.png");
  v38 = this->game;
  LOBYTE(v80) = 37;
  v39 = ResourceStore::getTexture(v38->graphics->resourceStore._Myptr, &section, &key, 0);
  v40 = this->items._Mylast;
  LOBYTE(v80) = 38;
  v72.__this = this;
  if ( v40 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_bf33cd3346b378aa7124754cb84cd787_>(
    &v71,
    this->items._Mylast,
    v39,
    (DamageDisplayer::{ctor}::__l20::<lambda_bf33cd3346b378aa7124754cb84cd787> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 37;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/tyre_rr.png");
  v41 = this->game;
  LOBYTE(v80) = 39;
  v42 = ResourceStore::getTexture(v41->graphics->resourceStore._Myptr, &section, &key, 0);
  v43 = this->items._Mylast;
  LOBYTE(v80) = 40;
  v72.__this = this;
  if ( v43 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_3831a4234c8b4f984cc416c0c2e8c0f1_>(
    &v71,
    this->items._Mylast,
    v42,
    (DamageDisplayer::{ctor}::__l21::<lambda_3831a4234c8b4f984cc416c0c2e8c0f1> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 39;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/sus_fl.png");
  v44 = this->game;
  LOBYTE(v80) = 41;
  v45 = ResourceStore::getTexture(v44->graphics->resourceStore._Myptr, &section, &key, 0);
  v46 = this->items._Mylast;
  LOBYTE(v80) = 42;
  v72.__this = this;
  if ( v46 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_4515a8dad98462c5b375a8904c2200c6_>(
    &v71,
    this->items._Mylast,
    v45,
    (DamageDisplayer::{ctor}::__l22::<lambda_4515a8dad98462c5b375a8904c2200c6> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 41;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/sus_fr.png");
  v47 = this->game;
  LOBYTE(v80) = 43;
  v48 = ResourceStore::getTexture(v47->graphics->resourceStore._Myptr, &section, &key, 0);
  v49 = this->items._Mylast;
  LOBYTE(v80) = 44;
  v72.__this = this;
  if ( v49 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_523e7597a8dac871e371bf604a802b40_>(
    &v71,
    this->items._Mylast,
    v48,
    (DamageDisplayer::{ctor}::__l23::<lambda_523e7597a8dac871e371bf604a802b40> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 43;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/sus_rl.png");
  v50 = this->game;
  LOBYTE(v80) = 45;
  v51 = ResourceStore::getTexture(v50->graphics->resourceStore._Myptr, &section, &key, 0);
  v52 = this->items._Mylast;
  LOBYTE(v80) = 46;
  v72.__this = this;
  if ( v52 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_893b1f3df355325909d41329b65269df_>(
    &v71,
    this->items._Mylast,
    v51,
    (DamageDisplayer::{ctor}::__l24::<lambda_893b1f3df355325909d41329b65269df> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 45;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/sus_rr.png");
  v53 = this->game;
  LOBYTE(v80) = 47;
  v54 = ResourceStore::getTexture(v53->graphics->resourceStore._Myptr, &section, &key, 0);
  v55 = this->items._Mylast;
  LOBYTE(v80) = 48;
  v72.__this = this;
  if ( v55 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_cafcf4fed9d61a619e644c666b02d61a_>(
    &v71,
    this->items._Mylast,
    v54,
    (DamageDisplayer::{ctor}::__l25::<lambda_cafcf4fed9d61a619e644c666b02d61a> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 47;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/flatspot_fl.png");
  v56 = this->game;
  LOBYTE(v80) = 49;
  v57 = ResourceStore::getTexture(v56->graphics->resourceStore._Myptr, &section, &key, 0);
  v58 = this->items._Mylast;
  LOBYTE(v80) = 50;
  v72.__this = this;
  if ( v58 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_577c23446fa9a047296e01313cec4df6_>(
    &v71,
    this->items._Mylast,
    v57,
    (DamageDisplayer::{ctor}::__l26::<lambda_577c23446fa9a047296e01313cec4df6> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 49;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/flatspot_fr.png");
  v59 = this->game;
  LOBYTE(v80) = 51;
  v60 = ResourceStore::getTexture(v59->graphics->resourceStore._Myptr, &section, &key, 0);
  v61 = this->items._Mylast;
  LOBYTE(v80) = 52;
  v72.__this = this;
  if ( v61 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_c5729e8bde39f0814e73b7c23b067a1b_>(
    &v71,
    this->items._Mylast,
    v60,
    (DamageDisplayer::{ctor}::__l27::<lambda_c5729e8bde39f0814e73b7c23b067a1b> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 51;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/flatspot_rl.png");
  v62 = this->game;
  LOBYTE(v80) = 53;
  v63 = ResourceStore::getTexture(v62->graphics->resourceStore._Myptr, &section, &key, 0);
  v64 = this->items._Mylast;
  LOBYTE(v80) = 54;
  v72.__this = this;
  if ( v64 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_f685c20988d4a25ca568bdb0cb6dbcb4_>(
    &v71,
    this->items._Mylast,
    v63,
    (DamageDisplayer::{ctor}::__l28::<lambda_f685c20988d4a25ca568bdb0cb6dbcb4> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 53;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v80) = 17;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"content/texture/damage/flatspot_rr.png");
  v65 = this->game;
  LOBYTE(v80) = 55;
  v66 = ResourceStore::getTexture(v65->graphics->resourceStore._Myptr, &section, &key, 0);
  v67 = this->items._Mylast;
  LOBYTE(v80) = 56;
  v72.__this = this;
  if ( v67 == this->items._Myend )
    std::vector<DamageDisplayer::DamageItem>::_Reserve(&this->items, 1u);
  std::allocator<DamageDisplayer::DamageItem>::construct<DamageDisplayer::DamageItem,Texture,_lambda_e9ec5f6fe842578807784ad4676f2b45_>(
    &v71,
    this->items._Mylast,
    v66,
    (DamageDisplayer::{ctor}::__l29::<lambda_e9ec5f6fe842578807784ad4676f2b45> *)&v72);
  ++this->items._Mylast;
  LOBYTE(v80) = 55;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v70 = (unsigned int)this;
  v69._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_08befdb401e28dbfbc434e667627dbb3_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v69._Bx._Alias[4] = this;
  v69._Mysize = (unsigned int)&v69;
  v68 = &this->sim->evOnReplayStatusChanged;
  LOBYTE(v80) = 17;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v68,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v69,
    this);
  LOBYTE(v80) = 5;
  INIReaderDocuments::~INIReaderDocuments(&gameplayIni);
  LOBYTE(v80) = 2;
  INIReader::~INIReader(&ini);
}
void DamageDisplayer::~DamageDisplayer(DamageDisplayer *this)
{
  Font *v2; // esi

  this->__vftable = (DamageDisplayer_vtbl *)&DamageDisplayer::`vftable';
  v2 = this->font._Myptr;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)this->font._Myptr);
    operator delete(v2);
  }
  if ( this->items._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->items);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<DamageDisplayer::DamageItem>>>(
      this->items._Myfirst,
      this->items._Mylast);
    operator delete(this->items._Myfirst);
    this->items._Myfirst = 0;
    this->items._Mylast = 0;
    this->items._Myend = 0;
  }
  GameObject::~GameObject(this);
}
DamageDisplayer *DamageDisplayer::`vector deleting destructor'(DamageDisplayer *this, unsigned int a2)
{
  DamageDisplayer::~DamageDisplayer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge DamageDisplayer::renderHUD(DamageDisplayer *this@<ecx>, float a2@<xmm3>, float dt)
{
  Sim *v4; // ecx
  EndSessionDisplayer *v5; // eax
  DamageDisplayer::DamageItem *v6; // esi
  DamageDisplayer::DamageItem *v7; // edi
  bool v8; // cl
  std::_Func_base<float> *v9; // ecx
  double v10; // st7
  float v11; // xmm1_4
  GLRenderer *v12; // eax
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  float b; // eax
  __m128 v16; // xmm0
  unsigned __int64 r; // xmm0_8
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  unsigned int v20; // eax
  unsigned int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm0_4
  CarAvatar *v24; // eax
  std::wstring *v25; // eax
  const std::wstring *v26; // eax
  Font *v27; // ecx
  CarAvatar *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  Font *v31; // ecx
  CarAvatar *v32; // eax
  std::wstring *v33; // eax
  const std::wstring *v34; // eax
  Font *v35; // ecx
  CarAvatar *v36; // eax
  std::wstring *v37; // eax
  const std::wstring *v38; // eax
  Font *v39; // ecx
  CarAvatar *v40; // eax
  std::wstring *v41; // eax
  const std::wstring *v42; // eax
  Font *v43; // ecx
  CarAvatar *v44; // eax
  std::wstring *v45; // eax
  const std::wstring *v46; // eax
  Font *v47; // ecx
  CarAvatar *v48; // eax
  std::wstring *v49; // eax
  const std::wstring *v50; // eax
  Font *v51; // ecx
  CarAvatar *v52; // eax
  std::wstring *v53; // eax
  const std::wstring *v54; // eax
  Font *v55; // ecx
  CarAvatar *v56; // eax
  std::wstring *v57; // eax
  const std::wstring *v58; // eax
  Font *v59; // ecx
  CarAvatar *v60; // eax
  std::wstring *v61; // eax
  const std::wstring *v62; // eax
  std::_Func_base<float> **v63; // eax
  float g; // [esp+Ch] [ebp-A0h]
  char i; // [esp+2Bh] [ebp-81h]
  float newHealth; // [esp+2Ch] [ebp-80h]
  unsigned int newHealtha; // [esp+2Ch] [ebp-80h]
  std::_Func_base<float> **newHealthb; // [esp+2Ch] [ebp-80h]
  GLRenderer *v69; // [esp+30h] [ebp-7Ch]
  float y; // [esp+34h] [ebp-78h]
  std::wstring result; // [esp+38h] [ebp-74h] BYREF
  std::wstring v72; // [esp+50h] [ebp-5Ch] BYREF
  vec3f color; // [esp+68h] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v74; // [esp+80h] [ebp-2Ch] BYREF
  int v75; // [esp+A8h] [ebp-4h]

  v4 = this->sim;
  v5 = v4->endSessionDisplayer;
  if ( (!v5 || !v5->isActive)
    && !v4->escMenu->visible
    && this->game->gui->isActive
    && !v4->pauseMenu->visible
    && this->enabled )
  {
    if ( this->initialized && this->oldCarIndex == Sim::getFocusedCarIndex(v4) )
    {
      v6 = this->items._Myfirst;
      v7 = this->items._Mylast;
      v8 = this->renderTimer > 0.0;
      for ( i = v8; v6 != v7; ++v6 )
      {
        v9 = v6->fetch._Impl;
        if ( !v9 )
          goto LABEL_23;
        v10 = ((double (*)(std::_Func_base<float> *))v9->_Do_call)(v9);
        v11 = v6->health;
        newHealth = v10;
        if ( newHealth <= v11 )
        {
          if ( v11 > newHealth || newHealth <= 0.0 )
          {
            v6->health = newHealth;
            v8 = 1;
            v6->blinkTime = 1.0;
            i = 1;
            this->renderTimer = this->maxRenderTimer;
            continue;
          }
        }
        else
        {
          v6->health = newHealth;
        }
        v8 = i;
      }
      if ( v8 )
      {
        v7 = this->items._Mylast;
        v6 = this->items._Myfirst;
        v12 = this->sim->game->graphics->gl;
        v69 = v12;
        for ( y = (float)(this->sim->game->graphics->videoSettings.height / 2) + this->yOff; v6 != v7; ++v6 )
        {
          GLRenderer::color4f(v12, 1.0, 1.0, 1.0, 1.0);
          a2 = 0.0;
          if ( v6->blinkTime > 0.0 && (int)this->game->gameTime.now / 100 % 2 )
          {
            GLRenderer::color4f(v69, 1.0, 0.0, 0.0, 1.0);
            v6->blinkTime = v6->blinkTime - (float)(dt * 2.0);
          }
          else
          {
$LN296:
            v13 = (__m128)LODWORD(v6->health);
            if ( v13.m128_f32[0] <= 0.5 )
            {
              v13.m128_f32[0] = v13.m128_f32[0] * 2.0;
              v18 = v13;
              v18.m128_f32[0] = v13.m128_f32[0] * a2;
              v19 = v18;
              *(float *)&v72._Bx._Alias[8] = v13.m128_f32[0] * a2;
              v19.m128_f32[0] = (float)(v13.m128_f32[0] * a2) + 1.0;
              b = v13.m128_f32[0] * a2;
              r = _mm_unpacklo_ps(v19, v13).m128_u64[0];
            }
            else
            {
              v13.m128_f32[0] = (float)(v13.m128_f32[0] - 0.5) * 2.0;
              v14 = v13;
              *(_DWORD *)&result._Bx._Alias[8] = v13.m128_i32[0];
              b = v13.m128_f32[0];
              v14.m128_f32[0] = v13.m128_f32[0] * a2;
              v16 = v14;
              v16.m128_f32[0] = (float)(v13.m128_f32[0] * a2) + 1.0;
              v14.m128_f32[0] = v16.m128_f32[0];
              r = _mm_unpacklo_ps(v16, v14).m128_u64[0];
            }
            *(_QWORD *)&color.x = r;
            color.z = b;
            GLRenderer::color4f(v69, *(float *)&r, *((float *)&r + 1), b, 1.0);
          }
          GraphicsManager::setTexture(this->sim->game->graphics, 0, &v6->texture);
          if ( v6->texture.kid )
            v20 = kglTextureGetHeight(v6->texture.kid);
          else
            v20 = 0;
          newHealtha = v20;
          if ( v6->texture.kid )
            v21 = kglTextureGetWidth(v6->texture.kid);
          else
            v21 = 0;
          v22 = (float)newHealtha;
          g = v22;
          v23 = (float)v21;
          GLRenderer::quad(v69, this->xOff, y, v23, g, 1, 0);
          v12 = v69;
        }
        if ( this->printValues )
        {
          v24 = Sim::getCar(this->sim, 0);
          v25 = std::to_wstring(&result, v24->physicsState.damageZoneLevel[0]);
          v75 = 0;
          v26 = std::operator+<wchar_t>(&v72, L"BODY FRONT : ", v25);
          v27 = this->font._Myptr;
          LOBYTE(v75) = 1;
          Font::blitString(v27, 0.0, 0.0, v26, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v28 = Sim::getCar(this->sim, 0);
          v29 = std::to_wstring(&result, v28->physicsState.damageZoneLevel[1]);
          v75 = 2;
          v30 = std::operator+<wchar_t>(&v72, L"BODY REAR : ", v29);
          v31 = this->font._Myptr;
          LOBYTE(v75) = 3;
          Font::blitString(v31, 0.0, 25.0, v30, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v32 = Sim::getCar(this->sim, 0);
          v33 = std::to_wstring(&result, v32->physicsState.damageZoneLevel[2]);
          v75 = 4;
          v34 = std::operator+<wchar_t>(&v72, L"BODY LEFT : ", v33);
          v35 = this->font._Myptr;
          LOBYTE(v75) = 5;
          Font::blitString(v35, 0.0, 50.0, v34, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v36 = Sim::getCar(this->sim, 0);
          v37 = std::to_wstring(&result, v36->physicsState.damageZoneLevel[3]);
          v75 = 6;
          v38 = std::operator+<wchar_t>(&v72, L"BODY RIGHT : ", v37);
          v39 = this->font._Myptr;
          LOBYTE(v75) = 7;
          Font::blitString(v39, 0.0, 75.0, v38, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v40 = Sim::getCar(this->sim, 0);
          v41 = std::to_wstring(&result, 1.0 - v40->physicsState.susDamage[0]);
          v75 = 8;
          v42 = std::operator+<wchar_t>(&v72, L"SUSPENSION FL : ", v41);
          v43 = this->font._Myptr;
          LOBYTE(v75) = 9;
          Font::blitString(v43, 0.0, 100.0, v42, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v44 = Sim::getCar(this->sim, 0);
          v45 = std::to_wstring(&result, 1.0 - v44->physicsState.susDamage[1]);
          v75 = 10;
          v46 = std::operator+<wchar_t>(&v72, L"SUSPENSION FR : ", v45);
          v47 = this->font._Myptr;
          LOBYTE(v75) = 11;
          Font::blitString(v47, 0.0, 125.0, v46, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v48 = Sim::getCar(this->sim, 0);
          v49 = std::to_wstring(&result, 1.0 - v48->physicsState.susDamage[2]);
          v75 = 12;
          v50 = std::operator+<wchar_t>(&v72, L"SUSPENSION RL : ", v49);
          v51 = this->font._Myptr;
          LOBYTE(v75) = 13;
          Font::blitString(v51, 0.0, 150.0, v50, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v52 = Sim::getCar(this->sim, 0);
          v53 = std::to_wstring(&result, 1.0 - v52->physicsState.susDamage[3]);
          v75 = 14;
          v54 = std::operator+<wchar_t>(&v72, L"SUSPENSION RR : ", v53);
          v55 = this->font._Myptr;
          LOBYTE(v75) = 15;
          Font::blitString(v55, 0.0, 175.0, v54, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v56 = Sim::getCar(this->sim, 0);
          v57 = std::to_wstring(&result, v56->physicsState.engineLifeLeft);
          v75 = 16;
          v58 = std::operator+<wchar_t>(&v72, L"ENGINE LIFE : ", v57);
          v59 = this->font._Myptr;
          LOBYTE(v75) = 17;
          Font::blitString(v59, 0.0, 200.0, v58, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
          v75 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v60 = Sim::getCar(this->sim, 0);
          v61 = std::to_wstring(&v74.name, v60->physicsState.gearRpmWindow);
          v75 = 18;
          v62 = std::operator+<wchar_t>((std::wstring *)&color, L"GEAR : ", v61);
          LOBYTE(v75) = 19;
          Font::blitString(this->font._Myptr, 0.0, 225.0, v62, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&color);
          std::wstring::~wstring(&v74);
        }
      }
      this->renderTimer = this->renderTimer - dt;
    }
    else
    {
      v6 = this->items._Myfirst;
      v7 = this->items._Mylast;
      if ( v6 != v7 )
      {
        v63 = &v6->fetch._Impl;
        newHealthb = &v6->fetch._Impl;
        do
        {
          if ( !*v63 )
          {
LABEL_23:
            std::_Xbad_function_call();
            goto $LN296;
          }
          ++v6;
          *((float *)newHealthb + 2) = (*v63)->_Do_call(*v63);
          v63 = newHealthb + 16;
          newHealthb += 16;
        }
        while ( v6 != v7 );
      }
      this->initialized = 1;
    }
  }
}
void DamageDisplayer::show(DamageDisplayer *this)
{
  this->renderTimer = this->maxRenderTimer;
}
void DamageDisplayer::shutdown(DamageDisplayer *this)
{
  std::wstring *v2; // eax
  std::wstring path; // [esp+8h] [ebp-28h] BYREF
  int v4; // [esp+2Ch] [ebp-4h]

  Path::getDocumentPath(&path);
  v4 = 0;
  std::wstring::append(&path, L"/Assetto Corsa/cfg/gameplay.ini", 0x1Fu);
  v2 = &path;
  if ( this->enabled )
  {
    if ( path._Myres >= 8 )
      v2 = (std::wstring *)path._Bx._Ptr;
    WritePrivateProfileStringW(L"DAMAGE_DISPLAYER", L"IS_ACTIVE", L"1", v2->_Bx._Buf);
  }
  else
  {
    if ( path._Myres >= 8 )
      v2 = (std::wstring *)path._Bx._Ptr;
    WritePrivateProfileStringW(L"DAMAGE_DISPLAYER", L"IS_ACTIVE", L"0", v2->_Bx._Buf);
  }
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
