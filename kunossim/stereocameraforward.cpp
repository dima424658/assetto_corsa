#include "stereocameraforward.h
void __userpurge StereoCameraForward::StereoCameraForward(StereoCameraForward *this@<ecx>, unsigned int a2@<ebx>, int a3@<ebp>, const std::wstring *iname, GraphicsManager *graphics, bool auseBlur, bool isYebis)
{
  std::wstring *v8; // eax
  Shader *v9; // eax
  bool v10; // cf
  int v11; // edi
  float v12; // xmm0_4
  char v13; // al
  int v14; // eax
  const __m128i *v15; // ecx
  int v16; // esi
  int v17; // edi
  ovrSizei_ v18; // kr00_8
  OculusTexture *v19; // eax
  OculusTexture *v20; // eax
  int v21; // eax
  GraphicsManager *v22; // esi
  _DWORD *v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  YebisPP *v28; // eax
  YebisPP *v29; // ecx
  int v30; // eax
  RenderTarget *v31; // eax
  int v32; // eax
  RenderTarget *v33; // eax
  int v34; // eax
  RenderTarget *v35; // eax
  int v36; // eax
  RenderTarget *v37; // eax
  int v38; // eax
  RenderTarget *v39; // eax
  int v40; // eax
  RenderTarget *v41; // eax
  int v42; // eax
  RenderTarget *v43; // eax
  int v44; // eax
  Shader *v45; // eax
  YebisPP *v46; // ecx
  std::vector<TyreThermalPatch *> *v47; // esi
  ID3D11Device *v48; // eax
  TyreThermalPatch **v49; // ecx
  TyreThermalPatch **v50; // edx
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // edx
  _DWORD *v55; // ecx
  int v56; // eax
  TyreThermalPatch **v57; // edx
  int v58; // ecx
  unsigned int v59; // edx
  unsigned int v60; // edx
  void *v61; // eax
  _BYTE v62[28]; // [esp-14h] [ebp-2E4h] BYREF
  ovrHmdDesc_ result; // [esp+14h] [ebp-2BCh] BYREF
  StereoCameraForward *v64; // [esp+114h] [ebp-1BCh]
  float pixelsPerDisplayPixel; // [esp+118h] [ebp-1B8h]
  int sizeW; // [esp+11Ch] [ebp-1B4h]
  GraphicsManager *v67; // [esp+120h] [ebp-1B0h]
  int length; // [esp+124h] [ebp-1ACh] BYREF
  void *ppObject; // [esp+128h] [ebp-1A8h] BYREF
  int v70; // [esp+12Ch] [ebp-1A4h] BYREF
  OculusTexture **v71; // [esp+130h] [ebp-1A0h]
  unsigned int _Count; // [esp+134h] [ebp-19Ch]
  int sizeH; // [esp+138h] [ebp-198h]
  char v74; // [esp+13Fh] [ebp-191h]
  RenderTarget *v75; // [esp+140h] [ebp-190h]
  int currentIndex; // [esp+144h] [ebp-18Ch] BYREF
  YebisPP *v77; // [esp+148h] [ebp-188h]
  char v78[256]; // [esp+14Ch] [ebp-184h] BYREF
  INIReaderDocuments v79; // [esp+24Ch] [ebp-84h] BYREF
  std::wstring name; // [esp+290h] [ebp-40h] BYREF
  std::wstring key; // [esp+2A8h] [ebp-28h] BYREF
  int v82; // [esp+2CCh] [ebp-4h]

  currentIndex = (int)this;
  LOBYTE(v77) = auseBlur;
  v64 = this;
  v67 = graphics;
  CameraForward::CameraForward(this, iname, graphics, auseBlur);
  this->__vftable = (StereoCameraForward_vtbl *)&StereoCameraForward::`vftable';
  this->debugString._Myres = 7;
  this->debugString._Mysize = 0;
  v82 = 0;
  this->debugString._Bx._Buf[0] = 0;
  *(_WORD *)&this->renderScene = 257;
  this->ovrExposure = 50.0;
  this->ovrMinExposure = 0.60000002;
  strcpy((char *)&this->ovrMaxExposure, "��L?");
  this->defaultPosition.x = 0.0;
  this->defaultPosition.y = 0.0;
  this->defaultPosition.z = 0.0;
  this->depthResolveShader = 0;
  mat44f::mat44f(&this->projMatrix);
  mat44f::mat44f(&this->viewMatrix);
  mat44f::mat44f(&this->defaultHeadOrientation);
  Trigger::Trigger(&this->renderUITrigger);
  this->font = 0;
  this->frameIndex = 0i64;
  this->fxaaShader = 0;
  this->yebisPP._Myptr = 0;
  this->rtYebisResolved = 0;
  this->rtYebisResolvedDepth = 0;
  this->rtTempAA = 0;
  _Count = (unsigned int)&this->mirrorTextureBuffers;
  this->mirrorTextureBuffers._Myfirst = 0;
  this->mirrorTextureBuffers._Mylast = 0;
  this->mirrorTextureBuffers._Myend = 0;
  this->renderUI = 1;
  this->lodMultiplier = 0.5;
  LOBYTE(v82) = 4;
  if ( !initialized )
  {
    if ( ovr_Initialize(a3, 0) >= 0 )
    {
      if ( ovr_Create(&session, &luid) >= 0 )
      {
        initialized = 1;
        goto LABEL_11;
      }
      ovr_Shutdown();
    }
    else
    {
      _printf("ERROR: ovr_Initialize failed\n");
    }
    std::wstring::wstring(&key, L"Could not initialize oculus");
    v8 = &key;
    LOBYTE(v82) = 5;
    if ( key._Myres >= 8 )
      v8 = (std::wstring *)key._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v8->_Bx._Buf);
    ksGenerateCrash();
    LOBYTE(v82) = 4;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
LABEL_11:
  qmemcpy(v78, ovr_GetHmdDesc(&result, session), sizeof(v78));
  if ( !v78[4] )
  {
    *(_DWORD *)&v62[24] = 7;
    *(_DWORD *)&v62[20] = 0;
    *(_WORD *)&v62[4] = 0;
    std::wstring::assign((std::wstring *)&v62[4], L"FAILED Rift detected, display not enabled.", 0x2Au);
    ksGenerateCrash(*(std::wstring *)&v62[4]);
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksMSDepthResolve", 0x10u);
  LOBYTE(v82) = 6;
  v9 = GraphicsManager::getShader(v67, a2, &name);
  v10 = name._Myres < 8;
  v11 = currentIndex;
  LOBYTE(v82) = 4;
  *(_DWORD *)(currentIndex + 1744) = v9;
  if ( !v10 )
    operator delete(name._Bx._Ptr);
  *(_DWORD *)&v62[24] = 0;
  *(_DWORD *)&v62[20] = 7;
  *(_DWORD *)&v62[16] = 0;
  *(_WORD *)v62 = 0;
  std::wstring::assign((std::wstring *)v62, L"cfg/oculus.ini", 0xEu);
  INIReaderDocuments::INIReaderDocuments(&v79, a2, *(std::wstring *)v62, v62[24]);
  v12 = FLOAT_1_0;
  LOBYTE(v82) = 7;
  pixelsPerDisplayPixel = FLOAT_1_0;
  if ( v79.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PIXEL_PER_DISPLAY", 0x11u);
    LOBYTE(v82) = 8;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"SETTINGS", 8u);
    LOBYTE(v82) = 9;
    *(float *)&sizeH = INIReader::getFloat(&v79, &name, &key);
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v82) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIRROR_TEXTURE", 0xEu);
    LOBYTE(v82) = 10;
    v13 = INIReader::hasSection(&v79, &key);
    v74 = v13;
    LOBYTE(v82) = 7;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v13 = v74;
    }
    if ( v13 )
    {
      std::wstring::wstring(&name, L"ENABLED");
      LOBYTE(v82) = 11;
      std::wstring::wstring(&key, L"MIRROR_TEXTURE");
      LOBYTE(v82) = 12;
      v14 = INIReader::getInt(&v79, &key, &name);
      v10 = key._Myres < 8;
      *(_BYTE *)(v11 + 1705) = v14 != 0;
      if ( !v10 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v82) = 7;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
    }
    v12 = *(float *)&sizeH;
    LODWORD(pixelsPerDisplayPixel) = sizeH;
  }
  _printf("Pixel per display: %f\n", v12);
  v15 = (const __m128i *)&v78[180];
  v71 = (OculusTexture **)(v11 + 2100);
  v16 = v11 + 2016;
  v77 = (YebisPP *)&v78[180];
  v17 = 0;
  do
  {
    *(float *)&v62[24] = pixelsPerDisplayPixel;
    v18 = ovr_GetFovTextureSize(session, (ovrEyeType_)v17, (ovrFovPort_)_mm_loadu_si128(v15), pixelsPerDisplayPixel);
    sizeH = v18.h;
    sizeW = v18.w;
    _printf("Ideal size %d %d\n", v18.w, v18.h);
    v19 = (OculusTexture *)operator new(32);
    if ( v19 )
    {
      v19->Session = 0;
      v19->TextureChain = 0;
      v19->TexRtv._Myfirst = 0;
      v19->TexRtv._Mylast = 0;
      v19->TexRtv._Myend = 0;
      v19->txResource._Myfirst = 0;
      v19->txResource._Mylast = 0;
      v19->txResource._Myend = 0;
    }
    else
    {
      v19 = 0;
    }
    *(_DWORD *)&v62[24] = sizeH;
    *(_DWORD *)&v62[20] = sizeW;
    *v71 = v19;
    if ( !OculusTexture::Init(v19, session, *(int *)&v62[20], *(int *)&v62[24]) )
    {
      *(_DWORD *)&v62[24] = 7;
      *(_DWORD *)&v62[20] = 0;
      *(_WORD *)&v62[4] = 0;
      std::wstring::assign((std::wstring *)&v62[4], L"OculusTexture->Init failed", 0x1Au);
      ksGenerateCrash(*(std::wstring *)&v62[4]);
    }
    kglCreateRenderTargetDepth(sizeW, sizeH, 1, 1);
    *(_DWORD *)&v62[8] = v20;
    *(_DWORD *)&v62[4] = v17;
    *(_DWORD *)v62 = "pEyeDepthBuffer %d %d\n";
    v71[2] = v20;
    _printf(*(const char *const *)v62, *(_DWORD *)&v62[4], *(_DWORD *)&v62[8]);
    *(_DWORD *)(v16 + 4) = sizeW;
    *(float *)(v16 + 8) = *(float *)&sizeH;
    v21 = (int)v71;
    *(_DWORD *)(v16 - 4) = 0;
    *(_DWORD *)v16 = 0;
    if ( !*(_DWORD *)(*(_DWORD *)v21 + 4) )
    {
      *(_DWORD *)&v62[24] = 7;
      *(_DWORD *)&v62[20] = 0;
      *(_WORD *)&v62[4] = 0;
      std::wstring::assign((std::wstring *)&v62[4], L"OculusTexture->Init failed to create swap chain", 0x2Fu);
      ksGenerateCrash(*(std::wstring *)&v62[4]);
    }
    ++v17;
    ++v71;
    v15 = (const __m128i *)&v77->pp.destinationRenderTarget;
    v16 += 16;
    v77 = (YebisPP *)((char *)v77 + 16);
  }
  while ( v17 < 2 );
  v22 = v67;
  v23 = (_DWORD *)currentIndex;
  if ( v67->videoSettings.ppHDREnabled )
  {
    *(_DWORD *)&v62[24] = 1648;
    v67->videoSettings.ppHeatShimmer = 0;
    v77 = (YebisPP *)operator new(*(_DWORD *)&v62[24]);
    LOBYTE(v82) = 13;
    if ( v77 )
    {
      v24 = v23[525];
      currentIndex = 0;
      ovr_GetTextureSwapChainCurrentIndex(
        *(struct ovrHmdStruct **)v24,
        *(struct ovrTextureSwapChainData **)(v24 + 4),
        &currentIndex);
      v25 = *(_DWORD *)(v24 + 8);
      v22 = v67;
      YebisPP::YebisPP(v77, v67, v23[505], v23[506], *(ID3D11RenderTargetView **)(v25 + 4 * currentIndex));
      v27 = v26;
    }
    else
    {
      v27 = 0;
    }
    v28 = (YebisPP *)v23[560];
    LOBYTE(v82) = 7;
    currentIndex = (int)v28;
    v23[560] = v27;
    if ( v28 )
    {
      YebisPP::~YebisPP(v28);
      operator delete(currentIndex);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"default", 7u);
    v29 = (YebisPP *)v23[560];
    LOBYTE(v82) = 14;
    YebisPP::loadPPSet(v29, &key);
    LOBYTE(v82) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v30 = v23[560];
    *(_DWORD *)&v62[24] = 28;
    *(_DWORD *)(v30 + 1192) = 0;
    if ( v22->videoSettings.aaSamples == 1 )
    {
      v31 = (RenderTarget *)operator new(*(_DWORD *)&v62[24]);
      v75 = v31;
      LOBYTE(v82) = 15;
      if ( v31 )
      {
        RenderTarget::RenderTarget(v31, v22, eR16G16B16A16, v23[505], v23[506], 1, 1, 1);
        v23[561] = v32;
      }
      else
      {
        v23[561] = 0;
      }
    }
    else
    {
      v33 = (RenderTarget *)operator new(*(_DWORD *)&v62[24]);
      v75 = v33;
      LOBYTE(v82) = 16;
      if ( v33 )
        RenderTarget::RenderTarget(v33, v22, eR16G16B16A16_MS, v23[505], v23[506], 1, 1, 1);
      else
        v34 = 0;
      *(_DWORD *)&v62[24] = 28;
      LOBYTE(v82) = 7;
      v23[561] = v34;
      v35 = (RenderTarget *)operator new(*(_DWORD *)&v62[24]);
      v75 = v35;
      LOBYTE(v82) = 17;
      if ( v35 )
        RenderTarget::RenderTarget(v35, v22, eR16G16B16A16, v23[505], v23[506], 1, 1, 1);
      else
        v36 = 0;
      *(_DWORD *)&v62[24] = 28;
      LOBYTE(v82) = 7;
      v23[562] = v36;
      v37 = (RenderTarget *)operator new(*(_DWORD *)&v62[24]);
      v75 = v37;
      LOBYTE(v82) = 18;
      if ( v37 )
      {
        RenderTarget::RenderTarget(v37, v22, eR32F, v23[505], v23[506], 1, 0, 1);
        v23[563] = v38;
      }
      else
      {
        v23[563] = 0;
      }
    }
    goto LABEL_63;
  }
  if ( v67->videoSettings.aaSamples > 1 )
  {
    v39 = (RenderTarget *)operator new(28);
    v75 = v39;
    LOBYTE(v82) = 19;
    if ( v39 )
      RenderTarget::RenderTarget(v39, v22, eR8G8B8A8_MS, v23[505], v23[506], 1, 1, 1);
    else
      v40 = 0;
    v23[564] = v40;
LABEL_63:
    LOBYTE(v82) = 7;
  }
  if ( v22->videoSettings.ppFXAA && v22->videoSettings.aaSamples == 1 )
  {
    v41 = (RenderTarget *)operator new(28);
    v75 = v41;
    LOBYTE(v82) = 20;
    if ( v41 )
      RenderTarget::RenderTarget(v41, v22, eR8G8B8A8, v23[505], v23[506], 1, 0, 1);
    else
      v42 = 0;
    *(_DWORD *)&v62[24] = 28;
    LOBYTE(v82) = 7;
    v23[500] = v42;
    v43 = (RenderTarget *)operator new(*(_DWORD *)&v62[24]);
    v75 = v43;
    LOBYTE(v82) = 21;
    if ( v43 )
      RenderTarget::RenderTarget(v43, v22, eR8G8B8A8, v23[505], v23[506], 1, 0, 1);
    else
      v44 = 0;
    v23[501] = v44;
    LOBYTE(v82) = 7;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ksFXAA", 6u);
    LOBYTE(v82) = 22;
    v45 = GraphicsManager::getShader(v22, a2, &key);
    v10 = key._Myres < 8;
    v23[502] = v45;
    LOBYTE(v82) = 7;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    v23[500] = 0;
    v23[501] = 0;
  }
  *(_DWORD *)&v62[24] = 0;
  v22->videoSettings.vSync = 0;
  kglSetVSync(*(int *)&v62[24]);
  ppObject = 0;
  ovr_GetTextureSwapChainLength(session, *(struct ovrTextureSwapChainData **)(v23[525] + 4), &length);
  _printf("OVR SWAP CHAIN LEN: %d\n", length);
  v46 = 0;
  v77 = 0;
  if ( length > 0 )
  {
    v47 = (std::vector<TyreThermalPatch *> *)_Count;
    do
    {
      ovr_GetTextureSwapChainBufferDX(
        session,
        *(struct ovrTextureSwapChainData **)(v23[525] + 4),
        (int)v46,
        (_GUID)_mm_loadu_si128((const __m128i *)&_GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c),
        &ppObject);
      key._Bx._Ptr = (wchar_t *)28;
      *(_QWORD *)&key._Mysize = 0i64;
      *(_DWORD *)&key._Bx._Alias[12] = 1;
      *(_QWORD *)&key._Bx._Alias[4] = 4i64;
      v48 = kglGetNativeDevice();
      v48->CreateShaderResourceView(
        v48,
        (ID3D11Resource *)ppObject,
        (const D3D11_SHADER_RESOURCE_VIEW_DESC *)&key,
        (ID3D11ShaderResourceView **)&v70);
      v49 = v47->_Mylast;
      if ( &v70 >= (int *)v49 || v47->_Myfirst > (TyreThermalPatch **)&v70 )
      {
        v57 = v47->_Myend;
        if ( v49 == v57 && !(v57 - v49) )
        {
          v58 = v49 - v47->_Myfirst;
          if ( v58 == 0x3FFFFFFF )
LABEL_105:
            std::_Xlength_error("vector<T> too long");
          v59 = v57 - v47->_Myfirst;
          _Count = v58 + 1;
          if ( 0x3FFFFFFF - (v59 >> 1) >= v59 )
            v60 = (v59 >> 1) + v59;
          else
            v60 = 0;
          if ( v60 < _Count )
            v60 = _Count;
          std::vector<ID3D11ShaderResourceView *>::_Reallocate(v47, v60);
        }
        v55 = v47->_Mylast;
        if ( !v55 )
          goto LABEL_103;
        v56 = v70;
      }
      else
      {
        v50 = v47->_Myend;
        v51 = ((char *)&v70 - (char *)v47->_Myfirst) >> 2;
        currentIndex = v51;
        if ( v49 == v50 )
        {
          if ( !(v50 - v49) )
          {
            v52 = v49 - v47->_Myfirst;
            if ( v52 == 0x3FFFFFFF )
              goto LABEL_105;
            v53 = v50 - v47->_Myfirst;
            _Count = v52 + 1;
            if ( 0x3FFFFFFF - (v53 >> 1) >= v53 )
              v54 = (v53 >> 1) + v53;
            else
              v54 = 0;
            if ( v54 < _Count )
              v54 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v47, v54);
          }
          v51 = currentIndex;
        }
        v55 = v47->_Mylast;
        if ( !v55 )
          goto LABEL_103;
        v56 = (int)v47->_Myfirst[v51];
      }
      *v55 = v56;
LABEL_103:
      v61 = ppObject;
      ++v47->_Mylast;
      (*(void (__stdcall **)(void *))(*(_DWORD *)v61 + 8))(v61);
      v46 = (YebisPP *)((char *)&v77->width + 1);
      v77 = v46;
    }
    while ( (int)v46 < length );
  }
  LOBYTE(v82) = 4;
  INIReaderDocuments::~INIReaderDocuments(&v79);
}
void StereoCameraForward::~StereoCameraForward(StereoCameraForward *this)
{
  RenderTarget *v2; // ecx
  Font *v3; // edi
  std::vector<ID3D11ShaderResourceView *> *v4; // edi
  YebisPP *v5; // edi

  this->__vftable = (StereoCameraForward_vtbl *)&StereoCameraForward::`vftable';
  v2 = this->rtTempAA;
  if ( v2 )
    ((void (*)(RenderTarget *, int))v2->~RenderTarget)(v2, 1);
  v3 = this->font;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)this->font);
    operator delete(v3);
  }
  v4 = &this->mirrorTextureBuffers;
  if ( this->mirrorTextureBuffers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->mirrorTextureBuffers);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->mirrorTextureBuffers._Mylast = 0;
    this->mirrorTextureBuffers._Myend = 0;
  }
  v5 = this->yebisPP._Myptr;
  if ( v5 )
  {
    YebisPP::~YebisPP(v5);
    operator delete(v5);
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->renderUITrigger);
  if ( this->debugString._Myres >= 8 )
    operator delete(this->debugString._Bx._Ptr);
  this->debugString._Myres = 7;
  this->debugString._Mysize = 0;
  this->debugString._Bx._Buf[0] = 0;
  CameraForward::~CameraForward(this);
}
StereoCameraForward *StereoCameraForward::`vector deleting destructor'(StereoCameraForward *this, unsigned int a2)
{
  StereoCameraForward::~StereoCameraForward(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
mat44f *__userpurge StereoCameraForward::computeCameraMatrix@<eax>(StereoCameraForward *this@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, mat44f *result, int eyeRenderPose, int eyeRenderPose_4, int eyeRenderPose_8, int eyeRenderPose_12, __int128 eyeRenderPose_16)
{
  __m128 v10; // xmm1
  unsigned int v11; // xmm0_4
  __m128 v12; // xmm1
  float v13; // xmm0_4
  __m128i v14; // xmm2
  __m128i v15; // xmm3
  float v16; // xmm0_4
  __int128 v17; // xmm1
  __int128 v18; // xmm2
  float v19; // xmm0_4
  __int128 v20; // xmm3
  mat44f *v21; // eax
  float v22; // [esp+Ch] [ebp-7Ch]
  float v23; // [esp+10h] [ebp-78h]
  float v24; // [esp+14h] [ebp-74h]
  __m128 Quaternion; // [esp+18h] [ebp-70h] BYREF
  ovrVector3f_ v26; // [esp+38h] [ebp-50h]
  DirectX::XMMATRIX M2; // [esp+48h] [ebp-40h] BYREF

  Quaternion = (__m128)_mm_loadu_si128((const __m128i *)&eyeRenderPose);
  v26 = (ovrVector3f_)eyeRenderPose_16;
  mat44f::createIdentity(result);
  v10 = (__m128)_mm_load_si128((const __m128i *)&Quaternion);
  Quaternion.m128_i32[0] = v10.m128_i32[0];
  Quaternion.m128_i32[1] = _mm_shuffle_ps(v10, v10, 85).m128_u32[0];
  v11 = _mm_shuffle_ps(v10, v10, 170).m128_u32[0];
  v12 = _mm_shuffle_ps(v10, v10, 255);
  Quaternion.m128_u64[1] = __PAIR64__(v12.m128_u32[0], v11);
  *(__m128 *)&result->M11 = DirectX::XMMatrixRotationQuaternion(Quaternion);
  v13 = v26.x;
  *(__m128 *)&result->M21 = v12;
  *(_OWORD *)&result->M31 = a2;
  *(_OWORD *)&result->M41 = a3;
  v14 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  v15 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  v23 = v13 - this->defaultPosition.x;
  v16 = v26.y - this->defaultPosition.y;
  M2.r[0] = (__m128)_mm_loadu_si128((const __m128i *)&this->matrix);
  v17 = *(_OWORD *)&result->M21;
  M2.r[1] = (__m128)v14;
  v18 = *(_OWORD *)&result->M31;
  v24 = v16;
  v19 = v26.z - this->defaultPosition.z;
  M2.r[2] = (__m128)v15;
  v20 = *(_OWORD *)&result->M41;
  v22 = v19;
  M2.r[3].m128_i32[3] = HIDWORD(*(unsigned __int128 *)&_mm_loadu_si128((const __m128i *)&this->matrix.M41));
  M2.r[3].m128_u64[0] = 0i64;
  M2.r[3].m128_i32[2] = 0;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&result->M11);
  *(_OWORD *)&result->M21 = v17;
  *(_OWORD *)&result->M31 = v18;
  *(_OWORD *)&result->M41 = v20;
  v21 = result;
  *(float *)&v18 = (float)((float)((float)(this->matrix.M22 * v24) + (float)(this->matrix.M12 * v23))
                         + (float)(this->matrix.M32 * v22))
                 + this->matrix.M42;
  *(float *)&v17 = (float)((float)((float)(this->matrix.M23 * v24) + (float)(this->matrix.M13 * v23))
                         + (float)(this->matrix.M33 * v22))
                 + this->matrix.M43;
  result->M41 = (float)((float)((float)(this->matrix.M21 * v24) + (float)(this->matrix.M11 * v23))
                      + (float)(this->matrix.M31 * v22))
              + this->matrix.M41;
  LODWORD(result->M42) = v18;
  LODWORD(result->M43) = v17;
  return v21;
}
void __usercall StereoCameraForward::computeEyePoses(StereoCameraForward *this@<ecx>, int a2@<ebp>)
{
  const __m128i *v3; // eax
  __m128i v4; // xmm1
  __m128i v5; // xmm2
  __int64 v6; // xmm3_8
  ovrFovPort_ v7; // xmm0
  const __m128i *v8; // eax
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  __m128i v11; // xmm2
  __int64 v12; // xmm3_8
  float v13; // eax
  ovrEyeRenderDesc_ v14; // [esp+Ch] [ebp-254h] BYREF
  ovrHmdDesc_ sess_desc; // [esp+44h] [ebp-21Ch] BYREF
  ovrHmdDesc_ result; // [esp+144h] [ebp-11Ch] BYREF
  ovrVector3f_ HmdToEyeOffset[2]; // [esp+244h] [ebp-1Ch] BYREF

  qmemcpy(&sess_desc, ovr_GetHmdDesc(&result, session), sizeof(sess_desc));
  v3 = (const __m128i *)ovr_GetRenderDesc(
                          &v14,
                          session,
                          ovrEye_Left,
                          (ovrFovPort_)_mm_loadu_si128((const __m128i *)sess_desc.DefaultEyeFov));
  v4 = _mm_loadu_si128(v3 + 1);
  v5 = _mm_loadu_si128(v3 + 2);
  v6 = v3[3].m128i_i64[0];
  *(__m128i *)&this->eyeRenderDesc[0].Eye = _mm_loadu_si128(v3);
  v7 = (ovrFovPort_)_mm_loadu_si128((const __m128i *)&sess_desc.DefaultEyeFov[1]);
  *(__m128i *)&this->eyeRenderDesc[0].Fov.RightTan = v4;
  *(__m128i *)&this->eyeRenderDesc[0].DistortedViewport.Size.h = v5;
  *(_QWORD *)&this->eyeRenderDesc[0].HmdToEyeOffset.y = v6;
  v8 = (const __m128i *)ovr_GetRenderDesc(&v14, session, ovrEye_Right, v7);
  v9 = _mm_loadu_si128(v8);
  v10 = _mm_loadu_si128(v8 + 1);
  v11 = _mm_loadu_si128(v8 + 2);
  v12 = v8[3].m128i_i64[0];
  v13 = this->eyeRenderDesc[0].HmdToEyeOffset.z;
  *(__m128i *)&this->eyeRenderDesc[1].Eye = v9;
  HmdToEyeOffset[0].z = v13;
  v9.m128i_i64[0] = *(_QWORD *)&this->eyeRenderDesc[0].HmdToEyeOffset.x;
  *(__m128i *)&this->eyeRenderDesc[1].Fov.RightTan = v10;
  *(__m128i *)&this->eyeRenderDesc[1].DistortedViewport.Size.h = v11;
  *(_QWORD *)&this->eyeRenderDesc[1].HmdToEyeOffset.y = v12;
  HmdToEyeOffset[1].z = this->eyeRenderDesc[1].HmdToEyeOffset.z;
  *(_QWORD *)&HmdToEyeOffset[0].x = v9.m128i_i64[0];
  *(_QWORD *)&HmdToEyeOffset[1].x = *(_QWORD *)&this->eyeRenderDesc[1].HmdToEyeOffset.x;
  ovr_GetEyePoses(a2, session, this->frameIndex, 1, HmdToEyeOffset, this->eyeRenderPoses, &this->sensorSampleTime);
}
void StereoCameraForward::finishRendering(StereoCameraForward *this)
{
  ovrHmdDesc_ *v2; // eax
  __m128i v3; // xmm0
  ovrHmdDesc_ *v4; // esi
  long double v5; // xmm1_8
  OculusTexture *v6; // eax
  struct ovrTextureSwapChainData *v7; // eax
  __m128i v8; // xmm0
  OculusTexture *v9; // eax
  ovrQuatf_ v10; // xmm0
  __m128i v11; // xmm0
  __int64 v12; // [esp-28h] [ebp-2D4h]
  ovrLayerHeader_ *layers; // [esp+Ch] [ebp-2A0h] BYREF
  ovrSessionStatus_ sessionStatus; // [esp+10h] [ebp-29Ch] BYREF
  ovrHmdDesc_ result; // [esp+18h] [ebp-294h] BYREF
  ovrLayerEyeFov_ ld; // [esp+118h] [ebp-194h] BYREF
  ovrHmdDesc_ sess_desc; // [esp+1A8h] [ebp-104h] BYREF

  memset(&ld, 0, sizeof(ld));
  ld.Header.Type = ovrLayerType_EyeFov;
  ld.Header.Flags = 0;
  v2 = ovr_GetHmdDesc(&result, session);
  v3 = _mm_loadu_si128((const __m128i *)this->eyeRenderViewport);
  v4 = v2;
  v5 = this->sensorSampleTime;
  v6 = this->pEyeRenderTexture[0];
  qmemcpy(&sess_desc, v4, sizeof(sess_desc));
  v7 = v6->TextureChain;
  ld.Viewport[0] = (ovrRecti_)v3;
  ld.ColorTexture[0] = v7;
  v8 = _mm_loadu_si128((const __m128i *)sess_desc.DefaultEyeFov);
  ld.RenderPose[0].Position.z = this->eyeRenderPoses[0].Position.z;
  v9 = this->pEyeRenderTexture[1];
  ld.Fov[0] = (ovrFovPort_)v8;
  v10 = (ovrQuatf_)_mm_loadu_si128((const __m128i *)this->eyeRenderPoses);
  ld.SensorSampleTime = v5;
  ld.RenderPose[0].Orientation = v10;
  *(_QWORD *)&ld.RenderPose[0].Position.x = *(_QWORD *)&this->eyeRenderPoses[0].Position.x;
  v11 = _mm_loadu_si128((const __m128i *)&this->eyeRenderViewport[1]);
  ld.ColorTexture[1] = v9->TextureChain;
  ld.RenderPose[1].Position.z = this->eyeRenderPoses[1].Position.z;
  ld.Viewport[1] = (ovrRecti_)v11;
  layers = (ovrLayerHeader_ *)&ld;
  HIDWORD(v12) = HIDWORD(this->frameIndex);
  ld.Fov[1] = (ovrFovPort_)_mm_loadu_si128((const __m128i *)&sess_desc.DefaultEyeFov[1]);
  LODWORD(v12) = this->frameIndex;
  ld.RenderPose[1].Orientation = (ovrQuatf_)_mm_loadu_si128((const __m128i *)&this->eyeRenderPoses[1]);
  *(_QWORD *)&ld.RenderPose[1].Position.x = *(_QWORD *)&this->eyeRenderPoses[1].Position.x;
  ld.SensorSampleTime = v5;
  ovr_SubmitFrame(session, v12, 0, (const ovrLayerHeader_ *const *)&layers, 1u);
  ++this->frameIndex;
  kglSwapBuffers();
  ovr_GetSessionStatus(session, &sessionStatus);
  if ( sessionStatus.ShouldRecenter )
    ovr_RecenterTrackingOrigin(session);
}
mat44f *__userpurge StereoCameraForward::getFinalWorldMatrix@<eax>(StereoCameraForward *this@<ecx>, int a2@<ebp>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, mat44f *result)
{
  __m128i v6; // xmm0
  float v7; // eax
  __int128 v9; // [esp-10h] [ebp-20h]
  vec3f aViewAdjust; // [esp+4h] [ebp-Ch] BYREF

  StereoCameraForward::computeEyePoses(this, a2);
  v6 = _mm_loadu_si128((const __m128i *)this->eyeRenderPoses);
  aViewAdjust.x = 0.0;
  v7 = this->eyeRenderPoses[0].Position.z;
  aViewAdjust.y = 0.0;
  aViewAdjust.z = 0.0;
  *(_QWORD *)&v9 = *(_QWORD *)&this->eyeRenderPoses[0].Position.x;
  *((_QWORD *)&v9 + 1) = __PAIR64__(&aViewAdjust, LODWORD(v7));
  StereoCameraForward::computeCameraMatrix(
    this,
    a3,
    a4,
    result,
    v6.m128i_i32[0],
    v6.m128i_i32[1],
    v6.m128i_i32[2],
    v6.m128i_i32[3],
    v9);
  return result;
}
mat44f *StereoCameraForward::getPerspectiveMatrix(StereoCameraForward *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->projMatrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->projMatrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->projMatrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->projMatrix.M41);
  return v2;
}
mat44f *StereoCameraForward::getViewMatrix(StereoCameraForward *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->viewMatrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->viewMatrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->viewMatrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->viewMatrix.M41);
  return v2;
}
bool __usercall StereoCameraForward::initOculus@<al>(int a1@<ebp>)
{
  bool result; // al

  if ( ovr_Initialize(a1, 0) >= 0 )
  {
    if ( ovr_Create(&session, &luid) >= 0 )
    {
      initialized = 1;
      result = 1;
    }
    else
    {
      ovr_Shutdown();
      result = 0;
    }
  }
  else
  {
    _printf("ERROR: ovr_Initialize failed\n");
    result = 0;
  }
  return result;
}
void StereoCameraForward::normalRendering(StereoCameraForward *this, Node *rootNode, float dt)
{
  GraphicsManager *v4; // ecx
  GraphicsManager *v5; // ecx
  RenderTarget *v6; // eax
  eAxisRendering v7; // eax
  GraphicsManager *v8; // ecx
  MaterialFilter materialFilter; // [esp+10h] [ebp-A4h] BYREF
  RenderContext rc; // [esp+18h] [ebp-9Ch] BYREF
  RenderContext rcTR; // [esp+28h] [ebp-8Ch] BYREF
  CameraMeshFilter filterTR; // [esp+38h] [ebp-7Ch] BYREF
  CameraMeshFilter filter; // [esp+48h] [ebp-6Ch] BYREF
  vec4f color; // [esp+58h] [ebp-5Ch] BYREF
  mat44f id; // [esp+68h] [ebp-4Ch] BYREF
  int v16; // [esp+B0h] [ebp-4h]

  v4 = this->graphics;
  color = (vec4f)_xmm;
  GraphicsManager::clearRenderTarget(v4, &color);
  GraphicsManager::clearRenderTargetDepth(this->graphics, 1.0);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
  v16 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v5 = this->graphics;
  rc.materialFilter = &materialFilter;
  rc.meshFilter = &filter;
  v6 = this->renderTarget;
  LOBYTE(v16) = 1;
  rc.graphics = v5;
  rc.camera = this;
  if ( v6 )
    GraphicsManager::setRenderTarget(v5, v6);
  GraphicsManager::setCullMode(this->graphics, eCullFront);
  Camera::renderCamera(this);
  if ( this->renderScene )
  {
    if ( this->skyBox )
    {
      mat44f::mat44f(&id);
      mat44f::loadIdentity(&id);
      GraphicsManager::setWorldMatrix(this->graphics, &id);
      SkyBox::render(this->skyBox, &rc);
      GraphicsManager::clearRenderTargetDepth(this->graphics, this->clearDepth);
    }
    rootNode->render(rootNode, &rc);
    v7 = this->axisRenderingMode;
    if ( v7 )
      Camera::renderAxis(this, v7 == eAxisBefore3d);
    CameraMeshFilter::CameraMeshFilter(&filterTR, this, Transparent, (int)this->maxLayer);
    v8 = this->graphics;
    rcTR.materialFilter = &materialFilter;
    LOBYTE(v16) = 2;
    rcTR.meshFilter = &filterTR;
    rcTR.graphics = v8;
    rcTR.camera = this;
    GraphicsManager::setDepthMode(v8, eDepthNoWrite);
    rootNode->render(rootNode, &rcTR);
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
    LOBYTE(v16) = 1;
    CameraMeshFilter::~CameraMeshFilter(&filterTR);
  }
  LOBYTE(v16) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v16 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filter);
}
ovrPosef_ *__userpurge StereoCameraForward::oculusRenderPass@<eax>(StereoCameraForward *this@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, ovrPosef_ *result, const unsigned int screenIndex, Node *rootNode, float dt)
{
  __m128i v8; // xmm0
  unsigned int v9; // esi
  const __m128i *v10; // eax
  StereoCameraForward *v11; // ecx
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  const __m128i *v17; // eax
  StereoCameraForward *v18; // ecx
  const __m128i *v19; // eax
  StereoCameraForward *v20; // esi
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  ovrPosef_ *v25; // eax
  float v26; // ecx
  __m128i v27; // [esp-14h] [ebp-D0h]
  __int128 v28; // [esp-4h] [ebp-C0h]
  mat44f v29; // [esp+14h] [ebp-A8h] BYREF
  __m128i v30; // [esp+54h] [ebp-68h] BYREF
  __m128i v31; // [esp+64h] [ebp-58h] BYREF
  __m128i v32; // [esp+74h] [ebp-48h] BYREF
  __m128i v33; // [esp+84h] [ebp-38h] BYREF
  vec3f cameraPosition; // [esp+94h] [ebp-28h] BYREF
  vec3f cameraTarget; // [esp+A0h] [ebp-1Ch] BYREF
  vec3f aViewAdjust; // [esp+ACh] [ebp-10h] BYREF
  StereoCameraForward *v37; // [esp+B8h] [ebp-4h]
  unsigned int screenIndexa; // [esp+C4h] [ebp+8h]

  v8 = _mm_loadu_si128((const __m128i *)&this->matrix);
  v37 = this;
  v33 = v8;
  v9 = screenIndex;
  v30 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  v32 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  v31 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  aViewAdjust.x = this->eyeRenderDesc[screenIndex].HmdToEyeOffset.x;
  aViewAdjust.y = this->eyeRenderDesc[screenIndex].HmdToEyeOffset.y;
  aViewAdjust.z = this->eyeRenderDesc[screenIndex].HmdToEyeOffset.z;
  HIDWORD(v28) = &aViewAdjust;
  screenIndexa = 7 * (screenIndex + 73);
  v27 = _mm_loadu_si128((const __m128i *)(&this->__vftable + screenIndexa));
  *(_QWORD *)&v28 = *(_QWORD *)(&this->matrix.M13 + screenIndexa);
  DWORD2(v28) = *((_DWORD *)&this->matrix.M21 + screenIndexa);
  v10 = (const __m128i *)StereoCameraForward::computeCameraMatrix(
                           this,
                           a2,
                           a3,
                           &v29,
                           v27.m128i_i32[0],
                           v27.m128i_i32[1],
                           v27.m128i_i32[2],
                           v27.m128i_i32[3],
                           v28);
  v11 = v37;
  *(__m128i *)&v37->matrix.M11 = _mm_loadu_si128(v10);
  *(__m128i *)&v11->matrix.M21 = _mm_loadu_si128(v10 + 1);
  *(__m128i *)&v11->matrix.M31 = _mm_loadu_si128(v10 + 2);
  *(__m128i *)&v11->matrix.M41 = _mm_loadu_si128(v10 + 3);
  v12 = v11->matrix.M31;
  v13 = v11->matrix.M32;
  v14 = v11->matrix.M33;
  v15 = v11->matrix.M42;
  v16 = v11->matrix.M43;
  aViewAdjust = *(vec3f *)&v11->matrix.M21;
  *(float *)v8.m128i_i32 = v11->matrix.M41 + COERCE_FLOAT(LODWORD(v12) ^ _xmm);
  cameraTarget.y = v15 + COERCE_FLOAT(LODWORD(v13) ^ _xmm);
  cameraTarget.z = v16 + COERCE_FLOAT(LODWORD(v14) ^ _xmm);
  LODWORD(cameraTarget.x) = v8.m128i_i32[0];
  cameraPosition = *(vec3f *)&v11->matrix.M41;
  v17 = (const __m128i *)mat44f::createLookAt(
                           (__m128)LODWORD(cameraPosition.z),
                           &v29,
                           &cameraPosition,
                           &cameraTarget,
                           &aViewAdjust);
  v18 = v37;
  *(__m128i *)&v37->viewMatrix.M11 = _mm_loadu_si128(v17);
  *(__m128i *)&v18->viewMatrix.M21 = _mm_loadu_si128(v17 + 1);
  *(__m128i *)&v18->viewMatrix.M31 = _mm_loadu_si128(v17 + 2);
  *(__m128i *)&v18->viewMatrix.M41 = _mm_loadu_si128(v17 + 3);
  v19 = (const __m128i *)ovrMatrix4f_Projection(
                           (ovrMatrix4f_ *)&v29,
                           (ovrFovPort_)_mm_loadu_si128((const __m128i *)&v18->eyeRenderDesc[v9].Fov),
                           v18->nearPlane,
                           v18->farPlane,
                           0);
  v20 = v37;
  v21 = (__m128)_mm_loadu_si128(v19);
  v22 = (__m128)_mm_loadu_si128(v19 + 1);
  v23 = (__m128)_mm_loadu_si128(v19 + 2);
  v24 = (__m128)_mm_loadu_si128(v19 + 3);
  LODWORD(v37->projMatrix.M11) = v21.m128_i32[0];
  LODWORD(v20->projMatrix.M21) = _mm_shuffle_ps(v21, v21, 85).m128_u32[0];
  LODWORD(v20->projMatrix.M22) = _mm_shuffle_ps(v22, v22, 85).m128_u32[0];
  LODWORD(v20->projMatrix.M23) = _mm_shuffle_ps(v23, v23, 85).m128_u32[0];
  LODWORD(v20->projMatrix.M24) = _mm_shuffle_ps(v24, v24, 85).m128_u32[0];
  LODWORD(v20->projMatrix.M31) = _mm_shuffle_ps(v21, v21, 170).m128_u32[0];
  LODWORD(v20->projMatrix.M32) = _mm_shuffle_ps(v22, v22, 170).m128_u32[0];
  LODWORD(v20->projMatrix.M33) = _mm_shuffle_ps(v23, v23, 170).m128_u32[0];
  LODWORD(v20->projMatrix.M12) = v22.m128_i32[0];
  LODWORD(v20->projMatrix.M13) = v23.m128_i32[0];
  LODWORD(v20->projMatrix.M14) = v24.m128_i32[0];
  LODWORD(v20->projMatrix.M34) = _mm_shuffle_ps(v24, v24, 170).m128_u32[0];
  LODWORD(v20->projMatrix.M41) = _mm_shuffle_ps(v21, v21, 255).m128_u32[0];
  LODWORD(v20->projMatrix.M42) = _mm_shuffle_ps(v22, v22, 255).m128_u32[0];
  LODWORD(v20->projMatrix.M43) = _mm_shuffle_ps(v23, v23, 255).m128_u32[0];
  LODWORD(v20->projMatrix.M44) = _mm_shuffle_ps(v24, v24, 255).m128_u32[0];
  GraphicsManager::setViewport(
    v20->graphics,
    v20->eyeRenderViewport[screenIndex].Pos.x,
    v20->eyeRenderViewport[screenIndex].Pos.y,
    v20->eyeRenderViewport[screenIndex].Size.w,
    v20->eyeRenderViewport[screenIndex].Size.h);
  StereoCameraForward::normalRendering(v20, rootNode, dt);
  v25 = result;
  *(__m128i *)&v20->matrix.M11 = _mm_loadu_si128(&v33);
  *(__m128i *)&v20->matrix.M21 = _mm_loadu_si128(&v30);
  *(__m128i *)&v20->matrix.M31 = _mm_loadu_si128(&v32);
  *(__m128i *)&v20->matrix.M41 = _mm_loadu_si128(&v31);
  result->Orientation = (ovrQuatf_)_mm_loadu_si128((const __m128i *)(&v20->__vftable + screenIndexa));
  v26 = *(&v20->matrix.M21 + screenIndexa);
  *(_QWORD *)&result->Position.x = *(_QWORD *)(&v20->matrix.M13 + screenIndexa);
  result->Position.z = v26;
  return v25;
}
void __userpurge StereoCameraForward::render(StereoCameraForward *this@<ecx>, int a2@<ebp>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, Node *blurred, Node *unblurred, Node *shadow, float dt)
{
  __m128i v9; // xmm0
  float v10; // eax
  __m128i v11; // xmm0
  const __m128i *v12; // eax
  __m128i v13; // xmm0
  StereoCameraForward_vtbl *v14; // eax
  __m128i v15; // xmm0
  __m128i v16; // [esp-14h] [ebp-B8h]
  __int128 v17; // [esp-4h] [ebp-A8h]
  float v18; // [esp+14h] [ebp-90h]
  vec3f aViewAdjust; // [esp+18h] [ebp-8Ch] BYREF
  __m128i v20; // [esp+24h] [ebp-80h] BYREF
  __m128i v21; // [esp+34h] [ebp-70h] BYREF
  __m128i v22; // [esp+44h] [ebp-60h] BYREF
  __m128i v23; // [esp+54h] [ebp-50h] BYREF
  mat44f result; // [esp+64h] [ebp-40h] BYREF

  StereoCameraForward::renderMirrorTexture(this);
  if ( GetAsyncKeyState(17) && GetAsyncKeyState(32) )
    ovr_RecenterTrackingOrigin(session);
  v18 = this->exposure;
  StereoCameraForward::computeEyePoses(this, a2);
  v9 = _mm_loadu_si128((const __m128i *)&this->matrix);
  aViewAdjust.x = 0.0;
  v10 = this->eyeRenderPoses[0].Position.z;
  v23 = v9;
  aViewAdjust.y = 0.0;
  v11 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  aViewAdjust.z = 0.0;
  v20 = v11;
  v21 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  v22 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  v16 = _mm_loadu_si128((const __m128i *)this->eyeRenderPoses);
  *(_QWORD *)&v17 = *(_QWORD *)&this->eyeRenderPoses[0].Position.x;
  *((_QWORD *)&v17 + 1) = __PAIR64__(&aViewAdjust, LODWORD(v10));
  v12 = (const __m128i *)StereoCameraForward::computeCameraMatrix(
                           this,
                           a3,
                           a4,
                           &result,
                           v16.m128i_i32[0],
                           v16.m128i_i32[1],
                           v16.m128i_i32[2],
                           v16.m128i_i32[3],
                           v17);
  *(__m128i *)&this->matrix.M11 = _mm_loadu_si128(v12);
  *(__m128i *)&this->matrix.M21 = _mm_loadu_si128(v12 + 1);
  *(__m128i *)&this->matrix.M31 = _mm_loadu_si128(v12 + 2);
  v13 = _mm_loadu_si128(v12 + 3);
  v14 = this->__vftable;
  this->fov = 90.0;
  *(__m128i *)&this->matrix.M41 = v13;
  ((void (*)(StereoCameraForward *, Node *, _DWORD))v14->shadowMapPass)(this, shadow, LODWORD(dt));
  if ( blurred )
    CubeMapRenderer::render(&this->cubeMapRenderer, this->cubeMap, blurred, this);
  v15 = _mm_loadu_si128(&v23);
  this->fov = 45.0;
  *(__m128i *)&this->matrix.M11 = v15;
  *(__m128i *)&this->matrix.M21 = _mm_loadu_si128(&v20);
  *(__m128i *)&this->matrix.M31 = _mm_loadu_si128(&v21);
  *(__m128i *)&this->matrix.M41 = _mm_loadu_si128(&v22);
  firstRender = 1;
  GraphicsManager::beginMainRenderPass(this->graphics);
  if ( this->graphics->videoSettings.ppHDREnabled )
    StereoCameraForward::renderYebis(this, (int)this, a3, a4, shadow, dt);
  else
    StereoCameraForward::renderNoPP(this, a3, a4, shadow, dt);
  GraphicsManager::endMainRenderPass(this->graphics);
  GraphicsManager::setViewport(
    this->graphics,
    0,
    0,
    this->graphics->videoSettings.width,
    this->graphics->videoSettings.height);
  this->exposure = v18;
}
void StereoCameraForward::renderMirrorTexture(StereoCameraForward *this)
{
  GraphicsManager *v2; // ecx
  ID3D11DeviceContext *v3; // esi
  const mat44f *v4; // eax
  GLRenderer *v5; // esi
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  int ind; // [esp+30h] [ebp-54h] BYREF
  vec4f color; // [esp+34h] [ebp-50h] BYREF
  mat44f result; // [esp+44h] [ebp-40h] BYREF

  ovr_GetTextureSwapChainCurrentIndex(session, this->pEyeRenderTexture[0]->TextureChain, &ind);
  GraphicsManager::setScreenRenderTargets(this->graphics);
  v2 = this->graphics;
  color = (vec4f)_xmm;
  GraphicsManager::clearRenderTarget(v2, &color);
  if ( this->mirrorEnabled )
  {
    GraphicsManager::clearRenderTargetDepth(this->graphics, 1.0);
    kglGetNativeDevice();
    v3 = kglGetNativeContext();
    GraphicsManager::resetRenderStates(this->graphics);
    v4 = mat44f::createIdentity(&result);
    GraphicsManager::setWorldMatrix(this->graphics, v4);
    GraphicsManager::setDepthMode(this->graphics, eDepthOff);
    v3->PSSetShaderResources(v3, 0, 1u, &this->mirrorTextureBuffers._Myfirst[ind]);
    GraphicsManager::setScreenSpaceMode(this->graphics);
    v5 = this->graphics->gl;
    GLRenderer::color3f(v5, 1.0, 1.0, 1.0);
    v6 = (float)this->eyeRenderViewport[0].Size.w;
    v7 = (float)this->graphics->videoSettings.width;
    v8 = (float)this->graphics->videoSettings.height;
    v9 = (float)this->eyeRenderViewport[0].Size.h;
    v10 = v7 / v6;
    if ( (float)(v7 / v6) <= (float)(v8 / v9) )
      v10 = v8 / v9;
    GLRenderer::quad(
      v5,
      (float)((float)(v6 * v10) - v7) * -0.5,
      (float)((float)(v9 * v10) - v8) * -0.5,
      v6 * v10,
      v9 * v10,
      1,
      0);
  }
}
void __userpurge StereoCameraForward::renderNoPP(StereoCameraForward *this@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, Node *node, float dt)
{
  unsigned int v6; // edi
  OculusTexture **v7; // ebx
  GraphicsManager *v8; // ecx
  struct ovrHmdStruct **v9; // esi
  ID3D11DeviceContext *v10; // eax
  GraphicsManager *v11; // ecx
  OculusTexture *v12; // esi
  ID3D11Texture2D *v13; // esi
  int v14; // edi
  ID3D11Texture2D *v15; // eax
  int currentIndex; // [esp+14h] [ebp-28h] BYREF
  int *v17; // [esp+18h] [ebp-24h]
  unsigned int v18; // [esp+1Ch] [ebp-20h]
  ovrPosef_ result; // [esp+20h] [ebp-1Ch] BYREF

  v6 = 0;
  this->renderTarget = 0;
  v7 = this->pEyeRenderTexture;
  v18 = 0;
  do
  {
    v8 = this->graphics;
    if ( v8->videoSettings.aaSamples == 1 )
    {
      v9 = (struct ovrHmdStruct **)*v7;
      currentIndex = 0;
      ovr_GetTextureSwapChainCurrentIndex(*v9, v9[1], &currentIndex);
      kglSetRenderTargetNative(*((void **)v9[2] + currentIndex), v7[2]);
    }
    else
    {
      GraphicsManager::setRenderTarget(v8, this->rtTempAA);
    }
    StereoCameraForward::oculusRenderPass(this, a2, a3, &result, v6, node, dt);
    v10 = kglGetNativeContext();
    v11 = this->graphics;
    v17 = (int *)v10;
    if ( v11->videoSettings.aaSamples > 1 )
    {
      v12 = *v7;
      currentIndex = 0;
      ovr_GetTextureSwapChainCurrentIndex(v12->Session, v12->TextureChain, &currentIndex);
      v13 = v12->txResource._Myfirst[currentIndex];
      v14 = *v17;
      v15 = kglGetRenderTargetTexture(this->rtTempAA->kidColor);
      (*(void (__stdcall **)(int *, ID3D11Texture2D *, _DWORD, ID3D11Texture2D *, _DWORD, int))(v14 + 228))(
        v17,
        v13,
        0,
        v15,
        0,
        28);
      v6 = v18;
    }
    ovr_CommitTextureSwapChain((*v7)->Session, (*v7)->TextureChain);
    ++v6;
    ++v7;
    v18 = v6;
  }
  while ( v6 < 2 );
}
void __userpurge StereoCameraForward::renderYebis(StereoCameraForward *this@<ecx>, int a2@<esi>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, Node *node, float dt)
{
  int v7; // ebx
  RenderTarget **v8; // ebp
  YebisPP *v9; // esi
  ID3D11ShaderResourceView *v10; // eax
  RenderTarget *v11; // esi
  RenderTarget *v12; // eax
  GraphicsManager *v13; // ecx
  GLRenderer *v14; // esi
  RenderTarget *v15; // esi
  int v16; // ecx
  YebisPP *v17; // esi
  RenderTarget *v18; // eax
  RenderTarget *v19; // esi
  int v20; // ecx
  ID3D11ShaderResourceView *v21; // eax
  int v22; // ebx
  ID3D11ShaderResourceView *v23; // [esp-4h] [ebp-144h]
  ID3D11ShaderResourceView *v24; // [esp-4h] [ebp-144h]
  ID3D11RenderTargetView *v25; // [esp+0h] [ebp-140h]
  ID3D11RenderTargetView *v26; // [esp+0h] [ebp-140h]
  float v27; // [esp+8h] [ebp-138h]
  float v28; // [esp+Ch] [ebp-134h]
  float v29; // [esp+10h] [ebp-130h]
  float v30; // [esp+14h] [ebp-12Ch]
  vec3f currentIndex; // [esp+18h] [ebp-128h] BYREF
  vec3f v32; // [esp+24h] [ebp-11Ch] BYREF
  mat44f v33; // [esp+30h] [ebp-110h] BYREF
  __m128i result_48; // [esp+70h] [ebp-D0h]
  __m128i result_64; // [esp+80h] [ebp-C0h]
  __m128i result_80; // [esp+90h] [ebp-B0h]
  __m128i result_96; // [esp+A0h] [ebp-A0h]

  ovr_GetHmdDesc((ovrHmdDesc_ *)&v33.M21, session);
  this->renderTarget = 0;
  v7 = 0;
  currentIndex.z = 0.0;
  v8 = this->rtFXAA_Temp;
  LODWORD(currentIndex.y) = &this->eyeRenderViewport[0].Size;
  do
  {
    kglSetRenderTargets(this->rtYebisTarget->kidColor, this->rtYebisTarget->kidDepth);
    StereoCameraForward::oculusRenderPass(this, a3, a4, (ovrPosef_ *)&v32, v7, node, dt);
    kglSetRenderTargets(0, 0);
    YebisPP::updatePPCameraValues(
      this->yebisPP._Myptr,
      (int)this,
      a2,
      dt,
      this,
      v27,
      v28,
      v29,
      v30,
      currentIndex,
      v32,
      v33,
      result_48,
      result_64,
      result_80,
      result_96);
    this->yebisPP._Myptr->pp.dofActive = 0;
    this->yebisPP._Myptr->pp.heatParticleEnabled = 0;
    YebisPP::updatePP(this->yebisPP._Myptr, v7 == 0);
    if ( *v8 )
    {
      v9 = this->yebisPP._Myptr;
      v25 = kglGetRenderTargetView((*v8)->kidColor);
      v23 = kglGetRenderTargetShaderResourceView(this->rtYebisTarget->kidDepth);
      v10 = kglGetRenderTargetShaderResourceView(this->rtYebisTarget->kidColor);
      YebisPP::applyPostProcessing(
        v9,
        (_DWORD *)v7,
        v10,
        DXGI_FORMAT_R16G16B16A16_FLOAT,
        v23,
        v25,
        DXGI_FORMAT_R8G8B8A8_UNORM);
      kglSetDefaultState();
      GraphicsManager::setSamplerState(this->graphics);
      GraphicsManager::resetRenderStates(this->graphics);
      v11 = v8[25];
      currentIndex.x = 0.0;
      ovr_GetTextureSwapChainCurrentIndex(
        (struct ovrHmdStruct *)v11->__vftable,
        (struct ovrTextureSwapChainData *)v11->format,
        (int *)&currentIndex);
      kglSetRenderTargetNative(*(void **)(v11->width + 4 * LODWORD(currentIndex.x)), v8[27]);
      GraphicsManager::setViewport(
        this->graphics,
        0,
        0,
        *(_DWORD *)LODWORD(currentIndex.y),
        *(_DWORD *)(LODWORD(currentIndex.y) + 4));
      GraphicsManager::setDepthMode(this->graphics, eDepthOff);
      if ( *v8 )
      {
        GraphicsManager::setTextureRT(this->graphics, 5u, *v8);
        GLRenderer::fullScreenQuad(this->graphics->gl, this->fxaaShader);
      }
    }
    else
    {
      v12 = this->rtYebisResolved;
      if ( v12 )
      {
        kglResolveRenderTarget(this->rtYebisTarget->kidColor, v12->kidColor, 1u);
        v13 = this->graphics;
        v14 = v13->gl;
        GraphicsManager::setBlendMode(v13, eOpaque);
        kglSetRenderTargets(this->rtYebisResolvedDepth->kidColor, 0);
        kglSetTextureRT(1u, this->rtYebisTarget->kidDepth);
        GraphicsManager::setViewport(this->graphics, 0, 0, this->rtYebisTarget->width, this->rtYebisTarget->height);
        GLRenderer::fullScreenQuad(v14, this->depthResolveShader);
        kglSetRenderTargets(0, 0);
        v15 = v8[25];
        currentIndex.x = 0.0;
        ovr_GetTextureSwapChainCurrentIndex(
          (struct ovrHmdStruct *)v15->__vftable,
          (struct ovrTextureSwapChainData *)v15->format,
          (int *)&currentIndex);
        v16 = v15->width;
        v17 = this->yebisPP._Myptr;
        v26 = *(ID3D11RenderTargetView **)(v16 + 4 * LODWORD(currentIndex.x));
        v24 = kglGetRenderTargetShaderResourceView(this->rtYebisResolvedDepth->kidColor);
        v18 = this->rtYebisResolved;
      }
      else
      {
        v19 = v8[25];
        currentIndex.x = 0.0;
        ovr_GetTextureSwapChainCurrentIndex(
          (struct ovrHmdStruct *)v19->__vftable,
          (struct ovrTextureSwapChainData *)v19->format,
          (int *)&currentIndex);
        v20 = v19->width;
        v17 = this->yebisPP._Myptr;
        v26 = *(ID3D11RenderTargetView **)(v20 + 4 * LODWORD(currentIndex.x));
        v24 = kglGetRenderTargetShaderResourceView(this->rtYebisTarget->kidDepth);
        v18 = this->rtYebisTarget;
      }
      v21 = kglGetRenderTargetShaderResourceView(v18->kidColor);
      YebisPP::applyPostProcessing(
        v17,
        (_DWORD *)v7,
        v21,
        DXGI_FORMAT_R16G16B16A16_FLOAT,
        v24,
        v26,
        DXGI_FORMAT_R8G8B8A8_UNORM);
    }
    ovr_CommitTextureSwapChain(
      (struct ovrHmdStruct *)v8[25]->__vftable,
      (struct ovrTextureSwapChainData *)v8[25]->format);
    kglSetDefaultState();
    GraphicsManager::setSamplerState(this->graphics);
    GraphicsManager::resetRenderStates(this->graphics);
    CubeMap::apply(this->cubeMap, 10);
    a2 = 0;
    v22 = 0;
    do
    {
      GraphicsManager::setShadowMapTexture(this->graphics, a2, this->shadowRT._Myfirst[a2]);
      GraphicsManager::setShadowMapMatrix(this->graphics, a2++, &this->shadowMatrices._Myfirst[v22++]);
    }
    while ( a2 < 3 );
    ++v8;
    LODWORD(currentIndex.y) += 16;
    v7 = LODWORD(currentIndex.z) + 1;
    LODWORD(currentIndex.z) = v7;
  }
  while ( v7 < 2 );
}
void StereoCameraForward::resetHeadPosition(StereoCameraForward *this)
{
  ovr_RecenterTrackingOrigin(session);
}
