#include "shader.h
void Shader::Shader(Shader *this, GraphicsManager *graphics, const std::wstring *ifilename)
{
  std::wstring *v4; // edi
  void *v5; // eax
  int v6; // eax
  void *v7; // [esp-14h] [ebp-30h]

  this->__vftable = (Shader_vtbl *)&Shader::`vftable';
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  this->vars._Myfirst = 0;
  this->vars._Mylast = 0;
  this->vars._Myend = 0;
  this->resources._Myfirst = 0;
  this->resources._Mylast = 0;
  this->resources._Myend = 0;
  this->cBuffers._Myfirst = 0;
  this->cBuffers._Mylast = 0;
  this->cBuffers._Myend = 0;
  this->options._Myfirst = 0;
  this->options._Mylast = 0;
  this->options._Myend = 0;
  this->isAlphaTested = 0;
  v4 = &this->filename;
  this->graphics = graphics;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  std::wstring::assign(&this->filename, ifilename, 0, 0xFFFFFFFF);
  if ( v4->_Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  v5 = (void *)kglCreateShader(v4->_Bx._Buf);
  this->kid = v5;
  this->useNullPS = 0;
  v6 = kglShaderGetParam(v5, 0);
  v7 = this->kid;
  this->isAlphaTested = v6 != 0;
  this->ilType = kglShaderGetParam(v7, 1u);
  Shader::initShaderBinary(this);
}
void Shader::~Shader(Shader *this)
{
  ShaderVariable **v2; // esi
  int v3; // edi
  unsigned int v4; // ebx
  ShaderResource **v5; // esi
  int v6; // edi
  unsigned int v7; // ebx
  CBuffer **v8; // esi
  int v9; // ebx
  unsigned int v10; // ecx
  CBuffer *v11; // edi
  std::wstring *v12; // ebx
  std::wstring *i; // esi
  unsigned int v14; // [esp+14h] [ebp-14h]

  this->__vftable = (Shader_vtbl *)&Shader::`vftable';
  v2 = this->vars._Myfirst;
  v3 = 0;
  v4 = (unsigned int)((char *)this->vars._Mylast - (char *)v2 + 3) >> 2;
  if ( v2 > this->vars._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      if ( *v2 )
        ((void (*)(ShaderVariable *, int))(*v2)->~ShaderVariable)(*v2, 1);
      ++v3;
      ++v2;
    }
    while ( v3 != v4 );
  }
  v5 = this->resources._Myfirst;
  v6 = 0;
  v7 = (unsigned int)((char *)this->resources._Mylast - (char *)v5 + 3) >> 2;
  if ( v5 > this->resources._Mylast )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      if ( *v5 )
        ((void (*)(ShaderResource *, int))(*v5)->~ShaderResource)(*v5, 1);
      ++v6;
      ++v5;
    }
    while ( v6 != v7 );
  }
  v8 = this->cBuffers._Myfirst;
  v9 = 0;
  v10 = (unsigned int)((char *)this->cBuffers._Mylast - (char *)v8 + 3) >> 2;
  if ( v8 > this->cBuffers._Mylast )
    v10 = 0;
  v14 = v10;
  if ( v10 )
  {
    do
    {
      v11 = *v8;
      if ( *v8 )
      {
        CBuffer::release(*v8);
        operator delete(v11);
        v10 = v14;
      }
      ++v9;
      ++v8;
    }
    while ( v9 != v10 );
  }
  kglDestroyShader(this->kid);
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  if ( this->options._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->options);
    v12 = this->options._Mylast;
    for ( i = this->options._Myfirst; i != v12; ++i )
    {
      if ( i->_Myres >= 8 )
        operator delete(i->_Bx._Ptr);
      i->_Myres = 7;
      i->_Mysize = 0;
      i->_Bx._Buf[0] = 0;
    }
    operator delete(this->options._Myfirst);
    this->options._Myfirst = 0;
    this->options._Mylast = 0;
    this->options._Myend = 0;
  }
  if ( this->cBuffers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cBuffers);
    operator delete(this->cBuffers._Myfirst);
    this->cBuffers._Myfirst = 0;
    this->cBuffers._Mylast = 0;
    this->cBuffers._Myend = 0;
  }
  if ( this->resources._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->resources);
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
Shader *Shader::`vector deleting destructor'(Shader *this, unsigned int a2)
{
  Shader::~Shader(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Shader::apply(Shader *this)
{
  kglSetShader(this->kid);
}
ShaderVariable *Shader::getVar(Shader *this, const std::wstring *name)
{
  ShaderVariable **v2; // esi
  ShaderVariable **v3; // edi
  ShaderVariable *v4; // ebp
  const std::wstring *v5; // eax

  v2 = this->vars._Myfirst;
  v3 = this->vars._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( 1 )
  {
    v4 = *v2;
    v5 = name->_Myres < 8 ? name : name->_Bx._Ptr;
    if ( !std::wstring::compare(&(*v2)->name, 0, (*v2)->name._Mysize, v5->_Bx._Buf, name->_Mysize) )
      break;
    if ( ++v2 == v3 )
      return 0;
  }
  return v4;
}
char Shader::initShaderBinary(Shader *this)
{
  std::wstring *v2; // ebx
  std::wstring *v3; // esi
  std::wstring result; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = Path::getFileNameWithoutExtension(&result, &this->filename);
  v3 = &this->name;
  if ( &this->name != v2 )
  {
    if ( this->name._Myres >= 8 )
      operator delete(v3->_Bx._Ptr);
    this->name._Myres = 7;
    this->name._Mysize = 0;
    v3->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->name, v2);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->guid = ++Shader::guidCount;
  Shader::reflectVars(this);
  return 1;
}
void Shader::reflectVars(Shader *this)
{
  Shader *v1; // edi
  unsigned int v2; // ebp
  unsigned int i; // ebx
  unsigned int v4; // ecx
  GraphicsManager *v5; // ecx
  SystemCBuffers *v6; // eax
  char v7; // al
  CBuffer *v8; // eax
  CBuffer *v9; // eax
  CBuffer *v10; // edi
  Shader *v11; // esi
  CBuffer **v12; // eax
  CBuffer **v13; // ecx
  int v14; // edi
  CBuffer **v15; // ecx
  CBuffer **v16; // eax
  const wchar_t *v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  GraphicsManager *v20; // ecx
  SystemCBuffers *v21; // eax
  bool v22; // bl
  CBuffer **v23; // eax
  CBuffer **v24; // ecx
  CBuffer *v25; // ebp
  unsigned int v26; // ecx
  unsigned int *v27; // esi
  std::vector<TyreThermalPatch *> *v28; // ebx
  ShaderVariable **v29; // edi
  unsigned int v30; // eax
  std::wstring *v31; // ecx
  std::wstring *v32; // eax
  unsigned int v33; // eax
  char v34; // al
  ShaderVariable *v35; // esi
  unsigned int v36; // ecx
  ShaderVariable *v37; // eax
  ShaderVariable *v38; // esi
  TyreThermalPatch **v39; // ecx
  TyreThermalPatch **v40; // edi
  TyreThermalPatch **v41; // edx
  int v42; // ecx
  unsigned int v43; // edx
  unsigned int v44; // edx
  TyreThermalPatch **v45; // ecx
  TyreThermalPatch **v46; // edx
  int v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // edx
  _DWORD *v50; // eax
  unsigned int v51; // ebp
  std::vector<TyreThermalPatch *> *v52; // esi
  ShaderResource *v53; // edi
  int v54; // ecx
  const wchar_t *v55; // ecx
  ShaderResource *v57; // eax
  ShaderResource *v58; // edi
  TyreThermalPatch **v59; // ecx
  TyreThermalPatch **v60; // ebx
  TyreThermalPatch **v61; // edx
  int v62; // ecx
  unsigned int v63; // edx
  unsigned int v64; // edx
  TyreThermalPatch **v65; // ecx
  TyreThermalPatch **v66; // edx
  int v67; // ecx
  unsigned int v68; // edx
  unsigned int v69; // edx
  _DWORD *v70; // eax
  _BYTE v71[32]; // [esp-24h] [ebp-A0h] BYREF
  unsigned int v72; // [esp-4h] [ebp-80h]
  char v73; // [esp+17h] [ebp-65h]
  Shader *v74; // [esp+18h] [ebp-64h]
  unsigned int v75; // [esp+1Ch] [ebp-60h]
  const wchar_t *v76; // [esp+20h] [ebp-5Ch]
  unsigned int v77; // [esp+24h] [ebp-58h]
  ShaderVariable *sh; // [esp+28h] [ebp-54h] BYREF
  ShaderResource *res; // [esp+2Ch] [ebp-50h] BYREF
  CBuffer *nb; // [esp+30h] [ebp-4Ch] BYREF
  KGLShaderVarDesc desc; // [esp+34h] [ebp-48h] BYREF
  ShaderResource *v82; // [esp+48h] [ebp-34h]
  KGLShaderTextureDesc v83; // [esp+4Ch] [ebp-30h] BYREF
  std::wstring name; // [esp+54h] [ebp-28h] BYREF
  int v85; // [esp+78h] [ebp-4h]

  v1 = this;
  v74 = this;
  v2 = kglShaderGetCBuffersCount(this->kid);
  for ( i = 0; i < v2; ++i )
  {
    kglShaderGetCBufferDescAtIndex(v1->kid, i, (KGLShaderCBufferDesc *)&desc);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    if ( *desc.name )
      v4 = wcslen(desc.name);
    else
      v4 = 0;
    std::wstring::assign(&name, desc.name, v4);
    v5 = v1->graphics;
    v85 = 0;
    v6 = GraphicsManager::getCBuffer(v5, &name);
    v85 = -1;
    v7 = v6 == 0;
    v73 = v7;
    if ( name._Myres >= 8 )
    {
      operator delete(name._Bx._Ptr);
      v7 = v73;
    }
    if ( v7 )
    {
      v8 = (CBuffer *)operator new(24);
      v76 = (const wchar_t *)v8;
      v85 = 1;
      if ( v8 )
      {
        CBuffer::CBuffer(v8, desc.cBufferSlot, (int)desc.cBufferName);
        v10 = v9;
      }
      else
      {
        v10 = 0;
      }
      v11 = v74;
      v85 = -1;
      nb = v10;
      v12 = v74->cBuffers._Mylast;
      if ( &nb >= v12 || (v13 = v74->cBuffers._Myfirst, v13 > &nb) )
      {
        if ( v12 == v74->cBuffers._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v74->cBuffers, 1u);
        v16 = v74->cBuffers._Mylast;
        if ( v16 )
          *v16 = v10;
      }
      else
      {
        v14 = &nb - v13;
        if ( v12 == v74->cBuffers._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v74->cBuffers, 1u);
        v15 = v74->cBuffers._Mylast;
        if ( v15 )
          *v15 = v74->cBuffers._Myfirst[v14];
      }
      ++v11->cBuffers._Mylast;
      v1 = v11;
    }
  }
  v17 = (const wchar_t *)kglShaderGetVarsCount(v1->kid);
  v18 = 0;
  v76 = v17;
  v75 = 0;
  if ( v17 )
  {
    do
    {
      kglShaderGetVarDescAtIndex(v1->kid, v18, &desc);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      if ( *desc.cBufferName )
        v19 = wcslen(desc.cBufferName);
      else
        v19 = 0;
      std::wstring::assign(&name, desc.cBufferName, v19);
      v20 = v1->graphics;
      v85 = 2;
      v21 = GraphicsManager::getCBuffer(v20, &name);
      v85 = -1;
      v22 = v21 == 0;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      if ( v22 )
      {
        v23 = v1->cBuffers._Myfirst;
        v24 = v1->cBuffers._Mylast;
        if ( v23 == v24 )
        {
LABEL_33:
          v25 = 0;
        }
        else
        {
          while ( 1 )
          {
            v25 = *v23;
            if ( (*v23)->slot == desc.cBufferSlot )
              break;
            if ( ++v23 == v24 )
              goto LABEL_33;
          }
        }
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        if ( *desc.name )
          v26 = wcslen(desc.name);
        else
          v26 = 0;
        std::wstring::assign(&name, desc.name, v26);
        v27 = (unsigned int *)v1->vars._Myfirst;
        v28 = (std::vector<TyreThermalPatch *> *)&v1->vars;
        v29 = v1->vars._Mylast;
        v85 = 3;
        if ( v27 == (unsigned int *)v29 )
        {
LABEL_42:
          v33 = 0;
        }
        else
        {
          while ( 1 )
          {
            v30 = *v27;
            v31 = (std::wstring *)(*v27 + 4);
            v72 = name._Mysize;
            v77 = v30;
            v32 = &name;
            if ( name._Myres >= 8 )
              v32 = (std::wstring *)name._Bx._Ptr;
            if ( !std::wstring::compare(v31, 0, v31->_Mysize, v32->_Bx._Buf, v72) )
              break;
            if ( ++v27 == (unsigned int *)v29 )
              goto LABEL_42;
          }
          v33 = v77;
        }
        v85 = -1;
        v34 = v33 == 0;
        v73 = v34;
        if ( name._Myres >= 8 )
        {
          operator delete(name._Bx._Ptr);
          v34 = v73;
        }
        if ( v34 )
        {
          v35 = (ShaderVariable *)operator new(44);
          v77 = (unsigned int)v35;
          v85 = 4;
          if ( v35 )
          {
            v72 = desc.size;
            *(_DWORD *)&v71[28] = desc.offset;
            *(_DWORD *)&v71[24] = v25;
            *(_DWORD *)&v71[20] = 7;
            *(_DWORD *)&v71[16] = 0;
            *(_WORD *)v71 = 0;
            if ( *desc.name )
              v36 = wcslen(desc.name);
            else
              v36 = 0;
            std::wstring::assign((std::wstring *)v71, desc.name, v36);
            ShaderVariable::ShaderVariable(v35, *(std::wstring *)v71, *(CBuffer **)&v71[24], *(int *)&v71[28], v72);
            v38 = v37;
          }
          else
          {
            v38 = 0;
          }
          v39 = v28->_Mylast;
          v85 = -1;
          sh = v38;
          if ( &sh >= (ShaderVariable **)v39 || (v40 = v28->_Myfirst, v28->_Myfirst > (TyreThermalPatch **)&sh) )
          {
            v46 = v28->_Myend;
            if ( v39 == v46 && !(v46 - v39) )
            {
              v47 = v39 - v28->_Myfirst;
              if ( v47 == 0x3FFFFFFF )
LABEL_85:
                std::_Xlength_error("vector<T> too long");
              v48 = v46 - v28->_Myfirst;
              if ( 0x3FFFFFFF - (v48 >> 1) >= v48 )
                v49 = (v48 >> 1) + v48;
              else
                v49 = 0;
              if ( v49 < v47 + 1 )
                v49 = v47 + 1;
              std::vector<ID3D11ShaderResourceView *>::_Reallocate(v28, v49);
            }
            v50 = v28->_Mylast;
            if ( v50 )
              *v50 = v38;
          }
          else
          {
            v41 = v28->_Myend;
            if ( v39 == v41 && !(v41 - v39) )
            {
              v42 = v39 - v40;
              if ( v42 == 0x3FFFFFFF )
                goto LABEL_85;
              v43 = v41 - v40;
              if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
                v44 = (v43 >> 1) + v43;
              else
                v44 = 0;
              if ( v44 < v42 + 1 )
                v44 = v42 + 1;
              std::vector<ID3D11ShaderResourceView *>::_Reallocate(v28, v44);
            }
            v45 = v28->_Mylast;
            if ( v45 )
              *v45 = v28->_Myfirst[((char *)&sh - (char *)v40) >> 2];
          }
          ++v28->_Mylast;
        }
        v1 = v74;
      }
      v18 = v75 + 1;
      v75 = v18;
    }
    while ( v18 < (unsigned int)v76 );
  }
  v51 = 0;
  v77 = kglShaderGetTexturesCount(v1->kid);
  v75 = 0;
  if ( v77 )
  {
    v52 = (std::vector<TyreThermalPatch *> *)&v1->resources;
    while ( 1 )
    {
      kglShaderGetTextureDescAtIndex(v1->kid, v51, &v83);
      v53 = (ShaderResource *)operator new(32);
      v82 = v53;
      v85 = 5;
      if ( v53 )
      {
        v72 = v83.slot;
        *(_DWORD *)&v71[28] = 7;
        *(_DWORD *)&v71[24] = 0;
        *(_WORD *)&v71[8] = 0;
        if ( *v83.name )
        {
          v55 = v83.name;
          v76 = v83.name + 1;
          while ( *v55++ )
            ;
          v54 = v55 - v76;
        }
        else
        {
          v54 = 0;
        }
        std::wstring::assign((std::wstring *)&v71[8], v83.name, v54);
        ShaderResource::ShaderResource(v53, *(std::wstring *)&v71[8], v72);
        v58 = v57;
      }
      else
      {
        v58 = 0;
      }
      v59 = v52->_Mylast;
      v85 = -1;
      res = v58;
      if ( &res >= (ShaderResource **)v59 || (v60 = v52->_Myfirst, v52->_Myfirst > (TyreThermalPatch **)&res) )
      {
        v66 = v52->_Myend;
        if ( v59 == v66 && !(v66 - v59) )
        {
          v67 = v59 - v52->_Myfirst;
          if ( v67 == 0x3FFFFFFF )
            goto LABEL_85;
          v68 = v66 - v52->_Myfirst;
          if ( 0x3FFFFFFF - (v68 >> 1) >= v68 )
            v69 = (v68 >> 1) + v68;
          else
            v69 = 0;
          if ( v69 < v67 + 1 )
            v69 = v67 + 1;
          std::vector<ID3D11ShaderResourceView *>::_Reallocate(v52, v69);
          v51 = v75;
        }
        v70 = v52->_Mylast;
        if ( v70 )
          *v70 = v58;
      }
      else
      {
        v61 = v52->_Myend;
        if ( v59 == v61 && !(v61 - v59) )
        {
          v62 = v59 - v60;
          if ( v62 == 0x3FFFFFFF )
            goto LABEL_85;
          v63 = v61 - v60;
          if ( 0x3FFFFFFF - (v63 >> 1) >= v63 )
            v64 = (v63 >> 1) + v63;
          else
            v64 = 0;
          if ( v64 < v62 + 1 )
            v64 = v62 + 1;
          std::vector<ID3D11ShaderResourceView *>::_Reallocate(v52, v64);
          v51 = v75;
        }
        v65 = v52->_Mylast;
        if ( v65 )
          *v65 = v52->_Myfirst[((char *)&res - (char *)v60) >> 2];
      }
      ++v52->_Mylast;
      v75 = ++v51;
      if ( v51 >= v77 )
        break;
      v1 = v74;
    }
  }
}
