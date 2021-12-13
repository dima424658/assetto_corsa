#include "material.h"
void Material::Material(Material *this, const std::wstring *iname, GraphicsManager *graphics)
{
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  this->shader = 0;
  this->wireFrame = 0;
  this->graphics = graphics;
  this->vars._Myfirst = 0;
  this->vars._Mylast = 0;
  this->vars._Myend = 0;
  this->resources._Myfirst = 0;
  this->resources._Mylast = 0;
  this->resources._Myend = 0;
  this->cBuffers._Myfirst = 0;
  this->cBuffers._Mylast = 0;
  this->cBuffers._Myend = 0;
  this->shaderVars._Myfirst = 0;
  this->shaderVars._Mylast = 0;
  this->shaderVars._Myend = 0;
  this->depthMode = eDepthNormal;
  this->blendMode = eOpaque;
  this->cullMode = eCullFront;
  this->doubleFaceShadow = 0;
  if ( this != (Material *)iname )
    std::wstring::assign(&this->name, iname, 0, 0xFFFFFFFF);
  this->shader = 0;
  this->guid = Material::guidCount++;
  this->doubleFace = 0;
  this->depthMode = eDepthNormal;
}
void Material::Material(Material *this, const Material *mat)
{
  GraphicsManager *v3; // ecx
  Shader *v4; // eax
  unsigned int i; // edi
  MaterialVar *v6; // ecx
  MaterialVar *v7; // edx
  __m128i v8; // xmm0
  ShaderVariable *v9; // ecx

  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  this->shader = 0;
  this->wireFrame = 0;
  this->graphics = mat->graphics;
  this->vars._Myfirst = 0;
  this->vars._Mylast = 0;
  this->vars._Myend = 0;
  this->resources._Myfirst = 0;
  this->resources._Mylast = 0;
  this->resources._Myend = 0;
  this->cBuffers._Myfirst = 0;
  this->cBuffers._Mylast = 0;
  this->cBuffers._Myend = 0;
  this->shaderVars._Myfirst = 0;
  this->shaderVars._Mylast = 0;
  this->shaderVars._Myend = 0;
  this->depthMode = eDepthNormal;
  this->blendMode = eOpaque;
  this->cullMode = eCullFront;
  this->doubleFaceShadow = 0;
  if ( this != mat )
    std::wstring::assign(&this->name, &mat->name, 0, 0xFFFFFFFF);
  v3 = this->graphics;
  this->blendMode = mat->blendMode;
  this->shader = 0;
  this->doubleFace = mat->doubleFace;
  v4 = GraphicsManager::getShader(v3, (unsigned int)mat, &mat->shader->name);
  if ( v4 != this->shader )
  {
    this->shader = v4;
    if ( v4 )
    {
      Material::createCBuffers(this);
      Material::initShaderVars(this, 1);
    }
  }
  std::vector<MaterialResource>::operator=(&this->resources, &mat->resources);
  for ( i = 0; i < this->vars._Mylast - this->vars._Myfirst; ++i )
  {
    v6 = mat->vars._Myfirst[i];
    v7 = this->vars._Myfirst[i];
    v7->fValue = v6->fValue;
    v7->fValue4 = (vec4f)_mm_loadu_si128((const __m128i *)&v6->fValue4);
    v7->fValue2.x = v6->fValue2.x;
    v7->fValue2.y = v6->fValue2.y;
    *(_QWORD *)&v7->fValue3.x = *(_QWORD *)&v6->fValue3.x;
    v7->fValue3.z = v6->fValue3.z;
    *(__m128i *)&v7->mValue.M11 = _mm_loadu_si128((const __m128i *)&v6->mValue);
    *(__m128i *)&v7->mValue.M21 = _mm_loadu_si128((const __m128i *)&v6->mValue.M21);
    *(__m128i *)&v7->mValue.M31 = _mm_loadu_si128((const __m128i *)&v6->mValue.M31);
    v8 = _mm_loadu_si128((const __m128i *)&v6->mValue.M41);
    v9 = v7->var;
    *(__m128i *)&v7->mValue.M41 = v8;
    switch ( v9->type )
    {
      case 0:
        ShaderVariable::set(v9, &v7->fValue);
        break;
      case 1:
        ShaderVariable::set(v9, &v7->fValue2.x);
        break;
      case 2:
        ShaderVariable::set(v9, &v7->fValue3.x);
        break;
      case 3:
        ShaderVariable::set(v9, &v7->fValue4.x);
        break;
      case 4:
        ShaderVariable::set(v9, &v7->mValue.M11);
        break;
      default:
        continue;
    }
  }
  this->guid = Material::guidCount++;
  this->depthMode = mat->depthMode;
  this->doubleFaceShadow = mat->doubleFaceShadow;
}
void Material::~Material(Material *this)
{
  CBuffer *v2; // edi
  CBuffer *i; // esi
  ShaderVariable **v4; // esi
  int v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  CBuffer *v8; // edi
  CBuffer *j; // esi
  unsigned int v10; // [esp+18h] [ebp-14h]

  Material::resetVars(this);
  v2 = this->cBuffers._Mylast;
  for ( i = this->cBuffers._Myfirst; i != v2; ++i )
    CBuffer::release(i);
  v4 = this->shaderVars._Myfirst;
  v5 = 0;
  v6 = (unsigned int)((char *)this->shaderVars._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->shaderVars._Mylast )
    v6 = 0;
  v10 = v6;
  if ( v6 )
  {
    v7 = v6;
    do
    {
      if ( *v4 )
      {
        ((void (*)(ShaderVariable *, int))(*v4)->~ShaderVariable)(*v4, 1);
        v7 = v10;
      }
      ++v5;
      ++v4;
    }
    while ( v5 != v7 );
  }
  if ( this->shaderVars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->shaderVars);
    operator delete(this->shaderVars._Myfirst);
    this->shaderVars._Myfirst = 0;
    this->shaderVars._Mylast = 0;
    this->shaderVars._Myend = 0;
  }
  if ( this->cBuffers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cBuffers);
    v8 = this->cBuffers._Mylast;
    for ( j = this->cBuffers._Myfirst; j != v8; ++j )
      CBuffer::release(j);
    operator delete(this->cBuffers._Myfirst);
    this->cBuffers._Myfirst = 0;
    this->cBuffers._Mylast = 0;
    this->cBuffers._Myend = 0;
  }
  if ( this->resources._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->resources);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<MaterialResource>>>(
      this->resources._Myfirst,
      this->resources._Mylast);
    operator delete(this->resources._Myfirst);
    this->resources._Myfirst = 0;
    this->resources._Mylast = 0;
    this->resources._Myend = 0;
  }
  if ( this->vars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->vars);
    operator delete(this->vars._Myfirst);
    this->vars._Myfirst = 0;
    this->vars._Mylast = 0;
    this->vars._Myend = 0;
  }
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
void Material::apply(Material *this, RenderContext *rc)
{
  MaterialResource *v3; // edi
  MaterialResource *i; // esi
  CBuffer *v5; // edi
  CBuffer *j; // esi

  GraphicsManager::setBlendMode(this->graphics, this->blendMode);
  GraphicsManager::setCullMode(this->graphics, this->cullMode);
  if ( rc->meshFilter->passID == Opaque )
    GraphicsManager::setDepthMode(this->graphics, this->depthMode);
  if ( this->doubleFace )
    GraphicsManager::setCullMode(this->graphics, eCullNone);
  v3 = this->resources._Mylast;
  for ( i = this->resources._Myfirst; i != v3; ++i )
    GraphicsManager::setTexture(this->graphics, i->slot, &i->texture);
  GraphicsManager::setShader(this->graphics, this->shader);
  v5 = this->cBuffers._Mylast;
  for ( j = this->cBuffers._Myfirst; j != v5; ++j )
    CBuffer::commit(j);
}
void Material::createCBuffers(Material *this)
{
  CBuffer *v1; // esi
  std::vector<CBuffer> *v2; // ebp
  CBuffer *i; // edi
  CBuffer *v4; // edi
  CBuffer *j; // esi
  int v6; // ebx
  Shader *v7; // eax
  int **v8; // esi
  CBuffer **v9; // eax
  unsigned int v10; // ecx
  int v11; // edi
  unsigned int v13; // [esp+10h] [ebp-4h]

  v1 = this->cBuffers._Myfirst;
  v2 = &this->cBuffers;
  for ( i = this->cBuffers._Mylast; v1 != i; ++v1 )
    CBuffer::release(v1);
  std::_Container_base0::_Orphan_all(v2);
  v4 = v2->_Mylast;
  for ( j = v2->_Myfirst; j != v4; ++j )
    CBuffer::release(j);
  v6 = 0;
  v2->_Mylast = v2->_Myfirst;
  std::vector<CBuffer>::resize(v2, this->shader->cBuffers._Mylast - this->shader->cBuffers._Myfirst);
  v7 = this->shader;
  v8 = (int **)v7->cBuffers._Myfirst;
  v9 = v7->cBuffers._Mylast;
  v10 = (unsigned int)((char *)v9 - (char *)v8 + 3) >> 2;
  if ( v8 > (int **)v9 )
    v10 = 0;
  v13 = v10;
  if ( v10 )
  {
    v11 = 0;
    do
    {
      CBuffer::init(&v2->_Myfirst[v11], (*v8)[1], **v8);
      ++v6;
      ++v8;
      ++v11;
    }
    while ( v6 != v13 );
  }
}
int Material::getResourceIndex(Material *this, const std::wstring *name)
{
  MaterialResource *v2; // esi
  int v3; // ebp
  MaterialResource *v4; // edi
  const std::wstring *v5; // eax

  v2 = this->resources._Myfirst;
  v3 = 0;
  v4 = this->resources._Mylast;
  if ( v2 == v4 )
    return -1;
  while ( 1 )
  {
    v5 = name->_Myres < 8 ? name : name->_Bx._Ptr;
    if ( !std::wstring::compare(&v2->name, 0, v2->name._Mysize, v5->_Bx._Buf, name->_Mysize) )
      break;
    ++v2;
    ++v3;
    if ( v2 == v4 )
      return -1;
  }
  return v3;
}
MaterialVar *Material::getVar(Material *this, const std::wstring *vname)
{
  const std::wstring *v2; // ebx
  Material *v3; // eax
  MaterialVar **v4; // esi
  MaterialVar **v5; // edi
  MaterialVar *v6; // ebp
  const std::wstring *v7; // eax
  MaterialVar *result; // eax

  v2 = vname;
  v3 = this;
  v4 = this->vars._Myfirst;
  v5 = this->vars._Mylast;
  if ( v4 == v5 )
  {
LABEL_8:
    if ( v3->name._Myres >= 8 )
      v3 = (Material *)v3->name._Bx._Ptr;
    if ( vname->_Myres >= 8 )
      v2 = (const std::wstring *)vname->_Bx._Ptr;
    _printf("ERROR: Material::getVar CANT FIND VAR %S for shader %S\n", v2->_Bx._Buf, v3->name._Bx._Buf);
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = *v4;
      v7 = vname->_Myres < 8 ? vname : vname->_Bx._Ptr;
      if ( !std::wstring::compare(&v6->name, 0, v6->name._Mysize, v7->_Bx._Buf, vname->_Mysize) )
        break;
      if ( ++v4 == v5 )
      {
        v3 = this;
        goto LABEL_8;
      }
    }
    result = v6;
  }
  return result;
}
void Material::initShaderVars(Material *this, bool updateOptions)
{
  std::vector<MaterialVar *> *v3; // esi
  std::vector<ICollisionObject *> *v4; // edi
  ShaderVariable **v5; // eax
  int v6; // ebx
  ShaderVariable **v7; // esi
  int v8; // ebp
  unsigned int v9; // ebp
  const std::vector<MaterialResource> *v10; // edx
  MaterialResource *v11; // ebp
  int *v12; // ebx
  int *v13; // ebp
  MaterialVar **v14; // edi
  float **v15; // esi
  int v16; // ebx
  unsigned int v17; // ebp
  float *v18; // edi
  std::vector<MaterialResource> *v19; // ebx
  MaterialResource *v20; // ebp
  MaterialResource *v21; // edi
  unsigned int *v22; // esi
  Shader *v23; // ebx
  ShaderResource **v24; // edi
  ShaderResource **i; // ebx
  ShaderResource *v26; // esi
  MaterialResource *v27; // esi
  std::wstring *v28; // ebp
  const wchar_t *v29; // eax
  CBuffer *v30; // esi
  CBuffer *v31; // eax
  ShaderVariable *v32; // eax
  ICollisionObject **v33; // ecx
  int v34; // esi
  _DWORD *v35; // ecx
  int v36; // eax
  ShaderVariable *v37; // ecx
  float *v38; // edx
  int v39; // eax
  const std::wstring *v40; // eax
  CBuffer *v41; // eax
  Material *v42; // esi
  MaterialVar **v43; // eax
  MaterialVar **v44; // edx
  int v45; // edi
  MaterialVar **v46; // edx
  _DWORD *v47; // eax
  bool v48; // cf
  float *v49; // eax
  unsigned int v50; // edx
  int v51; // eax
  float *v52; // edx
  __m128i v53; // xmm0
  __m128i v54; // xmm0
  CBuffer *v55; // eax
  MaterialResource *v56; // edi
  MaterialResource *v57; // eax
  unsigned int *v58; // esi
  std::wstring v59; // [esp-24h] [ebp-C0h] BYREF
  CBuffer *v60; // [esp-Ch] [ebp-A8h]
  int v61; // [esp-8h] [ebp-A4h]
  float *v62; // [esp-4h] [ebp-A0h]
  ShaderVariable *v63; // [esp+14h] [ebp-88h]
  ShaderVariable *v64; // [esp+18h] [ebp-84h]
  Material *v65; // [esp+1Ch] [ebp-80h]
  float *value; // [esp+20h] [ebp-7Ch]
  float *v67; // [esp+24h] [ebp-78h]
  MaterialVar *mv; // [esp+28h] [ebp-74h] BYREF
  float *v69; // [esp+2Ch] [ebp-70h]
  ShaderVariable *nsv; // [esp+30h] [ebp-6Ch] BYREF
  float *v71; // [esp+34h] [ebp-68h]
  std::vector<MaterialResource> oldres; // [esp+38h] [ebp-64h] BYREF
  std::vector<MaterialVar *> oldvars; // [esp+44h] [ebp-58h] BYREF
  std::vector<ICollisionObject *> *v74; // [esp+50h] [ebp-4Ch]
  MaterialResource mr; // [esp+54h] [ebp-48h] BYREF
  int v76; // [esp+98h] [ebp-4h]

  v65 = this;
  v3 = &this->vars;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&oldvars,
    (const std::vector<TyreThermalPatch *> *)&this->vars);
  v76 = 0;
  std::_Container_base0::_Orphan_all(v3);
  v4 = (std::vector<ICollisionObject *> *)&this->shaderVars;
  v3->_Mylast = v3->_Myfirst;
  v5 = this->shaderVars._Mylast;
  v6 = 0;
  v7 = (ShaderVariable **)v4->_Myfirst;
  v8 = (char *)v5 - (char *)v4->_Myfirst;
  v74 = v4;
  v9 = (unsigned int)(v8 + 3) >> 2;
  if ( v7 > v5 )
    v9 = 0;
  if ( v9 )
  {
    do
    {
      if ( *v7 )
        ((void (*)(ShaderVariable *, int))(*v7)->~ShaderVariable)(*v7, 1);
      ++v6;
      ++v7;
    }
    while ( v6 != v9 );
  }
  std::_Container_base0::_Orphan_all(v4);
  v10 = (const std::vector<MaterialResource> *)v65;
  v4->_Mylast = v4->_Myfirst;
  v11 = v10[2]._Myfirst;
  v12 = (int *)v11->texture.fileName._Myres;
  v13 = (int *)v11->name._Bx._Ptr;
  if ( v12 != v13 )
  {
    while ( 1 )
    {
      v30 = (CBuffer *)v10[5]._Myfirst;
      v64 = (ShaderVariable *)*v12;
      v31 = (CBuffer *)v10[5]._Mylast;
      if ( v30 == v31 )
      {
LABEL_36:
        _printf("ERROR: Material::getBufferFromSlot, Buffer not found! slot:%d\n", v64->buffer->slot);
        v30 = v64->buffer;
      }
      else
      {
        while ( v30->slot != v64->buffer->slot )
        {
          if ( ++v30 == v31 )
            goto LABEL_36;
        }
      }
      v63 = (ShaderVariable *)operator new(44);
      LOBYTE(v76) = 1;
      if ( v63 )
      {
        v62 = (float *)v64->size;
        v61 = v64->offset;
        v60 = v30;
        v59._Myres = 7;
        v59._Mysize = 0;
        v59._Bx._Buf[0] = 0;
        std::wstring::assign(&v59, &v64->name, 0, 0xFFFFFFFF);
        ShaderVariable::ShaderVariable(v63, v59, v60, v61, (int)v62);
      }
      else
      {
        v32 = 0;
      }
      v33 = v4->_Mylast;
      v64 = v32;
      LOBYTE(v76) = 0;
      nsv = v32;
      if ( &nsv >= (ShaderVariable **)v33 || v4->_Myfirst > (ICollisionObject **)&nsv )
      {
        if ( v33 == v4->_Myend )
        {
          std::vector<SVar *>::_Reserve(v4, 1u);
          v32 = v64;
        }
        v35 = v4->_Mylast;
        if ( v35 )
          goto LABEL_49;
      }
      else
      {
        v34 = ((char *)&nsv - (char *)v4->_Myfirst) >> 2;
        if ( v33 == v4->_Myend )
          std::vector<SVar *>::_Reserve(v4, 1u);
        v35 = v4->_Mylast;
        if ( v35 )
        {
          v32 = (ShaderVariable *)v4->_Myfirst[v34];
LABEL_49:
          *v35 = v32;
          goto LABEL_50;
        }
      }
LABEL_50:
      ++v4->_Mylast;
      v36 = operator new(132);
      v37 = (ShaderVariable *)v36;
      v63 = (ShaderVariable *)v36;
      v69 = (float *)v36;
      if ( v36 )
      {
        *(_DWORD *)(v36 + 20) = 7;
        *(_DWORD *)(v36 + 16) = 0;
        *(_WORD *)v36 = 0;
        *(_DWORD *)(v36 + 28) = 0;
        *(_DWORD *)(v36 + 32) = 0;
        *(_DWORD *)(v36 + 36) = 0;
        v38 = (float *)(v36 + 36);
        *(_DWORD *)(v36 + 40) = 0;
        *(_DWORD *)(v36 + 44) = 0;
        *(_DWORD *)(v36 + 48) = 0;
        *(_DWORD *)(v36 + 52) = 0;
        *(_DWORD *)(v36 + 56) = 0;
        *(_DWORD *)(v36 + 60) = 0;
        v71 = (float *)(v36 + 28);
        v39 = (int)v64;
        v37[1].name._Mysize = 0;
        v37[1].name._Myres = 0;
        v37[1].type = eBoolean;
        v37[1].size = 0;
        v37[1].offset = 0;
        v37[1].buffer = 0;
        v37[2].__vftable = 0;
        v37[2].name._Bx._Ptr = 0;
        *(_DWORD *)&v37[2].name._Bx._Alias[4] = 0;
        *(_DWORD *)&v37[2].name._Bx._Alias[8] = 0;
        *(_DWORD *)&v37[2].name._Bx._Alias[12] = 0;
        v37[2].name._Mysize = 0;
        v37[2].name._Myres = 0;
        v37[2].type = eBoolean;
        v37[2].size = 0;
        v37[2].offset = 0;
        v37[2].buffer = (CBuffer *)v39;
        v40 = (const std::wstring *)(v39 + 4);
        LOBYTE(v76) = 3;
        value = (float *)&v37->offset;
        v67 = (float *)&v37[1].name._Mysize;
        if ( v37 != (ShaderVariable *)v40 )
        {
          std::wstring::assign((std::wstring *)v37, v40, 0, 0xFFFFFFFF);
          v37 = v63;
          v38 = value;
        }
        v37->name._Myres = 0;
        value = (float *)&v37->name._Myres;
        v41 = v37[2].buffer;
        switch ( v41[1].slot )
        {
          case 0:
            ShaderVariable::set((ShaderVariable *)v41, value);
            v37 = v63;
            break;
          case 1:
            ShaderVariable::set((ShaderVariable *)v41, v71);
            v37 = v63;
            break;
          case 2:
            ShaderVariable::set((ShaderVariable *)v41, v38);
            v37 = v63;
            break;
          case 3:
            ShaderVariable::set((ShaderVariable *)v41, (float *)&v37[1].name._Bx._Ptr);
            v37 = v63;
            break;
          case 4:
            ShaderVariable::set((ShaderVariable *)v37[2].buffer, v67);
            v37 = v63;
            break;
          default:
            break;
        }
      }
      else
      {
        v37 = 0;
        v63 = 0;
      }
      v42 = v65;
      LOBYTE(v76) = 0;
      mv = (MaterialVar *)v37;
      v43 = v65->vars._Mylast;
      if ( &mv >= v43 || (v44 = v65->vars._Myfirst, v44 > &mv) )
      {
        if ( v43 == v65->vars._Myend )
        {
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v65->vars, 1u);
          v37 = v63;
        }
        v47 = v42->vars._Mylast;
        if ( v47 )
          *v47 = v37;
      }
      else
      {
        v45 = &mv - v44;
        if ( v43 == v65->vars._Myend )
        {
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v65->vars, 1u);
          v37 = v63;
        }
        v46 = v42->vars._Mylast;
        if ( v46 )
          *v46 = v42->vars._Myfirst[v45];
      }
      ++v42->vars._Mylast;
      v15 = (float **)oldvars._Myfirst;
      v14 = oldvars._Mylast;
      if ( oldvars._Myfirst != oldvars._Mylast )
      {
        do
        {
          v48 = v37->name._Mysize < 8;
          v49 = *v15;
          v50 = *(_DWORD *)&v37->name._Bx._Alias[12];
          v67 = *v15;
          if ( !v48 )
            v37 = (ShaderVariable *)v37->__vftable;
          v51 = std::wstring::compare((std::wstring *)v49, 0, *((_DWORD *)v49 + 4), (const wchar_t *)v37, v50);
          v37 = v63;
          if ( !v51 )
          {
            v52 = v67;
            v71 = (float *)&v63->name._Myres;
            v63->name._Myres = (unsigned int)v67[6];
            v53 = _mm_loadu_si128((const __m128i *)v52 + 3);
            v64 = (ShaderVariable *)((char *)v37 + 48);
            v37[1].name._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)v53;
            v67 = (float *)&v37->type;
            v37->type = (eVariableType)v52[7];
            v37->size = (int)v52[8];
            *(_QWORD *)&v37->offset = *(_QWORD *)(v52 + 9);
            value = (float *)&v37->offset;
            v37[1].__vftable = (ShaderVariable_vtbl *)v52[11];
            v54 = _mm_loadu_si128((const __m128i *)v52 + 4);
            v69 = (float *)&v37[1].name._Mysize;
            *(__m128i *)&v37[1].name._Mysize = v54;
            *(__m128i *)&v37[1].offset = _mm_loadu_si128((const __m128i *)v52 + 5);
            *(__m128i *)((char *)&v37[2].name._Bx + 4) = _mm_loadu_si128((const __m128i *)v52 + 6);
            *(__m128i *)&v37[2].name._Myres = _mm_loadu_si128((const __m128i *)v52 + 7);
            v55 = v37[2].buffer;
            switch ( v55[1].slot )
            {
              case 0:
                v62 = v71;
                goto LABEL_80;
              case 1:
                v62 = v67;
                goto LABEL_80;
              case 2:
                v62 = value;
                goto LABEL_80;
              case 3:
                v62 = (float *)v64;
                goto LABEL_80;
              case 4:
                v62 = v69;
LABEL_80:
                ShaderVariable::set((ShaderVariable *)v55, v62);
                v37 = v63;
                break;
              default:
                break;
            }
          }
          ++v15;
        }
        while ( v15 != (float **)v14 );
        v14 = oldvars._Mylast;
        v15 = (float **)oldvars._Myfirst;
      }
      v10 = (const std::vector<MaterialResource> *)v65;
      if ( ++v12 == v13 )
        goto LABEL_9;
      v4 = v74;
    }
  }
  v14 = oldvars._Mylast;
  v15 = (float **)oldvars._Myfirst;
