#include "formopenvr.h"
void __userpurge FormOpenVR::FormOpenVR(FormOpenVR *this@<ecx>, double a2@<st0>, Sim *aSim)
{
  Game *v4; // eax
  ksgui::Control *v5; // eax
  Font *v6; // eax
  ksgui::Control *v7; // eax
  Font *v8; // eax
  ksgui::Spinner *v9; // edi
  ksgui::Spinner *v10; // eax
  int i; // ebp
  unsigned int v12; // ecx
  ksgui::Spinner *v13; // edi
  int v14; // ecx
  ksgui::Spinner *v15; // ecx
  std::vector<ksgui::CustomSpinner *> *v16; // ebp
  ksgui::Control **v17; // eax
  int v18; // edi
  ksgui::Control **v19; // edx
  ksgui::Control **v20; // eax
  Sim *v21; // ecx
  CameraForward *v22; // eax
  StereoCameraVive *v23; // eax
  float v24; // xmm0_4
  unsigned int v25; // ecx
  ksgui::Spinner *v26; // edi
  ksgui::Spinner *v27; // eax
  int v28; // esi
  double v29; // st7
  int v30; // ecx
  int v31; // ebp
  ksgui::Spinner *v32; // edi
  int v33; // ecx
  ksgui::CustomSpinner **v34; // ecx
  ksgui::CustomSpinner **v35; // edx
  int v36; // eax
  int v37; // ecx
  unsigned int v38; // edx
  unsigned int v39; // edx
  ksgui::CustomSpinner **v40; // ecx
  int v41; // ecx
  ksgui::Control *v42; // eax
  ksgui::CustomSpinner **v43; // edx
  int v44; // ecx
  unsigned int v45; // edx
  unsigned int v46; // edx
  ksgui::CustomSpinner **v47; // eax
  const std::wstring *v48; // eax
  char *v49; // eax
  ksgui::Control *v50; // ecx
  __int64 v51; // xmm0_8
  ksgui::Control *v52; // eax
  std::_Ref_count_base *v53; // esi
  ksgui::Control *v54; // ecx
  wchar_t *v55; // edx
  Font *v56; // eax
  ksgui::Control *v57; // ecx
  ksgui::Control *v58; // ecx
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  char *v64; // eax
  __m128i v65; // xmm0
  ksgui::Control *v66; // ecx
  ksgui::CustomSpinner **v67; // ecx
  ksgui::CustomSpinner **v68; // edx
  int v69; // eax
  int v70; // ecx
  unsigned int v71; // ecx
  unsigned int v72; // edx
  unsigned int v73; // edx
  ksgui::CustomSpinner **v74; // ecx
  ksgui::Control *v75; // ecx
  ksgui::Label *v76; // edi
  ksgui::Label *v77; // eax
  ksgui::Label *v78; // eax
  const std::wstring *v79; // eax
  ksgui::Label *v80; // ecx
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm2_4
  ksgui::Label *v86; // ecx
  ksgui::Label_vtbl *v87; // eax
  std::_Ref_count_base *v88; // edi
  ksgui::CustomSpinner **v89; // edx
  int v90; // ecx
  unsigned int v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // edx
  _DWORD *v94; // eax
  _BYTE v95[28]; // [esp+1Ch] [ebp-D8h] BYREF
  float y; // [esp+38h] [ebp-BCh]
  ksgui::Control *v97; // [esp+54h] [ebp-A0h]
  int _Val; // [esp+58h] [ebp-9Ch] BYREF
  ksgui::Control *v99; // [esp+5Ch] [ebp-98h]
  int v100; // [esp+60h] [ebp-94h]
  int v101; // [esp+64h] [ebp-90h]
  unsigned int _Count; // [esp+68h] [ebp-8Ch]
  StereoCameraVive *v103; // [esp+6Ch] [ebp-88h]
  __int128 v104; // [esp+70h] [ebp-84h] BYREF
  std::shared_ptr<Font> small_font; // [esp+80h] [ebp-74h] BYREF
  std::shared_ptr<Font> font; // [esp+88h] [ebp-6Ch] BYREF
  FormOpenVR *v107; // [esp+90h] [ebp-64h]
  std::wstring iname; // [esp+94h] [ebp-60h] BYREF
  std::wstring result; // [esp+ACh] [ebp-48h] BYREF
  wchar_t str[16]; // [esp+C4h] [ebp-30h] BYREF
  int v111; // [esp+F0h] [ebp-4h]

  v101 = 0;
  y = 0.0;
  v100 = 0;
  v4 = aSim->game;
  v107 = this;
  *(_DWORD *)&v95[24] = v4->gui;
  *(_DWORD *)&v95[20] = 7;
  *(_DWORD *)&v95[16] = 0;
  *(_WORD *)v95 = 0;
  std::wstring::assign((std::wstring *)v95, L"FORM_OPENVR", 0xBu);
  ksgui::Form::Form(this, (unsigned int)this, *(std::wstring *)v95, *(ksgui::GUI **)&v95[24], SLOBYTE(y));
  v111 = 0;
  LODWORD(y) = 24;
  this->__vftable = (FormOpenVR_vtbl *)&FormOpenVR::`vftable';
  this->superSampling = 0;
  this->eyesDistanceSpinner = 0;
  this->saveButton = 0;
  this->devApp = 0;
  this->sim = aSim;
  this->loaded = 0;
  v5 = (ksgui::Control *)operator new(LODWORD(y));
  v97 = v5;
  LOBYTE(v111) = 1;
  if ( v5 )
    Font::Font((Font *)v5, eFontMonospaced, 18.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v111) = 0;
  font._Ptr = 0;
  font._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&font, v6);
  LOBYTE(v111) = 2;
  v7 = (ksgui::Control *)operator new(0x18u);
  v97 = v7;
  LOBYTE(v111) = 3;
  if ( v7 )
    Font::Font((Font *)v7, eFontMonospaced, 15.0, 0, 0);
  else
    v8 = 0;
  LOBYTE(v111) = 2;
  small_font._Ptr = 0;
  small_font._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&small_font, v8);
  LOBYTE(v111) = 4;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"OpenVR", 6u);
  LOBYTE(v111) = 5;
  this->formTitle->setText(this->formTitle, &iname);
  LOBYTE(v111) = 4;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v9 = (ksgui::Spinner *)operator new(0x1BCu);
  v97 = v9;
  v10 = 0;
  LOBYTE(v111) = 6;
  if ( v9 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"SUPERSAMPLING *", 0xFu);
    LOBYTE(v111) = 7;
    y = 0.0;
    *(_DWORD *)&v95[24] = 1;
    *(_DWORD *)&v95[20] = this->gui;
    v100 = 1;
    v101 = 1;
    ksgui::Spinner::Spinner(v9, &iname, *(ksgui::GUI **)&v95[20], 1, 0);
  }
  this->superSampling = v10;
  v111 = 4;
  if ( (v100 & 1) != 0 )
  {
    v100 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->superSampling->setSize)(
    this->superSampling,
    1134231552,
    1102577664);
  ksgui::Spinner::setPosition(this->superSampling, 30.0, 70.0);
  for ( i = 8; i <= 24; ++i )
  {
    _swprintf_s(str, 0x10u, L"%.2f", (float)((float)i * 0.1));
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( str[0] )
      v12 = wcslen(str);
    else
      v12 = 0;
    std::wstring::assign(&iname, str, v12);
    v13 = this->superSampling;
    LOBYTE(v111) = 9;
    std::vector<std::wstring>::push_back(&v13->items, &iname);
    v13->minValue = 0;
    v14 = (char *)v13->items._Mylast - (char *)v13->items._Myfirst;
    LOBYTE(v111) = 4;
    v13->maxValue = ((int)((unsigned __int64)(715827883i64 * v14) >> 32) >> 2)
                  + ((unsigned int)((unsigned __int64)(715827883i64 * v14) >> 32) >> 31)
                  - 1;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v15 = this->superSampling;
  v16 = (std::vector<ksgui::CustomSpinner *> *)&this->controls;
  v17 = this->controls._Mylast;
  v99 = v15;
  DWORD1(v104) = v15;
  if ( (char *)&v104 + 4 >= (char *)v17 || v16->_Myfirst > (ksgui::CustomSpinner **)&v104 + 1 )
  {
    if ( v17 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v15 = (ksgui::Spinner *)v99;
    }
    v20 = this->controls._Mylast;
    if ( v20 )
      *v20 = v15;
  }
  else
  {
    v18 = ((char *)&v104 + 4 - (char *)v16->_Myfirst) >> 2;
    if ( v17 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v15 = (ksgui::Spinner *)v99;
    }
    v19 = this->controls._Mylast;
    if ( v19 )
      *v19 = v16->_Myfirst[v18];
  }
  ++this->controls._Mylast;
  y = 0.0;
  *(_DWORD *)&v95[24] = &StereoCameraVive `RTTI Type Descriptor';
  *(_DWORD *)&v95[20] = &Camera `RTTI Type Descriptor';
  v15->parent = this;
  v21 = this->sim;
  *(_DWORD *)&v95[16] = 0;
  v22 = Sim::getSceneCamera(v21);
  v23 = (StereoCameraVive *)__RTDynamicCast(
                              v22,
                              *(_DWORD *)&v95[16],
                              *(_DWORD *)&v95[20],
                              *(_DWORD *)&v95[24],
                              LODWORD(y));
  v103 = v23;
  if ( v23 )
  {
    StereoCameraVive::getRenderMultiplier(v23);
    v24 = FLOAT_2_4000001;
    *(float *)&_Val = a2;
    if ( *(float *)&_Val <= 2.4000001 )
    {
      v24 = FLOAT_0_80000001;
      if ( *(float *)&_Val >= 0.80000001 )
        v24 = *(float *)&_Val;
    }
    _swprintf_s(str, 0x10u, L"%.2f", v24);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( str[0] )
      v25 = wcslen(str);
    else
      v25 = 0;
    std::wstring::assign(&iname, str, v25);
    LOBYTE(v111) = 10;
    ksgui::Spinner::setValue(this->superSampling, &iname);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  *(_DWORD *)&v95[4] = &std::_Func_impl<std::_Callable_obj<_lambda_383499965d89d985d924898137421ec9_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v95[8] = this;
  *(_DWORD *)&v95[20] = &v95[4];
  LOBYTE(v111) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->superSampling->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v95[4],
    this);
  v26 = (ksgui::Spinner *)operator new(0x1BCu);
  v97 = v26;
  v27 = 0;
  LOBYTE(v111) = 12;
  if ( v26 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"PUPILLARY DISTANCE(mm)", 0x16u);
    LOBYTE(v111) = 13;
    y = 0.0;
    *(_DWORD *)&v95[24] = 1;
    *(_DWORD *)&v95[20] = this->gui;
    v100 |= 2u;
    v101 = v100;
    ksgui::Spinner::Spinner(v26, &iname, *(ksgui::GUI **)&v95[20], 1, 0);
  }
  this->eyesDistanceSpinner = v27;
  v111 = 4;
  if ( (v100 & 2) != 0 )
  {
    v100 &= 0xFFFFFFFD;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->eyesDistanceSpinner->setSize)(
    this->eyesDistanceSpinner,
    1134231552,
    1102577664);
  ksgui::Spinner::setPosition(this->eyesDistanceSpinner, 30.0, 140.0);
  v28 = (int)(float)(v103->maxDistanceOffset * 1000.0);
  v99 = (ksgui::Control *)v28;
  v29 = StereoCameraVive::getEyesDistanceRef(v103);
  v97 = (ksgui::Control *)-v28;
  _Val = -v28;
  *(float *)&v104 = v29 * 1000.0;
  v30 = (int)*(float *)&v104;
  if ( -v28 <= v28 )
  {
    v31 = -v28;
    do
    {
      std::to_wstring(&result, v30 + v31);
      v32 = this->eyesDistanceSpinner;
      LOBYTE(v111) = 15;
      std::vector<std::wstring>::push_back(&v32->items, &result);
      v32->minValue = 0;
      v33 = (char *)v32->items._Mylast - (char *)v32->items._Myfirst;
      LOBYTE(v111) = 4;
      v32->maxValue = ((int)((unsigned __int64)(715827883i64 * v33) >> 32) >> 2)
                    + ((unsigned int)((unsigned __int64)(715827883i64 * v33) >> 32) >> 31)
                    - 1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v28 = (int)v99;
      ++v31;
      v30 = (int)*(float *)&v104;
    }
    while ( v31 <= (int)v99 );
    v16 = (std::vector<ksgui::CustomSpinner *> *)&this->controls;
  }
  v34 = v16->_Mylast;
  v101 = (int)this->eyesDistanceSpinner;
  HIDWORD(v104) = v101;
  if ( (char *)&v104 + 12 < (char *)v34 && v16->_Myfirst <= (ksgui::CustomSpinner **)&v104 + 3 )
  {
    v35 = v16->_Myend;
    v36 = ((char *)&v104 + 12 - (char *)v16->_Myfirst) >> 2;
    _Val = v36;
    if ( v34 == v35 )
    {
      if ( !(v35 - v34) )
      {
        v37 = v34 - v16->_Myfirst;
        if ( v37 == 0x3FFFFFFF )
          std::_Xlength_error("vector<T> too long");
        v38 = v35 - v16->_Myfirst;
        _Count = v37 + 1;
        if ( 0x3FFFFFFF - (v38 >> 1) >= v38 )
          v39 = (v38 >> 1) + v38;
        else
          v39 = 0;
        if ( v39 < _Count )
          v39 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate(v16, v39);
      }
      v36 = _Val;
    }
    v40 = v16->_Mylast;
    if ( v40 )
      *v40 = v16->_Myfirst[v36];
LABEL_66:
    v41 = v101;
    goto LABEL_67;
  }
  v43 = v16->_Myend;
  if ( v34 == v43 && !(v43 - v34) )
  {
    v44 = v34 - v16->_Myfirst;
    if ( v44 == 0x3FFFFFFF )
      std::_Xlength_error("vector<T> too long");
    v45 = v43 - v16->_Myfirst;
    _Count = v44 + 1;
    if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
      v46 = (v45 >> 1) + v45;
    else
      v46 = 0;
    if ( v46 < _Count )
      v46 = _Count;
    std::vector<ksgui::CustomSpinner *>::_Reallocate(v16, v46);
  }
  v47 = v16->_Mylast;
  if ( !v47 )
    goto LABEL_66;
  v41 = v101;
  *v47 = (ksgui::CustomSpinner *)v101;
LABEL_67:
  ++v16->_Mylast;
  *(_DWORD *)(v41 + 148) = this;
  *(float *)&_Count = StereoCameraVive::getEyesDistance(v103) * 1000.0;
  v42 = (ksgui::Control *)((int)*(float *)&_Count - (int)*(float *)&v104);
  if ( (int)v42 <= v28 )
  {
    if ( (int)v42 < (int)v97 )
      v42 = v97;
  }
  else
  {
    v42 = (ksgui::Control *)v28;
  }
  v48 = std::to_wstring(&result, (int)v42 + (int)*(float *)&v104);
  LOBYTE(v111) = 16;
  ksgui::Spinner::setValue(this->eyesDistanceSpinner, v48);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LODWORD(y) = this;
  *(_QWORD *)iname._Bx._Buf = __PAIR64__((unsigned int)v99, (unsigned int)v103);
  v97 = (ksgui::Control *)&v95[4];
  *(_DWORD *)&v95[20] = 0;
  LOBYTE(v111) = 17;
  v49 = (char *)operator new(0x14u);
  if ( !v49 )
    std::_Xbad_alloc();
  v50 = v97;
  v51 = *(_QWORD *)iname._Bx._Buf;
  *(_DWORD *)v49 = &std::_Func_impl<std::_Callable_obj<_lambda_43fdd51eb06f281a9fb5c00b64dbd4b0_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_QWORD *)(v49 + 4) = v51;
  *((_DWORD *)v49 + 3) = this;
  *(_DWORD *)&v50->name._Bx._Alias[12] = v49;
  LOBYTE(v111) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->eyesDistanceSpinner->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v95[4],
    (void *)LODWORD(y));
  v97 = (ksgui::Control *)operator new(0x118u);
  LOBYTE(v111) = 18;
  if ( v97 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"SAVE_BUTTON", 0xBu);
    LOBYTE(v111) = 19;
    y = *(float *)&this->gui;
    v100 |= 4u;
    v101 = v100;
    ksgui::Control::Control(v97, &iname, (ksgui::GUI *)LODWORD(y));
  }
  else
  {
    v52 = 0;
  }
  this->saveButton = v52;
  v111 = 4;
  if ( (v100 & 4) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v53 = font._Rep;
  v54 = (ksgui::Control *)&this->saveButton->font;
  v97 = v54;
  if ( font._Rep )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&font._Rep->_Uses, 1u);
    v54 = v97;
  }
  v55 = v54->name._Bx._Ptr;
  v56 = font._Ptr;
  v54->name._Bx._Ptr = (wchar_t *)v53;
  v97 = (ksgui::Control *)v55;
  v54->__vftable = (ksgui::Control_vtbl *)v56;
  if ( v55 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v55 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(wchar_t *))v55)(v55);
      v57 = v97;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v97->name._Bx._Alias[4], 0xFFFFFFFF) )
        ((void (*)(ksgui::Control *))v57->hitTest)(v57);
    }
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Save", 4u);
  LOBYTE(v111) = 21;
  this->saveButton->setText(this->saveButton, &iname);
  LOBYTE(v111) = 4;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->saveButton->setSize)(this->saveButton, 1114636288, 1102577664);
  ((void (*)(ksgui::Control *, int))this->saveButton->setRepeatInterval)(this->saveButton, 1028443341);
  v58 = this->saveButton;
  v59 = v58->rectBase.left;
  v60 = v58->rect.right - v58->rect.left;
  v61 = v58->rect.bottom - v58->rect.top;
  v58->rect.top = 200.0;
  v58->rect.left = 275.0;
  v62 = v60 + 275.0;
  v63 = v61 + 200.0;
  v58->rect.right = v62;
  v58->rect.bottom = v63;
  if ( v59 == 0.0 && v58->rectBase.top == 0.0 )
  {
    v58->rectBase.left = 275.0;
    v58->rectBase.top = 200.0;
    v58->rectBase.right = v62;
    v58->rectBase.bottom = v63;
  }
  y = *(float *)&this->saveButton;
  iname._Bx._Ptr = (wchar_t *)(int)*(float *)&v104;
  *(_DWORD *)&iname._Bx._Alias[4] = v103;
  *(_QWORD *)&iname._Bx._Alias[8] = __PAIR64__((unsigned int)this, (unsigned int)v99);
  v97 = (ksgui::Control *)&v95[4];
  *(_DWORD *)&v95[20] = 0;
  LOBYTE(v111) = 22;
  v64 = (char *)operator new(0x18u);
  if ( !v64 )
    std::_Xbad_alloc();
  v65 = _mm_loadu_si128((const __m128i *)&iname);
  v66 = v97;
  *(_DWORD *)v64 = &std::_Func_impl<std::_Callable_obj<_lambda_1f30e92d90f7df2d8ce4a56b22aaa5eb_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(__m128i *)(v64 + 4) = v65;
  LOBYTE(v111) = 4;
  *(_DWORD *)&v66->name._Bx._Alias[12] = v64;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->saveButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v95[4],
    (void *)LODWORD(y));
  v67 = v16->_Mylast;
  v99 = this->saveButton;
  DWORD2(v104) = v99;
  if ( (char *)&v104 + 8 < (char *)v67 && v16->_Myfirst <= (ksgui::CustomSpinner **)&v104 + 2 )
  {
    v68 = v16->_Myend;
    v69 = ((char *)&v104 + 8 - (char *)v16->_Myfirst) >> 2;
    _Val = v69;
    if ( v67 == v68 )
    {
      if ( !(v68 - v67) )
      {
        v70 = v67 - v16->_Myfirst;
        if ( v70 == 0x3FFFFFFF )
          std::_Xlength_error("vector<T> too long");
        v71 = v70 + 1;
        v72 = v68 - v16->_Myfirst;
        if ( 0x3FFFFFFF - (v72 >> 1) >= v72 )
          v73 = (v72 >> 1) + v72;
        else
          v73 = 0;
        if ( v73 < v71 )
          v73 = v71;
        std::vector<ksgui::CustomSpinner *>::_Reallocate(v16, v73);
      }
      v69 = _Val;
    }
    v74 = v16->_Mylast;
    if ( v74 )
      *v74 = v16->_Myfirst[v69];
LABEL_121:
    v75 = v99;
    goto LABEL_122;
  }
  v89 = v16->_Myend;
  if ( v67 == v89 && !(v89 - v67) )
  {
    v90 = v67 - v16->_Myfirst;
    if ( v90 == 0x3FFFFFFF )
      std::_Xlength_error("vector<T> too long");
    v91 = v90 + 1;
    v92 = v89 - v16->_Myfirst;
    if ( 0x3FFFFFFF - (v92 >> 1) >= v92 )
      v93 = (v92 >> 1) + v92;
    else
      v93 = 0;
    if ( v93 < v91 )
      v93 = v91;
    std::vector<ksgui::CustomSpinner *>::_Reallocate(v16, v93);
  }
  v94 = v16->_Mylast;
  if ( !v94 )
    goto LABEL_121;
  v75 = v99;
  *v94 = v99;
LABEL_122:
  ++v16->_Mylast;
  LODWORD(y) = 284;
  v75->parent = this;
  v76 = (ksgui::Label *)operator new(LODWORD(y));
  v97 = v76;
  v77 = 0;
  LOBYTE(v111) = 23;
  if ( v76 )
  {
    y = *(float *)&this->gui;
    *(_DWORD *)&v95[24] = 7;
    *(_DWORD *)&v95[20] = 0;
    *(_WORD *)&v95[4] = 0;
    std::wstring::assign((std::wstring *)&v95[4], L"LAB_WARNING", 0xBu);
    ksgui::Label::Label(v76, *(std::wstring *)&v95[4], (ksgui::GUI *)LODWORD(y));
  }
  LOBYTE(v111) = 4;
  LODWORD(y) = &small_font;
  this->labWarning = v77;
  std::shared_ptr<Font>::operator=(&v77->font, (const std::shared_ptr<Font> *)LODWORD(y));
  v78 = this->labWarning;
  LODWORD(y) = 40;
  *(_DWORD *)&v95[24] = L"* supersampling changes requires restart";
  iname._Myres = 7;
  v78->fontAlign = eAlignLeft;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v95[24], LODWORD(y));
  LOBYTE(v111) = 24;
  v79 = acTranslate(&result, &iname);
  LOBYTE(v111) = 25;
  this->labWarning->setText(this->labWarning, v79);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v111) = 4;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ((void (*)(ksgui::Label *, int, int))this->labWarning->setSize)(this->labWarning, 1120403456, 1102577664);
  v80 = this->labWarning;
  v81 = v80->rectBase.left;
  v82 = v80->rect.right - v80->rect.left;
  v83 = v80->rect.bottom - v80->rect.top;
  v80->rect.top = 250.0;
  v80->rect.left = 20.0;
  v84 = v82 + 20.0;
  v85 = v83 + 250.0;
  v80->rect.right = v84;
  v80->rect.bottom = v85;
  if ( v81 == 0.0 && v80->rectBase.top == 0.0 )
  {
    v80->rectBase.left = 20.0;
    v80->rectBase.top = 250.0;
    v80->rectBase.right = v84;
    v80->rectBase.bottom = v85;
  }
  v86 = this->labWarning;
  if ( !v86->visible )
  {
    v87 = v86->__vftable;
    LODWORD(y) = 1;
    v86->visible = 1;
    ((void (__stdcall *)(_DWORD))v87->onVisibleChanged)(LODWORD(y));
  }
  _Val = (int)this->labWarning;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)v16, &_Val);
  y = 280.0;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 370.0, y);
  LOBYTE(v111) = 2;
  v88 = small_font._Rep;
  this->loaded = 1;
  if ( v88 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v88->_Uses, 0xFFFFFFFF) )
    {
      v88->_Destroy(v88);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v88->_Weaks, 0xFFFFFFFF) )
        v88->_Delete_this(v88);
    }
  }
  LOBYTE(v111) = 0;
  if ( v53 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v53->_Uses, 0xFFFFFFFF) )
  {
    v53->_Destroy(v53);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v53->_Weaks) )
      ((void (*)(void))v53->_Delete_this)();
  }
}
