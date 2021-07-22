#include "acessentials.h
void __userpurge ACEssentials::ACEssentials(ACEssentials *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  const std::wstring *v4; // eax
  void (__cdecl *v5)(void *); // eax
  ksgui::Label *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // edx
  ksgui::Label *v9; // ecx
  Texture *v10; // eax
  Texture *v11; // eax
  ksgui::Label *v12; // eax
  const std::wstring *v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // edx
  ksgui::Label *v16; // ecx
  ksgui::Label_vtbl *v17; // eax
  ksgui::Label *v18; // ecx
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  ksgui::Label *v25; // eax
  const std::wstring *v26; // eax
  _DWORD *v27; // eax
  unsigned int v28; // edx
  ksgui::Label *v29; // ecx
  ksgui::Label_vtbl *v30; // eax
  ksgui::Label *v31; // ecx
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm4_4
  ksgui::Label *v38; // eax
  ksgui::Label *v39; // ecx
  Font *v40; // eax
  Font *v41; // eax
  ksgui::Label *v42; // ecx
  std::_Ref_count_base *v43; // edx
  ksgui::Label *v44; // ecx
  ksgui::Label *v45; // ecx
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  ksgui::Label *v50; // eax
  const std::wstring *v51; // eax
  ksgui::Label *v52; // ecx
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm3_4
  float v58; // xmm4_4
  ksgui::Label *v59; // eax
  ksgui::Label *v60; // ecx
  Font *v61; // eax
  Font *v62; // eax
  std::_Ref_count_base *v63; // edx
  std::_Ref_count_base *v64; // ecx
  ksgui::Label *v65; // ecx
  float v66; // xmm0_4
  float v67; // xmm3_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  ksgui::Label *v70; // eax
  ksgui::Label *v71; // ecx
  ksgui::Label *v72; // ecx
  float v73; // xmm3_4
  float v74; // xmm4_4
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm3_4
  float v78; // xmm4_4
  ksgui::Label *v79; // eax
  ksgui::Label *v80; // ecx
  Font *v81; // eax
  Font *v82; // eax
  std::_Ref_count_base *v83; // edx
  std::_Ref_count_base *v84; // ecx
  ksgui::Label *v85; // ecx
  float v86; // xmm0_4
  float v87; // xmm3_4
  float v88; // xmm2_4
  float v89; // xmm3_4
  Font *v90; // ebx
  ksgui::Label *v91; // eax
  const std::wstring *v92; // eax
  ksgui::Label *v93; // ecx
  float v94; // xmm3_4
  float v95; // xmm4_4
  float v96; // xmm2_4
  float v97; // xmm0_4
  float v98; // xmm3_4
  float v99; // xmm4_4
  Font *v100; // ebx
  ksgui::Label *v101; // eax
  ksgui::Label *v102; // ecx
  Font *v103; // eax
  Font *v104; // eax
  std::_Ref_count_base *v105; // ebx
  ksgui::Label *v106; // ecx
  float v107; // xmm0_4
  float v108; // xmm3_4
  float v109; // xmm2_4
  float v110; // xmm3_4
  Font *v111; // ebx
  ksgui::Label *v112; // eax
  const std::wstring *v113; // eax
  ksgui::Label *v114; // ecx
  float v115; // xmm3_4
  float v116; // xmm4_4
  float v117; // xmm2_4
  float v118; // xmm0_4
  float v119; // xmm3_4
  float v120; // xmm4_4
  Font *v121; // ebx
  ksgui::Label *v122; // eax
  ksgui::Label *v123; // ecx
  Font *v124; // eax
  Font *v125; // eax
  std::_Ref_count_base *v126; // ebx
  ksgui::Label *v127; // ecx
  float v128; // xmm0_4
  float v129; // xmm3_4
  float v130; // xmm2_4
  float v131; // xmm3_4
  bool v132; // al
  ksgui::Label *v133; // eax
  Font *v134; // eax
  Font *v135; // eax
  ksgui::Label *v136; // eax
  ksgui::Label *v137; // eax
  Font *v138; // eax
  Font *v139; // eax
  Font *v140; // ebx
  ksgui::Label *v141; // eax
  const std::wstring *v142; // eax
  ksgui::Label *v143; // ecx
  float v144; // xmm2_4
  float v145; // xmm0_4
  float v146; // xmm3_4
  float v147; // xmm2_4
  float v148; // xmm0_4
  float v149; // xmm3_4
  float v150; // xmm4_4
  float v151; // xmm0_4
  Font *v152; // ebx
  ksgui::Label *v153; // eax
  ksgui::Label *v154; // ecx
  ksgui::Label *v155; // eax
  ksgui::Label *v156; // eax
  Font *v157; // eax
  Font *v158; // eax
  std::_Ref_count_base *v159; // ebx
  ksgui::Label *v160; // ecx
  float v161; // xmm0_4
  float v162; // xmm2_4
  float v163; // xmm3_4
  float v164; // xmm2_4
  float v165; // xmm3_4
  std::vector<ksgui::Control *> *v166; // ebx
  ksgui::Label *v167; // eax
  ksgui::Label *v168; // ecx
  ksgui::Label *v169; // eax
  ksgui::Label *v170; // eax
  Font *v171; // eax
  Font *v172; // eax
  std::_Ref_count_base *v173; // esi
  ksgui::Label *v174; // edx
  float v175; // xmm0_4
  float v176; // xmm2_4
  float v177; // xmm3_4
  float v178; // xmm2_4
  float v179; // xmm3_4
  _BYTE v180[28]; // [esp+8Ch] [ebp-8Ch] BYREF
  float h; // [esp+A8h] [ebp-70h]
  ksgui::Label *v182; // [esp+C0h] [ebp-58h] BYREF
  std::shared_ptr<Font> _Right; // [esp+C4h] [ebp-54h] BYREF
  ACEssentials *v184; // [esp+CCh] [ebp-4Ch]
  std::wstring text; // [esp+D0h] [ebp-48h] BYREF
  Texture result; // [esp+E8h] [ebp-30h] BYREF
  int v187; // [esp+114h] [ebp-4h]

  LODWORD(h) = 1;
  v184 = this;
  *(_DWORD *)&v180[24] = aSim->game->gui;
  *(_DWORD *)&v180[20] = 7;
  *(_DWORD *)&v180[16] = 0;
  *(_WORD *)v180 = 0;
  std::wstring::assign((std::wstring *)v180, L"AC_ESSENTIALS", 0xDu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v180, *(ksgui::GUI **)&v180[24], SLOBYTE(h));
  v187 = 0;
  this->__vftable = (ACEssentials_vtbl *)&ACEssentials::`vftable';
  this->sim = aSim;
  this->lblGear = 0;
  this->lblSpeed = 0;
  this->lblSession = 0;
  this->lblPosition = 0;
  this->lblPositionDescription = 0;
  this->lblLast = 0;
  this->abs = 0;
  this->tc = 0;
  this->guiSessionDesc = 0;
  this->guiSpeedDesc = 0;
  this->hasP2P = 0;
  this->p2pLabel = 0;
  this->p2pValue = 0;
  this->texFuelBar.kid = 0;
  this->texFuelBar.fileName._Myres = 7;
  this->texFuelBar.fileName._Mysize = 0;
  this->texFuelBar.fileName._Bx._Buf[0] = 0;
  this->texRpmBar.kid = 0;
  this->texRpmBar.fileName._Myres = 7;
  this->texRpmBar.fileName._Mysize = 0;
  this->texRpmBar.fileName._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  LODWORD(h) = 10;
  *(_DWORD *)&v180[24] = L"Essentials";
  this->currentRPM = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v180[24], LODWORD(h));
  LOBYTE(v187) = 3;
  v4 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 4;
  this->formTitle->setText(this->formTitle, v4);
  v5 = operator delete;
  if ( result.fileName._Mysize >= 8 )
  {
    operator delete(result.kid);
    v5 = operator delete;
  }
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    v5(text._Bx._Ptr);
  this->devApp = 0;
  ksgui::Form::setSize(this, 850.0, 110.0);
  if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Race )
    ksgui::Form::setSize(this, 875.0, 110.0);
  LODWORD(h) = 24;
  this->autohide = 1;
  v6 = (ksgui::Label *)operator new(LODWORD(h));
  v182 = v6;
  LOBYTE(v187) = 5;
  if ( v6 )
    Font::Font((Font *)v6, eFontProportional, 15.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v7);
  v8 = this->font._Rep;
  this->font._Rep = _Right._Rep;
  v182 = (ksgui::Label *)v8;
  this->font._Ptr = _Right._Ptr;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      v9 = v182;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v182->name._Bx._Alias[4], 0xFFFFFFFF) )
        ((void (*)(ksgui::Label *))v9->hitTest)(v9);
    }
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/essential/rpmBar.png", 0x20u);
  LOBYTE(v187) = 6;
  v10 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v187) = 7;
  this->texRpmBar.kid = v10->kid;
  if ( &this->texRpmBar.fileName != &v10->fileName )
    std::wstring::assign(&this->texRpmBar.fileName, &v10->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v187) = 6;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v187) = 2;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/essential/fuelBar.png", 0x21u);
  LOBYTE(v187) = 8;
  v11 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v187) = 9;
  this->texFuelBar.kid = v11->kid;
  if ( &this->texFuelBar.fileName != &v11->fileName )
    std::wstring::assign(&this->texFuelBar.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v187) = 8;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v187) = 2;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v182 = (ksgui::Label *)operator new(0x11Cu);
  LOBYTE(v187) = 10;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v180[24] = 7;
    *(_DWORD *)&v180[20] = 0;
    *(_WORD *)&v180[4] = 0;
    std::wstring::assign((std::wstring *)&v180[4], L"FUEL_BAR", 8u);
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v12 = 0;
  }
  LOBYTE(v187) = 2;
  this->lbl[0] = v12;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"FUELS", 5u);
  LOBYTE(v187) = 11;
  v13 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 12;
  this->lbl[0]->setText(this->lbl[0], v13);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v14 = this->texFuelBar.kid;
  if ( v14 )
    v15 = v14[9];
  else
    v15 = 0;
  v16 = this->lbl[0];
  v17 = v16->__vftable;
  *(float *)&v180[24] = (float)v15;
  ((void (*)(ksgui::Label *, _DWORD, int))v17->setSize)(v16, *(_DWORD *)&v180[24], 1101529088);
  this->lbl[0]->fontAlign = eAlignCenter;
  v18 = this->lbl[0];
  v19 = v18->rect.right - v18->rect.left;
  v20 = v18->rect.bottom - v18->rect.top;
  v21 = (float)(this->rect.bottom - this->rect.top) - v20;
  v18->rect.left = coordFuel.x;
  v22 = v18->rectBase.left;
  v23 = v19 + 24.0;
  v18->rect.top = v21;
  v24 = v20 + v21;
  v18->rect.right = v23;
  v18->rect.bottom = v24;
  if ( v22 == 0.0 && v18->rectBase.top == 0.0 )
  {
    v18->rectBase.left = coordFuel.x;
    v18->rectBase.top = v21;
    v18->rectBase.right = v23;
    v18->rectBase.bottom = v24;
  }
  v182 = this->lbl[0];
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 13;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v180[24] = 7;
    *(_DWORD *)&v180[20] = 0;
    *(_WORD *)&v180[4] = 0;
    std::wstring::assign((std::wstring *)&v180[4], L"RPM_BAR", 7u);
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v25 = 0;
  }
  LOBYTE(v187) = 2;
  this->lbl[1] = v25;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"RPMS", 4u);
  LOBYTE(v187) = 14;
  v26 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 15;
  this->lbl[1]->setText(this->lbl[1], v26);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v27 = this->texRpmBar.kid;
  if ( v27 )
    v28 = v27[9];
  else
    v28 = 0;
  v29 = this->lbl[1];
  v30 = v29->__vftable;
  *(float *)&v180[24] = (float)v28;
  ((void (*)(ksgui::Label *, _DWORD, int))v30->setSize)(v29, *(_DWORD *)&v180[24], 1101529088);
  this->lbl[1]->fontAlign = eAlignCenter;
  v31 = this->lbl[1];
  v32 = v31->rect.right - v31->rect.left;
  v33 = v31->rect.bottom - v31->rect.top;
  v34 = (float)(this->rect.bottom - this->rect.top) - v33;
  v31->rect.left = coordRpm.x;
  v35 = v31->rectBase.left;
  v36 = v32 + 164.0;
  v31->rect.top = v34;
  v37 = v33 + v34;
  v31->rect.right = v36;
  v31->rect.bottom = v37;
  if ( v35 == 0.0 && v31->rectBase.top == 0.0 )
  {
    v31->rectBase.left = coordRpm.x;
    v31->rectBase.top = v34;
    v31->rectBase.right = v36;
    v31->rectBase.bottom = v37;
  }
  v182 = this->lbl[1];
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 16;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v180[24] = 7;
    *(_DWORD *)&v180[20] = 0;
    *(_WORD *)&v180[4] = 0;
    std::wstring::assign((std::wstring *)&v180[4], L"4", 1u);
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v39 = v38;
  }
  else
  {
    v39 = 0;
  }
  LOBYTE(v187) = 2;
  this->lblGear = v39;
  ((void (*)(ksgui::Label *, int, int))v39->setSize)(v39, 1113325568, 1113325568);
  v40 = (Font *)operator new(0x18u);
  _Right._Ptr = v40;
  LOBYTE(v187) = 17;
  if ( v40 )
    Font::Font(v40, eFontProportional, 60.0, 0, 0);
  else
    v41 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v41);
  v42 = this->lblGear;
  v43 = v42->font._Rep;
  v42->font._Rep = _Right._Rep;
  v182 = (ksgui::Label *)v43;
  v42->font._Ptr = _Right._Ptr;
  if ( v43 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v43->_Uses, 0xFFFFFFFF) )
    {
      v43->_Destroy(v43);
      v44 = v182;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v182->name._Bx._Alias[4], 0xFFFFFFFF) )
        ((void (*)(ksgui::Label *))v44->hitTest)(v44);
    }
  }
  this->lblGear->fontAlign = eAlignCenter;
  v45 = this->lblGear;
  v46 = v45->rectBase.left;
  v47 = v45->rect.bottom - v45->rect.top;
  v48 = (float)(v45->rect.right - v45->rect.left) + 348.0;
  v45->rect.top = coordGear.y;
  v49 = v47 + 15.0;
  v45->rect.left = coordGear.x;
  v45->rect.right = v48;
  v45->rect.bottom = v49;
  if ( v46 == 0.0 && v45->rectBase.top == 0.0 )
  {
    v45->rectBase.left = coordGear.x;
    v45->rectBase.top = coordGear.y;
    v45->rectBase.right = v48;
    v45->rectBase.bottom = v49;
  }
  v182 = this->lblGear;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 18;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v180[24] = 7;
    *(_DWORD *)&v180[20] = 0;
    *(_WORD *)&v180[4] = 0;
    std::wstring::assign((std::wstring *)&v180[4], L"GEAR_BAR", 8u);
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v50 = 0;
  }
  LOBYTE(v187) = 2;
  this->lbl[2] = v50;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"GEAR", 4u);
  LOBYTE(v187) = 19;
  v51 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 20;
  this->lbl[2]->setText(this->lbl[2], v51);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Label *, int, int))this->lbl[2]->setSize)(this->lbl[2], 1113325568, 1101529088);
  this->lbl[2]->fontAlign = eAlignCenter;
  v52 = this->lbl[2];
  v53 = v52->rect.right - v52->rect.left;
  v54 = v52->rect.bottom - v52->rect.top;
  v55 = (float)(this->rect.bottom - this->rect.top) - v54;
  v52->rect.left = coordGear.x;
  v56 = v52->rectBase.left;
  v57 = v53 + 348.0;
  v52->rect.top = v55;
  v58 = v54 + v55;
  v52->rect.right = v57;
  v52->rect.bottom = v58;
  if ( v56 == 0.0 && v52->rectBase.top == 0.0 )
  {
    v52->rectBase.left = coordGear.x;
    v52->rectBase.top = v55;
    v52->rectBase.right = v57;
    v52->rectBase.bottom = v58;
  }
  v182 = this->lbl[2];
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 21;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"354");
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v60 = v59;
  }
  else
  {
    v60 = 0;
  }
  LOBYTE(v187) = 2;
  this->lblSpeed = v60;
  ((void (*)(ksgui::Label *, int, int))v60->setSize)(v60, 1116471296, 1107296256);
  v61 = (Font *)operator new(0x18u);
  _Right._Ptr = v61;
  LOBYTE(v187) = 22;
  if ( v61 )
    Font::Font(v61, eFontProportional, 25.0, 0, 0);
  else
    v62 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v62);
  std::shared_ptr<Font>::operator=(&this->lblSpeed->font, &_Right);
  v63 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v63->_Destroy(v63);
      v64 = _Right._Rep;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Weaks, 0xFFFFFFFF) )
        v64->_Delete_this(v64);
    }
  }
  this->lblSpeed->fontAlign = eAlignCenter;
  v65 = this->lblSpeed;
  v66 = v65->rectBase.left;
  v67 = v65->rect.bottom - v65->rect.top;
  v68 = (float)(v65->rect.right - v65->rect.left) + 426.0;
  v65->rect.top = coordSpeed.y;
  v69 = v67 + 55.0;
  v65->rect.left = coordSpeed.x;
  v65->rect.right = v68;
  v65->rect.bottom = v69;
  if ( v66 == 0.0 && v65->rectBase.top == 0.0 )
  {
    v65->rectBase.left = coordSpeed.x;
    v65->rectBase.top = coordSpeed.y;
    v65->rectBase.right = v68;
    v65->rectBase.bottom = v69;
  }
  v182 = this->lblSpeed;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 23;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"KMH");
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v71 = v70;
  }
  else
  {
    v71 = 0;
  }
  LOBYTE(v187) = 2;
  this->guiSpeedDesc = v71;
  ((void (*)(ksgui::Label *, int, int))v71->setSize)(v71, 1116471296, 1101529088);
  this->guiSpeedDesc->fontAlign = eAlignCenter;
  v72 = this->guiSpeedDesc;
  v73 = v72->rect.right - v72->rect.left;
  v74 = v72->rect.bottom - v72->rect.top;
  v75 = (float)(this->rect.bottom - this->rect.top) - v74;
  v72->rect.left = coordSpeed.x;
  v76 = v72->rectBase.left;
  v77 = v73 + 426.0;
  v72->rect.top = v75;
  v78 = v74 + v75;
  v72->rect.right = v77;
  v72->rect.bottom = v78;
  if ( v76 == 0.0 && v72->rectBase.top == 0.0 )
  {
    v72->rectBase.left = coordSpeed.x;
    v72->rectBase.top = v75;
    v72->rectBase.right = v77;
    v72->rectBase.bottom = v78;
  }
  v182 = this->guiSpeedDesc;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 24;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"1:23:456");
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v80 = v79;
  }
  else
  {
    v80 = 0;
  }
  LOBYTE(v187) = 2;
  this->lblSession = v80;
  ((void (*)(ksgui::Label *, int, int))v80->setSize)(v80, 1116471296, 1107296256);
  v81 = (Font *)operator new(0x18u);
  _Right._Ptr = v81;
  LOBYTE(v187) = 25;
  if ( v81 )
    Font::Font(v81, eFontProportional, 25.0, 0, 0);
  else
    v82 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v82);
  std::shared_ptr<Font>::operator=(&this->lblSession->font, &_Right);
  v83 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v83->_Destroy(v83);
      v84 = _Right._Rep;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Weaks, 0xFFFFFFFF) )
        v84->_Delete_this(v84);
    }
  }
  this->lblSession->fontAlign = eAlignCenter;
  v85 = this->lblSession;
  v86 = v85->rectBase.left;
  v87 = v85->rect.bottom - v85->rect.top;
  v88 = (float)(v85->rect.right - v85->rect.left) + 532.0;
  v85->rect.top = coordSession.y;
  v89 = v87 + 55.0;
  v85->rect.left = coordSession.x;
  v85->rect.right = v88;
  v85->rect.bottom = v89;
  if ( v86 == 0.0 && v85->rectBase.top == 0.0 )
  {
    v85->rectBase.left = coordSession.x;
    v85->rectBase.top = coordSession.y;
    v85->rectBase.right = v88;
    v85->rectBase.bottom = v89;
  }
  v182 = this->lblSession;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v90 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v90;
  LOBYTE(v187) = 26;
  if ( v90 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"SESSION_LABEL");
    ksgui::Label::Label((ksgui::Label *)v90, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v91 = 0;
  }
  LOBYTE(v187) = 2;
  LODWORD(h) = L"SESSION";
  this->guiSessionDesc = v91;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(h));
  LOBYTE(v187) = 27;
  v92 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 28;
  this->guiSessionDesc->setText(this->guiSessionDesc, v92);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Label *, _DWORD, int))this->guiSessionDesc->setSize)(
    this->guiSessionDesc,
    this->lblSession->rect.right - this->lblSession->rect.left,
    1101529088);
  this->guiSessionDesc->fontAlign = eAlignCenter;
  v93 = this->guiSessionDesc;
  v94 = v93->rect.right - v93->rect.left;
  v95 = v93->rect.bottom - v93->rect.top;
  v96 = (float)(this->rect.bottom - this->rect.top) - v95;
  v93->rect.left = coordSession.x;
  v97 = v93->rectBase.left;
  v98 = v94 + 532.0;
  v93->rect.top = v96;
  v99 = v95 + v96;
  v93->rect.right = v98;
  v93->rect.bottom = v99;
  if ( v97 == 0.0 && v93->rectBase.top == 0.0 )
  {
    v93->rectBase.left = coordSession.x;
    v93->rectBase.top = v96;
    v93->rectBase.right = v98;
    v93->rectBase.bottom = v99;
  }
  v182 = this->guiSessionDesc;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v100 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v100;
  LOBYTE(v187) = 29;
  if ( v100 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"1:23:456");
    ksgui::Label::Label((ksgui::Label *)v100, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v102 = v101;
  }
  else
  {
    v102 = 0;
  }
  LOBYTE(v187) = 2;
  this->lblLast = v102;
  ((void (*)(ksgui::Label *, int, int))v102->setSize)(v102, 1116471296, 1107296256);
  v103 = (Font *)operator new(0x18u);
  _Right._Ptr = v103;
  LOBYTE(v187) = 30;
  if ( v103 )
    Font::Font(v103, eFontProportional, 25.0, 0, 0);
  else
    v104 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v104);
  std::shared_ptr<Font>::operator=(&this->lblLast->font, &_Right);
  v105 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v105->_Destroy(v105);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v105->_Weaks, 0xFFFFFFFF) )
        v105->_Delete_this(v105);
    }
  }
  this->lblLast->fontAlign = eAlignCenter;
  v106 = this->lblLast;
  v107 = v106->rectBase.left;
  v108 = v106->rect.bottom - v106->rect.top;
  v109 = (float)(v106->rect.right - v106->rect.left) + 659.0;
  v106->rect.top = coordLast.y;
  v110 = v108 + 55.0;
  v106->rect.left = coordLast.x;
  v106->rect.right = v109;
  v106->rect.bottom = v110;
  if ( v107 == 0.0 && v106->rectBase.top == 0.0 )
  {
    v106->rectBase.left = coordLast.x;
    v106->rectBase.top = coordLast.y;
    v106->rectBase.right = v109;
    v106->rectBase.bottom = v110;
  }
  v182 = this->lblLast;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v111 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v111;
  LOBYTE(v187) = 31;
  if ( v111 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"LAST_LABEL");
    ksgui::Label::Label((ksgui::Label *)v111, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v112 = 0;
  }
  LOBYTE(v187) = 2;
  LODWORD(h) = L"LAST";
  this->lbl[3] = v112;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(h));
  LOBYTE(v187) = 32;
  v113 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 33;
  this->lbl[3]->setText(this->lbl[3], v113);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Label *, _DWORD, int))this->lbl[3]->setSize)(
    this->lbl[3],
    this->lblLast->rect.right - this->lblLast->rect.left,
    1101529088);
  this->lbl[3]->fontAlign = eAlignCenter;
  v114 = this->lbl[3];
  v115 = v114->rect.right - v114->rect.left;
  v116 = v114->rect.bottom - v114->rect.top;
  v117 = (float)(this->rect.bottom - this->rect.top) - v116;
  v114->rect.left = coordLast.x;
  v118 = v114->rectBase.left;
  v119 = v115 + 659.0;
  v114->rect.top = v117;
  v120 = v116 + v117;
  v114->rect.right = v119;
  v114->rect.bottom = v120;
  if ( v118 == 0.0 && v114->rectBase.top == 0.0 )
  {
    v114->rectBase.left = coordLast.x;
    v114->rectBase.top = v117;
    v114->rectBase.right = v119;
    v114->rectBase.bottom = v120;
  }
  v182 = this->lbl[3];
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v121 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v121;
  LOBYTE(v187) = 34;
  if ( v121 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"9");
    ksgui::Label::Label((ksgui::Label *)v121, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v123 = v122;
  }
  else
  {
    v123 = 0;
  }
  LOBYTE(v187) = 2;
  this->lblPosition = v123;
  ((void (*)(ksgui::Label *, int, int))v123->setSize)(v123, 1116471296, 1107296256);
  v124 = (Font *)operator new(0x18u);
  _Right._Ptr = v124;
  LOBYTE(v187) = 35;
  if ( v124 )
    Font::Font(v124, eFontProportional, 25.0, 0, 0);
  else
    v125 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v125);
  std::shared_ptr<Font>::operator=(&this->lblPosition->font, &_Right);
  v126 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v126->_Destroy(v126);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v126->_Weaks, 0xFFFFFFFF) )
        v126->_Delete_this(v126);
    }
  }
  this->lblPosition->fontAlign = eAlignCenter;
  v127 = this->lblPosition;
  v128 = v127->rectBase.left;
  v129 = v127->rect.bottom - v127->rect.top;
  v130 = (float)(v127->rect.right - v127->rect.left) + 775.0;
  v127->rect.top = coordPos.y;
  v131 = v129 + 55.0;
  v127->rect.left = coordPos.x;
  v127->rect.right = v130;
  v127->rect.bottom = v131;
  if ( v128 == 0.0 && v127->rectBase.top == 0.0 )
  {
    v127->rectBase.left = coordPos.x;
    v127->rectBase.top = coordPos.y;
    v127->rectBase.right = v130;
    v127->rectBase.bottom = v131;
  }
  v182 = this->lblPosition;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  v182->parent = this;
  v132 = GameObject::getGameObject<PushToPassManager>(this->sim) != 0;
  this->hasP2P = v132;
  if ( v132 )
  {
    v182 = (ksgui::Label *)operator new(0x11Cu);
    LOBYTE(v187) = 36;
    if ( v182 )
    {
      h = *(float *)&this->gui;
      std::wstring::wstring((std::wstring *)&v180[4], L"P2PLBL");
      ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    }
    else
    {
      v133 = 0;
    }
    LOBYTE(v187) = 2;
    this->p2pLabel = v133;
    ksgui::Form::setPosition((ksgui::Form *)v133, 775.0, 55.0 - 22.0);
    ((void (*)(ksgui::Label *, int, int))this->p2pLabel->setSize)(this->p2pLabel, 1106247680, 1107296256);
    v134 = (Font *)operator new(0x18u);
    _Right._Ptr = v134;
    LOBYTE(v187) = 37;
    if ( v134 )
      Font::Font(v134, eFontMonospaced, 16.0, 0, 0);
    else
      v135 = 0;
    LOBYTE(v187) = 2;
    _Right._Ptr = 0;
    _Right._Rep = 0;
    std::shared_ptr<Font>::_Resetp<Font>(&_Right, v135);
    std::shared_ptr<Font>::operator=(&this->p2pLabel->font, &_Right);
    std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&_Right);
    v136 = this->p2pLabel;
    LODWORD(h) = L"P2P";
    v136->fontAlign = eAlignRight;
    std::wstring::wstring((std::wstring *)&result, (const wchar_t *)LODWORD(h));
    LOBYTE(v187) = 38;
    this->p2pLabel->setText(this->p2pLabel, (const std::wstring *)&result);
    LOBYTE(v187) = 2;
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    v182 = this->p2pLabel;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
    LODWORD(h) = 284;
    v182->parent = this;
    v182 = (ksgui::Label *)operator new(LODWORD(h));
    LOBYTE(v187) = 39;
    if ( v182 )
    {
      h = *(float *)&this->gui;
      std::wstring::wstring((std::wstring *)&v180[4], L"P2PVAL");
      ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    }
    else
    {
      v137 = 0;
    }
    LOBYTE(v187) = 2;
    this->p2pValue = v137;
    ksgui::Form::setPosition((ksgui::Form *)v137, 775.0 + 40.0, 55.0 - 25.0);
    ((void (*)(ksgui::Label *, int, int))this->p2pValue->setSize)(this->p2pValue, 1106247680, 1107296256);
    v138 = (Font *)operator new(0x18u);
    _Right._Ptr = v138;
    LOBYTE(v187) = 40;
    if ( v138 )
      Font::Font(v138, eFontProportional, 20.0, 0, 0);
    else
      v139 = 0;
    LOBYTE(v187) = 2;
    _Right._Ptr = 0;
    _Right._Rep = 0;
    std::shared_ptr<Font>::_Resetp<Font>(&_Right, v139);
    std::shared_ptr<Font>::operator=(&this->p2pValue->font, &_Right);
    std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&_Right);
    this->p2pValue->fontAlign = eAlignLeft;
    v182 = this->p2pValue;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
    v182->parent = this;
  }
  v140 = (Font *)operator new(0x11Cu);
  _Right._Ptr = v140;
  LOBYTE(v187) = 41;
  if ( v140 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"POSITION_LABEL");
    ksgui::Label::Label((ksgui::Label *)v140, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v141 = 0;
  }
  LOBYTE(v187) = 2;
  LODWORD(h) = L"POS.";
  this->lblPositionDescription = v141;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(h));
  LOBYTE(v187) = 42;
  v142 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v187) = 43;
  this->lblPositionDescription->setText(this->lblPositionDescription, v142);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v187) = 2;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Label *, _DWORD, int))this->lblPositionDescription->setSize)(
    this->lblPositionDescription,
    this->lblLast->rect.right - this->lblLast->rect.left,
    1101529088);
  this->lblPositionDescription->fontAlign = eAlignCenter;
  v143 = this->lblPositionDescription;
  v144 = this->rect.bottom - this->rect.top;
  v145 = v143->rect.bottom - v143->rect.top;
  v146 = v143->rect.right - v143->rect.left;
  v143->rect.left = coordPos.x;
  v147 = v144 - v145;
  v148 = v143->rect.bottom - v143->rect.top;
  v149 = v146 + 775.0;
  v143->rect.top = v147;
  v150 = v147 + v148;
  v151 = v143->rectBase.left;
  v143->rect.right = v149;
  v143->rect.bottom = v150;
  if ( v151 == 0.0 && v143->rectBase.top == 0.0 )
  {
    v143->rectBase.left = coordPos.x;
    v143->rectBase.top = v147;
    v143->rectBase.right = v149;
    v143->rectBase.bottom = v150;
  }
  v182 = this->lblPositionDescription;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v152 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v152;
  LOBYTE(v187) = 44;
  if ( v152 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"ABS");
    ksgui::Label::Label((ksgui::Label *)v152, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v154 = v153;
  }
  else
  {
    v154 = 0;
  }
  LOBYTE(v187) = 2;
  v155 = this->lblLast;
  this->abs = v154;
  ((void (*)(ksgui::Label *, _DWORD, int))v154->setSize)(
    v154,
    v155->rect.right - v155->rect.left,
    1101529088);
  v156 = this->abs;
  LODWORD(h) = 24;
  v156->fontAlign = eAlignCenter;
  v157 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v157;
  LOBYTE(v187) = 45;
  if ( v157 )
    Font::Font(v157, eFontProportional, 16.0, 0, 0);
  else
    v158 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v158);
  std::shared_ptr<Font>::operator=(&this->abs->font, &_Right);
  v159 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v159->_Destroy(v159);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v159->_Weaks, 0xFFFFFFFF) )
        v159->_Delete_this(v159);
    }
  }
  v160 = this->abs;
  v161 = v160->rectBase.left;
  v162 = v160->rect.right - v160->rect.left;
  v163 = v160->rect.bottom - v160->rect.top;
  v160->rect.top = 30.0;
  v160->rect.left = 650.0;
  v164 = v162 + 650.0;
  v165 = v163 + 30.0;
  v160->rect.right = v164;
  v160->rect.bottom = v165;
  if ( v161 == 0.0 && v160->rectBase.top == 0.0 )
  {
    v160->rectBase.left = 650.0;
    v160->rectBase.top = 30.0;
    v160->rectBase.right = v164;
    v160->rectBase.bottom = v165;
  }
  v166 = &this->controls;
  v182 = this->abs;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&v182);
  LODWORD(h) = 284;
  v182->parent = this;
  v182 = (ksgui::Label *)operator new(LODWORD(h));
  LOBYTE(v187) = 46;
  if ( v182 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v180[4], L"TC");
    ksgui::Label::Label(v182, *(std::wstring *)&v180[4], (ksgui::GUI *)LODWORD(h));
    v168 = v167;
  }
  else
  {
    v168 = 0;
  }
  LOBYTE(v187) = 2;
  v169 = this->lblLast;
  this->tc = v168;
  ((void (*)(ksgui::Label *, _DWORD, int))v168->setSize)(
    v168,
    v169->rect.right - v169->rect.left,
    1101529088);
  v170 = this->tc;
  LODWORD(h) = 24;
  v170->fontAlign = eAlignCenter;
  v171 = (Font *)operator new(LODWORD(h));
  _Right._Ptr = v171;
  LOBYTE(v187) = 47;
  if ( v171 )
    Font::Font(v171, eFontProportional, 16.0, 0, 0);
  else
    v172 = 0;
  LOBYTE(v187) = 2;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v172);
  std::shared_ptr<Font>::operator=(&this->tc->font, &_Right);
  v173 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v173->_Destroy(v173);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v173->_Weaks) )
        v173->_Delete_this(v173);
    }
    v166 = &this->controls;
  }
  v174 = this->tc;
  v175 = v174->rectBase.left;
  v176 = v174->rect.right - v174->rect.left;
  v177 = v174->rect.bottom - v174->rect.top;
  v174->rect.top = 30.0;
  v174->rect.left = 690.0;
  v178 = v176 + 690.0;
  v179 = v177 + 30.0;
  v174->rect.right = v178;
  v174->rect.bottom = v179;
  if ( v175 == 0.0 && v174->rectBase.top == 0.0 )
  {
    v174->rectBase.left = 690.0;
    v174->rectBase.top = 30.0;
    v174->rectBase.right = v178;
    v174->rectBase.bottom = v179;
  }
  v182 = this->tc;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)v166, (int *)&v182);
  LODWORD(h) = v182;
  v182->parent = this;
  ((void (*)(ACEssentials *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
}
ACEssentials *ACEssentials::`scalar deleting destructor'(ACEssentials *this, unsigned int a2)
{
  this->__vftable = (ACEssentials_vtbl *)&ACEssentials::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->texRpmBar);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texFuelBar);
  this->__vftable = (ACEssentials_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge ACEssentials::render(ACEssentials *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  CarAvatar *v5; // edi
  double v6; // xmm3_8
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  _DWORD *v10; // ecx
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  _DWORD *v17; // ecx
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  int *v24; // edx
  float v25; // xmm1_4
  vec4f v26; // xmm0
  float v27; // xmm0_4
  float v28; // xmm2_4
  _DWORD *v29; // ecx
  unsigned int v30; // ecx
  _DWORD *v31; // eax
  unsigned int v32; // eax
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  _DWORD *v36; // ecx
  unsigned int v37; // ecx
  _DWORD *v38; // eax
  unsigned int v39; // eax
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  const std::wstring *v43; // eax
  std::wstring *v44; // eax
  float v45; // xmm4_4
  float v46; // xmm4_4
  float v47; // xmm4_4
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  float v51; // xmm1_4
  const std::wstring *v52; // eax
  std::wstring *v53; // eax
  ksgui::Label *v54; // ecx
  ksgui::Label_vtbl *v55; // eax
  ksgui::Label *v56; // ecx
  ksgui::Label_vtbl *v57; // eax
  Lap *v58; // eax
  std::wstring *v59; // eax
  const std::wstring *v60; // eax
  const std::wstring *v61; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v62; // ecx
  std::wstring *v63; // eax
  Sim *v64; // ecx
  signed int v65; // eax
  std::wostream *v66; // eax
  std::wostream *v67; // eax
  const std::wstring *v68; // eax
  std::wstring *v69; // eax
  Sim *v70; // ecx
  long double v71; // st7
  ksgui::Label *v72; // eax
  std::wstring *v73; // eax
  const std::wstring *v74; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v75; // ecx
  ksgui::Label *v76; // ecx
  ksgui::Label_vtbl *v77; // eax
  ksgui::Label *v78; // ecx
  ksgui::Label_vtbl *v79; // eax
  ksgui::Label *v80; // ecx
  ksgui::Label_vtbl *v81; // eax
  ksgui::Label *v82; // ecx
  ksgui::Label_vtbl *v83; // eax
  std::wstring *v84; // eax
  Sim *v85; // ecx
  std::wostream *v86; // eax
  Sim *v87; // ecx
  unsigned int v88; // eax
  std::wostream *v89; // eax
  const std::wstring *v90; // eax
  std::wstring *v91; // eax
  Sim *v92; // ecx
  RaceManager *v93; // ecx
  long double v94; // st7
  std::wstring *v95; // eax
  const std::wstring *v96; // eax
  long double v97; // st7
  std::wstring *v98; // eax
  int v99; // ecx
  int v100; // ecx
  std::wostream *v101; // eax
  std::wostream *v102; // eax
  const std::wstring *v103; // eax
  const std::wstring *v104; // eax
  std::wstring *v105; // eax
  Lap *v106; // eax
  std::wstring *v107; // eax
  const std::wstring *v108; // eax
  std::wstring *v109; // eax
  bool v110; // al
  ksgui::Label *v111; // ecx
  vec4f v112; // xmm0
  bool v113; // al
  ksgui::Label *v114; // ecx
  vec4f v115; // xmm0
  vec4f v116; // xmm0
  const std::wstring *v117; // eax
  const char *r; // [esp+2Ch] [ebp-4ECh]
  float ga; // [esp+30h] [ebp-4E8h]
  float gb; // [esp+30h] [ebp-4E8h]
  float gc; // [esp+30h] [ebp-4E8h]
  float gd; // [esp+30h] [ebp-4E8h]
  float ge; // [esp+30h] [ebp-4E8h]
  const char *g; // [esp+30h] [ebp-4E8h]
  int g_4; // [esp+34h] [ebp-4E4h]
  int a; // [esp+38h] [ebp-4E0h]
  int aa; // [esp+38h] [ebp-4E0h]
  __int64 v128; // [esp+3Ch] [ebp-4DCh]
  float v129; // [esp+44h] [ebp-4D4h]
  GLRenderer *v130; // [esp+4Ch] [ebp-4CCh]
  GLRenderer *v131; // [esp+4Ch] [ebp-4CCh]
  bool v132; // [esp+57h] [ebp-4C1h]
  long double v133; // [esp+58h] [ebp-4C0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v134; // [esp+60h] [ebp-4B8h] BYREF
  std::wstring v135; // [esp+110h] [ebp-408h] BYREF
  std::wstring v136; // [esp+128h] [ebp-3F0h] BYREF
  std::wstring v137; // [esp+140h] [ebp-3D8h] BYREF
  std::wstring v138; // [esp+158h] [ebp-3C0h] BYREF
  std::wstring v139; // [esp+170h] [ebp-3A8h] BYREF
  std::wstring result; // [esp+188h] [ebp-390h] BYREF
  std::wstring v141; // [esp+1A0h] [ebp-378h] BYREF
  std::wstring v142; // [esp+1B8h] [ebp-360h] BYREF
  std::wstring v143; // [esp+1D0h] [ebp-348h] BYREF
  std::wstring v144; // [esp+1E8h] [ebp-330h] BYREF
  Lap v145; // [esp+200h] [ebp-318h] BYREF
  std::wstring v146; // [esp+230h] [ebp-2E8h] BYREF
  std::wstring v147; // [esp+248h] [ebp-2D0h] BYREF
  std::wstring v148; // [esp+260h] [ebp-2B8h] BYREF
  std::wstring v149; // [esp+278h] [ebp-2A0h] BYREF
  std::wstring v150; // [esp+290h] [ebp-288h] BYREF
  std::wstring text; // [esp+2A8h] [ebp-270h] BYREF
  Session v152; // [esp+2C0h] [ebp-258h] BYREF
  std::wstring v153; // [esp+320h] [ebp-1F8h] BYREF
  std::wstring v154; // [esp+338h] [ebp-1E0h] BYREF
  std::wstring v155; // [esp+350h] [ebp-1C8h] BYREF
  std::wstring v156; // [esp+368h] [ebp-1B0h] BYREF
  std::wstring v157; // [esp+380h] [ebp-198h] BYREF
  std::wstring v158; // [esp+398h] [ebp-180h] BYREF
  Lap v159; // [esp+3B0h] [ebp-168h] BYREF
  Session v160; // [esp+3E0h] [ebp-138h] BYREF
  Session v161; // [esp+440h] [ebp-D8h] BYREF
  Session v162; // [esp+4A0h] [ebp-78h] BYREF
  int v163; // [esp+514h] [ebp-4h]

  ksgui::Control::render(this, a2, (int)this, dt, v128, v129);
  v4 = Sim::getFocusedCarIndex(this->sim);
  v5 = Sim::getCar(this->sim, v4);
  *(_DWORD *)v134.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v134.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v134.gap68);
  v163 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v134, &v134.gap10[8], 0);
  v163 = 1;
  *(_DWORD *)&v134.gap0[*(_DWORD *)(*(_DWORD *)v134.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v133 + *(_DWORD *)(*(_DWORD *)v134.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v134.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v134.gap10[8]);
  *(_DWORD *)&v134.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v134.gap10[64] = 0;
  *(_DWORD *)&v134.gap10[68] = 0;
  v163 = 3;
  v130 = this->gui->graphics->gl;
  GLRenderer::color4f(v130, 1.0, 1.0, 1.0, 1.0);
  v6 = v5->physicsInfo.maxFuel;
  v7 = v5->physicsState.fuel;
  v8 = v6;
  if ( v7 <= v8 )
  {
    if ( v7 >= 0.0 )
      v8 = v5->physicsState.fuel;
    else
      v8 = 0.0;
  }
  v9 = v8 / v6;
  *(float *)&v133 = v9;
  if ( v9 <= 0.25 )
  {
    ga = 1.0 - (0.25 - v9) * 4.0;
    GLRenderer::color4f(v130, 1.0, ga, 0.0, 0.5);
  }
  else
  {
    GLRenderer::color4f(v130, 1.0, 1.0, 1.0, 0.5);
  }
  v10 = this->texFuelBar.kid;
  if ( v10 )
    v11 = v10[10];
  else
    v11 = 0;
  v12 = this->texFuelBar.kid;
  if ( v12 )
    v13 = v12[9];
  else
    v13 = 0;
  v14 = this->scaleMult;
  v15 = (float)v11;
  gb = v15 * v14;
  v16 = (float)v13;
  GLRenderer::quad(
    v130,
    (float)(v14 * 24.0) + this->rect.left,
    (float)(v14 * 66.0) + this->rect.top,
    (float)(v16 * *(float *)&v133) * v14,
    gb,
    0,
    0);
  GLRenderer::color4f(v130, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texFuelBar);
  v17 = this->texFuelBar.kid;
  if ( v17 )
    v18 = v17[10];
  else
    v18 = 0;
  v19 = this->texFuelBar.kid;
  if ( v19 )
    v20 = v19[9];
  else
    v20 = 0;
  v21 = this->scaleMult;
  v22 = (float)v18;
  gc = v22 * v21;
  v23 = (float)v20;
  GLRenderer::quad(
    v130,
    (float)(v21 * 24.0) + this->rect.left,
    (float)(v21 * 66.0) + this->rect.top,
    v23 * v21,
    gc,
    1,
    0);
  v24 = &v5->physicsInfo.engineDamageRPM;
  if ( v5->physicsState.limiterRPM < v5->physicsInfo.engineDamageRPM )
    v24 = &v5->physicsState.limiterRPM;
  *(float *)&v133 = (float)*v24;
  v25 = (float)((float)(v5->physicsState.engineRPM - this->currentRPM) * (float)((float)(dt * 62.499996) * 0.2))
      + this->currentRPM;
  this->currentRPM = v25;
  if ( (float)(*(float *)&v133 * 0.99000001) <= v25 )
  {
    GLRenderer::color4f(v130, 1.0, 0.0, 0.0, 0.5);
    v26 = (vec4f)_xmm;
  }
  else
  {
    GLRenderer::color4f(v130, 1.0, 1.0, 1.0, 0.5);
    v26 = (vec4f)_xmm;
  }
  this->lblGear->foreColor = v26;
  v27 = this->currentRPM / *(float *)&v133;
  if ( v27 <= 1.0 )
  {
    v28 = 0.0;
    if ( v27 >= 0.0 )
      v28 = this->currentRPM / *(float *)&v133;
  }
  else
  {
    v28 = FLOAT_1_0;
  }
  v29 = this->texRpmBar.kid;
  if ( v29 )
    v30 = v29[10];
  else
    v30 = 0;
  v31 = this->texRpmBar.kid;
  if ( v31 )
    v32 = v31[9];
  else
    v32 = 0;
  v33 = this->scaleMult;
  v34 = (float)v30;
  gd = v34 * v33;
  v35 = (float)v32;
  GLRenderer::quad(
    v130,
    (float)(v33 * 164.0) + this->rect.left,
    (float)(v33 * 66.0) + this->rect.top,
    (float)(v35 * v28) * v33,
    gd,
    0,
    0);
  GLRenderer::color4f(v130, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->texRpmBar);
  v36 = this->texRpmBar.kid;
  if ( v36 )
    v37 = v36[10];
  else
    v37 = 0;
  v38 = this->texRpmBar.kid;
  if ( v38 )
    v39 = v38[9];
  else
    v39 = 0;
  v40 = this->scaleMult;
  v41 = (float)v37;
  ge = v41 * v40;
  v42 = (float)v39;
  GLRenderer::quad(
    v130,
    (float)(v40 * 164.0) + this->rect.left,
    (float)(v40 * 66.0) + this->rect.top,
    v42 * v40,
    ge,
    1,
    0);
  std::operator<<<wchar_t>((std::wostream *)v134.gap10, &gears[v5->physicsState.gear]);
  v43 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &result);
  LOBYTE(v163) = 4;
  this->lblGear->setText(this->lblGear, v43);
  LOBYTE(v163) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v136._Myres = 7;
  v136._Mysize = 0;
  v136._Bx._Buf[0] = 0;
  std::wstring::assign(&v136, word_17BE9D8, 0);
  LOBYTE(v163) = 5;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
  v44 = &v136;
  if ( v136._Myres >= 8 )
    v44 = (std::wstring *)v136._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v44->_Bx._Buf, v136._Mysize, *(int *)&v134.gap10[68]);
  LOBYTE(v163) = 3;
  if ( v136._Myres >= 8 )
    operator delete(v136._Bx._Ptr);
  v45 = v5->physicsState.speed.value;
  if ( Speed::useMPH )
    v46 = v45 * 2.2369363;
  else
    v46 = v45 * 3.5999999;
  v47 = v46 + 0.5;
  v48.m128_f32[0] = FLOAT_8388608_0;
  v49.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v47);
  v50.m128_i32[0] = LODWORD(v47) ^ LODWORD(FLOAT_N0_0) & LODWORD(v47);
  v50.m128_f32[0] = _mm_cmplt_ss(v50, v48).m128_f32[0];
  v51 = (float)(v47 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v50.m128_i32[0] | v49.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v50.m128_i32[0] | v49.m128_i32[0]);
  v50.m128_f32[0] = v51 - v47;
  std::wostream::operator<<(
    v134.gap10,
    (int)(float)(v51 - COERCE_FLOAT(_mm_cmpgt_ss(v50, v49).m128_u32[0] & LODWORD(FLOAT_1_0))));
  v52 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &result);
  LOBYTE(v163) = 6;
  this->lblSpeed->setText(this->lblSpeed, v52);
  LOBYTE(v163) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v136._Myres = 7;
  v136._Mysize = 0;
  v136._Bx._Buf[0] = 0;
  std::wstring::assign(&v136, word_17BE9D8, 0);
  LOBYTE(v163) = 7;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
  v53 = &v136;
  if ( v136._Myres >= 8 )
    v53 = (std::wstring *)v136._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v53->_Bx._Buf, v136._Mysize, *(int *)&v134.gap10[68]);
  LOBYTE(v163) = 3;
  if ( v136._Myres >= 8 )
    operator delete(v136._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  if ( Speed::useMPH )
  {
    std::wstring::assign(&v135, L"MPH", 3u);
    LOBYTE(v163) = 8;
  }
  else
  {
    std::wstring::assign(&v135, L"KMH", 3u);
    LOBYTE(v163) = 9;
  }
  this->guiSpeedDesc->setText(this->guiSpeedDesc, &v135);
  LOBYTE(v163) = 3;
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v54 = this->lblPosition;
  if ( v54->visible )
  {
    v55 = v54->__vftable;
    v54->visible = 0;
    ((void (__stdcall *)(_DWORD))v55->onVisibleChanged)(0);
  }
  v56 = this->lblPositionDescription;
  if ( v56->visible )
  {
    v57 = v56->__vftable;
    v56->visible = 0;
    ((void (__stdcall *)(_DWORD))v57->onVisibleChanged)(0);
  }
  this->lblSession->foreColor = (vec4f)_xmm;
  LODWORD(v133) = RaceManager::getCurrentSession(this->sim->raceManager, &v152)->sessionType;
  if ( v152.name._Myres >= 8 )
    operator delete(v152.name._Bx._Ptr);
  v152.name._Myres = 7;
  v152.name._Mysize = 0;
  v152.name._Bx._Buf[0] = 0;
  if ( v152.spawSet._Myres >= 8 )
    operator delete(v152.spawSet._Bx._Ptr);
  v152.spawSet._Myres = 7;
  v152.spawSet._Bx._Buf[0] = 0;
  v152.spawSet._Mysize = 0;
  switch ( LODWORD(v133) )
  {
    case 0:
      v58 = RaceManager::getBestLap(this->sim->raceManager, &v159, v5);
      LOBYTE(v163) = 10;
      v59 = timeToString(&v143, v58->time, 3);
      LOBYTE(v163) = 11;
      if ( v59->_Myres >= 8 )
        v59 = (std::wstring *)v59->_Bx._Ptr;
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, v59->_Bx._Buf);
      if ( v143._Myres >= 8 )
        operator delete(v143._Bx._Ptr);
      v143._Myres = 7;
      v143._Mysize = 0;
      v143._Bx._Buf[0] = 0;
      LOBYTE(v163) = 3;
      Lap::~Lap(&v159);
      std::wstring::wstring(&result, L"BEST");
      LOBYTE(v163) = 12;
      v60 = acTranslate(&v144, &result);
      LOBYTE(v163) = 13;
      this->guiSessionDesc->setText(this->guiSessionDesc, v60);
      if ( v144._Myres >= 8 )
        operator delete(v144._Bx._Ptr);
      LOBYTE(v163) = 3;
      v144._Myres = 7;
      v144._Mysize = 0;
      v144._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      break;
    case 1:
      if ( RaceManager::getSessionCount(this->sim->raceManager) != 1 )
        goto $LN28_0;
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, "---");
      std::wstring::wstring(&text, L"LEFT");
      LOBYTE(v163) = 14;
      v61 = acTranslate(&v155, &text);
      LOBYTE(v163) = 15;
      this->guiSessionDesc->setText(this->guiSessionDesc, v61);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v155);
      v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
      goto LABEL_134;
    case 2:
