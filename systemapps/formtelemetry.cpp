#include "formtelemetry.h
void FormTelemetry::FormTelemetry(FormTelemetry *this, CarAvatar *car_avatar)
{
  Game *v3; // eax
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TelemetryChannelDef>> > *v4; // ecx
  std::_Tree_node<std::pair<std::wstring const ,TelemetryChannelDef>,void *> *v5; // eax
  CarAvatar *v6; // eax
  const std::wstring *v7; // eax
  void (__cdecl *v8)(void *); // esi
  std::vector<unsigned int> *v9; // ebx
  ksgui::Graph *v10; // edi
  int v11; // eax
  ksgui::Graph *v12; // edi
  __int64 v13; // xmm0_8
  unsigned int *v14; // eax
  int v15; // edi
  unsigned int *v16; // ecx
  _DWORD *v17; // eax
  ksgui::Spinner *v18; // edi
  Event<OnPhysicsStepCompleted> *v19; // eax
  ksgui::Spinner *v20; // edi
  _DWORD *v21; // edi
  _DWORD *v22; // esi
  Event<OnPhysicsStepCompleted> *v23; // ebx
  unsigned int v24; // edx
  int **v25; // eax
  int *j; // eax
  int i; // eax
  ksgui::Label *v28; // esi
  ksgui::Label *v29; // eax
  unsigned int *v30; // ecx
  unsigned int *v31; // edi
  unsigned int *v32; // edx
  int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edx
  _DWORD *v36; // ecx
  unsigned int *v37; // edx
  int v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // edx
  int v41; // eax
  _DWORD *v42; // edi
  ksgui::Label *v43; // esi
  int v44; // eax
  ksgui::Label *v45; // esi
  unsigned int *v46; // ecx
  unsigned int *v47; // edi
  unsigned int *v48; // edx
  int v49; // ecx
  unsigned int v50; // edx
  unsigned int v51; // edx
  unsigned int *v52; // ecx
  unsigned int *v53; // edx
  int v54; // ecx
  unsigned int v55; // edx
  unsigned int v56; // edx
  _DWORD *v57; // eax
  ksgui::Control *v58; // ecx
  Event<OnPhysicsStepCompleted> *v59; // esi
  unsigned int *v60; // ecx
  unsigned int *v61; // edi
  unsigned int *v62; // edx
  int v63; // ecx
  unsigned int v64; // edx
  unsigned int v65; // edx
  unsigned int *v66; // ecx
  unsigned int *v67; // edx
  int v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // edx
  _DWORD *v71; // eax
  int v72; // eax
  _DWORD *v73; // eax
  int v74; // edi
  std::vector<ksgui::CustomSpinner *> *v75; // esi
  int v76; // eax
  ksgui::CustomSpinner **v77; // ecx
  ksgui::CustomSpinner **v78; // edx
  int v79; // edi
  int v80; // ecx
  unsigned int v81; // edx
  unsigned int v82; // edx
  ksgui::CustomSpinner **v83; // ecx
  ksgui::CustomSpinner **v84; // edx
  int v85; // ecx
  unsigned int v86; // edx
  unsigned int v87; // edx
  _DWORD *v88; // eax
  std::vector<TelemetryGraph> *v89; // ecx
  std::vector<TelemetryGraph> *v90; // esi
  ksgui::Spinner *v91; // eax
  FormTelemetry *v92; // edi
  void (__cdecl *v93)(void *); // ebx
  int v94; // eax
  std::wstring *v95; // eax
  TelemetryPreset *v96; // esi
  int v97; // edi
  std::wstring *v98; // esi
  std::wstring *v99; // eax
  const std::wstring *v100; // eax
  std::wstring *v101; // ebx
  const std::wstring *v102; // eax
  PitCrew *const *v103; // eax
  _BYTE v104[32]; // [esp-8h] [ebp-234h] BYREF
  unsigned int _Count; // [esp+34h] [ebp-1F8h]
  ksgui::Label *v106; // [esp+38h] [ebp-1F4h]
  void *owner; // [esp+3Ch] [ebp-1F0h]
  int _Val; // [esp+40h] [ebp-1ECh] BYREF
  unsigned int v109; // [esp+44h] [ebp-1E8h]
  Event<OnPhysicsStepCompleted> *v110; // [esp+48h] [ebp-1E4h]
  std::vector<TelemetryGraph> *v111; // [esp+4Ch] [ebp-1E0h]
  std::vector<TelemetryPreset> *v112; // [esp+50h] [ebp-1DCh] BYREF
  int v113; // [esp+54h] [ebp-1D8h]
  ksgui::Graph *v114; // [esp+58h] [ebp-1D4h] BYREF
  ksgui::Label *v115; // [esp+5Ch] [ebp-1D0h] BYREF
  Event<OnPhysicsStepCompleted> *v116; // [esp+60h] [ebp-1CCh] BYREF
  ksgui::Label *v117; // [esp+64h] [ebp-1C8h] BYREF
  int v118; // [esp+68h] [ebp-1C4h] BYREF
  std::vector<unsigned int> *v119; // [esp+6Ch] [ebp-1C0h]
  std::wstring text; // [esp+70h] [ebp-1BCh] BYREF
  __int64 v121; // [esp+88h] [ebp-1A4h]
  std::wstring section; // [esp+90h] [ebp-19Ch] BYREF
  std::wstring v123; // [esp+A8h] [ebp-184h] BYREF
  std::wstring key; // [esp+C0h] [ebp-16Ch] BYREF
  std::wstring result; // [esp+D8h] [ebp-154h] BYREF
  TelemetryGraph tg; // [esp+F0h] [ebp-13Ch] BYREF
  TelemetryPreset p; // [esp+10Ch] [ebp-120h] BYREF
  INIReader ini; // [esp+184h] [ebp-A8h] BYREF
  INIReaderDocuments v129; // [esp+1CCh] [ebp-60h] BYREF
  int v130; // [esp+228h] [ebp-4h]

  owner = this;
  v106 = 0;
  *(_DWORD *)&v104[28] = 0;
  v109 = 0;
  v3 = car_avatar->game;
  text._Bx._Ptr = (wchar_t *)this;
  *(_DWORD *)&v104[24] = v3->gui;
  *(_DWORD *)&v104[20] = 7;
  *(_DWORD *)&v104[16] = 0;
  *(_WORD *)v104 = 0;
  std::wstring::assign((std::wstring *)v104, L"TELEMETRY", 9u);
  ksgui::Form::Form(this, (unsigned int)this, *(std::wstring *)v104, *(ksgui::GUI **)&v104[24], v104[28]);
  v130 = 0;
  this->__vftable = (FormTelemetry_vtbl *)&FormTelemetry::`vftable';
  v111 = &this->graphs;
  this->graphs._Myfirst = 0;
  this->graphs._Mylast = 0;
  this->graphs._Myend = 0;
  LOBYTE(v130) = 1;
  this->carAvatar = car_avatar;
  this->channels._Myhead = 0;
  this->channels._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,TelemetryChannelDef>>>::_Buyheadnode(v4);
  this->channels._Myhead = v5;
  this->presets._Myfirst = 0;
  v112 = &this->presets;
  this->presets._Mylast = 0;
  this->presets._Myend = 0;
  LOBYTE(v130) = 3;
  `eh vector constructor iterator'(
    this->liveValuesChannels,
    0x14u,
    4,
    (void (*)(void *))BufferedChannel<float>::BufferedChannel<float>,
    (void (*)(void *))BufferedChannel<float>::~BufferedChannel<float>);
  LOBYTE(v130) = 4;
  v6 = this->carAvatar;
  this->carPhysics = 0;
  this->lastPhysicsRecTime = 0.0;
  *(_DWORD *)&v104[28] = 9;
  this->carPhysics = v6->physics;
  LODWORD(v121) = 7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"Telemetry", *(unsigned int *)&v104[28]);
  LOBYTE(v130) = 5;
  v7 = acTranslate(&section, (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v130) = 6;
  this->formTitle->setText(this->formTitle, v7);
  v8 = operator delete;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  LOBYTE(v130) = 4;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( (unsigned int)v121 >= 8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  FormTelemetry::initChannels(this);
  v9 = (std::vector<unsigned int> *)&this->controls;
  _Val = 0;
  *(_QWORD *)key._Bx._Buf = 0i64;
  *(_DWORD *)&key._Bx._Alias[8] = 0;
  v119 = v9;
  while ( 1 )
  {
    tg.channel = 0;
    tg.smoothValue = 0.0;
    tg.resetSmoothValue = 0;
    v10 = (ksgui::Graph *)operator new(0x140u);
    _Count = (unsigned int)v10;
    LOBYTE(v130) = 7;
    if ( v10 )
    {
      *(_DWORD *)&v104[28] = *((_DWORD *)owner + 60);
      *(_DWORD *)&v104[24] = 7;
      *(_DWORD *)&v104[20] = 0;
      *(_WORD *)&v104[4] = 0;
      std::wstring::assign((std::wstring *)&v104[4], L"GRAPH", 5u);
      ksgui::Graph::Graph(v10, *(std::wstring *)&v104[4], *(ksgui::GUI **)&v104[28]);
      v12 = (ksgui::Graph *)v11;
      v113 = v11;
    }
    else
    {
      v12 = 0;
      v113 = 0;
    }
    LOBYTE(v130) = 4;
    v13 = *(_QWORD *)key._Bx._Buf;
    *(_DWORD *)&text._Bx._Alias[12] = *(_DWORD *)&key._Bx._Alias[8];
    *(_DWORD *)&v104[28] = &text._Bx._Alias[4];
    tg.graph = v12;
    v12->maxValuesCount = 500;
    *(_QWORD *)&text._Bx._Alias[4] = v13;
    text._Mysize = 1056964608;
    LOBYTE(text._Myres) = 0;
    std::vector<ksgui::GraphReferenceAxis>::push_back(&v12->axes, *(const ksgui::GraphReferenceAxis **)&v104[28]);
    v14 = v9->_Mylast;
    v114 = v12;
    if ( &v114 >= (ksgui::Graph **)v14 || v9->_Myfirst > (unsigned int *)&v114 )
    {
      if ( v14 == v9->_Myend )
        std::vector<unsigned int>::_Reserve(v9, 1u);
      v17 = v9->_Mylast;
      if ( v17 )
        *v17 = v12;
    }
    else
    {
      v15 = ((char *)&v114 - (char *)v9->_Myfirst) >> 2;
      if ( v14 == v9->_Myend )
        std::vector<unsigned int>::_Reserve(v9, 1u);
      v16 = v9->_Mylast;
      if ( v16 )
        *v16 = v9->_Myfirst[v15];
      v12 = (ksgui::Graph *)v113;
    }
    ++v9->_Mylast;
    *(_DWORD *)&v104[28] = 444;
    v12->parent = (ksgui::Control *)owner;
    v18 = (ksgui::Spinner *)operator new(*(unsigned int *)&v104[28]);
    _Count = (unsigned int)v18;
    LOBYTE(v130) = 8;
    if ( v18 )
    {
      LODWORD(v121) = 7;
      text._Myres = 0;
      text._Bx._Buf[2] = 0;
      std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"SPINNER", 7u);
      LOBYTE(v130) = 9;
      v109 |= 1u;
      v106 = (ksgui::Label *)v109;
      ksgui::Spinner::Spinner(v18, (const std::wstring *)&text._Bx._Alias[4], *((ksgui::GUI **)owner + 60), 0, 0);
      v20 = (ksgui::Spinner *)v19;
      v110 = v19;
    }
    else
    {
      v20 = 0;
      v110 = 0;
    }
    v130 = 4;
    tg.spinner = v20;
    if ( (v109 & 1) != 0 )
    {
      v109 &= 0xFFFFFFFE;
      if ( (unsigned int)v121 >= 8 )
        v8(*(void **)&text._Bx._Alias[4]);
    }
    LODWORD(v121) = 7;
    text._Myres = 0;
    text._Bx._Buf[2] = 0;
    std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
    LOBYTE(v130) = 11;
    v20->label->setText(v20->label, (const std::wstring *)&text._Bx._Alias[4]);
    LOBYTE(v130) = 4;
    if ( (unsigned int)v121 >= 8 )
      v8(*(void **)&text._Bx._Alias[4]);
    v21 = (_DWORD *)*((_DWORD *)owner + 84);
    v22 = (_DWORD *)*v21;
    if ( (_DWORD *)*v21 != v21 )
    {
      v23 = v110;
      do
      {
        LODWORD(v121) = 7;
        text._Bx._Buf[2] = 0;
        text._Myres = 0;
        std::wstring::assign((std::wstring *)&text._Bx._Alias[4], (const std::wstring *)(v22 + 4), 0, 0xFFFFFFFF);
        LOBYTE(v130) = 12;
        std::vector<std::wstring>::push_back(
          (std::vector<std::wstring> *)&v23[35].handlers._Mylast,
          (const std::wstring *)&text._Bx._Alias[4]);
        v110[24].handlers._Myfirst = 0;
        v24 = (int)((unsigned __int64)(715827883i64
                                     * ((char *)v23[35].handlers._Myend - (char *)v23[35].handlers._Mylast)) >> 32) >> 2;
        LOBYTE(v130) = 4;
        v110[24].handlers._Mylast = (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)(v24 + (v24 >> 31) - 1);
        if ( (unsigned int)v121 >= 8 )
          operator delete(*(void **)&text._Bx._Alias[4]);
        if ( !*((_BYTE *)v22 + 13) )
        {
          v25 = (int **)v22[2];
          if ( *((_BYTE *)v25 + 13) )
          {
            for ( i = v22[1]; !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 4) )
            {
              if ( v22 != *(_DWORD **)(i + 8) )
                break;
              v22 = (_DWORD *)i;
            }
            v22 = (_DWORD *)i;
          }
          else
          {
            v22 = (_DWORD *)v22[2];
            for ( j = *v25; !*((_BYTE *)j + 13); j = (int *)*j )
              v22 = j;
          }
        }
      }
      while ( v22 != v21 );
      v9 = v119;
    }
    v28 = (ksgui::Label *)operator new(0x11Cu);
    _Count = (unsigned int)v28;
    LOBYTE(v130) = 13;
    if ( v28 )
    {
      *(_DWORD *)&v104[28] = *((_DWORD *)owner + 60);
      *(_DWORD *)&v104[24] = 7;
      *(_DWORD *)&v104[20] = 0;
      *(_WORD *)&v104[4] = 0;
      std::wstring::assign((std::wstring *)&v104[4], L"LIVE", 4u);
      ksgui::Label::Label(v28, *(std::wstring *)&v104[4], *(ksgui::GUI **)&v104[28]);
    }
    else
    {
      v29 = 0;
    }
    LOBYTE(v130) = 4;
    v30 = v9->_Mylast;
    v106 = v29;
    tg.lblLiveValue = v29;
    v115 = v29;
    if ( &v115 >= (ksgui::Label **)v30 || (v31 = v9->_Myfirst, v9->_Myfirst > (unsigned int *)&v115) )
    {
      v37 = v9->_Myend;
      if ( v30 == v37 )
      {
        if ( !(v37 - v30) )
        {
          v38 = v30 - v9->_Myfirst;
          if ( v38 == 0x3FFFFFFF )
            goto LABEL_152;
          v39 = v37 - v9->_Myfirst;
          if ( 0x3FFFFFFF - (v39 >> 1) >= v39 )
            v40 = (v39 >> 1) + v39;
          else
            v40 = 0;
          if ( v40 < v38 + 1 )
            v40 = v38 + 1;
          std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v40);
        }
        v29 = v106;
      }
      v36 = v9->_Mylast;
      if ( v36 )
        goto LABEL_70;
    }
    else
    {
      v32 = v9->_Myend;
      if ( v30 == v32 && !(v32 - v30) )
      {
        v33 = v30 - v31;
        if ( v33 == 0x3FFFFFFF )
          goto LABEL_152;
        v34 = v32 - v31;
        _Count = v33 + 1;
        if ( 0x3FFFFFFF - (v34 >> 1) >= v34 )
          v35 = (v34 >> 1) + v34;
        else
          v35 = 0;
        if ( v35 < _Count )
          v35 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v35);
      }
      v36 = v9->_Mylast;
      if ( v36 )
      {
        v29 = (ksgui::Label *)v9->_Myfirst[((char *)&v115 - (char *)v31) >> 2];
LABEL_70:
        *v36 = v29;
        goto LABEL_71;
      }
    }
