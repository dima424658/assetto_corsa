#include "carphysicsform.h
RaceFuelMonitor *CarPhysicsForm::`scalar deleting destructor'(RaceFuelMonitor *this, unsigned int a2)
{
  this->__vftable = (RaceFuelMonitor_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarPhysicsForm::CarPhysicsForm(CarPhysicsForm *this, CarAvatar *icar)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  RaceEngineer *v5; // ecx
  double v6; // st7
  CarAvatar *v7; // eax
  int v8; // eax
  int v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  ksgui::ConnectedLabel *v16; // ebp
  CarAvatar *v17; // eax
  ksgui::Form *v18; // eax
  ksgui::Form *v19; // ebp
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  ksgui::ConnectedLabel *v26; // ebp
  CarAvatar *v27; // eax
  ksgui::Form *v28; // eax
  ksgui::Form *v29; // ebp
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  ksgui::ConnectedLabel *v36; // ebp
  CarAvatar *v37; // eax
  ksgui::Form *v38; // eax
  ksgui::Form *v39; // ebp
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  ksgui::ConnectedLabel *v46; // ebp
  CarAvatar *v47; // eax
  ksgui::Form *v48; // eax
  ksgui::Form *v49; // ebp
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  ksgui::ConnectedLabel *v56; // ebp
  CarAvatar *v57; // eax
  ksgui::Form *v58; // eax
  ksgui::Form *v59; // ebp
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm3_4
  ksgui::ConnectedLabel *v66; // ebp
  CarAvatar *v67; // eax
  ksgui::Form *v68; // eax
  ksgui::Form *v69; // ebp
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm3_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  ksgui::ConnectedLabel *v76; // ebp
  CarAvatar *v77; // eax
  ksgui::Form *v78; // eax
  ksgui::Form *v79; // ebp
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float v83; // xmm3_4
  float v84; // xmm2_4
  float v85; // xmm3_4
  ksgui::ConnectedLabel *v86; // ebp
  ksgui::Form *v87; // eax
  ksgui::Form *v88; // ebp
  float v89; // xmm0_4
  float v90; // xmm1_4
  float v91; // xmm2_4
  float v92; // xmm3_4
  float v93; // xmm2_4
  float v94; // xmm3_4
  ksgui::ConnectedLabel *v95; // ebp
  CarAvatar *v96; // eax
  ksgui::Form *v97; // eax
  ksgui::Form *v98; // ebp
  float v99; // xmm0_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm3_4
  ksgui::ConnectedLabel *v105; // ebp
  CarAvatar *v106; // eax
  ksgui::Form *v107; // eax
  ksgui::Form *v108; // ebp
  float v109; // xmm0_4
  float v110; // xmm1_4
  float v111; // xmm2_4
  float v112; // xmm3_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  ksgui::ConnectedLabel *v115; // ebp
  CarAvatar *v116; // eax
  ksgui::Form *v117; // eax
  ksgui::Form *v118; // ebp
  float v119; // xmm0_4
  float v120; // xmm1_4
  float v121; // xmm2_4
  float v122; // xmm3_4
  float v123; // xmm2_4
  float v124; // xmm3_4
  ksgui::ConnectedLabel *v125; // ebp
  CarAvatar *v126; // eax
  ksgui::Form *v127; // eax
  ksgui::Form *v128; // ebp
  float v129; // xmm0_4
  float v130; // xmm1_4
  float v131; // xmm2_4
  float v132; // xmm3_4
  float v133; // xmm2_4
  float v134; // xmm3_4
  ksgui::ConnectedLabel *v135; // ebp
  CarAvatar *v136; // eax
  ksgui::Form *v137; // eax
  ksgui::Form *v138; // ebp
  float v139; // xmm0_4
  float v140; // xmm1_4
  float v141; // xmm2_4
  float v142; // xmm3_4
  float v143; // xmm2_4
  float v144; // xmm3_4
  ksgui::ConnectedLabel *v145; // ebp
  ksgui::Form *v146; // eax
  ksgui::Form *v147; // ebp
  float v148; // xmm0_4
  float v149; // xmm1_4
  float v150; // xmm2_4
  float v151; // xmm3_4
  float v152; // xmm2_4
  float v153; // xmm3_4
  ksgui::ConnectedLabel *v154; // ebp
  CarAvatar *v155; // eax
  ksgui::Form *v156; // eax
  ksgui::Form *v157; // ebp
  float v158; // xmm0_4
  float v159; // xmm1_4
  float v160; // xmm2_4
  float v161; // xmm3_4
  float v162; // xmm2_4
  float v163; // xmm3_4
  ksgui::ConnectedLabel *v164; // ebp
  CarAvatar *v165; // eax
  ksgui::Form *v166; // eax
  ksgui::Form *v167; // ebp
  float v168; // xmm0_4
  float v169; // xmm1_4
  float v170; // xmm2_4
  float v171; // xmm3_4
  float v172; // xmm2_4
  float v173; // xmm3_4
  ksgui::ConnectedLabel *v174; // ebp
  CarAvatar *v175; // eax
  ksgui::Form *v176; // eax
  ksgui::Form *v177; // ebp
  float v178; // xmm0_4
  float v179; // xmm1_4
  float v180; // xmm2_4
  float v181; // xmm3_4
  float v182; // xmm2_4
  float v183; // xmm3_4
  ksgui::ConnectedLabel *v184; // ebp
  CarAvatar *v185; // eax
  ksgui::Form *v186; // eax
  ksgui::Form *v187; // ebp
  float v188; // xmm0_4
  float v189; // xmm1_4
  float v190; // xmm2_4
  float v191; // xmm3_4
  float v192; // xmm2_4
  float v193; // xmm3_4
  ksgui::ConnectedLabel *v194; // ebp
  CarAvatar *v195; // eax
  ksgui::Form *v196; // eax
  ksgui::Form *v197; // ebp
  float v198; // xmm0_4
  float v199; // xmm1_4
  float v200; // xmm2_4
  float v201; // xmm3_4
  float v202; // xmm2_4
  float v203; // xmm3_4
  ksgui::ConnectedLabel *v204; // ebp
  CarAvatar *v205; // eax
  ksgui::Form *v206; // eax
  ksgui::Form *v207; // ebp
  float v208; // xmm0_4
  float v209; // xmm1_4
  float v210; // xmm2_4
  float v211; // xmm3_4
  float v212; // xmm2_4
  float v213; // xmm3_4
  ksgui::ConnectedLabel *v214; // ebp
  CarAvatar *v215; // eax
  ksgui::Form *v216; // eax
  ksgui::Form *v217; // ebp
  float v218; // xmm0_4
  float v219; // xmm1_4
  float v220; // xmm2_4
  float v221; // xmm3_4
  float v222; // xmm2_4
  float v223; // xmm3_4
  ksgui::ConnectedLabel *v224; // ebp
  ksgui::Form *v225; // eax
  ksgui::Form *v226; // ebp
  float v227; // xmm0_4
  float v228; // xmm1_4
  float v229; // xmm2_4
  float v230; // xmm3_4
  float v231; // xmm2_4
  float v232; // xmm3_4
  ksgui::ConnectedLabel *v233; // ebp
  CarAvatar *v234; // eax
  ksgui::Form *v235; // eax
  ksgui::Form *v236; // ebp
  float v237; // xmm0_4
  float v238; // xmm1_4
  float v239; // xmm2_4
  float v240; // xmm3_4
  float v241; // xmm2_4
  float v242; // xmm3_4
  ksgui::ConnectedLabel *v243; // ebp
  CarAvatar *v244; // eax
  ksgui::Form *v245; // eax
  ksgui::Form *v246; // ebp
  float v247; // xmm0_4
  float v248; // xmm1_4
  float v249; // xmm2_4
  float v250; // xmm3_4
  float v251; // xmm2_4
  float v252; // xmm3_4
  ksgui::ConnectedLabel *v253; // ebp
  CarAvatar *v254; // eax
  ksgui::Form *v255; // eax
  ksgui::Form *v256; // ebp
  float v257; // xmm0_4
  float v258; // xmm1_4
  float v259; // xmm2_4
  float v260; // xmm3_4
  float v261; // xmm2_4
  float v262; // xmm3_4
  ksgui::ConnectedLabel *v263; // ebp
  CarAvatar *v264; // eax
  ksgui::Form *v265; // eax
  ksgui::Form *v266; // ebp
  float v267; // xmm0_4
  float v268; // xmm1_4
  float v269; // xmm2_4
  float v270; // xmm3_4
  float v271; // xmm2_4
  float v272; // xmm3_4
  ksgui::ConnectedLabel *v273; // ebp
  CarAvatar *v274; // eax
  ksgui::Form *v275; // eax
  ksgui::Form *v276; // ebp
  float v277; // xmm0_4
  float v278; // xmm1_4
  float v279; // xmm2_4
  float v280; // xmm3_4
  float v281; // xmm2_4
  float v282; // xmm3_4
  ksgui::ConnectedLabel *v283; // ebp
  CarAvatar *v284; // eax
  ksgui::Form *v285; // eax
  ksgui::Form *v286; // ebp
  float v287; // xmm0_4
  float v288; // xmm1_4
  float v289; // xmm2_4
  float v290; // xmm3_4
  float v291; // xmm2_4
  float v292; // xmm3_4
  ksgui::ConnectedLabel *v293; // ebp
  CarAvatar *v294; // eax
  ksgui::Form *v295; // eax
  ksgui::Form *v296; // ebp
  float v297; // xmm0_4
  float v298; // xmm1_4
  float v299; // xmm2_4
  float v300; // xmm3_4
  float v301; // xmm2_4
  float v302; // xmm3_4
  ksgui::ConnectedLabel *v303; // ebp
  CarAvatar *v304; // eax
  ksgui::Form *v305; // eax
  ksgui::Form *v306; // ebp
  float v307; // xmm0_4
  float v308; // xmm1_4
  float v309; // xmm2_4
  float v310; // xmm3_4
  float v311; // xmm2_4
  float v312; // xmm3_4
  ksgui::ConnectedLabel *v313; // ebp
  CarAvatar *v314; // eax
  ksgui::Form *v315; // eax
  ksgui::Form *v316; // ebp
  float v317; // xmm0_4
  float v318; // xmm1_4
  float v319; // xmm2_4
  float v320; // xmm3_4
  float v321; // xmm2_4
  float v322; // xmm3_4
  ksgui::ConnectedLabel *v323; // ebp
  ksgui::Form *v324; // eax
  ksgui::Form *v325; // ebp
  float v326; // xmm0_4
  float v327; // xmm1_4
  float v328; // xmm2_4
  float v329; // xmm3_4
  float v330; // xmm2_4
  float v331; // xmm3_4
  ksgui::ConnectedLabel *v332; // ebx
  ksgui::Form *v333; // eax
  ksgui::Form *v334; // ebx
  float v335; // xmm0_4
  float v336; // xmm1_4
  float v337; // xmm2_4
  float v338; // xmm3_4
  float v339; // xmm2_4
  float v340; // xmm3_4
  ksgui::Form *v341; // eax
  ksgui::Form *v342; // eax
  int v343; // edi
  ksgui::Graph *v344; // edi
  ksgui::Graph *v345; // eax
  __m128 v346; // xmm0
  ksgui::Graph *v347; // eax
  __m128 v348; // xmm0
  ksgui::Graph *v349; // eax
  ksgui::Graph *v350; // ecx
  Font *v351; // eax
  Font *v352; // eax
  _BYTE v353[36]; // [esp+118h] [ebp-90h] BYREF
  int v354; // [esp+14Ch] [ebp-5Ch] BYREF
  __m128i v355; // [esp+150h] [ebp-58h] BYREF
  int _Val[2]; // [esp+160h] [ebp-48h] BYREF
  std::wstring text; // [esp+168h] [ebp-40h] BYREF
  std::wstring result; // [esp+180h] [ebp-28h] BYREF
  int v359; // [esp+1A4h] [ebp-4h]

  *(_DWORD *)&v353[28] = 0;
  v3 = 0;
  _Val[1] = (int)this;
  v354 = 0;
  _Val[0] = 0;
  *(_DWORD *)&v353[24] = icar->game->gui;
  *(_DWORD *)&v353[20] = 7;
  *(_DWORD *)&v353[16] = 0;
  *(_WORD *)v353 = 0;
  std::wstring::assign((std::wstring *)v353, L"CAR_STATS", 9u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v353, *(ksgui::GUI **)&v353[24], v353[28]);
  v359 = 0;
  *(_DWORD *)&v353[28] = 11;
  this->__vftable = (CarPhysicsForm_vtbl *)&CarPhysicsForm::`vftable';
  this->engineer = 0;
  *(_DWORD *)&v353[24] = L"Car physics";
  v355.m128i_i64[1] = 0i64;
  this->dynamicTrackGrip = 0.0;
  this->kmPerLiter = 0.0;
  this->ncp = 0.0;
  this->filteredSpeed = 0.0;
  this->weightDistr = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v353[24], *(unsigned int *)&v353[28]);
  LOBYTE(v359) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v359) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v359) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->car = icar;
  this->engineer = 0;
  v5 = icar->raceEngineer._Myptr;
  if ( v5 )
  {
    v6 = RaceEngineer::getDynamicIndex(v5);
    v7 = this->car;
    this->dynamicIndex = v6;
    this->engineer = v7->raceEngineer._Myptr;
  }
  v354 = (int)operator new(0x11Cu);
  LOBYTE(v359) = 3;
  if ( v354 )
  {
    *(_DWORD *)&v353[28] = this->gui;
    *(_DWORD *)&v353[24] = 7;
    *(_DWORD *)&v353[20] = 0;
    *(_WORD *)&v353[4] = 0;
    std::wstring::assign((std::wstring *)&v353[4], L"TYRE:", 5u);
    ksgui::Label::Label((ksgui::Label *)v354, *(std::wstring *)&v353[4], *(ksgui::GUI **)&v353[28]);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v359) = 0;
  v10 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  this->tyreName = (ksgui::Label *)v9;
  v11 = *(float *)(v9 + 264);
  v12 = *(float *)(v9 + 32) - *(float *)(v9 + 28);
  v13 = *(float *)(v9 + 40) - *(float *)(v9 + 36);
  *(_DWORD *)(v9 + 36) = 1107296256;
  *(_DWORD *)(v9 + 28) = 1084227584;
  v14 = v12 + 5.0;
  v15 = v13 + 32.0;
  *(float *)(v9 + 32) = v14;
  *(float *)(v9 + 40) = v15;
  if ( v11 == v10 && *(float *)(v9 + 272) == v10 )
  {
    *(_DWORD *)(v9 + 264) = 1084227584;
    *(_DWORD *)(v9 + 272) = 1107296256;
    *(float *)(v9 + 268) = v14;
    *(float *)(v9 + 276) = v15;
  }
  ((void (*)(ksgui::Label *, int, int))this->tyreName->setSize)(this->tyreName, 1112014848, 1107296256);
  v354 = (int)this->tyreName;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v16 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v16;
  LOBYTE(v359) = 4;
  if ( v16 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"CGH", 3u);
    LOBYTE(v359) = 5;
    v3 = 1;
    v17 = this->car;
    v354 = 1;
    ksgui::ConnectedLabel::ConnectedLabel(v16, &text, this->gui, &v17->physicsState.cgHeight);
    v19 = v18;
  }
  else
  {
    v19 = 0;
  }
  v359 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v20 = v19->rectBase.left;
  v21 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v22 = v19->rect.right - v19->rect.left;
  v23 = v19->rect.bottom - v19->rect.top;
  v19->rect.top = 52.0;
  v19->rect.left = 5.0;
  v24 = v22 + 5.0;
  v25 = v23 + 52.0;
  v19->rect.right = v24;
  v19->rect.bottom = v25;
  if ( v20 == v21 && v19->rectBase.top == v21 )
  {
    v19->rectBase.left = 5.0;
    v19->rectBase.top = 52.0;
    v19->rectBase.right = v24;
    v19->rectBase.bottom = v25;
  }
  ((void (*)(ksgui::Form *, int, int))v19->setSize)(v19, 1112014848, 1107296256);
  v354 = (int)v19;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v26 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v26;
  LOBYTE(v359) = 7;
  if ( v26 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DY F", 4u);
    LOBYTE(v359) = 8;
    v3 |= 2u;
    v27 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v26, &text, this->gui, v27->physicsState.Dy);
    v29 = v28;
  }
  else
  {
    v29 = 0;
  }
  v359 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v30 = v29->rectBase.left;
  v31 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v32 = v29->rect.right - v29->rect.left;
  v33 = v29->rect.bottom - v29->rect.top;
  v29->rect.top = 72.0;
  v29->rect.left = 5.0;
  v34 = v32 + 5.0;
  v35 = v33 + 72.0;
  v29->rect.right = v34;
  v29->rect.bottom = v35;
  if ( v30 == v31 && v29->rectBase.top == v31 )
  {
    v29->rectBase.left = 5.0;
    v29->rectBase.top = 72.0;
    v29->rectBase.right = v34;
    v29->rectBase.bottom = v35;
  }
  ((void (*)(ksgui::Form *, int, int))v29->setSize)(v29, 1112014848, 1107296256);
  v354 = (int)v29;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v36 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v36;
  LOBYTE(v359) = 10;
  if ( v36 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DY R", 4u);
    LOBYTE(v359) = 11;
    v3 |= 4u;
    v37 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v36, &text, this->gui, &v37->physicsState.Dy[2]);
    v39 = v38;
  }
  else
  {
    v39 = 0;
  }
  v359 = 0;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v40 = v39->rectBase.left;
  v41 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v42 = v39->rect.right - v39->rect.left;
  v43 = v39->rect.bottom - v39->rect.top;
  v39->rect.top = 92.0;
  v39->rect.left = 5.0;
  v44 = v42 + 5.0;
  v45 = v43 + 92.0;
  v39->rect.right = v44;
  v39->rect.bottom = v45;
  if ( v40 == v41 && v39->rectBase.top == v41 )
  {
    v39->rectBase.left = 5.0;
    v39->rectBase.top = 92.0;
    v39->rectBase.right = v44;
    v39->rectBase.bottom = v45;
  }
  ((void (*)(ksgui::Form *, int, int))v39->setSize)(v39, 1112014848, 1107296256);
  v354 = (int)v39;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v46 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v46;
  LOBYTE(v359) = 13;
  if ( v46 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"LD0", 3u);
    LOBYTE(v359) = 14;
    v3 |= 8u;
    v47 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v46, &text, this->gui, v47->physicsState.load);
    v49 = v48;
  }
  else
  {
    v49 = 0;
  }
  v359 = 0;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v50 = v49->rectBase.left;
  v51 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v52 = v49->rect.right - v49->rect.left;
  v53 = v49->rect.bottom - v49->rect.top;
  v49->rect.top = 112.0;
  v49->rect.left = 5.0;
  v54 = v52 + 5.0;
  v55 = v53 + 112.0;
  v49->rect.right = v54;
  v49->rect.bottom = v55;
  if ( v50 == v51 && v49->rectBase.top == v51 )
  {
    v49->rectBase.left = 5.0;
    v49->rectBase.top = 112.0;
    v49->rectBase.right = v54;
    v49->rectBase.bottom = v55;
  }
  ((void (*)(ksgui::Form *, int, int))v49->setSize)(v49, 1112014848, 1107296256);
  v354 = (int)v49;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v56 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v56;
  LOBYTE(v359) = 16;
  if ( v56 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"LD1", 3u);
    LOBYTE(v359) = 17;
    v3 |= 0x10u;
    v57 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v56, &text, this->gui, &v57->physicsState.load[1]);
    v59 = v58;
  }
  else
  {
    v59 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v60 = v59->rectBase.left;
  v61 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v62 = v59->rect.right - v59->rect.left;
  v63 = v59->rect.bottom - v59->rect.top;
  v59->rect.top = 132.0;
  v59->rect.left = 5.0;
  v64 = v62 + 5.0;
  v65 = v63 + 132.0;
  v59->rect.right = v64;
  v59->rect.bottom = v65;
  if ( v60 == v61 && v59->rectBase.top == v61 )
  {
    v59->rectBase.left = 5.0;
    v59->rectBase.top = 132.0;
    v59->rectBase.right = v64;
    v59->rectBase.bottom = v65;
  }
  ((void (*)(ksgui::Form *, int, int))v59->setSize)(v59, 1112014848, 1107296256);
  v354 = (int)v59;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v66 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v66;
  LOBYTE(v359) = 19;
  if ( v66 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"LD2", 3u);
    LOBYTE(v359) = 20;
    v3 |= 0x20u;
    v67 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v66, &text, this->gui, &v67->physicsState.load[2]);
    v69 = v68;
  }
  else
  {
    v69 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v70 = v69->rectBase.left;
  v71 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v72 = v69->rect.right - v69->rect.left;
  v73 = v69->rect.bottom - v69->rect.top;
  v69->rect.top = 152.0;
  v69->rect.left = 5.0;
  v74 = v72 + 5.0;
  v75 = v73 + 152.0;
  v69->rect.right = v74;
  v69->rect.bottom = v75;
  if ( v70 == v71 && v69->rectBase.top == v71 )
  {
    v69->rectBase.left = 5.0;
    v69->rectBase.top = 152.0;
    v69->rectBase.right = v74;
    v69->rectBase.bottom = v75;
  }
  ((void (*)(ksgui::Form *, int, int))v69->setSize)(v69, 1112014848, 1107296256);
  v354 = (int)v69;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v76 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v76;
  LOBYTE(v359) = 22;
  if ( v76 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"LD3", 3u);
    LOBYTE(v359) = 23;
    v3 |= 0x40u;
    v77 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v76, &text, this->gui, &v77->physicsState.load[3]);
    v79 = v78;
  }
  else
  {
    v79 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x40) != 0 )
  {
    v3 &= 0xFFFFFFBF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v80 = v79->rectBase.left;
  v81 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v82 = v79->rect.right - v79->rect.left;
  v83 = v79->rect.bottom - v79->rect.top;
  v79->rect.top = 172.0;
  v79->rect.left = 5.0;
  v84 = v82 + 5.0;
  v85 = v83 + 172.0;
  v79->rect.right = v84;
  v79->rect.bottom = v85;
  if ( v80 == v81 && v79->rectBase.top == v81 )
  {
    v79->rectBase.left = 5.0;
    v79->rectBase.top = 172.0;
    v79->rectBase.right = v84;
    v79->rectBase.bottom = v85;
  }
  ((void (*)(ksgui::Form *, int, int))v79->setSize)(v79, 1112014848, 1107296256);
  v354 = (int)v79;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v86 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v86;
  LOBYTE(v359) = 25;
  if ( v86 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DISTR", 5u);
    LOBYTE(v359) = 26;
    *(_DWORD *)&v353[28] = &this->weightDistr;
    *(_DWORD *)&v353[24] = this->gui;
    v3 |= 0x80u;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v86, &text, *(ksgui::GUI **)&v353[24], &this->weightDistr);
    v88 = v87;
  }
  else
  {
    v88 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x80u) != 0 )
  {
    v3 &= 0xFFFFFF7F;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v89 = v88->rectBase.left;
  v90 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v91 = v88->rect.right - v88->rect.left;
  v92 = v88->rect.bottom - v88->rect.top;
  v88->rect.top = 192.0;
  v88->rect.left = 5.0;
  v93 = v91 + 5.0;
  v94 = v92 + 192.0;
  v88->rect.right = v93;
  v88->rect.bottom = v94;
  if ( v89 == v90 && v88->rectBase.top == v90 )
  {
    v88->rectBase.left = 5.0;
    v88->rectBase.top = 192.0;
    v88->rectBase.right = v93;
    v88->rectBase.bottom = v94;
  }
  ((void (*)(ksgui::Form *, int, int))v88->setSize)(v88, 1112014848, 1107296256);
  v354 = (int)v88;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v95 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v95;
  LOBYTE(v359) = 28;
  if ( v95 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SA LF", 5u);
    LOBYTE(v359) = 29;
    v3 |= 0x100u;
    v96 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v95, &text, this->gui, v96->physicsState.slipAngle);
    v98 = v97;
  }
  else
  {
    v98 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x100) != 0 )
  {
    v3 &= 0xFFFFFEFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v99 = v98->rectBase.left;
  v100 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v101 = v98->rect.right - v98->rect.left;
  v102 = v98->rect.bottom - v98->rect.top;
  v98->rect.top = 212.0;
  v98->rect.left = 5.0;
  v103 = v101 + 5.0;
  v104 = v102 + 212.0;
  v98->rect.right = v103;
  v98->rect.bottom = v104;
  if ( v99 == v100 && v98->rectBase.top == v100 )
  {
    v98->rectBase.left = 5.0;
    v98->rectBase.top = 212.0;
    v98->rectBase.right = v103;
    v98->rectBase.bottom = v104;
  }
  ((void (*)(ksgui::Form *, int, int))v98->setSize)(v98, 1112014848, 1107296256);
  v354 = (int)v98;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v105 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v105;
  LOBYTE(v359) = 31;
  if ( v105 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SA LR", 5u);
    LOBYTE(v359) = 32;
    v3 |= 0x200u;
    v106 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v105, &text, this->gui, &v106->physicsState.slipAngle[2]);
    v108 = v107;
  }
  else
  {
    v108 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x200) != 0 )
  {
    v3 &= 0xFFFFFDFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v109 = v108->rectBase.left;
  v110 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v111 = v108->rect.right - v108->rect.left;
  v112 = v108->rect.bottom - v108->rect.top;
  v108->rect.top = 232.0;
  v108->rect.left = 5.0;
  v113 = v111 + 5.0;
  v114 = v112 + 232.0;
  v108->rect.right = v113;
  v108->rect.bottom = v114;
  if ( v109 == v110 && v108->rectBase.top == v110 )
  {
    v108->rectBase.left = 5.0;
    v108->rectBase.top = 232.0;
    v108->rectBase.right = v113;
    v108->rectBase.bottom = v114;
  }
  ((void (*)(ksgui::Form *, int, int))v108->setSize)(v108, 1112014848, 1107296256);
  v354 = (int)v108;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v115 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v115;
  LOBYTE(v359) = 34;
  if ( v115 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"AVEL_Y", 6u);
    LOBYTE(v359) = 35;
    v3 |= 0x400u;
    v116 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v115, &text, this->gui, &v116->physicsState.localAngularVelocity.y);
    v118 = v117;
  }
  else
  {
    v118 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x400) != 0 )
  {
    v3 &= 0xFFFFFBFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v119 = v118->rectBase.left;
  v120 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v121 = v118->rect.right - v118->rect.left;
  v122 = v118->rect.bottom - v118->rect.top;
  v118->rect.top = 252.0;
  v118->rect.left = 5.0;
  v123 = v121 + 5.0;
  v124 = v122 + 252.0;
  v118->rect.right = v123;
  v118->rect.bottom = v124;
  if ( v119 == v120 && v118->rectBase.top == v120 )
  {
    v118->rectBase.left = 5.0;
    v118->rectBase.top = 252.0;
    v118->rectBase.right = v123;
    v118->rectBase.bottom = v124;
  }
  ((void (*)(ksgui::Form *, int, int))v118->setSize)(v118, 1112014848, 1107296256);
  v354 = (int)v118;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v125 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v125;
  LOBYTE(v359) = 37;
  if ( v125 )
  {
    std::wstring::wstring(&text, L"GLAT");
    LOBYTE(v359) = 38;
    v3 |= 0x800u;
    v126 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v125, &text, this->gui, &v126->physicsState.accG.x);
    v128 = v127;
  }
  else
  {
    v128 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x800) != 0 )
  {
    v3 &= 0xFFFFF7FF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v129 = v128->rectBase.left;
  v130 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v131 = v128->rect.right - v128->rect.left;
  v132 = v128->rect.bottom - v128->rect.top;
  v128->rect.top = 272.0;
  v128->rect.left = 5.0;
  v133 = v131 + 5.0;
  v134 = v132 + 272.0;
  v128->rect.right = v133;
  v128->rect.bottom = v134;
  if ( v129 == v130 && v128->rectBase.top == v130 )
  {
    v128->rectBase.left = 5.0;
    v128->rectBase.top = 272.0;
    v128->rectBase.right = v133;
    v128->rectBase.bottom = v134;
  }
  ((void (*)(ksgui::Form *, int, int))v128->setSize)(v128, 1112014848, 1107296256);
  v354 = (int)v128;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v135 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v135;
  LOBYTE(v359) = 40;
  if ( v135 )
  {
    std::wstring::wstring(&text, L"GLON");
    LOBYTE(v359) = 41;
    v3 |= 0x1000u;
    v136 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v135, &text, this->gui, &v136->physicsState.accG.z);
    v138 = v137;
  }
  else
  {
    v138 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x1000) != 0 )
  {
    v3 &= 0xFFFFEFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v139 = v138->rectBase.left;
  v140 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v141 = v138->rect.right - v138->rect.left;
  v142 = v138->rect.bottom - v138->rect.top;
  v138->rect.top = 292.0;
  v138->rect.left = 5.0;
  v143 = v141 + 5.0;
  v144 = v142 + 292.0;
  v138->rect.right = v143;
  v138->rect.bottom = v144;
  if ( v139 == v140 && v138->rectBase.top == v140 )
  {
    v138->rectBase.left = 5.0;
    v138->rectBase.top = 292.0;
    v138->rectBase.right = v143;
    v138->rectBase.bottom = v144;
  }
  ((void (*)(ksgui::Form *, int, int))v138->setSize)(v138, 1112014848, 1107296256);
  v354 = (int)v138;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v145 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v145;
  LOBYTE(v359) = 43;
  if ( v145 )
  {
    std::wstring::wstring(&text, L"DI");
    LOBYTE(v359) = 44;
    *(_DWORD *)&v353[28] = &this->dynamicIndex;
    *(_DWORD *)&v353[24] = this->gui;
    v3 |= 0x2000u;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v145, &text, *(ksgui::GUI **)&v353[24], &this->dynamicIndex);
    v147 = v146;
  }
  else
  {
    v147 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x2000) != 0 )
  {
    v3 &= 0xFFFFDFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v148 = v147->rectBase.left;
  v149 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v150 = v147->rect.right - v147->rect.left;
  v151 = v147->rect.bottom - v147->rect.top;
  v147->rect.top = 312.0;
  v147->rect.left = 5.0;
  v152 = v150 + 5.0;
  v153 = v151 + 312.0;
  v147->rect.right = v152;
  v147->rect.bottom = v153;
  if ( v148 == v149 && v147->rectBase.top == v149 )
  {
    v147->rectBase.left = 5.0;
    v147->rectBase.top = 312.0;
    v147->rectBase.right = v152;
    v147->rectBase.bottom = v153;
  }
  ((void (*)(ksgui::Form *, int, int))v147->setSize)(v147, 1112014848, 1107296256);
  v354 = (int)v147;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v154 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v154;
  LOBYTE(v359) = 46;
  if ( v154 )
  {
    std::wstring::wstring(&text, L"DSPEED");
    LOBYTE(v359) = 47;
    v3 |= 0x4000u;
    v155 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v154, &text, this->gui, &v155->physicsState.drivetrainSpeed);
    v157 = v156;
  }
  else
  {
    v157 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x4000) != 0 )
  {
    v3 &= 0xFFFFBFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v158 = v157->rectBase.left;
  v159 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v160 = v157->rect.right - v157->rect.left;
  v161 = v157->rect.bottom - v157->rect.top;
  v157->rect.top = 332.0;
  v157->rect.left = 5.0;
  v162 = v160 + 5.0;
  v163 = v161 + 332.0;
  v157->rect.right = v162;
  v157->rect.bottom = v163;
  if ( v158 == v159 && v157->rectBase.top == v159 )
  {
    v157->rectBase.left = 5.0;
    v157->rectBase.top = 332.0;
    v157->rectBase.right = v162;
    v157->rectBase.bottom = v163;
  }
  ((void (*)(ksgui::Form *, int, int))v157->setSize)(v157, 1112014848, 1107296256);
  v354 = (int)v157;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v164 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v164;
  LOBYTE(v359) = 49;
  if ( v164 )
  {
    std::wstring::wstring(&text, L"BOOST");
    LOBYTE(v359) = 50;
    v3 |= 0x8000u;
    v165 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v164, &text, this->gui, &v165->physicsState.turboBoost);
    v167 = v166;
  }
  else
  {
    v167 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x8000) != 0 )
  {
    v3 &= 0xFFFF7FFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v168 = v167->rectBase.left;
  v169 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v170 = v167->rect.right - v167->rect.left;
  v171 = v167->rect.bottom - v167->rect.top;
  v167->rect.top = 352.0;
  v167->rect.left = 5.0;
  v172 = v170 + 5.0;
  v173 = v171 + 352.0;
  v167->rect.right = v172;
  v167->rect.bottom = v173;
  if ( v168 == v169 && v167->rectBase.top == v169 )
  {
    v167->rectBase.left = 5.0;
    v167->rectBase.top = 352.0;
    v167->rectBase.right = v172;
    v167->rectBase.bottom = v173;
  }
  ((void (*)(ksgui::Form *, int, int))v167->setSize)(v167, 1112014848, 1107296256);
  v354 = (int)v167;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v174 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v174;
  LOBYTE(v359) = 52;
  if ( v174 )
  {
    std::wstring::wstring(&text, L"VKM F");
    LOBYTE(v359) = 53;
    v3 |= 0x10000u;
    v175 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v174, &text, this->gui, v175->physicsState.tyreVirtualKM);
    v177 = v176;
  }
  else
  {
    v177 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x10000) != 0 )
  {
    v3 &= 0xFFFEFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v178 = v177->rectBase.left;
  v179 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v180 = v177->rect.right - v177->rect.left;
  v181 = v177->rect.bottom - v177->rect.top;
  v177->rect.top = 372.0;
  v177->rect.left = 5.0;
  v182 = v180 + 5.0;
  v183 = v181 + 372.0;
  v177->rect.right = v182;
  v177->rect.bottom = v183;
  if ( v178 == v179 && v177->rectBase.top == v179 )
  {
    v177->rectBase.left = 5.0;
    v177->rectBase.top = 372.0;
    v177->rectBase.right = v182;
    v177->rectBase.bottom = v183;
  }
  ((void (*)(ksgui::Form *, int, int))v177->setSize)(v177, 1112014848, 1107296256);
  v354 = (int)v177;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v184 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v184;
  LOBYTE(v359) = 55;
  if ( v184 )
  {
    std::wstring::wstring(&text, L"VKM R");
    LOBYTE(v359) = 56;
    v3 |= 0x20000u;
    v185 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v184, &text, this->gui, &v185->physicsState.tyreVirtualKM[2]);
    v187 = v186;
  }
  else
  {
    v187 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x20000) != 0 )
  {
    v3 &= 0xFFFDFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v188 = v187->rectBase.left;
  v189 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v190 = v187->rect.right - v187->rect.left;
  v191 = v187->rect.bottom - v187->rect.top;
  v187->rect.top = 392.0;
  v187->rect.left = 5.0;
  v192 = v190 + 5.0;
  v193 = v191 + 392.0;
  v187->rect.right = v192;
  v187->rect.bottom = v193;
  if ( v188 == v189 && v187->rectBase.top == v189 )
  {
    v187->rectBase.left = 5.0;
    v187->rectBase.top = 392.0;
    v187->rectBase.right = v192;
    v187->rectBase.bottom = v193;
  }
  ((void (*)(ksgui::Form *, int, int))v187->setSize)(v187, 1112014848, 1107296256);
  v354 = (int)v187;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v194 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v194;
  LOBYTE(v359) = 58;
  if ( v194 )
  {
    std::wstring::wstring(&text, L"AP");
    LOBYTE(v359) = 59;
    v3 |= 0x40000u;
    v195 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v194, &text, this->gui, &v195->physicsState.airDensity);
    v197 = v196;
  }
  else
  {
    v197 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x40000) != 0 )
  {
    v3 &= 0xFFFBFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v198 = v197->rectBase.left;
  v199 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v200 = v197->rect.right - v197->rect.left;
  v201 = v197->rect.bottom - v197->rect.top;
  v197->rect.top = 412.0;
  v197->rect.left = 5.0;
  v202 = v200 + 5.0;
  v203 = v201 + 412.0;
  v197->rect.right = v202;
  v197->rect.bottom = v203;
  if ( v198 == v199 && v197->rectBase.top == v199 )
  {
    v197->rectBase.left = 5.0;
    v197->rectBase.top = 412.0;
    v197->rectBase.right = v202;
    v197->rectBase.bottom = v203;
  }
  ((void (*)(ksgui::Form *, int, int))v197->setSize)(v197, 1112014848, 1107296256);
  v354 = (int)v197;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v204 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v204;
  LOBYTE(v359) = 61;
  if ( v204 )
  {
    std::wstring::wstring(&text, L"ELIFE");
    LOBYTE(v359) = 62;
    v3 |= 0x80000u;
    v205 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v204, &text, this->gui, &v205->physicsState.engineLifeLeft);
    v207 = v206;
  }
  else
  {
    v207 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x80000) != 0 )
  {
    v3 &= 0xFFF7FFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v208 = v207->rectBase.left;
  v209 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v210 = v207->rect.right - v207->rect.left;
  v211 = v207->rect.bottom - v207->rect.top;
  v207->rect.top = 432.0;
  v207->rect.left = 5.0;
  v212 = v210 + 5.0;
  v213 = v211 + 432.0;
  v207->rect.right = v212;
  v207->rect.bottom = v213;
  if ( v208 == v209 && v207->rectBase.top == v209 )
  {
    v207->rectBase.left = 5.0;
    v207->rectBase.top = 432.0;
    v207->rectBase.right = v212;
    v207->rectBase.bottom = v213;
  }
  ((void (*)(ksgui::Form *, int, int))v207->setSize)(v207, 1112014848, 1107296256);
  v354 = (int)v207;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v214 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v214;
  LOBYTE(v359) = 64;
  if ( v214 )
  {
    std::wstring::wstring(&text, L"BOV");
    LOBYTE(v359) = 65;
    v3 |= 0x100000u;
    v215 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v214, &text, this->gui, &v215->physicsState.turboBov);
    v217 = v216;
  }
  else
  {
    v217 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x100000) != 0 )
  {
    v3 &= 0xFFEFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v218 = v217->rectBase.left;
  v219 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v220 = v217->rect.right - v217->rect.left;
  v221 = v217->rect.bottom - v217->rect.top;
  v217->rect.top = 452.0;
  v217->rect.left = 5.0;
  v222 = v220 + 5.0;
  v223 = v221 + 452.0;
  v217->rect.right = v222;
  v217->rect.bottom = v223;
  if ( v218 == v219 && v217->rectBase.top == v219 )
  {
    v217->rectBase.left = 5.0;
    v217->rectBase.top = 452.0;
    v217->rectBase.right = v222;
    v217->rectBase.bottom = v223;
  }
  ((void (*)(ksgui::Form *, int, int))v217->setSize)(v217, 1112014848, 1107296256);
  v354 = (int)v217;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v224 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v224;
  LOBYTE(v359) = 67;
  if ( v224 )
  {
    std::wstring::wstring(&text, L"DYN_TRK");
    LOBYTE(v359) = 68;
    *(_DWORD *)&v353[28] = &this->dynamicTrackGrip;
    *(_DWORD *)&v353[24] = this->gui;
    v3 |= 0x200000u;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v224, &text, *(ksgui::GUI **)&v353[24], &this->dynamicTrackGrip);
    v226 = v225;
  }
  else
  {
    v226 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x200000) != 0 )
  {
    v3 &= 0xFFDFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v227 = v226->rectBase.left;
  v228 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v229 = v226->rect.right - v226->rect.left;
  v230 = v226->rect.bottom - v226->rect.top;
  v226->rect.top = 472.0;
  v226->rect.left = 5.0;
  v231 = v229 + 5.0;
  v232 = v230 + 472.0;
  v226->rect.right = v231;
  v226->rect.bottom = v232;
  if ( v227 == v228 && v226->rectBase.top == v228 )
  {
    v226->rectBase.left = 5.0;
    v226->rectBase.top = 472.0;
    v226->rectBase.right = v231;
    v226->rectBase.bottom = v232;
  }
  ((void (*)(ksgui::Form *, int, int))v226->setSize)(v226, 1112014848, 1107296256);
  v354 = (int)v226;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v233 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v233;
  LOBYTE(v359) = 70;
  if ( v233 )
  {
    std::wstring::wstring(&text, L"BOOST");
    LOBYTE(v359) = 71;
    v3 |= (unsigned int)&_ImageBase;
    v234 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v233, &text, this->gui, &v234->physicsState.turboBoostLevel);
    v236 = v235;
  }
  else
  {
    v236 = 0;
  }
  v359 = 0;
  if ( ((unsigned int)&_ImageBase & v3) != 0 )
  {
    v3 &= 0xFFBFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v237 = v236->rectBase.left;
  v238 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v239 = v236->rect.right - v236->rect.left;
  v240 = v236->rect.bottom - v236->rect.top;
  v236->rect.top = 492.0;
  v236->rect.left = 5.0;
  v241 = v239 + 5.0;
  v242 = v240 + 492.0;
  v236->rect.right = v241;
  v236->rect.bottom = v242;
  if ( v237 == v238 && v236->rectBase.top == v238 )
  {
    v236->rectBase.left = 5.0;
    v236->rectBase.top = 492.0;
    v236->rectBase.right = v241;
    v236->rectBase.bottom = v242;
  }
  ((void (*)(ksgui::Form *, int, int))v236->setSize)(v236, 1112014848, 1107296256);
  v354 = (int)v236;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v243 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v243;
  LOBYTE(v359) = 73;
  if ( v243 )
  {
    std::wstring::wstring(&text, L"GRAIN F");
    LOBYTE(v359) = 74;
    v3 |= (unsigned int)&loc_800000;
    v244 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v243, &text, this->gui, v244->physicsState.tyreGrain);
    v246 = v245;
  }
  else
  {
    v246 = 0;
  }
  v359 = 0;
  if ( ((unsigned int)&loc_800000 & v3) != 0 )
  {
    v3 &= 0xFF7FFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v247 = v246->rectBase.left;
  v248 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v249 = v246->rect.right - v246->rect.left;
  v250 = v246->rect.bottom - v246->rect.top;
  v246->rect.top = 512.0;
  v246->rect.left = 5.0;
  v251 = v249 + 5.0;
  v252 = v250 + 512.0;
  v246->rect.right = v251;
  v246->rect.bottom = v252;
  if ( v247 == v248 && v246->rectBase.top == v248 )
  {
    v246->rectBase.left = 5.0;
    v246->rectBase.top = 512.0;
    v246->rectBase.right = v251;
    v246->rectBase.bottom = v252;
  }
  ((void (*)(ksgui::Form *, int, int))v246->setSize)(v246, 1112014848, 1107296256);
  v354 = (int)v246;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v253 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v253;
  LOBYTE(v359) = 76;
  if ( v253 )
  {
    std::wstring::wstring(&text, L"GRAIN R");
    LOBYTE(v359) = 77;
    v3 |= (unsigned int)&unk_1000000;
    v254 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v253, &text, this->gui, &v254->physicsState.tyreGrain[2]);
    v256 = v255;
  }
  else
  {
    v256 = 0;
  }
  v359 = 0;
  if ( ((unsigned int)&unk_1000000 & v3) != 0 )
  {
    v3 &= 0xFEFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v257 = v256->rectBase.left;
  v258 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v259 = v256->rect.right - v256->rect.left;
  v260 = v256->rect.bottom - v256->rect.top;
  v256->rect.top = 532.0;
  v256->rect.left = 5.0;
  v261 = v259 + 5.0;
  v262 = v260 + 532.0;
  v256->rect.right = v261;
  v256->rect.bottom = v262;
  if ( v257 == v258 && v256->rectBase.top == v258 )
  {
    v256->rectBase.left = 5.0;
    v256->rectBase.top = 532.0;
    v256->rectBase.right = v261;
    v256->rectBase.bottom = v262;
  }
  ((void (*)(ksgui::Form *, int, int))v256->setSize)(v256, 1112014848, 1107296256);
  v354 = (int)v256;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v263 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v263;
  LOBYTE(v359) = 79;
  if ( v263 )
  {
    std::wstring::wstring(&text, L"BLISTER F");
    LOBYTE(v359) = 80;
    v3 |= 0x2000000u;
    v264 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v263, &text, this->gui, v264->physicsState.tyreBlister);
    v266 = v265;
  }
  else
  {
    v266 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x2000000) != 0 )
  {
    v3 &= 0xFDFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v267 = v266->rectBase.left;
  v268 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v269 = v266->rect.right - v266->rect.left;
  v270 = v266->rect.bottom - v266->rect.top;
  v266->rect.top = 552.0;
  v266->rect.left = 5.0;
  v271 = v269 + 5.0;
  v272 = v270 + 552.0;
  v266->rect.right = v271;
  v266->rect.bottom = v272;
  if ( v267 == v268 && v266->rectBase.top == v268 )
  {
    v266->rectBase.left = 5.0;
    v266->rectBase.top = 552.0;
    v266->rectBase.right = v271;
    v266->rectBase.bottom = v272;
  }
  ((void (*)(ksgui::Form *, int, int))v266->setSize)(v266, 1112014848, 1107296256);
  v354 = (int)v266;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v273 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v273;
  LOBYTE(v359) = 82;
  if ( v273 )
  {
    std::wstring::wstring(&text, L"BLISTER R");
    LOBYTE(v359) = 83;
    v3 |= 0x4000000u;
    v274 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v273, &text, this->gui, &v274->physicsState.tyreBlister[2]);
    v276 = v275;
  }
  else
  {
    v276 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x4000000) != 0 )
  {
    v3 &= 0xFBFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v277 = v276->rectBase.left;
  v278 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v279 = v276->rect.right - v276->rect.left;
  v280 = v276->rect.bottom - v276->rect.top;
  v276->rect.top = 572.0;
  v276->rect.left = 5.0;
  v281 = v279 + 5.0;
  v282 = v280 + 572.0;
  v276->rect.right = v281;
  v276->rect.bottom = v282;
  if ( v277 == v278 && v276->rectBase.top == v278 )
  {
    v276->rectBase.left = 5.0;
    v276->rectBase.top = 572.0;
    v276->rectBase.right = v281;
    v276->rectBase.bottom = v282;
  }
  ((void (*)(ksgui::Form *, int, int))v276->setSize)(v276, 1112014848, 1107296256);
  v354 = (int)v276;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v283 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v283;
  LOBYTE(v359) = 85;
  if ( v283 )
  {
    std::wstring::wstring(&text, L"FLAT L");
    LOBYTE(v359) = 86;
    v3 |= 0x8000000u;
    v284 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v283, &text, this->gui, v284->physicsState.tyreFlatSpot);
    v286 = v285;
  }
  else
  {
    v286 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x8000000) != 0 )
  {
    v3 &= 0xF7FFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v287 = v286->rectBase.left;
  v288 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v289 = v286->rect.right - v286->rect.left;
  v290 = v286->rect.bottom - v286->rect.top;
  v286->rect.top = 592.0;
  v286->rect.left = 5.0;
  v291 = v289 + 5.0;
  v292 = v290 + 592.0;
  v286->rect.right = v291;
  v286->rect.bottom = v292;
  if ( v287 == v288 && v286->rectBase.top == v288 )
  {
    v286->rectBase.left = 5.0;
    v286->rectBase.top = 592.0;
    v286->rectBase.right = v291;
    v286->rectBase.bottom = v292;
  }
  ((void (*)(ksgui::Form *, int, int))v286->setSize)(v286, 1112014848, 1107296256);
  v354 = (int)v286;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v293 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v293;
  LOBYTE(v359) = 88;
  if ( v293 )
  {
    std::wstring::wstring(&text, L"FLAT R");
    LOBYTE(v359) = 89;
    v3 |= 0x10000000u;
    v294 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v293, &text, this->gui, &v294->physicsState.tyreFlatSpot[1]);
    v296 = v295;
  }
  else
  {
    v296 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x10000000) != 0 )
  {
    v3 &= 0xEFFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v297 = v296->rectBase.left;
  v298 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v299 = v296->rect.right - v296->rect.left;
  v300 = v296->rect.bottom - v296->rect.top;
  v296->rect.top = 612.0;
  v296->rect.left = 5.0;
  v301 = v299 + 5.0;
  v302 = v300 + 612.0;
  v296->rect.right = v301;
  v296->rect.bottom = v302;
  if ( v297 == v298 && v296->rectBase.top == v298 )
  {
    v296->rectBase.left = 5.0;
    v296->rectBase.top = 612.0;
    v296->rectBase.right = v301;
    v296->rectBase.bottom = v302;
  }
  ((void (*)(ksgui::Form *, int, int))v296->setSize)(v296, 1112014848, 1107296256);
  v354 = (int)v296;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v303 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v303;
  LOBYTE(v359) = 91;
  if ( v303 )
  {
    std::wstring::wstring(&text, L"KERS");
    LOBYTE(v359) = 92;
    v3 |= 0x20000000u;
    v304 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v303, &text, this->gui, &v304->physicsState.kersCharge);
    v306 = v305;
  }
  else
  {
    v306 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x20000000) != 0 )
  {
    v3 &= 0xDFFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v307 = v306->rectBase.left;
  v308 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v309 = v306->rect.right - v306->rect.left;
  v310 = v306->rect.bottom - v306->rect.top;
  v306->rect.top = 632.0;
  v306->rect.left = 5.0;
  v311 = v309 + 5.0;
  v312 = v310 + 632.0;
  v306->rect.right = v311;
  v306->rect.bottom = v312;
  if ( v307 == v308 && v306->rectBase.top == v308 )
  {
    v306->rectBase.left = 5.0;
    v306->rectBase.top = 632.0;
    v306->rectBase.right = v311;
    v306->rectBase.bottom = v312;
  }
  ((void (*)(ksgui::Form *, int, int))v306->setSize)(v306, 1112014848, 1107296256);
  v354 = (int)v306;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v313 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v313;
  LOBYTE(v359) = 94;
  if ( v313 )
  {
    std::wstring::wstring(&text, L"KERS_KJ");
    LOBYTE(v359) = 95;
    v3 |= 0x40000000u;
    v314 = this->car;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v313, &text, this->gui, &v314->physicsState.kersCurrentKJ);
    v316 = v315;
  }
  else
  {
    v316 = 0;
  }
  v359 = 0;
  if ( (v3 & 0x40000000) != 0 )
  {
    v3 &= 0xBFFFFFFF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v317 = v316->rectBase.left;
  v318 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v319 = v316->rect.right - v316->rect.left;
  v320 = v316->rect.bottom - v316->rect.top;
  v316->rect.top = 652.0;
  v316->rect.left = 5.0;
  v321 = v319 + 5.0;
  v322 = v320 + 652.0;
  v316->rect.right = v321;
  v316->rect.bottom = v322;
  if ( v317 == v318 && v316->rectBase.top == v318 )
  {
    v316->rectBase.left = 5.0;
    v316->rectBase.top = 652.0;
    v316->rectBase.right = v321;
    v316->rectBase.bottom = v322;
  }
  ((void (*)(ksgui::Form *, int, int))v316->setSize)(v316, 1112014848, 1107296256);
  v354 = (int)v316;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v323 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v323;
  LOBYTE(v359) = 97;
  if ( v323 )
  {
    std::wstring::wstring(&text, L"CONS");
    LOBYTE(v359) = 98;
    *(_DWORD *)&v353[28] = &this->kmPerLiter;
    *(_DWORD *)&v353[24] = this->gui;
    v3 |= 0x80000000;
    v354 = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v323, &text, *(ksgui::GUI **)&v353[24], &this->kmPerLiter);
    v325 = v324;
  }
  else
  {
    v325 = 0;
  }
  v359 = 0;
  if ( v3 < 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v326 = v325->rectBase.left;
  v327 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v328 = v325->rect.right - v325->rect.left;
  v329 = v325->rect.bottom - v325->rect.top;
  v325->rect.top = 672.0;
  v325->rect.left = 5.0;
  v330 = v328 + 5.0;
  v331 = v329 + 672.0;
  v325->rect.right = v330;
  v325->rect.bottom = v331;
  if ( v326 == v327 && v325->rectBase.top == v327 )
  {
    v325->rectBase.left = 5.0;
    v325->rectBase.top = 672.0;
    v325->rectBase.right = v330;
    v325->rectBase.bottom = v331;
  }
  ((void (*)(ksgui::Form *, int, int))v325->setSize)(v325, 1112014848, 1107296256);
  v354 = (int)v325;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v332 = (ksgui::ConnectedLabel *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v332;
  LOBYTE(v359) = 100;
  if ( v332 )
  {
    std::wstring::wstring(&text, L"NCP");
    LOBYTE(v359) = 101;
    _Val[0] = 1;
    v354 = 1;
    ksgui::ConnectedLabel::ConnectedLabel(v332, &text, this->gui, &this->ncp);
    v334 = v333;
  }
  else
  {
    v334 = 0;
  }
  v359 = 0;
  if ( (_Val[0] & 1) != 0 )
  {
    _Val[0] &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v335 = v334->rectBase.left;
  v336 = *(float *)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]).m128i_i32;
  v337 = v334->rect.right - v334->rect.left;
  v338 = v334->rect.bottom - v334->rect.top;
  v334->rect.top = 692.0;
  v334->rect.left = 5.0;
  v339 = v337 + 5.0;
  v340 = v338 + 692.0;
  v334->rect.right = v339;
  v334->rect.bottom = v340;
  if ( v335 == v336 && v334->rectBase.top == v336 )
  {
    v334->rectBase.left = 5.0;
    v334->rectBase.top = 692.0;
    v334->rectBase.right = v339;
    v334->rectBase.bottom = v340;
  }
  ((void (*)(ksgui::Form *, int, int))v334->setSize)(v334, 1112014848, 1107296256);
  v354 = (int)v334;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v355.m128i_i32[0] = (int)operator new(*(unsigned int *)&v353[28]);
  LOBYTE(v359) = 103;
  if ( v355.m128i_i32[0] )
  {
    std::wstring::wstring(&text, L"RPM");
    LOBYTE(v359) = 104;
    _Val[0] |= 2u;
    v354 = _Val[0];
    ksgui::ConnectedLabel::ConnectedLabel(
      (ksgui::ConnectedLabel *)v355.m128i_i32[0],
      &text,
      this->gui,
      &this->car->physicsState.engineRPM);
    v354 = (int)v341;
  }
  else
  {
    v354 = 0;
  }
  v359 = 0;
  if ( (_Val[0] & 2) != 0 )
  {
    _Val[0] &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  ksgui::Form::setPosition((ksgui::Form *)v354, 5.0, 712.0);
  (*(void (**)(int, int, int))(*(_DWORD *)v354 + 28))(v354, 1112014848, 1107296256);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v354);
  *(_DWORD *)&v353[28] = 344;
  *(_DWORD *)(v354 + 148) = this;
  v355.m128i_i32[0] = (int)operator new(*(unsigned int *)&v353[28]);
  LOBYTE(v359) = 106;
  if ( v355.m128i_i32[0] )
  {
    std::wstring::wstring(&text, L"FSPEED");
    LOBYTE(v359) = 107;
    _Val[0] |= 4u;
    v354 = _Val[0];
    ksgui::ConnectedLabel::ConnectedLabel(
      (ksgui::ConnectedLabel *)v355.m128i_i32[0],
      &text,
      this->gui,
      &this->filteredSpeed);
  }
  else
  {
    v342 = 0;
  }
  v354 = (int)v342;
  v359 = 0;
  if ( (_Val[0] & 4) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v343 = v354;
  ksgui::Form::setPosition((ksgui::Form *)v354, 5.0, 732.0);
  (*(void (**)(int, int, int))(*(_DWORD *)v343 + 28))(v343, 1112014848, 1107296256);
  _Val[0] = v343;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, _Val);
  *(_DWORD *)&v353[28] = 320;
  *(_DWORD *)(_Val[0] + 148) = this;
  v344 = (ksgui::Graph *)operator new(*(unsigned int *)&v353[28]);
  v355.m128i_i32[0] = (int)v344;
  LOBYTE(v359) = 109;
  if ( v344 )
  {
    *(_DWORD *)&v353[28] = this->gui;
    std::wstring::wstring((std::wstring *)&v353[4], L"FF");
    ksgui::Graph::Graph(v344, *(std::wstring *)&v353[4], *(ksgui::GUI **)&v353[28]);
  }
  else
  {
    v345 = 0;
  }
  LOBYTE(v359) = 0;
  this->ffGraph = v345;
  ksgui::Form::setPosition((ksgui::Form *)v345, 5.0, 772.0);
  ((void (*)(ksgui::Graph *, int, int))this->ffGraph->setSize)(this->ffGraph, 1126170624, 1120403456);
  _Val[0] = (int)this->ffGraph;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, _Val);
  v355.m128i_i64[0] = LODWORD(FLOAT_1_0);
  v346 = (__m128)_mm_loadl_epi64((const __m128i *)&v355.m128i_i8[8]);
  *(_DWORD *)(_Val[0] + 148) = this;
  *(_QWORD *)&v353[20] = _mm_unpacklo_ps(v346, v346).m128_u64[0];
  *(_DWORD *)&result._Bx._Alias[8] = 1065353216;
  *(_DWORD *)&v353[28] = 1065353216;
  ksgui::Graph::addSerie(this->ffGraph, *(__int128 *)&v353[20]);
  v347 = this->ffGraph;
  v348 = (__m128)_mm_loadl_epi64(&v355);
  *(_DWORD *)&result._Bx._Alias[8] = 1065353216;
  v347->minY = 0.0;
  v349 = this->ffGraph;
  *(_QWORD *)text._Bx._Buf = _mm_unpacklo_ps(v348, v348).m128_u64[0];
  *(_DWORD *)&text._Bx._Alias[12] = 1036831949;
  LOBYTE(text._Mysize) = 0;
  v349->maxY = 1.0;
  v350 = this->ffGraph;
  *(_DWORD *)&text._Bx._Alias[8] = *(_DWORD *)&result._Bx._Alias[8];
  std::vector<ksgui::GraphReferenceAxis>::push_back(&v350->axes, (const ksgui::GraphReferenceAxis *)&text);
  ksgui::Form::setSize(this, 170.0, 880.0);
  v351 = (Font *)operator new(0x18u);
  v355.m128i_i32[0] = (int)v351;
  LOBYTE(v359) = 110;
  if ( v351 )
    Font::Font(v351, eFontMonospaced, 20.0, 0, 0);
  else
    v352 = 0;
  LOBYTE(v359) = 0;
  v355.m128i_i64[1] = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&v355.m128i_u64[1], v352);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&v355.m128i_u64[1]);
  std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&v355.m128i_u64[1]);
}
void __userpurge CarPhysicsForm::render(CarPhysicsForm *this@<ecx>, int a2@<edi>, float dt)
{
  double v4; // st7
  CarAvatar *v5; // ecx
  double v6; // st7
  CarAvatar *v7; // eax
  DynamicTrackStatus *v8; // eax
  ksgui::Graph *v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  CarAvatar *v12; // ecx
  const std::wstring *v13; // eax
  CarAvatar *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm0_4
  __int64 v17; // [esp+8h] [ebp-3Ch]
  DynamicTrackStatus result; // [esp+10h] [ebp-34h] BYREF
  std::wstring v19; // [esp+18h] [ebp-2Ch] BYREF
  int v20; // [esp+40h] [ebp-4h]

  v4 = RaceEngineer::getDynamicIndex(this->engineer);
  v5 = this->car;
  this->dynamicIndex = v4;
  v6 = CarAvatar::getKmPerLiter(v5);
  v7 = this->car;
  this->kmPerLiter = v6;
  v8 = PhysicsAvatar::getDynamicTrackStatus(v7->sim->physicsAvatar, &result);
  v9 = this->ffGraph;
  this->dynamicTrackGrip = v8->currentGripLevel;
  LODWORD(v10) = LODWORD(this->car->physicsState.lastFF_Pure) & _xmm;
  v11 = v9->series._Mylast - v9->series._Myfirst;
  *(float *)&result.enabled = v10;
  if ( v11 )
  {
    if ( v9->autoAdjustMaxValue && v10 > v9->maxY )
      v9->maxY = v10;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&(*v9->series._Myfirst)->values, (int *)&result.enabled);
  }
  v12 = this->car;
  this->ncp = v12->physicsState.normalizedSplinePosition;
  v13 = CarAvatar::getCurrentCompoundShortName(v12, &v19);
  v20 = 0;
  this->tyreName->setText(this->tyreName, v13);
  v20 = -1;
  if ( v19._Myres >= 8 )
    operator delete(v19._Bx._Ptr);
  v14 = this->car;
  v19._Bx._Buf[0] = 0;
  v19._Myres = 7;
  this->filteredSpeed = v14->filteredSpeed;
  v15 = v14->physicsState.load[1] + v14->physicsState.load[0];
  v16 = v14->physicsState.load[2];
  v19._Mysize = 0;
  this->weightDistr = (float)(v15 / (float)((float)(v16 + v15) + v14->physicsState.load[3])) * 100.0;
  ksgui::Control::render(this, a2, (int)this, dt, v17, *(float *)&result.enabled);
}
