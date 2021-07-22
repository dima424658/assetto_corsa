#include "postprocesseffectsupdater.h
void PostProcessEffectsUpdater::PostProcessEffectsUpdater(PostProcessEffectsUpdater *this, Sim *aSim, CameraForwardYebis *aCamera)
{
  std::wstring *v4; // edi
  char v5; // al
  std::wstring *v6; // esi
  std::wstring v7; // [esp-1Ch] [ebp-D4h] BYREF
  Game *v8; // [esp-4h] [ebp-BCh]
  char v9; // [esp+13h] [ebp-A5h]
  PostProcessEffectsUpdater *v10; // [esp+18h] [ebp-A0h]
  std::wstring section; // [esp+1Ch] [ebp-9Ch] BYREF
  std::wstring result; // [esp+34h] [ebp-84h] BYREF
  std::wstring key; // [esp+4Ch] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+64h] [ebp-54h] BYREF
  int v15; // [esp+B4h] [ebp-4h]

  v10 = this;
  v8 = aSim->game;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, L"POST_PROCESS_EFFECTS_MANAGER", 0x1Cu);
  GameObject::GameObject(this, v7, v8);
  v4 = &this->defaultFilter;
  this->__vftable = (PostProcessEffectsUpdater_vtbl *)&PostProcessEffectsUpdater::`vftable';
  this->defaultFilter._Myres = 7;
  this->defaultFilter._Mysize = 0;
  v15 = 0;
  this->defaultFilter._Bx._Buf[0] = 0;
  v8 = 0;
  this->camera = aCamera;
  this->sim = aSim;
  LOBYTE(v15) = 1;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)this, v7, (bool)v8);
  LOBYTE(v15) = 2;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"POST_PROCESS", 0xCu);
    LOBYTE(v15) = 3;
    v5 = INIReader::hasSection(&ini, &section);
    v9 = v5;
    LOBYTE(v15) = 2;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v5 = v9;
    }
    if ( v5 )
    {
      std::wstring::wstring(&key, L"FILTER");
      LOBYTE(v15) = 4;
      std::wstring::wstring(&section, L"POST_PROCESS");
      LOBYTE(v15) = 5;
      v6 = INIReader::getString(&ini, &result, &section, &key);
      if ( v4 != v6 )
      {
        if ( this->defaultFilter._Myres >= 8 )
          operator delete(v4->_Bx._Ptr);
        this->defaultFilter._Myres = 7;
        this->defaultFilter._Mysize = 0;
        v8 = (Game *)v6;
        v4->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&this->defaultFilter, (std::wstring *)v8);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( this->defaultFilter._Myres >= 8 )
        v4 = (std::wstring *)v4->_Bx._Ptr;
      _printf("Default PP filter:%S\n", v4->_Bx._Buf);
    }
  }
  LOBYTE(v15) = 1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
PostProcessEffectsUpdater *PostProcessEffectsUpdater::`vector deleting destructor'(PostProcessEffectsUpdater *this, unsigned int a2)
{
  this->__vftable = (PostProcessEffectsUpdater_vtbl *)&PostProcessEffectsUpdater::`vftable';
  if ( this->defaultFilter._Myres >= 8 )
    operator delete(this->defaultFilter._Bx._Ptr);
  this->defaultFilter._Myres = 7;
  this->defaultFilter._Mysize = 0;
  this->defaultFilter._Bx._Buf[0] = 0;
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PostProcessEffectsUpdater::loadConfigurationFile(PostProcessEffectsUpdater *this, std::wstring filePath)
{
  std::wstring v3; // [esp-18h] [ebp-30h] BYREF
  int v4; // [esp+14h] [ebp-4h]

  v4 = 0;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, &filePath, 0, 0xFFFFFFFF);
  CameraForwardYebis::loadPPSet(this->camera, v3);
  if ( filePath._Myres >= 8 )
    operator delete(filePath._Bx._Ptr);
}
void PostProcessEffectsUpdater::update(PostProcessEffectsUpdater *this, float dt)
{
  CameraForwardYebis *v3; // eax
  unsigned int v4; // eax
  Sim *v5; // ecx
  unsigned int v6; // esi
  int v7; // edi
  CarAvatar *v8; // eax
  CarAvatar *v9; // eax
  float *v10; // eax
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  CameraForwardYebis *v17; // eax
  bool v18; // zf
  __m128i v19; // xmm0
  CameraForwardYebis *v20; // eax
  KGLVolume v; // [esp+4h] [ebp-58h] BYREF
  mat44f v22; // [esp+1Ch] [ebp-40h] BYREF

  v3 = this->camera;
  if ( v3->pp.heatParticleEnabled )
  {
    v3->pp.heatParticleActive = 1;
    v4 = Sim::getFocusedCarIndex(this->sim);
    if ( (float)(Sim::getCar(this->sim, v4)->physicsState.speed.value * 3.5999999) > 25.0 )
      this->camera->pp.heatParticleActive = 0;
    v5 = this->sim;
    v6 = 0;
    if ( v5->cars._Mylast - v5->cars._Myfirst )
    {
      v7 = 0;
      do
      {
        v8 = Sim::getCar(v5, v6);
        if ( !CarAvatar::isConnected(v8) )
          break;
        v9 = Sim::getCar(this->sim, v6);
        v10 = (float *)v9->bodyTransform->getWorldMatrix(v9->bodyTransform, &v22);
        v.depth = 1.5;
        v.width = 1.5;
        v11 = v10[4];
        v12 = *v10 * 0.0;
        v.height = 0.0;
        v13 = (float)((float)((float)(v11 * 0.0) + v12) + (float)(v10[8] * -2.0)) + v10[12];
        v14 = (float)((float)((float)(v10[5] * 0.0) + (float)(v10[1] * 0.0)) + (float)(v10[9] * -2.0)) + v10[13];
        v15 = (float)((float)((float)(v10[6] * 0.0) + (float)(v10[2] * 0.0)) + (float)(v10[10] * -2.0)) + v10[14];
        v16 = (float)((float)((float)(v10[7] * 0.0) + (float)(v10[3] * 0.0)) + (float)(v10[11] * -2.0)) + v10[15];
        v17 = this->camera;
        v18 = v17->pp.heatParticleEnabled == 0;
        v.center[0] = (float)(1.0 / v16) * v13;
        v.center[1] = (float)((float)(1.0 / v16) * v14) + 0.5;
        v.center[2] = (float)(1.0 / v16) * v15;
        if ( !v18 && v17->pp.heatParticleActive && v6 < 0x1E )
        {
          v19 = _mm_loadu_si128((const __m128i *)&v);
          v17->pp.heatParticleSets[v7].active = 1;
          v20 = this->camera;
          *(__m128i *)v20->pp.heatParticleSets[v7].volume.center = v19;
          *(_QWORD *)&v20->pp.heatParticleSets[v7].volume.depth = *(_QWORD *)&v.depth;
        }
        v5 = this->sim;
        ++v6;
        ++v7;
      }
      while ( v6 < v5->cars._Mylast - v5->cars._Myfirst );
    }
  }
}
void PostProcessEffectsUpdater::loadDefaultConfiguration(PostProcessEffectsUpdater *this)
{
  std::wstring v2; // [esp-18h] [ebp-20h] BYREF

  v2._Myres = 7;
  v2._Mysize = 0;
  v2._Bx._Buf[0] = 0;
  std::wstring::assign(&v2, &this->defaultFilter, 0, 0xFFFFFFFF);
  PostProcessEffectsUpdater::loadConfigurationFile(this, v2);
}
