#include "game.h
void __userpurge Game::Game(Game *this@<ecx>, __m128 a2@<xmm1>, std::wstring name, VideoSettings *videoSettings)
{
  VideoSettings *v5; // edi
  char v6; // bl
  GraphicsManager *v7; // eax
  GraphicsManager *v8; // eax
  ksgui::GUI *v9; // edi
  ksgui::GUI *v10; // eax
  AudioEngine *v11; // eax
  AudioEngine *v12; // eax
  float v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4
  GameObject *v16; // edi
  GameObject *v17; // eax
  ksgui::GUI *v18; // ecx
  double v19; // st7
  bool v20; // cf
  std::wstring v21; // [esp-18h] [ebp-12Ch] BYREF
  float volume; // [esp+0h] [ebp-114h]
  int v23; // [esp+20h] [ebp-F4h]
  bool v24; // [esp+27h] [ebp-EDh]
  void *v25; // [esp+28h] [ebp-ECh]
  VideoSettings *v26; // [esp+2Ch] [ebp-E8h]
  Game *v27; // [esp+30h] [ebp-E4h]
  std::wstring section; // [esp+34h] [ebp-E0h] BYREF
  std::wstring key; // [esp+4Ch] [ebp-C8h] BYREF
  std::wstring ifilename; // [esp+64h] [ebp-B0h] BYREF
  INIReader ini; // [esp+7Ch] [ebp-98h] BYREF
  INIReaderDocuments audioIni; // [esp+C0h] [ebp-54h] BYREF
  int v33; // [esp+110h] [ebp-4h]

  v5 = videoSettings;
  v6 = 0;
  v27 = this;
  v26 = videoSettings;
  *(float *)&v23 = 0.0;
  v33 = 0;
  this->__vftable = (Game_vtbl *)&Game::`vftable';
  *(_WORD *)&this->isRenderingGui = 257;
  this->isSuppressingAudioUpdate = 0;
  GameTime::GameTime(&this->gameTime);
  LODWORD(volume) = v5;
  LOBYTE(v33) = 1;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, &name, 0, 0xFFFFFFFF);
  RenderWindow::RenderWindow(&this->window, v21, (VideoSettings *)LODWORD(volume));
  this->masterVolume = 1.0;
  this->audioEngine = 0;
  LOBYTE(v33) = 2;
  LODWORD(volume) = &this->window;
  this->stats.renderAudioTime = 0.0;
  *(_OWORD *)&this->stats.cpuTime = 0i64;
  *(_OWORD *)&this->stats.renderHUDTime = 0i64;
  KeyboardManager::KeyboardManager(&this->keyboardManager, (RenderWindow *)LODWORD(volume));
  LOBYTE(v33) = 3;
  JoypadManager::JoypadManager(&this->joypadManager);
  this->evOnPreGUI.handlers._Myfirst = 0;
  this->evOnPreGUI.handlers._Mylast = 0;
  this->evOnPreGUI.handlers._Myend = 0;
  this->evOnPostGui.handlers._Myfirst = 0;
  this->evOnPostGui.handlers._Mylast = 0;
  this->evOnPostGui.handlers._Myend = 0;
  this->evOnRenderFinished.handlers._Myfirst = 0;
  this->evOnRenderFinished.handlers._Mylast = 0;
  this->evOnRenderFinished.handlers._Myend = 0;
  this->evOnPostUpdate.handlers._Myfirst = 0;
  this->evOnPostUpdate.handlers._Mylast = 0;
  this->evOnPostUpdate.handlers._Myend = 0;
  this->evOnBeginFrame.handlers._Myfirst = 0;
  this->evOnBeginFrame.handlers._Mylast = 0;
  this->evOnBeginFrame.handlers._Myend = 0;
  this->evOnEndFrame.handlers._Myfirst = 0;
  this->evOnEndFrame.handlers._Mylast = 0;
  this->evOnEndFrame.handlers._Myend = 0;
  this->evOnShutdownRequested.handlers._Myfirst = 0;
  this->evOnShutdownRequested.handlers._Mylast = 0;
  this->evOnShutdownRequested.handlers._Myend = 0;
  LOBYTE(v33) = 11;
  this->isClosing = 0;
  ksInitTimer();
  *(float *)&v7 = COERCE_FLOAT(operator new(888));
  v23 = (int)v7;
  LOBYTE(v33) = 12;
  if ( *(float *)&v7 == 0.0 )
    v8 = 0;
  else
    GraphicsManager::GraphicsManager(v7, a2, v5);
  LODWORD(volume) = 256;
  LOBYTE(v33) = 11;
  this->graphics = v8;
  *(float *)&v9 = COERCE_FLOAT(operator new(LODWORD(volume)));
  v23 = (int)v9;
  v10 = 0;
  LOBYTE(v33) = 13;
  if ( *(float *)&v9 != 0.0 )
  {
    LODWORD(volume) = &this->keyboardManager;
    v21._Mysize = 0;
    v21._Myres = 7;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, &name, 0, 0xFFFFFFFF);
    ksgui::GUI::GUI(v9, this->graphics, v21, (KeyboardManager *)LODWORD(volume));
  }
  this->gui = v10;
  LOBYTE(v33) = 11;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/audio_engine.ini", 0x1Bu);
  LOBYTE(v33) = 14;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v33) = 16;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( !ini.ready )
    _printf("ERROR: system/cfg/audio_engine.ini not found\n");
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ENABLE_AUDIO", 0xCu);
  LOBYTE(v33) = 17;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SETTINGS", 8u);
  LOBYTE(v33) = 18;
  v24 = INIReader::getInt(&ini, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v33) = 16;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v24 || !ini.ready )
  {
    v11 = (AudioEngine *)operator new(72);
    v25 = v11;
    LOBYTE(v33) = 19;
    if ( v11 )
      AudioEngine::AudioEngine(v11, 0);
    else
      v12 = 0;
    LOBYTE(v33) = 16;
    this->audioEngine = v12;
  }
  volume = 0.0;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"cfg/audio.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&audioIni, 0, v21, SLOBYTE(volume));
  LOBYTE(v33) = 20;
  if ( audioIni.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MASTER", 6u);
    LOBYTE(v33) = 21;
    v23 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"LEVELS", 6u);
    v33 = 22;
    v6 = 3;
    v23 = 3;
    v14 = FLOAT_1_0;
    *(float *)&v23 = INIReader::getFloat(&audioIni, &section, &key);
    if ( *(float *)&v23 <= 1.0 )
    {
      v14 = 0.0;
      if ( *(float *)&v23 >= 0.0 )
        v14 = *(float *)&v23;
    }
  }
  else
  {
    v14 = FLOAT_1_0;
  }
  this->masterVolume = v14;
  if ( (v6 & 2) != 0 )
  {
    v6 &= 0xFDu;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v33 = 20;
  if ( (v6 & 1) != 0 && key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v15 = this->masterVolume;
  volume = v13;
  AudioEngine::setVolume(this->audioEngine, (int)this, v15);
  ksgui::GUI::setAudioEngine(this->gui, this->audioEngine);
  LOBYTE(v33) = 16;
  INIReaderDocuments::~INIReaderDocuments(&audioIni);
  LOBYTE(v33) = 11;
  INIReader::~INIReader(&ini);
  v16 = (GameObject *)operator new(52);
  v25 = v16;
  v17 = 0;
  LOBYTE(v33) = 23;
  if ( v16 )
  {
    LODWORD(volume) = this;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"ROOT", 4u);
    GameObject::GameObject(v16, v21, (Game *)LODWORD(volume));
  }
  LODWORD(volume) = this;
  this->root = v17;
  this->isClosing = 0;
  v21._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_1538a204a34bca24117e69238147887a_,0>,std::allocator<std::_Func_class<void,OnWindowClosedEvent const &>>,void,OnWindowClosedEvent const &>::`vftable';
  *(_DWORD *)&v21._Bx._Alias[4] = this;
  v21._Mysize = (unsigned int)&v21;
  LOBYTE(v33) = 11;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->window.evOnWindowClosed,
    (std::function<void __cdecl(SessionInfo const &)>)v21,
    (void *)LODWORD(volume));
  v21._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_18a35724c70df2be12f164aa2efd390e_,0>,std::allocator<std::_Func_class<void,OnWindowResizeEvent const &>>,void,OnWindowResizeEvent const &>::`vftable';
  *(_DWORD *)&v21._Bx._Alias[4] = this;
  v21._Mysize = (unsigned int)&v21;
  LOBYTE(v33) = 11;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->window.evOnWindowResize,
    (std::function<void __cdecl(SessionInfo const &)>)v21,
    this);
  v18 = this->gui;
  LODWORD(volume) = &this->window;
  this->sleepTime = 0;
  ksgui::GUI::attachToRenderWindowEvents(v18, (RenderWindow *)LODWORD(volume));
  this->gameTime.cappedFPS = v26->fpsCapMS;
  v19 = ksGetTime();
  v20 = name._Myres < 8;
  this->gameTime.startTime = v19;
  if ( !v20 )
    operator delete(name._Bx._Ptr);
}
void Game::~Game(Game *this)
{
  GameObject *v2; // ebp
  GameObject **i; // esi
  ksgui::GUI *v4; // ecx
  AudioEngine *v5; // esi
  GraphicsManager *v6; // ecx
  std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **v7; // esi
  Task **v8; // esi
  Task **v9; // esi
  Task **v10; // esi
  Task **v11; // esi
  Task **v12; // esi
  Task **v13; // esi
  GameObject *v14; // [esp-4h] [ebp-28h]

  this->__vftable = (Game_vtbl *)&Game::`vftable';
  v2 = this->root;
  for ( i = v2->gameObjects._Mylast; i != v2->gameObjects._Myfirst; --i )
  {
    v14 = *(i - 1);
    Game::deleteGameObjectRec(this, v14);
  }
  std::_Container_base0::_Orphan_all(&v2->gameObjects);
  v2->gameObjects._Mylast = v2->gameObjects._Myfirst;
  ((void (*)(GameObject *, int))v2->~GameObject)(v2, 1);
  v4 = this->gui;
  if ( v4 )
    ((void (*)(ksgui::GUI *, int))v4->~GUI)(v4, 1);
  v5 = this->audioEngine;
  if ( v5 )
  {
    AudioEngine::~AudioEngine(this->audioEngine);
    operator delete(v5);
  }
  v6 = this->graphics;
  if ( v6 )
    ((void (*)(GraphicsManager *, int))v6->~GraphicsManager)(v6, 1);
  ksShutdownTimer();
  v7 = (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **)&this->evOnShutdownRequested;
  if ( this->evOnShutdownRequested.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnShutdownRequested);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnShutdownRequested,
      *v7,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnShutdownRequested.handlers._Mylast);
    operator delete(*v7);
    *v7 = 0;
    this->evOnShutdownRequested.handlers._Mylast = 0;
    this->evOnShutdownRequested.handlers._Myend = 0;
  }
  v8 = (Task **)&this->evOnEndFrame;
  if ( this->evOnEndFrame.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnEndFrame);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnEndFrame,
      *v8,
      (Task *)this->evOnEndFrame.handlers._Mylast);
    operator delete(*v8);
    *v8 = 0;
    this->evOnEndFrame.handlers._Mylast = 0;
    this->evOnEndFrame.handlers._Myend = 0;
  }
  v9 = (Task **)&this->evOnBeginFrame;
  if ( this->evOnBeginFrame.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnBeginFrame);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnBeginFrame,
      *v9,
      (Task *)this->evOnBeginFrame.handlers._Mylast);
    operator delete(*v9);
    *v9 = 0;
    this->evOnBeginFrame.handlers._Mylast = 0;
    this->evOnBeginFrame.handlers._Myend = 0;
  }
  v10 = (Task **)&this->evOnPostUpdate;
  if ( this->evOnPostUpdate.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPostUpdate);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnPostUpdate,
      *v10,
      (Task *)this->evOnPostUpdate.handlers._Mylast);
    operator delete(*v10);
    *v10 = 0;
    this->evOnPostUpdate.handlers._Mylast = 0;
    this->evOnPostUpdate.handlers._Myend = 0;
  }
  v11 = (Task **)&this->evOnRenderFinished;
  if ( this->evOnRenderFinished.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnRenderFinished);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnRenderFinished,
      *v11,
      (Task *)this->evOnRenderFinished.handlers._Mylast);
    operator delete(*v11);
    *v11 = 0;
    this->evOnRenderFinished.handlers._Mylast = 0;
    this->evOnRenderFinished.handlers._Myend = 0;
  }
  v12 = (Task **)&this->evOnPostGui;
  if ( this->evOnPostGui.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPostGui);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnPostGui,
      *v12,
      (Task *)this->evOnPostGui.handlers._Mylast);
    operator delete(*v12);
    *v12 = 0;
    this->evOnPostGui.handlers._Mylast = 0;
    this->evOnPostGui.handlers._Myend = 0;
  }
  v13 = (Task **)&this->evOnPreGUI;
  if ( this->evOnPreGUI.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPreGUI);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnPreGUI,
      *v13,
      (Task *)this->evOnPreGUI.handlers._Mylast);
    operator delete(*v13);
    *v13 = 0;
    this->evOnPreGUI.handlers._Mylast = 0;
    this->evOnPreGUI.handlers._Myend = 0;
  }
  if ( this->joypadManager.joypad._Myptr )
    operator delete(this->joypadManager.joypad._Myptr);
  KeyboardManager::~KeyboardManager(&this->keyboardManager);
  RenderWindow::~RenderWindow(&this->window);
  GameTime::~GameTime(&this->gameTime);
}
Game *Game::`vector deleting destructor'(Game *this, unsigned int a2)
{
  Game::~Game(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Game::deleteGameObjectRec(Game *this, GameObject *go)
{
  GameObject **i; // esi
  GameObject *v4; // [esp-4h] [ebp-14h]

  for ( i = go->gameObjects._Mylast; i != go->gameObjects._Myfirst; --i )
  {
    v4 = *(i - 1);
    Game::deleteGameObjectRec(this, v4);
  }
  std::_Container_base0::_Orphan_all(&go->gameObjects);
  go->gameObjects._Mylast = go->gameObjects._Myfirst;
  ((void (*)(GameObject *, int))go->~GameObject)(go, 1);
}
void Game::onIdle(Game *this)
{
  TyreTester *v2; // ecx
  std::pair<void *,std::function<void __cdecl(double const &)> > *v3; // esi
  std::_Func_base<void,double const &> **v4; // ebx
  double v5; // st7
  unsigned int v6; // eax
  double v7; // st7
  unsigned int v8; // eax
  double v9; // st7
  unsigned int v10; // eax
  double v11; // st7
  unsigned int v12; // eax
  std::_Func_base<void,double const &> **v13; // ebx
  double tt3; // [esp+18h] [ebp-18h]
  double start; // [esp+20h] [ebp-10h]
  double starta; // [esp+20h] [ebp-10h]
  double start_update_time; // [esp+28h] [ebp-8h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( (_S4_0 & 1) == 0 )
  {
    perfCounter_17.name = "Game::onIdle";
    _S4_0 |= 1u;
    perfCounter_17.group = Render;
    perfCounter_17.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle" | 0xFF000000;
  }
  GameTime::update(&this->gameTime);
  v3 = this->evOnBeginFrame.handlers._Myfirst;
  if ( v3 != this->evOnBeginFrame.handlers._Mylast )
  {
    v4 = &v3->second._Impl;
    do
    {
      if ( !*v4 )
        goto LABEL_22;
      (*v4)->_Do_call(*v4, &this->gameTime.now);
      ++v3;
      v4 += 8;
    }
    while ( v3 != this->evOnBeginFrame.handlers._Mylast );
  }
  v3 = (std::pair<void *,std::function<void __cdecl(double const &)> > *)&this->gameTime.deltaT;
  if ( this->gameTime.deltaT <= 0.0 )
    goto LABEL_26;
  start_update_time = ksGetQPTTime();
  if ( (_S4_0 & 2) == 0 )
  {
    perfCounter_18.name = "Game::onIdle (update)";
    _S4_0 |= 2u;
    perfCounter_18.group = Render;
    perfCounter_18.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle (update)" | 0xFF000000;
  }
  Game::update(this, this->root, *(float *)&v3->first);
  Event<std::wstring>::trigger(
    (Event<OnGearRequestEvent> *)&this->evOnPostUpdate,
    (const OnGearRequestEvent *)&this->gameTime.deltaT);
  v5 = ksGetQPTTime();
  v6 = _S4_0;
  tt3 = v5;
  this->stats.updateTime = v5 - start_update_time;
  if ( (v6 & 4) == 0 )
  {
    perfCounter_19.name = "Game::onIdle (render)";
    _S4_0 = v6 | 4;
    perfCounter_19.group = Render;
    perfCounter_19.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle (render)" | 0xFF000000;
  }
  GraphicsManager::beginScene(this->graphics);
  Game::render(this, this->root, *(float *)&v3->first);
  v7 = ksGetQPTTime();
  v8 = _S4_0;
  start = v7;
  this->stats.renderTime = v7 - tt3;
  if ( (v8 & 8) == 0 )
  {
    perfCounter_20.name = "Game::onIdle (renderHUD)";
    _S4_0 = v8 | 8;
    perfCounter_20.group = Render;
    perfCounter_20.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle (renderHUD)" | 0xFF000000;
  }
  GraphicsManager::setScreenSpaceMode(this->graphics);
  Event<std::wstring>::trigger(
    (Event<OnGearRequestEvent> *)&this->evOnPreGUI,
    (const OnGearRequestEvent *)&this->gameTime.deltaT);
  if ( this->isRenderingGui )
  {
    ksgui::GUI::render(this->gui, *(float *)&v3->first);
    Game::renderHUD(this, this->root, *(float *)&v3->first);
  }
  Event<std::wstring>::trigger(
    (Event<OnGearRequestEvent> *)&this->evOnPostGui,
    (const OnGearRequestEvent *)&this->gameTime.deltaT);
  v9 = ksGetQPTTime();
  v10 = _S4_0;
  this->stats.renderHUDTime = v9 - start;
  this->stats.cpuTime = v9 - start_update_time;
  if ( (v10 & 0x10) == 0 )
  {
    perfCounter_21.name = "Game::onIdle (renderAudio)";
    _S4_0 = v10 | 0x10;
    perfCounter_21.group = Render;
    perfCounter_21.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle (renderAudio)" | 0xFF000000;
  }
  starta = ksGetQPTTime();
  Game::renderAudio(this, this->root, *(float *)&v3->first);
  AudioEngine::update(this->audioEngine, (int)&savedregs, (int)this, (float *)v3, *(const float *)&v3->first);
  v11 = ksGetQPTTime();
  v12 = _S4_0;
  this->stats.renderAudioTime = (float)(v11 - starta);
  if ( (v12 & 0x20) == 0 )
  {
    perfCounter_22.name = "Game::onIdle (postRender)";
    _S4_0 = v12 | 0x20;
    perfCounter_22.group = Render;
    perfCounter_22.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Game::onIdle (postRender)" | 0xFF000000;
  }
  if ( !this->isSwappingBuffer )
    goto $LN155_2;
  GraphicsManager::endScene(this->graphics);
  while ( 1 )
  {
    if ( this->sleepTime != -1 )
      ksSleep(this->sleepTime);
LABEL_26:
    v3 = this->evOnEndFrame.handlers._Myfirst;
    if ( v3 == this->evOnEndFrame.handlers._Mylast )
      break;
    v13 = &v3->second._Impl;
    while ( *v13 )
    {
      (*v13)->_Do_call(*v13, &this->gameTime.now);
      ++v3;
      v13 += 8;
      if ( v3 == this->evOnEndFrame.handlers._Mylast )
        goto LABEL_30;
    }
LABEL_22:
    std::_Xbad_function_call();
$LN155_2:
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnRenderFinished, (const OnGearRequestEvent *)v3);
  }
LABEL_30:
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(v2);
}
void Game::render(Game *this, GameObject *o, float dt)
{
  GameObject **i; // esi

  if ( o->isActive )
  {
    ((void (*)(GameObject *, _DWORD))o->render)(o, LODWORD(dt));
    for ( i = o->gameObjects._Myfirst; i != o->gameObjects._Mylast; ++i )
      Game::render(this, *i, dt);
  }
}
void Game::renderAudio(Game *this, GameObject *o, float dt)
{
  GameObject **i; // esi

  if ( o->isActive )
  {
    ((void (*)(GameObject *, _DWORD))o->renderAudio)(o, LODWORD(dt));
    for ( i = o->gameObjects._Myfirst; i != o->gameObjects._Mylast; ++i )
      Game::renderAudio(this, *i, dt);
  }
}
void Game::renderHUD(Game *this, GameObject *o, float dt)
{
  GameObject **i; // esi

  if ( o->isActive )
  {
    ((void (*)(GameObject *, _DWORD))o->renderHUD)(o, LODWORD(dt));
    for ( i = o->gameObjects._Myfirst; i != o->gameObjects._Mylast; ++i )
      Game::renderHUD(this, *i, dt);
  }
}
void Game::renderHUDOnDemand(Game *this, float dt)
{
  GameObject *v3; // edi
  GameObject **i; // esi

  v3 = this->root;
  if ( v3->isActive )
  {
    ((void (*)(GameObject *, _DWORD))v3->renderHUD)(v3, LODWORD(dt));
    for ( i = v3->gameObjects._Myfirst; i != v3->gameObjects._Mylast; ++i )
      Game::renderHUD(this, *i, dt);
  }
}
void Game::run(Game *this)
{
  std::pair<void *,std::function<void __cdecl(int const &)> > *v2; // esi
  std::_Func_base<void,int const &> **v3; // ebx
  GameObject *v4; // ebx
  GameObject **i; // esi
  int v6; // [esp+10h] [ebp-4h] BYREF

  while ( RenderWindow::step(&this->window) )
  {
    if ( this->isClosing )
    {
      v2 = this->evOnShutdownRequested.handlers._Myfirst;
      v6 = 0;
      if ( v2 != this->evOnShutdownRequested.handlers._Mylast )
      {
        v3 = &v2->second._Impl;
        do
        {
          if ( !*v3 )
          {
            std::_Xbad_function_call();
            JUMPOUT(0x7234A5);
          }
          (*v3)->_Do_call(*v3, &v6);
          ++v2;
          v3 += 8;
        }
        while ( v2 != this->evOnShutdownRequested.handlers._Mylast );
      }
      if ( this->isClosing )
        break;
    }
    Game::onIdle(this);
  }
  AudioEngine::stop(this->audioEngine);
  v4 = this->root;
  this->isClosing = 1;
  for ( i = v4->gameObjects._Myfirst; i != v4->gameObjects._Mylast; ++i )
    Game::shutdownObject(this, *i);
  v4->shutdown(v4);
}
void Game::shutdown(Game *this)
{
  this->isClosing = 1;
}
void Game::shutdownObject(Game *this, GameObject *o)
{
  GameObject **i; // esi

  for ( i = o->gameObjects._Myfirst; i != o->gameObjects._Mylast; ++i )
    Game::shutdownObject(this, *i);
  o->shutdown(o);
}
void Game::update(Game *this, GameObject *o, float dt)
{
  GameObject **i; // esi

  if ( o->isActive )
  {
    ((void (*)(GameObject *, _DWORD))o->update)(o, LODWORD(dt));
    for ( i = o->gameObjects._Myfirst; i != o->gameObjects._Mylast; ++i )
      Game::update(this, *i, dt);
  }
}
