#include "formmgu.h"
void __userpurge FormMGU::FormMGU(FormMGU *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar)
{
  const std::wstring *v4; // eax
  void (__cdecl *v5)(void *); // eax
  Font *v6; // eax
  Font *v7; // eax
  Font *v8; // ebp
  Font *v9; // eax
  Font *v10; // eax
  Font *v11; // eax
  Font *v12; // eax
  Font *v13; // eax
  Font *v14; // eax
  ksgui::Label *v15; // edi
  int v16; // eax
  int v17; // edi
  float v18; // eax
  volatile signed __int32 *v19; // ebp
  int v20; // eax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  Material *v26; // edi
  int v27; // eax
  int v28; // edi
  float v29; // eax
  volatile signed __int32 *v30; // ebp
  int v31; // eax
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  Material *v37; // edi
  int v38; // eax
  int v39; // edi
  float v40; // eax
  volatile signed __int32 *v41; // ebp
  int v42; // eax
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm3_4
  Material *v48; // edi
  int v49; // eax
  int v50; // edi
  float v51; // eax
  int v52; // edx
  int v53; // ecx
  int v54; // eax
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  Material *v60; // edi
  int v61; // eax
  int v62; // edi
  float v63; // eax
  int v64; // edx
  int v65; // ecx
  int v66; // eax
  float v67; // xmm0_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm2_4
  float v71; // xmm3_4
  Material *v72; // edi
  int v73; // eax
  int v74; // edi
  float v75; // eax
  int v76; // edx
  int v77; // ecx
  int v78; // eax
  float v79; // xmm0_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  float v82; // xmm2_4
  float v83; // xmm3_4
  Material *v84; // edi
  int v85; // eax
  int v86; // edi
  float v87; // eax
  int v88; // edx
  int v89; // ecx
  int v90; // eax
  float v91; // xmm0_4
  float v92; // xmm2_4
  float v93; // xmm3_4
  float v94; // xmm2_4
  float v95; // xmm3_4
  Material *v96; // edi
  int v97; // eax
  int v98; // edi
  int v99; // eax
  float v100; // xmm0_4
  float v101; // xmm2_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm3_4
  Material *v105; // edi
  ksgui::Label *v106; // eax
  ksgui::Label *v107; // ecx
  float v108; // eax
  ksgui::Label *v109; // eax
  ksgui::Label *v110; // ecx
  float v111; // xmm0_4
  float v112; // xmm2_4
  float v113; // xmm3_4
  float v114; // xmm2_4
  float v115; // xmm3_4
  ksgui::Label *v116; // eax
  ksgui::Label *v117; // ecx
  float v118; // eax
  ksgui::Label *v119; // eax
  ksgui::Label *v120; // ecx
  float v121; // xmm0_4
  float v122; // xmm2_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm3_4
  ksgui::Label *v126; // eax
  ksgui::Label *v127; // ecx
  float v128; // eax
  ksgui::Label *v129; // eax
  ksgui::Label *v130; // ecx
  float v131; // xmm0_4
  float v132; // xmm2_4
  float v133; // xmm3_4
  float v134; // xmm2_4
  float v135; // xmm3_4
  Material *v136; // ebp
  ksgui::Label *v137; // eax
  ksgui::Label *v138; // ecx
  float v139; // eax
  ksgui::Label *v140; // eax
  ksgui::Label *v141; // edx
  float v142; // xmm0_4
  float v143; // xmm2_4
  float v144; // xmm3_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  std::_Ref_count_base *v147; // edi
  std::_Ref_count_base *v148; // edi
  std::_Ref_count_base *v149; // edi
  _BYTE v150[28]; // [esp+7Ch] [ebp-9Ch] BYREF
  float h; // [esp+98h] [ebp-80h]
  int _Val; // [esp+B0h] [ebp-68h] BYREF
  std::_Ptr_base<Material> v153; // [esp+B4h] [ebp-64h] BYREF
  std::shared_ptr<Font> smallfont; // [esp+BCh] [ebp-5Ch] BYREF
  std::shared_ptr<Font> mediumfont; // [esp+C4h] [ebp-54h] BYREF
  std::shared_ptr<Font> bigfont; // [esp+CCh] [ebp-4Ch] BYREF
  FormMGU *v157; // [esp+D4h] [ebp-44h]
  std::wstring text; // [esp+D8h] [ebp-40h] BYREF
  std::wstring result; // [esp+F0h] [ebp-28h] BYREF
  int v160; // [esp+114h] [ebp-4h]

  LODWORD(h) = 1;
  v157 = this;
  *(_DWORD *)&v150[24] = aCar->sim->game->gui;
  *(_DWORD *)&v150[20] = 7;
  *(_DWORD *)&v150[16] = 0;
  *(_WORD *)v150 = 0;
  std::wstring::assign((std::wstring *)v150, L"FORM_MGU", 8u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v150, *(ksgui::GUI **)&v150[24], SLOBYTE(h));
  v160 = 0;
  LODWORD(h) = 14;
  this->__vftable = (FormMGU_vtbl *)&FormMGU::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"ERS Management", LODWORD(h));
  LOBYTE(v160) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v160) = 2;
  this->formTitle->setText(this->formTitle, v4);
  v5 = operator delete;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v5 = operator delete;
  }
  result._Myres = 7;
  LOBYTE(v160) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v5(text._Bx._Ptr);
  LODWORD(h) = 1;
  this->devApp = 0;
  this->avatar = aCar;
  ksgui::Form::setAutoHideMode(this, SLODWORD(h));
  v6 = (Font *)operator new(0x18u);
  _Val = (int)v6;
  LOBYTE(v160) = 3;
  if ( v6 )
    Font::Font(v6, eFontMonospaced, 12.0, 0, 1);
  else
    v7 = 0;
  LOBYTE(v160) = 0;
  smallfont._Ptr = 0;
  smallfont._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&smallfont, v7);
  LOBYTE(v160) = 4;
  v8 = smallfont._Ptr;
  LODWORD(h) = 24;
  smallfont._Ptr->shadowed = 1;
  v8->shadowPixelDistance = 1.0;
  v9 = (Font *)operator new(LODWORD(h));
  _Val = (int)v9;
  LOBYTE(v160) = 5;
  if ( v9 )
    Font::Font(v9, eFontMonospaced, 14.0, 0, 1);
  else
    v10 = 0;
  LOBYTE(v160) = 4;
  mediumfont._Ptr = 0;
  mediumfont._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&mediumfont, v10);
  LOBYTE(v160) = 6;
  v11 = mediumfont._Ptr;
  LODWORD(h) = 24;
  mediumfont._Ptr->shadowed = 1;
  v11->shadowPixelDistance = 1.0;
  v12 = (Font *)operator new(LODWORD(h));
  _Val = (int)v12;
  LOBYTE(v160) = 7;
  if ( v12 )
    Font::Font(v12, eFontMonospaced, 40.0, 0, 1);
  else
    v13 = 0;
  LOBYTE(v160) = 6;
  bigfont._Ptr = 0;
  bigfont._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&bigfont, v13);
  LOBYTE(v160) = 8;
  v14 = bigfont._Ptr;
  LODWORD(h) = 284;
  bigfont._Ptr->shadowed = 1;
  v14->shadowPixelDistance = 1.0;
  v15 = (ksgui::Label *)operator new(LODWORD(h));
  _Val = (int)v15;
  LOBYTE(v160) = 9;
  if ( v15 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Recovery_title", 0xEu);
    ksgui::Label::Label(v15, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v18 = this->fontScale;
  *(_DWORD *)&v150[24] = v8;
  *(float *)(v17 + 208) = v18;
  v153 = 0i64;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v19 = *(volatile signed __int32 **)(v17 + 132);
  *(std::_Ptr_base<Material> *)(v17 + 128) = v153;
  if ( v19 )
  {
    if ( !_InterlockedExchangeAdd(v19 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v19)(v19);
      if ( !_InterlockedExchangeAdd(v19 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v19 + 4))(v19);
    }
  }
  LODWORD(h) = 5;
  *(_DWORD *)(v17 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"MGU-K", LODWORD(h));
  LOBYTE(v160) = 10;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v17 + 68))(v17, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v20 = *(_DWORD *)v17;
  *(_OWORD *)(v17 + 76) = _xmm;
  (*(void (**)(int, int, int))(v20 + 28))(v17, 1117782016, 1101004800);
  v21 = *(float *)(v17 + 264);
  v22 = *(float *)(v17 + 32) - *(float *)(v17 + 28);
  v23 = *(float *)(v17 + 40) - *(float *)(v17 + 36);
  *(_DWORD *)(v17 + 36) = 1109393408;
  *(_DWORD *)(v17 + 28) = 1084227584;
  v24 = v22 + 5.0;
  v25 = v23 + 40.0;
  *(float *)(v17 + 32) = v24;
  *(float *)(v17 + 40) = v25;
  if ( v21 == 0.0 && *(float *)(v17 + 272) == 0.0 )
  {
    *(_DWORD *)(v17 + 264) = 1084227584;
    *(_DWORD *)(v17 + 272) = 1109393408;
    *(float *)(v17 + 268) = v24;
    *(float *)(v17 + 276) = v25;
  }
  _Val = v17;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v26 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v26;
  LOBYTE(v160) = 11;
  if ( v26 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Delivery_title", 0xEu);
    ksgui::Label::Label((ksgui::Label *)v26, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v28 = v27;
  }
  else
  {
    v28 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v29 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v28 + 208) = v29;
  v153 = 0i64;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v30 = *(volatile signed __int32 **)(v28 + 132);
  *(std::_Ptr_base<Material> *)(v28 + 128) = v153;
  if ( v30 )
  {
    if ( !_InterlockedExchangeAdd(v30 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v30)(v30);
      if ( !_InterlockedExchangeAdd(v30 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v30 + 4))(v30);
    }
  }
  LODWORD(h) = 5;
  *(_DWORD *)(v28 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"MGU-K", LODWORD(h));
  LOBYTE(v160) = 12;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v28 + 68))(v28, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v31 = *(_DWORD *)v28;
  *(_OWORD *)(v28 + 76) = _xmm;
  (*(void (**)(int, int, int))(v31 + 28))(v28, 1123024896, 1101004800);
  v32 = *(float *)(v28 + 264);
  v33 = *(float *)(v28 + 32) - *(float *)(v28 + 28);
  v34 = *(float *)(v28 + 40) - *(float *)(v28 + 36);
  *(_DWORD *)(v28 + 36) = 1109393408;
  *(_DWORD *)(v28 + 28) = 1119092736;
  v35 = v33 + 90.0;
  v36 = v34 + 40.0;
  *(float *)(v28 + 32) = v35;
  *(float *)(v28 + 40) = v36;
  if ( v32 == 0.0 && *(float *)(v28 + 272) == 0.0 )
  {
    *(_DWORD *)(v28 + 264) = 1119092736;
    *(_DWORD *)(v28 + 272) = 1109393408;
    *(float *)(v28 + 268) = v35;
    *(float *)(v28 + 276) = v36;
  }
  _Val = v28;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v37 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v37;
  LOBYTE(v160) = 13;
  if ( v37 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Mode_title", 0xAu);
    ksgui::Label::Label((ksgui::Label *)v37, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v39 = v38;
  }
  else
  {
    v39 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v40 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v39 + 208) = v40;
  v153 = 0i64;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v41 = *(volatile signed __int32 **)(v39 + 132);
  *(std::_Ptr_base<Material> *)(v39 + 128) = v153;
  if ( v41 )
  {
    if ( !_InterlockedExchangeAdd(v41 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v41)(v41);
      if ( !_InterlockedExchangeAdd(v41 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v41 + 4))(v41);
    }
  }
  LODWORD(h) = 5;
  *(_DWORD *)(v39 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"MGU-H", LODWORD(h));
  LOBYTE(v160) = 14;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v39 + 68))(v39, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v42 = *(_DWORD *)v39;
  *(_OWORD *)(v39 + 76) = _xmm;
  (*(void (**)(int, int, int))(v42 + 28))(v39, 1117782016, 1101004800);
  v43 = *(float *)(v39 + 264);
  v44 = *(float *)(v39 + 32) - *(float *)(v39 + 28);
  v45 = *(float *)(v39 + 40) - *(float *)(v39 + 36);
  *(_DWORD *)(v39 + 36) = 1109393408;
  *(_DWORD *)(v39 + 28) = 1129775104;
  v46 = v44 + 215.0;
  v47 = v45 + 40.0;
  *(float *)(v39 + 32) = v46;
  *(float *)(v39 + 40) = v47;
  if ( v43 == 0.0 && *(float *)(v39 + 272) == 0.0 )
  {
    *(_DWORD *)(v39 + 264) = 1129775104;
    *(_DWORD *)(v39 + 272) = 1109393408;
    *(float *)(v39 + 268) = v46;
    *(float *)(v39 + 276) = v47;
  }
  _Val = v39;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v48 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v48;
  LOBYTE(v160) = 15;
  if ( v48 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"EngineBrake_title", 0x11u);
    ksgui::Label::Label((ksgui::Label *)v48, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v50 = v49;
  }
  else
  {
    v50 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v51 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v50 + 208) = v51;
  v153._Ptr = 0;
  v153._Rep = 0;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v52 = *(_DWORD *)(v50 + 132);
  *(_DWORD *)(v50 + 132) = v153._Rep;
  _Val = v52;
  *(_DWORD *)(v50 + 128) = v153._Ptr;
  if ( v52 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v52 + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(int))v52)(v52);
      v53 = _Val;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(_Val + 8), 0xFFFFFFFF) )
        (*(void (**)(int))(*(_DWORD *)v53 + 4))(v53);
    }
  }
  LODWORD(h) = 6;
  *(_DWORD *)(v50 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"ENGINE", LODWORD(h));
  LOBYTE(v160) = 16;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v50 + 68))(v50, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v54 = *(_DWORD *)v50;
  *(_OWORD *)(v50 + 76) = _xmm;
  (*(void (**)(int, int, int))(v54 + 28))(v50, 1117782016, 1101004800);
  v55 = *(float *)(v50 + 264);
  v56 = *(float *)(v50 + 32) - *(float *)(v50 + 28);
  v57 = *(float *)(v50 + 40) - *(float *)(v50 + 36);
  *(_DWORD *)(v50 + 36) = 1109393408;
  *(_DWORD *)(v50 + 28) = 1133903872;
  v58 = v56 + 300.0;
  v59 = v57 + 40.0;
  *(float *)(v50 + 32) = v58;
  *(float *)(v50 + 40) = v59;
  if ( v55 == 0.0 && *(float *)(v50 + 272) == 0.0 )
  {
    *(_DWORD *)(v50 + 264) = 1133903872;
    *(_DWORD *)(v50 + 272) = 1109393408;
    *(float *)(v50 + 268) = v58;
    *(float *)(v50 + 276) = v59;
  }
  _Val = v50;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v60 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v60;
  LOBYTE(v160) = 17;
  if ( v60 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Recovery_title2", 0xFu);
    ksgui::Label::Label((ksgui::Label *)v60, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v62 = v61;
  }
  else
  {
    v62 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v63 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v62 + 208) = v63;
  v153._Ptr = 0;
  v153._Rep = 0;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v64 = *(_DWORD *)(v62 + 132);
  *(_DWORD *)(v62 + 132) = v153._Rep;
  _Val = v64;
  *(_DWORD *)(v62 + 128) = v153._Ptr;
  if ( v64 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v64 + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(int))v64)(v64);
      v65 = _Val;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(_Val + 8), 0xFFFFFFFF) )
        (*(void (**)(int))(*(_DWORD *)v65 + 4))(v65);
    }
  }
  LODWORD(h) = 8;
  *(_DWORD *)(v62 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"RECOVERY", LODWORD(h));
  LOBYTE(v160) = 18;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v62 + 68))(v62, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v66 = *(_DWORD *)v62;
  *(_OWORD *)(v62 + 76) = _xmm;
  (*(void (**)(int, int, int))(v66 + 28))(v62, 1117782016, 1101004800);
  v67 = *(float *)(v62 + 264);
  v68 = *(float *)(v62 + 32) - *(float *)(v62 + 28);
  v69 = *(float *)(v62 + 40) - *(float *)(v62 + 36);
  *(_DWORD *)(v62 + 36) = 1112801280;
  *(_DWORD *)(v62 + 28) = 1084227584;
  v70 = v68 + 5.0;
  v71 = v69 + 53.0;
  *(float *)(v62 + 32) = v70;
  *(float *)(v62 + 40) = v71;
  if ( v67 == 0.0 && *(float *)(v62 + 272) == 0.0 )
  {
    *(_DWORD *)(v62 + 264) = 1084227584;
    *(_DWORD *)(v62 + 272) = 1112801280;
    *(float *)(v62 + 268) = v70;
    *(float *)(v62 + 276) = v71;
  }
  _Val = v62;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v72 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v72;
  LOBYTE(v160) = 19;
  if ( v72 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Delivery_title2", 0xFu);
    ksgui::Label::Label((ksgui::Label *)v72, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v74 = v73;
  }
  else
  {
    v74 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v75 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v74 + 208) = v75;
  v153._Ptr = 0;
  v153._Rep = 0;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v76 = *(_DWORD *)(v74 + 132);
  *(_DWORD *)(v74 + 132) = v153._Rep;
  _Val = v76;
  *(_DWORD *)(v74 + 128) = v153._Ptr;
  if ( v76 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v76 + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(int))v76)(v76);
      v77 = _Val;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(_Val + 8), 0xFFFFFFFF) )
        (*(void (**)(int))(*(_DWORD *)v77 + 4))(v77);
    }
  }
  LODWORD(h) = 8;
  *(_DWORD *)(v74 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DELIVERY", LODWORD(h));
  LOBYTE(v160) = 20;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v74 + 68))(v74, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v78 = *(_DWORD *)v74;
  *(_OWORD *)(v74 + 76) = _xmm;
  (*(void (**)(int, int, int))(v78 + 28))(v74, 1123024896, 1101004800);
  v79 = *(float *)(v74 + 264);
  v80 = *(float *)(v74 + 32) - *(float *)(v74 + 28);
  v81 = *(float *)(v74 + 40) - *(float *)(v74 + 36);
  *(_DWORD *)(v74 + 36) = 1112801280;
  *(_DWORD *)(v74 + 28) = 1119092736;
  v82 = v80 + 90.0;
  v83 = v81 + 53.0;
  *(float *)(v74 + 32) = v82;
  *(float *)(v74 + 40) = v83;
  if ( v79 == 0.0 && *(float *)(v74 + 272) == 0.0 )
  {
    *(_DWORD *)(v74 + 264) = 1119092736;
    *(_DWORD *)(v74 + 272) = 1112801280;
    *(float *)(v74 + 268) = v82;
    *(float *)(v74 + 276) = v83;
  }
  _Val = v74;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v84 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v84;
  LOBYTE(v160) = 21;
  if ( v84 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v150[24] = 7;
    *(_DWORD *)&v150[20] = 0;
    *(_WORD *)&v150[4] = 0;
    std::wstring::assign((std::wstring *)&v150[4], L"Mode_title2", 0xBu);
    ksgui::Label::Label((ksgui::Label *)v84, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v86 = v85;
  }
  else
  {
    v86 = 0;
  }
  LOBYTE(v160) = 8;
  h = *(float *)&smallfont._Rep;
  v87 = this->fontScale;
  *(_DWORD *)&v150[24] = smallfont._Ptr;
  *(float *)(v86 + 208) = v87;
  v153._Ptr = 0;
  v153._Rep = 0;
  std::_Ptr_base<Font>::_Reset(&v153, *(Material **)&v150[24], (std::_Ref_count_base *)LODWORD(h));
  v88 = *(_DWORD *)(v86 + 132);
  *(_DWORD *)(v86 + 132) = v153._Rep;
  _Val = v88;
  *(_DWORD *)(v86 + 128) = v153._Ptr;
  if ( v88 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v88 + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(int))v88)(v88);
      v89 = _Val;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(_Val + 8), 0xFFFFFFFF) )
        (*(void (**)(int))(*(_DWORD *)v89 + 4))(v89);
    }
  }
  LODWORD(h) = 4;
  *(_DWORD *)(v86 + 152) = 2;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"MODE", LODWORD(h));
  LOBYTE(v160) = 22;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v86 + 68))(v86, &text);
  LOBYTE(v160) = 8;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v90 = *(_DWORD *)v86;
  *(_OWORD *)(v86 + 76) = _xmm;
  (*(void (**)(int, int, int))(v90 + 28))(v86, 1117782016, 1101004800);
  v91 = *(float *)(v86 + 264);
  v92 = *(float *)(v86 + 32) - *(float *)(v86 + 28);
  v93 = *(float *)(v86 + 40) - *(float *)(v86 + 36);
  *(_DWORD *)(v86 + 36) = 1112801280;
  *(_DWORD *)(v86 + 28) = 1129775104;
  v94 = v92 + 215.0;
  v95 = v93 + 53.0;
  *(float *)(v86 + 32) = v94;
  *(float *)(v86 + 40) = v95;
  if ( v91 == 0.0 && *(float *)(v86 + 272) == 0.0 )
  {
    *(_DWORD *)(v86 + 264) = 1129775104;
    *(_DWORD *)(v86 + 272) = 1112801280;
    *(float *)(v86 + 268) = v94;
    *(float *)(v86 + 276) = v95;
  }
  _Val = v86;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v96 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v96;
  LOBYTE(v160) = 23;
  if ( v96 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v150[4], L"EngineBrake_title2");
    ksgui::Label::Label((ksgui::Label *)v96, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v98 = v97;
  }
  else
  {
    v98 = 0;
  }
  LOBYTE(v160) = 8;
  *(float *)(v98 + 208) = this->fontScale;
  std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)(v98 + 128), &smallfont);
  LODWORD(h) = L"BRAKE";
  *(_DWORD *)(v98 + 152) = 2;
  std::wstring::wstring(&result, (const wchar_t *)LODWORD(h));
  LOBYTE(v160) = 24;
  (*(void (**)(int, std::wstring *))(*(_DWORD *)v98 + 68))(v98, &result);
  LOBYTE(v160) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v99 = *(_DWORD *)v98;
  *(_OWORD *)(v98 + 76) = _xmm;
  (*(void (**)(int, int, int))(v99 + 28))(v98, 1117782016, 1101004800);
  v100 = *(float *)(v98 + 264);
  v101 = *(float *)(v98 + 32) - *(float *)(v98 + 28);
  v102 = *(float *)(v98 + 40) - *(float *)(v98 + 36);
  *(_DWORD *)(v98 + 36) = 1112801280;
  *(_DWORD *)(v98 + 28) = 1133903872;
  v103 = v101 + 300.0;
  v104 = v102 + 53.0;
  *(float *)(v98 + 32) = v103;
  *(float *)(v98 + 40) = v104;
  if ( v100 == 0.0 && *(float *)(v98 + 272) == 0.0 )
  {
    *(_DWORD *)(v98 + 264) = 1133903872;
    *(_DWORD *)(v98 + 272) = 1112801280;
    *(float *)(v98 + 268) = v103;
    *(float *)(v98 + 276) = v104;
  }
  _Val = v98;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v105 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v105;
  LOBYTE(v160) = 25;
  if ( v105 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v150[4], L"Recovery_value");
    ksgui::Label::Label((ksgui::Label *)v105, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v107 = v106;
  }
  else
  {
    v107 = 0;
  }
  LOBYTE(v160) = 8;
  v108 = this->fontScale;
  this->lblRecovery = v107;
  v107->fontScale = v108;
  std::shared_ptr<Font>::operator=(&this->lblRecovery->font, &bigfont);
  v109 = this->lblRecovery;
  LODWORD(h) = word_17BE9D8;
  v109->fontAlign = eAlignCenter;
  std::wstring::wstring(&result, (const wchar_t *)LODWORD(h));
  LOBYTE(v160) = 26;
  this->lblRecovery->setText(this->lblRecovery, &result);
  LOBYTE(v160) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ((void (*)(ksgui::Label *, int, int))this->lblRecovery->setSize)(this->lblRecovery, 1117782016, 1109393408);
  v110 = this->lblRecovery;
  v111 = v110->rectBase.left;
  v112 = v110->rect.right - v110->rect.left;
  v113 = v110->rect.bottom - v110->rect.top;
  v110->rect.top = 60.0;
  v110->rect.left = 5.0;
  v114 = v112 + 5.0;
  v115 = v113 + 60.0;
  v110->rect.right = v114;
  v110->rect.bottom = v115;
  if ( v111 == 0.0 && v110->rectBase.top == 0.0 )
  {
    v110->rectBase.left = 5.0;
    v110->rectBase.top = 60.0;
    v110->rectBase.right = v114;
    v110->rectBase.bottom = v115;
  }
  _Val = (int)this->lblRecovery;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  _Val = (int)operator new(LODWORD(h));
  LOBYTE(v160) = 27;
  if ( _Val )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v150[4], L"Delivery_value");
    ksgui::Label::Label((ksgui::Label *)_Val, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v117 = v116;
  }
  else
  {
    v117 = 0;
  }
  LOBYTE(v160) = 8;
  v118 = this->fontScale;
  this->lblDelivery = v117;
  v117->fontScale = v118;
  std::shared_ptr<Font>::operator=(&this->lblDelivery->font, &mediumfont);
  v119 = this->lblDelivery;
  LODWORD(h) = word_17BE9D8;
  v119->fontAlign = eAlignCenter;
  std::wstring::wstring(&result, (const wchar_t *)LODWORD(h));
  LOBYTE(v160) = 28;
  this->lblDelivery->setText(this->lblDelivery, &result);
  LOBYTE(v160) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->lblDelivery->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Label *, int, int))this->lblDelivery->setSize)(this->lblDelivery, 1123024896, 1106247680);
  v120 = this->lblDelivery;
  v121 = v120->rectBase.left;
  v122 = v120->rect.right - v120->rect.left;
  v123 = v120->rect.bottom - v120->rect.top;
  v120->rect.top = 75.0;
  v120->rect.left = 90.0;
  v124 = v122 + 90.0;
  v125 = v123 + 75.0;
  v120->rect.right = v124;
  v120->rect.bottom = v125;
  if ( v121 == 0.0 && v120->rectBase.top == 0.0 )
  {
    v120->rectBase.left = 90.0;
    v120->rectBase.top = 75.0;
    v120->rectBase.right = v124;
    v120->rectBase.bottom = v125;
  }
  _Val = (int)this->lblDelivery;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  _Val = (int)operator new(LODWORD(h));
  LOBYTE(v160) = 29;
  if ( _Val )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v150[4], L"Mode_value");
    ksgui::Label::Label((ksgui::Label *)_Val, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v127 = v126;
  }
  else
  {
    v127 = 0;
  }
  LOBYTE(v160) = 8;
  v128 = this->fontScale;
  this->lblMode = v127;
  v127->fontScale = v128;
  std::shared_ptr<Font>::operator=(&this->lblMode->font, &mediumfont);
  v129 = this->lblMode;
  LODWORD(h) = word_17BE9D8;
  v129->fontAlign = eAlignCenter;
  std::wstring::wstring(&result, (const wchar_t *)LODWORD(h));
  LOBYTE(v160) = 30;
  this->lblMode->setText(this->lblMode, &result);
  LOBYTE(v160) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->lblMode->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Label *, int, int))this->lblMode->setSize)(this->lblMode, 1117782016, 1106247680);
  v130 = this->lblMode;
  v131 = v130->rectBase.left;
  v132 = v130->rect.right - v130->rect.left;
  v133 = v130->rect.bottom - v130->rect.top;
  v130->rect.top = 75.0;
  v130->rect.left = 215.0;
  v134 = v132 + 215.0;
  v135 = v133 + 75.0;
  v130->rect.right = v134;
  v130->rect.bottom = v135;
  if ( v131 == 0.0 && v130->rectBase.top == 0.0 )
  {
    v130->rectBase.left = 215.0;
    v130->rectBase.top = 75.0;
    v130->rectBase.right = v134;
    v130->rectBase.bottom = v135;
  }
  _Val = (int)this->lblMode;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v136 = (Material *)operator new(LODWORD(h));
  v153._Ptr = v136;
  LOBYTE(v160) = 31;
  if ( v136 )
  {
    h = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v150[4], L"EngineBrake_value");
    ksgui::Label::Label((ksgui::Label *)v136, *(std::wstring *)&v150[4], (ksgui::GUI *)LODWORD(h));
    v138 = v137;
  }
  else
  {
    v138 = 0;
  }
  LOBYTE(v160) = 8;
  v139 = this->fontScale;
  this->lblEngineBrake = v138;
  v138->fontScale = v139;
  std::shared_ptr<Font>::operator=(&this->lblEngineBrake->font, &bigfont);
  v140 = this->lblEngineBrake;
  LODWORD(h) = word_17BE9D8;
  v140->fontAlign = eAlignCenter;
  std::wstring::wstring(&result, (const wchar_t *)LODWORD(h));
  LOBYTE(v160) = 32;
  this->lblEngineBrake->setText(this->lblEngineBrake, &result);
  LOBYTE(v160) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->lblEngineBrake->foreColor = (vec4f)_xmm;
  ((void (*)(ksgui::Label *, int, int))this->lblEngineBrake->setSize)(
    this->lblEngineBrake,
    1117782016,
    1109393408);
  v141 = this->lblEngineBrake;
  v142 = v141->rectBase.left;
  v143 = v141->rect.right - v141->rect.left;
  v144 = v141->rect.bottom - v141->rect.top;
  v141->rect.top = 60.0;
  v141->rect.left = 300.0;
  v145 = v143 + 300.0;
  v146 = v144 + 60.0;
  v141->rect.right = v145;
  v141->rect.bottom = v146;
  if ( v142 == 0.0 && v141->rectBase.top == 0.0 )
  {
    v141->rectBase.left = 300.0;
    v141->rectBase.top = 60.0;
    v141->rectBase.right = v145;
    v141->rectBase.bottom = v146;
  }
  _Val = (int)this->lblEngineBrake;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  h = 100.0;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 385.0, h);
  ((void (*)(FormMGU *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
  LOBYTE(v160) = 6;
  v147 = bigfont._Rep;
  if ( bigfont._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&bigfont._Rep->_Uses, 0xFFFFFFFF) )
    {
      v147->_Destroy(v147);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v147->_Weaks, 0xFFFFFFFF) )
        v147->_Delete_this(v147);
    }
  }
  LOBYTE(v160) = 4;
  v148 = mediumfont._Rep;
  if ( mediumfont._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&mediumfont._Rep->_Uses, 0xFFFFFFFF) )
    {
      v148->_Destroy(v148);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v148->_Weaks, 0xFFFFFFFF) )
        v148->_Delete_this(v148);
    }
  }
  LOBYTE(v160) = 0;
  v149 = smallfont._Rep;
  if ( smallfont._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&smallfont._Rep->_Uses, 0xFFFFFFFF) )
  {
    v149->_Destroy(v149);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v149->_Weaks) )
      ((void (*)(void))v149->_Delete_this)();
  }
}
void __userpurge FormMGU::render(FormMGU *this@<ecx>, void (__cdecl *a2)(void *)@<esi>, float dt)
{
  CarAvatar *v4; // ecx
  std::pair<int,std::wstring > *v5; // eax
  const std::wstring *v6; // eax
  const std::wstring *v7; // eax
  const std::wstring *v8; // eax
  const std::wstring *v9; // eax
  __int64 v10; // [esp+14h] [ebp-84h]
  float v11; // [esp+1Ch] [ebp-7Ch]
  std::pair<int,std::wstring > result; // [esp+20h] [ebp-78h] BYREF
  std::wstring text; // [esp+3Ch] [ebp-5Ch] BYREF
  std::wstring v14; // [esp+54h] [ebp-44h] BYREF
  std::wstring v15; // [esp+6Ch] [ebp-2Ch] BYREF
  int v16; // [esp+94h] [ebp-4h]

  v4 = this->avatar;
  if ( v4->physicsInfo.hasERS )
  {
    v5 = CarAvatar::getERSPower(v4, &result);
    v16 = 0;
    this->lblDelivery->setText(this->lblDelivery, &v5->second);
    v16 = -1;
    a2 = operator delete;
    if ( result.second._Myres >= 8 )
      operator delete(result.second._Bx._Ptr);
    v6 = std::to_wstring((std::wstring *)&result, this->avatar->currentERSRecovery);
    v16 = 1;
    this->lblRecovery->setText(this->lblRecovery, v6);
    v16 = -1;
    if ( result.second._Mysize >= 8 )
      operator delete((void *)result.first);
    v7 = std::to_wstring((std::wstring *)&result, this->avatar->currentEngineBrakeSetting + 1);
    v16 = 2;
    this->lblEngineBrake->setText(this->lblEngineBrake, v7);
    v16 = -1;
    if ( result.second._Mysize >= 8 )
      operator delete((void *)result.first);
    if ( this->avatar->isHeatChargingBatteries )
    {
      std::wstring::wstring((std::wstring *)&result, L"BATTERY");
      v16 = 3;
      v8 = acTranslate(&v14, (const std::wstring *)&result);
      LOBYTE(v16) = 4;
      this->lblMode->setText(this->lblMode, v8);
      if ( v14._Myres >= 8 )
        operator delete(v14._Bx._Ptr);
      v16 = -1;
      v14._Myres = 7;
      v14._Mysize = 0;
      v14._Bx._Buf[0] = 0;
      if ( result.second._Mysize >= 8 )
        operator delete((void *)result.first);
    }
    else
    {
      std::wstring::wstring(&text, L"MOTOR");
      v16 = 5;
      v9 = acTranslate(&v15, &text);
      LOBYTE(v16) = 6;
      this->lblMode->setText(this->lblMode, v9);
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
      v16 = -1;
      v15._Myres = 7;
      v15._Mysize = 0;
      v15._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
    }
  }
  ksgui::Control::render(this, (int)this, (int)a2, dt, v10, v11);
}
