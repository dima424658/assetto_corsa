#include "skidmarkbuffer.h
void SkidMarkBuffer::SkidMarkBuffer(SkidMarkBuffer *this, GraphicsManager *graphics, unsigned int isize)
{
  std::shared_ptr<Material> *v4; // edi
  std::shared_ptr<Material> *v5; // eax
  volatile signed __int32 *v6; // esi
  Material *v7; // ecx
  const Texture *v8; // eax
  Material *v9; // ecx
  Material *v10; // ecx
  MaterialVar *v11; // eax
  Material *v12; // ecx
  MaterialVar *v13; // eax
  Material *v14; // ecx
  MaterialVar *v15; // eax
  Material *v16; // ecx
  MaterialVar *v17; // eax
  double v18; // st7
  bool v19; // cf
  double v20; // st7
  Material *v21; // esi
  MaterialVar *v22; // eax
  Material *v23; // esi
  MaterialVar *v24; // eax
  Material *v25; // esi
  MaterialVar *v26; // eax
  Material *v27; // esi
  MaterialVar *v28; // eax
  Material *v29; // ecx
  MaterialVar *v30; // eax
  __m128 v31; // xmm0
  float v32; // ecx
  Material *v33; // ecx
  MaterialVar *v34; // eax
  Material *v35; // eax
  std::wstring v36; // [esp-18h] [ebp-F4h] BYREF
  GraphicsManager *v37; // [esp+14h] [ebp-C8h] BYREF
  __int64 v38; // [esp+18h] [ebp-C4h] BYREF
  SkidMarkBuffer *v39; // [esp+20h] [ebp-BCh]
  std::wstring name; // [esp+24h] [ebp-B8h] BYREF
  std::wstring result; // [esp+3Ch] [ebp-A0h] BYREF
  Texture v42; // [esp+54h] [ebp-88h] BYREF
  std::wstring ifilename; // [esp+70h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+88h] [ebp-54h] BYREF
  int v45; // [esp+D8h] [ebp-4h]

  v39 = this;
  v37 = graphics;
  v36._Myres = 7;
  v36._Mysize = 0;
  v36._Bx._Buf[0] = 0;
  std::wstring::assign(&v36, L"SKID_BUFFER", 0xBu);
  Renderable::Renderable(this, v36);
  this->__vftable = (SkidMarkBuffer_vtbl *)&SkidMarkBuffer::`vftable';
  this->textureStep = 0.2;
  this->heightFromGround = 0.02;
  this->cursor = 0;
  this->validVertexCount = 0;
  this->lastV1.x = 0.0;
  this->lastV1.y = 0.0;
  this->lastV1.z = 0.0;
  this->lastV2.x = 0.0;
  this->lastV2.y = 0.0;
  this->lastV2.z = 0.0;
  this->lastNormal.x = 0.0;
  this->lastNormal.y = 0.0;
  this->lastNormal.z = 0.0;
  v36._Myres = isize;
  v45 = 0;
  v38 = 0i64;
  this->lastAlpha = 0.0;
  this->currentTextureV = 0.0;
  DynamicBuffer::DynamicBuffer(&this->dynamicBuffer, v36._Myres);
  this->graphics = graphics;
  v4 = &this->material;
  this->isStarted = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  LOBYTE(v45) = 2;
  v36._Myres = (unsigned int)&v37;
  this->isDirty = 0;
  v36._Mysize = (unsigned int)L"SKID_MARK_MATERIAL";
  *(_DWORD *)&v36._Bx._Alias[12] = &result;
  this->cursor = 0;
  this->currentTextureV = 0.0;
  v5 = std::make_shared<Material,wchar_t const (&)[19],GraphicsManager * &>(
         *(std::shared_ptr<Material> **)&v36._Bx._Alias[12],
         (const wchar_t (*)[16])v36._Mysize,
         (GraphicsManager **)v36._Myres);
  std::shared_ptr<Material>::operator=(&this->material, v5);
  v6 = *(volatile signed __int32 **)&result._Bx._Alias[4];
  if ( *(_DWORD *)&result._Bx._Alias[4] )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&result._Bx._Alias[4] + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v6)(v6);
      if ( !_InterlockedDecrement(v6 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v6 + 4))(v6);
    }
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksSkidMark", 0xAu);
  v7 = v4->_Ptr;
  LOBYTE(v45) = 3;
  Material::setShader(v7, (unsigned int)this, &name);
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"content/texture/skids.dds", 0x19u);
  LOBYTE(v45) = 4;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"txDiffuse", 9u);
  LOBYTE(v45) = 5;
  v8 = ResourceStore::getTexture(v37->resourceStore._Myptr, &v42, &name, 0);
  v9 = v4->_Ptr;
  LOBYTE(v45) = 6;
  Material::setTexture(v9, &result, v8);
  LOBYTE(v45) = 5;
  OnSetupAppCreated::~OnSetupAppCreated(&v42);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  v36._Myres = 10;
  this->textureStep = 0.2;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksSpecular", v36._Myres);
  v10 = v4->_Ptr;
  LOBYTE(v45) = 7;
  v11 = Material::getVar(v10, &name);
  v11->fValue = 1.0;
  MaterialVar::set(v11);
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksSpecularEXP", 0xDu);
  v12 = v4->_Ptr;
  LOBYTE(v45) = 8;
  v13 = Material::getVar(v12, &name);
  v13->fValue = 30.0;
  MaterialVar::set(v13);
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksAmbient", 9u);
  v14 = v4->_Ptr;
  LOBYTE(v45) = 9;
  v15 = Material::getVar(v14, &name);
  v15->fValue = 0.5;
  MaterialVar::set(v15);
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksDiffuse", 9u);
  v16 = v4->_Ptr;
  LOBYTE(v45) = 10;
  v17 = Material::getVar(v16, &name);
  v17->fValue = 1.0;
  MaterialVar::set(v17);
  LOBYTE(v45) = 2;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/skidmarks.ini", 0x18u);
  LOBYTE(v45) = 11;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v45) = 13;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"TEXTURE_STEP", 0xCu);
    LOBYTE(v45) = 14;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"GRAPHICS", 8u);
    LOBYTE(v45) = 15;
    v18 = INIReader::getFloat(&ini, &result, &name);
    v19 = result._Myres < 8;
    this->textureStep = v18;
    if ( !v19 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"HEIGHT_FROM_GROUND", 0x12u);
    LOBYTE(v45) = 16;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"GRAPHICS", 8u);
    LOBYTE(v45) = 17;
    v20 = INIReader::getFloat(&ini, &result, &name);
    v19 = result._Myres < 8;
    this->heightFromGround = v20;
    if ( !v19 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    v42.fileName._Mysize = 7;
    *(_DWORD *)&v42.fileName._Bx._Alias[12] = 0;
    LOWORD(v42.kid) = 0;
    std::wstring::assign((std::wstring *)&v42, L"SPECULAR", 8u);
    LOBYTE(v45) = 18;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"GRAPHICS", 8u);
    LOBYTE(v45) = 19;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"ksSpecular", 0xAu);
    v21 = v4->_Ptr;
    LOBYTE(v45) = 20;
    *(float *)&v37 = INIReader::getFloat(&ini, &name, (const std::wstring *)&v42);
    v22 = Material::getVar(v21, &result);
    v22->fValue = *(float *)&v37;
    MaterialVar::set(v22);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( v42.fileName._Mysize >= 8 )
      operator delete(v42.kid);
    v42.fileName._Mysize = 7;
    *(_DWORD *)&v42.fileName._Bx._Alias[12] = 0;
    LOWORD(v42.kid) = 0;
    std::wstring::assign((std::wstring *)&v42, L"SPECULAR_EXP", 0xCu);
    LOBYTE(v45) = 21;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"GRAPHICS", 8u);
    LOBYTE(v45) = 22;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"ksSpecularEXP", 0xDu);
    v23 = v4->_Ptr;
    LOBYTE(v45) = 23;
    *(float *)&v37 = INIReader::getFloat(&ini, &result, (const std::wstring *)&v42);
    v24 = Material::getVar(v23, &name);
    v24->fValue = *(float *)&v37;
    MaterialVar::set(v24);
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( v42.fileName._Mysize >= 8 )
      operator delete(v42.kid);
    std::wstring::wstring(&result, L"AMBIENT");
    LOBYTE(v45) = 24;
    std::wstring::wstring(&name, L"GRAPHICS");
    LOBYTE(v45) = 25;
    std::wstring::wstring((std::wstring *)&v42, L"ksAmbient");
    v25 = v4->_Ptr;
    LOBYTE(v45) = 26;
    *(float *)&v37 = INIReader::getFloat(&ini, &name, &result);
    v26 = Material::getVar(v25, (const std::wstring *)&v42);
    v26->fValue = *(float *)&v37;
    MaterialVar::set(v26);
    if ( v42.fileName._Mysize >= 8 )
      operator delete(v42.kid);
    v42.fileName._Mysize = 7;
    *(_DWORD *)&v42.fileName._Bx._Alias[12] = 0;
    LOWORD(v42.kid) = 0;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"DIFFUSE");
    LOBYTE(v45) = 27;
    std::wstring::wstring(&name, L"GRAPHICS");
    LOBYTE(v45) = 28;
    std::wstring::wstring((std::wstring *)&v42, L"ksDiffuse");
    v27 = v4->_Ptr;
    LOBYTE(v45) = 29;
    *(float *)&v37 = INIReader::getFloat(&ini, &name, &result);
    v28 = Material::getVar(v27, (const std::wstring *)&v42);
    v28->fValue = *(float *)&v37;
    MaterialVar::set(v28);
    if ( v42.fileName._Mysize >= 8 )
      operator delete(v42.kid);
    v42.fileName._Mysize = 7;
    *(_DWORD *)&v42.fileName._Bx._Alias[12] = 0;
    LOWORD(v42.kid) = 0;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v45) = 13;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  std::wstring::wstring((std::wstring *)&v42, L"ksEmissive");
  v29 = v4->_Ptr;
  LOBYTE(v45) = 30;
  *(_DWORD *)&result._Bx._Alias[8] = 0;
  v30 = Material::getVar(v29, (const std::wstring *)&v42);
  v31 = (__m128)_mm_loadl_epi64((const __m128i *)&v38);
  v32 = *(float *)&result._Bx._Alias[8];
  *(_QWORD *)&v30->fValue3.x = _mm_unpacklo_ps(v31, v31).m128_u64[0];
  v30->fValue3.z = v32;
  MaterialVar::set(v30);
  LOBYTE(v45) = 13;
  if ( v42.fileName._Mysize >= 8 )
    operator delete(v42.kid);
  std::wstring::wstring((std::wstring *)&v42, L"ksAlphaRef");
  v33 = v4->_Ptr;
  LOBYTE(v45) = 31;
  v34 = Material::getVar(v33, (const std::wstring *)&v42);
  v34->fValue = 0.0;
  MaterialVar::set(v34);
  if ( v42.fileName._Mysize >= 8 )
    operator delete(v42.kid);
  v35 = v4->_Ptr;
  LOBYTE(v45) = 2;
  v35->blendMode = eAlphaBlend;
  v4->_Ptr->cullMode = eCullBack;
  this->validVertexCount = 0;
  this->isStarted = 0;
  this->lastAlpha = 0.0;
  *(_WORD *)&this->isTransparent = 256;
  this->castShadows = 0;
  INIReader::~INIReader(&ini);
}
void SkidMarkBuffer::~SkidMarkBuffer(SkidMarkBuffer *this)
{
  std::_Ref_count_base *v2; // esi

  this->__vftable = (SkidMarkBuffer_vtbl *)&SkidMarkBuffer::`vftable';
  v2 = this->material._Rep;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v2->_Weaks) )
        v2->_Delete_this(v2);
    }
  }
  DynamicBuffer::~DynamicBuffer(&this->dynamicBuffer);
  Renderable::~Renderable(this);
}
SkidMarkBuffer *SkidMarkBuffer::`vector deleting destructor'(SkidMarkBuffer *this, unsigned int a2)
{
  SkidMarkBuffer::~SkidMarkBuffer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SkidMarkBuffer::addSegment(SkidMarkBuffer *this, const vec3f *v1, const vec3f *v2, const vec3f *normal, float alpha)
{
  float v7; // xmm0_4
  float v8; // [esp+0h] [ebp-1Ch]
  float v9; // [esp+0h] [ebp-1Ch]
  vec2f texcoord; // [esp+14h] [ebp-8h] BYREF
  float normala; // [esp+28h] [ebp+Ch]

  if ( this->isStarted )
  {
    v7 = this->textureStep;
    normala = this->currentTextureV;
    texcoord.x = normala;
    texcoord.y = 0.0;
    this->currentTextureV = v7 + normala;
    SkidMarkBuffer::addVertex(this, &this->lastV1, &this->lastNormal, &texcoord, this->lastAlpha);
    texcoord.x = normala;
    v8 = this->lastAlpha;
    texcoord.y = 1.0;
    SkidMarkBuffer::addVertex(this, &this->lastV2, &this->lastNormal, &texcoord, v8);
    texcoord.x = this->currentTextureV;
    texcoord.y = 1.0;
    SkidMarkBuffer::addVertex(this, v2, normal, &texcoord, alpha);
    texcoord.x = normala;
    v9 = this->lastAlpha;
    texcoord.y = 0.0;
    SkidMarkBuffer::addVertex(this, &this->lastV1, &this->lastNormal, &texcoord, v9);
    texcoord.x = this->currentTextureV;
    texcoord.y = 1.0;
    SkidMarkBuffer::addVertex(this, v2, normal, &texcoord, alpha);
    texcoord.x = this->currentTextureV;
    texcoord.y = 0.0;
    SkidMarkBuffer::addVertex(this, v1, normal, &texcoord, alpha);
    this->isDirty = 1;
  }
  else
  {
    this->isStarted = 1;
  }
  this->lastV1 = *v1;
  this->lastV2 = *v2;
  *(_QWORD *)&this->lastNormal.x = *(_QWORD *)&normal->x;
  this->lastNormal.z = normal->z;
  this->lastAlpha = alpha;
}
void SkidMarkBuffer::addVertex(SkidMarkBuffer *this, const vec3f *pos, const vec3f *normal, const vec2f *texcoord, float alpha)
{
  unsigned int v5; // eax

  this->dynamicBuffer.vertices[this->cursor].pos = *pos;
  this->dynamicBuffer.vertices[this->cursor].normal = *normal;
  this->dynamicBuffer.vertices[this->cursor].texCoord.x = texcoord->y;
  this->dynamicBuffer.vertices[this->cursor].texCoord.y = texcoord->x;
  this->dynamicBuffer.vertices[this->cursor++].tangent.x = alpha;
  v5 = this->cursor;
  ++this->validVertexCount;
  if ( v5 >= this->dynamicBuffer.size )
    this->cursor = 0;
}
void SkidMarkBuffer::render(SkidMarkBuffer *this, RenderContext *rc)
{
  Camera *v3; // eax
  int *v4; // edx
  unsigned int *v5; // edx
  mat44f id; // [esp+8h] [ebp-40h] BYREF

  v3 = rc->camera;
  if ( !v3 || !v3->isCubeMapCamera )
  {
    if ( this->cursor > 3 && rc->meshFilter->isVisible(rc->meshFilter, this, &this->matrixWS) )
    {
      if ( this->isDirty )
      {
        v4 = (int *)&this->validVertexCount;
        if ( this->dynamicBuffer.size < this->validVertexCount )
          v4 = (int *)&this->dynamicBuffer.size;
        DynamicBuffer::commit(&this->dynamicBuffer, *v4);
        this->isDirty = 0;
      }
      Material::apply(this->material._Ptr, rc);
      mat44f::mat44f(&id);
      mat44f::loadIdentity(&id);
      GraphicsManager::setWorldMatrix(this->graphics, &id);
      GraphicsManager::commitShaderChanges(this->graphics);
      GraphicsManager::setDepthMode(this->graphics, eDepthNoWrite);
      v5 = &this->validVertexCount;
      if ( this->dynamicBuffer.size < this->validVertexCount )
        v5 = &this->dynamicBuffer.size;
      DynamicBuffer::render(&this->dynamicBuffer, 0, *v5);
      GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
    }
    Node::render(this, rc);
  }
}
void SkidMarkBuffer::reset(SkidMarkBuffer *this)
{
  this->cursor = 0;
  this->validVertexCount = 0;
  this->isStarted = 0;
  this->dynamicBuffer.oldNumberOfVerticesToCommit = 0;
}
void SkidMarkBuffer::split(SkidMarkBuffer *this)
{
  this->isStarted = 0;
}
