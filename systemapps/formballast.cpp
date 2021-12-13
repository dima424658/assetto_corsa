#include "formballast.h"
void FormBallast::FormBallast(FormBallast *this, CarAvatar *aCar)
{
  int v3; // ebx
  Font *v4; // esi
  ksgui::Spinner *v5; // eax
  Font *v6; // esi
  int v7; // ebx
  const std::wstring *v8; // eax
  int v9; // eax
  int v10; // esi
  Font *v11; // eax
  Font *v12; // eax
  volatile signed __int32 *v13; // edi
  _BYTE v14[28]; // [esp-8h] [ebp-88h] BYREF
  float y; // [esp+14h] [ebp-6Ch]
  int _Val; // [esp+30h] [ebp-50h] BYREF
  std::shared_ptr<Font> v17; // [esp+34h] [ebp-4Ch] BYREF
  FormBallast *v18; // [esp+3Ch] [ebp-44h]
  std::wstring iname; // [esp+40h] [ebp-40h] BYREF
  std::wstring result; // [esp+58h] [ebp-28h] BYREF
  int v21; // [esp+7Ch] [ebp-4h]

  v3 = 0;
  _Val = 0;
  LODWORD(y) = 1;
  v18 = this;
  *(_DWORD *)&v14[24] = aCar->sim->game->gui;
  *(_DWORD *)&v14[20] = 7;
  *(_DWORD *)&v14[16] = 0;
  *(_WORD *)v14 = 0;
  std::wstring::assign((std::wstring *)v14, L"FORM_BALLAST", 0xCu);
  ksgui::Form::Form(this, 0, *(std::wstring *)v14, *(ksgui::GUI **)&v14[24], SLOBYTE(y));
  v21 = 0;
  LODWORD(y) = 1;
  this->__vftable = (FormBallast_vtbl *)&FormBallast::`vftable';
  this->spinner = 0;
  this->devApp = 0;
  ksgui::Form::setAutoHideMode(this, SLODWORD(y));
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Ballast", 7u);
  LOBYTE(v21) = 1;
  this->formTitle->setText(this->formTitle, &iname);
  LOBYTE(v21) = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v4 = (Font *)operator new(0x1BCu);
  v17._Ptr = v4;
  v5 = 0;
  LOBYTE(v21) = 2;
  if ( v4 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"spinnerBallast", 0xEu);
    y = 0.0;
    v3 = 1;
    LOBYTE(v21) = 3;
    *(_DWORD *)&v14[24] = 1;
    *(_DWORD *)&v14[20] = this->gui;
    _Val = 1;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v4, &iname, *(ksgui::GUI **)&v14[20], 1, 0);
  }
  this->spinner = v5;
  v21 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v6 = (Font *)operator new(0x1BCu);
  v17._Ptr = v6;
  LOBYTE(v21) = 5;
  if ( v6 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Ballast", 7u);
    LOBYTE(v21) = 6;
    v7 = v3 | 2;
    _Val = v7;
    v8 = acTranslate(&result, &iname);
    y = 0.0;
    *(_DWORD *)&v14[24] = 1;
    v21 = 7;
    v3 = v7 | 4;
    *(_DWORD *)&v14[20] = this->gui;
    _Val = v3;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v6, v8, *(ksgui::GUI **)&v14[20], 1, 0);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  if ( (v3 & 4) != 0 )
  {
    LOBYTE(v3) = v3 & 0xFB;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v21 = 0;
  if ( (v3 & 2) != 0 )
  {
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
  }
  y = 0.0;
  *(_DWORD *)(v10 + 288) = 0;
  *(_DWORD *)(v10 + 296) = 1;
  *(_DWORD *)(v10 + 292) = 150;
  ksgui::Spinner::setValue((ksgui::Spinner *)v10, SLODWORD(y));
  *(_DWORD *)&v14[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3479fde088a2586ab0371d2b7374ba88_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v14[8] = aCar;
  *(_DWORD *)&v14[20] = &v14[4];
  LOBYTE(v21) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)(v10 + 300),
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v14[4],
    this);
  ksgui::Spinner::setDrawArrows((ksgui::Spinner *)v10, 1);
  (*(void (**)(int, int, int))(*(_DWORD *)v10 + 28))(v10, 1127743488, 1101529088);
  v11 = (Font *)operator new(0x18u);
  v17._Ptr = v11;
  LOBYTE(v21) = 11;
  if ( v11 )
    Font::Font(v11, eFontProportional, 12.0, 0, 0);
  else
    v12 = 0;
  LOBYTE(v21) = 0;
  v17 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v17, v12);
  v13 = *(volatile signed __int32 **)(v10 + 132);
  *(std::shared_ptr<Font> *)(v10 + 128) = v17;
  if ( v13 )
  {
    if ( !_InterlockedExchangeAdd(v13 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v13)(v13);
      if ( !_InterlockedDecrement(v13 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v13 + 4))(v13);
    }
  }
  ksgui::Spinner::setPosition((ksgui::Spinner *)v10, 58.0, 70.0);
  _Val = v10;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  y = 110.0;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 300.0, y);
  ((void (*)(FormBallast *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
}
