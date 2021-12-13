#include "achideall.h"
void ACHideAll::ACHideAll(ACHideAll *this, Sim *aSim)
{
  const std::wstring *v3; // eax
  bool v4; // zf
  ACHideAll_vtbl *v5; // eax
  ksgui::Control *v6; // ecx
  ksgui::Control_vtbl *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  _BYTE v11[28]; // [esp-Ch] [ebp-80h] BYREF
  float h; // [esp+10h] [ebp-64h]
  ACHideAll *v13; // [esp+30h] [ebp-44h]
  std::wstring text; // [esp+34h] [ebp-40h] BYREF
  std::wstring result; // [esp+4Ch] [ebp-28h] BYREF
  int v16; // [esp+70h] [ebp-4h]

  h = 0.0;
  v13 = this;
  *(_DWORD *)&v11[24] = aSim->game->gui;
  *(_DWORD *)&v11[20] = 7;
  *(_DWORD *)&v11[16] = 0;
  *(_WORD *)v11 = 0;
  std::wstring::assign((std::wstring *)v11, L"HIDE_APPS", 9u);
  ksgui::Form::Form(this, (unsigned int)aSim, *(std::wstring *)v11, *(ksgui::GUI **)&v11[24], SLOBYTE(h));
  v16 = 0;
  LODWORD(h) = 13;
  this->__vftable = (ACHideAll_vtbl *)&ACHideAll::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Hide all Apps", LODWORD(h));
  LOBYTE(v16) = 1;
  v3 = acTranslate(&result, &text);
  LOBYTE(v16) = 2;
  this->formTitle->setText(this->formTitle, v3);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v16) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v4 = !this->visible;
  this->devApp = 0;
  this->oldAppsOpened = 0;
  this->sim = aSim;
  if ( !v4 )
  {
    v5 = this->__vftable;
    h = 0.0;
    this->visible = 0;
    v5->onVisibleChanged(this, LODWORD(h));
  }
  v6 = this->formTitle;
  *(_WORD *)&this->drawBorder = 0;
  if ( v6->visible )
  {
    v7 = v6->__vftable;
    h = 0.0;
    v6->visible = 0;
    ((void (__stdcall *)(_DWORD))v7->onVisibleChanged)(LODWORD(h));
  }
  ksgui::Form::setIconVisible(this, 0);
  ksgui::Form::setSize(this, 0.0, 0.0);
  v8 = this->rectBase.left;
  v9 = this->rect.right - this->rect.left;
  v10 = this->rect.bottom - this->rect.top;
  this->rect.top = 0.0;
  this->rect.left = 0.0;
  this->rect.right = v9;
  this->rect.bottom = v10;
  if ( v8 == 0.0 && this->rectBase.top == 0.0 )
  {
    this->rectBase.left = 0.0;
    this->rectBase.top = 0.0;
    this->rectBase.right = v9;
    this->rectBase.bottom = v10;
  }
  *(_DWORD *)&v11[4] = &std::_Func_impl<std::_Callable_obj<_lambda_f2652e9655ac4ac94ea406878adb968e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v11[8] = this;
  *(_DWORD *)&v11[20] = &v11[4];
  LOBYTE(v16) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&aSim->game->gui->taskbar->evAppOpened,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v11[4],
    this);
  *(_DWORD *)&v11[4] = &std::_Func_impl<std::_Callable_obj<_lambda_83c168d685c22b66debe45fa0467ae4a_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v11[8] = this;
  *(_DWORD *)&v11[20] = &v11[4];
  LOBYTE(v16) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&aSim->game->gui->taskbar->evAppDismiss,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v11[4],
    this);
  *(_DWORD *)&v11[4] = &std::_Func_impl<std::_Callable_obj<_lambda_adbc95ba9dbbebff7a8f1dd866fed35c_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v11[8] = this;
  *(_DWORD *)&v11[20] = &v11[4];
  LOBYTE(v16) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&aSim->gameScreen->evDesktopShown,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v11[4],
    this);
  this->visible = 0;
  this->gs = aSim->gameScreen;
}
