#include "escmenu.h
void __userpurge ESCMenu::ESCMenu(ESCMenu *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim, ksgui::GUI *gui)
{
  ksgui::Control *v5; // eax
  Font *v6; // eax
  volatile signed __int32 *v7; // edi
  GraphicsManager *v8; // eax
  Texture *v9; // eax
  SetupScreen *v10; // eax
  SetupScreen *v11; // eax
  ksgui::ActiveButton *v12; // eax
  ksgui::ActiveButton *v13; // eax
  _DWORD *v14; // eax
  double v15; // st7
  bool v16; // cf
  Event<OnMouseWheelMovedEvent> *v17; // ecx
  ksgui::ActiveButton *v18; // ecx
  SetupScreen *v19; // eax
  ksgui::ActiveButton *v20; // eax
  const __m128i *v21; // eax
  GraphicsManager *v22; // eax
  Texture *v23; // edx
  ksgui::ActiveButton *v24; // ecx
  void *v25; // eax
  const std::wstring *v26; // edx
  std::wstring *v27; // ecx
  Event<OnMouseWheelMovedEvent> *v28; // ecx
  ksgui::ActiveButton *v29; // eax
  ComparativeTelemetry *v30; // eax
  ComparativeTelemetry *v31; // eax
  ksgui::ActiveButton *v32; // ecx
  ComparativeTelemetry *v33; // eax
  Event<OnMouseWheelMovedEvent> *v34; // ecx
  ksgui::ActiveButton *v35; // eax
  RaceControlScreen *v36; // eax
  RaceControlScreen *v37; // eax
  ksgui::ActiveButton *v38; // ecx
  RaceControlScreen *v39; // eax
  RaceControlScreen *v40; // eax
  Event<OnMouseWheelMovedEvent> *v41; // ecx
  EscMenuTimeTable *v42; // eax
  EscMenuTimeTable *v43; // eax
  ksgui::ActiveButton *v44; // ecx
  EscMenuTimeTable *v45; // eax
  EscMenuTimeTable *v46; // eax
  Event<OnMouseWheelMovedEvent> *v47; // ecx
  ksgui::ActiveButton *v48; // eax
  Event<OnMouseWheelMovedEvent> *v49; // ecx
  Event<OnNewSessionEvent> *v50; // ecx
  std::wstring v51; // [esp+0h] [ebp-F4h] BYREF
  float h; // [esp+18h] [ebp-DCh]
  ESCMenu *v53; // [esp+4Ch] [ebp-A8h]
  ksgui::OnControlClicked ev; // [esp+50h] [ebp-A4h] BYREF
  int v55; // [esp+60h] [ebp-94h]
  unsigned int v56; // [esp+64h] [ebp-90h]
  std::wstring iname; // [esp+6Ch] [ebp-88h] BYREF
  Texture result; // [esp+84h] [ebp-70h] BYREF
  INIReader d; // [esp+A0h] [ebp-54h] BYREF
  int v60; // [esp+F0h] [ebp-4h]

  v53 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"ESCMenu", 7u);
  v60 = 0;
  ksgui::Control::Control(this, &iname, gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (ESCMenu_vtbl *)&ESCMenu::`vftable';
  this->evOnESCMenuTriggered.handlers._Myfirst = 0;
  this->evOnESCMenuTriggered.handlers._Mylast = 0;
  this->evOnESCMenuTriggered.handlers._Myend = 0;
  this->evOnDriveMenuPressed.handlers._Myfirst = 0;
  this->evOnDriveMenuPressed.handlers._Mylast = 0;
  this->evOnDriveMenuPressed.handlers._Myend = 0;
  this->setupScreen = 0;
  *(_WORD *)&this->showLeaderboard = 0;
  this->fadeTime = 0.0;
  this->message.menu = 0;
  *(_WORD *)&this->message.visible = 0;
  this->width = 0.0;
  this->acLogo.kid = 0;
  this->acLogo.fileName._Myres = 7;
  this->acLogo.fileName._Mysize = 0;
  this->acLogo.fileName._Bx._Buf[0] = 0;
  LODWORD(h) = 24;
  LOBYTE(v60) = 5;
  this->sim = 0;
  this->butExit = 0;
  this->butDrive = 0;
  this->butDriveFake = 0;
  this->butSetup = 0;
  this->butTime = 0;
  this->butNextSession = 0;
  this->butComparativeTelemetry = 0;
  this->lastSelected = 0;
  this->butRaceControl = 0;
  this->comparativeTelemetry = 0;
  this->raceControl = 0;
  this->timeTable = 0;
  v5 = (ksgui::Control *)operator new(LODWORD(h));
  ev.control = v5;
  LOBYTE(v60) = 6;
  if ( v5 )
    Font::Font((Font *)v5, eFontMonospaced, 20.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v60) = 5;
  ev.control = 0;
  ev.localx = 0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&ev, v6);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&ev);
  v7 = (volatile signed __int32 *)ev.localx;
  if ( ev.localx )
  {
    a2 = -1;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(ev.localx + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v7)(v7);
      a2 = _InterlockedDecrement(v7 + 2);
      if ( !a2 )
        (*(void (**)(volatile signed __int32 *))(*v7 + 4))(v7);
    }
  }
  this->fadeTime = 0.0;
  this->width = 100.0;
  ksgui::Control::setSize(this, 100.0, (float)gui->graphics->videoSettings.height);
  h = 0.0;
  this->lastSelected = 0;
  this->sim = aSim;
  *(_WORD *)&this->drawBorder = 0;
  ksgui::Control::setVisible(this, SLODWORD(h));
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/logo_esc_menu.png", 0x1Du);
  v8 = gui->graphics;
  LOBYTE(v60) = 7;
  v9 = ResourceStore::getTexture(v8->resourceStore._Myptr, &result, &iname, 0);
  this->acLogo.kid = v9->kid;
  LOBYTE(v60) = 8;
  if ( &this->acLogo.fileName != &v9->fileName )
    std::wstring::assign(&this->acLogo.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v60) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v60) = 5;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v10 = (SetupScreen *)operator new(352);
  ev.control = v10;
  LOBYTE(v60) = 9;
  if ( v10 )
    SetupScreen::SetupScreen(v10, this->sim);
  else
    v11 = 0;
  LODWORD(h) = v11;
  LOBYTE(v60) = 5;
  this->setupScreen = v11;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(h));
  h = 125.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"drive", 5u);
  this->butDrive = ESCMenu::addButton(this, a2, v51, h);
  h = 125.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"drive_VALIDATE", 0xEu);
  v12 = ESCMenu::addButton(this, a2, v51, h);
  ev.control = 0;
  this->butDriveFake = v12;
  ev.localx = 1092616192;
  v12->textCoord.x = 0.0;
  LODWORD(v12->textCoord.y) = ev.localx;
  v13 = this->butDriveFake;
  LODWORD(h) = 20;
  v51._Myres = (unsigned int)L"system/cfg/fades.ini";
  iname._Myres = 7;
  v14 = (_DWORD *)&v13->font._Ptr->scale;
  iname._Mysize = 0;
  *v14 = 1094713344;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)v51._Myres, LODWORD(h));
  LOBYTE(v60) = 10;
  INIReader::INIReader(&d, &iname);
  LOBYTE(v60) = 12;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"MS", 2u);
  LOBYTE(v60) = 13;
  v56 = 7;
  v55 = 0;
  LOWORD(ev.control) = 0;
  std::wstring::assign((std::wstring *)&ev, L"ESC_MENU_FADE", 0xDu);
  LOBYTE(v60) = 14;
  v15 = INIReader::getFloat(&d, (const std::wstring *)&ev, (const std::wstring *)&result);
  v16 = v56 < 8;
  this->fadeTime = v15 * 0.001;
  if ( !v16 )
    operator delete(ev.control);
  v56 = 7;
  v55 = 0;
  LOWORD(ev.control) = 0;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LODWORD(h) = this;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_9d776f265dfc97ec18d2be4f167d568b_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v17 = (Event<OnMouseWheelMovedEvent> *)&this->butDrive->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v17,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    this);
  h = 225.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"setup", 5u);
  v18 = ESCMenu::addButton(this, a2, v51, h);
  v19 = this->setupScreen;
  this->butSetup = v18;
  v18->tag = v19;
  if ( this->sim->raceManager->fixedSetup )
  {
    v20 = this->butSetup;
    LODWORD(h) = 36;
    v51._Myres = (unsigned int)L"content/gui/inGameMenu/setup_OFF.png";
    result.fileName._Mysize = 7;
    v20->usingMultipleTextures = 0;
    v21 = (const __m128i *)this->butSetup;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    v21[20] = _mm_loadu_si128(v21 + 18);
    LOWORD(result.kid) = 0;
    std::wstring::assign((std::wstring *)&result, (const wchar_t *)v51._Myres, LODWORD(h));
    v22 = gui->graphics;
    LOBYTE(v60) = 16;
    v23 = ResourceStore::getTexture(v22->resourceStore._Myptr, (Texture *)&ev, (const std::wstring *)&result, 0);
    v24 = this->butSetup;
    v25 = v23->kid;
    v26 = &v23->fileName;
    LOBYTE(v60) = 17;
    v24->backTexture.kid = v25;
    v27 = &v24->backTexture.fileName;
    if ( v27 != v26 )
      std::wstring::assign(v27, v26, 0, 0xFFFFFFFF);
    LOBYTE(v60) = 16;
    OnSetupAppCreated::~OnSetupAppCreated((Texture *)&ev);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
  }
  LODWORD(h) = this;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_1bb0d5a339313a80c90480293f47e7cb_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v28 = (Event<OnMouseWheelMovedEvent> *)&this->butSetup->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v28,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    this);
  h = 325.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"time", 4u);
  this->butTime = ESCMenu::addButton(this, a2, v51, h);
  h = 425.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"telemetry", 9u);
  v29 = ESCMenu::addButton(this, a2, v51, h);
  LODWORD(h) = 400;
  this->butComparativeTelemetry = v29;
  v30 = (ComparativeTelemetry *)operator new(LODWORD(h));
  ev.control = v30;
  LOBYTE(v60) = 19;
  if ( v30 )
    ComparativeTelemetry::ComparativeTelemetry(v30, a2, this->sim);
  else
    v31 = 0;
  h = 0.0;
  LOBYTE(v60) = 12;
  this->comparativeTelemetry = v31;
  ksgui::Form::setIconVisible(v31, SLODWORD(h));
  ksgui::Control::setVisible(this->comparativeTelemetry, 0);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->comparativeTelemetry->setSize)(
    this->comparativeTelemetry,
    (float)((float)this->sim->game->graphics->videoSettings.width - this->rect.right) - 20.0,
    (float)this->sim->game->graphics->videoSettings.height);
  ksgui::Form::setPosition(this->comparativeTelemetry, this->rect.right + 10.0, 0.0);
  ksgui::Control::addControl(this, this->comparativeTelemetry);
  v32 = this->butComparativeTelemetry;
  v33 = this->comparativeTelemetry;
  LODWORD(h) = this;
  v32->tag = v33;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_099bb1e1c93c1bff0282678f1bf2df13_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v34 = (Event<OnMouseWheelMovedEvent> *)&this->butComparativeTelemetry->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v34,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    (void *)LODWORD(h));
  h = 525.0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"racecontrol", 0xBu);
  v35 = ESCMenu::addButton(this, a2, v51, h);
  LODWORD(h) = 312;
  this->butRaceControl = v35;
  v36 = (RaceControlScreen *)operator new(LODWORD(h));
  ev.control = v36;
  LOBYTE(v60) = 21;
  if ( v36 )
    RaceControlScreen::RaceControlScreen(v36, this->sim);
  else
    v37 = 0;
  LODWORD(h) = v37;
  LOBYTE(v60) = 12;
  this->raceControl = v37;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(h));
  v38 = this->butRaceControl;
  v39 = this->raceControl;
  h = 0.0;
  v38->tag = v39;
  ksgui::Control::setVisible(this->raceControl, SLODWORD(h));
  ksgui::Form::setPosition((ksgui::Form *)this->raceControl, 100.0, 0.0);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->raceControl->setSize)(
    this->raceControl,
    (float)(gui->graphics->videoSettings.width - 100),
    (float)gui->graphics->videoSettings.height);
  v40 = this->raceControl;
  LODWORD(h) = this;
  v40->drawBorder = 0;
  this->raceControl->drawBackground = 0;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_2e12a074487b3f1db6b34b05b6ffcbb0_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v41 = (Event<OnMouseWheelMovedEvent> *)&this->butRaceControl->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v41,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    (void *)LODWORD(h));
  if ( this->sim->client )
  {
    ev.control = this->butRaceControl;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&ev.control->evClicked, (const OnGearRequestEvent *)&ev);
  }
  v42 = (EscMenuTimeTable *)operator new(624);
  ev.control = v42;
  LOBYTE(v60) = 23;
  if ( v42 )
    EscMenuTimeTable::EscMenuTimeTable(v42, a2, this->sim);
  else
    v43 = 0;
  LODWORD(h) = v43;
  LOBYTE(v60) = 12;
  this->timeTable = v43;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(h));
  v44 = this->butTime;
  v45 = this->timeTable;
  h = 0.0;
  v44->tag = v45;
  ksgui::Control::setVisible(this->timeTable, SLODWORD(h));
  ksgui::Form::setPosition((ksgui::Form *)this->timeTable, 100.0, 0.0);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->timeTable->setSize)(
    this->timeTable,
    1142292480,
    (float)gui->graphics->videoSettings.height);
  v46 = this->timeTable;
  LODWORD(h) = this;
  v46->drawBorder = 0;
  this->timeTable->drawBackground = 0;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_4e71073b6ad773819bc9a3fecf4180b5_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v47 = (Event<OnMouseWheelMovedEvent> *)&this->butTime->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v47,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    (void *)LODWORD(h));
  h = 625.0;
  std::wstring::wstring(&v51, L"exit");
  v48 = ESCMenu::addButton(this, a2, v51, h);
  LODWORD(h) = this;
  this->butExit = v48;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_a157c12c8d11684cae7c683843cbc668_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v49 = (Event<OnMouseWheelMovedEvent> *)&this->butExit->evClicked;
  LOBYTE(v60) = 12;
  Event<ksgui::OnControlClicked>::addHandler(
    v49,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v51,
    (void *)LODWORD(h));
  LODWORD(h) = this;
  v51._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_f6a9abc42bf3e3c0401ca1a5492ba9ab_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v51._Bx._Alias[4] = this;
  v51._Mysize = (unsigned int)&v51;
  v50 = &this->sim->evOnNewSession;
  LOBYTE(v60) = 12;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v50,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v51,
    this);
  LOBYTE(v60) = 5;
  INIReader::~INIReader(&d);
}
void ESCMenu::~ESCMenu(ESCMenu *this)
{
  std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **v2; // esi
  Task **v3; // esi

  this->__vftable = (ESCMenu_vtbl *)&ESCMenu::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->acLogo);
  v2 = (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **)&this->evOnDriveMenuPressed;
  if ( this->evOnDriveMenuPressed.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnDriveMenuPressed);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnDriveMenuPressed,
      *v2,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnDriveMenuPressed.handlers._Mylast);
    operator delete(*v2);
    *v2 = 0;
    this->evOnDriveMenuPressed.handlers._Mylast = 0;
    this->evOnDriveMenuPressed.handlers._Myend = 0;
  }
  v3 = (Task **)&this->evOnESCMenuTriggered;
  if ( this->evOnESCMenuTriggered.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnESCMenuTriggered);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnESCMenuTriggered,
      *v3,
      (Task *)this->evOnESCMenuTriggered.handlers._Mylast);
    operator delete(*v3);
    *v3 = 0;
    this->evOnESCMenuTriggered.handlers._Mylast = 0;
    this->evOnESCMenuTriggered.handlers._Myend = 0;
  }
  ksgui::Control::~Control(this);
}
ESCMenu *ESCMenu::`vector deleting destructor'(ESCMenu *this, unsigned int a2)
{
  ESCMenu::~ESCMenu(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
ksgui::ActiveButton *__userpurge ESCMenu::addButton@<eax>(ESCMenu *this@<ecx>, unsigned int a2@<ebx>, std::wstring id, float y)
{
  ksgui::ActiveButton *v5; // esi
  int *v6; // eax
  int *v7; // esi
  ESCMenu_vtbl *v8; // eax
  int v9; // eax
  _BYTE v11[28]; // [esp-Ch] [ebp-58h] BYREF
  ksgui::ActiveButton *v12; // [esp+20h] [ebp-2Ch]
  std::wstring v13; // [esp+24h] [ebp-28h] BYREF
  int v14; // [esp+48h] [ebp-4h]

  v14 = 1;
  v5 = (ksgui::ActiveButton *)operator new(448);
  v12 = v5;
  if ( v5 )
  {
    *(_DWORD *)&v11[24] = this->gui;
    *(_DWORD *)&v11[20] = 7;
    *(_DWORD *)&v11[16] = 0;
    *(_WORD *)v11 = 0;
    std::wstring::assign((std::wstring *)v11, &id, 0, 0xFFFFFFFF);
    ksgui::ActiveButton::ActiveButton(v5, *(std::wstring *)v11, *(ksgui::GUI **)&v11[24]);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v8 = this->__vftable;
  LOBYTE(v14) = 0;
  v8->addControl(this, (ksgui::Control *)v7);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  std::wstring::assign(&v13, word_17BE9D8, 0);
  v9 = *v7;
  LOBYTE(v14) = 2;
  (*(void (**)(int *, std::wstring *))(v9 + 68))(v7, &v13);
  LOBYTE(v14) = 0;
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  ksgui::Form::setPosition((ksgui::Form *)v7, 1.0, y);
  (*(void (**)(int *, int, int))(*v7 + 28))(v7, 1120010240, 1120010240);
  *((_WORD *)v7 + 100) = 0;
  std::operator+<wchar_t>((std::wstring *)&v11[4], L"content/gui/inGameMenu/", &id);
  ksgui::ActiveButton::setMultipleTexture((ksgui::ActiveButton *)v7, a2, *(std::wstring *)&v11[4]);
  if ( id._Myres >= 8 )
    operator delete(id._Bx._Ptr);
  return (ksgui::ActiveButton *)v7;
}
void ESCMenu::onShutdown(ESCMenu *this)
{
  ReplayManager *v2; // eax
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // esi
  Sim *v7; // ecx
  CarAvatar *v8; // eax
  const std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // esi
  Sim *v12; // ecx
  CarAvatar *v13; // eax
  std::wstring *v14; // eax
  const std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // esi
  Sim *v18; // ecx
  CarAvatar *v19; // eax
  std::wstring *v20; // eax
  const std::wstring *v21; // eax
  SetupScreen *v22; // ecx
  std::wstring result; // [esp+Ch] [ebp-D0h] BYREF
  std::wstring v24; // [esp+24h] [ebp-B8h] BYREF
  std::wstring v25; // [esp+3Ch] [ebp-A0h] BYREF
  std::wstring v26; // [esp+54h] [ebp-88h] BYREF
  std::wstring v27; // [esp+6Ch] [ebp-70h] BYREF
  std::wstring v28; // [esp+84h] [ebp-58h] BYREF
  std::wstring v29; // [esp+9Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v30; // [esp+B4h] [ebp-28h] BYREF
  int v31; // [esp+D8h] [ebp-4h]

  if ( this->setupScreen )
  {
    if ( Sim::getCar(this->sim, 0) )
    {
      v2 = this->sim->replayManager;
      if ( v2 )
      {
        if ( !v2->hasLoadedReplay )
        {
          v3 = Path::getDocumentPath(&result);
          v31 = 0;
          v4 = std::operator+<wchar_t>(&v24, v3, L"\\Assetto Corsa\\setups");
          LOBYTE(v31) = 1;
          Path::createFolder(v4);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v24);
          v31 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v5 = Path::getDocumentPath(&v25);
          v31 = 2;
          v6 = std::operator+<wchar_t>(&v24, v5, L"\\Assetto Corsa\\setups\\");
          v7 = this->sim;
          LOBYTE(v31) = 3;
          v8 = Sim::getCar(v7, 0);
          v9 = std::operator+<wchar_t>(&result, v6, &v8->unixName);
          LOBYTE(v31) = 4;
          Path::createFolder(v9);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v24);
          v31 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v25);
          v10 = Path::getDocumentPath(&v26);
          v31 = 5;
          v11 = std::operator+<wchar_t>(&v24, v10, L"\\Assetto Corsa\\setups\\");
          v12 = this->sim;
          LOBYTE(v31) = 6;
          v13 = Sim::getCar(v12, 0);
          v14 = std::operator+<wchar_t>(&result, v11, &v13->unixName);
          LOBYTE(v31) = 7;
          v15 = std::operator+<wchar_t>(&v25, v14, L"\\generic");
          LOBYTE(v31) = 8;
          Path::createFolder(v15);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v25);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v24);
          v31 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v26);
          v16 = Path::getDocumentPath(&v30.name);
          v31 = 9;
          v17 = std::operator+<wchar_t>(&v28, v16, L"\\Assetto Corsa\\setups\\");
          v18 = this->sim;
          LOBYTE(v31) = 10;
          v19 = Sim::getCar(v18, 0);
          v20 = std::operator+<wchar_t>(&v27, v17, &v19->unixName);
          LOBYTE(v31) = 11;
          v21 = std::operator+<wchar_t>(&v29, v20, L"\\generic\\last.ini");
          v22 = this->setupScreen;
          LOBYTE(v31) = 12;
          SetupScreen::saveSetupAbsolutePath(v22, v21);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v29);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v27);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v28);
          std::wstring::~wstring(&v30);
        }
      }
    }
  }
}
void ESCMenu::onVisibleChanged(ESCMenu *this, BOOL newValue)
{
  ksgui::Control **v3; // edi
  ksgui::Control **i; // esi
  ksgui::ActiveButton *v5; // eax
  std::pair<void *,std::function<void __cdecl(OnESCMenuTriggered const &)> > *v6; // esi
  std::_Func_base<void,OnESCMenuTriggered const &> **v7; // edi
  Sim *v8; // eax
  ksgui::OnControlClicked cc; // [esp+10h] [ebp-Ch] BYREF

  v3 = this->controls._Mylast;
  for ( i = this->controls._Myfirst; i != v3; ++i )
    (*i)->onVisibleChanged(*i, newValue);
  if ( this->visible )
  {
    v5 = this->butDrive;
    this->message.startReplay = 0;
    v5->status = eABUnselected;
  }
  this->message.menu = this;
  this->message.visible = newValue;
  v6 = this->evOnESCMenuTriggered.handlers._Myfirst;
  if ( v6 != this->evOnESCMenuTriggered.handlers._Mylast )
  {
    v7 = &v6->second._Impl;
    do
    {
      if ( !*v7 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x5F4E77);
      }
      (*v7)->_Do_call(*v7, &this->message);
      ++v6;
      v7 += 8;
    }
    while ( v6 != this->evOnESCMenuTriggered.handlers._Mylast );
  }
  v8 = this->sim;
  if ( !v8->client && this->visible && v8->cameraManager->mode != eOnBoardFree && !this->lastSelected )
  {
    cc.control = this->butRaceControl;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&cc.control->evClicked, (const OnGearRequestEvent *)&cc);
  }
}
void ESCMenu::render(ESCMenu *this, float dt)
{
  CarAvatar *v3; // eax
  ComparativeTelemetry *v4; // ecx
  CarSetupState v5; // eax
  __int32 v6; // eax
  std::wstring *v7; // eax
  ksgui::ActiveButton *v8; // ecx
  std::wstring *v9; // eax
  ksgui::ActiveButton *v10; // ecx
  GLRenderer *v11; // edi
  Sim *v12; // ecx
  __int32 v13; // eax
  __int32 v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  CarAvatar *v19; // eax
  Sim *v20; // ecx
  CarAvatar *v21; // eax
  Sim *v22; // ecx
  CarAvatar *v23; // eax
  const std::wstring *v24; // eax
  Font *v25; // ecx
  double v26; // st7
  const std::wstring *v27; // eax
  const std::wstring *v28; // eax
  Font *v29; // ecx
  const std::wstring *v30; // eax
  Font *v31; // ecx
  SessionType v32; // eax
  RaceManager *v33; // ecx
  double v34; // xmm1_8
  double v35; // xmm0_8
  const std::wstring *v36; // eax
  bool v37; // bl
  RaceManager *v38; // ecx
  double v39; // xmm1_8
  double v40; // xmm0_8
  Session *v41; // eax
  Sim *v42; // ecx
  const std::wstring *v43; // eax
  Font *v44; // ecx
  long double g; // [esp+18h] [ebp-1D0h]
  __int64 v46; // [esp+24h] [ebp-1C4h]
  float v47; // [esp+2Ch] [ebp-1BCh]
  double raceClosingTime; // [esp+48h] [ebp-1A0h]
  std::wstring setName; // [esp+50h] [ebp-198h] BYREF
  std::wstring v50; // [esp+68h] [ebp-180h] BYREF
  std::wstring sessionName; // [esp+80h] [ebp-168h] BYREF
  std::wstring text; // [esp+98h] [ebp-150h] BYREF
  std::wstring v53; // [esp+B0h] [ebp-138h] BYREF
  std::wstring v54; // [esp+C8h] [ebp-120h] BYREF
  std::wstring result; // [esp+E0h] [ebp-108h] BYREF
  std::wstring v56; // [esp+F8h] [ebp-F0h] BYREF
  std::wstring v57; // [esp+110h] [ebp-D8h] BYREF
  std::wstring v58; // [esp+128h] [ebp-C0h] BYREF
  Session v59; // [esp+140h] [ebp-A8h] BYREF
  int v60; // [esp+1E4h] [ebp-4h]

  v3 = Sim::getCar(this->sim, 0);
  CarAvatar::setControlsLock(v3, 1);
  this->sim->gameScreen->appInteractionEnabled = 1;
  v4 = this->comparativeTelemetry;
  if ( v4 )
  {
    ((void (*)(ComparativeTelemetry *, _DWORD, float))v4->setSize)(
      v4,
      (float)((float)this->sim->game->graphics->videoSettings.width - this->rect.right) - 20.0,
      (float)this->sim->game->graphics->videoSettings.height);
    ksgui::Form::setPosition(this->comparativeTelemetry, (float)(this->rect.right - this->rect.left) + 10.0, 0.0);
  }
  v5 = Sim::getCar(this->sim, 0)->physicsState.setupState;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( !v6 )
    {
      ksgui::Control::setVisible(this->butDriveFake, 0);
      ksgui::Control::setVisible(this->butDrive, 1);
      goto LABEL_18;
    }
    if ( v6 != 1 )
      goto LABEL_18;
    ksgui::Control::setVisible(this->butDriveFake, 1);
    std::wstring::wstring(&text, L"SETUP\nINVALID\n\nCLICK TO\nCHECK AGAIN");
    v60 = 0;
    v7 = acTranslate(&result, &text);
    v8 = this->butDriveFake;
    LOBYTE(v60) = 1;
    v8->setText(v8, v7);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v60 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  else
  {
    ksgui::Control::setVisible(this->butDriveFake, 1);
    std::wstring::wstring(&v53, L"SETUP\nVALIDATING\n\nPLEASE WAIT");
    v60 = 2;
    v9 = acTranslate(&v54, &v53);
    v10 = this->butDriveFake;
    LOBYTE(v60) = 3;
    v10->setText(v10, v9);
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    v54._Myres = 7;
    v54._Mysize = 0;
    v54._Bx._Buf[0] = 0;
    v60 = -1;
    if ( v53._Myres >= 8 )
      operator delete(v53._Bx._Ptr);
    v53._Myres = 7;
    v53._Mysize = 0;
    v53._Bx._Buf[0] = 0;
  }
  ksgui::Control::setVisible(this->butDrive, 0);
LABEL_18:
  if ( Sim::isInTripleScreenMode(this->sim) )
    ksgui::Form::setPosition((ksgui::Form *)this, (float)this->gui->graphics->videoSettings.width * 0.33333334, 0.0);
  v11 = this->gui->graphics->gl;
  GLRenderer::color4f(v11, 0.0, 0.0, 0.0, 0.69999999);
  GLRenderer::quad(
    v11,
    this->rect.left,
    this->rect.top,
    this->width,
    (float)this->gui->graphics->videoSettings.height,
    0,
    0);
  GLRenderer::color4f(v11, 0.25, 0.25, 0.25, 0.5);
  GLRenderer::begin(v11, eLines, 0);
  GLRenderer::vertex3f(v11, this->rect.right, 0.0, 0.0);
  GLRenderer::vertex3f(v11, this->rect.right, (float)this->gui->graphics->videoSettings.height, 0.0);
  GLRenderer::end(v11);
  if ( !this->sim->client )
  {
    GLRenderer::color4f(v11, 1.0, 1.0, 1.0, 1.0);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->acLogo);
    GLRenderer::quad(v11, this->rect.left, 0.0, 98.0, 98.0, 1, 0);
    goto LABEL_89;
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"SESSION", 7u);
  v60 = 4;
  acTranslate(&sessionName, &text);
  LOBYTE(v60) = 6;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v12 = this->sim;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v13 = RaceManager::getCurrentSessionType(v12->raceManager) - 1;
  if ( v13 )
  {
    v14 = v13 - 1;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        std::wstring::wstring(&v57, L"RACE");
        LOBYTE(v60) = 9;
        v16 = acTranslate(&result, &v57);
        std::wstring::operator=(&sessionName, v16);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        LOBYTE(v60) = 6;
        if ( v57._Myres >= 8 )
          operator delete(v57._Bx._Ptr);
      }
      else
      {
        std::wstring::wstring(&v58, L"SESSION");
        LOBYTE(v60) = 10;
        v15 = acTranslate(&v54, &v58);
        std::wstring::operator=(&sessionName, v15);
        if ( v54._Myres >= 8 )
          operator delete(v54._Bx._Ptr);
        v54._Myres = 7;
        v54._Mysize = 0;
        v54._Bx._Buf[0] = 0;
        LOBYTE(v60) = 6;
        if ( v58._Myres >= 8 )
          operator delete(v58._Bx._Ptr);
      }
    }
    else
    {
      std::wstring::wstring(&v56, L"QUALIFY");
      LOBYTE(v60) = 8;
      v17 = acTranslate(&v53, &v56);
      std::wstring::operator=(&sessionName, v17);
      if ( v53._Myres >= 8 )
        operator delete(v53._Bx._Ptr);
      v53._Myres = 7;
      v53._Mysize = 0;
      v53._Bx._Buf[0] = 0;
      LOBYTE(v60) = 6;
      if ( v56._Myres >= 8 )
        operator delete(v56._Bx._Ptr);
    }
  }
  else
  {
    std::wstring::wstring(&setName, L"PRACTICE");
    LOBYTE(v60) = 7;
    v18 = acTranslate(&v50, &setName);
    std::wstring::operator=(&sessionName, v18);
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    LOBYTE(v60) = 6;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
  }
  raceClosingTime = RaceManager::getTimetoWait(this->sim->raceManager);
  if ( raceClosingTime != 0.0 )
  {
    std::wstring::wstring(&setName, L"WAIT TIME");
    LOBYTE(v60) = 11;
    v11 = (GLRenderer *)acTranslate(&v50, &setName);
    if ( &sessionName != (std::wstring *)v11 )
    {
      if ( sessionName._Myres >= 8 )
        operator delete(sessionName._Bx._Ptr);
      sessionName._Myres = 7;
      sessionName._Mysize = 0;
      sessionName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&sessionName, (std::wstring *)v11);
    }
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    LOBYTE(v60) = 6;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
  }
  Font::blitString(this->font._Ptr, 50.0, 10.0, &sessionName, 0.89999998, eAlignCenter);
  if ( RaceManager::getTimeToSessionStart(this->sim->raceManager) < 5000.0
    && RaceManager::getTimeToSessionStart(this->sim->raceManager) > 0.0 )
  {
    v19 = Sim::getCar(this->sim, 0);
    if ( !CarAvatar::isInPit(v19) )
    {
      std::wstring::wstring(&setName, L"PIT");
      v20 = this->sim;
      LOBYTE(v60) = 12;
      v21 = Sim::getCar(v20, 0);
      CarAvatar::goToSpawnPosition(v21, &setName);
      LOBYTE(v60) = 6;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
      v22 = this->sim;
      g = v22->game->gameTime.now;
      v23 = Sim::getCar(v22, 0);
      CarAvatar::lockControlsUntilTime(v23, 20000.0, g, 0);
    }
  }
  if ( RaceManager::getTimeToSessionStart(this->sim->raceManager) > 0.0 )
  {
    std::wstring::wstring(&setName, L"Countdown");
    LOBYTE(v60) = 13;
    v24 = acTranslate(&v50, &setName);
    v25 = this->font._Ptr;
    LOBYTE(v60) = 14;
    Font::blitString(v25, 50.0, 40.0, v24, 0.69999999, eAlignCenter);
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    LOBYTE(v60) = 6;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    v26 = RaceManager::getTimeToSessionStart(this->sim->raceManager);
    v27 = timeToWString(&setName, (int)v26, 0, 0);
    LOBYTE(v60) = 15;
LABEL_68:
    Font::blitString(this->font._Ptr, 50.0, 60.0, v27, 1.2, eAlignCenter);
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    goto LABEL_86;
  }
  if ( raceClosingTime > 0.0 )
  {
    std::wstring::wstring(&setName, L"Countdown");
    LOBYTE(v60) = 16;
    v28 = acTranslate(&v50, &setName);
    v29 = this->font._Ptr;
    LOBYTE(v60) = 17;
    Font::blitString(v29, 50.0, 40.0, v28, 0.69999999, eAlignCenter);
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    LOBYTE(v60) = 6;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    v27 = timeToWString(&setName, (int)(raceClosingTime - this->sim->game->gameTime.now), 0, 0);
    LOBYTE(v60) = 18;
    goto LABEL_68;
  }
  std::wstring::wstring(&setName, L"Time");
  LOBYTE(v60) = 19;
  v30 = acTranslate(&v50, &setName);
  v31 = this->font._Ptr;
  LOBYTE(v60) = 20;
  Font::blitString(v31, 50.0, 40.0, v30, 0.69999999, eAlignCenter);
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  LOBYTE(v60) = 6;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  v32 = RaceManager::getCurrentSessionType(this->sim->raceManager);
  v33 = this->sim->raceManager;
  if ( v32 == Race )
  {
    v37 = RaceManager::getCurrentSession(v33, &v59)->isTimedRace;
    Session::~Session(&v59);
    v38 = this->sim->raceManager;
    if ( !v37 )
    {
      v41 = RaceManager::getCurrentSession(v38, &v59);
      v42 = this->sim;
      LOBYTE(v60) = 23;
      v43 = timeToWString(&setName, (int)(v42->game->gameTime.now - v41->startTime), 0, 0);
      v44 = this->font._Ptr;
      LOBYTE(v60) = 24;
      Font::blitString(v44, 50.0, 60.0, v43, 1.2, eAlignCenter);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
      Session::~Session(&v59);
      goto LABEL_86;
    }
    v39 = RaceManager::getSessionTimeLeft(v38);
    v40 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
    if ( v39 <= v40 )
    {
      v40 = 0.0;
      if ( v39 >= 0.0 )
        v40 = v39;
    }
    v36 = timeToWString(&setName, (int)v40, 0, 0);
    LOBYTE(v60) = 22;
  }
  else
  {
    v34 = RaceManager::getSessionTimeLeft(v33);
    v35 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
    if ( v34 <= v35 )
    {
      v35 = 0.0;
      if ( v34 >= 0.0 )
        v35 = v34;
    }
    v36 = timeToWString(&setName, (int)v35, 0, 0);
    LOBYTE(v60) = 21;
  }
  Font::blitString(this->font._Ptr, 50.0, 60.0, v36, 1.2, eAlignCenter);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
