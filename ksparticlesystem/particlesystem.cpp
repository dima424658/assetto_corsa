#include "particlesystem.h"
std::vector<unsigned short> *ParticleSystem::generateIndexBuffer(ParticleSystem *this, std::vector<unsigned short> *result, int pcount)
{
  int v3; // eax
  int v4; // ebp
  unsigned __int16 *v5; // eax
  int v6; // edi
  unsigned __int16 *v7; // ecx
  unsigned __int16 *v8; // eax
  unsigned __int16 *v9; // ecx
  int v10; // edi
  unsigned __int16 *v11; // ecx
  unsigned __int16 *v12; // eax
  unsigned __int16 v13; // bx
  unsigned __int16 *v14; // ecx
  int v15; // edi
  unsigned __int16 *v16; // ecx
  unsigned __int16 *v17; // eax
  unsigned __int16 *v18; // ecx
  int v19; // edi
  unsigned __int16 *v20; // ecx
  unsigned __int16 *v21; // eax
  unsigned __int16 *v22; // ecx
  int v23; // edi
  unsigned __int16 *v24; // ecx
  unsigned __int16 *v25; // eax
  unsigned __int16 *v26; // ecx
  int v27; // edi
  unsigned __int16 *v28; // ecx
  unsigned __int16 *v29; // eax
  int v30; // eax
  bool v31; // zf
  int v33; // [esp+14h] [ebp-2Ch] BYREF
  int v34; // [esp+18h] [ebp-28h] BYREF
  int v35; // [esp+1Ch] [ebp-24h] BYREF
  int v36; // [esp+20h] [ebp-20h] BYREF
  int v37; // [esp+24h] [ebp-1Ch] BYREF
  int v38; // [esp+28h] [ebp-18h] BYREF
  int v39; // [esp+2Ch] [ebp-14h]
  int v40; // [esp+30h] [ebp-10h]
  int v41; // [esp+3Ch] [ebp-4h]

  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v41 = 0;
  v40 = 1;
  if ( pcount > 0 )
  {
    LOWORD(v3) = 0;
    v39 = 0;
    do
    {
      v4 = (unsigned __int16)v3;
      v33 = (unsigned __int16)v3;
      v5 = result->_Mylast;
      if ( &v33 >= (int *)v5 || result->_Myfirst > (unsigned __int16 *)&v33 )
      {
        if ( v5 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v8 = result->_Mylast;
        if ( v8 )
          *v8 = v4;
      }
      else
      {
        v6 = ((char *)&v33 - (char *)result->_Myfirst) >> 1;
        if ( v5 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v7 = result->_Mylast;
        if ( v7 )
          *v7 = result->_Myfirst[v6];
      }
      v9 = ++result->_Mylast;
      v34 = (unsigned __int16)(v4 + 1);
      if ( &v34 >= (int *)v9 || result->_Myfirst > (unsigned __int16 *)&v34 )
      {
        if ( v9 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v12 = result->_Mylast;
        if ( v12 )
          *v12 = v4 + 1;
      }
      else
      {
        v10 = ((char *)&v34 - (char *)result->_Myfirst) >> 1;
        if ( v9 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v11 = result->_Mylast;
        if ( v11 )
          *v11 = result->_Myfirst[v10];
      }
      ++result->_Mylast;
      v13 = v4 + 2;
      v14 = result->_Mylast;
      v35 = (unsigned __int16)(v4 + 2);
      if ( &v35 >= (int *)v14 || result->_Myfirst > (unsigned __int16 *)&v35 )
      {
        if ( v14 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v17 = result->_Mylast;
        if ( v17 )
          *v17 = v13;
      }
      else
      {
        v15 = ((char *)&v35 - (char *)result->_Myfirst) >> 1;
        if ( v14 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v16 = result->_Mylast;
        if ( v16 )
          *v16 = result->_Myfirst[v15];
      }
      v18 = ++result->_Mylast;
      v36 = v4;
      if ( &v36 >= (int *)v18 || result->_Myfirst > (unsigned __int16 *)&v36 )
      {
        if ( v18 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v21 = result->_Mylast;
        if ( v21 )
          *v21 = v4;
      }
      else
      {
        v19 = ((char *)&v36 - (char *)result->_Myfirst) >> 1;
        if ( v18 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v20 = result->_Mylast;
        if ( v20 )
          *v20 = result->_Myfirst[v19];
      }
      v22 = ++result->_Mylast;
      v37 = v13;
      if ( &v37 >= (int *)v22 || result->_Myfirst > (unsigned __int16 *)&v37 )
      {
        if ( v22 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v25 = result->_Mylast;
        if ( v25 )
          *v25 = v13;
      }
      else
      {
        v23 = ((char *)&v37 - (char *)result->_Myfirst) >> 1;
        if ( v22 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v24 = result->_Mylast;
        if ( v24 )
          *v24 = result->_Myfirst[v23];
      }
      v26 = ++result->_Mylast;
      v38 = (unsigned __int16)(v4 + 3);
      if ( &v38 >= (int *)v26 || result->_Myfirst > (unsigned __int16 *)&v38 )
      {
        if ( v26 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v29 = result->_Mylast;
        if ( v29 )
          *v29 = v4 + 3;
      }
      else
      {
        v27 = ((char *)&v38 - (char *)result->_Myfirst) >> 1;
        if ( v26 == result->_Myend )
          std::vector<unsigned short>::_Reserve(result, 1u);
        v28 = result->_Mylast;
        if ( v28 )
          *v28 = result->_Myfirst[v27];
      }
      v30 = v39;
      ++result->_Mylast;
      v3 = v30 + 4;
      v31 = pcount-- == 1;
      v39 = v3;
    }
    while ( !v31 );
  }
  return result;
}
void ParticleSystem::ParticleSystem(ParticleSystem *this, const std::wstring *a_name, GraphicsManager *graphics, int a_maxParticleCount, const Texture *a_texture)
{
  int v6; // ebx
  int v7; // eax
  ParticleVertex *v8; // esi
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
  ShaderVariable *v21; // ecx
  ShaderVariable *v22; // ecx
  ShaderVariable *v23; // eax
  ShaderVariable *v24; // eax
  int v25; // esi
  int v26; // edx
  int shadedVal[2]; // [esp+14h] [ebp-30h] BYREF
  std::wstring name; // [esp+1Ch] [ebp-28h] BYREF
  int v29; // [esp+40h] [ebp-4h]

  shadedVal[1] = (int)this;
  Node::Node(this, a_name);
  v29 = 0;
  this->__vftable = (ParticleSystem_vtbl *)&ParticleSystem::`vftable';
  this->blendMode = eAlphaBlend;
  this->depthMode = eDepthNoWrite;
  this->diffuse.x = 0.2;
  this->diffuse.y = 0.2;
  this->diffuse.z = 0.2;
  this->ambient.x = 0.2;
  this->ambient.y = 0.2;
  this->ambient.z = 0.2;
  this->maxTimeAlive = 10.0;
  this->particles._Myfirst = 0;
  this->particles._Mylast = 0;
  this->particles._Myend = 0;
  this->graphics = graphics;
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  this->texture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v29) = 2;
  this->texture.kid = a_texture->kid;
  if ( &this->texture.fileName != &a_texture->fileName )
    std::wstring::assign(&this->texture.fileName, &a_texture->fileName, 0, 0xFFFFFFFF);
  this->maxParticlesCount = a_maxParticleCount;
  StaticParticleSystem::initIndexBuffer(this);
  v6 = 4 * this->maxParticlesCount;
  v7 = operator new[](144 * this->maxParticlesCount);
  v8 = (ParticleVertex *)v7;
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
  LOBYTE(v29) = 3;
  v16 = GraphicsManager::getShader(graphics, v12, &name);
  LOBYTE(v29) = 2;
  v17 = name._Myres < 8;
  this->shParticle = v16;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  this->emissiveBlend = 0.5;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"emissiveBlend", 0xDu);
  LOBYTE(v29) = 4;
  v18 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v29) = 2;
  v17 = name._Myres < 8;
  this->varEmissiveBlend = v18;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"minDistance", 0xBu);
  LOBYTE(v29) = 5;
  v19 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v29) = 2;
  v17 = name._Myres < 8;
  this->varMinDistance = v19;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"shaded", 6u);
  LOBYTE(v29) = 6;
  v20 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v29) = 2;
  v17 = name._Myres < 8;
  this->varShaded = v20;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  v21 = this->varShaded;
  shadedVal[0] = 0;
  ShaderVariable::set(v21, (float *)shadedVal);
  v22 = this->varMinDistance;
  this->minDistance = 1.5;
  ShaderVariable::set(v22, &this->minDistance);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksDiffuse", 9u);
  LOBYTE(v29) = 7;
  v23 = Shader::getVar(this->shParticle, &name);
  LOBYTE(v29) = 2;
  v17 = name._Myres < 8;
  this->varDiffuse = v23;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksAmbient", 9u);
  LOBYTE(v29) = 8;
  v24 = Shader::getVar(this->shParticle, &name);
  v17 = name._Myres < 8;
  this->varAmbient = v24;
  if ( !v17 )
    operator delete(name._Bx._Ptr);
  v25 = 0;
  if ( this->maxParticlesCount > 0 )
  {
    v26 = 0;
    do
    {
      v26 += 4;
      ++v25;
      *((_DWORD *)&this->stagingBuffer[v26 - 3] - 2) = 0;
      *((_DWORD *)&this->stagingBuffer[v26 - 3] - 1) = 1065353216;
      *((_DWORD *)&this->stagingBuffer[v26 - 2] - 2) = 1065353216;
      *((_DWORD *)&this->stagingBuffer[v26 - 2] - 1) = 1065353216;
      *((_DWORD *)&this->stagingBuffer[v26 - 1] - 2) = 1065353216;
      *((_DWORD *)&this->stagingBuffer[v26 - 1] - 1) = 0;
      this->stagingBuffer[v26 - 1].texCoord.x = 0.0;
      this->stagingBuffer[v26 - 1].texCoord.y = 0.0;
    }
    while ( v25 < this->maxParticlesCount );
  }
}
ParticleSystem *ParticleSystem::`vector deleting destructor'(ParticleSystem *this, unsigned int a2)
{
  ParticleSystem::~ParticleSystem(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ParticleSystem::~ParticleSystem(ParticleSystem *this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // edi

  this->__vftable = (ParticleSystem_vtbl *)&ParticleSystem::`vftable';
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
void ParticleSystem::step(ParticleSystem *this, float dt)
{
  Particle *v3; // esi
  Particle *i; // eax
  Particle *v5; // ecx
  Particle *v6; // eax
  float *v7; // esi
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // [esp+Ch] [ebp-4h]

  v3 = this->particles._Myfirst;
  for ( i = this->particles._Mylast; v3 != i; ++v3 )
  {
    if ( v3->opacity <= 0.0 || v3->timeAlive > this->maxTimeAlive )
    {
      std::_Move<Particle *,Particle *>(v3 + 1, this->particles._Mylast, v3);
      i = --this->particles._Mylast;
      if ( v3 == i )
        break;
    }
  }
  v5 = this->particles._Mylast;
  v6 = this->particles._Myfirst;
  if ( v6 != v5 )
  {
    v7 = &v6->velocity.z;
    do
    {
      v8 = v7[8];
      v7[10] = v7[10] + dt;
      v9 = *v7;
      LODWORD(v10) = COERCE_UNSIGNED_INT(v7[9] * dt) ^ _xmm;
      v11 = *(v7 - 1) * v10;
      *(v7 - 2) = (float)(*(v7 - 2) * v10) + *(v7 - 2);
      v12 = (float)(v9 * v10) + *v7;
      v13 = *(v7 - 1) + (float)(v11 + COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * dt) ^ _xmm));
      *v7 = v12;
      *(v7 - 1) = v13;
      v6->position.x = (float)(dt * *(v7 - 2)) + v6->position.x;
      ++v6;
      *(v7 - 4) = *(v7 - 4) + (float)(v13 * dt);
      *(v7 - 3) = *(v7 - 3) + (float)(v12 * dt);
      v14 = v7[2] + (float)(v7[4] * dt);
      v7[1] = v7[1] + (float)(v7[3] * dt);
      v16 = v14;
      v15 = v7[12];
      v7[2] = v16;
      v7[11] = (float)(v15 * dt) + v7[11];
      v7 += 18;
    }
    while ( v6 != v5 );
  }
}
void ParticleSystem::render(ParticleSystem *this, RenderContext *rc)
{
  ParticleSystem *v3; // edx
  unsigned int v4; // eax
  Particle *v5; // edi
  Particle *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  float *v12; // ecx
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  __m128i v16; // xmm5
  float v17; // xmm1_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  float *v23; // ecx
  float v24; // xmm1_4
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  int v27; // ecx
  __m128 v28; // xmm2
  float v29; // eax
  float v30; // xmm1_4
  int v31; // ecx
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  int v34; // ecx
  int v35; // ecx
  ID3D11Resource **v36; // edi
  ParticleVertex *v37; // esi
  int v38; // edi
  char *v39; // ecx
  ShaderVariable *v40; // ecx
  int v41; // [esp+38h] [ebp-12Ch]
  int v42; // [esp+38h] [ebp-12Ch]
  int v43; // [esp+3Ch] [ebp-128h]
  float v44; // [esp+40h] [ebp-124h]
  ID3D11DeviceContext *v45; // [esp+40h] [ebp-124h]
  ParticleSystem *v46; // [esp+44h] [ebp-120h] BYREF
  float v47; // [esp+48h] [ebp-11Ch]
  int v48; // [esp+4Ch] [ebp-118h]
  float v49; // [esp+50h] [ebp-114h]
  float v50; // [esp+54h] [ebp-110h] BYREF
  float v51; // [esp+58h] [ebp-10Ch]
  float v52; // [esp+5Ch] [ebp-108h]
  float v53; // [esp+64h] [ebp-100h]
  float v54; // [esp+68h] [ebp-FCh]
  float v55; // [esp+6Ch] [ebp-F8h]
  float v56; // [esp+74h] [ebp-F0h]
  float v57; // [esp+78h] [ebp-ECh]
  float v58; // [esp+7Ch] [ebp-E8h]
  float v59; // [esp+84h] [ebp-E0h]
  float v60; // [esp+88h] [ebp-DCh]
  float v61; // [esp+8Ch] [ebp-D8h]
  float value; // [esp+94h] [ebp-D0h] BYREF
  void *v63[3]; // [esp+98h] [ebp-CCh] BYREF
  __m128i v64; // [esp+A4h] [ebp-C0h] BYREF
  float v65; // [esp+C8h] [ebp-9Ch]
  float v66; // [esp+D4h] [ebp-90h]
  float v67; // [esp+E0h] [ebp-84h]
  mat44f matrix; // [esp+E4h] [ebp-80h] BYREF
  mat44f result; // [esp+124h] [ebp-40h] BYREF

  v46 = this;
  if ( (dword_1873950 & 1) == 0 )
  {
    perfCounter_51.name = "ParticleSystem::traverseForRender";
    dword_1873950 |= 1u;
    perfCounter_51.group = Render;
    perfCounter_51.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"ParticleSystem::traverseForRender" | 0xFF000000;
  }
  if ( rc->meshFilter->passID == Transparent && this->particles._Myfirst != this->particles._Mylast )
  {
    v43 = 0;
    GraphicsManager::getViewMatrix(this->graphics, &result);
    v3 = this;
    v4 = 0;
    v48 = 0;
    v5 = this->particles._Mylast;
    v6 = v3->particles._Myfirst;
    if ( v6 != v5 )
    {
      v41 = 0;
      do
      {
        if ( v4 >= v3->maxParticlesCount || (v7 = v6->opacity, v7 <= 0.0) )
        {
          v35 = v43;
        }
        else
        {
          v64.m128i_i64[0] = *(_QWORD *)&v6->color.x;
          v64.m128i_i32[2] = LODWORD(v6->color.z);
          *(float *)&v64.m128i_i32[3] = v7;
          mat44f::createBillboard(&v6->position, (int)&v50, &result);
          LODWORD(v8) = LODWORD(v6->halfSize.x) ^ _xmm;
          LODWORD(v9) = LODWORD(v6->halfSize.y) ^ _xmm;
          v10 = (__m128)LODWORD(v53);
          v11 = (__m128)LODWORD(v54);
          v3 = v46;
          v12 = (float *)((char *)&v46->stagingBuffer->position.x + v41);
          v49 = v56 * 0.0;
          v13 = v58 * 0.0;
          v14 = v52;
          v10.m128_f32[0] = (float)((float)((float)(v53 * v9) + (float)(v50 * v8)) + (float)(v56 * 0.0)) + v59;
          v47 = v57 * 0.0;
          v11.m128_f32[0] = (float)((float)((float)(v54 * v9) + (float)(v51 * v8)) + (float)(v57 * 0.0)) + v60;
          v44 = v58 * 0.0;
          v15 = (float)(v55 * v9) + (float)(v52 * v8);
          *(_QWORD *)v12 = _mm_unpacklo_ps(v10, v11).m128_u64[0];
          v16 = _mm_load_si128(&v64);
          v17 = v15 + v13;
          v18 = v61;
          v65 = v17 + v61;
          v12[2] = v17 + v61;
          *(__m128i *)((char *)&v3->stagingBuffer->color + v41) = v16;
          v19 = v6->halfSize.x;
          v20 = _mm_xor_ps((__m128)LODWORD(v6->halfSize.y), (__m128)_xmm);
          v21 = v20;
          v42 = v41 + 36;
          v22 = v20;
          v21.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] * v53) + (float)(v19 * v50)) + v49) + v59;
          v23 = (float *)((char *)&v3->stagingBuffer->position.x + v42);
          v22.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] * v54) + (float)(v19 * v51)) + v47) + v60;
          v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v55) + (float)(v19 * v14)) + v44;
          *(_QWORD *)v23 = _mm_unpacklo_ps(v21, v22).m128_u64[0];
          v67 = v20.m128_f32[0] + v18;
          v23[2] = v20.m128_f32[0] + v18;
          *(__m128i *)((char *)&v3->stagingBuffer->color + v42) = v16;
          v24 = v6->halfSize.x;
          v25 = (__m128)LODWORD(v6->halfSize.y);
          v26 = v25;
          v27 = (int)&v3->stagingBuffer[1] + v42;
          v28 = v25;
          v26.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] * v53) + (float)(v24 * v50)) + v49) + v59;
          v28.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] * v54) + (float)(v24 * v51)) + v47) + v60;
          v66 = (float)((float)((float)(v25.m128_f32[0] * v55) + (float)(v24 * v14)) + v44) + v18;
          v29 = v66;
          *(_QWORD *)v27 = _mm_unpacklo_ps(v26, v28).m128_u64[0];
          *(float *)(v27 + 8) = v29;
          *(__m128i *)((char *)&v3->stagingBuffer[1].color + v42) = v16;
          LODWORD(v30) = LODWORD(v6->halfSize.x) ^ _xmm;
          v31 = (int)&v3->stagingBuffer[2] + v42;
          v32 = (__m128)LODWORD(v6->halfSize.y);
          v33 = v32;
          v32.m128_f32[0] = (float)((float)((float)(v32.m128_f32[0] * v53) + (float)(v30 * v50)) + v49) + v59;
          v25.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] * v55) + (float)(v30 * v14)) + v44) + v18;
          v33.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] * v54) + (float)(v30 * v51)) + v47) + v60;
          v63[2] = (void *)v25.m128_i32[0];
          *(_QWORD *)v31 = _mm_unpacklo_ps(v32, v33).m128_u64[0];
          *(_DWORD *)(v31 + 8) = v25.m128_i32[0];
          v34 = v42 + 72;
          v41 = v42 + 108;
          *(__m128i *)((char *)&v3->stagingBuffer->color + v34) = v16;
          v35 = v43 + 4;
          v4 = v48 + 1;
          v43 += 4;
          ++v48;
        }
        ++v6;
      }
      while ( v6 != v5 );
      if ( v35 )
      {
        v36 = (ID3D11Resource **)v3->buffer;
        v37 = v3->stagingBuffer;
        v45 = immediateContext;
        immediateContext->Map(immediateContext, *v36, 0, D3D11_MAP_WRITE_DISCARD, 0, (D3D11_MAPPED_SUBRESOURCE *)v63);
        memcpy(v63[0], v37, 36 * v43);
        v45->Unmap(v45, *v36, 0);
        v38 = (int)v46;
        GraphicsManager::setTexture(v46->graphics, 0, &v46->texture);
        GraphicsManager::setBlendMode(*(GraphicsManager **)(v38 + 244), *(BlendMode *)(v38 + 196));
        v39 = (char *)v46->buffer;
        v46 = 0;
        immediateContext->IASetVertexBuffers(
          immediateContext,
          0,
          1u,
          (ID3D11Buffer *const *)v39,
          (const unsigned int *)(v39 + 4),
          (const unsigned int *)&v46);
        immediateContext->IASetIndexBuffer(immediateContext, **(ID3D11Buffer ***)(v38 + 252), DXGI_FORMAT_R16_UINT, 0);
        ShaderVariable::set(*(ShaderVariable **)(v38 + 300), (float *)(v38 + 188));
        CBuffer::commit(*(CBuffer **)(*(_DWORD *)(v38 + 300) + 40));
        v40 = *(ShaderVariable **)(v38 + 308);
        value = 0.0;
        ShaderVariable::set(v40, &value);
        CBuffer::commit(*(CBuffer **)(*(_DWORD *)(v38 + 308) + 40));
        GraphicsManager::setShader(*(GraphicsManager **)(v38 + 244), *(Shader **)(v38 + 296));
        mat44f::mat44f(&matrix);
        mat44f::loadIdentity(&matrix);
        GraphicsManager::setWorldMatrix(*(GraphicsManager **)(v38 + 244), &matrix);
        GraphicsManager::setCullMode(*(GraphicsManager **)(v38 + 244), eCullFront);
        GraphicsManager::commitShaderChanges(*(GraphicsManager **)(v38 + 244));
        GraphicsManager::setDepthMode(*(GraphicsManager **)(v38 + 244), *(DepthMode *)(v38 + 200));
        immediateContext->DrawIndexed(immediateContext, 6 * v48, 0, 0);
        MaterialFilter::resetMaterialCache((Turbo *)rc->materialFilter);
      }
    }
  }
}
void ParticleSystem::clearParticles(ParticleSystem *this)
{
  this->particles._Mylast = this->particles._Myfirst;
}
void ParticleSystem::disable(ParticleSystem *this)
{
  this->particles._Mylast = this->particles._Myfirst;
  this->isActive = 0;
}
