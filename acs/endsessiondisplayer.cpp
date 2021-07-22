#include "endsessiondisplayer.h
void __userpurge EndSessionDisplayer::EndSessionDisplayer(EndSessionDisplayer *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  std::_Ref_count_base *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  Font *v7; // eax
  Game *v8; // eax
  Texture *v9; // eax
  Game *v10; // eax
  Texture *v11; // eax
  Sim *v12; // eax
  Texture *v13; // eax
  std::_Ref_count_base *v14; // edi
  ksgui::Control *v15; // eax
  Game *v16; // eax
  bool v17; // zf
  ksgui::Control *v18; // eax
  std::_Ref_count_base *v19; // eax
  EndSessionCommonGui *v20; // eax
  EndSessionCommonGui *v21; // edx
  ksgui::Control *v22; // ecx
  std::_Ref_count_base *v23; // eax
  ACStandardLeaderboard *v24; // eax
  Sim *v25; // ecx
  ksgui::Control *v26; // ecx
  ksgui::Control_vtbl *v27; // eax
  float v28; // xmm0_4
  ACStandardLeaderboard *v29; // eax
  Event<OnMouseDownEvent> *v30; // ecx
  Event<OnMouseWheelMovedEvent> *v31; // ecx
  Event<OnMouseWheelMovedEvent> *v32; // ecx
  Event<OnMouseWheelMovedEvent> *v33; // ecx
  std::wstring v34; // [esp+4h] [ebp-90h] BYREF
  float top; // [esp+1Ch] [ebp-78h]
  EndSessionDisplayer *v36; // [esp+3Ch] [ebp-58h]
  Sim *v37; // [esp+40h] [ebp-54h]
  float left; // [esp+44h] [ebp-50h]
  std::shared_ptr<Font> _Right; // [esp+48h] [ebp-4Ch] BYREF
  Texture result; // [esp+50h] [ebp-44h] BYREF
  std::wstring filename; // [esp+6Ch] [ebp-28h] BYREF
  int v42; // [esp+90h] [ebp-4h]

  left = 0.0;
  v37 = aSim;
  v36 = this;
  top = *(float *)&aSim->game;
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"INTER_SESSION_DISPLAYER", 0x17u);
  GameObject::GameObject(this, v34, (Game *)LODWORD(top));
  this->__vftable = (EndSessionDisplayer_vtbl *)&EndSessionDisplayer::`vftable';
  v42 = 0;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->sim = v37;
  this->parentControl = 0;
  this->leaderboard = 0;
  this->commonGui = 0;
  this->texEndpointsTimeAttack.kid = 0;
  this->texEndpointsTimeAttack.fileName._Myres = 7;
  this->texEndpointsTimeAttack.fileName._Mysize = 0;
  this->texEndpointsTimeAttack.fileName._Bx._Buf[0] = 0;
  this->texEndpointsDrift.kid = 0;
  this->texEndpointsDrift.fileName._Myres = 7;
  this->texEndpointsDrift.fileName._Mysize = 0;
  this->texEndpointsDrift.fileName._Bx._Buf[0] = 0;
  this->texEndDrag.kid = 0;
  this->texEndDrag.fileName._Myres = 7;
  this->texEndDrag.fileName._Mysize = 0;
  this->texEndDrag.fileName._Bx._Buf[0] = 0;
  this->oldMode = eCockpit;
  this->currentTitle._Myres = 7;
  this->currentTitle._Mysize = 0;
  this->currentTitle._Bx._Buf[0] = 0;
  LODWORD(top) = 24;
  LOBYTE(v42) = 5;
  this->isLoaded = 0;
  v4 = (std::_Ref_count_base *)operator new(LODWORD(top));
  _Right._Rep = v4;
  LOBYTE(v42) = 6;
  if ( v4 )
    Font::Font((Font *)v4, eFontMonospaced, 30.0, 0, 1);
  else
    v5 = 0;
  LOBYTE(v42) = 5;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v6 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v7 = this->font._Ptr;
  LODWORD(top) = 36;
  v34._Myres = (unsigned int)L"content/gui/timeAttack/endpoints.png";
  filename._Myres = 7;
  v7->shadowed = 1;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v34._Myres, LODWORD(top));
  v8 = this->game;
  LOBYTE(v42) = 7;
  v9 = ResourceStore::getTexture(v8->gui->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->texEndpointsTimeAttack.kid = v9->kid;
  LOBYTE(v42) = 8;
  if ( &this->texEndpointsTimeAttack.fileName != &v9->fileName )
    std::wstring::assign(&this->texEndpointsTimeAttack.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v42) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v42) = 5;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/endpoints.png", 0x1Fu);
  v10 = this->game;
  LOBYTE(v42) = 9;
  v11 = ResourceStore::getTexture(v10->gui->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->texEndpointsDrift.kid = v11->kid;
  LOBYTE(v42) = 10;
  if ( &this->texEndpointsDrift.fileName != &v11->fileName )
    std::wstring::assign(&this->texEndpointsDrift.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v42) = 9;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v42) = 5;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drag/drag_end.png", 0x1Du);
  v12 = this->sim;
  LOBYTE(v42) = 11;
  v13 = ResourceStore::getTexture(v12->game->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->texEndDrag.kid = v13->kid;
  LOBYTE(v42) = 12;
  if ( &this->texEndDrag.fileName != &v13->fileName )
    std::wstring::assign(&this->texEndDrag.fileName, &v13->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v42) = 11;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v42) = 5;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v14 = (std::_Ref_count_base *)operator new(280);
  _Right._Rep = v14;
  v15 = 0;
  LOBYTE(v42) = 13;
  if ( v14 )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"PARENT_CONTROL", 0xEu);
    LODWORD(left) = 1;
    v16 = this->game;
    LOBYTE(v42) = 14;
    ksgui::Control::Control((ksgui::Control *)v14, &filename, v16->gui);
  }
  v17 = (LOBYTE(left) & 1) == 0;
  this->parentControl = v15;
  v42 = 5;
  if ( !v17 && filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)this->parentControl, 0.0, 0.0);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->parentControl->setSize)(
    this->parentControl,
    (float)this->game->graphics->videoSettings.width,
    (float)this->game->graphics->videoSettings.height);
  v18 = this->parentControl;
  LODWORD(top) = 324;
  v18->backColor = 0i64;
  this->parentControl->drawBorder = 0;
  v19 = (std::_Ref_count_base *)operator new(LODWORD(top));
  _Right._Rep = v19;
  LOBYTE(v42) = 16;
  if ( v19 )
  {
    EndSessionCommonGui::EndSessionCommonGui((EndSessionCommonGui *)v19, a2, this->sim);
    v21 = v20;
  }
  else
  {
    v21 = 0;
  }
  v22 = this->parentControl;
  this->commonGui = v21;
  LOBYTE(v42) = 5;
  v22->addControl(v22, v21);
  ksgui::Form::setPosition((ksgui::Form *)this->commonGui, 0.0, 0.0);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->commonGui->setSize)(
    this->commonGui,
    (float)this->game->gui->graphics->videoSettings.width,
    (float)this->game->gui->graphics->videoSettings.height);
  v23 = (std::_Ref_count_base *)operator new(536);
  _Right._Rep = v23;
  LOBYTE(v42) = 17;
  if ( v23 )
    ACStandardLeaderboard::ACStandardLeaderboard((ACStandardLeaderboard *)v23, this->sim, 10, 0);
  else
    v24 = 0;
  v25 = v37;
  LOBYTE(v42) = 5;
  this->leaderboard = v24;
  Sim::isInTripleScreenMode(v25);
  v26 = this->parentControl;
  top = *(float *)&this->leaderboard;
  v27 = v26->__vftable;
  v28 = *(float *)(LODWORD(top) + 40) - *(float *)(LODWORD(top) + 36);
  left = (float)((float)(v26->rect.right - v26->rect.left) * 0.5)
       - (float)((float)(*(float *)(LODWORD(top) + 32) - *(float *)(LODWORD(top) + 28)) * 0.5);
  *(float *)&v37 = (float)((float)(v26->rect.bottom - v26->rect.top) * 0.5) - (float)(v28 * 0.5);
  ((void (__stdcall *)(_DWORD))v27->addControl)(LODWORD(top));
  ksgui::Form::setPosition((ksgui::Form *)this->leaderboard, left, *(float *)&v37);
  v29 = this->leaderboard;
  LODWORD(top) = this;
  v29->showModeButtons = 0;
  v34._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_8f050bd46cec01de98404ba30ab7adbc_,0>,std::allocator<std::_Func_class<void,OnMouseDownEvent const &>>,void,OnMouseDownEvent const &>::`vftable';
  *(_DWORD *)&v34._Bx._Alias[4] = this;
  v34._Mysize = (unsigned int)&v34;
  v30 = &this->game->window.evOnMouseDown;
  LOBYTE(v42) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v30,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v34,
    (void *)LODWORD(top));
  LODWORD(top) = this;
  v34._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_7a1348330e14661c3c6081daeac93b3c_,0>,std::allocator<std::_Func_class<void,OnMouseUpEvent const &>>,void,OnMouseUpEvent const &>::`vftable';
  *(_DWORD *)&v34._Bx._Alias[4] = this;
  v34._Mysize = (unsigned int)&v34;
  v31 = (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseUp;
  LOBYTE(v42) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    v31,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v34,
    this);
  LODWORD(top) = this;
  v34._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_49966eceae654fae86f3adc27087016b_,0>,std::allocator<std::_Func_class<void,OnMouseMoveEvent const &>>,void,OnMouseMoveEvent const &>::`vftable';
  *(_DWORD *)&v34._Bx._Alias[4] = this;
  v34._Mysize = (unsigned int)&v34;
  v32 = (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseMove;
  LOBYTE(v42) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    v32,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v34,
    this);
  LODWORD(top) = this;
  v34._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e503a2ba0ad768d124dfbed39b28eb8e_,0>,std::allocator<std::_Func_class<void,OnMouseWheelMovedEvent const &>>,void,OnMouseWheelMovedEvent const &>::`vftable';
  *(_DWORD *)&v34._Bx._Alias[4] = this;
  v34._Mysize = (unsigned int)&v34;
  v33 = &this->game->window.evOnMouseWheelMoved;
  LOBYTE(v42) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    v33,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v34,
    this);
  this->isActive = 0;
}
void EndSessionDisplayer::~EndSessionDisplayer(EndSessionDisplayer *this)
{
  ksgui::Control *v2; // ecx
  std::_Ref_count_base *v3; // edi

  this->__vftable = (EndSessionDisplayer_vtbl *)&EndSessionDisplayer::`vftable';
  v2 = this->parentControl;
  if ( v2 )
    ((void (*)(ksgui::Control *, int))v2->~Control)(v2, 1);
  if ( this->currentTitle._Myres >= 8 )
    operator delete(this->currentTitle._Bx._Ptr);
  this->currentTitle._Myres = 7;
  this->currentTitle._Mysize = 0;
  this->currentTitle._Bx._Buf[0] = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&this->texEndDrag);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texEndpointsDrift);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texEndpointsTimeAttack);
  v3 = this->font._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  GameObject::~GameObject(this);
}
EndSessionDisplayer *EndSessionDisplayer::`scalar deleting destructor'(EndSessionDisplayer *this, unsigned int a2)
{
  EndSessionDisplayer::~EndSessionDisplayer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void EndSessionDisplayer::displayResults(EndSessionDisplayer *this)
{
  Sim *v2; // ecx
  CarAvatar *v3; // eax

  if ( !this->isActive )
  {
    v2 = this->sim;
    this->isActive = 1;
    this->oldMode = v2->cameraManager->mode;
    if ( !v2->isVrConnected )
    {
      ACCameraManager::setMode(v2->cameraManager, eOnBoardFree, 0, 0);
      CameraOnBoardFree::setIntroMode(this->sim->cameraManager->cameraOnBoardFree, 1);
    }
    this->game->gui->isActive = 0;
    ksgui::Control::setVisible(this->parentControl, 1);
    v3 = Sim::getCar(this->sim, 0);
    CarAvatar::setControlsLock(v3, 1);
  }
}
void EndSessionDisplayer::hide(EndSessionDisplayer *this)
{
  Sim *v2; // ecx
  CarAvatar *v3; // eax
  CameraMode v4; // [esp-Ch] [ebp-10h]

  if ( this->isActive )
  {
    v2 = this->sim;
    v4 = this->oldMode;
    this->isActive = 0;
    ACCameraManager::setMode(v2->cameraManager, v4, 0, 0);
    this->game->gui->isActive = 1;
    ksgui::Control::setVisible(this->parentControl, 0);
    v3 = Sim::getCar(this->sim, 0);
    CarAvatar::setControlsLock(v3, 0);
  }
}
void EndSessionDisplayer::renderHUD(EndSessionDisplayer *this, float dt)
{
  Sim *v3; // ecx
  GLRenderer *v4; // ebp
  DragMode *v5; // ebx
  __int64 v6; // rax
  int v7; // esi
  unsigned int v8; // ebp
  signed int v9; // ebp
  signed int v10; // eax
  Font *v11; // ecx
  const vec4f *v12; // eax
  std::wostream *v13; // eax
  const std::wstring *v14; // eax
  Font *v15; // ecx
  std::wostream *v16; // eax
  const std::wstring *v17; // eax
  Font *v18; // ecx
  DriftMode *v19; // ebx
  unsigned int v20; // eax
  int v21; // eax
  Game *v22; // eax
  Font *v23; // ecx
  TimeAttack *v24; // ebx
  unsigned int v25; // eax
  int v26; // eax
  Game *v27; // eax
  Font *v28; // ecx
  float x; // [esp+10h] [ebp-30Ch]
  float r; // [esp+18h] [ebp-304h]
  float ra; // [esp+18h] [ebp-304h]
  float rb; // [esp+18h] [ebp-304h]
  float g; // [esp+1Ch] [ebp-300h]
  float ga; // [esp+1Ch] [ebp-300h]
  const std::wstring *gb; // [esp+1Ch] [ebp-300h]
  float gc; // [esp+1Ch] [ebp-300h]
  const std::wstring *gd; // [esp+1Ch] [ebp-300h]
  unsigned int a; // [esp+24h] [ebp-2F8h]
  float v39; // [esp+48h] [ebp-2D4h]
  __int128 v40; // [esp+4Ch] [ebp-2D0h] BYREF
  vec4f cc_4; // [esp+5Ch] [ebp-2C0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v42; // [esp+6Ch] [ebp-2B0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v43; // [esp+11Ch] [ebp-200h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v44; // [esp+1CCh] [ebp-150h] BYREF
  std::wstring _Newstr; // [esp+27Ch] [ebp-A0h] BYREF
  std::wstring v46; // [esp+294h] [ebp-88h] BYREF
  std::wstring result; // [esp+2ACh] [ebp-70h] BYREF
  std::wstring v48; // [esp+2C4h] [ebp-58h] BYREF
  std::wstring v49; // [esp+2DCh] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v50; // [esp+2F4h] [ebp-28h] BYREF
  int v51; // [esp+318h] [ebp-4h]

  if ( this->isActive )
  {
    v3 = this->sim;
    if ( !v3->pauseMenu->visible && !ReplayManager::isInReplaymode(v3->replayManager) )
    {
      GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
      ((void (*)(ksgui::Control *, _DWORD))this->parentControl->render)(this->parentControl, LODWORD(dt));
      v4 = this->game->gui->graphics->gl;
      GLRenderer::color4f(v4, 1.0, 1.0, 1.0, 1.0);
      switch ( RaceManager::getCurrentSessionType(this->sim->raceManager) )
      {
        case Pratice:
        case Qualify:
        case Race:
          if ( !this->isLoaded )
          {
            ksgui::Control::setVisible(this->leaderboard, 1);
            ACStandardLeaderboard::setLastSession(this->leaderboard);
            this->isLoaded = 1;
          }
          ((void (*)(ACStandardLeaderboard *, _DWORD))this->leaderboard->render)(
            this->leaderboard,
            LODWORD(dt));
          break;
        case TimeAttack:
          ksgui::Control::setVisible(this->leaderboard, 0);
          v24 = GameObject::getGameObject<TimeAttack>(this->sim);
          if ( v24 )
          {
            GraphicsManager::setTexture(this->game->gui->graphics, 0, &this->texEndpointsTimeAttack);
            v39 = (float)this->game->gui->graphics->videoSettings.width * 0.5;
            gc = (float)Texture::height(&this->texEndpointsTimeAttack);
            rb = (float)Texture::width(&this->texEndpointsTimeAttack);
            v25 = Texture::width(&this->texEndpointsTimeAttack);
            GLRenderer::quad(v4, v39 - (float)((double)(v25 >> 1) + 0.0), 250.0, rb, gc, 1, 0);
            *(_DWORD *)v43.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v43.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v43.gap68);
            v51 = 13;
            std::wiostream::basic_iostream<wchar_t>(&v43, &v43.gap10[8], 0);
            v51 = 14;
            *(_DWORD *)&v43.gap0[*(_DWORD *)(*(_DWORD *)v43.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v42.gap68[*(_DWORD *)(*(_DWORD *)v43.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v43.gap0 + 4)
                                                                             - 104;
            std::wstreambuf::wstreambuf(&v43.gap10[8]);
            *(_DWORD *)&v43.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v43.gap10[64] = 0;
            *(_DWORD *)&v43.gap10[68] = 0;
            v26 = (int)v24->status.points;
            v51 = 16;
            std::wostream::operator<<(v43.gap10, v26);
            Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
            gd = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                   &v43,
                   &v50.name);
            v27 = this->game;
            v28 = this->font._Ptr;
            LOBYTE(v51) = 17;
            Font::blitString(
              v28,
              (float)v27->gui->graphics->videoSettings.width * 0.5,
              275.0,
              gd,
              0.80000001,
              eAlignCenter);
            std::wstring::~wstring(&v50);
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v43);
          }
          break;
        case Drift:
          ksgui::Control::setVisible(this->leaderboard, 0);
          v19 = GameObject::getGameObject<DriftMode>(this->sim);
          if ( v19 )
          {
            GraphicsManager::setTexture(this->game->gui->graphics, 0, &this->texEndpointsDrift);
            v39 = (float)this->game->gui->graphics->videoSettings.width * 0.5;
            ga = (float)Texture::height(&this->texEndpointsDrift);
            ra = (float)Texture::width(&this->texEndpointsDrift);
            v20 = Texture::width(&this->texEndpointsDrift);
            GLRenderer::quad(v4, v39 - (float)((double)(v20 >> 1) + 0.0), 250.0, ra, ga, 1, 0);
            *(_DWORD *)v44.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v44.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v44.gap68);
            v51 = 8;
            std::wiostream::basic_iostream<wchar_t>(&v44, &v44.gap10[8], 0);
            v51 = 9;
            *(_DWORD *)&v44.gap0[*(_DWORD *)(*(_DWORD *)v44.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v43.gap68[*(_DWORD *)(*(_DWORD *)v44.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v44.gap0 + 4)
                                                                             - 104;
            std::wstreambuf::wstreambuf(&v44.gap10[8]);
            *(_DWORD *)&v44.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v44.gap10[64] = 0;
            *(_DWORD *)&v44.gap10[68] = 0;
            v21 = (int)v19->sessionPoints;
            v51 = 11;
            std::wostream::operator<<(v44.gap10, v21);
            Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
            gb = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v44, &v48);
            v22 = this->game;
            v23 = this->font._Ptr;
            LOBYTE(v51) = 12;
            Font::blitString(
              v23,
              (float)v22->gui->graphics->videoSettings.width * 0.5,
              275.0,
              gb,
              0.80000001,
              eAlignCenter);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v48);
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v44);
          }
          break;
        case Drag:
          ksgui::Control::setVisible(this->leaderboard, 0);
          v5 = GameObject::getGameObject<DragMode>(this->sim);
          if ( v5 )
          {
            GraphicsManager::setTexture(this->game->gui->graphics, 0, &this->texEndDrag);
            g = (float)Texture::height(&this->texEndDrag);
            r = (float)Texture::width(&this->texEndDrag);
            x = (float)(this->game->gui->graphics->videoSettings.width / 2 - (Texture::width(&this->texEndDrag) >> 1));
            GLRenderer::quad(v4, x, 250.0, r, g, 1, 0);
            v6 = this->game->gui->graphics->videoSettings.width;
            v7 = ((int)v6 - HIDWORD(v6)) >> 1;
            v8 = DragMode::getNumberOfRuns(v5);
            v9 = v8 - DragMode::getNumberOfPlayerWins(v5);
            v10 = DragMode::getNumberOfPlayerWins(v5);
            v11 = this->font._Ptr;
            if ( v9 >= v10 )
            {
              v12 = (const vec4f *)&v40;
              v40 = _xmm;
            }
            else
            {
              v12 = &cc_4;
              cc_4 = (vec4f)_xmm;
            }
            Font::setColor(v11, v12);
            *(_DWORD *)v42.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v42.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v42.gap68);
            v51 = 0;
            std::wiostream::basic_iostream<wchar_t>(&v42, &v42.gap10[8], 0);
            v51 = 1;
            *(_DWORD *)&v42.gap0[*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)((char *)&cc_4.w + *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)
                                                                                - 104;
            std::wstreambuf::wstreambuf(&v42.gap10[8]);
            *(_DWORD *)&v42.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v42.gap10[64] = 0;
            *(_DWORD *)&v42.gap10[68] = 0;
            v51 = 3;
            std::wstring::wstring(&_Newstr, word_17BE9D8);
            LOBYTE(v51) = 4;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &_Newstr);
            LOBYTE(v51) = 3;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Newstr);
            a = DragMode::getNumberOfPlayerWins(v5);
            v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "PLAYER : ");
            std::wostream::operator<<(v13, a);
            v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &result);
            v15 = this->font._Ptr;
            LOBYTE(v51) = 5;
            Font::blitString(v15, (float)(v7 - 25), 280.0, v14, 1.0, eAlignRight);
            LOBYTE(v51) = 3;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
            std::wstring::wstring(&v46, word_17BE9D8);
            LOBYTE(v51) = 6;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &v46);
            LOBYTE(v51) = 3;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v46);
            v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v42.gap10, "AI : ");
            std::wostream::operator<<(v16, v9);
            v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &v49);
            v18 = this->font._Ptr;
            LOBYTE(v51) = 7;
            Font::blitString(v18, (float)(v7 + 25), 280.0, v17, 1.0, eAlignLeft);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v49);
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v42);
          }
          break;
        default:
          ksgui::Control::setVisible(this->leaderboard, 0);
          break;
      }
    }
  }
}
void EndSessionDisplayer::update(EndSessionDisplayer *this, float dt)
{
  bool v3; // al
  ksgui::Control *v4; // ecx

  SystemMessage::clearMessage(this->sim->systemMessage);
  v3 = ReplayManager::isInReplaymode(this->sim->replayManager);
  v4 = this->parentControl;
  if ( v3 )
  {
    ksgui::Control::setVisible(v4, 0);
    this->game->gui->isActive = 1;
  }
  else
  {
    ksgui::Control::setVisible(v4, 1);
    this->game->gui->isActive = 0;
  }
}