LABEL_9:
  if ( v10[2]._Myfirst[1].texture.fileName._Bx._Alias[12] )
    v10[7]._Myend = (MaterialResource *)2;
  v16 = 0;
  v17 = (unsigned int)((char *)v14 - (char *)v15 + 3) >> 2;
  if ( v15 > (float **)v14 )
    v17 = 0;
  if ( v17 )
  {
    do
    {
      v18 = *v15;
      if ( *v15 )
      {
        if ( *((_DWORD *)v18 + 5) >= 8u )
          operator delete(*(_DWORD *)v18);
        *((_DWORD *)v18 + 5) = 7;
        v18[4] = 0.0;
        v62 = v18;
        *(_WORD *)v18 = 0;
        operator delete(v62);
      }
      ++v16;
      ++v15;
    }
    while ( v16 != v17 );
    v10 = (const std::vector<MaterialResource> *)v65;
  }
  v19 = (std::vector<MaterialResource> *)&v10[4];
  std::vector<MaterialResource>::vector<MaterialResource>(&oldres, v10 + 4);
  LOBYTE(v76) = 4;
  std::_Container_base0::_Orphan_all(v19);
  v20 = v19->_Mylast;
  v21 = v19->_Myfirst;
  if ( v19->_Myfirst != v20 )
  {
    v22 = &v21->name._Myres;
    do
    {
      if ( *v22 >= 8 )
        operator delete(*(v22 - 5));
      *v22 = 7;
      *(v22 - 1) = 0;
      *((_WORD *)v22 - 10) = 0;
      OnSetupAppCreated::~OnSetupAppCreated((Texture *)(v22 - 12));
      ++v21;
      v22 += 14;
    }
    while ( v21 != v20 );
  }
  v19->_Mylast = v19->_Myfirst;
  v23 = v65->shader;
  v24 = v23->resources._Myfirst;
  for ( i = v23->resources._Mylast; v24 != i; ++v24 )
  {
    v26 = *v24;
    mr.texture.kid = 0;
    mr.texture.fileName._Myres = 7;
    mr.texture.fileName._Mysize = 0;
    mr.texture.fileName._Bx._Buf[0] = 0;
    mr.name._Myres = 7;
    mr.name._Mysize = 0;
    mr.name._Bx._Buf[0] = 0;
    LOBYTE(v76) = 6;
    if ( &mr.name != &v26->name )
      std::wstring::assign(&mr.name, &v26->name, 0, 0xFFFFFFFF);
    mr.slot = v26->slot;
    v27 = oldres._Mylast;
    LOBYTE(v76) = 7;
    if ( oldres._Myfirst != oldres._Mylast )
    {
      v28 = &oldres._Myfirst->texture.fileName;
      do
      {
        if ( v28[1]._Myres < 8 )
          v29 = v28[1]._Bx._Buf;
        else
          v29 = v28[1]._Bx._Ptr;
        if ( !std::wstring::compare(&mr.name, 0, mr.name._Mysize, v29, v28[1]._Mysize) || mr.slot == v28[-1]._Mysize )
        {
          mr.texture.kid = (void *)v28[-1]._Myres;
          if ( &mr.texture.fileName != v28 )
            std::wstring::assign(&mr.texture.fileName, v28, 0, 0xFFFFFFFF);
        }
        v28 = (std::wstring *)((char *)v28 + 56);
      }
      while ( &v28[-1]._Mysize != (unsigned int *)v27 );
    }
    std::vector<MaterialResource>::push_back(&v65->resources, &mr);
    LOBYTE(v76) = 4;
    if ( mr.name._Myres >= 8 )
      operator delete(mr.name._Bx._Ptr);
    mr.name._Myres = 7;
    mr.name._Mysize = 0;
    mr.name._Bx._Buf[0] = 0;
    OnSetupAppCreated::~OnSetupAppCreated(&mr.texture);
  }
  LOBYTE(v76) = 0;
  if ( oldres._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&oldres);
    v56 = oldres._Mylast;
    v57 = oldres._Myfirst;
    if ( oldres._Myfirst != oldres._Mylast )
    {
      v58 = &oldres._Myfirst->name._Myres;
      do
      {
        if ( *v58 >= 8 )
          operator delete(*(v58 - 5));
        *v58 = 7;
        *(v58 - 1) = 0;
        *((_WORD *)v58 - 10) = 0;
        OnSetupAppCreated::~OnSetupAppCreated((Texture *)(v58 - 12));
        v58 += 14;
      }
      while ( v58 - 13 != (unsigned int *)v56 );
      v57 = oldres._Myfirst;
    }
    operator delete(v57);
    oldres._Myfirst = 0;
    oldres._Mylast = 0;
    oldres._Myend = 0;
  }
  v76 = -1;
  if ( oldvars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&oldvars);
    operator delete(oldvars._Myfirst);
  }
}
void Material::resetVars(Material *this)
{
  int v1; // ebx
  MaterialVar **v2; // esi
  std::vector<MaterialVar *> *v3; // edi
  unsigned int v4; // ebp
  MaterialVar *v5; // edi
  std::vector<MaterialVar *> *v6; // [esp+10h] [ebp-4h]

  v1 = 0;
  v2 = this->vars._Myfirst;
  v3 = &this->vars;
  v4 = (unsigned int)((char *)this->vars._Mylast - (char *)v2 + 3) >> 2;
  v6 = &this->vars;
  if ( v2 > this->vars._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      v5 = *v2;
      if ( *v2 )
      {
        if ( v5->name._Myres >= 8 )
          operator delete(v5->name._Bx._Ptr);
        v5->name._Myres = 7;
        v5->name._Mysize = 0;
        v5->name._Bx._Buf[0] = 0;
        operator delete(v5);
      }
      ++v1;
      ++v2;
    }
    while ( v1 != v4 );
    v3 = v6;
  }
  std::_Container_base0::_Orphan_all(v3);
  v3->_Mylast = v3->_Myfirst;
}
void __userpurge Material::setShader(Material *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *name)
{
  Shader *v4; // eax

  v4 = GraphicsManager::getShader(this->graphics, a2, name);
  if ( v4 != this->shader )
  {
    this->shader = v4;
    if ( v4 )
    {
      Material::createCBuffers(this);
      Material::initShaderVars(this, 1);
    }
  }
}
void Material::setTexture(Material *this, const std::wstring *rname, const Texture *tex)
{
  const std::wstring *v3; // ebx
  Material *v4; // ebp
  MaterialResource *v5; // esi
  MaterialResource *v6; // edi
  const std::wstring *v7; // eax
  std::wstring *v8; // esi

  v3 = rname;
  v4 = this;
  v5 = this->resources._Myfirst;
  v6 = this->resources._Mylast;
  if ( v5 == v6 )
  {
LABEL_7:
    if ( v4->name._Myres >= 8 )
      v4 = (Material *)v4->name._Bx._Ptr;
    if ( rname->_Myres >= 8 )
      v3 = (const std::wstring *)rname->_Bx._Ptr;
    _printf("ERROR: Material::setTexture CANT FIND Resource %S for shader %S\n", v3->_Bx._Buf, v4->name._Bx._Buf);
  }
  else
  {
    while ( 1 )
    {
      v7 = rname->_Myres < 8 ? rname : rname->_Bx._Ptr;
      if ( !std::wstring::compare(&v5->name, 0, v5->name._Mysize, v7->_Bx._Buf, rname->_Mysize) )
        break;
      if ( ++v5 == v6 )
        goto LABEL_7;
    }
    v5->texture.kid = tex->kid;
    v8 = &v5->texture.fileName;
    if ( v8 != &tex->fileName )
      std::wstring::assign(v8, &tex->fileName, 0, 0xFFFFFFFF);
  }
}
void Material::setVar(Material *this, const std::wstring *name, const vec3f *value)
{
  MaterialVar *v3; // eax

  v3 = Material::getVar(this, name);
  if ( v3 )
  {
    v3->fValue3 = *value;
    MaterialVar::set(v3);
  }
}
void Material::setVar(Material *this, const std::wstring *name, const vec4f *value)
{
  MaterialVar *v3; // eax

  v3 = Material::getVar(this, name);
  if ( v3 )
  {
    v3->fValue4 = (vec4f)_mm_loadu_si128((const __m128i *)value);
    MaterialVar::set(v3);
  }
}
void Material::setVar(Material *this, const std::wstring *name, float value)
{
  MaterialVar *v3; // eax

  v3 = Material::getVar(this, name);
  if ( v3 )
  {
    v3->fValue = value;
    MaterialVar::set(v3);
  }
}
