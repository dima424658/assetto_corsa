#include "setuppitstoppresets.h"
void SetupPitstopPresets::SetupPitstopPresets(SetupPitstopPresets *this, CarAvatar *aCar, QuickMenuPitstop *aPit)
{
  int v4; // ebx
  std::vector<ksgui::Control *> *v5; // esi
  ksgui::Spinner *v6; // edi
  ksgui::Spinner *v7; // eax
  const std::wstring *v8; // eax
  ksgui::Spinner *v9; // eax
  Font *v10; // eax
  Font *v11; // eax
  std::_Ref_count_base *v12; // edi
  Event<ksgui::OnSpinnerValueChanged> *v13; // ecx
  QuickMenuPitstop *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  ksgui::Control *v17; // edi
  std::wstring *v18; // eax
  int v19; // ebx
  const std::wstring *v20; // eax
  Sim *v21; // ecx
  ksgui::Control *v22; // eax
  ksgui::Control *v23; // edi
  std::wstring *v24; // eax
  ksgui::Control_vtbl *v25; // edx
  float v26; // xmm0_4
  Font *v27; // eax
  Font *v28; // eax
  ksgui::Control *v29; // edx
  volatile signed __int32 *v30; // edi
  Font *v31; // eax
  ksgui::Control **v32; // eax
  int v33; // edi
  ksgui::Control **v34; // ecx
  ksgui::Control *v35; // edi
  ksgui::Spinner *v36; // esi
  ksgui::Spinner *v37; // eax
  int v38; // ebx
  const std::wstring *v39; // eax
  ksgui::Spinner *v40; // eax
  Font *v41; // eax
  Font *v42; // eax
  ksgui::Control **v43; // eax
  ksgui::Spinner *v44; // ecx
  volatile signed __int32 *v45; // esi
  CarAvatar *v46; // esi
  std::wstring *v47; // edi
  const std::wstring *i; // esi
  Event<ksgui::OnSpinnerValueChanged> *v49; // ecx
  ksgui::Spinner *v50; // esi
  ksgui::Spinner *v51; // eax
  int v52; // ebx
  const std::wstring *v53; // eax
  ksgui::Spinner *v54; // eax
  Font *v55; // eax
  Font *v56; // eax
  std::_Ref_count_base *v57; // esi
  Event<ksgui::OnSpinnerValueChanged> *v58; // ecx
  const QuickMenuPitstopItem *v59; // eax
  ksgui::Spinner *v60; // esi
  ksgui::Spinner *v61; // eax
  int v62; // ebx
  const std::wstring *v63; // eax
  ksgui::Spinner *v64; // eax
  Font *v65; // eax
  Font *v66; // eax
  std::_Ref_count_base *v67; // esi
  Event<ksgui::OnSpinnerValueChanged> *v68; // ecx
  const QuickMenuPitstopItem *v69; // eax
  ksgui::Spinner *v70; // esi
  ksgui::Spinner *v71; // eax
  int v72; // ebx
  const std::wstring *v73; // eax
  ksgui::Spinner *v74; // eax
  Font *v75; // eax
  Font *v76; // eax
  std::_Ref_count_base *v77; // esi
  Event<ksgui::OnSpinnerValueChanged> *v78; // ecx
  const QuickMenuPitstopItem *v79; // eax
  ksgui::Spinner *v80; // esi
  ksgui::Spinner *v81; // eax
  int v82; // ebx
  const std::wstring *v83; // eax
  ksgui::Spinner *v84; // eax
  Font *v85; // eax
  Font *v86; // eax
  std::_Ref_count_base *v87; // esi
  Event<ksgui::OnSpinnerValueChanged> *v88; // ecx
  ksgui::Label *v89; // esi
  ksgui::Label *v90; // eax
  std::wstring *v91; // eax
  ksgui::Label *v92; // ecx
  _BYTE v93[64]; // [esp+2Ch] [ebp-180h] BYREF
  float v94; // [esp+7Ch] [ebp-130h]
  ksgui::Control *c; // [esp+80h] [ebp-12Ch]
  std::shared_ptr<Font> _Right; // [esp+84h] [ebp-128h] BYREF
  float v97; // [esp+8Ch] [ebp-120h]
  int _Val; // [esp+90h] [ebp-11Ch]
  ksgui::Control *v99; // [esp+94h] [ebp-118h]
  ksgui::Control *lbl; // [esp+98h] [ebp-114h] BYREF
  float v101; // [esp+9Ch] [ebp-110h]
  SetupPitstopPresets *v102; // [esp+A0h] [ebp-10Ch]
  std::wstring text; // [esp+A4h] [ebp-108h] BYREF
  std::wstring result; // [esp+BCh] [ebp-F0h] BYREF
  std::wstring v105; // [esp+D4h] [ebp-D8h] BYREF
  QuickMenuPitstopItem item; // [esp+ECh] [ebp-C0h] BYREF
  QuickMenuPitstopItem __that; // [esp+144h] [ebp-68h] BYREF
  int v108; // [esp+1A8h] [ebp-4h]

  v4 = 0;
  v102 = this;
  c = 0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"PITSTOP STRATEGY", 0x10u);
  *(_DWORD *)&v93[28] = aCar->sim;
  v108 = 0;
  *(_DWORD *)&v93[24] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v93[28] + 4) + 252);
  acTranslate((std::wstring *)v93, &text);
  SetupTab::SetupTab(this, *(std::wstring *)v93, *(ksgui::GUI **)&v93[24], *(Sim **)&v93[28]);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->car = aCar;
  v5 = &this->presets;
  this->__vftable = (SetupPitstopPresets_vtbl *)&SetupPitstopPresets::`vftable';
  this->force = 0;
  this->currentPreset = 0.0;
  v97 = 0.0;
  this->presets._Myfirst = 0;
  this->presets._Mylast = 0;
  this->presets._Myend = 0;
  LOBYTE(v108) = 3;
  ksgui::Control::setSize(this, 450.0, 400.0);
  *(_DWORD *)&v93[28] = 444;
  this->pit = aPit;
  v6 = (ksgui::Spinner *)operator new(*(_DWORD *)&v93[28]);
  v94 = *(float *)&v6;
  v7 = 0;
  LOBYTE(v108) = 4;
  if ( v6 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Add Liters", 0xAu);
    LOBYTE(v108) = 5;
    c = (ksgui::Control *)1;
    v8 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = 3;
    v108 = 6;
    c = (ksgui::Control *)3;
    ksgui::Spinner::Spinner(v6, v8, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->fuelSpinner = v7;
  if ( (v4 & 2) != 0 )
  {
    v4 &= 0xFFFFFFFD;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 3;
  if ( (v4 & 1) != 0 )
  {
    v4 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v9 = this->fuelSpinner;
  *(_DWORD *)&v93[28] = 1;
  v9->minValue = 0;
  this->fuelSpinner->maxValue = (int)this->car->physicsInfo.maxFuel;
  this->fuelSpinner->step = 1;
  ksgui::Spinner::setDrawArrows(this->fuelSpinner, v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->fuelSpinner->setSize)(
    this->fuelSpinner,
    1127743488,
    1101529088);
  ksgui::Spinner::setPosition(
    this->fuelSpinner,
    (float)((float)(this->rect.right - this->rect.left) * 0.5)
  - (float)((float)(this->fuelSpinner->rect.right - this->fuelSpinner->rect.left) * 0.5),
    120.0);
  v10 = (Font *)operator new(24);
  v94 = *(float *)&v10;
  LOBYTE(v108) = 9;
  if ( v10 )
    Font::Font(v10, eFontProportional, 12.0, 0, 0);
  else
    v11 = 0;
  LOBYTE(v108) = 3;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v11);
  std::shared_ptr<Font>::operator=(&this->fuelSpinner->font, &_Right);
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
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_dd21360307adb6d027fdbb916ff38fbd_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v13 = &this->fuelSpinner->evOnValueChanged;
  LOBYTE(v108) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v13,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->fuelSpinner);
  v14 = this->pit;
  v15 = this->rect.right - this->rect.left;
  _Val = 0;
  v16 = (float)v14->PRESETS_COUNT;
  v94 = v16;
  v101 = (float)(v15 - 40.0) / v16;
  if ( v16 > 0.0 )
  {
    _Right._Ptr = 0;
    _Right._Rep = 0;
    do
    {
      v17 = (ksgui::Control *)operator new(280);
      v99 = v17;
      LOBYTE(v108) = 11;
      if ( v17 )
      {
        v18 = std::to_wstring(&v105, _Val);
        LOBYTE(v108) = 12;
        v19 = v4 | 4;
        c = (ksgui::Control *)v19;
        v20 = std::operator+<wchar_t>(&result, L"PITSTOP_PRESETS_", v18);
        v21 = this->sim;
        v4 = v19 | 8;
        v108 = 13;
        c = (ksgui::Control *)v4;
        ksgui::Control::Control(v17, v20, v21->game->gui);
        v23 = v22;
        c = v22;
      }
      else
      {
        v23 = 0;
        c = 0;
      }
      lbl = v23;
      if ( (v4 & 8) != 0 )
      {
        v4 &= 0xFFFFFFF7;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
      }
      v108 = 3;
      if ( (v4 & 4) != 0 )
      {
        v4 &= 0xFFFFFFFB;
        if ( v105._Myres >= 8 )
          operator delete(v105._Bx._Ptr);
      }
      v99 = (ksgui::Control *)(_Val + 1);
      v24 = std::to_wstring(&v105, _Val + 1);
      v25 = v23->__vftable;
      LOBYTE(v108) = 16;
      v25->setText(v23, v24);
      LOBYTE(v108) = 3;
      if ( v105._Myres >= 8 )
        operator delete(v105._Bx._Ptr);
      ((void (*)(ksgui::Control *, float, int))v23->setSize)(v23, COERCE_FLOAT(LODWORD(v101)), 1101529088);
      v26 = v97 * v101;
      v23->fontAlign = eAlignCenter;
      ksgui::Form::setPosition((ksgui::Form *)v23, v26 + 20.0, 60.0);
      v23->backColor = (vec4f)_xmm;
      *(_DWORD *)&v93[28] = 24;
      v23->foreColor = (vec4f)_xmm;
      v27 = (Font *)operator new(*(_DWORD *)&v93[28]);
      v97 = *(float *)&v27;
      LOBYTE(v108) = 17;
      if ( v27 )
        Font::Font(v27, eFontProportional, 12.0, 0, 0);
      else
        v28 = 0;
      LOBYTE(v108) = 3;
      std::shared_ptr<Font>::_Resetp<Font>(&_Right, v28);
      v29 = c;
      v30 = (volatile signed __int32 *)v23->font._Rep;
      v31 = _Right._Ptr;
      c->font._Rep = _Right._Rep;
      _Right._Rep = 0;
      _Right._Ptr = 0;
      v29->font._Ptr = v31;
      if ( v30 )
      {
        if ( !_InterlockedExchangeAdd(v30 + 1, 0xFFFFFFFF) )
        {
          (**(void (***)(volatile signed __int32 *))v30)(v30);
          if ( !_InterlockedExchangeAdd(v30 + 2, 0xFFFFFFFF) )
            (*(void (**)(volatile signed __int32 *))(*v30 + 4))(v30);
        }
      }
      v32 = this->presets._Mylast;
      if ( &lbl >= v32 || v5->_Myfirst > &lbl )
      {
        if ( v32 == this->presets._Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->presets, 1u);
        v43 = this->presets._Mylast;
        if ( v43 )
        {
          v35 = c;
          *v43 = c;
          goto LABEL_47;
        }
      }
      else
      {
        v33 = &lbl - v5->_Myfirst;
        if ( v32 == this->presets._Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->presets, 1u);
        v34 = this->presets._Mylast;
        if ( v34 )
          *v34 = v5->_Myfirst[v33];
      }
      v35 = c;
LABEL_47:
      ++this->presets._Mylast;
      *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_7e845f6cddd5849a4436595890680bb7_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
      *(_DWORD *)&v93[12] = _Val;
      *(_DWORD *)&v93[8] = this;
      *(_DWORD *)&v93[20] = &v93[4];
      LOBYTE(v108) = 3;
      Event<ksgui::OnControlClicked>::addHandler(
        (Event<OnMouseWheelMovedEvent> *)&v35->evClicked,
        *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v93[4],
        this);
      ksgui::Control::addControl(this, v35);
      _Val = (int)v99;
      v97 = (float)(int)v99;
    }
    while ( v94 > (float)(int)v99 );
  }
  v36 = (ksgui::Spinner *)operator new(444);
  v94 = *(float *)&v36;
  v37 = 0;
  LOBYTE(v108) = 19;
  if ( v36 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Compound", 8u);
    LOBYTE(v108) = 20;
    v38 = v4 | 0x10;
    c = (ksgui::Control *)v38;
    v39 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = v38 | 0x20;
    v108 = 21;
    c = (ksgui::Control *)v4;
    ksgui::Spinner::Spinner(v36, v39, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->compoundSpinner = v37;
  if ( (v4 & 0x20) != 0 )
  {
    v4 &= 0xFFFFFFDF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 3;
  if ( (v4 & 0x10) != 0 )
  {
    v4 &= 0xFFFFFFEF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v40 = this->compoundSpinner;
  *(_DWORD *)&v93[28] = 1;
  v40->step = 1;
  ksgui::Spinner::setDrawArrows(this->compoundSpinner, v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->compoundSpinner->setSize)(
    this->compoundSpinner,
    1135542272,
    1101529088);
  ksgui::Spinner::setPosition(
    this->compoundSpinner,
    (float)((float)(this->rect.right - this->rect.left) * 0.5)
  - (float)((float)(this->compoundSpinner->rect.right - this->compoundSpinner->rect.left) * 0.5),
    180.0);
  v41 = (Font *)operator new(24);
  v94 = *(float *)&v41;
  LOBYTE(v108) = 24;
  if ( v41 )
    Font::Font(v41, eFontProportional, 12.0, 0, 0);
  else
    v42 = 0;
  LOBYTE(v108) = 3;
  _Right = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v42);
  v44 = this->compoundSpinner;
  v45 = (volatile signed __int32 *)v44->font._Rep;
  v44->font = _Right;
  if ( v45 )
  {
    if ( !_InterlockedExchangeAdd(v45 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v45)(v45);
      if ( !_InterlockedExchangeAdd(v45 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v45 + 4))(v45);
    }
  }
  *(_DWORD *)&v93[28] = 7;
  *(_DWORD *)&v93[24] = 0;
  *(_WORD *)&v93[8] = 0;
  std::wstring::assign((std::wstring *)&v93[8], L"NO CHANGE", 9u);
  ksgui::Spinner::addItem(this->compoundSpinner, *(std::wstring *)&v93[8]);
  v46 = this->car;
  v47 = v46->physicsInfo.tyreCompounds._Mylast;
  for ( i = v46->physicsInfo.tyreCompounds._Myfirst; i != v47; ++i )
  {
    *(_DWORD *)&v93[28] = 7;
    *(_DWORD *)&v93[24] = 0;
    *(_WORD *)&v93[8] = 0;
    std::wstring::assign((std::wstring *)&v93[8], i, 0, 0xFFFFFFFF);
    ksgui::Spinner::addItem(this->compoundSpinner, *(std::wstring *)&v93[8]);
  }
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_f6171b2e31fb2aa2de8938764ec9142e_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v49 = &this->compoundSpinner->evOnValueChanged;
  LOBYTE(v108) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v49,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->compoundSpinner);
  *(__m128i *)&item.type = _mm_load_si128((const __m128i *)&_xmm);
  item.function._Impl = 0;
  LOBYTE(v108) = 26;
  item.minValue = 0.0;
  item.maxValue = 1.0;
  item.setupName._Myres = 7;
  item.setupName._Mysize = 0;
  item.setupName._Bx._Buf[0] = 0;
  std::wstring::assign(&item.setupName, word_17BE9D8, 0);
  item.componentIndex = -1;
  item.isFixed = 0;
  item.pitstopTime = 0.0;
  item.header = 0;
  *(__m128i *)&__that.type = _mm_load_si128((const __m128i *)&_xmm);
  __that.function._Impl = 0;
  LOBYTE(v108) = 28;
  __that.minValue = 0.0;
  __that.maxValue = 1.0;
  __that.setupName._Myres = 7;
  __that.setupName._Mysize = 0;
  __that.setupName._Bx._Buf[0] = 0;
  std::wstring::assign(&__that.setupName, word_17BE9D8, 0);
  __that.componentIndex = -1;
  __that.isFixed = 0;
  __that.pitstopTime = 0.0;
  __that.header = 0;
  LOBYTE(v108) = 29;
  QuickMenuPitstopItem::operator=(&item, &__that);
  LOBYTE(v108) = 27;
  if ( __that.setupName._Myres >= 8 )
    operator delete(__that.setupName._Bx._Ptr);
  __that.setupName._Myres = 7;
  __that.setupName._Mysize = 0;
  __that.setupName._Bx._Buf[0] = 0;
  if ( __that.function._Impl )
    ((void (__stdcall *)(bool))__that.function._Impl->_Delete_this)(__that.function._Impl != (std::_Func_base<void,int,int> *)&__that.function);
  v50 = (ksgui::Spinner *)operator new(444);
  v94 = *(float *)&v50;
  v51 = 0;
  LOBYTE(v108) = 30;
  if ( v50 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Pressure LF", 0xBu);
    LOBYTE(v108) = 31;
    v52 = v4 | 0x40;
    c = (ksgui::Control *)v52;
    v53 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = v52 | 0x80;
    v108 = 32;
    c = (ksgui::Control *)v4;
    ksgui::Spinner::Spinner(v50, v53, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->pressureSpinner[0] = v51;
  if ( (v4 & 0x80u) != 0 )
  {
    v4 &= 0xFFFFFF7F;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 27;
  if ( (v4 & 0x40) != 0 )
  {
    v4 &= 0xFFFFFFBF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  QuickMenuPitstop::getItemValues(this->pit, TyrePressure, 0, &item);
  v54 = this->pressureSpinner[0];
  *(_DWORD *)&v93[28] = 1;
  v54->minValue = (int)item.minValue;
  this->pressureSpinner[0]->maxValue = (int)item.maxValue;
  this->pressureSpinner[0]->step = 1;
  ksgui::Spinner::setDrawArrows(this->pressureSpinner[0], v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->pressureSpinner[0]->setSize)(
    this->pressureSpinner[0],
    1127743488,
    1101529088);
  ksgui::Spinner::setPosition(this->pressureSpinner[0], 20.0, 240.0);
  v55 = (Font *)operator new(24);
  v94 = *(float *)&v55;
  LOBYTE(v108) = 35;
  if ( v55 )
    Font::Font(v55, eFontProportional, 12.0, 0, 0);
  else
    v56 = 0;
  LOBYTE(v108) = 27;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v56);
  std::shared_ptr<Font>::operator=(&this->pressureSpinner[0]->font, &_Right);
  v57 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v57->_Destroy(v57);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v57->_Weaks, 0xFFFFFFFF) )
        v57->_Delete_this(v57);
    }
  }
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_61559dcb57a987539418aedbffe68d9f_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v58 = &this->pressureSpinner[0]->evOnValueChanged;
  LOBYTE(v108) = 27;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v58,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->pressureSpinner[0]);
  QuickMenuPitstopItem::QuickMenuPitstopItem(&__that);
  LOBYTE(v108) = 37;
  QuickMenuPitstopItem::operator=(&item, v59);
  LOBYTE(v108) = 27;
  QuickMenuPitstopItem::~QuickMenuPitstopItem(&__that);
  v60 = (ksgui::Spinner *)operator new(444);
  v94 = *(float *)&v60;
  v61 = 0;
  LOBYTE(v108) = 38;
  if ( v60 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Pressure RF", 0xBu);
    LOBYTE(v108) = 39;
    v62 = v4 | 0x100;
    c = (ksgui::Control *)v62;
    v63 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = v62 | 0x200;
    v108 = 40;
    c = (ksgui::Control *)v4;
    ksgui::Spinner::Spinner(v60, v63, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->pressureSpinner[1] = v61;
  if ( (v4 & 0x200) != 0 )
  {
    v4 &= 0xFFFFFDFF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 27;
  if ( (v4 & 0x100) != 0 )
  {
    v4 &= 0xFFFFFEFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  QuickMenuPitstop::getItemValues(this->pit, TyrePressure, 1, &item);
  v64 = this->pressureSpinner[1];
  *(_DWORD *)&v93[28] = 1;
  v64->minValue = (int)item.minValue;
  this->pressureSpinner[1]->maxValue = (int)item.maxValue;
  this->pressureSpinner[1]->step = 1;
  ksgui::Spinner::setDrawArrows(this->pressureSpinner[1], v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->pressureSpinner[1]->setSize)(
    this->pressureSpinner[1],
    1127743488,
    1101529088);
  ksgui::Spinner::setPosition(
    this->pressureSpinner[1],
    (float)((float)(this->rect.right - this->rect.left) - 20.0)
  - (float)(this->pressureSpinner[1]->rect.right - this->pressureSpinner[1]->rect.left),
    240.0);
  v65 = (Font *)operator new(24);
  v94 = *(float *)&v65;
  LOBYTE(v108) = 43;
  if ( v65 )
    Font::Font(v65, eFontProportional, 12.0, 0, 0);
  else
    v66 = 0;
  LOBYTE(v108) = 27;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v66);
  std::shared_ptr<Font>::operator=(&this->pressureSpinner[1]->font, &_Right);
  v67 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v67->_Destroy(v67);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v67->_Weaks, 0xFFFFFFFF) )
        v67->_Delete_this(v67);
    }
  }
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_1ac7f74e0155320955b56e2fd8eda8ef_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v68 = &this->pressureSpinner[1]->evOnValueChanged;
  LOBYTE(v108) = 27;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v68,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->pressureSpinner[1]);
  QuickMenuPitstopItem::QuickMenuPitstopItem(&__that);
  LOBYTE(v108) = 45;
  QuickMenuPitstopItem::operator=(&item, v69);
  LOBYTE(v108) = 27;
  QuickMenuPitstopItem::~QuickMenuPitstopItem(&__that);
  v70 = (ksgui::Spinner *)operator new(444);
  v94 = *(float *)&v70;
  v71 = 0;
  LOBYTE(v108) = 46;
  if ( v70 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Pressure LR", 0xBu);
    LOBYTE(v108) = 47;
    v72 = v4 | 0x400;
    c = (ksgui::Control *)v72;
    v73 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = v72 | 0x800;
    v108 = 48;
    c = (ksgui::Control *)v4;
    ksgui::Spinner::Spinner(v70, v73, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->pressureSpinner[2] = v71;
  if ( (v4 & 0x800) != 0 )
  {
    v4 &= 0xFFFFF7FF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 27;
  if ( (v4 & 0x400) != 0 )
  {
    v4 &= 0xFFFFFBFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  QuickMenuPitstop::getItemValues(this->pit, TyrePressure, 2, &item);
  v74 = this->pressureSpinner[2];
  *(_DWORD *)&v93[28] = 1;
  v74->minValue = (int)item.minValue;
  this->pressureSpinner[2]->maxValue = (int)item.maxValue;
  this->pressureSpinner[2]->step = 1;
  ksgui::Spinner::setDrawArrows(this->pressureSpinner[2], v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->pressureSpinner[2]->setSize)(
    this->pressureSpinner[2],
    1127743488,
    1101529088);
  ksgui::Spinner::setPosition(this->pressureSpinner[2], 20.0, 300.0);
  v75 = (Font *)operator new(24);
  v94 = *(float *)&v75;
  LOBYTE(v108) = 51;
  if ( v75 )
    Font::Font(v75, eFontProportional, 12.0, 0, 0);
  else
    v76 = 0;
  LOBYTE(v108) = 27;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v76);
  std::shared_ptr<Font>::operator=(&this->pressureSpinner[2]->font, &_Right);
  v77 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v77->_Destroy(v77);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v77->_Weaks, 0xFFFFFFFF) )
        v77->_Delete_this(v77);
    }
  }
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_a1d433f8ba72e84bfdb87fa8d2c7942c_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v78 = &this->pressureSpinner[2]->evOnValueChanged;
  LOBYTE(v108) = 27;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v78,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->pressureSpinner[2]);
  QuickMenuPitstopItem::QuickMenuPitstopItem(&__that);
  LOBYTE(v108) = 53;
  QuickMenuPitstopItem::operator=(&item, v79);
  LOBYTE(v108) = 27;
  QuickMenuPitstopItem::~QuickMenuPitstopItem(&__that);
  v80 = (ksgui::Spinner *)operator new(444);
  v94 = *(float *)&v80;
  v81 = 0;
  LOBYTE(v108) = 54;
  if ( v80 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Pressure RR", 0xBu);
    LOBYTE(v108) = 55;
    v82 = v4 | 0x1000;
    c = (ksgui::Control *)v82;
    v83 = acTranslate(&result, &text);
    *(_DWORD *)&v93[28] = 0;
    *(_DWORD *)&v93[24] = 1;
    *(_DWORD *)&v93[20] = this->gui;
    v4 = v82 | 0x2000;
    v108 = 56;
    c = (ksgui::Control *)v4;
    ksgui::Spinner::Spinner(v80, v83, *(ksgui::GUI **)&v93[20], 1, 0);
  }
  this->pressureSpinner[3] = v81;
  if ( (v4 & 0x2000) != 0 )
  {
    LOWORD(v4) = v4 & 0xDFFF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v108 = 27;
  if ( (v4 & 0x1000) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  QuickMenuPitstop::getItemValues(this->pit, TyrePressure, 3, &item);
  v84 = this->pressureSpinner[3];
  *(_DWORD *)&v93[28] = 1;
  v84->minValue = (int)item.minValue;
  this->pressureSpinner[3]->maxValue = (int)item.maxValue;
  this->pressureSpinner[3]->step = 1;
  ksgui::Spinner::setDrawArrows(this->pressureSpinner[3], v93[28]);
  ((void (*)(ksgui::Spinner *, int, int))this->pressureSpinner[3]->setSize)(
    this->pressureSpinner[3],
    1127743488,
    1101529088);
  ksgui::Spinner::setPosition(
    this->pressureSpinner[3],
    (float)((float)(this->rect.right - this->rect.left) - 20.0)
  - (float)(this->pressureSpinner[3]->rect.right - this->pressureSpinner[3]->rect.left),
    300.0);
  v85 = (Font *)operator new(24);
  v94 = *(float *)&v85;
  LOBYTE(v108) = 59;
  if ( v85 )
    Font::Font(v85, eFontProportional, 12.0, 0, 0);
  else
    v86 = 0;
  LOBYTE(v108) = 27;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v86);
  std::shared_ptr<Font>::operator=(&this->pressureSpinner[3]->font, &_Right);
  v87 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v87->_Destroy(v87);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v87->_Weaks) )
        v87->_Delete_this(v87);
    }
  }
  *(_DWORD *)&v93[28] = this;
  *(_DWORD *)&v93[4] = &std::_Func_impl<std::_Callable_obj<_lambda_f726f1d6e9367dcc20b39a7fa8856fc1_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v93[8] = this;
  *(_DWORD *)&v93[20] = &v93[4];
  v88 = &this->pressureSpinner[3]->evOnValueChanged;
  LOBYTE(v108) = 27;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v88,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v93[4],
    this);
  ksgui::Control::addControl(this, this->pressureSpinner[3]);
  v89 = (ksgui::Label *)operator new(284);
  v94 = *(float *)&v89;
  LOBYTE(v108) = 61;
  if ( v89 )
  {
    *(_DWORD *)&v93[28] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)&v93[4], L"PRESSURE_ALERT");
    ksgui::Label::Label(v89, *(std::wstring *)&v93[4], *(ksgui::GUI **)&v93[28]);
  }
  else
  {
    v90 = 0;
  }
  this->pressureAlert = v90;
  LOBYTE(v108) = 27;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"Effective pressure adjustment will be limited to a range of 8psi", 0x40u);
  LOBYTE(v108) = 62;
  v91 = acTranslate(&v105, &result);
  v92 = this->pressureAlert;
  LOBYTE(v108) = 63;
  v92->setText(v92, v91);
  if ( v105._Myres >= 8 )
    operator delete(v105._Bx._Ptr);
  v105._Myres = 7;
  v105._Mysize = 0;
  v105._Bx._Buf[0] = 0;
  LOBYTE(v108) = 27;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->pressureAlert->fontAlign = eAlignCenter;
  ksgui::Form::setPosition((ksgui::Form *)this->pressureAlert, (float)(this->rect.right - this->rect.left) * 0.5, 340.0);
  ksgui::Control::addControl(this, this->pressureAlert);
  SetupPitstopPresets::syncSpinners(this);
  QuickMenuPitstopItem::~QuickMenuPitstopItem(&item);
}
SetupPitstopPresets *SetupPitstopPresets::`scalar deleting destructor'(SetupPitstopPresets *this, unsigned int a2)
{
  std::vector<ksgui::Control *> *v3; // edi

  this->__vftable = (SetupPitstopPresets_vtbl *)&SetupPitstopPresets::`vftable';
  v3 = &this->presets;
  if ( this->presets._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->presets);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  SetupTab::~SetupTab(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SetupPitstopPresets::loadFixed(SetupPitstopPresets *this, const std::wstring *path)
{
  QuickMenuPitstop::loadFixedSetup(this->pit, path);
}
void SetupPitstopPresets::loadPresets(SetupPitstopPresets *this, INIReader *ini)
{
  int v3; // edi
  INIReader *v4; // esi
  int v5; // ebx
  std::wstring *v6; // eax
  std::vector<QuickMenuPitstopItem> *v7; // esi
  unsigned int v8; // ebx
  int v9; // edi
  QuickMenuPitstopItem *v10; // esi
  double v11; // st7
  float v12; // xmm0_4
  int v13; // [esp+18h] [ebp-4Ch]
  int v14; // [esp+1Ch] [ebp-48h]
  float v15; // [esp+20h] [ebp-44h]
  std::wstring result; // [esp+24h] [ebp-40h] BYREF
  std::wstring sect; // [esp+3Ch] [ebp-28h] BYREF
  int v18; // [esp+60h] [ebp-4h]

  v3 = 0;
  v4 = ini;
  v14 = 0;
  if ( (float)this->pit->PRESETS_COUNT > 0.0 )
  {
    v5 = 0;
    v13 = 0;
    do
    {
      v6 = std::to_wstring(&result, v3);
      v18 = 0;
      std::operator+<wchar_t>(&sect, L"PRESET_", v6);
      LOBYTE(v18) = 2;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( INIReader::hasSection(v4, &sect) )
      {
        v7 = &this->pit->items;
        v8 = 0;
        if ( this->pit->items._Mylast - v7->_Myfirst )
        {
          v9 = 0;
          do
          {
            if ( INIReader::hasKey(ini, &sect, &v7->_Myfirst[v9].setupName) )
            {
              v10 = this->pit->items._Myfirst;
              v11 = INIReader::getFloat(ini, &sect, &v10[v9].setupName);
              v12 = v10[v9].maxValue;
              v15 = v11;
              if ( v15 <= v12 )
              {
                if ( v10[v9].minValue <= v15 )
                  v12 = v11;
                else
                  v12 = v10[v9].minValue;
              }
              (*(float **)((char *)&this->pit->pitstopPresets._Myfirst->_Myfirst + v13))[v8] = v12;
            }
            v7 = &this->pit->items;
            ++v8;
            ++v9;
          }
          while ( v8 < this->pit->items._Mylast - v7->_Myfirst );
          v3 = v14;
        }
        v4 = ini;
        v5 = v13;
      }
      v18 = -1;
      if ( sect._Myres >= 8 )
        operator delete(sect._Bx._Ptr);
      ++v3;
      v5 += 12;
      v14 = v3;
      v13 = v5;
    }
    while ( (float)this->pit->PRESETS_COUNT > (float)v3 );
  }
  SetupPitstopPresets::syncSpinners(this);
}
void SetupPitstopPresets::onVisibleChanged(SetupPitstopPresets *this, bool value)
{
  SetupPitstopPresets::syncSpinners(this);
}
void __userpurge SetupPitstopPresets::render(SetupPitstopPresets *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  int i; // edx

  for ( i = 0; i < (unsigned int)(this->presets._Mylast - this->presets._Myfirst); ++i )
  {
    this->presets._Myfirst[i]->backColor = (vec4f)_xmm;
    this->presets._Myfirst[i]->foreColor = (vec4f)_xmm;
    if ( (float)i == this->currentPreset )
    {
      this->presets._Myfirst[i]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_12);
      this->presets._Myfirst[i]->foreColor = (vec4f)_xmm;
    }
  }
  SetupTab::render(this, a2, dt);
}
void SetupPitstopPresets::savePresets(SetupPitstopPresets *this, std::wofstream *file)
{
  int v3; // ecx
  int v4; // edi
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  QuickMenuPitstop *v8; // esi
  unsigned int v9; // ebx
  int v10; // edi
  QuickMenuPitstopItem *v11; // ecx
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  int v14; // eax
  int v15; // [esp+4h] [ebp-24h]
  const char *v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+20h] [ebp-8h]
  int v18; // [esp+24h] [ebp-4h]

  v3 = 0;
  v18 = 0;
  if ( (float)this->pit->PRESETS_COUNT > 0.0 )
  {
    v4 = 0;
    v17 = 0;
    do
    {
      v15 = v3;
      v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(file, L"[PRESET_");
      v6 = (std::wostream *)std::wostream::operator<<(v5, v15);
      v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, v16);
      std::wostream::operator<<(v7);
      v8 = this->pit;
      v9 = 0;
      if ( v8->items._Mylast - v8->items._Myfirst )
      {
        v10 = 0;
        do
        {
          v11 = v8->items._Myfirst;
          if ( v11[v10].type != Repair )
          {
            v12 = std::operator<<<wchar_t>(file, &v11[v10].setupName);
            v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v12, L"=");
            v14 = std::wostream::operator<<(v13);
            std::wostream::operator<<(v14);
          }
          v8 = this->pit;
          ++v9;
          ++v10;
        }
        while ( v9 < v8->items._Mylast - v8->items._Myfirst );
        v4 = v17;
      }
      v4 += 12;
      v3 = v18 + 1;
      v18 = v3;
      v17 = v4;
    }
    while ( (float)this->pit->PRESETS_COUNT > (float)v3 );
  }
}
void SetupPitstopPresets::syncCarPitstop(SetupPitstopPresets *this)
{
  QuickMenuPitstop *v2; // edi
  QuickMenuPitstopItem *v3; // esi
  QuickMenuPitstopItem *v4; // edi
  float *v5; // ebx
  ksgui::Spinner *v6; // ecx
  float *v7; // ebx
  int v8; // eax
  int v9; // [esp+8h] [ebp-4h]

  v2 = this->pit;
  if ( v2 )
  {
    if ( this->force )
    {
      v3 = v2->items._Myfirst;
      v4 = v2->items._Mylast;
      if ( v3 != v4 )
      {
        v9 = 0;
        while ( v3->type )
        {
          if ( v3->type == TyreCompound )
          {
            v7 = &this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[v9];
            v8 = ksgui::Spinner::getValue(this->compoundSpinner) - 1;
            goto LABEL_12;
          }
          if ( v3->type == TyrePressure )
          {
            v5 = this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst;
            v6 = this->pressureSpinner[v3->componentIndex];
            goto LABEL_11;
          }
LABEL_13:
          ++v9;
          if ( ++v3 == v4 )
            return;
        }
        v5 = this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst;
        v6 = this->fuelSpinner;
LABEL_11:
        v7 = &v5[v9];
        v8 = ksgui::Spinner::getValue(v6);
LABEL_12:
        *v7 = (float)v8;
        goto LABEL_13;
      }
    }
  }
}
void SetupPitstopPresets::syncSpinners(SetupPitstopPresets *this)
{
  QuickMenuPitstop *v2; // edi
  QuickMenuPitstopItem *v3; // esi
  QuickMenuPitstopItem *v4; // edi
  int i; // ebp
  float *v6; // eax
  ksgui::Spinner *v7; // ecx
  int v8; // eax

  v2 = this->pit;
  this->force = 0;
  if ( v2 )
  {
    v3 = v2->items._Myfirst;
    v4 = v2->items._Mylast;
    if ( v3 != v4 )
    {
      for ( i = 0; ; ++i )
      {
        if ( v3->type == Fuel )
        {
          v6 = this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst;
          v7 = this->fuelSpinner;
          goto LABEL_12;
        }
        if ( v3->type == TyreCompound )
          break;
        if ( v3->type == TyrePressure )
        {
          if ( v3->isFixed )
            this->pressureSpinner[v3->componentIndex]->isReadOnly = 1;
          v6 = this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst;
          v7 = this->pressureSpinner[v3->componentIndex];
LABEL_12:
          v8 = (int)v6[i];
LABEL_13:
          ksgui::Spinner::setValue(v7, v8);
        }
        if ( ++v3 == v4 )
        {
          this->force = 1;
          return;
        }
      }
      v7 = this->compoundSpinner;
      v8 = (int)this->pit->pitstopPresets._Myfirst[this->currentPreset]._Myfirst[i] + 1;
      goto LABEL_13;
    }
    this->force = 1;
  }
  else
  {
    this->force = 1;
  }
}
