#include "systemnotification.h"
void SystemNotification::SystemNotification(SystemNotification *this, Sim *aSim)
{
  int v3; // ebx
  Game *v4; // eax
  ksgui::Taskbar *v5; // eax
  bool v6; // al
  int v7; // ebx
  char v8; // al
  double v9; // st7
  bool v10; // cf
  int v11; // ebx
  char v12; // al
  double v13; // st7
  bool v14; // al
  int v15; // ebx
  char v16; // al
  ksgui::Control *v17; // esi
  ksgui::Control *v18; // eax
  Sim *v19; // eax
  Game *v20; // eax
  Game *v21; // eax
  float v22; // xmm0_4
  unsigned int v23; // eax
  unsigned int v24; // ecx
  GraphicsManager *v25; // eax
  ksgui::Control *v26; // ecx
  std::wstring *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // edx
  float v30; // xmm0_4
  ksgui::Control *v31; // eax
  ksgui::Control *v32; // eax
  ksgui::Control *v33; // esi
  ksgui::Control *v34; // eax
  Sim *v35; // eax
  ksgui::Control *v36; // ecx
  ksgui::Control_vtbl *v37; // eax
  ksgui::Control *v38; // ecx
  ksgui::Control_vtbl *v39; // eax
  GraphicsManager *v40; // eax
  ksgui::Form *v41; // ecx
  ksgui::Control *v42; // eax
  Font *v43; // esi
  Font *v44; // eax
  std::_Ref_count_base *v45; // esi
  ksgui::Control *v46; // eax
  Font *v47; // esi
  ksgui::ProgressBar *v48; // eax
  ksgui::ProgressBar *v49; // ecx
  float v50; // xmm0_4
  ksgui::ProgressBar_vtbl *v51; // eax
  ksgui::Form *v52; // ecx
  GraphicsManager *v53; // eax
  ksgui::ProgressBar *v54; // eax
  Font *v55; // esi
  ksgui::ProgressBar *v56; // eax
  ksgui::ProgressBar *v57; // ecx
  float v58; // xmm0_4
  ksgui::ProgressBar_vtbl *v59; // eax
  ksgui::ProgressBar *v60; // eax
  std::wstring v61; // [esp+28h] [ebp-104h] BYREF
  float top; // [esp+40h] [ebp-ECh]
  char v63; // [esp+5Bh] [ebp-D1h]
  int v64; // [esp+5Ch] [ebp-D0h]
  float v65; // [esp+60h] [ebp-CCh]
  float v66; // [esp+64h] [ebp-C8h]
  std::shared_ptr<Font> _Right; // [esp+68h] [ebp-C4h] BYREF
  SystemNotification *v68; // [esp+70h] [ebp-BCh]
  std::wstring section; // [esp+74h] [ebp-B8h] BYREF
  std::wstring key; // [esp+8Ch] [ebp-A0h] BYREF
  std::wstring str; // [esp+A4h] [ebp-88h] BYREF
  Texture t; // [esp+BCh] [ebp-70h] BYREF
  INIReaderDocuments ini; // [esp+D8h] [ebp-54h] BYREF
  int v74; // [esp+128h] [ebp-4h]

  v3 = 0;
  v64 = 0;
  v68 = this;
  top = *(float *)&aSim->game;
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  std::wstring::assign(&v61, L"SYSTEM_NOTIFICATION", 0x13u);
  GameObject::GameObject(this, v61, (Game *)LODWORD(top));
  this->__vftable = (SystemNotification_vtbl *)&SystemNotification::`vftable';
  this->currentStatus = eNotificationNone;
  this->blinkTime = 0.0;
  this->show = 0;
  this->sim = aSim;
  this->maxBlinkTime = 0.30000001;
  this->wheelCenteredActive = 1;
  this->timer = 0.0;
  v4 = aSim->game;
  v74 = 0;
  v5 = v4->gui->taskbar;
  if ( v5 )
    this->taskbar = v5;
  top = 0.0;
  this->maxTimer[0] = 2.2;
  this->maxTimer[1] = 3.0;
  this->wheelCenteredActive = 1;
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  std::wstring::assign(&v61, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&ini, 0, v61, SLOBYTE(top));
  LOBYTE(v74) = 1;
  if ( !ini.ready )
    goto LABEL_5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DOWNSHIFT_PROTECTION_NOTIFICATION", 0x21u);
  LOBYTE(v74) = 2;
  v3 = 1;
  v64 = 1;
  v6 = INIReader::hasSection(&ini, &section);
  v63 = 1;
  if ( !v6 )
LABEL_5:
    v63 = 0;
  v74 = 1;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    v64 = v3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  if ( v63 )
  {
    if ( !ini.ready )
      goto LABEL_12;
    std::wstring::wstring(&key, L"TIME_SHOW");
    v7 = v3 | 2;
    LOBYTE(v74) = 3;
    v64 = v7;
    std::wstring::wstring(&section, L"DOWNSHIFT_PROTECTION_NOTIFICATION");
    v74 = 4;
    v3 = v7 | 4;
    v64 = v3;
    v8 = INIReader::hasKey(&ini, &section, &key);
    v63 = 1;
    if ( !v8 )
LABEL_12:
      v63 = 0;
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFFFFFFFB;
      v64 = v3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    v74 = 1;
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFFFFFFFD;
      v64 = v3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    if ( v63 )
    {
      std::wstring::wstring(&key, L"TIME_SHOW");
      LOBYTE(v74) = 5;
      std::wstring::wstring(&section, L"DOWNSHIFT_PROTECTION_NOTIFICATION");
      LOBYTE(v74) = 6;
      v9 = INIReader::getFloat(&ini, &section, &key);
      v10 = section._Myres < 8;
      this->maxTimer[0] = v9;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v74) = 1;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    if ( !ini.ready )
      goto LABEL_27;
    std::wstring::wstring(&key, L"TIME_BLINKING");
    v11 = v3 | 8;
    LOBYTE(v74) = 7;
    v64 = v11;
    std::wstring::wstring(&section, L"DOWNSHIFT_PROTECTION_NOTIFICATION");
    v74 = 8;
    v3 = v11 | 0x10;
    v64 = v3;
    v12 = INIReader::hasKey(&ini, &section, &key);
    v63 = 1;
    if ( !v12 )
LABEL_27:
      v63 = 0;
    if ( (v3 & 0x10) != 0 )
    {
      v3 &= 0xFFFFFFEF;
      v64 = v3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    v74 = 1;
    if ( (v3 & 8) != 0 )
    {
      v3 &= 0xFFFFFFF7;
      v64 = v3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    if ( v63 )
    {
      std::wstring::wstring(&key, L"TIME_BLINKING");
      LOBYTE(v74) = 9;
      std::wstring::wstring(&section, L"DOWNSHIFT_PROTECTION_NOTIFICATION");
      LOBYTE(v74) = 10;
      v13 = INIReader::getFloat(&ini, &section, &key);
      v10 = section._Myres < 8;
      this->maxBlinkTime = v13;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v74) = 1;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  if ( !ini.ready )
    goto LABEL_42;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"STEERING_CENTERED_NOTIFICATION", 0x1Eu);
  LOBYTE(v74) = 11;
  v3 |= 0x20u;
  v64 = v3;
  v14 = INIReader::hasSection(&ini, &section);
  v63 = 1;
  if ( !v14 )
LABEL_42:
    v63 = 0;
  v74 = 1;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    v64 = v3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  if ( v63 )
  {
    if ( !ini.ready )
      goto LABEL_49;
    std::wstring::wstring(&key, L"ACTIVE");
    v15 = v3 | 0x40;
    LOBYTE(v74) = 12;
    v64 = v15;
    std::wstring::wstring(&section, L"STEERING_CENTERED_NOTIFICATION");
    v74 = 13;
    v3 = v15 | 0x80;
    v64 = v3;
    v16 = INIReader::hasKey(&ini, &section, &key);
    v63 = 1;
    if ( !v16 )
LABEL_49:
      v63 = 0;
    if ( (v3 & 0x80u) != 0 )
    {
      v3 &= 0xFFFFFF7F;
      v64 = v3;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    v74 = 1;
    if ( (v3 & 0x40) != 0 )
    {
      v3 &= 0xFFFFFFBF;
      v64 = v3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    if ( v63 )
    {
      std::wstring::wstring(&key, L"ACTIVE");
      LOBYTE(v74) = 14;
      std::wstring::wstring(&section, L"STEERING_CENTERED_NOTIFICATION");
      LOBYTE(v74) = 15;
      v65 = INIReader::getFloat(&ini, &section, &key);
      v10 = section._Myres < 8;
      this->wheelCenteredActive = v65 != 0.0;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v74) = 1;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  *(float *)&v17 = COERCE_FLOAT(operator new(280));
  v65 = *(float *)&v17;
  v18 = 0;
  LOBYTE(v74) = 16;
  if ( *(float *)&v17 != 0.0 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DownShiftProtection", 0x13u);
    v19 = this->sim;
    v3 |= 0x100u;
    LOBYTE(v74) = 17;
    v64 = v3;
    ksgui::Control::Control(v17, &section, v19->game->gui);
  }
  this->controlDownShift = v18;
  v74 = 1;
  if ( (v3 & 0x100) != 0 )
  {
    v3 &= 0xFFFFFEFF;
    v64 = v3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/SystemNotification/down_shift_protection.png", 0x38u);
  v20 = this->game;
  LOBYTE(v74) = 19;
  ResourceStore::getTexture(v20->graphics->resourceStore._Myptr, &t, &key, 0);
  LOBYTE(v74) = 21;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  v21 = this->game;
  key._Mysize = 0;
  v22 = (float)((float)v21->graphics->videoSettings.height * 0.00092592591) * 64.0;
  v66 = v22;
  if ( t.kid )
  {
    v23 = kglTextureGetWidth(t.kid);
    v22 = v66;
    v24 = v23;
  }
  else
  {
    v24 = 0;
  }
  v25 = this->game->graphics;
  top = v22;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->controlDownShift,
    (float)(v25->videoSettings.width / 2) - (float)((float)((float)v24 * 0.5) * 0.5),
    v22);
  v26 = this->controlDownShift;
  v26->backTexture.kid = t.kid;
  v27 = &v26->backTexture.fileName;
  if ( v27 != &t.fileName )
    std::wstring::assign(v27, &t.fileName, 0, 0xFFFFFFFF);
  if ( t.kid )
  {
    v28 = kglTextureGetHeight(t.kid);
    if ( t.kid )
    {
      v29 = kglTextureGetWidth(t.kid);
      goto LABEL_79;
    }
  }
  else
  {
    v28 = 0;
  }
  v29 = 0;
LABEL_79:
  v30 = (float)v28;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->controlDownShift->setSize)(
    this->controlDownShift,
    (float)v29 * 0.5,
    v30 * 0.5);
  v31 = this->controlDownShift;
  top = 0.0;
  v31->drawBackground = 0;
  this->controlDownShift->drawBorder = 0;
  ksgui::Control::setVisible(this->controlDownShift, SLODWORD(top));
  v32 = this->controlDownShift;
  top = 0.0;
  v32->backTextureColor = (vec4f)_xmm;
  this->sim->gameScreen->addControl(this->sim->gameScreen, this->controlDownShift, LODWORD(top));
  *(float *)&v33 = COERCE_FLOAT(operator new(280));
  v65 = *(float *)&v33;
  v34 = 0;
  LOBYTE(v74) = 22;
  if ( *(float *)&v33 != 0.0 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DownShiftProtection", 0x13u);
    v35 = this->sim;
    v3 |= 0x200u;
    LOBYTE(v74) = 23;
    v64 = v3;
    ksgui::Control::Control(v33, &section, v35->game->gui);
  }
  this->controlRotatedWheel = v34;
  v74 = 21;
  if ( (v3 & 0x200) != 0 )
  {
    v3 &= 0xFFFFFDFF;
    v64 = v3;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  Sim::isInTripleScreenMode(this->sim);
  section._Myres = 7;
  section._Mysize = 0;
  v66 = v66 + 100.0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"Warning, steering wheel is not centered", 0x27u);
  LOBYTE(v74) = 25;
  acTranslate(&str, &section);
  LOBYTE(v74) = 27;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v36 = this->controlRotatedWheel;
  section._Myres = 7;
  section._Bx._Buf[0] = 0;
  LODWORD(top) = &str;
  v37 = v36->__vftable;
  section._Mysize = 0;
  v37->setText(v36, &str);
  v38 = this->controlRotatedWheel;
  v39 = v38->__vftable;
  top = 25.0;
  v65 = (float)str._Mysize * 12.0;
  ((void (*)(ksgui::Control *, float, int))v39->setSize)(v38, COERCE_FLOAT(LODWORD(v65)), 1103626240);
  v40 = this->game->graphics;
  v41 = (ksgui::Form *)this->controlRotatedWheel;
  top = v66;
  v65 = v65 * 0.5;
  ksgui::Form::setPosition(v41, (float)(v40->videoSettings.width / 2) - v65, v66);
  v42 = this->controlRotatedWheel;
  LODWORD(top) = 24;
  v42->fontAlign = eAlignCenter;
  v43 = (Font *)operator new(LODWORD(top));
  _Right._Ptr = v43;
  v44 = 0;
  LOBYTE(v74) = 28;
  if ( v43 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"Orbitron", 8u);
    v3 |= 0x400u;
    LOBYTE(v74) = 29;
    v64 = v3;
    Font::Font(v43, &key, eFontCustom, 18.0, 0, 0);
  }
  v74 = 30;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v44);
  std::shared_ptr<Font>::operator=(&this->controlRotatedWheel->font, &_Right);
  v45 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v45->_Destroy(v45);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v45->_Weaks) )
        v45->_Delete_this(v45);
    }
  }
  v74 = 27;
  if ( (v3 & 0x400) != 0 && key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v46 = this->controlRotatedWheel;
  top = 0.0;
  v46->font._Ptr->shadowed = 1;
  this->controlRotatedWheel->font._Ptr->shadowPixelDistance = 1.0;
  this->controlRotatedWheel->foreColor = (vec4f)_xmm;
  this->controlRotatedWheel->drawBackground = 1;
  this->controlRotatedWheel->backColor = (vec4f)_xmm;
  this->controlRotatedWheel->drawBorder = 1;
  ksgui::Control::setVisible(this->controlRotatedWheel, SLODWORD(top));
  this->sim->gameScreen->addControl(this->sim->gameScreen, this->controlRotatedWheel, 0);
  v66 = v66 + 40.0;
  v47 = (Font *)operator new(296);
  _Right._Ptr = v47;
  LOBYTE(v74) = 31;
  if ( v47 )
  {
    top = *(float *)&this->sim->game->gui;
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    std::wstring::assign(&v61, L"LEFT", 4u);
    ksgui::ProgressBar::ProgressBar((ksgui::ProgressBar *)v47, v61, (ksgui::GUI *)LODWORD(top));
    v49 = v48;
  }
  else
  {
    v49 = 0;
  }
  v50 = v65;
  this->pbLeft = v49;
  v51 = v49->__vftable;
  LOBYTE(v74) = 27;
  ((void (*)(ksgui::ProgressBar *, float, int))v51->setSize)(v49, COERCE_FLOAT(LODWORD(v50)), 1084227584);
  v52 = (ksgui::Form *)this->pbLeft;
  v53 = this->game->graphics;
  top = v66;
  ksgui::Form::setPosition(
    v52,
    (float)((float)v53->videoSettings.width * 0.5) - (float)(v52->rect.right - v52->rect.left),
    v66);
  v54 = this->pbLeft;
  top = 0.0;
  v54->foreColor = (vec4f)_xmm;
  this->pbLeft->borderColor = (vec4f)_xmm;
  this->pbLeft->isVertical = 0;
  this->pbLeft->value = 0.0;
  this->pbLeft->isInverted = 1;
  ksgui::Control::setVisible(this->pbLeft, SLODWORD(top));
  this->sim->gameScreen->addControl(this->sim->gameScreen, this->pbLeft, 0);
  v55 = (Font *)operator new(296);
  _Right._Ptr = v55;
  LOBYTE(v74) = 32;
  if ( v55 )
  {
    top = *(float *)&this->sim->game->gui;
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    std::wstring::assign(&v61, L"RIGHT", 5u);
    ksgui::ProgressBar::ProgressBar((ksgui::ProgressBar *)v55, v61, (ksgui::GUI *)LODWORD(top));
    v57 = v56;
  }
  else
  {
    v57 = 0;
  }
  v58 = v65;
  this->pbRight = v57;
  v59 = v57->__vftable;
  LOBYTE(v74) = 27;
  ((void (*)(ksgui::ProgressBar *, float, int))v59->setSize)(v57, COERCE_FLOAT(LODWORD(v58)), 1084227584);
  ksgui::Form::setPosition((ksgui::Form *)this->pbRight, (float)this->game->graphics->videoSettings.width * 0.5, v66);
  v60 = this->pbRight;
  top = 0.0;
  v60->foreColor = (vec4f)_xmm;
  this->pbRight->borderColor = (vec4f)_xmm;
  this->pbRight->isVertical = 0;
  this->pbRight->isInverted = 0;
  this->pbRight->value = 0.0;
  ksgui::Control::setVisible(this->pbRight, SLODWORD(top));
  this->sim->gameScreen->addControl(this->sim->gameScreen, this->pbRight, 0);
  ksgui::Control::setVisible(this->controlDownShift, 0);
  ksgui::Control::setVisible(this->controlRotatedWheel, 0);
  ksgui::Control::setVisible(this->pbLeft, 0);
  ksgui::Control::setVisible(this->pbRight, 0);
  v10 = str._Myres < 8;
  this->timer = -1.0;
  this->show = 0;
  this->currentStatus = eNotificationNone;
  if ( !v10 )
    operator delete(str._Bx._Ptr);
  str._Myres = 7;
  str._Mysize = 0;
  str._Bx._Buf[0] = 0;
  LOBYTE(v74) = 1;
  OnSetupAppCreated::~OnSetupAppCreated(&t);
  LOBYTE(v74) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
SystemNotification *SystemNotification::`scalar deleting destructor'(SystemNotification *this, unsigned int a2)
{
  this->__vftable = (SystemNotification_vtbl *)&SystemNotification::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SystemNotification::clearMessage(SystemNotification *this)
{
  ksgui::Control::setVisible(this->controlDownShift, 0);
  ksgui::Control::setVisible(this->controlRotatedWheel, 0);
  ksgui::Control::setVisible(this->pbLeft, 0);
  ksgui::Control::setVisible(this->pbRight, 0);
  this->timer = -1.0;
  this->show = 0;
  this->currentStatus = eNotificationNone;
}
void SystemNotification::showNotification(SystemNotification *this, const SystemNotificationMode type)
{
  this->show = 1;
  this->currentStatus = type;
  if ( type == eDownShiftProtection )
  {
    ksgui::Control::setVisible(this->controlDownShift, 1);
    ksgui::Control::setVisible(this->controlRotatedWheel, 0);
    ksgui::Control::setVisible(this->pbLeft, 0);
    ksgui::Control::setVisible(this->pbRight, 0);
    this->blinkTime = this->maxBlinkTime;
    this->timer = this->maxTimer[0];
  }
  else if ( type == 2 )
  {
    ksgui::Control::setVisible(this->controlDownShift, 0);
    ksgui::Control::setVisible(this->controlRotatedWheel, 1);
    ksgui::Control::setVisible(this->pbLeft, 1);
    ksgui::Control::setVisible(this->pbRight, 1);
    this->timer = this->maxTimer[1];
  }
}
void SystemNotification::update(SystemNotification *this, float deltaT)
{
  ksgui::Control *v3; // ecx
  Sim *v4; // ecx
  float v5; // xmm2_4
  SystemNotificationMode v6; // eax
  CarAvatar *v7; // eax
  Sim *v8; // ecx
  float v9; // xmm2_4
  vec4f v10; // xmm0
  ksgui::ProgressBar *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm0_4
  ksgui::Control *v14; // ecx
  __m128i v15; // [esp+4h] [ebp-84h] BYREF
  int v16; // [esp+14h] [ebp-74h]
  double v17; // [esp+18h] [ebp-70h]
  bool v18; // [esp+23h] [ebp-65h]
  Session result; // [esp+24h] [ebp-64h] BYREF

  if ( this->wheelCenteredActive )
  {
    v18 = RaceManager::getCurrentSession(this->sim->raceManager, &result)->sessionType == Race;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
    if ( result.spawSet._Myres >= 8 )
      operator delete(result.spawSet._Bx._Ptr);
    if ( v18 )
    {
      v17 = RaceManager::getTimeToSessionStart(this->sim->raceManager);
      if ( v17 < 30000.0 )
      {
        v17 = RaceManager::getTimeToSessionStart(this->sim->raceManager);
        if ( v17 > 1000.0 )
        {
          if ( COERCE_FLOAT(LODWORD(Sim::getCar(this->sim, 0)->physicsState.steer) & _xmm) <= 90.0 )
          {
            if ( this->currentStatus == 2 )
              SystemNotification::clearMessage(this);
          }
          else if ( this->currentStatus != 2 )
          {
            v3 = this->controlDownShift;
            this->show = 1;
            this->currentStatus = 2;
            ksgui::Control::setVisible(v3, 0);
            ksgui::Control::setVisible(this->controlRotatedWheel, 1);
            ksgui::Control::setVisible(this->pbLeft, 1);
            ksgui::Control::setVisible(this->pbRight, 1);
            this->timer = this->maxTimer[1];
          }
        }
      }
    }
  }
  v4 = this->sim;
  if ( v4->escMenu->visible || (v5 = this->timer, v5 <= 0.0) )
  {
    ksgui::Control::setVisible(this->controlDownShift, 0);
    ksgui::Control::setVisible(this->controlRotatedWheel, 0);
    ksgui::Control::setVisible(this->pbLeft, 0);
    ksgui::Control::setVisible(this->pbRight, 0);
    this->timer = -1.0;
    this->show = 0;
    this->currentStatus = eNotificationNone;
  }
  else if ( this->show )
  {
    v6 = this->currentStatus;
    if ( v6 == 2 )
    {
      v7 = Sim::getCar(v4, 0);
      v8 = this->sim;
      HIDWORD(v17) = LODWORD(v7->physicsState.steer);
      v16 = HIDWORD(v17) & _xmm;
      v9 = COERCE_FLOAT(HIDWORD(v17) & _xmm) / Sim::getCar(v8, 0)->physicsInfo.steerLock;
      if ( v9 <= 1.0 )
      {
        if ( v9 < 0.0 )
          v9 = 0.0;
      }
      else
      {
        v9 = FLOAT_1_0;
      }
      v15.m128i_i32[3] = 1065353216;
      *(float *)v15.m128i_i32 = v9 * 2.0;
      *(__int64 *)((char *)v15.m128i_i64 + 4) = COERCE_UNSIGNED_INT((float)(1.0 - v9) * 2.0);
      v10 = (vec4f)_mm_loadu_si128(&v15);
      if ( *((float *)&v17 + 1) >= 0.0 )
      {
        this->pbRight->foreColor = v10;
        this->pbRight->value = v9;
        ksgui::Control::setVisible(this->pbRight, 1);
        v11 = this->pbLeft;
      }
      else
      {
        this->pbLeft->foreColor = v10;
        this->pbLeft->value = v9;
        ksgui::Control::setVisible(this->pbLeft, 1);
        v11 = this->pbRight;
      }
      ksgui::Control::setVisible(v11, 0);
      this->timer = this->timer - deltaT;
    }
    else if ( v6 == eDownShiftProtection )
    {
      v12 = this->blinkTime - deltaT;
      this->blinkTime = v12;
      if ( v12 > 0.0 || (v13 = this->maxBlinkTime, v13 == 0.0) )
      {
        this->timer = v5 - deltaT;
      }
      else
      {
        v14 = this->controlDownShift;
        this->blinkTime = v13;
        ksgui::Control::setVisible(v14, !v14->visible);
      }
    }
  }
}
