#include "carfakeshadow.h
void __userpurge CarFakeShadow::CarFakeShadow(CarFakeShadow *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *acar)
{
  Game *v4; // ecx
  GLRenderer *v5; // eax
  Sim *v6; // eax
  Game *v7; // ecx
  Shader *v8; // eax
  bool v9; // cf
  CarAvatar *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  double v13; // st7
  double v14; // st7
  CarAvatar *v15; // eax
  std::wstring *v16; // eax
  std::wstring v17; // [esp-1Ch] [ebp-118h] BYREF
  unsigned int v18; // [esp-4h] [ebp-100h]
  CarFakeShadow *v19; // [esp+14h] [ebp-E8h]
  std::wstring name; // [esp+18h] [ebp-E4h] BYREF
  std::wstring key; // [esp+30h] [ebp-CCh] BYREF
  std::wstring _Left; // [esp+48h] [ebp-B4h] BYREF
  std::wstring loadname; // [esp+60h] [ebp-9Ch] BYREF
  std::wstring v24; // [esp+78h] [ebp-84h] BYREF
  std::wstring result; // [esp+90h] [ebp-6Ch] BYREF
  INIReader r; // [esp+A8h] [ebp-54h] BYREF
  int v27; // [esp+F8h] [ebp-4h]

  v19 = this;
  v18 = (unsigned int)acar->game;
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  std::wstring::assign(&v17, L"CAR_FAKE_SHADOW", 0xFu);
  GameObject::GameObject(this, v17, (Game *)v18);
  this->__vftable = (CarFakeShadow_vtbl *)&CarFakeShadow::`vftable';
  this->car = acar;
  this->sim = acar->sim;
  this->txBody.kid = 0;
  this->txBody.fileName._Myres = 7;
  this->txBody.fileName._Mysize = 0;
  v27 = 0;
  this->txBody.fileName._Bx._Buf[0] = 0;
  LOBYTE(v27) = 1;
  `eh vector constructor iterator'(
    this->txWheels,
    0x1Cu,
    4,
    (void (*)(void *))Texture::Texture,
    (void (*)(void *))OnSetupAppCreated::~OnSetupAppCreated);
  v4 = this->game;
  this->localGL = 0;
  LOBYTE(v27) = 2;
  v5 = GraphicsManager::createGLRenderer(v4->graphics, 6u);
  v18 = (unsigned int)this;
  this->localGL = v5;
  v17._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_8976a459e797af2afd5a5fba90ea734d_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v17._Bx._Alias[4] = this;
  v17._Mysize = (unsigned int)&v17;
  v6 = this->sim;
  LOBYTE(v27) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v6->carFakeShadowsNode->evOnRender,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v17,
    (void *)v18);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksFakeCarShadows", 0x10u);
  v7 = this->game;
  LOBYTE(v27) = 4;
  v8 = GraphicsManager::getShader(v7->graphics, a2, &name);
  v9 = name._Myres < 8;
  this->shFakeCarShadows = v8;
  LOBYTE(v27) = 2;
  if ( !v9 )
    operator delete(name._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v10 = this->car;
  LOBYTE(v27) = 5;
  v11 = std::operator+<wchar_t>(&result, &_Left, &v10->unixName);
  LOBYTE(v27) = 6;
  v12 = std::operator+<wchar_t>(&v24, v11, L"/data/ambient_shadows.ini");
  LOBYTE(v27) = 7;
  INIReader::INIReader(&r, v12);
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v27) = 11;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  this->tyreSideSize = 0.30000001;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"WIDTH", 5u);
    LOBYTE(v27) = 12;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"SETTINGS", 8u);
    LOBYTE(v27) = 13;
    v13 = INIReader::getFloat(&r, &name, &key);
    v9 = name._Myres < 8;
    this->width = v13;
    if ( !v9 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v27) = 11;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LENGTH", 6u);
    LOBYTE(v27) = 14;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"SETTINGS", 8u);
    LOBYTE(v27) = 15;
    v14 = INIReader::getFloat(&r, &name, &key);
    v9 = name._Myres < 8;
    this->length = v14;
    if ( !v9 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v27) = 11;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    this->width = 2.0;
    this->length = 4.0;
  }
  v18 = 13;
  this->ambientGain = 0.5;
  v17._Myres = (unsigned int)L"content/cars/";
  this->heightGain = 0.0;
  this->bodyRefHeight = 0.0;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, (const wchar_t *)v17._Myres, v18);
  v15 = this->car;
  LOBYTE(v27) = 16;
  v16 = std::operator+<wchar_t>(&key, &name, &v15->unixName);
  LOBYTE(v27) = 17;
  std::operator+<wchar_t>(&loadname, v16, L"/body_shadow.png");
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v27) = 20;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Bx._Buf[0] = 0;
  name._Mysize = 0;
  if ( Path::fileExists(a2, &loadname, 0) )
    CarFakeShadow::loadShadows(this);
  else
    CarFakeShadow::generateFakeShadow(this, a2);
  if ( loadname._Myres >= 8 )
    operator delete(loadname._Bx._Ptr);
  loadname._Myres = 7;
  loadname._Mysize = 0;
  loadname._Bx._Buf[0] = 0;
  LOBYTE(v27) = 2;
  INIReader::~INIReader(&r);
}
CarFakeShadow *CarFakeShadow::`vector deleting destructor'(CarFakeShadow *this, unsigned int a2)
{
  this->__vftable = (CarFakeShadow_vtbl *)&CarFakeShadow::`vftable';
  `eh vector destructor iterator'(
    this->txWheels,
    0x1Cu,
    4,
    (void (*)(void *))OnSetupAppCreated::~OnSetupAppCreated);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txBody);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __usercall CarFakeShadow::generateFakeShadow(CarFakeShadow *this@<ecx>, unsigned int a2@<ebx>)
{
  void *v3; // eax
  const mat44f *v4; // eax
  CarAvatar *v5; // eax
  Node *v6; // eax
  __m128 v7; // xmm0
  unsigned int v8; // xmm2_4
  mat44f *v9; // eax
  Game *v10; // eax
  Game *v11; // eax
  int v12; // eax
  CarAvatar *v13; // eax
  ShaderVariable *v14; // eax
  ShaderVariable *v15; // eax
  ShaderVariable *v16; // eax
  ShaderVariable *v17; // eax
  const mat44f *v18; // eax
  int v19; // esi
  CarAvatar *v20; // ecx
  void *v21; // eax
  Node *v22; // eax
  Game *v23; // ecx
  Node *v24; // eax
  mat44f *v25; // eax
  Node *v26; // eax
  CarAvatar *v27; // eax
  std::wostream *v28; // eax
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  std::wostream *v31; // eax
  std::wstring *v32; // eax
  int v33; // eax
  CarAvatar *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  void *v37; // esi
  const std::wstring *right; // [esp+8h] [ebp-210h]
  mat44f v39; // [esp+28h] [ebp-1F0h] BYREF
  char v40; // [esp+68h] [ebp-1B0h] BYREF
  mat44f result; // [esp+6Ch] [ebp-1ACh] BYREF
  CameraMeshFilter v42; // [esp+ACh] [ebp-16Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v43; // [esp+BCh] [ebp-15Ch] BYREF
  int v44[4]; // [esp+16Ch] [ebp-ACh] BYREF
  void *v45; // [esp+17Ch] [ebp-9Ch]
  __int128 v46; // [esp+180h] [ebp-98h] BYREF
  float v47; // [esp+190h] [ebp-88h]
  float v48; // [esp+194h] [ebp-84h] BYREF
  vec3f cameraUpVector; // [esp+198h] [ebp-80h] BYREF
  void *rt; // [esp+1A4h] [ebp-74h]
  void *v51; // [esp+1A8h] [ebp-70h] BYREF
  std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > v52; // [esp+1AFh] [ebp-69h] BYREF
  std::wstring v53; // [esp+1B0h] [ebp-68h] BYREF
  std::wstring v54; // [esp+1C8h] [ebp-50h] BYREF
  std::wstring _Left; // [esp+1E0h] [ebp-38h] BYREF
  float color[4]; // [esp+1F8h] [ebp-20h] BYREF
  int v57; // [esp+210h] [ebp-8h]
  int v58; // [esp+214h] [ebp-4h]

  rt = 0;
  kglCreateRenderTarget(512, 512, 0, 1, 1);
  v45 = v3;
  *(_OWORD *)color = _xmm;
  kglSetRenderTarget(v3);
  kglSetViewport(0.0, 0.0, 512.0, 512.0);
  kglClearColor(color);
  kglClearDepth(1.0);
  GraphicsManager::setBlendMode(this->game->graphics, eOpaque);
  GraphicsManager::setDepthMode(this->game->graphics, eDepthNormal);
  v4 = mat44f::createOrtho(
         &result,
         COERCE_FLOAT(COERCE_UNSIGNED_INT(this->width * 0.98000002) ^ _xmm),
         this->width * 0.98000002,
         COERCE_FLOAT(COERCE_UNSIGNED_INT(this->length * 0.98000002) ^ _xmm),
         this->length * 0.98000002,
         0.1,
         500.0);
  GraphicsManager::setProjectionMatrix(this->game->graphics, v4);
  v5 = this->car;
  cameraUpVector.x = 0.0;
  cameraUpVector.y = 0.0;
  v6 = v5->bodyTransform;
  cameraUpVector.z = 1.0;
  v7 = (__m128)LODWORD(v6->matrix.M41);
  v8 = LODWORD(v6->matrix.M43);
  v47 = v6->matrix.M42;
  HIDWORD(v46) = v7.m128_i32[0];
  v48 = *(float *)&v8;
  *(_DWORD *)&v54._Bx._Alias[12] = v7.m128_i32[0];
  *(float *)&v54._Mysize = v47 - 10.0;
  v54._Myres = v8;
  v9 = mat44f::createLookAt(v7, &result, (const vec3f *)&v54._Bx._Alias[12], (const vec3f *)&v46 + 1, &cameraUpVector);
  GraphicsManager::setViewMatrix(this->game->graphics, v9, 0);
  CameraMeshFilter::CameraMeshFilter(&v42, 0, Opaque, 5);
  v10 = this->game;
  v58 = 0;
  FakeMaterialFilter::FakeMaterialFilter((FakeMaterialFilter *)&v46, a2, v10->graphics);
  v11 = this->game;
  LOBYTE(v58) = 1;
  v12 = (int)v11->graphics;
  v44[0] = (int)&v46;
  v44[1] = (int)&v42;
  v44[2] = v12;
  v44[3] = 0;
  FolderEncrypter::FolderEncrypter(&v52);
  v13 = this->car;
  LOBYTE(v58) = 2;
  WorldMatrixTraverser::traverse((WorldMatrixTraverser *)&v52, v13->bodyTransform);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"refHeight", 9u);
  LOBYTE(v58) = 3;
  v14 = Shader::getVar((Shader *)DWORD2(v46), &_Left);
  ShaderVariable::set(v14, &this->bodyRefHeight);
  LOBYTE(v58) = 2;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"heightGain", 0xAu);
  LOBYTE(v58) = 4;
  v15 = Shader::getVar((Shader *)DWORD2(v46), &_Left);
  ShaderVariable::set(v15, &this->heightGain);
  LOBYTE(v58) = 2;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"gain", 4u);
  LOBYTE(v58) = 5;
  v16 = Shader::getVar((Shader *)DWORD2(v46), &_Left);
  ShaderVariable::set(v16, &this->ambientGain);
  LOBYTE(v58) = 2;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"gain", 4u);
  LOBYTE(v58) = 6;
  v17 = Shader::getVar((Shader *)DWORD2(v46), &_Left);
  CBuffer::commit(v17->buffer);
  LOBYTE(v58) = 2;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  GraphicsManager::commitShaderChanges(this->game->graphics);
  this->car->bodyTransform->render(this->car->bodyTransform, (RenderContext *)v44);
  v18 = mat44f::createOrtho(
          &result,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(this->tyreSideSize * 0.98000002) ^ _xmm),
          this->tyreSideSize * 0.98000002,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(this->tyreSideSize * 0.98000002) ^ _xmm),
          this->tyreSideSize * 0.98000002,
          0.1,
          500.0);
  GraphicsManager::setProjectionMatrix(this->game->graphics, v18);
  v19 = 0;
  v54._Myres = 1065353216;
  *(_DWORD *)&v54._Bx._Alias[12] = 0;
  v54._Mysize = 0;
  do
  {
    kglCreateRenderTarget(64, 64, 0, 1, 1);
    v20 = this->car;
    v51 = v21;
    v22 = (Node *)((int (*)(ISuspensionAvatar *))v20->suspensionAvatar->getWheelTransform)(v20->suspensionAvatar);
    WorldMatrixTraverser::traverse((WorldMatrixTraverser *)&v51 + 3, v22);
    kglSetRenderTarget(rt);
    kglSetViewport(0.0, 0.0, 64.0, 64.0);
    v23 = this->game;
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&_Left._Bx + 4) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    GraphicsManager::clearRenderTarget(v23->graphics, (const vec4f *)&_Left._Bx._Alias[4]);
    GraphicsManager::clearRenderTargetDepth(this->game->graphics, 1.0);
    v24 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, v19);
    v24->getWorldMatrix(v24, (mat44f *)&v40);
    *((_QWORD *)&v46 + 1) = *(_QWORD *)&result.M34;
    v47 = result.M42;
    v48 = result.M34;
    cameraUpVector.x = result.M41 - 10.0;
    cameraUpVector.y = result.M42;
    v25 = mat44f::createLookAt(
            (__m128)LODWORD(result.M42),
            &v39,
            (const vec3f *)&v48,
            (const vec3f *)((char *)&v46 + 8),
            (const vec3f *)&v54._Bx._Alias[8]);
    GraphicsManager::setViewMatrix(this->game->graphics, v25, 0);
    v26 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, v19);
    v26->render(v26, (RenderContext *)&v43.gap68[68]);
    v42.camera = (Camera *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    HIDWORD(v43._Chcount) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(&v43.gap60[4]);
    LODWORD(cameraUpVector.z) |= 1u;
    LOBYTE(v57) = 7;
    std::wiostream::basic_iostream<wchar_t>(&v42.camera, &v43.gap10[4], 0);
    v57 = 8;
    *(Camera **)((char *)&v42.camera + LODWORD(v42.camera->fov)) = (Camera *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v42.maxLayer + LODWORD(v42.camera->fov)) = LODWORD(v42.camera->fov) - 104;
    std::wstreambuf::wstreambuf(&v43.gap10[4]);
    *(_DWORD *)&v43.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v43.gap10[60] = 0;
    *(_DWORD *)&v43.gap10[64] = 0;
    LOBYTE(v57) = 10;
    _Left._Mysize = 7;
    *(_DWORD *)&_Left._Bx._Alias[12] = 0;
    LOWORD(v54._Myres) = 0;
    std::wstring::assign((std::wstring *)&v54._Myres, L"content/cars/", 0xDu);
    v27 = this->car;
    LOBYTE(v57) = 11;
    right = &v27->unixName;
    v28 = std::operator<<<wchar_t>((std::wostream *)((char *)&v43._Chcount + 4), (const std::wstring *)&v54._Myres);
    v29 = std::operator<<<wchar_t>(v28, right);
    v30 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v29, "/tyre_");
    v31 = (std::wostream *)std::wostream::operator<<(v30, v19);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v31, (const char *)v19);
    LOBYTE(v58) = 10;
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
    v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v43, &_Left);
    if ( v32->_Myres >= 8 )
      v32 = (std::wstring *)v32->_Bx._Ptr;
    kglRenderTargetSaveToFile(v51, v32->_Bx._Buf);
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
    kglDestroyRenderTarget(v51);
    LOBYTE(v58) = 2;
    *(_DWORD *)&v43.gap0[*(_DWORD *)(*(_DWORD *)v43.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(Camera **)((char *)&v42.camera + *(_DWORD *)(*(_DWORD *)v43.gap0 + 4)) = (Camera *)(*(_DWORD *)(*(_DWORD *)v43.gap0 + 4)
                                                                                        - 104);
    *(_DWORD *)&v43.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v43.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v43.gap10[8]) )
        std::wstreambuf::epptr(&v43.gap10[8]);
      else
        std::wstreambuf::egptr(&v43.gap10[8]);
      std::wstreambuf::eback(&v43.gap10[8]);
      v33 = std::wstreambuf::eback(&v43.gap10[8]);
      operator delete(v33);
    }
    std::wstreambuf::setg(&v43.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v43.gap10[8], 0, 0);
    *(_DWORD *)&v43.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v43.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v43.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v43.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v43.gap68);
    ++v19;
  }
  while ( v19 < 4 );
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v34 = this->car;
  LOBYTE(v58) = 12;
  v35 = std::operator+<wchar_t>(&v54, &_Left, &v34->unixName);
  LOBYTE(v58) = 13;
  std::operator+<wchar_t>(&v53, v35, L"/body_shadow.png");
  if ( v54._Myres >= 8 )
    operator delete(v54._Bx._Ptr);
  v54._Myres = 7;
  v54._Mysize = 0;
  v54._Bx._Buf[0] = 0;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v36 = &v53;
  v37 = v45;
  if ( v53._Myres >= 8 )
    v36 = (std::wstring *)v53._Bx._Ptr;
  kglRenderTargetSaveToFile(v45, v36->_Bx._Buf);
  kglDestroyRenderTarget(v37);
  if ( v53._Myres >= 8 )
    operator delete(v53._Bx._Ptr);
  v53._Myres = 7;
  v53._Mysize = 0;
  v53._Bx._Buf[0] = 0;
  LOBYTE(v58) = 1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v52);
  LOBYTE(v58) = 0;
  MaterialFilter::~MaterialFilter((MaterialFilter *)&v46);
  v58 = -1;
  CameraMeshFilter::~CameraMeshFilter(&v42);
}
void CarFakeShadow::loadShadows(CarFakeShadow *this)
{
  int v2; // ebp
  CarAvatar *v3; // eax
  std::wstring *v4; // eax
  Game *v5; // eax
  Texture *v6; // eax
  void *v7; // ecx
  const std::wstring *v8; // eax
  int v9; // edi
  std::wstring *v10; // esi
  CarAvatar *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  const std::wstring *v16; // eax
  Game *v17; // ecx
  Texture *v18; // eax
  void *v19; // ecx
  const std::wstring *v20; // eax
  int v21; // eax
  const std::wstring *v22; // [esp-14h] [ebp-170h]
  const wchar_t *v23; // [esp-4h] [ebp-160h]
  int v24; // [esp+14h] [ebp-148h]
  int v25; // [esp+18h] [ebp-144h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v26; // [esp+1Ch] [ebp-140h] BYREF
  Texture v27; // [esp+CCh] [ebp-90h] BYREF
  std::wstring _Left; // [esp+E8h] [ebp-74h] BYREF
  std::wstring result; // [esp+100h] [ebp-5Ch] BYREF
  std::wstring loadname; // [esp+118h] [ebp-44h] BYREF
  Texture v31; // [esp+130h] [ebp-2Ch] BYREF
  int v32; // [esp+154h] [ebp-8h]
  int v33; // [esp+158h] [ebp-4h]
  void *retaddr; // [esp+15Ch] [ebp+0h]

  v2 = 0;
  v25 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v3 = this->car;
  v33 = 0;
  v4 = std::operator+<wchar_t>(&result, &_Left, &v3->unixName);
  LOBYTE(v33) = 1;
  std::operator+<wchar_t>(&loadname, v4, L"/body_shadow.png");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v33) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  v5 = this->game;
  _Left._Mysize = 0;
  v6 = ResourceStore::getTexture(v5->graphics->resourceStore._Myptr, &v27, &loadname, 0);
  v7 = v6->kid;
  v8 = &v6->fileName;
  this->txBody.kid = v7;
  LOBYTE(v33) = 5;
  if ( &this->txBody.fileName != v8 )
    std::wstring::assign(&this->txBody.fileName, v8, 0, 0xFFFFFFFF);
  LOBYTE(v33) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&v27);
  v9 = 0;
  v10 = &this->txWheels[0].fileName;
  do
  {
    *(_DWORD *)v26.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v26.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v26.gap68);
    LOBYTE(retaddr) = 6;
    v2 |= 1u;
    *(_DWORD *)v26.gap0 = v2;
    std::wiostream::basic_iostream<wchar_t>(&v26.gap0[4], &v26.gap10[12], 0);
    v32 = 7;
    *(int *)((char *)&v25 + *(_DWORD *)(v25 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v24 + *(_DWORD *)(v25 + 4)) = *(_DWORD *)(v25 + 4) - 104;
    std::wstreambuf::wstreambuf(&v26.gap10[4]);
    *(_DWORD *)&v26.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v26.gap10[60] = 0;
    *(_DWORD *)&v26.gap10[64] = 0;
    LOBYTE(v32) = 9;
    *(_QWORD *)&v27.fileName._Bx._Alias[8] = 0x700000000i64;
    *(_WORD *)&v26.gap68[68] = 0;
    std::wstring::assign((std::wstring *)&v26.gap68[68], L"content/cars/", 0xDu);
    v11 = this->car;
    LOBYTE(v32) = 10;
    v22 = &v11->unixName;
    v12 = std::operator<<<wchar_t>((std::wostream *)((char *)&v26._Chcount + 4), (const std::wstring *)&v26.gap68[68]);
    v13 = std::operator<<<wchar_t>(v12, v22);
    v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, L"/tyre_");
    v15 = (std::wostream *)std::wostream::operator<<(v14, v9);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, v23);
    LOBYTE(v33) = 9;
    if ( v27.fileName._Mysize >= 8 )
      operator delete(v27.kid);
    v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &v26,
            (std::wstring *)&v27);
    v17 = this->game;
    LOBYTE(v33) = 11;
    v18 = ResourceStore::getTexture(v17->graphics->resourceStore._Myptr, &v31, v16, 0);
    v19 = v18->kid;
    v20 = &v18->fileName;
    LOBYTE(v33) = 12;
    v10[-1]._Myres = (unsigned int)v19;
    if ( v10 != v20 )
      std::wstring::assign(v10, v20, 0, 0xFFFFFFFF);
    LOBYTE(v33) = 11;
    OnSetupAppCreated::~OnSetupAppCreated(&v31);
    if ( v27.fileName._Mysize >= 8 )
      operator delete(v27.kid);
    LOBYTE(v33) = 4;
    *(_DWORD *)&v26.gap0[*(_DWORD *)(*(_DWORD *)v26.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v25 + *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v26.gap0 + 4) - 104;
    *(_DWORD *)&v26.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v26.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v26.gap10[8]) )
        std::wstreambuf::epptr(&v26.gap10[8]);
      else
        std::wstreambuf::egptr(&v26.gap10[8]);
      std::wstreambuf::eback(&v26.gap10[8]);
      v21 = std::wstreambuf::eback(&v26.gap10[8]);
      operator delete(v21);
    }
    std::wstreambuf::setg(&v26.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v26.gap10[8], 0, 0);
    *(_DWORD *)&v26.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v26.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v26.gap68);
    ++v9;
    v10 = (std::wstring *)((char *)v10 + 28);
  }
  while ( v9 < 4 );
  if ( loadname._Myres >= 8 )
    operator delete(loadname._Bx._Ptr);
}
void CarFakeShadow::onNodeRenderEvent(CarFakeShadow *this, const OnNodeRenderEvent *e)
{
  GLRenderer *v3; // edi
  float v4; // xmm7_4
  float v5; // xmm5_4
  CarAvatar *v6; // esi
  float *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float *v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float *v16; // eax
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  int v24; // esi
  CarFakeShadow *v25; // eax
  CarAvatar *v26; // ecx
  __m128 v27; // xmm5
  float v28; // xmm6_4
  __m128 v29; // xmm0
  float v30; // xmm1_4
  float v31; // xmm7_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  Game *v46; // ecx
  CarFakeShadow *v47; // esi
  mat44f matrix; // [esp+14h] [ebp-108h] BYREF
  mat44f v49; // [esp+54h] [ebp-C8h] BYREF
  float v50[3]; // [esp+94h] [ebp-88h] BYREF
  float v51[3]; // [esp+A0h] [ebp-7Ch] BYREF
  float v52[2]; // [esp+ACh] [ebp-70h] BYREF
  float v53; // [esp+B4h] [ebp-68h]
  float v[3]; // [esp+B8h] [ebp-64h] BYREF
  vec3f result; // [esp+C4h] [ebp-58h] BYREF
  float v56; // [esp+D0h] [ebp-4Ch]
  float v57; // [esp+D4h] [ebp-48h]
  vec3f v58; // [esp+D8h] [ebp-44h] BYREF
  vec3f org; // [esp+E4h] [ebp-38h] BYREF
  vec3f v60; // [esp+F0h] [ebp-2Ch] BYREF
  vec3f v61; // [esp+FCh] [ebp-20h] BYREF
  Texture *tex; // [esp+108h] [ebp-14h]
  vec3f dir; // [esp+10Ch] [ebp-10h] BYREF
  CarFakeShadow *v64; // [esp+118h] [ebp-4h]
  const OnNodeRenderEvent *ea; // [esp+120h] [ebp+4h]

  v64 = this;
  if ( e->renderContext->meshFilter->passID == Opaque
    && CarAvatar::isConnected(this->car)
    && !e->renderContext->camera->isCubeMapCamera )
  {
    v3 = this->localGL;
    GLRenderer::begin(v3, eQuads, this->shFakeCarShadows);
    GLRenderer::color3f(v3, 3.0, 0.0, 3.0);
    mat44f::mat44f(&matrix);
    mat44f::loadIdentity(&matrix);
    GraphicsManager::setWorldMatrix(this->game->graphics, &matrix);
    GraphicsManager::setTexture(this->game->graphics, 0, &this->txBody);
    GraphicsManager::setDepthMode(this->game->graphics, eDepthNoWrite);
    GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
    GraphicsManager::setCullMode(this->game->graphics, eCullFront);
    v4 = this->width;
    v5 = this->length;
    v6 = this->car;
    v7 = (float *)v6->bodyTransform;
    org.x = 0.0;
    org.y = 0.0;
    org.z = 0.0;
    v8 = (float)((float)((float)(v7[2] * COERCE_FLOAT(LODWORD(v4) ^ _xmm)) + (float)(v7[6] * 0.0))
               + (float)(v7[10] * COERCE_FLOAT(LODWORD(v5) ^ _xmm)))
       + v7[14];
    v9 = (float)((float)((float)(v7[3] * COERCE_FLOAT(LODWORD(v4) ^ _xmm)) + (float)(v7[7] * 0.0))
               + (float)(v7[11] * COERCE_FLOAT(LODWORD(v5) ^ _xmm)))
       + v7[15];
    org.x = (float)((float)((float)(COERCE_FLOAT(LODWORD(v4) ^ _xmm) * v7[1]) + (float)(v7[5] * 0.0))
                  + (float)(v7[9] * COERCE_FLOAT(LODWORD(v5) ^ _xmm)))
          + v7[13];
    org.y = v8;
    org.z = v9;
    v10 = (float *)v6->bodyTransform;
    v58.x = 0.0;
    v58.y = 0.0;
    v58.z = 0.0;
    v11 = (float)((float)((float)(v10[2] * COERCE_FLOAT(LODWORD(v4) ^ _xmm)) + (float)(v10[6] * 0.0))
                + (float)(v10[10] * v5))
        + v10[14];
    v12 = (float)((float)((float)(v10[3] * COERCE_FLOAT(LODWORD(v4) ^ _xmm)) + (float)(v10[7] * 0.0))
                + (float)(v10[11] * v5))
        + v10[15];
    v58.x = (float)((float)((float)(COERCE_FLOAT(LODWORD(v4) ^ _xmm) * v10[1]) + (float)(v10[5] * 0.0))
                  + (float)(v10[9] * v5))
          + v10[13];
    v58.y = v11;
    v58.z = v12;
    v13 = (float *)v6->bodyTransform;
    v60.x = 0.0;
    v60.y = 0.0;
    v60.z = 0.0;
    v14 = (float)((float)((float)(v13[2] * v4) + (float)(v13[6] * 0.0)) + (float)(v13[10] * v5)) + v13[14];
    v15 = (float)((float)((float)(v13[3] * v4) + (float)(v13[7] * 0.0)) + (float)(v13[11] * v5)) + v13[15];
    v60.x = (float)((float)((float)(v4 * v13[1]) + (float)(v13[5] * 0.0)) + (float)(v13[9] * v5)) + v13[13];
    v60.y = v14;
    v60.z = v15;
    v16 = (float *)v6->bodyTransform;
    v61.x = 0.0;
    v61.y = 0.0;
    v61.z = 0.0;
    v17 = (float)((float)(v16[1] * v4) + (float)(v16[5] * 0.0)) + (float)(v16[9] * COERCE_FLOAT(LODWORD(v5) ^ _xmm));
    v6 = (CarAvatar *)((char *)v6 + 2288);
    v18 = v16[2];
    v19 = v16[3];
    v20 = v16[6] * 0.0;
    dir.x = 0.0;
    v21 = v17 + v16[13];
    dir.y = -1.0;
    dir.z = 0.0;
    v22 = (float)((float)((float)(v18 * v4) + v20) + (float)(v16[10] * COERCE_FLOAT(LODWORD(v5) ^ _xmm))) + v16[14];
    v23 = (float)((float)((float)(v19 * v4) + (float)(v16[7] * 0.0))
                + (float)(v16[11] * COERCE_FLOAT(LODWORD(v5) ^ _xmm)))
        + v16[15];
    v61.x = v21;
    v61.y = v22;
    v61.z = v23;
    org.y = plane4f::getRayIntersection((plane4f *)v6, &result, &org, &dir)->y + 0.0099999998;
    v58.y = plane4f::getRayIntersection((plane4f *)v6, &result, &v58, &dir)->y + 0.0099999998;
    v60.y = plane4f::getRayIntersection((plane4f *)v6, &result, &v60, &dir)->y + 0.0099999998;
    v61.y = plane4f::getRayIntersection((plane4f *)v6, &result, &v61, &dir)->y + 0.0099999998;
    GLRenderer::texCoord2f(v3, 0.0, 1.0);
    GLRenderer::vertex3fv(v3, &org.x);
    GLRenderer::texCoord2f(v3, 0.0, 0.0);
    GLRenderer::vertex3fv(v3, &v58.x);
    GLRenderer::texCoord2f(v3, 1.0, 0.0);
    GLRenderer::vertex3fv(v3, &v60.x);
    GLRenderer::texCoord2f(v3, 1.0, 1.0);
    GLRenderer::vertex3fv(v3, &v61.x);
    GLRenderer::end(v3);
    v24 = 2088;
    ea = 0;
    v25 = v64;
    tex = v64->txWheels;
    while ( 1 )
    {
      GLRenderer::begin(v3, eQuads, v25->shFakeCarShadows);
      GraphicsManager::setTexture(v64->game->graphics, 0, tex);
      v26 = v64->car;
      *(__m128i *)&v49.M11 = _mm_loadu_si128((const __m128i *)((char *)&ea[62].renderContext + (_DWORD)v26));
      *(__m128i *)&v49.M21 = _mm_loadu_si128((const __m128i *)((char *)&ea[64].renderContext + (_DWORD)v26));
      *(__m128i *)&v49.M31 = _mm_loadu_si128((const __m128i *)((char *)&ea[66].renderContext + (_DWORD)v26));
      *(__m128i *)&v49.M41 = _mm_loadu_si128((const __m128i *)((char *)&ea[68].renderContext + (_DWORD)v26));
      v27 = _mm_xor_ps(_mm_shuffle_ps(*(__m128 *)&v49.M31, *(__m128 *)&v49.M31, 85), (__m128)(unsigned int)_xmm);
      LODWORD(v28) = _mm_shuffle_ps(*(__m128 *)&v49.M31, *(__m128 *)&v49.M31, 170).m128_u32[0] ^ _xmm;
      v29 = (__m128)*(unsigned int *)&v26->name._Bx._Buf[v24 / 2u];
      v30 = (float)((float)(*(float *)((char *)&v26->__vftable + v24) * COERCE_FLOAT(LODWORD(v49.M31) ^ _xmm))
                  + (float)(*(float *)((char *)&v26->game + v24) * v27.m128_f32[0]))
          + (float)(v29.m128_f32[0] * v28);
      v31 = COERCE_FLOAT(LODWORD(v49.M31) ^ _xmm) - (float)(*(float *)((char *)&v26->__vftable + v24) * v30);
      v32 = *(float *)&v26->name._Bx._Buf[v24 / 2u] * v30;
      v27.m128_f32[0] = v27.m128_f32[0] - (float)(*(float *)((char *)&v26->game + v24) * v30);
      v29.m128_f32[0] = v31;
      *(_QWORD *)&dir.x = _mm_unpacklo_ps(v29, v27).m128_u64[0];
      result.z = v28 - v32;
      dir.z = v28 - v32;
      v33 = fsqrt((float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v31 * v31)) + (float)(result.z * result.z));
      if ( v33 == 0.0 )
      {
        v36 = dir.z;
        v35 = dir.y;
        v34 = dir.x;
      }
      else
      {
        v34 = (float)(1.0 / v33) * v31;
        v35 = (float)(1.0 / v33) * dir.y;
        v36 = (float)(1.0 / v33) * dir.z;
      }
      v37 = *(float *)&v26->name._Bx._Buf[v24 / 2u];
      v38 = *(float *)((char *)&v26->game + v24);
      v57 = *(float *)((char *)&ea[68].renderContext + (_DWORD)v26);
      v56 = *(float *)((char *)&ea[69].renderContext + (_DWORD)v26);
      v39 = (float)(v37 * v35) - (float)(v38 * v36);
      v40 = *(float *)((char *)&v26->__vftable + v24);
      v41 = (float)(v38 * v34) - (float)(v40 * v35);
      v42 = (float)(v40 * v36) - (float)(v37 * v34);
      v43 = fsqrt((float)((float)(v42 * v42) + (float)(v39 * v39)) + (float)(v41 * v41));
      if ( v43 != 0.0 )
      {
        v39 = (float)(1.0 / v43) * v39;
        v44 = 1.0 / v43;
        v42 = v42 * v44;
        v41 = v44 * v41;
      }
      LODWORD(v49.M31) = LODWORD(v34) ^ _xmm;
      LODWORD(v49.M32) = LODWORD(v35) ^ _xmm;
      LODWORD(v49.M33) = LODWORD(v36) ^ _xmm;
      LODWORD(v49.M21) = *(CarAvatar_vtbl **)((char *)&v26->__vftable + v24);
      LODWORD(v49.M22) = *(Game **)((char *)&v26->game + v24);
      v49.M23 = *(float *)&v26->name._Bx._Buf[v24 / 2u];
      v49.M11 = v39;
      v49.M12 = v42;
      v49.M13 = v41;
      v45 = *(float *)((char *)v26 + v24 - 44);
      v46 = v64->game;
      v49.M42 = v45;
      v49.M41 = v57;
      v49.M43 = v56;
      GraphicsManager::setWorldMatrix(v46->graphics, &v49);
      GLRenderer::texCoord2f(v3, 0.0, 1.0);
      v[1] = 0.0099999998;
      LODWORD(v[0]) = LODWORD(v64->tyreSideSize) ^ _xmm;
      v[2] = v[0];
      GLRenderer::vertex3fv(v3, v);
      GLRenderer::texCoord2f(v3, 0.0, 0.0);
      v52[1] = 0.0099999998;
      v53 = v64->tyreSideSize;
      LODWORD(v52[0]) = LODWORD(v53) ^ _xmm;
      GLRenderer::vertex3fv(v3, v52);
      GLRenderer::texCoord2f(v3, 1.0, 0.0);
      v51[1] = 0.0099999998;
      v51[0] = v64->tyreSideSize;
      v51[2] = v51[0];
      GLRenderer::vertex3fv(v3, v51);
      GLRenderer::texCoord2f(v3, 1.0, 1.0);
      v50[1] = 0.0099999998;
      v50[0] = v64->tyreSideSize;
      LODWORD(v50[2]) = LODWORD(v50[0]) ^ _xmm;
      GLRenderer::vertex3fv(v3, v50);
      GLRenderer::end(v3);
      ++tex;
      v24 += 12;
      ea += 8;
      if ( v24 >= 2136 )
        break;
      v25 = v64;
    }
    v47 = v64;
    GraphicsManager::setDepthMode(v64->game->graphics, eDepthNormal);
    GraphicsManager::setCullMode(v47->game->graphics, eCullFront);
  }
}
