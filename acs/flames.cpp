#include "flames.h
void Flames::Flames(Flames *this, CarAvatar *a_car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Game *v5; // eax
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  char v8; // bl
  std::wstring *v9; // eax
  Sim *v10; // eax
  Event<bool> *v11; // ecx
  _BYTE v12[56]; // [esp-1Ch] [ebp-7Ch] BYREF
  Flames *v13; // [esp+1Ch] [ebp-44h]
  std::wstring folder; // [esp+20h] [ebp-40h] BYREF
  std::wstring result; // [esp+38h] [ebp-28h] BYREF
  int v16; // [esp+5Ch] [ebp-4h]

  v13 = this;
  *(_DWORD *)&v12[24] = a_car->game;
  *(_DWORD *)&v12[20] = 7;
  *(_DWORD *)&v12[16] = 0;
  *(_WORD *)v12 = 0;
  std::wstring::assign((std::wstring *)v12, L"FLAMES", 6u);
  GameObject::GameObject(this, *(std::wstring *)v12, *(Game **)&v12[24]);
  v16 = 0;
  *(_DWORD *)&v12[24] = &a_car->unixName;
  this->__vftable = (Flames_vtbl *)&Flames::`vftable';
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", *(const std::wstring **)&v12[24]);
  LOBYTE(v16) = 1;
  v4 = std::operator+<wchar_t>(&folder, v3, L"/data/flames.ini");
  LOBYTE(v16) = 2;
  FileChangeObserver::FileChangeObserver(&this->observer, v4);
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->textures._Myfirst = 0;
  this->textures._Mylast = 0;
  this->textures._Myend = 0;
  this->flashTextures._Myfirst = 0;
  this->flashTextures._Mylast = 0;
  this->flashTextures._Myend = 0;
  this->tailTextures._Myfirst = 0;
  this->tailTextures._Mylast = 0;
  this->tailTextures._Myend = 0;
  this->flames._Myfirst = 0;
  this->flames._Mylast = 0;
  this->flames._Myend = 0;
  this->flamesV2._Myfirst = 0;
  this->flamesV2._Mylast = 0;
  this->flamesV2._Myend = 0;
  this->cycleIndex = 0;
  this->version = 1;
  this->isFlashing = 0;
  v5 = this->game;
  this->observeINI = 0.0;
  this->intensity = 1.0;
  this->car = a_car;
  this->burnFuelMult = 10.0;
  this->flashThreshold = 2.0;
  this->currentDt = v5->gameTime.deltaT;
  *(_DWORD *)&v12[24] = &a_car->unixName;
  *(_DWORD *)&this->textureFlashIndex = 0;
  this->textureTailIndex = 0;
  this->rotation = 0;
  LOBYTE(v16) = 10;
  v6 = std::operator+<wchar_t>(&result, L"content/cars/", *(const std::wstring **)&v12[24]);
  LOBYTE(v16) = 11;
  v7 = std::operator+<wchar_t>(&folder, v6, L"/data/flame_presets.ini");
  LOBYTE(v16) = 12;
  v8 = Path::fileExists((unsigned int)&a_car->unixName, v7, 0);
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  LOBYTE(v16) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v8 )
    this->version = 2;
  v9 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  LOBYTE(v16) = 13;
  std::operator+<wchar_t>((std::wstring *)&v12[4], v9, L"/texture/flames");
  Flames::loadTextures(this, *(std::wstring *)&v12[4]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  *(_DWORD *)&v12[24] = this;
  *(_DWORD *)v12 = &std::_Func_impl<std::_Callable_obj<_lambda_742fdea74c23d6fba2d43591d216c592_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v12[4] = this;
  *(_DWORD *)&v12[16] = v12;
  v10 = a_car->sim;
  LOBYTE(v16) = 10;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v10->renderFinishedNodeEvent->evOnRender,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v12,
    this);
  Flames::loadFlames(this);
  *(_DWORD *)&v12[24] = this;
  this->flamesTime = 0.0;
  *(_DWORD *)v12 = &std::_Func_impl<std::_Callable_obj<_lambda_e4c5f6407e9e08463f99f2dd7db30c08_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v12[4] = this;
  *(_DWORD *)&v12[16] = v12;
  v11 = &this->car->evOnBackfireTriggered;
  LOBYTE(v16) = 10;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v11,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v12,
    *(void **)&v12[24]);
}
void Flames::~Flames(Flames *this)
{
  std::vector<FlameGroup> *v2; // esi
  std::vector<FlameInstance> *v3; // esi

  this->__vftable = (Flames_vtbl *)&Flames::`vftable';
  v2 = &this->flamesV2;
  if ( this->flamesV2._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->flamesV2);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<FlameGroup>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->flames;
  if ( this->flames._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->flames);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->flames._Mylast = 0;
    this->flames._Myend = 0;
  }
  std::vector<Texture>::_Tidy(&this->tailTextures);
  std::vector<Texture>::_Tidy(&this->flashTextures);
  std::vector<Texture>::_Tidy(&this->textures);
  BonusInfo::~BonusInfo((SGearRatio *)&this->observer);
  GameObject::~GameObject(this);
}
Flames *Flames::`vector deleting destructor'(Flames *this, unsigned int a2)
{
  Flames::~Flames(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Flames::checkTextures(Flames *this, const std::wstring name, const std::vector<FlameTexture> *orig)
{
  FlameTexture *v4; // esi
  FlameTexture *v5; // edi
  FlameType v6; // eax
  __int32 v7; // eax
  std::wstring *v8; // eax
  bool v9; // cf
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring v12; // [esp+14h] [ebp-58h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring v14; // [esp+44h] [ebp-28h] BYREF
  int v15; // [esp+68h] [ebp-4h]

  v15 = 0;
  v4 = orig->_Myfirst;
  v5 = orig->_Mylast;
  if ( orig->_Myfirst != v5 )
  {
    do
    {
      v6 = v4->flametype;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 == 1 && !(this->tailTextures._Mylast - this->tailTextures._Myfirst) )
          {
            v8 = std::operator+<wchar_t>(&result, &name, L" : Tail textures are missing! (texture prefix = 'l' )");
            v9 = v8->_Myres < 8;
            LOBYTE(v15) = 3;
            if ( !v9 )
              v8 = (std::wstring *)v8->_Bx._Ptr;
            _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v8->_Bx._Buf);
            ksGenerateCrash();
            LOBYTE(v15) = 0;
            if ( result._Myres >= 8 )
              operator delete(result._Bx._Ptr);
          }
        }
        else if ( !(this->textures._Mylast - this->textures._Myfirst) )
        {
          v10 = std::operator+<wchar_t>(&v12, &name, L" : Main textures are missing! (any prefix except 'f' and 'l')");
          v9 = v10->_Myres < 8;
          LOBYTE(v15) = 2;
          if ( !v9 )
            v10 = (std::wstring *)v10->_Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v10->_Bx._Buf);
          ksGenerateCrash();
          LOBYTE(v15) = 0;
          if ( v12._Myres >= 8 )
            operator delete(v12._Bx._Ptr);
        }
      }
      else if ( !(this->flashTextures._Mylast - this->flashTextures._Myfirst) )
      {
        v11 = std::operator+<wchar_t>(&v14, &name, L" : Flash textures are missing! (texture prefix = 'f' )");
        v9 = v11->_Myres < 8;
        LOBYTE(v15) = 1;
        if ( !v9 )
          v11 = (std::wstring *)v11->_Bx._Ptr;
        _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v11->_Bx._Buf);
        ksGenerateCrash();
        LOBYTE(v15) = 0;
        if ( v14._Myres >= 8 )
          operator delete(v14._Bx._Ptr);
      }
      ++v4;
    }
    while ( v4 != v5 );
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void Flames::copyFlameVector(Flames *this, const std::vector<FlameTexture> *orig, std::vector<FlameTexture> *dest, FlameInstanceV2 *f)
{
  FlameTexture *v4; // ecx
  FlameTexture *i; // eax

  std::vector<FlameTexture>::operator=(dest, orig);
  v4 = dest->_Mylast;
  for ( i = dest->_Myfirst; i != v4; ++i )
  {
    i->offset.z = (float)(i->offset.z * -1.0) * f->sizeMult;
    i->offset.y = (float)(i->offset.y * -1.0) * f->sizeMult;
    i->offset.x = (float)((float)(2 * f->isLeft - 1) * i->offset.x) * f->sizeMult;
    i->size = i->size * f->sizeMult;
  }
}
void Flames::cycleTexture(Flames *this, FlameTexture *ft, unsigned __int16 cycle)
{
  FlameType v3; // eax
  __int32 v4; // eax

  v3 = ft->flametype;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        this->textureTailIndex += cycle + 1;
        this->textureTailIndex %= (unsigned int)(this->tailTextures._Mylast - this->tailTextures._Myfirst);
      }
    }
    else
    {
      this->textureBodyIndex += cycle + 1;
      this->textureBodyIndex %= (unsigned int)(this->textures._Mylast - this->textures._Myfirst);
    }
  }
  else
  {
    this->textureFlashIndex += cycle + 1;
    this->textureFlashIndex %= (unsigned int)(this->flashTextures._Mylast - this->flashTextures._Myfirst);
  }
}
void __userpurge Flames::drawBackfireState(Flames *this@<ecx>, float a2@<xmm0>, GLRenderer *gl, RenderContext *rc, FlameGroup *f)
{
  switch ( f->state )
  {
    case eCar:
      Flames::drawFlame(this, a2, gl, rc, eCar, f);
      break;
    case eDrivable:
      Flames::drawFlame(this, a2, gl, rc, eCar, f);
      Flames::drawFlame(this, a2, gl, rc, eDrivable, f);
      break;
    case eTrack:
      Flames::drawFlame(this, a2, gl, rc, eTrack, f);
      break;
  }
}
void Flames::drawFlame(Flames *this, GLRenderer *gl, FlameInstance *flame, RenderContext *rc)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  Node *v7; // eax
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm2
  __int128 v14; // xmm3
  GraphicsManager *v15; // ecx
  unsigned int v16; // edx
  float v17; // [esp+20h] [ebp-90h]
  float v18; // [esp+24h] [ebp-8Ch]
  mat44f matrix; // [esp+30h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+70h] [ebp-40h] BYREF

  if ( flame->visTime > 0.0 )
  {
    v5 = *(double *)__libm_sse2_sin().m128_u64;
    v17 = (float)(v5 * flame->sinVariation) * flame->vsizeEnd;
    v6 = *(double *)__libm_sse2_cos().m128_u64;
    v18 = (float)(v6 * flame->sinVariation) * flame->lsize;
    mat44f::mat44f(&matrix);
    v7 = this->car->bodyTransform;
    v8 = *(__m128 *)&v7->matrix.M21;
    v9 = *(__m128 *)&v7->matrix.M31;
    v10 = *(__m128 *)&v7->matrix.M41;
    M2.r[0] = *(__m128 *)&v7->matrix.M11;
    v11 = *(__m128 *)&flame->matrix.M11;
    M2.r[1] = v8;
    v12 = *(_OWORD *)&flame->matrix.M21;
    M2.r[2] = v9;
    v13 = *(_OWORD *)&flame->matrix.M31;
    M2.r[3] = v10;
    v14 = *(_OWORD *)&flame->matrix.M41;
    *(__m128 *)&matrix.M11 = DirectX::XMMatrixMultiply(M2.r, v11);
    v15 = rc->graphics;
    *(_OWORD *)&matrix.M21 = v12;
    *(_OWORD *)&matrix.M31 = v13;
    *(_OWORD *)&matrix.M41 = v14;
    GraphicsManager::setWorldMatrix(v15, &matrix);
    v16 = flame->textureIndex;
    if ( v16 >= this->textures._Mylast - this->textures._Myfirst )
    {
      _printf("ERROR, FLAME INDEX: %u NOT VALID\n", flame->textureIndex);
    }
    else
    {
      GraphicsManager::setTexture(this->game->graphics, 0, &this->textures._Myfirst[v16]);
      GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
      GLRenderer::color4f(gl, this->intensity, this->intensity, this->intensity, flame->visTime);
      GLRenderer::begin(gl, eQuads, 0);
      GLRenderer::texCoord2f(gl, 0.0, 0.0);
      GLRenderer::vertex3f(gl, 0.0, v17 - flame->vsizeStart, 0.0);
      GLRenderer::texCoord2f(gl, 0.0, 1.0);
      GLRenderer::vertex3f(gl, 0.0, flame->vsizeStart - v17, 0.0);
      GLRenderer::texCoord2f(gl, 1.0, 1.0);
      GLRenderer::vertex3f(gl, 0.0, flame->vsizeEnd + v17, flame->lsize + v18);
      GLRenderer::texCoord2f(gl, 1.0, 0.0);
      GLRenderer::vertex3f(gl, 0.0, COERCE_FLOAT(LODWORD(flame->vsizeEnd) ^ _xmm) - v17, flame->lsize - v18);
      GLRenderer::texCoord2f(gl, 0.0, 0.0);
      GLRenderer::vertex3f(gl, v17 - flame->vsizeStart, 0.0, 0.0);
      GLRenderer::texCoord2f(gl, 0.0, 1.0);
      GLRenderer::vertex3f(gl, flame->vsizeStart - v17, 0.0, 0.0);
      GLRenderer::texCoord2f(gl, 1.0, 1.0);
      GLRenderer::vertex3f(gl, flame->vsizeEnd + v17, 0.0, flame->lsize + v18);
      GLRenderer::texCoord2f(gl, 1.0, 0.0);
      GLRenderer::vertex3f(gl, COERCE_FLOAT(LODWORD(flame->vsizeEnd) ^ _xmm) - v17, 0.0, flame->lsize - v18);
      GLRenderer::texCoord2f(gl, 0.0, 0.0);
      GLRenderer::vertex3f(gl, v17 - flame->vsizeStart, v17 - flame->vsizeStart, 0.0);
      GLRenderer::texCoord2f(gl, 0.0, 1.0);
      GLRenderer::vertex3f(gl, flame->vsizeStart - v17, COERCE_FLOAT(LODWORD(flame->vsizeStart) ^ _xmm) - v17, 0.0);
      GLRenderer::texCoord2f(gl, 1.0, 1.0);
      GLRenderer::vertex3f(gl, flame->vsizeStart + v17, flame->vsizeStart - v17, 0.0);
      GLRenderer::texCoord2f(gl, 1.0, 0.0);
      GLRenderer::vertex3f(gl, COERCE_FLOAT(LODWORD(flame->vsizeStart) ^ _xmm) - v17, flame->vsizeStart + v17, 0.0);
      GLRenderer::end(gl);
    }
  }
}
void __userpurge Flames::drawFlame(Flames *this@<ecx>, float a2@<xmm0>, GLRenderer *gl, RenderContext *rc, BackfireState st, FlameGroup *g)
{
  FlameGroup *v6; // edx
  const __m128i *v7; // esi
  FlameInstanceV2 *v8; // edi
  int v9; // xmm4_4
  std::vector<FlameTexture> *v10; // eax
  FlameTexture *v11; // edx
  FlameTexture *v12; // ecx
  char v13; // al
  char v14; // dl
  __m128 v15; // xmm0
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  int v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  __m128 v23; // xmm5
  __m128 v24; // xmm7
  float v25; // xmm6_4
  __m128 v26; // xmm4
  float v27; // xmm6_4
  Node *v28; // eax
  float v29; // xmm3_4
  unsigned int v30; // xmm2_4
  unsigned int v31; // xmm1_4
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128i v36; // xmm1
  __m128i v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  unsigned int *v40; // eax
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  CameraForward *v43; // eax
  const __m128i *v44; // eax
  FlameType v45; // eax
  __int32 v46; // eax
  Flames *v47; // edx
  int v48; // ecx
  Texture *v49; // eax
  float v50; // xmm0_4
  float v51; // xmm1_4
  __int128 v52; // xmm3
  __int128 v53; // xmm2
  __int128 v54; // xmm1
  GraphicsManager *v55; // ecx
  Flames *v56; // ecx
  float v57; // xmm0_4
  float r_8; // [esp+8h] [ebp-228h]
  int v59; // [esp+10h] [ebp-220h]
  int v60; // [esp+14h] [ebp-21Ch]
  FlameTexture *v62; // [esp+28h] [ebp-208h]
  int v63; // [esp+2Ch] [ebp-204h]
  std::vector<FlameTexture> *v64; // [esp+38h] [ebp-1F8h]
  int v65; // [esp+38h] [ebp-1F8h]
  char v66; // [esp+3Ch] [ebp-1F4h]
  unsigned int v67; // [esp+44h] [ebp-1ECh]
  float v68; // [esp+50h] [ebp-1E0h]
  vec3f cameraUpVector; // [esp+58h] [ebp-1D8h] BYREF
  vec3f cameraForwardVector; // [esp+64h] [ebp-1CCh] BYREF
  mat44f matrix; // [esp+70h] [ebp-1C0h] BYREF
  __m128 v72; // [esp+B0h] [ebp-180h]
  __int128 v73; // [esp+C0h] [ebp-170h]
  _BYTE v74[32]; // [esp+D0h] [ebp-160h]
  vec3f objectPosition; // [esp+F0h] [ebp-140h] BYREF
  vec3f cameraPosition; // [esp+FCh] [ebp-134h] BYREF
  float v77; // [esp+110h] [ebp-120h]
  float v78; // [esp+11Ch] [ebp-114h]
  __m128 v79; // [esp+120h] [ebp-110h]
  DirectX::XMMATRIX M2; // [esp+130h] [ebp-100h] BYREF
  DirectX::XMMATRIX v81; // [esp+170h] [ebp-C0h] BYREF
  __m128 v82; // [esp+1E0h] [ebp-50h]
  mat44f result; // [esp+1F0h] [ebp-40h] BYREF

  if ( g->state == eCockpit )
    return;
  mat44f::mat44f(&matrix);
  v6 = g;
  v66 = 0;
  v7 = (const __m128i *)g->flames._Myfirst;
  v8 = g->flames._Mylast;
  if ( v7 == (const __m128i *)v8 )
    goto LABEL_49;
  v9 = _xmm;
  do
  {
    ++this->cycleIndex;
    if ( this->isFlashing )
    {
      v10 = (std::vector<FlameTexture> *)((char *)&v7[6].m128i_u64[1] + 4);
    }
    else
    {
      switch ( st )
      {
        case eCar:
          v10 = (std::vector<FlameTexture> *)&v7[4].m128i_u64[1];
          break;
        case eDrivable:
          v10 = (std::vector<FlameTexture> *)((char *)v7[5].m128i_i64 + 4);
          break;
        case eTrack:
          v10 = (std::vector<FlameTexture> *)&v7[6];
          break;
        default:
          goto LABEL_13;
      }
    }
    this->currentFlameVector = v10;
LABEL_13:
    v67 = 0;
    if ( this->currentFlameVector->_Mylast - this->currentFlameVector->_Myfirst )
    {
      v63 = 0;
      while ( 1 )
      {
        v64 = this->currentFlameVector;
        v62 = v64->_Myfirst;
        if ( v64->_Mylast - v64->_Myfirst <= v67 )
        {
          std::_Xout_of_range("invalid vector<T> subscript");
$LN232:
          v57 = a2 - v56->currentDt;
          v6->state = eTrack;
          v6->visTime = -5.0;
          v6->fuelInExhaust = 0.0;
          v6->flashTimes = v57;
          return;
        }
        v11 = v64->_Myfirst;
        v12 = &v62[v63];
        a2 = this->observeINI;
        if ( a2 != 0.0 )
        {
          v13 = 1;
          goto LABEL_33;
        }
        v13 = 0;
        if ( st == eCar )
          break;
        if ( st == eDrivable )
        {
          a2 = g->visTime;
          if ( a2 < v12->triggerTime )
            goto LABEL_32;
          v66 = 1;
          v11 = v64->_Myfirst;
          v13 = 1;
          if ( v67 == ((int)((unsigned __int64)(1321528399i64 * ((char *)v64->_Mylast - (char *)v64->_Myfirst)) >> 32) >> 5)
                    + ((unsigned int)((unsigned __int64)(1321528399i64 * ((char *)v64->_Mylast - (char *)v64->_Myfirst)) >> 32) >> 31)
                    - 1 )
            v66 = 0;
        }
        else
        {
          if ( st != eTrack )
            goto LABEL_32;
          a2 = v12->triggerTime;
          v11 = v64->_Myfirst;
          if ( a2 >= g->visTime )
          {
            v13 = 1;
            v66 = 1;
          }
        }
LABEL_33:
        if ( v13 )
        {
          v15 = (__m128)_mm_loadu_si128(v7 + 2);
          v16 = _mm_shuffle_ps(v15, v15, 85).m128_f32[0];
          LODWORD(v17) = v15.m128_i32[0] ^ v9;
          v82 = (__m128)_mm_loadu_si128(v7 + 3);
          v18 = _mm_shuffle_ps(v15, v15, 170).m128_f32[0];
          v15.m128_i32[0] = LODWORD(v11[v63].offset.z);
          v19 = LODWORD(v18) ^ v9;
          v20 = COERCE_FLOAT(LODWORD(v16) ^ v9) * v15.m128_f32[0];
          v21 = v82.m128_f32[0] + (float)(v17 * v15.m128_f32[0]);
          v22 = *(float *)&v19 * v15.m128_f32[0];
          v15.m128_i32[0] = LODWORD(v11[v63].offset.y);
          v23 = _mm_shuffle_ps(v82, v82, 170);
          v23.m128_f32[0] = v23.m128_f32[0] + v22;
          v24 = (__m128)_mm_loadu_si128(v7 + 1);
          v25 = _mm_shuffle_ps(v24, v24, 85).m128_f32[0];
          v79 = v23;
          v23.m128_f32[0] = _mm_shuffle_ps(v24, v24, 170).m128_f32[0];
          v24.m128_f32[0] = (float)(v24.m128_f32[0] * v15.m128_f32[0]) + v21;
          v26 = (__m128)_mm_loadu_si128(v7);
          v27 = (float)(v25 * v15.m128_f32[0]) + (float)(_mm_shuffle_ps(v82, v82, 85).m128_f32[0] + v20);
          v23.m128_f32[0] = v23.m128_f32[0] * v15.m128_f32[0];
          v15.m128_i32[0] = LODWORD(v11[v63].offset.x);
          v28 = this->car->bodyTransform;
          v29 = v26.m128_f32[0] * v15.m128_f32[0];
          *(float *)&v30 = (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] * v15.m128_f32[0]) + v27;
          *(float *)&v31 = (float)(_mm_shuffle_ps(v26, v26, 170).m128_f32[0] * v15.m128_f32[0])
                         + (float)(v23.m128_f32[0] + v79.m128_f32[0]);
          v32 = *(__m128 *)&v28->matrix.M11;
          *(unsigned __int64 *)((char *)v82.m128_u64 + 4) = __PAIR64__(v31, v30);
          v33 = *(__m128 *)&v28->matrix.M31;
          v34 = *(__m128 *)&v28->matrix.M21;
          v82.m128_f32[0] = v29 + v24.m128_f32[0];
          v35 = *(__m128 *)&v28->matrix.M41;
          M2.r[1] = v34;
          v36 = _mm_loadu_si128(v7 + 1);
          M2.r[2] = v33;
          v37 = _mm_loadu_si128(v7 + 2);
          M2.r[0] = v32;
          M2.r[3] = v35;
          v38 = v82;
          v39 = DirectX::XMMatrixMultiply(M2.r, v26);
          *(__m128i *)&matrix.M21 = v36;
          *(__m128 *)&matrix.M11 = v39;
          *(__m128 *)&matrix.M41 = v38;
          *(__m128i *)&matrix.M31 = v37;
          LODWORD(v78) = _mm_shuffle_ps(v38, v38, 170).m128_u32[0];
          *(_QWORD *)&objectPosition.x = _mm_unpacklo_ps(v38, _mm_shuffle_ps(v38, v38, 85)).m128_u64[0];
          objectPosition.z = v78;
          v40 = (unsigned int *)Sim::getSceneCamera(this->car->sim);
          v41 = (__m128)v40[14];
          v42 = (__m128)v40[15];
          v77 = *((float *)v40 + 16);
          cameraPosition.z = v77;
          *(_QWORD *)&cameraPosition.x = _mm_unpacklo_ps(v41, v42).m128_u64[0];
          v43 = Sim::getSceneCamera(this->car->sim);
          LODWORD(cameraForwardVector.x) = LODWORD(v43->matrix.M31) ^ _xmm;
          LODWORD(cameraForwardVector.y) = LODWORD(v43->matrix.M32) ^ _xmm;
          LODWORD(cameraForwardVector.z) = LODWORD(v43->matrix.M33) ^ _xmm;
          cameraUpVector = *(vec3f *)&Sim::getSceneCamera(this->car->sim)->matrix.M21;
          v44 = (const __m128i *)mat44f::createBillboard(
                                   &result,
                                   &objectPosition,
                                   &cameraPosition,
                                   &cameraUpVector,
                                   &cameraForwardVector);
          v65 = 0;
          *(__m128i *)&matrix.M11 = _mm_loadu_si128(v44);
          *(__m128i *)&matrix.M21 = _mm_loadu_si128(v44 + 1);
          *(__m128i *)&matrix.M31 = _mm_loadu_si128(v44 + 2);
          *(__m128i *)&matrix.M41 = _mm_loadu_si128(v44 + 3);
          v45 = v62[v63].flametype;
          if ( v45 == eFlash )
          {
            Flames::cycleTexture(this, &v62[v63], this->cycleIndex);
            v47 = this;
            v48 = this->textureFlashIndex;
            v49 = this->flashTextures._Myfirst;
            goto LABEL_44;
          }
          v46 = v45 - 1;
          if ( v46 )
          {
            if ( v46 == 1 )
            {
              v47 = this;
              v65 = 20 * this->cycleIndex;
              if ( !g->frameTimeSwitch )
              {
                Flames::cycleTexture(this, &v62[v63], this->cycleIndex);
                v47 = this;
              }
              v48 = v47->textureTailIndex;
              v49 = v47->tailTextures._Myfirst;
              goto LABEL_44;
            }
          }
          else
          {
            v47 = this;
            v65 = 10 * this->cycleIndex;
            if ( !g->frameTimeSwitch )
            {
              Flames::cycleTexture(this, &v62[v63], this->cycleIndex);
              v47 = this;
            }
            v48 = v47->textureBodyIndex;
            v49 = v47->textures._Myfirst;
LABEL_44:
            GraphicsManager::setTexture(v47->game->graphics, 0, &v49[v48]);
          }
          this->rotation = (v65 + this->rotation) % 360;
          v68 = __libm_sse2_cosf(v59, v60).m128_f32[0];
          v50 = __libm_sse2_sinf().m128_f32[0];
          v72.m128_i32[3] = 0;
          HIDWORD(v73) = 0;
          *(_OWORD *)&v74[12] = 0i64;
          *(_DWORD *)&v74[28] = 1065353216;
          v51 = (float)(1.0 - v68) * 0.0;
          *(float *)&v74[8] = (float)(1.0 - v68) + v68;
          *((float *)&v73 + 1) = v51 + v68;
          v72.m128_f32[0] = v51 + v68;
          v81 = (DirectX::XMMATRIX)matrix;
          v52 = *(_OWORD *)&v74[16];
          v72.m128_f32[1] = v50 + v51;
          *(float *)&v73 = v51 - v50;
          v72.m128_f32[2] = v51 - (float)(v50 * 0.0);
          *(float *)v74 = (float)(v50 * 0.0) + v51;
          *((float *)&v73 + 2) = *(float *)v74;
          *(float *)&v74[4] = v72.m128_f32[2];
          v53 = *(_OWORD *)v74;
          v54 = v73;
          *(__m128 *)&matrix.M11 = DirectX::XMMatrixMultiply(v81.r, v72);
          *(_OWORD *)&matrix.M21 = v54;
          v55 = rc->graphics;
          *(_OWORD *)&matrix.M31 = v53;
          *(_OWORD *)&matrix.M41 = v52;
          GraphicsManager::setWorldMatrix(v55, &matrix);
          GLRenderer::color4f(gl, v62[v63].color.x, v62[v63].color.y, v62[v63].color.z, v62[v63].color.w);
          GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
          GLRenderer::begin(gl, eQuads, 0);
          GLRenderer::texCoord2f(gl, 0.0, 0.0);
          GLRenderer::vertex3f(
            gl,
            COERCE_FLOAT(LODWORD(v62[v63].size) ^ _xmm),
            COERCE_FLOAT(LODWORD(v62[v63].size) ^ _xmm),
            0.0);
          GLRenderer::texCoord2f(gl, 0.0, 1.0);
          GLRenderer::vertex3f(gl, v62[v63].size, COERCE_FLOAT(LODWORD(v62[v63].size) ^ _xmm), 0.0);
          GLRenderer::texCoord2f(gl, 1.0, 1.0);
          GLRenderer::vertex3f(gl, v62[v63].size, v62[v63].size, 0.0);
          GLRenderer::texCoord2f(gl, 1.0, 0.0);
          r_8 = v62[v63].size;
          LODWORD(a2) = LODWORD(r_8) ^ _xmm;
          GLRenderer::vertex3f(gl, COERCE_FLOAT(LODWORD(r_8) ^ _xmm), r_8, 0.0);
          GLRenderer::end(gl);
          v9 = _xmm;
        }
        ++v67;
        ++v63;
        if ( v67 >= this->currentFlameVector->_Mylast - this->currentFlameVector->_Myfirst )
          goto LABEL_47;
      }
      a2 = g->visTime;
      if ( a2 >= v12->triggerTime )
      {
        v14 = 1;
        v13 = 1;
        if ( v67 == ((int)((unsigned __int64)(1321528399i64 * ((char *)v64->_Mylast - (char *)v64->_Myfirst)) >> 32) >> 5)
                  - 1
                  + ((unsigned int)((unsigned __int64)(1321528399i64 * ((char *)v64->_Mylast - (char *)v64->_Myfirst)) >> 32) >> 31) )
          v14 = 0;
        v66 = v14;
      }
      if ( g->state == eDrivable )
        v13 = 1;
LABEL_32:
      v11 = v64->_Myfirst;
      goto LABEL_33;
    }
LABEL_47:
    v7 = (const __m128i *)((char *)v7 + 120);
  }
  while ( v7 != (const __m128i *)v8 );
  v6 = g;
LABEL_49:
  v56 = this;
  if ( this->observeINI == 0.0 )
  {
    if ( v6->state == eCar )
    {
      if ( !v66 )
      {
        v6->state = eDrivable;
        v6->visTime = 0.0;
      }
    }
    else if ( v6->state == eDrivable )
    {
      if ( !v66 )
        v6->visTime = 0.0;
    }
    else if ( v6->state == eTrack && !v66 )
    {
      a2 = v6->flashTimes;
      if ( a2 > 0.0 )
        goto $LN232;
      v6->state = eCockpit;
      v6->visTime = 0.0;
      v6->fuelInExhaust = 0.0;
    }
  }
}
void Flames::loadFlames(Flames *this)
{
  std::vector<FlameInstance> *v2; // edi
  std::vector<FlameGroup> *v3; // ebp
  bool v4; // zf
  CarAvatar *v5; // eax
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  CarAvatar *v8; // eax
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  CarAvatar *v11; // ecx
  void (*v12)(const char *const, ...); // esi
  double v13; // st7
  bool v14; // cf
  float v15; // xmm1_4
  float v16; // xmm0_4
  double v17; // st7
  double v18; // st7
  int v19; // esi
  int v20; // esi
  std::wostream *v21; // eax
  const std::wstring *v22; // eax
  char v23; // al
  const std::wstring *v24; // eax
  float v25; // xmm1_4
  const __m128i *v26; // eax
  __m128i v27; // xmm0
  const std::wstring *v28; // eax
  const std::wstring *v29; // eax
  const std::wstring *v30; // eax
  const std::wstring *v31; // eax
  const std::wstring *v32; // eax
  float v33; // xmm1_4
  const __m128i *v34; // eax
  const std::wstring *v35; // eax
  const std::wstring *v36; // eax
  const std::wstring *v37; // eax
  const std::wstring *v38; // eax
  const std::wstring *v39; // eax
  const std::wstring *v40; // eax
  unsigned __int16 v41; // di
  int v42; // ecx
  unsigned int v43; // esi
  unsigned __int16 *v44; // eax
  char v45; // al
  int v46; // edi
  FlameGroup *v47; // ebp
  const std::vector<FlameTexture> *v48; // esi
  const std::vector<FlameTexture> *v49; // ebx
  Flames *v50; // edi
  const std::vector<FlameTexture> *v51; // ebp
  float v52; // eax
  std::wstring v53; // [esp-1Ch] [ebp-33Ch] BYREF
  const std::vector<FlameTexture> *v54; // [esp-4h] [ebp-324h]
  char v55; // [esp+1Bh] [ebp-305h] BYREF
  int v56; // [esp+1Ch] [ebp-304h]
  unsigned int j; // [esp+20h] [ebp-300h]
  Flames *v58; // [esp+28h] [ebp-2F8h]
  vec3f dir; // [esp+2Ch] [ebp-2F4h] BYREF
  vec3f cameraPosition; // [esp+38h] [ebp-2E8h] BYREF
  vec3f cameraTarget; // [esp+44h] [ebp-2DCh] BYREF
  vec3f v62; // [esp+50h] [ebp-2D0h] BYREF
  FlameInstanceV2 i; // [esp+5Ch] [ebp-2C4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v64; // [esp+D4h] [ebp-24Ch] BYREF
  FlameInstanceV2 temp; // [esp+184h] [ebp-19Ch] BYREF
  std::wstring v66; // [esp+1FCh] [ebp-124h] BYREF
  std::wstring result; // [esp+214h] [ebp-10Ch] BYREF
  FlameGroup fg; // [esp+22Ch] [ebp-F4h] BYREF
  std::wstring key; // [esp+26Ch] [ebp-B4h] BYREF
  std::wstring _Left; // [esp+284h] [ebp-9Ch] BYREF
  INIReader ini; // [esp+29Ch] [ebp-84h] BYREF
  std::wstring v72; // [esp+2E0h] [ebp-40h] BYREF
  std::wstring v73; // [esp+2F8h] [ebp-28h] BYREF
  int v74; // [esp+31Ch] [ebp-4h]

  v58 = this;
  v2 = &this->flames;
  j = 0;
  std::_Container_base0::_Orphan_all(&this->flames);
  v3 = &this->flamesV2;
  v2->_Mylast = v2->_Myfirst;
  std::_Container_base0::_Orphan_all(&this->flamesV2);
  v54 = (const std::vector<FlameTexture> *)v58;
  v53._Myres = (unsigned int)&v55;
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<FlameGroup>>>(this->flamesV2._Myfirst, this->flamesV2._Mylast);
  this->flamesV2._Mylast = this->flamesV2._Myfirst;
  FlameInstanceV2::FlameInstanceV2(&temp);
  v4 = this->version == 2;
  v74 = 0;
  if ( v4 )
  {
    _Left._Myres = 7;
    _Left._Mysize = 0;
    _Left._Bx._Buf[0] = 0;
    std::wstring::assign(&_Left, L"content/cars/", 0xDu);
    v5 = this->car;
    LOBYTE(v74) = 1;
    v6 = std::operator+<wchar_t>(&result, &_Left, &v5->unixName);
    LOBYTE(v74) = 2;
    v7 = std::operator+<wchar_t>(&v66, v6, L"/data/flame_presets.ini");
    LOBYTE(v74) = 3;
    Flames::readFlamePresets(this, v7, &temp);
    if ( v66._Myres >= 8 )
      operator delete(v66._Bx._Ptr);
    v66._Myres = 7;
    v66._Mysize = 0;
    v66._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v74) = 0;
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
  }
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v8 = this->car;
  LOBYTE(v74) = 4;
  v9 = std::operator+<wchar_t>(&v73, &_Left, &v8->unixName);
  LOBYTE(v74) = 5;
  v10 = std::operator+<wchar_t>(&v72, v9, L"/data/flames.ini");
  v11 = this->car;
  LOBYTE(v74) = 6;
  CarAvatar::openINI(v11, &ini, v10);
  if ( v72._Myres >= 8 )
    operator delete(v72._Bx._Ptr);
  v72._Myres = 7;
  v72._Mysize = 0;
  v72._Bx._Buf[0] = 0;
  if ( v73._Myres >= 8 )
    operator delete(v73._Bx._Ptr);
  v73._Myres = 7;
  v73._Mysize = 0;
  v73._Bx._Buf[0] = 0;
  LOBYTE(v74) = 10;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&ini, 0);
  v12 = (void (*)(const char *const, ...))_printf;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"INTENSITY", 9u);
    LOBYTE(v74) = 11;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"HEADER", 6u);
    LOBYTE(v74) = 12;
    v13 = INIReader::getFloat(&ini, &result, &key);
    v14 = result._Myres < 8;
    this->intensity = v13;
    if ( !v14 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v74) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v15 = FLOAT_1_0;
    if ( !this->car->sim->game->graphics->videoSettings.ppHDREnabled )
    {
      v16 = this->intensity;
      if ( v16 > 1.0 || (v15 = 0.0, v16 < 0.0) )
        v16 = v15;
      this->intensity = v16;
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BURN_FUEL_MULT", 0xEu);
    LOBYTE(v74) = 13;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"HEADER", 6u);
    LOBYTE(v74) = 14;
    v55 = INIReader::hasKey(&ini, &result, &key);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v74) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v55 )
    {
      std::wstring::wstring((std::wstring *)&fg, L"BURN_FUEL_MULT");
      LOBYTE(v74) = 15;
      std::wstring::wstring(&result, L"HEADER");
      LOBYTE(v74) = 16;
      v17 = INIReader::getFloat(&ini, &result, (const std::wstring *)&fg);
      v14 = result._Myres < 8;
      this->burnFuelMult = v17;
      if ( !v14 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v74) = 10;
      if ( fg.frameTimeSwitch >= 8u )
        operator delete(LODWORD(fg.fuelInExhaust));
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FLASH_THRESHOLD", 0xFu);
    LOBYTE(v74) = 17;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"HEADER", 6u);
    LOBYTE(v74) = 18;
    v55 = INIReader::hasKey(&ini, &result, &key);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v74) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v55 )
    {
      std::wstring::wstring((std::wstring *)&fg, L"FLASH_THRESHOLD");
      LOBYTE(v74) = 19;
      std::wstring::wstring(&result, L"HEADER");
      LOBYTE(v74) = 20;
      v18 = INIReader::getFloat(&ini, &result, (const std::wstring *)&fg);
      v14 = result._Myres < 8;
      this->flashThreshold = v18;
      if ( !v14 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v74) = 10;
      if ( fg.frameTimeSwitch >= 8u )
        operator delete(LODWORD(fg.fuelInExhaust));
    }
    if ( this->observeINI != 0.0 )
    {
      v54 = (const std::vector<FlameTexture> *)L"EDIT_STATE";
      this->isFlashing = 0;
      std::wstring::wstring((std::wstring *)&fg, (const wchar_t *)v54);
      LOBYTE(v74) = 21;
      std::wstring::wstring(&result, L"HEADER");
      LOBYTE(v74) = 22;
      v19 = INIReader::getInt(&ini, &result, (const std::wstring *)&fg);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v74) = 10;
      if ( fg.frameTimeSwitch >= 8u )
        operator delete(LODWORD(fg.fuelInExhaust));
      switch ( v19 )
      {
        case 0:
          this->edit_state = eCockpit;
          goto LABEL_53;
        case 1:
          this->edit_state = eCar;
          this->edit_time = 10000.0;
          break;
        case 2:
          this->edit_state = eDrivable;
          this->edit_time = 10000.0;
          break;
        case 3:
          goto $LN28_1;
        case 4:
          this->isFlashing = 1;
$LN28_1:
          this->edit_state = eTrack;
LABEL_53:
          this->edit_time = 0.0;
          break;
        default:
          break;
      }
    }
    v20 = 0;
    v56 = 0;
    while ( 1 )
    {
      *(_DWORD *)v64.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v64.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v64.gap68);
      j |= 1u;
      LOBYTE(v74) = 23;
      std::wiostream::basic_iostream<wchar_t>(&v64, &v64.gap10[8], 0);
      v74 = 24;
      *(_DWORD *)&v64.gap0[*(_DWORD *)(*(_DWORD *)v64.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(FlameTexture **)((char *)&i.FlamesFlash._Myend + *(_DWORD *)(*(_DWORD *)v64.gap0 + 4)) = (FlameTexture *)(*(_DWORD *)(*(_DWORD *)v64.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v64.gap10[8]);
      *(_DWORD *)&v64.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v64.gap10[64] = 0;
      *(_DWORD *)&v64.gap10[68] = 0;
      LOBYTE(v74) = 26;
      v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v64.gap10, "FLAME_");
      std::wostream::operator<<(v21, v20);
      v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v64,
              (std::wstring *)&fg);
      LOBYTE(v74) = 27;
      v23 = INIReader::hasSection(&ini, v22);
      v55 = v23;
      LOBYTE(v74) = 26;
      if ( fg.frameTimeSwitch >= 8u )
      {
        operator delete(LODWORD(fg.fuelInExhaust));
        v23 = v55;
      }
      if ( !v23 )
        break;
      if ( this->version == 1 )
      {
        mat44f::mat44f(&i.matrix);
        mat44f::loadIdentity(&i.matrix);
        i.FlamesStart._Mylast = 0;
        i.FlamesStart._Myend = 0;
        i.FlamesLoop._Myfirst = (FlameTexture *)1036831949;
        v66._Myres = 7;
        v66._Mysize = 0;
        v66._Bx._Buf[0] = 0;
        std::wstring::assign(&v66, L"DIRECTION", 9u);
        LOBYTE(v74) = 28;
        v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 29;
        INIReader::getFloat3(&ini, &dir, v24, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 26;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        v25 = fsqrt((float)((float)(dir.x * dir.x) + (float)(dir.y * dir.y)) + (float)(dir.z * dir.z));
        if ( v25 != 0.0 )
        {
          dir.x = dir.x * (float)(1.0 / v25);
          dir.y = dir.y * (float)(1.0 / v25);
          dir.z = dir.z * (float)(1.0 / v25);
        }
        cameraTarget.x = 0.0;
        cameraTarget.y = 0.0;
        cameraTarget.z = 0.0;
        v26 = (const __m128i *)mat44f::createTarget((mat44f *)&fg, &dir, &cameraTarget);
        v66._Myres = 7;
        v66._Mysize = 0;
        *(__m128i *)&i.matrix.M11 = _mm_loadu_si128(v26);
        *(__m128i *)&i.matrix.M21 = _mm_loadu_si128(v26 + 1);
        *(__m128i *)&i.matrix.M31 = _mm_loadu_si128(v26 + 2);
        v27 = _mm_loadu_si128(v26 + 3);
        v66._Bx._Buf[0] = 0;
        *(__m128i *)&i.matrix.M41 = v27;
        std::wstring::assign(&v66, L"POSITION", 8u);
        LOBYTE(v74) = 30;
        v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 31;
        *(vec3f *)&i.matrix.M41 = *INIReader::getFloat3(&ini, (vec3f *)&key, v28, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 26;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        v66._Myres = 7;
        v66._Mysize = 0;
        v66._Bx._Buf[0] = 0;
        std::wstring::assign(&v66, L"LSIZE", 5u);
        LOBYTE(v74) = 32;
        v29 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 33;
        *(float *)&i.FlamesStart._Myfirst = INIReader::getFloat(&ini, v29, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 26;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        std::wstring::wstring(&v66, L"VSIZE_START");
        LOBYTE(v74) = 34;
        v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 35;
        i.sizeMult = INIReader::getFloat(&ini, v30, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 26;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        std::wstring::wstring(&v66, L"VSIZE_END");
        LOBYTE(v74) = 36;
        v31 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 37;
        *(float *)&i.isLeft = INIReader::getFloat(&ini, v31, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 26;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        std::vector<FlameInstance>::push_back(v2, (const FlameInstance *)&i);
      }
      else
      {
        FlameInstanceV2::FlameInstanceV2(&i);
        LOBYTE(v74) = 38;
        std::wstring::wstring(&v66, L"DIRECTION");
        LOBYTE(v74) = 39;
        v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 40;
        INIReader::getFloat3(&ini, &cameraPosition, v32, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 38;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        v33 = fsqrt(
                (float)((float)(cameraPosition.x * cameraPosition.x) + (float)(cameraPosition.y * cameraPosition.y))
              + (float)(cameraPosition.z * cameraPosition.z));
        if ( v33 != 0.0 )
        {
          cameraPosition.x = cameraPosition.x * (float)(1.0 / v33);
          cameraPosition.y = cameraPosition.y * (float)(1.0 / v33);
          cameraPosition.z = cameraPosition.z * (float)(1.0 / v33);
        }
        v62.x = 0.0;
        v62.y = 0.0;
        v62.z = 0.0;
        v34 = (const __m128i *)mat44f::createTarget((mat44f *)&fg, &cameraPosition, &v62);
        *(__m128i *)&i.matrix.M11 = _mm_loadu_si128(v34);
        *(__m128i *)&i.matrix.M21 = _mm_loadu_si128(v34 + 1);
        *(__m128i *)&i.matrix.M31 = _mm_loadu_si128(v34 + 2);
        *(__m128i *)&i.matrix.M41 = _mm_loadu_si128(v34 + 3);
        std::wstring::wstring(&v66, L"POSITION");
        LOBYTE(v74) = 41;
        v35 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 42;
        *(vec3f *)&i.matrix.M41 = *INIReader::getFloat3(&ini, (vec3f *)&result, v35, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 38;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        std::wstring::wstring(&v66, L"IS_LEFT");
        LOBYTE(v74) = 43;
        v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 44;
        v55 = INIReader::hasKey(&ini, v36, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 38;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        if ( v55 )
        {
          std::wstring::wstring(&v66, L"IS_LEFT");
          LOBYTE(v74) = 45;
          v37 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                  &v64,
                  (std::wstring *)&fg);
          LOBYTE(v74) = 46;
          i.isLeft = INIReader::getInt(&ini, v37, &v66) != 0;
          if ( fg.frameTimeSwitch >= 8u )
            operator delete(LODWORD(fg.fuelInExhaust));
          fg.frameTimeSwitch = 7;
          fg.visTime = 0.0;
          LOWORD(fg.fuelInExhaust) = 0;
          LOBYTE(v74) = 38;
          if ( v66._Myres >= 8 )
            operator delete(v66._Bx._Ptr);
        }
        std::wstring::wstring(&v66, L"SIZE_MULT");
        LOBYTE(v74) = 47;
        v38 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 48;
        v55 = INIReader::hasKey(&ini, v38, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 38;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        if ( v55 )
        {
          std::wstring::wstring(&v66, L"SIZE_MULT");
          LOBYTE(v74) = 49;
          v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                  &v64,
                  (std::wstring *)&fg);
          LOBYTE(v74) = 50;
          i.sizeMult = INIReader::getFloat(&ini, v39, &v66);
          if ( fg.frameTimeSwitch >= 8u )
            operator delete(LODWORD(fg.fuelInExhaust));
          fg.frameTimeSwitch = 7;
          fg.visTime = 0.0;
          LOWORD(fg.fuelInExhaust) = 0;
          LOBYTE(v74) = 38;
          if ( v66._Myres >= 8 )
            operator delete(v66._Bx._Ptr);
        }
        else
        {
          i.sizeMult = 1.0;
        }
        std::wstring::wstring(&v66, L"GROUP");
        LOBYTE(v74) = 51;
        v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &v64,
                (std::wstring *)&fg);
        LOBYTE(v74) = 52;
        v41 = INIReader::getInt(&ini, v40, &v66);
        if ( fg.frameTimeSwitch >= 8u )
          operator delete(LODWORD(fg.fuelInExhaust));
        fg.frameTimeSwitch = 7;
        fg.visTime = 0.0;
        LOWORD(fg.fuelInExhaust) = 0;
        LOBYTE(v74) = 38;
        if ( v66._Myres >= 8 )
          operator delete(v66._Bx._Ptr);
        Flames::copyFlameVector(this, &temp.FlamesStart, &i.FlamesStart, &i);
        Flames::copyFlameVector(this, &temp.FlamesLoop, &i.FlamesLoop, &i);
        Flames::copyFlameVector(this, &temp.FlamesEnd, &i.FlamesEnd, &i);
        Flames::copyFlameVector(this, &temp.FlamesFlash, &i.FlamesFlash, &i);
        v42 = (char *)this->flamesV2._Mylast - (char *)this->flamesV2._Myfirst;
        v43 = 0;
        v55 = 1;
        if ( v42 / 40 )
        {
          v44 = &v3->_Myfirst->group;
          while ( *v44 != v41 )
          {
            ++v43;
            v44 += 20;
            if ( v43 >= this->flamesV2._Mylast - this->flamesV2._Myfirst )
              goto LABEL_119;
          }
          std::vector<FlameInstanceV2>::push_back(&v3->_Myfirst[v43].flames, &i);
          v45 = 0;
        }
        else
        {
LABEL_119:
          v45 = v55;
        }
        if ( v45 )
        {
          fg.flames._Myfirst = 0;
          fg.flames._Mylast = 0;
          fg.flames._Myend = 0;
          fg.state = eCockpit;
          fg.visTime = -1.0;
          fg.frameTimeSwitch = 0;
          fg.fuelInExhaust = 0.0;
          fg.fuelDiff = 0.0;
          fg.flashTimes = 0.0;
          LOBYTE(v74) = 53;
          fg.group = v41;
          std::vector<FlameInstanceV2>::push_back(&fg.flames, &i);
          std::vector<FlameGroup>::push_back(&this->flamesV2, &fg);
          LOBYTE(v74) = 38;
          std::vector<FlameInstanceV2>::_Tidy(&fg.flames);
        }
        FlameInstanceV2::~FlameInstanceV2(&i);
        v20 = v56;
        v2 = &this->flames;
      }
      ++v20;
      LOBYTE(v74) = 10;
      v56 = v20;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v64);
    }
    LOBYTE(v74) = 10;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v64);
    v12 = (void (*)(const char *const, ...))_printf;
  }
  else
  {
    _printf("WARNING: flames.ini not found\n");
  }
  if ( this->version == 1 )
  {
    if ( v2->_Mylast - v2->_Myfirst && !(this->textures._Mylast - this->textures._Myfirst) )
    {
      std::wstring::wstring((std::wstring *)&fg, L"Flame V1: texture not found");
      v52 = COERCE_FLOAT(&fg);
      LOBYTE(v74) = 54;
      if ( fg.frameTimeSwitch >= 8u )
        v52 = fg.fuelInExhaust;
      v12("Kunos Simulazioni: CRITICAL ERROR\n%S\n", (const wchar_t *)LODWORD(v52));
      ksGenerateCrash();
      if ( fg.frameTimeSwitch >= 8u )
        operator delete(LODWORD(fg.fuelInExhaust));
    }
  }
  else if ( this->version == 2 )
  {
    v46 = (int)v3->_Myfirst;
    v47 = this->flamesV2._Mylast;
    v56 = v46;
    for ( j = (unsigned int)v47; (FlameGroup *)v46 != v47; v56 = v46 )
    {
      v48 = *(const std::vector<FlameTexture> **)(v46 + 28);
      v49 = *(const std::vector<FlameTexture> **)(v46 + 32);
      if ( v48 != v49 )
      {
        v50 = v58;
        v51 = v48 + 7;
        do
        {
          v54 = v51 - 1;
          v53._Myres = 7;
          v53._Mysize = 0;
          v53._Bx._Buf[0] = 0;
          std::wstring::assign(&v53, L"FlameStart", 0xAu);
          Flames::checkTextures(v50, v53, v54);
          v54 = v51;
          v53._Myres = 7;
          v53._Mysize = 0;
          v53._Bx._Buf[0] = 0;
          std::wstring::assign(&v53, L"FlameLoop", 9u);
          Flames::checkTextures(v50, v53, v54);
          v54 = v51 + 1;
          v53._Myres = 7;
          v53._Mysize = 0;
          v53._Bx._Buf[0] = 0;
          std::wstring::assign(&v53, L"FlameEnd", 8u);
          Flames::checkTextures(v50, v53, v54);
          v54 = v51 + 2;
          v53._Myres = 7;
          v53._Mysize = 0;
          v53._Bx._Buf[0] = 0;
          std::wstring::assign(&v53, L"FlameFlash", 0xAu);
          Flames::checkTextures(v50, v53, v54);
          v48 += 10;
          v51 += 10;
        }
        while ( v48 != v49 );
        v46 = v56;
        v47 = (FlameGroup *)j;
      }
      v46 += 40;
    }
  }
  LOBYTE(v74) = 0;
  INIReader::~INIReader(&ini);
  FlameInstanceV2::~FlameInstanceV2(&temp);
}
void Flames::loadTextures(Flames *this, std::wstring folder)
{
  bool v3; // zf
  const std::wstring *v4; // eax
  std::wstring *v5; // esi
  std::wstring *v6; // edi
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  Game *v9; // ecx
  Texture *v10; // eax
  char v11; // al
  std::wstring *v12; // ecx
  std::wstring *v13; // eax
  const std::wstring *v14; // eax
  Game *v15; // ecx
  Texture *v16; // eax
  std::wstring *v17; // ecx
  std::wstring *v18; // eax
  const std::wstring *v19; // eax
  Game *v20; // ecx
  Texture *v21; // eax
  std::wstring *v22; // eax
  const std::wstring *v23; // eax
  Game *v24; // ecx
  Texture *v25; // eax
  std::wstring *v26; // edi
  std::wstring *v27; // esi
  std::vector<std::wstring> f; // [esp+14h] [ebp-98h] BYREF
  std::wstring v29; // [esp+20h] [ebp-8Ch] BYREF
  std::wstring v30; // [esp+38h] [ebp-74h] BYREF
  std::wstring ext; // [esp+50h] [ebp-5Ch] BYREF
  Texture v32; // [esp+68h] [ebp-44h] BYREF
  std::wstring result; // [esp+84h] [ebp-28h] BYREF
  int v34; // [esp+A8h] [ebp-4h]

  v34 = 0;
  ext._Myres = 7;
  ext._Mysize = 0;
  ext._Bx._Buf[0] = 0;
  std::wstring::assign(&ext, L"/*.dds", 6u);
  v3 = this->version == 1;
  LOBYTE(v34) = 1;
  if ( v3 )
    std::wstring::assign(&ext, L"/*.png", 6u);
  v4 = std::operator+<wchar_t>(&result, &folder, &ext);
  LOBYTE(v34) = 2;
  Path::getFiles(&f, v4);
  LOBYTE(v34) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v5 = f._Myfirst;
  v3 = this->version == 1;
  v6 = f._Mylast;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v3 )
  {
    if ( f._Myfirst == f._Mylast )
      goto LABEL_39;
    do
    {
      v7 = std::operator+<wchar_t>(&v30, &folder, L"/");
      LOBYTE(v34) = 5;
      v8 = std::operator+<wchar_t>(&v29, v7, v5);
      v9 = this->game;
      LOBYTE(v34) = 6;
      v10 = ResourceStore::getTexture(v9->graphics->resourceStore._Myptr, &v32, v8, 0);
      LOBYTE(v34) = 7;
      std::vector<Texture>::push_back(&this->textures, v10);
      LOBYTE(v34) = 6;
      OnSetupAppCreated::~OnSetupAppCreated(&v32);
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      LOBYTE(v34) = 4;
      if ( v30._Myres >= 8 )
        operator delete(v30._Bx._Ptr);
      ++v5;
    }
    while ( v5 != v6 );
  }
  else
  {
    if ( f._Myfirst == f._Mylast )
      goto LABEL_39;
    do
    {
      v11 = 0;
      if ( v5->_Myres < 8 )
        v12 = v5;
      else
        v12 = (std::wstring *)v5->_Bx._Ptr;
      if ( v12->_Bx._Buf[0] == 102 )
      {
        v13 = std::operator+<wchar_t>(&v30, &folder, L"/");
        LOBYTE(v34) = 8;
        v14 = std::operator+<wchar_t>(&v29, v13, v5);
        v15 = this->game;
        LOBYTE(v34) = 9;
        v16 = ResourceStore::getTexture(v15->graphics->resourceStore._Myptr, &v32, v14, 0);
        LOBYTE(v34) = 10;
        std::vector<Texture>::push_back(&this->flashTextures, v16);
        LOBYTE(v34) = 9;
        OnSetupAppCreated::~OnSetupAppCreated(&v32);
        if ( v29._Myres >= 8 )
          operator delete(v29._Bx._Ptr);
        v29._Myres = 7;
        v29._Mysize = 0;
        v29._Bx._Buf[0] = 0;
        LOBYTE(v34) = 4;
        if ( v30._Myres >= 8 )
          operator delete(v30._Bx._Ptr);
        v11 = 1;
      }
      if ( v5->_Myres < 8 )
        v17 = v5;
      else
        v17 = (std::wstring *)v5->_Bx._Ptr;
      if ( v17->_Bx._Buf[0] == 108 )
      {
        v18 = std::operator+<wchar_t>(&v30, &folder, L"/");
        LOBYTE(v34) = 11;
        v19 = std::operator+<wchar_t>(&v29, v18, v5);
        v20 = this->game;
        LOBYTE(v34) = 12;
        v21 = ResourceStore::getTexture(v20->graphics->resourceStore._Myptr, &v32, v19, 0);
        LOBYTE(v34) = 13;
        std::vector<Texture>::push_back(&this->tailTextures, v21);
        LOBYTE(v34) = 12;
        OnSetupAppCreated::~OnSetupAppCreated(&v32);
        if ( v29._Myres >= 8 )
          operator delete(v29._Bx._Ptr);
        v29._Myres = 7;
        v29._Mysize = 0;
        v29._Bx._Buf[0] = 0;
        LOBYTE(v34) = 4;
        if ( v30._Myres >= 8 )
          operator delete(v30._Bx._Ptr);
        v11 = 1;
      }
      if ( !v11 )
      {
        v22 = std::operator+<wchar_t>(&v30, &folder, L"/");
        LOBYTE(v34) = 14;
        v23 = std::operator+<wchar_t>(&v29, v22, v5);
        v24 = this->game;
        LOBYTE(v34) = 15;
        v25 = ResourceStore::getTexture(v24->graphics->resourceStore._Myptr, &v32, v23, 0);
        LOBYTE(v34) = 16;
        std::vector<Texture>::push_back(&this->textures, v25);
        LOBYTE(v34) = 15;
        OnSetupAppCreated::~OnSetupAppCreated(&v32);
        if ( v29._Myres >= 8 )
          operator delete(v29._Bx._Ptr);
        v29._Myres = 7;
        v29._Mysize = 0;
        v29._Bx._Buf[0] = 0;
        LOBYTE(v34) = 4;
        if ( v30._Myres >= 8 )
          operator delete(v30._Bx._Ptr);
      }
      ++v5;
    }
    while ( v5 != v6 );
  }
  v5 = f._Myfirst;
LABEL_39:
  LOBYTE(v34) = 1;
  if ( v5 )
  {
    std::_Container_base0::_Orphan_all(&f);
    v26 = f._Mylast;
    v27 = f._Myfirst;
    if ( f._Myfirst != f._Mylast )
    {
      do
      {
        if ( v27->_Myres >= 8 )
          operator delete(v27->_Bx._Ptr);
        v27->_Myres = 7;
        v27->_Mysize = 0;
        v27->_Bx._Buf[0] = 0;
        ++v27;
      }
      while ( v27 != v26 );
      v27 = f._Myfirst;
    }
    operator delete(v27);
    f._Myfirst = 0;
    f._Mylast = 0;
    f._Myend = 0;
  }
  if ( ext._Myres >= 8 )
    operator delete(ext._Bx._Ptr);
  ext._Myres = 7;
  ext._Mysize = 0;
  ext._Bx._Buf[0] = 0;
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
}
void __userpurge Flames::onNodeRenderEvent(Flames *this@<ecx>, float a2@<xmm0>, const OnNodeRenderEvent *e)
{
  GraphicsManager *v5; // ecx
  FlameInstance *v6; // edi
  FlameInstance *i; // esi
  FlameGroup *v8; // edi
  FlameGroup *j; // esi
  GLRenderer *ea; // [esp+Ch] [ebp+4h]

  if ( e->renderContext->meshFilter->passID == Transparent && CarAvatar::isVisible(this->car) )
  {
    v5 = this->game->graphics;
    ea = v5->gl;
    GraphicsManager::setCullMode(v5, eCullNone);
    GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
    if ( this->version == 1 )
    {
      v6 = this->flames._Mylast;
      for ( i = this->flames._Myfirst; i != v6; ++i )
        Flames::drawFlame(this, ea, i, e->renderContext);
    }
    else
    {
      this->cycleIndex = 0;
      v8 = this->flamesV2._Mylast;
      for ( j = this->flamesV2._Myfirst; j != v8; ++j )
      {
        j->frameTimeSwitch = (j->frameTimeSwitch + 1) % 10;
        ++this->cycleIndex;
        Flames::drawBackfireState(this, a2, ea, e->renderContext, j);
        a2 = this->currentDt + j->visTime;
        j->visTime = a2;
      }
    }
  }
}
void Flames::readFlamePresets(Flames *this, const std::wstring *str, FlameInstanceV2 *f)
{
  Flames *v3; // edi
  bool v4; // zf
  int v5; // eax
  char v6; // al
  int v7; // esi
  const std::wstring *v8; // eax
  vec3f *v9; // eax
  __int64 v10; // xmm0_8
  int v11; // eax
  int v12; // eax
  const __m128i *v13; // eax
  std::vector<FlameTexture> *v14; // eax
  std::vector<FlameTexture> *v15; // esi
  FlameTexture *v16; // eax
  int v17; // edi
  FlameTexture *v18; // edx
  int v19; // ecx
  FlameTexture *v20; // eax
  int v21; // ecx
  __m128i v22; // xmm0
  int v23; // ecx
  vec4f v24; // [esp+Ch] [ebp-150h] BYREF
  vec3f v25; // [esp+1Ch] [ebp-140h] BYREF
  __int64 v26; // [esp+28h] [ebp-134h] BYREF
  int v27; // [esp+30h] [ebp-12Ch]
  float v28; // [esp+34h] [ebp-128h]
  float v29; // [esp+38h] [ebp-124h]
  int v30; // [esp+3Ch] [ebp-120h]
  __int128 v31; // [esp+40h] [ebp-11Ch]
  __int128 v32; // [esp+50h] [ebp-10Ch]
  __int128 v33; // [esp+60h] [ebp-FCh]
  __int128 v34; // [esp+70h] [ebp-ECh]
  __int128 v35; // [esp+80h] [ebp-DCh]
  __int64 v36; // [esp+90h] [ebp-CCh]
  std::vector<FlameTexture> *v37; // [esp+98h] [ebp-C4h]
  std::vector<FlameTexture> *v38; // [esp+9Ch] [ebp-C0h]
  std::vector<FlameTexture> *v39; // [esp+A0h] [ebp-BCh]
  int v40; // [esp+A4h] [ebp-B8h]
  std::vector<FlameTexture> *v41; // [esp+A8h] [ebp-B4h]
  Flames *v42; // [esp+ACh] [ebp-B0h]
  int v43; // [esp+B0h] [ebp-ACh]
  int v44; // [esp+B4h] [ebp-A8h]
  int v45; // [esp+B8h] [ebp-A4h]
  char v46; // [esp+BFh] [ebp-9Dh]
  INIReader result; // [esp+C0h] [ebp-9Ch] BYREF
  std::wstring v48; // [esp+104h] [ebp-58h] BYREF
  std::wstring section; // [esp+11Ch] [ebp-40h] BYREF
  std::wstring key; // [esp+134h] [ebp-28h] BYREF
  int v51; // [esp+158h] [ebp-4h]

  v3 = this;
  v42 = this;
  CarAvatar::openINI(this->car, &result, str);
  v51 = 0;
  INIReader::setVerboseMode(&result, 0);
  v39 = &f->FlamesStart;
  std::_Container_base0::_Orphan_all(&f->FlamesStart);
  f->FlamesStart._Mylast = f->FlamesStart._Myfirst;
  v41 = &f->FlamesLoop;
  std::_Container_base0::_Orphan_all(&f->FlamesLoop);
  f->FlamesLoop._Mylast = f->FlamesLoop._Myfirst;
  v38 = &f->FlamesEnd;
  std::_Container_base0::_Orphan_all(&f->FlamesEnd);
  f->FlamesEnd._Mylast = f->FlamesEnd._Myfirst;
  v37 = &f->FlamesFlash;
  std::_Container_base0::_Orphan_all(&f->FlamesFlash);
  v4 = !result.ready;
  f->FlamesFlash._Mylast = f->FlamesFlash._Myfirst;
  if ( !v4 )
  {
    v5 = 0;
    v44 = 0;
    do
    {
      v45 = 0;
      v6 = v5 == 0;
      v46 = v6;
      do
      {
        v7 = 0;
        v43 = 0;
        while ( 1 )
        {
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          LOBYTE(v51) = 1;
          if ( v6 )
          {
            std::wstring::assign(&section, L"PRESET_", 7u);
            if ( v45 )
            {
              if ( v45 == 1 )
              {
                std::wstring::append(&section, L"LOOP_", 5u);
              }
              else if ( v45 == 2 )
              {
                std::wstring::append(&section, L"END_", 4u);
              }
            }
            else
            {
              std::wstring::append(&section, L"START_", 6u);
            }
          }
          else
          {
            std::wstring::assign(&section, L"PRESET_FLASH_", 0xDu);
          }
          v8 = std::to_wstring(&v48, v7);
          LOBYTE(v51) = 2;
          std::wstring::append(&section, v8, 0, 0xFFFFFFFF);
          LOBYTE(v51) = 1;
          if ( v48._Myres >= 8 )
            operator delete(v48._Bx._Ptr);
          if ( !INIReader::hasSection(&result, &section) )
            break;
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          v32 = 0i64;
          v33 = 0i64;
          v34 = 0i64;
          v35 = 0i64;
          std::wstring::assign(&key, L"OFFSET", 6u);
          LOBYTE(v51) = 3;
          v9 = INIReader::getFloat3(&result, &v25, &section, &key);
          LOBYTE(v51) = 1;
          v10 = *(_QWORD *)&v9->x;
          v11 = LODWORD(v9->z);
          v36 = v10;
          v26 = v10;
          v40 = v11;
          v27 = v11;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"SIZE", 4u);
          LOBYTE(v51) = 4;
          v28 = INIReader::getFloat(&result, &section, &key);
          LOBYTE(v51) = 1;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"TRIGGER", 7u);
          LOBYTE(v51) = 5;
          v12 = INIReader::getInt(&result, &section, &key);
          LOBYTE(v51) = 1;
          v29 = (float)v12;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"TYPE", 4u);
          LOBYTE(v51) = 6;
          v30 = INIReader::getInt(&result, &section, &key);
          LOBYTE(v51) = 1;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          v48._Myres = 7;
          v48._Mysize = 0;
          v48._Bx._Buf[0] = 0;
          std::wstring::assign(&v48, L"RGB", 3u);
          LOBYTE(v51) = 7;
          v13 = (const __m128i *)INIReader::getFloat4(&result, &v24, &section, &v48);
          LOBYTE(v51) = 1;
          *(__m128i *)((char *)&key._Bx + 8) = _mm_loadu_si128(v13);
          v31 = *(__int128 *)((char *)&key._Bx + 8);
          if ( v48._Myres >= 8 )
            operator delete(v48._Bx._Ptr);
          if ( !v46 )
          {
            v14 = v37;
            goto LABEL_34;
          }
          switch ( v45 )
          {
            case 0:
              v14 = v39;
              goto LABEL_34;
            case 1:
              v14 = v41;
              goto LABEL_34;
            case 2:
              v14 = v38;
LABEL_34:
              v3->currentFlameVector = v14;
              break;
          }
          v15 = v3->currentFlameVector;
          v16 = v15->_Mylast;
          if ( &v26 >= (__int64 *)v16 || v15->_Myfirst > (FlameTexture *)&v26 )
          {
            if ( v16 == v15->_Myend )
              std::vector<FlameTexture>::_Reserve(v15, 1u);
            v20 = v15->_Mylast;
            if ( v20 )
            {
              v21 = v40;
              *(_QWORD *)&v20->offset.x = v36;
              v20->size = v28;
              v20->triggerTime = v29;
              v22 = _mm_loadu_si128((const __m128i *)&key._Bx._Buf[4]);
              LODWORD(v20->offset.z) = v21;
              v23 = v30;
              v20->color = (vec4f)v22;
              v20->flametype = v23;
              *(_OWORD *)&v20->matrix.M11 = 0i64;
              *(_OWORD *)&v20->matrix.M21 = 0i64;
              *(_OWORD *)&v20->matrix.M31 = 0i64;
              *(_OWORD *)&v20->matrix.M41 = 0i64;
            }
          }
          else
          {
            v17 = ((char *)&v26 - (char *)v15->_Myfirst) / 104;
            if ( v15->_Mylast == v15->_Myend )
              std::vector<FlameTexture>::_Reserve(v15, 1u);
            v18 = v15->_Mylast;
            v19 = (int)&v15->_Myfirst[v17];
            if ( v18 )
            {
              *(_QWORD *)&v18->offset.x = *(_QWORD *)v19;
              v18->offset.z = *(float *)(v19 + 8);
              v18->size = *(float *)(v19 + 12);
              v18->triggerTime = *(float *)(v19 + 16);
              v18->flametype = *(_DWORD *)(v19 + 20);
              v18->color = (vec4f)_mm_loadu_si128((const __m128i *)(v19 + 24));
              *(__m128i *)&v18->matrix.M11 = _mm_loadu_si128((const __m128i *)(v19 + 40));
              *(__m128i *)&v18->matrix.M21 = _mm_loadu_si128((const __m128i *)(v19 + 56));
              *(__m128i *)&v18->matrix.M31 = _mm_loadu_si128((const __m128i *)(v19 + 72));
              *(__m128i *)&v18->matrix.M41 = _mm_loadu_si128((const __m128i *)(v19 + 88));
            }
            v3 = v42;
          }
          ++v15->_Mylast;
          v6 = v46;
          v7 = ++v43;
          if ( section._Myres >= 8 )
          {
            operator delete(section._Bx._Ptr);
            v6 = v46;
          }
        }
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Bx._Buf[0] = 0;
        section._Mysize = 0;
        ++v45;
        v6 = v46;
      }
      while ( v45 < 3 );
      v5 = v44 + 1;
      v44 = v5;
    }
    while ( v5 < 2 );
  }
  v51 = -1;
  INIReader::~INIReader(&result);
}
void Flames::reset(Flames *this)
{
  FlameGroup *v1; // edx
  FlameGroup *i; // eax

  this->car->fuelInExhaust = 0.0;
  v1 = this->flamesV2._Mylast;
  for ( i = this->flamesV2._Myfirst; i != v1; ++i )
  {
    i->visTime = 0.0;
    i->state = eCockpit;
  }
}
void Flames::update(Flames *this, float dt)
{
  float v3; // xmm3_4
  bool v4; // zf
  FlameInstance *v5; // ecx
  FlameInstance *i; // eax
  FlameInstance *v7; // ecx
  FlameInstance *v8; // eax
  float v9; // xmm3_4
  float v10; // xmm0_4
  FlameGroup *v11; // esi
  FlameGroup *v12; // edi
  bool v13; // al
  float v14; // xmm0_4
  float v15; // xmm0_4
  float dta; // [esp+8h] [ebp+4h]

  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    v3 = this->car->sim->replayManager->timeMult * dt;
  else
    v3 = dt;
  v4 = this->version == 1;
  dta = v3;
  this->flamesTime = v3 + this->flamesTime;
  if ( !v4 )
  {
    v11 = this->flamesV2._Myfirst;
    v12 = this->flamesV2._Mylast;
    if ( v11 == v12 )
      return;
    while ( this->observeINI == 0.0 )
    {
      this->currentDt = v3 / this->game->gameTime.deltaT;
      if ( v11->state )
      {
        v13 = CarAvatar::isConnected(this->car);
        this->car->fuelInExhaust = 0.0;
        if ( v13 )
        {
          v14 = v11->fuelDiff;
          if ( v14 > 0.0 )
          {
            v15 = v14 + v11->fuelInExhaust;
            v11->fuelDiff = 0.0;
            v11->fuelInExhaust = v15;
          }
          if ( v11->fuelInExhaust > 0.0 && v11->state != eCar )
            v11->fuelInExhaust = v11->fuelInExhaust - (float)(this->currentDt / this->burnFuelMult);
          if ( v11->fuelInExhaust < 0.0 )
          {
            v3 = dta;
            if ( v11->state != eTrack )
            {
              v11->state = eTrack;
              v11->visTime = 0.0;
              v11->fuelInExhaust = 0.0;
            }
            goto LABEL_36;
          }
        }
        else
        {
          v11->visTime = 0.0;
          v11->state = eCockpit;
        }
        goto LABEL_35;
      }
LABEL_36:
      if ( ++v11 == v12 )
        return;
    }
    if ( FileChangeObserver::hasChanged(&this->observer) )
    {
      INIReader::clearCache();
      Flames::loadFlames(this);
    }
    v11->state = this->edit_state;
    v11->visTime = this->edit_time;
    v11->flashTimes = 0.0;
LABEL_35:
    v3 = dta;
    goto LABEL_36;
  }
  if ( this->observeINI == 0.0 )
  {
    v7 = this->flames._Mylast;
    v8 = this->flames._Myfirst;
    if ( v8 != v7 )
    {
      v9 = v3 * 4.0;
      do
      {
        v10 = v8->visTime - v9;
        if ( v10 <= 1.0 )
        {
          if ( v10 < 0.0 )
            v10 = 0.0;
        }
        else
        {
          v10 = FLOAT_1_0;
        }
        v8->visTime = v10;
        ++v8;
      }
      while ( v8 != v7 );
    }
  }
  else
  {
    if ( FileChangeObserver::hasChanged(&this->observer) )
    {
      INIReader::clearCache();
      Flames::loadFlames(this);
    }
    v5 = this->flames._Mylast;
    for ( i = this->flames._Myfirst; i != v5; ++i )
      i->visTime = 1.0;
  }
}
