#include "playercurrenttime.h"
void __userpurge PlayerCurrentTime::PlayerCurrentTime(PlayerCurrentTime *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  const std::wstring *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // ebx
  Font *v8; // eax
  Texture *v9; // eax
  Texture *v10; // eax
  Texture *v11; // eax
  Texture *v12; // eax
  Texture *v13; // eax
  Texture *v14; // eax
  Texture *v15; // eax
  Font *v16; // eax
  Font *v17; // eax
  ksgui::Label *v18; // esi
  ksgui::Label *v19; // eax
  ksgui::Label *v20; // eax
  Font *v21; // eax
  Font *v22; // eax
  std::_Ref_count_base *v23; // esi
  ksgui::Label *v24; // ecx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  Font *v29; // esi
  ksgui::Label *v30; // eax
  ksgui::Label *v31; // ecx
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  Font *v36; // esi
  ksgui::Label *v37; // eax
  ksgui::Label *v38; // edx
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // ecx
  std::_Ref_count_base *v44; // esi
  _BYTE v45[28]; // [esp+0h] [ebp-94h] BYREF
  float h; // [esp+1Ch] [ebp-78h]
  int _Val; // [esp+34h] [ebp-60h] BYREF
  std::shared_ptr<Font> secondaryFont; // [esp+38h] [ebp-5Ch] BYREF
  std::shared_ptr<Font> _Right; // [esp+40h] [ebp-54h] BYREF
  PlayerCurrentTime *v50; // [esp+48h] [ebp-4Ch]
  Texture text; // [esp+4Ch] [ebp-48h] BYREF
  Texture result; // [esp+68h] [ebp-2Ch] BYREF
  int v53; // [esp+90h] [ebp-4h]

  LODWORD(h) = 1;
  v50 = this;
  *(_DWORD *)&v45[24] = aSim->game->gui;
  *(_DWORD *)&v45[20] = 7;
  *(_DWORD *)&v45[16] = 0;
  *(_WORD *)v45 = 0;
  std::wstring::assign((std::wstring *)v45, L"LAP_TIME", 8u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v45, *(ksgui::GUI **)&v45[24], SLOBYTE(h));
  v53 = 0;
  this->__vftable = (PlayerCurrentTime_vtbl *)&PlayerCurrentTime::`vftable';
  this->sim = aSim;
  this->texLast.kid = 0;
  this->texLast.fileName._Myres = 7;
  this->texLast.fileName._Mysize = 0;
  this->texLast.fileName._Bx._Buf[0] = 0;
  this->texBest.kid = 0;
  this->texBest.fileName._Myres = 7;
  this->texBest.fileName._Mysize = 0;
  this->texBest.fileName._Bx._Buf[0] = 0;
  this->texArrowDown.kid = 0;
  this->texArrowDown.fileName._Myres = 7;
  this->texArrowDown.fileName._Mysize = 0;
  this->texArrowDown.fileName._Bx._Buf[0] = 0;
  this->texArrowRight.kid = 0;
  this->texArrowRight.fileName._Myres = 7;
  this->texArrowRight.fileName._Mysize = 0;
  this->texArrowRight.fileName._Bx._Buf[0] = 0;
  this->texSectorUp.kid = 0;
  this->texSectorUp.fileName._Myres = 7;
  this->texSectorUp.fileName._Mysize = 0;
  this->texSectorUp.fileName._Bx._Buf[0] = 0;
  this->texSectorDown.kid = 0;
  this->texSectorDown.fileName._Myres = 7;
  this->texSectorDown.fileName._Mysize = 0;
  this->texSectorDown.fileName._Bx._Buf[0] = 0;
  this->texInf.kid = 0;
  this->texInf.fileName._Myres = 7;
  this->texInf.fileName._Mysize = 0;
  this->texInf.fileName._Bx._Buf[0] = 0;
  LOBYTE(v53) = 7;
  LODWORD(h) = 4;
  *(_DWORD *)&v45[24] = L"Laps";
  this->devApp = 0;
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, *(const wchar_t **)&v45[24], LODWORD(h));
  LOBYTE(v53) = 8;
  v4 = acTranslate((std::wstring *)&result, (const std::wstring *)&text);
  LOBYTE(v53) = 9;
  this->formTitle->setText(this->formTitle, v4);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v53) = 7;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  ksgui::Form::setSize(this, 295.0, 277.0);
  ksgui::Form::setAutoHideMode(this, 1);
  v5 = (Font *)operator new(0x18u);
  _Val = (int)v5;
  LOBYTE(v53) = 10;
  if ( v5 )
    Font::Font(v5, eFontProportional, 17.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v53) = 7;
  secondaryFont = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&secondaryFont, v6);
  v7 = this->font._Rep;
  this->font = secondaryFont;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Weaks, 0xFFFFFFFF) )
        v7->_Delete_this(v7);
    }
  }
  v8 = this->font._Ptr;
  LODWORD(h) = 38;
  *(_DWORD *)&v45[24] = L"content/gui/PlayerCurrentTime/last.png";
  text.fileName._Mysize = 7;
  v8->shadowed = 1;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, *(const wchar_t **)&v45[24], LODWORD(h));
  LOBYTE(v53) = 11;
  v9 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 12;
  this->texLast.kid = v9->kid;
  if ( &this->texLast.fileName != &v9->fileName )
    std::wstring::assign(&this->texLast.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 11;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, L"content/gui/PlayerCurrentTime/best.png", 0x26u);
  LOBYTE(v53) = 13;
  v10 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 14;
  this->texBest.kid = v10->kid;
  if ( &this->texBest.fileName != &v10->fileName )
    std::wstring::assign(&this->texBest.fileName, &v10->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 13;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, L"content/gui/PlayerCurrentTime/downArrow.png", 0x2Bu);
  LOBYTE(v53) = 15;
  v11 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 16;
  this->texArrowDown.kid = v11->kid;
  if ( &this->texArrowDown.fileName != &v11->fileName )
    std::wstring::assign(&this->texArrowDown.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 15;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, L"content/gui/PlayerCurrentTime/rightArrow.png", 0x2Cu);
  LOBYTE(v53) = 17;
  v12 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 18;
  this->texArrowRight.kid = v12->kid;
  if ( &this->texArrowRight.fileName != &v12->fileName )
    std::wstring::assign(&this->texArrowRight.fileName, &v12->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 17;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, L"content/gui/PlayerCurrentTime/up.png", 0x24u);
  LOBYTE(v53) = 19;
  v13 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 20;
  this->texSectorUp.kid = v13->kid;
  if ( &this->texSectorUp.fileName != &v13->fileName )
    std::wstring::assign(&this->texSectorUp.fileName, &v13->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 19;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  text.fileName._Mysize = 7;
  *(_DWORD *)&text.fileName._Bx._Alias[12] = 0;
  LOWORD(text.kid) = 0;
  std::wstring::assign((std::wstring *)&text, L"content/gui/PlayerCurrentTime/down.png", 0x26u);
  LOBYTE(v53) = 21;
  v14 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, (const std::wstring *)&text, 0);
  LOBYTE(v53) = 22;
  this->texSectorDown.kid = v14->kid;
  if ( &this->texSectorDown.fileName != &v14->fileName )
    std::wstring::assign(&this->texSectorDown.fileName, &v14->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v53) = 7;
  if ( text.fileName._Mysize >= 8 )
    operator delete(text.kid);
  std::wstring::wstring((std::wstring *)&result, L"content/gui/PlayerCurrentTime/infinity_icon.png");
  LOBYTE(v53) = 23;
  v15 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &text, (const std::wstring *)&result, 0);
  LOBYTE(v53) = 24;
  this->texInf.kid = v15->kid;
  if ( &this->texInf.fileName != &v15->fileName )
    std::wstring::assign(&this->texInf.fileName, &v15->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v53) = 23;
  OnSetupAppCreated::~OnSetupAppCreated(&text);
  LOBYTE(v53) = 7;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  v16 = (Font *)operator new(0x18u);
  _Val = (int)v16;
  LOBYTE(v53) = 25;
  if ( v16 )
    Font::Font(v16, eFontProportional, 24.0, 0, 0);
  else
    v17 = 0;
  LOBYTE(v53) = 7;
  secondaryFont._Ptr = 0;
  secondaryFont._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&secondaryFont, v17);
  LOBYTE(v53) = 26;
  LODWORD(h) = 284;
  secondaryFont._Ptr->shadowed = 1;
  v18 = (ksgui::Label *)operator new(LODWORD(h));
  _Val = (int)v18;
  LOBYTE(v53) = 27;
  if ( v18 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v45[4], L"TIME_LABEL");
    ksgui::Label::Label(v18, *(std::wstring *)&v45[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v19 = 0;
  }
  LOBYTE(v53) = 26;
  this->time = v19;
  v19->drawBackground = 0;
  ((void (*)(ksgui::Label *, _DWORD, int))this->time->setSize)(
    this->time,
    this->rect.right - this->rect.left,
    1109393408);
  v20 = this->time;
  LODWORD(h) = 24;
  v20->foreColor = (vec4f)_xmm;
  this->time->fontAlign = eAlignCenter;
  v21 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v21;
  LOBYTE(v53) = 28;
  if ( v21 )
    Font::Font(v21, eFontProportional, 32.0, 0, 0);
  else
    v22 = 0;
  LOBYTE(v53) = 26;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v22);
  std::shared_ptr<Font>::operator=(&this->time->font, &_Right);
  v23 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v23->_Destroy(v23);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v23->_Weaks, 0xFFFFFFFF) )
        v23->_Delete_this(v23);
    }
  }
  this->time->font._Ptr->shadowed = 1;
  v24 = this->time;
  v25 = v24->rectBase.left;
  v26 = v24->rect.bottom - v24->rect.top;
  v27 = v24->rect.right - v24->rect.left;
  v24->rect.top = 110.0;
  v24->rect.left = 0.0;
  v28 = v26 + 110.0;
  v24->rect.right = v27;
  v24->rect.bottom = v28;
  if ( v25 == 0.0 && v24->rectBase.top == 0.0 )
  {
    v24->rectBase.left = 0.0;
    v24->rectBase.top = 110.0;
    v24->rectBase.right = v27;
    v24->rectBase.bottom = v28;
  }
  _Val = (int)this->time;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v29 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v29;
  LOBYTE(v53) = 29;
  if ( v29 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v45[4], L"BEST_LABEL");
    ksgui::Label::Label((ksgui::Label *)v29, *(std::wstring *)&v45[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v30 = 0;
  }
  LOBYTE(v53) = 26;
  this->best = v30;
  v30->drawBackground = 0;
  ((void (*)(ksgui::Label *, _DWORD, int))this->best->setSize)(
    this->best,
    (float)(this->rect.right - this->rect.left) - 20.0,
    1109393408);
  this->best->foreColor = (vec4f)_xmm;
  this->best->fontAlign = eAlignRight;
  std::shared_ptr<Font>::operator=(&this->best->font, &secondaryFont);
  v31 = this->best;
  v32 = v31->rectBase.left;
  v33 = v31->rect.bottom - v31->rect.top;
  v34 = v31->rect.right - v31->rect.left;
  v31->rect.top = 194.0;
  v31->rect.left = 0.0;
  v35 = v33 + 194.0;
  v31->rect.right = v34;
  v31->rect.bottom = v35;
  if ( v32 == 0.0 && v31->rectBase.top == 0.0 )
  {
    v31->rectBase.left = 0.0;
    v31->rectBase.top = 194.0;
    v31->rectBase.right = v34;
    v31->rectBase.bottom = v35;
  }
  _Val = (int)this->best;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v36 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v36;
  LOBYTE(v53) = 30;
  if ( v36 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v45[4], L"LAST_LABEL");
    ksgui::Label::Label((ksgui::Label *)v36, *(std::wstring *)&v45[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v37 = 0;
  }
  LOBYTE(v53) = 26;
  this->last = v37;
  v37->drawBackground = 0;
  ((void (*)(ksgui::Label *, _DWORD, int))this->last->setSize)(
    this->last,
    (float)(this->rect.right - this->rect.left) - 20.0,
    1109393408);
  this->last->foreColor = (vec4f)_xmm;
  this->last->fontAlign = eAlignRight;
  std::shared_ptr<Font>::operator=(&this->last->font, &secondaryFont);
  v38 = this->last;
  v39 = v38->rectBase.left;
  v40 = v38->rect.bottom - v38->rect.top;
  v41 = v38->rect.right - v38->rect.left;
  v38->rect.top = 235.0;
  v38->rect.left = 0.0;
  v42 = v40 + 235.0;
  v38->rect.right = v41;
  v38->rect.bottom = v42;
  if ( v39 == 0.0 && v38->rectBase.top == 0.0 )
  {
    v38->rectBase.left = 0.0;
    v38->rectBase.top = 235.0;
    v38->rectBase.right = v41;
    v38->rectBase.bottom = v42;
  }
  _Val = (int)this->last;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  h = v43;
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(PlayerCurrentTime *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
  LOBYTE(v53) = 7;
  v44 = secondaryFont._Rep;
  if ( secondaryFont._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&secondaryFont._Rep->_Uses, 0xFFFFFFFF) )
  {
    v44->_Destroy(v44);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v44->_Weaks) )
      ((void (*)(void))v44->_Delete_this)();
  }
}
PlayerCurrentTime *PlayerCurrentTime::`vector deleting destructor'(PlayerCurrentTime *this, unsigned int a2)
{
  PlayerCurrentTime::~PlayerCurrentTime(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PlayerCurrentTime::~PlayerCurrentTime(PlayerCurrentTime *this)
{
  this->__vftable = (PlayerCurrentTime_vtbl *)&PlayerCurrentTime::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->texInf);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texSectorDown);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texSectorUp);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texArrowRight);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texArrowDown);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texBest);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texLast);
  this->__vftable = (PlayerCurrentTime_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void __userpurge PlayerCurrentTime::render(PlayerCurrentTime *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  PlayerCurrentTime_vtbl *v5; // eax
  Session *v6; // eax
  int v7; // ecx
  bool v8; // zf
  Session *v9; // eax
  const std::wstring *v10; // eax
  long double v11; // st7
  std::wstring *v12; // eax
  const std::wstring *v13; // eax
  Font *v14; // ecx
  const std::wstring *v15; // eax
  const wchar_t *v16; // eax
  Session *v17; // eax
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  vec4f v20; // xmm0
  vec4f v21; // xmm0
  Lap *v22; // eax
  const std::wstring *v23; // eax
  const std::wstring *v24; // eax
  const std::wstring *v25; // eax
  int v26; // eax
  const std::wstring *v27; // eax
  unsigned int v28; // ecx
  std::wstring *v29; // eax
  wchar_t *v30; // edx
  std::wstring *v31; // eax
  __int64 v32; // [esp+38h] [ebp-29Ch]
  float v33; // [esp+40h] [ebp-294h]
  char v34; // [esp+4Bh] [ebp-289h]
  float v35; // [esp+4Ch] [ebp-288h] BYREF
  float v36; // [esp+50h] [ebp-284h]
  GLRenderer *v37; // [esp+54h] [ebp-280h]
  unsigned int v38; // [esp+58h] [ebp-27Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+5Ch] [ebp-278h] BYREF
  Lap bestLap; // [esp+10Ch] [ebp-1C8h] BYREF
  Lap v41; // [esp+13Ch] [ebp-198h] BYREF
  std::wstring v42; // [esp+16Ch] [ebp-168h] BYREF
  Lap text; // [esp+184h] [ebp-150h] BYREF
  std::wstring s; // [esp+1B4h] [ebp-120h] BYREF
  Lap lap; // [esp+1CCh] [ebp-108h] BYREF
  Session result; // [esp+1FCh] [ebp-D8h] BYREF
  Session v47; // [esp+25Ch] [ebp-78h] BYREF
  int v48; // [esp+2D0h] [ebp-4h]

  text.time = 0;
  v4 = Sim::getFocusedCarIndex(this->sim);
  this->car = Sim::getCar(this->sim, v4);
  v37 = this->gui->graphics->gl;
  ksgui::Control::render(this, a2, (int)this, dt, v32, v33);
  PlayerCurrentTime::renderBackground(this);
  v5 = this->__vftable;
  *(_QWORD *)&text.time = 0i64;
  v5->localToWorld(this, (vec2f *)&v35, (const vec2f *)&text);
  v6 = RaceManager::getCurrentSession(this->sim->raceManager, &result);
  v48 = 0;
  v7 = 1;
  v8 = v6->sessionType == Race;
  v38 = 1;
  text.time = 1;
  if ( !v8
    || (v9 = RaceManager::getCurrentSession(this->sim->raceManager, &v47), v7 = 3, v34 = 1, v38 = 3, !v9->isTimedRace) )
  {
    v34 = 0;
  }
  if ( (v7 & 2) != 0 )
  {
    v38 = v7 & 0xFFFFFFFD;
    Session::~Session(&v47);
    v7 = v38;
  }
  v48 = -1;
  if ( (v7 & 1) != 0 )
  {
    v38 = v7 & 0xFFFFFFFE;
    Session::~Session(&result);
  }
  *(_DWORD *)&text.isValid = 7;
  text.cuts = 0;
  LOWORD(text.time) = 0;
  if ( v34 )
  {
    std::wstring::assign((std::wstring *)&text, L"Total Time", 0xAu);
    v48 = 1;
    v10 = acTranslate(&v42, (const std::wstring *)&text);
    LOBYTE(v48) = 2;
  }
  else
  {
    std::wstring::assign((std::wstring *)&text, L"Current lap", 0xBu);
    v48 = 3;
    v10 = acTranslate(&v42, (const std::wstring *)&text);
    LOBYTE(v48) = 4;
  }
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 10.0) + v35,
    (float)(this->scaleMult * 60.0) + v36,
    v10,
    this->scaleMult,
    eAlignLeft);
  if ( v42._Myres >= 8 )
    operator delete(v42._Bx._Ptr);
  v48 = -1;
  v42._Bx._Buf[0] = 0;
  v42._Mysize = 0;
  v42._Myres = 7;
  if ( *(_DWORD *)&text.isValid >= 8u )
    operator delete((void *)text.time);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texArrowRight);
  GLRenderer::color4f(v37, 1.0, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v37,
    (float)(this->scaleMult * 100.0) + v35,
    (float)(this->scaleMult * 68.0) + v36,
    this->scaleMult * 11.0,
    this->scaleMult * 13.0,
    1,
    0);
  *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v39.gap68);
  v48 = 5;
  text.time = v38 | 4;
  std::wiostream::basic_iostream<wchar_t>(&v39, &v39.gap10[8], 0);
  v48 = 6;
  *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(unsigned int *)((char *)&v38 + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v39.gap10[8]);
  *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v39.gap10[64] = 0;
  *(_DWORD *)&v39.gap10[68] = 0;
  v48 = 8;
  if ( v34 )
  {
    *(double *)&text.time = RaceManager::getTimeToSessionStart(this->sim->raceManager);
    if ( *(double *)&text.time >= 0.0 )
      goto LABEL_35;
    v11 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
    v12 = timeToWString(&v42, (int)v11, 0, 0);
    LOBYTE(v48) = 9;
    if ( v12->_Myres >= 8 )
      v12 = (std::wstring *)v12->_Bx._Ptr;
    std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v39.gap10, v12->_Bx._Buf);
    LOBYTE(v48) = 8;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v42);
    LOBYTE(v48) = 10;
    Font::blitString(
      this->font._Ptr,
      (float)((float)(this->rect.right - this->rect.left) + v35) - (float)(this->scaleMult * 10.0),
      (float)(this->scaleMult * 35.0) + v36,
      v13,
      this->scaleMult * 2.8,
      eAlignRight);
  }
  else
  {
    std::wostream::operator<<(v39.gap10, this->car->physicsState.lapCount + 1);
    v14 = this->font._Ptr;
    *(_OWORD *)&text.time = _xmm;
    Font::setColor(v14, (const vec4f *)&text);
    v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v42);
    LOBYTE(v48) = 11;
    Font::blitString(
      this->font._Ptr,
      (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + v35) + (float)(this->scaleMult * 45.0),
      (float)(this->scaleMult * 35.0) + v36,
      v15,
      this->scaleMult * 3.0,
      eAlignCenter);
    LOBYTE(v48) = 8;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, word_17BE9D8, 0);
    LOBYTE(v48) = 12;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v39.gap10[8]);
    v16 = (const wchar_t *)&text;
    if ( *(_DWORD *)&text.isValid >= 8u )
      v16 = (const wchar_t *)text.time;
    std::wstringbuf::_Init((std::wstringbuf *)&v39.gap10[8], v16, text.cuts, *(int *)&v39.gap10[68]);
    LOBYTE(v48) = 8;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, L"/", 1u);
    LOBYTE(v48) = 13;
    Font::blitString(
      this->font._Ptr,
      (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + v35) + (float)(this->scaleMult * 75.0),
      (float)(this->scaleMult * 60.0) + v36,
      (const std::wstring *)&text,
      this->scaleMult * 1.1,
      eAlignLeft);
    LOBYTE(v48) = 8;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
    if ( RaceManager::getCurrentSessionType(this->sim->raceManager) != Race )
    {
      GraphicsManager::setTexture(this->gui->graphics, 0, &this->texInf);
      GLRenderer::color4f(v37, 1.0, 1.0, 1.0, 1.0);
      GLRenderer::quad(
        v37,
        (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + v35) + (float)(this->scaleMult * 90.0),
        (float)(this->scaleMult * 68.0) + v36,
        this->scaleMult * 29.0,
        this->scaleMult * 17.0,
        1,
        0);
      goto LABEL_35;
    }
    v17 = RaceManager::getCurrentSession(this->sim->raceManager, &result);
    LOBYTE(v48) = 14;
    std::wostream::operator<<(v39.gap10, v17->laps);
    LOBYTE(v48) = 8;
    Session::~Session(&result);
    v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v42);
    LOBYTE(v48) = 15;
    Font::blitString(
      this->font._Ptr,
      (float)((float)((float)(this->rect.right - this->rect.left) * 0.5) + v35) + (float)(this->scaleMult * 100.0),
      (float)(this->scaleMult * 60.0) + v36,
      v18,
      this->scaleMult * 1.1,
      eAlignCenter);
  }
  LOBYTE(v48) = 8;
  if ( v42._Myres >= 8 )
    operator delete(v42._Bx._Ptr);
