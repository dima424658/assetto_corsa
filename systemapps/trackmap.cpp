#include "trackmap.h"
void TrackMap::TrackMap(TrackMap *this, ksgui::GUI *a_gui, Sim *a_sim, bool zoomed)
{
  std::wstring *v5; // edi
  Game *v6; // eax
  const std::wstring *v7; // eax
  Sim *v8; // eax
  const std::wstring *v9; // eax
  std::wstring *v10; // ebp
  Sim *v11; // ecx
  TrackAvatar *v12; // eax
  Texture *v13; // eax
  std::wstring v14; // [esp-20h] [ebp-84h] BYREF
  ksgui::GUI *v15; // [esp-8h] [ebp-6Ch]
  int v16; // [esp-4h] [ebp-68h]
  Sim *v17; // [esp+14h] [ebp-50h]
  TrackMap *v18; // [esp+1Ch] [ebp-48h]
  std::wstring text; // [esp+20h] [ebp-44h] BYREF
  Texture result; // [esp+38h] [ebp-2Ch] BYREF
  int v21; // [esp+60h] [ebp-4h]

  v16 = 0;
  v15 = a_gui;
  v18 = this;
  v17 = a_sim;
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  std::wstring::assign(&v14, L"KSMAP", 5u);
  ksgui::Form::Form(this, (unsigned int)a_sim, v14, v15, v16);
  v21 = 0;
  this->__vftable = (TrackMap_vtbl *)&TrackMap::`vftable';
  this->adversaryIcon.kid = 0;
  this->adversaryIcon.fileName._Myres = 7;
  this->adversaryIcon.fileName._Mysize = 0;
  this->adversaryIcon.fileName._Bx._Buf[0] = 0;
  this->map.kid = 0;
  this->map.fileName._Myres = 7;
  this->map.fileName._Mysize = 0;
  this->map.fileName._Bx._Buf[0] = 0;
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  v5 = &this->trackConfigName;
  this->trackConfigName._Myres = 7;
  this->trackConfigName._Mysize = 0;
  this->trackConfigName._Bx._Buf[0] = 0;
  this->carModel._Myres = 7;
  this->carModel._Mysize = 0;
  this->carModel._Bx._Buf[0] = 0;
  LOBYTE(v21) = 5;
  this->game = a_sim->game;
  v6 = a_sim->game;
  v16 = (int)a_sim;
  this->gl = v6->graphics->gl;
  TrackMapHandler::TrackMapHandler(&this->tmc, (unsigned int)a_sim, (Sim *)v16);
  LOBYTE(v21) = 6;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Track map", 9u);
  LOBYTE(v21) = 7;
  v7 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v21) = 8;
  this->formTitle->setText(this->formTitle, v7);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v21) = 6;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v8 = v17;
  this->sim = v17;
  this->devApp = 0;
  v9 = &v8->track->name;
  if ( &this->trackName != v9 )
    std::wstring::assign(&this->trackName, v9, 0, 0xFFFFFFFF);
  v10 = TrackAvatar::getConfig(this->sim->track, (std::wstring *)&result);
  if ( v5 != v10 )
  {
    if ( this->trackConfigName._Myres >= 8 )
      operator delete(v5->_Bx._Ptr);
    this->trackConfigName._Myres = 7;
    this->trackConfigName._Mysize = 0;
    v16 = (int)v10;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->trackConfigName, (std::wstring *)v16);
  }
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  v11 = this->sim;
  this->mode = eZoom;
  v12 = GameObject::getGameObject<TrackAvatar>(v11);
  this->aiSpline = TrackAvatar::getAISpline(v12);
  TrackMap::initParameters(this, (unsigned int)operator delete);
  TrackMap::loadMap(this, (unsigned int)operator delete);
  v16 = 1;
  this->cWidth = 0.0;
  this->cHeight = 0.0;
  ksgui::Form::setAutoHideMode(this, v16);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/ksmap/adversaryMapTexture.png", 0x29u);
  LOBYTE(v21) = 9;
  v13 = ResourceStore::getTexture(this->game->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v21) = 10;
  this->adversaryIcon.kid = v13->kid;
  if ( &this->adversaryIcon.fileName != &v13->fileName )
    std::wstring::assign(&this->adversaryIcon.fileName, &v13->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v21) = 9;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
}
TrackMap *TrackMap::`vector deleting destructor'(TrackMap *this, unsigned int a2)
{
  TrackMap::~TrackMap(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __usercall TrackMap::initParameters(TrackMap *this@<ecx>, unsigned int a2@<ebx>)
{
  Sim *v3; // ecx
  double v4; // st7
  bool v5; // cf
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  std::wstring section; // [esp+Ch] [ebp-A8h] BYREF
  std::wstring key; // [esp+24h] [ebp-90h] BYREF
  std::wstring iniMainConfigurationPath; // [esp+3Ch] [ebp-78h] BYREF
  INIReader r; // [esp+54h] [ebp-60h] BYREF
  int v14; // [esp+B0h] [ebp-4h]

  v3 = this->sim;
  this->sizeIcon = 10.0;
  this->zoomSection = 1.35;
  this->maxDimensionForm = 300.0;
  this->startingAlpha = 0.80000001;
  this->finishingAlpha = 0.0;
  Sim::getCar(v3, 0);
  iniMainConfigurationPath._Myres = 7;
  iniMainConfigurationPath._Mysize = 0;
  iniMainConfigurationPath._Bx._Buf[0] = 0;
  std::wstring::assign(&iniMainConfigurationPath, L"system/cfg/map.ini", 0x12u);
  v14 = 0;
  if ( Path::fileExists(a2, &iniMainConfigurationPath, 0) )
  {
    INIReader::INIReader(&r, &iniMainConfigurationPath);
    LOBYTE(v14) = 1;
    if ( r.ready )
    {
      std::wstring::wstring(&key, L"SIZE");
      LOBYTE(v14) = 2;
      std::wstring::wstring(&section, L"DRIVER_ICON");
      LOBYTE(v14) = 3;
      v4 = INIReader::getFloat(&r, &section, &key);
      v5 = section._Myres < 8;
      this->sizeIcon = v4;
      if ( !v5 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v14) = 1;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"ZOOM_ON_SECTION");
      LOBYTE(v14) = 4;
      std::wstring::wstring(&section, L"MAP_SECTION");
      LOBYTE(v14) = 5;
      v6 = INIReader::getFloat(&r, &section, &key);
      v5 = section._Myres < 8;
      this->zoomSection = v6;
      if ( !v5 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v14) = 1;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"MAX_DIMENSION_FORM");
      LOBYTE(v14) = 6;
      std::wstring::wstring(&section, L"MAP_FORM");
      LOBYTE(v14) = 7;
      v7 = INIReader::getFloat(&r, &section, &key);
      v5 = section._Myres < 8;
      this->maxDimensionForm = v7;
      if ( !v5 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v14) = 1;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"STARTING_ALPHA");
      LOBYTE(v14) = 8;
      std::wstring::wstring(&section, L"MAP_SECTION");
      LOBYTE(v14) = 9;
      v8 = INIReader::getFloat(&r, &section, &key);
      v5 = section._Myres < 8;
      this->startingAlpha = v8;
      if ( !v5 )
        operator delete(section._Bx._Ptr);
      LOBYTE(v14) = 1;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"FINISHING_ALPHA");
      LOBYTE(v14) = 10;
      std::wstring::wstring(&section, L"MAP_SECTION");
      LOBYTE(v14) = 11;
      v9 = INIReader::getFloat(&r, &section, &key);
      v5 = section._Myres < 8;
      this->finishingAlpha = v9;
      if ( !v5 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    LOBYTE(v14) = 0;
    INIReader::~INIReader(&r);
  }
  if ( iniMainConfigurationPath._Myres >= 8 )
    operator delete(iniMainConfigurationPath._Bx._Ptr);
}
void TrackMap::createMap(TrackMap *this)
{
  TrackMapHandler *v2; // edi
  float *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  std::wstring *v7; // ebx
  float v8; // xmm1_4
  std::wstring *v9; // eax
  void (__cdecl *v10)(void *); // esi
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // ebp
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring v19[2]; // [esp-18h] [ebp-D4h] BYREF
  std::wstring result; // [esp+1Ch] [ebp-A0h] BYREF
  std::wstring v21; // [esp+34h] [ebp-88h] BYREF
  std::wstring v22; // [esp+4Ch] [ebp-70h] BYREF
  std::wstring v23; // [esp+64h] [ebp-58h] BYREF
  std::wstring v24; // [esp+7Ch] [ebp-40h] BYREF
  std::wstring v25; // [esp+94h] [ebp-28h] BYREF
  int v26; // [esp+B8h] [ebp-4h]

  v2 = &this->tmc;
  TrackMapHandler::createListOfPointsToDrawFromSpline(&this->tmc);
  TrackMapHandler::makePositiveCoordAndCalculateWidthAndHeightRT(v2);
  v3 = &v2->width;
  v4 = v2->scaleFactor;
  if ( v2->height > v2->width )
    v3 = &v2->height;
  v5 = *v3;
  v2->mapSquareSize = *v3;
  v6 = v5 / v4;
  if ( (float)(v5 / v4) >= 1600.0 )
  {
    do
    {
      v4 = v4 + 0.1;
      v6 = v5 / v4;
    }
    while ( (float)(v5 / v4) >= 1600.0 );
    v2->scaleFactor = v4;
  }
  v2->mapSquareSize = v6;
  v7 = &this->trackName;
  v8 = 1.0 / v2->scaleFactor;
  v19[0]._Myres = (unsigned int)&this->trackName;
  v19[0]._Mysize = (unsigned int)L"content\\tracks\\";
  v2->width = v2->width * v8;
  v2->height = v2->height * v8;
  if ( this->trackConfigName._Mysize )
  {
    v12 = std::operator+<wchar_t>(&v24, (const wchar_t *)v19[0]._Mysize, (const std::wstring *)v19[0]._Myres);
    v26 = 2;
    v13 = std::operator+<wchar_t>(&result, v12, L"\\");
    v14 = &this->trackConfigName;
    LOBYTE(v26) = 3;
    v15 = std::operator+<wchar_t>(&v23, v13, &this->trackConfigName);
    LOBYTE(v26) = 4;
    std::operator+<wchar_t>(v19, v15, L"\\map.png");
    TrackMapHandler::drawMapOnRenderTarget(v2, v19[0]);
    v10 = operator delete;
    if ( v23._Myres >= 8 )
      operator delete(v23._Bx._Ptr);
    v23._Myres = 7;
    v23._Mysize = 0;
    v23._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v26 = -1;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v24._Myres >= 8 )
      operator delete(v24._Bx._Ptr);
    v16 = std::operator+<wchar_t>(&v25, L"content\\tracks\\", v7);
    v26 = 5;
    v17 = std::operator+<wchar_t>(&v22, v16, L"\\");
    LOBYTE(v26) = 6;
    v18 = std::operator+<wchar_t>(&v21, v17, v14);
    LOBYTE(v26) = 7;
    std::operator+<wchar_t>(v19, v18, L"\\data\\map.ini");
    TrackMapHandler::saveParameters(v2, v19[0]);
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( v25._Myres >= 8 )
    {
      v19[0]._Myres = (unsigned int)v25._Bx._Ptr;
      goto LABEL_23;
    }
  }
  else
  {
    v9 = std::operator+<wchar_t>(&result, (const wchar_t *)v19[0]._Mysize, (const std::wstring *)v19[0]._Myres);
    v26 = 0;
    std::operator+<wchar_t>(v19, v9, L"\\map.png");
    TrackMapHandler::drawMapOnRenderTarget(v2, v19[0]);
    v26 = -1;
    v10 = operator delete;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v11 = std::operator+<wchar_t>(&result, L"content\\tracks\\", v7);
    v26 = 1;
    std::operator+<wchar_t>(v19, v11, L"\\data\\map.ini");
    TrackMapHandler::saveParameters(v2, v19[0]);
    if ( result._Myres >= 8 )
    {
      v19[0]._Myres = (unsigned int)result._Bx._Ptr;
LABEL_23:
      v10((void *)v19[0]._Myres);
      return;
    }
  }
}
void __usercall TrackMap::loadMap(TrackMap *this@<ecx>, unsigned int a2@<ebx>)
{
  bool v3; // zf
  std::wstring *v4; // edi
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  char v7; // al
  void (__cdecl *v8)(void *); // ebx
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  char v13; // al
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  const std::wstring *v17; // eax
  Texture *v18; // eax
  void *v19; // ecx
  const std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  const std::wstring *v28; // eax
  Texture *v29; // eax
  void *v30; // ecx
  const std::wstring *v31; // eax
  _DWORD *v32; // ecx
  unsigned int v33; // ecx
  _DWORD *v34; // eax
  unsigned int v35; // eax
  float v36; // xmm2_4
  _DWORD *v37; // eax
  unsigned int v38; // eax
  float v39; // xmm6_4
  _DWORD *v40; // eax
  unsigned int v41; // eax
  float v42; // xmm1_4
  float v43; // xmm7_4
  _DWORD *v44; // eax
  unsigned int v45; // eax
  double v46; // xmm0_8
  _DWORD *v47; // eax
  float v48; // xmm2_4
  unsigned int v49; // eax
  float v50; // xmm4_4
  double v51; // xmm0_8
  int *v52; // eax
  float v53; // xmm0_4
  float v54; // xmm3_4
  int v55; // ecx
  float *v56; // edi
  float *v57; // esi
  unsigned int *v58; // eax
  int v59; // edx
  float v60; // xmm5_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  std::wstring v63; // [esp-10h] [ebp-E4h] BYREF
  bool v64; // [esp+1Bh] [ebp-B9h]
  float v65; // [esp+1Ch] [ebp-B8h] BYREF
  int v66; // [esp+20h] [ebp-B4h] BYREF
  TrackMap *v67; // [esp+24h] [ebp-B0h]
  std::wstring result; // [esp+28h] [ebp-ACh] BYREF
  std::wstring v69; // [esp+40h] [ebp-94h] BYREF
  std::wstring iniPath; // [esp+58h] [ebp-7Ch] BYREF
  Texture v71; // [esp+70h] [ebp-64h] BYREF
  std::wstring v72; // [esp+8Ch] [ebp-48h] BYREF
  Texture v73; // [esp+A4h] [ebp-30h] BYREF
  int v74; // [esp+D0h] [ebp-4h]

  v67 = this;
  v3 = this->trackConfigName._Mysize == 0;
  v4 = &this->trackName;
  v63._Myres = (unsigned int)&this->trackName;
  v63._Mysize = (unsigned int)L"content\\tracks\\";
  if ( v3 )
  {
    v5 = std::operator+<wchar_t>(&result, (const wchar_t *)v63._Mysize, (const std::wstring *)v63._Myres);
    v74 = 0;
    v6 = std::operator+<wchar_t>(&v69, v5, L"\\map.png");
    LOBYTE(v74) = 1;
    v7 = Path::fileExists(a2, v6, 0);
    v8 = operator delete;
    v64 = v7 == 0;
    if ( v69._Myres >= 8 )
      operator delete(v69._Bx._Ptr);
    v74 = -1;
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
    {
      v63._Myres = (unsigned int)result._Bx._Ptr;
LABEL_14:
      v8((void *)v63._Myres);
      goto LABEL_15;
    }
  }
  else
  {
    v9 = std::operator+<wchar_t>(&v72, (const wchar_t *)v63._Mysize, (const std::wstring *)v63._Myres);
    v74 = 2;
    v10 = std::operator+<wchar_t>(&result, v9, L"\\");
    LOBYTE(v74) = 3;
    v11 = std::operator+<wchar_t>((std::wstring *)&v71, v10, &this->trackConfigName);
    LOBYTE(v74) = 4;
    v12 = std::operator+<wchar_t>(&v69, v11, L"\\map.png");
    LOBYTE(v74) = 5;
    v13 = Path::fileExists(a2, v12, 0);
    v8 = operator delete;
    v64 = v13 == 0;
    if ( v69._Myres >= 8 )
      operator delete(v69._Bx._Ptr);
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
    if ( v71.fileName._Mysize >= 8 )
      operator delete(v71.kid);
    v71.fileName._Mysize = 7;
    *(_DWORD *)&v71.fileName._Bx._Alias[12] = 0;
    LOWORD(v71.kid) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v74 = -1;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v72._Myres >= 8 )
    {
      v63._Myres = (unsigned int)v72._Bx._Ptr;
      goto LABEL_14;
    }
  }
