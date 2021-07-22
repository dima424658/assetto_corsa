#include "driverstatussystemmessage.h
void DriverStatusSystemMessage::DriverStatusSystemMessage(DriverStatusSystemMessage *this, Sim *aSim)
{
  Game *v3; // eax
  Sim *v4; // eax
  Texture *v5; // eax
  ksgui::Label *v6; // edi
  ksgui::Label *v7; // eax
  ksgui::Label *v8; // ecx
  ksgui::Label *v9; // eax
  Font *v10; // eax
  Font *v11; // eax
  std::_Ref_count_base *v12; // ebx
  Font *v13; // ebx
  ksgui::Label *v14; // eax
  ksgui::Label *v15; // ecx
  ksgui::Label *v16; // eax
  Font *v17; // eax
  Font *v18; // eax
  std::_Ref_count_base *v19; // ebx
  Font *v20; // ebx
  ksgui::Label *v21; // eax
  ksgui::Label *v22; // ecx
  ksgui::Label *v23; // eax
  Font *v24; // eax
  Font *v25; // eax
  std::_Ref_count_base *v26; // ebx
  Font *v27; // ebx
  ksgui::Label *v28; // eax
  ksgui::Label *v29; // eax
  Font *v30; // eax
  Font *v31; // eax
  std::_Ref_count_base *v32; // ebx
  Font *v33; // ebx
  ksgui::Label *v34; // eax
  ksgui::Label *v35; // ecx
  ksgui::Label *v36; // eax
  Font *v37; // eax
  Font *v38; // eax
  std::_Ref_count_base *v39; // ebx
  std::wstring v40; // [esp+10h] [ebp-80h] BYREF
  unsigned int v41; // [esp+28h] [ebp-68h]
  std::shared_ptr<Font> _Right; // [esp+3Ch] [ebp-54h] BYREF
  ksgui::Label *v43; // [esp+44h] [ebp-4Ch]
  DriverStatusSystemMessage *v44; // [esp+48h] [ebp-48h]
  std::wstring iname; // [esp+4Ch] [ebp-44h] BYREF
  Texture result; // [esp+64h] [ebp-2Ch] BYREF
  int v47; // [esp+8Ch] [ebp-4h]

  v44 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"DriverStatusSystemMessage", 0x19u);
  v3 = aSim->game;
  v47 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (DriverStatusSystemMessage_vtbl *)&DriverStatusSystemMessage::`vftable';
  this->sim = aSim;
  this->carLogos._Myfirst = 0;
  this->carLogos._Mylast = 0;
  this->carLogos._Myend = 0;
  this->driverNationality._Myfirst = 0;
  this->driverNationality._Mylast = 0;
  this->driverNationality._Myend = 0;
  this->cameraNames._Myfirst = 0;
  this->cameraNames._Mylast = 0;
  this->cameraNames._Myend = 0;
  this->bar.kid = 0;
  this->bar.fileName._Myres = 7;
  this->bar.fileName._Mysize = 0;
  this->bar.fileName._Bx._Buf[0] = 0;
  this->backColor = (vec4f)_xmm;
  v41 = 33;
  v40._Myres = (unsigned int)L"content/gui/systemMessage/bar.png";
  LOBYTE(v47) = 6;
  this->cameraManager = 0;
  this->borderColor = (vec4f)_xmm;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)v40._Myres, v41);
  v4 = this->sim;
  LOBYTE(v47) = 7;
  v5 = ResourceStore::getTexture(v4->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->bar.kid = v5->kid;
  LOBYTE(v47) = 8;
  if ( &this->bar.fileName != &v5->fileName )
    std::wstring::assign(&this->bar.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v47) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v47) = 6;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v41 = 284;
  *(_WORD *)&this->drawBorder = 257;
  this->currentCarIndex = 0;
  v6 = (ksgui::Label *)operator new(v41);
  v43 = v6;
  v7 = 0;
  LOBYTE(v47) = 9;
  if ( v6 )
  {
    v41 = (unsigned int)this->gui;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"DRIVER_NAME", 0xBu);
    ksgui::Label::Label(v6, v40, (ksgui::GUI *)v41);
  }
  this->labDriverName = v7;
  v7->drawBackground = 1;
  v8 = this->labDriverName;
  LOBYTE(v47) = 6;
  ((void (*)(ksgui::Label *, int, int))v8->setSize)(v8, 1133903872, 1103626240);
  v9 = this->labDriverName;
  this->foreColor = (vec4f)_xmm;
  v41 = 24;
  v9->foreColor = (vec4f)_xmm;
  this->labDriverName->drawBackground = 0;
  this->labDriverName->fontAlign = eAlignRight;
  v10 = (Font *)operator new(v41);
  _Right._Ptr = v10;
  LOBYTE(v47) = 10;
  if ( v10 )
    Font::Font(v10, eFontProportional, 21.0, 0, 0);
  else
    v11 = 0;
  LOBYTE(v47) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v11);
  std::shared_ptr<Font>::operator=(&this->labDriverName->font, &_Right);
  v12 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v12->_Destroy(v12);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v12->_Weaks, 0xFFFFFFFF) )
        v12->_Delete_this(v12);
    }
  }
  ksgui::Control::addControl(this, this->labDriverName);
  v13 = (Font *)operator new(284);
  _Right._Ptr = v13;
  v14 = 0;
  LOBYTE(v47) = 11;
  if ( v13 )
  {
    v41 = (unsigned int)this->gui;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"CAR_NAME", 8u);
    ksgui::Label::Label((ksgui::Label *)v13, v40, (ksgui::GUI *)v41);
  }
  this->labCarName = v14;
  v14->drawBackground = 1;
  v15 = this->labCarName;
  LOBYTE(v47) = 6;
  ((void (*)(ksgui::Label *, int, int))v15->setSize)(v15, 1133903872, 1103626240);
  v16 = this->labCarName;
  this->foreColor = (vec4f)_xmm;
  v41 = 24;
  v16->foreColor = (vec4f)_xmm;
  this->labCarName->drawBackground = 0;
  this->labCarName->fontAlign = eAlignLeft;
  v17 = (Font *)operator new(v41);
  _Right._Ptr = v17;
  LOBYTE(v47) = 12;
  if ( v17 )
    Font::Font(v17, eFontProportional, 21.0, 1, 0);
  else
    v18 = 0;
  LOBYTE(v47) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v18);
  std::shared_ptr<Font>::operator=(&this->labCarName->font, &_Right);
  v19 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v19->_Destroy(v19);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v19->_Weaks, 0xFFFFFFFF) )
        v19->_Delete_this(v19);
    }
  }
  ksgui::Control::addControl(this, this->labCarName);
  v20 = (Font *)operator new(284);
  _Right._Ptr = v20;
  v21 = 0;
  LOBYTE(v47) = 13;
  if ( v20 )
  {
    v41 = (unsigned int)this->gui;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"CAMERA_DESCRIPTION", 0x12u);
    ksgui::Label::Label((ksgui::Label *)v20, v40, (ksgui::GUI *)v41);
  }
  this->labCameraDescription = v21;
  v21->drawBackground = 1;
  v22 = this->labCameraDescription;
  LOBYTE(v47) = 6;
  ((void (*)(ksgui::Label *, int, int))v22->setSize)(v22, 1130102784, 1103626240);
  v23 = this->labCameraDescription;
  this->foreColor = (vec4f)_xmm;
  v41 = 24;
  v23->foreColor = (vec4f)_xmm;
  this->labCameraDescription->drawBackground = 0;
  this->labCameraDescription->fontAlign = eAlignRight;
  v24 = (Font *)operator new(v41);
  _Right._Ptr = v24;
  LOBYTE(v47) = 14;
  if ( v24 )
    Font::Font(v24, eFontProportional, 18.0, 0, 0);
  else
    v25 = 0;
  LOBYTE(v47) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v25);
  std::shared_ptr<Font>::operator=(&this->labCameraDescription->font, &_Right);
  v26 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v26->_Destroy(v26);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v26->_Weaks, 0xFFFFFFFF) )
        v26->_Delete_this(v26);
    }
  }
  ksgui::Control::addControl(this, this->labCameraDescription);
  v27 = (Font *)operator new(284);
  _Right._Ptr = v27;
  v28 = 0;
  LOBYTE(v47) = 15;
  if ( v27 )
  {
    v41 = (unsigned int)this->gui;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"DRIVER_POSITION", 0xFu);
    ksgui::Label::Label((ksgui::Label *)v27, v40, (ksgui::GUI *)v41);
  }
  this->labDriverPosition = v28;
  v28->drawBackground = 1;
  v29 = this->labDriverPosition;
  this->foreColor = (vec4f)_xmm;
  v41 = 24;
  LOBYTE(v47) = 6;
  v29->foreColor = (vec4f)_xmm;
  this->labDriverPosition->drawBackground = 0;
  this->labDriverPosition->fontAlign = eAlignCenter;
  v30 = (Font *)operator new(v41);
  _Right._Ptr = v30;
  LOBYTE(v47) = 16;
  if ( v30 )
    Font::Font(v30, eFontProportional, 18.0, 0, 0);
  else
    v31 = 0;
  LOBYTE(v47) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v31);
  std::shared_ptr<Font>::operator=(&this->labDriverPosition->font, &_Right);
  v32 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v32->_Destroy(v32);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v32->_Weaks, 0xFFFFFFFF) )
        v32->_Delete_this(v32);
    }
  }
  ksgui::Control::addControl(this, this->labDriverPosition);
  v33 = (Font *)operator new(284);
  _Right._Ptr = v33;
  v34 = 0;
  LOBYTE(v47) = 17;
  if ( v33 )
  {
    v41 = (unsigned int)this->gui;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"CAR_NAME", 8u);
    ksgui::Label::Label((ksgui::Label *)v33, v40, (ksgui::GUI *)v41);
  }
  this->labLastTime = v34;
  v34->drawBackground = 1;
  v35 = this->labLastTime;
  LOBYTE(v47) = 6;
  ((void (*)(ksgui::Label *, int, int))v35->setSize)(v35, 1130102784, 1103626240);
  v36 = this->labLastTime;
  this->foreColor = (vec4f)_xmm;
  v41 = 24;
  v36->foreColor = (vec4f)_xmm;
  this->labLastTime->drawBackground = 0;
  this->labLastTime->fontAlign = eAlignLeft;
  v37 = (Font *)operator new(v41);
  _Right._Ptr = v37;
  LOBYTE(v47) = 18;
  if ( v37 )
    Font::Font(v37, eFontProportional, 18.0, 0, 0);
  else
    v38 = 0;
  LOBYTE(v47) = 6;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v38);
  std::shared_ptr<Font>::operator=(&this->labLastTime->font, &_Right);
  v39 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v39->_Destroy(v39);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v39->_Weaks) )
        v39->_Delete_this(v39);
    }
  }
  ksgui::Control::addControl(this, this->labLastTime);
}
void DriverStatusSystemMessage::~DriverStatusSystemMessage(DriverStatusSystemMessage *this)
{
  std::vector<std::wstring> *v2; // edi

  this->__vftable = (DriverStatusSystemMessage_vtbl *)&DriverStatusSystemMessage::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->bar);
  v2 = &this->cameraNames;
  if ( this->cameraNames._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cameraNames);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v2->_Myfirst, this->cameraNames._Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->cameraNames._Mylast = 0;
    this->cameraNames._Myend = 0;
  }
  std::vector<Texture>::_Tidy(&this->driverNationality);
  std::vector<Texture>::_Tidy(&this->carLogos);
  ksgui::Control::~Control(this);
}
DriverStatusSystemMessage *DriverStatusSystemMessage::`vector deleting destructor'(DriverStatusSystemMessage *this, unsigned int a2)
{
  DriverStatusSystemMessage::~DriverStatusSystemMessage(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DriverStatusSystemMessage::loadDriversInfo(DriverStatusSystemMessage *this)
{
  unsigned int v2; // esi
  int v3; // edi
  Sim *v4; // eax
  Texture *v5; // eax
  Texture *v6; // edx
  void *v7; // ecx
  const std::wstring *v8; // eax
  std::wstring *v9; // ecx
  CarAvatar *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  Sim *v13; // ecx
  Texture *v14; // eax
  Texture *v15; // edx
  void *v16; // ecx
  const std::wstring *v17; // eax
  std::wstring *v18; // ecx
  Sim *v19; // edi
  GameObject **v20; // esi
  ACCameraManager *v21; // eax
  std::wstring *v22; // eax
  std::vector<std::wstring> *v23; // esi
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  unsigned int v29; // ebx
  std::wstring *v30; // edi
  std::wstring *v31; // ecx
  int v32; // edi
  std::wstring *v33; // ebx
  int i; // [esp+14h] [ebp-7Ch]
  std::wstring filename; // [esp+18h] [ebp-78h] BYREF
  Texture result; // [esp+30h] [ebp-60h] BYREF
  std::wstring v37; // [esp+4Ch] [ebp-44h] BYREF
  Texture v38; // [esp+64h] [ebp-2Ch] BYREF
  int v39; // [esp+8Ch] [ebp-4h]

  std::vector<Texture>::resize(&this->driverNationality, this->sim->cars._Mylast - this->sim->cars._Myfirst);
  std::vector<Texture>::resize(&this->carLogos, this->sim->cars._Mylast - this->sim->cars._Myfirst);
  v2 = 0;
  if ( this->sim->cars._Mylast - this->sim->cars._Myfirst )
  {
    v3 = 0;
    do
    {
      filename._Myres = 7;
      filename._Mysize = 0;
      filename._Bx._Buf[0] = 0;
      std::wstring::assign(&filename, L"content/gui/Nationality/default.png", 0x23u);
      v4 = this->sim;
      v39 = 0;
      v5 = ResourceStore::getTexture(v4->game->graphics->resourceStore._Myptr, &result, &filename, 0);
      v6 = this->driverNationality._Myfirst;
      v7 = v5->kid;
      v8 = &v5->fileName;
      LOBYTE(v39) = 1;
      v6[v3].kid = v7;
      v9 = &v6[v3].fileName;
      if ( v9 != v8 )
        std::wstring::assign(v9, v8, 0, 0xFFFFFFFF);
      LOBYTE(v39) = 0;
      OnSetupAppCreated::~OnSetupAppCreated(&result);
      v39 = -1;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      v10 = Sim::getCar(this->sim, v2);
      v11 = std::operator+<wchar_t>((std::wstring *)&result, L"content/cars/", &v10->unixName);
      v39 = 2;
      v12 = std::operator+<wchar_t>(&filename, v11, L"/logo.png");
      v13 = this->sim;
      LOBYTE(v39) = 3;
      v14 = ResourceStore::getTexture(v13->game->graphics->resourceStore._Myptr, &v38, v12, 0);
      v15 = this->carLogos._Myfirst;
      v16 = v14->kid;
      v17 = &v14->fileName;
      LOBYTE(v39) = 4;
      v15[v3].kid = v16;
      v18 = &v15[v3].fileName;
      if ( v18 != v17 )
        std::wstring::assign(v18, v17, 0, 0xFFFFFFFF);
      LOBYTE(v39) = 3;
      OnSetupAppCreated::~OnSetupAppCreated(&v38);
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      filename._Myres = 7;
      filename._Mysize = 0;
      filename._Bx._Buf[0] = 0;
      v39 = -1;
      if ( result.fileName._Mysize >= 8 )
        operator delete(result.kid);
      ++v2;
      ++v3;
    }
    while ( v2 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
  }
  v19 = this->sim;
  v20 = v19->gameObjects._Myfirst;
  if ( v20 == v19->gameObjects._Mylast )
  {
LABEL_17:
    v21 = 0;
  }
  else
  {
    while ( 1 )
    {
      v21 = (ACCameraManager *)__RTDynamicCast(
                                 *v20,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &ACCameraManager `RTTI Type Descriptor',
                                 0);
      if ( v21 )
        break;
      if ( ++v20 == v19->gameObjects._Mylast )
        goto LABEL_17;
    }
  }
  this->cameraManager = v21;
  if ( v21 )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"Cockpit", 7u);
    v39 = 5;
    v22 = acTranslate((std::wstring *)&result, &filename);
    v23 = &this->cameraNames;
    LOBYTE(v39) = 6;
    std::vector<std::wstring>::push_back(&this->cameraNames, v22);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"Chase 1", 7u);
    v39 = 7;
    v24 = acTranslate((std::wstring *)&result, &filename);
    LOBYTE(v39) = 8;
    std::vector<std::wstring>::push_back(&this->cameraNames, v24);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"Chase 2", 7u);
    v39 = 9;
    v25 = acTranslate((std::wstring *)&result, &filename);
    LOBYTE(v39) = 10;
    std::vector<std::wstring>::push_back(&this->cameraNames, v25);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, (const wchar_t *)&stru_17C4688.text._Myres, 6u);
    v39 = 11;
    v26 = acTranslate((std::wstring *)&result, &filename);
    LOBYTE(v39) = 12;
    std::vector<std::wstring>::push_back(&this->cameraNames, v26);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, (const wchar_t *)&stru_17C4688.labWarning, 6u);
    v39 = 13;
    v27 = acTranslate((std::wstring *)&result, &filename);
    LOBYTE(v39) = 14;
    std::vector<std::wstring>::push_back(&this->cameraNames, v27);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"Dash", 4u);
    v39 = 15;
    v28 = acTranslate((std::wstring *)&result, &filename);
    LOBYTE(v39) = 16;
    std::vector<std::wstring>::push_back(&this->cameraNames, v28);
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    v39 = -1;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    v29 = 0;
    for ( i = 0; i < CameraTrack::getCameraTrackCount(this->cameraManager->cameraTrack); v29 = i )
    {
      v30 = CameraTrack::getCameraSetName(this->cameraManager->cameraTrack, &v37, v29);
      v31 = this->cameraNames._Mylast;
      v39 = 17;
      if ( v30 >= v31 || v23->_Myfirst > v30 )
      {
        if ( v31 == this->cameraNames._Myend )
          std::vector<std::wstring>::_Reserve(&this->cameraNames, 1u);
      }
      else
      {
        v32 = v30 - v23->_Myfirst;
        if ( v31 == this->cameraNames._Myend )
          std::vector<std::wstring>::_Reserve(&this->cameraNames, 1u);
        v30 = &v23->_Myfirst[v32];
      }
      v33 = this->cameraNames._Mylast;
      if ( v33 )
      {
        v33->_Myres = 7;
        v33->_Mysize = 0;
        v33->_Bx._Buf[0] = 0;
        if ( v30->_Myres >= 8 )
        {
          v33->_Bx._Ptr = v30->_Bx._Ptr;
          v30->_Bx._Ptr = 0;
        }
        else if ( v30->_Mysize != -1 )
        {
          _memmove(v33, v30, 2 * (v30->_Mysize + 1));
        }
        v33->_Mysize = v30->_Mysize;
        v33->_Myres = v30->_Myres;
        v30->_Myres = 7;
        v30->_Mysize = 0;
        v30->_Bx._Buf[0] = 0;
      }
      ++this->cameraNames._Mylast;
      v39 = -1;
      if ( v37._Myres >= 8 )
        operator delete(v37._Bx._Ptr);
      ++i;
    }
  }
}
void DriverStatusSystemMessage::render(DriverStatusSystemMessage *this, float dt)
{
  float v3; // xmm0_4
  Sim *v4; // ecx
  unsigned int v5; // edx
  CarAvatar *v6; // ebp
  ACCameraManager *v7; // esi
  unsigned int v8; // ebx
  ksgui::Label *v9; // ecx
  SessionType v10; // esi
  __int32 v11; // esi
  __int32 v12; // esi
  ksgui::Label *v13; // ecx
  Sim *v14; // ecx
  signed int v15; // eax
  std::wstring *v16; // esi
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  Sim *v20; // ecx
  signed int v21; // eax
  std::wstring *v22; // esi
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  ksgui::Label *v26; // ecx
  Sim *v27; // ecx
  std::wstring *v28; // esi
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  ksgui::Label *v32; // ecx
  ksgui::Form *v33; // ecx
  GLRenderer *v34; // ebx
  ESCMenu *v35; // eax
  float v36; // xmm0_4
  int left; // [esp+2Ch] [ebp-350h]
  __int64 v38; // [esp+34h] [ebp-348h]
  float v39; // [esp+3Ch] [ebp-340h]
  float v40; // [esp+50h] [ebp-32Ch]
  float v41; // [esp+50h] [ebp-32Ch]
  float v42; // [esp+54h] [ebp-328h]
  float v43; // [esp+54h] [ebp-328h]
  float top; // [esp+58h] [ebp-324h]
  float v45; // [esp+60h] [ebp-31Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v46; // [esp+64h] [ebp-318h] BYREF
  std::wstring text; // [esp+114h] [ebp-268h] BYREF
  std::wstring v48; // [esp+12Ch] [ebp-250h] BYREF
  std::wstring v49; // [esp+144h] [ebp-238h] BYREF
  std::wstring v50; // [esp+15Ch] [ebp-220h] BYREF
  std::wstring v51; // [esp+174h] [ebp-208h] BYREF
  std::wstring v52; // [esp+18Ch] [ebp-1F0h] BYREF
  std::wstring v53; // [esp+1A4h] [ebp-1D8h] BYREF
  std::wstring v54; // [esp+1BCh] [ebp-1C0h] BYREF
  std::wstring v55; // [esp+1D4h] [ebp-1A8h] BYREF
  std::wstring v56; // [esp+1ECh] [ebp-190h] BYREF
  std::wstring v57; // [esp+204h] [ebp-178h] BYREF
  std::wstring v58; // [esp+21Ch] [ebp-160h] BYREF
  Session result; // [esp+234h] [ebp-148h] BYREF
  std::wstring v60; // [esp+294h] [ebp-E8h] BYREF
  std::wstring v61; // [esp+2ACh] [ebp-D0h] BYREF
  std::wstring v62; // [esp+2C4h] [ebp-B8h] BYREF
  std::wstring v63; // [esp+2DCh] [ebp-A0h] BYREF
  std::wstring v64; // [esp+2F4h] [ebp-88h] BYREF
  std::wstring v65; // [esp+30Ch] [ebp-70h] BYREF
  std::wstring v66; // [esp+324h] [ebp-58h] BYREF
  Lap v67; // [esp+33Ch] [ebp-40h] BYREF
  int v68; // [esp+378h] [ebp-4h]

  v3 = this->rect.right - this->rect.left;
  v4 = this->sim;
  v5 = this->currentCarIndex;
  v40 = v3 * 0.5;
  top = (float)((float)(this->rect.bottom - this->rect.top) * 0.25) - 12.0;
  v42 = top + 40.0;
  if ( v5 > v4->cars._Mylast - v4->cars._Myfirst )
    return;
  v6 = Sim::getCar(v4, v5);
  this->labDriverName->setText(this->labDriverName, (const std::wstring *)&v6->driverInfo);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->labDriverName,
    (float)(v40 - 30.0) - (float)(this->labDriverName->rect.right - this->labDriverName->rect.left),
    top);
  this->labCarName->setText(this->labCarName, &v6->guiName);
  ksgui::Form::setPosition((ksgui::Form *)this->labCarName, v40 + 30.0, top);
  if ( this->currentCarIndex < this->cameraNames._Mylast - this->cameraNames._Myfirst )
  {
    v7 = this->cameraManager;
    v8 = v7->currentGlobalCameraIndex;
    if ( v8 >= this->cameraNames._Mylast - this->cameraNames._Myfirst || v7->randomMode )
    {
      std::wstring::wstring(&v49, word_17BE9D8);
      v9 = this->labCameraDescription;
      v68 = 0;
      v9->setText(v9, &v49);
      v68 = -1;
      if ( v49._Myres >= 8 )
        operator delete(v49._Bx._Ptr);
    }
    else
    {
      this->labCameraDescription->setText(this->labCameraDescription, &this->cameraNames._Myfirst[v8]);
    }
    ksgui::Form::setPosition((ksgui::Form *)this->labCameraDescription, v40 - 330.0, v42);
  }
  v10 = RaceManager::getCurrentSession(this->sim->raceManager, &result)->sessionType;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( result.spawSet._Myres >= 8 )
    operator delete(result.spawSet._Bx._Ptr);
  result.spawSet._Myres = 7;
  result.spawSet._Mysize = 0;
  result.spawSet._Bx._Buf[0] = 0;
  v11 = v10 - 1;
  if ( !v11 )
  {
    std::wstring::wstring(&v56, L"Practice");
    v68 = 1;
    v25 = acTranslate(&v49, &v56);
    v26 = this->labDriverPosition;
    LOBYTE(v68) = 2;
    v26->setText(v26, v25);
    if ( v49._Myres >= 8 )
      operator delete(v49._Bx._Ptr);
    v49._Myres = 7;
    v49._Mysize = 0;
    v49._Bx._Buf[0] = 0;
    v68 = -1;
    if ( v56._Myres >= 8 )
      operator delete(v56._Bx._Ptr);
    goto LABEL_34;
  }
  v12 = v11 - 1;
  if ( v12 )
  {
    if ( v12 != 1 )
    {
      std::wstring::wstring(&v57, word_17BE9D8);
      v13 = this->labDriverPosition;
      v68 = 23;
      v13->setText(v13, &v57);
      v68 = -1;
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      goto LABEL_34;
    }
    std::wstring::wstring(&v50, L"Race");
    v68 = 12;
    acTranslate(&text, &v50);
    LOBYTE(v68) = 14;
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    *(_DWORD *)v46.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v46.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v46.gap68);
    LOBYTE(v68) = 15;
    std::wiostream::basic_iostream<wchar_t>(&v46, &v46.gap10[8], 0);
    v68 = 16;
    *(_DWORD *)&v46.gap0[*(_DWORD *)(*(_DWORD *)v46.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v45 + *(_DWORD *)(*(_DWORD *)v46.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v46.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v46.gap10[8]);
    *(_DWORD *)&v46.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v46.gap10[64] = 0;
    *(_DWORD *)&v46.gap10[68] = 0;
    v14 = this->sim;
    LOBYTE(v68) = 18;
    v15 = RaceManager::getCarLeaderboardPosition(v14->raceManager, v6);
    if ( v15 >= 0 )
    {
      std::wostream::operator<<(v46.gap10, v15);
      std::wstring::wstring(&v58, L"Position");
      LOBYTE(v68) = 19;
      v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v46, &v62);
      LOBYTE(v68) = 20;
      v17 = acTranslate(&v60, &v58);
      LOBYTE(v68) = 21;
      v18 = std::operator+<wchar_t>(&v66, v17, L" : ");
      LOBYTE(v68) = 22;
      v19 = std::operator+<wchar_t>(&v65, v18, v16);
      std::wstring::operator=(&text, v19);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v65);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v60);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
      LOBYTE(v68) = 18;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v58);
    }
    this->labDriverPosition->setText(this->labDriverPosition, &text);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v46);
    v68 = -1;
    if ( text._Myres < 8 )
      goto LABEL_34;
  }
  else
  {
    std::wstring::wstring(&v51, L"Qualify");
    v68 = 3;
    acTranslate(&text, &v51);
    LOBYTE(v68) = 5;
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    *(_DWORD *)v46.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v46.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v46.gap68);
    LOBYTE(v68) = 6;
    std::wiostream::basic_iostream<wchar_t>(&v46, &v46.gap10[8], 0);
    v68 = 7;
    *(_DWORD *)&v46.gap0[*(_DWORD *)(*(_DWORD *)v46.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v45 + *(_DWORD *)(*(_DWORD *)v46.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v46.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v46.gap10[8]);
    *(_DWORD *)&v46.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v46.gap10[64] = 0;
    *(_DWORD *)&v46.gap10[68] = 0;
    v20 = this->sim;
    LOBYTE(v68) = 9;
    v21 = RaceManager::getCarLeaderboardPosition(v20->raceManager, v6);
    if ( v21 >= 0 )
    {
      std::wostream::operator<<(v46.gap10, v21);
      v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v46, &v61);
      LOBYTE(v68) = 10;
      v23 = std::operator+<wchar_t>(&v64, &text, L" : ");
      LOBYTE(v68) = 11;
      v24 = std::operator+<wchar_t>(&v63, v23, v22);
      std::wstring::operator=(&text, v24);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
      LOBYTE(v68) = 9;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
    }
    this->labDriverPosition->setText(this->labDriverPosition, &text);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v46);
    v68 = -1;
    if ( text._Myres < 8 )
      goto LABEL_34;
  }
  operator delete(text._Bx._Ptr);
LABEL_34:
  ((void (*)(ksgui::Label *, _DWORD, int))this->labDriverPosition->setSize)(
    this->labDriverPosition,
    this->rect.right - this->rect.left,
    1103626240);
  ksgui::Form::setPosition((ksgui::Form *)this->labDriverPosition, 0.0, v42);
  v48._Myres = 7;
  v48._Mysize = 0;
  v48._Bx._Buf[0] = 0;
  std::wstring::assign(&v48, L"Last", 4u);
  v27 = this->sim;
  v68 = 24;
  left = RaceManager::getLastLap(v27->raceManager, &v67, v6)->time;
  LOBYTE(v68) = 25;
  v28 = timeToString(&v52, left, 3);
  LOBYTE(v68) = 26;
  v29 = acTranslate(&v54, &v48);
  LOBYTE(v68) = 27;
  v30 = std::operator+<wchar_t>(&v55, v29, L" ");
  LOBYTE(v68) = 28;
  v31 = std::operator+<wchar_t>(&v53, v30, v28);
  v32 = this->labLastTime;
  LOBYTE(v68) = 29;
  v32->setText(v32, v31);
  if ( v53._Myres >= 8 )
    operator delete(v53._Bx._Ptr);
  v53._Myres = 7;
  v53._Mysize = 0;
  v53._Bx._Buf[0] = 0;
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  if ( v54._Myres >= 8 )
    operator delete(v54._Bx._Ptr);
  v54._Myres = 7;
  v54._Mysize = 0;
  v54._Bx._Buf[0] = 0;
  if ( v52._Myres >= 8 )
    operator delete(v52._Bx._Ptr);
  v52._Myres = 7;
  v52._Mysize = 0;
  v52._Bx._Buf[0] = 0;
  Lap::~Lap(&v67);
  v68 = -1;
  if ( v48._Myres >= 8 )
    operator delete(v48._Bx._Ptr);
  v33 = (ksgui::Form *)this->labLastTime;
  v48._Myres = 7;
  v48._Mysize = 0;
  v48._Bx._Buf[0] = 0;
  ksgui::Form::setPosition(v33, v40 + 110.0, v42);
  ksgui::Control::render(this, (int)this, (int)v28, dt, v38, v39);
  v34 = this->sim->game->graphics->gl;
  if ( this->currentCarIndex < this->driverNationality._Mylast - this->driverNationality._Myfirst )
  {
    GLRenderer::color4f(this->sim->game->graphics->gl, 1.0, 1.0, 1.0, 1.0);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->driverNationality._Myfirst[this->currentCarIndex]);
    v35 = this->sim->escMenu;
    if ( v35->visible )
      GLRenderer::quad(v34, (float)(v35->rect.right - v35->rect.left) + (float)(v40 - 15.0), top, 30.0, 20.0, 1, 0);
    else
      GLRenderer::quad(v34, v40 - 15.0, top, 30.0, 20.0, 1, 0);
  }
  v43 = (float)((float)(this->rect.bottom - this->rect.top) * 0.5) + 6.0;
  GLRenderer::color4f(v34, &this->borderColor);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->bar);
  v36 = this->rect.bottom - this->rect.top;
  v45 = v40 - 275.0;
  GLRenderer::quad(v34, v40 - 275.0, v36 * 0.5, 550.0, 1.0, 1, 0);
  GLRenderer::color4f(v34, &this->borderColor);
  GLRenderer::begin(v34, eLines, 0);
  GLRenderer::vertex3f(v34, v40 - 85.0, v43, 0.0);
  GLRenderer::vertex3f(v34, v40 - 85.0, v43 + 28.0, 0.0);
  GLRenderer::end(v34);
  GLRenderer::color4f(v34, &this->borderColor);
  GLRenderer::begin(v34, eLines, 0);
  v41 = v40 + 85.0;
  GLRenderer::vertex3f(v34, v41, v43, 0.0);
  GLRenderer::vertex3f(v34, v41, v43 + 28.0, 0.0);
  GLRenderer::end(v34);
  if ( this->currentCarIndex < this->carLogos._Mylast - this->carLogos._Myfirst )
  {
    GLRenderer::color4f(v34, 1.0, 1.0, 1.0, 1.0);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->carLogos._Myfirst[this->currentCarIndex]);
    GLRenderer::quad(v34, v45 - 80.0, 5.0, 70.0, 70.0, 1, 0);
  }
}
