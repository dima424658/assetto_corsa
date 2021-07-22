#include "kglshader.h"
void KGLShader::KGLShader(KGLShader *this, const std::wstring *filename, ID3D11Device *device)
{
  KGLShader *v3; // ebx
  ID3D11Device *v4; // edi
  std::wstring *v5; // ecx

  v3 = this;
  v4 = ::device;
  v5 = &this->fileName;
  this->vs = 0;
  v3->ps = 0;
  v3->inputLayout = 0;
  v3->ilType = 0;
  v5->_Myres = 7;
  v5->_Mysize = 0;
  v5->_Bx._Buf[0] = 0;
  std::wstring::assign(v5, filename, 0, 0xFFFFFFFF);
  v3->vars._Myfirst = 0;
  v3->vars._Mylast = 0;
  v3->vars._Myend = 0;
  v3->textures._Myfirst = 0;
  v3->textures._Mylast = 0;
  v3->textures._Myend = 0;
  v3->cBuffers._Myfirst = 0;
  v3->cBuffers._Mylast = 0;
  v3->cBuffers._Myend = 0;
  v3->device = v4;
  KGLShader::loadShaderBinary(v3, filename);
}
void KGLShader::~KGLShader(KGLShader *this)
{
  KGLShaderCBuffer *v2; // eax
  KGLShaderTexture *v3; // eax
  KGLShaderVar *v4; // ecx

  v2 = this->cBuffers._Myfirst;
  if ( v2 )
  {
    std::vector<KGLShaderCBuffer>::_Destroy(
      (std::vector<FriendsLeaderboardDisplayer::FriendsLeaderboardElement> *)this,
      (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)v2,
      (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)this->cBuffers._Mylast);
    operator delete(this->cBuffers._Myfirst);
    this->cBuffers._Myfirst = 0;
    this->cBuffers._Mylast = 0;
    this->cBuffers._Myend = 0;
  }
  v3 = this->textures._Myfirst;
  if ( v3 )
  {
    std::vector<KGLShaderTexture>::_Destroy((std::vector<KGLShaderTexture> *)this, v3, this->textures._Mylast);
    operator delete(this->textures._Myfirst);
    this->textures._Myfirst = 0;
    this->textures._Mylast = 0;
    this->textures._Myend = 0;
  }
  v4 = this->vars._Myfirst;
  if ( v4 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<KGLShaderVar>>>(v4, this->vars._Mylast);
    operator delete(this->vars._Myfirst);
    this->vars._Myfirst = 0;
    this->vars._Mylast = 0;
    this->vars._Myend = 0;
  }
  if ( this->fileName._Myres >= 8 )
    operator delete(this->fileName._Bx._Ptr);
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
}
void KGLShader::loadShaderBinary(KGLShader *this, const std::wstring *filename)
{
  const std::wstring *v3; // eax
  std::wstring *v4; // eax
  int v5; // eax
  bool v6; // cf
  const std::wstring *v7; // eax
  ID3D10Blob *v8; // eax
  ID3D10Blob *v9; // ebp
  const std::wstring *v10; // eax
  ID3D10Blob *v11; // eax
  bool v12; // cl
  ID3D10Blob *v13; // ebx
  ID3D11Device_vtbl *v14; // esi
  int v15; // eax
  int v16; // eax
  std::wstring *v17; // edi
  bool v18; // [esp+1Bh] [ebp-A5h]
  bool v19; // [esp+1Bh] [ebp-A5h]
  std::wstring key; // [esp+1Ch] [ebp-A4h] BYREF
  std::wstring section; // [esp+34h] [ebp-8Ch] BYREF
  std::wstring result; // [esp+4Ch] [ebp-74h] BYREF
  INIReader meta; // [esp+64h] [ebp-5Ch] BYREF
  int v24; // [esp+BCh] [ebp-4h]

  this->inputLayout = 0;
  v3 = std::operator+<wchar_t>(&result, filename, L"_meta.ini");
  v24 = 0;
  INIReader::INIReader(&meta, v3);
  LOBYTE(v24) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( !meta.ready )
  {
    v4 = std::operator+<wchar_t>(&key, filename, L"_meta.ini");
    if ( v4->_Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    _printf("ERROR: Cannot find shader meta %S\n", v4->_Bx._Buf);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ALPHATEST", 9u);
  LOBYTE(v24) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"METADATA", 8u);
  LOBYTE(v24) = 4;
  v5 = INIReader::getInt(&meta, &section, &key);
  v6 = section._Myres < 8;
  this->isAlphaTested = v5 != 0;
  if ( !v6 )
    operator delete(section._Bx._Ptr);
  LOBYTE(v24) = 2;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"PARTICLE", 8u);
  LOBYTE(v24) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"METADATA", 8u);
  LOBYTE(v24) = 6;
  v18 = INIReader::getInt(&meta, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  LOBYTE(v24) = 2;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v18 )
  {
    this->ilType = 2;
  }
  else
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SKINNED", 7u);
    LOBYTE(v24) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"METADATA", 8u);
    LOBYTE(v24) = 8;
    v19 = INIReader::getInt(&meta, &section, &key) != 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    this->ilType = v19;
  }
  v24 = -1;
  INIReader::~INIReader(&meta);
  v7 = std::operator+<wchar_t>(&result, filename, L"_vs.fxo");
  v24 = 9;
  v8 = readBlob(v7);
  v24 = -1;
  v9 = v8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  KGLShader::createVertexShader(this, v9);
  v9->Release(v9);
  v10 = std::operator+<wchar_t>(&key, filename, L"_ps.fxo");
  v24 = 10;
  v11 = readBlob(v10);
  v24 = -1;
  v13 = v11;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  KGLShader::reflectVars(this, v13, v12);
  v14 = this->device->__vftable;
  v15 = ((int (__stdcall *)(ID3D10Blob *, _DWORD, ID3D11PixelShader **))v13->GetBufferSize)(v13, 0, &this->ps);
  v16 = ((int (__stdcall *)(ID3D10Blob *, int))v13->GetBufferPointer)(v13, v15);
  if ( ((int (__stdcall *)(ID3D11Device *, int))v14->CreatePixelShader)(this->device, v16) < 0 )
  {
    v17 = &this->fileName;
    if ( v17->_Myres >= 8 )
      v17 = (std::wstring *)v17->_Bx._Ptr;
    _printf("ERROR: CreatePixelShader failed (%s)\n", (const char *)v17);
  }
  v13->Release(v13);
}
void KGLShader::createVertexShader(KGLShader *this, ID3D10Blob *blob)
{
  ID3D11Device_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  std::wstring *v7; // eax
  int v8; // eax
  void *v9; // eax
  int v10; // [esp-4h] [ebp-14h]

  KGLShader::reflectVars(this, blob, (bool)this);
  v4 = this->device->__vftable;
  v5 = ((int (__stdcall *)(ID3D10Blob *, _DWORD, KGLShader *))blob->GetBufferSize)(blob, 0, this);
  v6 = ((int (__stdcall *)(ID3D10Blob *, int))blob->GetBufferPointer)(blob, v5);
  if ( ((int (__stdcall *)(ID3D11Device *, int))v4->CreateVertexShader)(this->device, v6) >= 0 )
  {
    v10 = this->ilType;
    v8 = ((int (*)(void))blob->GetBufferSize)();
    v9 = (void *)((int (__stdcall *)(ID3D10Blob *, int))blob->GetBufferPointer)(blob, v8);
    this->inputLayout = getInputLayout(this->device, v9, (unsigned int)blob, v10);
  }
  else
  {
    v7 = &this->fileName;
    if ( this->fileName._Myres >= 8 )
      v7 = (std::wstring *)v7->_Bx._Ptr;
    _printf("ERROR: CreateVertexShader failed (%S)\n", v7->_Bx._Buf);
  }
}
void KGLShader::reflectVars(KGLShader *this, ID3D10Blob *blob, bool isPS)
{
  ID3D10Blob_vtbl *v3; // eax
  int v4; // eax
  const void *v5; // eax
  unsigned int v6; // edx
  void (__cdecl *v7)(void *, const void *, size_t); // ebx
  ID3D11ShaderReflectionConstantBuffer *v8; // ebx
  unsigned int v9; // edi
  bool v10; // zf
  unsigned int v11; // ecx
  std::wstring *v12; // eax
  KGLShader *v13; // esi
  unsigned int v14; // ecx
  std::vector<KGLShaderVar> *v15; // esi
  ID3D11ShaderReflectionVariable *v16; // eax
  unsigned int v17; // ecx
  std::wstring *v18; // eax
  std::wstring *v19; // edi
  std::wstring *v20; // ebx
  KGLShaderVar *v21; // esi
  const wchar_t *v22; // eax
  unsigned int v23; // ecx
  KGLShaderVar *v24; // esi
  unsigned int v25; // ecx
  KGLShaderVar *v26; // esi
  unsigned int i; // edi
  unsigned int v28; // ecx
  KGLShaderTexture *v29; // esi
  const IID *v30; // [esp+30h] [ebp-1DCh]
  void **v31; // [esp+34h] [ebp-1D8h]
  ID3D11ShaderReflection *pReflector; // [esp+48h] [ebp-1C4h] BYREF
  std::vector<KGLShaderVar> *v33; // [esp+4Ch] [ebp-1C0h]
  unsigned int v34; // [esp+50h] [ebp-1BCh]
  KGLShader *v35; // [esp+54h] [ebp-1B8h]
  unsigned int v36; // [esp+58h] [ebp-1B4h]
  unsigned int v37; // [esp+5Ch] [ebp-1B0h]
  ID3D11ShaderReflectionConstantBuffer *v38; // [esp+60h] [ebp-1ACh]
  _D3D11_SHADER_BUFFER_DESC cbDesc; // [esp+64h] [ebp-1A8h] BYREF
  char *_Ptr[2]; // [esp+78h] [ebp-194h] BYREF
  unsigned int v41; // [esp+80h] [ebp-18Ch]
  _D3D11_SHADER_VARIABLE_DESC vDesc; // [esp+98h] [ebp-174h] BYREF
  _D3D11_SHADER_INPUT_BIND_DESC rDesc; // [esp+BCh] [ebp-150h] BYREF
  _D3D11_SHADER_DESC desc; // [esp+DCh] [ebp-130h] BYREF
  std::string s; // [esp+174h] [ebp-98h] BYREF
  std::wstring v46; // [esp+18Ch] [ebp-80h] BYREF
  KGLShaderTexture res; // [esp+1A4h] [ebp-68h] BYREF
  KGLShaderVar sh; // [esp+1C0h] [ebp-4Ch] BYREF
  int v49; // [esp+208h] [ebp-4h]

  v35 = this;
  v3 = blob->__vftable;
  pReflector = 0;
  v4 = ((int (__stdcall *)(ID3D10Blob *, GUID *))v3->GetBufferSize)(blob, &IID_ID3D11ShaderReflection);
  v5 = (const void *)((int (__stdcall *)(ID3D10Blob *, int))blob->GetBufferPointer)(blob, v4);
  D3DReflect(v5, (SIZE_T)&pReflector, v30, v31);
  (*(void (__cdecl **)(unsigned int, unsigned int *))(*(_DWORD *)v34 + 12))(v34, &desc.Flags);
  v6 = 0;
  v7 = (void (__cdecl *)(void *, const void *, size_t))_memmove;
  v34 = 0;
  if ( desc.ConstantBuffers )
  {
    do
    {
      v8 = pReflector->GetConstantBufferByIndex(pReflector, v6);
      v38 = v8;
      v38->GetDesc(v38, &cbDesc);
      pReflector->GetResourceBindingDescByName(pReflector, cbDesc.Name, &rDesc);
      v9 = rDesc.BindPoint;
      s._Myres = 15;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      v10 = *cbDesc.Name == 0;
      v37 = rDesc.BindPoint;
      if ( v10 )
        v11 = 0;
      else
        v11 = strlen(cbDesc.Name);
      std::string::assign(&s, cbDesc.Name, v11);
      v49 = 0;
      v12 = string2wstring(&v46, &s);
      v13 = v35;
      LOBYTE(v49) = 1;
      KGLShader::addCBuffer(v35, v12, cbDesc.Size, v9);
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v49 = -1;
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( s._Myres >= 0x10 )
        operator delete(s._Bx._Ptr);
      v14 = 0;
      v36 = 0;
      if ( cbDesc.Variables )
      {
        v15 = &v13->vars;
        v33 = v15;
        do
        {
          v16 = v8->GetVariableByIndex(v8, v14);
          v16->GetDesc(v16, &vDesc);
          s._Myres = 15;
          s._Mysize = 0;
          s._Bx._Buf[0] = 0;
          if ( *vDesc.Name )
          {
            v17 = strlen(vDesc.Name);
            v15 = v33;
          }
          else
          {
            v17 = 0;
          }
          std::string::assign(&s, vDesc.Name, v17);
          v49 = 2;
          v18 = string2wstring(&v46, &s);
          v19 = &v15->_Myfirst->name;
          v20 = v18;
          v21 = v15->_Mylast;
          if ( v19 == (std::wstring *)v21 )
          {
LABEL_20:
            v19 = 0;
          }
          else
          {
            while ( 1 )
            {
              v22 = (const wchar_t *)(v20->_Myres < 8 ? v20 : v20->_Bx._Ptr);
              if ( !std::wstring::compare(v19, 0, v19->_Mysize, v22, v20->_Mysize) )
                break;
              v19 = (std::wstring *)((char *)v19 + 60);
              if ( v19 == (std::wstring *)v21 )
                goto LABEL_20;
            }
          }
          if ( v46._Myres >= 8 )
            operator delete(v46._Bx._Ptr);
          v49 = -1;
          v46._Myres = 7;
          v46._Mysize = 0;
          v46._Bx._Buf[0] = 0;
          if ( s._Myres >= 0x10 )
            operator delete(s._Bx._Ptr);
          if ( v19 )
          {
            v15 = v33;
          }
          else
          {
            sh.name._Myres = 7;
            sh.name._Mysize = 0;
            sh.name._Bx._Buf[0] = 0;
            sh.cBufferName._Myres = 7;
            sh.cBufferName._Mysize = 0;
            sh.cBufferName._Bx._Buf[0] = 0;
            v49 = 3;
            s._Myres = 15;
            s._Mysize = 0;
            s._Bx._Buf[0] = 0;
            if ( *cbDesc.Name )
              v23 = strlen(cbDesc.Name);
            else
              v23 = 0;
            std::string::assign(&s, cbDesc.Name, v23);
            LOBYTE(v49) = 4;
            v24 = (KGLShaderVar *)string2wstring(&v46, &s);
            if ( &sh.cBufferName != (std::wstring *)v24 )
            {
              if ( sh.cBufferName._Myres >= 8 )
                operator delete(sh.cBufferName._Bx._Ptr);
              sh.cBufferName._Myres = 7;
              sh.cBufferName._Mysize = 0;
              sh.cBufferName._Bx._Buf[0] = 0;
              if ( v24->name._Myres >= 8 )
              {
                sh.cBufferName._Bx._Ptr = v24->name._Bx._Ptr;
                v24->name._Bx._Ptr = 0;
              }
              else if ( v24->name._Mysize != -1 )
              {
                _memmove(&sh.cBufferName, v24, 2 * (v24->name._Mysize + 1));
              }
              sh.cBufferName._Mysize = v24->name._Mysize;
              sh.cBufferName._Myres = v24->name._Myres;
              v24->name._Myres = 7;
              v24->name._Mysize = 0;
              v24->name._Bx._Buf[0] = 0;
            }
            if ( v46._Myres >= 8 )
              operator delete(v46._Bx._Ptr);
            LOBYTE(v49) = 3;
            v46._Myres = 7;
            v46._Mysize = 0;
            v46._Bx._Buf[0] = 0;
            if ( s._Myres >= 0x10 )
              operator delete(s._Bx._Ptr);
            s._Myres = 15;
            s._Mysize = 0;
            s._Bx._Buf[0] = 0;
            if ( *vDesc.Name )
              v25 = strlen(vDesc.Name);
            else
              v25 = 0;
            std::string::assign(&s, vDesc.Name, v25);
            LOBYTE(v49) = 5;
            v26 = (KGLShaderVar *)string2wstring(&v46, &s);
            if ( &sh != v26 )
            {
              if ( sh.name._Myres >= 8 )
                operator delete(sh.name._Bx._Ptr);
              sh.name._Myres = 7;
              sh.name._Mysize = 0;
              sh.name._Bx._Buf[0] = 0;
              if ( v26->name._Myres >= 8 )
              {
                sh.name._Bx._Ptr = v26->name._Bx._Ptr;
                v26->name._Bx._Ptr = 0;
              }
              else if ( v26->name._Mysize != -1 )
              {
                _memmove(&sh, v26, 2 * (v26->name._Mysize + 1));
              }
              sh.name._Mysize = v26->name._Mysize;
              sh.name._Myres = v26->name._Myres;
              v26->name._Myres = 7;
              v26->name._Mysize = 0;
              v26->name._Bx._Buf[0] = 0;
            }
            if ( v46._Myres >= 8 )
              operator delete(v46._Bx._Ptr);
            LOBYTE(v49) = 3;
            v46._Myres = 7;
            v46._Mysize = 0;
            v46._Bx._Buf[0] = 0;
            if ( s._Myres >= 0x10 )
              operator delete(s._Bx._Ptr);
            v15 = v33;
            sh.offset = vDesc.StartOffset;
            sh.size = vDesc.Size;
            sh.cBufferSlot = v37;
            std::vector<KGLShaderVar>::push_back(v33, &sh);
            v49 = -1;
            if ( sh.cBufferName._Myres >= 8 )
              operator delete(sh.cBufferName._Bx._Ptr);
            sh.cBufferName._Myres = 7;
            sh.cBufferName._Mysize = 0;
            sh.cBufferName._Bx._Buf[0] = 0;
            if ( sh.name._Myres >= 8 )
              operator delete(sh.name._Bx._Ptr);
          }
          v8 = v38;
          v14 = v36 + 1;
          v36 = v14;
        }
        while ( v14 < cbDesc.Variables );
      }
      v6 = v34 + 1;
      v34 = v6;
    }
    while ( v6 < desc.ConstantBuffers );
    v7 = (void (__cdecl *)(void *, const void *, size_t))_memmove;
  }
  for ( i = 0; i < desc.BoundResources; ++i )
  {
    pReflector->GetResourceBindingDesc(pReflector, i, (_D3D11_SHADER_INPUT_BIND_DESC *)_Ptr);
    if ( _Ptr[1] == (char *)2 && (v41 < 6 || v41 >= 0x14) )
    {
      res.name._Myres = 7;
      res.name._Mysize = 0;
      res.name._Bx._Buf[0] = 0;
      v49 = 6;
      s._Myres = 15;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      if ( *_Ptr[0] )
        v28 = strlen(_Ptr[0]);
      else
        v28 = 0;
      std::string::assign(&s, _Ptr[0], v28);
      LOBYTE(v49) = 7;
      v29 = (KGLShaderTexture *)string2wstring(&v46, &s);
      if ( &res != v29 )
      {
        if ( res.name._Myres >= 8 )
          operator delete(res.name._Bx._Ptr);
        res.name._Myres = 7;
        res.name._Mysize = 0;
        res.name._Bx._Buf[0] = 0;
        if ( v29->name._Myres >= 8 )
        {
          res.name._Bx._Ptr = v29->name._Bx._Ptr;
          v29->name._Bx._Ptr = 0;
        }
        else if ( v29->name._Mysize != -1 )
        {
          v7(&res, v29, 2 * (v29->name._Mysize + 1));
        }
        res.name._Mysize = v29->name._Mysize;
        res.name._Myres = v29->name._Myres;
        v29->name._Myres = 7;
        v29->name._Mysize = 0;
        v29->name._Bx._Buf[0] = 0;
      }
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      LOBYTE(v49) = 6;
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( s._Myres >= 0x10 )
        operator delete(s._Bx._Ptr);
      res.slot = v41;
      std::vector<KGLShaderTexture>::push_back(&v35->textures, &res);
      v49 = -1;
      if ( res.name._Myres >= 8 )
        operator delete(res.name._Bx._Ptr);
      res.name._Myres = 7;
      res.name._Mysize = 0;
      res.name._Bx._Buf[0] = 0;
    }
  }
  pReflector->Release(pReflector);
}
void KGLShader::addCBuffer(KGLShader *this, const std::wstring *name, unsigned int size, unsigned int slot)
{
  KGLShaderCBuffer *v4; // esi
  KGLShaderCBuffer *v5; // edi
  const std::wstring *v6; // eax
  std::vector<KGLShaderCBuffer> *v7; // [esp+18h] [ebp-38h]
  KGLShaderCBuffer b; // [esp+1Ch] [ebp-34h] BYREF
  int v9; // [esp+4Ch] [ebp-4h]

  v4 = this->cBuffers._Myfirst;
  v5 = this->cBuffers._Mylast;
  v7 = &this->cBuffers;
  if ( v4 == v5 )
  {
LABEL_8:
    b.cBufferName._Myres = 7;
    b.cBufferName._Mysize = 0;
    b.cBufferName._Bx._Buf[0] = 0;
    v9 = 0;
    if ( &b != (KGLShaderCBuffer *)name )
      std::wstring::assign(&b.cBufferName, name, 0, 0xFFFFFFFF);
    b.size = size;
    b.slot = slot;
    std::vector<KGLShaderCBuffer>::push_back(v7, &b);
    if ( b.cBufferName._Myres >= 8 )
      operator delete(b.cBufferName._Bx._Ptr);
  }
  else
  {
    while ( 1 )
    {
      v6 = name->_Myres < 8 ? name : name->_Bx._Ptr;
      if ( !std::wstring::compare(&v4->cBufferName, 0, v4->cBufferName._Mysize, v6->_Bx._Buf, name->_Mysize)
        || v4->slot == slot )
      {
        break;
      }
      if ( ++v4 == v5 )
        goto LABEL_8;
    }
  }
}
void KGLShader::clearInputLayouts()
{
  std::_Tree_node<std::pair<int const ,ID3D11InputLayout *>,void *> *v0; // edi
  std::_Tree_node<std::pair<int const ,ID3D11InputLayout *>,void *> *v1; // esi
  std::_Tree_node<std::pair<int const ,ID3D11InputLayout *>,void *> *v2; // eax
  std::_Tree_node<std::pair<int const ,ID3D11InputLayout *>,void *> *j; // eax
  std::_Tree_node<std::pair<int const ,ID3D11InputLayout *>,void *> *i; // eax

  v0 = inputLayouts._Myhead;
  v1 = inputLayouts._Myhead->_Left;
  while ( v1 != v0 )
  {
    v1->_Myval.second->Release(v1->_Myval.second);
    if ( !v1->_Isnil )
    {
      v2 = v1->_Right;
      if ( v2->_Isnil )
      {
        for ( i = v1->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v1 != i->_Right )
            break;
          v1 = i;
        }
        v1 = i;
      }
      else
      {
        v1 = v1->_Right;
        for ( j = v2->_Left; !j->_Isnil; j = j->_Left )
          v1 = j;
      }
    }
  }
}