$LN28_0:
      std::wstring::wstring(&v136, word_17BE9D8);
      LOBYTE(v163) = 16;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
      v63 = &v136;
      if ( v136._Myres >= 8 )
        v63 = (std::wstring *)v136._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v63->_Bx._Buf, v136._Mysize, *(int *)&v134.gap10[68]);
      LOBYTE(v163) = 3;
      if ( v136._Myres >= 8 )
        operator delete(v136._Bx._Ptr);
      v64 = this->sim;
      v136._Myres = 7;
      v136._Mysize = 0;
      v136._Bx._Buf[0] = 0;
      v65 = RaceManager::getCarLeaderboardPosition(v64->raceManager, v5);
      a = this->sim->connectedCarsCount;
      if ( v65 <= 0 )
      {
        v66 = (std::wostream *)v134.gap10;
        g = "-- / ";
      }
      else
      {
        g = " / ";
        v66 = (std::wostream *)std::wostream::operator<<(v134.gap10, v65);
      }
      v67 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v66, g);
      std::wostream::operator<<(v67, a);
      v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &v142);
      LOBYTE(v163) = 17;
      this->lblPosition->setText(this->lblPosition, v68);
      LOBYTE(v163) = 3;
      if ( v142._Myres >= 8 )
        operator delete(v142._Bx._Ptr);
      v142._Myres = 7;
      v142._Mysize = 0;
      v142._Bx._Buf[0] = 0;
      std::wstring::wstring(&v141, word_17BE9D8);
      LOBYTE(v163) = 18;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
      v69 = &v141;
      if ( v141._Myres >= 8 )
        v69 = (std::wstring *)v141._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v69->_Bx._Buf, v141._Mysize, *(int *)&v134.gap10[68]);
      LOBYTE(v163) = 3;
      if ( v141._Myres >= 8 )
        operator delete(v141._Bx._Ptr);
      v70 = this->sim;
      v141._Myres = 7;
      v141._Mysize = 0;
      v141._Bx._Buf[0] = 0;
      v71 = RaceManager::getSessionTimeLeft(v70->raceManager);
      v72 = this->lblSession;
      v133 = v71;
      if ( v71 < 0.0 )
      {
        v72->foreColor = (vec4f)_xmm;
        std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, "0:00");
        std::wstring::wstring(&v150, L"OVER");
        LOBYTE(v163) = 22;
        this->guiSessionDesc->setText(this->guiSessionDesc, &v150);
        v75 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v150;
      }
      else
      {
        v72->foreColor = (vec4f)_xmm;
        v73 = timeToWString(&v157, (int)v71, 0, 0);
        LOBYTE(v163) = 19;
        if ( v73->_Myres >= 8 )
          v73 = (std::wstring *)v73->_Bx._Ptr;
        std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, v73->_Bx._Buf);
        LOBYTE(v163) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v157);
        std::wstring::wstring(&v147, L"LEFT");
        LOBYTE(v163) = 20;
        v74 = acTranslate(&v154, &v147);
        LOBYTE(v163) = 21;
        this->guiSessionDesc->setText(this->guiSessionDesc, v74);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v154);
        v75 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v147;
      }
      LOBYTE(v163) = 3;
      std::wstring::~wstring(v75);
      v76 = this->lblPosition;
      if ( !v76->visible )
      {
        v77 = v76->__vftable;
        v76->visible = 1;
        ((void (__stdcall *)(int))v77->onVisibleChanged)(1);
      }
      v78 = this->lblPositionDescription;
      if ( !v78->visible )
      {
        v79 = v78->__vftable;
        v78->visible = 1;
        ((void (__stdcall *)(int))v79->onVisibleChanged)(1);
      }
      break;
    case 3:
      v80 = this->lblPosition;
      if ( !v80->visible )
      {
        v81 = v80->__vftable;
        v80->visible = 1;
        ((void (__stdcall *)(int))v81->onVisibleChanged)(1);
      }
      v82 = this->lblPositionDescription;
      if ( !v82->visible )
      {
        v83 = v82->__vftable;
        v82->visible = 1;
        ((void (__stdcall *)(int))v83->onVisibleChanged)(1);
      }
      std::wstring::wstring(&v139, word_17BE9D8);
      LOBYTE(v163) = 23;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
      v84 = &v139;
      if ( v139._Myres >= 8 )
        v84 = (std::wstring *)v139._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v84->_Bx._Buf, v139._Mysize, *(int *)&v134.gap10[68]);
      LOBYTE(v163) = 3;
      if ( v139._Myres >= 8 )
        operator delete(v139._Bx._Ptr);
      v85 = this->sim;
      v139._Myres = 7;
      v139._Mysize = 0;
      v139._Bx._Buf[0] = 0;
      if ( ReplayManager::isInReplaymode(v85->replayManager) )
      {
        aa = this->sim->connectedCarsCount;
        v86 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, L"--");
      }
      else
      {
        v87 = this->sim;
        aa = v87->connectedCarsCount;
        v88 = RaceManager::getCarRealTimePosition(v87->raceManager, v5);
        v86 = (std::wostream *)std::wostream::operator<<(v134.gap10, v88 + 1);
      }
      v89 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v86, " / ");
      std::wostream::operator<<(v89, aa);
      v90 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &v137);
      LOBYTE(v163) = 24;
      this->lblPosition->setText(this->lblPosition, v90);
      LOBYTE(v163) = 3;
      if ( v137._Myres >= 8 )
        operator delete(v137._Bx._Ptr);
      v137._Myres = 7;
      v137._Mysize = 0;
      v137._Bx._Buf[0] = 0;
      std::wstring::wstring(&v135, word_17BE9D8);
      LOBYTE(v163) = 25;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
      v91 = &v135;
      if ( v135._Myres >= 8 )
        v91 = (std::wstring *)v135._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v91->_Bx._Buf, v135._Mysize, *(int *)&v134.gap10[68]);
      LOBYTE(v163) = 3;
      if ( v135._Myres >= 8 )
        operator delete(v135._Bx._Ptr);
      v92 = this->sim;
      v135._Bx._Buf[0] = 0;
      v135._Myres = 7;
      v135._Mysize = 0;
      v132 = RaceManager::getCurrentSession(v92->raceManager, &v160)->isTimedRace;
      Session::~Session(&v160);
      v93 = this->sim->raceManager;
      if ( v132 )
      {
        v133 = RaceManager::getTimeToSessionStart(v93);
        if ( v133 >= 0.0 )
        {
          v133 = RaceManager::getTimetoWait(this->sim->raceManager);
          if ( v133 <= 0.0 )
          {
            std::wstring::wstring(&v149, word_17BE9D8);
            LOBYTE(v163) = 31;
            this->guiSessionDesc->setText(this->guiSessionDesc, &v149);
            v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v149;
          }
          else
          {
            this->lblSession->foreColor = (vec4f)_xmm;
            v97 = RaceManager::getTimetoWait(this->sim->raceManager);
            v98 = timeToWString(&v158, (int)v97, 0, 0);
            LOBYTE(v163) = 29;
            if ( v98->_Myres >= 8 )
              v98 = (std::wstring *)v98->_Bx._Ptr;
            std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, v98->_Bx._Buf);
            LOBYTE(v163) = 3;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
            std::wstring::wstring(&v148, L"OVER");
            LOBYTE(v163) = 30;
            this->guiSessionDesc->setText(this->guiSessionDesc, &v148);
            v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v148;
          }
        }
        else
        {
          this->lblSession->foreColor = (vec4f)_xmm;
          v94 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
          v95 = timeToWString(&v156, (int)v94, 0, 0);
          LOBYTE(v163) = 26;
          if ( v95->_Myres >= 8 )
            v95 = (std::wstring *)v95->_Bx._Ptr;
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, v95->_Bx._Buf);
          LOBYTE(v163) = 3;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v156);
          std::wstring::wstring(&v146, L"LEFT");
          LOBYTE(v163) = 27;
          v96 = acTranslate(&v153, &v146);
          LOBYTE(v163) = 28;
          this->guiSessionDesc->setText(this->guiSessionDesc, v96);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v153);
          v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v146;
        }
      }
      else
      {
        v131 = (GLRenderer *)RaceManager::getCurrentSession(v93, &v162)->laps;
        if ( v5->physicsState.lapCount + 1 <= (unsigned int)v131 )
        {
          v99 = v5->physicsState.lapCount + 1;
          if ( v5->physicsState.lapCount == -1 )
            v99 = 1;
          v131 = (GLRenderer *)v99;
        }
        Session::~Session(&v162);
        RaceManager::getCurrentSession(this->sim->raceManager, &v161);
        LOBYTE(v163) = 32;
        g_4 = v100;
        v101 = (std::wostream *)std::wostream::operator<<(v134.gap10, v131);
        v102 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v101, r);
        std::wostream::operator<<(v102, g_4);
        LOBYTE(v163) = 3;
        Session::~Session(&v161);
        std::wstring::wstring(&v138, L"LAPS");
        LOBYTE(v163) = 33;
        v103 = acTranslate((std::wstring *)&v145, &v138);
        LOBYTE(v163) = 34;
        this->guiSessionDesc->setText(this->guiSessionDesc, v103);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v145);
        v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v138;
      }
