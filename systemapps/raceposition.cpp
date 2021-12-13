#include "raceposition.h"
void __userpurge RacePosition::RacePosition(RacePosition *this@<ecx>, unsigned int a2@<ebx>, Sim *sim)
{
  const std::wstring *v4; // eax
  void (__cdecl *v5)(void *); // eax
  Font *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // edi
  Font *v9; // eax
  ksgui::Label *v10; // edi
  int v11; // eax
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  ksgui::Label *v18; // eax
  Font *v19; // edi
  int v20; // eax
  int v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  Font *v27; // eax
  Font *v28; // eax
  ksgui::Label *v29; // ecx
  volatile signed __int32 *v30; // edi
  Font *v31; // edi
  ksgui::Label *v32; // eax
  const std::wstring *v33; // eax
  ksgui::Label *v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  Font *v40; // eax
  Font *v41; // eax
  ksgui::Label *v42; // ecx
  volatile signed __int32 *v43; // edi
  Font *v44; // edi
  int v45; // eax
  int v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  Font *v52; // edi
  int v53; // eax
  int v54; // ecx
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  Font *v60; // eax
  Font *v61; // eax
  ksgui::Label *v62; // ecx
  volatile signed __int32 *v63; // edi
  Font *v64; // edi
  ksgui::Label *v65; // eax
  const std::wstring *v66; // eax
  ksgui::Label *v67; // ecx
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  Font *v73; // eax
  Font *v74; // eax
  ksgui::Label *v75; // ecx
  volatile signed __int32 *v76; // edi
  _BYTE v77[28]; // [esp+28h] [ebp-84h] BYREF
  float h; // [esp+44h] [ebp-68h]
  int _Val; // [esp+5Ch] [ebp-50h] BYREF
  std::shared_ptr<Font> v80; // [esp+60h] [ebp-4Ch] BYREF
  RacePosition *v81; // [esp+68h] [ebp-44h]
  std::wstring text; // [esp+6Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+84h] [ebp-28h] BYREF
  int v84; // [esp+A8h] [ebp-4h]

  LODWORD(h) = 1;
  v81 = this;
  *(_DWORD *)&v77[24] = sim->game->gui;
  *(_DWORD *)&v77[20] = 7;
  *(_DWORD *)&v77[16] = 0;
  *(_WORD *)v77 = 0;
  std::wstring::assign((std::wstring *)v77, L"RACE_POSITION", 0xDu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v77, *(ksgui::GUI **)&v77[24], SLOBYTE(h));
  v84 = 0;
  LODWORD(h) = 13;
  this->__vftable = (RacePosition_vtbl *)&RacePosition::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Race Position", LODWORD(h));
  LOBYTE(v84) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v84) = 2;
  this->formTitle->setText(this->formTitle, v4);
  v5 = operator delete;
  if ( result._Myres >= 8 )
  {
    operator delete(result._Bx._Ptr);
    v5 = operator delete;
  }
  result._Myres = 7;
  LOBYTE(v84) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    v5(text._Bx._Ptr);
  this->devApp = 0;
  this->sim = sim;
  this->raceManager = sim->raceManager;
  ksgui::Form::setSize(this, 450.0, 150.0);
  ksgui::Form::setAutoHideMode(this, 1);
  v6 = (Font *)operator new(0x18u);
  _Val = (int)v6;
  LOBYTE(v84) = 3;
  if ( v6 )
    Font::Font(v6, eFontProportional, 98.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v84) = 0;
  v80 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v80, v7);
  v8 = this->font._Rep;
  this->font = v80;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  v9 = this->font._Ptr;
  LODWORD(h) = 284;
  v9->shadowed = 1;
  v10 = (ksgui::Label *)operator new(LODWORD(h));
  _Val = (int)v10;
  LOBYTE(v84) = 4;
  if ( v10 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"-", 1u);
    ksgui::Label::Label(v10, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  LOBYTE(v84) = 0;
  this->labPosition = (ksgui::Label *)v12;
  v13 = *(float *)(v12 + 264);
  v14 = *(float *)(v12 + 32) - *(float *)(v12 + 28);
  v15 = *(float *)(v12 + 40) - *(float *)(v12 + 36);
  *(_DWORD *)(v12 + 36) = 1104150528;
  *(_DWORD *)(v12 + 28) = 1117782016;
  v16 = v14 + 80.0;
  v17 = v15 + 26.0;
  *(float *)(v12 + 32) = v16;
  *(float *)(v12 + 40) = v17;
  if ( v13 == 0.0 && *(float *)(v12 + 272) == 0.0 )
  {
    *(_DWORD *)(v12 + 264) = 1117782016;
    *(_DWORD *)(v12 + 272) = 1104150528;
    *(float *)(v12 + 268) = v16;
    *(float *)(v12 + 276) = v17;
  }
  ((void (*)(ksgui::Label *, int, int))this->labPosition->setSize)(this->labPosition, 1112014848, 1107296256);
  std::shared_ptr<Font>::operator=(&this->labPosition->font, &this->font);
  v18 = this->labPosition;
  LODWORD(h) = &_Val;
  v18->foreColor = (vec4f)_xmm;
  this->labPosition->fontAlign = eAlignRight;
  _Val = (int)this->labPosition;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v19 = (Font *)operator new(LODWORD(h));
  v80._Ptr = v19;
  LOBYTE(v84) = 5;
  if ( v19 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"/-", 2u);
    ksgui::Label::Label((ksgui::Label *)v19, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
    v21 = v20;
  }
  else
  {
    v21 = 0;
  }
  LOBYTE(v84) = 0;
  this->labTotalCars = (ksgui::Label *)v21;
  v22 = *(float *)(v21 + 264);
  v23 = *(float *)(v21 + 32) - *(float *)(v21 + 28);
  v24 = *(float *)(v21 + 40) - *(float *)(v21 + 36);
  *(_DWORD *)(v21 + 36) = 1116471296;
  *(_DWORD *)(v21 + 28) = 1124204544;
  v25 = v23 + 130.0;
  v26 = v24 + 70.0;
  *(float *)(v21 + 32) = v25;
  *(float *)(v21 + 40) = v26;
  if ( v22 == 0.0 && *(float *)(v21 + 272) == 0.0 )
  {
    *(_DWORD *)(v21 + 264) = 1124204544;
    *(_DWORD *)(v21 + 272) = 1116471296;
    *(float *)(v21 + 268) = v25;
    *(float *)(v21 + 276) = v26;
  }
  ((void (*)(ksgui::Label *, int, int))this->labTotalCars->setSize)(
    this->labTotalCars,
    1112014848,
    1107296256);
  v27 = (Font *)operator new(0x18u);
  v80._Ptr = v27;
  LOBYTE(v84) = 6;
  if ( v27 )
    Font::Font(v27, eFontProportional, 48.0, 0, 0);
  else
    v28 = 0;
  LOBYTE(v84) = 0;
  v80 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v80, v28);
  v29 = this->labTotalCars;
  v30 = (volatile signed __int32 *)v29->font._Rep;
  v29->font = v80;
  if ( v30 )
  {
    if ( !_InterlockedExchangeAdd(v30 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v30)(v30);
      if ( !_InterlockedExchangeAdd(v30 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v30 + 4))(v30);
    }
  }
  this->labTotalCars->font._Ptr->shadowed = 1;
  this->labTotalCars->fontAlign = eAlignLeft;
  this->labTotalCars->foreColor = (vec4f)_xmm;
  _Val = (int)this->labTotalCars;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v31 = (Font *)operator new(LODWORD(h));
  v80._Ptr = v31;
  v32 = 0;
  LOBYTE(v84) = 7;
  if ( v31 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"LABEL_POSITION", 0xEu);
    ksgui::Label::Label((ksgui::Label *)v31, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
  }
  LOBYTE(v84) = 0;
  this->labPosText = v32;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Pos", 3u);
  LOBYTE(v84) = 8;
  v33 = acTranslate(&result, &text);
  LOBYTE(v84) = 9;
  this->labPosText->setText(this->labPosText, v33);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v84) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v34 = this->labPosText;
  v35 = v34->rectBase.left;
  v36 = v34->rect.right - v34->rect.left;
  v37 = v34->rect.bottom - v34->rect.top;
  v34->rect.top = 30.0;
  v34->rect.left = 60.0;
  v38 = v36 + 60.0;
  v39 = v37 + 30.0;
  v34->rect.right = v38;
  v34->rect.bottom = v39;
  if ( v35 == 0.0 && v34->rectBase.top == 0.0 )
  {
    v34->rectBase.left = 60.0;
    v34->rectBase.top = 30.0;
    v34->rectBase.right = v38;
    v34->rectBase.bottom = v39;
  }
  ((void (*)(ksgui::Label *, int, int))this->labPosText->setSize)(this->labPosText, 1112014848, 1107296256);
  v40 = (Font *)operator new(0x18u);
  v80._Ptr = v40;
  LOBYTE(v84) = 10;
  if ( v40 )
    Font::Font(v40, eFontProportional, 24.0, 0, 0);
  else
    v41 = 0;
  LOBYTE(v84) = 0;
  v80 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v80, v41);
  v42 = this->labPosText;
  v43 = (volatile signed __int32 *)v42->font._Rep;
  v42->font = v80;
  if ( v43 )
  {
    if ( !_InterlockedExchangeAdd(v43 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v43)(v43);
      if ( !_InterlockedExchangeAdd(v43 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v43 + 4))(v43);
    }
  }
  this->labPosText->font._Ptr->shadowed = 1;
  this->labPosText->foreColor = (vec4f)_xmm;
  _Val = (int)this->labPosText;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  this->positionAccumulator = -1.0;
  v44 = (Font *)operator new(LODWORD(h));
  v80._Ptr = v44;
  LOBYTE(v84) = 11;
  if ( v44 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"-", 1u);
    ksgui::Label::Label((ksgui::Label *)v44, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
    v46 = v45;
  }
  else
  {
    v46 = 0;
  }
  LOBYTE(v84) = 0;
  this->labLap = (ksgui::Label *)v46;
  v47 = *(float *)(v46 + 264);
  v48 = *(float *)(v46 + 32) - *(float *)(v46 + 28);
  v49 = *(float *)(v46 + 40) - *(float *)(v46 + 36);
  *(_DWORD *)(v46 + 36) = 1104150528;
  *(_DWORD *)(v46 + 28) = 1132396544;
  v50 = v48 + 255.0;
  v51 = v49 + 26.0;
  *(float *)(v46 + 32) = v50;
  *(float *)(v46 + 40) = v51;
  if ( v47 == 0.0 && *(float *)(v46 + 272) == 0.0 )
  {
    *(_DWORD *)(v46 + 264) = 1132396544;
    *(_DWORD *)(v46 + 272) = 1104150528;
    *(float *)(v46 + 268) = v50;
    *(float *)(v46 + 276) = v51;
  }
  ((void (*)(ksgui::Label *, int, int))this->labLap->setSize)(this->labLap, 1112014848, 1107296256);
  std::shared_ptr<Font>::operator=(&this->labLap->font, &this->font);
  this->labLap->foreColor = (vec4f)_xmm;
  _Val = (int)this->labLap;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v52 = (Font *)operator new(LODWORD(h));
  v80._Ptr = v52;
  LOBYTE(v84) = 12;
  if ( v52 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"/-", 2u);
    ksgui::Label::Label((ksgui::Label *)v52, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
    v54 = v53;
  }
  else
  {
    v54 = 0;
  }
  LOBYTE(v84) = 0;
  this->labTotalLaps = (ksgui::Label *)v54;
  v55 = *(float *)(v54 + 264);
  v56 = *(float *)(v54 + 32) - *(float *)(v54 + 28);
  v57 = *(float *)(v54 + 40) - *(float *)(v54 + 36);
  *(_DWORD *)(v54 + 36) = 1116471296;
  *(_DWORD *)(v54 + 28) = 1134231552;
  v58 = v56 + 310.0;
  v59 = v57 + 70.0;
  *(float *)(v54 + 32) = v58;
  *(float *)(v54 + 40) = v59;
  if ( v55 == 0.0 && *(float *)(v54 + 272) == 0.0 )
  {
    *(_DWORD *)(v54 + 264) = 1134231552;
    *(_DWORD *)(v54 + 272) = 1116471296;
    *(float *)(v54 + 268) = v58;
    *(float *)(v54 + 276) = v59;
  }
  ((void (*)(ksgui::Label *, int, int))this->labTotalLaps->setSize)(
    this->labTotalLaps,
    1112014848,
    1107296256);
  v60 = (Font *)operator new(0x18u);
  v80._Ptr = v60;
  LOBYTE(v84) = 13;
  if ( v60 )
    Font::Font(v60, eFontProportional, 48.0, 0, 0);
  else
    v61 = 0;
  LOBYTE(v84) = 0;
  v80 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v80, v61);
  v62 = this->labTotalLaps;
  v63 = (volatile signed __int32 *)v62->font._Rep;
  v62->font = v80;
  if ( v63 )
  {
    if ( !_InterlockedExchangeAdd(v63 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v63)(v63);
      if ( !_InterlockedExchangeAdd(v63 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v63 + 4))(v63);
    }
  }
  this->labTotalLaps->font._Ptr->shadowed = 1;
  this->labTotalLaps->foreColor = (vec4f)_xmm;
  _Val = (int)this->labTotalLaps;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v64 = (Font *)operator new(LODWORD(h));
  v80._Ptr = v64;
  v65 = 0;
  LOBYTE(v84) = 14;
  if ( v64 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v77[24] = 7;
    *(_DWORD *)&v77[20] = 0;
    *(_WORD *)&v77[4] = 0;
    std::wstring::assign((std::wstring *)&v77[4], L"LABEL_LAP", 9u);
    ksgui::Label::Label((ksgui::Label *)v64, *(std::wstring *)&v77[4], (ksgui::GUI *)LODWORD(h));
  }
  LOBYTE(v84) = 0;
  this->labLapText = v65;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Lap", 3u);
  LOBYTE(v84) = 15;
  v66 = acTranslate(&result, &text);
  LOBYTE(v84) = 16;
  this->labLapText->setText(this->labLapText, v66);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v84) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v67 = this->labLapText;
  v68 = v67->rectBase.left;
  v69 = v67->rect.right - v67->rect.left;
  v70 = v67->rect.bottom - v67->rect.top;
  v67->rect.top = 30.0;
  v67->rect.left = 310.0;
  v71 = v69 + 310.0;
  v72 = v70 + 30.0;
  v67->rect.right = v71;
  v67->rect.bottom = v72;
  if ( v68 == 0.0 && v67->rectBase.top == 0.0 )
  {
    v67->rectBase.left = 310.0;
    v67->rectBase.top = 30.0;
    v67->rectBase.right = v71;
    v67->rectBase.bottom = v72;
  }
  ((void (*)(ksgui::Label *, int, int))this->labLapText->setSize)(this->labLapText, 1112014848, 1107296256);
  v73 = (Font *)operator new(0x18u);
  v80._Ptr = v73;
  LOBYTE(v84) = 17;
  if ( v73 )
    Font::Font(v73, eFontProportional, 24.0, 0, 0);
  else
    v74 = 0;
  LOBYTE(v84) = 0;
  v80 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v80, v74);
  v75 = this->labLapText;
  v76 = (volatile signed __int32 *)v75->font._Rep;
  v75->font = v80;
  if ( v76 )
  {
    if ( !_InterlockedExchangeAdd(v76 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v76)(v76);
      if ( !_InterlockedDecrement(v76 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v76 + 4))(v76);
    }
  }
  this->labLapText->font._Ptr->shadowed = 1;
  this->labLapText->foreColor = (vec4f)_xmm;
  _Val = (int)this->labLapText;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = _Val;
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(RacePosition *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
}
void RacePosition::render(RacePosition *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax
  ksgui::Label *v5; // ecx
  float v6; // xmm0_4
  ksgui::Label *v7; // ecx
  std::wostream *v8; // eax
  const std::wstring *v9; // eax
  void (__cdecl *v10)(void *); // edi
  std::wstring *v11; // eax
  signed int v12; // eax
  const std::wstring *v13; // eax
  unsigned int v14; // eax
  const std::wstring *v15; // eax
  const std::wstring *v16; // eax
  RaceManager *v17; // ecx
  long double v18; // st7
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  long double v21; // st7
  const std::wstring *v22; // eax
  const std::wstring *v23; // eax
  CarAvatar **v24; // eax
  std::wostream *v25; // eax
  const std::wstring *v26; // eax
  int v27; // [esp+18h] [ebp-338h]
  int v28; // [esp+18h] [ebp-338h]
  __int64 v29; // [esp+1Ch] [ebp-334h]
  float v30; // [esp+24h] [ebp-32Ch]
  bool v31; // [esp+2Fh] [ebp-321h]
  CarAvatar *car; // [esp+30h] [ebp-320h] BYREF
  int v33; // [esp+34h] [ebp-31Ch] BYREF
  double v34; // [esp+38h] [ebp-318h]
  float v35; // [esp+40h] [ebp-310h]
  float v36; // [esp+44h] [ebp-30Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v37; // [esp+48h] [ebp-308h] BYREF
  std::wstring text; // [esp+F8h] [ebp-258h] BYREF
  std::wstring v39; // [esp+110h] [ebp-240h] BYREF
  std::wstring result; // [esp+128h] [ebp-228h] BYREF
  std::wstring _Newstr; // [esp+140h] [ebp-210h] BYREF
  std::wstring v42; // [esp+158h] [ebp-1F8h] BYREF
  std::wstring v43; // [esp+170h] [ebp-1E0h] BYREF
  std::wstring v44; // [esp+188h] [ebp-1C8h] BYREF
  std::wstring v45; // [esp+1A0h] [ebp-1B0h] BYREF
  Session v46; // [esp+1B8h] [ebp-198h] BYREF
  std::wstring v47; // [esp+218h] [ebp-138h] BYREF
  std::wstring v48; // [esp+230h] [ebp-120h] BYREF
  std::wstring v49; // [esp+248h] [ebp-108h] BYREF
  std::wstring v50; // [esp+260h] [ebp-F0h] BYREF
  Session v51; // [esp+278h] [ebp-D8h] BYREF
  Session v52; // [esp+2D8h] [ebp-78h] BYREF
  int v53; // [esp+34Ch] [ebp-4h]

  v33 = 0;
  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  v5 = this->labPosition;
  car = v4;
  v6 = v5->rect.left;
  v7 = this->labLap;
  v35 = v6;
  v36 = v7->rect.left;
  *(_DWORD *)v37.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v37.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v37.gap68);
  v53 = 0;
  v33 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v37, &v37.gap10[8], 0);
  v53 = 1;
  *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v36 + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v37.gap10[8]);
  *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v37.gap10[64] = 0;
  *(_DWORD *)&v37.gap10[68] = 0;
  v53 = 3;
  if ( this->sim->connectedCarsCount < 1 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"-/-", 3u);
    LOBYTE(v53) = 11;
    this->labTotalCars->setText(this->labTotalCars, &text);
    LOBYTE(v53) = 3;
    v10 = operator delete;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"-", 1u);
    LOBYTE(v53) = 12;
    this->labPosition->setText(this->labPosition, &text);
    LOBYTE(v53) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  else
  {
    v27 = this->sim->connectedCarsCount;
    v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, "/");
    std::wostream::operator<<(v8, v27);
    v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &result);
    LOBYTE(v53) = 4;
    this->labTotalCars->setText(this->labTotalCars, v9);
    LOBYTE(v53) = 3;
    v10 = operator delete;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, word_17BE9D8, 0);
    LOBYTE(v53) = 5;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v37.gap10[8]);
    v11 = &text;
    if ( text._Myres >= 8 )
      v11 = (std::wstring *)text._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v37.gap10[8], v11->_Bx._Buf, text._Mysize, *(int *)&v37.gap10[68]);
    LOBYTE(v53) = 3;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v33 = RaceManager::getCurrentSession(this->raceManager, &v51)->sessionType;
    Session::~Session(&v51);
    switch ( v33 )
    {
      case 0:
      case 1:
      case 2:
        v12 = RaceManager::getCarLeaderboardPosition(this->raceManager, car);
        if ( v12 <= 0 )
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, "-");
        else
          std::wostream::operator<<(v37.gap10, v12);
        v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v43);
        LOBYTE(v53) = 7;
        this->labPosition->setText(this->labPosition, v13);
        LOBYTE(v53) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
        std::wstring::wstring(&_Newstr, word_17BE9D8);
        LOBYTE(v53) = 8;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &_Newstr);
        LOBYTE(v53) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Newstr);
        break;
      case 3:
        if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
        {
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, L"-");
        }
        else
        {
          v14 = RaceManager::getCarRealTimePosition(this->raceManager, car);
          std::wostream::operator<<(v37.gap10, v14 + 1);
        }
        v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v42);
        LOBYTE(v53) = 9;
        this->labPosition->setText(this->labPosition, v15);
        LOBYTE(v53) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v42);
        std::wstring::wstring(&v39, word_17BE9D8);
        LOBYTE(v53) = 10;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v39);
        LOBYTE(v53) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
        break;
      case 4:
        std::wstring::wstring(&result, L"1");
        LOBYTE(v53) = 6;
        this->labPosition->setText(this->labPosition, &result);
        LOBYTE(v53) = 3;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        break;
      default:
        break;
    }
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v53) = 13;
  this->labLap->setText(this->labLap, &text);
  LOBYTE(v53) = 3;
  if ( text._Myres >= 8 )
    v10(text._Bx._Ptr);
  RaceManager::getCurrentSession(this->raceManager, &v46);
  LOBYTE(v53) = 14;
  this->labTotalLaps->foreColor = (vec4f)_xmm;
  switch ( v46.sessionType )
  {
    case Pratice:
    case Qualify:
    case Hotlap:
    case TimeAttack:
      std::wstring::wstring(&text, L"Time");
      LOBYTE(v53) = 15;
      v16 = acTranslate(&_Newstr, &text);
      LOBYTE(v53) = 16;
      this->labLapText->setText(this->labLapText, v16);
      if ( _Newstr._Myres >= 8 )
        v10(_Newstr._Bx._Ptr);
      LOBYTE(v53) = 14;
      _Newstr._Myres = 7;
      _Newstr._Mysize = 0;
      _Newstr._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        v10(text._Bx._Ptr);
      v17 = this->raceManager;
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
      v18 = RaceManager::getSessionTimeLeft(v17);
      v34 = v18;
      if ( (int)v18 <= 0 )
      {
        this->labTotalLaps->foreColor = (vec4f)_xmm;
        std::wstring::wstring(&result, L"0:00");
        LOBYTE(v53) = 18;
        this->labTotalLaps->setText(this->labTotalLaps, &result);
        LOBYTE(v53) = 14;
        if ( result._Myres >= 8 )
          v10(result._Bx._Ptr);
      }
      else
      {
        v19 = timeToWString(&v44, (int)v18, 0, 0);
        LOBYTE(v53) = 17;
        this->labTotalLaps->setText(this->labTotalLaps, v19);
        LOBYTE(v53) = 14;
        if ( v44._Myres >= 8 )
          v10(v44._Bx._Ptr);
      }
      break;
    case Race:
      v31 = RaceManager::getCurrentSession(this->sim->raceManager, &v52)->isTimedRace;
      Session::~Session(&v52);
      if ( v31 )
      {
        v34 = RaceManager::getTimeToSessionStart(this->sim->raceManager);
        if ( v34 < 0.0 )
        {
          std::wstring::wstring(&v45, L"Race Time");
          LOBYTE(v53) = 19;
          v20 = acTranslate(&v50, &v45);
          LOBYTE(v53) = 20;
          this->labLapText->setText(this->labLapText, v20);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v50);
          LOBYTE(v53) = 14;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v45);
          v21 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
          v22 = timeToWString(&v48, (int)v21, 0, 0);
          LOBYTE(v53) = 21;
          this->labTotalLaps->setText(this->labTotalLaps, v22);
          LOBYTE(v53) = 14;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v48);
          this->labTotalLaps->fontAlign = eAlignCenter;
        }
      }
      else
      {
        std::wstring::wstring(&v42, L"Lap");
        LOBYTE(v53) = 22;
        v23 = acTranslate(&v49, &v42);
        LOBYTE(v53) = 23;
        this->labLapText->setText(this->labLapText, v23);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v49);
        LOBYTE(v53) = 14;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v42);
        this->labTotalLaps->fontAlign = eAlignLeft;
        RaceManager::getCurrentSession(this->sim->raceManager, &v51);
        LOBYTE(v53) = 24;
        v33 = v51.laps;
        LODWORD(v34) = v51.laps;
        v24 = (CarAvatar **)&v33;
        car = (CarAvatar *)(car->physicsState.lapCount + 1);
        if ( v51.laps >= (unsigned int)car )
          v24 = &car;
        std::wostream::operator<<(v37.gap10, *v24);
        if ( LODWORD(v34) )
        {
          v28 = LODWORD(v34);
          v25 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, "/");
          std::wostream::operator<<(v25, v28);
          v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v47);
          LOBYTE(v53) = 25;
          this->labTotalLaps->setText(this->labTotalLaps, v26);
          LOBYTE(v53) = 24;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v47);
          this->labPosition->rect.left = this->labPosition->rect.left
                                       - (float)((float)(this->labPosition->getText(this->labPosition)->_Mysize - 1)
                                               * 50.0);
          this->labLap->rect.left = this->labLap->rect.left
                                  - (float)((float)(this->labLap->getText(this->labLap)->_Mysize - 1) * 50.0);
        }
        else
        {
          std::wstring::wstring(&v43, word_17BE9D8);
          LOBYTE(v53) = 26;
          this->labTotalLaps->setText(this->labTotalLaps, &v43);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
        }
        LOBYTE(v53) = 14;
        Session::~Session(&v51);
        v10 = operator delete;
      }
      break;
    default:
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      std::wstring::assign(&v39, word_17BE9D8, 0);
      LOBYTE(v53) = 27;
      this->labLapText->setText(this->labLapText, &v39);
      LOBYTE(v53) = 14;
      if ( v39._Myres >= 8 )
        v10(v39._Bx._Ptr);
      break;
  }
  this->labLap->rect.left = v36;
  this->labPosition->rect.left = v35;
  ksgui::Control::render(this, (int)v10, (int)this, dt, v29, v30);
  if ( v46.name._Myres >= 8 )
    v10(v46.name._Bx._Ptr);
  v46.name._Myres = 7;
  v46.name._Mysize = 0;
  v46.name._Bx._Buf[0] = 0;
  if ( v46.spawSet._Myres >= 8 )
    v10(v46.spawSet._Bx._Ptr);
  v46.spawSet._Myres = 7;
  v46.spawSet._Bx._Buf[0] = 0;
  v46.spawSet._Mysize = 0;
  *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v36 + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) - 104;
  *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v37.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v37.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v37.gap68);
}
