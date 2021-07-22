#include "tyresapp.h
void __userpurge TyresApp::TyresApp(TyresApp *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *icar)
{
  Game *v4; // eax
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float w; // xmm0_4
  Font *v11; // eax
  Font *v12; // eax
  const std::wstring *v13; // eax
  void (__cdecl *v14)(void *); // eax
  float v15; // xmm1_4
  int v16; // esi
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // ecx
  const wchar_t *v21; // eax
  const wchar_t *v22; // ecx
  ksgui::Control *v24; // eax
  ksgui::Control *v25; // edx
  std::_Ref_count_base *v26; // eax
  volatile signed __int32 *v27; // esi
  int v28; // esi
  ksgui::Control *v29; // ecx
  float v30; // xmm4_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  std::vector<unsigned int> *v37; // ecx
  ksgui::Control **v38; // eax
  int v39; // edx
  unsigned int *v40; // ecx
  int v41; // esi
  std::vector<unsigned int> *v42; // ecx
  int v43; // esi
  unsigned int *v44; // eax
  unsigned int *v45; // ecx
  _DWORD *v46; // eax
  ksgui::Label *v47; // esi
  int v48; // ecx
  ksgui::Label *v49; // eax
  const wchar_t *v50; // ecx
  int v52; // eax
  int v53; // edx
  std::_Ref_count_base *v54; // eax
  volatile signed __int32 *v55; // esi
  int v56; // esi
  int v57; // ecx
  const wchar_t *v58; // esi
  int v59; // ecx
  const wchar_t *v60; // ecx
  int v62; // eax
  int v63; // edx
  std::_Ref_count_base *v64; // eax
  volatile signed __int32 *v65; // esi
  int v66; // esi
  int v67; // eax
  int v68; // esi
  int v69; // edx
  float v70; // xmm7_4
  float *v71; // ecx
  float v72; // xmm3_4
  float v73; // xmm5_4
  float v74; // xmm0_4
  float v75; // xmm2_4
  float v76; // xmm1_4
  float v77; // xmm3_4
  float v78; // xmm4_4
  float v79; // xmm0_4
  float *v80; // ecx
  float v81; // xmm0_4
  float v82; // xmm4_4
  float v83; // xmm1_4
  float v84; // xmm2_4
  float v85; // xmm3_4
  float v86; // xmm4_4
  float *v87; // ecx
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm3_4
  float v91; // xmm2_4
  float v92; // xmm3_4
  float v93; // xmm2_4
  int v94; // edx
  float v95; // xmm7_4
  float v96; // xmm1_4
  float *v97; // ecx
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm0_4
  float v101; // xmm3_4
  float v102; // xmm4_4
  float v103; // xmm0_4
  float v104; // xmm3_4
  float *v105; // ecx
  float v106; // xmm2_4
  float v107; // xmm3_4
  float v108; // xmm0_4
  float v109; // xmm1_4
  float v110; // xmm4_4
  float v111; // xmm0_4
  float *v112; // ecx
  float v113; // xmm0_4
  float v114; // xmm3_4
  float v115; // xmm4_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  float v118; // xmm3_4
  float v119; // xmm4_4
  float *v120; // ecx
  float v121; // xmm1_4
  float v122; // xmm0_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm3_4
  float v126; // xmm3_4
  float v127; // xmm2_4
  float v128; // xmm4_4
  float v129; // xmm1_4
  float v130; // xmm3_4
  float v131; // xmm3_4
  float v132; // xmm2_4
  float v133; // xmm0_4
  float v134; // xmm4_4
  float v135; // xmm1_4
  float v136; // xmm3_4
  ksgui::Control **v137; // ecx
  int v138; // eax
  std::vector<int> *v139; // esi
  int *v140; // esi
  ksgui::Control **v141; // edx
  int v142; // eax
  int v143; // ecx
  unsigned int v144; // edx
  unsigned int v145; // edx
  int *v146; // ecx
  ksgui::Label *v147; // ecx
  int v148; // eax
  int v149; // esi
  signed int v150; // ecx
  const wchar_t *v151; // eax
  int *v152; // edx
  int *v153; // esi
  int v154; // ecx
  unsigned int v155; // edx
  unsigned int v156; // edx
  float *v157; // eax
  const wchar_t *v158; // ecx
  ksgui::Control *v160; // eax
  const wchar_t *v161; // edx
  signed int v162; // ecx
  const wchar_t *v163; // ecx
  ksgui::Control *v165; // eax
  ksgui::Control *v166; // ecx
  std::wstring *v167; // ecx
  unsigned int v168; // edx
  unsigned int v169; // esi
  ksgui::Control *v170; // ecx
  ksgui::Control_vtbl *v171; // eax
  float v172; // xmm0_4
  int v173; // edx
  unsigned int v174; // eax
  float v175; // xmm2_4
  float v176; // xmm0_4
  float v177; // xmm1_4
  unsigned int v178; // eax
  float v179; // xmm0_4
  ksgui::ProgressBar *v180; // esi
  ksgui::ProgressBar *v181; // eax
  int v182; // esi
  float v183; // xmm6_4
  float v184; // xmm0_4
  float v185; // xmm1_4
  ksgui::Control *v186; // ecx
  float v187; // xmm1_4
  float v188; // xmm4_4
  float v189; // xmm0_4
  float v190; // xmm2_4
  float v191; // xmm3_4
  ksgui::Control *v192; // ecx
  float v193; // xmm1_4
  float v194; // xmm0_4
  float v195; // xmm4_4
  float v196; // xmm2_4
  float v197; // xmm3_4
  float v198; // xmm4_4
  float v199; // xmm2_4
  float v200; // xmm3_4
  float v201; // xmm4_4
  float v202; // xmm2_4
  float v203; // xmm1_4
  float v204; // xmm0_4
  float v205; // xmm3_4
  ksgui::Control *v206; // ecx
  float v207; // xmm4_4
  float v208; // xmm0_4
  float v209; // xmm3_4
  float v210; // xmm2_4
  float v211; // xmm1_4
  float v212; // xmm4_4
  float v213; // xmm1_4
  ksgui::ProgressBar *v214; // ecx
  float v215; // xmm0_4
  float v216; // xmm1_4
  float v217; // xmm3_4
  float v218; // xmm4_4
  float v219; // xmm1_4
  float v220; // xmm0_4
  float v221; // xmm1_4
  ksgui::Label *v222; // esi
  ksgui::Control *v223; // eax
  ksgui::Control *v224; // ecx
  float v225; // xmm1_4
  float v226; // xmm2_4
  float v227; // xmm0_4
  float v228; // xmm3_4
  float v229; // xmm2_4
  float v230; // xmm2_4
  float v231; // xmm0_4
  float v232; // xmm4_4
  float v233; // xmm0_4
  int v234; // eax
  bool v235; // cf
  vec3f *v236; // eax
  vec3f *v237; // eax
  vec3f *v238; // eax
  vec3f *v239; // eax
  vec3f *v240; // eax
  vec3f *v241; // eax
  vec3f *v242; // eax
  vec3f *v243; // eax
  std::_Ref_count_base *v244; // esi
  _BYTE v245[28]; // [esp+34h] [ebp-130h] BYREF
  float h; // [esp+50h] [ebp-114h]
  TyresApp *v247; // [esp+60h] [ebp-104h]
  int v248; // [esp+64h] [ebp-100h] BYREF
  ksgui::Label *v249; // [esp+68h] [ebp-FCh] BYREF
  unsigned int v250; // [esp+6Ch] [ebp-F8h]
  std::shared_ptr<Font> _Right; // [esp+70h] [ebp-F4h] BYREF
  int v252; // [esp+78h] [ebp-ECh]
  float v253; // [esp+7Ch] [ebp-E8h]
  int v254; // [esp+80h] [ebp-E4h]
  int v255; // [esp+84h] [ebp-E0h]
  ksgui::Label *v256; // [esp+88h] [ebp-DCh]
  int v257; // [esp+8Ch] [ebp-D8h]
  int _Val; // [esp+90h] [ebp-D4h] BYREF
  INIReader v259; // [esp+94h] [ebp-D0h] BYREF
  std::wstring key; // [esp+D8h] [ebp-8Ch] BYREF
  Texture result; // [esp+F0h] [ebp-74h] BYREF
  std::wstring v262; // [esp+10Ch] [ebp-58h] BYREF
  std::wstring text; // [esp+124h] [ebp-40h] BYREF
  std::wstring section; // [esp+13Ch] [ebp-28h] BYREF
  int v265; // [esp+160h] [ebp-4h]

  v262._Myres = 0;
  v250 = 0;
  LODWORD(h) = 1;
  v4 = icar->game;
  v247 = this;
  *(_DWORD *)&v245[24] = v4->gui;
  *(_DWORD *)&v245[20] = 7;
  *(_DWORD *)&v245[16] = 0;
  *(_WORD *)v245 = 0;
  std::wstring::assign((std::wstring *)v245, L"TYRES_APP", 9u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v245, *(ksgui::GUI **)&v245[24], SLOBYTE(h));
  v265 = 0;
  this->__vftable = (TyresApp_vtbl *)&TyresApp::`vftable';
  this->car = icar;
  this->FWIDTH = 237.0;
  this->FHEIGHT = 257.0;
  this->IMO_WIDTH = 111.0;
  this->IMO_HEIGHT = 15.0;
  this->MARGIN = 1.0;
  this->PRG_HEIGHT = 5.0;
  this->TYRE_HEIGHT = 30.0;
  this->TYRE_WIDTH = 20.0;
  this->TOP_MARGIN = 32.0;
  this->LEFT_MARGIN = 0.0;
  this->IMO_SEP = 15.0;
  this->FRONT_REAR_SEP = 180.0;
  this->WEAR_WIDTH = 5.0;
  this->WEAR_HEIGHT = 35.0;
  this->TYRE_V_SPACE = 5.0;
  this->coreText._Myres = 7;
  this->coreText._Mysize = 0;
  LODWORD(h) = 6;
  this->coreText._Bx._Buf[0] = 0;
  std::wstring::assign((std::wstring *)&this->coreText, L"Core  ", LODWORD(h));
  LOBYTE(v265) = 1;
  this->backColor.x = 0.0;
  this->backColor.y = 0.0;
  this->backColor.z = 0.0;
  this->backColor.w = 0.40000001;
  this->IMOColor.x = 1.0;
  this->IMOColor.y = 1.0;
  this->IMOColor.z = 1.0;
  this->IMOColor.w = 1.0;
  this->IMODarkColor.x = 0.0;
  this->IMODarkColor.y = 0.050000001;
  this->IMODarkColor.z = 0.079999998;
  this->IMODarkColor.w = 0.33000001;
  this->IMOFontColor.x = 0.0;
  this->IMOFontColor.y = 0.0;
  this->IMOFontColor.z = 0.0;
  this->IMOFontColor.w = 1.0;
  this->farColdColor.x = 0.0;
  this->farColdColor.y = 0.0;
  this->farColdColor.z = 1.0;
  this->farHotColor.x = 1.0;
  this->farHotColor.y = 0.0;
  this->farHotColor.z = 0.0;
  this->nearColdColor.x = 0.0;
  this->nearColdColor.y = 0.5;
  this->nearColdColor.z = 1.0;
  this->nearHotColor.x = 1.0;
  this->nearHotColor.y = 0.5;
  this->nearHotColor.z = 0.0;
  this->optimalColor.x = 0.0;
  this->optimalColor.y = 1.0;
  this->optimalColor.z = 0.0;
  this->goodColor.x = 0.0;
  this->goodColor.y = 1.0;
  this->goodColor.z = 0.0;
  this->usedColor.x = 1.0;
  this->usedColor.y = 1.0;
  this->usedColor.z = 0.0;
  this->badColor.x = 1.0;
  this->badColor.y = 0.0;
  this->badColor.z = 0.0;
  v5 = this->TOP_MARGIN;
  v6 = this->LEFT_MARGIN;
  v7 = this->FHEIGHT - v5;
  this->backgroundRect.top = v5;
  this->backgroundRect.left = v6;
  v8 = v6 + this->FWIDTH;
  h = 0.0;
  *(_DWORD *)&v245[24] = word_17BE9D8;
  this->backgroundRect.right = v8;
  this->backgroundRect.bottom = v5 + v7;
  this->pos[0].x = 0.0;
  this->pos[0].y = 0.0;
  this->pos[1].x = 0.0;
  this->pos[1].y = 0.0;
  this->pos[2].x = 0.0;
  this->pos[2].y = 0.0;
  this->pos[3].x = 0.0;
  this->pos[3].y = 0.0;
  this->NEAR_LIMIT = 0.99000001;
  this->FAR_LIMIT = 0.98000002;
  this->currentCompound._Myres = 7;
  this->currentCompound._Mysize = 0;
  this->currentCompound._Bx._Buf[0] = 0;
  std::wstring::assign(&this->currentCompound, *(const wchar_t **)&v245[24], LODWORD(h));
  LOBYTE(v265) = 2;
  v9 = this->FHEIGHT;
  this->NearTempLimit = 1.0;
  this->FarTempLimit = 1.0;
  h = v9;
  w = this->FWIDTH;
  this->useTempInF = 0;
  ksgui::Form::setSize(this, w, h);
  LODWORD(h) = 24;
  *(_WORD *)&this->devApp = 256;
  v11 = (Font *)operator new(LODWORD(h));
  v262._Myres = (unsigned int)v11;
  LOBYTE(v265) = 3;
  if ( v11 )
    Font::Font(v11, eFontProportional, 10.0, 0, 0);
  else
    v12 = 0;
  LOBYTE(v265) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v12);
  LOBYTE(v265) = 4;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, (const wchar_t *)&stru_17C4688.rectBase.right, 5u);
  LOBYTE(v265) = 5;
  v13 = acTranslate(&result.fileName, &text);
  LOBYTE(v265) = 6;
  this->formTitle->setText(this->formTitle, v13);
  v14 = operator delete;
  if ( result.fileName._Myres >= 8 )
  {
    operator delete(result.fileName._Bx._Ptr);
    v14 = operator delete;
  }
  LOBYTE(v265) = 4;
  result.fileName._Myres = 7;
  result.fileName._Mysize = 0;
  result.fileName._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v14(text._Bx._Ptr);
  v15 = this->TOP_MARGIN;
  v16 = 0;
  v262._Mysize = LODWORD(this->LEFT_MARGIN);
  LODWORD(this->pos[0].x) = v262._Mysize;
  *(float *)&v262._Myres = v15;
  this->pos[0].y = v15;
  v17 = this->IMO_WIDTH + this->LEFT_MARGIN;
  v262._Myres = LODWORD(this->TOP_MARGIN);
  v253 = 0.0;
  v255 = 0;
  *(float *)&v262._Mysize = v17 + this->IMO_SEP;
  LODWORD(this->pos[1].x) = v262._Mysize;
  LODWORD(this->pos[1].y) = v262._Myres;
  v18 = this->TOP_MARGIN;
  v262._Mysize = LODWORD(this->LEFT_MARGIN);
  LODWORD(this->pos[2].x) = v262._Mysize;
  *(float *)&v262._Myres = v18;
  this->pos[2].y = v18;
  v19 = this->IMO_WIDTH + this->LEFT_MARGIN;
  v262._Myres = LODWORD(this->TOP_MARGIN);
  *(float *)&v262._Mysize = v19 + this->IMO_SEP;
  LODWORD(this->pos[3].x) = v262._Mysize;
  LODWORD(this->pos[3].y) = v262._Myres;
  do
  {
    if ( v16 >= 2 )
      v253 = this->FRONT_REAR_SEP;
    *(float *)&v256 = COERCE_FLOAT(operator new(0x11Cu));
    LOBYTE(v265) = 7;
    if ( *(float *)&v256 == 0.0 )
    {
      v25 = 0;
    }
    else
    {
      h = *(float *)&this->gui;
      v20 = 0;
      v21 = &aCore_0[v16];
      *(_DWORD *)&v245[24] = 7;
      *(_DWORD *)&v245[20] = 0;
      *(_WORD *)&v245[4] = 0;
      if ( *v21 )
      {
        v22 = &aCore_0[v16];
        _Val = (int)(v21 + 1);
        while ( *v22++ )
          ;
        v21 = &aCore_0[v16];
        v20 = ((int)v22 - _Val) >> 1;
      }
      std::wstring::assign((std::wstring *)&v245[4], v21, v20);
      ksgui::Label::Label(v256, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
      v25 = v24;
    }
    LOBYTE(v265) = 4;
    v26 = _Right._Rep;
    this->lblCore[v16] = v25;
    if ( v26 )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)&v26->_Uses, 1u);
      v26 = _Right._Rep;
    }
    v27 = (volatile signed __int32 *)v25->font._Rep;
    v25->font._Rep = v26;
    v25->font._Ptr = _Right._Ptr;
    if ( v27 )
    {
      if ( !_InterlockedExchangeAdd(v27 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v27)(v27);
        if ( !_InterlockedExchangeAdd(v27 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v27 + 4))(v27);
      }
    }
    LODWORD(h) = std::operator+<wchar_t>(&key, &this->coreText, L"--- �C");
    v28 = v255;
    LOBYTE(v265) = 8;
    this->lblCore[v255]->setText(this->lblCore[v255], (const std::wstring *)LODWORD(h));
    LOBYTE(v265) = 4;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    this->lblCore[v28]->fontAlign = eAlignCenter;
    this->lblCore[v28]->fontScale = 1.2;
    this->lblCore[v28]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMOColor);
    this->lblCore[v28]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMOFontColor);
    ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->lblCore[v28]->setSize)(
      this->lblCore[v28],
      LODWORD(this->IMO_WIDTH),
      LODWORD(this->IMO_HEIGHT));
    v29 = this->lblCore[v28];
    v30 = this->pos[v28].x;
    v31 = this->pos[v28].y + v253;
    v32 = v29->rect.right - v29->rect.left;
    v33 = v29->rect.bottom - v29->rect.top;
    v29->rect.top = v31;
    v29->rect.left = v30;
    v34 = v30 + v32;
    v35 = v29->rectBase.left;
    v36 = v33 + v31;
    v29->rect.right = v34;
    v29->rect.bottom = v36;
    if ( v35 == 0.0 && v29->rectBase.top == 0.0 )
    {
      v29->rectBase.left = v30;
      v29->rectBase.top = v31;
      v29->rectBase.right = v34;
      v29->rectBase.bottom = v36;
    }
    v37 = (std::vector<unsigned int> *)&this->controls;
    v38 = this->controls._Mylast;
    v257 = (int)this->lblCore[v28];
    v248 = v257;
    v39 = v257;
    if ( &v248 >= (int *)v38 )
      goto LABEL_37;
    v40 = v37->_Myfirst;
    v39 = v257;
    if ( v40 > (unsigned int *)&v248 )
    {
      v37 = (std::vector<unsigned int> *)&this->controls;
LABEL_37:
      if ( v38 == (ksgui::Control **)v37->_Myend )
      {
        std::vector<unsigned int>::_Reserve(v37, 1u);
        v39 = v257;
        v37 = (std::vector<unsigned int> *)&this->controls;
      }
      v46 = v37->_Mylast;
      if ( v46 )
        *v46 = v39;
      ++v37->_Mylast;
      goto LABEL_42;
    }
    v41 = (char *)&v248 - (char *)v40;
    v42 = (std::vector<unsigned int> *)&this->controls;
    v43 = v41 >> 2;
    if ( v38 == this->controls._Myend )
    {
      std::vector<unsigned int>::_Reserve(v42, 1u);
      v39 = v257;
      v42 = (std::vector<unsigned int> *)&this->controls;
    }
    v44 = v42->_Myfirst;
    v45 = v42->_Mylast;
    if ( v45 )
      *v45 = v44[v43];
    ++this->controls._Mylast;
    v28 = v255;
LABEL_42:
    *(_DWORD *)(v39 + 148) = this;
    v252 = 0;
    v254 = 3 * (v28 + 27);
    v257 = 3 * (v28 + 31);
    do
    {
      v47 = (ksgui::Label *)operator new(0x11Cu);
      v262._Myres = (unsigned int)v47;
      LOBYTE(v265) = 9;
      if ( v47 )
      {
        h = *(float *)&this->gui;
        v48 = 0;
        v49 = (ksgui::Label *)&aImoLbl[v252 + v255];
        *(_DWORD *)&v245[24] = 7;
        *(_DWORD *)&v245[20] = 0;
        *(_WORD *)&v245[4] = 0;
        v256 = v49;
        if ( LOWORD(v49->__vftable) )
        {
          v50 = &aImoLbl[v252 + v255];
          _Val = (int)&v49->__vftable + 2;
          while ( *v50++ )
            ;
          v49 = v256;
          v48 = ((int)v50 - _Val) >> 1;
        }
        std::wstring::assign((std::wstring *)&v245[4], (const wchar_t *)v49, v48);
        ksgui::Label::Label(v47, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
        v53 = v52;
      }
      else
      {
        v53 = 0;
      }
      LOBYTE(v265) = 4;
      *((_DWORD *)&this->__vftable + v254 + v252) = v53;
      v54 = _Right._Rep;
      if ( _Right._Rep )
      {
        _InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 1u);
        v54 = _Right._Rep;
      }
      v55 = *(volatile signed __int32 **)(v53 + 132);
      *(_DWORD *)(v53 + 132) = v54;
      *(_DWORD *)(v53 + 128) = _Right._Ptr;
      if ( v55 )
      {
        if ( !_InterlockedExchangeAdd(v55 + 1, 0xFFFFFFFF) )
        {
          (**(void (***)(volatile signed __int32 *))v55)(v55);
          if ( !_InterlockedExchangeAdd(v55 + 2, 0xFFFFFFFF) )
            (*(void (**)(volatile signed __int32 *))(*v55 + 4))(v55);
        }
      }
      v56 = v252;
      v57 = v252 + v254;
      *(_DWORD *)(*((_DWORD *)&this->__vftable + v252 + v254) + 208) = 1067030938;
      *(_DWORD *)(*((_DWORD *)&this->__vftable + v57) + 152) = 2;
      *(__m128i *)(*((_DWORD *)&this->__vftable + v57) + 44) = _mm_loadu_si128((const __m128i *)&this->IMODarkColor);
      *(__m128i *)(*((_DWORD *)&this->__vftable + v57) + 76) = _mm_loadu_si128((const __m128i *)&this->IMOColor);
      (*(void (**)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)&this->__vftable + v57) + 28))(
        *((_DWORD *)&this->__vftable + v57),
        this->IMO_WIDTH * 0.33333334,
        LODWORD(this->IMO_HEIGHT));
      *(float *)&v256 = COERCE_FLOAT(operator new(0x11Cu));
      LOBYTE(v265) = 10;
      if ( *(float *)&v256 == 0.0 )
      {
        v63 = 0;
      }
      else
      {
        h = *(float *)&this->gui;
        v58 = &aImoTempLbl[v56 + v255];
        *(_DWORD *)&v245[24] = 7;
        *(_DWORD *)&v245[20] = 0;
        *(_WORD *)&v245[4] = 0;
        if ( *v58 )
        {
          v60 = v58;
          _Val = (int)(v58 + 1);
          while ( *v60++ )
            ;
          v59 = ((int)v60 - _Val) >> 1;
        }
        else
        {
          v59 = 0;
        }
        std::wstring::assign((std::wstring *)&v245[4], v58, v59);
        ksgui::Label::Label(v256, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
        v56 = v252;
        v63 = v62;
      }
      LOBYTE(v265) = 4;
      *((_DWORD *)&this->__vftable + v56 + v257) = v63;
      v64 = _Right._Rep;
      if ( _Right._Rep )
      {
        _InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 1u);
        v64 = _Right._Rep;
      }
      v65 = *(volatile signed __int32 **)(v63 + 132);
      *(_DWORD *)(v63 + 132) = v64;
      *(_DWORD *)(v63 + 128) = _Right._Ptr;
      if ( v65 )
      {
        if ( !_InterlockedExchangeAdd(v65 + 1, 0xFFFFFFFF) )
        {
          (**(void (***)(volatile signed __int32 *))v65)(v65);
          if ( !_InterlockedExchangeAdd(v65 + 2, 0xFFFFFFFF) )
            (*(void (**)(volatile signed __int32 *))(*v65 + 4))(v65);
        }
      }
      v66 = v252 + v257;
      LODWORD(h) = 3;
      *(_DWORD *)&v245[24] = L"---";
      text._Myres = 7;
      v67 = *((_DWORD *)&this->__vftable + v252 + v257);
      text._Mysize = 0;
      *(_DWORD *)(v67 + 208) = 1067030938;
      *(_DWORD *)(*((_DWORD *)&this->__vftable + v66) + 152) = 2;
      text._Bx._Buf[0] = 0;
      std::wstring::assign(&text, *(const wchar_t **)&v245[24], LODWORD(h));
      LOBYTE(v265) = 11;
      (*(void (**)(_DWORD, std::wstring *))(**((_DWORD **)&this->__vftable + v66) + 68))(
        *((_DWORD *)&this->__vftable + v66),
        &text);
      LOBYTE(v265) = 4;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      *(__m128i *)(*((_DWORD *)&this->__vftable + v66) + 44) = _mm_loadu_si128((const __m128i *)&this->IMOColor);
      *(__m128i *)(*((_DWORD *)&this->__vftable + v66) + 76) = _mm_loadu_si128((const __m128i *)&this->IMOFontColor);
      (*(void (**)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)&this->__vftable + v66) + 28))(
        *((_DWORD *)&this->__vftable + v66),
        this->IMO_WIDTH * 0.33333334,
        LODWORD(this->IMO_HEIGHT));
      v68 = v252;
      if ( v252 )
      {
        if ( v252 == 1 )
        {
          v262._Myres = 7;
          v262._Mysize = 0;
          v262._Bx._Buf[0] = 0;
          std::wstring::assign(&v262, L"M", 1u);
          LOBYTE(v265) = 13;
          (*(void (**)(_DWORD, std::wstring *))(**(_DWORD **)&this->name._Bx._Buf[2 * v254] + 68))(
            *(_DWORD *)&this->name._Bx._Buf[2 * v254],
            &v262);
          LOBYTE(v265) = 4;
          if ( v262._Myres >= 8 )
            operator delete(v262._Bx._Ptr);
          v93 = this->IMO_WIDTH;
          v94 = v255;
          v95 = v253;
          v262._Bx._Buf[0] = 0;
          v96 = this->pos[v255].y;
          v262._Myres = 7;
          v262._Mysize = 0;
          v97 = *(float **)&this->name._Bx._Buf[2 * v254];
          v98 = (float)(v96 + v253) + this->IMO_HEIGHT;
          v99 = (float)(v93 * 0.33333334) + this->pos[v255].x;
          v100 = v97[8] - v97[7];
          v101 = v97[10] - v97[9];
          v97[9] = v98;
          v97[7] = v99;
          v102 = v99 + v100;
          v103 = v97[66];
          v104 = v101 + v98;
          v97[8] = v102;
          v97[10] = v104;
          if ( v103 == 0.0 && v97[68] == 0.0 )
          {
            v97[66] = v99;
            v97[68] = v98;
            v97[67] = v102;
            v97[69] = v104;
          }
          v105 = *(float **)&this->name._Bx._Buf[2 * v257];
          v106 = (float)(this->pos[v94].y + v95) + (float)(this->IMO_HEIGHT * 2.0);
          v107 = (float)(this->IMO_WIDTH * 0.33333334) + this->pos[v94].x;
          v108 = v105[8] - v105[7];
          v109 = v105[10] - v105[9];
          v105[9] = v106;
          v105[7] = v107;
          v110 = v107 + v108;
          v111 = v105[66];
          v105[8] = v110;
          v105[10] = v106 + v109;
          if ( v111 == 0.0 && v105[68] == 0.0 )
          {
            v105[66] = v107;
            v105[68] = v106;
            v105[67] = v110;
            v105[69] = v106 + v109;
          }
        }
        else
        {
          if ( v252 != 2 )
            goto LABEL_112;
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"O", 1u);
          LOBYTE(v265) = 14;
          (*(void (**)(_DWORD, std::wstring *))(**(_DWORD **)&this->name._Bx._Alias[4 * v254 + 4] + 68))(
            *(_DWORD *)&this->name._Bx._Alias[4 * v254 + 4],
            &section);
          LOBYTE(v265) = 4;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          v69 = v255;
          section._Bx._Buf[0] = 0;
          section._Myres = 7;
          section._Mysize = 0;
          v70 = v253;
          v71 = *(float **)&this->name._Bx._Alias[4 * v254 + 4];
          v72 = v71[10] - v71[9];
          if ( v255 % 2 )
          {
            v73 = FLOAT_0_33333334;
            v74 = v71[8] - v71[7];
            v75 = (float)(this->pos[v255].y + v253) + this->IMO_HEIGHT;
            v76 = (float)((float)(this->IMO_WIDTH * 0.33333334) * 2.0) + this->pos[v255].x;
            v77 = v72 + v75;
            v71[9] = v75;
            v71[7] = v76;
            v78 = v76 + v74;
            v79 = v71[66];
            v71[8] = v78;
            v71[10] = v77;
            if ( v79 == 0.0 && v71[68] == 0.0 )
            {
              v71[66] = v76;
              v71[68] = v75;
              v71[67] = v78;
              v71[69] = v77;
            }
            v80 = *(float **)&this->name._Bx._Alias[4 * v257 + 4];
LABEL_109:
            v131 = v80[8] - v80[7];
            v132 = (float)(this->pos[v69].y + v70) + (float)(this->IMO_HEIGHT * 2.0);
            v133 = v80[66];
            v134 = (float)(v80[10] - v80[9]) + v132;
            v135 = (float)((float)(this->IMO_WIDTH * v73) * 2.0) + this->pos[v69].x;
            v80[10] = v134;
            v136 = v131 + v135;
            v80[8] = v136;
            v80[7] = v135;
            v80[9] = v132;
            if ( v133 == 0.0 && v80[68] == 0.0 )
            {
              v80[69] = v134;
              v80[67] = v136;
              v80[68] = v132;
              v80[66] = v135;
            }
            goto LABEL_112;
          }
          v81 = v71[66];
          v82 = this->pos[v255].x;
          v83 = (float)(this->pos[v255].y + v253) + this->IMO_HEIGHT;
          v84 = (float)(v71[8] - v71[7]) + v82;
          v71[7] = v82;
          v71[9] = v83;
          v85 = v72 + v83;
          v71[8] = v84;
          v71[10] = v85;
          if ( v81 == 0.0 && v71[68] == 0.0 )
          {
            v71[66] = v82;
            v71[68] = v83;
            v71[67] = v84;
            v71[69] = v85;
          }
          v86 = this->pos[v69].x;
          v87 = *(float **)&this->name._Bx._Alias[4 * v257 + 4];
          v88 = (float)(this->pos[v69].y + v70) + (float)(this->IMO_HEIGHT * 2.0);
          v89 = v87[66];
          v90 = v87[10] - v87[9];
          v91 = (float)(v87[8] - v87[7]) + v86;
          v87[9] = v88;
          v92 = v90 + v88;
          v87[7] = v86;
          v87[8] = v91;
          v87[10] = v92;
          if ( v89 == 0.0 && v87[68] == 0.0 )
          {
            v87[66] = v86;
            v87[68] = v88;
            v87[67] = v91;
            v87[69] = v92;
          }
        }
      }
      else
      {
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, L"I", 1u);
        LOBYTE(v265) = 12;
        (*(void (**)(_DWORD, std::wstring *))(**((_DWORD **)&this->__vftable + v254) + 68))(
          *((_DWORD *)&this->__vftable + v254),
          &text);
        LOBYTE(v265) = 4;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        v69 = v255;
        text._Bx._Buf[0] = 0;
        text._Myres = 7;
        text._Mysize = 0;
        v70 = v253;
        v112 = (float *)*((_DWORD *)&this->__vftable + v254);
        v113 = v112[66];
        if ( !(v255 % 2) )
        {
          v73 = FLOAT_0_33333334;
          v126 = v112[8] - v112[7];
          v127 = (float)(this->pos[v255].y + v253) + this->IMO_HEIGHT;
          v128 = (float)(v112[10] - v112[9]) + v127;
          v129 = (float)((float)(this->IMO_WIDTH * 0.33333334) * 2.0) + this->pos[v255].x;
          v112[9] = v127;
          v112[10] = v128;
          v112[7] = v129;
          v130 = v126 + v129;
          v112[8] = v130;
          if ( v113 == 0.0 && v112[68] == 0.0 )
          {
            v112[66] = v129;
            v112[68] = v127;
            v112[67] = v130;
            v112[69] = v128;
          }
          v80 = (float *)*((_DWORD *)&this->__vftable + v257);
          goto LABEL_109;
        }
        v114 = v112[10] - v112[9];
        v115 = this->pos[v255].x;
        v116 = (float)(this->pos[v255].y + v253) + this->IMO_HEIGHT;
        v117 = (float)(v112[8] - v112[7]) + v115;
        v112[7] = v115;
        v118 = v114 + v116;
        v112[9] = v116;
        v112[8] = v117;
        v112[10] = v118;
        if ( v113 == 0.0 && v112[68] == 0.0 )
        {
          v112[66] = v115;
          v112[68] = v116;
          v112[67] = v117;
          v112[69] = v118;
        }
        v119 = this->pos[v69].x;
        v120 = (float *)*((_DWORD *)&this->__vftable + v257);
        v121 = (float)(this->pos[v69].y + v70) + (float)(this->IMO_HEIGHT * 2.0);
        v122 = v120[66];
        v123 = v120[10] - v120[9];
        v124 = (float)(v120[8] - v120[7]) + v119;
        v120[9] = v121;
        v125 = v123 + v121;
        v120[7] = v119;
        v120[8] = v124;
        v120[10] = v125;
        if ( v122 == 0.0 && v120[68] == 0.0 )
        {
          v120[66] = v119;
          v120[68] = v121;
          v120[67] = v124;
          v120[69] = v125;
        }
      }
LABEL_112:
      v137 = this->controls._Mylast;
      v138 = v68 + v254;
      v139 = (std::vector<int> *)&this->controls;
      v256 = *((ksgui::Label **)&this->__vftable + v138);
      v249 = v256;
      if ( &v249 < v137 )
      {
        v140 = v139->_Myfirst;
        if ( v140 <= (int *)&v249 )
        {
          v141 = this->controls._Myend;
          v142 = ((char *)&v249 - (char *)v140) >> 2;
          _Val = v142;
          if ( v137 == v141 )
          {
            if ( !(v141 - v137) )
            {
              v143 = ((char *)v137 - (char *)v140) >> 2;
              if ( v143 == 0x3FFFFFFF )
                goto LABEL_202;
              v144 = ((char *)v141 - (char *)v140) >> 2;
              v262._Myres = v143 + 1;
              if ( 0x3FFFFFFF - (v144 >> 1) >= v144 )
                v145 = (v144 >> 1) + v144;
              else
                v145 = 0;
              v139 = (std::vector<int> *)&this->controls;
              if ( v145 < v262._Myres )
                v145 = v262._Myres;
              std::vector<ksgui::CustomSpinner *>::_Reallocate(
                (std::vector<ksgui::CustomSpinner *> *)&this->controls,
                v145);
              v142 = _Val;
              goto LABEL_125;
            }
            v142 = _Val;
          }
          v139 = (std::vector<int> *)&this->controls;
LABEL_125:
          v146 = v139->_Mylast;
          if ( v146 )
            *v146 = v139->_Myfirst[v142];
LABEL_127:
          v147 = v256;
          goto LABEL_128;
        }
        v139 = (std::vector<int> *)&this->controls;
      }
      v152 = v139->_Myend;
      if ( v137 == (ksgui::Control **)v152 && !(((char *)v152 - (char *)v137) >> 2) )
      {
        v153 = v139->_Myfirst;
        v154 = ((char *)v137 - (char *)v153) >> 2;
        if ( v154 == 0x3FFFFFFF )
LABEL_202:
          std::_Xlength_error("vector<T> too long");
        v155 = v152 - v153;
        v262._Myres = v154 + 1;
        if ( 0x3FFFFFFF - (v155 >> 1) >= v155 )
          v156 = (v155 >> 1) + v155;
        else
          v156 = 0;
        v139 = (std::vector<int> *)&this->controls;
        if ( v156 < v262._Myres )
          v156 = v262._Myres;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&this->controls, v156);
      }
      v157 = (float *)v139->_Mylast;
      if ( !v157 )
        goto LABEL_127;
      v147 = v256;
      *v157 = *(float *)&v256;
LABEL_128:
      v148 = v252 + v257;
      ++v139->_Mylast;
      v147->parent = this;
      _Val = *((int *)&this->__vftable + v148);
      std::vector<CarAvatar *>::push_back(v139, &_Val);
      *(_DWORD *)(_Val + 148) = this;
      ++v252;
    }
    while ( v252 < 3 );
    v149 = v255;
    if ( v255 >= 2 )
      v253 = this->FRONT_REAR_SEP - (float)(this->IMO_HEIGHT * 4.0);
    *(float *)&_Val = COERCE_FLOAT(operator new(0x11Cu));
    LOBYTE(v265) = 15;
    if ( *(float *)&_Val == 0.0 )
    {
      v160 = 0;
    }
    else
    {
      h = *(float *)&this->gui;
      v150 = 0;
      v151 = &aPsi[v149];
      *(_DWORD *)&v245[24] = 7;
      *(_DWORD *)&v245[20] = 0;
      *(_WORD *)&v245[4] = 0;
      if ( *v151 )
      {
        v158 = &aPsi[v149];
        v262._Myres = (unsigned int)(v151 + 1);
        while ( *v158++ )
          ;
        v151 = &aPsi[v149];
        v150 = (int)((int)v158 - v262._Myres) >> 1;
      }
      std::wstring::assign((std::wstring *)&v245[4], v151, v150);
      ksgui::Label::Label((ksgui::Label *)_Val, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
    }
    LOBYTE(v265) = 4;
    LODWORD(h) = &_Right;
    this->lblPressure[v149] = v160;
    std::shared_ptr<Font>::operator=(&v160->font, (const std::shared_ptr<Font> *)LODWORD(h));
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"---psi", 6u);
    LOBYTE(v265) = 16;
    this->lblPressure[v149]->setText(this->lblPressure[v149], &text);
    LOBYTE(v265) = 4;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    this->lblPressure[v149]->fontAlign = eAlignCenter;
    this->lblPressure[v149]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMODarkColor);
    this->lblPressure[v149]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMOColor);
    ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->lblPressure[v149]->setSize)(
      this->lblPressure[v149],
      this->IMO_WIDTH * 0.5,
      LODWORD(this->IMO_HEIGHT));
    *(float *)&_Val = COERCE_FLOAT(operator new(0x118u));
    LOBYTE(v265) = 17;
    if ( *(float *)&_Val == 0.0 )
    {
      v165 = 0;
    }
    else
    {
      text._Myres = 7;
      v161 = &aTyre[v149];
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
      if ( *v161 )
      {
        v163 = &aTyre[v149];
        v262._Myres = (unsigned int)(v161 + 1);
        while ( *v163++ )
          ;
        v162 = (int)((int)v163 - v262._Myres) >> 1;
      }
      else
      {
        v162 = 0;
      }
      std::wstring::assign(&text, &aTyre[v149], v162);
      LOBYTE(v265) = 18;
      h = *(float *)&this->gui;
      v250 |= 1u;
      v262._Myres = v250;
      ksgui::Control::Control((ksgui::Control *)_Val, &text, (ksgui::GUI *)LODWORD(h));
    }
    this->ctrlTyres[v149] = v165;
    v265 = 4;
    if ( (v250 & 1) != 0 )
    {
      v250 &= 0xFFFFFFFE;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"content/gui/tyresapp/tyre_white_full.png", 0x28u);
    LOBYTE(v265) = 20;
    ResourceStore::getTexture(this->car->game->graphics->resourceStore._Myptr, &result, &text, 0);
    LOBYTE(v265) = 22;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v166 = this->ctrlTyres[v149];
    text._Bx._Buf[0] = 0;
    text._Myres = 7;
    v166->backTexture.kid = result.kid;
    v167 = &v166->backTexture.fileName;
    text._Mysize = 0;
    if ( v167 != &result.fileName )
      std::wstring::assign(v167, &result.fileName, 0, 0xFFFFFFFF);
    if ( result.kid )
    {
      v168 = *((_DWORD *)result.kid + 10);
      v169 = *((_DWORD *)result.kid + 9);
    }
    else
    {
      v168 = 0;
      v169 = 0;
    }
    v170 = this->ctrlTyres[v255];
    v171 = v170->__vftable;
    v172 = (float)v168;
    *(float *)&v245[24] = (float)v169;
    ((void (*)(ksgui::Control *, _DWORD, _DWORD))v171->setSize)(v170, *(_DWORD *)&v245[24], LODWORD(v172));
    v173 = v255;
    this->ctrlTyres[v255]->drawBackground = 0;
    this->ctrlTyres[v173]->drawBorder = 0;
    if ( result.kid )
      v174 = *((_DWORD *)result.kid + 9);
    else
      v174 = 0;
    v175 = this->IMO_HEIGHT;
    v176 = (float)v174;
    *(float *)&_Val = (float)((float)(this->IMO_WIDTH * 0.5) - v176) * 0.5;
    v177 = this->TYRE_V_SPACE;
    v256 = (ksgui::Label *)(LODWORD(this->TYRE_V_SPACE) ^ _xmm);
    v257 = COERCE_UNSIGNED_INT(v175 + v177) ^ _xmm;
    if ( v173 >= 2 )
    {
      if ( result.kid )
        v178 = *((_DWORD *)result.kid + 10);
      else
        v178 = 0;
      v179 = (float)v178;
      *(float *)&v256 = (float)(v179 - v175) + v177;
      *(float *)&v257 = this->WEAR_HEIGHT + v177;
    }
    v180 = (ksgui::ProgressBar *)operator new(0x128u);
    v262._Myres = (unsigned int)v180;
    v181 = 0;
    LOBYTE(v265) = 23;
    if ( v180 )
    {
      h = *(float *)&this->gui;
      *(_DWORD *)&v245[24] = 7;
      *(_DWORD *)&v245[20] = 0;
      *(_WORD *)&v245[4] = 0;
      std::wstring::assign((std::wstring *)&v245[4], L"WEAR", 4u);
      ksgui::ProgressBar::ProgressBar(v180, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
    }
    v182 = v255;
    LOBYTE(v265) = 22;
    this->prgWear[v255] = v181;
    v181->isVertical = 1;
    ((void (*)(ksgui::ProgressBar *, _DWORD, _DWORD))this->prgWear[v182]->setSize)(
      this->prgWear[v182],
      LODWORD(this->WEAR_WIDTH),
      LODWORD(this->WEAR_HEIGHT));
    this->prgWear[v182]->foreColor = (vec4f)_xmm;
    v183 = v253;
    v184 = this->IMO_HEIGHT;
    v185 = this->pos[v182].y + v253;
    v186 = this->lblPressure[v182];
    if ( v182 % 2 )
    {
      v187 = v185 + (float)(v184 * 3.0);
      v188 = v187 + (float)(v186->rect.bottom - v186->rect.top);
      v189 = v186->rectBase.left;
      v190 = (float)(this->IMO_WIDTH * 0.5) + this->pos[v182].x;
      v191 = (float)(v186->rect.right - v186->rect.left) + v190;
      v186->rect.top = v187;
      v186->rect.left = v190;
      v186->rect.bottom = v188;
      v186->rect.right = v191;
      if ( v189 == 0.0 && v186->rectBase.top == 0.0 )
      {
        v186->rectBase.left = v190;
        v186->rectBase.top = v187;
        v186->rectBase.right = v191;
        v186->rectBase.bottom = v188;
      }
      v192 = this->ctrlTyres[v182];
      v193 = *(float *)&_Val + this->pos[v182].x;
      v194 = v192->rectBase.left;
      v195 = v192->rect.bottom - v192->rect.top;
      v196 = (float)((float)(this->pos[v182].y + v183) + (float)(this->IMO_HEIGHT * 3.0)) - *(float *)&v256;
      v197 = (float)(v192->rect.right - v192->rect.left) + v193;
      v192->rect.left = v193;
      v198 = v195 + v196;
      v192->rect.top = v196;
      v192->rect.right = v197;
      v192->rect.bottom = v198;
      if ( v194 == 0.0 && v192->rectBase.top == 0.0 )
      {
        v192->rectBase.left = v193;
        v192->rectBase.top = v196;
        v192->rectBase.right = v197;
        v192->rectBase.bottom = v198;
      }
      v199 = (float)(this->IMO_WIDTH * 0.5) + this->pos[v182].x;
    }
    else
    {
      v200 = v186->rect.bottom - v186->rect.top;
      v201 = this->pos[v182].x;
      v202 = (float)(v186->rect.right - v186->rect.left) + v201;
      v186->rect.left = v201;
      v203 = v185 + (float)(v184 * 3.0);
      v204 = v186->rectBase.left;
      v205 = v200 + v203;
      v186->rect.top = v203;
      v186->rect.right = v202;
      v186->rect.bottom = v205;
      if ( v204 == 0.0 && v186->rectBase.top == 0.0 )
      {
        v186->rectBase.left = v201;
        v186->rectBase.top = v203;
        v186->rectBase.right = v202;
        v186->rectBase.bottom = v205;
      }
      v206 = this->ctrlTyres[v182];
      v207 = v206->rect.bottom - v206->rect.top;
      v208 = v206->rectBase.left;
      v209 = (float)(this->IMO_WIDTH * 0.5) + (float)(*(float *)&_Val + this->pos[v182].x);
      v210 = (float)((float)(this->pos[v182].y + v183) + (float)(this->IMO_HEIGHT * 3.0)) - *(float *)&v256;
      v211 = v206->rect.right - v206->rect.left;
      v206->rect.left = v209;
      v206->rect.top = v210;
      v212 = v207 + v210;
      v213 = v211 + v209;
      v206->rect.bottom = v212;
      v206->rect.right = v213;
      if ( v208 == 0.0 && v206->rectBase.top == 0.0 )
      {
        v206->rectBase.left = v209;
        v206->rectBase.top = v210;
        v206->rectBase.right = v213;
        v206->rectBase.bottom = v212;
      }
      v199 = (float)((float)(this->IMO_WIDTH * 0.5) + this->pos[v182].x) - this->WEAR_WIDTH;
    }
    v214 = this->prgWear[v182];
    v215 = v214->rectBase.left;
    v216 = (float)((float)(this->pos[v182].y + v183) + (float)(this->IMO_HEIGHT * 3.0)) - *(float *)&v257;
    v217 = (float)(v214->rect.right - v214->rect.left) + v199;
    v218 = (float)(v214->rect.bottom - v214->rect.top) + v216;
    v214->rect.bottom = v218;
    v214->rect.right = v217;
    v214->rect.left = v199;
    v214->rect.top = v216;
    if ( v215 == 0.0 && v214->rectBase.top == 0.0 )
    {
      v214->rectBase.bottom = v218;
      v214->rectBase.right = v217;
      v214->rectBase.top = v216;
      v214->rectBase.left = v199;
    }
    _Val = (int)this->lblPressure[v182];
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    *(_DWORD *)(_Val + 148) = this;
    _Val = (int)this->ctrlTyres[v182];
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    *(_DWORD *)(_Val + 148) = this;
    _Val = (int)this->prgWear[v182];
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LOBYTE(v265) = 4;
    *(_DWORD *)(_Val + 148) = this;
    this->HighNearPressureLimit[v182] = 1.0;
    this->HighFarPressureLimit[v182] = 1.0;
    this->LowNearPressureLimit[v182] = 1.0;
    this->LowFarPressureLimit[v182] = 1.0;
    this->HighNearPressureSaturation[v182] = 1.0;
    this->HighFarPressureSaturation[v182] = 1.0;
    this->LowNearPressureSaturation[v182] = 1.0;
    this->LowFarPressureSaturation[v182] = 1.0;
    OnSetupAppCreated::~OnSetupAppCreated(&result);
    v16 = v182 + 1;
    v255 = v16;
  }
  while ( v16 < 4 );
  v219 = this->NEAR_LIMIT;
  v220 = 1.0 - v219;
  v221 = v219 - (float)this->FAR_LIMIT;
  LODWORD(h) = 284;
  this->NearTempLimit = v220;
  this->FarTempLimit = v221;
  v222 = (ksgui::Label *)operator new(LODWORD(h));
  v262._Myres = (unsigned int)v222;
  LOBYTE(v265) = 24;
  if ( v222 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v245[4], L"COMP");
    ksgui::Label::Label(v222, *(std::wstring *)&v245[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v223 = 0;
  }
  LOBYTE(v265) = 4;
  LODWORD(h) = &_Right;
  this->lblCompound = v223;
  std::shared_ptr<Font>::operator=(&v223->font, (const std::shared_ptr<Font> *)LODWORD(h));
  std::wstring::wstring(&result.fileName, word_17BE9D8);
  LOBYTE(v265) = 25;
  this->lblCompound->setText(this->lblCompound, &result.fileName);
  LOBYTE(v265) = 4;
  if ( result.fileName._Myres >= 8 )
    operator delete(result.fileName._Bx._Ptr);
  this->lblCompound->fontAlign = eAlignCenter;
  this->lblCompound->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMODarkColor);
  this->lblCompound->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->IMOColor);
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->lblCompound->setSize)(
    this->lblCompound,
    this->IMO_WIDTH * 0.5,
    LODWORD(this->IMO_HEIGHT));
  v224 = this->lblCompound;
  v225 = (float)((float)(this->IMO_HEIGHT * 3.0) + 1.0) + (float)(this->FRONT_REAR_SEP * 0.5);
  v226 = this->IMO_WIDTH;
  v227 = v226 * 0.5;
  v228 = (float)(v224->rect.bottom - v224->rect.top) + v225;
  v229 = (float)(v226 + this->LEFT_MARGIN) + this->IMO_SEP;
  v224->rect.top = v225;
  v224->rect.bottom = v228;
  v230 = v229 + v227;
  v231 = v224->rect.right - v224->rect.left;
  v224->rect.left = v230;
  v232 = v230 + v231;
  v233 = v224->rectBase.left;
  v224->rect.right = v232;
  if ( v233 == 0.0 && v224->rectBase.top == 0.0 )
  {
    v224->rectBase.left = v230;
    v224->rectBase.top = v225;
    v224->rectBase.right = v232;
    v224->rectBase.bottom = v228;
  }
  _Val = (int)this->lblCompound;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = L"system/cfg/tyres_app.ini";
  *(_DWORD *)(_Val + 148) = this;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(h));
  LOBYTE(v265) = 26;
  INIReader::INIReader(&v259, &text);
  LOBYTE(v265) = 28;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( v259.ready )
  {
    std::wstring::wstring(&result.fileName, L"USE_FAHRENHEIT");
    LOBYTE(v265) = 29;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 30;
    v234 = INIReader::getInt(&v259, &section, &result.fileName);
    v235 = section._Myres < 8;
    this->useTempInF = v234 != 0;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"FAR_COLD");
    LOBYTE(v265) = 31;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 32;
    v236 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->farColdColor = *v236;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"FAR_HOT");
    LOBYTE(v265) = 33;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 34;
    v237 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->farHotColor = *v237;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"NEAR_COLD");
    LOBYTE(v265) = 35;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 36;
    v238 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->nearColdColor = *v238;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"NEAR_HOT");
    LOBYTE(v265) = 37;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 38;
    v239 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->nearHotColor = *v239;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"OPTIMAL");
    LOBYTE(v265) = 39;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 40;
    v240 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->optimalColor = *v240;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"WEAR1");
    LOBYTE(v265) = 41;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 42;
    v241 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->goodColor = *v241;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&result.fileName, L"WEAR2");
    LOBYTE(v265) = 43;
    std::wstring::wstring(&section, L"OPTIONS");
    LOBYTE(v265) = 44;
    v242 = INIReader::getFloat3(&v259, (vec3f *)&v262._Bx._Alias[12], &section, &result.fileName);
    v235 = section._Myres < 8;
    this->usedColor = *v242;
    if ( !v235 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v265) = 28;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring(&key, L"WEAR3");
    LOBYTE(v265) = 45;
    std::wstring::wstring(&result.fileName, L"OPTIONS");
    LOBYTE(v265) = 46;
    v243 = INIReader::getFloat3(&v259, (vec3f *)&section._Bx._Alias[12], &result.fileName, &key);
    v235 = result.fileName._Myres < 8;
    this->badColor = *v243;
    if ( !v235 )
      operator delete(result.fileName._Bx._Ptr);
    LOBYTE(v265) = 28;
    result.fileName._Myres = 7;
    result.fileName._Mysize = 0;
    result.fileName._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  ((void (*)(TyresApp *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
  LOBYTE(v265) = 4;
  INIReader::~INIReader(&v259);
  LOBYTE(v265) = 2;
  v244 = _Right._Rep;
  if ( _Right._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
  {
    v244->_Destroy(v244);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v244->_Weaks, 0xFFFFFFFF) )
      ((void (*)(void))v244->_Delete_this)();
  }
}
TyresApp *TyresApp::`vector deleting destructor'(TyresApp *this, unsigned int a2)
{
  TyresApp::~TyresApp(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TyresApp::~TyresApp(TyresApp *this)
{
  this->__vftable = (TyresApp_vtbl *)&TyresApp::`vftable';
  if ( this->currentCompound._Myres >= 8 )
    operator delete(this->currentCompound._Bx._Ptr);
  this->currentCompound._Myres = 7;
  this->currentCompound._Mysize = 0;
  this->currentCompound._Bx._Buf[0] = 0;
  if ( this->coreText._Myres >= 8 )
    operator delete(this->coreText._Bx._Ptr);
  this->coreText._Myres = 7;
  this->coreText._Mysize = 0;
  this->coreText._Bx._Buf[0] = 0;
  this->__vftable = (TyresApp_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void TyresApp::render(TyresApp *this, float dt)
{
  TyresApp *v2; // edi
  ksgui::GUI *v3; // eax
  GraphicsManager *v4; // eax
  int v5; // esi
  std::wstring *v6; // eax
  int v7; // eax
  unsigned int v8; // ecx
  const std::wstring *v9; // eax
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  __m128i v15; // xmm0
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  ksgui::ProgressBar *v20; // eax
  int v21; // eax
  int v22; // esi
  _DWORD *v23; // edi
  int v24; // esi
  int v25; // edx
  int v26; // eax
  _DWORD *v27; // esi
  int v28; // ecx
  float v29; // xmm2_4
  float *v30; // eax
  int v31; // ecx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  std::wstring *v37; // eax
  CarAvatar *v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  std::wstring *v42; // eax
  std::wstring *v43; // eax
  std::wstring *v44; // eax
  std::wstring *v45; // eax
  std::wstring *v46; // eax
  CarAvatar *v47; // ecx
  float v48; // xmm0_4
  float v49; // xmm6_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  float v52; // xmm6_4
  float v53; // xmm0_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm3_4
  __m128i v59; // xmm0
  float v60; // xmm0_4
  float v61; // xmm6_4
  float v62; // xmm0_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm5_4
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm0_4
  float v70; // xmm6_4
  float v71; // xmm0_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm5_4
  float v75; // xmm4_4
  float v76; // xmm3_4
  float v77; // xmm0_4
  float v78; // xmm6_4
  float v79; // xmm0_4
  float v80; // xmm2_4
  float v81; // xmm1_4
  float v82; // xmm5_4
  float v83; // xmm4_4
  float v84; // xmm3_4
  CarAvatar *v85; // ecx
  int v86; // eax
  float v87; // xmm0_4
  CarAvatar *v88; // ecx
  int v89; // eax
  float v90; // xmm1_4
  CarAvatar *v91; // ecx
  __m128i v92; // xmm0
  CarAvatar *v93; // eax
  float v94; // xmm6_4
  float v95; // xmm0_4
  float v96; // xmm6_4
  float v97; // xmm0_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm5_4
  float v101; // xmm4_4
  float v102; // xmm3_4
  __m128i v103; // xmm0
  float v104; // xmm6_4
  float v105; // xmm0_4
  float v106; // xmm2_4
  float v107; // xmm1_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm3_4
  float v111; // xmm0_4
  float v112; // xmm6_4
  float v113; // xmm6_4
  float v114; // xmm5_4
  float v115; // xmm4_4
  float v116; // xmm1_4
  float v117; // xmm0_4
  float v118; // xmm2_4
  float v119; // xmm3_4
  float v120; // xmm6_4
  float v121; // xmm0_4
  float v122; // xmm2_4
  float v123; // xmm1_4
  float v124; // xmm5_4
  float v125; // xmm4_4
  float v126; // xmm3_4
  ksgui::Control *v127; // eax
  __int64 v128; // [esp+20h] [ebp-184h]
  float v129; // [esp+28h] [ebp-17Ch]
  int v130; // [esp+2Ch] [ebp-178h]
  int v131; // [esp+2Ch] [ebp-178h]
  bool v132; // [esp+33h] [ebp-171h]
  int v133[2]; // [esp+34h] [ebp-170h] BYREF
  unsigned __int16 tyreIndex[8]; // [esp+3Ch] [ebp-168h]
  __int128 v135; // [esp+4Ch] [ebp-158h] BYREF
  __int128 v136; // [esp+5Ch] [ebp-148h] BYREF
  float v137; // [esp+6Ch] [ebp-138h]
  int v138; // [esp+70h] [ebp-134h]
  __m128i v139; // [esp+74h] [ebp-130h] BYREF
  __m128i v140; // [esp+84h] [ebp-120h] BYREF
  __m128i v141; // [esp+94h] [ebp-110h] BYREF
  __m128i v142; // [esp+A4h] [ebp-100h] BYREF
  __m128i v143; // [esp+B4h] [ebp-F0h] BYREF
  __m128i v144; // [esp+C4h] [ebp-E0h] BYREF
  __m128i v145; // [esp+D4h] [ebp-D0h] BYREF
  __m128i v146; // [esp+E4h] [ebp-C0h] BYREF
  __m128i v147; // [esp+F4h] [ebp-B0h] BYREF
  std::wstring v148; // [esp+10Ch] [ebp-98h] BYREF
  std::wstring result; // [esp+124h] [ebp-80h] BYREF
  std::wstring v150; // [esp+13Ch] [ebp-68h] BYREF
  std::wstring v151; // [esp+154h] [ebp-50h] BYREF
  std::wstring v152; // [esp+16Ch] [ebp-38h] BYREF
  int v153[3]; // [esp+184h] [ebp-20h]
  int v154; // [esp+1A0h] [ebp-4h]

  v2 = this;
  *(_DWORD *)&tyreIndex[6] = this;
  v3 = this->gui;
  v133[0] = 0;
  v4 = v3->graphics;
  v133[1] = 0;
  v5 = (int)v4->gl;
  this->localToWorld(this, (vec2f *)&v135, (const vec2f *)v133);
  GLRenderer::color4f((GLRenderer *)v5, &v2->backColor);
  GLRenderer::quad(
    (GLRenderer *)v5,
    (float)(v2->backgroundRect.left * v2->scaleMult) + *(float *)&v135,
    (float)(v2->backgroundRect.top * v2->scaleMult) + *((float *)&v135 + 1),
    (float)(v2->backgroundRect.right - v2->backgroundRect.left) * v2->scaleMult,
    (float)(v2->backgroundRect.bottom - v2->backgroundRect.top) * v2->scaleMult,
    0,
    0);
  GLRenderer::end((GLRenderer *)v5);
  if ( !ReplayManager::isInReplaymode(v2->car->sim->replayManager) )
  {
    v6 = CarAvatar::getCurrentCompoundShortName(v2->car, &result);
    v154 = 0;
    v2->lblCompound->setText(v2->lblCompound, v6);
    v154 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v7 = (int)v2->lblCompound->getText(v2->lblCompound);
    v8 = *(_DWORD *)(v7 + 16);
    if ( *(_DWORD *)(v7 + 20) >= 8u )
      v7 = *(_DWORD *)v7;
    v132 = std::wstring::compare(&v2->currentCompound, 0, v2->currentCompound._Mysize, (const wchar_t *)v7, v8) != 0;
    v9 = v2->lblCompound->getText(v2->lblCompound);
    if ( &v2->currentCompound != v9 )
      std::wstring::assign(&v2->currentCompound, v9, 0, 0xFFFFFFFF);
    v10 = FLOAT_1_0;
    v5 = 0;
    *(_DWORD *)&tyreIndex[2] = 0;
    do
    {
      v11 = v10 - v2->car->physicsState.wear[v5];
      if ( v11 <= v10 )
      {
        if ( v11 < 0.0 )
          v11 = 0.0;
      }
      else
      {
        v11 = v10;
      }
      v2->prgWear[v5]->value = v11;
      v12 = v2->car->physicsState.wearMult[v5];
      if ( v12 <= 0.98000002 )
      {
        if ( v12 <= 0.95999998 )
        {
          v18 = v2->badColor.y;
          v19 = v2->badColor.z;
          v143.m128i_i32[0] = LODWORD(v2->badColor.x);
          *(__int64 *)((char *)v143.m128i_i64 + 4) = __PAIR64__(LODWORD(v19), LODWORD(v18));
          v143.m128i_i32[3] = 1065353216;
          v15 = _mm_loadu_si128(&v143);
        }
        else
        {
          v16 = v2->usedColor.y;
          v17 = v2->usedColor.z;
          v140.m128i_i32[0] = LODWORD(v2->usedColor.x);
          *(__int64 *)((char *)v140.m128i_i64 + 4) = __PAIR64__(LODWORD(v17), LODWORD(v16));
          v140.m128i_i32[3] = 1065353216;
          v15 = _mm_loadu_si128(&v140);
        }
      }
      else
      {
        v13 = v2->goodColor.y;
        v14 = v2->goodColor.z;
        v145.m128i_i32[0] = LODWORD(v2->goodColor.x);
        *(__int64 *)((char *)v145.m128i_i64 + 4) = __PAIR64__(LODWORD(v14), LODWORD(v13));
        v145.m128i_i32[3] = 1065353216;
        v15 = _mm_loadu_si128(&v145);
      }
      v20 = v2->prgWear[v5];
      v153[0] = 0;
      v153[1] = 0;
      v153[2] = 0;
      v20->foreColor = (vec4f)v15;
      if ( (int)v2->car->physicsState.tyreInflation[v5] )
      {
        v25 = 0;
        *(_DWORD *)&tyreIndex[4] = 0;
        v133[0] = (int)v2->lblTempIMO[v5];
        v26 = 3 * v5;
        v27 = (_DWORD *)v133[0];
        v130 = v26 << 6;
        v28 = (v26 << 6) + 2464;
        *(_DWORD *)tyreIndex = v28;
        do
        {
          v29 = *(float *)&v153[v25];
          v30 = (float *)((char *)v2->car + v28);
          v31 = 2;
          do
          {
            v32 = *(v30 - 3) + v29;
            v33 = v30[12];
            v34 = v30[6] + (float)(v30[3] + (float)(v32 + *v30));
            v35 = v30[9];
            v30 += 18;
            v29 = v33 + (float)(v35 + v34);
            --v31;
          }
          while ( v31 );
          v36 = v29 * 0.083333336;
          *(float *)&v153[v25] = v36;
          if ( v2->useTempInF )
          {
            v37 = std::to_wstring(&result, (int)(float)((float)((float)(v36 * 9.0) * 0.2) + 32.0));
            v154 = 5;
          }
          else
          {
            v37 = std::to_wstring(&result, (int)v36);
            v154 = 4;
          }
          (*(void (**)(_DWORD, std::wstring *))(*(_DWORD *)*v27 + 68))(*v27, v37);
          v154 = -1;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          ++v27;
          v25 = *(_DWORD *)&tyreIndex[4] + 1;
          v28 = *(_DWORD *)tyreIndex + 4;
          *(_DWORD *)&tyreIndex[4] = v25;
          *(_DWORD *)tyreIndex += 4;
        }
        while ( v25 < 3 );
        v24 = *(_DWORD *)&tyreIndex[2];
        v38 = v2->car;
        if ( v2->useTempInF )
        {
          v42 = std::to_wstring(
                  &v150,
                  (int)(float)((float)((float)(*(float *)((char *)v38->physicsState.tyreThermalStates[0].temps[12] + v130)
                                             * 9.0)
                                     * 0.2)
                             + 32.0));
          v154 = 9;
          v43 = std::operator+<wchar_t>(&v148, &v2->coreText, v42);
          LOBYTE(v154) = 10;
          v44 = std::operator+<wchar_t>(&result, v43, L"�F");
          LOBYTE(v154) = 11;
          v2->lblCore[v24]->setText(v2->lblCore[v24], v44);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( v148._Myres >= 8 )
            operator delete(v148._Bx._Ptr);
          v148._Myres = 7;
          v148._Mysize = 0;
          v148._Bx._Buf[0] = 0;
        }
        else
        {
          v39 = std::to_wstring(&v150, (int)*(float *)((char *)v38->physicsState.tyreThermalStates[0].temps[12] + v130));
          v154 = 6;
          v40 = std::operator+<wchar_t>(&result, &v2->coreText, v39);
          LOBYTE(v154) = 7;
          v41 = std::operator+<wchar_t>(&v148, v40, L"�C");
          LOBYTE(v154) = 8;
          v2->lblCore[v24]->setText(v2->lblCore[v24], v41);
          if ( v148._Myres >= 8 )
            operator delete(v148._Bx._Ptr);
          v148._Myres = 7;
          v148._Mysize = 0;
          v148._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
        }
        v154 = -1;
        if ( v150._Myres >= 8 )
          operator delete(v150._Bx._Ptr);
        v45 = std::to_wstring(
                &v152,
                (int)*(float *)((char *)&v2->car->physicsState.tyreThermalStates[0].dynamicPressure + v130));
        v154 = 12;
        v46 = std::operator+<wchar_t>(&v151, v45, L"psi");
        LOBYTE(v154) = 13;
        v2->lblPressure[v24]->setText(v2->lblPressure[v24], v46);
        if ( v151._Myres >= 8 )
          operator delete(v151._Bx._Ptr);
        v154 = -1;
        v151._Myres = 7;
        v151._Mysize = 0;
        v151._Bx._Buf[0] = 0;
        if ( v152._Myres >= 8 )
          operator delete(v152._Bx._Ptr);
        v152._Myres = 7;
        v152._Mysize = 0;
        v152._Bx._Buf[0] = 0;
      }
      else
      {
        v148._Myres = 7;
        v148._Mysize = 0;
        v148._Bx._Buf[0] = 0;
        std::wstring::assign(&v148, L"0psi", 4u);
        v154 = 1;
        v2->lblPressure[v5]->setText(v2->lblPressure[v5], &v148);
        v154 = -1;
        if ( v148._Myres >= 8 )
          operator delete(v148._Bx._Ptr);
        v148._Myres = 7;
        v148._Mysize = 0;
        v148._Bx._Buf[0] = 0;
        std::wstring::assign(&v148, word_17BE9D8, 0);
        v154 = 2;
        v2->lblCore[v5]->setText(v2->lblCore[v5], &v148);
        v154 = -1;
        if ( v148._Myres >= 8 )
          operator delete(v148._Bx._Ptr);
        v21 = 3 * (v5 + 31);
        v22 = 3;
        *(_DWORD *)tyreIndex = (char *)v2 + 4 * v21;
        v23 = *(_DWORD **)tyreIndex;
        do
        {
          v148._Myres = 7;
          v148._Mysize = 0;
          v148._Bx._Buf[0] = 0;
          std::wstring::assign(&v148, word_17BE9D8, 0);
          v154 = 3;
          (*(void (**)(_DWORD, std::wstring *))(*(_DWORD *)*v23 + 68))(*v23, &v148);
          v154 = -1;
          if ( v148._Myres >= 8 )
            operator delete(v148._Bx._Ptr);
          ++v23;
          --v22;
        }
        while ( v22 );
        v2 = *(TyresApp **)&tyreIndex[6];
        v24 = *(_DWORD *)&tyreIndex[2];
      }
      v47 = v2->car;
      v48 = v2->NEAR_LIMIT;
      v131 = v24;
      v49 = v47->physicsState.tyreThermalStates[v24].mult;
      if ( v47->physicsState.tyreThermalStates[v24].isHot )
      {
        if ( v49 <= v48 )
        {
          v60 = FLOAT_1_0;
          v61 = (float)(v49 - (float)v2->FAR_LIMIT) / v2->FarTempLimit;
          if ( v61 > 1.0 || (v60 = 0.0, v61 < 0.0) )
            v61 = v60;
          v62 = v2->farHotColor.z;
          v63 = v2->farHotColor.x;
          v64 = v2->farHotColor.y;
          v65 = v2->nearHotColor.x;
          v66 = v2->nearHotColor.y;
          v67 = v2->nearHotColor.z;
          v142.m128i_i32[3] = 1065353216;
          *(float *)v142.m128i_i32 = (float)((float)(v65 - v63) * v61) + v63;
          *(float *)&v142.m128i_i32[1] = (float)((float)(v66 - v64) * v61) + v64;
          *(float *)&v142.m128i_i32[2] = (float)((float)(v67 - v62) * v61) + v62;
          v59 = _mm_loadu_si128(&v142);
        }
        else
        {
          v50 = v49 - v48;
          v51 = FLOAT_1_0;
          v52 = v50 / v2->NearTempLimit;
          if ( v52 > 1.0 || (v51 = 0.0, v52 < 0.0) )
            v52 = v51;
          v53 = v2->nearHotColor.z;
          v54 = v2->nearHotColor.x;
          v55 = v2->nearHotColor.y;
          v56 = v2->optimalColor.x;
          v57 = v2->optimalColor.y;
          v58 = v2->optimalColor.z;
          DWORD1(v136) = 1065353216;
          *((float *)&v135 + 2) = (float)((float)(v56 - v54) * v52) + v54;
          *((float *)&v135 + 3) = (float)((float)(v57 - v55) * v52) + v55;
          *(float *)&v136 = (float)((float)(v58 - v53) * v52) + v53;
          v59 = _mm_loadu_si128((const __m128i *)((char *)&v135 + 8));
        }
      }
      else if ( v49 <= v48 )
      {
        v77 = FLOAT_1_0;
        v78 = (float)(v49 - (float)v2->FAR_LIMIT) / v2->FarTempLimit;
        if ( v78 > 1.0 || (v77 = 0.0, v78 < 0.0) )
          v78 = v77;
        v79 = v2->farColdColor.z;
        v80 = v2->farColdColor.x;
        v81 = v2->farColdColor.y;
        v82 = v2->nearColdColor.x;
        v83 = v2->nearColdColor.y;
        v84 = v2->nearColdColor.z;
        v144.m128i_i32[3] = 1065353216;
        *(float *)v144.m128i_i32 = (float)((float)(v82 - v80) * v78) + v80;
        *(float *)&v144.m128i_i32[1] = (float)((float)(v83 - v81) * v78) + v81;
        *(float *)&v144.m128i_i32[2] = (float)((float)(v84 - v79) * v78) + v79;
        v59 = _mm_loadu_si128(&v144);
      }
      else
      {
        v68 = v49 - v48;
        v69 = FLOAT_1_0;
        v70 = v68 / v2->NearTempLimit;
        if ( v70 > 1.0 || (v69 = 0.0, v70 < 0.0) )
          v70 = v69;
        v71 = v2->nearColdColor.z;
        v72 = v2->nearColdColor.x;
        v73 = v2->nearColdColor.y;
        v74 = v2->optimalColor.x;
        v75 = v2->optimalColor.y;
        v76 = v2->optimalColor.z;
        v147.m128i_i32[3] = 1065353216;
        *(float *)v147.m128i_i32 = (float)((float)(v74 - v72) * v70) + v72;
        *(float *)&v147.m128i_i32[1] = (float)((float)(v75 - v73) * v70) + v73;
        *(float *)&v147.m128i_i32[2] = (float)((float)(v76 - v71) * v70) + v71;
        v59 = _mm_loadu_si128(&v147);
      }
      v2->ctrlTyres[v24]->backTextureColor = (vec4f)v59;
      if ( v132 )
      {
        v2->HighNearPressureLimit[v24] = (float)CarAvatar::getCurrentCompoundIdealPressure(v2->car, v24) * 1.1;
        v2->HighFarPressureLimit[v24] = (float)CarAvatar::getCurrentCompoundIdealPressure(v2->car, v24) * 1.5;
        v85 = v2->car;
        v133[0] = LODWORD(v2->HighNearPressureLimit[v24]);
        v86 = CarAvatar::getCurrentCompoundIdealPressure(v85, v24);
        v87 = v2->HighFarPressureLimit[v24] - v2->HighNearPressureLimit[v24];
        v2->HighNearPressureSaturation[v24] = *(float *)v133 - (float)v86;
        v2->HighFarPressureSaturation[v24] = v87;
        v2->LowNearPressureLimit[v24] = (float)CarAvatar::getCurrentCompoundIdealPressure(v2->car, v24) * 0.89999998;
        v2->LowFarPressureLimit[v24] = (float)CarAvatar::getCurrentCompoundIdealPressure(v2->car, v24) * 0.5;
        v88 = v2->car;
        v133[0] = LODWORD(v2->LowNearPressureLimit[v24]);
        v89 = CarAvatar::getCurrentCompoundIdealPressure(v88, v24);
        v90 = *(float *)v133 - v2->LowFarPressureLimit[v24];
        v2->LowNearPressureSaturation[v24] = (float)v89 - *(float *)v133;
        v2->LowFarPressureSaturation[v24] = v90;
      }
      v91 = v2->car;
      v133[0] = LODWORD(v91->physicsState.tyreThermalStates[v131].dynamicPressure);
      v10 = FLOAT_1_0;
      v92 = _mm_cvtsi32_si128(CarAvatar::getCurrentCompoundIdealPressure(v91, v24));
      v93 = v2->car;
      if ( _mm_cvtepi32_ps(v92).m128_f32[0] < *(float *)v133 )
      {
        v111 = v93->physicsState.tyreThermalStates[v131].dynamicPressure;
        v112 = v2->HighNearPressureLimit[v24];
        if ( v111 <= v112 )
        {
          v120 = (float)(v112 - v111) / v2->HighNearPressureSaturation[v24];
          if ( v120 <= 1.0 )
          {
            if ( v120 < 0.0 )
              v120 = 0.0;
          }
          else
          {
            v120 = FLOAT_1_0;
          }
          v121 = v2->nearHotColor.z;
          v122 = v2->nearHotColor.x;
          v123 = v2->nearHotColor.y;
          v124 = v2->optimalColor.x;
          v125 = v2->optimalColor.y;
          v126 = v2->optimalColor.z;
          v146.m128i_i32[3] = 1065353216;
          *(float *)v146.m128i_i32 = (float)((float)(v124 - v122) * v120) + v122;
          *(float *)&v146.m128i_i32[1] = (float)((float)(v125 - v123) * v120) + v123;
          *(float *)&v146.m128i_i32[2] = (float)((float)(v126 - v121) * v120) + v121;
          v103 = _mm_loadu_si128(&v146);
        }
        else
        {
          v113 = (float)(v2->HighFarPressureLimit[v24] - v111) / v2->HighFarPressureSaturation[v24];
          if ( v113 <= 1.0 )
          {
            if ( v113 < 0.0 )
              v113 = 0.0;
          }
          else
          {
            v113 = FLOAT_1_0;
          }
          v114 = v2->farHotColor.x;
          v115 = v2->farHotColor.y;
          v116 = v2->farHotColor.z;
          v117 = v2->nearHotColor.y - v115;
          v118 = v2->nearHotColor.x;
          v119 = v2->nearHotColor.z;
          v141.m128i_i32[3] = 1065353216;
          *(float *)&v141.m128i_i32[1] = v115 + (float)(v117 * v113);
          *(float *)v141.m128i_i32 = v114 + (float)((float)(v118 - v114) * v113);
          *(float *)&v141.m128i_i32[2] = (float)((float)(v119 - v116) * v113) + v116;
          v103 = _mm_loadu_si128(&v141);
        }
      }
      else
      {
        v94 = v93->physicsState.tyreThermalStates[v131].dynamicPressure;
        v95 = v2->LowNearPressureLimit[v24];
        if ( v95 <= v94 )
        {
          v104 = (float)(v94 - v95) / v2->LowNearPressureSaturation[v24];
          if ( v104 <= 1.0 )
          {
            if ( v104 < 0.0 )
              v104 = 0.0;
          }
          else
          {
            v104 = FLOAT_1_0;
          }
          v105 = v2->nearColdColor.z;
          v106 = v2->nearColdColor.x;
          v107 = v2->nearColdColor.y;
          v108 = v2->optimalColor.x;
          v109 = v2->optimalColor.y;
          v110 = v2->optimalColor.z;
          v139.m128i_i32[3] = 1065353216;
          *(float *)v139.m128i_i32 = (float)((float)(v108 - v106) * v104) + v106;
          *(float *)&v139.m128i_i32[1] = (float)((float)(v109 - v107) * v104) + v107;
          *(float *)&v139.m128i_i32[2] = (float)((float)(v110 - v105) * v104) + v105;
          v103 = _mm_loadu_si128(&v139);
        }
        else
        {
          v96 = (float)(v94 - v2->LowFarPressureLimit[v24]) / v2->LowFarPressureSaturation[v24];
          if ( v96 <= 1.0 )
          {
            if ( v96 < 0.0 )
              v96 = 0.0;
          }
          else
          {
            v96 = FLOAT_1_0;
          }
          v97 = v2->farColdColor.z;
          v98 = v2->farColdColor.x;
          v99 = v2->farColdColor.y;
          v100 = v2->nearColdColor.x;
          v101 = v2->nearColdColor.y;
          v102 = v2->nearColdColor.z;
          v138 = 1065353216;
          *((float *)&v136 + 2) = (float)((float)(v100 - v98) * v96) + v98;
          *((float *)&v136 + 3) = (float)((float)(v101 - v99) * v96) + v99;
          v137 = (float)((float)(v102 - v97) * v96) + v97;
          v103 = _mm_loadu_si128((const __m128i *)((char *)&v136 + 8));
        }
      }
      v127 = v2->lblPressure[v24];
      v5 = v24 + 1;
      *(_DWORD *)&tyreIndex[2] = v5;
      v127->foreColor = (vec4f)v103;
    }
    while ( v5 < 4 );
  }
  ksgui::Control::render(v2, (int)v2, v5, dt, v128, v129);
}
