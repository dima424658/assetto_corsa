#include "formdrivermodel.h
void FormDriverModel::FormDriverModel(FormDriverModel *this, CarAvatar *aCar)
{
  Sim *v3; // eax
  const std::wstring *v4; // eax
  wchar_t *v5; // eax
  Font *v6; // eax
  wchar_t *v7; // esi
  int v8; // eax
  int v9; // esi
  float v10; // eax
  volatile signed __int32 *v11; // ebp
  int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  wchar_t *v18; // esi
  ksgui::Spinner *v19; // eax
  ksgui::Spinner *v20; // ecx
  float v21; // eax
  ksgui::Spinner *v22; // esi
  volatile signed __int32 *v23; // edi
  ksgui::Spinner *v24; // eax
  int i; // ebp
  ksgui::Spinner *v26; // edi
  int v27; // ecx
  ksgui::Spinner *v28; // ecx
  std::vector<ksgui::Control *> *v29; // ebp
  ksgui::Control **v30; // eax
  int v31; // edi
  ksgui::Control **v32; // edx
  ksgui::Control **v33; // eax
  wchar_t *v34; // edi
  ksgui::Spinner *v35; // eax
  std::_Ref_count_base *v36; // edi
  ksgui::Spinner *v37; // edx
  volatile signed __int32 *v38; // esi
  Font *v39; // eax
  ksgui::Spinner *v40; // eax
  ksgui::Spinner *v41; // edi
  int v42; // ecx
  ksgui::Spinner *v43; // edi
  int v44; // ecx
  ksgui::Spinner *v45; // edi
  int v46; // ecx
  ksgui::Spinner *v47; // ecx
  ksgui::Control **v48; // eax
  int v49; // esi
  ksgui::Control **v50; // edx
  ksgui::Control **v51; // eax
  ksgui::Spinner *v52; // eax
  ksgui::Spinner *v53; // eax
  ksgui::Spinner *v54; // eax
  ksgui::Spinner *v55; // eax
  wchar_t *v56; // esi
  ksgui::Spinner *v57; // eax
  ksgui::Spinner *v58; // eax
  int j; // esi
  wchar_t *v60; // esi
  ksgui::Spinner *v61; // eax
  ksgui::Spinner *v62; // eax
  int k; // esi
  wchar_t *v64; // esi
  ksgui::Spinner *v65; // eax
  ksgui::Spinner *v66; // eax
  int l; // esi
  wchar_t *v68; // esi
  ksgui::Spinner *v69; // eax
  ksgui::Spinner *v70; // eax
  int m; // esi
  wchar_t *v72; // esi
  ksgui::Spinner *v73; // eax
  ksgui::Spinner *v74; // eax
  int n; // esi
  wchar_t *v76; // esi
  ksgui::Control *v77; // eax
  bool v78; // zf
  ksgui::Control *v79; // eax
  const __m128i *v80; // eax
  CarAvatar *v81; // esi
  bool v82; // al
  std::wstring *v83; // eax
  std::wstring *v84; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v85; // ecx
  std::wstring *v86; // eax
  std::wstring *v87; // eax
  std::wstring *v88; // eax
  std::wstring *v89; // eax
  FormDriverModel::{ctor}::__l43::<lambda_d585b647a5665d78a2e60f3ee5d46edd> *v90; // eax
  _BYTE h[64]; // [esp+58h] [ebp-100h] BYREF
  int _Val; // [esp+B0h] [ebp-A8h] BYREF
  int v93; // [esp+B4h] [ebp-A4h]
  std::shared_ptr<Font> smallfont; // [esp+B8h] [ebp-A0h] BYREF
  ksgui::Spinner *v95; // [esp+C0h] [ebp-98h] BYREF
  int v96[2]; // [esp+C4h] [ebp-94h] BYREF
  std::wstring result; // [esp+CCh] [ebp-8Ch] BYREF
  std::wstring text; // [esp+E4h] [ebp-74h] BYREF
  std::wstring filename; // [esp+FCh] [ebp-5Ch] BYREF
  FormDriverModel::{ctor}::__l43::<lambda_d585b647a5665d78a2e60f3ee5d46edd> v100; // [esp+114h] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v101; // [esp+130h] [ebp-28h] BYREF
  int v102; // [esp+154h] [ebp-4h]

  _Val = 0;
  v93 = 0;
  *(_DWORD *)&h[28] = 1;
  v3 = aCar->sim;
  v96[1] = (int)this;
  *(_DWORD *)&h[24] = v3->game->gui;
  *(_DWORD *)&h[20] = 7;
  *(_DWORD *)&h[16] = 0;
  *(_WORD *)h = 0;
  std::wstring::assign((std::wstring *)h, L"FORM_DRIVER_MODEL", 0x11u);
  ksgui::Form::Form(this, (unsigned int)this, *(std::wstring *)h, *(ksgui::GUI **)&h[24], h[28]);
  v102 = 0;
  this->__vftable = (FormDriverModel_vtbl *)&FormDriverModel::`vftable';
  *(_DWORD *)&h[28] = 22;
  this->accG.x = 0.0;
  this->accG.y = 0.0;
  this->accG.z = 0.0;
  *(_DWORD *)&h[24] = L"Driver Model Utilities";
  *(_WORD *)&this->loaded = 0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&h[24], *(unsigned int *)&h[28]);
  LOBYTE(v102) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v102) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v102) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  *(_DWORD *)&h[28] = 1;
  this->devApp = 1;
  this->avatar = aCar;
  ksgui::Form::setAutoHideMode(this, *(BOOL *)&h[28]);
  v5 = (wchar_t *)operator new(0x18u);
  text._Bx._Ptr = v5;
  LOBYTE(v102) = 3;
  if ( v5 )
    Font::Font((Font *)v5, eFontMonospaced, 14.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v102) = 0;
  smallfont._Ptr = 0;
  smallfont._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&smallfont, v6);
  LOBYTE(v102) = 4;
  v7 = (wchar_t *)operator new(0x11Cu);
  text._Bx._Ptr = v7;
  LOBYTE(v102) = 5;
  if ( v7 )
  {
    *(_DWORD *)&h[28] = this->gui;
    *(_DWORD *)&h[24] = 7;
    *(_DWORD *)&h[20] = 0;
    *(_WORD *)&h[4] = 0;
    std::wstring::assign((std::wstring *)&h[4], L"Head_movement_title", 0x13u);
    ksgui::Label::Label((ksgui::Label *)v7, *(std::wstring *)&h[4], *(ksgui::GUI **)&h[28]);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v102) = 4;
  *(_DWORD *)&h[28] = smallfont._Rep;
  v10 = this->fontScale;
  *(_DWORD *)&h[24] = smallfont._Ptr;
  *(float *)(v9 + 208) = v10;
  *(_QWORD *)text._Bx._Buf = 0i64;
  std::_Ptr_base<Font>::_Reset(
    (std::_Ptr_base<Material> *)&text,
    *(Material **)&h[24],
    *(std::_Ref_count_base **)&h[28]);
  v11 = *(volatile signed __int32 **)(v9 + 132);
  *(_QWORD *)(v9 + 128) = *(_QWORD *)text._Bx._Buf;
  if ( v11 )
  {
    if ( !_InterlockedExchangeAdd(v11 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v11)(v11);
      if ( !_InterlockedExchangeAdd(v11 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v11 + 4))(v11);
    }
  }
  *(_DWORD *)&h[28] = 13;
  *(_DWORD *)(v9 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Head Movement", *(unsigned int *)&h[28]);
  LOBYTE(v102) = 6;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v9 + 68))(v9, &text);
  LOBYTE(v102) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v12 = *(_DWORD *)v9;
  *(_OWORD *)(v9 + 76) = _xmm;
  (*(void (**)(int, int, int))(v12 + 28))(v9, 1128792064, 1101004800);
  v13 = *(float *)(v9 + 264);
  v14 = *(float *)(v9 + 32) - *(float *)(v9 + 28);
  v15 = *(float *)(v9 + 40) - *(float *)(v9 + 36);
  *(_DWORD *)(v9 + 36) = 1106247680;
  *(_DWORD *)(v9 + 28) = 1084227584;
  v16 = v14 + 5.0;
  v17 = v15 + 30.0;
  *(float *)(v9 + 32) = v16;
  *(float *)(v9 + 40) = v17;
  if ( v13 == 0.0 && *(float *)(v9 + 272) == 0.0 )
  {
    *(_DWORD *)(v9 + 264) = 1084227584;
    *(_DWORD *)(v9 + 272) = 1106247680;
    *(float *)(v9 + 268) = v16;
    *(float *)(v9 + 276) = v17;
  }
  _Val = v9;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v18 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v18;
  v19 = 0;
  LOBYTE(v102) = 7;
  if ( v18 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"G Force", 7u);
    LOBYTE(v102) = 8;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 = 1;
    _Val = 1;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v18, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  this->gForce = v19;
  v102 = 4;
  if ( (v93 & 1) != 0 )
  {
    v93 &= 0xFFFFFFFE;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v20 = this->gForce;
  *(_DWORD *)&h[28] = smallfont._Rep;
  v21 = this->fontScale;
  *(_DWORD *)&h[24] = smallfont._Ptr;
  v20->fontScale = v21;
  v22 = this->gForce;
  *(_QWORD *)text._Bx._Buf = 0i64;
  std::_Ptr_base<Font>::_Reset(
    (std::_Ptr_base<Material> *)&text,
    *(Material **)&h[24],
    *(std::_Ref_count_base **)&h[28]);
  v23 = (volatile signed __int32 *)v22->font._Rep;
  v22->font = *(std::shared_ptr<Font> *)text._Bx._Buf;
  if ( v23 )
  {
    if ( !_InterlockedExchangeAdd(v23 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v23)(v23);
      if ( !_InterlockedExchangeAdd(v23 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v23 + 4))(v23);
    }
  }
  this->gForce->fontAlign = eAlignCenter;
  v24 = this->gForce;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v24->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->gForce->setSize)(
    this->gForce,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->gForce, 5.0, 80.0);
  for ( i = 0; i < 31; ++i )
  {
    std::to_wstring(&result, (float)i * 0.1);
    v26 = this->gForce;
    LOBYTE(v102) = 10;
    std::vector<std::wstring>::push_back(&v26->items, &result);
    v26->minValue = 0;
    v27 = (char *)v26->items._Mylast - (char *)v26->items._Myfirst;
    LOBYTE(v102) = 4;
    v26->maxValue = ((int)((unsigned __int64)(715827883i64 * v27) >> 32) >> 2)
                  + ((unsigned int)((unsigned __int64)(715827883i64 * v27) >> 32) >> 31)
                  - 1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_4d8035fa4009959b4cdd71326fc7fa0b_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->gForce->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  v28 = this->gForce;
  v29 = &this->controls;
  v30 = this->controls._Mylast;
  _Val = (int)v28;
  v95 = v28;
  if ( &v95 >= v30 || v29->_Myfirst > &v95 )
  {
    if ( v30 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v28 = (ksgui::Spinner *)_Val;
    }
    v33 = this->controls._Mylast;
    if ( v33 )
      *v33 = v28;
  }
  else
  {
    v31 = &v95 - (ksgui::Spinner **)v29->_Myfirst;
    if ( v30 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v28 = (ksgui::Spinner *)_Val;
    }
    v32 = this->controls._Mylast;
    if ( v32 )
      *v32 = v29->_Myfirst[v31];
  }
  ++this->controls._Mylast;
  *(_DWORD *)&h[28] = 444;
  v28->parent = this;
  v34 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v34;
  v35 = 0;
  LOBYTE(v102) = 12;
  if ( v34 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"G Direction X", 0xDu);
    LOBYTE(v102) = 13;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 2u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v34, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  this->gDirectionX = v35;
  v102 = 4;
  if ( (v93 & 2) != 0 )
  {
    v93 &= 0xFFFFFFFD;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v36 = smallfont._Rep;
  this->gDirectionX->fontScale = this->fontScale;
  v37 = this->gDirectionX;
  if ( v36 )
    _InterlockedExchangeAdd((volatile signed __int32 *)&v36->_Uses, 1u);
  v38 = (volatile signed __int32 *)v37->font._Rep;
  v39 = smallfont._Ptr;
  v37->font._Rep = v36;
  v37->font._Ptr = v39;
  if ( v38 )
  {
    if ( !_InterlockedExchangeAdd(v38 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v38)(v38);
      if ( !_InterlockedDecrement(v38 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v38 + 4))(v38);
    }
  }
  this->gDirectionX->fontAlign = eAlignCenter;
  v40 = this->gDirectionX;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v40->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->gDirectionX->setSize)(
    this->gDirectionX,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->gDirectionX, 5.0, 130.0);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"Negative", 8u);
  v41 = this->gDirectionX;
  LOBYTE(v102) = 15;
  std::vector<std::wstring>::push_back(&v41->items, &result);
  v41->minValue = 0;
  v42 = (char *)v41->items._Mylast - (char *)v41->items._Myfirst;
  LOBYTE(v102) = 4;
  v41->maxValue = ((int)((unsigned __int64)(715827883i64 * v42) >> 32) >> 2)
                + ((unsigned int)((unsigned __int64)(715827883i64 * v42) >> 32) >> 31)
                - 1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"No Force", 8u);
  v43 = this->gDirectionX;
  LOBYTE(v102) = 16;
  std::vector<std::wstring>::push_back(&v43->items, &result);
  v43->minValue = 0;
  v44 = (char *)v43->items._Mylast - (char *)v43->items._Myfirst;
  LOBYTE(v102) = 4;
  v43->maxValue = ((int)((unsigned __int64)(715827883i64 * v44) >> 32) >> 2)
                + ((unsigned int)((unsigned __int64)(715827883i64 * v44) >> 32) >> 31)
                - 1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"Positive", 8u);
  v45 = this->gDirectionX;
  LOBYTE(v102) = 17;
  std::vector<std::wstring>::push_back(&v45->items, &result);
  v45->minValue = 0;
  v46 = (char *)v45->items._Mylast - (char *)v45->items._Myfirst;
  LOBYTE(v102) = 4;
  v45->maxValue = ((int)((unsigned __int64)(715827883i64 * v46) >> 32) >> 2)
                + ((unsigned int)((unsigned __int64)(715827883i64 * v46) >> 32) >> 31)
                - 1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ksgui::Spinner::setValue(this->gDirectionX, 1);
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_4c92995575c5794bd396a7a9e00c1789_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->gDirectionX->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  v47 = this->gDirectionX;
  v48 = this->controls._Mylast;
  _Val = (int)v47;
  v96[0] = (int)v47;
  if ( v96 >= (int *)v48 || v29->_Myfirst > (ksgui::Control **)v96 )
  {
    if ( v48 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v47 = (ksgui::Spinner *)_Val;
    }
    v51 = this->controls._Mylast;
    if ( v51 )
      *v51 = v47;
  }
  else
  {
    v49 = ((char *)v96 - (char *)v29->_Myfirst) >> 2;
    if ( v48 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v47 = (ksgui::Spinner *)_Val;
    }
    v50 = this->controls._Mylast;
    if ( v50 )
      *v50 = v29->_Myfirst[v49];
  }
  ++this->controls._Mylast;
  *(_DWORD *)&h[28] = 444;
  v47->parent = this;
  text._Bx._Ptr = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v102) = 19;
  if ( text._Bx._Ptr )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"G Direction Y", 0xDu);
    LOBYTE(v102) = 20;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 4u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)text._Bx._Ptr, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  else
  {
    v52 = 0;
  }
  this->gDirectionY = v52;
  v102 = 4;
  if ( (v93 & 4) != 0 )
  {
    v93 &= 0xFFFFFFFB;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->gDirectionY->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->gDirectionY->font, &smallfont);
  this->gDirectionY->fontAlign = eAlignCenter;
  v53 = this->gDirectionY;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v53->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->gDirectionY->setSize)(
    this->gDirectionY,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->gDirectionY, 5.0, 180.0);
  *(_DWORD *)&h[28] = 7;
  *(_DWORD *)&h[24] = 0;
  *(_WORD *)&h[8] = 0;
  std::wstring::assign((std::wstring *)&h[8], L"Negative", 8u);
  ksgui::Spinner::addItem(this->gDirectionY, *(std::wstring *)&h[8]);
  *(_DWORD *)&h[28] = 7;
  *(_DWORD *)&h[24] = 0;
  *(_WORD *)&h[8] = 0;
  std::wstring::assign((std::wstring *)&h[8], L"No Force", 8u);
  ksgui::Spinner::addItem(this->gDirectionY, *(std::wstring *)&h[8]);
  *(_DWORD *)&h[28] = 7;
  *(_DWORD *)&h[24] = 0;
  *(_WORD *)&h[8] = 0;
  std::wstring::assign((std::wstring *)&h[8], L"Positive", 8u);
  ksgui::Spinner::addItem(this->gDirectionY, *(std::wstring *)&h[8]);
  ksgui::Spinner::setValue(this->gDirectionY, 1);
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_47d07b2d836dc5977966343d84141a44_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->gDirectionY->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->gDirectionY;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  text._Bx._Ptr = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  LOBYTE(v102) = 23;
  if ( text._Bx._Ptr )
  {
    std::wstring::wstring(&result, L"G Direction Z");
    LOBYTE(v102) = 24;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 8u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)text._Bx._Ptr, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  else
  {
    v54 = 0;
  }
  this->gDirectionZ = v54;
  v102 = 4;
  if ( (v93 & 8) != 0 )
  {
    v93 &= 0xFFFFFFF7;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->gDirectionZ->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->gDirectionZ->font, &smallfont);
  this->gDirectionZ->fontAlign = eAlignCenter;
  v55 = this->gDirectionZ;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v55->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->gDirectionZ->setSize)(
    this->gDirectionZ,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->gDirectionZ, 5.0, 230.0);
  *(_DWORD *)&h[28] = 7;
  *(_DWORD *)&h[24] = 0;
  *(_WORD *)&h[8] = 0;
  std::wstring::assign((std::wstring *)&h[8], L"Negative", 8u);
  ksgui::Spinner::addItem(this->gDirectionZ, *(std::wstring *)&h[8]);
  std::wstring::wstring((std::wstring *)&h[8], L"No Force");
  ksgui::Spinner::addItem(this->gDirectionZ, *(std::wstring *)&h[8]);
  std::wstring::wstring((std::wstring *)&h[8], L"Positive");
  ksgui::Spinner::addItem(this->gDirectionZ, *(std::wstring *)&h[8]);
  ksgui::Spinner::setValue(this->gDirectionZ, 1);
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_fe5a91515c9953887c1460f0044c9dca_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->gDirectionZ->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->gDirectionZ;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v56 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v56;
  LOBYTE(v102) = 27;
  if ( v56 )
  {
    std::wstring::wstring(&result, L"Max G Force");
    LOBYTE(v102) = 28;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 0x10u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v56, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  else
  {
    v57 = 0;
  }
  this->spMaxG = v57;
  v102 = 4;
  if ( (v93 & 0x10) != 0 )
  {
    v93 &= 0xFFFFFFEF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->spMaxG->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->spMaxG->font, &smallfont);
  this->spMaxG->fontAlign = eAlignCenter;
  v58 = this->spMaxG;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v58->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spMaxG->setSize)(
    this->spMaxG,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->spMaxG, 210.0, 80.0);
  for ( j = 0; j < 31; ++j )
  {
    std::to_wstring((std::wstring *)&h[8], (float)j * 0.1);
    ksgui::Spinner::addItem(this->spMaxG, *(std::wstring *)&h[8]);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_86b1dcff24ed3ac8cd41b2c1af768aef_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spMaxG->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->spMaxG;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v60 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v60;
  v61 = 0;
  LOBYTE(v102) = 31;
  if ( v60 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"Roll Max Deg", 0xCu);
    LOBYTE(v102) = 32;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 0x20u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v60, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  this->spRollMaxDeg = v61;
  v102 = 4;
  if ( (v93 & 0x20) != 0 )
  {
    v93 &= 0xFFFFFFDF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->spRollMaxDeg->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->spRollMaxDeg->font, &smallfont);
  this->spRollMaxDeg->fontAlign = eAlignCenter;
  v62 = this->spRollMaxDeg;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v62->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spRollMaxDeg->setSize)(
    this->spRollMaxDeg,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->spRollMaxDeg, 210.0, 130.0);
  for ( k = 0; k < 101; ++k )
  {
    std::to_wstring((std::wstring *)&h[8], k - 50);
    ksgui::Spinner::addItem(this->spRollMaxDeg, *(std::wstring *)&h[8]);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6efc1d0bf9b940ce381d15e5d54a45e0_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spRollMaxDeg->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->spRollMaxDeg;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v64 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v64;
  v65 = 0;
  LOBYTE(v102) = 35;
  if ( v64 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"Yaw Max Deg", 0xBu);
    LOBYTE(v102) = 36;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 0x40u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v64, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  this->spYawMaxDeg = v65;
  v102 = 4;
  if ( (v93 & 0x40) != 0 )
  {
    v93 &= 0xFFFFFFBF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->spYawMaxDeg->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->spYawMaxDeg->font, &smallfont);
  this->spYawMaxDeg->fontAlign = eAlignCenter;
  v66 = this->spYawMaxDeg;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v66->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spYawMaxDeg->setSize)(
    this->spYawMaxDeg,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->spYawMaxDeg, 210.0, 180.0);
  for ( l = 0; l < 101; ++l )
  {
    std::to_wstring((std::wstring *)&h[8], l - 50);
    ksgui::Spinner::addItem(this->spYawMaxDeg, *(std::wstring *)&h[8]);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_c3b871161022629a3ea893f648b1ef9e_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spYawMaxDeg->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->spYawMaxDeg;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v68 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v68;
  LOBYTE(v102) = 39;
  if ( v68 )
  {
    std::wstring::wstring(&result, L"Pitch Max Deg");
    LOBYTE(v102) = 40;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 0x80u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v68, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  else
  {
    v69 = 0;
  }
  this->spPitchMaxDeg = v69;
  v102 = 4;
  if ( (v93 & 0x80u) != 0 )
  {
    v93 &= 0xFFFFFF7F;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->spPitchMaxDeg->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->spPitchMaxDeg->font, &smallfont);
  this->spPitchMaxDeg->fontAlign = eAlignCenter;
  v70 = this->spPitchMaxDeg;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v70->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spPitchMaxDeg->setSize)(
    this->spPitchMaxDeg,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->spPitchMaxDeg, 210.0, 230.0);
  for ( m = 0; m < 101; ++m )
  {
    std::to_wstring((std::wstring *)&h[8], m - 50);
    ksgui::Spinner::addItem(this->spPitchMaxDeg, *(std::wstring *)&h[8]);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_58a5d9153cd1f5a891a57050d4d01fec_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spPitchMaxDeg->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  _Val = (int)this->spPitchMaxDeg;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&h[28] = 444;
  *(_DWORD *)(_Val + 148) = this;
  v72 = (wchar_t *)operator new(*(unsigned int *)&h[28]);
  text._Bx._Ptr = v72;
  LOBYTE(v102) = 43;
  if ( v72 )
  {
    std::wstring::wstring(&result, L"Filter");
    LOBYTE(v102) = 44;
    *(_DWORD *)&h[28] = 0;
    *(_DWORD *)&h[24] = 1;
    *(_DWORD *)&h[20] = this->gui;
    v93 |= 0x100u;
    _Val = v93;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v72, &result, *(ksgui::GUI **)&h[20], 1, 0);
  }
  else
  {
    v73 = 0;
  }
  this->spFilter = v73;
  v102 = 4;
  if ( (v93 & 0x100) != 0 )
  {
    v93 &= 0xFFFFFEFF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  this->spFilter->fontScale = this->fontScale;
  std::shared_ptr<Font>::operator=(&this->spFilter->font, &smallfont);
  this->spFilter->fontAlign = eAlignCenter;
  v74 = this->spFilter;
  *(_DWORD *)&h[28] = 1101004800;
  *(_DWORD *)&h[24] = 1128792064;
  v74->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spFilter->setSize)(
    this->spFilter,
    *(_DWORD *)&h[24],
    *(_DWORD *)&h[28]);
  ksgui::Spinner::setPosition(this->spFilter, 210.0, 280.0);
  for ( n = 0; n < 300; ++n )
  {
    std::to_wstring((std::wstring *)&h[8], (float)n * 0.0099999998);
    ksgui::Spinner::addItem(this->spFilter, *(std::wstring *)&h[8]);
  }
  *(_DWORD *)&h[4] = &std::_Func_impl<std::_Callable_obj<_lambda_81144551637da43cbdd0a64c1fd66994_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&h[8] = this;
  *(_DWORD *)&h[20] = &h[4];
  LOBYTE(v102) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spFilter->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&h[4],
    this);
  ksgui::Control::addControl(this, this->spFilter);
  v76 = (wchar_t *)operator new(0x118u);
  text._Bx._Ptr = v76;
  LOBYTE(v102) = 47;
  if ( v76 )
  {
    std::wstring::wstring(&result, L"SaveIni");
    LOBYTE(v102) = 48;
    *(_DWORD *)&h[28] = this->gui;
    v93 |= 0x200u;
    _Val = v93;
    ksgui::Control::Control((ksgui::Control *)v76, &result, *(ksgui::GUI **)&h[28]);
  }
  else
  {
    v77 = 0;
  }
  v102 = 4;
  v78 = (v93 & 0x200) == 0;
  this->saveIni = v77;
  if ( !v78 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  v79 = this->saveIni;
  *(_DWORD *)&h[28] = L"Start";
  v79->fontScale = 0.69999999;
  std::wstring::wstring(&result, *(const wchar_t **)&h[28]);
  LOBYTE(v102) = 50;
  this->saveIni->setText(this->saveIni, &result);
  LOBYTE(v102) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  ((void (*)(ksgui::Control *, int, int))this->saveIni->setSize)(this->saveIni, 1128792064, 1101004800);
  ((void (*)(ksgui::Control *, int))this->saveIni->setRepeatInterval)(this->saveIni, 1028443341);
  ksgui::Form::setPosition((ksgui::Form *)this->saveIni, 5.0, 280.0);
  vec4f::vec4f((vec4f *)&text, 1.0, 0.0, 0.0, 1.0);
  this->saveIni->backColor = (vec4f)_mm_loadu_si128(v80);
  ksgui::Control::addControl(this, this->saveIni);
  std::wstring::wstring(&filename);
  LOBYTE(v102) = 51;
  v81 = this->avatar;
  v82 = std::wstring::empty(&v81->configName);
  *(_DWORD *)&h[28] = &v81->unixName;
  *(_DWORD *)&h[24] = L"content/cars/";
  if ( v82 )
  {
    v83 = std::operator+<wchar_t>(&text, *(const wchar_t **)&h[24], *(const std::wstring **)&h[28]);
    LOBYTE(v102) = 52;
    v84 = std::operator+<wchar_t>(&result, v83, L"/data/driver3d.ini");
    std::wstring::operator=(&filename, v84);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
  }
  else
  {
    v86 = std::operator+<wchar_t>(&v100.filename, *(const wchar_t **)&h[24], *(const std::wstring **)&h[28]);
    LOBYTE(v102) = 53;
    v87 = std::operator+<wchar_t>(&v101.name, v86, L"/data_");
    LOBYTE(v102) = 54;
    v88 = std::operator+<wchar_t>(&text, v87, &this->avatar->configName);
    LOBYTE(v102) = 55;
    v89 = std::operator+<wchar_t>(&result, v88, L"/driver3d.ini");
    std::wstring::operator=(&filename, v89);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    std::wstring::~wstring(&v101);
    v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v100;
  }
  LOBYTE(v102) = 51;
  std::wstring::~wstring(v85);
  if ( Path::fileExists((unsigned int)this, &filename, 1) )
  {
    *(_DWORD *)&h[28] = this->saveIni;
    lambda_d585b647a5665d78a2e60f3ee5d46edd_::_lambda_d585b647a5665d78a2e60f3ee5d46edd_(&v100, &filename, this);
    LOBYTE(v102) = 56;
    std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
      (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&h[4],
      v90);
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)&this->saveIni->evClicked,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&h[4],
      *(void **)&h[28]);
    LOBYTE(v102) = 51;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v100);
  }
  else
  {
    ksgui::Control::setVisible(this->saveIni, 0);
  }
  ksgui::Form::setSize(this, 415.0, 350.0);
  ksgui::Control::scaleByMult(this);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&smallfont);
}
void FormDriverModel::updateForces(FormDriverModel *this)
{
  ksgui::Spinner *v1; // eax
  __m128i v2; // xmm0
  ksgui::Spinner *v3; // eax
  __m128i v4; // xmm0
  ksgui::Spinner *v5; // eax
  float v6; // xmm1_4

  this->avatar->driverModel_HR->lockAnimation = 1;
  v1 = this->gDirectionY;
  this->accG.x = (float)(this->gDirectionX->value - 1);
  v2 = _mm_cvtsi32_si128(v1->value - 1);
  v3 = this->gDirectionZ;
  LODWORD(this->accG.y) = _mm_cvtepi32_ps(v2).m128_u32[0];
  v4 = _mm_cvtsi32_si128(v3->value - 1);
  v5 = this->gForce;
  LODWORD(this->accG.z) = _mm_cvtepi32_ps(v4).m128_u32[0];
  v6 = (float)v5->value * 0.1;
  this->accG.x = this->accG.x * v6;
  this->accG.y = this->accG.y * v6;
  this->accG.z = this->accG.z * v6;
}