LABEL_86:
  v60 = -1;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  sessionName._Myres = 7;
  sessionName._Mysize = 0;
  sessionName._Bx._Buf[0] = 0;
LABEL_89:
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butExit,
    this->butExit->rect.left,
    (float)this->gui->graphics->videoSettings.height - (float)(this->butExit->rect.right - this->butExit->rect.left));
  ksgui::Control::render(this, (int)v11, (int)this, dt, v46, v47);
}
void ESCMenu::selectButton(ESCMenu *this, ksgui::ActiveButton *ab)
{
  ksgui::ActiveButton *v3; // ecx
  ksgui::Control *v4; // ecx

  v3 = this->lastSelected;
  if ( !v3 )
    goto LABEL_7;
  v4 = (ksgui::Control *)v3->tag;
  if ( v4 )
  {
    if ( v4->visible )
      ksgui::Control::setVisible(v4, 0);
  }
  this->lastSelected->selected = 0;
  if ( this->lastSelected == ab )
  {
    this->lastSelected = 0;
  }
  else
  {
LABEL_7:
    ab->selected = 1;
    this->lastSelected = ab;
  }
}
void ESCMenu::setDriveButtonEnabled(ESCMenu *this, bool value)
{
  this->butDrive->isActive = value;
}
void ESCMenu::setRaceControlScreen(ESCMenu *this)
{
  if ( this->lastSelected != this->butRaceControl )
  {
    ESCMenu::selectButton(this, this->butRaceControl);
    ksgui::Control::setVisible(this->raceControl, 1);
  }
}
