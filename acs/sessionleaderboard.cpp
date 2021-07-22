#include "sessionleaderboard.h"
void SessionLeaderboard::SessionLeaderboard(SessionLeaderboard *this, Sim *aSim)
{
  char v3; // bl
  ksgui::Control *v4; // edi
  ksgui::Control *v5; // eax
  Game *v6; // eax
  ksgui::Control *v7; // eax
  ACStandardLeaderboard *v8; // eax
  int v9; // eax
  int v10; // edi
  ksgui::Control *v11; // ecx
  float v12; // xmm2_4
  ksgui::Control_vtbl *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  Event<OnMouseDownEvent> *v17; // ecx
  Event<OnMouseWheelMovedEvent> *v18; // ecx
  Event<OnMouseWheelMovedEvent> *v19; // ecx
  std::wstring v20; // [esp-8h] [ebp-70h] BYREF
  int left_4; // [esp+10h] [ebp-58h]
  __int64 left; // [esp+34h] [ebp-34h]
  SessionLeaderboard *v23; // [esp+3Ch] [ebp-2Ch]
  std::wstring iname; // [esp+40h] [ebp-28h] BYREF
  int v25; // [esp+64h] [ebp-4h]

  v3 = 0;
  HIDWORD(left) = 0;
  v23 = this;
  left_4 = (int)aSim->game;
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  std::wstring::assign(&v20, L"ESC_MENU_LEADERBOARD", 0x14u);
  GameObject::GameObject(this, v20, (Game *)left_4);
  left_4 = 280;
  v25 = 0;
  this->__vftable = (SessionLeaderboard_vtbl *)&SessionLeaderboard::`vftable';
  v4 = (ksgui::Control *)operator new(left_4);
  LODWORD(left) = v4;
  v5 = 0;
  LOBYTE(v25) = 1;
  if ( v4 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"PARENT_CONTROL", 0xEu);
    v6 = this->game;
    v3 = 1;
    LOBYTE(v25) = 2;
    HIDWORD(left) = 1;
    ksgui::Control::Control(v4, &iname, v6->gui);
  }
  this->parentControl = v5;
  v25 = 0;
  if ( (v3 & 1) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(_DWORD, _DWORD, _DWORD))this->parentControl->setSize)(
    this->parentControl,
    (float)this->game->graphics->videoSettings.width,
    (float)this->game->graphics->videoSettings.height);
  ksgui::Form::setPosition((ksgui::Form *)this->parentControl, 0.0, 0.0);
  v7 = this->parentControl;
  left_4 = 536;
  v7->drawBorder = 0;
  v8 = (ACStandardLeaderboard *)operator new(left_4);
  LODWORD(left) = v8;
  LOBYTE(v25) = 4;
  if ( v8 )
  {
    ACStandardLeaderboard::ACStandardLeaderboard(v8, aSim, 10, 1);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  LOBYTE(v25) = 0;
  Sim::isInTripleScreenMode(aSim);
  v11 = this->parentControl;
  v12 = v11->rect.right - v11->rect.left;
  v13 = v11->__vftable;
  v14 = (float)(*(float *)(v10 + 32) - *(float *)(v10 + 28)) * 0.5;
  left_4 = v10;
  v15 = (float)(v12 * 0.5) - v14;
  v16 = *(float *)(v10 + 40) - *(float *)(v10 + 36);
  *(float *)&left = v15;
  *((float *)&left + 1) = (float)((float)(v11->rect.bottom - v11->rect.top) * 0.5) - (float)(v16 * 0.5);
  ((void (__stdcall *)(int))v13->addControl)(v10);
  ksgui::Form::setPosition((ksgui::Form *)v10, *(float *)&left, *((float *)&left + 1));
  left_4 = (int)this;
  *(_DWORD *)(v10 + 436) = 2;
  *(_BYTE *)(v10 + 440) = 0;
  v20._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_24367c9bb314e4401f0a883470dec8f8_,0>,std::allocator<std::_Func_class<void,OnMouseDownEvent const &>>,void,OnMouseDownEvent const &>::`vftable';
  *(_DWORD *)&v20._Bx._Alias[4] = this;
  v20._Mysize = (unsigned int)&v20;
  v17 = &this->game->window.evOnMouseDown;
  LOBYTE(v25) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v17,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v20,
    (void *)left_4);
  left_4 = (int)this;
  v20._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e5daf2dd37a3422ce554481036ba3d08_,0>,std::allocator<std::_Func_class<void,OnMouseUpEvent const &>>,void,OnMouseUpEvent const &>::`vftable';
  *(_DWORD *)&v20._Bx._Alias[4] = this;
  v20._Mysize = (unsigned int)&v20;
  v18 = (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseUp;
  LOBYTE(v25) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v18,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v20,
    this);
  left_4 = (int)this;
  v20._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_a5cb235b6f1de62b1d977ec75d7dd7e7_,0>,std::allocator<std::_Func_class<void,OnMouseMoveEvent const &>>,void,OnMouseMoveEvent const &>::`vftable';
  *(_DWORD *)&v20._Bx._Alias[4] = this;
  v20._Mysize = (unsigned int)&v20;
  v19 = (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseMove;
  LOBYTE(v25) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    v19,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v20,
    this);
}
SessionLeaderboard *SessionLeaderboard::`scalar deleting destructor'(SessionLeaderboard *this, unsigned int a2)
{
  ksgui::Control *v3; // ecx

  this->__vftable = (SessionLeaderboard_vtbl *)&SessionLeaderboard::`vftable';
  v3 = this->parentControl;
  if ( v3 )
    ((void (*)(ksgui::Control *, int))v3->~Control)(v3, 1);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SessionLeaderboard::renderHUD(SessionLeaderboard *this, float dt)
{
  ksgui::Control *v2; // ecx

  v2 = this->parentControl;
  if ( v2->visible )
    ((void (__stdcall *)(_DWORD))v2->render)(LODWORD(dt));
}
void SessionLeaderboard::setVisible(SessionLeaderboard *this, BOOL value)
{
  ksgui::Control::setVisible(this->parentControl, value);
}
