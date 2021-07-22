#include "acdcarengineer.h
void ACDCarEngineer::ACDCarEngineer(ACDCarEngineer *this, Sim *asim)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  ksgui::Control *v5; // ebp
  ksgui::Control *v6; // eax
  ksgui::Control *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  ksgui::Control *v13; // ebp
  ksgui::Control *v14; // eax
  ksgui::Control *v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  ksgui::Control *v21; // ebp
  ksgui::Control *v22; // eax
  ksgui::Control *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  ksgui::Control *v29; // ebp
  ksgui::Control *v30; // eax
  ksgui::Control *v31; // ecx
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  ksgui::Control *v37; // ebp
  ksgui::Control *v38; // eax
  ksgui::Control *v39; // ecx
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  ksgui::Control *v45; // ebp
  ksgui::Control *v46; // eax
  ksgui::Control *v47; // ecx
  float v48; // xmm0_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  std::wstring v53; // [esp+20h] [ebp-80h] BYREF
  float w; // [esp+38h] [ebp-68h]
  float h; // [esp+3Ch] [ebp-64h]
  int _Val; // [esp+54h] [ebp-4Ch] BYREF
  ksgui::Control *v57; // [esp+58h] [ebp-48h]
  ACDCarEngineer *v58; // [esp+5Ch] [ebp-44h]
  std::wstring text; // [esp+60h] [ebp-40h] BYREF
  std::wstring result; // [esp+78h] [ebp-28h] BYREF
  int v61; // [esp+9Ch] [ebp-4h]

  v3 = 0;
  _Val = 0;
  h = 0.0;
  v58 = this;
  w = *(float *)&asim->game->gui;
  v53._Myres = 7;
  v53._Mysize = 0;
  v53._Bx._Buf[0] = 0;
  std::wstring::assign(&v53, L"ACDCarEngineer", 0xEu);
  ksgui::Form::Form(this, 0, v53, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v61 = 0;
  LODWORD(h) = 12;
  this->__vftable = (ACDCarEngineer_vtbl *)&ACDCarEngineer::`vftable';
  LODWORD(w) = L"Car engineer";
  this->sim = asim;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, (const wchar_t *)LODWORD(w), LODWORD(h));
  LOBYTE(v61) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v61) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v61) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  LODWORD(h) = 280;
  this->devApp = 1;
  v5 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v5;
  v6 = 0;
  LOBYTE(v61) = 3;
  if ( v5 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"CAR_MASS", 8u);
    LOBYTE(v61) = 4;
    h = *(float *)&this->gui;
    v3 = 1;
    _Val = 1;
    ksgui::Control::Control(v5, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->carMass = v6;
  v61 = 0;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v7 = this->carMass;
  v8 = v7->rectBase.left;
  v9 = v7->rect.right - v7->rect.left;
  v10 = v7->rect.bottom - v7->rect.top;
  v7->rect.top = 50.0;
  v7->rect.left = 10.0;
  v11 = v9 + 10.0;
  v12 = v10 + 50.0;
  v7->rect.right = v11;
  v7->rect.bottom = v12;
  if ( v8 == 0.0 && v7->rectBase.top == 0.0 )
  {
    v7->rectBase.left = 10.0;
    v7->rectBase.top = 50.0;
    v7->rectBase.right = v11;
    v7->rectBase.bottom = v12;
  }
  ((void (*)(ksgui::Control *, int, int))this->carMass->setSize)(this->carMass, 1138819072, 1101004800);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"CAR MASS:", 9u);
  LOBYTE(v61) = 6;
  this->carMass->setText(this->carMass, &text);
  LOBYTE(v61) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  _Val = (int)this->carMass;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v13 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v13;
  v14 = 0;
  LOBYTE(v61) = 7;
  if ( v13 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SPRUNG_WEIGHT", 0xDu);
    LOBYTE(v61) = 8;
    h = *(float *)&this->gui;
    v3 |= 2u;
    _Val = v3;
    ksgui::Control::Control(v13, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->sprungWeight = v14;
  v61 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v15 = this->sprungWeight;
  v16 = v15->rectBase.left;
  v17 = v15->rect.right - v15->rect.left;
  v18 = v15->rect.bottom - v15->rect.top;
  v15->rect.top = 75.0;
  v15->rect.left = 10.0;
  v19 = v17 + 10.0;
  v20 = v18 + 75.0;
  v15->rect.right = v19;
  v15->rect.bottom = v20;
  if ( v16 == 0.0 && v15->rectBase.top == 0.0 )
  {
    v15->rectBase.left = 10.0;
    v15->rectBase.top = 75.0;
    v15->rectBase.right = v19;
    v15->rectBase.bottom = v20;
  }
  ((void (*)(ksgui::Control *, int, int))this->sprungWeight->setSize)(
    this->sprungWeight,
    1138819072,
    1101004800);
  _Val = (int)this->sprungWeight;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v21 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v21;
  v22 = 0;
  LOBYTE(v61) = 10;
  if ( v21 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"UNSPRUNG_WEIGHT", 0xFu);
    LOBYTE(v61) = 11;
    h = *(float *)&this->gui;
    v3 |= 4u;
    _Val = v3;
    ksgui::Control::Control(v21, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->unsprungWeight = v22;
  v61 = 0;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v23 = this->unsprungWeight;
  v24 = v23->rectBase.left;
  v25 = v23->rect.right - v23->rect.left;
  v26 = v23->rect.bottom - v23->rect.top;
  v23->rect.top = 100.0;
  v23->rect.left = 10.0;
  v27 = v25 + 10.0;
  v28 = v26 + 100.0;
  v23->rect.right = v27;
  v23->rect.bottom = v28;
  if ( v24 == 0.0 && v23->rectBase.top == 0.0 )
  {
    v23->rectBase.left = 10.0;
    v23->rectBase.top = 100.0;
    v23->rectBase.right = v27;
    v23->rectBase.bottom = v28;
  }
  ((void (*)(ksgui::Control *, int, int))this->unsprungWeight->setSize)(
    this->unsprungWeight,
    1138819072,
    1101004800);
  _Val = (int)this->unsprungWeight;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v29 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v29;
  v30 = 0;
  LOBYTE(v61) = 13;
  if ( v29 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"FREQUENCY", 9u);
    LOBYTE(v61) = 14;
    h = *(float *)&this->gui;
    v3 |= 8u;
    _Val = v3;
    ksgui::Control::Control(v29, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->frequency = v30;
  v61 = 0;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v31 = this->frequency;
  v32 = v31->rectBase.left;
  v33 = v31->rect.right - v31->rect.left;
  v34 = v31->rect.bottom - v31->rect.top;
  v31->rect.top = 125.0;
  v31->rect.left = 10.0;
  v35 = v33 + 10.0;
  v36 = v34 + 125.0;
  v31->rect.right = v35;
  v31->rect.bottom = v36;
  if ( v32 == 0.0 && v31->rectBase.top == 0.0 )
  {
    v31->rectBase.left = 10.0;
    v31->rectBase.top = 125.0;
    v31->rectBase.right = v35;
    v31->rectBase.bottom = v36;
  }
  ((void (*)(ksgui::Control *, int, int))this->frequency->setSize)(this->frequency, 1138819072, 1101004800);
  _Val = (int)this->frequency;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v37 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v37;
  v38 = 0;
  LOBYTE(v61) = 16;
  if ( v37 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DAMP F", 6u);
    LOBYTE(v61) = 17;
    h = *(float *)&this->gui;
    v3 |= 0x10u;
    _Val = v3;
    ksgui::Control::Control(v37, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->damp = v38;
  v61 = 0;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v39 = this->damp;
  v40 = v39->rectBase.left;
  v41 = v39->rect.right - v39->rect.left;
  v42 = v39->rect.bottom - v39->rect.top;
  v39->rect.top = 150.0;
  v39->rect.left = 10.0;
  v43 = v41 + 10.0;
  v44 = v42 + 150.0;
  v39->rect.right = v43;
  v39->rect.bottom = v44;
  if ( v40 == 0.0 && v39->rectBase.top == 0.0 )
  {
    v39->rectBase.left = 10.0;
    v39->rectBase.top = 150.0;
    v39->rectBase.right = v43;
    v39->rectBase.bottom = v44;
  }
  ((void (*)(ksgui::Control *, int, int))this->damp->setSize)(this->damp, 1138819072, 1101004800);
  _Val = (int)this->damp;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = 280;
  *(_DWORD *)(_Val + 148) = this;
  v45 = (ksgui::Control *)operator new(LODWORD(h));
  v57 = v45;
  v46 = 0;
  LOBYTE(v61) = 19;
  if ( v45 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"DAMP R", 6u);
    LOBYTE(v61) = 20;
    h = *(float *)&this->gui;
    v3 |= 0x20u;
    _Val = v3;
    ksgui::Control::Control(v45, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->dampRear = v46;
  v61 = 0;
  if ( (v3 & 0x20) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v47 = this->dampRear;
  v48 = v47->rectBase.left;
  v49 = v47->rect.right - v47->rect.left;
  v50 = v47->rect.bottom - v47->rect.top;
  v47->rect.top = 175.0;
  v47->rect.left = 10.0;
  v51 = v49 + 10.0;
  v52 = v50 + 175.0;
  v47->rect.right = v51;
  v47->rect.bottom = v52;
  if ( v48 == 0.0 && v47->rectBase.top == 0.0 )
  {
    v47->rectBase.left = 10.0;
    v47->rectBase.top = 175.0;
    v47->rectBase.right = v51;
    v47->rectBase.bottom = v52;
  }
  ((void (*)(ksgui::Control *, int, int))this->dampRear->setSize)(this->dampRear, 1138819072, 1101004800);
  _Val = (int)this->dampRear;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 500.0, 205.0);
}
void __userpurge ACDCarEngineer::render(ACDCarEngineer *this@<ecx>, int a2@<esi>, float deltaT)
{
  ACDCarEngineer *v3; // edi
  const std::wstring *v4; // esi
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wstring *v8; // eax
  const wchar_t *v9; // eax
  const std::wstring *v10; // esi
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wstring *v14; // eax
  const wchar_t *v15; // eax
  const std::wstring *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  std::wostream *v19; // eax
  std::wstring *v20; // eax
  const wchar_t *v21; // eax
  int v22; // eax
  const std::wstring *v23; // edi
  RaceEngineer *v24; // esi
  std::wostream *v25; // eax
  std::wostream *v26; // eax
  std::wostream *v27; // eax
  std::wostream *v28; // eax
  std::wostream *v29; // eax
  const std::wstring *v30; // eax
  const wchar_t *v31; // eax
  int v32; // eax
  const std::wstring *v33; // eax
  std::wstring *v34; // ecx
  std::wostream *v35; // eax
  std::wostream *v36; // eax
  std::wostream *v37; // eax
  std::wostream *v38; // eax
  std::wostream *v39; // eax
  std::wostream *v40; // eax
  const std::wstring *v41; // eax
  const wchar_t *v42; // eax
  const std::wstring *v43; // eax
  std::wstring *v44; // ecx
  std::wostream *v45; // eax
  std::wostream *v46; // eax
  std::wostream *v47; // eax
  std::wostream *v48; // eax
  std::wostream *v49; // eax
  std::wostream *v50; // eax
  const std::wstring *v51; // eax
  char *v52; // [esp+38h] [ebp-17Ch]
  char *v53; // [esp+38h] [ebp-17Ch]
  const std::wstring *v54; // [esp+40h] [ebp-174h]
  const std::wstring *v55; // [esp+40h] [ebp-174h]
  char *_Val; // [esp+48h] [ebp-16Ch]
  char *_Vala; // [esp+48h] [ebp-16Ch]
  char *_Valb; // [esp+48h] [ebp-16Ch]
  const char *dt; // [esp+54h] [ebp-160h]
  __int64 v60; // [esp+58h] [ebp-15Ch]
  float v61; // [esp+60h] [ebp-154h]
  std::tuple<float,float> reard; // [esp+7Ch] [ebp-138h] BYREF
  std::tuple<float,float> frontd; // [esp+84h] [ebp-130h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v65; // [esp+8Ch] [ebp-128h] BYREF
  std::wstring text; // [esp+13Ch] [ebp-78h] BYREF
  std::wstring result; // [esp+154h] [ebp-60h] BYREF
  unsigned int v68; // [esp+16Ch] [ebp-48h]
  std::wstring v69; // [esp+170h] [ebp-44h] BYREF
  std::wstring v70; // [esp+188h] [ebp-2Ch] BYREF
  int v71; // [esp+1ACh] [ebp-8h]
  int v72; // [esp+1B0h] [ebp-4h]
  int vars0; // [esp+1B4h] [ebp+0h]

  v3 = this;
  ksgui::Control::render(this, (int)this, a2, deltaT, v60, v61);
  Sim::getCar(v3->sim, 0);
  *(_DWORD *)v65.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v65.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v65.gap68);
  vars0 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v65.gap0[4], &v65.gap10[12], 0);
  v71 = 1;
  *(_DWORD *)((char *)&frontd._Myfirst._Val + *(_DWORD *)(LODWORD(frontd._Myfirst._Val) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&frontd.std::tuple<float>::_Myfirst._Val + *(_DWORD *)(LODWORD(frontd._Myfirst._Val) + 4)) = *(_DWORD *)(LODWORD(frontd._Myfirst._Val) + 4) - 104;
  std::wstreambuf::wstreambuf(&v65.gap10[4]);
  *(_DWORD *)&v65.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v65.gap10[60] = 0;
  *(_DWORD *)&v65.gap10[64] = 0;
  v71 = 3;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"CAR MASS", 8u);
  LOBYTE(v71) = 4;
  v4 = acTranslate(&result, &text);
  LOBYTE(v71) = 5;
  Sim::getCar(v3->sim, 0);
  v5 = std::operator<<<wchar_t>((std::wostream *)((char *)&v65._Chcount + 4), v4);
  v6 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, (const char *)&Manip);
  v7 = (std::wostream *)std::wostream::operator<<(v6);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v7, dt);
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 6;
  v3->carMass->setText(v3->carMass, v8);
  LOBYTE(v72) = 3;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
  LOBYTE(v72) = 7;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v65.gap10[8]);
  v9 = &text._Bx._Buf[2];
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    v9 = *(const wchar_t **)&text._Bx._Alias[4];
  std::wstringbuf::_Init((std::wstringbuf *)&v65.gap10[8], v9, text._Myres, *(int *)&v65.gap10[68]);
  LOBYTE(v72) = 3;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"SPRUNG", 6u);
  LOBYTE(v72) = 8;
  v10 = acTranslate((std::wstring *)&result._Bx._Alias[4], (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v72) = 9;
  Sim::getCar(v3->sim, 0);
  v11 = std::operator<<<wchar_t>((std::wostream *)v65.gap10, v10);
  v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, (const char *)&Manip);
  v13 = (std::wostream *)std::wostream::operator<<(v12);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, " Kg");
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 10;
  v3->sprungWeight->setText(v3->sprungWeight, v14);
  LOBYTE(v72) = 3;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
  LOBYTE(v72) = 11;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v65.gap10[8]);
  v15 = &text._Bx._Buf[2];
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    v15 = *(const wchar_t **)&text._Bx._Alias[4];
  std::wstringbuf::_Init((std::wstringbuf *)&v65.gap10[8], v15, text._Myres, *(int *)&v65.gap10[68]);
  LOBYTE(v72) = 3;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"UNSPRUNG", 8u);
  LOBYTE(v72) = 12;
  v16 = acTranslate((std::wstring *)&result._Bx._Alias[4], (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v72) = 13;
  v17 = std::operator<<<wchar_t>((std::wostream *)v65.gap10, v16);
  v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, (const char *)&Manip);
  v19 = (std::wostream *)std::wostream::operator<<(v18);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v19, " Kg");
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 14;
  v3->unsprungWeight->setText(v3->unsprungWeight, v20);
  LOBYTE(v72) = 3;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
  LOBYTE(v72) = 15;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v65.gap10[8]);
  v21 = &text._Bx._Buf[2];
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    v21 = *(const wchar_t **)&text._Bx._Alias[4];
  std::wstringbuf::_Init((std::wstringbuf *)&v65.gap10[8], v21, text._Myres, *(int *)&v65.gap10[68]);
  LOBYTE(v72) = 3;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  result._Bx._Ptr = (wchar_t *)7;
  v22 = *(_DWORD *)(*(_DWORD *)v65.gap0 + 4);
  text._Myres = 0;
  *(_DWORD *)&v65.gap10[v22 + 8] = 2;
  *(_DWORD *)&v65.gap10[v22 + 12] = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"FREQUENCY", 9u);
  LOBYTE(v72) = 16;
  v23 = acTranslate((std::wstring *)&result._Bx._Alias[4], (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v72) = 17;
  v24 = (RaceEngineer *)MEMORY[0xE59];
  RaceEngineer::getRearNaturalFrequencyHZ(MEMORY[0xE59]);
  *(float *)&_Val = RaceEngineer::getFrontNaturalFrequencyHZ(v24);
  v25 = std::operator<<<wchar_t>((std::wostream *)v65.gap10, v23);
  v26 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v25, " F:");
  v27 = (std::wostream *)std::wostream::operator<<(v26);
  v28 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v27, _Val);
  v29 = (std::wostream *)std::wostream::operator<<(v28);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v29, " Hz");
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 18;
  this->frequency->setText(this->frequency, v30);
  LOBYTE(v72) = 3;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
  LOBYTE(v72) = 19;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v65.gap10[8]);
  v31 = &text._Bx._Buf[2];
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    v31 = *(const wchar_t **)&text._Bx._Alias[4];
  std::wstringbuf::_Init((std::wstringbuf *)&v65.gap10[8], v31, text._Myres, *(int *)&v65.gap10[68]);
  LOBYTE(v72) = 3;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v32 = *(_DWORD *)(*(_DWORD *)v65.gap0 + 4);
  *(_DWORD *)&v65.gap10[v32 + 8] = 2;
  *(_DWORD *)&v65.gap10[v32 + 12] = 0;
  RaceEngineer::getFrontDampingRatio(MEMORY[0xE59], &frontd);
  RaceEngineer::getRearDampingRatio(MEMORY[0xE59], &reard);
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&result._Bx._Alias[4], L"REBOUND", 7u);
  LOBYTE(v72) = 20;
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"DAMP FRONT BUMP", 0xFu);
  LOBYTE(v72) = 21;
  acTranslate(&v69, (const std::wstring *)&result._Bx._Alias[4]);
  LOBYTE(v72) = 22;
  v33 = acTranslate(&v70, (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v72) = 23;
  _Vala = (char *)v34;
  v54 = v34;
  v52 = (char *)LODWORD(frontd._Myfirst._Val);
  v35 = std::operator<<<wchar_t>((std::wostream *)v65.gap10, v33);
  v36 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v35, (const char *)&Manip);
  v37 = (std::wostream *)std::wostream::operator<<(v36);
  v38 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v37, v52);
  v39 = std::operator<<<wchar_t>(v38, v54);
  v40 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v39, _Vala);
  std::wostream::operator<<(v40);
  if ( v70._Myres >= 8 )
    operator delete(v70._Bx._Ptr);
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 24;
  this->damp->setText(this->damp, v41);
  LOBYTE(v72) = 3;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], word_17BE9D8, 0);
  LOBYTE(v72) = 25;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v65.gap10[8]);
  v42 = &text._Bx._Buf[2];
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    v42 = *(const wchar_t **)&text._Bx._Alias[4];
  std::wstringbuf::_Init((std::wstringbuf *)&v65.gap10[8], v42, text._Myres, *(int *)&v65.gap10[68]);
  LOBYTE(v72) = 3;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  v68 = 7;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&result._Bx._Alias[4], L"REBOUND", 7u);
  LOBYTE(v72) = 26;
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"DAMP REAR BUMP", 0xEu);
  LOBYTE(v72) = 27;
  acTranslate(&v70, (const std::wstring *)&result._Bx._Alias[4]);
  LOBYTE(v72) = 28;
  v43 = acTranslate(&v69, (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v72) = 29;
  _Valb = (char *)v44;
  v55 = v44;
  v53 = (char *)LODWORD(reard._Myfirst._Val);
  v45 = std::operator<<<wchar_t>((std::wostream *)v65.gap10, v43);
  v46 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v45, (const char *)&Manip);
  v47 = (std::wostream *)std::wostream::operator<<(v46);
  v48 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v47, v53);
  v49 = std::operator<<<wchar_t>(v48, v55);
  v50 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v49, _Valb);
  std::wostream::operator<<(v50);
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  if ( v70._Myres >= 8 )
    operator delete(v70._Bx._Ptr);
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  LOBYTE(v72) = 3;
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  if ( v68 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  v51 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v65, &v69);
  LOBYTE(v72) = 30;
  this->dampRear->setText(this->dampRear, v51);
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v65);
}
