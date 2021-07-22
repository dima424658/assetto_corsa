#include "staticparticlesystem.h
void StaticParticleSystem::StaticParticleSystem(StaticParticleSystem *this, const std::wstring *a_name, GraphicsManager *graphics, int a_maxParticleCount, const Texture *a_texture)
{
  int v6; // ebx
  int v7; // eax
  StaticParticleVertex *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  KGLVertexBuffer *v13; // eax
  ID3D11Device *v14; // ecx
  void *v15; // eax
  Shader *v16; // eax
  bool v17; // cf
  ShaderVariable *v18; // eax
  ShaderVariable *v19; // eax
  ShaderVariable *v20; // eax
  ShaderVariable *v21; // eax
  ShaderVariable *v22; // eax
  std::wstring name; // [esp+18h] [ebp-28h] BYREF
  int v24; // [esp+3Ch] [ebp-4h]

  Node::Node(this, a_name);
  v24 = 0;
  this->__vftable = (StaticParticleSystem_vtbl *)&StaticParticleSystem::`vftable';
  this->blendMode = eAlphaBlend;
  this->depthMode = eDepthNoWrite;
  this->diffuse.x = 0.2;
  this->diffuse.y = 0.2;
  this->diffuse.z = 0.2;
  this->ambient.x = 0.2;
  this->ambient.y = 0.2;
  this->ambient.z = 0.2;
  this->layer = 0;
  this->particles._Myfirst = 0;
  this->particles._Mylast = 0;
  this->particles._Myend = 0;
  this->graphics = graphics;
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  this->texture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v24) = 2;
  this->isFinalized = 0;
  this->texture.kid = a_texture->kid;
  if ( &this->texture.fileName != &a_texture->fileName )
    std::wstring::assign(&this->texture.fileName, &a_texture->fileName, 0, 0xFFFFFFFF);
  this->maxParticlesCount = a_maxParticleCount;
  StaticParticleSystem::initIndexBuffer((ParticleSystem *)this);
  v6 = 4 * this->maxParticlesCount;
  v7 = operator new[](144 * this->maxParticlesCount);
  v8 = (StaticParticleVertex *)v7;
  if ( v7 )
  {
    v9 = v6 - 1;
    if ( v6 - 1 >= 0 )
    {
      v10 = v7 + 20;
      do
      {
        --v9;
        *(_DWORD *)(v10 - 20) = 0;
        *(_DWORD *)(v10 - 16) = 0;
        v10 += 36;
        *(_DWORD *)(v10 - 48) = 0;
        *(_DWORD *)(v10 - 44) = 0;
        *(_DWORD *)(v10 - 40) = 0;
        *(_DWORD *)(v10 - 36) = 0;
        *(_DWORD *)(v10 - 32) = 0;
        *(_DWORD *)(v10 - 28) = 0;
        *(_DWORD *)(v10 - 24) = 0;
      }
      while ( v9 >= 0 );
    }
  }
  else
  {
    v8 = 0;
  }
  v11 = this->maxParticlesCount;
  this->stagingBuffer = v8;
  v12 = 144 * v11;
  this->bufferSize = 144 * v11;
  v13 = (KGLVertexBuffer *)operator new(8u);
  if ( v13 )
    KGLVertexBuffer::KGLVertexBuffer(v13, (int)this, (int)v8, v14, v12, 0x24u, v8, 1);
  else
    v15 = 0;
  this->buffer = v15;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksParticle", 0xAu);
  LOBYTE(v24) = 3;
  v16 = GraphicsManager::getShader(graphics, v12, &name);
  LOBYTE(v24) = 2;
  v17 = name._Myres < 8;
  this->shParticle = v16;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  this->emissiveBlend = 0.5;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"emissiveBlend", 0xDu);
  LOBYTE(v24) = 4;
  v18 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v24) = 2;
  v17 = name._Myres < 8;
  this->varEmissiveBlend = v18;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"minDistance", 0xBu);
  LOBYTE(v24) = 5;
  v19 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v24) = 2;
  v17 = name._Myres < 8;
  this->varMinDistance = v19;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"shaded", 6u);
  LOBYTE(v24) = 6;
  v20 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v24) = 2;
  v17 = name._Myres < 8;
  this->varShaded = v20;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksDiffuse", 9u);
  LOBYTE(v24) = 7;
  v21 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v24) = 2;
  v17 = name._Myres < 8;
  this->varDiffuse = v21;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksAmbient", 9u);
  LOBYTE(v24) = 8;
  v22 = Shader::getVar(this->shParticle, &name);
  v17 = name._Myres < 8;
  this->varAmbient = v22;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  this->blendMode = eAlphaToCoverage;
}
StaticParticleSystem *StaticParticleSystem::`vector deleting destructor'(StaticParticleSystem *this, unsigned int a2)
{
  StaticParticleSystem::~StaticParticleSystem(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void StaticParticleSystem::~StaticParticleSystem(StaticParticleSystem *this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // edi

  this->__vftable = (StaticParticleSystem_vtbl *)&StaticParticleSystem::`vftable';
  operator delete[](this->stagingBuffer);
  this->particles._Mylast = this->particles._Myfirst;
  v2 = this->buffer;
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v2 + 8))(*v2);
    operator delete(v2);
  }
  v3 = this->ib;
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v3 + 8))(*v3);
    operator delete(v3);
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->texture);
  if ( this->particles._Myfirst )
  {
    operator delete(this->particles._Myfirst);
    this->particles._Myfirst = 0;
    this->particles._Mylast = 0;
    this->particles._Myend = 0;
  }
  Node::~Node(this);
}
void StaticParticleSystem::render(StaticParticleSystem *this, RenderContext *rc)
{
  int v3; // eax
  IMeshRenderFilter *v4; // ecx
  StaticParticleSystem *v5; // edx
  StaticParticle *v6; // edi
  StaticParticle *v7; // esi
  float v8; // xmm0_4
  float v9; // xmm3_4
  __m128 v10; // xmm4
  float v11; // xmm7_4
  float *v12; // ecx
  __m128 v13; // xmm1
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  int v21; // ecx
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  int v25; // ecx
  __m128 v26; // xmm2
  float v27; // xmm0_4
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  int v30; // ecx
  __m128 v31; // xmm2
  ID3D11Resource **v32; // edi
  StaticParticleVertex *v33; // esi
  ID3D11DeviceContext_vtbl *v34; // eax
  int v35; // edi
  char *v36; // ecx
  ShaderVariable *v37; // ecx
  ShaderVariable *v38; // ecx
  ID3D11Resource *v39; // [esp+30h] [ebp-12Ch]
  int v40; // [esp+4Ch] [ebp-110h]
  int v41; // [esp+50h] [ebp-10Ch]
  int v42; // [esp+50h] [ebp-10Ch]
  StaticParticleSystem *v43; // [esp+54h] [ebp-108h] BYREF
  float v44; // [esp+58h] [ebp-104h]
  float v45; // [esp+5Ch] [ebp-100h]
  float v46; // [esp+60h] [ebp-FCh]
  float value; // [esp+64h] [ebp-F8h] BYREF
  void *v48[3]; // [esp+68h] [ebp-F4h] BYREF
  float v49; // [esp+74h] [ebp-E8h] BYREF
  float v50; // [esp+78h] [ebp-E4h]
  float v51; // [esp+7Ch] [ebp-E0h]
  float v52; // [esp+94h] [ebp-C8h]
  float v53; // [esp+98h] [ebp-C4h]
  float v54; // [esp+9Ch] [ebp-C0h]
  float v55; // [esp+A4h] [ebp-B8h]
  float v56; // [esp+A8h] [ebp-B4h]
  float v57; // [esp+ACh] [ebp-B0h]
  float v58; // [esp+C0h] [ebp-9Ch]
  int v59; // [esp+CCh] [ebp-90h]
  int v60; // [esp+D8h] [ebp-84h]
  mat44f matrix; // [esp+DCh] [ebp-80h] BYREF
  mat44f result; // [esp+11Ch] [ebp-40h] BYREF

  v43 = this;
  if ( (dword_1873940 & 1) == 0 )
  {
    perfCounter_50.name = "StaticParticleSystem::traverseForRender";
    dword_1873940 |= 1u;
    perfCounter_50.group = Render;
    perfCounter_50.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"StaticParticleSystem::traverseForRender" | 0xFF000000;
  }
  v3 = this->layer;
  v4 = rc->meshFilter;
  if ( v3 <= v4->maxLayer
    && v4->passID == Opaque
    && this->particles._Myfirst != this->particles._Mylast
    && rc->graphics->currentCubeMap )
  {
    if ( !this->isFinalized )
    {
      StaticParticleSystem::finalize(this);
      this->isFinalized = 1;
    }
    v40 = 0;
    GraphicsManager::getViewMatrix(this->graphics, &result);
    v5 = this;
    v6 = this->particles._Mylast;
    v7 = this->particles._Myfirst;
    if ( v7 != v6 )
    {
      v41 = 0;
      do
      {
        mat44f::createBillboard(&v7->position, (int)&v49, &result);
        LODWORD(v8) = LODWORD(v7->halfSize.y) ^ _xmm;
        LODWORD(v9) = LODWORD(v7->halfSize.x) ^ _xmm;
        v10 = (__m128)LODWORD(v49);
        v5 = v43;
        v11 = v56;
        v12 = (float *)((char *)&v43->stagingBuffer->position.x + v41);
        v45 = v52 * 0.0;
        v46 = v53 * 0.0;
        v13 = (__m128)LODWORD(v50);
        v10.m128_f32[0] = (float)((float)((float)(v49 * v9) + (float)(v8 * 0.0)) + (float)(v52 * 0.0)) + v55;
        v14 = v54 * 0.0;
        v15 = v51;
        v13.m128_f32[0] = (float)((float)((float)(v50 * v9) + v8) + (float)(v53 * 0.0)) + v56;
        v44 = v54 * 0.0;
        v16 = (float)(v51 * v9) + (float)(v8 * 0.0);
        *(_QWORD *)v12 = _mm_unpacklo_ps(v10, v13).m128_u64[0];
        v17 = v16 + v14;
        v18 = v57;
        v58 = v17 + v57;
        v12[2] = v17 + v57;
        v19 = (__m128)LODWORD(v7->halfSize.x);
        v20 = v19;
        v13.m128_f32[0] = COERCE_FLOAT(LODWORD(v7->halfSize.y) ^ _xmm) * 0.0;
        v21 = (int)&v5->stagingBuffer[1] + v41;
        v22 = v19;
        v42 = v41 + 36;
        v20.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] * v49) + v13.m128_f32[0]) + v45) + v55;
        v22.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] * v50) + COERCE_FLOAT(LODWORD(v7->halfSize.y) ^ _xmm))
                                + v46)
                        + v11;
        v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] * v15) + v13.m128_f32[0]) + v44) + v18;
        *(_QWORD *)v21 = _mm_unpacklo_ps(v20, v22).m128_u64[0];
        v60 = v19.m128_i32[0];
        *(_DWORD *)(v21 + 8) = v19.m128_i32[0];
        v23 = (__m128)LODWORD(v7->halfSize.x);
        v24 = v23;
        v25 = (int)&v5->stagingBuffer[1] + v42;
        v42 += 36;
        v13.m128_f32[0] = v7->halfSize.y * 0.0;
        v26 = v23;
        v40 += 4;
        v24.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] * v49) + v13.m128_f32[0]) + v45) + v55;
        v26.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] * v50) + v7->halfSize.y) + v46) + v11;
        v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] * v15) + v13.m128_f32[0]) + v44) + v18;
        *(_QWORD *)v25 = _mm_unpacklo_ps(v24, v26).m128_u64[0];
        v59 = v23.m128_i32[0];
        *(_DWORD *)(v25 + 8) = v23.m128_i32[0];
        v27 = v7->halfSize.y;
        v28 = _mm_xor_ps((__m128)LODWORD(v7->halfSize.x), (__m128)_xmm);
        ++v7;
        v29 = v28;
        v30 = (int)&v5->stagingBuffer[1] + v42;
        v41 = v42 + 72;
        v31 = v28;
        v29.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] * v49) + (float)(v27 * 0.0)) + v45) + v55;
        v31.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] * v50) + v27) + v46) + v11;
        v28.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] * v15) + (float)(v27 * 0.0)) + v44) + v18;
        *(_QWORD *)v30 = _mm_unpacklo_ps(v29, v31).m128_u64[0];
        v48[2] = (void *)v28.m128_i32[0];
        *(_DWORD *)(v30 + 8) = v28.m128_i32[0];
      }
      while ( v7 != v6 );
    }
    v32 = (ID3D11Resource **)v5->buffer;
    v33 = v5->stagingBuffer;
    v34 = immediateContext->__vftable;
    v39 = *v32;
    v44 = *(float *)&immediateContext;
    v34->Map(immediateContext, v39, 0, D3D11_MAP_WRITE_DISCARD, 0, (D3D11_MAPPED_SUBRESOURCE *)v48);
    memcpy(v48[0], v33, 36 * v40);
    (*(void (__stdcall **)(float, ID3D11Resource *, _DWORD))(*(_DWORD *)LODWORD(v44) + 60))(
      COERCE_FLOAT(LODWORD(v44)),
      *v32,
      0);
    v35 = (int)v43;
    ShaderVariable::set(v43->varDiffuse, &v43->diffuse.x);
    ShaderVariable::set(*(ShaderVariable **)(v35 + 316), (float *)(v35 + 216));
    CBuffer::commit(v43->varDiffuse->buffer);
    GraphicsManager::setTexture(*(GraphicsManager **)(v35 + 244), 0, (const Texture *)(v35 + 268));
    GraphicsManager::setBlendMode(*(GraphicsManager **)(v35 + 244), *(BlendMode *)(v35 + 196));
    v36 = (char *)v43->buffer;
    v43 = 0;
    immediateContext->IASetVertexBuffers(
      immediateContext,
      0,
      1u,
      (ID3D11Buffer *const *)v36,
      (const unsigned int *)(v36 + 4),
      (const unsigned int *)&v43);
    immediateContext->IASetIndexBuffer(immediateContext, **(ID3D11Buffer ***)(v35 + 252), DXGI_FORMAT_R16_UINT, 0);
    v37 = *(ShaderVariable **)(v35 + 308);
    value = 1.0;
    ShaderVariable::set(v37, &value);
    v38 = *(ShaderVariable **)(v35 + 304);
    *(_DWORD *)(v35 + 192) = 1069547520;
    ShaderVariable::set(v38, (float *)(v35 + 192));
    ShaderVariable::set(*(ShaderVariable **)(v35 + 300), (float *)(v35 + 188));
    CBuffer::commit(*(CBuffer **)(*(_DWORD *)(v35 + 300) + 40));
    GraphicsManager::setShader(*(GraphicsManager **)(v35 + 244), *(Shader **)(v35 + 296));
    mat44f::mat44f(&matrix);
    mat44f::loadIdentity(&matrix);
    GraphicsManager::setWorldMatrix(*(GraphicsManager **)(v35 + 244), &matrix);
    GraphicsManager::setCullMode(*(GraphicsManager **)(v35 + 244), eCullFront);
    GraphicsManager::commitShaderChanges(*(GraphicsManager **)(v35 + 244));
    GraphicsManager::setDepthMode(*(GraphicsManager **)(v35 + 244), *(DepthMode *)(v35 + 200));
    immediateContext->DrawIndexed(immediateContext, 6 * (v40 / 4), 0, 0);
    MaterialFilter::resetMaterialCache((Turbo *)rc->materialFilter);
  }
}
void StaticParticleSystem::addParticle(StaticParticleSystem *this, const StaticParticle *particle)
{
  if ( (unsigned int)(this->particles._Mylast - this->particles._Myfirst) < this->maxParticlesCount )
    std::vector<StaticParticle>::push_back(&this->particles, particle);
}
void StaticParticleSystem::initIndexBuffer(ParticleSystem *this)
{
  unsigned __int16 *v2; // ebx
  int v3; // esi
  KGLIndexBuffer *v4; // eax
  void *v5; // eax
  std::vector<unsigned short> indices; // [esp+Ch] [ebp-Ch] BYREF

  ParticleSystem::generateIndexBuffer(this, &indices, this->maxParticlesCount);
  v2 = indices._Myfirst;
  v3 = indices._Mylast - indices._Myfirst;
  v4 = (KGLIndexBuffer *)operator new(4u);
  if ( v4 )
    KGLIndexBuffer::KGLIndexBuffer(v4, (ID3D11Device *)(2 * v3), 2 * v3, v2);
  else
    v5 = 0;
  this->ib = v5;
  if ( indices._Myfirst )
    operator delete(indices._Myfirst);
}
void StaticParticleSystem::finalize(StaticParticleSystem *this)
{
  StaticParticle *v2; // ecx
  std::vector<StaticParticle> *v3; // esi
  StaticParticle *v4; // eax
  StaticParticle *v5; // ecx
  StaticParticle *v6; // eax
  int v7; // edi
  StaticParticleVertex *v8; // esi
  float v9; // xmm0_4
  StaticParticleVertex *v10; // esi
  float v11; // xmm0_4
  StaticParticleVertex *v12; // esi
  float v13; // xmm0_4
  StaticParticleVertex *v14; // esi
  float v15; // xmm0_4
  float v16; // [esp+24h] [ebp-8h]

  v2 = this->particles._Mylast;
  v3 = &this->particles;
  if ( this->particles._Myend != v2 )
  {
    v4 = v3->_Myfirst;
    if ( v3->_Myfirst == v2 )
    {
      if ( v4 )
      {
        operator delete(v3->_Myfirst);
        v3->_Myfirst = 0;
        this->particles._Mylast = 0;
        this->particles._Myend = 0;
      }
    }
    else
    {
      std::vector<StaticParticle>::_Reallocate(&this->particles, v2 - v4);
    }
  }
  _printf(
    "FINALIZING STATIC PARTICLE SYSTEM, particles.size()=%d stagingBufferSize=%d\n",
    this->particles._Mylast - this->particles._Myfirst,
    this->maxParticlesCount);
  v5 = this->particles._Mylast;
  v6 = v3->_Myfirst;
  if ( v3->_Myfirst != v5 )
  {
    v7 = 0;
    do
    {
      v7 += 4;
      v8 = this->stagingBuffer;
      v9 = v6->vRange.y;
      *((_DWORD *)&v8[v7 - 3] - 2) = LODWORD(v6->uRange.x);
      *((float *)&v8[v7 - 3] - 1) = v9;
      *(_OWORD *)((char *)&this->stagingBuffer[v7 - 3] - 24) = _xmm;
      v10 = this->stagingBuffer;
      v11 = v6->vRange.y;
      *((_DWORD *)&v10[v7 - 2] - 2) = LODWORD(v6->uRange.y);
      *((float *)&v10[v7 - 2] - 1) = v11;
      *(_OWORD *)((char *)&this->stagingBuffer[v7 - 2] - 24) = _xmm;
      v12 = this->stagingBuffer;
      v13 = v6->vRange.x;
      *((_DWORD *)&v12[v7 - 1] - 2) = LODWORD(v6->uRange.y);
      *((float *)&v12[v7 - 1] - 1) = v13;
      *(_OWORD *)((char *)&this->stagingBuffer[v7 - 1] - 24) = _xmm;
      v14 = this->stagingBuffer;
      v16 = v6->uRange.x;
      v15 = v6->vRange.x;
      ++v6;
      v14[v7 - 1].texCoord.x = v16;
      v14[v7 - 1].texCoord.y = v15;
      this->stagingBuffer[v7 - 1].color = (vec4f)_xmm;
    }
    while ( v6 != v5 );
  }
}