LABEL_15:
  if ( v64 )
    TrackMap::createMap(this);
  iniPath._Myres = 7;
  iniPath._Mysize = 0;
  iniPath._Bx._Buf[0] = 0;
  v63._Myres = (unsigned int)v4;
  v74 = 6;
  v3 = this->trackConfigName._Mysize == 0;
  v63._Mysize = (unsigned int)L"content\\tracks\\";
  *(_DWORD *)&v63._Bx._Alias[12] = &v72;
  if ( v3 )
  {
    v14 = std::operator+<wchar_t>(
            *(std::wstring **)&v63._Bx._Alias[12],
            (const wchar_t *)v63._Mysize,
            (const std::wstring *)v63._Myres);
    LOBYTE(v74) = 7;
    v15 = std::operator+<wchar_t>(&result, v14, L"\\data\\map.ini");
    v65 = *(float *)&v15;
    if ( &iniPath != v15 )
    {
      if ( iniPath._Myres >= 8 )
      {
        v8(iniPath._Bx._Ptr);
        v15 = (std::wstring *)LODWORD(v65);
      }
      iniPath._Myres = 7;
      iniPath._Bx._Buf[0] = 0;
      iniPath._Mysize = 0;
      std::wstring::_Assign_rv(&iniPath, v15);
    }
    if ( result._Myres >= 8 )
      v8(result._Bx._Ptr);
    LOBYTE(v74) = 6;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v72._Myres >= 8 )
      v8(v72._Bx._Ptr);
    v16 = std::operator+<wchar_t>(&v72, L"content\\tracks\\", v4);
    LOBYTE(v74) = 8;
    v17 = std::operator+<wchar_t>(&result, v16, L"\\map.png");
    LOBYTE(v74) = 9;
    v18 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &v71, v17, 0);
    LOBYTE(v74) = 10;
    v19 = v18->kid;
    v20 = &v18->fileName;
    this->map.kid = v19;
    if ( &this->map.fileName != v20 )
      std::wstring::assign(&this->map.fileName, v20, 0, 0xFFFFFFFF);
    LOBYTE(v74) = 9;
    OnSetupAppCreated::~OnSetupAppCreated(&v71);
    if ( result._Myres >= 8 )
      v8(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  else
  {
    v21 = std::operator+<wchar_t>(
            *(std::wstring **)&v63._Bx._Alias[12],
            (const wchar_t *)v63._Mysize,
            (const std::wstring *)v63._Myres);
    LOBYTE(v74) = 11;
    v22 = std::operator+<wchar_t>(&v69, v21, L"\\");
    LOBYTE(v74) = 12;
    v23 = std::operator+<wchar_t>((std::wstring *)&v71, v22, &this->trackConfigName);
    LOBYTE(v74) = 13;
    v24 = std::operator+<wchar_t>(&result, v23, L"\\data\\map.ini");
    v65 = *(float *)&v24;
    if ( &iniPath != v24 )
    {
      if ( iniPath._Myres >= 8 )
      {
        v8(iniPath._Bx._Ptr);
        v24 = (std::wstring *)LODWORD(v65);
      }
      iniPath._Myres = 7;
      iniPath._Bx._Buf[0] = 0;
      iniPath._Mysize = 0;
      std::wstring::_Assign_rv(&iniPath, v24);
    }
    if ( result._Myres >= 8 )
      v8(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v71.fileName._Mysize >= 8 )
      v8(v71.kid);
    v71.fileName._Mysize = 7;
    *(_DWORD *)&v71.fileName._Bx._Alias[12] = 0;
    LOWORD(v71.kid) = 0;
    if ( v69._Myres >= 8 )
      v8(v69._Bx._Ptr);
    LOBYTE(v74) = 6;
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
    if ( v72._Myres >= 8 )
      v8(v72._Bx._Ptr);
    v25 = std::operator+<wchar_t>(&v72, L"content\\tracks\\", v4);
    LOBYTE(v74) = 14;
    v26 = std::operator+<wchar_t>(&v69, v25, L"\\");
    LOBYTE(v74) = 15;
    v27 = std::operator+<wchar_t>((std::wstring *)&v71, v26, &this->trackConfigName);
    LOBYTE(v74) = 16;
    v28 = std::operator+<wchar_t>(&result, v27, L"\\map.png");
    LOBYTE(v74) = 17;
    v29 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &v73, v28, 0);
    LOBYTE(v74) = 18;
    v30 = v29->kid;
    v31 = &v29->fileName;
    this->map.kid = v30;
    if ( &this->map.fileName != v31 )
      std::wstring::assign(&this->map.fileName, v31, 0, 0xFFFFFFFF);
    LOBYTE(v74) = 17;
    OnSetupAppCreated::~OnSetupAppCreated(&v73);
    if ( result._Myres >= 8 )
      v8(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v71.fileName._Mysize >= 8 )
      v8(v71.kid);
    v71.fileName._Mysize = 7;
    *(_DWORD *)&v71.fileName._Bx._Alias[12] = 0;
    LOWORD(v71.kid) = 0;
    if ( v69._Myres >= 8 )
      v8(v69._Bx._Ptr);
    v69._Myres = 7;
    v69._Mysize = 0;
    v69._Bx._Buf[0] = 0;
  }
  LOBYTE(v74) = 6;
  if ( v72._Myres >= 8 )
    v8(v72._Bx._Ptr);
  v63._Myres = 7;
  v63._Mysize = 0;
  v63._Bx._Buf[0] = 0;
  std::wstring::assign(&v63, &iniPath, 0, 0xFFFFFFFF);
  v32 = this->map.kid;
  if ( v32 )
    v33 = v32[10];
  else
    v33 = 0;
  v34 = this->map.kid;
  if ( v34 )
    v35 = v34[9];
  else
    v35 = 0;
  v36 = (float)v33;
  TrackMapHandler::loadParameters(&this->tmc, (float)v35, v36, v63);
  v37 = this->map.kid;
  if ( v37 )
    v38 = v37[9];
  else
    v38 = 0;
  v39 = (float)v38;
  this->originalWidth = v39;
  v40 = this->map.kid;
  if ( v40 )
    v41 = v40[10];
  else
    v41 = 0;
  v42 = FLOAT_1_0;
  v43 = (float)v41;
  this->originalHeight = v43;
  v44 = this->map.kid;
  if ( v44 )
    v45 = v44[10];
  else
    v45 = 0;
  v46 = (double)v45;
  v47 = this->map.kid;
  v48 = v46;
  v65 = v48;
  if ( v47 )
    v49 = v47[9];
  else
    v49 = 0;
  v50 = this->maxDimensionForm;
  v51 = (double)v49;
  v52 = (int *)&v65;
  *(float *)&v51 = v51;
  v66 = LODWORD(v51);
  if ( v48 <= *(float *)&v51 )
    v52 = &v66;
  v53 = *(float *)v52;
  v54 = *(float *)v52;
  if ( *(float *)v52 > v50 )
  {
    do
    {
      v42 = v42 + 0.1;
      v54 = v53 / v42;
    }
    while ( (float)(v53 / v42) > v50 );
  }
  v55 = (int)v67;
  v56 = &this->zoomModeWidth;
  this->zoomModeWidth = v54;
  v57 = &this->zoomModeHeight;
  v58 = (unsigned int *)v56;
  v59 = *(_DWORD *)v55;
  *v57 = v54;
  v60 = 1.0 / *(float *)(v55 + 600);
  *(float *)(v55 + 612) = (float)(v54 / v39) * v60;
  v61 = (float)(v54 * 4.0) * 0.2;
  *(float *)(v55 + 620) = v54 * 0.5;
  *(float *)(v55 + 624) = v54 * 0.5;
  *(float *)(v55 + 616) = (float)(v54 / v43) * v60;
  v62 = *(float *)(v55 + 28) + (float)(v54 * 0.5);
  *(float *)(v55 + 628) = v61;
  *(float *)(v55 + 632) = v54 * 0.2;
  *(float *)(v55 + 636) = v62;
  *(float *)(v55 + 640) = *(float *)(v55 + 36) + v61;
  if ( *v56 > *v57 )
    v58 = (unsigned int *)v57;
  v63._Myres = *v58;
  if ( *v57 > *v56 )
    v56 = v57;
  (*(void (__stdcall **)(_DWORD, unsigned int))(v59 + 28))(*(_DWORD *)v56, v63._Myres);
  if ( iniPath._Myres >= 8 )
    v8(iniPath._Bx._Ptr);
}
void TrackMap::setSize(ComparativeTelemetry *this, float width, float height)
{
  ksgui::Form::setSize(this, width, height);
}
void TrackMap::showMapOnScreen(TrackMap *this)
{
  unsigned int v2; // eax
  CarAvatar *v3; // ebx
  TrackMap_vtbl *v4; // eax
  vec2f *v5; // eax
  float v6; // ecx
  _DWORD *v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  float v10; // xmm0_4
  float width; // xmm0_4
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  float v14; // xmm0_4
  GLRenderer *v15; // ecx
  float height; // [esp+14h] [ebp-40h]
  float worldCoords; // [esp+30h] [ebp-24h]
  float worldCoords_4; // [esp+34h] [ebp-20h]
  int v19[2]; // [esp+38h] [ebp-1Ch] BYREF
  float v20; // [esp+40h] [ebp-14h]
  vec3f carPosition; // [esp+44h] [ebp-10h] BYREF

  v2 = Sim::getFocusedCarIndex(this->sim);
  v3 = Sim::getCar(this->sim, v2);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->map);
  v4 = this->__vftable;
  v19[0] = 0;
  v19[1] = 0;
  v5 = v4->localToWorld(this, (vec2f *)&carPosition, (const vec2f *)v19);
  v6 = v5->x;
  worldCoords_4 = v5->y;
  v7 = this->map.kid;
  worldCoords = v6;
  if ( v7 )
    v8 = v7[10];
  else
    v8 = 0;
  if ( v7 )
    v9 = v7[9];
  else
    v9 = 0;
  v10 = (float)v8;
  height = v10;
  width = (float)v9;
  GLRenderer::quad(this->gl, worldCoords, worldCoords_4, width, height, 1, 0);
  GLRenderer::color4f(this->game->graphics->gl, 1.0, 0.0, 0.0, 1.0);
  v12 = (__m128)LODWORD(v3->physicsState.worldMatrix.M41);
  v13 = (__m128)LODWORD(v3->physicsState.worldMatrix.M42);
  v20 = v3->physicsState.worldMatrix.M43;
  *(_QWORD *)&carPosition.x = _mm_unpacklo_ps(v12, v13).m128_u64[0];
  v14 = 1.0 / this->tmc.scaleFactor;
  v15 = this->gl;
  carPosition.z = v20;
  GLRenderer::quad(
    v15,
    this->rect.left + (float)((float)(this->tmc.coordOffsetX + v12.m128_f32[0]) * v14),
    this->rect.top + (float)((float)(this->tmc.coordOffsetZ + v20) * v14),
    20.0,
    20.0,
    0,
    0);
}
void __userpurge TrackMap::render(TrackMap *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  TrackMap *v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  AISpline *v7; // esi
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  int v10; // eax
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  vec3f v15; // [esp-14h] [ebp-48h]
  vec3f v16; // [esp-8h] [ebp-3Ch]
  vec3f v17; // [esp-8h] [ebp-3Ch]
  __int64 v18; // [esp+4h] [ebp-30h]
  float v19; // [esp+Ch] [ebp-28h]
  float v20; // [esp+Ch] [ebp-28h]
  vec3f result; // [esp+10h] [ebp-24h] BYREF
  vec3f v22; // [esp+1Ch] [ebp-18h] BYREF
  float v23; // [esp+30h] [ebp-4h]

  v18 = a2;
  LODWORD(a2) = this;
  ksgui::Control::render(this, (int)this, SHIDWORD(a2), dt, v18, v19);
  HIDWORD(a2) = Sim::getCar(*(Sim **)(a2 + 324), 0);
  GraphicsManager::overrideSamplerState(*(GraphicsManager **)(*(_DWORD *)(a2 + 240) + 8), eLinearClamped);
  v5 = *(_DWORD *)(a2 + 320);
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        InterpolatingSpline::splineToWorld(&v3->aiSpline->spline, &result, v3->customCursorPosition);
        v7 = v3->aiSpline;
        v20 = Spline::length(&v7->spline);
        InterpolatingSpline::splineToWorld(&v7->spline, &v22, (float)(1.0 / v20) + v3->customCursorPosition);
        v8 = (__m128)LODWORD(result.x);
        v9 = (__m128)LODWORD(result.y);
        v8.m128_f32[0] = result.x - v22.x;
        v9.m128_f32[0] = result.y - v22.y;
        *(_QWORD *)&result.x = _mm_unpacklo_ps((__m128)LODWORD(result.x), (__m128)LODWORD(result.y)).m128_u64[0];
        *(_QWORD *)&v16.x = _mm_unpacklo_ps(v8, v9).m128_u64[0];
        v23 = result.z - v22.z;
        v16.z = result.z - v22.z;
        TrackMap::showMapOnScreenZoom(v3, result, v16);
      }
    }
    else
    {
      v10 = *(_DWORD *)(v4 + 272);
      v11 = _mm_xor_ps((__m128)*(unsigned int *)(v10 + 36), (__m128)(unsigned int)_xmm);
      v12 = (__m128)*(unsigned int *)(v10 + 52);
      v13 = _mm_xor_ps((__m128)*(unsigned int *)(v10 + 40), (__m128)(unsigned int)_xmm);
      v14 = (__m128)*(unsigned int *)(v10 + 56);
      LODWORD(v23) = *(_DWORD *)(v10 + 44) ^ _xmm;
      *(_QWORD *)&v17.x = _mm_unpacklo_ps(v11, v13).m128_u64[0];
      v17.z = v23;
      v22.z = *(float *)(v10 + 60);
      *(_QWORD *)&v15.x = _mm_unpacklo_ps(v12, v14).m128_u64[0];
      v15.z = v22.z;
      TrackMap::showMapOnScreenZoom(v3, v15, v17);
    }
  }
  else
  {
    TrackMap::showMapOnScreen(v3);
  }
  GraphicsManager::overrideSamplerState(v3->gui->graphics, eDefaultSampler);
}
void TrackMap::showMapOnScreenZoom(TrackMap *this, vec3f carPosition, vec3f carDirection)
{
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // xmm5_4
  float v17; // xmm1_4
  CarItemCmp *v18; // edi
  float v19; // xmm1_4
  unsigned int v20; // edx
  Sim *v21; // ecx
  CarAvatar *v22; // eax
  Node *v23; // eax
  CarItemCmp *v24; // ecx
  __m128 v25; // xmm2
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // edx
  float v30; // eax
  Sim *v31; // ecx
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  ksgui::GUI *v35; // ecx
  GraphicsManager *v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm5_4
  unsigned int v40; // edi
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  unsigned int v45; // xmm6_4
  CarItemCmp *v46; // ecx
  unsigned int v47; // edx
  float v48; // xmm3_4
  GLRenderer *v49; // ecx
  float v50; // ecx
  float v51; // xmm0_4
  GLRenderer *v52; // ecx
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  float v55; // xmm2_4
  float y; // xmm2_4
  float v57; // xmm1_4
  float b[7]; // [esp+10h] [ebp-84h]
  __int64 ba; // [esp+10h] [ebp-84h]
  __int64 bb; // [esp+10h] [ebp-84h]
  __int64 bc; // [esp+10h] [ebp-84h]
  float v62; // [esp+2Ch] [ebp-68h]
  float v63; // [esp+30h] [ebp-64h]
  float v64; // [esp+34h] [ebp-60h]
  float v65; // [esp+38h] [ebp-5Ch]
  float v66; // [esp+3Ch] [ebp-58h] BYREF
  float v67; // [esp+40h] [ebp-54h]
  float v68; // [esp+44h] [ebp-50h]
  unsigned __int64 v69; // [esp+48h] [ebp-4Ch]
  float v70; // [esp+50h] [ebp-44h]
  float v71; // [esp+54h] [ebp-40h]
  __int64 v72; // [esp+58h] [ebp-3Ch]
  float u; // [esp+60h] [ebp-34h]
  float v74; // [esp+64h] [ebp-30h]
  std::vector<CarItemCmp> v75; // [esp+68h] [ebp-2Ch] BYREF
  float v76; // [esp+74h] [ebp-20h]
  unsigned int index; // [esp+78h] [ebp-1Ch]
  float v78; // [esp+7Ch] [ebp-18h]
  float v79; // [esp+80h] [ebp-14h]
  int v80; // [esp+90h] [ebp-4h]

  GraphicsManager::setTexture(this->gui->graphics, 0, &this->map);
  v4 = 0.0;
  *(_QWORD *)&v75._Myfirst = *(_QWORD *)&carPosition.x;
  v5 = 1.0 / this->tmc.scaleFactor;
  v75._Myend = (CarItemCmp *)LODWORD(carPosition.z);
  v6 = this->tmc.coordOffsetX;
  v7 = this->tmc.coordOffsetZ;
  v75 = (std::vector<CarItemCmp>)carDirection;
  v8 = carDirection.z;
  v70 = carDirection.x;
  v9 = (float)((float)(v6 + carPosition.x) * v5) / this->originalWidth;
  v10 = (float)((float)(v7 + carPosition.z) * v5) / this->originalHeight;
  v11 = fsqrt((float)(v70 * v70) + (float)(v8 * v8));
  v79 = v9;
  v78 = v10;
  if ( v11 == 0.0 )
  {
    v13 = *(float *)&v75._Myfirst;
  }
  else
  {
    v12 = 1.0 / v11;
    v8 = carDirection.z * (float)(1.0 / v11);
    v13 = (float)(1.0 / v11) * *(float *)&v75._Myfirst;
    v4 = v12 * 0.0;
    v70 = v12 * *(float *)&v75._Myfirst;
  }
  v14 = (float)((float)(v13 * 0.0) + (float)(v4 * 0.0)) + v8;
  if ( v14 <= -1.0 || v14 >= 1.0 )
  {
    v15 = 0.0;
    v76 = 0.0;
  }
  else
  {
    LODWORD(v15) = __libm_sse2_acosf().m128_u32[0];
    v9 = v79;
    v10 = v78;
    v76 = v15;
  }
  v16 = _xmm;
  if ( v70 <= 0.0 )
    LODWORD(v76) = LODWORD(v15) ^ _xmm;
  v17 = this->scaledX;
  v75._Myfirst = 0;
  v18 = 0;
  v75._Mylast = 0;
  v75._Myend = 0;
  u = v9 - v17;
  *(float *)&v72 = v17 + v9;
  v19 = this->scaledZ;
  *((float *)&v72 + 1) = v10 - v19;
  v71 = v19 + v10;
  v80 = 0;
  v20 = 1;
  v21 = this->sim;
  index = 1;
  if ( (unsigned int)(v21->cars._Mylast - v21->cars._Myfirst) > 1 )
  {
    while ( 1 )
    {
      v22 = Sim::getCar(this->sim, v20);
      if ( CarAvatar::isConnected(v22) )
        break;
LABEL_24:
      v31 = this->sim;
      v20 = index + 1;
      index = v20;
      if ( v20 >= v31->cars._Mylast - v31->cars._Myfirst )
      {
        v16 = _xmm;
        goto LABEL_26;
      }
    }
    v23 = Sim::getCar(this->sim, index)->bodyTransform;
    v25 = (__m128)LODWORD(v23->matrix.M41);
    v26 = this->tmc.coordOffsetX + v25.m128_f32[0];
    v62 = v23->matrix.M43;
    v69 = _mm_unpacklo_ps(v25, (__m128)LODWORD(v23->matrix.M42)).m128_u64[0];
    v27 = 1.0 / this->tmc.scaleFactor;
    v70 = v62;
    v28 = this->zh;
    v25.m128_f32[0] = (float)((float)((float)((float)((float)((float)(this->tmc.coordOffsetZ + v62) * v27)
                                                    / this->originalHeight)
                                            - *((float *)&v72 + 1))
                                    / (float)(v71 - *((float *)&v72 + 1)))
                            * 2.0)
                    * v28;
    v66 = (float)((float)((float)((float)((float)((float)(v26 * v27) / this->originalWidth) - u)
                                / (float)(*(float *)&v72 - u))
                        * 2.0)
                * this->zw)
        - this->zw;
    v67 = v25.m128_f32[0] - v28;
    if ( &v66 >= (float *)v18 || (v24 = v75._Myfirst, v75._Myfirst > (CarItemCmp *)&v66) )
    {
      if ( v18 == v75._Myend )
      {
        std::vector<CarItemCmp>::_Reserve(&v75, (unsigned int)v24);
        v18 = v75._Mylast;
      }
      if ( !v18 )
        goto LABEL_23;
      *(float *)&v18->car = v66;
      v30 = v67;
    }
    else
    {
      LODWORD(v29) = ((char *)&v66 - (char *)v75._Myfirst) >> 3;
      v79 = v29;
      if ( v18 == v75._Myend )
      {
        std::vector<CarItemCmp>::_Reserve(&v75, (unsigned int)v75._Myfirst);
        v18 = v75._Mylast;
        v24 = v75._Myfirst;
        v29 = v79;
      }
      if ( !v18 )
        goto LABEL_23;
      v18->car = v24[LODWORD(v29)].car;
      v30 = v24[LODWORD(v29)].dist;
    }
    v18->dist = v30;
LABEL_23:
    v75._Mylast = ++v18;
    goto LABEL_24;
  }
LABEL_26:
  v32 = this->zw;
  v33 = this->zh;
  v34 = this->rect.left + v32;
  v35 = this->gui;
  v68 = v32;
  v74 = v33;
  this->xOff = v34;
  this->zOff = v33 + this->rect.top;
  v36 = v35->graphics;
  index = LODWORD(v32) ^ v16;
  LODWORD(v79) = LODWORD(v33) ^ v16;
  GraphicsManager::setCullMode(v36, eCullNone);
  LODWORD(v78) = __libm_sse2_sinf().m128_u32[0];
  v37 = __libm_sse2_cosf().m128_f32[0];
  v38 = v78;
  v39 = v37;
  v40 = v18 - v75._Myfirst;
  v41 = v79 * v78;
  v78 = (float)(v79 * v37) + (float)(*(float *)&index * v78);
  v42 = (float)(*(float *)&index * v37) - v41;
  v43 = v79 * v39;
  v44 = v79 * v38;
  v79 = v42;
  v65 = v43 + (float)(v68 * v38);
  v64 = (float)(v68 * v39) - v44;
  v63 = (float)(v74 * v39) + (float)(v68 * v38);
  v68 = (float)(v68 * v39) - (float)(v74 * v38);
  *(float *)&v45 = (float)(*(float *)&index * v39) - (float)(v74 * v38);
  v74 = (float)(v74 * v39) + (float)(*(float *)&index * v38);
  index = v45;
  if ( v40 )
  {
    v46 = v75._Myfirst;
    v47 = v40;
    do
    {
      HIDWORD(v69) = v46->car;
      v70 = v46->dist;
      v48 = (float)(v70 * v39) + (float)(*((float *)&v69 + 1) * v38);
      *((float *)&v69 + 1) = (float)(*((float *)&v69 + 1) * v39) - (float)(v70 * v38);
      v46->car = (CarAvatar *)HIDWORD(v69);
      v70 = v48;
      v46->dist = v48;
      ++v46;
      --v47;
    }
    while ( v47 );
  }
  GLRenderer::begin(this->gl, eTriangles, 0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->startingAlpha);
  v49 = this->gl;
  v76 = (float)(v71 + *((float *)&v72 + 1)) * 0.5;
  v70 = (float)(*(float *)&v72 + u) * 0.5;
  GLRenderer::texCoord2f(v49, v70, v76);
  GLRenderer::vertex3f(this->gl, this->xOff, this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, u, *((float *)&v72 + 1));
  GLRenderer::vertex3f(this->gl, this->xOff + v79, v78 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, *(float *)&v72, *((float *)&v72 + 1));
  GLRenderer::vertex3f(this->gl, this->xOff + v64, v65 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->startingAlpha);
  GLRenderer::texCoord2f(this->gl, v70, v76);
  GLRenderer::vertex3f(this->gl, this->xOff, this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, *(float *)&v72, *((float *)&v72 + 1));
  GLRenderer::vertex3f(this->gl, this->xOff + v64, v65 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, *(float *)&v72, v71);
  GLRenderer::vertex3f(this->gl, this->xOff + v68, v63 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->startingAlpha);
  GLRenderer::texCoord2f(this->gl, v70, v76);
  GLRenderer::vertex3f(this->gl, this->xOff, this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, *(float *)&v72, v71);
  GLRenderer::vertex3f(this->gl, this->xOff + v68, v63 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, u, v71);
  GLRenderer::vertex3f(this->gl, this->xOff + *(float *)&index, v74 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->startingAlpha);
  GLRenderer::texCoord2f(this->gl, v70, v76);
  GLRenderer::vertex3f(this->gl, this->xOff, this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, u, v71);
  GLRenderer::vertex3f(this->gl, this->xOff + *(float *)&index, v74 + this->zOff, 0.0);
  GLRenderer::color4f(this->gl, 1.0, 1.0, 1.0, this->finishingAlpha);
  GLRenderer::texCoord2f(this->gl, u, *((float *)&v72 + 1));
  GLRenderer::vertex3f(this->gl, this->xOff + v79, v78 + this->zOff, 0.0);
  GLRenderer::end(this->gl);
  v50 = 0.0;
  v74 = 0.0;
  if ( v40 )
  {
    do
    {
      v78 = *(float *)&v75._Myfirst[LODWORD(v50)].car + this->xOff;
      v51 = v75._Myfirst[LODWORD(v50)].dist + this->zOff;
      v52 = this->gl;
      v79 = v51;
      GLRenderer::color4f(v52, 1.0, 1.0, 1.0, 1.0);
      if ( v78 > this->rect.left && this->rect.right > v78 && v79 > this->rect.top && this->rect.bottom > v79 )
      {
        GraphicsManager::setTexture(this->game->graphics, 0, &this->adversaryIcon);
        v53.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v79 - 7.5);
        v54.m128_i32[0] = COERCE_UNSIGNED_INT(v79 - 7.5) ^ v53.m128_i32[0];
        v54.m128_f32[0] = _mm_cmplt_ss(v54, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
        v55 = (float)((float)(v79 - 7.5) + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v54.m128_i32[0] | v53.m128_i32[0]))
            - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v54.m128_i32[0] | v53.m128_i32[0]);
        v54.m128_f32[0] = v55 - (float)(v79 - 7.5);
        v54.m128_f32[0] = _mm_cmpgt_ss(v54, v53).m128_f32[0];
        v53.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v78 - 7.5);
        y = v55 - COERCE_FLOAT(v54.m128_i32[0] & LODWORD(FLOAT_1_0));
        v54.m128_i32[0] = COERCE_UNSIGNED_INT(v78 - 7.5) ^ v53.m128_i32[0];
        LODWORD(v57) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v54, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | v53.m128_i32[0];
        v54.m128_f32[0] = (float)((float)((float)(v78 - 7.5) + v57) - v57) - (float)(v78 - 7.5);
        GLRenderer::quad(
          this->gl,
          (float)((float)((float)(v78 - 7.5) + v57) - v57)
        - COERCE_FLOAT(_mm_cmpgt_ss(v54, v53).m128_u32[0] & LODWORD(FLOAT_1_0)),
          y,
          15.0,
          15.0,
          1,
          0);
      }
      LODWORD(v50) = LODWORD(v74) + 1;
      v74 = v50;
    }
    while ( LODWORD(v50) < v40 );
  }
  GLRenderer::color4f(this->game->graphics->gl, 1.0, 0.0, 0.0, 1.0);
  GLRenderer::begin(this->gl, eTriangles, 0);
  *(_QWORD *)b = COERCE_UNSIGNED_INT(this->zOff - (float)(this->sizeIcon * 0.5));
  GLRenderer::vertex3f(this->gl, this->xOff, b[0], b[1]);
  ba = COERCE_UNSIGNED_INT(this->sizeIcon + this->zOff);
  GLRenderer::vertex3f(this->gl, this->sizeIcon + this->xOff, *(float *)&ba, *((float *)&ba + 1));
  GLRenderer::vertex3f(
    this->gl,
    this->xOff - (float)(this->sizeIcon * 0.5),
    (float)(this->sizeIcon * 0.5) + this->zOff,
    0.0);
  GLRenderer::end(this->gl);
  GLRenderer::begin(this->gl, eTriangles, 0);
  bb = COERCE_UNSIGNED_INT(this->zOff - (float)(this->sizeIcon * 0.5));
  GLRenderer::vertex3f(this->gl, this->xOff, *(float *)&bb, *((float *)&bb + 1));
  bc = COERCE_UNSIGNED_INT(this->sizeIcon + this->zOff);
  GLRenderer::vertex3f(this->gl, this->xOff - this->sizeIcon, *(float *)&bc, *((float *)&bc + 1));
  GLRenderer::vertex3f(
    this->gl,
    (float)(this->sizeIcon * 0.5) + this->xOff,
    (float)(this->sizeIcon * 0.5) + this->zOff,
    0.0);
  GLRenderer::end(this->gl);
  GraphicsManager::setCullMode(this->gui->graphics, eCullFront);
  if ( v75._Myfirst )
    operator delete(v75._Myfirst);
}
void TrackMap::~TrackMap(TrackMap *this)
{
  TrackMapHandler *v2; // edi

  this->__vftable = (TrackMap_vtbl *)&TrackMap::`vftable';
  v2 = &this->tmc;
  this->tmc.pointsToDraw._Mylast = this->tmc.pointsToDraw._Myfirst;
  OnSetupAppCreated::~OnSetupAppCreated(&this->tmc.roadTexture);
  if ( v2->pointsToDraw._Myfirst )
  {
    operator delete(v2->pointsToDraw._Myfirst);
    v2->pointsToDraw._Myfirst = 0;
    v2->pointsToDraw._Mylast = 0;
    v2->pointsToDraw._Myend = 0;
  }
  if ( this->carModel._Myres >= 8 )
    operator delete(this->carModel._Bx._Ptr);
  this->carModel._Myres = 7;
  this->carModel._Mysize = 0;
  this->carModel._Bx._Buf[0] = 0;
  if ( this->trackConfigName._Myres >= 8 )
    operator delete(this->trackConfigName._Bx._Ptr);
  this->trackConfigName._Myres = 7;
  this->trackConfigName._Mysize = 0;
  this->trackConfigName._Bx._Buf[0] = 0;
  if ( this->trackName._Myres >= 8 )
    operator delete(this->trackName._Bx._Ptr);
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&this->map);
  OnSetupAppCreated::~OnSetupAppCreated(&this->adversaryIcon);
  this->__vftable = (TrackMap_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