LABEL_134:
      LOBYTE(v163) = 3;
      std::wstring::~wstring(v62);
      break;
    default:
      break;
  }
  v104 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &v138);
  LOBYTE(v163) = 35;
  this->lblSession->setText(this->lblSession, v104);
  LOBYTE(v163) = 3;
  if ( v138._Myres >= 8 )
    operator delete(v138._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  std::wstring::assign(&v135, word_17BE9D8, 0);
  LOBYTE(v163) = 36;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
  v105 = &v135;
  if ( v135._Myres >= 8 )
    v105 = (std::wstring *)v135._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v105->_Bx._Buf, v135._Mysize, *(int *)&v134.gap10[68]);
  LOBYTE(v163) = 3;
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v106 = RaceManager::getLastLap(this->sim->raceManager, &v145, v5);
  LOBYTE(v163) = 37;
  v107 = timeToString(&v137, v106->time, 3);
  LOBYTE(v163) = 38;
  if ( v107->_Myres >= 8 )
    v107 = (std::wstring *)v107->_Bx._Ptr;
  std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v134.gap10, v107->_Bx._Buf);
  if ( v137._Myres >= 8 )
    operator delete(v137._Bx._Ptr);
  LOBYTE(v163) = 3;
  v137._Myres = 7;
  v137._Mysize = 0;
  v137._Bx._Buf[0] = 0;
  if ( v145.compound._Myres >= 8 )
    operator delete(v145.compound._Bx._Ptr);
  v145.compound._Myres = 7;
  v145.compound._Bx._Buf[0] = 0;
  v145.compound._Mysize = 0;
  if ( v145.splits._Myfirst )
    operator delete(v145.splits._Myfirst);
  v108 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v134, &v138);
  LOBYTE(v163) = 39;
  this->lblLast->setText(this->lblLast, v108);
  LOBYTE(v163) = 3;
  if ( v138._Myres >= 8 )
    operator delete(v138._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  std::wstring::assign(&v135, word_17BE9D8, 0);
  LOBYTE(v163) = 40;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v134.gap10[8]);
  v109 = &v135;
  if ( v135._Myres >= 8 )
    v109 = (std::wstring *)v135._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v134.gap10[8], v109->_Bx._Buf, v135._Mysize, *(int *)&v134.gap10[68]);
  LOBYTE(v163) = 3;
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v110 = CarAvatar::isAbsEnabled(v5);
  v111 = this->abs;
  LOBYTE(v133) = v110;
  if ( v111->visible != v110 )
  {
    v111->visible = v110;
    v111->onVisibleChanged(v111, LODWORD(v133));
  }
  if ( this->abs->visible )
  {
    if ( CarAvatar::isAbsInAction(v5) )
      v112 = (vec4f)_xmm;
    else
      v112 = (vec4f)_xmm;
    this->abs->foreColor = v112;
  }
  v113 = CarAvatar::isTcEnabled(v5);
  v114 = this->tc;
  LOBYTE(v133) = v113;
  if ( v114->visible != v113 )
  {
    v114->visible = v113;
    v114->onVisibleChanged(v114, LODWORD(v133));
  }
  if ( this->tc->visible )
  {
    if ( CarAvatar::isTcInAction(v5) )
      v115 = (vec4f)_xmm;
    else
      v115 = (vec4f)_xmm;
    this->tc->foreColor = v115;
  }
  if ( this->hasP2P )
  {
    switch ( v5->physicsState.p2pStatus )
    {
      case 1u:
        v116 = (vec4f)_xmm;
        break;
      case 2u:
        v116 = (vec4f)_xmm;
        break;
      case 3u:
        v116 = (vec4f)_xmm;
        break;
      default:
        goto LABEL_177;
    }
    this->p2pValue->foreColor = v116;
LABEL_177:
    v117 = std::to_wstring(&v138, v5->physicsState.p2pActivations);
    LOBYTE(v163) = 41;
    this->p2pValue->setText(this->p2pValue, v117);
    if ( v138._Myres >= 8 )
      operator delete(v138._Bx._Ptr);
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v134);
}
