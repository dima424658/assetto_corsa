#include "carlabel.h"
void CarLabel::CarLabel(CarLabel *this, int id, float maxDist, CarLabel::eLabelType type, Sim *aSim)
{
  int v6; // ebp
  __int16 v7; // bx
  const wchar_t *v8; // edx
  int v9; // ecx
  const wchar_t *v10; // ecx
  Game *v12; // eax
  Font *v13; // edi
  ksgui::Control *v14; // eax
  const wchar_t *v15; // edx
  int v16; // ecx
  const wchar_t *v17; // ecx
  Sim *v19; // eax
  ksgui::Control *v20; // eax
  ksgui::Control *v21; // eax
  ksgui::Control *v22; // ecx
  Font *v23; // edi
  Font *v24; // eax
  std::_Ref_count_base *v25; // edi
  ksgui::Control *v26; // eax
  Font *v27; // edi
  Sim *v28; // eax
  ksgui::Control *v29; // eax
  Font *v30; // edi
  Sim *v31; // eax
  ksgui::Control *v32; // eax
  Font *v33; // edi
  Sim *v34; // eax
  ksgui::Control *v35; // eax
  ksgui::Control *v36; // eax
  ksgui::Control *v37; // eax
  ksgui::Control *v38; // ecx
  Font *v39; // edi
  Font *v40; // eax
  std::_Ref_count_base *v41; // edi
  Font *v42; // edi
  int v43; // ebp
  Sim *v44; // eax
  ksgui::Control *v45; // eax
  ksgui::Control *v46; // eax
  ksgui::Control *v47; // eax
  Sim *v48; // eax
  ksgui::Control *v49; // ecx
  std::wstring *v50; // ecx
  Font *v51; // edi
  Sim *v52; // eax
  ksgui::Control *v53; // eax
  Font *v54; // edi
  Sim *v55; // eax
  ksgui::Control *v56; // eax
  ksgui::Control *v57; // eax
  ksgui::Control *v58; // eax
  Sim *v59; // eax
  ksgui::Control *v60; // ecx
  std::wstring *v61; // ecx
  std::shared_ptr<Font> _Right; // [esp+34h] [ebp-6Ch] BYREF
  int v63; // [esp+3Ch] [ebp-64h]
  CarLabel *v64; // [esp+40h] [ebp-60h]
  std::wstring iname; // [esp+44h] [ebp-5Ch] BYREF
  Texture texture; // [esp+5Ch] [ebp-44h] BYREF
  std::wstring v67; // [esp+78h] [ebp-28h] BYREF
  int v68; // [esp+9Ch] [ebp-4h]

  v6 = id;
  v7 = 0;
  v8 = &aCarLabel[id];
  v64 = this;
  v63 = id;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( *v8 )
  {
    v10 = &aCarLabel[id];
    while ( *v10++ )
      ;
    v6 = v63;
    v9 = v10 - (v8 + 1);
  }
  else
  {
    v9 = 0;
  }
  std::wstring::assign(&iname, &aCarLabel[id], v9);
  v12 = aSim->game;
  v68 = 0;
  ksgui::Control::Control(this, &iname, v12->gui);
  LOBYTE(v68) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (CarLabel_vtbl *)&CarLabel::`vftable';
  iname._Myres = 7;
  this->nationCode._Myres = 7;
  this->nationCode._Mysize = 0;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  this->nationCode._Bx._Buf[0] = 0;
  std::wstring::assign(&this->nationCode, L".", 1u);
  LOBYTE(v68) = 3;
  this->sim = aSim;
  this->labelType = type;
  this->maxDistance = maxDist;
  CarLabel::CarData::CarData(&this->oldData);
  LOBYTE(v68) = 4;
  *(_WORD *)&this->drawBorder = 0;
  v13 = (Font *)operator new(280);
  _Right._Ptr = v13;
  v14 = 0;
  LOBYTE(v68) = 5;
  if ( v13 )
  {
    v15 = &aName_3[v6];
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( *v15 )
    {
      v17 = &aName_3[v6];
      while ( *v17++ )
        ;
      v16 = v17 - (v15 + 1);
    }
    else
    {
      v16 = 0;
    }
    std::wstring::assign(&iname, &aName_3[v6], v16);
    v19 = this->sim;
    v7 = 1;
    LOBYTE(v68) = 6;
    ksgui::Control::Control((ksgui::Control *)v13, &iname, v19->game->gui);
  }
  this->name = v14;
  v68 = 4;
  if ( (v7 & 1) != 0 )
  {
    v7 &= 0xFFFEu;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v20 = this->name;
  iname._Myres = 7;
  v20->drawBackground = 0;
  v21 = this->name;
  iname._Mysize = 0;
  v21->drawBorder = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Name", 4u);
  v22 = this->name;
  LOBYTE(v68) = 8;
  v22->setText(v22, &iname);
  LOBYTE(v68) = 4;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Control::setVisible(this->name, 1);
  v23 = (Font *)operator new(24);
  v24 = 0;
  LOBYTE(v68) = 9;
  if ( v23 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Orbitron", 8u);
    v7 |= 2u;
    LOBYTE(v68) = 10;
    Font::Font(v23, &iname, eFontCustom, 12.0, 0, 0);
  }
  v68 = 11;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v24);
  std::shared_ptr<Font>::operator=(&this->name->font, &_Right);
  v25 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v25->_Destroy(v25);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v25->_Weaks, 0xFFFFFFFF) )
        v25->_Delete_this(v25);
    }
  }
  v68 = 4;
  if ( (v7 & 2) != 0 )
  {
    v7 &= 0xFFFDu;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  this->name->font._Ptr->shadowed = 0;
  this->name->backTextureColor = (vec4f)_xmm;
  v26 = this->name;
  if ( type )
  {
    v26->fontAlign = eAlignLeft;
    v27 = (Font *)operator new(280);
    _Right._Ptr = v27;
    LOBYTE(v68) = 12;
    if ( v27 )
    {
      std::wstring::wstring(&iname, &aNameparent[v63]);
      v28 = this->sim;
      LOBYTE(v7) = v7 | 4;
      LOBYTE(v68) = 13;
      ksgui::Control::Control((ksgui::Control *)v27, &iname, v28->game->gui);
    }
    else
    {
      v29 = 0;
    }
    this->nameParent = v29;
    v68 = 4;
    if ( (v7 & 4) != 0 )
    {
      LOBYTE(v7) = v7 & 0xFB;
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
    }
    this->nameParent->drawBackground = 1;
    this->nameParent->drawBorder = 0;
    ksgui::Control::setVisible(this->nameParent, 1);
    this->nameParent->backTextureColor = (vec4f)_xmm;
    this->nameParent->addControl(this->nameParent, this->name);
    if ( type == Flag )
    {
      v30 = (Font *)operator new(280);
      _Right._Ptr = v30;
      LOBYTE(v68) = 15;
      if ( v30 )
      {
        std::wstring::wstring(&iname, &aFlag[v63]);
        v31 = this->sim;
        LOBYTE(v7) = v7 | 8;
        LOBYTE(v68) = 16;
        ksgui::Control::Control((ksgui::Control *)v30, &iname, v31->game->gui);
      }
      else
      {
        v32 = 0;
      }
      this->flag = v32;
      v68 = 4;
      if ( (v7 & 8) != 0 )
      {
        LOBYTE(v7) = v7 & 0xF7;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
      }
      this->flag->drawBackground = 0;
      this->flag->drawBorder = 0;
      ksgui::Control::setVisible(this->flag, 1);
      this->flag->backTextureColor = (vec4f)_xmm;
      this->nameParent->addControl(this->nameParent, this->flag);
    }
    v33 = (Font *)operator new(280);
    _Right._Ptr = v33;
    LOBYTE(v68) = 18;
    if ( v33 )
    {
      std::wstring::wstring(&iname, &aPosition_2[v63]);
      v34 = this->sim;
      LOBYTE(v7) = v7 | 0x10;
      LOBYTE(v68) = 19;
      ksgui::Control::Control((ksgui::Control *)v33, &iname, v34->game->gui);
    }
    else
    {
      v35 = 0;
    }
    this->position = v35;
    v68 = 4;
    if ( (v7 & 0x10) != 0 )
    {
      LOBYTE(v7) = v7 & 0xEF;
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
    }
    v36 = this->position;
    iname._Myres = 7;
    v36->drawBackground = 0;
    v37 = this->position;
    iname._Mysize = 0;
    v37->drawBorder = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"-", 1u);
    v38 = this->position;
    LOBYTE(v68) = 21;
    v38->setText(v38, &iname);
    LOBYTE(v68) = 4;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    ksgui::Control::setVisible(this->position, 1);
    this->position->fontAlign = eAlignCenter;
    v39 = (Font *)operator new(24);
    _Right._Ptr = v39;
    LOBYTE(v68) = 22;
    if ( v39 )
    {
      std::wstring::wstring(&iname, L"Orbitron");
      LOBYTE(v7) = v7 | 0x20;
      LOBYTE(v68) = 23;
      Font::Font(v39, &iname, eFontCustom, 18.0, 0, 1);
    }
    else
    {
      v40 = 0;
    }
    v68 = 24;
    _Right._Ptr = 0;
    _Right._Rep = 0;
    std::shared_ptr<Font>::_Resetp<Font>(&_Right, v40);
    std::shared_ptr<Font>::operator=(&this->position->font, &_Right);
    v41 = _Right._Rep;
    if ( _Right._Rep )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
      {
        v41->_Destroy(v41);
        if ( !_InterlockedDecrement((volatile signed __int32 *)&v41->_Weaks) )
          v41->_Delete_this(v41);
      }
    }
    v68 = 4;
    if ( (v7 & 0x20) != 0 )
    {
      LOBYTE(v7) = v7 & 0xDF;
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
    }
    this->position->backTextureColor = (vec4f)_xmm;
    this->position->font._Ptr->shadowed = 0;
    v42 = (Font *)operator new(280);
    _Right._Ptr = v42;
    v43 = v63;
    LOBYTE(v68) = 25;
    if ( v42 )
    {
      std::wstring::wstring(&iname, &aArrow[v63]);
      v44 = this->sim;
      LOBYTE(v7) = v7 | 0x40;
      LOBYTE(v68) = 26;
      ksgui::Control::Control((ksgui::Control *)v42, &iname, v44->game->gui);
    }
    else
    {
      v45 = 0;
    }
    this->arrow = v45;
    v68 = 4;
    if ( (v7 & 0x40) != 0 )
    {
      LOBYTE(v7) = v7 & 0xBF;
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
    }
    v46 = this->arrow;
    iname._Myres = 7;
    v46->drawBackground = 0;
    v47 = this->arrow;
    iname._Mysize = 0;
    v47->drawBorder = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"content/gui/driverNameDisplayer/arrow.png", 0x29u);
    v48 = this->sim;
    LOBYTE(v68) = 28;
    ResourceStore::getTexture(v48->game->graphics->resourceStore._Myptr, &texture, &iname, 0);
    LOBYTE(v68) = 30;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    v49 = this->arrow;
    iname._Bx._Buf[0] = 0;
    iname._Myres = 7;
    v49->backTexture.kid = texture.kid;
    v50 = &v49->backTexture.fileName;
    iname._Mysize = 0;
    if ( v50 != &texture.fileName )
      std::wstring::assign(v50, &texture.fileName, 0, 0xFFFFFFFF);
    ksgui::Control::setVisible(this->arrow, 1);
    this->arrow->backTextureColor = (vec4f)_xmm;
    v51 = (Font *)operator new(280);
    _Right._Ptr = v51;
    LOBYTE(v68) = 31;
    if ( v51 )
    {
      std::wstring::wstring(&v67, &aPosparent[v43]);
      v52 = this->sim;
      LOBYTE(v7) = v7 | 0x80;
      LOBYTE(v68) = 32;
      ksgui::Control::Control((ksgui::Control *)v51, &v67, v52->game->gui);
    }
    else
    {
      v53 = 0;
    }
    this->posParent = v53;
    v68 = 30;
    if ( (v7 & 0x80u) != 0 && v67._Myres >= 8 )
      operator delete(v67._Bx._Ptr);
    this->posParent->drawBackground = 1;
    this->posParent->drawBorder = 0;
    ksgui::Control::setVisible(this->posParent, 1);
    this->posParent->addControl(this->posParent, this->position);
    ksgui::Control::addControl(this, this->nameParent);
    ksgui::Control::addControl(this, this->posParent);
    ksgui::Control::addControl(this, this->arrow);
    CarLabel::resetRects(this, 60);
  }
  else
  {
    v26->fontAlign = eAlignCenter;
    v54 = (Font *)operator new(280);
    _Right._Ptr = v54;
    LOBYTE(v68) = 34;
    if ( v54 )
    {
      std::wstring::wstring(&v67, &aArrow[v63]);
      v55 = this->sim;
      v7 |= 0x100u;
      LOBYTE(v68) = 35;
      ksgui::Control::Control((ksgui::Control *)v54, &v67, v55->game->gui);
    }
    else
    {
      v56 = 0;
    }
    this->arrow = v56;
    v68 = 4;
    if ( (v7 & 0x100) != 0 && v67._Myres >= 8 )
      operator delete(v67._Bx._Ptr);
    v57 = this->arrow;
    iname._Myres = 7;
    v57->drawBackground = 0;
    v58 = this->arrow;
    iname._Mysize = 0;
    v58->drawBorder = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"content/gui/driverNameDisplayer/down.png", 0x28u);
    v59 = this->sim;
    LOBYTE(v68) = 37;
    ResourceStore::getTexture(v59->game->graphics->resourceStore._Myptr, &texture, &iname, 0);
    LOBYTE(v68) = 39;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    v60 = this->arrow;
    iname._Bx._Buf[0] = 0;
    iname._Myres = 7;
    v60->backTexture.kid = texture.kid;
    v61 = &v60->backTexture.fileName;
    iname._Mysize = 0;
    if ( v61 != &texture.fileName )
      std::wstring::assign(v61, &texture.fileName, 0, 0xFFFFFFFF);
    ksgui::Control::setVisible(this->arrow, 1);
    this->arrow->backTextureColor = (vec4f)_xmm;
    ksgui::Control::addControl(this, this->name);
    ksgui::Control::addControl(this, this->arrow);
  }
  LOBYTE(v68) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&texture);
}
void CarLabel::~CarLabel(CarLabel *this)
{
  this->__vftable = (CarLabel_vtbl *)&CarLabel::`vftable';
  if ( this->oldData.nationCode._Myres >= 8 )
    operator delete(this->oldData.nationCode._Bx._Ptr);
  this->oldData.nationCode._Myres = 7;
  this->oldData.nationCode._Mysize = 0;
  this->oldData.nationCode._Bx._Buf[0] = 0;
  if ( this->oldData.name._Myres >= 8 )
    operator delete(this->oldData.name._Bx._Ptr);
  this->oldData.name._Myres = 7;
  this->oldData.name._Mysize = 0;
  this->oldData.name._Bx._Buf[0] = 0;
  if ( this->nationCode._Myres >= 8 )
    operator delete(this->nationCode._Bx._Ptr);
  this->nationCode._Myres = 7;
  this->nationCode._Mysize = 0;
  this->nationCode._Bx._Buf[0] = 0;
  ksgui::Control::~Control(this);
}
CarLabel *CarLabel::`vector deleting destructor'(CarLabel *this, unsigned int a2)
{
  CarLabel::~CarLabel(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarLabel::resetRects(CarLabel *this, int width)
{
  CarLabel::eLabelType v3; // eax
  int v4; // ebx
  int v5; // ebp

  ksgui::Control::resetBaseRect(this);
  v3 = this->labelType;
  v4 = width + 10;
  if ( v3 )
  {
    v5 = 0;
    if ( v3 == Flag )
      v5 = 25;
    ((void (*)(_DWORD, _DWORD, _DWORD))this->setSize)(this, (float)(v4 + v5 + 49), 1108344832);
    ((void (*)(_DWORD, _DWORD, _DWORD))this->nameParent->setSize)(
      this->nameParent,
      (float)(v4 + v5),
      1102053376);
    ((void (*)(_DWORD, _DWORD, _DWORD))this->name->setSize)(this->name, (float)v4, 1100480512);
    ((void (*)(ksgui::Control *, int, int))this->arrow->setSize)(this->arrow, 1111752704, 1095761920);
    ((void (*)(ksgui::Control *, int, int))this->posParent->setSize)(this->posParent, 1109131264, 1102053376);
    ((void (*)(ksgui::Control *, int, int))this->position->setSize)(this->position, 1109131264, 1102053376);
    if ( this->labelType == Flag )
    {
      ((void (*)(ksgui::Control *, int, int))this->flag->setSize)(this->flag, 1102053376, 1102053376);
      ksgui::Form::setPosition((ksgui::Form *)this->flag, 3.0, 0.0);
    }
    ksgui::Form::setPosition((ksgui::Form *)this->arrow, 0.0, 23.0);
    ksgui::Form::setPosition((ksgui::Form *)this->posParent, 10.0, 0.0);
    ksgui::Form::setPosition((ksgui::Form *)this->position, -1.0, -1.0);
    ksgui::Form::setPosition((ksgui::Form *)this->nameParent, 49.0, 0.0);
    ksgui::Form::setPosition((ksgui::Form *)this->name, (float)(v5 + 10), 3.0);
  }
  else
  {
    ((void (*)(_DWORD, _DWORD, _DWORD))this->setSize)(this, (float)v4, 1108344832);
    ((void (*)(_DWORD, _DWORD, _DWORD))this->name->setSize)(this->name, (float)v4, 1100480512);
    ((void (*)(ksgui::Control *, int, int))this->arrow->setSize)(this->arrow, 1099956224, 1099956224);
    ksgui::Form::setPosition((ksgui::Form *)this->arrow, -9.0, 22.0);
    ksgui::Form::setPosition((ksgui::Form *)this->name, (float)(v4 / -2), 3.0);
  }
}
void CarLabel::updatePilotData(CarLabel *this, const CarLabel::CarData *carData, float scale)
{
  CarLabel::CarData *v4; // ebp
  ksgui::Control *v5; // eax
  float v6; // xmm0_4
  CarLabel::CarData *v7; // eax
  ksgui::Control *v8; // ecx
  unsigned int v9; // esi
  double v10; // st7
  int v11; // eax
  vec4f v12; // xmm0
  Texture *v13; // edx
  ksgui::Control *v14; // ecx
  void *v15; // eax
  const std::wstring *v16; // edx
  std::wstring *v17; // ecx
  std::wstring *v18; // eax
  ksgui::Control *v19; // ecx
  int v20; // eax
  std::wstring *v21; // edi
  float v22; // [esp+1Ch] [ebp-54h]
  vec4f grey; // [esp+20h] [ebp-50h] BYREF
  vec4f positionColor; // [esp+30h] [ebp-40h] BYREF
  unsigned int v25; // [esp+40h] [ebp-30h]
  unsigned int v26; // [esp+44h] [ebp-2Ch]
  vec4f white; // [esp+48h] [ebp-28h] BYREF
  unsigned int v28; // [esp+5Ch] [ebp-14h]
  int v29; // [esp+6Ch] [ebp-4h]

  v4 = &this->oldData;
  v5 = this->arrow;
  grey.x = 0.1;
  v6 = carData->distance / this->maxDistance;
  grey.y = 0.1;
  grey.z = 0.1;
  white.x = 1.0;
  white.y = 1.0;
  white.z = 1.0;
  v22 = 1.0 - v6;
  white.w = 1.0 - v6;
  grey.w = (float)(1.0 - v6) * 0.5;
  v5->backTextureColor = (vec4f)_mm_loadu_si128((const __m128i *)&grey);
  if ( this->oldData.name._Myres < 8 )
    v7 = &this->oldData;
  else
    v7 = (CarLabel::CarData *)v4->name._Bx._Ptr;
  if ( std::wstring::compare(&carData->name, 0, carData->name._Mysize, v7->name._Bx._Buf, this->oldData.name._Mysize) )
  {
    v26 = 7;
    v25 = 0;
    LOWORD(positionColor.x) = 0;
    std::wstring::assign((std::wstring *)&positionColor, &carData->name, 0, 0xFFFFFFFF);
    v8 = this->name;
    v9 = v25;
    v29 = 0;
    v8->setText(v8, (const std::wstring *)&positionColor);
    v10 = _roundf((float)v9 * 8.5);
    CarLabel::resetRects(this, (int)v10);
    ((void (*)(CarLabel *, _DWORD))this->scaleByMult)(this, LODWORD(scale));
    v29 = -1;
    if ( v26 >= 8 )
      operator delete(LODWORD(positionColor.x));
  }
  v11 = carData->ping;
  positionColor.x = 1.0;
  positionColor.y = 1.0;
  positionColor.z = 1.0;
  positionColor.w = 1.0 - v6;
  if ( v11 != -1 )
  {
    if ( v11 <= 250 )
    {
      if ( v11 <= 100 )
        goto LABEL_13;
      positionColor.y = 1.0;
    }
    else
    {
      positionColor.y = 0.0;
    }
    positionColor.w = 1.0 - v6;
    positionColor.z = 0.0;
    positionColor.x = 1.0;
  }
LABEL_13:
  this->name->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&positionColor);
  if ( this->labelType == Simple )
    goto LABEL_27;
  this->nameParent->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&grey);
  v12 = (vec4f)_mm_loadu_si128((const __m128i *)&white);
  this->position->foreColor = v12;
  if ( this->labelType == Flag )
  {
    this->flag->foreColor = v12;
    this->flag->backTextureColor = v12;
    v13 = carData->texture;
    if ( v13 )
    {
      v14 = this->flag;
      v15 = v13->kid;
      v16 = &v13->fileName;
      v14->backTexture.kid = v15;
      v17 = &v14->backTexture.fileName;
      if ( v17 != v16 )
        std::wstring::assign(v17, v16, 0, 0xFFFFFFFF);
    }
  }
  if ( carData->position != this->oldData.position )
  {
    v18 = std::to_wstring((std::wstring *)&white, carData->position);
    v19 = this->position;
    v29 = 1;
    v19->setText(v19, v18);
    v29 = -1;
    if ( v28 >= 8 )
      operator delete(LODWORD(white.x));
  }
  v20 = carData->ahead;
  positionColor.x = 0.74000001;
  positionColor.y = 0.0;
  positionColor.z = 0.0;
  positionColor.w = v22 * 0.80000001;
  if ( v20 == 1 )
  {
    positionColor.x = 0.0;
    positionColor.y = 1.0;
    positionColor.z = 0.0;
LABEL_25:
    positionColor.w = v22 * 0.80000001;
    goto LABEL_26;
  }
  if ( !v20 )
  {
    positionColor.x = 0.1;
    positionColor.y = 0.0;
    positionColor.z = 0.89999998;
    goto LABEL_25;
  }
LABEL_26:
  this->posParent->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&positionColor);
LABEL_27:
  if ( v4 != carData )
    std::wstring::assign(&v4->name, &carData->name, 0, 0xFFFFFFFF);
  v4->position = carData->position;
  v4->distance = carData->distance;
  v4->ahead = carData->ahead;
  v4->ping = carData->ping;
  v21 = &carData->nationCode;
  v4->texture = carData->texture;
  if ( &v4->nationCode != &carData->nationCode )
    std::wstring::assign(&v4->nationCode, v21, 0, 0xFFFFFFFF);
  if ( &this->nationCode != v21 )
    std::wstring::assign(&this->nationCode, v21, 0, 0xFFFFFFFF);
}
