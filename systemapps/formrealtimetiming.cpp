#include "formrealtimetiming.h
void FormRealTimeTiming::FormRealTimeTiming(FormRealTimeTiming *this, Sim *sim)
{
  char *v2; // ebp
  unsigned int v3; // ebx
  Game *v4; // eax
  std::wstring *v5; // eax
  void (__cdecl *v6)(void *); // eax
  std::vector<unsigned int> *v7; // esi
  ksgui::Label *v8; // edi
  int v9; // ebp
  std::wstring *v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  Font *v20; // eax
  Font *v21; // eax
  volatile signed __int32 *v22; // ebp
  Font *v23; // eax
  int v24; // eax
  void *v25; // ebp
  unsigned int *v26; // ecx
  eFontType v27; // eax
  unsigned int *v28; // ecx
  _DWORD *v29; // eax
  ksgui::Label *v30; // edi
  int v31; // ebp
  std::wstring *v32; // eax
  int v33; // eax
  int v34; // edi
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  int v37; // eax
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  Font *v44; // eax
  Font *v45; // eax
  volatile signed __int32 *v46; // ebp
  Font *v47; // eax
  int v48; // eax
  void *v49; // ebp
  unsigned int *v50; // ecx
  eFontType v51; // eax
  unsigned int *v52; // ecx
  _DWORD *v53; // eax
  ksgui::Label *v54; // edi
  std::wstring *v55; // eax
  int v56; // eax
  int v57; // edi
  int v58; // eax
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  Font *v65; // eax
  Font *v66; // eax
  volatile signed __int32 *v67; // ebp
  Font *v68; // eax
  int v69; // eax
  unsigned int *v70; // ecx
  eFontType v71; // eax
  unsigned int *v72; // ecx
  _DWORD *v73; // eax
  int v74; // eax
  ksgui::Label *v75; // edi
  int v76; // ebp
  std::wstring *v77; // eax
  int v78; // eax
  int v79; // edi
  int v80; // eax
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm3_4
  float v86; // xmm2_4
  Font *v87; // eax
  Font *v88; // eax
  volatile signed __int32 *v89; // ebp
  Font *v90; // eax
  float v91; // eax
  unsigned int *v92; // ecx
  unsigned int *v93; // edx
  int v94; // ebp
  int v95; // ecx
  unsigned int v96; // edx
  unsigned int v97; // edx
  unsigned int *v98; // ecx
  unsigned int *v99; // edx
  int v100; // ecx
  unsigned int v101; // edx
  unsigned int v102; // edx
  _DWORD *v103; // eax
  float *v104; // ebp
  Font *v105; // edi
  std::wstring *v106; // eax
  unsigned int v107; // eax
  unsigned int v108; // edi
  int v109; // eax
  float v110; // xmm0_4
  float v111; // xmm3_4
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm0_4
  float v115; // xmm1_4
  Font *v116; // eax
  Font *v117; // eax
  volatile signed __int32 *v118; // ebp
  Font *v119; // eax
  float v120; // eax
  _QWORD *v121; // ecx
  __int64 v122; // xmm0_8
  int v123; // eax
  Sim *v124; // ebx
  Font *v125; // edi
  int v126; // eax
  int v127; // ecx
  float v128; // xmm0_4
  float v129; // xmm1_4
  float v130; // xmm2_4
  float v131; // xmm1_4
  float v132; // xmm2_4
  int v133; // eax
  int *v134; // eax
  int v135; // ecx
  int v136; // edx
  int v137; // ebx
  volatile signed __int32 *v138; // edi
  volatile signed __int32 *v139; // edi
  Texture *v140; // eax
  void *v141; // ecx
  const std::wstring *v142; // eax
  _BYTE v143[28]; // [esp+30h] [ebp-F8h] BYREF
  float h; // [esp+4Ch] [ebp-DCh]
  eFontType v145; // [esp+6Ch] [ebp-BCh] BYREF
  int _Val; // [esp+70h] [ebp-B8h]
  unsigned int _Count; // [esp+74h] [ebp-B4h] BYREF
  float v148[2]; // [esp+78h] [ebp-B0h] BYREF
  std::shared_ptr<Font> v149; // [esp+80h] [ebp-A8h] BYREF
  void *owner; // [esp+88h] [ebp-A0h]
  std::shared_ptr<Font> v151; // [esp+8Ch] [ebp-9Ch] BYREF
  std::shared_ptr<Font> v152; // [esp+94h] [ebp-94h] BYREF
  int v153; // [esp+9Ch] [ebp-8Ch] BYREF
  int v154; // [esp+A0h] [ebp-88h] BYREF
  int v155; // [esp+A4h] [ebp-84h] BYREF
  int v156; // [esp+A8h] [ebp-80h] BYREF
  std::shared_ptr<Font> v157; // [esp+ACh] [ebp-7Ch] BYREF
  Sim *v158; // [esp+B4h] [ebp-74h]
  __int64 v159; // [esp+B8h] [ebp-70h] BYREF
  FormRealTimeTiming *v160; // [esp+C0h] [ebp-68h]
  int v161; // [esp+C4h] [ebp-64h] BYREF
  std::wstring text; // [esp+CCh] [ebp-5Ch] BYREF
  std::wstring result; // [esp+E4h] [ebp-44h] BYREF
  Texture v164; // [esp+FCh] [ebp-2Ch] BYREF
  int v165; // [esp+124h] [ebp-4h]

  v2 = (char *)this;
  owner = this;
  v3 = 0;
  _Count = 0;
  LODWORD(h) = 1;
  v160 = this;
  v4 = sim->game;
  v158 = sim;
  *(_DWORD *)&v143[24] = v4->gui;
  *(_DWORD *)&v143[20] = 7;
  *(_DWORD *)&v143[16] = 0;
  *(_WORD *)v143 = 0;
  std::wstring::assign((std::wstring *)v143, L"REAL_TIME_APP", 0xDu);
  ksgui::Form::Form((ksgui::Form *)v2, 0, *(std::wstring *)v143, *(ksgui::GUI **)&v143[24], SLOBYTE(h));
  v165 = 0;
  *(_DWORD *)v2 = &FormRealTimeTiming::`vftable';
  *((_DWORD *)v2 + 80) = sim;
  *((_DWORD *)v2 + 114) = 0;
  *((_DWORD *)v2 + 115) = 0;
  *((_DWORD *)v2 + 116) = 0;
  *((_DWORD *)v2 + 117) = 0;
  *((_DWORD *)v2 + 118) = 0;
  *((_DWORD *)v2 + 119) = 0;
  *((_DWORD *)v2 + 120) = 0;
  *((_DWORD *)v2 + 121) = 0;
  *((_DWORD *)v2 + 122) = 0;
  *((_DWORD *)v2 + 123) = 0;
  *((_DWORD *)v2 + 124) = 0;
  *((_DWORD *)v2 + 125) = 0;
  *((_DWORD *)v2 + 126) = 0;
  *((_DWORD *)v2 + 127) = 0;
  *((_DWORD *)v2 + 129) = 0;
  *((_DWORD *)v2 + 135) = 7;
  *((_DWORD *)v2 + 134) = 0;
  *((_WORD *)v2 + 260) = 0;
  LOBYTE(v165) = 1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Realtime", 8u);
  LOBYTE(v165) = 2;
  v5 = acTranslate(&result, &text);
  LOBYTE(v165) = 3;
  (*(void (**)(_DWORD, std::wstring *))(**((_DWORD **)v2 + 70) + 68))(*((_DWORD *)v2 + 70), v5);
  v6 = operator delete;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v6 = operator delete;
  }
  LOBYTE(v165) = 1;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v6(text._Bx._Ptr);
  v7 = (std::vector<unsigned int> *)(v2 + 136);
  *((_WORD *)v2 + 142) = 256;
  *(_OWORD *)(v2 + 44) = _xmm;
  _Val = 0;
  v151._Ptr = 0;
  v151._Rep = 0;
  v152._Ptr = 0;
  v152._Rep = 0;
  v149._Ptr = 0;
  v149._Rep = 0;
  do
  {
    v8 = (ksgui::Label *)operator new(0x11Cu);
    LODWORD(v148[0]) = v8;
    LOBYTE(v165) = 4;
    if ( v8 )
    {
      h = *((float *)v2 + 60);
      v9 = _Val;
      v10 = std::to_wstring(&result, _Val);
      LOBYTE(v165) = 5;
      v3 |= 1u;
      _Count = v3;
      std::operator+<wchar_t>((std::wstring *)&v143[4], L"LABEL_POS_D", v10);
      ksgui::Label::Label(v8, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
      v12 = v11;
    }
    else
    {
      v9 = _Val;
      v12 = 0;
    }
    v165 = 1;
    if ( (v3 & 1) != 0 )
    {
      v3 &= 0xFFFFFFFE;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, word_17BE9D8, 0);
    LOBYTE(v165) = 7;
    (*(void (**)(int, std::wstring *))(*(_DWORD *)v12 + 68))(v12, &text);
    LOBYTE(v165) = 1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v13 = *(_DWORD *)v12;
    *(_DWORD *)(v12 + 152) = 0;
    (*(void (**)(int, int, int))(v13 + 28))(v12, 1106247680, 1101004800);
    v14 = *(float *)(v12 + 264);
    v15 = *(float *)(v12 + 32) - *(float *)(v12 + 28);
    v16 = *(float *)(v12 + 40) - *(float *)(v12 + 36);
    *(_DWORD *)(v12 + 28) = 1084227584;
    v17 = v15 + 5.0;
    v18 = (float)((float)v9 * 20.0) + 30.0;
    *(float *)(v12 + 32) = v17;
    v148[1] = v18;
    v19 = v16 + v18;
    *(float *)(v12 + 36) = v18;
    *(float *)(v12 + 40) = v19;
    if ( v14 == 0.0 && *(float *)(v12 + 272) == 0.0 )
    {
      *(_DWORD *)(v12 + 264) = 1084227584;
      *(float *)(v12 + 272) = v18;
      *(float *)(v12 + 268) = v17;
      *(float *)(v12 + 276) = v19;
    }
    v20 = (Font *)operator new(0x18u);
    LODWORD(v148[0]) = v20;
    LOBYTE(v165) = 8;
    if ( v20 )
      Font::Font(v20, eFontMonospaced, 16.0, 0, 0);
    else
      v21 = 0;
    LOBYTE(v165) = 1;
    std::shared_ptr<Font>::_Resetp<Font>(&v151, v21);
    v22 = *(volatile signed __int32 **)(v12 + 132);
    v23 = v151._Ptr;
    *(_DWORD *)(v12 + 132) = v151._Rep;
    v151._Rep = 0;
    v151._Ptr = 0;
    *(_DWORD *)(v12 + 128) = v23;
    if ( v22 )
    {
      if ( !_InterlockedExchangeAdd(v22 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v22)(v22);
        if ( !_InterlockedExchangeAdd(v22 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v22 + 4))(v22);
      }
    }
    v24 = _Val;
    v25 = owner;
    *(_OWORD *)(v12 + 76) = _xmm;
    v154 = v12;
    *((_DWORD *)v25 + v24 + 95) = v12;
    v26 = v7->_Mylast;
    if ( &v154 >= (int *)v26 || v7->_Myfirst > (unsigned int *)&v154 )
    {
      if ( v26 == v7->_Myend )
        std::vector<unsigned int>::_Reserve(v7, 1u);
      v29 = v7->_Mylast;
      if ( v29 )
        *v29 = v12;
    }
    else
    {
      v27 = ((char *)&v154 - (char *)v7->_Myfirst) >> 2;
      v145 = v27;
      if ( v26 == v7->_Myend )
      {
        std::vector<unsigned int>::_Reserve(v7, 1u);
        v27 = v145;
      }
      v28 = v7->_Mylast;
      if ( v28 )
        *v28 = v7->_Myfirst[v27];
    }
    ++v7->_Mylast;
    LODWORD(h) = 284;
    *(_DWORD *)(v12 + 148) = v25;
    v30 = (ksgui::Label *)operator new(LODWORD(h));
    LODWORD(v148[0]) = v30;
    LOBYTE(v165) = 9;
    if ( v30 )
    {
      h = *((float *)v25 + 60);
      v31 = _Val;
      v32 = std::to_wstring(&result, _Val);
      LOBYTE(v165) = 10;
      v3 |= 2u;
      _Count = v3;
      std::operator+<wchar_t>((std::wstring *)&v143[4], L"LABEL_NAME_D", v32);
      ksgui::Label::Label(v30, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
      v34 = v33;
    }
    else
    {
      v31 = _Val;
      v34 = 0;
    }
    v165 = 1;
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFFFFFFFD;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v35 = std::to_wstring((std::wstring *)&v164, v31);
    LOBYTE(v165) = 12;
    v36 = std::operator+<wchar_t>(&text, L"DRIVER", v35);
    LOBYTE(v165) = 13;
    (*(void (**)(int, std::wstring *))(*(_DWORD *)v34 + 68))(v34, v36);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v165) = 1;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    if ( v164.fileName._Mysize >= 8 )
      operator delete(v164.kid);
    v37 = *(_DWORD *)v34;
    *(_DWORD *)(v34 + 152) = 0;
    (*(void (**)(int, int, int))(v37 + 28))(v34, 1125515264, 1101004800);
    v38 = *(float *)(v34 + 264);
    v39 = *(float *)(v34 + 32) - *(float *)(v34 + 28);
    v40 = *(float *)(v34 + 40) - *(float *)(v34 + 36);
    v41 = v148[1];
    *(_DWORD *)(v34 + 28) = 1108082688;
    v42 = v39 + 35.0;
    v43 = v40 + v41;
    *(float *)(v34 + 36) = v41;
    *(float *)(v34 + 32) = v42;
    *(float *)(v34 + 40) = v43;
    if ( v38 == 0.0 && *(float *)(v34 + 272) == 0.0 )
    {
      *(_DWORD *)(v34 + 264) = 1108082688;
      *(float *)(v34 + 272) = v41;
      *(float *)(v34 + 268) = v42;
      *(float *)(v34 + 276) = v43;
    }
    v44 = (Font *)operator new(0x18u);
    LODWORD(v148[0]) = v44;
    LOBYTE(v165) = 14;
    if ( v44 )
      Font::Font(v44, eFontMonospaced, 16.0, 0, 0);
    else
      v45 = 0;
    LOBYTE(v165) = 1;
    std::shared_ptr<Font>::_Resetp<Font>(&v152, v45);
    v46 = *(volatile signed __int32 **)(v34 + 132);
    v47 = v152._Ptr;
    *(_DWORD *)(v34 + 132) = v152._Rep;
    v152._Rep = 0;
    v152._Ptr = 0;
    *(_DWORD *)(v34 + 128) = v47;
    if ( v46 )
    {
      if ( !_InterlockedExchangeAdd(v46 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v46)(v46);
        if ( !_InterlockedExchangeAdd(v46 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v46 + 4))(v46);
      }
    }
    v48 = _Val;
    v49 = owner;
    *(_OWORD *)(v34 + 76) = _xmm;
    v153 = v34;
    *((_DWORD *)v49 + v48 + 81) = v34;
    v50 = v7->_Mylast;
    if ( &v153 >= (int *)v50 || v7->_Myfirst > (unsigned int *)&v153 )
    {
      if ( v50 == v7->_Myend )
        std::vector<unsigned int>::_Reserve(v7, 1u);
      v53 = v7->_Mylast;
      if ( v53 )
        *v53 = v34;
    }
    else
    {
      v51 = ((char *)&v153 - (char *)v7->_Myfirst) >> 2;
      v145 = v51;
      if ( v50 == v7->_Myend )
      {
        std::vector<unsigned int>::_Reserve(v7, 1u);
        v51 = v145;
      }
      v52 = v7->_Mylast;
      if ( v52 )
        *v52 = v7->_Myfirst[v51];
    }
    ++v7->_Mylast;
    LODWORD(h) = 284;
    *(_DWORD *)(v34 + 148) = v49;
    v54 = (ksgui::Label *)operator new(LODWORD(h));
    LODWORD(v148[0]) = v54;
    LOBYTE(v165) = 15;
    if ( v54 )
    {
      h = *((float *)v49 + 60);
      v55 = std::to_wstring(&result, _Val);
      LOBYTE(v165) = 16;
      v3 |= 4u;
      _Count = v3;
      std::operator+<wchar_t>((std::wstring *)&v143[4], L"LABEL_TIME_D", v55);
      ksgui::Label::Label(v54, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
      v57 = v56;
    }
    else
    {
      v57 = 0;
    }
    v165 = 1;
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFFFFFFFB;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"-12.4", 5u);
    LOBYTE(v165) = 18;
    (*(void (**)(int, std::wstring *))(*(_DWORD *)v57 + 68))(v57, &text);
    LOBYTE(v165) = 1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v58 = *(_DWORD *)v57;
    *(_DWORD *)(v57 + 152) = 1;
    (*(void (**)(int, int, int))(v58 + 28))(v57, 1109393408, 1101004800);
    v59 = *(float *)(v57 + 264);
    v60 = *(float *)(v57 + 32) - *(float *)(v57 + 28);
    v61 = *(float *)(v57 + 40) - *(float *)(v57 + 36);
    v62 = v148[1];
    *(_DWORD *)(v57 + 28) = 1131413504;
    v63 = v60 + 240.0;
    v64 = v61 + v62;
    *(float *)(v57 + 36) = v62;
    *(float *)(v57 + 32) = v63;
    *(float *)(v57 + 40) = v64;
    if ( v59 == 0.0 && *(float *)(v57 + 272) == 0.0 )
    {
      *(_DWORD *)(v57 + 264) = 1131413504;
      *(float *)(v57 + 272) = v62;
      *(float *)(v57 + 268) = v63;
      *(float *)(v57 + 276) = v64;
    }
    v65 = (Font *)operator new(0x18u);
    LODWORD(v148[0]) = v65;
    LOBYTE(v165) = 19;
    if ( v65 )
      Font::Font(v65, eFontMonospaced, 16.0, 0, 0);
    else
      v66 = 0;
    LOBYTE(v165) = 1;
    std::shared_ptr<Font>::_Resetp<Font>(&v149, v66);
    v67 = *(volatile signed __int32 **)(v57 + 132);
    v68 = v149._Ptr;
    *(_DWORD *)(v57 + 132) = v149._Rep;
    v149._Rep = 0;
    v149._Ptr = 0;
    *(_DWORD *)(v57 + 128) = v68;
    if ( v67 )
    {
      if ( !_InterlockedExchangeAdd(v67 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v67)(v67);
        if ( !_InterlockedExchangeAdd(v67 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v67 + 4))(v67);
      }
    }
    v69 = _Val;
    v2 = (char *)owner;
    *(_OWORD *)(v57 + 76) = _xmm;
    v155 = v57;
    *(_DWORD *)&v2[4 * v69 + 352] = v57;
    v70 = v7->_Mylast;
    if ( &v155 >= (int *)v70 || v7->_Myfirst > (unsigned int *)&v155 )
    {
      if ( v70 == v7->_Myend )
        std::vector<unsigned int>::_Reserve(v7, 1u);
      v73 = v7->_Mylast;
      if ( v73 )
        *v73 = v57;
    }
    else
    {
      v71 = ((char *)&v155 - (char *)v7->_Myfirst) >> 2;
      v145 = v71;
      if ( v70 == v7->_Myend )
      {
        std::vector<unsigned int>::_Reserve(v7, 1u);
        v71 = v145;
      }
      v72 = v7->_Mylast;
      if ( v72 )
        *v72 = v7->_Myfirst[v71];
    }
    v74 = _Val;
    ++v7->_Mylast;
    *(_DWORD *)(v57 + 148) = v2;
    _Val = v74 + 1;
  }
  while ( v74 + 1 < 7 );
  *(_OWORD *)(*((_DWORD *)v2 + 98) + 76) = _xmm;
  *(_OWORD *)(*((_DWORD *)v2 + 84) + 76) = _xmm;
  *(_OWORD *)(*((_DWORD *)v2 + 91) + 76) = _xmm;
  _Val = 0;
  v149._Ptr = 0;
  v149._Rep = 0;
  v145 = (eFontType)(v2 + 432);
  LODWORD(v148[1]) = v2 + 420;
  v159 = 0i64;
  do
  {
    v75 = (ksgui::Label *)operator new(0x11Cu);
    LODWORD(v148[0]) = v75;
    LOBYTE(v165) = 20;
    if ( v75 )
    {
      h = *((float *)v2 + 60);
      v76 = _Val;
      v77 = std::to_wstring(&result, _Val);
      LOBYTE(v165) = 21;
      v3 |= 8u;
      _Count = v3;
      std::operator+<wchar_t>((std::wstring *)&v143[4], L"LABEL_NAME_L", v77);
      ksgui::Label::Label(v75, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
      v79 = v78;
    }
    else
    {
      v76 = _Val;
      v79 = 0;
    }
    v165 = 1;
    if ( (v3 & 8) != 0 )
    {
      v3 &= 0xFFFFFFF7;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, word_17BE9D8, 0);
    LOBYTE(v165) = 23;
    (*(void (**)(int, std::wstring *))(*(_DWORD *)v79 + 68))(v79, &text);
    LOBYTE(v165) = 1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v80 = *(_DWORD *)v79;
    *(_DWORD *)(v79 + 152) = 0;
    (*(void (**)(int, int, int))(v80 + 28))(v79, 1125515264, 1101004800);
    v81 = *(float *)(v79 + 264);
    v82 = *(float *)(v79 + 32) - *(float *)(v79 + 28);
    v83 = *(float *)(v79 + 40) - *(float *)(v79 + 36);
    *(_DWORD *)(v79 + 28) = 1084227584;
    v84 = v82 + 5.0;
    *(float *)(v79 + 32) = v84;
    v85 = (float)((float)((float)v76 * 20.0) + 170.0) + 40.0;
    v148[0] = v85;
    v86 = v83 + v85;
    *(float *)(v79 + 36) = v85;
    *(float *)(v79 + 40) = v86;
    if ( v81 == 0.0 && *(float *)(v79 + 272) == 0.0 )
    {
      *(_DWORD *)(v79 + 264) = 1084227584;
      *(float *)(v79 + 272) = v85;
      *(float *)(v79 + 268) = v84;
      *(float *)(v79 + 276) = v86;
    }
    v87 = (Font *)operator new(0x18u);
    v152._Ptr = v87;
    LOBYTE(v165) = 24;
    if ( v87 )
      Font::Font(v87, eFontMonospaced, 16.0, 0, 0);
    else
      v88 = 0;
    LOBYTE(v165) = 1;
    std::shared_ptr<Font>::_Resetp<Font>(&v149, v88);
    v89 = *(volatile signed __int32 **)(v79 + 132);
    v90 = v149._Ptr;
    *(_DWORD *)(v79 + 132) = v149._Rep;
    v149._Rep = 0;
    v149._Ptr = 0;
    *(_DWORD *)(v79 + 128) = v90;
    if ( v89 )
    {
      if ( !_InterlockedExchangeAdd(v89 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v89)(v89);
        if ( !_InterlockedExchangeAdd(v89 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v89 + 4))(v89);
      }
    }
    v91 = v148[1];
    *(_OWORD *)(v79 + 76) = _xmm;
    v156 = v79;
    *(_DWORD *)(LODWORD(v91) - 12) = v79;
    v92 = v7->_Mylast;
    if ( &v156 >= (int *)v92 || v7->_Myfirst > (unsigned int *)&v156 )
    {
      v99 = v7->_Myend;
      if ( v92 == v99 && !(v99 - v92) )
      {
        v100 = v92 - v7->_Myfirst;
        if ( v100 == 0x3FFFFFFF )
LABEL_162:
          std::_Xlength_error("vector<T> too long");
        v101 = v99 - v7->_Myfirst;
        _Count = v100 + 1;
        if ( 0x3FFFFFFF - (v101 >> 1) >= v101 )
          v102 = (v101 >> 1) + v101;
        else
          v102 = 0;
        if ( v102 < _Count )
          v102 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v7, v102);
      }
      v103 = v7->_Mylast;
      if ( v103 )
        *v103 = v79;
    }
    else
    {
      v93 = v7->_Myend;
      v94 = ((char *)&v156 - (char *)v7->_Myfirst) >> 2;
      if ( v92 == v93 && !(v93 - v92) )
      {
        v95 = v92 - v7->_Myfirst;
        if ( v95 == 0x3FFFFFFF )
          goto LABEL_162;
        v96 = v93 - v7->_Myfirst;
        _Count = v95 + 1;
        if ( 0x3FFFFFFF - (v96 >> 1) >= v96 )
          v97 = (v96 >> 1) + v96;
        else
          v97 = 0;
        if ( v97 < _Count )
          v97 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)v7, v97);
      }
      v98 = v7->_Mylast;
      if ( v98 )
        *v98 = v7->_Myfirst[v94];
    }
    ++v7->_Mylast;
    v104 = (float *)owner;
    LODWORD(h) = 284;
    *(_DWORD *)(v79 + 148) = owner;
    v105 = (Font *)operator new(LODWORD(h));
    v152._Ptr = v105;
    LOBYTE(v165) = 25;
    if ( v105 )
    {
      h = v104[60];
      v106 = std::to_wstring(&result, _Val);
      LOBYTE(v165) = 26;
      v3 |= 0x10u;
      _Count = v3;
      std::operator+<wchar_t>((std::wstring *)&v143[4], L"LABEL_TIME_L", v106);
      ksgui::Label::Label((ksgui::Label *)v105, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
      v108 = v107;
    }
    else
    {
      v108 = 0;
    }
    v165 = 1;
    if ( (v3 & 0x10) != 0 )
    {
      v3 &= 0xFFFFFFEF;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, word_17BE9D8, 0);
    LOBYTE(v165) = 28;
    (*(void (**)(unsigned int, std::wstring *))(*(_DWORD *)v108 + 68))(v108, &text);
    LOBYTE(v165) = 1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v109 = *(_DWORD *)v108;
    *(_DWORD *)(v108 + 152) = 1;
    (*(void (**)(unsigned int, int, int))(v109 + 28))(v108, 1109393408, 1101004800);
    v110 = *(float *)(v108 + 40) - *(float *)(v108 + 36);
    v111 = v148[0];
    v112 = *(float *)(v108 + 32) - *(float *)(v108 + 28);
    *(float *)(v108 + 36) = v148[0];
    v113 = v111 + v110;
    *(_DWORD *)(v108 + 28) = 1131413504;
    v114 = *(float *)(v108 + 264);
    v115 = v112 + 240.0;
    *(float *)(v108 + 40) = v113;
    *(float *)(v108 + 32) = v115;
    if ( v114 == 0.0 && *(float *)(v108 + 272) == 0.0 )
    {
      *(_DWORD *)(v108 + 264) = 1131413504;
      *(float *)(v108 + 272) = v111;
      *(float *)(v108 + 268) = v115;
      *(float *)(v108 + 276) = v113;
    }
    v116 = (Font *)operator new(0x18u);
    v151._Ptr = v116;
    LOBYTE(v165) = 29;
    if ( v116 )
      Font::Font(v116, eFontMonospaced, 16.0, 0, 0);
    else
      v117 = 0;
    LOBYTE(v165) = 1;
    v157._Ptr = 0;
    v157._Rep = 0;
    std::shared_ptr<Font>::_Resetp<Font>(&v157, v117);
    v118 = *(volatile signed __int32 **)(v108 + 132);
    v119 = v157._Ptr;
    *(_DWORD *)(v108 + 132) = v157._Rep;
    v157._Rep = 0;
    v157._Ptr = 0;
    *(_DWORD *)(v108 + 128) = v119;
    if ( v118 )
    {
      if ( !_InterlockedExchangeAdd(v118 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v118)(v118);
        if ( !_InterlockedExchangeAdd(v118 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v118 + 4))(v118);
      }
    }
    v120 = v148[1];
    *(_OWORD *)(v108 + 76) = _xmm;
    _Count = v108;
    *(_DWORD *)LODWORD(v120) = v108;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)v7, (int *)&_Count);
    v121 = (_QWORD *)v145;
    v2 = (char *)owner;
    v122 = v159;
    LODWORD(v148[1]) += 4;
    *(_DWORD *)(_Count + 148) = owner;
    v123 = _Val + 1;
    *v121 = v122;
    _Val = v123;
    v145 = (eFontType)(v121 + 1);
  }
  while ( v123 < 3 );
  LOBYTE(v165) = 1;
  v124 = v158;
  *(_DWORD *)&v143[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3f7155b984f8d27266a007d7497c8239_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v143[8] = v2;
  *(_DWORD *)&v143[20] = &v143[4];
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v158->evOnNewSession,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v143[4],
    v2);
  *(_DWORD *)&v143[4] = &std::_Func_impl<std::_Callable_obj<_lambda_c9b91ae19c4ec20e9e1041d264b58c4a_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v143[8] = v2;
  *(_DWORD *)&v143[12] = v124;
  *(_DWORD *)&v143[20] = &v143[4];
  LOBYTE(v165) = 1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v124->raceManager->evOnLapCompleted,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v143[4],
    v2);
  v125 = (Font *)operator new(0x11Cu);
  v151._Ptr = v125;
  LOBYTE(v165) = 32;
  if ( v125 )
  {
    h = *((float *)v2 + 60);
    *(_DWORD *)&v143[24] = 7;
    *(_DWORD *)&v143[20] = 0;
    *(_WORD *)&v143[4] = 0;
    std::wstring::assign((std::wstring *)&v143[4], L"TRACK_STATUS", 0xCu);
    ksgui::Label::Label((ksgui::Label *)v125, *(std::wstring *)&v143[4], (ksgui::GUI *)LODWORD(h));
    v127 = v126;
  }
  else
  {
    v127 = 0;
  }
  LOBYTE(v165) = 1;
  *((_DWORD *)v2 + 128) = v127;
  v128 = *(float *)(v127 + 264);
  v129 = *(float *)(v127 + 32) - *(float *)(v127 + 28);
  v130 = *(float *)(v127 + 40) - *(float *)(v127 + 36);
  *(_DWORD *)(v127 + 36) = 1133019136;
  *(_DWORD *)(v127 + 28) = 1084227584;
  v131 = v129 + 5.0;
  v132 = v130 + 273.0;
  *(float *)(v127 + 32) = v131;
  *(float *)(v127 + 40) = v132;
  if ( v128 == 0.0 && *(float *)(v127 + 272) == 0.0 )
  {
    *(_DWORD *)(v127 + 264) = 1084227584;
    *(_DWORD *)(v127 + 272) = 1133019136;
    *(float *)(v127 + 268) = v131;
    *(float *)(v127 + 276) = v132;
  }
  (*(void (**)(_DWORD, _DWORD, int))(**((_DWORD **)v2 + 128) + 28))(
    *((_DWORD *)v2 + 128),
    (float)(*((float *)v2 + 8) - *((float *)v2 + 7)) - 10.0,
    1101004800);
  v133 = *((_DWORD *)v2 + 128);
  v148[0] = 12.0;
  v145 = eFontProportional;
  *(_OWORD *)(v133 + 44) = _xmm;
  v134 = (int *)std::make_shared<Font,enum eFontType,float>(&v145, &v159, v148);
  v135 = *((_DWORD *)v2 + 128);
  v136 = 0;
  v137 = 0;
  if ( &v161 != v134 )
  {
    v137 = v134[1];
    v134[1] = 0;
    v136 = *v134;
    *v134 = 0;
  }
  v138 = *(volatile signed __int32 **)(v135 + 132);
  *(_DWORD *)(v135 + 132) = v137;
  *(_DWORD *)(v135 + 128) = v136;
  if ( v138 )
  {
    if ( !_InterlockedExchangeAdd(v138 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v138)(v138);
      if ( !_InterlockedExchangeAdd(v138 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v138 + 4))(v138);
    }
  }
  v139 = (volatile signed __int32 *)HIDWORD(v159);
  if ( HIDWORD(v159) )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(HIDWORD(v159) + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v139)(v139);
      if ( !_InterlockedDecrement(v139 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v139 + 4))(v139);
    }
  }
  v145 = *((_DWORD *)v2 + 128);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)v7, (int *)&v145);
  h = 300.0;
  *(_DWORD *)(v145 + 148) = v2;
  ksgui::Form::setSize((ksgui::Form *)v2, 285.0, h);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/wind_indicator.png", 0x1Eu);
  LOBYTE(v165) = 33;
  v140 = ResourceStore::getTexture(v158->game->graphics->resourceStore._Myptr, &v164, &text, 0);
  LOBYTE(v165) = 34;
  v141 = v140->kid;
  v142 = &v140->fileName;
  *((_DWORD *)v2 + 129) = v141;
  if ( v2 + 520 != (char *)v142 )
    std::wstring::assign((std::wstring *)(v2 + 520), v142, 0, 0xFFFFFFFF);
  LOBYTE(v165) = 33;
  OnSetupAppCreated::~OnSetupAppCreated(&v164);
  LOBYTE(v165) = 1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  (*(void (**)(char *, _DWORD))(*(_DWORD *)v2 + 76))(v2, *((_DWORD *)v2 + 64));
}
FormRealTimeTiming *FormRealTimeTiming::`vector deleting destructor'(FormRealTimeTiming *this, unsigned int a2)
{
  this->__vftable = (FormRealTimeTiming_vtbl *)&FormRealTimeTiming::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->txWindIndicator);
  this->__vftable = (FormRealTimeTiming_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormRealTimeTiming::render(FormRealTimeTiming *this, float dt)
{
  GraphicsManager *v3; // eax
  GLRenderer *v4; // esi
  FormRealTimeTiming_vtbl *v5; // eax
  ksgui::Label **v6; // esi
  CarAvatar *v7; // edi
  SessionType v8; // eax
  CarItemCmp *v9; // esi
  unsigned int v10; // edx
  float v11; // ecx
  CarAvatar *v12; // eax
  CarItemCmp *v13; // edx
  int v14; // ecx
  CarItemCmp *v15; // ecx
  CarItemCmp *v16; // eax
  int v17; // edx
  float v18; // eax
  RaceManager *v19; // ecx
  unsigned int v20; // eax
  std::wstring *v21; // eax
  int v22; // eax
  std::wstring *v23; // eax
  CarItemCmp *v24; // esi
  CarAvatar *v25; // edi
  RaceManager *v26; // ecx
  unsigned int v27; // eax
  std::wstring *v28; // eax
  int v29; // eax
  std::wstring *v30; // eax
  double v31; // st7
  std::wstring *v32; // eax
  RaceManager *v33; // ecx
  unsigned int v34; // edi
  __int128 v35; // xmm0
  unsigned int v36; // edi
  bool v37; // cf
  _DWORD *v38; // edi
  CarAvatar_vtbl *v39; // eax
  signed int v40; // edi
  signed int v41; // edi
  int v42; // ecx
  int v43; // eax
  __m128i v44; // xmm0
  int v45; // ecx
  CarItemCmp *v46; // esi
  RaceManager *v47; // ecx
  unsigned int v48; // eax
  std::wstring *v49; // eax
  int v50; // eax
  std::wstring *v51; // eax
  double v52; // st7
  std::wstring *v53; // eax
  unsigned int v54; // edi
  __int128 v55; // xmm0
  unsigned int v56; // edi
  CarAvatar_vtbl *v57; // ecx
  std::pair<void *,std::function<void __cdecl(OnValueChanged const &)> > *v58; // eax
  __m128i v59; // xmm0
  int v60; // ecx
  ksgui::Control *v61; // edi
  double v62; // xmm2_8
  double v63; // xmm0_8
  float v64; // xmm0_4
  Font *v65; // eax
  float v66; // xmm1_4
  __m128i v67; // xmm0
  double v68; // xmm0_8
  float v69; // xmm0_4
  std::_Ref_count_base *v70; // eax
  float v71; // xmm1_4
  __m128i v72; // xmm0
  double v73; // xmm0_8
  float v74; // xmm1_4
  ksgui::Control **v75; // eax
  float v76; // xmm0_4
  float v77; // xmm2_4
  unsigned int v78; // xmm0_4
  __m128i v79; // xmm0
  std::wostream *v80; // eax
  std::wostream *v81; // eax
  std::wostream *v82; // eax
  std::wostream *v83; // eax
  std::wostream *v84; // eax
  std::wostream *v85; // eax
  std::wostream *v86; // eax
  std::wostream *v87; // eax
  std::wstring *v88; // eax
  CarAvatar *v89; // eax
  float v90; // xmm2_4
  float v91; // xmm0_4
  int v92; // ecx
  unsigned int v93; // ecx
  int v94; // ecx
  CarAvatar *v95; // ecx
  int v96; // edx
  unsigned int v97; // edx
  int v98; // ecx
  unsigned int v99; // ecx
  float v100; // xmm0_4
  float v101; // xmm0_4
  float v102; // xmm0_4
  float v103; // [esp+5Ch] [ebp-188h]
  float width; // [esp+60h] [ebp-184h]
  int x; // [esp+64h] [ebp-180h]
  const char *xa; // [esp+64h] [ebp-180h]
  const char *x_4; // [esp+68h] [ebp-17Ch]
  CarAvatar *z; // [esp+6Ch] [ebp-178h]
  CarAvatar *za; // [esp+6Ch] [ebp-178h]
  int zb; // [esp+6Ch] [ebp-178h]
  const char *zc; // [esp+6Ch] [ebp-178h]
  __int64 v112; // [esp+70h] [ebp-174h]
  float carg; // [esp+80h] [ebp-164h]
  float carh; // [esp+80h] [ebp-164h]
  int car; // [esp+80h] [ebp-164h]
  CarAvatar *cara; // [esp+80h] [ebp-164h]
  CarAvatar *carb; // [esp+80h] [ebp-164h]
  CarAvatar *carc; // [esp+80h] [ebp-164h]
  CarAvatar *card; // [esp+80h] [ebp-164h]
  CarAvatar *care; // [esp+80h] [ebp-164h]
  CarAvatar *carf; // [esp+80h] [ebp-164h]
  bool v122; // [esp+87h] [ebp-15Dh]
  CarAvatar *v123; // [esp+88h] [ebp-15Ch]
  __int64 v124; // [esp+8Ch] [ebp-158h] BYREF
  unsigned int v125; // [esp+94h] [ebp-150h]
  ksgui::Control *v126; // [esp+98h] [ebp-14Ch]
  std::vector<CarItemCmp> v127; // [esp+9Ch] [ebp-148h] BYREF
  std::vector<CarItemCmp> v128; // [esp+A8h] [ebp-13Ch] BYREF
  unsigned int _Count; // [esp+B4h] [ebp-130h] BYREF
  float v130; // [esp+B8h] [ebp-12Ch]
  GLRenderer *v131; // [esp+BCh] [ebp-128h]
  float backDistance; // [esp+C0h] [ebp-124h] BYREF
  TemperatureInfo v; // [esp+C4h] [ebp-120h] BYREF
  vec4f v_8; // [esp+CCh] [ebp-118h] BYREF
  DynamicTrackStatus v135; // [esp+DCh] [ebp-108h] BYREF
  vec4f v136; // [esp+E4h] [ebp-100h] BYREF
  float v137; // [esp+F4h] [ebp-F0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v138; // [esp+F8h] [ebp-ECh] BYREF
  std::wstring v139; // [esp+1A8h] [ebp-3Ch] BYREF
  int v140; // [esp+1E0h] [ebp-4h]
  char vars0; // [esp+1E4h] [ebp+0h]

  v126 = this;
  *(_DWORD *)&v138.gap68[68] = 0;
  v3 = this->gui->graphics;
  carg = this->scaleMult * 20.0;
  *(_DWORD *)&v138.gap68[68] = 0;
  v4 = v3->gl;
  v5 = this->__vftable;
  v131 = v4;
  v139._Bx._Ptr = 0;
  v5->localToWorld(this, (vec2f *)&v124, (const vec2f *)&v138.gap68[68]);
  v_8 = (vec4f)_xmm;
  v136 = (vec4f)_xmm;
  *((float *)&v124 + 1) = (float)(this->scaleMult * 30.0) + *((float *)&v124 + 1);
  GLRenderer::color4f(v4, &v_8);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::vertex3f(v4, (float)(this->rect.right - this->rect.left) + *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &v136);
  *(float *)&v125 = carg * 7.0;
  GLRenderer::quad(
    v4,
    *(float *)&v124,
    this->scaleMult + *((float *)&v124 + 1),
    this->rect.right - this->rect.left,
    carg * 7.0,
    0,
    0);
  *((float *)&v124 + 1) = (float)((float)(this->scaleMult * 2.0) + *(float *)&v125) + *((float *)&v124 + 1);
  GLRenderer::color4f(v4, &v_8);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::vertex3f(v4, (float)(this->rect.right - this->rect.left) + *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::end(v4);
  *((float *)&v124 + 1) = (float)(this->scaleMult * 38.0) + *((float *)&v124 + 1);
  GLRenderer::color4f(v4, &v_8);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::vertex3f(v4, (float)(this->rect.right - this->rect.left) + *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::end(v4);
  GLRenderer::color4f(v4, &v136);
  carh = carg * 3.0;
  GLRenderer::quad(
    v4,
    *(float *)&v124,
    this->scaleMult + *((float *)&v124 + 1),
    this->rect.right - this->rect.left,
    carh,
    0,
    0);
  *((float *)&v124 + 1) = (float)((float)(this->scaleMult * 2.0) + carh) + *((float *)&v124 + 1);
  GLRenderer::color4f(v4, &v_8);
  GLRenderer::begin(v4, eLines, 0);
  GLRenderer::vertex3f(v4, *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::vertex3f(v4, (float)(this->rect.right - this->rect.left) + *(float *)&v124, *((float *)&v124 + 1), 0.0);
  GLRenderer::end(v4);
  v128._Myfirst = 0;
  v128._Mylast = 0;
  v128._Myend = 0;
  v140 = 1;
  v127._Myfirst = 0;
  v127._Mylast = 0;
  v127._Myend = 0;
  v6 = this->names;
  car = 7;
  do
  {
    v139._Mysize = 7;
    *(_DWORD *)&v139._Bx._Alias[12] = 0;
    *(_WORD *)&v138.gap68[68] = 0;
    std::wstring::assign((std::wstring *)&v138.gap68[68], word_17BE9D8, 0);
    LOBYTE(v140) = 2;
    v6[14]->setText(v6[14], (const std::wstring *)&v138.gap68[68]);
    LOBYTE(v140) = 1;
    if ( v139._Mysize >= 8 )
      operator delete(*(void **)&v138.gap68[68]);
    v139._Mysize = 7;
    *(_DWORD *)&v139._Bx._Alias[12] = 0;
    *(_WORD *)&v138.gap68[68] = 0;
    std::wstring::assign((std::wstring *)&v138.gap68[68], word_17BE9D8, 0);
    LOBYTE(v140) = 3;
    (*v6)->setText(*v6, (const std::wstring *)&v138.gap68[68]);
    LOBYTE(v140) = 1;
    if ( v139._Mysize >= 8 )
      operator delete(*(void **)&v138.gap68[68]);
    v139._Mysize = 7;
    *(_DWORD *)&v139._Bx._Alias[12] = 0;
    *(_WORD *)&v138.gap68[68] = 0;
    std::wstring::assign((std::wstring *)&v138.gap68[68], word_17BE9D8, 0);
    LOBYTE(v140) = 4;
    v6[7]->setText(v6[7], (const std::wstring *)&v138.gap68[68]);
    LOBYTE(v140) = 1;
    if ( v139._Mysize >= 8 )
      operator delete(*(void **)&v138.gap68[68]);
    ++v6;
    --car;
  }
  while ( car );
  v7 = Sim::getCar((Sim *)LODWORD(v126[1].rect.bottom), 0);
  v123 = v7;
  v8 = RaceManager::getCurrentSessionType(*(RaceManager **)(LODWORD(v126[1].rect.bottom) + 224));
  v9 = v128._Mylast;
  v10 = 1;
  v122 = v8 == Race;
  v125 = 1;
  v11 = v126[1].rect.bottom;
  if ( (unsigned int)((*(_DWORD *)(LODWORD(v11) + 284) - *(_DWORD *)(LODWORD(v11) + 280)) >> 2) > 1 )
  {
    do
    {
      cara = Sim::getCar((Sim *)LODWORD(v11), v10);
      if ( !CarAvatar::isConnected(cara) || CarAvatar::isInPitlane(cara) )
        goto LABEL_37;
      CarAvatar::getDistancesOnSpline(v7, cara, (float *)&v138.gap68[68], &backDistance);
      v12 = cara;
      _Count = (unsigned int)cara;
      if ( backDistance >= *(float *)&v138.gap68[68] )
      {
        v130 = *(float *)&v138.gap68[68];
        if ( &_Count >= (unsigned int *)v9 || (v13 = v128._Myfirst, v128._Myfirst > (CarItemCmp *)&_Count) )
        {
          if ( v9 == v128._Myend )
          {
            std::vector<CarItemCmp>::_Reserve(&v128, (unsigned int)&_Count);
            v9 = v128._Mylast;
            v12 = cara;
          }
          if ( v9 )
          {
            v9->car = v12;
            v9->dist = v130;
          }
          v128._Mylast = ++v9;
        }
        else
        {
          v14 = ((char *)&_Count - (char *)v128._Myfirst) >> 3;
          carb = (CarAvatar *)v14;
          if ( v9 == v128._Myend )
          {
            std::vector<CarItemCmp>::_Reserve(&v128, v14);
            v9 = v128._Mylast;
            v14 = (int)carb;
            v13 = v128._Myfirst;
          }
          if ( v9 )
          {
            v9->car = v13[v14].car;
            v9->dist = v13[v14].dist;
          }
          v128._Mylast = ++v9;
        }
        goto LABEL_37;
      }
      v15 = v127._Mylast;
      v130 = backDistance;
      if ( (CarItemCmp *)&_Count >= v127._Mylast || v127._Myfirst > (CarItemCmp *)&_Count )
      {
        if ( v127._Mylast == v127._Myend )
        {
          std::vector<CarItemCmp>::_Reserve(&v127, (unsigned int)v127._Mylast);
          v15 = v127._Mylast;
          v12 = cara;
        }
        if ( !v15 )
          goto LABEL_36;
        v15->car = v12;
        v18 = v130;
      }
      else
      {
        v16 = v127._Myfirst;
        v17 = ((char *)&_Count - (char *)v127._Myfirst) >> 3;
        carc = (CarAvatar *)v17;
        if ( v127._Mylast == v127._Myend )
        {
          std::vector<CarItemCmp>::_Reserve(&v127, (unsigned int)v127._Mylast);
          v15 = v127._Mylast;
          v17 = (int)carc;
          v16 = v127._Myfirst;
        }
        if ( !v15 )
          goto LABEL_36;
        v15->car = v16[v17].car;
        v18 = v127._Myfirst[v17].dist;
      }
      v15->dist = v18;
LABEL_36:
      v127._Mylast = v15 + 1;
LABEL_37:
      v10 = v125 + 1;
      v125 = v10;
      v11 = v126[1].rect.bottom;
    }
    while ( v10 < (*(_DWORD *)(LODWORD(v11) + 284) - *(_DWORD *)(LODWORD(v11) + 280)) >> 2 );
  }
  std::_Sort<CarItemCmp *,int,_lambda_68770df51abce0dd6fbff13ce66ec551_>(
    v128._Myfirst,
    v9,
    v9 - v128._Myfirst,
    (FormRealTimeTiming::render::__l16::<lambda_9a0e0571fd08e21a8eea0ed7aeaf8a4f>)v138.gap68[68]);
  std::_Sort<CarItemCmp *,int,_lambda_68770df51abce0dd6fbff13ce66ec551_>(
    v127._Myfirst,
    v127._Mylast,
    v127._Mylast - v127._Myfirst,
    (FormRealTimeTiming::render::__l16::<lambda_9a0e0571fd08e21a8eea0ed7aeaf8a4f>)v138.gap68[68]);
  v19 = v7->sim->raceManager;
  if ( v122 )
  {
    v20 = RaceManager::getCarRealTimePosition(v19, v7);
    v21 = std::to_wstring((std::wstring *)&v138.gap68[68], v20 + 1);
    LOBYTE(v140) = 5;
  }
  else
  {
    v22 = RaceManager::getCarLeaderboardPosition(v19, v7);
    v21 = std::to_wstring((std::wstring *)&v138.gap68[68], v22);
    LOBYTE(v140) = 6;
  }
  (*(void (**)(_DWORD, std::wstring *))(*(_DWORD *)LODWORD(v126[1].backTextureColor.x) + 68))(
    LODWORD(v126[1].backTextureColor.x),
    v21);
  LOBYTE(v140) = 1;
  if ( v139._Mysize >= 8 )
    operator delete(*(void **)&v138.gap68[68]);
  v23 = std::wstring::substr(&v7->driverInfo.name, (std::wstring *)&v138.gap68[68], 0, 0x14u);
  LOBYTE(v140) = 7;
  (*(void (**)(_DWORD, std::wstring *))(*(_DWORD *)LODWORD(v126[1].backColor.w) + 68))(
    LODWORD(v126[1].backColor.w),
    v23);
  LOBYTE(v140) = 1;
  if ( v139._Mysize >= 8 )
    operator delete(*(void **)&v138.gap68[68]);
  v139._Mysize = 7;
  *(_DWORD *)&v139._Bx._Alias[12] = 0;
  *(_WORD *)&v138.gap68[68] = 0;
  std::wstring::assign((std::wstring *)&v138.gap68[68], L"0.0", 3u);
  LOBYTE(v140) = 8;
  (*(void (**)(_DWORD, _BYTE *))(*(_DWORD *)LODWORD(v126[1].foreColor.z) + 68))(
    LODWORD(v126[1].foreColor.z),
    &v138.gap68[68]);
  LOBYTE(v140) = 1;
  if ( v139._Mysize >= 8 )
    operator delete(*(void **)&v138.gap68[68]);
  v24 = v128._Myfirst;
  *(float *)&v125 = 0.0;
  if ( v128._Myfirst != v128._Mylast )
  {
    v25 = (CarAvatar *)&v126[1].backColor.z;
    card = (CarAvatar *)&v126[1].backColor.z;
    while ( 1 )
    {
      z = v24->car;
      v26 = v24->car->sim->raceManager;
      if ( v122 )
      {
        v27 = RaceManager::getCarRealTimePosition(v26, z);
        v28 = std::to_wstring((std::wstring *)&v138.gap68[68], v27 + 1);
        LOBYTE(v140) = 9;
      }
      else
      {
        v29 = RaceManager::getCarLeaderboardPosition(v26, z);
        v28 = std::to_wstring((std::wstring *)&v138.gap68[68], v29);
        LOBYTE(v140) = 10;
      }
      (*((void (**)(std::pair<void *,std::function<void __cdecl(OnValueChanged const &)> > *, std::wstring *))v25->evOnGearChanged.handlers._Myfirst->first
       + 17))(
        v25->evOnGearChanged.handlers._Myfirst,
        v28);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v30 = std::wstring::substr(&v24->car->driverInfo.name, (std::wstring *)&v138.gap68[68], 0, 0x14u);
      LOBYTE(v140) = 11;
      (*((void (**)(CarAvatar_vtbl *, std::wstring *))v25->~GameObject + 17))(v25->__vftable, v30);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v31 = CarAvatar::getTimeDifferenceOnSpline(v123, v24->car);
      v32 = timeToDiffShort((std::wstring *)&v138.gap68[68], (int)v31);
      LOBYTE(v140) = 12;
      (*(void (**)(unsigned int, std::wstring *))(*(_DWORD *)v25->name._Myres + 68))(v25->name._Myres, v32);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v33 = v123->sim->raceManager;
      if ( v122 )
      {
        v34 = RaceManager::getLapCount(v33, v123);
        if ( v34 <= RaceManager::getLapCount(v123->sim->raceManager, v24->car) )
        {
          v36 = RaceManager::getLapCount(v123->sim->raceManager, v123);
          v37 = v36 < RaceManager::getLapCount(v123->sim->raceManager, v24->car);
          v38 = &card->__vftable;
          v39 = card->__vftable;
          if ( v37 )
            v35 = _xmm;
          else
            v35 = _xmm;
          goto LABEL_70;
        }
        v35 = _xmm;
      }
      else
      {
        v40 = RaceManager::getCarLeaderboardPosition(v33, v123);
        if ( v40 <= (int)RaceManager::getCarLeaderboardPosition(v123->sim->raceManager, v24->car) )
        {
          v41 = RaceManager::getCarLeaderboardPosition(v123->sim->raceManager, v123);
          if ( v41 >= (int)RaceManager::getCarLeaderboardPosition(v123->sim->raceManager, v24->car) )
            v35 = _xmm;
          else
            v35 = _xmm;
        }
        else
        {
          v35 = _xmm;
        }
      }
      v38 = &card->__vftable;
      v39 = card->__vftable;
LABEL_70:
      *(_OWORD *)&v39[3].update = v35;
      *(__m128i *)(v38[7] + 76) = _mm_loadu_si128((const __m128i *)(*v38 + 76));
      v42 = *v38;
      v43 = v38[14];
      v25 = (CarAvatar *)(v38 - 1);
      card = v25;
      v44 = _mm_loadu_si128((const __m128i *)(v42 + 76));
      v45 = ++v125;
      *(__m128i *)(v43 + 76) = v44;
      if ( v45 <= 2 && ++v24 != v128._Mylast )
        continue;
      v7 = v123;
      break;
    }
  }
  v46 = v127._Myfirst;
  *(float *)&v125 = 0.0;
  if ( v127._Myfirst != v127._Mylast )
  {
    care = (CarAvatar *)&v126[1].borderColor;
    do
    {
      za = v46->car;
      v47 = v46->car->sim->raceManager;
      if ( v122 )
      {
        v48 = RaceManager::getCarRealTimePosition(v47, za);
        v49 = std::to_wstring((std::wstring *)&v138.gap68[68], v48 + 1);
        LOBYTE(v140) = 13;
      }
      else
      {
        v50 = RaceManager::getCarLeaderboardPosition(v47, za);
        v49 = std::to_wstring((std::wstring *)&v138.gap68[68], v50);
        LOBYTE(v140) = 14;
      }
      (*((void (**)(std::pair<void *,std::function<void __cdecl(OnValueChanged const &)> > *, std::wstring *))care->evOnGearChanged.handlers._Myfirst->first
       + 17))(
        care->evOnGearChanged.handlers._Myfirst,
        v49);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v51 = std::wstring::substr(&v46->car->driverInfo.name, (std::wstring *)&v138.gap68[68], 0, 0x14u);
      LOBYTE(v140) = 15;
      (*((void (**)(CarAvatar_vtbl *, std::wstring *))care->~GameObject + 17))(care->__vftable, v51);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v52 = CarAvatar::getTimeDifferenceOnSpline(v7, v46->car);
      v53 = timeToDiffShort((std::wstring *)&v138.gap68[68], (int)v52);
      LOBYTE(v140) = 16;
      (*(void (**)(unsigned int, std::wstring *))(*(_DWORD *)care->name._Myres + 68))(care->name._Myres, v53);
      LOBYTE(v140) = 1;
      if ( v139._Mysize >= 8 )
        operator delete(*(void **)&v138.gap68[68]);
      v54 = RaceManager::getLapCount(v7->sim->raceManager, v7);
      if ( v54 <= RaceManager::getLapCount(v123->sim->raceManager, v46->car) )
      {
        v56 = RaceManager::getLapCount(v123->sim->raceManager, v123);
        if ( v56 >= RaceManager::getLapCount(v123->sim->raceManager, v46->car) )
          v55 = _xmm;
        else
          v55 = _xmm;
      }
      else
      {
        v55 = _xmm;
      }
      *(_OWORD *)&care->__vftable[3].update = v55;
      *(__m128i *)(care->name._Myres + 76) = _mm_loadu_si128((const __m128i *)&care->__vftable[3].update);
      v57 = care->__vftable;
      v58 = care->evOnGearChanged.handlers._Myfirst;
      care = (CarAvatar *)((char *)care + 4);
      v59 = _mm_loadu_si128((const __m128i *)&v57[3].update);
      v60 = ++v125;
      *(__m128i *)((char *)&v58[2].second._Space + 4) = v59;
      if ( v60 > 2 )
        break;
      v7 = v123;
      ++v46;
    }
    while ( v46 != v127._Mylast );
  }
  v61 = v126;
  v62 = DOUBLE_1_0;
  v63 = (*(double *)(*(_DWORD *)(LODWORD(v126[1].rect.bottom) + 4) + 24) - *(double *)&v126[1].fontAlign) * 0.0001;
  if ( v63 <= 1.0 )
  {
    if ( v63 < 0.0 )
      v63 = 0.0;
  }
  else
  {
    v63 = DOUBLE_1_0;
  }
  v64 = v63;
  v65 = v126[1].font._Ptr;
  *(_DWORD *)&v139._Bx._Alias[8] = 1065353216;
  v66 = 1.0 - (float)(v64 * 0.30000001);
  *(float *)&v138.gap68[68] = *(float *)&v126[1].backTexture.fileName._Bx._Ptr * v66;
  *(float *)&v139._Bx._Ptr = *(float *)&v126[1].backTexture.fileName._Bx._Alias[4] * v66;
  *(float *)&v139._Bx._Alias[4] = *(float *)&v126[1].backTexture.fileName._Bx._Alias[8] * v66;
  v67 = _mm_load_si128((const __m128i *)&v138.gap68[68]);
  *(__m128i *)&v65[3].shadowed = v67;
  *(__m128i *)(v61[1].controls._Mylast + 19) = v67;
  v68 = (*(double *)(*(_DWORD *)(LODWORD(v61[1].rect.bottom) + 4) + 24) - *(double *)&v61[1].evClicked.handlers._Mylast)
      * 0.0001;
  if ( v68 <= 1.0 )
  {
    if ( v68 < 0.0 )
      v68 = 0.0;
  }
  else
  {
    v68 = DOUBLE_1_0;
  }
  v69 = v68;
  v70 = v61[1].font._Rep;
  *(_DWORD *)&v139._Bx._Alias[8] = 1065353216;
  v71 = 1.0 - (float)(v69 * 0.30000001);
  *(float *)&v138.gap68[68] = *(float *)&v61[1].backTexture.fileName._Mysize * v71;
  *(float *)&v139._Bx._Ptr = *(float *)&v61[1].backTexture.fileName._Myres * v71;
  *(float *)&v139._Bx._Alias[4] = *(float *)&v61[1].drawBorder * v71;
  v72 = _mm_load_si128((const __m128i *)&v138.gap68[68]);
  *(__m128i *)&v70[6]._Uses = v72;
  *(__m128i *)(v61[1].controls._Myend + 19) = v72;
  v73 = (*(double *)(*(_DWORD *)(LODWORD(v61[1].rect.bottom) + 4) + 24) - *(double *)&v61[1].tag) * 0.0001;
  if ( v73 <= 1.0 )
  {
    if ( v73 >= 0.0 )
      v62 = (*(double *)(*(_DWORD *)(LODWORD(v61[1].rect.bottom) + 4) + 24) - *(double *)&v61[1].tag) * 0.0001;
    else
      v62 = 0.0;
  }
  v74 = *(float *)&v61[1].text._Bx._Ptr;
  v75 = v61[1].controls._Myfirst;
  v76 = v62;
  v77 = 1.0 - (float)(v76 * 0.30000001);
  *(float *)&v78 = *(float *)&v61[1].text._Bx._Alias[4] * v77;
  *(float *)&v138.gap68[68] = v61[1].fontScale * v77;
  *(_QWORD *)&v139._Bx._Alias[4] = v78 | 0x3F80000000000000i64;
  *(float *)&v139._Bx._Ptr = v74 * v77;
  v79 = _mm_load_si128((const __m128i *)&v138.gap68[68]);
  *(__m128i *)(v75 + 19) = v79;
  v61[1].parent->foreColor = (vec4f)v79;
  PhysicsAvatar::getTemperatureInfo(*(PhysicsAvatar **)(LODWORD(v61[1].rect.bottom) + 232), &v);
  PhysicsAvatar::getDynamicTrackStatus(*(PhysicsAvatar **)(LODWORD(v61[1].rect.bottom) + 232), &v135);
  v137 = COERCE_FLOAT(&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'});
  HIDWORD(v138._Chcount) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(&v138.gap60[4]);
  v139._Mysize = 1;
  std::wiostream::basic_iostream<wchar_t>(v138.gap10, &v138.gap10[24], 0);
  *(_DWORD *)&v138.gap10[*(_DWORD *)(*(_DWORD *)v138.gap10 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v138._Chcount + *(_DWORD *)(*(_DWORD *)v138.gap10 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v138.gap10
                                                                                               + 4)
                                                                                   - 104;
  std::wstreambuf::wstreambuf(&v138.gap10[24]);
  *(_DWORD *)&v138.gap10[24] = &std::wstringbuf::`vftable';
  *(_DWORD *)v138.gap60 = 0;
  *(_DWORD *)&v138.gap60[4] = 0;
  HIDWORD(v112) = (int)(float)(v137 * 100.0);
  zb = (int)v_8.w;
  x = (int)*(float *)&v135.enabled;
  v80 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v138.gap10[16], "ROAD: ");
  v81 = (std::wostream *)std::wostream::operator<<(v80, x);
  v82 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v81, xa);
  v83 = (std::wostream *)std::wostream::operator<<(v82, "C AIR: ");
  v84 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v83, x_4);
  v85 = (std::wostream *)std::wostream::operator<<(v84, zb);
  v86 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v85, zc);
  v87 = (std::wostream *)std::wostream::operator<<(v86, "C GRIP: ");
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v87, (const char *)v112);
  v88 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v138, &v139);
  vars0 = 21;
  LODWORD(v112) = v88;
  (*(void (**)(unsigned int))(*(_DWORD *)v61[1].text._Myres + 68))(v61[1].text._Myres);
  LOBYTE(v140) = 20;
  if ( v139._Mysize >= 8 )
    operator delete(*(void **)&v138.gap68[68]);
  ksgui::Control::render(v61, (int)v61, (int)operator delete, dt, v112, COERCE_FLOAT("% WIND: "));
  GraphicsManager::setTexture(
    *(GraphicsManager **)(*(_DWORD *)(LODWORD(v61[1].rect.bottom) + 4) + 192),
    0,
    (const Texture *)&v61[1].isHighlight);
  v89 = Sim::getCar((Sim *)LODWORD(v61[1].rect.bottom), 0);
  LODWORD(v90) = LODWORD(v89->physicsState.worldMatrix.M33) ^ _xmm;
  *(_DWORD *)&v138.gap68[68] = LODWORD(v89->physicsState.worldMatrix.M31) ^ _xmm;
  *(float *)&v139._Bx._Alias[4] = v90;
  if ( *(float *)&v138.gap68[68] != 0.0 || v90 != 0.0 )
  {
    v91 = fsqrt((float)(v90 * v90) + (float)(*(float *)&v138.gap68[68] * *(float *)&v138.gap68[68]));
    if ( v91 != 0.0 )
    {
      *(float *)&v139._Bx._Alias[4] = v90 * (float)(1.0 / v91);
      *(float *)&v138.gap68[68] = (float)(1.0 / v91) * *(float *)&v138.gap68[68];
    }
    *(float *)&v138.gap68[68] = atan2(*(float *)&v138.gap68[68], *(float *)&v139._Bx._Alias[4]);
    *(_DWORD *)&v138.gap68[68] = COERCE_UNSIGNED_INT(*(float *)&v138.gap68[68] * 57.29578) ^ _xmm;
    GLRenderer::color3f(v131, 1.0, 1.0, 1.0);
    v92 = *(_DWORD *)&v61[1].isHighlight;
    if ( v92 )
      v93 = *(unsigned int *)(v92 + 40);
    else
      *(float *)&v93 = 0.0;
    v125 = v93;
    v94 = *(_DWORD *)&v61[1].isHighlight;
    if ( v94 )
      v95 = *(CarAvatar **)(v94 + 36);
    else
      v95 = 0;
    v96 = *(_DWORD *)&v61[1].isHighlight;
    carf = v95;
    if ( v96 )
      v97 = *(_DWORD *)(v96 + 40);
    else
      v97 = 0;
    v98 = *(_DWORD *)&v61[1].isHighlight;
    if ( v98 )
      v99 = *(_DWORD *)(v98 + 36);
    else
      v99 = 0;
    v100 = (float)v125;
    width = v100;
    v101 = (float)(unsigned int)carf;
    v103 = v101;
    v102 = (float)v97;
    GLRenderer::quadCentredRotated(
      v131,
      (int)operator delete,
      (float)(v61->rect.right - (float)((float)v99 * 0.5)) - 1.0,
      (float)(*(float *)(v61[1].text._Myres + 36) + v61->rect.top) + (float)(v102 * 0.5),
      v103,
      width,
      (float)(*(float *)(*(_DWORD *)(LODWORD(v61[1].rect.bottom) + 232) + 548) - *(float *)&v138.gap68[68]) * 0.017453,
      1,
      0);
  }
  LOBYTE(v140) = 1;
  *(_DWORD *)((char *)&v137 + *(_DWORD *)(LODWORD(v137) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v136.w + *(_DWORD *)(LODWORD(v137) + 4)) = *(_DWORD *)(LODWORD(v137) + 4) - 104;
  *(_DWORD *)&v138.gap10[4] = &std::wstringbuf::`vftable';
  if ( (v138.gap10[64] & 1) != 0 )
    operator delete(**(void ***)&v138.gap10[16]);
  std::wstreambuf::setg(&v138.gap10[4], 0, 0, 0);
  std::wstreambuf::setp(&v138.gap10[4], 0, 0);
  *(_DWORD *)&v138.gap10[64] &= 0xFFFFFFFE;
  *(_DWORD *)&v138.gap10[60] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v138.gap10[4]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v138.gap10[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v138.gap60[4]);
  if ( v127._Myfirst )
    operator delete(v127._Myfirst);
  if ( v128._Myfirst )
    operator delete(v128._Myfirst);
}