LABEL_35:
  *(_DWORD *)&text.isValid = 7;
  text.cuts = 0;
  LOWORD(text.time) = 0;
  std::wstring::assign((std::wstring *)&text, L"Lap Time", 8u);
  LOBYTE(v48) = 16;
  v19 = acTranslate(&v42, (const std::wstring *)&text);
  LOBYTE(v48) = 17;
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 10.0) + v35,
    (float)(this->scaleMult * 80.0) + v36,
    v19,
    this->scaleMult,
    eAlignLeft);
  if ( v42._Myres >= 8 )
    operator delete(v42._Bx._Ptr);
  LOBYTE(v48) = 8;
  v42._Myres = 7;
  v42._Mysize = 0;
  v42._Bx._Buf[0] = 0;
  if ( *(_DWORD *)&text.isValid >= 8u )
    operator delete((void *)text.time);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texArrowDown);
  GLRenderer::color4f(v37, 1.0, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v37,
    (float)(this->scaleMult * 100.0) + v35,
    (float)(this->scaleMult * 87.0) + v36,
    this->scaleMult * 13.0,
    this->scaleMult * 13.0,
    1,
    0);
  RaceManager::getCurrentLap(this->sim->raceManager, &lap, this->car);
  LOBYTE(v48) = 18;
  RaceManager::getBestLap(this->sim->raceManager, &bestLap, this->car);
  LOBYTE(v48) = 19;
  RaceManager::getLastLap(this->sim->raceManager, &v41, this->car);
  LOBYTE(v48) = 20;
  if ( CarAvatar::isCurrentLapValid(this->car) )
    v20 = (vec4f)_xmm;
  else
    v20 = (vec4f)_xmm;
  this->time->foreColor = v20;
  if ( !v41.time || v41.isValid )
    v21 = (vec4f)_xmm;
  else
    v21 = (vec4f)_xmm;
  this->last->foreColor = v21;
  if ( lap.time )
  {
    v22 = RaceManager::getCurrentLap(this->sim->raceManager, &text, this->car);
    LOBYTE(v48) = 21;
    v23 = timeToString(&v42, v22->time, 3);
    LOBYTE(v48) = 22;
    this->time->setText(this->time, v23);
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    LOBYTE(v48) = 20;
    Lap::~Lap(&text);
  }
  else
  {
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, L"00:00:000", 9u);
    LOBYTE(v48) = 23;
    this->time->setText(this->time, (const std::wstring *)&text);
    LOBYTE(v48) = 20;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
  }
  if ( v41.time )
  {
    v24 = timeToString(&v42, v41.time, 3);
    LOBYTE(v48) = 24;
    this->last->setText(this->last, v24);
    LOBYTE(v48) = 20;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
  }
  else
  {
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, L"--:--:--", 8u);
    LOBYTE(v48) = 25;
    this->last->setText(this->last, (const std::wstring *)&text);
    LOBYTE(v48) = 20;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
  }
  if ( bestLap.time )
  {
    v25 = timeToString(&v42, bestLap.time, 3);
    LOBYTE(v48) = 26;
    this->best->setText(this->best, v25);
    LOBYTE(v48) = 20;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
  }
  else
  {
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, L"--:--:--", 8u);
    LOBYTE(v48) = 27;
    this->best->setText(this->best, (const std::wstring *)&text);
    LOBYTE(v48) = 20;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
  }
  v26 = RaceManager::getSplit(this->sim->raceManager, this->car);
  PlayerCurrentTime::getSectorSplitsString(this, &s, &lap, &bestLap, v26);
  LOBYTE(v48) = 28;
  if ( std::wstring::compare(&s, 0, s._Mysize, word_17BE9D8, 0) )
  {
    *(_DWORD *)&text.isValid = 7;
    text.cuts = 0;
    LOWORD(text.time) = 0;
    std::wstring::assign((std::wstring *)&text, L"Split from", 0xAu);
    LOBYTE(v48) = 29;
    v27 = acTranslate(&v42, (const std::wstring *)&text);
    LOBYTE(v48) = 30;
    Font::blitString(
      this->font._Ptr,
      (float)(this->scaleMult * 10.0) + v35,
      (float)(this->scaleMult * 165.0) + v36,
      v27,
      this->scaleMult * 0.89999998,
      eAlignLeft);
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    LOBYTE(v48) = 28;
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    if ( *(_DWORD *)&text.isValid >= 8u )
      operator delete((void *)text.time);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->texArrowDown);
    GLRenderer::color4f(v37, 1.0, 1.0, 1.0, 1.0);
    GLRenderer::quad(
      v37,
      (float)(this->scaleMult * 95.0) + v35,
      (float)(this->scaleMult * 170.0) + v36,
      this->scaleMult * 13.0,
      this->scaleMult * 13.0,
      1,
      0);
    v28 = s._Myres;
    v29 = &s;
    v30 = s._Bx._Ptr;
    if ( s._Myres >= 8 )
      v29 = (std::wstring *)s._Bx._Ptr;
    if ( v29->_Bx._Buf[0] == 43 )
    {
      Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
      GraphicsManager::setTexture(this->gui->graphics, 0, &this->texSectorDown);
      v28 = s._Myres;
      v30 = s._Bx._Ptr;
    }
    v31 = &s;
    if ( v28 >= 8 )
      v31 = (std::wstring *)v30;
    if ( v31->_Bx._Buf[0] == 45 )
    {
      Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
      GraphicsManager::setTexture(this->gui->graphics, 0, &this->texSectorUp);
    }
    GLRenderer::quad(
      v37,
      this->rect.right - (float)(this->scaleMult * 40.0),
      (float)(this->scaleMult * 167.0) + v36,
      this->scaleMult * 18.0,
      this->scaleMult * 17.0,
      1,
      0);
    Font::blitString(
      this->font._Ptr,
      this->rect.right - (float)(this->scaleMult * 50.0),
      (float)(this->scaleMult * 163.0) + v36,
      &s,
      this->scaleMult,
      eAlignRight);
  }
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( v41.compound._Myres >= 8 )
    operator delete(v41.compound._Bx._Ptr);
  v41.compound._Myres = 7;
  v41.compound._Bx._Buf[0] = 0;
  v41.compound._Mysize = 0;
  if ( v41.splits._Myfirst )
  {
    operator delete(v41.splits._Myfirst);
    v41.splits._Myfirst = 0;
    v41.splits._Mylast = 0;
    v41.splits._Myend = 0;
  }
  LOBYTE(v48) = 18;
  if ( bestLap.compound._Myres >= 8 )
    operator delete(bestLap.compound._Bx._Ptr);
  bestLap.compound._Myres = 7;
  bestLap.compound._Mysize = 0;
  bestLap.compound._Bx._Buf[0] = 0;
  if ( bestLap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&bestLap.splits);
    operator delete(bestLap.splits._Myfirst);
    bestLap.splits._Myfirst = 0;
    bestLap.splits._Mylast = 0;
    bestLap.splits._Myend = 0;
  }
  LOBYTE(v48) = 8;
  if ( lap.compound._Myres >= 8 )
    operator delete(lap.compound._Bx._Ptr);
  lap.compound._Myres = 7;
  lap.compound._Mysize = 0;
  lap.compound._Bx._Buf[0] = 0;
  if ( lap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lap.splits);
    operator delete(lap.splits._Myfirst);
    lap.splits._Myfirst = 0;
    lap.splits._Mylast = 0;
    lap.splits._Myend = 0;
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v39);
}
std::wstring *PlayerCurrentTime::getSectorSplitsString(PlayerCurrentTime *this, std::wstring *result, Lap *lap, Lap *bestLap, int bestLapSplit)
{
  unsigned int v5; // ebx
  unsigned int *v7; // eax
  int v8; // edx
  unsigned int *v9; // ebp
  int v10; // edi
  unsigned int *v11; // esi

  v5 = lap->time;
  if ( !lap->time )
  {
    if ( bestLap->time )
      goto LABEL_6;
    if ( bestLapSplit <= 0 )
    {
LABEL_4:
      std::wstring::wstring(result, word_17BE9D8);
      return result;
    }
  }
  if ( !bestLap->time )
    goto LABEL_14;
LABEL_6:
  if ( lap->splits._Mylast - lap->splits._Myfirst > (unsigned int)(bestLap->splits._Mylast - bestLap->splits._Myfirst) )
    goto LABEL_14;
  if ( v5 >= 0x1B58 )
  {
    v7 = lap->splits._Myfirst;
    v8 = 0;
    v9 = lap->splits._Mylast;
    v10 = 0;
    if ( v7 != v9 )
    {
      v11 = bestLap->splits._Myfirst;
      while ( 1 )
      {
        v8 += *v7;
        v10 += *v11;
        if ( v5 - v8 < 0x1B58 )
          break;
        ++v7;
        ++v11;
        if ( v7 == v9 )
          goto LABEL_14;
      }
      timeToDiffString(result, v8 - v10, 3);
      return result;
    }
LABEL_14:
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
    return result;
  }
  if ( this->car->physicsState.lapCount <= 1 )
    goto LABEL_4;
  timeToDiffString(result, bestLapSplit, 3);
  return result;
}
void PlayerCurrentTime::renderBackground(PlayerCurrentTime *this)
{
  ksgui::GUI *v2; // eax
  GraphicsManager *v3; // eax
  GLRenderer *v4; // ebx
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  vec2f off; // [esp+34h] [ebp-D0h] BYREF
  int v10[2]; // [esp+3Ch] [ebp-C8h] BYREF
  vec4f lineColor; // [esp+44h] [ebp-C0h] BYREF
  vec4f backColor; // [esp+54h] [ebp-B0h] BYREF
  std::wstring text; // [esp+64h] [ebp-A0h] BYREF
  std::wstring v14; // [esp+7Ch] [ebp-88h] BYREF
  std::wstring result; // [esp+94h] [ebp-70h] BYREF
  std::wstring v16; // [esp+ACh] [ebp-58h] BYREF
  std::wstring v17; // [esp+C4h] [ebp-40h] BYREF
  std::wstring v18; // [esp+DCh] [ebp-28h] BYREF
  int v19; // [esp+100h] [ebp-4h]

  v2 = this->gui;
  v10[0] = 0;
  v3 = v2->graphics;
  v10[1] = 0;
  v4 = v3->gl;
  this->localToWorld(this, &off, (const vec2f *)v10);
  lineColor = (vec4f)_xmm;
  backColor = (vec4f)_xmm;
  GLRenderer::color4f(v4, &lineColor);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, off.x, (float)(this->scaleMult * 110.0) + off.y, 0.0);
  GLRenderer::vertex3f(
    v4,
    (float)(this->rect.right - this->rect.left) + off.x,
    (float)(this->scaleMult * 110.0) + off.y,
    0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &backColor);
  GLRenderer::quad(
    v4,
    off.x,
    (float)(this->scaleMult * 111.0) + off.y,
    this->rect.right - this->rect.left,
    this->scaleMult * 40.0,
    0,
    0);
  GLRenderer::color4f(v4, &lineColor);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, off.x, (float)(this->scaleMult * 152.0) + off.y, 0.0);
  GLRenderer::vertex3f(
    v4,
    (float)(this->rect.right - this->rect.left) + off.x,
    (float)(this->scaleMult * 152.0) + off.y,
    0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &lineColor);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, off.x, (float)(this->scaleMult * 192.0) + off.y, 0.0);
  GLRenderer::vertex3f(
    v4,
    (float)(this->rect.right - this->rect.left) + off.x,
    (float)(this->scaleMult * 192.0) + off.y,
    0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &backColor);
  GLRenderer::quad(
    v4,
    off.x,
    (float)(this->scaleMult * 193.0) + off.y,
    this->rect.right - this->rect.left,
    this->scaleMult * 40.0,
    0,
    0);
  GLRenderer::color4f(v4, &lineColor);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, off.x, (float)(this->scaleMult * 235.0) + off.y, 0.0);
  GLRenderer::vertex3f(
    v4,
    (float)(this->rect.right - this->rect.left) + off.x,
    (float)(this->scaleMult * 235.0) + off.y,
    0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &backColor);
  GLRenderer::quad(
    v4,
    off.x,
    (float)(this->scaleMult * 235.0) + off.y,
    this->rect.right - this->rect.left,
    this->scaleMult * 40.0,
    0,
    0);
  GLRenderer::color4f(v4, &lineColor);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, off.x, (float)(this->scaleMult * 276.0) + off.y, 0.0);
  GLRenderer::vertex3f(
    v4,
    (float)(this->rect.right - this->rect.left) + off.x,
    (float)(this->scaleMult * 276.0) + off.y,
    0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texBest);
  GLRenderer::quad(
    v4,
    (float)(this->scaleMult * 5.0) + off.x,
    (float)(this->scaleMult * 196.0) + off.y,
    this->scaleMult * 27.0,
    this->scaleMult * 31.0,
    1,
    0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Best", 4u);
  v19 = 0;
  v5 = acTranslate(&result, &text);
  LOBYTE(v19) = 1;
  v6 = std::operator+<wchar_t>(&v17, v5, L" :");
  LOBYTE(v19) = 2;
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 55.0) + off.x,
    (float)(this->scaleMult * 201.0) + off.y,
    v6,
    this->scaleMult,
    eAlignLeft);
  if ( v17._Myres >= 8 )
    operator delete(v17._Bx._Ptr);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v19 = -1;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  GLRenderer::color4f(v4, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texLast);
  GLRenderer::quad(
    v4,
    (float)(this->scaleMult * 5.0) + off.x,
    (float)(this->scaleMult * 238.0) + off.y,
    this->scaleMult * 27.0,
    this->scaleMult * 31.0,
    1,
    0);
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  std::wstring::assign(&v14, L"Last", 4u);
  v19 = 3;
  v7 = acTranslate(&v18, &v14);
  LOBYTE(v19) = 4;
  v8 = std::operator+<wchar_t>(&v16, v7, L" :");
  LOBYTE(v19) = 5;
  Font::blitString(
    this->font._Ptr,
    (float)(this->scaleMult * 55.0) + off.x,
    (float)(this->scaleMult * 243.0) + off.y,
    v8,
    this->scaleMult,
    eAlignLeft);
  if ( v16._Myres >= 8 )
    operator delete(v16._Bx._Ptr);
  v16._Myres = 7;
  v16._Mysize = 0;
  v16._Bx._Buf[0] = 0;
  if ( v18._Myres >= 8 )
    operator delete(v18._Bx._Ptr);
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
}
