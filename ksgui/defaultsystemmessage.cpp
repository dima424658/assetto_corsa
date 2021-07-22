#include "defaultsystemmessage.h
void DefaultSystemMessage::DefaultSystemMessage(DefaultSystemMessage *this, ksgui::GUI *gui)
{
  Texture *v3; // eax
  ksgui::Label *v4; // edi
  int v5; // eax
  Font *v6; // eax
  Font *v7; // eax
  ksgui::Label *v8; // ecx
  volatile signed __int32 *v9; // edi
  Font *v10; // edi
  int v11; // eax
  Font *v12; // eax
  Font *v13; // eax
  ksgui::Label *v14; // ecx
  volatile signed __int32 *v15; // edi
  std::wstring v16; // [esp-10h] [ebp-88h] BYREF
  unsigned int v17; // [esp+8h] [ebp-70h]
  int _Val; // [esp+20h] [ebp-58h] BYREF
  std::shared_ptr<Font> v19; // [esp+24h] [ebp-54h] BYREF
  ksgui::GUI *igui; // [esp+2Ch] [ebp-4Ch]
  DefaultSystemMessage *v21; // [esp+30h] [ebp-48h]
  std::wstring iname; // [esp+34h] [ebp-44h] BYREF
  Texture result; // [esp+4Ch] [ebp-2Ch] BYREF
  int v24; // [esp+74h] [ebp-4h]

  v21 = this;
  igui = gui;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"DEFAULT_SYSTEM_MESSAGE", 0x16u);
  v24 = 0;
  ksgui::Control::Control(this, &iname, gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (DefaultSystemMessage_vtbl *)&DefaultSystemMessage::`vftable';
  this->bar.kid = 0;
  this->bar.fileName._Myres = 7;
  this->bar.fileName._Mysize = 0;
  this->bar.fileName._Bx._Buf[0] = 0;
  LOBYTE(v24) = 3;
  this->backColor = (vec4f)_xmm;
  v17 = 33;
  v16._Myres = (unsigned int)L"content/gui/systemMessage/bar.png";
  this->borderColor = (vec4f)_xmm;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)v16._Myres, v17);
  LOBYTE(v24) = 4;
  v3 = ResourceStore::getTexture(gui->graphics->resourceStore._Myptr, &result, &iname, 0);
  LOBYTE(v24) = 5;
  this->bar.kid = v3->kid;
  if ( &this->bar.fileName != &v3->fileName )
    std::wstring::assign(&this->bar.fileName, &v3->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v24) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v24) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v17 = 284;
  *(_WORD *)&this->drawBorder = 257;
  v4 = (ksgui::Label *)operator new(v17);
  _Val = (int)v4;
  v5 = 0;
  LOBYTE(v24) = 6;
  if ( v4 )
  {
    v17 = (unsigned int)gui;
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    std::wstring::assign(&v16, L"SYSTEM_MESSAGE_TITLE", 0x14u);
    ksgui::Label::Label(v4, v16, (ksgui::GUI *)v17);
  }
  LOBYTE(v24) = 3;
  this->title = (ksgui::Label *)v5;
  this->foreColor = (vec4f)_xmm;
  v17 = 24;
  *(_OWORD *)(v5 + 76) = _xmm;
  this->title->drawBackground = 0;
  this->title->fontAlign = eAlignCenter;
  v6 = (Font *)operator new(v17);
  v19._Ptr = v6;
  LOBYTE(v24) = 7;
  if ( v6 )
    Font::Font(v6, eFontProportional, 21.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v24) = 3;
  v19 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v19, v7);
  v8 = this->title;
  v9 = (volatile signed __int32 *)v8->font._Rep;
  v8->font = v19;
  if ( v9 )
  {
    if ( !_InterlockedExchangeAdd(v9 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v9)(v9);
      if ( !_InterlockedExchangeAdd(v9 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v9 + 4))(v9);
    }
  }
  _Val = (int)this->title;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  v17 = 284;
  *(_DWORD *)(_Val + 148) = this;
  v10 = (Font *)operator new(v17);
  v19._Ptr = v10;
  v11 = 0;
  LOBYTE(v24) = 8;
  if ( v10 )
  {
    v17 = (unsigned int)igui;
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    std::wstring::assign(&v16, L"SYSTEM_MESSAGE_DESCRIPTION", 0x1Au);
    ksgui::Label::Label((ksgui::Label *)v10, v16, (ksgui::GUI *)v17);
  }
  LOBYTE(v24) = 3;
  this->description = (ksgui::Label *)v11;
  this->foreColor = (vec4f)_xmm;
  v17 = 24;
  *(_OWORD *)(v11 + 76) = _xmm;
  this->description->drawBackground = 0;
  this->description->fontAlign = eAlignCenter;
  v12 = (Font *)operator new(v17);
  v19._Ptr = v12;
  LOBYTE(v24) = 9;
  if ( v12 )
    Font::Font(v12, eFontProportional, 17.0, 0, 0);
  else
    v13 = 0;
  LOBYTE(v24) = 3;
  v19 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v19, v13);
  v14 = this->description;
  v15 = (volatile signed __int32 *)v14->font._Rep;
  v14->font = v19;
  if ( v15 )
  {
    if ( !_InterlockedExchangeAdd(v15 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v15)(v15);
      if ( !_InterlockedDecrement(v15 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v15 + 4))(v15);
    }
  }
  _Val = (int)this->description;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
}
DefaultSystemMessage *DefaultSystemMessage::`scalar deleting destructor'(DefaultSystemMessage *this, unsigned int a2)
{
  this->__vftable = (DefaultSystemMessage_vtbl *)&DefaultSystemMessage::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->bar);
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge DefaultSystemMessage::render(DefaultSystemMessage *this@<ecx>, int a2@<esi>, float dt)
{
  ksgui::Label_vtbl *v4; // eax
  ksgui::Label *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  ksgui::Label *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  GLRenderer *v16; // esi
  ksgui::Label *v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  __int64 v23; // [esp+28h] [ebp-10h]
  float v24; // [esp+30h] [ebp-8h]
  float v25; // [esp+34h] [ebp-4h]

  v4 = this->title->__vftable;
  if ( this->description->visible )
  {
    v25 = (float)(this->rect.right - this->rect.left) * 0.5;
    ((void (__stdcall *)(_DWORD, _DWORD))v4->setSize)(
      this->rect.right - this->rect.left,
      (float)(this->rect.bottom - this->rect.top) * 0.5);
    ((void (*)(ksgui::Label *, _DWORD, _DWORD))this->description->setSize)(
      this->description,
      this->rect.right - this->rect.left,
      (float)(this->rect.bottom - this->rect.top) * 0.5);
    v5 = this->title;
    v6 = v5->rectBase.left;
    v7 = v5->rect.bottom - v5->rect.top;
    v8 = v5->rect.right - v5->rect.left;
    v5->rect.top = 6.0;
    v5->rect.left = 0.0;
    v9 = v7 + 6.0;
    v5->rect.right = v8;
    v5->rect.bottom = v9;
    if ( v6 == 0.0 && v5->rectBase.top == 0.0 )
    {
      v5->rectBase.left = 0.0;
      v5->rectBase.top = 6.0;
      v5->rectBase.right = v8;
      v5->rectBase.bottom = v9;
    }
    v10 = this->description;
    v11 = v10->rectBase.left;
    v12 = v10->rect.bottom - v10->rect.top;
    v13 = v10->rect.right - v10->rect.left;
    v14 = (float)((float)(this->rect.bottom - this->rect.top) * 0.5) + 8.0;
    v10->rect.left = 0.0;
    v15 = v12 + v14;
    v10->rect.top = v14;
    v10->rect.right = v13;
    v10->rect.bottom = v15;
    if ( v11 == 0.0 && v10->rectBase.top == 0.0 )
    {
      v10->rectBase.left = 0.0;
      v10->rectBase.top = v14;
      v10->rectBase.right = v13;
      v10->rectBase.bottom = v15;
    }
    ksgui::Control::render(this, (int)this, a2, dt, v23, v24);
    v16 = this->controlGLR;
    GLRenderer::color4f(v16, &this->borderColor);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->bar);
    GLRenderer::quad(v16, v25 - 275.0, (float)(this->rect.bottom - this->rect.top) * 0.5, 550.0, 1.0, 1, 0);
  }
  else
  {
    ((void (__stdcall *)(_DWORD, _DWORD))v4->setSize)(
      this->rect.right - this->rect.left,
      (float)(this->rect.bottom - this->rect.top) * 0.5);
    v17 = this->title;
    v18 = v17->rect.bottom - v17->rect.top;
    v19 = v17->rect.right - v17->rect.left;
    v20 = (float)((float)(this->rect.bottom - this->rect.top) * 0.5) - (float)(v18 * 0.33333334);
    v17->rect.left = 0.0;
    v21 = v17->rectBase.left;
    v22 = v18 + v20;
    v17->rect.top = v20;
    v17->rect.right = v19;
    v17->rect.bottom = v22;
    if ( v21 == 0.0 && v17->rectBase.top == 0.0 )
    {
      v17->rectBase.left = 0.0;
      v17->rectBase.top = v20;
      v17->rectBase.right = v19;
      v17->rectBase.bottom = v22;
    }
    ksgui::Control::render(this, (int)this, a2, dt, v23, v24);
  }
}
void DefaultSystemMessage::setMessage(DefaultSystemMessage *this, std::wstring title, std::wstring description)
{
  this->title->setText(this->title, &title);
  this->description->setText(this->description, &description);
  if ( title._Myres >= 8 )
    operator delete(title._Bx._Ptr);
  title._Myres = 7;
  title._Mysize = 0;
  title._Bx._Buf[0] = 0;
  if ( description._Myres >= 8 )
    operator delete(description._Bx._Ptr);
}
