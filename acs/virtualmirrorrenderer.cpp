#include "virtualmirrorrenderer.h"
void VirtualMirrorRenderer::VirtualMirrorRenderer(VirtualMirrorRenderer *this, Sim *aSim)
{
  unsigned int v3; // ebx
  Node *v4; // edi
  Node *v5; // eax
  Event<float> *v6; // ecx
  Sim *v7; // eax
  Node *v8; // eax
  bool v9; // al
  std::wstring v10; // [esp-1Ch] [ebp-C8h] BYREF
  int v11; // [esp-4h] [ebp-B0h]
  int v12; // [esp+18h] [ebp-94h]
  unsigned int v13; // [esp+1Ch] [ebp-90h]
  Node *v14; // [esp+20h] [ebp-8Ch]
  VirtualMirrorRenderer *v15; // [esp+24h] [ebp-88h]
  std::wstring n; // [esp+28h] [ebp-84h] BYREF
  std::wstring key; // [esp+40h] [ebp-6Ch] BYREF
  INIReaderDocuments acINI; // [esp+58h] [ebp-54h] BYREF
  int v19; // [esp+A8h] [ebp-4h]

  v3 = 0;
  v13 = 0;
  v15 = this;
  v11 = (int)aSim->game;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"VIRTUAL_MIRROR_RENDERER", 0x17u);
  GameObject::GameObject(this, v10, (Game *)v11);
  v19 = 0;
  this->__vftable = (VirtualMirrorRenderer_vtbl *)&VirtualMirrorRenderer::`vftable';
  this->sim = aSim;
  Trigger::Trigger(&this->keyboardTrigger);
  v11 = 188;
  LOBYTE(v19) = 1;
  this->tripleScreenPassesCount = 0;
  v4 = (Node *)operator new(v11);
  v14 = v4;
  v5 = 0;
  LOBYTE(v19) = 2;
  if ( v4 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"VIRTUAL_MIRROR", 0xEu);
    LOBYTE(v19) = 3;
    v3 = 1;
    v13 = 1;
    Node::Node(v4, &n);
  }
  this->nodeVirtualMirror = v5;
  v19 = 1;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  aSim->rootNode->addChild(aSim->rootNode, this->nodeVirtualMirror);
  v11 = (int)this;
  v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_d97c1dc3acfaa796a0b08d1aa97a84ae_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v10._Bx._Alias[4] = this;
  v10._Mysize = (unsigned int)&v10;
  v6 = &this->game->evOnPreGUI;
  LOBYTE(v19) = 1;
  Event<float>::addHandler((Event<SessionInfo> *)v6, (std::function<void __cdecl(SessionInfo const &)>)v10, this);
  v7 = this->sim;
  if ( !v7->isVirtualMirrorForced || v7->isVrConnected )
  {
    v8 = this->nodeVirtualMirror;
    v11 = 0;
    v8->isActive = 0;
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, L"cfg/gameplay.ini", 0x10u);
    INIReaderDocuments::INIReaderDocuments(&acINI, v3, v10, v11);
    LOBYTE(v19) = 6;
    if ( !acINI.ready )
      goto LABEL_11;
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"VIRTUAL_MIRROR", 0xEu);
    LOBYTE(v19) = 7;
    v3 |= 2u;
    v13 = v3;
    v9 = INIReader::hasSection(&acINI, &n);
    HIBYTE(v12) = 1;
    if ( !v9 )
LABEL_11:
      HIBYTE(v12) = 0;
    v19 = 6;
    if ( (v3 & 2) != 0 && n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
    if ( HIBYTE(v12) )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"ACTIVE", 6u);
      LOBYTE(v19) = 8;
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"VIRTUAL_MIRROR", 0xEu);
      LOBYTE(v19) = 9;
      this->nodeVirtualMirror->isActive = INIReader::getInt(&acINI, &n, &key) != 0;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    LOBYTE(v19) = 1;
    INIReaderDocuments::~INIReaderDocuments(&acINI);
  }
  else
  {
    this->nodeVirtualMirror->isActive = 1;
  }
}
VirtualMirrorRenderer *VirtualMirrorRenderer::`vector deleting destructor'(VirtualMirrorRenderer *this, unsigned int a2)
{
  this->__vftable = (VirtualMirrorRenderer_vtbl *)&VirtualMirrorRenderer::`vftable';
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->keyboardTrigger);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void VirtualMirrorRenderer::renderVirtualMirror(VirtualMirrorRenderer *this, float dt)
{
  GraphicsManager *v3; // ecx
  GLRenderer *v4; // edi
  float x; // [esp+14h] [ebp-Ch]
  float xa; // [esp+14h] [ebp-Ch]
  float y; // [esp+18h] [ebp-8h]
  float ya; // [esp+18h] [ebp-8h]
  float v9; // [esp+1Ch] [ebp-4h]

  if ( ACCameraManager::isVirtualMirrorOn(this->sim->cameraManager) )
  {
    GraphicsManager::setDepthMode(this->game->graphics, eDepthOff);
    GraphicsManager::setScreenSpaceMode(this->game->graphics);
    y = (float)((float)this->game->graphics->videoSettings.height * 0.00092592591) * 128.0;
    v9 = (float)(y * 0.0078125) * 512.0;
    x = (float)((float)this->game->graphics->videoSettings.width - v9) * 0.5;
    GraphicsManager::setBlendMode(this->game->graphics, eOpaque);
    GraphicsManager::setCullMode(this->game->graphics, eCullNone);
    v3 = this->game->graphics;
    v4 = v3->gl;
    GraphicsManager::clearTextureSlot(v3, 0);
    GraphicsManager::setTexture(this->game->graphics, 0, &this->sim->mirrorTextureRenderer->texture);
    if ( this->game->graphics->videoSettings.ppHDREnabled )
      GLRenderer::color3f(v4, 0.30000001, 0.30000001, 0.30000001);
    else
      GLRenderer::color3f(v4, 1.0, 1.0, 1.0);
    GLRenderer::begin(v4, eQuads, 0);
    GLRenderer::texCoord2f(v4, 1.0, 0.0);
    GLRenderer::vertex3f(v4, x, 85.0, 0.0);
    GLRenderer::texCoord2f(v4, 1.0, 1.0);
    ya = y + 85.0;
    GLRenderer::vertex3f(v4, x, ya, 0.0);
    GLRenderer::texCoord2f(v4, 0.0, 1.0);
    xa = x + v9;
    GLRenderer::vertex3f(v4, xa, ya, 0.0);
    GLRenderer::texCoord2f(v4, 0.0, 0.0);
    GLRenderer::vertex3f(v4, xa, 85.0, 0.0);
    GLRenderer::end(v4);
    GraphicsManager::clearTextureSlot(this->game->graphics, 0);
  }
}
void VirtualMirrorRenderer::shutdown(VirtualMirrorRenderer *this)
{
  Sim *v2; // eax
  std::wstring *v3; // eax
  std::wstring path; // [esp+8h] [ebp-28h] BYREF
  int v5; // [esp+2Ch] [ebp-4h]

  v2 = this->sim;
  if ( !v2->isVirtualMirrorForced || v2->isVrConnected )
  {
    Path::getDocumentPath(&path);
    v5 = 0;
    std::wstring::append(&path, L"/Assetto Corsa/cfg/gameplay.ini", 0x1Fu);
    v3 = &path;
    if ( this->nodeVirtualMirror->isActive )
    {
      if ( path._Myres >= 8 )
        v3 = (std::wstring *)path._Bx._Ptr;
      WritePrivateProfileStringW(L"VIRTUAL_MIRROR", L"ACTIVE", L"1", v3->_Bx._Buf);
    }
    else
    {
      if ( path._Myres >= 8 )
        v3 = (std::wstring *)path._Bx._Ptr;
      WritePrivateProfileStringW(L"VIRTUAL_MIRROR", L"ACTIVE", L"0", v3->_Bx._Buf);
    }
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
  }
}
void VirtualMirrorRenderer::update(VirtualMirrorRenderer *this, float dt)
{
  SHORT v3; // ax
  Sim *v4; // eax
  const std::wstring *v5; // esi
  const std::wstring *v6; // eax
  SystemMessage *v7; // ecx
  const std::wstring *v8; // esi
  const std::wstring *v9; // eax
  SystemMessage *v10; // ecx
  const std::wstring *v11; // esi
  const std::wstring *v12; // eax
  SystemMessage *v13; // ecx
  std::wstring v14; // [esp+Ch] [ebp-D0h] BYREF
  std::wstring v15; // [esp+24h] [ebp-B8h] BYREF
  std::wstring v16; // [esp+3Ch] [ebp-A0h] BYREF
  std::wstring v17; // [esp+54h] [ebp-88h] BYREF
  std::wstring text; // [esp+6Ch] [ebp-70h] BYREF
  std::wstring v19; // [esp+84h] [ebp-58h] BYREF
  std::wstring v20; // [esp+9Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+B4h] [ebp-28h] BYREF
  int v22; // [esp+D8h] [ebp-4h]

  v3 = GetAsyncKeyState(122);
  if ( Trigger::ignoreSubsequentTrue(&this->keyboardTrigger, v3 != 0) )
  {
    v4 = this->sim;
    if ( !v4->isVrConnected )
    {
      if ( v4->isVirtualMirrorForced )
      {
        this->nodeVirtualMirror->isActive = 1;
        std::wstring::wstring(&text, L"Virtual Mirror is forced ON by the Server");
        v22 = 8;
        std::wstring::wstring(&v19, L"VIRTUAL MIRROR");
        LOBYTE(v22) = 9;
        v5 = acTranslate(&result.name, &text);
        LOBYTE(v22) = 10;
        v6 = acTranslate(&v20, &v19);
        v7 = this->sim->systemMessage;
        LOBYTE(v22) = 11;
        SystemMessage::addMessage(v7, v6, v5, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v20);
        std::wstring::~wstring(&result);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v19);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      }
      else
      {
        this->nodeVirtualMirror->isActive = !this->nodeVirtualMirror->isActive;
        if ( this->nodeVirtualMirror->isActive )
        {
          std::wstring::wstring(&v17, L"ON");
          v22 = 0;
          std::wstring::wstring(&v14, L"VIRTUAL MIRROR");
          LOBYTE(v22) = 1;
          v8 = acTranslate(&v16, &v17);
          LOBYTE(v22) = 2;
          v9 = acTranslate(&v15, &v14);
          v10 = this->sim->systemMessage;
          LOBYTE(v22) = 3;
          SystemMessage::addMessage(v10, v9, v8, eDefault);
          if ( v15._Myres >= 8 )
            operator delete(v15._Bx._Ptr);
          v15._Myres = 7;
          v15._Mysize = 0;
          v15._Bx._Buf[0] = 0;
          if ( v16._Myres >= 8 )
            operator delete(v16._Bx._Ptr);
          v16._Myres = 7;
          v16._Mysize = 0;
          v16._Bx._Buf[0] = 0;
        }
        else
        {
          std::wstring::wstring(&v17, L"OFF");
          v22 = 4;
          std::wstring::wstring(&v14, L"VIRTUAL MIRROR");
          LOBYTE(v22) = 5;
          v11 = acTranslate(&v15, &v17);
          LOBYTE(v22) = 6;
          v12 = acTranslate(&v16, &v14);
          v13 = this->sim->systemMessage;
          LOBYTE(v22) = 7;
          SystemMessage::addMessage(v13, v12, v11, eDefault);
          if ( v16._Myres >= 8 )
            operator delete(v16._Bx._Ptr);
          v16._Myres = 7;
          v16._Mysize = 0;
          v16._Bx._Buf[0] = 0;
          if ( v15._Myres >= 8 )
            operator delete(v15._Bx._Ptr);
          v15._Myres = 7;
          v15._Mysize = 0;
          v15._Bx._Buf[0] = 0;
        }
        if ( v14._Myres >= 8 )
          operator delete(v14._Bx._Ptr);
        v14._Myres = 7;
        v14._Bx._Buf[0] = 0;
        v14._Mysize = 0;
        if ( v17._Myres >= 8 )
          operator delete(v17._Bx._Ptr);
      }
    }
  }
}