LABEL_71:
    v41 = (int)v106;
    ++v9->_Mylast;
    v42 = owner;
    *(_DWORD *)&v104[28] = 284;
    *(_DWORD *)(v41 + 148) = owner;
    v43 = (ksgui::Label *)operator new(*(unsigned int *)&v104[28]);
    _Count = (unsigned int)v43;
    LOBYTE(v130) = 14;
    if ( v43 )
    {
      *(_DWORD *)&v104[28] = v42[60];
      *(_DWORD *)&v104[24] = 7;
      *(_DWORD *)&v104[20] = 0;
      *(_WORD *)&v104[4] = 0;
      std::wstring::assign((std::wstring *)&v104[4], L"SMOOTH", 6u);
      ksgui::Label::Label(v43, *(std::wstring *)&v104[4], *(ksgui::GUI **)&v104[28]);
      v45 = (ksgui::Label *)v44;
      v106 = (ksgui::Label *)v44;
    }
    else
    {
      v45 = 0;
      v106 = 0;
    }
    LOBYTE(v130) = 4;
    v46 = v9->_Mylast;
    tg.lblSmoothValue = v45;
    v117 = v45;
    if ( &v117 >= (ksgui::Label **)v46 || (v47 = v9->_Myfirst, v9->_Myfirst > (unsigned int *)&v117) )
    {
      v53 = v9->_Myend;
      if ( v46 == v53 && !(v53 - v46) )
      {
        v54 = v46 - v9->_Myfirst;
        if ( v54 == 0x3FFFFFFF )
          goto LABEL_152;
        v55 = v53 - v9->_Myfirst;
        _Count = v54 + 1;
        if ( 0x3FFFFFFF - (v55 >> 1) >= v55 )
          v56 = (v55 >> 1) + v55;
        else
          v56 = 0;
        if ( v56 < _Count )
          v56 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v56);
      }
      v57 = v9->_Mylast;
      if ( v57 )
        *v57 = v45;
    }
    else
    {
      v48 = v9->_Myend;
      if ( v46 == v48 && !(v48 - v46) )
      {
        v49 = v46 - v47;
        if ( v49 == 0x3FFFFFFF )
          goto LABEL_152;
        v50 = v48 - v47;
        _Count = v49 + 1;
        if ( 0x3FFFFFFF - (v50 >> 1) >= v50 )
          v51 = (v50 >> 1) + v50;
        else
          v51 = 0;
        if ( v51 < _Count )
          v51 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v51);
      }
      v52 = v9->_Mylast;
      if ( v52 )
        *v52 = v9->_Myfirst[((char *)&v117 - (char *)v47) >> 2];
      v45 = v106;
    }
    v58 = (ksgui::Control *)owner;
    ++v9->_Mylast;
    *(_DWORD *)&v104[28] = v58;
    v45->parent = v58;
    v59 = v110;
    *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_9457bf3edf1a84cb5d031a705cb1b383_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v104[12] = v58;
    *(_DWORD *)&v104[8] = _Val;
    *(_DWORD *)&v104[20] = &v104[4];
    LOBYTE(v130) = 4;
    Event<std::wstring>::addHandler(
      v110 + 25,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v104[4],
      *(void **)&v104[28]);
    v60 = v9->_Mylast;
    v116 = v59;
    if ( &v116 >= (Event<OnPhysicsStepCompleted> **)v60 || (v61 = v9->_Myfirst, v9->_Myfirst > (unsigned int *)&v116) )
    {
      v67 = v9->_Myend;
      if ( v60 == v67 && !(v67 - v60) )
      {
        v68 = v60 - v9->_Myfirst;
        if ( v68 == 0x3FFFFFFF )
          goto LABEL_152;
        v69 = v67 - v9->_Myfirst;
        if ( 0x3FFFFFFF - (v69 >> 1) >= v69 )
          v70 = (v69 >> 1) + v69;
        else
          v70 = 0;
        if ( v70 < v68 + 1 )
          v70 = v68 + 1;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v70);
        v59 = v110;
      }
      v71 = v9->_Mylast;
      if ( v71 )
        *v71 = v59;
    }
    else
    {
      v62 = v9->_Myend;
      if ( v60 == v62 && !(v62 - v60) )
      {
        v63 = v60 - v61;
        if ( v63 == 0x3FFFFFFF )
          goto LABEL_152;
        v64 = v62 - v61;
        _Count = v63 + 1;
        if ( 0x3FFFFFFF - (v64 >> 1) >= v64 )
          v65 = (v64 >> 1) + v64;
        else
          v65 = 0;
        if ( v65 < _Count )
          v65 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v9, v65);
      }
      v66 = v9->_Mylast;
      if ( v66 )
        *v66 = v9->_Myfirst[((char *)&v116 - (char *)v61) >> 2];
    }
    v72 = (int)v110;
    ++v9->_Mylast;
    *(_DWORD *)&v104[28] = 24;
    *(_DWORD *)(v72 + 148) = owner;
    *(_QWORD *)section._Bx._Buf = 1065353216i64;
    *(_DWORD *)&section._Bx._Alias[8] = 0;
    v73 = operator new(*(unsigned int *)&v104[28]);
    v74 = (int)v73;
    if ( v73 )
    {
      *v73 = 0;
      v73[1] = 0;
      v73[2] = 0;
      v73[3] = 0;
      v73[4] = 0;
      v73[5] = 0;
    }
    else
    {
      v74 = 0;
    }
    v75 = (std::vector<ksgui::CustomSpinner *> *)(v113 + 296);
    v76 = *(_DWORD *)&section._Bx._Alias[8];
    *(_QWORD *)v74 = *(_QWORD *)section._Bx._Buf;
    *(_DWORD *)(v74 + 8) = v76;
    v77 = v75->_Mylast;
    v118 = v74;
    if ( &v118 >= (int *)v77 || v75->_Myfirst > (ksgui::CustomSpinner **)&v118 )
    {
      v84 = v75->_Myend;
      if ( v77 == v84 && !(v84 - v77) )
      {
        v85 = v77 - v75->_Myfirst;
        if ( v85 == 0x3FFFFFFF )
LABEL_152:
          std::_Xlength_error("vector<T> too long");
        v86 = v84 - v75->_Myfirst;
        _Count = v85 + 1;
        if ( 0x3FFFFFFF - (v86 >> 1) >= v86 )
          v87 = (v86 >> 1) + v86;
        else
          v87 = 0;
        if ( v87 < _Count )
          v87 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate(v75, v87);
      }
      v88 = v75->_Mylast;
      if ( v88 )
        *v88 = v74;
    }
    else
    {
      v78 = v75->_Myend;
      v79 = ((char *)&v118 - (char *)v75->_Myfirst) >> 2;
      if ( v77 == v78 && !(v78 - v77) )
      {
        v80 = v77 - v75->_Myfirst;
        if ( v80 == 0x3FFFFFFF )
          goto LABEL_152;
        v81 = v78 - v75->_Myfirst;
        _Count = v80 + 1;
        if ( 0x3FFFFFFF - (v81 >> 1) >= v81 )
          v82 = (v81 >> 1) + v81;
        else
          v82 = 0;
        if ( v82 < _Count )
          v82 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate(v75, v82);
      }
      v83 = v75->_Mylast;
      if ( v83 )
        *v83 = v75->_Myfirst[v79];
    }
    v89 = v111;
    ++v75->_Mylast;
    std::vector<TelemetryGraph>::push_back(v89, &tg);
    if ( ++_Val >= 4 )
      break;
    v8 = operator delete;
  }
  v90 = (std::vector<TelemetryGraph> *)operator new(0x1BCu);
  v111 = v90;
  v91 = 0;
  LOBYTE(v130) = 16;
  if ( v90 )
  {
    LODWORD(v121) = 7;
    text._Myres = 0;
    text._Bx._Buf[2] = 0;
    std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"PRESETS", 7u);
    LOBYTE(v130) = 17;
    v92 = (FormTelemetry *)owner;
    *(_DWORD *)&v104[28] = 0;
    *(_DWORD *)&v104[24] = 0;
    v109 |= 2u;
    *(_DWORD *)&v104[20] = *((_DWORD *)owner + 60);
    v106 = (ksgui::Label *)v109;
    ksgui::Spinner::Spinner(
      (ksgui::Spinner *)v90,
      (const std::wstring *)&text._Bx._Alias[4],
      *(ksgui::GUI **)&v104[20],
      0,
      0);
  }
  else
  {
    v92 = (FormTelemetry *)owner;
  }
  v92->spPresets = v91;
  v130 = 4;
  if ( (v109 & 2) != 0 && (unsigned int)v121 >= 8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  ((void (*)(ksgui::Spinner *, int, int))v92->spPresets->setSize)(v92->spPresets, 1137180672, 1106247680);
  ksgui::Spinner::setPosition(v92->spPresets, 2.0, 50.0);
  _Val = (int)v92->spPresets;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)v9, &_Val);
  *(_DWORD *)&v104[28] = 32;
  *(_DWORD *)&v104[24] = L"system/cfg/telemetry_presets.ini";
  LODWORD(v121) = 7;
  *(_DWORD *)(_Val + 148) = v92;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], *(const wchar_t **)&v104[24], *(unsigned int *)&v104[28]);
  LOBYTE(v130) = 19;
  INIReader::INIReader(&ini, (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v130) = 21;
  v93 = operator delete;
  if ( (unsigned int)v121 >= 8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v94 = 0;
  LODWORD(v121) = 7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  if ( ini.ready )
  {
    _Val = 0;
    while ( 1 )
    {
      v95 = std::to_wstring(&result, v94);
      LOBYTE(v130) = 22;
      std::operator+<wchar_t>(&section, L"PRESET_", v95);
      LOBYTE(v130) = 24;
      if ( result._Myres >= 8 )
        v93(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      p.name._Myres = 7;
      p.name._Mysize = 0;
      p.name._Bx._Buf[0] = 0;
      LOBYTE(v130) = 25;
      `eh vector constructor iterator'(
        p.channels,
        0x18u,
        4,
        (void (*)(void *))std::wstring::wstring,
        (void (*)(void *))std::wstring::~wstring);
      LOBYTE(v130) = 26;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"NAME", 4u);
      LOBYTE(v130) = 27;
      v96 = (TelemetryPreset *)INIReader::getString(&ini, &v123, &section, &key);
      if ( &p != v96 )
      {
        if ( p.name._Myres >= 8 )
          v93(p.name._Bx._Ptr);
        p.name._Myres = 7;
        p.name._Mysize = 0;
        p.name._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&p.name, &v96->name);
      }
      if ( v123._Myres >= 8 )
        v93(v123._Bx._Ptr);
      LOBYTE(v130) = 26;
      v123._Myres = 7;
      v123._Mysize = 0;
      v123._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        v93(key._Bx._Ptr);
      v97 = 0;
      v98 = p.channels;
      do
      {
        v99 = std::to_wstring((std::wstring *)&tg, v97);
        LOBYTE(v130) = 28;
        v100 = std::operator+<wchar_t>(&key, L"DATA_", v99);
        LOBYTE(v130) = 29;
        v101 = INIReader::getString(&ini, &v123, &section, v100);
        if ( v98 != v101 )
        {
          if ( v98->_Myres >= 8 )
            operator delete(v98->_Bx._Ptr);
          v98->_Myres = 7;
          v98->_Mysize = 0;
          *(_DWORD *)&v104[28] = v101;
          v98->_Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(v98, *(std::wstring **)&v104[28]);
        }
        v93 = operator delete;
        if ( v123._Myres >= 8 )
          operator delete(v123._Bx._Ptr);
        v123._Myres = 7;
        v123._Mysize = 0;
        v123._Bx._Buf[0] = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        LOBYTE(v130) = 26;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( LODWORD(tg.smoothValue) >= 8 )
          operator delete(tg.graph);
        ++v97;
        ++v98;
      }
      while ( v97 < 4 );
      std::vector<TelemetryPreset>::push_back(v112, &p);
      *(_DWORD *)&v104[28] = 7;
      *(_DWORD *)&v104[24] = 0;
      *(_WORD *)&v104[8] = 0;
      std::wstring::assign((std::wstring *)&v104[8], &p.name, 0, 0xFFFFFFFF);
      v92 = (FormTelemetry *)owner;
      ksgui::Spinner::addItem(*((ksgui::Spinner **)owner + 86), *(std::wstring *)&v104[8]);
      LOBYTE(v130) = 24;
      `eh vector destructor iterator'(p.channels, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
      if ( p.name._Myres >= 8 )
        operator delete(p.name._Bx._Ptr);
      v94 = _Val + 1;
      LOBYTE(v130) = 21;
      ++_Val;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v94 = _Val;
      }
    }
    if ( section._Myres >= 8 )
      v93(section._Bx._Ptr);
  }
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6a09d9ac97f50fd80b6d1c5187e176c0_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v104[8] = v92;
  *(_DWORD *)&v104[20] = &v104[4];
  LOBYTE(v130) = 21;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v92->spPresets->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v104[4],
    v92);
  if ( v92->presets._Mylast - v92->presets._Myfirst )
  {
    *(_DWORD *)&v104[28] = 0;
    std::wstring::wstring((std::wstring *)&v104[4], L"/cfg/telemetry_user.ini");
    INIReaderDocuments::INIReaderDocuments(&v129, (unsigned int)v93, *(std::wstring *)&v104[4], v104[28]);
    LOBYTE(v130) = 31;
    if ( v129.ready )
    {
      std::wstring::wstring(&result, L"PRESET");
      LOBYTE(v130) = 32;
      std::wstring::wstring(&section, L"USER");
      LOBYTE(v130) = 33;
      v102 = INIReader::getString(&v129, &v123, &section, &result);
      LOBYTE(v130) = 34;
      ksgui::Spinner::setValue(v92->spPresets, v102);
      if ( v123._Myres >= 8 )
        v93(v123._Bx._Ptr);
      v123._Myres = 7;
      v123._Mysize = 0;
      v123._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        v93(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        v93(result._Bx._Ptr);
    }
    else
    {
      FormTelemetry::applyPreset(v92, &v92->presets._Myfirst->name);
    }
    LOBYTE(v130) = 21;
    INIReaderDocuments::~INIReaderDocuments(&v129);
  }
  *(_DWORD *)&v104[28] = v92;
  v112 = (std::vector<TelemetryPreset> *)v92;
  *(_DWORD *)&v104[20] = 0;
  *(_DWORD *)&v104[4] = &std::_Func_impl<std::_Callable_obj<_lambda_4b59d039ab703025dddb443a6cef518a_,0>,std::allocator<std::_Func_class<void,OnPhysicsStepCompleted const &>>,void,OnPhysicsStepCompleted const &>::`vftable';
  FolderEncrypter::FolderEncrypter((std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&v112);
  std::_Callable_obj<_lambda_4b59d039ab703025dddb443a6cef518a_,0>::_Callable_obj<_lambda_4b59d039ab703025dddb443a6cef518a_,0>(
    (PitStop::{ctor}::__l65::<lambda_9c16e304e7e2c085ae3f98eceac1031e> *)&v104[8],
    v103);
  std::_Func_class<void,OnPhysicsStepCompleted const &>::_Set(
    (std::_Func_class<void,OnPhysicsStepCompleted const &> *)&v104[4],
    (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v104[4]);
  LOBYTE(v130) = 21;
  Event<std::wstring>::addHandler(
    &v92->carAvatar->sim->physicsAvatar->evOnStepCompleted,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v104[4],
    *(void **)&v104[28]);
  ksgui::Form::setSize(v92, 600.0, 700.0);
  LOBYTE(v130) = 4;
  INIReader::~INIReader(&ini);
}
FormTelemetry *FormTelemetry::`scalar deleting destructor'(FormTelemetry *this, unsigned int a2)
{
  FormTelemetry::~FormTelemetry(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormTelemetry::~FormTelemetry(FormTelemetry *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  std::wostream *v4; // eax
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  TelemetryPreset *v7; // ecx
  const std::wstring *v8; // [esp-8h] [ebp-11Ch]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TelemetryChannelDef> > > > v9; // [esp+10h] [ebp-104h] BYREF
  std::wofstream file; // [esp+14h] [ebp-100h] BYREF
  std::wstring result; // [esp+BCh] [ebp-58h] BYREF
  std::wstring v12; // [esp+D4h] [ebp-40h] BYREF
  std::wstring v13; // [esp+ECh] [ebp-28h] BYREF
  int v14; // [esp+110h] [ebp-4h]

  v9._Ptr = (std::_Tree_node<std::pair<std::wstring const ,TelemetryChannelDef>,void *> *)this;
  this->__vftable = (FormTelemetry_vtbl *)&FormTelemetry::`vftable';
  v14 = 4;
  v2 = Path::getDocumentPath(&result);
  LOBYTE(v14) = 5;
  v3 = std::operator+<wchar_t>(&v12, v2, L"/Assetto Corsa/cfg/telemetry_user.ini");
  LOBYTE(v14) = 6;
  std::wofstream::wofstream(&file, v3, 2, 64, 1);
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  LOBYTE(v14) = 9;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, "[USER]");
  std::wostream::operator<<(v4);
  v8 = ksgui::Spinner::getCurrentItem(this->spPresets, &v13);
  LOBYTE(v14) = 10;
  v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, "PRESET=");
  v6 = std::operator<<<wchar_t>(v5, v8);
  std::wostream::operator<<(v6);
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&file.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap58[8]);
  LOBYTE(v14) = 3;
  `eh vector destructor iterator'(
    this->liveValuesChannels,
    0x14u,
    4,
    (void (*)(void *))BufferedChannel<float>::~BufferedChannel<float>);
  v7 = this->presets._Myfirst;
  if ( v7 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TelemetryPreset>>>(v7, this->presets._Mylast);
    operator delete(this->presets._Myfirst);
    this->presets._Myfirst = 0;
    this->presets._Mylast = 0;
    this->presets._Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<std::wstring,TelemetryChannelDef,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,TelemetryChannelDef>>,0>>::erase(
    &this->channels,
    &v9,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TelemetryChannelDef> > > >)this->channels._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TelemetryChannelDef> > > >)this->channels._Myhead);
  operator delete(this->channels._Myhead);
  if ( this->graphs._Myfirst )
  {
    operator delete(this->graphs._Myfirst);
    this->graphs._Myfirst = 0;
    this->graphs._Mylast = 0;
    this->graphs._Myend = 0;
  }
  v14 = -1;
  this->__vftable = (FormTelemetry_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void FormTelemetry::render(FormTelemetry *this, float dt)
{
  int v3; // ecx
  float v4; // xmm1_4
  int v5; // ebx
  int v6; // eax
  ksgui::Control *v7; // ecx
  int v8; // esi
  int v9; // edi
  float v10; // xmm0_4
  float *v11; // ecx
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float *v18; // ecx
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  int v25; // ecx
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  float v36; // xmm0_4
  float *v37; // eax
  float *v38; // ecx
  float *v39; // eax
  float *v40; // ecx
  int v41; // ecx
  float v42; // xmm1_4
  std::vector<ksgui::CustomSpinner *> *v43; // edx
  ksgui::CustomSpinner **v44; // ecx
  int v45; // eax
  int v46; // ecx
  unsigned int v47; // ecx
  unsigned int v48; // ecx
  ksgui::CustomSpinner **v49; // ecx
  ksgui::CustomSpinner *v50; // eax
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // ecx
  unsigned int v54; // ecx
  float *v55; // eax
  Concurrency::details::_Concurrent_queue_base_v4 *v56; // ecx
  std::wstring *v57; // ecx
  std::wstring *v58; // eax
  std::wstring *v59; // ecx
  std::wstring *v60; // eax
  int y; // [esp+6Ch] [ebp-128h]
  int ya; // [esp+6Ch] [ebp-128h]
  __int64 v63; // [esp+70h] [ebp-124h]
  float v64; // [esp+78h] [ebp-11Ch]
  float live_value; // [esp+84h] [ebp-110h] BYREF
  int v66; // [esp+88h] [ebp-10Ch]
  float v67; // [esp+8Ch] [ebp-108h]
  ksgui::Control *v68; // [esp+90h] [ebp-104h]
  unsigned int _Count; // [esp+94h] [ebp-100h]
  Concurrency::details::_Concurrent_queue_base_v4 *v70; // [esp+98h] [ebp-FCh]
  int v71; // [esp+9Ch] [ebp-F8h]
  int v72; // [esp+A0h] [ebp-F4h]
  std::vector<ksgui::CustomSpinner *> *v73; // [esp+A4h] [ebp-F0h]
  float v74; // [esp+A8h] [ebp-ECh] BYREF
  float v75; // [esp+ACh] [ebp-E8h]
  float v76; // [esp+B0h] [ebp-E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v77; // [esp+B4h] [ebp-E0h] BYREF
  std::wstring result; // [esp+164h] [ebp-30h] BYREF
  int v79; // [esp+190h] [ebp-4h]

  v68 = this;
  v66 = 0;
  FormTelemetry::getValuesFromGraphics(this);
  v3 = (char *)this->graphs._Mylast - (char *)this->graphs._Myfirst;
  v4 = this->rect.bottom - this->rect.top;
  v67 = FLOAT_100_0;
  *(_DWORD *)v77.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v77.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v5 = (int)(float)((float)(v4 - 100.0) / (float)(unsigned int)(v3 / 28));
  std::wios::wios(v77.gap68);
  v79 = 0;
  v66 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v77, &v77.gap10[8], 0);
  v79 = 1;
  *(_DWORD *)&v77.gap0[*(_DWORD *)(*(_DWORD *)v77.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v76 + *(_DWORD *)(*(_DWORD *)v77.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v77.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v77.gap10[8]);
  *(_DWORD *)&v77.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v77.gap10[64] = 0;
  *(_DWORD *)&v77.gap10[68] = 0;
  v79 = 3;
  v6 = std::setprecision(&result, 2, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v6)(
    &v77.gap10[*(_DWORD *)(*(_DWORD *)v77.gap10 + 4)],
    *(_DWORD *)(v6 + 8),
    *(_DWORD *)(v6 + 12));
  std::wostream::operator<<(v77.gap10, std::fixed);
  v7 = v68;
  v8 = LODWORD(v68[1].rect.bottom);
  v9 = LODWORD(v68[1].backColor.x);
  if ( v8 != v9 )
  {
    v70 = (Concurrency::details::_Concurrent_queue_base_v4 *)&v68[1].foreColor.y;
    v76 = (float)((float)v5 - 30.0) - 5.0;
    v10 = FLOAT_100_0;
    do
    {
      ksgui::Spinner::setPosition(
        *(ksgui::Spinner **)(v8 + 4),
        (float)((float)(v7->rect.right - v7->rect.left) - 200.0) * 0.5,
        v10);
      (*(void (**)(_DWORD, int, int))(**(_DWORD **)(v8 + 4) + 28))(
        *(_DWORD *)(v8 + 4),
        1128792064,
        1106247680);
      v11 = *(float **)(v8 + 8);
      v12 = v67;
      v13 = v11[66];
      v14 = v11[8] - v11[7];
      v15 = v11[10] - v11[9];
      v11[7] = 2.0;
      v16 = v14 + 2.0;
      v17 = v15 + v12;
      v11[9] = v12;
      v11[8] = v16;
      v11[10] = v17;
      if ( v13 == 0.0 && v11[68] == 0.0 )
      {
        v11[66] = 2.0;
        v11[68] = v12;
        v11[67] = v16;
        v11[69] = v17;
      }
      (*(void (**)(_DWORD, int, int))(**(_DWORD **)(v8 + 8) + 28))(
        *(_DWORD *)(v8 + 8),
        1117782016,
        1106247680);
      v18 = *(float **)(v8 + 12);
      v19 = v67;
      v20 = v18[66];
      v21 = v18[8] - v18[7];
      v22 = (float)((float)(v68->rect.right - v68->rect.left) - 80.0) - 2.0;
      v23 = (float)(v18[10] - v18[9]) + v67;
      v18[9] = v67;
      v18[7] = v22;
      v24 = v21 + v22;
      v18[10] = v23;
      v18[8] = v24;
      if ( v20 == 0.0 && v18[68] == 0.0 )
      {
        v18[66] = v22;
        v18[68] = v19;
        v18[67] = v24;
        v18[69] = v23;
      }
      (*(void (**)(_DWORD, int, int))(**(_DWORD **)(v8 + 12) + 28))(
        *(_DWORD *)(v8 + 12),
        1117782016,
        1106247680);
      v25 = *(_DWORD *)v8;
      v26 = v67 + 35.0;
      v27 = *(float *)(*(_DWORD *)v8 + 264);
      v28 = *(float *)(*(_DWORD *)v8 + 32) - *(float *)(*(_DWORD *)v8 + 28);
      v29 = *(float *)(*(_DWORD *)v8 + 40) - *(float *)(*(_DWORD *)v8 + 36);
      *(_DWORD *)(v25 + 28) = 0x40000000;
      v30 = v28 + 2.0;
      v31 = v29 + v26;
      *(float *)(v25 + 36) = v26;
      *(float *)(v25 + 32) = v30;
      *(float *)(v25 + 40) = v31;
      if ( v27 == 0.0 && *(float *)(v25 + 272) == 0.0 )
      {
        *(_DWORD *)(v25 + 264) = 0x40000000;
        *(float *)(v25 + 272) = v26;
        *(float *)(v25 + 268) = v30;
        *(float *)(v25 + 276) = v31;
      }
      (*(void (__stdcall **)(_DWORD, float))(**(_DWORD **)v8 + 28))(
        (float)(v68->rect.right - v68->rect.left) - 4.0,
        COERCE_FLOAT(LODWORD(v76)));
      v32 = *(_DWORD *)(v8 + 16);
      v10 = (float)v5 + v67;
      v67 = v10;
      if ( v32 )
      {
        v33 = *(_DWORD *)v8;
        v34 = *(_DWORD *)(v32 + 32);
        v71 = 0;
        *(_DWORD *)(v33 + 280) = v34;
        *(_DWORD *)(*(_DWORD *)v8 + 284) = *(_DWORD *)(*(_DWORD *)(v8 + 16) + 36);
        if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(v70, &live_value) )
        {
          do
          {
            v35 = *(_DWORD *)(v8 + 16);
            if ( *(_BYTE *)(v35 + 56) )
            {
              v36 = *(float *)(v35 + 32);
              v37 = &live_value;
              v38 = (float *)(v35 + 32);
              if ( v36 <= live_value )
                v37 = v38;
              *v38 = *v37;
              v39 = &live_value;
              v40 = (float *)(*(_DWORD *)(v8 + 16) + 36);
              if ( live_value <= *v40 )
                v39 = (float *)(*(_DWORD *)(v8 + 16) + 36);
              *v40 = *v39;
            }
            v41 = *(_DWORD *)v8;
            v42 = live_value;
            v75 = live_value;
            v74 = live_value;
            if ( (*(_DWORD *)(v41 + 300) - *(_DWORD *)(v41 + 296)) >> 2 )
            {
              if ( *(_BYTE *)(v41 + 292) && live_value > *(float *)(v41 + 284) )
                *(float *)(v41 + 284) = live_value;
              v43 = (std::vector<ksgui::CustomSpinner *> *)(**(_DWORD **)(v41 + 296) + 12);
              v73 = v43;
              v44 = v43->_Mylast;
              if ( &v74 >= (float *)v44 || v43->_Myfirst > (ksgui::CustomSpinner **)&v74 )
              {
                v51 = (int)v43->_Myend;
                v72 = v51;
                if ( v44 == (ksgui::CustomSpinner **)v51 && !((v51 - (int)v44) >> 2) )
                {
                  v52 = v44 - v43->_Myfirst;
                  if ( v52 == 0x3FFFFFFF )
LABEL_75:
                    std::_Xlength_error("vector<T> too long");
                  _Count = v52 + 1;
                  v53 = (signed int)(v72 - (unsigned int)v43->_Myfirst) >> 2;
                  v66 = v53 >> 1;
                  if ( 0x3FFFFFFF - (v53 >> 1) >= v53 )
                    v54 = v66 + v53;
                  else
                    v54 = 0;
                  if ( v54 < _Count )
                    v54 = _Count;
                  std::vector<ksgui::CustomSpinner *>::_Reallocate(v43, v54);
                  v42 = v75;
                  v43 = v73;
                }
                v55 = (float *)v43->_Mylast;
                if ( v55 )
                  *v55 = v42;
              }
              else
              {
                v72 = ((char *)&v74 - (char *)v43->_Myfirst) >> 2;
                v45 = (int)v43->_Myend;
                v66 = v45;
                if ( v44 == (ksgui::CustomSpinner **)v45 && !((v45 - (int)v44) >> 2) )
                {
                  v46 = v44 - v43->_Myfirst;
                  if ( v46 == 0x3FFFFFFF )
                    goto LABEL_75;
                  _Count = v46 + 1;
                  v47 = (signed int)(v66 - (unsigned int)v43->_Myfirst) >> 2;
                  v66 = v47 >> 1;
                  if ( 0x3FFFFFFF - (v47 >> 1) >= v47 )
                    v48 = v66 + v47;
                  else
                    v48 = 0;
                  if ( v48 < _Count )
                    v48 = _Count;
                  std::vector<ksgui::CustomSpinner *>::_Reallocate(v43, v48);
                  v43 = v73;
                }
                v49 = v43->_Mylast;
                if ( v49 )
                {
                  v50 = v43->_Myfirst[v72];
                  v43 = v73;
                  *v49 = v50;
                }
              }
              ++v43->_Mylast;
              v42 = live_value;
            }
            if ( *(_BYTE *)(v8 + 24) )
              *(_BYTE *)(v8 + 24) = 0;
            else
              v42 = (float)((float)(v42 - *(float *)(v8 + 20)) * 0.003) + *(float *)(v8 + 20);
            v56 = v70;
            ++v71;
            *(float *)(v8 + 20) = v42;
          }
          while ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(v56, &live_value) );
        }
        if ( v71 )
        {
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, word_17BE9D8, 0);
          LOBYTE(v79) = 4;
          if ( (v77.gap10[68] & 1) != 0 )
            operator delete(**(void ***)&v77.gap10[20]);
          std::wstreambuf::setg(&v77.gap10[8], 0, 0, 0);
          std::wstreambuf::setp(&v77.gap10[8], 0, 0);
          v57 = &result;
          *(_DWORD *)&v77.gap10[64] = 0;
          y = *(_DWORD *)&v77.gap10[68] & 0xFFFFFFFE;
          if ( result._Myres >= 8 )
            v57 = (std::wstring *)result._Bx._Ptr;
          *(_DWORD *)&v77.gap10[68] &= 0xFFFFFFFE;
          std::wstringbuf::_Init((std::wstringbuf *)&v77.gap10[8], v57->_Bx._Buf, result._Mysize, y);
          LOBYTE(v79) = 3;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          std::wostream::operator<<(v77.gap10);
          v58 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v77, &result);
          LOBYTE(v79) = 5;
          (*(void (**)(_DWORD, std::wstring *))(**(_DWORD **)(v8 + 8) + 68))(*(_DWORD *)(v8 + 8), v58);
          LOBYTE(v79) = 3;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
        }
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, word_17BE9D8, 0);
        LOBYTE(v79) = 6;
        if ( (v77.gap10[68] & 1) != 0 )
          operator delete(**(void ***)&v77.gap10[20]);
        std::wstreambuf::setg(&v77.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v77.gap10[8], 0, 0);
        v59 = &result;
        *(_DWORD *)&v77.gap10[64] = 0;
        ya = *(_DWORD *)&v77.gap10[68] & 0xFFFFFFFE;
        if ( result._Myres >= 8 )
          v59 = (std::wstring *)result._Bx._Ptr;
        *(_DWORD *)&v77.gap10[68] &= 0xFFFFFFFE;
        std::wstringbuf::_Init((std::wstringbuf *)&v77.gap10[8], v59->_Bx._Buf, result._Mysize, ya);
        LOBYTE(v79) = 3;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        std::wostream::operator<<(v77.gap10);
        v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v77, &result);
        LOBYTE(v79) = 7;
        (*(void (**)(_DWORD, std::wstring *))(**(_DWORD **)(v8 + 12) + 68))(*(_DWORD *)(v8 + 12), v60);
        LOBYTE(v79) = 3;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v10 = v67;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
      }
      v70 = (Concurrency::details::_Concurrent_queue_base_v4 *)((char *)v70 + 20);
      v8 += 28;
      v7 = v68;
    }
    while ( v8 != v9 );
  }
  ksgui::Control::render(v7, v9, v8, dt, v63, v64);
  v79 = -1;
  *(_DWORD *)&v77.gap0[*(_DWORD *)(*(_DWORD *)v77.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v76 + *(_DWORD *)(*(_DWORD *)v77.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v77.gap0 + 4) - 104;
  *(_DWORD *)&v77.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v77.gap10[68] & 1) != 0 )
    operator delete(**(void ***)&v77.gap10[20]);
  std::wstreambuf::setg(&v77.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v77.gap10[8], 0, 0);
  *(_DWORD *)&v77.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v77.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v77.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v77.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v77.gap68);
}
void __userpurge FormTelemetry::addChannel(FormTelemetry *this@<ecx>, float a2@<xmm3>, const std::wstring *name, float *input_value, float max_value, float scale, bool isReadOnPhysicsThread, int jumpFrames)
{
  TelemetryChannelDef *v9; // eax
  TelemetryChannelDef c; // [esp+4h] [ebp-50h] BYREF
  int v11; // [esp+50h] [ebp-4h]

  c.inputLambda._Impl = 0;
  c.jumpedFrameCounter = 0;
  c.auto_range = 0;
  v11 = 0;
  c.inputValue = input_value;
  c.isReadOnPhysicsThread = isReadOnPhysicsThread;
  c.jumpFrames = jumpFrames;
  *(_QWORD *)&c.max_value = __PAIR64__(LODWORD(scale), LODWORD(max_value));
  c.min_value = a2;
  if ( max_value == 0.0 && a2 == 0.0 )
    c.auto_range = 1;
  v9 = std::map<std::wstring,TelemetryChannelDef>::operator[](&this->channels, name);
  TelemetryChannelDef::operator=(v9, &c);
  v11 = -1;
  if ( c.inputLambda._Impl )
    ((void (__stdcall *)(bool))c.inputLambda._Impl->_Delete_this)(c.inputLambda._Impl != (std::_Func_base<float> *)&c.inputLambda);
}
void __userpurge FormTelemetry::addChannelLambda(FormTelemetry *this@<ecx>, float a2@<xmm2>, float a3@<xmm3>, const std::wstring *name, float scale, bool isReadOnPhysicsThread, std::function<float __cdecl(void)> lambda)
{
  std::_Func_base<float>_vtbl *v10; // eax
  std::_Func_base<float> *v11; // eax
  TelemetryChannelDef *v12; // eax
  TelemetryChannelDef c; // [esp+14h] [ebp-54h] BYREF
  int v14; // [esp+64h] [ebp-4h]

  v14 = 1;
  c.inputValue = 0;
  c.inputLambda._Impl = 0;
  c.min_value = 0.0;
  c.max_value = 1.0;
  c.scale = 1.0;
  c.isReadOnPhysicsThread = 1;
  c.jumpFrames = 0;
  c.jumpedFrameCounter = 0;
  c.auto_range = 0;
  if ( lambda._Impl )
  {
    v10 = lambda._Impl->__vftable;
    if ( (std::function<float __cdecl(void)> *)lambda._Impl == &lambda )
      v11 = (std::_Func_base<float> *)((int (__stdcall *)(std::function<float __cdecl(void)> *))v10->_Copy)(&c.inputLambda);
    else
      v11 = (std::_Func_base<float> *)((int (__stdcall *)(_DWORD))v10->_Copy)(0);
    c.inputLambda._Impl = v11;
  }
  else
  {
    c.inputLambda._Impl = 0;
  }
  c.scale = scale;
  c.inputValue = 0;
  c.isReadOnPhysicsThread = isReadOnPhysicsThread;
  *(_QWORD *)&c.min_value = __PAIR64__(LODWORD(a3), LODWORD(a2));
  if ( a3 == 0.0 && a2 == 0.0 )
    c.auto_range = 1;
  v12 = std::map<std::wstring,TelemetryChannelDef>::operator[](&this->channels, name);
  TelemetryChannelDef::operator=(v12, &c);
  LOBYTE(v14) = 0;
  if ( c.inputLambda._Impl )
  {
    ((void (__stdcall *)(bool))c.inputLambda._Impl->_Delete_this)(c.inputLambda._Impl != (std::_Func_base<float> *)&c.inputLambda);
    c.inputLambda._Impl = 0;
  }
  v14 = -1;
  if ( lambda._Impl )
    ((void (__stdcall *)(bool))lambda._Impl->_Delete_this)(lambda._Impl != (std::_Func_base<float> *)&lambda);
}
void FormTelemetry::initChannels(FormTelemetry *this)
{
  int v2; // eax
  Car *v3; // eax
  float max_value; // xmm0_4
  FormTelemetry::initChannels::__l10::<lambda_0b45dc25b54337508d45fb2cc81cebec> *v5; // eax
  FormTelemetry::initChannels::__l11::<lambda_99e20ae7fb1672ea9e51d47f360ff173> *v6; // eax
  FormTelemetry::initChannels::__l15::<lambda_d234b025edab9d0c5b533f0a90297f61> *v7; // eax
  FormTelemetry::initChannels::__l19::<lambda_cb85c02d451b3d35cd73741e92a56ee5> *v8; // eax
  FormTelemetry::initChannels::__l23::<lambda_612f2ee5d374d6bc27fecf8107a0eb89> *v9; // eax
  FormTelemetry::initChannels::__l24::<lambda_b48c119a6d403e72303dd5cc2bbd8c27> *v10; // eax
  FormTelemetry::initChannels::__l25::<lambda_0b2ae9dff0a3fa8ac567838220b45b27> *v11; // eax
  FormTelemetry::initChannels::__l26::<lambda_8496b1724944c3ec817a6a7e2a63d90b> *v12; // eax
  FormTelemetry::initChannels::__l27::<lambda_e80cedfbc36e85d3b3b0d4f9652fc876> *v13; // eax
  FormTelemetry::initChannels::__l28::<lambda_1f4c9a27e18532bd8e175822098b55f2> *v14; // eax
  FormTelemetry::initChannels::__l29::<lambda_a370bb2d34fd94e70373d3d5991680b8> *v15; // eax
  FormTelemetry::initChannels::__l30::<lambda_52f4e36b5356405b4071f6b5c68e88fb> *v16; // eax
  FormTelemetry::initChannels::__l31::<lambda_fbe9a8a72d7f77a9ef5e3c86145af769> *v17; // eax
  FormTelemetry::initChannels::__l32::<lambda_5e519fd37e6882212bd572f891d10dc5> *v18; // eax
  FormTelemetry::initChannels::__l33::<lambda_9758e3463cfa7bab3606f45749ca7fb7> *v19; // eax
  FormTelemetry::initChannels::__l34::<lambda_96deb83e4c8b3efb0eff0d6cd1e7b913> *v20; // eax
  FormTelemetry::initChannels::__l35::<lambda_dc6ad93c02f3997160bb08300834b8a8> *v21; // eax
  FormTelemetry::initChannels::__l36::<lambda_cd89ab481931db59103e748f4c2355bc> *v22; // eax
  FormTelemetry::initChannels::__l37::<lambda_225a8ca640349735bf0d5d8178c1fd73> *v23; // eax
  FormTelemetry::initChannels::__l38::<lambda_1c590acddc90ceb5a52ccb6b8f85025f> *v24; // eax
  FormTelemetry::initChannels::__l39::<lambda_80a42ccb21c6cb2f77bbd4c29cfddfb2> *v25; // eax
  FormTelemetry::initChannels::__l40::<lambda_7640fe02043c10bc53af9e4c17c76c29> *v26; // eax
  FormTelemetry::initChannels::__l41::<lambda_2a4bdd3e5f97ff09080f4c8d0c1c555e> *v27; // eax
  FormTelemetry::initChannels::__l42::<lambda_ac733f2c7e7196312ea3e1d8a6464c84> *v28; // eax
  FormTelemetry::initChannels::__l43::<lambda_58f86a4f724d61a31dde2b7e5263ee76> *v29; // eax
  FormTelemetry::initChannels::__l44::<lambda_0947a1311c13784f22521bbdaf5b63eb> *v30; // eax
  FormTelemetry::initChannels::__l45::<lambda_2920f72b9ee18298ab81d35933b4fabb> *v31; // eax
  FormTelemetry::initChannels::__l46::<lambda_68ea35e34616ccf18f534cd4b6e72d1e> *v32; // eax
  FormTelemetry::initChannels::__l47::<lambda_26c3e7d398d580b6c8a0a78573062873> *v33; // eax
  FormTelemetry::initChannels::__l48::<lambda_34c8b836dd98b64c1a0d08b8886d306c> *v34; // eax
  FormTelemetry::initChannels::__l49::<lambda_07a5f7e914fbc95ecb795c6a0bc85708> *v35; // eax
  FormTelemetry::initChannels::__l50::<lambda_50035c619f9709a26e621b9fce45a2cb> *v36; // eax
  FormTelemetry::initChannels::__l51::<lambda_3fb9d18ea5ab16af294885637ca1c983> *v37; // eax
  std::function<float __cdecl(void)> v38; // [esp+8h] [ebp-534h] BYREF
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v39; // [esp+40h] [ebp-4FCh] BYREF
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v40; // [esp+44h] [ebp-4F8h] BYREF
  std::wstring name; // [esp+48h] [ebp-4F4h] BYREF
  std::wstring v42; // [esp+60h] [ebp-4DCh] BYREF
  std::wstring v43; // [esp+78h] [ebp-4C4h] BYREF
  std::wstring v44; // [esp+90h] [ebp-4ACh] BYREF
  std::wstring v45; // [esp+A8h] [ebp-494h] BYREF
  std::wstring v46; // [esp+C0h] [ebp-47Ch] BYREF
  std::wstring v47; // [esp+D8h] [ebp-464h] BYREF
  std::wstring v48; // [esp+F0h] [ebp-44Ch] BYREF
  std::wstring v49; // [esp+108h] [ebp-434h] BYREF
  std::wstring v50; // [esp+120h] [ebp-41Ch] BYREF
  std::wstring v51; // [esp+138h] [ebp-404h] BYREF
  std::wstring v52; // [esp+150h] [ebp-3ECh] BYREF
  std::wstring v53; // [esp+168h] [ebp-3D4h] BYREF
  std::wstring v54; // [esp+180h] [ebp-3BCh] BYREF
  std::wstring v55; // [esp+198h] [ebp-3A4h] BYREF
  std::wstring v56; // [esp+1B0h] [ebp-38Ch] BYREF
  std::wstring v57; // [esp+1C8h] [ebp-374h] BYREF
  std::wstring v58; // [esp+1E0h] [ebp-35Ch] BYREF
  std::wstring v59; // [esp+1F8h] [ebp-344h] BYREF
  std::wstring v60; // [esp+210h] [ebp-32Ch] BYREF
  std::wstring v61; // [esp+228h] [ebp-314h] BYREF
  std::wstring v62; // [esp+240h] [ebp-2FCh] BYREF
  std::wstring v63; // [esp+258h] [ebp-2E4h] BYREF
  std::wstring v64; // [esp+270h] [ebp-2CCh] BYREF
  std::wstring v65; // [esp+288h] [ebp-2B4h] BYREF
  std::wstring v66; // [esp+2A0h] [ebp-29Ch] BYREF
  std::wstring v67; // [esp+2B8h] [ebp-284h] BYREF
  std::wstring v68; // [esp+2D0h] [ebp-26Ch] BYREF
  std::wstring v69; // [esp+2E8h] [ebp-254h] BYREF
  std::wstring v70; // [esp+300h] [ebp-23Ch] BYREF
  std::wstring v71; // [esp+318h] [ebp-224h] BYREF
  std::wstring v72; // [esp+330h] [ebp-20Ch] BYREF
  std::wstring v73; // [esp+348h] [ebp-1F4h] BYREF
  std::wstring v74; // [esp+360h] [ebp-1DCh] BYREF
  std::wstring v75; // [esp+378h] [ebp-1C4h] BYREF
  std::wstring v76; // [esp+390h] [ebp-1ACh] BYREF
  std::wstring v77; // [esp+3A8h] [ebp-194h] BYREF
  std::wstring v78; // [esp+3C0h] [ebp-17Ch] BYREF
  std::wstring v79; // [esp+3D8h] [ebp-164h] BYREF
  std::wstring v80; // [esp+3F0h] [ebp-14Ch] BYREF
  std::wstring v81; // [esp+408h] [ebp-134h] BYREF
  std::wstring v82; // [esp+420h] [ebp-11Ch] BYREF
  std::wstring v83; // [esp+438h] [ebp-104h] BYREF
  std::wstring v84; // [esp+450h] [ebp-ECh] BYREF
  std::wstring v85; // [esp+468h] [ebp-D4h] BYREF
  std::wstring v86; // [esp+480h] [ebp-BCh] BYREF
  std::wstring v87; // [esp+498h] [ebp-A4h] BYREF
  std::wstring v88; // [esp+4B0h] [ebp-8Ch] BYREF
  std::wstring v89; // [esp+4C8h] [ebp-74h] BYREF
  std::wstring v90; // [esp+4E0h] [ebp-5Ch] BYREF
  std::wstring v91; // [esp+4F8h] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v92; // [esp+510h] [ebp-2Ch] BYREF
  int v93; // [esp+538h] [ebp-4h]

  if ( this->carPhysics->drivetrain.tractionType == AWD_NEW )
  {
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"AWD2_LOCK", 9u);
    v93 = 0;
    FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->drivetrain.awd2.currentLockTorque, 2000.0, 1.0, 1, 0);
    v93 = -1;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ENGINE_RPM", 0xAu);
  v93 = 3;
  v39.__this = (CarAudioFMOD *)&v38;
  v38._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_871ee79c1458db700aa20d0e1b1dfaf0_,0>,std::allocator<std::_Func_class<float,>>,float,>::`vftable';
  v38._Space._Pfn[1] = (void (__cdecl *)())this;
  v38._Impl = (std::_Func_base<float> *)&v38;
  v2 = this->carPhysics->drivetrain.acEngine.getLimiterRPM(&this->carPhysics->drivetrain.acEngine);
  LOBYTE(v93) = 1;
  FormTelemetry::addChannelLambda(this, 0.0, (float)v2 * 1.2, &name, 1.0, 1, v38);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"CLUTCH_TORQUE", 0xDu);
  v93 = 4;
  v3 = this->carPhysics;
  (&v38._Impl)[1] = 0;
  v38._Impl = (std::_Func_base<float> *)1;
  max_value = v3->drivetrain.clutchMaxTorque * 1.200000047683716;
  FormTelemetry::addChannel(
    this,
    v3->drivetrain.clutchMaxTorque * -1.200000047683716,
    &name,
    &v3->drivetrain.currentClutchTorque,
    max_value,
    1.0,
    1,
    0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"DRV_ROOT_VEL", 0xCu);
  v93 = 5;
  v38._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b645091ddd59e6974900c9db1736ab48_,0>,std::allocator<std::_Func_class<float,>>,float,>::`vftable';
  v38._Space._Pfn[1] = (void (__cdecl *)())this;
  v38._Impl = (std::_Func_base<float> *)&v38;
  FormTelemetry::addChannelLambda(this, 0.0, 2000.0, &name, 1.0, 1, v38);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"YAW_RATE", 8u);
  v93 = 7;
  FormTelemetry::addChannel(this, -1.0, &name, &this->carAvatar->physicsState.localAngularVelocity.y, 1.0, 1.0, 0, 10);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"LOAD_LF", 7u);
  v93 = 8;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[0].status.load, 1000.0, 0.10197838, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"LOAD_RF", 7u);
  v93 = 9;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[1].status.load, 1000.0, 0.10197838, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"LOAD_LR", 7u);
  v93 = 10;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[2].status.load, 1000.0, 0.10197838, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"LOAD_RR", 7u);
  v93 = 11;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[3].status.load, 1000.0, 0.10197838, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"AVEL_LF", 7u);
  v93 = 12;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[0].status.angularVelocity, 300.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"AVEL_RF", 7u);
  v93 = 13;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[1].status.angularVelocity, 300.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"AVEL_LR", 7u);
  v93 = 14;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[2].status.angularVelocity, 300.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"AVEL_RR");
  v93 = 15;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[3].status.angularVelocity, 300.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SA_LF");
  v93 = 16;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[0].status.slipAngleRAD, 20.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SA_RF");
  v93 = 17;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[1].status.slipAngleRAD, 20.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SA_LR");
  v93 = 18;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[2].status.slipAngleRAD, 20.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SA_RR");
  v93 = 19;
  FormTelemetry::addChannel(this, -20.0, &name, &this->carPhysics->tyres[3].status.slipAngleRAD, 20.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SR_LF");
  v93 = 20;
  FormTelemetry::addChannel(this, -1.0, &name, &this->carPhysics->tyres[0].status.slipRatio, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SR_RF");
  v93 = 21;
  FormTelemetry::addChannel(this, -1.0, &name, &this->carPhysics->tyres[1].status.slipRatio, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SR_LR");
  v93 = 22;
  FormTelemetry::addChannel(this, -1.0, &name, &this->carPhysics->tyres[2].status.slipRatio, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SR_RR");
  v93 = 23;
  FormTelemetry::addChannel(this, -1.0, &name, &this->carPhysics->tyres[3].status.slipRatio, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"MZ_LF");
  v93 = 24;
  FormTelemetry::addChannel(this, -150.0, &name, &this->carPhysics->tyres[0].status.Mz, 150.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"MZ_RF");
  v93 = 25;
  FormTelemetry::addChannel(this, -150.0, &name, &this->carPhysics->tyres[1].status.Mz, 150.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"MZ_LR");
  v93 = 26;
  FormTelemetry::addChannel(this, -150.0, &name, &this->carPhysics->tyres[2].status.Mz, 150.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"MZ_RR");
  v93 = 27;
  FormTelemetry::addChannel(this, -150.0, &name, &this->carPhysics->tyres[3].status.Mz, 150.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DY_LF");
  v93 = 28;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[0].status.Dy, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DY_RF");
  v93 = 29;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[1].status.Dy, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DY_LR");
  v93 = 30;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[2].status.Dy, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DY_RR");
  v93 = 31;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[3].status.Dy, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"FY_LF");
  v93 = 32;
  FormTelemetry::addChannel(this, -5000.0, &name, &this->carPhysics->tyres[0].status.Fy, 50000.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"FY_RF");
  v93 = 33;
  FormTelemetry::addChannel(this, -5000.0, &name, &this->carPhysics->tyres[1].status.Fy, 50000.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"FY_LR");
  v93 = 34;
  FormTelemetry::addChannel(this, -5000.0, &name, &this->carPhysics->tyres[2].status.Fy, 50000.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"FY_RR");
  v93 = 35;
  FormTelemetry::addChannel(this, -5000.0, &name, &this->carPhysics->tyres[3].status.Fy, 50000.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DX_LF");
  v93 = 36;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[0].status.Dx, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DX_RF");
  v93 = 37;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[1].status.Dx, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DX_LR");
  v93 = 38;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[2].status.Dx, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"DX_RR");
  v93 = 39;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[3].status.Dx, 2.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"CAMBER_DEG_LF");
  v93 = 40;
  FormTelemetry::addChannel(this, -10.0, &name, &this->carPhysics->tyres[0].status.camberRAD, 10.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"CAMBER_DEG_RF");
  v93 = 41;
  FormTelemetry::addChannel(this, -10.0, &name, &this->carPhysics->tyres[1].status.camberRAD, 10.0, -57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"CAMBER_DEG_LR");
  v93 = 42;
  FormTelemetry::addChannel(this, -10.0, &name, &this->carPhysics->tyres[2].status.camberRAD, 10.0, 57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"CAMBER_DEG_RR");
  v93 = 43;
  FormTelemetry::addChannel(this, -10.0, &name, &this->carPhysics->tyres[3].status.camberRAD, 10.0, -57.29578, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"NDSLIP_LF");
  v93 = 44;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[0].status.ndSlip, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"NDSLIP_RF");
  v93 = 45;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[1].status.ndSlip, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"NDSLIP_LR");
  v93 = 46;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[2].status.ndSlip, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"NDSLIP_RR");
  v93 = 47;
  FormTelemetry::addChannel(this, 0.0, &name, &this->carPhysics->tyres[3].status.ndSlip, 1.0, 1.0, 1, 0);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SUSTRVL_LF");
  v93 = 48;
  v38._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_da65dbe4a397dcf176f6297db8756b05_,0>,std::allocator<std::_Func_class<float,>>,float,>::`vftable';
  v38._Space._Pfn[1] = (void (__cdecl *)())this;
  v38._Impl = (std::_Func_base<float> *)&v38;
  FormTelemetry::addChannelLambda(this, -200.0, 200.0, &name, 1000.0, 1, v38);
  v93 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  std::wstring::wstring(&name, L"SUSTRVL_RF");
  v93 = 50;
  v38._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_df7d5d7028ffabd7e37afdaa507e839d_,0>,std::allocator<std::_Func_class<float,>>,float,>::`vftable';
  v38._Space._Pfn[1] = (void (__cdecl *)())this;
  v38._Impl = (std::_Func_base<float> *)&v38;
  FormTelemetry::addChannelLambda(this, -200.0, 200.0, &name, 1000.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"SUSTRVL_LR");
  v93 = 52;
  CommandItem::CommandItem(&v39, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v5);
  FormTelemetry::addChannelLambda(this, -200.0, 200.0, &name, 1000.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"SUSTRVL_RR");
  v93 = 53;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v6);
  FormTelemetry::addChannelLambda(this, -200.0, 200.0, &name, 1000.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"AI_PUSH");
  v93 = 54;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v7);
  FormTelemetry::addChannelLambda(this, 0.0, 100.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"AI_LIVE_OFFSET");
  v93 = 55;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v8);
  FormTelemetry::addChannelLambda(this, -3.0, 3.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"AI_DIST_CORNER");
  v93 = 56;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v9);
  FormTelemetry::addChannelLambda(this, 0.0, 200.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"DAMP_VEL_LF");
  v93 = 57;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v10);
  FormTelemetry::addChannelLambda(this, -1.0, 1.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"DAMP_VEL_RF");
  v93 = 58;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v11);
  FormTelemetry::addChannelLambda(this, -1.0, 1.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&name, L"DAMP_VEL_LR");
  v93 = 59;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v12);
  FormTelemetry::addChannelLambda(this, -1.0, 1.0, &name, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
  std::wstring::wstring(&v79, L"DAMP_VEL_RR");
  v93 = 60;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v13);
  FormTelemetry::addChannelLambda(this, -1.0, 1.0, &v79, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
  std::wstring::wstring(&v90, L"CORE_TEMP_LF");
  v93 = 61;
  FormTelemetry::addChannel(this, 0.0, &v90, &this->carPhysics->tyres[0].thermalModel.coreTemp, 180.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v90);
  std::wstring::wstring(&v45, L"CORE_TEMP_RF");
  v93 = 62;
  FormTelemetry::addChannel(this, 0.0, &v45, &this->carPhysics->tyres[1].thermalModel.coreTemp, 180.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v45);
  std::wstring::wstring(&v69, L"CORE_TEMP_LR");
  v93 = 63;
  FormTelemetry::addChannel(this, 0.0, &v69, &this->carPhysics->tyres[2].thermalModel.coreTemp, 180.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
  std::wstring::wstring(&v47, L"CORE_TEMP_RR");
  v93 = 64;
  FormTelemetry::addChannel(this, 0.0, &v47, &this->carPhysics->tyres[3].thermalModel.coreTemp, 180.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v47);
  std::wstring::wstring(&v81, L"AVG_SURF_TEMP_LF");
  v93 = 65;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v14);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v81, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
  std::wstring::wstring(&v49, L"AVG_SURF_TEMP_RF");
  v93 = 66;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v15);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v49, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v49);
  std::wstring::wstring(&v71, L"AVG_SURF_TEMP_LR");
  v93 = 67;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v16);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v71, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
  std::wstring::wstring(&v51, L"AVG_SURF_TEMP_RR");
  v93 = 68;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v17);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v51, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51);
  std::wstring::wstring(&v87, L"PRACT_TEMP_LF");
  v93 = 69;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v18);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v87, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
  std::wstring::wstring(&v53, L"PRACT_TEMP_RF");
  v93 = 70;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v19);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v53, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v53);
  std::wstring::wstring(&v73, L"PRACT_TEMP_LR");
  v93 = 71;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v20);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v73, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
  std::wstring::wstring(&v55, L"PRACT_TEMP_RR");
  v93 = 72;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v21);
  FormTelemetry::addChannelLambda(this, 0.0, 180.0, &v55, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v55);
  std::wstring::wstring(&v83, L"TEMP_MULT_LF");
  v93 = 73;
  FormTelemetry::addChannel(this, 0.0, &v83, &this->carPhysics->tyres[0].thermalModel.thermalMultD, 100.0, 100.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
  std::wstring::wstring(&v57, L"TEMP_MULT_RF");
  v93 = 74;
  FormTelemetry::addChannel(this, 0.0, &v57, &this->carPhysics->tyres[1].thermalModel.thermalMultD, 100.0, 100.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v57);
  std::wstring::wstring(&v75, L"TEMP_MULT_LR");
  v93 = 75;
  FormTelemetry::addChannel(this, 0.0, &v75, &this->carPhysics->tyres[2].thermalModel.thermalMultD, 100.0, 100.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
  std::wstring::wstring(&v59, L"TEMP_MULT_RR");
  v93 = 76;
  FormTelemetry::addChannel(this, 0.0, &v59, &this->carPhysics->tyres[3].thermalModel.thermalMultD, 100.0, 100.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
  std::wstring::wstring(&v91, L"BRAKE_PAD_INPUT_LF");
  v93 = 77;
  FormTelemetry::addChannel(this, 0.0, &v91, (float *)this->carPhysics->tyres, 2500.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v91);
  std::wstring::wstring(&v61, L"BRAKE_PAD_INPUT_RF");
  v93 = 78;
  FormTelemetry::addChannel(this, 0.0, &v61, &this->carPhysics->tyres[1].inputs.brakeTorque, 2500.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
  std::wstring::wstring(&v77, L"BRAKE_PAD_INPUT_LR");
  v93 = 79;
  FormTelemetry::addChannel(this, 0.0, &v77, &this->carPhysics->tyres[2].inputs.brakeTorque, 2500.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
  std::wstring::wstring(&v63, L"BRAKE_PAD_INPUT_RR");
  v93 = 80;
  FormTelemetry::addChannel(this, 0.0, &v63, &this->carPhysics->tyres[3].inputs.brakeTorque, 2500.0, 1.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
  std::wstring::wstring(&v85, L"ERS_KINETIC_REC");
  v93 = 81;
  FormTelemetry::addChannel(this, 0.0, &v85, &this->carPhysics->ers.status.kineticRecovery, 100.0, 1000.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v85);
  std::wstring::wstring(&v65, L"ERS_HEAT_REC");
  v93 = 82;
  FormTelemetry::addChannel(this, 0.0, &v65, &this->carPhysics->ers.status.heatRecovery, 100.0, 1000.0, 1, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v65);
  std::wstring::wstring(&v43, L"ERS_CHARGE");
  v93 = 83;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v22);
  FormTelemetry::addChannelLambda(this, 0.0, 100.0, &v43, 100.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
  std::wstring::wstring(&v67, L"ERS_TORQUE");
  v93 = 84;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v23);
  FormTelemetry::addChannelLambda(this, 0.0, 200.0, &v67, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
  std::wstring::wstring(&v89, L"AVG_REAR_TRAVEL");
  v93 = 85;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v24);
  FormTelemetry::addChannelLambda(this, -200.0, 200.0, &v89, 1000.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v89);
  std::wstring::wstring(&v44, L"OVERSTEER_FACTOR");
  v93 = 86;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v25);
  FormTelemetry::addChannelLambda(this, -5.0, 5.0, &v44, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
  std::wstring::wstring(&v46, L"STEER_DEG_LF");
  v93 = 87;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v26);
  FormTelemetry::addChannelLambda(this, -30.0, 20.0, &v46, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v46);
  std::wstring::wstring(&v48, L"STEER_DEG_RF");
  v93 = 88;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v27);
  FormTelemetry::addChannelLambda(this, -30.0, 20.0, &v48, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v48);
  std::wstring::wstring(&v50, L"STEER_DEG_LR");
  v93 = 89;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v28);
  FormTelemetry::addChannelLambda(this, -30.0, 20.0, &v50, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v50);
  std::wstring::wstring(&v52, L"STEER_DEG_RR");
  v93 = 90;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v29);
  FormTelemetry::addChannelLambda(this, -30.0, 20.0, &v52, 1.0, 1, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v52);
  std::wstring::wstring(&v54, L"SKID_VOL_LF");
  v93 = 91;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v30);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v54, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v54);
  std::wstring::wstring(&v56, L"SKID_VOL_RF");
  v93 = 92;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v31);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v56, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
  std::wstring::wstring(&v58, L"SKID_VOL_LR");
  v93 = 93;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v32);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v58, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v58);
  std::wstring::wstring(&v60, L"SKID_VOL_RR");
  v93 = 94;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v33);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v60, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v60);
  std::wstring::wstring(&v62, L"SKID_PITCH_LF");
  v93 = 95;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v34);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v62, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
  std::wstring::wstring(&v64, L"SKID_PITCH_RF");
  v93 = 96;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v35);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v64, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
  std::wstring::wstring(&v66, L"SKID_PITCH_LR");
  v93 = 97;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v36);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v66, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
  std::wstring::wstring(&v68, L"SKID_PITCH_RR");
  v93 = 98;
  CommandItem::CommandItem(&v40, (CarAudioFMOD *)this);
  std::function<float __cdecl (void)>::function<float __cdecl (void)>(&v38, v37);
  FormTelemetry::addChannelLambda(this, 0.0, 1.0, &v68, 1.0, 0, v38);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
  std::wstring::wstring(&v70, L"BRAKE_DISC_T_LF");
  v93 = 99;
  FormTelemetry::addChannel(this, 0.0, &v70, (float *)this->carPhysics->brakeSystem.discs, 1000.0, 1.0, 1, 10);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
  std::wstring::wstring(&v72, L"BRAKE_DISC_T_RF");
  v93 = 100;
  FormTelemetry::addChannel(this, 0.0, &v72, &this->carPhysics->brakeSystem.discs[1].t, 1000.0, 1.0, 1, 10);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
  std::wstring::wstring(&v74, L"BRAKE_DISC_T_LR");
  v93 = 101;
  FormTelemetry::addChannel(this, 0.0, &v74, &this->carPhysics->brakeSystem.discs[2].t, 1000.0, 1.0, 1, 10);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
  std::wstring::wstring(&v76, L"BRAKE_DISC_T_RR");
  v93 = 102;
  FormTelemetry::addChannel(this, 0.0, &v76, &this->carPhysics->brakeSystem.discs[3].t, 1000.0, 1.0, 1, 10);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
  std::wstring::wstring(&v78, L"FF_PURE");
  v93 = 103;
  FormTelemetry::addChannel(this, -1.0, &v78, &this->carAvatar->physicsState.lastFF_Pure, 1.0, 1.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
  std::wstring::wstring(&v80, L"FF_FINAL");
  v93 = 104;
  FormTelemetry::addChannel(this, -1.0, &v80, &this->carAvatar->physicsState.lastFF_Final, 1.0, 1.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
  std::wstring::wstring(&v82, L"WATER_TEMP");
  v93 = 105;
  FormTelemetry::addChannel(this, 0.0, &v82, &this->carAvatar->physicsState.water, 150.0, 1.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
  std::wstring::wstring(&v84, L"RIDE_HEIGHT_F");
  v93 = 106;
  FormTelemetry::addChannel(this, 0.0, &v84, this->carAvatar->physicsState.rideHeight, 200.0, 1000.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
  std::wstring::wstring(&v86, L"RIDE_HEIGHT_R");
  v93 = 107;
  FormTelemetry::addChannel(this, 0.0, &v86, &this->carAvatar->physicsState.rideHeight[1], 200.0, 1000.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v86);
  std::wstring::wstring(&v88, L"ACC_LAT");
  v93 = 108;
  FormTelemetry::addChannel(this, -4.0, &v88, &this->carAvatar->physicsState.accG.x, 4.0, 1.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v88);
  std::wstring::wstring(&v42, L"ACC_LON");
  v93 = 109;
  FormTelemetry::addChannel(this, -5.0, &v42, &this->carAvatar->physicsState.accG.z, 2.0, 1.0, 0, 0);
  v93 = -1;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v42);
  if ( DynamicController::isReady(&this->carPhysics->antirollBars[0].ctrl) )
  {
    std::wstring::wstring(&v42, L"ARB_FRONT");
    v93 = 110;
    FormTelemetry::addChannel(this, 0.0, &v42, &this->carPhysics->antirollBars[0].k, 0.0, 1.0, 1, 0);
    v93 = -1;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v42);
  }
  if ( DynamicController::isReady(&this->carPhysics->antirollBars[1].ctrl) )
  {
    std::wstring::wstring(&v92.name, L"ARB_REAR");
    v93 = 111;
    FormTelemetry::addChannel(this, 0.0, &v92.name, &this->carPhysics->antirollBars[1].k, 0.0, 1.0, 1, 0);
    std::wstring::~wstring(&v92);
  }
}
void FormTelemetry::applyPreset(FormTelemetry *this, const std::wstring *preset_name)
{
  TelemetryPreset *v2; // edi
  TelemetryPreset *v3; // esi
  const std::wstring *v4; // eax
  const std::wstring *v5; // ebp
  int j; // ebx
  TelemetryPreset *i; // [esp+Ch] [ebp-4h]

  v2 = this->presets._Mylast;
  v3 = this->presets._Myfirst;
  for ( i = v2; v3 != v2; ++v3 )
  {
    v4 = preset_name;
    if ( preset_name->_Myres >= 8 )
      v4 = (const std::wstring *)preset_name->_Bx._Ptr;
    if ( !std::wstring::compare(&v3->name, 0, v3->name._Mysize, v4->_Bx._Buf, preset_name->_Mysize) )
    {
      v5 = v3->channels;
      for ( j = 0; j < 4; ++j )
        ksgui::Spinner::setValue(this->graphs._Myfirst[j].spinner, v5++);
      v2 = i;
    }
  }
}
void FormTelemetry::getValuesFromPhysics(FormTelemetry *this)
{
  TelemetryGraph *v1; // esi
  TelemetryGraph *v2; // edi
  BufferedChannel<float> *v3; // ebx
  TelemetryChannelDef *v4; // ecx
  int v5; // eax
  TelemetryChannelDef *v6; // eax
  std::_Func_base<float> *v7; // ecx
  double v8; // st7
  TelemetryChannelDef *v9; // eax
  float v10; // [esp+8h] [ebp-Ch] BYREF
  float v11; // [esp+Ch] [ebp-8h]
  float v12; // [esp+10h] [ebp-4h] BYREF

  v1 = this->graphs._Myfirst;
  v2 = this->graphs._Mylast;
  if ( v1 != v2 )
  {
    v3 = this->liveValuesChannels;
    do
    {
      v4 = v1->channel;
      if ( v4->isReadOnPhysicsThread )
      {
        v5 = v4->jumpedFrameCounter;
        if ( v5 < v4->jumpFrames )
        {
          v4->jumpedFrameCounter = v5 + 1;
        }
        else
        {
          if ( v4->inputValue )
          {
            v10 = v4->scale * *v4->inputValue;
            Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&v3->queue, &v10);
          }
          v6 = v1->channel;
          if ( v6->inputLambda._Impl )
          {
            v7 = v6->inputLambda._Impl;
            if ( !v7 )
            {
              std::_Xbad_function_call();
              JUMPOUT(0x4CFF2A);
            }
            v8 = ((double (*)(std::_Func_base<float> *))v7->_Do_call)(v7);
            v9 = v1->channel;
            v11 = v8;
            v12 = v9->scale * v11;
            Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&v3->queue, &v12);
          }
          v1->channel->jumpedFrameCounter = 0;
        }
      }
      ++v1;
      ++v3;
    }
    while ( v1 != v2 );
  }
}
void FormTelemetry::getValuesFromGraphics(FormTelemetry *this)
{
  TelemetryGraph *v1; // esi
  TelemetryGraph *v2; // edi
  BufferedChannel<float> *v3; // ebx
  TelemetryChannelDef *v4; // eax
  TelemetryChannelDef *v5; // eax
  std::_Func_base<float> *v6; // ecx
  double v7; // st7
  TelemetryChannelDef *v8; // eax
  float v9; // [esp+8h] [ebp-Ch] BYREF
  float v10; // [esp+Ch] [ebp-8h]
  float v11; // [esp+10h] [ebp-4h] BYREF

  v1 = this->graphs._Myfirst;
  v2 = this->graphs._Mylast;
  if ( v1 != v2 )
  {
    v3 = this->liveValuesChannels;
    do
    {
      v4 = v1->channel;
      if ( !v4->isReadOnPhysicsThread )
      {
        if ( v4->inputValue )
        {
          v9 = v4->scale * *v4->inputValue;
          Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&v3->queue, &v9);
        }
        v5 = v1->channel;
        if ( v5->inputLambda._Impl )
        {
          v6 = v5->inputLambda._Impl;
          if ( !v6 )
          {
            std::_Xbad_function_call();
            JUMPOUT(0x4CFFCA);
          }
          v7 = ((double (*)(std::_Func_base<float> *))v6->_Do_call)(v6);
          v8 = v1->channel;
          v10 = v7;
          v11 = v8->scale * v10;
          Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&v3->queue, &v11);
        }
      }
      ++v1;
      ++v3;
    }
    while ( v1 != v2 );
  }
}
