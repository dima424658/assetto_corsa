#include "drivethroughpenaltyavatar.h"
void DriveThroughPenaltyAvatar::DriveThroughPenaltyAvatar(DriveThroughPenaltyAvatar *this, Sim *sim)
{
  char v3; // bl
  Font *v4; // eax
  Font *v5; // eax
  Font *v6; // edi
  Font *v7; // eax
  Font *v8; // eax
  Game *v9; // eax
  unsigned int v10; // eax
  ksgui::Control *v11; // edi
  Game *v12; // eax
  ksgui::Control *v13; // eax
  ksgui::Control *v14; // ecx
  std::wstring *v15; // ecx
  unsigned int v16; // edi
  unsigned int v17; // edx
  ksgui::Control *v18; // ecx
  ksgui::Control_vtbl *v19; // eax
  float v20; // xmm0_4
  ksgui::Control *v21; // eax
  std::wstring v22; // [esp-4h] [ebp-98h] BYREF
  float top; // [esp+14h] [ebp-80h]
  int v24; // [esp+2Ch] [ebp-68h]
  ksgui::Control *v25; // [esp+30h] [ebp-64h]
  DriveThroughPenaltyAvatar *v26; // [esp+34h] [ebp-60h]
  std::wstring filename; // [esp+38h] [ebp-5Ch] BYREF
  Texture t; // [esp+50h] [ebp-44h] BYREF
  std::wstring iname; // [esp+6Ch] [ebp-28h] BYREF
  int v30; // [esp+90h] [ebp-4h]

  v3 = 0;
  v24 = 0;
  v26 = this;
  top = *(float *)&sim->game;
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  std::wstring::assign(&v22, L"DT_PENALTY_AVATAR", 0x11u);
  GameObject::GameObject(this, v22, (Game *)LODWORD(top));
  this->__vftable = (DriveThroughPenaltyAvatar_vtbl *)&DriveThroughPenaltyAvatar::`vftable';
  this->sim = sim;
  v30 = 0;
  this->font._Myptr = 0;
  LOBYTE(v30) = 1;
  v4 = (Font *)operator new(24);
  v24 = (int)v4;
  LOBYTE(v30) = 2;
  if ( v4 )
    Font::Font(v4, eFontProportional, 15.0, 0, 0);
  else
    v5 = 0;
  v6 = this->font._Myptr;
  LOBYTE(v30) = 1;
  this->font._Myptr = v5;
  if ( v6 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v6);
    operator delete(v6);
  }
  v7 = this->font._Myptr;
  LODWORD(top) = 29;
  v22._Myres = (unsigned int)L"content/gui/flags/penalty.png";
  filename._Myres = 7;
  v7->shadowed = 1;
  v8 = this->font._Myptr;
  filename._Mysize = 0;
  v8->shadowPixelDistance = 1.0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v22._Myres, LODWORD(top));
  v9 = this->game;
  LOBYTE(v30) = 3;
  ResourceStore::getTexture(v9->graphics->resourceStore._Myptr, &t, &filename, 0);
  LOBYTE(v30) = 5;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Bx._Buf[0] = 0;
  filename._Mysize = 0;
  if ( t.kid )
    v10 = kglTextureGetHeight(t.kid);
  else
    v10 = 0;
  this->textPos = (float)(v10 + 20) + this->textPos;
  if ( sim->isVrConnected )
  {
    v11 = (ksgui::Control *)operator new(280);
    v25 = v11;
    LOBYTE(v30) = 6;
    if ( v11 )
    {
      std::wstring::wstring(&iname, L"FLAG_DT");
      v12 = sim->game;
      v3 = 1;
      LOBYTE(v30) = 7;
      v24 = 1;
      ksgui::Control::Control(v11, &iname, v12->gui);
    }
    else
    {
      v13 = 0;
    }
    this->flag = v13;
    v30 = 5;
    if ( (v3 & 1) != 0 && iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    v14 = this->flag;
    v14->backTexture.kid = t.kid;
    v15 = &v14->backTexture.fileName;
    if ( v15 != &t.fileName )
      std::wstring::assign(v15, &t.fileName, 0, 0xFFFFFFFF);
    if ( t.kid )
    {
      v16 = kglTextureGetHeight(t.kid);
      if ( t.kid )
      {
        v17 = kglTextureGetWidth(t.kid);
LABEL_25:
        v18 = this->flag;
        v19 = v18->__vftable;
        v20 = (float)v16;
        *(float *)&v22._Myres = (float)v17;
        ((void (*)(ksgui::Control *, unsigned int, _DWORD))v19->setSize)(v18, v22._Myres, LODWORD(v20));
        v21 = this->flag;
        LODWORD(top) = 1;
        v21->drawBackground = 0;
        this->flag->drawBorder = 0;
        ksgui::Control::setVisible(this->flag, SLODWORD(top));
        ksgui::Form::setPosition(
          (ksgui::Form *)this->flag,
          (float)(this->game->graphics->videoSettings.width / 2 - 160),
          (float)(this->game->graphics->videoSettings.height / 2 - 245));
        goto LABEL_26;
      }
    }
    else
    {
      v16 = 0;
    }
    v17 = 0;
    goto LABEL_25;
  }
LABEL_26:
  Font::setColor(this->font._Myptr, 1.0, 0.0, 0.0, 1.0);
  LOBYTE(v30) = 1;
  OnSetupAppCreated::~OnSetupAppCreated(&t);
}
DriveThroughPenaltyAvatar *DriveThroughPenaltyAvatar::`vector deleting destructor'(DriveThroughPenaltyAvatar *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (DriveThroughPenaltyAvatar_vtbl *)&DriveThroughPenaltyAvatar::`vftable';
  v3 = this->font._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DriveThroughPenaltyAvatar::renderHUD(DriveThroughPenaltyAvatar *this, float deltaT)
{
  Sim *v3; // ecx
  Sim *v4; // ecx
  const std::wstring *v5; // eax
  GraphicsManager *v6; // esi
  Font *v7; // ecx
  std::wstring *v8; // esi
  Sim *v9; // ecx
  CarAvatar *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  const std::wstring *v13; // eax
  GraphicsManager *v14; // esi
  Font *v15; // ecx
  Game *v16; // eax
  float y; // xmm0_4
  Font *v18; // ecx
  unsigned int v19; // edx
  std::wstring *v20; // esi
  Sim *v21; // ecx
  CarAvatar *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  unsigned int v26; // edx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v27; // ecx
  const std::wstring *v28; // eax
  float v29; // xmm0_4
  Font *v30; // ecx
  std::wstring *v31; // esi
  Sim *v32; // ecx
  CarAvatar *v33; // eax
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  const std::wstring *v36; // eax
  float v37; // xmm0_4
  Font *v38; // ecx
  const std::wstring *v39; // [esp+8h] [ebp-118h]
  std::wstring text; // [esp+20h] [ebp-100h] BYREF
  std::wstring v41; // [esp+38h] [ebp-E8h] BYREF
  std::wstring result; // [esp+50h] [ebp-D0h] BYREF
  std::wstring v43; // [esp+68h] [ebp-B8h] BYREF
  std::wstring v44; // [esp+80h] [ebp-A0h] BYREF
  std::wstring v45; // [esp+98h] [ebp-88h] BYREF
  std::wstring v46; // [esp+B0h] [ebp-70h] BYREF
  std::wstring v47; // [esp+C8h] [ebp-58h] BYREF
  std::wstring v48; // [esp+E0h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v49; // [esp+F8h] [ebp-28h] BYREF
  int v50; // [esp+11Ch] [ebp-4h]

  if ( Sim::getCar(this->sim, 0)->physics->penaltyManager.pitPenaltyLaps > 0
    && !ReplayManager::isInReplaymode(this->sim->replayManager) )
  {
    v3 = this->sim;
    if ( !v3->pauseMenu->visible && !v3->escMenu->visible && !Sim::getCar(v3, 0)->isBlackFlagged )
    {
      v4 = this->sim;
      if ( v4->isVrConnected )
      {
        std::wstring::wstring(&text, L"DRIVE THROUGH PENALTY");
        v50 = 0;
        v5 = acTranslate(&result, &text);
        v6 = this->game->graphics;
        v7 = this->font._Myptr;
        LOBYTE(v50) = 1;
        Font::blitString(
          v7,
          (float)(v6->videoSettings.width / 2 + 40),
          (float)(v6->videoSettings.height / 2 - 250),
          v5,
          1.0,
          eAlignCenter);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        v50 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        std::wstring::wstring(&text, L"LAPS REMAINING");
        v50 = 2;
        v8 = acTranslate(&v41, &text);
        v9 = this->sim;
        LOBYTE(v50) = 3;
        v10 = Sim::getCar(v9, 0);
        v11 = std::to_wstring(&v43, v10->physics->penaltyManager.pitPenaltyLaps - 1);
        LOBYTE(v50) = 4;
        v12 = std::operator+<wchar_t>(&v44, v11, L" ");
        LOBYTE(v50) = 5;
        v13 = std::operator+<wchar_t>(&result, v12, v8);
        v14 = this->game->graphics;
        v15 = this->font._Myptr;
        LOBYTE(v50) = 6;
        Font::blitString(
          v15,
          (float)(v14->videoSettings.width / 2 + 40),
          (float)(v14->videoSettings.height / 2 - 230),
          v13,
          1.0,
          eAlignCenter);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v41);
        v50 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        ((void (*)(ksgui::Control *, _DWORD))this->flag->render)(this->flag, LODWORD(deltaT));
      }
      else
      {
        if ( Sim::isInTripleScreenMode(v4) )
        {
          std::wstring::wstring(&text, L"DRIVE THROUGH PENALTY");
          v50 = 7;
          v39 = acTranslate(&v41, &text);
          v16 = this->game;
          y = this->textPos;
          v18 = this->font._Myptr;
          LOBYTE(v50) = 8;
          v19 = (unsigned __int64)(1431655766i64 * v16->graphics->videoSettings.width) >> 32;
          Font::blitString(v18, (float)(int)(v19 + (v19 >> 31) + 15), y, v39, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v41);
          v50 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          std::wstring::wstring(&text, L"LAPS REMAINING");
          v50 = 9;
          v20 = acTranslate(&result, &text);
          v21 = this->sim;
          LOBYTE(v50) = 10;
          v22 = Sim::getCar(v21, 0);
          v23 = std::to_wstring(&v44, v22->physics->penaltyManager.pitPenaltyLaps - 1);
          LOBYTE(v50) = 11;
          v24 = std::operator+<wchar_t>(&v43, v23, L" ");
          LOBYTE(v50) = 12;
          v25 = std::operator+<wchar_t>(&v41, v24, v20);
          LOBYTE(v50) = 13;
          v26 = (unsigned __int64)(1431655766i64 * this->game->graphics->videoSettings.width) >> 32;
          Font::blitString(
            this->font._Myptr,
            (float)(int)(v26 + (v26 >> 31) + 15),
            this->textPos + 20.0,
            v25,
            1.0,
            eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v41);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v27 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
        }
        else
        {
          std::wstring::wstring(&text, L"DRIVE THROUGH PENALTY");
          v50 = 14;
          v28 = acTranslate(&v41, &text);
          v29 = this->textPos;
          v30 = this->font._Myptr;
          LOBYTE(v50) = 15;
          Font::blitString(v30, 15.0, v29, v28, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v41);
          v50 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          std::wstring::wstring(&v45, L"LAPS REMAINING");
          v50 = 16;
          v31 = acTranslate(&v49.name, &v45);
          v32 = this->sim;
          LOBYTE(v50) = 17;
          v33 = Sim::getCar(v32, 0);
          v34 = std::to_wstring(&v47, v33->physics->penaltyManager.pitPenaltyLaps - 1);
          LOBYTE(v50) = 18;
          v35 = std::operator+<wchar_t>(&v48, v34, L" ");
          LOBYTE(v50) = 19;
          v36 = std::operator+<wchar_t>(&v46, v35, v31);
          v37 = this->textPos + 20.0;
          v38 = this->font._Myptr;
          LOBYTE(v50) = 20;
          Font::blitString(v38, 15.0, v37, v36, 1.0, eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v46);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v48);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v47);
          std::wstring::~wstring(&v49);
          v27 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v45;
        }
        std::wstring::~wstring(v27);
      }
    }
  }
}
