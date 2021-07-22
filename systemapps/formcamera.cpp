#include "formcamera.h
void __userpurge FormCamera::FormCamera(FormCamera *this@<ecx>, unsigned int a2@<ebx>, Sim *a_sim, CameraForwardYebis *camera)
{
  int v5; // esi
  Game *v6; // eax
  const std::wstring *v7; // eax
  void (__cdecl *v8)(void *); // eax
  double v9; // st7
  bool v10; // cf
  void *(__cdecl *v11)(unsigned int); // edx
  int v12; // eax
  ksgui::Form *v13; // ecx
  int v14; // esi
  CarAudioFMOD *v15; // esi
  ksgui::Form_vtbl *v16; // eax
  int v17; // ecx
  wchar_t *v18; // ecx
  ksgui::Form *v20; // esi
  ksgui::Control **v21; // eax
  std::vector<ksgui::Control *> *v22; // esi
  ksgui::Control **v23; // ecx
  ksgui::Form *v24; // eax
  ksgui::Control **v25; // ecx
  ksgui::Control **v26; // ecx
  std::wostream *v27; // eax
  std::wstring *v28; // eax
  float *v29; // edx
  float *v30; // ecx
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float *v37; // ecx
  int v38; // eax
  int v39; // eax
  ksgui::Control **v40; // esi
  int v41; // ecx
  ksgui::Control **v42; // eax
  wchar_t *v43; // ecx
  ksgui::Control *v45; // eax
  std::wostream *v46; // eax
  std::wstring *v47; // eax
  float *v48; // esi
  ksgui::Form *v49; // edx
  int v50; // ecx
  __m128 v51; // xmm0
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  CarAvatar *v57; // eax
  CarAvatar *v58; // eax
  Sim *v59; // ecx
  const __m128i *v60; // eax
  CarAvatar *v61; // eax
  Sim *v62; // ecx
  CarAvatar *v63; // eax
  Sim *v64; // ecx
  CarAvatar *v65; // eax
  Sim *v66; // ecx
  CarAvatar *v67; // eax
  int v68; // eax
  ksgui::Control **v69; // eax
  int v70; // eax
  int v71; // ecx
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  ksgui::Control **v77; // eax
  int v78; // eax
  int v79; // ecx
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float v83; // xmm1_4
  float v84; // xmm2_4
  ksgui::Control **v85; // eax
  int v86; // eax
  int v87; // ecx
  float v88; // xmm0_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  float v91; // xmm1_4
  float v92; // xmm2_4
  ksgui::Control **v93; // eax
  int v94; // eax
  int v95; // ecx
  float v96; // xmm0_4
  float v97; // xmm1_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm2_4
  ksgui::Control **v101; // eax
  int v102; // eax
  int v103; // ecx
  float v104; // xmm0_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm1_4
  float v108; // xmm2_4
  ksgui::Control **v109; // eax
  int v110; // eax
  int v111; // ecx
  float v112; // xmm0_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm1_4
  float v116; // xmm2_4
  float *v117; // eax
  float *v118; // esi
  float v119; // xmm0_4
  float v120; // xmm1_4
  float v121; // xmm2_4
  float v122; // xmm1_4
  float v123; // xmm2_4
  CarAudioFMOD *v124; // esi
  float *v125; // eax
  float *v126; // esi
  float v127; // xmm0_4
  float v128; // xmm1_4
  float v129; // xmm2_4
  float v130; // xmm1_4
  float v131; // xmm2_4
  CarAudioFMOD *v132; // esi
  float *v133; // eax
  float *v134; // esi
  float v135; // xmm0_4
  float v136; // xmm1_4
  float v137; // xmm2_4
  float v138; // xmm1_4
  float v139; // xmm2_4
  ksgui::Form *v140; // eax
  std::allocator<wchar_t> *v141; // eax
  FormCamera::{ctor}::__l25::<lambda_7a006080ccb0972db10ae7dbcf7a7705> *v142; // eax
  ksgui::Form *v143; // eax
  FormCamera::{ctor}::__l26::<lambda_7b7d802148895b2b2804cf5c8be9289d> *v144; // eax
  ksgui::Form *v145; // eax
  FormCamera::{ctor}::__l27::<lambda_00abf2264fc63cfd7e5bbe2e67d3f097> *v146; // eax
  int v147; // eax
  const __m128i *v148; // eax
  vec4f v149; // xmm0
  ksgui::Form_vtbl *v150; // eax
  int v151; // eax
  const __m128i *v152; // eax
  vec4f v153; // xmm0
  ksgui::Form_vtbl *v154; // eax
  int v155; // eax
  const __m128i *v156; // eax
  vec4f v157; // xmm0
  ksgui::Form_vtbl *v158; // eax
  int v159; // eax
  const __m128i *v160; // eax
  vec4f v161; // xmm0
  ksgui::Form_vtbl *v162; // eax
  int v163; // eax
  const __m128i *v164; // eax
  vec4f v165; // xmm0
  ksgui::Form_vtbl *v166; // eax
  int v167; // eax
  const __m128i *v168; // eax
  vec4f v169; // xmm0
  ksgui::Form_vtbl *v170; // eax
  ksgui::Form *v171; // eax
  FormCamera::{ctor}::__l28::<lambda_da575a3503933d2ced3581450e46a814> *v172; // eax
  ksgui::Form *v173; // eax
  FormCamera::{ctor}::__l29::<lambda_eace2b57934a8b87f3c1c6b0a678f188> *v174; // eax
  ksgui::Form *v175; // eax
  FormCamera::{ctor}::__l30::<lambda_f0e92d8d847ad365988fdd9b10c607e6> *v176; // eax
  ksgui::Form *v177; // eax
  FormCamera::{ctor}::__l31::<lambda_7b4ea2632516f90a76908156ba000f9b> *v178; // eax
  ksgui::Form *v179; // eax
  FormCamera::{ctor}::__l32::<lambda_5bad573555ba6eaa821d54b6931931a7> *v180; // eax
  ksgui::Form *v181; // eax
  FormCamera::{ctor}::__l33::<lambda_193de89817183dc5bc30c4c3ca15a163> *v182; // eax
  int v183; // eax
  const __m128i *v184; // eax
  vec4f v185; // xmm0
  ksgui::Form_vtbl *v186; // eax
  int v187; // eax
  const __m128i *v188; // eax
  vec4f v189; // xmm0
  ksgui::Form_vtbl *v190; // eax
  int v191; // eax
  const __m128i *v192; // eax
  vec4f v193; // xmm0
  ksgui::Form_vtbl *v194; // eax
  ksgui::Form *v195; // eax
  const __m128i *v196; // eax
  ksgui::Form *v197; // eax
  const __m128i *v198; // eax
  vec4f v199; // xmm0
  ksgui::Form *v200; // eax
  ksgui::Form *v201; // eax
  FormCamera::{ctor}::__l34::<lambda_5af06adcb52077a331fe943fca12deb3> *v202; // eax
  int v203; // eax
  ksgui::Form *v204; // eax
  ksgui::Form_vtbl *v205; // eax
  FormCamera::{ctor}::__l35::<lambda_6dbf9fd634d99c33903639310fdaa9c1> *v206; // eax
  ksgui::Form *v207; // eax
  FormCamera::{ctor}::__l36::<lambda_3f4dd1c0d10a6015d2c008ef135ba700> *v208; // eax
  ksgui::Label *v209; // eax
  const __m128i *v210; // eax
  ksgui::Label *v211; // eax
  const __m128i *v212; // eax
  ksgui::Label *v213; // eax
  const __m128i *v214; // eax
  ksgui::Form *v215; // eax
  FormCamera::{ctor}::__l37::<lambda_0bbe1d6e3723da7f0183d0d0d4608897> *v216; // eax
  int v217; // eax
  const __m128i *v218; // eax
  vec4f v219; // xmm0
  ksgui::Form_vtbl *v220; // eax
  int v221; // eax
  const __m128i *v222; // eax
  vec4f v223; // xmm0
  ksgui::Form_vtbl *v224; // eax
  int v225; // eax
  const __m128i *v226; // eax
  vec4f v227; // xmm0
  ksgui::Form_vtbl *v228; // eax
  int v229; // eax
  const __m128i *v230; // eax
  vec4f v231; // xmm0
  ksgui::Form_vtbl *v232; // eax
  ksgui::Form *v233; // eax
  FormCamera::{ctor}::__l38::<lambda_548cf411b82d84975322e83c770ee65c> *v234; // eax
  int v235; // eax
  ksgui::Form *v236; // eax
  ksgui::Form_vtbl *v237; // eax
  FormCamera::{ctor}::__l39::<lambda_1f202aa6992e0e61ca5c6b1fbad943bd> *v238; // eax
  ksgui::Control *v239; // eax
  ksgui::Control *v240; // eax
  const __m128i *v241; // eax
  FormCamera::{ctor}::__l40::<lambda_00c040002a7865e82de2ae0ad7909613> *v242; // eax
  ksgui::Control *v243; // eax
  ksgui::Control *v244; // eax
  const __m128i *v245; // eax
  FormCamera::{ctor}::__l41::<lambda_dc54fc283a98e69980e29c142711bc4a> *v246; // eax
  ksgui::Form *v247; // eax
  const std::wstring *v248; // eax
  FormCamera::{ctor}::__l42::<lambda_2057a35e8ce4fe8d75ec38f02b3433e2> *v249; // eax
  ksgui::Form *v250; // eax
  const std::wstring *v251; // eax
  FormCamera::{ctor}::__l43::<lambda_2652a96a26541857e7890c18d991ce3a> *v252; // eax
  CarAudioFMOD *v253; // esi
  int v254; // eax
  int v255; // esi
  std::wstring *v256; // eax
  FormCamera::{ctor}::__l44::<lambda_dc9151347bc8de3dab8c11ae9d36748c> *v257; // eax
  _BYTE v258[28]; // [esp+2ACh] [ebp-2D0h] BYREF
  float top; // [esp+2C8h] [ebp-2B4h]
  int v260; // [esp+2F0h] [ebp-28Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v261; // [esp+2F4h] [ebp-288h] BYREF
  CameraCarDefinition v262; // [esp+3A4h] [ebp-1D8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v263; // [esp+3F0h] [ebp-18Ch] BYREF
  FormCamera *v264; // [esp+4A0h] [ebp-DCh]
  ksgui::Control **v265; // [esp+4A4h] [ebp-D8h] BYREF
  wchar_t *_Ptr; // [esp+4A8h] [ebp-D4h]
  int v267; // [esp+4ACh] [ebp-D0h] BYREF
  ksgui::Control **v268; // [esp+4B0h] [ebp-CCh]
  int _Val; // [esp+4B4h] [ebp-C8h] BYREF
  int v270; // [esp+4B8h] [ebp-C4h]
  ksgui::Form *v271; // [esp+4BCh] [ebp-C0h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v272; // [esp+4C0h] [ebp-BCh] BYREF
  ksgui::Form *v273; // [esp+4C4h] [ebp-B8h]
  INIReader v274; // [esp+4C8h] [ebp-B4h] BYREF
  std::wstring v275; // [esp+50Ch] [ebp-70h] BYREF
  std::wstring ifilename; // [esp+524h] [ebp-58h] BYREF
  std::wstring text; // [esp+53Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+554h] [ebp-28h] BYREF
  int v279; // [esp+578h] [ebp-4h]

  v5 = 0;
  v273 = 0;
  top = 0.0;
  v264 = this;
  v6 = a_sim->game;
  v270 = 0;
  *(_DWORD *)&v258[24] = v6->gui;
  *(_DWORD *)&v258[20] = 7;
  *(_DWORD *)&v258[16] = 0;
  *(_WORD *)v258 = 0;
  std::wstring::assign((std::wstring *)v258, L"FORM_CAMERA", 0xBu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v258, *(ksgui::GUI **)&v258[24], SLOBYTE(top));
  v279 = 0;
  this->__vftable = (FormCamera_vtbl *)&FormCamera::`vftable';
  *(_DWORD *)&this->currentLevel = 0;
  *(_DWORD *)&this->highExp = 0;
  this->highDiff = 0.0;
  this->lowDiff = 0.0;
  this->started = 0;
  this->cameraYebis = camera;
  this->F1_COUNT = 6;
  this->F6_COUNT = 6;
  LODWORD(top) = 13;
  *(_DWORD *)&v258[24] = L"Camera editor";
  this->isByButton = 0;
  this->targetExp = 0.0;
  this->timing = 0.0;
  this->lastAutoExp = 0.0;
  this->camW = 50.0;
  this->border = 5.0;
  this->header = 35.0;
  this->fontScale = 0.5;
  this->currentMode = eCockpit;
  this->currentCamera = 0;
  this->currentSensibility = 3.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v258[24], LODWORD(top));
  LOBYTE(v279) = 1;
  v7 = acTranslate(&result.name, &text);
  LOBYTE(v279) = 2;
  this->formTitle->setText(this->formTitle, v7);
  v8 = operator delete;
  if ( result.name._Myres >= 8 )
  {
    operator delete(result.name._Bx._Ptr);
    v8 = operator delete;
  }
  result.name._Myres = 7;
  LOBYTE(v279) = 0;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v8(text._Bx._Ptr);
  this->sim = a_sim;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v279) = 3;
  INIReader::INIReader(&v274, &ifilename);
  LOBYTE(v279) = 4;
  if ( v274.ready )
  {
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
    std::wstring::assign(&result.name, L"AUTOEXP", 7u);
    LOBYTE(v279) = 5;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"AC_APPS", 7u);
    LOBYTE(v279) = 6;
    HIBYTE(v267) = INIReader::hasKey(&v274, &text, &result.name);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v279) = 4;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    if ( HIBYTE(v267) )
    {
      std::wstring::wstring(&text, L"AUTOEXP");
      LOBYTE(v279) = 7;
      std::wstring::wstring(&result.name, L"AC_APPS");
      LOBYTE(v279) = 8;
      v9 = INIReader::getFloat(&v274, &result.name, &text);
      v10 = result.name._Myres < 8;
      this->targetExp = v9;
      if ( !v10 )
        operator delete(result.name._Bx._Ptr);
      LOBYTE(v279) = 4;
      result.name._Myres = 7;
      result.name._Mysize = 0;
      result.name._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
  }
  v11 = operator new;
  v12 = this->F1_COUNT + 1;
  this->currentCamera = 0;
  _Val = 0;
  if ( v12 > 0 )
  {
    v13 = (ksgui::Form *)this->cameraF1;
    _Ptr = L"COCK";
    v271 = (ksgui::Form *)this->cameraF1;
    v14 = 0;
    while ( v14 == this->F1_COUNT )
    {
LABEL_45:
      v39 = this->F1_COUNT;
      ++v14;
      ++_Ptr;
      v13 = (ksgui::Form *)((char *)v13 + 4);
      _Val = v14;
      v271 = v13;
      if ( v14 >= v39 + 1 )
      {
        v5 = v270;
        goto LABEL_47;
      }
    }
    v15 = (CarAudioFMOD *)v11(0x118u);
    v272.__this = v15;
    v16 = 0;
    LOBYTE(v279) = 9;
    if ( v15 )
    {
      result.name._Myres = 7;
      result.name._Mysize = 0;
      result.name._Bx._Buf[0] = 0;
      if ( *_Ptr )
      {
        v18 = _Ptr;
        v268 = (ksgui::Control **)(_Ptr + 1);
        while ( *v18++ )
          ;
        v17 = ((char *)v18 - (char *)v268) >> 1;
      }
      else
      {
        v17 = 0;
      }
      std::wstring::assign(&result.name, _Ptr, v17);
      LOBYTE(v279) = 10;
      top = *(float *)&this->gui;
      v270 |= 1u;
      v273 = (ksgui::Form *)v270;
      ksgui::Control::Control((ksgui::Control *)v15, &result.name, (ksgui::GUI *)LODWORD(top));
    }
    v20 = v271;
    v279 = 4;
    v271->__vftable = v16;
    if ( (v270 & 1) != 0 )
    {
      v270 &= 0xFFFFFFFE;
      if ( result.name._Myres >= 8 )
        operator delete(result.name._Bx._Ptr);
    }
    v21 = (ksgui::Control **)v20->__vftable;
    v22 = &this->controls;
    v23 = this->controls._Mylast;
    v268 = v21;
    v265 = v21;
    if ( &v265 >= (ksgui::Control ***)v23 || v22->_Myfirst > (ksgui::Control **)&v265 )
    {
      if ( v23 == this->controls._Myend )
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
      v42 = this->controls._Mylast;
      if ( v42 )
      {
        v26 = v268;
        *v42 = (ksgui::Control *)v268;
        goto LABEL_35;
      }
    }
    else
    {
      v24 = (ksgui::Form *)(((char *)&v265 - (char *)v22->_Myfirst) >> 2);
      v273 = v24;
      if ( v23 == this->controls._Myend )
      {
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
        v24 = v273;
      }
      v25 = this->controls._Mylast;
      if ( v25 )
        *v25 = v22->_Myfirst[(_DWORD)v24];
    }
    v26 = v268;
LABEL_35:
    ++this->controls._Mylast;
    v26[37] = this;
    *(_DWORD *)v261.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v261.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v261.gap68);
    LOBYTE(v279) = 12;
    v270 |= 0x2000000u;
    v273 = (ksgui::Form *)v270;
    std::wiostream::basic_iostream<wchar_t>(&v261, &v261.gap10[8], 0);
    v279 = 13;
    *(_DWORD *)&v261.gap0[*(_DWORD *)(*(_DWORD *)v261.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v260 + *(_DWORD *)(*(_DWORD *)v261.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v261.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v261.gap10[8]);
    *(_DWORD *)&v261.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v261.gap10[64] = 0;
    *(_DWORD *)&v261.gap10[68] = 0;
    LOBYTE(v279) = 15;
    v14 = _Val;
    LODWORD(top) = _Val + 1;
    v27 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v261.gap10, "F1-");
    std::wostream::operator<<(v27, LODWORD(top));
    v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v261, &result.name);
    LOBYTE(v279) = 16;
    (*((void (**)(ksgui::Form_vtbl *, std::wstring *))v271->~Control + 17))(v271->__vftable, v28);
    LOBYTE(v279) = 15;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    (*((void (**)(ksgui::Form_vtbl *, int, int))v271->~Control + 7))(v271->__vftable, 1112014848, 1106247680);
    v29 = (float *)v271;
    *(_OWORD *)&v271->onMouseUp = 0i64;
    v30 = *(float **)v29;
    v31 = (float)((float)v14 * 55.0) + 5.0;
    v32 = *(float *)(*(_DWORD *)v29 + 264);
    v33 = *(float *)(*(_DWORD *)v29 + 32) - *(float *)(*(_DWORD *)v29 + 28);
    v34 = *(float *)(*(_DWORD *)v29 + 40) - *(float *)(*(_DWORD *)v29 + 36);
    v30[9] = 35.0;
    v35 = v33 + v31;
    v30[7] = v31;
    v36 = v34 + 35.0;
    v30[8] = v35;
    v30[10] = v36;
    if ( v32 == 0.0 && v30[68] == 0.0 )
    {
      v30[66] = v31;
      v30[68] = 35.0;
      v30[67] = v35;
      v30[69] = v36;
    }
    if ( v14 == 1 || v14 == 2 )
    {
      v37 = *(float **)v29;
      if ( *(_BYTE *)(*(_DWORD *)v29 + 244) )
      {
        v38 = *(_DWORD *)v37;
        top = 0.0;
        *((_BYTE *)v37 + 244) = 0;
        (*(void (__stdcall **)(_DWORD))(v38 + 32))(LODWORD(top));
        v29 = (float *)v271;
      }
    }
    top = *v29;
    *(_DWORD *)&v258[4] = &std::_Func_impl<std::_Callable_obj<_lambda_a766d8685a6a2b2ab7000edb929cdf48_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v258[8] = v14;
    *(_DWORD *)&v258[12] = this;
    *(_DWORD *)&v258[20] = &v258[4];
    LOBYTE(v279) = 15;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)v29 + 156),
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
      (void *)LODWORD(top));
    std::wostream::flush(v261.gap10);
    LOBYTE(v279) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v261);
    v13 = v271;
    v11 = operator new;
    goto LABEL_45;
  }
LABEL_47:
  v271 = 0;
  if ( this->F6_COUNT > 0 )
  {
    v40 = this->cameraF6;
    _Ptr = L"CAM";
    v268 = this->cameraF6;
    do
    {
      v272.__this = (CarAudioFMOD *)v11(0x118u);
      LOBYTE(v279) = 18;
      if ( v272.__this )
      {
        result.name._Myres = 7;
        result.name._Mysize = 0;
        result.name._Bx._Buf[0] = 0;
        if ( *_Ptr )
        {
          v43 = _Ptr;
          _Val = (int)(_Ptr + 1);
          while ( *v43++ )
            ;
          v41 = ((int)v43 - _Val) >> 1;
        }
        else
        {
          v41 = 0;
        }
        std::wstring::assign(&result.name, _Ptr, v41);
        LOBYTE(v279) = 19;
        top = *(float *)&this->gui;
        v270 |= 2u;
        v273 = (ksgui::Form *)v270;
        ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
      }
      else
      {
        v45 = 0;
      }
      *v40 = v45;
      v279 = 4;
      if ( (v270 & 2) != 0 )
      {
        v270 &= 0xFFFFFFFD;
        if ( result.name._Myres >= 8 )
          operator delete(result.name._Bx._Ptr);
      }
      _Val = (int)*v268;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
      *(_DWORD *)(_Val + 148) = this;
      *(_DWORD *)v263.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v263.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v263.gap68);
      LOBYTE(v279) = 21;
      v270 |= 0x4000000u;
      v273 = (ksgui::Form *)v270;
      std::wiostream::basic_iostream<wchar_t>(&v263, &v263.gap10[8], 0);
      v279 = 22;
      *(_DWORD *)&v263.gap0[*(_DWORD *)(*(_DWORD *)v263.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)(&v262.externalSound + *(_DWORD *)(*(_DWORD *)v263.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v263.gap0 + 4)
                                                                               - 104;
      std::wstreambuf::wstreambuf(&v263.gap10[8]);
      *(_DWORD *)&v263.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v263.gap10[64] = 0;
      *(_DWORD *)&v263.gap10[68] = 0;
      LOBYTE(v279) = 24;
      LODWORD(top) = (char *)&v271->__vftable + 1;
      v272.__this = (CarAudioFMOD *)((char *)&v271->__vftable + 1);
      v46 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v263.gap10, "F6-");
      std::wostream::operator<<(v46, LODWORD(top));
      v47 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v263, &result.name);
      LOBYTE(v279) = 25;
      (*v268)->setText(*v268, v47);
      LOBYTE(v279) = 24;
      if ( result.name._Myres >= 8 )
        operator delete(result.name._Bx._Ptr);
      v48 = (float *)v268;
      ((void (*)(ksgui::Control *, int, int))(*v268)->setSize)(*v268, 1112014848, 1106247680);
      v49 = v271;
      *(_OWORD *)(*(_DWORD *)v48 + 44) = 0i64;
      v50 = *(_DWORD *)v48;
      v51 = (__m128)*(unsigned int *)(*(_DWORD *)v48 + 264);
      v52 = (float)((float)(int)v49 * 55.0) + 5.0;
      v53 = *(float *)(*(_DWORD *)v48 + 32) - *(float *)(*(_DWORD *)v48 + 28);
      v54 = *(float *)(*(_DWORD *)v48 + 40) - *(float *)(*(_DWORD *)v48 + 36);
      *(_DWORD *)(v50 + 36) = 1116471296;
      v55 = v53 + v52;
      *(float *)(v50 + 28) = v52;
      v56 = v54 + 70.0;
      *(float *)(v50 + 32) = v55;
      *(float *)(v50 + 40) = v56;
      if ( v51.m128_f32[0] == 0.0 )
      {
        v51 = (__m128)*(unsigned int *)(v50 + 272);
        if ( v51.m128_f32[0] == 0.0 )
        {
          *(float *)(v50 + 264) = v52;
          *(_DWORD *)(v50 + 272) = 1116471296;
          *(float *)(v50 + 268) = v55;
          *(float *)(v50 + 276) = v56;
        }
      }
      top = *v48;
      *(_DWORD *)&v258[4] = &std::_Func_impl<std::_Callable_obj<_lambda_c2682667bb55da40432990ff4ce05757_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
      *(_DWORD *)&v258[8] = v49;
      *(_DWORD *)&v258[12] = this;
      *(_DWORD *)&v258[20] = &v258[4];
      LOBYTE(v279) = 24;
      Event<ksgui::OnControlClicked>::addHandler(
        (Event<OnMouseWheelMovedEvent> *)(*(_DWORD *)v48 + 156),
        *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
        (void *)LODWORD(top));
      v57 = Sim::getCar(this->sim, 0);
      if ( (unsigned int)v271 >= v57->cameras._Mylast - v57->cameras._Myfirst )
      {
        CameraCarDefinition::CameraCarDefinition(&v262, v51);
        v58 = Sim::getCar(this->sim, 0);
        v59 = this->sim;
        top = 0.0;
        v60 = (const __m128i *)v58->cameras._Myfirst;
        *(__m128i *)&v262.matrix.M11 = _mm_loadu_si128(v60);
        *(__m128i *)&v262.matrix.M21 = _mm_loadu_si128(v60 + 1);
        *(__m128i *)&v262.matrix.M31 = _mm_loadu_si128(v60 + 2);
        *(__m128i *)&v262.matrix.M41 = _mm_loadu_si128(v60 + 3);
        v61 = Sim::getCar(v59, 0);
        v62 = this->sim;
        top = 0.0;
        v262.fov = v61->cameras._Myfirst->fov;
        v63 = Sim::getCar(v62, 0);
        v64 = this->sim;
        top = 0.0;
        v262.exposure = v63->cameras._Myfirst->exposure;
        v65 = Sim::getCar(v64, 0);
        v66 = this->sim;
        v262.externalSound = v65->cameras._Myfirst->externalSound;
        LODWORD(top) = &v262;
        v67 = Sim::getCar(v66, 0);
        std::vector<CameraCarDefinition>::push_back(&v67->cameras, (CameraCarDefinition *)LODWORD(top));
      }
      std::wostream::flush(v263.gap10);
      LOBYTE(v279) = 4;
      *(_DWORD *)&v263.gap0[*(_DWORD *)(*(_DWORD *)v263.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)(&v262.externalSound + *(_DWORD *)(*(_DWORD *)v263.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v263.gap0 + 4)
                                                                               - 104;
      *(_DWORD *)&v263.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v263.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v263.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v263.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v263.gap68);
      v40 = (ksgui::Control **)(v48 + 1);
      v68 = this->F6_COUNT;
      ++_Ptr;
      v11 = operator new;
      v271 = (ksgui::Form *)v272.__this;
      v268 = v40;
    }
    while ( (int)v272.__this < v68 );
    v5 = v270;
  }
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 27;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    *(_DWORD *)&v258[24] = 7;
    *(_DWORD *)&v258[20] = 0;
    *(_WORD *)&v258[4] = 0;
    std::wstring::assign((std::wstring *)&v258[4], L"PitchUP", 7u);
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v69 = 0;
  }
  LOBYTE(v279) = 4;
  v268 = v69;
  v69[52] = (ksgui::Control *)1056964608;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  std::wstring::assign(&result.name, L"PITCH", 5u);
  LOBYTE(v279) = 28;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v70 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v70 + 28))(1112014848, LODWORD(top));
  v71 = (int)v268;
  v72 = *((float *)v268 + 66);
  v73 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v74 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v71 + 28) = 1084227584;
  v75 = v73 + 5.0;
  v76 = v74 + 105.0;
  *(float *)(v71 + 32) = v75;
  *(float *)(v71 + 40) = v76;
  if ( v72 == 0.0 && *(float *)(v71 + 272) == 0.0 )
  {
    *(_DWORD *)(v71 + 264) = 1084227584;
    *(_DWORD *)(v71 + 272) = 1121058816;
    *(float *)(v71 + 268) = v75;
    *(float *)(v71 + 276) = v76;
  }
  _Val = v71;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 29;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    *(_DWORD *)&v258[24] = 7;
    *(_DWORD *)&v258[20] = 0;
    *(_WORD *)&v258[4] = 0;
    std::wstring::assign((std::wstring *)&v258[4], L"PitchDOWN", 9u);
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v77 = 0;
  }
  LOBYTE(v279) = 4;
  v268 = v77;
  v77[52] = (ksgui::Control *)1056964608;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  std::wstring::assign(&result.name, L"PITCH", 5u);
  LOBYTE(v279) = 30;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v78 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v78 + 28))(1112014848, LODWORD(top));
  v79 = (int)v268;
  v80 = *((float *)v268 + 66);
  v81 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v82 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v79 + 28) = 1114636288;
  v83 = v81 + 60.0;
  v84 = v82 + 105.0;
  *(float *)(v79 + 32) = v83;
  *(float *)(v79 + 40) = v84;
  if ( v80 == 0.0 && *(float *)(v79 + 272) == 0.0 )
  {
    *(_DWORD *)(v79 + 264) = 1114636288;
    *(_DWORD *)(v79 + 272) = 1121058816;
    *(float *)(v79 + 268) = v83;
    *(float *)(v79 + 276) = v84;
  }
  _Val = v79;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 31;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"RollLeft");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v85 = 0;
  }
  LOBYTE(v279) = 4;
  v268 = v85;
  v85[52] = (ksgui::Control *)1056964608;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  std::wstring::assign(&result.name, L"ROLL", 4u);
  LOBYTE(v279) = 32;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v86 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v86 + 28))(1112014848, LODWORD(top));
  v87 = (int)v268;
  v88 = *((float *)v268 + 66);
  v89 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v90 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v87 + 28) = 1122369536;
  v91 = v89 + 115.0;
  v92 = v90 + 105.0;
  *(float *)(v87 + 32) = v91;
  *(float *)(v87 + 40) = v92;
  if ( v88 == 0.0 && *(float *)(v87 + 272) == 0.0 )
  {
    *(_DWORD *)(v87 + 264) = 1122369536;
    *(_DWORD *)(v87 + 272) = 1121058816;
    *(float *)(v87 + 268) = v91;
    *(float *)(v87 + 276) = v92;
  }
  _Val = v87;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 33;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"RollRight");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v93 = 0;
  }
  LOBYTE(v279) = 4;
  v268 = v93;
  v93[52] = (ksgui::Control *)1056964608;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  std::wstring::assign(&result.name, L"ROLL", 4u);
  LOBYTE(v279) = 34;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v94 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v94 + 28))(1112014848, LODWORD(top));
  v95 = (int)v268;
  v96 = *((float *)v268 + 66);
  v97 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v98 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v95 + 28) = 1126825984;
  v99 = v97 + 170.0;
  v100 = v98 + 105.0;
  *(float *)(v95 + 32) = v99;
  *(float *)(v95 + 40) = v100;
  if ( v96 == 0.0 && *(float *)(v95 + 272) == 0.0 )
  {
    *(_DWORD *)(v95 + 264) = 1126825984;
    *(_DWORD *)(v95 + 272) = 1121058816;
    *(float *)(v95 + 268) = v99;
    *(float *)(v95 + 276) = v100;
  }
  _Val = v95;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 35;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"YawLeft");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v101 = 0;
  }
  LOBYTE(v279) = 4;
  v268 = v101;
  v101[52] = (ksgui::Control *)1056964608;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  std::wstring::assign(&result.name, L"YAW", 3u);
  LOBYTE(v279) = 36;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v102 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v102 + 28))(1112014848, LODWORD(top));
  v103 = (int)v268;
  v104 = *((float *)v268 + 66);
  v105 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v106 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v103 + 28) = 1130430464;
  v107 = v105 + 225.0;
  v108 = v106 + 105.0;
  *(float *)(v103 + 32) = v107;
  *(float *)(v103 + 40) = v108;
  if ( v104 == 0.0 && *(float *)(v103 + 272) == 0.0 )
  {
    *(_DWORD *)(v103 + 264) = 1130430464;
    *(_DWORD *)(v103 + 272) = 1121058816;
    *(float *)(v103 + 268) = v107;
    *(float *)(v103 + 276) = v108;
  }
  _Val = v103;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 37;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"YawRight");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v109 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"YAW";
  v268 = v109;
  v109[52] = (ksgui::Control *)1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 38;
  ((void (*)(ksgui::Control **, FriendsLeaderboardDisplayer::FriendsLeaderboardElement *))LODWORD((*v268)->borderColor.z))(
    v268,
    &result);
  LOBYTE(v279) = 4;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v110 = (int)*v268;
  top = 10.0;
  *(_OWORD *)(v268 + 11) = _xmm;
  (*(void (__stdcall **)(int, _DWORD))(v110 + 28))(1112014848, LODWORD(top));
  v111 = (int)v268;
  v112 = *((float *)v268 + 66);
  v113 = *((float *)v268 + 8) - *((float *)v268 + 7);
  v114 = *((float *)v268 + 10) - *((float *)v268 + 9);
  v268[9] = (ksgui::Control *)1121058816;
  *(_DWORD *)(v111 + 28) = 1133248512;
  v115 = v113 + 280.0;
  v116 = v114 + 105.0;
  *(float *)(v111 + 32) = v115;
  *(float *)(v111 + 40) = v116;
  if ( v112 == 0.0 && *(float *)(v111 + 272) == 0.0 )
  {
    *(_DWORD *)(v111 + 264) = 1133248512;
    *(_DWORD *)(v111 + 272) = 1121058816;
    *(float *)(v111 + 268) = v115;
    *(float *)(v111 + 276) = v116;
  }
  _Val = v111;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 39;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"PitchUP_V");
    LOBYTE(v279) = 40;
    top = *(float *)&this->gui;
    v270 = v5 | 4;
    v273 = (ksgui::Form *)(v5 | 4);
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v118 = v117;
  }
  else
  {
    v118 = 0;
  }
  v279 = 4;
  if ( (v270 & 4) != 0 )
  {
    v270 &= 0xFFFFFFFB;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
  }
  LODWORD(top) = L"Up";
  v118[52] = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 42;
  (*(void (**)(float *, std::wstring *))(*(_DWORD *)v118 + 68))(v118, &text);
  LOBYTE(v279) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  (*(void (**)(float *, int, int))(*(_DWORD *)v118 + 28))(v118, 1112014848, 1101004800);
  (*(void (**)(float *, int))(*(_DWORD *)v118 + 64))(v118, 1028443341);
  v119 = v118[66];
  v120 = v118[8] - v118[7];
  v121 = v118[10] - v118[9];
  v118[9] = 115.0;
  v118[7] = 5.0;
  v122 = v120 + 5.0;
  v123 = v121 + 115.0;
  v118[8] = v122;
  v118[10] = v123;
  if ( v119 == 0.0 && v118[68] == 0.0 )
  {
    v118[66] = 5.0;
    v118[68] = 115.0;
    v118[67] = v122;
    v118[69] = v123;
  }
  *(_DWORD *)&v258[4] = &std::_Func_impl<std::_Callable_obj<_lambda_87d3c16ee7ef238ff66e8cd5b5698f9e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v258[8] = this;
  *(_DWORD *)&v258[20] = &v258[4];
  LOBYTE(v279) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v118 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    v118);
  _Val = (int)v118;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v124 = (CarAudioFMOD *)operator new(LODWORD(top));
  v272.__this = v124;
  LOBYTE(v279) = 44;
  if ( v124 )
  {
    std::wstring::wstring(&result.name, L"PitchDOWN_V");
    LOBYTE(v279) = 45;
    top = *(float *)&this->gui;
    v270 |= 8u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v124, &result.name, (ksgui::GUI *)LODWORD(top));
    v126 = v125;
  }
  else
  {
    v126 = 0;
  }
  v279 = 4;
  if ( (v270 & 8) != 0 )
  {
    v270 &= 0xFFFFFFF7;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
  }
  LODWORD(top) = L"Down";
  v126[52] = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 47;
  (*(void (**)(float *, std::wstring *))(*(_DWORD *)v126 + 68))(v126, &text);
  LOBYTE(v279) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  (*(void (**)(float *, int, int))(*(_DWORD *)v126 + 28))(v126, 1112014848, 1101004800);
  (*(void (**)(float *, int))(*(_DWORD *)v126 + 64))(v126, 1028443341);
  v127 = v126[66];
  v128 = v126[8] - v126[7];
  v129 = v126[10] - v126[9];
  v126[9] = 115.0;
  v126[7] = 60.0;
  v130 = v128 + 60.0;
  v131 = v129 + 115.0;
  v126[8] = v130;
  v126[10] = v131;
  if ( v127 == 0.0 && v126[68] == 0.0 )
  {
    v126[66] = 60.0;
    v126[68] = 115.0;
    v126[67] = v130;
    v126[69] = v131;
  }
  *(_DWORD *)&v258[4] = &std::_Func_impl<std::_Callable_obj<_lambda_da4d593f7ee8b9f30268a21e6b44fc2a_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v258[8] = this;
  *(_DWORD *)&v258[20] = &v258[4];
  LOBYTE(v279) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v126 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    v126);
  _Val = (int)v126;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v132 = (CarAudioFMOD *)operator new(LODWORD(top));
  v272.__this = v132;
  LOBYTE(v279) = 49;
  if ( v132 )
  {
    std::wstring::wstring(&result.name, L"RollLeft_V");
    LOBYTE(v279) = 50;
    top = *(float *)&this->gui;
    v270 |= 0x10u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v132, &result.name, (ksgui::GUI *)LODWORD(top));
    v134 = v133;
  }
  else
  {
    v134 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x10) != 0 )
  {
    v270 &= 0xFFFFFFEF;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
  }
  LODWORD(top) = L"Left";
  v134[52] = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 52;
  (*(void (**)(float *, std::wstring *))(*(_DWORD *)v134 + 68))(v134, &text);
  LOBYTE(v279) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  (*(void (**)(float *, int, int))(*(_DWORD *)v134 + 28))(v134, 1112014848, 1101004800);
  (*(void (**)(float *, int))(*(_DWORD *)v134 + 64))(v134, 1028443341);
  v135 = v134[66];
  v136 = v134[8] - v134[7];
  v137 = v134[10] - v134[9];
  v134[9] = 115.0;
  v134[7] = 115.0;
  v138 = v136 + 115.0;
  v139 = v137 + 115.0;
  v134[8] = v138;
  v134[10] = v139;
  if ( v135 == 0.0 && v134[68] == 0.0 )
  {
    v134[66] = 115.0;
    v134[68] = 115.0;
    v134[67] = v138;
    v134[69] = v139;
  }
  *(_DWORD *)&v258[4] = &std::_Func_impl<std::_Callable_obj<_lambda_6955a9ab5b92abd0b1bfb5d53710e97d_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v258[8] = this;
  *(_DWORD *)&v258[20] = &v258[4];
  LOBYTE(v279) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v134 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    v134);
  _Val = (int)v134;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(top) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v272.__this = (CarAudioFMOD *)operator new(LODWORD(top));
  LOBYTE(v279) = 54;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"RollRight_V");
    LOBYTE(v279) = 55;
    top = *(float *)&this->gui;
    v270 |= 0x20u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v140;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x20) != 0 )
  {
    v270 &= 0xFFFFFFDF;
    if ( result.name._Myres >= 8 )
    {
      LODWORD(top) = result.name._Myres + 1;
      *(_DWORD *)&v258[24] = result.name._Bx._Ptr;
      v141 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                          (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&result,
                                          (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v267 + 3);
      std::allocator<wchar_t>::deallocate(v141, *(wchar_t **)&v258[24], LODWORD(top));
    }
    result.name._Myres = 7;
    std::wstring::_Eos(&result.name, 0);
  }
  LODWORD(top) = L"Right";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 57;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 170.0, 115.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v142);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 58;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"YawLeft_V");
    LOBYTE(v279) = 59;
    top = *(float *)&this->gui;
    v270 |= 0x40u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v143;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x40) != 0 )
  {
    v270 &= 0xFFFFFFBF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Left";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 61;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 225.0, 115.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v144);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 62;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"YawRight_V");
    LOBYTE(v279) = 63;
    top = *(float *)&this->gui;
    v270 |= 0x80u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v145;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x80u) != 0 )
  {
    v270 &= 0xFFFFFF7F;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Right";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 65;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 280.0, 115.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v146);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 66;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"ElevUP");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v147 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"ELEV";
  v271 = (ksgui::Form *)v147;
  *(_DWORD *)(v147 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 67;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v149 = (vec4f)_mm_loadu_si128(v148);
  v150 = v271->__vftable;
  top = 10.0;
  v271->backColor = v149;
  ((void (__stdcall *)(int, _DWORD))v150->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 5.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 68;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"ElevDOWN");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v151 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"ELEV";
  v271 = (ksgui::Form *)v151;
  *(_DWORD *)(v151 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 69;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v153 = (vec4f)_mm_loadu_si128(v152);
  v154 = v271->__vftable;
  top = 10.0;
  v271->backColor = v153;
  ((void (__stdcall *)(int, _DWORD))v154->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 60.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 70;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"StrafeLeft");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v155 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"STRAFE";
  v271 = (ksgui::Form *)v155;
  *(_DWORD *)(v155 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 71;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v157 = (vec4f)_mm_loadu_si128(v156);
  v158 = v271->__vftable;
  top = 10.0;
  v271->backColor = v157;
  ((void (__stdcall *)(int, _DWORD))v158->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 115.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 72;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"StrafeRight");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v159 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"STRAFE";
  v271 = (ksgui::Form *)v159;
  *(_DWORD *)(v159 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 73;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v161 = (vec4f)_mm_loadu_si128(v160);
  v162 = v271->__vftable;
  top = 10.0;
  v271->backColor = v161;
  ((void (__stdcall *)(int, _DWORD))v162->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 170.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 74;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"MoveFor");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v163 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"MOVE";
  v271 = (ksgui::Form *)v163;
  *(_DWORD *)(v163 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 75;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v165 = (vec4f)_mm_loadu_si128(v164);
  v166 = v271->__vftable;
  top = 10.0;
  v271->backColor = v165;
  ((void (__stdcall *)(int, _DWORD))v166->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 225.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 76;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"MoveBack");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v167 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"MOVE";
  v271 = (ksgui::Form *)v167;
  *(_DWORD *)(v167 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 77;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v169 = (vec4f)_mm_loadu_si128(v168);
  v170 = v271->__vftable;
  top = 10.0;
  v271->backColor = v169;
  ((void (__stdcall *)(int, _DWORD))v170->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 280.0, 140.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 78;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"ElevUP_V");
    LOBYTE(v279) = 79;
    top = *(float *)&this->gui;
    v270 |= 0x100u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v171;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x100) != 0 )
  {
    v270 &= 0xFFFFFEFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Up";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 81;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 5.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v172);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 82;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"ElevDOWN_V");
    LOBYTE(v279) = 83;
    top = *(float *)&this->gui;
    v270 |= 0x200u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v173;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x200) != 0 )
  {
    v270 &= 0xFFFFFDFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Down";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 85;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 60.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v174);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 86;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"StrafeLeft_V");
    LOBYTE(v279) = 87;
    top = *(float *)&this->gui;
    v270 |= 0x400u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v175;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x400) != 0 )
  {
    v270 &= 0xFFFFFBFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Left";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 89;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 115.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v176);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 90;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"StrafeRight_V");
    LOBYTE(v279) = 91;
    top = *(float *)&this->gui;
    v270 |= 0x800u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v177;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x800) != 0 )
  {
    v270 &= 0xFFFFF7FF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Right";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 93;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 170.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v178);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 94;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"MoveFor_V");
    LOBYTE(v279) = 95;
    top = *(float *)&this->gui;
    v270 |= 0x1000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v179;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x1000) != 0 )
  {
    v270 &= 0xFFFFEFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Forw";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 97;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 225.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v180);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 98;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"MoveBack_V");
    LOBYTE(v279) = 99;
    top = *(float *)&this->gui;
    v270 |= 0x2000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v181;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x2000) != 0 )
  {
    v270 &= 0xFFFFDFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"Back";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 101;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  ksgui::Form::setPosition(v273, 280.0, 150.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v182);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 102;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"ExpDec");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v183 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"EXP";
  v271 = (ksgui::Form *)v183;
  *(_DWORD *)(v183 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 103;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v185 = (vec4f)_mm_loadu_si128(v184);
  v186 = v271->__vftable;
  top = 10.0;
  v271->backColor = v185;
  ((void (__stdcall *)(int, _DWORD))v186->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 5.0, 175.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 104;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Val");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v187 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"CURRENT";
  v271 = (ksgui::Form *)v187;
  *(_DWORD *)(v187 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 105;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v189 = (vec4f)_mm_loadu_si128(v188);
  v190 = v271->__vftable;
  top = 10.0;
  v271->backColor = v189;
  ((void (__stdcall *)(int, _DWORD))v190->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 60.0, 175.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 106;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"ExpInc");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v191 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"EXP";
  v271 = (ksgui::Form *)v191;
  *(_DWORD *)(v191 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 107;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v193 = (vec4f)_mm_loadu_si128(v192);
  v194 = v271->__vftable;
  top = 10.0;
  v271->backColor = v193;
  ((void (__stdcall *)(int, _DWORD))v194->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 115.0, 175.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 108;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"SensB");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
    v271 = v195;
  }
  else
  {
    v271 = 0;
  }
  LOBYTE(v279) = 4;
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  LODWORD(top) = word_17BE9D8;
  v271->backColor = (vec4f)_mm_loadu_si128(v196);
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 109;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Form *, int, int))v271->setSize)(v271, 1126170624, 1092616192);
  ksgui::Form::setPosition(v271, 170.0, 175.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 110;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"SensLabel");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
    v271 = v197;
  }
  else
  {
    v271 = 0;
  }
  LOBYTE(v279) = 4;
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  LODWORD(top) = L"SENSITIVITY";
  v199 = (vec4f)_mm_loadu_si128(v198);
  v200 = v271;
  v271->backColor = v199;
  v200->fontScale = 0.5;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 111;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Form *, int, int))v271->setSize)(v271, 1112014848, 1092616192);
  ksgui::Form::setPosition(v271, 170.0, 175.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 112;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"ExpDec_V");
    LOBYTE(v279) = 113;
    top = *(float *)&this->gui;
    v270 |= 0x4000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v201;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x4000) != 0 )
  {
    v270 &= 0xFFFFBFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"-";
  v273->fontScale = 0.80000001;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 115;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ksgui::Form::setPosition(v273, 5.0, 185.0);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v202);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 116;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"e");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v203 = 0;
  }
  LOBYTE(v279) = 4;
  this->explabel = (ksgui::Label *)v203;
  *(_DWORD *)(v203 + 208) = 1060320051;
  ((void (*)(ksgui::Label *, int, int))this->explabel->setSize)(this->explabel, 1101004800, 1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->explabel, 75.0, 185.0);
  ksgui::Control::addControl(this, this->explabel);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 117;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"ExpInc_V");
    LOBYTE(v279) = 118;
    top = *(float *)&this->gui;
    v270 |= 0x8000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v204;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x8000) != 0 )
  {
    v270 &= 0xFFFF7FFF;
    std::wstring::~wstring(&result);
  }
  v205 = v273->__vftable;
  top = 20.0;
  v273->fontScale = 0.69999999;
  ((void (__stdcall *)(int, _DWORD))v205->setSize)(1112014848, LODWORD(top));
  std::wstring::wstring(&text, L"+");
  LOBYTE(v279) = 120;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ksgui::Form::setPosition(v273, 115.0, 185.0);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v206);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = 121;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"SenDec");
    LOBYTE(v279) = 122;
    top = *(float *)&this->gui;
    v270 |= 0x10000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v207;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x10000) != 0 )
  {
    v270 &= 0xFFFEFFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"-";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 124;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1101004800, 1101004800);
  ksgui::Form::setPosition(v273, 170.0, 185.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v208);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 125;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Sens1");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v209 = 0;
  }
  LOBYTE(v279) = 4;
  _Val = (int)v209;
  this->sensLabel[0] = v209;
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  LODWORD(top) = L" ";
  *(__m128i *)(_Val + 44) = _mm_loadu_si128(v210);
  this->sensLabel[0]->fontScale = 0.69999999;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 126;
  this->sensLabel[0]->setText(this->sensLabel[0], (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Label *, int, int))this->sensLabel[0]->setSize)(
    this->sensLabel[0],
    1109393408,
    1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->sensLabel[0], 190.0, 185.0);
  ksgui::Control::addControl(this, this->sensLabel[0]);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = 127;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Sens2");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v211 = 0;
  }
  LOBYTE(v279) = 4;
  _Val = (int)v211;
  this->sensLabel[1] = v211;
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  LODWORD(top) = L" ";
  *(__m128i *)(_Val + 44) = _mm_loadu_si128(v212);
  this->sensLabel[1]->fontScale = 0.69999999;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = 0x80;
  this->sensLabel[1]->setText(this->sensLabel[1], (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Label *, int, int))this->sensLabel[1]->setSize)(
    this->sensLabel[1],
    1109393408,
    1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->sensLabel[1], 230.0, 185.0);
  ksgui::Control::addControl(this, this->sensLabel[1]);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -127;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Sens3");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v213 = 0;
  }
  LOBYTE(v279) = 4;
  _Val = (int)v213;
  this->sensLabel[2] = v213;
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  LODWORD(top) = L" ";
  *(__m128i *)(_Val + 44) = _mm_loadu_si128(v214);
  this->sensLabel[2]->fontScale = 0.69999999;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -126;
  this->sensLabel[2]->setText(this->sensLabel[2], (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Label *, int, int))this->sensLabel[2]->setSize)(
    this->sensLabel[2],
    1109393408,
    1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->sensLabel[2], 270.0, 185.0);
  ksgui::Control::addControl(this, this->sensLabel[2]);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -125;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"SenInc");
    LOBYTE(v279) = -124;
    top = *(float *)&this->gui;
    v270 |= 0x20000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v215;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x20000) != 0 )
  {
    v270 &= 0xFFFDFFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"+";
  v273->fontScale = 0.69999999;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -122;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1101004800, 1101004800);
  ksgui::Form::setPosition(v273, 310.0, 185.0);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v216);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -121;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"FovDec");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v217 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"FOV";
  v271 = (ksgui::Form *)v217;
  *(_DWORD *)(v217 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -120;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v219 = (vec4f)_mm_loadu_si128(v218);
  v220 = v271->__vftable;
  top = 10.0;
  v271->backColor = v219;
  ((void (__stdcall *)(int, _DWORD))v220->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 5.0, 210.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -119;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Valf");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v221 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"CURRENT";
  v271 = (ksgui::Form *)v221;
  *(_DWORD *)(v221 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -118;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v223 = (vec4f)_mm_loadu_si128(v222);
  v224 = v271->__vftable;
  top = 10.0;
  v271->backColor = v223;
  ((void (__stdcall *)(int, _DWORD))v224->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 60.0, 210.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -117;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"FovInc");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v225 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"FOV";
  v271 = (ksgui::Form *)v225;
  *(_DWORD *)(v225 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -116;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v227 = (vec4f)_mm_loadu_si128(v226);
  v228 = v271->__vftable;
  top = 10.0;
  v271->backColor = v227;
  ((void (__stdcall *)(int, _DWORD))v228->setSize)(1112014848, LODWORD(top));
  ksgui::Form::setPosition(v271, 115.0, 210.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -115;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"Sound");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v229 = 0;
  }
  LOBYTE(v279) = 4;
  LODWORD(top) = L"Sound";
  v271 = (ksgui::Form *)v229;
  *(_DWORD *)(v229 + 208) = 1056964608;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -114;
  v271->setText(v271, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 0.0, 0.0, 1.0);
  v231 = (vec4f)_mm_loadu_si128(v230);
  v232 = v271->__vftable;
  top = 10.0;
  v271->backColor = v231;
  ((void (__stdcall *)(int, _DWORD))v232->setSize)(1126170624, LODWORD(top));
  ksgui::Form::setPosition(v271, 170.0, 210.0);
  ksgui::Control::addControl(this, v271);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -113;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"FovDec_V");
    LOBYTE(v279) = -112;
    top = *(float *)&this->gui;
    v270 |= 0x40000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v233;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x40000) != 0 )
  {
    v270 &= 0xFFFBFFFF;
    std::wstring::~wstring(&result);
  }
  LODWORD(top) = L"-";
  v273->fontScale = 0.80000001;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -110;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v273->setSize)(v273, 1112014848, 1101004800);
  ksgui::Form::setPosition(v273, 5.0, 220.0);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v234);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x11Cu);
  LOBYTE(v279) = -109;
  if ( v272.__this )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v258[4], L"f");
    ksgui::Label::Label((ksgui::Label *)v272.__this, *(std::wstring *)&v258[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v235 = 0;
  }
  LOBYTE(v279) = 4;
  this->fovlabel = (ksgui::Label *)v235;
  *(_DWORD *)(v235 + 208) = 1060320051;
  ((void (*)(ksgui::Label *, int, int))this->fovlabel->setSize)(this->fovlabel, 1101004800, 1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->fovlabel, 75.0, 220.0);
  ksgui::Control::addControl(this, this->fovlabel);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -108;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"FovInc_V");
    LOBYTE(v279) = -107;
    top = *(float *)&this->gui;
    v270 |= 0x80000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v273 = v236;
  }
  else
  {
    v273 = 0;
  }
  v279 = 4;
  if ( (v270 & 0x80000) != 0 )
  {
    v270 &= 0xFFF7FFFF;
    std::wstring::~wstring(&result);
  }
  v237 = v273->__vftable;
  top = 20.0;
  v273->fontScale = 0.69999999;
  ((void (__stdcall *)(int, _DWORD))v237->setSize)(1112014848, LODWORD(top));
  std::wstring::wstring(&text, L"+");
  LOBYTE(v279) = -105;
  v273->setText(v273, &text);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ksgui::Form::setPosition(v273, 115.0, 220.0);
  ((void (*)(ksgui::Form *, int))v273->setRepeatInterval)(v273, 1028443341);
  LODWORD(top) = v273;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v238);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v273->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, v273);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -104;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"ExtSound");
    LOBYTE(v279) = -103;
    top = *(float *)&this->gui;
    v270 |= 0x100000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v239 = 0;
  }
  this->extSound = v239;
  v279 = 4;
  if ( (v270 & 0x100000) != 0 )
  {
    v270 &= 0xFFEFFFFF;
    std::wstring::~wstring(&result);
  }
  v240 = this->extSound;
  LODWORD(top) = L"External";
  v240->fontScale = 0.80000001;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -101;
  this->extSound->setText(this->extSound, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Control *, int, int))this->extSound->setSize)(this->extSound, 1117388800, 1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->extSound, 170.0, 220.0);
  ((void (*)(ksgui::Control *, int))this->extSound->setRepeatInterval)(this->extSound, 1028443341);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 1.0, 1.0, 1.0);
  this->extSound->backColor = (vec4f)_mm_loadu_si128(v241);
  top = *(float *)&this->extSound;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v242);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->extSound->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, this->extSound);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -100;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"IntSound");
    LOBYTE(v279) = -99;
    top = *(float *)&this->gui;
    v270 |= 0x200000u;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v243 = 0;
  }
  this->intSound = v243;
  v279 = 4;
  if ( (v270 & 0x200000) != 0 )
  {
    v270 &= 0xFFDFFFFF;
    std::wstring::~wstring(&result);
  }
  v244 = this->intSound;
  LODWORD(top) = L"Internal";
  v244->fontScale = 0.80000001;
  std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(top));
  LOBYTE(v279) = -97;
  this->intSound->setText(this->intSound, (const std::wstring *)&result);
  LOBYTE(v279) = 4;
  std::wstring::~wstring(&result);
  ((void (*)(ksgui::Control *, int, int))this->intSound->setSize)(this->intSound, 1117388800, 1101004800);
  ksgui::Form::setPosition((ksgui::Form *)this->intSound, 253.0, 220.0);
  ((void (*)(ksgui::Control *, int))this->intSound->setRepeatInterval)(this->intSound, 1028443341);
  vec4f::vec4f((vec4f *)&text._Bx._Alias[8], 1.0, 1.0, 1.0, 1.0);
  this->intSound->backColor = (vec4f)_mm_loadu_si128(v245);
  top = *(float *)&this->intSound;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v246);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->intSound->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Control::addControl(this, this->intSound);
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -96;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"SETCAMERA");
    LOBYTE(v279) = -95;
    top = *(float *)&this->gui;
    v270 |= (unsigned int)&_ImageBase;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v271 = v247;
  }
  else
  {
    v271 = 0;
  }
  v279 = 4;
  if ( ((unsigned int)&_ImageBase & v270) != 0 )
  {
    v270 &= 0xFFBFFFFF;
    std::wstring::~wstring(&result);
  }
  ksgui::Control::addControl(this, v271);
  std::wstring::wstring(&text, L"SET");
  LOBYTE(v279) = -93;
  v248 = acTranslate(&v275, &text);
  LOBYTE(v279) = -92;
  v271->setText(v271, v248);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v275);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v271->setSize)(v271, 1112014848, 1106247680);
  ksgui::Form::setPosition(v271, 5.0, 245.0);
  LODWORD(top) = v271;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v249);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v271->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  v272.__this = (CarAudioFMOD *)operator new(0x118u);
  LOBYTE(v279) = -91;
  if ( v272.__this )
  {
    std::wstring::wstring(&result.name, L"SAVE CAMERACAR");
    LOBYTE(v279) = -90;
    top = *(float *)&this->gui;
    v270 |= (unsigned int)&loc_800000;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v272.__this, &result.name, (ksgui::GUI *)LODWORD(top));
    v271 = v250;
  }
  else
  {
    v271 = 0;
  }
  v279 = 4;
  if ( ((unsigned int)&loc_800000 & v270) != 0 )
  {
    v270 &= 0xFF7FFFFF;
    std::wstring::~wstring(&result);
  }
  ksgui::Control::addControl(this, v271);
  std::wstring::wstring(&text, L"SAVE CAMERAS");
  LOBYTE(v279) = -88;
  v251 = acTranslate(&v275, &text);
  LOBYTE(v279) = -87;
  v271->setText(v271, v251);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v275);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  ((void (*)(ksgui::Form *, int, int))v271->setSize)(v271, 1126170624, 1106247680);
  ksgui::Form::setPosition(v271, 60.0, 245.0);
  LODWORD(top) = v271;
  CommandItem::CommandItem(&v272, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v252);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&v271->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  v253 = (CarAudioFMOD *)operator new(0x118u);
  v272.__this = v253;
  LOBYTE(v279) = -86;
  if ( v253 )
  {
    std::wstring::wstring(&result.name, L"AUTOEXP");
    LOBYTE(v279) = -85;
    top = *(float *)&this->gui;
    v270 |= (unsigned int)&unk_1000000;
    v273 = (ksgui::Form *)v270;
    ksgui::Control::Control((ksgui::Control *)v253, &result.name, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v254 = 0;
  }
  _Val = v254;
  v279 = 4;
  if ( ((unsigned int)&unk_1000000 & v270) != 0 )
    std::wstring::~wstring(&result);
  v255 = _Val;
  ksgui::Control::addControl(this, (ksgui::Control *)_Val);
  std::wstring::wstring(&text, L"AUTO EXP");
  LOBYTE(v279) = -83;
  v256 = acTranslate(&v275, &text);
  LOBYTE(v279) = -82;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v255 + 68))(v255, v256);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v275);
  LOBYTE(v279) = 4;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  (*(void (**)(int, int, int))(*(_DWORD *)v255 + 28))(v255, 1123024896, 1106247680);
  ksgui::Form::setPosition((ksgui::Form *)v255, 225.0, 245.0);
  LODWORD(top) = v255;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Val,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v258[4],
    v257);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)(v255 + 156),
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v258[4],
    (void *)LODWORD(top));
  ksgui::Form::setSize(this, 350.0, 280.0);
  LOBYTE(v279) = 3;
  INIReader::~INIReader(&v274);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ifilename);
}
void FormCamera::render(FormCamera *this, float dt)
{
  CameraMode v3; // eax
  int v4; // ebx
  int v5; // esi
  CarAvatar *v6; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  Sim *v10; // ecx
  int v11; // esi
  std::wstring *v12; // eax
  const unsigned __int16 *v13; // edx
  unsigned int v14; // ecx
  std::wstring *v15; // eax
  const unsigned __int16 *v16; // edx
  unsigned int v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  int v24; // eax
  __int16 v25; // cx
  bool v26; // zf
  float v27; // xmm0_4
  float v28; // eax
  __int64 v29; // [esp+Ch] [ebp-8Ch]
  float v30; // [esp+14h] [ebp-84h]
  int _Val; // [esp+20h] [ebp-78h]
  std::wstring v32; // [esp+24h] [ebp-74h] BYREF
  std::wstring v33; // [esp+3Ch] [ebp-5Ch] BYREF
  std::wstring v34; // [esp+54h] [ebp-44h] BYREF
  std::wstring result; // [esp+6Ch] [ebp-2Ch] BYREF
  int v36; // [esp+94h] [ebp-4h]

  v3 = this->currentMode;
  v4 = 40;
  _Val = 60;
  if ( v3 )
  {
    if ( v3 == eCar )
    {
      v5 = this->currentCamera;
      v6 = Sim::getCar(this->sim, 0);
      v7 = v5;
      v8 = this->currentCamera;
      v4 = (int)v6->cameras._Myfirst[v7].exposure;
      _Val = (int)Sim::getCar(this->sim, 0)->cameras._Myfirst[v8].fov;
    }
  }
  else
  {
    v9 = this->currentCamera;
    v10 = this->sim;
    if ( v9 )
    {
      if ( v9 == 5 )
      {
        if ( !(int)Sim::getCar(v10, 0)->dashBoardExposure )
        {
          v11 = (int)Sim::getCar(this->sim, 0)->onBoardExposure;
          Sim::getCar(this->sim, 0)->dashBoardExposure = (float)v11;
        }
        v4 = (int)Sim::getCar(this->sim, 0)->dashBoardExposure;
      }
      else
      {
        v4 = (int)Sim::getCar(v10, 0)->outBoardExposure;
      }
    }
    else
    {
      v4 = (int)Sim::getCar(v10, 0)->onBoardExposure;
    }
  }
  v12 = std::to_wstring(&result, v4);
  v13 = (const unsigned __int16 *)v12;
  v36 = 0;
  if ( v12->_Myres >= 8 )
    v13 = v12->_Bx._Ptr;
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  if ( *v13 )
    v14 = wcslen(v13);
  else
    v14 = 0;
  std::wstring::assign(&v33, v13, v14);
  LOBYTE(v36) = 1;
  this->explabel->setText(this->explabel, &v33);
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  v36 = -1;
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v15 = std::to_wstring(&v34, _Val);
  v16 = (const unsigned __int16 *)v15;
  v36 = 2;
  if ( v15->_Myres >= 8 )
    v16 = v15->_Bx._Ptr;
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  if ( *v16 )
    v17 = wcslen(v16);
  else
    v17 = 0;
  std::wstring::assign(&v32, v16, v17);
  LOBYTE(v36) = 3;
  this->fovlabel->setText(this->fovlabel, &v32);
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v36 = -1;
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  if ( v34._Myres >= 8 )
    operator delete(v34._Bx._Ptr);
  v18 = this->targetExp;
  v34._Bx._Buf[0] = 0;
  v34._Myres = 7;
  v34._Mysize = 0;
  if ( v18 == 0.0 )
  {
    if ( this->isByButton )
    {
      v27 = dt + this->timing;
      this->timing = v27;
      if ( v27 > 3.0 )
      {
        v28 = this->cameraYebis->currentAutoExposure;
        ++this->currentLevel;
        this->targetExp = v28;
        this->timing = 0.0;
      }
    }
  }
  else
  {
    this->cameraYebis->useAutoExposureLimits = 0;
    v19 = dt + this->timing;
    this->timing = v19;
    if ( v19 > 3.0 )
    {
      v20 = this->targetExp;
      this->lastAutoExp = this->cameraYebis->currentAutoExposure;
      v21 = this->lastAutoExp;
      this->timing = 0.0;
      if ( v21 <= v20 )
      {
        if ( (float)(v20 - v21) > 0.05 )
          FormCamera::increaseExp(this);
        FormCamera::increaseExp(this);
        v23 = this->targetExp - this->lastAutoExp;
        this->lowExp = v4;
        this->lowDiff = v23;
      }
      else
      {
        if ( (float)(v21 - v20) > 0.05 )
          FormCamera::decreaseExp(this);
        FormCamera::decreaseExp(this);
        v22 = this->lastAutoExp - this->targetExp;
        this->highExp = v4;
        this->highDiff = v22;
      }
      LOWORD(v24) = this->highExp;
      if ( (_WORD)v24 )
      {
        v25 = this->lowExp;
        if ( v25 )
        {
          if ( this->highDiff <= this->lowDiff )
            v24 = (__int16)v24;
          else
            v24 = v25;
          FormCamera::setExp(this, (float)v24);
          ++this->currentLevel;
          *(_DWORD *)&this->highExp = 0;
        }
      }
    }
    switch ( this->currentLevel )
    {
      case 0:
        FormCamera::selectCamera(this, eCockpit, 0);
        break;
      case 1:
        FormCamera::selectCamera(this, eCar, 0);
        break;
      case 2:
        FormCamera::selectCamera(this, eCar, 1);
        break;
      case 3:
        FormCamera::selectCamera(this, eCar, 2);
        break;
      case 4:
        FormCamera::selectCamera(this, eCar, 3);
        break;
      case 5:
        FormCamera::selectCamera(this, eCar, 4);
        break;
      case 6:
        FormCamera::selectCamera(this, eCar, 5);
        break;
      case 7:
        FormCamera::selectCamera(this, eCockpit, 2);
        break;
      case 8:
        FormCamera::selectCamera(this, eCockpit, 5);
        break;
      case 9:
        FormCamera::savecameraF1(this);
        FormCamera::savecameraF6(this);
        v26 = !this->isByButton;
        this->targetExp = 0.0;
        if ( v26 )
          _exit(2);
        this->isByButton = 0;
        break;
      default:
        break;
    }
  }
  ksgui::Control::render(this, (int)this, (int)operator delete, dt, v29, v30);
}
void FormCamera::selectCamera(FormCamera *this, CameraMode mode, int index)
{
  Sim *v4; // ecx
  int v5; // edx
  ksgui::Control **v6; // ecx
  int v7; // eax
  int v8; // ecx
  ksgui::Control **v9; // edx
  int v10; // eax
  int v11; // esi
  int v12; // esi
  ksgui::Control *v13; // eax
  bool v14; // [esp+Fh] [ebp-1h]

  v4 = this->sim;
  this->currentMode = mode;
  ACCameraManager::setMode(v4->cameraManager, mode, 0, 0);
  v5 = 0;
  if ( this->F1_COUNT > 0 )
  {
    v6 = this->cameraF1;
    do
    {
      v7 = (int)*v6++;
      ++v5;
      *(_OWORD *)(v7 + 44) = 0i64;
    }
    while ( v5 < this->F1_COUNT );
  }
  v8 = 0;
  if ( this->F6_COUNT > 0 )
  {
    v9 = this->cameraF6;
    do
    {
      v10 = (int)*v9++;
      ++v8;
      *(_OWORD *)(v10 + 44) = 0i64;
    }
    while ( v8 < this->F6_COUNT );
  }
  if ( this->currentMode == eCockpit )
  {
    if ( this->targetExp != 0.0 && this->currentLevel != this->lastLevel && !this->isByButton )
    {
      FormCamera::savecameraF1(this);
      this->lastLevel = this->currentLevel;
    }
    ACCameraManager::setDrivableCarIndex(this->sim->cameraManager, index);
    this->currentCamera = index;
    this->cameraF1[index]->backColor = (vec4f)_xmm;
    this->extSound->backColor = (vec4f)_xmm;
    this->intSound->backColor = (vec4f)_xmm;
  }
  if ( this->currentMode == eCar )
  {
    if ( this->targetExp != 0.0 && this->currentLevel != this->lastLevel && !this->isByButton )
    {
      FormCamera::savecameraF6(this);
      this->lastLevel = this->currentLevel;
    }
    ACCameraManager::setCameraCarIndex(this->sim->cameraManager, index);
    this->currentCamera = index;
    this->cameraF6[index]->backColor = (vec4f)_xmm;
    v11 = this->currentCamera;
    v14 = Sim::getCar(this->sim, 0)->cameras._Myfirst[v11].externalSound;
    if ( this->currentMode == eCar )
    {
      v12 = this->currentCamera;
      Sim::getCar(this->sim, 0)->cameras._Myfirst[v12].externalSound = v14;
      v13 = this->intSound;
      if ( v14 )
      {
        v13->backColor = 0i64;
        this->extSound->backColor = (vec4f)_xmm;
      }
      else
      {
        v13->backColor = (vec4f)_xmm;
        this->extSound->backColor = 0i64;
      }
    }
  }
}
void FormCamera::setCamera(FormCamera *this)
{
  Node *v2; // eax
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  Sim *v7; // ecx
  int v8; // esi
  CameraCarDefinition *v9; // esi
  CameraForward *v10; // eax
  __int128 v11; // xmm1
  __int128 v12; // xmm2
  __int128 v13; // xmm3
  __m128 pDeterminant; // [esp+10h] [ebp-80h] BYREF
  __m128 v15; // [esp+20h] [ebp-70h]
  __m128 v16; // [esp+30h] [ebp-60h]
  __m128 v17; // [esp+40h] [ebp-50h]
  mat44f v18; // [esp+50h] [ebp-40h] BYREF

  if ( this->currentMode == eCar )
  {
    mat44f::mat44f(&v18);
    v2 = Sim::getCar(this->sim, 0)->bodyTransform;
    v3 = *(__m128 *)&v2->matrix.M21;
    v4 = *(__m128 *)&v2->matrix.M31;
    v5 = *(__m128 *)&v2->matrix.M41;
    v6 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&v2->matrix.M11, v3, v4, v5);
    v7 = this->sim;
    v8 = this->currentCamera;
    pDeterminant = v5;
    v15 = v4;
    v16 = v3;
    v17 = v6;
    v9 = &Sim::getCar(v7, 0)->cameras._Myfirst[v8];
    v10 = Sim::getSceneCamera(this->sim);
    *(__m128 *)&v18.M11 = v17;
    v11 = *(_OWORD *)&v10->matrix.M21;
    v12 = *(_OWORD *)&v10->matrix.M31;
    v13 = *(_OWORD *)&v10->matrix.M41;
    *(__m128 *)&v18.M21 = v16;
    *(__m128 *)&v18.M31 = v15;
    *(__m128 *)&v18.M41 = pDeterminant;
    *(__m128 *)&v9->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&v18, *(__m128 *)&v10->matrix.M11);
    *(_OWORD *)&v9->matrix.M21 = v11;
    *(_OWORD *)&v9->matrix.M31 = v12;
    *(_OWORD *)&v9->matrix.M41 = v13;
  }
}
void FormCamera::decreaseExp(FormCamera *this)
{
  CameraMode v1; // eax
  int v2; // esi
  CarAvatar *v3; // eax
  int v4; // eax
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax

  v1 = this->currentMode;
  if ( v1 )
  {
    if ( v1 == eCar )
    {
      v2 = this->currentCamera;
      v3 = Sim::getCar(this->sim, 0);
      v3->cameras._Myfirst[v2].exposure = v3->cameras._Myfirst[v2].exposure - 1.0;
    }
  }
  else
  {
    v4 = this->currentCamera;
    v5 = this->sim;
    if ( v4 )
    {
      if ( v4 == 5 )
      {
        v7 = Sim::getCar(v5, 0);
        v7->dashBoardExposure = v7->dashBoardExposure - 1.0;
      }
      else
      {
        v6 = Sim::getCar(v5, 0);
        v6->outBoardExposure = v6->outBoardExposure - 1.0;
      }
    }
    else
    {
      v8 = Sim::getCar(v5, 0);
      v8->onBoardExposure = v8->onBoardExposure - 1.0;
    }
  }
}
void FormCamera::increaseExp(FormCamera *this)
{
  CameraMode v1; // eax
  int v2; // esi
  CarAvatar *v3; // eax
  int v4; // eax
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax

  v1 = this->currentMode;
  if ( v1 )
  {
    if ( v1 == eCar )
    {
      v2 = this->currentCamera;
      v3 = Sim::getCar(this->sim, 0);
      v3->cameras._Myfirst[v2].exposure = v3->cameras._Myfirst[v2].exposure + 1.0;
    }
  }
  else
  {
    v4 = this->currentCamera;
    v5 = this->sim;
    if ( v4 )
    {
      if ( v4 == 5 )
      {
        v7 = Sim::getCar(v5, 0);
        v7->dashBoardExposure = v7->dashBoardExposure + 1.0;
      }
      else
      {
        v6 = Sim::getCar(v5, 0);
        v6->outBoardExposure = v6->outBoardExposure + 1.0;
      }
    }
    else
    {
      v8 = Sim::getCar(v5, 0);
      v8->onBoardExposure = v8->onBoardExposure + 1.0;
    }
  }
}
void __usercall FormCamera::setExp(FormCamera *this@<ecx>, float a2@<xmm1>)
{
  CameraMode v3; // eax
  int v4; // esi
  int v5; // eax
  Sim *v6; // ecx

  v3 = this->currentMode;
  if ( v3 )
  {
    if ( v3 == eCar )
    {
      v4 = this->currentCamera;
      Sim::getCar(this->sim, 0)->cameras._Myfirst[v4].exposure = a2;
    }
  }
  else
  {
    v5 = this->currentCamera;
    v6 = this->sim;
    if ( v5 )
    {
      if ( v5 == 5 )
        Sim::getCar(v6, 0)->dashBoardExposure = a2;
      else
        Sim::getCar(v6, 0)->outBoardExposure = a2;
    }
    else
    {
      Sim::getCar(v6, 0)->onBoardExposure = a2;
    }
  }
}
void FormCamera::updateSens(FormCamera *this)
{
  int v2; // esi
  ksgui::Label **v3; // edi
  ksgui::Label *v4; // ecx
  bool v5; // al
  bool v6; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v3 = this->sensLabel;
  do
  {
    v4 = *v3;
    v5 = this->currentSensibility > (float)v2;
    v6 = v5;
    if ( (*v3)->visible != v5 )
    {
      v4->visible = v5;
      v4->onVisibleChanged(v4, v6);
    }
    ++v2;
    ++v3;
  }
  while ( v2 < 3 );
}
void FormCamera::elev(FormCamera *this, int direction)
{
  CameraMode v3; // eax
  CameraForward *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  CameraForward *v7; // eax
  CameraForward *v8; // eax
  Node *v9; // eax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  Sim *v14; // ecx
  int v15; // esi
  CameraCarDefinition *v16; // esi
  CameraForward *v17; // eax
  int v18; // eax
  int v19; // eax
  Sim *v20; // ecx
  CameraDrivableManager *v21; // esi
  unsigned int v22; // ecx
  DrivableCameraDef *v23; // eax
  float v24; // xmm0_4
  __m128i v25; // xmm2
  __m128i v26; // xmm3
  __int64 v27; // xmm4_8
  Sim *v28; // ecx
  CameraDrivableManager *v29; // esi
  unsigned int v30; // ecx
  DrivableCameraDef *v31; // eax
  float v32; // xmm0_4
  __m128i v33; // xmm4
  __m128i v34; // xmm2
  __int64 v35; // xmm3_8
  int v36; // eax
  CarAvatar *v37; // eax
  _BYTE v38[56]; // [esp-38h] [ebp-A0h]
  float v39; // [esp+14h] [ebp-54h]
  float v40; // [esp+14h] [ebp-54h]
  float v41; // [esp+14h] [ebp-54h]
  DrivableCameraDef v42; // [esp+18h] [ebp-50h] BYREF
  __m128 v43; // [esp+50h] [ebp-18h]
  int v44; // [esp+60h] [ebp-8h] BYREF

  v39 = __libm_sse2_powf(this).m128_f32[0] * 0.0000099999997;
  DrivableCameraDef::DrivableCameraDef((DrivableCameraDef *)&v42.bumperCameraPos.z);
  v3 = this->currentMode;
  if ( v3 )
  {
    if ( v3 == eCar )
    {
      v4 = Sim::getSceneCamera(this->sim);
      v5 = (float)(v4->matrix.M22 * (float)direction) * v39;
      v6 = (float)(v4->matrix.M23 * (float)direction) * v39;
      v40 = (float)(v4->matrix.M21 * (float)direction) * v39;
      v7 = Sim::getSceneCamera(this->sim);
      v41 = v40 + v7->matrix.M41;
      v42.bumperCameraPos.y = v5 + v7->matrix.M42;
      v42.bumperCameraPos.x = v6 + v7->matrix.M43;
      v8 = Sim::getSceneCamera(this->sim);
      v8->matrix.M41 = v41;
      v8->matrix.M42 = v42.bumperCameraPos.y;
      v8->matrix.M43 = v42.bumperCameraPos.x;
      mat44f::mat44f((mat44f *)&v42.bumperCameraPos.z);
      v9 = Sim::getCar(this->sim, 0)->bodyTransform;
      v10 = *(__m128 *)&v9->matrix.M21;
      v11 = *(__m128 *)&v9->matrix.M31;
      v12 = *(__m128 *)&v9->matrix.M41;
      v13 = DirectX::XMMatrixInverse((__m128 *)&v44, *(__m128 *)&v9->matrix.M11, v10, v11, v12);
      v14 = this->sim;
      v15 = this->currentCamera;
      *(__m128 *)&v42.bumperCameraPos.z = v13;
      *(__m128 *)&v42.bonnetCameraPos.z = v10;
      *(__m128 *)&v42.dashCameraPos.y = v11;
      v43 = v12;
      v16 = &Sim::getCar(v14, 0)->cameras._Myfirst[v15];
      v17 = Sim::getSceneCamera(this->sim);
      mul(&v16->matrix, &v17->matrix, (const mat44f *)&v42.bumperCameraPos.z);
    }
  }
  else
  {
    v18 = this->currentCamera;
    if ( v18 )
    {
      v19 = v18 - 3;
      if ( v19 )
      {
        if ( v19 != 1 )
          return;
        v20 = this->sim;
        v21 = v20->cameraManager->cameraDrivable;
        v22 = Sim::getFocusedCarIndex(v20);
        v23 = v21->drivableCameraPositions._Myfirst;
        v24 = (float)((float)SLODWORD(v42.bumperCameraPos.x) * v39) + v23[v22].bumperCameraPos.y;
        v25 = _mm_loadu_si128((const __m128i *)&v23[v22].bonnetCameraPos);
        v26 = _mm_loadu_si128((const __m128i *)&v23[v22].chaseCameraPitch);
        v27 = *(_QWORD *)&v23[v22].rotationOffset;
        *(__m128i *)&v42.bumperCameraPos.z = _mm_loadu_si128((const __m128i *)&v23[v22]);
        v42.bumperCameraPitch = v24;
        *(__m128i *)v38 = _mm_loadu_si128((const __m128i *)&v42.bumperCameraPos.z);
        *(__m128i *)&v38[16] = v25;
        *(__m128i *)&v38[32] = v26;
        *(_QWORD *)&v38[48] = v27;
      }
      else
      {
        v28 = this->sim;
        v29 = v28->cameraManager->cameraDrivable;
        v30 = Sim::getFocusedCarIndex(v28);
        v31 = v29->drivableCameraPositions._Myfirst;
        v32 = (float)((float)SLODWORD(v42.bumperCameraPos.x) * v39) + v31[v30].bonnetCameraPos.y;
        v33 = _mm_loadu_si128((const __m128i *)&v31[v30]);
        v34 = _mm_loadu_si128((const __m128i *)&v31[v30].chaseCameraPitch);
        v35 = *(_QWORD *)&v31[v30].rotationOffset;
        *(__m128i *)&v42.bonnetCameraPos.z = _mm_loadu_si128((const __m128i *)&v31[v30].bonnetCameraPos);
        v42.bonnetCameraPitch = v32;
        *(__m128i *)v38 = v33;
        *(__m128i *)&v38[16] = _mm_loadu_si128((const __m128i *)&v42.bonnetCameraPos.z);
        *(__m128i *)&v38[32] = v34;
        *(_QWORD *)&v38[48] = v35;
      }
      v36 = Sim::getFocusedCarIndex(this->sim);
      CameraDrivableManager::setDrivableCameraDefAt(
        this->sim->cameraManager->cameraDrivable,
        v36,
        *(DrivableCameraDef *)v38);
    }
    else
    {
      v37 = Sim::getCar(this->sim, 0);
      v37->driverEyesPosition.y = (float)((float)direction * v39) + v37->driverEyesPosition.y;
    }
  }
}
void FormCamera::move(FormCamera *this, int direction)
{
  CameraMode v3; // eax
  CameraForward *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm1_4
  CameraForward *v7; // eax
  CameraForward *v8; // eax
  Node *v9; // eax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  Sim *v14; // ecx
  int v15; // esi
  CameraCarDefinition *v16; // esi
  CameraForward *v17; // eax
  int v18; // eax
  int v19; // eax
  Sim *v20; // ecx
  CameraDrivableManager *v21; // esi
  unsigned int v22; // ecx
  DrivableCameraDef *v23; // eax
  float v24; // xmm0_4
  __m128i v25; // xmm2
  __m128i v26; // xmm3
  __int64 v27; // xmm4_8
  Sim *v28; // ecx
  CameraDrivableManager *v29; // esi
  unsigned int v30; // ecx
  DrivableCameraDef *v31; // eax
  float v32; // xmm0_4
  __m128i v33; // xmm4
  __m128i v34; // xmm2
  __int64 v35; // xmm3_8
  int v36; // eax
  CarAvatar *v37; // eax
  _BYTE v38[56]; // [esp-38h] [ebp-A0h]
  float v39; // [esp+14h] [ebp-54h]
  float v40; // [esp+14h] [ebp-54h]
  float v41; // [esp+14h] [ebp-54h]
  DrivableCameraDef v42; // [esp+18h] [ebp-50h] BYREF
  __m128 v43; // [esp+50h] [ebp-18h]
  int v44; // [esp+60h] [ebp-8h] BYREF

  v39 = __libm_sse2_powf(this).m128_f32[0] * 0.0000099999997;
  DrivableCameraDef::DrivableCameraDef((DrivableCameraDef *)&v42.bumperCameraPos.z);
  v3 = this->currentMode;
  if ( v3 )
  {
    if ( v3 == eCar )
    {
      v4 = Sim::getSceneCamera(this->sim);
      v5 = (float)(COERCE_FLOAT(LODWORD(v4->matrix.M32) ^ _xmm) * (float)direction) * v39;
      v6 = (float)(COERCE_FLOAT(LODWORD(v4->matrix.M33) ^ _xmm) * (float)direction) * v39;
      v40 = (float)(COERCE_FLOAT(LODWORD(v4->matrix.M31) ^ _xmm) * (float)direction) * v39;
      v7 = Sim::getSceneCamera(this->sim);
      v41 = v40 + v7->matrix.M41;
      v42.bumperCameraPos.y = v5 + v7->matrix.M42;
      v42.bumperCameraPos.x = v6 + v7->matrix.M43;
      v8 = Sim::getSceneCamera(this->sim);
      v8->matrix.M41 = v41;
      v8->matrix.M42 = v42.bumperCameraPos.y;
      v8->matrix.M43 = v42.bumperCameraPos.x;
      mat44f::mat44f((mat44f *)&v42.bumperCameraPos.z);
      v9 = Sim::getCar(this->sim, 0)->bodyTransform;
      v10 = *(__m128 *)&v9->matrix.M21;
      v11 = *(__m128 *)&v9->matrix.M31;
      v12 = *(__m128 *)&v9->matrix.M41;
      v13 = DirectX::XMMatrixInverse((__m128 *)&v44, *(__m128 *)&v9->matrix.M11, v10, v11, v12);
      v14 = this->sim;
      v15 = this->currentCamera;
      *(__m128 *)&v42.bumperCameraPos.z = v13;
      *(__m128 *)&v42.bonnetCameraPos.z = v10;
      *(__m128 *)&v42.dashCameraPos.y = v11;
      v43 = v12;
      v16 = &Sim::getCar(v14, 0)->cameras._Myfirst[v15];
      v17 = Sim::getSceneCamera(this->sim);
      mul(&v16->matrix, &v17->matrix, (const mat44f *)&v42.bumperCameraPos.z);
    }
  }
  else
  {
    v18 = this->currentCamera;
    if ( v18 )
    {
      v19 = v18 - 3;
      if ( v19 )
      {
        if ( v19 != 1 )
          return;
        v20 = this->sim;
        v21 = v20->cameraManager->cameraDrivable;
        v22 = Sim::getFocusedCarIndex(v20);
        v23 = v21->drivableCameraPositions._Myfirst;
        v24 = (float)((float)SLODWORD(v42.bumperCameraPos.x) * v39) + v23[v22].bumperCameraPos.z;
        v25 = _mm_loadu_si128((const __m128i *)&v23[v22].bonnetCameraPos);
        v26 = _mm_loadu_si128((const __m128i *)&v23[v22].chaseCameraPitch);
        v27 = *(_QWORD *)&v23[v22].rotationOffset;
        *(__m128i *)&v42.bumperCameraPos.z = _mm_loadu_si128((const __m128i *)&v23[v22]);
        v42.bonnetCameraPos.x = v24;
        *(__m128i *)v38 = _mm_loadu_si128((const __m128i *)&v42.bumperCameraPos.z);
        *(__m128i *)&v38[16] = v25;
        *(__m128i *)&v38[32] = v26;
        *(_QWORD *)&v38[48] = v27;
      }
      else
      {
        v28 = this->sim;
        v29 = v28->cameraManager->cameraDrivable;
        v30 = Sim::getFocusedCarIndex(v28);
        v31 = v29->drivableCameraPositions._Myfirst;
        v32 = (float)((float)SLODWORD(v42.bumperCameraPos.x) * v39) + v31[v30].bonnetCameraPos.z;
        v33 = _mm_loadu_si128((const __m128i *)&v31[v30]);
        v34 = _mm_loadu_si128((const __m128i *)&v31[v30].chaseCameraPitch);
        v35 = *(_QWORD *)&v31[v30].rotationOffset;
        *(__m128i *)&v42.bonnetCameraPos.z = _mm_loadu_si128((const __m128i *)&v31[v30].bonnetCameraPos);
        v42.chaseCameraPitch = v32;
        *(__m128i *)v38 = v33;
        *(__m128i *)&v38[16] = _mm_loadu_si128((const __m128i *)&v42.bonnetCameraPos.z);
        *(__m128i *)&v38[32] = v34;
        *(_QWORD *)&v38[48] = v35;
      }
      v36 = Sim::getFocusedCarIndex(this->sim);
      CameraDrivableManager::setDrivableCameraDefAt(
        this->sim->cameraManager->cameraDrivable,
        v36,
        *(DrivableCameraDef *)v38);
    }
    else
    {
      v37 = Sim::getCar(this->sim, 0);
      v37->driverEyesPosition.z = (float)((float)direction * v39) + v37->driverEyesPosition.z;
    }
  }
}
void FormCamera::strafe(FormCamera *this, int direction)
{
  CameraMode v3; // eax
  CameraForward *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  CameraForward *v7; // eax
  CameraForward *v8; // eax
  Node *v9; // eax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  Sim *v14; // ecx
  int v15; // esi
  CameraCarDefinition *v16; // esi
  CameraForward *v17; // eax
  int v18; // eax
  int v19; // eax
  Sim *v20; // ecx
  CameraDrivableManager *v21; // esi
  unsigned int v22; // ecx
  DrivableCameraDef *v23; // eax
  __m128i v24; // xmm2
  __m128i v25; // xmm3
  __int64 v26; // xmm4_8
  Sim *v27; // ecx
  CameraDrivableManager *v28; // esi
  unsigned int v29; // ecx
  DrivableCameraDef *v30; // eax
  __m128i v31; // xmm4
  __m128i v32; // xmm2
  __int64 v33; // xmm3_8
  int v34; // eax
  CarAvatar *v35; // eax
  _BYTE v36[56]; // [esp-38h] [ebp-A0h]
  float v37; // [esp+14h] [ebp-54h]
  float v38; // [esp+14h] [ebp-54h]
  float v39; // [esp+14h] [ebp-54h]
  DrivableCameraDef v40; // [esp+18h] [ebp-50h] BYREF
  __m128 v41; // [esp+50h] [ebp-18h]
  int v42; // [esp+60h] [ebp-8h] BYREF

  v37 = __libm_sse2_powf(this).m128_f32[0] * 0.0000099999997;
  DrivableCameraDef::DrivableCameraDef((DrivableCameraDef *)&v40.bumperCameraPos.z);
  v3 = this->currentMode;
  if ( v3 )
  {
    if ( v3 == eCar )
    {
      v4 = Sim::getSceneCamera(this->sim);
      v5 = (float)(v4->matrix.M12 * (float)direction) * v37;
      v6 = (float)(v4->matrix.M13 * (float)direction) * v37;
      v38 = (float)(v4->matrix.M11 * (float)direction) * v37;
      v7 = Sim::getSceneCamera(this->sim);
      v39 = v38 + v7->matrix.M41;
      v40.bumperCameraPos.y = v5 + v7->matrix.M42;
      v40.bumperCameraPos.x = v6 + v7->matrix.M43;
      v8 = Sim::getSceneCamera(this->sim);
      v8->matrix.M41 = v39;
      v8->matrix.M42 = v40.bumperCameraPos.y;
      v8->matrix.M43 = v40.bumperCameraPos.x;
      mat44f::mat44f((mat44f *)&v40.bumperCameraPos.z);
      v9 = Sim::getCar(this->sim, 0)->bodyTransform;
      v10 = *(__m128 *)&v9->matrix.M21;
      v11 = *(__m128 *)&v9->matrix.M31;
      v12 = *(__m128 *)&v9->matrix.M41;
      v13 = DirectX::XMMatrixInverse((__m128 *)&v42, *(__m128 *)&v9->matrix.M11, v10, v11, v12);
      v14 = this->sim;
      v15 = this->currentCamera;
      *(__m128 *)&v40.bumperCameraPos.z = v13;
      *(__m128 *)&v40.bonnetCameraPos.z = v10;
      *(__m128 *)&v40.dashCameraPos.y = v11;
      v41 = v12;
      v16 = &Sim::getCar(v14, 0)->cameras._Myfirst[v15];
      v17 = Sim::getSceneCamera(this->sim);
      mul(&v16->matrix, &v17->matrix, (const mat44f *)&v40.bumperCameraPos.z);
    }
  }
  else
  {
    v18 = this->currentCamera;
    if ( v18 )
    {
      v19 = v18 - 3;
      if ( v19 )
      {
        if ( v19 != 1 )
          return;
        v20 = this->sim;
        v21 = v20->cameraManager->cameraDrivable;
        v22 = Sim::getFocusedCarIndex(v20);
        v23 = v21->drivableCameraPositions._Myfirst;
        v24 = _mm_loadu_si128((const __m128i *)&v23[v22].bonnetCameraPos);
        v25 = _mm_loadu_si128((const __m128i *)&v23[v22].chaseCameraPitch);
        v26 = *(_QWORD *)&v23[v22].rotationOffset;
        *(__m128i *)&v40.bumperCameraPos.z = _mm_loadu_si128((const __m128i *)&v23[v22]);
        v40.bumperCameraPos.z = v40.bumperCameraPos.z - (float)((float)SLODWORD(v40.bumperCameraPos.x) * v37);
        *(__m128i *)v36 = _mm_loadu_si128((const __m128i *)&v40.bumperCameraPos.z);
        *(__m128i *)&v36[16] = v24;
        *(__m128i *)&v36[32] = v25;
        *(_QWORD *)&v36[48] = v26;
      }
      else
      {
        v27 = this->sim;
        v28 = v27->cameraManager->cameraDrivable;
        v29 = Sim::getFocusedCarIndex(v27);
        v30 = v28->drivableCameraPositions._Myfirst;
        v31 = _mm_loadu_si128((const __m128i *)&v30[v29]);
        v32 = _mm_loadu_si128((const __m128i *)&v30[v29].chaseCameraPitch);
        v33 = *(_QWORD *)&v30[v29].rotationOffset;
        *(__m128i *)&v40.bonnetCameraPos.z = _mm_loadu_si128((const __m128i *)&v30[v29].bonnetCameraPos);
        *(__m128i *)v36 = v31;
        v40.bonnetCameraPos.z = v40.bonnetCameraPos.z - (float)((float)SLODWORD(v40.bumperCameraPos.x) * v37);
        *(__m128i *)&v36[16] = _mm_loadu_si128((const __m128i *)&v40.bonnetCameraPos.z);
        *(__m128i *)&v36[32] = v32;
        *(_QWORD *)&v36[48] = v33;
      }
      v34 = Sim::getFocusedCarIndex(this->sim);
      CameraDrivableManager::setDrivableCameraDefAt(
        this->sim->cameraManager->cameraDrivable,
        v34,
        *(DrivableCameraDef *)v36);
    }
    else
    {
      v35 = Sim::getCar(this->sim, 0);
      v35->driverEyesPosition.x = v35->driverEyesPosition.x - (float)((float)direction * v37);
    }
  }
}
void FormCamera::rotate(FormCamera *this, vec3f v, int direction)
{
  float v4; // xmm2_4
  float v5; // xmm4_4
  int v6; // ecx
  CameraMode v7; // eax
  CameraForward *v8; // eax
  Node *v9; // eax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  Sim *v14; // ecx
  int v15; // esi
  CameraCarDefinition *v16; // esi
  CameraForward *v17; // eax
  float v18; // xmm0_4
  int v19; // eax
  int v20; // eax
  Sim *v21; // ecx
  CameraDrivableManager *v22; // esi
  unsigned int v23; // ecx
  DrivableCameraDef *v24; // eax
  __m128i v25; // xmm2
  __m128i v26; // xmm3
  __int64 v27; // xmm4_8
  float v28; // xmm1_4
  Sim *v29; // ecx
  CameraDrivableManager *v30; // esi
  unsigned int v31; // ecx
  DrivableCameraDef *v32; // eax
  __m128i v33; // xmm2
  float v34; // xmm1_4
  int v35; // eax
  float v36; // xmm1_4
  CameraOnBoardCustomSettings *v37; // eax
  float v38; // xmm0_4
  _BYTE v39[56]; // [esp-38h] [ebp-D0h]
  mat44f *v40; // [esp-4h] [ebp-9Ch]
  float v41; // [esp+8h] [ebp-90h]
  float v42; // [esp+8h] [ebp-90h]
  __m128 pDeterminant; // [esp+10h] [ebp-88h] BYREF
  mat44f matrix2; // [esp+20h] [ebp-78h] BYREF
  DrivableCameraDef v45; // [esp+60h] [ebp-38h] BYREF

  *(double *)pDeterminant.m128_u64 = (float)(__libm_sse2_powf(this).m128_f32[0] * 0.001);
  *(double *)pDeterminant.m128_u64 = *(double *)pDeterminant.m128_u64
                                   * (*(double *)__libm_sse2_atan().m128_u64
                                    * 4.0
                                    * 0.005555555555555556
                                    * (double)direction);
  v41 = __libm_sse2_cosf().m128_f32[0];
  pDeterminant.m128_f32[0] = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&matrix2);
  matrix2.M44 = 1.0;
  matrix2.M22 = (float)((float)(v.y * v.y) * (float)(1.0 - v41)) + v41;
  matrix2.M11 = (float)((float)(v.x * v.x) * (float)(1.0 - v41)) + v41;
  v4 = (float)(v.y * v.x) * (float)(1.0 - v41);
  matrix2.M33 = (float)((float)(v.z * v.z) * (float)(1.0 - v41)) + v41;
  matrix2.M21 = v4 - (float)(v.z * pDeterminant.m128_f32[0]);
  matrix2.M12 = (float)(v.z * pDeterminant.m128_f32[0]) + v4;
  v5 = (float)(v.z * v.y) * (float)(1.0 - v41);
  matrix2.M13 = (float)((float)(v.z * v.x) * (float)(1.0 - v41)) - (float)(v.y * pDeterminant.m128_f32[0]);
  matrix2.M31 = (float)(v.y * pDeterminant.m128_f32[0]) + (float)((float)(v.z * v.x) * (float)(1.0 - v41));
  matrix2.M23 = (float)(pDeterminant.m128_f32[0] * v.x) + v5;
  matrix2.M32 = v5 - (float)(pDeterminant.m128_f32[0] * v.x);
  DrivableCameraDef::DrivableCameraDef(&v45);
  v7 = this->currentMode;
  if ( v7 )
  {
    if ( v7 == eCar )
    {
      v40 = &Sim::getSceneCamera(this->sim)->matrix;
      v8 = Sim::getSceneCamera(this->sim);
      mul(&v8->matrix, &matrix2, v40);
      mat44f::mat44f(&matrix2);
      v9 = Sim::getCar(this->sim, 0)->bodyTransform;
      v10 = *(__m128 *)&v9->matrix.M21;
      v11 = *(__m128 *)&v9->matrix.M31;
      v12 = *(__m128 *)&v9->matrix.M41;
      v13 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)&v9->matrix.M11, v10, v11, v12);
      v14 = this->sim;
      v15 = this->currentCamera;
      *(__m128 *)&matrix2.M11 = v13;
      *(__m128 *)&matrix2.M21 = v10;
      *(__m128 *)&matrix2.M31 = v11;
      *(__m128 *)&matrix2.M41 = v12;
      v16 = &Sim::getCar(v14, 0)->cameras._Myfirst[v15];
      v17 = Sim::getSceneCamera(this->sim);
      mul(&v16->matrix, &v17->matrix, &matrix2);
    }
  }
  else
  {
    if ( v.x != 1.0 )
      return;
    v18 = __libm_sse2_powf(v6).m128_f32[0];
    v19 = this->currentCamera;
    v42 = v18 * 0.0000099999997;
    if ( v19 )
    {
      v20 = v19 - 3;
      if ( v20 )
      {
        if ( v20 != 1 )
          return;
        v21 = this->sim;
        v22 = v21->cameraManager->cameraDrivable;
        v23 = Sim::getFocusedCarIndex(v21);
        v24 = v22->drivableCameraPositions._Myfirst;
        v25 = _mm_loadu_si128((const __m128i *)&v24[v23].bonnetCameraPos);
        v26 = _mm_loadu_si128((const __m128i *)&v24[v23].chaseCameraPitch);
        v27 = *(_QWORD *)&v24[v23].rotationOffset;
        *(__m128i *)&v45.bumperCameraPos.x = _mm_loadu_si128((const __m128i *)&v24[v23]);
        v28 = (float)((float)direction * v42)
            + _mm_shuffle_ps(*(__m128 *)&v45.bumperCameraPos.x, *(__m128 *)&v45.bumperCameraPos.x, 255).m128_f32[0];
        if ( v28 <= 0.26179498 )
        {
          if ( v28 >= -0.26179498 )
            v45.bumperCameraPitch = v28;
          else
            v45.bumperCameraPitch = -0.26179498;
        }
        else
        {
          v45.bumperCameraPitch = 0.26179498;
        }
        *(__m128i *)v39 = _mm_loadu_si128((const __m128i *)&v45);
        *(__m128i *)&v39[16] = v25;
      }
      else
      {
        v29 = this->sim;
        v30 = v29->cameraManager->cameraDrivable;
        v31 = Sim::getFocusedCarIndex(v29);
        v32 = v30->drivableCameraPositions._Myfirst;
        v33 = _mm_loadu_si128((const __m128i *)&v32[v31]);
        v26 = _mm_loadu_si128((const __m128i *)&v32[v31].chaseCameraPitch);
        v27 = *(_QWORD *)&v32[v31].rotationOffset;
        *(__m128i *)&v45.bonnetCameraPos.x = _mm_loadu_si128((const __m128i *)&v32[v31].bonnetCameraPos);
        v34 = (float)((float)direction * v42)
            + _mm_shuffle_ps(*(__m128 *)&v45.bonnetCameraPos.x, *(__m128 *)&v45.bonnetCameraPos.x, 255).m128_f32[0];
        if ( v34 <= 0.26179498 )
        {
          if ( v34 >= -0.26179498 )
            v45.bonnetCameraPitch = v34;
          else
            v45.bonnetCameraPitch = -0.26179498;
        }
        else
        {
          v45.bonnetCameraPitch = 0.26179498;
        }
        *(__m128i *)v39 = v33;
        *(__m128i *)&v39[16] = _mm_loadu_si128((const __m128i *)&v45.bonnetCameraPos);
      }
      *(__m128i *)&v39[32] = v26;
      *(_QWORD *)&v39[48] = v27;
      v35 = Sim::getFocusedCarIndex(this->sim);
      CameraDrivableManager::setDrivableCameraDefAt(
        this->sim->cameraManager->cameraDrivable,
        v35,
        *(DrivableCameraDef *)v39);
    }
    else
    {
      v36 = FLOAT_0_26179498;
      v37 = this->sim->cameraManager->cameraOnBoard->customCameraSettings._Myfirst;
      v38 = (float)((float)direction * (float)(v18 * 0.0000099999997)) + v37->pitch;
      if ( v38 <= 0.26179498 )
      {
        v36 = FLOAT_N0_26179498;
        if ( v38 >= -0.26179498 )
          v36 = v38;
      }
      v37->pitch = v36;
    }
  }
}
void FormCamera::savecameraF1(FormCamera *this)
{
  bool v2; // zf
  CarAvatar *v3; // eax
  std::wstring *v4; // eax
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // ecx
  CarAvatar *v9; // eax
  std::wstring *v10; // eax
  Sim *v11; // ecx
  CarAvatar *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // ecx
  CarAvatar *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // ecx
  int v18; // eax
  int v19; // eax
  Sim *v20; // ecx
  CameraDrivableManager *v21; // esi
  unsigned int v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // ecx
  Sim *v25; // ecx
  CameraDrivableManager *v26; // esi
  unsigned int v27; // ecx
  DrivableCameraDef *v28; // eax
  __int64 v29; // xmm0_8
  std::wstring *v30; // edi
  std::wstring *v31; // esi
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // ecx
  std::wstring *v38; // eax
  Sim *v39; // ecx
  CameraDrivableManager *v40; // esi
  unsigned int v41; // eax
  std::wstring *v42; // eax
  std::wstring *v43; // ecx
  Sim *v44; // ecx
  CameraDrivableManager *v45; // esi
  unsigned int v46; // ecx
  DrivableCameraDef *v47; // eax
  __int64 v48; // xmm0_8
  std::wstring *v49; // edi
  std::wstring *v50; // esi
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  std::wstring *v54; // eax
  std::wstring *v55; // eax
  std::wstring *v56; // ecx
  std::wstring *v57; // eax
  std::wstring *v58; // eax
  std::wstring *v59; // ecx
  Sim *v60; // ecx
  CarAvatar *v61; // eax
  __int64 v62; // xmm0_8
  std::wstring *v63; // edi
  std::wstring *v64; // esi
  std::wstring *v65; // eax
  std::wstring *v66; // eax
  std::wstring *v67; // eax
  std::wstring *v68; // eax
  std::wstring *v69; // eax
  std::wstring *v70; // ecx
  std::wstring *v71; // eax
  vec3f pos; // [esp+18h] [ebp-298h] BYREF
  int v73; // [esp+28h] [ebp-288h]
  unsigned int v74; // [esp+2Ch] [ebp-284h]
  std::wstring filename; // [esp+30h] [ebp-280h] BYREF
  std::wstring posw; // [esp+48h] [ebp-268h] BYREF
  std::wstring v77; // [esp+60h] [ebp-250h] BYREF
  std::wstring v78; // [esp+78h] [ebp-238h] BYREF
  std::wstring result; // [esp+90h] [ebp-220h] BYREF
  std::wstring v80; // [esp+A8h] [ebp-208h] BYREF
  std::wstring v81; // [esp+C0h] [ebp-1F0h] BYREF
  std::wstring v82; // [esp+D8h] [ebp-1D8h] BYREF
  std::wstring v83; // [esp+F0h] [ebp-1C0h] BYREF
  std::wstring v84; // [esp+108h] [ebp-1A8h] BYREF
  std::wstring v85; // [esp+120h] [ebp-190h] BYREF
  std::wstring v86; // [esp+138h] [ebp-178h] BYREF
  std::wstring v87; // [esp+150h] [ebp-160h] BYREF
  std::wstring v88; // [esp+168h] [ebp-148h] BYREF
  std::wstring v89; // [esp+180h] [ebp-130h] BYREF
  std::wstring v90; // [esp+198h] [ebp-118h] BYREF
  std::wstring v91; // [esp+1B0h] [ebp-100h] BYREF
  std::wstring v92; // [esp+1C8h] [ebp-E8h] BYREF
  std::wstring v93; // [esp+1E0h] [ebp-D0h] BYREF
  std::wstring v94; // [esp+1F8h] [ebp-B8h] BYREF
  std::wstring v95; // [esp+210h] [ebp-A0h] BYREF
  std::wstring v96; // [esp+228h] [ebp-88h] BYREF
  std::wstring v97; // [esp+240h] [ebp-70h] BYREF
  std::wstring v98; // [esp+258h] [ebp-58h] BYREF
  std::wstring v99; // [esp+270h] [ebp-40h] BYREF
  std::wstring v100; // [esp+288h] [ebp-28h] BYREF
  int v101; // [esp+2ACh] [ebp-4h]

  v74 = 7;
  v2 = this->currentCamera == 5;
  v73 = 0;
  LOWORD(pos.x) = 0;
  if ( v2 )
  {
    std::wstring::assign((std::wstring *)&pos, L"content/cars/", 0xDu);
    v101 = 0;
    v3 = Sim::getCar(this->sim, 0);
    v4 = std::operator+<wchar_t>(&result, (std::wstring *)&pos, &v3->unixName);
    LOBYTE(v101) = 1;
    std::operator+<wchar_t>(&v77, v4, L"/data/dash_cam.ini");
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v101) = 4;
    if ( v74 >= 8 )
      operator delete((void *)LODWORD(pos.x));
    v5 = this->sim;
    v74 = 7;
    v73 = 0;
    LOWORD(pos.x) = 0;
    v6 = Sim::getCar(v5, 0);
    v7 = std::to_wstring(&v78, (int)v6->dashBoardExposure);
    v8 = &v77;
    if ( v77._Myres >= 8 )
      v8 = (std::wstring *)v77._Bx._Ptr;
    if ( v7->_Myres >= 8 )
      v7 = (std::wstring *)v7->_Bx._Ptr;
    WritePrivateProfileStringW(L"DASH_CAM", L"EXP", v7->_Bx._Buf, v8->_Bx._Buf);
    if ( v78._Myres >= 8 )
      operator delete(v78._Bx._Ptr);
    if ( v77._Myres >= 8 )
      operator delete(v77._Bx._Ptr);
    return;
  }
  std::wstring::assign((std::wstring *)&pos, L"content/cars/", 0xDu);
  v101 = 5;
  v9 = Sim::getCar(this->sim, 0);
  v10 = std::operator+<wchar_t>(&v77, (std::wstring *)&pos, &v9->unixName);
  LOBYTE(v101) = 6;
  std::operator+<wchar_t>(&filename, v10, L"/data/car.ini");
  if ( v77._Myres >= 8 )
    operator delete(v77._Bx._Ptr);
  v77._Myres = 7;
  v77._Mysize = 0;
  v77._Bx._Buf[0] = 0;
  LOBYTE(v101) = 9;
  if ( v74 >= 8 )
    operator delete((void *)LODWORD(pos.x));
  v11 = this->sim;
  v74 = 7;
  v73 = 0;
  LOWORD(pos.x) = 0;
  v12 = Sim::getCar(v11, 0);
  v13 = std::to_wstring(&v78, (int)v12->onBoardExposure);
  v14 = &filename;
  if ( filename._Myres >= 8 )
    v14 = (std::wstring *)filename._Bx._Ptr;
  if ( v13->_Myres >= 8 )
    v13 = (std::wstring *)v13->_Bx._Ptr;
  WritePrivateProfileStringW(L"GRAPHICS", L"ONBOARD_EXPOSURE", v13->_Bx._Buf, v14->_Bx._Buf);
  if ( v78._Myres >= 8 )
    operator delete(v78._Bx._Ptr);
  v15 = Sim::getCar(this->sim, 0);
  v16 = std::to_wstring(&v78, (int)v15->outBoardExposure);
  v17 = &filename;
  if ( filename._Myres >= 8 )
    v17 = (std::wstring *)filename._Bx._Ptr;
  if ( v16->_Myres >= 8 )
    v16 = (std::wstring *)v16->_Bx._Ptr;
  WritePrivateProfileStringW(L"GRAPHICS", L"OUTBOARD_EXPOSURE", v16->_Bx._Buf, v17->_Bx._Buf);
  if ( v78._Myres >= 8 )
    operator delete(v78._Bx._Ptr);
  posw._Myres = 7;
  posw._Mysize = 0;
  posw._Bx._Buf[0] = 0;
  LOBYTE(v101) = 10;
  v18 = this->currentCamera;
  if ( !v18 )
  {
    v58 = std::to_wstring(
            &v86,
            this->sim->cameraManager->cameraOnBoard->customCameraSettings._Myfirst->pitch * 57.29578);
    v59 = &filename;
    if ( filename._Myres >= 8 )
      v59 = (std::wstring *)filename._Bx._Ptr;
    if ( v58->_Myres >= 8 )
      v58 = (std::wstring *)v58->_Bx._Ptr;
    WritePrivateProfileStringW(L"GRAPHICS", L"ON_BOARD_PITCH_ANGLE", v58->_Bx._Buf, v59->_Bx._Buf);
    if ( v86._Myres >= 8 )
      operator delete(v86._Bx._Ptr);
    v60 = this->sim;
    v86._Myres = 7;
    v86._Mysize = 0;
    v86._Bx._Buf[0] = 0;
    v61 = Sim::getCar(v60, 0);
    v62 = *(_QWORD *)&v61->driverEyesPosition.x;
    pos.z = v61->driverEyesPosition.z;
    *(_QWORD *)&pos.x = v62;
    v63 = std::to_wstring(&v78, pos.z);
    LOBYTE(v101) = 11;
    v64 = std::to_wstring(&v98, pos.y);
    LOBYTE(v101) = 12;
    v65 = std::to_wstring(&v96, pos.x);
    LOBYTE(v101) = 13;
    v66 = std::operator+<wchar_t>(&v94, v65, L",");
    LOBYTE(v101) = 14;
    v67 = std::operator+<wchar_t>(&v92, v66, v64);
    LOBYTE(v101) = 15;
    v68 = std::operator+<wchar_t>(&v90, v67, L",");
    LOBYTE(v101) = 16;
    v69 = std::operator+<wchar_t>(&v88, v68, v63);
    std::wstring::operator=(&posw, v69);
    if ( v88._Myres >= 8 )
      operator delete(v88._Bx._Ptr);
    v88._Myres = 7;
    v88._Mysize = 0;
    v88._Bx._Buf[0] = 0;
    if ( v90._Myres >= 8 )
      operator delete(v90._Bx._Ptr);
    v90._Myres = 7;
    v90._Mysize = 0;
    v90._Bx._Buf[0] = 0;
    if ( v92._Myres >= 8 )
      operator delete(v92._Bx._Ptr);
    v92._Myres = 7;
    v92._Mysize = 0;
    v92._Bx._Buf[0] = 0;
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    if ( v98._Myres >= 8 )
      operator delete(v98._Bx._Ptr);
    v98._Myres = 7;
    v98._Mysize = 0;
    v98._Bx._Buf[0] = 0;
    if ( v78._Myres >= 8 )
      operator delete(v78._Bx._Ptr);
    v78._Myres = 7;
    v70 = &filename;
    v78._Bx._Buf[0] = 0;
    v71 = &posw;
    if ( filename._Myres >= 8 )
      v70 = (std::wstring *)filename._Bx._Ptr;
    if ( posw._Myres >= 8 )
      v71 = (std::wstring *)posw._Bx._Ptr;
    v78._Mysize = 0;
    WritePrivateProfileStringW(L"GRAPHICS", L"DRIVEREYES", v71->_Bx._Buf, v70->_Bx._Buf);
    goto LABEL_108;
  }
  v19 = v18 - 3;
  if ( !v19 )
  {
    v39 = this->sim;
    v40 = v39->cameraManager->cameraDrivable;
    v41 = Sim::getFocusedCarIndex(v39);
    v42 = std::to_wstring(&v93, v40->drivableCameraPositions._Myfirst[v41].bonnetCameraPitch * 57.29578);
    v43 = &filename;
    if ( filename._Myres >= 8 )
      v43 = (std::wstring *)filename._Bx._Ptr;
    if ( v42->_Myres >= 8 )
      v42 = (std::wstring *)v42->_Bx._Ptr;
    WritePrivateProfileStringW(L"GRAPHICS", L"BONNET_CAMERA_PITCH", v42->_Bx._Buf, v43->_Bx._Buf);
    if ( v93._Myres >= 8 )
      operator delete(v93._Bx._Ptr);
    v44 = this->sim;
    v93._Myres = 7;
    v93._Mysize = 0;
    v93._Bx._Buf[0] = 0;
    v45 = v44->cameraManager->cameraDrivable;
    v46 = Sim::getFocusedCarIndex(v44);
    v47 = v45->drivableCameraPositions._Myfirst;
    v48 = *(_QWORD *)&v47[v46].bonnetCameraPos.x;
    pos.z = v47[v46].bonnetCameraPos.z;
    *(_QWORD *)&pos.x = v48;
    v49 = std::to_wstring(&v84, pos.z);
    LOBYTE(v101) = 17;
    v50 = std::to_wstring(&v82, pos.y);
    LOBYTE(v101) = 18;
    v51 = std::to_wstring(&v81, pos.x);
    LOBYTE(v101) = 19;
    v52 = std::operator+<wchar_t>(&v95, v51, L",");
    LOBYTE(v101) = 20;
    v53 = std::operator+<wchar_t>(&v89, v52, v50);
    LOBYTE(v101) = 21;
    v54 = std::operator+<wchar_t>(&v80, v53, L",");
    LOBYTE(v101) = 22;
    v55 = std::operator+<wchar_t>(&v87, v54, v49);
    std::wstring::operator=(&posw, v55);
    if ( v87._Myres >= 8 )
      operator delete(v87._Bx._Ptr);
    v87._Myres = 7;
    v87._Mysize = 0;
    v87._Bx._Buf[0] = 0;
    if ( v80._Myres >= 8 )
      operator delete(v80._Bx._Ptr);
    v80._Myres = 7;
    v80._Mysize = 0;
    v80._Bx._Buf[0] = 0;
    if ( v89._Myres >= 8 )
      operator delete(v89._Bx._Ptr);
    v89._Myres = 7;
    v89._Mysize = 0;
    v89._Bx._Buf[0] = 0;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    if ( v81._Myres >= 8 )
      operator delete(v81._Bx._Ptr);
    v81._Myres = 7;
    v81._Mysize = 0;
    v81._Bx._Buf[0] = 0;
    if ( v82._Myres >= 8 )
      operator delete(v82._Bx._Ptr);
    v82._Myres = 7;
    v82._Mysize = 0;
    v82._Bx._Buf[0] = 0;
    if ( v84._Myres >= 8 )
      operator delete(v84._Bx._Ptr);
    v84._Myres = 7;
    v56 = &filename;
    v84._Bx._Buf[0] = 0;
    v57 = &posw;
    if ( filename._Myres >= 8 )
      v56 = (std::wstring *)filename._Bx._Ptr;
    if ( posw._Myres >= 8 )
      v57 = (std::wstring *)posw._Bx._Ptr;
    v84._Mysize = 0;
    WritePrivateProfileStringW(L"GRAPHICS", L"BONNET_CAMERA_POS", v57->_Bx._Buf, v56->_Bx._Buf);
    goto LABEL_108;
  }
  if ( v19 == 1 )
  {
    v20 = this->sim;
    v21 = v20->cameraManager->cameraDrivable;
    v22 = Sim::getFocusedCarIndex(v20);
    v23 = std::to_wstring(&v77, v21->drivableCameraPositions._Myfirst[v22].bumperCameraPitch * 57.29578);
    v24 = &filename;
    if ( filename._Myres >= 8 )
      v24 = (std::wstring *)filename._Bx._Ptr;
    if ( v23->_Myres >= 8 )
      v23 = (std::wstring *)v23->_Bx._Ptr;
    WritePrivateProfileStringW(L"GRAPHICS", L"BUMPER_CAMERA_PITCH", v23->_Bx._Buf, v24->_Bx._Buf);
    if ( v77._Myres >= 8 )
      operator delete(v77._Bx._Ptr);
    v25 = this->sim;
    v77._Myres = 7;
    v77._Mysize = 0;
    v77._Bx._Buf[0] = 0;
    v26 = v25->cameraManager->cameraDrivable;
    v27 = Sim::getFocusedCarIndex(v25);
    v28 = v26->drivableCameraPositions._Myfirst;
    v29 = *(_QWORD *)&v28[v27].bumperCameraPos.x;
    pos.z = v28[v27].bumperCameraPos.z;
    *(_QWORD *)&pos.x = v29;
    v30 = std::to_wstring(&v85, pos.z);
    LOBYTE(v101) = 23;
    v31 = std::to_wstring(&v99, pos.y);
    LOBYTE(v101) = 24;
    v32 = std::to_wstring(&v83, pos.x);
    LOBYTE(v101) = 25;
    v33 = std::operator+<wchar_t>(&v91, v32, L",");
    LOBYTE(v101) = 26;
    v34 = std::operator+<wchar_t>(&v100, v33, v31);
    LOBYTE(v101) = 27;
    v35 = std::operator+<wchar_t>(&v97, v34, L",");
    LOBYTE(v101) = 28;
    v36 = std::operator+<wchar_t>(&result, v35, v30);
    std::wstring::operator=(&posw, v36);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    if ( v100._Myres >= 8 )
      operator delete(v100._Bx._Ptr);
    v100._Myres = 7;
    v100._Mysize = 0;
    v100._Bx._Buf[0] = 0;
    if ( v91._Myres >= 8 )
      operator delete(v91._Bx._Ptr);
    v91._Myres = 7;
    v91._Mysize = 0;
    v91._Bx._Buf[0] = 0;
    if ( v83._Myres >= 8 )
      operator delete(v83._Bx._Ptr);
    v83._Myres = 7;
    v83._Mysize = 0;
    v83._Bx._Buf[0] = 0;
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v99._Myres = 7;
    v99._Mysize = 0;
    v99._Bx._Buf[0] = 0;
    if ( v85._Myres >= 8 )
      operator delete(v85._Bx._Ptr);
    v85._Myres = 7;
    v37 = &filename;
    v85._Bx._Buf[0] = 0;
    v38 = &posw;
    if ( filename._Myres >= 8 )
      v37 = (std::wstring *)filename._Bx._Ptr;
    if ( posw._Myres >= 8 )
      v38 = (std::wstring *)posw._Bx._Ptr;
    v85._Mysize = 0;
    WritePrivateProfileStringW(L"GRAPHICS", L"BUMPER_CAMERA_POS", v38->_Bx._Buf, v37->_Bx._Buf);
LABEL_108:
    if ( posw._Myres >= 8 )
      operator delete(posw._Bx._Ptr);
  }
  posw._Myres = 7;
  posw._Mysize = 0;
  posw._Bx._Buf[0] = 0;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void FormCamera::savecameraF6(FormCamera *this)
{
  CarAvatar *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  Sim *v5; // ecx
  CameraCarDefinition *v6; // esi
  CarAvatar *v7; // eax
  int i; // [esp+18h] [ebp-10Ch] BYREF
  std::wostream *v9[2]; // [esp+1Ch] [ebp-108h] BYREF
  std::wofstream out; // [esp+24h] [ebp-100h] BYREF
  std::wstring _Left; // [esp+CCh] [ebp-58h] BYREF
  std::wstring filename; // [esp+E4h] [ebp-40h] BYREF
  std::wstring result; // [esp+FCh] [ebp-28h] BYREF
  int v14; // [esp+120h] [ebp-4h]

  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v14 = 0;
  v2 = Sim::getCar(this->sim, 0);
  v3 = std::operator+<wchar_t>(&result, &_Left, &v2->unixName);
  LOBYTE(v14) = 1;
  std::operator+<wchar_t>(&filename, v3, L"/data/cameras.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v14) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  v4 = &filename;
  if ( filename._Myres >= 8 )
    v4 = (std::wstring *)filename._Bx._Ptr;
  _Left._Mysize = 0;
  std::wofstream::wofstream(&out, v4->_Bx._Buf, 2, 64, 1);
  LOBYTE(v14) = 5;
  v5 = this->sim;
  i = 0;
  v6 = Sim::getCar(v5, 0)->cameras._Mylast;
  v7 = Sim::getCar(this->sim, 0);
  v9[0] = &out;
  v9[1] = (std::wostream *)&i;
  std::_For_each<CameraCarDefinition *,_lambda_f310107f2407ec4fa9c3b58fa5e44314_>(v7->cameras._Myfirst, v6, v9);
  std::wofstream::close(&out);
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&out.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
