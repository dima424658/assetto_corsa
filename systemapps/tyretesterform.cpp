#include "tyretesterform.h
void TyreTesterForm::TyreTesterForm(TyreTesterForm *this, CarAvatar *acar, ksgui::GUI *agui)
{
  int v4; // ebx
  const std::wstring *v5; // eax
  void (__cdecl *v6)(void *); // eax
  void *(__cdecl *v7)(unsigned int); // ebp
  ksgui::Spinner *v8; // esi
  ksgui::Graph *v9; // eax
  int v10; // esi
  TyreTester *v11; // ebp
  std::wstring *v12; // eax
  int v13; // ebx
  const std::wstring *v14; // eax
  ksgui::Spinner_vtbl *v15; // eax
  ksgui::Spinner *v16; // ebp
  ksgui::Graph *v17; // esi
  _DWORD *v18; // eax
  unsigned int v19; // ebp
  unsigned int *v20; // ecx
  int v21; // eax
  std::vector<ksgui::CustomSpinner *> *v22; // esi
  ksgui::CustomSpinner **v23; // eax
  int v24; // ebp
  ksgui::CustomSpinner **v25; // ecx
  _DWORD *v26; // eax
  ksgui::Graph *v27; // esi
  _DWORD *v28; // eax
  unsigned int v29; // ebp
  unsigned int *v30; // ecx
  int v31; // eax
  std::vector<ksgui::CustomSpinner *> *v32; // esi
  ksgui::CustomSpinner **v33; // eax
  int v34; // ebp
  ksgui::CustomSpinner **v35; // ecx
  _DWORD *v36; // eax
  ksgui::Graph *v37; // esi
  _DWORD *v38; // eax
  unsigned int v39; // ebp
  unsigned int *v40; // ecx
  int v41; // eax
  std::vector<ksgui::CustomSpinner *> *v42; // esi
  ksgui::CustomSpinner **v43; // eax
  int v44; // ebp
  ksgui::CustomSpinner **v45; // ecx
  _DWORD *v46; // eax
  ksgui::Graph *v47; // esi
  _DWORD *v48; // eax
  unsigned int v49; // ebp
  unsigned int *v50; // ecx
  int v51; // eax
  std::vector<ksgui::CustomSpinner *> *v52; // esi
  ksgui::CustomSpinner **v53; // eax
  int v54; // ebp
  ksgui::CustomSpinner **v55; // ecx
  _DWORD *v56; // eax
  ksgui::Graph *v57; // esi
  _DWORD *v58; // eax
  unsigned int v59; // ebp
  unsigned int *v60; // ecx
  int v61; // eax
  std::vector<ksgui::CustomSpinner *> *v62; // esi
  ksgui::CustomSpinner **v63; // eax
  int v64; // ebp
  ksgui::CustomSpinner **v65; // ecx
  _DWORD *v66; // eax
  ksgui::Graph *v67; // esi
  _DWORD *v68; // eax
  unsigned int v69; // ebp
  unsigned int *v70; // ecx
  int v71; // eax
  std::vector<ksgui::CustomSpinner *> *v72; // esi
  ksgui::CustomSpinner **v73; // eax
  int v74; // ebp
  ksgui::CustomSpinner **v75; // ecx
  _DWORD *v76; // eax
  ksgui::Graph *v77; // ecx
  float v78; // xmm0_4
  float v79; // xmm1_4
  float v80; // xmm2_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  __m128 v83; // xmm0
  ksgui::Graph *v84; // eax
  ksgui::Graph *v85; // eax
  ksgui::Graph *v86; // ecx
  __m128 v87; // xmm0
  ksgui::Graph *v88; // ecx
  ksgui::Spinner *v89; // edx
  std::vector<ksgui::Control *> *v90; // esi
  ksgui::Control **v91; // ecx
  int v92; // ebp
  ksgui::Control **v93; // ecx
  ksgui::Control **v94; // eax
  ksgui::Label *v95; // ebp
  ksgui::Label *v96; // eax
  ksgui::Label *v97; // ecx
  float v98; // xmm0_4
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm1_4
  float v102; // xmm2_4
  ksgui::Label *v103; // edx
  ksgui::Control **v104; // ecx
  int v105; // eax
  ksgui::Control **v106; // ecx
  ksgui::Control **v107; // eax
  int v108; // ebx
  const std::wstring *v109; // eax
  ksgui::Spinner *v110; // eax
  ksgui::Control **v111; // eax
  ksgui::Spinner *v112; // ebp
  int v113; // ebx
  ksgui::Control **v114; // eax
  ksgui::Control **v115; // eax
  _BYTE v116[28]; // [esp-4h] [ebp-B0h] BYREF
  float h; // [esp+18h] [ebp-94h]
  ksgui::Spinner *v118; // [esp+30h] [ebp-7Ch]
  __m128i v119; // [esp+34h] [ebp-78h] BYREF
  ksgui::Spinner *v120; // [esp+44h] [ebp-68h] BYREF
  ksgui::Spinner *v121; // [esp+48h] [ebp-64h] BYREF
  unsigned int v122; // [esp+4Ch] [ebp-60h] BYREF
  unsigned int v123; // [esp+50h] [ebp-5Ch] BYREF
  unsigned int v124; // [esp+54h] [ebp-58h] BYREF
  unsigned int v125; // [esp+58h] [ebp-54h] BYREF
  unsigned int _Count; // [esp+5Ch] [ebp-50h] BYREF
  unsigned int v127[2]; // [esp+60h] [ebp-4Ch] BYREF
  TyreTesterForm *v128; // [esp+68h] [ebp-44h]
  std::wstring text; // [esp+6Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+84h] [ebp-28h] BYREF
  int v131; // [esp+A8h] [ebp-4h]

  v4 = 0;
  v128 = this;
  h = 0.0;
  *(_DWORD *)&v116[24] = agui;
  v119.m128i_i32[3] = 0;
  *(_DWORD *)&v116[20] = 7;
  *(_DWORD *)&v116[16] = 0;
  *(_WORD *)v116 = 0;
  std::wstring::assign((std::wstring *)v116, L"TYRE_TESTER", 0xBu);
  ksgui::Form::Form(this, 0, *(std::wstring *)v116, *(ksgui::GUI **)&v116[24], SLOBYTE(h));
  v131 = 0;
  LODWORD(h) = 11;
  this->__vftable = (TyreTesterForm_vtbl *)&TyreTesterForm::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre tester", LODWORD(h));
  LOBYTE(v131) = 1;
  v5 = acTranslate(&result, &text);
  LOBYTE(v131) = 2;
  this->formTitle->setText(this->formTitle, v5);
  v6 = operator delete;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v6 = operator delete;
  }
  result._Myres = 7;
  LOBYTE(v131) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v6(text._Bx._Ptr);
  this->car = acar;
  ksgui::Form::setSize(this, 560.0, 560.0);
  v7 = operator new;
  v8 = (ksgui::Spinner *)operator new(0x140u);
  v118 = v8;
  v9 = 0;
  LOBYTE(v131) = 3;
  if ( v8 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v116[24] = 7;
    *(_DWORD *)&v116[20] = 0;
    *(_WORD *)&v116[4] = 0;
    std::wstring::assign((std::wstring *)&v116[4], L"SLIPGRAPH", 9u);
    ksgui::Graph::Graph((ksgui::Graph *)v8, *(std::wstring *)&v116[4], (ksgui::GUI *)LODWORD(h));
  }
  LOBYTE(v131) = 0;
  v10 = 0;
  this->graph = v9;
  v118 = (ksgui::Spinner *)this->tester;
  do
  {
    v11 = (TyreTester *)v7(0x108u);
    v119.m128i_i32[0] = (int)v11;
    LOBYTE(v131) = 4;
    if ( v11 )
    {
      v12 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
      LOBYTE(v131) = 5;
      v13 = v4 | 1;
      v119.m128i_i32[3] = v13;
      v14 = std::operator+<wchar_t>(&text, v12, L"/data/");
      v4 = v13 | 2;
      v131 = 6;
      v119.m128i_i32[3] = v4;
      TyreTester::TyreTester(v11, v14, v10);
    }
    else
    {
      v15 = 0;
    }
    v16 = v118;
    v118->__vftable = v15;
    if ( (v4 & 2) != 0 )
    {
      v4 &= 0xFFFFFFFD;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
    }
    v131 = 0;
    if ( (v4 & 1) != 0 )
    {
      v4 &= 0xFFFFFFFE;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    ++v10;
    v118 = (ksgui::Spinner *)&v16->name;
    v7 = operator new;
  }
  while ( v10 < 4 );
  v17 = this->graph;
  v119.m128i_i64[0] = 0x3F8000003F800000i64;
  v119.m128i_i32[2] = 1065353216;
  v18 = operator new(0x18u);
  v19 = (unsigned int)v18;
  if ( v18 )
  {
    *v18 = 0;
    v18[1] = 0;
    v18[2] = 0;
    v18[3] = 0;
    v18[4] = 0;
    v18[5] = 0;
  }
  else
  {
    v19 = 0;
  }
  v20 = &_Count;
  v21 = v119.m128i_i32[2];
  v22 = (std::vector<ksgui::CustomSpinner *> *)&v17->series;
  *(_QWORD *)v19 = v119.m128i_i64[0];
  *(_DWORD *)(v19 + 8) = v21;
  _Count = v19;
  v23 = v22->_Mylast;
  if ( &_Count >= (unsigned int *)v23
    || (v20 = (unsigned int *)v22->_Myfirst, v22->_Myfirst > (ksgui::CustomSpinner **)&_Count) )
  {
    if ( v23 == v22->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v22, (unsigned int)v20);
    v26 = v22->_Mylast;
    if ( v26 )
      *v26 = v19;
  }
  else
  {
    v24 = &_Count - v20;
    if ( v23 == v22->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v22, (unsigned int)v22->_Myfirst);
    v25 = v22->_Mylast;
    if ( v25 )
      *v25 = v22->_Myfirst[v24];
  }
  ++v22->_Mylast;
  v27 = this->graph;
  v119.m128i_i64[0] = 1065353216i64;
  v119.m128i_i32[2] = 1065353216;
  v28 = operator new(0x18u);
  v29 = (unsigned int)v28;
  if ( v28 )
  {
    *v28 = 0;
    v28[1] = 0;
    v28[2] = 0;
    v28[3] = 0;
    v28[4] = 0;
    v28[5] = 0;
  }
  else
  {
    v29 = 0;
  }
  v30 = &v123;
  v31 = v119.m128i_i32[2];
  v32 = (std::vector<ksgui::CustomSpinner *> *)&v27->series;
  *(_QWORD *)v29 = v119.m128i_i64[0];
  *(_DWORD *)(v29 + 8) = v31;
  v123 = v29;
  v33 = v32->_Mylast;
  if ( &v123 >= (unsigned int *)v33
    || (v30 = (unsigned int *)v32->_Myfirst, v32->_Myfirst > (ksgui::CustomSpinner **)&v123) )
  {
    if ( v33 == v32->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v32, (unsigned int)v30);
    v36 = v32->_Mylast;
    if ( v36 )
      *v36 = v29;
  }
  else
  {
    v34 = &v123 - v30;
    if ( v33 == v32->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v32, (unsigned int)v32->_Myfirst);
    v35 = v32->_Mylast;
    if ( v35 )
      *v35 = v32->_Myfirst[v34];
  }
  ++v32->_Mylast;
  v37 = this->graph;
  v119.m128i_i64[0] = 0x3F80000000000000i64;
  v119.m128i_i32[2] = 0;
  v38 = operator new(0x18u);
  v39 = (unsigned int)v38;
  if ( v38 )
  {
    *v38 = 0;
    v38[1] = 0;
    v38[2] = 0;
    v38[3] = 0;
    v38[4] = 0;
    v38[5] = 0;
  }
  else
  {
    v39 = 0;
  }
  v40 = v127;
  v41 = v119.m128i_i32[2];
  v42 = (std::vector<ksgui::CustomSpinner *> *)&v37->series;
  *(_QWORD *)v39 = v119.m128i_i64[0];
  *(_DWORD *)(v39 + 8) = v41;
  v127[0] = v39;
  v43 = v42->_Mylast;
  if ( v127 >= (unsigned int *)v43
    || (v40 = (unsigned int *)v42->_Myfirst, v42->_Myfirst > (ksgui::CustomSpinner **)v127) )
  {
    if ( v43 == v42->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v42, (unsigned int)v40);
    v46 = v42->_Mylast;
    if ( v46 )
      *v46 = v39;
  }
  else
  {
    v44 = v127 - v40;
    if ( v43 == v42->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v42, (unsigned int)v42->_Myfirst);
    v45 = v42->_Mylast;
    if ( v45 )
      *v45 = v42->_Myfirst[v44];
  }
  ++v42->_Mylast;
  v47 = this->graph;
  v119.m128i_i64[0] = 0x3F8000003F800000i64;
  v119.m128i_i32[2] = 0;
  v48 = operator new(0x18u);
  v49 = (unsigned int)v48;
  if ( v48 )
  {
    *v48 = 0;
    v48[1] = 0;
    v48[2] = 0;
    v48[3] = 0;
    v48[4] = 0;
    v48[5] = 0;
  }
  else
  {
    v49 = 0;
  }
  v50 = &v122;
  v51 = v119.m128i_i32[2];
  v52 = (std::vector<ksgui::CustomSpinner *> *)&v47->series;
  *(_QWORD *)v49 = v119.m128i_i64[0];
  *(_DWORD *)(v49 + 8) = v51;
  v122 = v49;
  v53 = v52->_Mylast;
  if ( &v122 >= (unsigned int *)v53
    || (v50 = (unsigned int *)v52->_Myfirst, v52->_Myfirst > (ksgui::CustomSpinner **)&v122) )
  {
    if ( v53 == v52->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v52, (unsigned int)v50);
    v56 = v52->_Mylast;
    if ( v56 )
      *v56 = v49;
  }
  else
  {
    v54 = &v122 - v50;
    if ( v53 == v52->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v52, (unsigned int)v52->_Myfirst);
    v55 = v52->_Mylast;
    if ( v55 )
      *v55 = v52->_Myfirst[v54];
  }
  ++v52->_Mylast;
  v57 = this->graph;
  v119.m128i_i64[0] = 0x3F80000000000000i64;
  v119.m128i_i32[2] = 1065353216;
  v58 = operator new(0x18u);
  v59 = (unsigned int)v58;
  if ( v58 )
  {
    *v58 = 0;
    v58[1] = 0;
    v58[2] = 0;
    v58[3] = 0;
    v58[4] = 0;
    v58[5] = 0;
  }
  else
  {
    v59 = 0;
  }
  v60 = &v125;
  v61 = v119.m128i_i32[2];
  v62 = (std::vector<ksgui::CustomSpinner *> *)&v57->series;
  *(_QWORD *)v59 = v119.m128i_i64[0];
  *(_DWORD *)(v59 + 8) = v61;
  v125 = v59;
  v63 = v62->_Mylast;
  if ( &v125 >= (unsigned int *)v63
    || (v60 = (unsigned int *)v62->_Myfirst, v62->_Myfirst > (ksgui::CustomSpinner **)&v125) )
  {
    if ( v63 == v62->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v62, (unsigned int)v60);
    v66 = v62->_Mylast;
    if ( v66 )
      *v66 = v59;
  }
  else
  {
    v64 = &v125 - v60;
    if ( v63 == v62->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v62, (unsigned int)v62->_Myfirst);
    v65 = v62->_Mylast;
    if ( v65 )
      *v65 = v62->_Myfirst[v64];
  }
  ++v62->_Mylast;
  v67 = this->graph;
  v119.m128i_i64[0] = 0x3F0000003F800000i64;
  v119.m128i_i32[2] = 1056964608;
  v68 = operator new(0x18u);
  v69 = (unsigned int)v68;
  if ( v68 )
  {
    *v68 = 0;
    v68[1] = 0;
    v68[2] = 0;
    v68[3] = 0;
    v68[4] = 0;
    v68[5] = 0;
  }
  else
  {
    v69 = 0;
  }
  v70 = &v124;
  v71 = v119.m128i_i32[2];
  v72 = (std::vector<ksgui::CustomSpinner *> *)&v67->series;
  *(_QWORD *)v69 = v119.m128i_i64[0];
  *(_DWORD *)(v69 + 8) = v71;
  v124 = v69;
  v73 = v72->_Mylast;
  if ( &v124 >= (unsigned int *)v73
    || (v70 = (unsigned int *)v72->_Myfirst, v72->_Myfirst > (ksgui::CustomSpinner **)&v124) )
  {
    if ( v73 == v72->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v72, (unsigned int)v70);
    v76 = v72->_Mylast;
    if ( v76 )
      *v76 = v69;
  }
  else
  {
    v74 = &v124 - v70;
    if ( v73 == v72->_Myend )
      std::vector<ksgui::CustomSpinner *>::_Reserve(v72, (unsigned int)v72->_Myfirst);
    v75 = v72->_Mylast;
    if ( v75 )
      *v75 = v72->_Myfirst[v74];
  }
  ++v72->_Mylast;
  v77 = this->graph;
  v78 = v77->rectBase.left;
  v79 = v77->rect.right - v77->rect.left;
  v80 = v77->rect.bottom - v77->rect.top;
  v77->rect.top = 30.0;
  v77->rect.left = 30.0;
  v81 = v79 + 30.0;
  v82 = v80 + 30.0;
  v77->rect.right = v81;
  v77->rect.bottom = v82;
  if ( v78 == 0.0 && v77->rectBase.top == 0.0 )
  {
    v77->rectBase.left = 30.0;
    v77->rectBase.top = 30.0;
    v77->rectBase.right = v81;
    v77->rectBase.bottom = v82;
  }
  v83 = ((__m128 (*)(ksgui::Graph *, int, int))this->graph->setSize)(this->graph, 1140457472, 1140457472);
  v84 = this->graph;
  *(_DWORD *)&result._Bx._Alias[8] = 1045220557;
  v83.m128_f32[0] = 0.2;
  v84->maxY = 2.5;
  v85 = this->graph;
  v119.m128i_i64[0] = LODWORD(FLOAT_0_2);
  *(_QWORD *)text._Bx._Buf = _mm_unpacklo_ps(v83, (__m128)LODWORD(FLOAT_0_2)).m128_u64[0];
  *(_DWORD *)&text._Bx._Alias[12] = 1056964608;
  v85->minY = -2.5;
  v86 = this->graph;
  *(_DWORD *)&text._Bx._Alias[8] = *(_DWORD *)&result._Bx._Alias[8];
  LOBYTE(text._Mysize) = 1;
  std::vector<ksgui::GraphReferenceAxis>::push_back(&v86->axes, (const ksgui::GraphReferenceAxis *)&text);
  v87 = (__m128)_mm_loadl_epi64(&v119);
  v88 = this->graph;
  *(_DWORD *)&result._Bx._Alias[8] = 1045220557;
  *(_QWORD *)&text._Bx._Alias[8] = 0x3F0000003E4CCCCDi64;
  *(_QWORD *)text._Bx._Buf = _mm_unpacklo_ps(v87, v87).m128_u64[0];
  LOBYTE(text._Mysize) = 0;
  std::vector<ksgui::GraphReferenceAxis>::push_back(&v88->axes, (const ksgui::GraphReferenceAxis *)&text);
  v89 = (ksgui::Spinner *)this->graph;
  v90 = &this->controls;
  v91 = this->controls._Mylast;
  v118 = v89;
  v120 = v89;
  if ( &v120 >= v91 || v90->_Myfirst > &v120 )
  {
    if ( v91 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v89 = v118;
    }
    v94 = this->controls._Mylast;
    if ( v94 )
      *v94 = v89;
  }
  else
  {
    v92 = &v120 - (ksgui::Spinner **)v90->_Myfirst;
    if ( v91 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v89 = v118;
    }
    v93 = this->controls._Mylast;
    if ( v93 )
      *v93 = v90->_Myfirst[v92];
  }
  ++this->controls._Mylast;
  LODWORD(h) = 284;
  v89->parent = this;
  v95 = (ksgui::Label *)operator new(LODWORD(h));
  v119.m128i_i32[0] = (int)v95;
  v96 = 0;
  LOBYTE(v131) = 9;
  if ( v95 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DATA", 4u);
    LOBYTE(v131) = 10;
    h = *(float *)&this->gui;
    v4 |= 4u;
    v119.m128i_i32[3] = v4;
    acTranslate((std::wstring *)&v116[4], &text);
    ksgui::Label::Label(v95, *(std::wstring *)&v116[4], (ksgui::GUI *)LODWORD(h));
  }
  v131 = 0;
  this->label1 = v96;
  if ( (v4 & 4) != 0 )
  {
    v4 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v97 = this->label1;
  v98 = v97->rectBase.left;
  v99 = v97->rect.right - v97->rect.left;
  v100 = v97->rect.bottom - v97->rect.top;
  v97->rect.top = 550.0;
  v97->rect.left = 10.0;
  v101 = v99 + 10.0;
  v102 = v100 + 550.0;
  v97->rect.right = v101;
  v97->rect.bottom = v102;
  if ( v98 == 0.0 && v97->rectBase.top == 0.0 )
  {
    v97->rectBase.left = 10.0;
    v97->rectBase.top = 550.0;
    v97->rectBase.right = v101;
    v97->rectBase.bottom = v102;
  }
  ((void (*)(ksgui::Label *, int, int))this->label1->setSize)(this->label1, 1140457472, 1101004800);
  v103 = this->label1;
  v104 = this->controls._Mylast;
  v119.m128i_i32[3] = (int)v103;
  v127[1] = (unsigned int)v103;
  if ( &v127[1] >= (unsigned int *)v104 || v90->_Myfirst > (ksgui::Control **)&v127[1] )
  {
    if ( v104 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v103 = (ksgui::Label *)v119.m128i_i32[3];
    }
    v107 = this->controls._Mylast;
    if ( v107 )
      *v107 = v103;
  }
  else
  {
    v105 = ((char *)&v127[1] - (char *)v90->_Myfirst) >> 2;
    v118 = (ksgui::Spinner *)v105;
    if ( v104 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v105 = (int)v118;
      v103 = (ksgui::Label *)v119.m128i_i32[3];
    }
    v106 = this->controls._Mylast;
    if ( v106 )
    {
      v103 = (ksgui::Label *)v119.m128i_i32[3];
      *v106 = v90->_Myfirst[v105];
    }
  }
  ++this->controls._Mylast;
  LODWORD(h) = 444;
  v103->parent = this;
  v118 = (ksgui::Spinner *)operator new(LODWORD(h));
  LOBYTE(v131) = 12;
  if ( v118 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SPINNER_TYRE", 0xCu);
    LOBYTE(v131) = 13;
    v108 = v4 | 8;
    v119.m128i_i32[3] = v108;
    v109 = acTranslate(&result, &text);
    h = 0.0;
    v131 = 14;
    v4 = v108 | 0x10;
    *(_DWORD *)&v116[24] = 0;
    *(_DWORD *)&v116[20] = this->gui;
    v119.m128i_i32[3] = v4;
    ksgui::Spinner::Spinner(v118, v109, *(ksgui::GUI **)&v116[20], 0, 0);
  }
  else
  {
    v110 = 0;
  }
  this->spTyre = v110;
  if ( (v4 & 0x10) != 0 )
  {
    LOBYTE(v4) = v4 & 0xEF;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v131 = 0;
  if ( (v4 & 8) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Spinner::setPosition(this->spTyre, 250.0, 10.0);
  ((void (*)(ksgui::Spinner *, int, int))this->spTyre->setSize)(this->spTyre, 1120403456, 1106247680);
  this->spTyre->minValue = 0;
  this->spTyre->maxValue = 3;
  v111 = this->controls._Mylast;
  v112 = this->spTyre;
  v121 = v112;
  if ( &v121 >= v111 || v90->_Myfirst > &v121 )
  {
    if ( v111 == this->controls._Myend )
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
    v115 = this->controls._Mylast;
    if ( v115 )
      *v115 = v112;
  }
  else
  {
    v113 = &v121 - (ksgui::Spinner **)v90->_Myfirst;
    if ( v111 == this->controls._Myend )
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
    v114 = this->controls._Mylast;
    if ( v114 )
      *v114 = v90->_Myfirst[v113];
  }
  ++this->controls._Mylast;
  v112->parent = this;
}
TyreTesterForm *TyreTesterForm::`scalar deleting destructor'(TyreTesterForm *this, unsigned int a2)
{
  TyreTesterForm::~TyreTesterForm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TyreTesterForm::~TyreTesterForm(TyreTesterForm *this)
{
  TyreTester **v2; // esi
  int v3; // edi

  this->__vftable = (TyreTesterForm_vtbl *)&TyreTesterForm::`vftable';
  v2 = this->tester;
  v3 = 4;
  do
  {
    if ( *v2 )
      ((void (*)(TyreTester *, int))(*v2)->~ISuspension)(*v2, 1);
    ++v2;
    --v3;
  }
  while ( v3 );
  this->__vftable = (TyreTesterForm_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void TyreTesterForm::render(TyreTesterForm *this, float dt)
{
  TyreTesterForm *v2; // ebx
  Tyre *v3; // esi
  int v4; // eax
  float v5; // xmm0_4
  unsigned int v6; // esi
  TyreTester *v7; // ecx
  ksgui::Graph *v8; // ecx
  ksgui::Graph *v9; // ecx
  ksgui::Graph *v10; // ecx
  ksgui::Graph *v11; // eax
  float *v12; // edi
  double v13; // st7
  ksgui::Graph *v14; // ecx
  int v15; // eax
  std::vector<unsigned int> *v16; // esi
  unsigned int *v17; // ecx
  unsigned int *v18; // edx
  int v19; // eax
  unsigned int *v20; // ecx
  float *v21; // eax
  ksgui::Graph *v22; // ecx
  unsigned int v23; // eax
  float v24; // xmm1_4
  std::vector<unsigned int> *v25; // esi
  unsigned int *v26; // ecx
  unsigned int *v27; // edx
  int v28; // eax
  unsigned int *v29; // ecx
  float *v30; // eax
  float v31; // xmm1_4
  float *v32; // edx
  ksgui::Graph *v33; // ecx
  float v34; // xmm0_4
  unsigned int v35; // eax
  std::vector<unsigned int> *v36; // esi
  unsigned int *v37; // eax
  unsigned int *v38; // ecx
  int v39; // edi
  unsigned int *v40; // ecx
  float *v41; // eax
  float v42; // xmm2_4
  ksgui::Graph *v43; // ecx
  TyreTestFrame *v44; // esi
  TyreTestFrame *i; // edi
  float v46; // xmm0_4
  ksgui::Graph *v47; // ecx
  unsigned int v48; // eax
  std::vector<ksgui::CustomSpinner *> *v49; // ebx
  ksgui::CustomSpinner **v50; // ecx
  ksgui::CustomSpinner **v51; // edx
  int v52; // eax
  ksgui::CustomSpinner **v53; // edx
  int v54; // eax
  int v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // edx
  ksgui::CustomSpinner **v58; // ecx
  ksgui::CustomSpinner **v59; // edx
  int v60; // ecx
  unsigned int v61; // edx
  unsigned int v62; // edx
  float *v63; // eax
  ksgui::Graph *v64; // ecx
  unsigned int v65; // esi
  float v66; // xmm0_4
  double v67; // st7
  ksgui::Graph *v68; // ecx
  std::vector<ksgui::CustomSpinner *> *v69; // esi
  ksgui::CustomSpinner **v70; // ecx
  ksgui::CustomSpinner **v71; // eax
  ksgui::CustomSpinner **v72; // edx
  int v73; // ecx
  unsigned int v74; // edx
  unsigned int v75; // edx
  ksgui::CustomSpinner **v76; // ecx
  ksgui::CustomSpinner **v77; // edx
  int v78; // ecx
  unsigned int v79; // edx
  unsigned int v80; // edx
  float *v81; // eax
  ksgui::Graph *v82; // ecx
  float v83; // xmm0_4
  double v84; // st7
  float v85; // xmm1_4
  ksgui::Graph *v86; // ecx
  unsigned int v87; // eax
  float v88; // xmm0_4
  std::vector<ksgui::CustomSpinner *> *v89; // esi
  ksgui::CustomSpinner **v90; // ecx
  ksgui::CustomSpinner **v91; // eax
  ksgui::CustomSpinner **v92; // edx
  int v93; // ecx
  unsigned int v94; // edx
  unsigned int v95; // edx
  ksgui::CustomSpinner **v96; // ecx
  ksgui::CustomSpinner **v97; // edx
  int v98; // ecx
  unsigned int v99; // edx
  unsigned int v100; // edx
  float *v101; // eax
  Tyre *v102; // esi
  double v103; // st7
  unsigned int v104; // ecx
  GLRenderer *v105; // esi
  TyreTestFrame *v106; // edi
  TyreTestFrame *v107; // esi
  float v108; // xmm4_4
  float v109; // xmm5_4
  float v110; // xmm6_4
  float v111; // xmm2_4
  float v112; // xmm1_4
  double minSA; // [esp+38h] [ebp-314h]
  float ms; // [esp+40h] [ebp-30Ch]
  double msa; // [esp+40h] [ebp-30Ch]
  __int64 v116; // [esp+48h] [ebp-304h]
  float v117; // [esp+50h] [ebp-2FCh]
  float dya; // [esp+80h] [ebp-2CCh]
  float dyb; // [esp+80h] [ebp-2CCh]
  float dy; // [esp+80h] [ebp-2CCh]
  unsigned int v121; // [esp+84h] [ebp-2C8h]
  float *v122; // [esp+88h] [ebp-2C4h]
  int v123; // [esp+88h] [ebp-2C4h]
  int v124; // [esp+8Ch] [ebp-2C0h]
  int v125; // [esp+8Ch] [ebp-2C0h]
  float v126; // [esp+8Ch] [ebp-2C0h]
  float v127; // [esp+90h] [ebp-2BCh]
  GLRenderer *v128; // [esp+90h] [ebp-2BCh]
  Speed result; // [esp+94h] [ebp-2B8h] BYREF
  float v130; // [esp+98h] [ebp-2B4h] BYREF
  float v131; // [esp+9Ch] [ebp-2B0h] BYREF
  float v132; // [esp+A0h] [ebp-2ACh]
  float v133; // [esp+A4h] [ebp-2A8h]
  float v134; // [esp+A8h] [ebp-2A4h] BYREF
  float v135; // [esp+ACh] [ebp-2A0h] BYREF
  float v136; // [esp+B0h] [ebp-29Ch]
  float v137; // [esp+B4h] [ebp-298h] BYREF
  float v138; // [esp+B8h] [ebp-294h] BYREF
  TyreTesterForm *v139; // [esp+BCh] [ebp-290h]
  float v140; // [esp+C0h] [ebp-28Ch]
  float v141; // [esp+C4h] [ebp-288h]
  std::vector<TyreTestFrame> ressrsa; // [esp+C8h] [ebp-284h] BYREF
  std::vector<TyreTestFrame> ressr; // [esp+D4h] [ebp-278h] BYREF
  std::vector<TyreTestFrame> res; // [esp+E0h] [ebp-26Ch] BYREF
  std::wstring v145; // [esp+ECh] [ebp-260h] BYREF
  wchar_t buffer[256]; // [esp+104h] [ebp-248h] BYREF
  int v147; // [esp+348h] [ebp-4h]

  v2 = this;
  v139 = this;
  if ( !ReplayManager::isInReplaymode(this->car->sim->replayManager) )
  {
    v121 = v2->spTyre->value;
    v3 = v2->tester[v121]->tyre;
    v4 = CarAvatar::getTyreCompoundIndex(v2->car, v121);
    Tyre::setCompound(v3, v4);
    v5 = v2->car->physicsState.speed.value;
    v6 = v121;
    if ( v5 <= 30.0 )
    {
      v2->tester[v121]->velocity = Speed::fromMS(&result, 15.0)->value;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    }
    else
    {
      v2->tester[v121]->velocity = v5;
    }
    v7 = v2->tester[v121];
    ms = v2->car->physicsState.load[v121];
    v140 = FLOAT_N20_0;
    TyreTester::slipAngleSweep(v7, &res, -20.0, 20.0, ms, 200);
    v147 = 0;
    v8 = v2->graph;
    if ( v8->series._Mylast - v8->series._Myfirst )
      (*v8->series._Myfirst)->values._Mylast = (*v8->series._Myfirst)->values._Myfirst;
    v9 = v2->graph;
    if ( (unsigned int)(v9->series._Mylast - v9->series._Myfirst) > 1 )
      *(_DWORD *)(*((_DWORD *)v9->series._Myfirst + 1) + 16) = *(_DWORD *)(*((_DWORD *)v9->series._Myfirst + 1) + 12);
    v10 = v2->graph;
    if ( (unsigned int)(v10->series._Mylast - v10->series._Myfirst) > 2 )
      *(_DWORD *)(*((_DWORD *)v10->series._Myfirst + 2) + 16) = *(_DWORD *)(*((_DWORD *)v10->series._Myfirst + 2) + 12);
    v11 = v2->graph;
    v132 = 0.0;
    v127 = 0.0;
    result.value = 0.0;
    v11->maxValuesCount = 200;
    v136 = 0.0;
    v141 = 0.0;
    if ( res._Myfirst != res._Mylast )
    {
      v12 = &res._Myfirst->Mz;
      do
      {
        v13 = TyreTester::getLoad(v2->tester[v6]);
        v14 = v2->graph;
        v15 = v14->series._Mylast - v14->series._Myfirst;
        v131 = *(v12 - 2) / v13;
        if ( v15 )
        {
          if ( v14->autoAdjustMaxValue && v131 > v14->maxY )
            v14->maxY = v131;
          v16 = (std::vector<unsigned int> *)*v14->series._Myfirst;
          v17 = v16[1]._Mylast;
          if ( &v131 >= (float *)v17 || (v18 = v16[1]._Myfirst, v18 > (unsigned int *)&v131) )
          {
            if ( v17 == v16[1]._Myend )
              std::vector<unsigned int>::_Reserve(v16 + 1, 1u);
            v21 = (float *)v16[1]._Mylast;
            if ( v21 )
              *v21 = v131;
          }
          else
          {
            v19 = ((char *)&v131 - (char *)v18) >> 2;
            v124 = v19;
            if ( v17 == v16[1]._Myend )
            {
              std::vector<unsigned int>::_Reserve(v16 + 1, 1u);
              v19 = v124;
            }
            v20 = v16[1]._Mylast;
            if ( v20 )
              *v20 = v16[1]._Myfirst[v19];
          }
          ++v16[1]._Mylast;
          v6 = v121;
        }
        v22 = v2->graph;
        v23 = v22->series._Mylast - v22->series._Myfirst;
        v24 = (float)(*v12 / (float)(v2->car->physicsState.load[v6] * 0.00019999999)) * 0.0099999998;
        v138 = v24;
        if ( v23 > 2 )
        {
          if ( v22->autoAdjustMaxValue && v24 > v22->maxY )
            v22->maxY = v24;
          v25 = (std::vector<unsigned int> *)*((_DWORD *)v22->series._Myfirst + 2);
          v26 = v25[1]._Mylast;
          if ( &v138 >= (float *)v26 || (v27 = v25[1]._Myfirst, v27 > (unsigned int *)&v138) )
          {
            if ( v26 == v25[1]._Myend )
              std::vector<unsigned int>::_Reserve(v25 + 1, 1u);
            v30 = (float *)v25[1]._Mylast;
            if ( v30 )
              *v30 = v24;
          }
          else
          {
            v28 = ((char *)&v138 - (char *)v27) >> 2;
            v125 = v28;
            if ( v26 == v25[1]._Myend )
            {
              std::vector<unsigned int>::_Reserve(v25 + 1, 1u);
              v28 = v125;
            }
            v29 = v25[1]._Mylast;
            if ( v29 )
              *v29 = v25[1]._Myfirst[v28];
          }
          ++v25[1]._Mylast;
          v6 = v121;
        }
        if ( *v12 > v136 )
        {
          v136 = *v12;
          v141 = v12[1];
        }
        if ( *(v12 - 2) > v127 )
        {
          v127 = *(v12 - 2);
          LODWORD(result.value) = (Speed)v12[1];
        }
        v12 += 5;
      }
      while ( v12 - 2 != (float *)res._Mylast );
    }
    TyreTester::slipRatioSweep(v2->tester[v6], &ressr, -1.0, 1.0, v2->car->physicsState.load[v6], 200);
    LOBYTE(v147) = 1;
    v31 = 0.0;
    v133 = 0.0;
    v126 = 0.0;
    if ( ressr._Myfirst != ressr._Mylast )
    {
      v32 = &ressr._Myfirst->Fx;
      v122 = &ressr._Myfirst->Fx;
      do
      {
        v33 = v2->graph;
        v34 = *v32 / v2->car->physicsState.load[v6];
        v35 = v33->series._Mylast - v33->series._Myfirst;
        v137 = v34;
        if ( v35 > 1 )
        {
          if ( v33->autoAdjustMaxValue && v34 > v33->maxY )
            v33->maxY = v34;
          v36 = (std::vector<unsigned int> *)*((_DWORD *)v33->series._Myfirst + 1);
          v37 = v36[1]._Mylast;
          if ( &v137 >= (float *)v37 || (v38 = v36[1]._Myfirst, v38 > (unsigned int *)&v137) )
          {
            if ( v37 == v36[1]._Myend )
            {
              std::vector<unsigned int>::_Reserve(v36 + 1, 1u);
              v31 = v133;
              v32 = v122;
            }
            v41 = (float *)v36[1]._Mylast;
            if ( v41 )
              *v41 = v34;
          }
          else
          {
            v39 = ((char *)&v137 - (char *)v38) >> 2;
            if ( v37 == v36[1]._Myend )
            {
              std::vector<unsigned int>::_Reserve(v36 + 1, 1u);
              v31 = v133;
              v32 = v122;
            }
            v40 = v36[1]._Mylast;
            if ( v40 )
              *v40 = v36[1]._Myfirst[v39];
          }
          ++v36[1]._Mylast;
          v6 = v121;
        }
        if ( *v32 > v31 )
        {
          v42 = v32[3];
          v31 = *v32;
          v133 = *v32;
          v126 = v42;
        }
        v32 += 5;
        v122 = v32;
      }
      while ( v32 - 1 != (float *)ressr._Mylast );
    }
    TyreTester::srSASweep(v2->tester[v6], &ressrsa, 9.0, -1.0, 1.0, v2->car->physicsState.load[v6], 200);
    LOBYTE(v147) = 2;
    v43 = v2->graph;
    if ( (unsigned int)(v43->series._Mylast - v43->series._Myfirst) > 4 )
      *(_DWORD *)(*((_DWORD *)v43->series._Myfirst + 4) + 16) = *(_DWORD *)(*((_DWORD *)v43->series._Myfirst + 4) + 12);
    v44 = ressrsa._Myfirst;
    for ( i = ressrsa._Mylast; v44 != i; ++v44 )
    {
      v46 = v44->Fy / v2->car->physicsState.load[v121];
      v47 = v2->graph;
      v48 = v47->series._Mylast - v47->series._Myfirst;
      v134 = v46;
      if ( v48 > 4 )
      {
        if ( v47->autoAdjustMaxValue && v46 > v47->maxY )
          v47->maxY = v46;
        v49 = (std::vector<ksgui::CustomSpinner *> *)*((_DWORD *)v47->series._Myfirst + 4);
        v50 = v49[1]._Mylast;
        if ( &v134 >= (float *)v50 || (v51 = v49[1]._Myfirst, v51 > (ksgui::CustomSpinner **)&v134) )
        {
          v59 = v49[1]._Myend;
          if ( v50 == v59 && !(v59 - v50) )
          {
            v60 = v50 - v49[1]._Myfirst;
            if ( v60 == 0x3FFFFFFF )
LABEL_116:
              std::_Xlength_error("vector<T> too long");
            v61 = v59 - v49[1]._Myfirst;
            if ( 0x3FFFFFFF - (v61 >> 1) >= v61 )
              v62 = (v61 >> 1) + v61;
            else
              v62 = 0;
            if ( v62 < v60 + 1 )
              v62 = v60 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate(v49 + 1, v62);
          }
          v63 = (float *)v49[1]._Mylast;
          if ( v63 )
            *v63 = v46;
        }
        else
        {
          v52 = (char *)&v134 - (char *)v51;
          v53 = v49[1]._Myend;
          v54 = v52 >> 2;
          v123 = v54;
          if ( v50 == v53 )
          {
            if ( !(v53 - v50) )
            {
              v55 = v50 - v49[1]._Myfirst;
              if ( v55 == 0x3FFFFFFF )
                goto LABEL_116;
              v56 = v53 - v49[1]._Myfirst;
              if ( 0x3FFFFFFF - (v56 >> 1) >= v56 )
                v57 = (v56 >> 1) + v56;
              else
                v57 = 0;
              if ( v57 < v55 + 1 )
                v57 = v55 + 1;
              std::vector<ksgui::CustomSpinner *>::_Reallocate(v49 + 1, v57);
            }
            v54 = v123;
          }
          v58 = v49[1]._Mylast;
          if ( v58 )
            *v58 = v49[1]._Myfirst[v54];
        }
        ++v49[1]._Mylast;
        v2 = v139;
      }
    }
    v64 = v2->graph;
    if ( (unsigned int)(v64->series._Mylast - v64->series._Myfirst) > 3 )
      *(_DWORD *)(*((_DWORD *)v64->series._Myfirst + 3) + 16) = *(_DWORD *)(*((_DWORD *)v64->series._Myfirst + 3) + 12);
    v65 = v121;
    v66 = 0.0;
    do
    {
      v67 = Tyre::getDY(v2->tester[v65]->tyre, v66 * 9.8059998);
      v68 = v2->graph;
      v130 = v67;
      if ( (unsigned int)(v68->series._Mylast - v68->series._Myfirst) > 3 )
      {
        if ( v68->autoAdjustMaxValue && v130 > v68->maxY )
          v68->maxY = v130;
        v69 = (std::vector<ksgui::CustomSpinner *> *)*((_DWORD *)v68->series._Myfirst + 3);
        v70 = v69[1]._Mylast;
        if ( &v130 >= (float *)v70 || (v71 = v69[1]._Myfirst, v71 > (ksgui::CustomSpinner **)&v130) )
        {
          v77 = v69[1]._Myend;
          if ( v70 == v77 && !(v77 - v70) )
          {
            i = (TyreTestFrame *)v69[1]._Myfirst;
            v78 = ((char *)v70 - (char *)i) >> 2;
            if ( v78 == 0x3FFFFFFF )
              goto LABEL_116;
            v79 = ((char *)v77 - (char *)i) >> 2;
            if ( 0x3FFFFFFF - (v79 >> 1) >= v79 )
              v80 = (v79 >> 1) + v79;
            else
              v80 = 0;
            if ( v80 < v78 + 1 )
              v80 = v78 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate(v69 + 1, v80);
          }
          v81 = (float *)v69[1]._Mylast;
          if ( v81 )
            *v81 = v130;
        }
        else
        {
          v72 = v69[1]._Myend;
          i = (TyreTestFrame *)(((char *)&v130 - (char *)v71) >> 2);
          if ( v70 == v72 && !(v72 - v70) )
          {
            v73 = v70 - v69[1]._Myfirst;
            if ( v73 == 0x3FFFFFFF )
              goto LABEL_116;
            v74 = v72 - v69[1]._Myfirst;
            if ( 0x3FFFFFFF - (v74 >> 1) >= v74 )
              v75 = (v74 >> 1) + v74;
            else
              v75 = 0;
            if ( v75 < v73 + 1 )
              v75 = v73 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate(v69 + 1, v75);
          }
          v76 = v69[1]._Mylast;
          if ( v76 )
            *v76 = v69[1]._Myfirst[(_DWORD)i];
        }
        ++v69[1]._Mylast;
        v65 = v121;
      }
      v66 = v132 + 10.0;
      v132 = v132 + 10.0;
    }
    while ( v132 < 2000.0 );
    v82 = v2->graph;
    if ( (unsigned int)(v82->series._Mylast - v82->series._Myfirst) > 5 )
      *(_DWORD *)(*((_DWORD *)v82->series._Myfirst + 5) + 16) = *(_DWORD *)(*((_DWORD *)v82->series._Myfirst + 5) + 12);
    v83 = FLOAT_N20_0;
    do
    {
      v84 = Tyre::getCamberedDy(v2->tester[v65]->tyre, v83 * 0.017453, 1.0);
      v85 = FLOAT_1_0;
      v86 = v2->graph;
      dya = v84;
      v87 = v86->series._Mylast - v86->series._Myfirst;
      v88 = (float)(dya - 1.0) * 5.0;
      v132 = v88;
      v135 = v88;
      if ( v87 > 5 )
      {
        if ( v86->autoAdjustMaxValue && v88 > v86->maxY )
          v86->maxY = v88;
        v89 = (std::vector<ksgui::CustomSpinner *> *)*((_DWORD *)v86->series._Myfirst + 5);
        v90 = v89[1]._Mylast;
        if ( &v135 >= (float *)v90 || (v91 = v89[1]._Myfirst, v91 > (ksgui::CustomSpinner **)&v135) )
        {
          v97 = v89[1]._Myend;
          if ( v90 == v97 && !(v97 - v90) )
          {
            i = (TyreTestFrame *)v89[1]._Myfirst;
            v98 = ((char *)v90 - (char *)i) >> 2;
            if ( v98 == 0x3FFFFFFF )
              goto LABEL_116;
            v99 = ((char *)v97 - (char *)i) >> 2;
            if ( 0x3FFFFFFF - (v99 >> 1) >= v99 )
              v100 = (v99 >> 1) + v99;
            else
              v100 = 0;
            if ( v100 < v98 + 1 )
              v100 = v98 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate(v89 + 1, v100);
            v88 = v132;
            v85 = FLOAT_1_0;
          }
          v101 = (float *)v89[1]._Mylast;
          if ( v101 )
            *v101 = v88;
        }
        else
        {
          v92 = v89[1]._Myend;
          i = (TyreTestFrame *)(((char *)&v135 - (char *)v91) >> 2);
          if ( v90 == v92 && !(v92 - v90) )
          {
            v93 = v90 - v89[1]._Myfirst;
            if ( v93 == 0x3FFFFFFF )
              goto LABEL_116;
            v94 = v92 - v89[1]._Myfirst;
            if ( 0x3FFFFFFF - (v94 >> 1) >= v94 )
              v95 = (v94 >> 1) + v94;
            else
              v95 = 0;
            if ( v95 < v93 + 1 )
              v95 = v93 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate(v89 + 1, v95);
            v85 = FLOAT_1_0;
          }
          v96 = v89[1]._Mylast;
          if ( v96 )
            *v96 = v89[1]._Myfirst[(_DWORD)i];
        }
        ++v89[1]._Mylast;
        v65 = v121;
      }
      v83 = v140 + 0.2;
      v140 = v140 + 0.2;
    }
    while ( v140 <= 20.0 );
    v102 = v2->tester[v65]->tyre;
    dyb = v85 / v2->car->physicsState.load[v121];
    msa = Tyre::getDY(v102, 19612.0);
    minSA = Tyre::getDY(v102, 9806.0);
    v103 = Tyre::getDY(v102, 4903.0);
    _swprintf_s(
      buffer,
      0x100u,
      L"FY:%.2f @ %.1f   FX:%.2f @ %.2f MZ:%.1f @ %.1f DY @ 0.5k:%.1f 1k:%.1f 2k:%.1f",
      (float)(dyb * v127),
      result.value,
      (float)(dyb * v133),
      v126,
      v136,
      v141,
      v103,
      minSA,
      msa);
    v145._Myres = 7;
    v145._Mysize = 0;
    v145._Bx._Buf[0] = 0;
    if ( buffer[0] )
      v104 = wcslen(buffer);
    else
      v104 = 0;
    std::wstring::assign(&v145, buffer, v104);
    LOBYTE(v147) = 3;
    v2->label1->setText(v2->label1, &v145);
    LOBYTE(v147) = 2;
    if ( v145._Myres >= 8 )
      operator delete(v145._Bx._Ptr);
    ksgui::Control::render(v2, (int)i, (int)v102, dt, v116, v117);
    v105 = glTyreTester;
    v128 = glTyreTester;
    if ( !glTyreTester )
    {
      v105 = GraphicsManager::createGLRenderer(v2->gui->graphics, 0x7D0u);
      v128 = v105;
      glTyreTester = v105;
    }
    GLRenderer::begin(v105, eLinesStrip, 0);
    GLRenderer::color3f(v105, 0.0, 1.0, 1.0);
    v106 = ressrsa._Mylast;
    v107 = ressrsa._Myfirst;
    v108 = (float)((float)(v2->rect.right - v2->rect.left) * 0.5) + v2->rect.left;
    v109 = (float)((float)(v2->rect.bottom - v2->rect.top) * 0.5) + v2->rect.top;
    dy = v108;
    result.value = v109;
    if ( ressrsa._Myfirst != ressrsa._Mylast )
    {
      v110 = FLOAT_0_25;
      do
      {
        v111 = 1.0 / v2->car->physicsState.load[v121];
        v112 = (float)((float)(v2->rect.bottom - v2->rect.top) * (float)(v107->Fy * v111)) * v110;
        *(float *)&v145._Bx._Ptr = (float)((float)((float)(v2->rect.right - v2->rect.left) * (float)(v107->Fx * v111))
                                         * v110)
                                 + v108;
        *(_QWORD *)&v145._Bx._Alias[4] = COERCE_UNSIGNED_INT(v112 + v109);
        GLRenderer::vertex3fv(v128, (const float *)&v145._Bx._Ptr);
        v108 = dy;
        ++v107;
        v109 = result.value;
        v110 = FLOAT_0_25;
      }
      while ( v107 != v106 );
    }
    GLRenderer::end(v128);
    if ( ressrsa._Myfirst )
    {
      operator delete(ressrsa._Myfirst);
      ressrsa._Myfirst = 0;
      ressrsa._Mylast = 0;
      ressrsa._Myend = 0;
    }
    if ( ressr._Myfirst )
    {
      operator delete(ressr._Myfirst);
      ressr._Myfirst = 0;
      ressr._Mylast = 0;
      ressr._Myend = 0;
    }
    if ( res._Myfirst )
      operator delete(res._Myfirst);
  }
}
