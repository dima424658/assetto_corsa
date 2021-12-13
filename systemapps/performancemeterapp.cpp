#include "performancemeterapp.h"
void __userpurge PerformanceMeterApp::PerformanceMeterApp(PerformanceMeterApp *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *car)
{
  const std::wstring *v4; // eax
  ksgui::ProgressBar *v5; // edi
  ksgui::ProgressBar *v6; // eax
  ksgui::ProgressBar *v7; // ecx
  float v8; // xmm0_4
  ksgui::ProgressBar *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  ksgui::ProgressBar *v16; // eax
  CarAvatar *v17; // edi
  ksgui::ProgressBar *v18; // eax
  ksgui::ProgressBar *v19; // ecx
  float v20; // xmm0_4
  ksgui::ProgressBar *v21; // ecx
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  ksgui::Label *v28; // eax
  const std::wstring *v29; // eax
  ksgui::Label *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  float v35; // xmm4_4
  float v36; // xmm3_4
  Font *v37; // eax
  Font *v38; // eax
  ksgui::Label *v39; // ecx
  volatile signed __int32 *v40; // edi
  Font *v41; // edi
  ksgui::Label *v42; // eax
  ksgui::Label *v43; // ecx
  float v44; // xmm0_4
  ksgui::Label *v45; // ecx
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  float v51; // xmm3_4
  Font *v52; // eax
  Font *v53; // eax
  ksgui::Label *v54; // ecx
  volatile signed __int32 *v55; // edi
  Font *v56; // edi
  ksgui::Label *v57; // eax
  const std::wstring *v58; // eax
  ksgui::Label *v59; // ecx
  float v60; // xmm0_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm4_4
  float v65; // xmm3_4
  Font *v66; // eax
  Font *v67; // eax
  ksgui::Label *v68; // ecx
  volatile signed __int32 *v69; // edi
  Font *v70; // edi
  ksgui::Label *v71; // eax
  ksgui::Label *v72; // ecx
  float v73; // xmm0_4
  ksgui::Label *v74; // ecx
  float v75; // xmm0_4
  float v76; // xmm3_4
  float v77; // xmm4_4
  float v78; // xmm2_4
  float v79; // xmm4_4
  float v80; // xmm3_4
  Font *v81; // eax
  Font *v82; // eax
  ksgui::Label *v83; // ecx
  volatile signed __int32 *v84; // edi
  float v85; // ecx
  PerformanceMeterApp_vtbl *v86; // edx
  float v87; // xmm0_4
  _BYTE v88[28]; // [esp+28h] [ebp-88h] BYREF
  float h; // [esp+44h] [ebp-6Ch]
  int _Val; // [esp+5Ch] [ebp-54h] BYREF
  std::shared_ptr<Font> v91; // [esp+60h] [ebp-50h] BYREF
  CarAvatar *v92; // [esp+68h] [ebp-48h]
  PerformanceMeterApp *v93; // [esp+6Ch] [ebp-44h]
  std::wstring text; // [esp+70h] [ebp-40h] BYREF
  std::wstring result; // [esp+88h] [ebp-28h] BYREF
  int v96; // [esp+ACh] [ebp-4h]

  LODWORD(h) = 1;
  v93 = this;
  v92 = car;
  *(_DWORD *)&v88[24] = car->game->gui;
  *(_DWORD *)&v88[20] = 7;
  *(_DWORD *)&v88[16] = 0;
  *(_WORD *)v88 = 0;
  std::wstring::assign((std::wstring *)v88, L"PERF_METER", 0xAu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v88, *(ksgui::GUI **)&v88[24], SLOBYTE(h));
  v96 = 0;
  LODWORD(h) = 17;
  this->__vftable = (PerformanceMeterApp_vtbl *)&PerformanceMeterApp::`vftable';
  *(_DWORD *)&v88[24] = L"Performance Delta";
  this->formPosition.x = 0.0;
  this->formPosition.y = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v88[24], LODWORD(h));
  LOBYTE(v96) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v96) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v96) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->devApp = 0;
  this->car = car;
  ksgui::Form::setSize(this, 300.0, 105.0);
  LODWORD(h) = 296;
  this->autohide = 1;
  v5 = (ksgui::ProgressBar *)operator new(LODWORD(h));
  _Val = (int)v5;
  LOBYTE(v96) = 3;
  if ( v5 )
  {
    h = *(float *)&v92->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"GREEN", 5u);
    ksgui::ProgressBar::ProgressBar(v5, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v96) = 0;
  v8 = this->rect.right - this->rect.left;
  this->pbGreen = v7;
  ((void (*)(ksgui::ProgressBar *, _DWORD, int))v7->setSize)(v7, v8 * 0.33333334, 1101004800);
  v9 = this->pbGreen;
  v10 = v9->rectBase.left;
  v11 = v9->rect.right - v9->rect.left;
  v12 = v9->rect.bottom - v9->rect.top;
  v13 = (float)(this->rect.right - this->rect.left) * 0.5;
  v9->rect.top = 30.0;
  v14 = v12 + 30.0;
  v15 = v11 + v13;
  v9->rect.left = v13;
  v9->rect.bottom = v14;
  v9->rect.right = v15;
  if ( v10 == 0.0 && v9->rectBase.top == 0.0 )
  {
    v9->rectBase.left = v13;
    v9->rectBase.top = 30.0;
    v9->rectBase.right = v15;
    v9->rectBase.bottom = v14;
  }
  v16 = this->pbGreen;
  LODWORD(h) = &_Val;
  v16->foreColor = (vec4f)_xmm;
  this->pbGreen->isVertical = 0;
  this->pbGreen->borderColor = (vec4f)_xmm;
  _Val = (int)this->pbGreen;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 296;
  *(_DWORD *)(_Val + 148) = this;
  _Val = (int)operator new(LODWORD(h));
  v17 = v92;
  LOBYTE(v96) = 4;
  if ( _Val )
  {
    h = *(float *)&v92->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"RED", 3u);
    ksgui::ProgressBar::ProgressBar((ksgui::ProgressBar *)_Val, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
    v19 = v18;
  }
  else
  {
    v19 = 0;
  }
  LOBYTE(v96) = 0;
  v20 = this->rect.right - this->rect.left;
  this->pbRed = v19;
  ((void (*)(ksgui::ProgressBar *, _DWORD, int))v19->setSize)(v19, v20 * 0.33333334, 1101004800);
  v21 = this->pbRed;
  v22 = v21->rect.right - v21->rect.left;
  v23 = v21->rect.bottom - v21->rect.top;
  v24 = (float)((float)(this->rect.right - this->rect.left) * 0.5) - v22;
  v21->rect.top = 30.0;
  v25 = v21->rectBase.left;
  v26 = v23 + 30.0;
  v27 = v22 + v24;
  v21->rect.left = v24;
  v21->rect.bottom = v26;
  v21->rect.right = v27;
  if ( v25 == 0.0 && v21->rectBase.top == 0.0 )
  {
    v21->rectBase.left = v24;
    v21->rectBase.top = 30.0;
    v21->rectBase.right = v27;
    v21->rectBase.bottom = v26;
  }
  this->pbRed->foreColor = (vec4f)_xmm;
  this->pbRed->borderColor = (vec4f)_xmm;
  this->pbRed->isVertical = 0;
  this->pbRed->isInverted = 1;
  _Val = (int)this->pbRed;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  _Val = (int)operator new(LODWORD(h));
  LOBYTE(v96) = 5;
  if ( _Val )
  {
    h = *(float *)&v17->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"DELTA_LABEL", 0xBu);
    ksgui::Label::Label((ksgui::Label *)_Val, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v28 = 0;
  }
  LOBYTE(v96) = 0;
  this->deltaLabel = v28;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"DELTA", 5u);
  LOBYTE(v96) = 6;
  v29 = acTranslate(&result, &text);
  LOBYTE(v96) = 7;
  this->deltaLabel->setText(this->deltaLabel, v29);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v96) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->deltaLabel->fontAlign = eAlignLeft;
  ((void (*)(ksgui::Label *, _DWORD, int))this->deltaLabel->setSize)(
    this->deltaLabel,
    (float)(this->rect.right - this->rect.left) * 0.5,
    1109393408);
  v30 = this->deltaLabel;
  v31 = v30->rectBase.left;
  v32 = v30->rect.right - v30->rect.left;
  v33 = v30->rect.bottom - v30->rect.top;
  v34 = (float)(this->rect.right - this->rect.left) * 0.16666667;
  v30->rect.top = 54.0;
  v35 = v33 + 54.0;
  v36 = v32 + v34;
  v30->rect.left = v34;
  v30->rect.bottom = v35;
  v30->rect.right = v36;
  if ( v31 == 0.0 && v30->rectBase.top == 0.0 )
  {
    v30->rectBase.left = v34;
    v30->rectBase.top = 54.0;
    v30->rectBase.right = v36;
    v30->rectBase.bottom = v35;
  }
  v37 = (Font *)operator new(0x18u);
  v91._Ptr = v37;
  LOBYTE(v96) = 8;
  if ( v37 )
    Font::Font(v37, eFontProportional, 17.0, 0, 1);
  else
    v38 = 0;
  LOBYTE(v96) = 0;
  v91 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v91, v38);
  v39 = this->deltaLabel;
  v40 = (volatile signed __int32 *)v39->font._Rep;
  v39->font = v91;
  if ( v40 )
  {
    if ( !_InterlockedExchangeAdd(v40 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v40)(v40);
      if ( !_InterlockedExchangeAdd(v40 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v40 + 4))(v40);
    }
  }
  this->deltaLabel->foreColor = (vec4f)_xmm;
  this->deltaLabel->font._Ptr->shadowed = 0;
  _Val = (int)this->deltaLabel;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v41 = (Font *)operator new(LODWORD(h));
  v91._Ptr = v41;
  LOBYTE(v96) = 9;
  if ( v41 )
  {
    h = *(float *)&v92->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"LAB_TEXT", 8u);
    ksgui::Label::Label((ksgui::Label *)v41, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
    v43 = v42;
  }
  else
  {
    v43 = 0;
  }
  LOBYTE(v96) = 0;
  v44 = this->rect.right - this->rect.left;
  this->labText = v43;
  ((void (*)(ksgui::Label *, _DWORD, int))v43->setSize)(v43, (float)(v44 * 0.33333334) - 2.0, 1109393408);
  v45 = this->labText;
  v46 = v45->rectBase.left;
  v47 = v45->rect.right - v45->rect.left;
  v48 = v45->rect.bottom - v45->rect.top;
  v49 = (float)(this->rect.right - this->rect.left) * 0.5;
  v45->rect.top = 53.0;
  v50 = v48 + 53.0;
  v51 = v47 + v49;
  v45->rect.left = v49;
  v45->rect.bottom = v50;
  v45->rect.right = v51;
  if ( v46 == 0.0 && v45->rectBase.top == 0.0 )
  {
    v45->rectBase.left = v49;
    v45->rectBase.top = 53.0;
    v45->rectBase.right = v51;
    v45->rectBase.bottom = v50;
  }
  v52 = (Font *)operator new(0x18u);
  v91._Ptr = v52;
  LOBYTE(v96) = 10;
  if ( v52 )
    Font::Font(v52, eFontMonospaced, 22.0, 0, 0);
  else
    v53 = 0;
  LOBYTE(v96) = 0;
  v91 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v91, v53);
  v54 = this->labText;
  v55 = (volatile signed __int32 *)v54->font._Rep;
  v54->font = v91;
  if ( v55 )
  {
    if ( !_InterlockedExchangeAdd(v55 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v55)(v55);
      if ( !_InterlockedExchangeAdd(v55 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v55 + 4))(v55);
    }
  }
  this->labText->fontAlign = eAlignRight;
  this->labText->drawBackground = 0;
  this->labText->font._Ptr->shadowed = 0;
  _Val = (int)this->labText;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v56 = (Font *)operator new(LODWORD(h));
  v91._Ptr = v56;
  LOBYTE(v96) = 11;
  if ( v56 )
  {
    h = *(float *)&v92->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"ESTIMATED_LABEL", 0xFu);
    ksgui::Label::Label((ksgui::Label *)v56, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v57 = 0;
  }
  LOBYTE(v96) = 0;
  this->estimatedLabel = v57;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"ESTIMATED", 9u);
  LOBYTE(v96) = 12;
  v58 = acTranslate(&result, &text);
  LOBYTE(v96) = 13;
  this->estimatedLabel->setText(this->estimatedLabel, v58);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v96) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->estimatedLabel->fontAlign = eAlignLeft;
  ((void (*)(ksgui::Label *, _DWORD, int))this->estimatedLabel->setSize)(
    this->estimatedLabel,
    (float)(this->rect.right - this->rect.left) * 0.5,
    1109393408);
  v59 = this->estimatedLabel;
  v60 = v59->rectBase.left;
  v61 = v59->rect.right - v59->rect.left;
  v62 = v59->rect.bottom - v59->rect.top;
  v63 = (float)(this->rect.right - this->rect.left) * 0.16666667;
  v59->rect.top = 78.0;
  v64 = v62 + 78.0;
  v65 = v61 + v63;
  v59->rect.left = v63;
  v59->rect.bottom = v64;
  v59->rect.right = v65;
  if ( v60 == 0.0 && v59->rectBase.top == 0.0 )
  {
    v59->rectBase.left = v63;
    v59->rectBase.top = 78.0;
    v59->rectBase.right = v65;
    v59->rectBase.bottom = v64;
  }
  v66 = (Font *)operator new(0x18u);
  v91._Ptr = v66;
  LOBYTE(v96) = 14;
  if ( v66 )
    Font::Font(v66, eFontProportional, 15.0, 0, 0);
  else
    v67 = 0;
  LOBYTE(v96) = 0;
  v91 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v91, v67);
  v68 = this->estimatedLabel;
  v69 = (volatile signed __int32 *)v68->font._Rep;
  v68->font = v91;
  if ( v69 )
  {
    if ( !_InterlockedExchangeAdd(v69 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v69)(v69);
      if ( !_InterlockedExchangeAdd(v69 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v69 + 4))(v69);
    }
  }
  this->estimatedLabel->foreColor = (vec4f)_xmm;
  this->estimatedLabel->font._Ptr->shadowed = 0;
  _Val = (int)this->estimatedLabel;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 284;
  *(_DWORD *)(_Val + 148) = this;
  v70 = (Font *)operator new(LODWORD(h));
  v91._Ptr = v70;
  LOBYTE(v96) = 15;
  if ( v70 )
  {
    h = *(float *)&v92->game->gui;
    *(_DWORD *)&v88[24] = 7;
    *(_DWORD *)&v88[20] = 0;
    *(_WORD *)&v88[4] = 0;
    std::wstring::assign((std::wstring *)&v88[4], L"LAB_PRJ", 7u);
    ksgui::Label::Label((ksgui::Label *)v70, *(std::wstring *)&v88[4], (ksgui::GUI *)LODWORD(h));
    v72 = v71;
  }
  else
  {
    v72 = 0;
  }
  LOBYTE(v96) = 0;
  v73 = this->rect.right - this->rect.left;
  this->labProjTime = v72;
  ((void (*)(ksgui::Label *, _DWORD, int))v72->setSize)(v72, (float)(v73 * 0.33333334) - 2.0, 1109393408);
  v74 = this->labProjTime;
  v75 = v74->rectBase.left;
  v76 = v74->rect.right - v74->rect.left;
  v77 = v74->rect.bottom - v74->rect.top;
  v78 = (float)(this->rect.right - this->rect.left) * 0.5;
  v74->rect.top = 78.0;
  v79 = v77 + 78.0;
  v80 = v76 + v78;
  v74->rect.left = v78;
  v74->rect.bottom = v79;
  v74->rect.right = v80;
  if ( v75 == 0.0 && v74->rectBase.top == 0.0 )
  {
    v74->rectBase.left = v78;
    v74->rectBase.top = 78.0;
    v74->rectBase.right = v80;
    v74->rectBase.bottom = v79;
  }
  v81 = (Font *)operator new(0x18u);
  v91._Ptr = v81;
  LOBYTE(v96) = 16;
  if ( v81 )
    Font::Font(v81, eFontMonospaced, 17.0, 0, 0);
  else
    v82 = 0;
  LOBYTE(v96) = 0;
  v91 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v91, v82);
  v83 = this->labProjTime;
  v84 = (volatile signed __int32 *)v83->font._Rep;
  v83->font = v91;
  if ( v84 )
  {
    if ( !_InterlockedExchangeAdd(v84 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v84)(v84);
      if ( !_InterlockedDecrement(v84 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v84 + 4))(v84);
    }
  }
  this->labProjTime->fontAlign = eAlignRight;
  this->labProjTime->drawBackground = 0;
  this->labProjTime->foreColor = (vec4f)_xmm;
  this->labProjTime->font._Ptr->shadowed = 0;
  _Val = (int)this->labProjTime;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  h = v85;
  *(_DWORD *)(_Val + 148) = this;
  v86 = this->__vftable;
  v87 = this->scaleMult;
  this->formPosition.y = 300.0;
  this->isFormVisible = 1;
  v86->scaleByMult(this, COERCE_FLOAT(LODWORD(v87)));
}
void __userpurge PerformanceMeterApp::render(PerformanceMeterApp *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  CarAvatar *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  PerformanceMeterApp_vtbl *v9; // eax
  PerformanceMeterApp_vtbl *v10; // eax
  float v11; // xmm1_4
  ksgui::Label *v12; // eax
  __int128 v13; // xmm0
  const std::wstring *v14; // eax
  CarAvatar *v15; // ecx
  unsigned int v16; // eax
  const std::wstring *v17; // eax
  __int64 v18; // [esp+2Ch] [ebp-74h]
  float v19; // [esp+34h] [ebp-6Ch]
  __int64 x; // [esp+40h] [ebp-60h] BYREF
  int v21[2]; // [esp+48h] [ebp-58h] BYREF
  std::wstring result; // [esp+50h] [ebp-50h] BYREF
  std::wstring v23; // [esp+74h] [ebp-2Ch] BYREF
  int v24; // [esp+9Ch] [ebp-4h]

  v4 = Sim::getFocusedCarIndex(this->car->sim);
  v5 = Sim::getCar(this->car->sim, v4);
  v6 = FLOAT_1_0;
  this->car = v5;
  v7 = v5->physicsState.performanceMeterSpeedDiffMS * 0.17999999;
  if ( v7 <= 1.0 )
  {
    if ( v7 < 0.0 )
      v7 = 0.0;
  }
  else
  {
    v7 = FLOAT_1_0;
  }
  this->pbGreen->value = v7;
  v8 = this->car->physicsState.performanceMeterSpeedDiffMS * -0.17999999;
  if ( v8 <= 1.0 )
  {
    if ( v8 >= 0.0 )
      v6 = this->car->physicsState.performanceMeterSpeedDiffMS * -0.17999999;
    else
      v6 = 0.0;
  }
  this->pbRed->value = v6;
  if ( this->car->sim->microSectors->enabled )
  {
    v9 = this->__vftable;
    result._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_loadu_si128((const __m128i *)&this->rect);
    v9->getWorldRect(this, (ksgui::ksRect *)&result);
    v10 = this->__vftable;
    v21[0] = 0;
    *(float *)&v21[1] = *(float *)&result._Bx._Alias[12] - *(float *)&result._Bx._Alias[8];
    v10->localToWorld(this, (vec2f *)&x, (const vec2f *)v21);
    MicroSectors::drawSectors(
      this->car->sim->microSectors,
      this->gui->graphics->gl,
      0,
      *(float *)&x,
      *((float *)&x + 1),
      *(float *)&result._Bx._Alias[4] - *(float *)&result._Bx._Ptr,
      (float)((float)(*(float *)&result._Bx._Alias[12] - *(float *)&result._Bx._Alias[8]) * 0.014285714) * 10.0,
      (vec4f)_mm_loadu_si128((const __m128i *)&this->backColor));
  }
  ksgui::Control::render(this, a2, (int)this, dt, v18, v19);
  v11 = this->car->physicsState.performanceMeter;
  v12 = this->labText;
  if ( v11 == 0.0 )
  {
    v12->foreColor = (vec4f)_xmm;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"0.000", 5u);
    v24 = 0;
    this->labText->setText(this->labText, &result);
  }
  else
  {
    if ( v11 <= 0.0 )
      v13 = _xmm;
    else
      v13 = _xmm;
    v12->foreColor = (vec4f)v13;
    v14 = timeToDiffString(&result, (int)(float)(this->car->physicsState.performanceMeter * 1000.0), 3);
    v24 = 1;
    this->labText->setText(this->labText, v14);
  }
  v24 = -1;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v15 = this->car;
  v16 = v15->physicsState.bestLap;
  if ( v16 )
  {
    v17 = timeToString(
            &result,
            (unsigned int)(float)((float)(v15->physicsState.performanceMeter * 1000.0) + (float)v16),
            3);
    v24 = 2;
    this->labProjTime->setText(this->labProjTime, v17);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  else
  {
    v23._Myres = 7;
    v23._Mysize = 0;
    v23._Bx._Buf[0] = 0;
    std::wstring::assign(&v23, L"---", 3u);
    v24 = 3;
    this->labProjTime->setText(this->labProjTime, &v23);
    if ( v23._Myres >= 8 )
      operator delete(v23._Bx._Ptr);
  }
}
