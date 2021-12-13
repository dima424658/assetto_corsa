#include "formgamestats.h"
void FormGameStats::FormGameStats(FormGameStats *this, Game *igame)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  ksgui::ConnectedLabel *v5; // esi
  int v6; // eax
  int v7; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  ksgui::ConnectedLabel *v13; // esi
  int v14; // eax
  int v15; // esi
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  ksgui::ConnectedLabel *v21; // esi
  int v22; // eax
  int v23; // esi
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  ksgui::ConnectedLabel *v29; // esi
  int v30; // eax
  int v31; // esi
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  ksgui::ConnectedLabel *v37; // esi
  int v38; // eax
  int v39; // esi
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  ksgui::ConnectedLabel *v45; // esi
  int v46; // eax
  int v47; // esi
  float v48; // xmm0_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  ksgui::ConnectedLabel *v53; // esi
  int v54; // eax
  int v55; // esi
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  std::wstring v61; // [esp+1Ch] [ebp-80h] BYREF
  float w; // [esp+34h] [ebp-68h]
  float h; // [esp+38h] [ebp-64h]
  int _Val; // [esp+50h] [ebp-4Ch] BYREF
  ksgui::ConnectedLabel *v65; // [esp+54h] [ebp-48h]
  FormGameStats *v66; // [esp+58h] [ebp-44h]
  std::wstring text; // [esp+5Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+74h] [ebp-28h] BYREF
  int v69; // [esp+98h] [ebp-4h]

  v3 = 0;
  h = 0.0;
  _Val = 0;
  v66 = this;
  w = *(float *)&igame->gui;
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  std::wstring::assign(&v61, L"GAME_STATS", 0xAu);
  ksgui::Form::Form(this, 0, v61, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v69 = 0;
  LODWORD(h) = 14;
  this->__vftable = (FormGameStats_vtbl *)&FormGameStats::`vftable';
  LODWORD(w) = L"Graphics stats";
  this->game = igame;
  this->cpuTime = 0.0;
  this->renderAudioTime = 0.0;
  this->cpuDiff = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, (const wchar_t *)LODWORD(w), LODWORD(h));
  LOBYTE(v69) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v69) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v69) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Form::setSize(this, 100.0, 200.0);
  v5 = (ksgui::ConnectedLabel *)operator new(0x158u);
  v65 = v5;
  LOBYTE(v69) = 3;
  if ( v5 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"UPD", 3u);
    LOBYTE(v69) = 4;
    LODWORD(h) = &this->updateTime;
    w = *(float *)&this->gui;
    v3 = 1;
    _Val = 1;
    ksgui::ConnectedLabel::ConnectedLabel(v5, &text, (ksgui::GUI *)LODWORD(w), &this->updateTime);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v69 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v8 = *(float *)(v7 + 264);
  v9 = *(float *)(v7 + 32) - *(float *)(v7 + 28);
  v10 = *(float *)(v7 + 40) - *(float *)(v7 + 36);
  *(_DWORD *)(v7 + 36) = 1107296256;
  *(_DWORD *)(v7 + 28) = 1084227584;
  v11 = v9 + 5.0;
  v12 = v10 + 32.0;
  *(float *)(v7 + 32) = v11;
  *(float *)(v7 + 40) = v12;
  if ( v8 == 0.0 && *(float *)(v7 + 272) == 0.0 )
  {
    *(_DWORD *)(v7 + 264) = 1084227584;
    *(_DWORD *)(v7 + 272) = 1107296256;
    *(float *)(v7 + 268) = v11;
    *(float *)(v7 + 276) = v12;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v7 + 28))(v7, 1112014848, 1107296256);
  _Val = v7;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v13 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v13;
  LOBYTE(v69) = 6;
  if ( v13 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"REND", 4u);
    LOBYTE(v69) = 7;
    LODWORD(h) = &this->renderTime;
    w = *(float *)&this->gui;
    v3 |= 2u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v13, &text, (ksgui::GUI *)LODWORD(w), &this->renderTime);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v69 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v16 = *(float *)(v15 + 264);
  v17 = *(float *)(v15 + 32) - *(float *)(v15 + 28);
  v18 = *(float *)(v15 + 40) - *(float *)(v15 + 36);
  *(_DWORD *)(v15 + 36) = 1112539136;
  *(_DWORD *)(v15 + 28) = 1084227584;
  v19 = v17 + 5.0;
  v20 = v18 + 52.0;
  *(float *)(v15 + 32) = v19;
  *(float *)(v15 + 40) = v20;
  if ( v16 == 0.0 && *(float *)(v15 + 272) == 0.0 )
  {
    *(_DWORD *)(v15 + 264) = 1084227584;
    *(_DWORD *)(v15 + 272) = 1112539136;
    *(float *)(v15 + 268) = v19;
    *(float *)(v15 + 276) = v20;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v15 + 28))(v15, 1112014848, 1107296256);
  _Val = v15;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v21 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v21;
  LOBYTE(v69) = 9;
  if ( v21 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"HUD", 3u);
    LOBYTE(v69) = 10;
    LODWORD(h) = &this->hudRenderTime;
    w = *(float *)&this->gui;
    v3 |= 4u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v21, &text, (ksgui::GUI *)LODWORD(w), &this->hudRenderTime);
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  v69 = 0;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v24 = *(float *)(v23 + 264);
  v25 = *(float *)(v23 + 32) - *(float *)(v23 + 28);
  v26 = *(float *)(v23 + 40) - *(float *)(v23 + 36);
  *(_DWORD *)(v23 + 36) = 1116733440;
  *(_DWORD *)(v23 + 28) = 1084227584;
  v27 = v25 + 5.0;
  v28 = v26 + 72.0;
  *(float *)(v23 + 32) = v27;
  *(float *)(v23 + 40) = v28;
  if ( v24 == 0.0 && *(float *)(v23 + 272) == 0.0 )
  {
    *(_DWORD *)(v23 + 264) = 1084227584;
    *(_DWORD *)(v23 + 272) = 1116733440;
    *(float *)(v23 + 268) = v27;
    *(float *)(v23 + 276) = v28;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v23 + 28))(v23, 1112014848, 1107296256);
  _Val = v23;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v29 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v29;
  LOBYTE(v69) = 12;
  if ( v29 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"PHYS", 4u);
    LOBYTE(v69) = 13;
    LODWORD(h) = &this->physicsTime;
    w = *(float *)&this->gui;
    v3 |= 8u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v29, &text, (ksgui::GUI *)LODWORD(w), &this->physicsTime);
    v31 = v30;
  }
  else
  {
    v31 = 0;
  }
  v69 = 0;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v32 = *(float *)(v31 + 264);
  v33 = *(float *)(v31 + 32) - *(float *)(v31 + 28);
  v34 = *(float *)(v31 + 40) - *(float *)(v31 + 36);
  *(_DWORD *)(v31 + 36) = 1119354880;
  *(_DWORD *)(v31 + 28) = 1084227584;
  v35 = v33 + 5.0;
  v36 = v34 + 92.0;
  *(float *)(v31 + 32) = v35;
  *(float *)(v31 + 40) = v36;
  if ( v32 == 0.0 && *(float *)(v31 + 272) == 0.0 )
  {
    *(_DWORD *)(v31 + 264) = 1084227584;
    *(_DWORD *)(v31 + 272) = 1119354880;
    *(float *)(v31 + 268) = v35;
    *(float *)(v31 + 276) = v36;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v31 + 28))(v31, 1112014848, 1107296256);
  _Val = v31;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v37 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v37;
  LOBYTE(v69) = 15;
  if ( v37 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"CPU", 3u);
    LOBYTE(v69) = 16;
    LODWORD(h) = &this->cpuTime;
    w = *(float *)&this->gui;
    v3 |= 0x10u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v37, &text, (ksgui::GUI *)LODWORD(w), &this->cpuTime);
    v39 = v38;
  }
  else
  {
    v39 = 0;
  }
  v69 = 0;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v40 = *(float *)(v39 + 264);
  v41 = *(float *)(v39 + 32) - *(float *)(v39 + 28);
  v42 = *(float *)(v39 + 40) - *(float *)(v39 + 36);
  *(_DWORD *)(v39 + 36) = 1121976320;
  *(_DWORD *)(v39 + 28) = 1084227584;
  v43 = v41 + 5.0;
  v44 = v42 + 112.0;
  *(float *)(v39 + 32) = v43;
  *(float *)(v39 + 40) = v44;
  if ( v40 == 0.0 && *(float *)(v39 + 272) == 0.0 )
  {
    *(_DWORD *)(v39 + 264) = 1084227584;
    *(_DWORD *)(v39 + 272) = 1121976320;
    *(float *)(v39 + 268) = v43;
    *(float *)(v39 + 276) = v44;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v39 + 28))(v39, 1112014848, 1107296256);
  _Val = v39;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v45 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v45;
  LOBYTE(v69) = 18;
  if ( v45 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"AUDIO", 5u);
    LOBYTE(v69) = 19;
    LODWORD(h) = &this->renderAudioTime;
    w = *(float *)&this->gui;
    v3 |= 0x20u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v45, &text, (ksgui::GUI *)LODWORD(w), &this->renderAudioTime);
    v47 = v46;
  }
  else
  {
    v47 = 0;
  }
  v69 = 0;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v48 = *(float *)(v47 + 264);
  v49 = *(float *)(v47 + 32) - *(float *)(v47 + 28);
  v50 = *(float *)(v47 + 40) - *(float *)(v47 + 36);
  *(_DWORD *)(v47 + 36) = 1124335616;
  *(_DWORD *)(v47 + 28) = 1084227584;
  v51 = v49 + 5.0;
  v52 = v50 + 132.0;
  *(float *)(v47 + 32) = v51;
  *(float *)(v47 + 40) = v52;
  if ( v48 == 0.0 && *(float *)(v47 + 272) == 0.0 )
  {
    *(_DWORD *)(v47 + 264) = 1084227584;
    *(_DWORD *)(v47 + 272) = 1124335616;
    *(float *)(v47 + 268) = v51;
    *(float *)(v47 + 276) = v52;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v47 + 28))(v47, 1112014848, 1107296256);
  _Val = v47;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 344;
  *(_DWORD *)(_Val + 148) = this;
  v53 = (ksgui::ConnectedLabel *)operator new(LODWORD(h));
  v65 = v53;
  LOBYTE(v69) = 21;
  if ( v53 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DIFF", 4u);
    LOBYTE(v69) = 22;
    LODWORD(h) = &this->cpuDiff;
    w = *(float *)&this->gui;
    v3 |= 0x40u;
    _Val = v3;
    ksgui::ConnectedLabel::ConnectedLabel(v53, &text, (ksgui::GUI *)LODWORD(w), &this->cpuDiff);
    v55 = v54;
  }
  else
  {
    v55 = 0;
  }
  v69 = 0;
  if ( (v3 & 0x40) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v56 = *(float *)(v55 + 264);
  v57 = *(float *)(v55 + 32) - *(float *)(v55 + 28);
  v58 = *(float *)(v55 + 40) - *(float *)(v55 + 36);
  *(_DWORD *)(v55 + 36) = 1125646336;
  *(_DWORD *)(v55 + 28) = 1084227584;
  v59 = v57 + 5.0;
  v60 = v58 + 152.0;
  *(float *)(v55 + 32) = v59;
  *(float *)(v55 + 40) = v60;
  if ( v56 == 0.0 && *(float *)(v55 + 272) == 0.0 )
  {
    *(_DWORD *)(v55 + 264) = 1084227584;
    *(_DWORD *)(v55 + 272) = 1125646336;
    *(float *)(v55 + 268) = v59;
    *(float *)(v55 + 276) = v60;
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v55 + 28))(v55, 1112014848, 1107296256);
  _Val = v55;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  this->physicsTime = 0.0;
  this->updateTime = 0.0;
  this->renderTime = 0.0;
  this->hudRenderTime = 0.0;
  this->physicsAvatar = 0;
}
