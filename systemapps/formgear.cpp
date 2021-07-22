#include "formgear.h
void __userpurge FormGear::FormGear(FormGear *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *acar)
{
  const std::wstring *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // ebp
  Font *v8; // eax
  Font *v9; // ebp
  int v10; // eax
  int v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  Font *v16; // eax
  Font *v17; // eax
  ksgui::Label *v18; // ecx
  volatile signed __int32 *v19; // ebp
  ksgui::Label *v20; // eax
  Font *v21; // ebp
  int v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  Font *v28; // eax
  Font *v29; // eax
  ksgui::Label *v30; // ecx
  volatile signed __int32 *v31; // ebp
  Font *v32; // ebp
  int v33; // eax
  int v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  Font *v39; // eax
  Font *v40; // eax
  ksgui::Label *v41; // ecx
  volatile signed __int32 *v42; // ebp
  Shader *v43; // eax
  bool v44; // cf
  ShaderVariable *v45; // eax
  ShaderVariable *v46; // eax
  Texture *v47; // eax
  Texture *v48; // eax
  Texture *v49; // eax
  Texture *v50; // eax
  Texture *v51; // eax
  Texture *v52; // eax
  Texture *v53; // eax
  Texture *v54; // eax
  Texture *v55; // eax
  Texture *v56; // eax
  unsigned int v57; // esi
  Sim *v58; // ecx
  CarAvatar *v59; // eax
  std::wstring *v60; // eax
  const std::wstring *v61; // eax
  float v62; // ebp
  std::wostream *v63; // eax
  const std::wstring *v64; // eax
  char v65; // al
  float *v66; // esi
  const std::wstring *v67; // eax
  std::allocator<wchar_t> *v68; // eax
  Material *v69; // esi
  CarAvatar *v70; // ebp
  std::_Vb_reference<std::_Wrap_alloc<std::allocator<unsigned int> > > *v71; // eax
  bool v72; // al
  Font *v73; // esi
  ksgui::Label *v74; // eax
  Font *v75; // eax
  Font *v76; // eax
  std::shared_ptr<Font> *v77; // eax
  TyreCompoundDef *v78; // eax
  Font *v79; // esi
  ksgui::Label *v80; // eax
  Font *v81; // eax
  Font *v82; // eax
  std::shared_ptr<Font> *v83; // eax
  TyreCompoundDef *v84; // eax
  _BYTE v85[28]; // [esp+24h] [ebp-194h] BYREF
  float h; // [esp+40h] [ebp-178h]
  std::shared_ptr<Font> v87; // [esp+58h] [ebp-160h] BYREF
  std::shared_ptr<Font> _Pval; // [esp+60h] [ebp-158h] BYREF
  bool _Val; // [esp+6Ah] [ebp-14Eh] BYREF
  char v90; // [esp+6Bh] [ebp-14Dh]
  CarAvatar *v91; // [esp+6Ch] [ebp-14Ch]
  std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > v92; // [esp+73h] [ebp-145h] BYREF
  FormGear *v93; // [esp+74h] [ebp-144h]
  std::_Vb_reference<std::_Wrap_alloc<std::allocator<unsigned int> > > v94; // [esp+78h] [ebp-140h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > turboSection; // [esp+80h] [ebp-138h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+130h] [ebp-88h] BYREF
  int text_16; // [esp+158h] [ebp-60h]
  unsigned int text_20; // [esp+15Ch] [ebp-5Ch]
  INIReader engineIni; // [esp+164h] [ebp-54h] BYREF
  int v100; // [esp+1B4h] [ebp-4h]

  LODWORD(h) = 1;
  v93 = this;
  v91 = acar;
  *(_DWORD *)&v85[24] = acar->game->gui;
  *(_DWORD *)&v85[20] = 7;
  *(_DWORD *)&v85[16] = 0;
  *(_WORD *)v85 = 0;
  std::wstring::assign((std::wstring *)v85, L"FORM_GEAR", 9u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v85, *(ksgui::GUI **)&v85[24], SLOBYTE(h));
  v100 = 0;
  this->__vftable = (FormGear_vtbl *)&FormGear::`vftable';
  this->offTexture.kid = 0;
  this->offTexture.fileName._Myres = 7;
  this->offTexture.fileName._Mysize = 0;
  this->offTexture.fileName._Bx._Buf[0] = 0;
  this->onTexture.kid = 0;
  this->onTexture.fileName._Myres = 7;
  this->onTexture.fileName._Mysize = 0;
  this->onTexture.fileName._Bx._Buf[0] = 0;
  this->offTextureTurbo.kid = 0;
  this->offTextureTurbo.fileName._Myres = 7;
  this->offTextureTurbo.fileName._Mysize = 0;
  this->offTextureTurbo.fileName._Bx._Buf[0] = 0;
  this->onTextureTurbo.kid = 0;
  this->onTextureTurbo.fileName._Myres = 7;
  this->onTextureTurbo.fileName._Mysize = 0;
  this->onTextureTurbo.fileName._Bx._Buf[0] = 0;
  this->kersLeftOffTexture.kid = 0;
  this->kersLeftOffTexture.fileName._Myres = 7;
  this->kersLeftOffTexture.fileName._Mysize = 0;
  this->kersLeftOffTexture.fileName._Bx._Buf[0] = 0;
  this->kersRightOffTexture.kid = 0;
  this->kersRightOffTexture.fileName._Myres = 7;
  this->kersRightOffTexture.fileName._Mysize = 0;
  this->kersRightOffTexture.fileName._Bx._Buf[0] = 0;
  this->kersOnTexture.kid = 0;
  this->kersOnTexture.fileName._Myres = 7;
  this->kersOnTexture.fileName._Mysize = 0;
  this->kersOnTexture.fileName._Bx._Buf[0] = 0;
  this->batteryOnTexture.kid = 0;
  this->batteryOnTexture.fileName._Myres = 7;
  this->batteryOnTexture.fileName._Mysize = 0;
  this->batteryOnTexture.fileName._Bx._Buf[0] = 0;
  this->kersLoadOnTexture.kid = 0;
  this->kersLoadOnTexture.fileName._Myres = 7;
  this->kersLoadOnTexture.fileName._Mysize = 0;
  this->kersLoadOnTexture.fileName._Bx._Buf[0] = 0;
  this->kersInnerRightOffTexture.kid = 0;
  this->kersInnerRightOffTexture.fileName._Myres = 7;
  this->kersInnerRightOffTexture.fileName._Mysize = 0;
  this->kersInnerRightOffTexture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v100) = 10;
  _Pval._Ptr = 0;
  this->kersOn._Myvec._Myfirst = 0;
  this->kersOn._Myvec._Mylast = 0;
  this->kersOn._Myvec._Myend = 0;
  std::vector<unsigned int>::_Construct_n(&this->kersOn._Myvec, 0, (const unsigned int *)&_Pval);
  this->kersOn._Mysize = 0;
  this->currentRPM = 0.0;
  this->maxTurbos._Myfirst = 0;
  this->maxTurbos._Mylast = 0;
  this->maxTurbos._Myend = 0;
  LOBYTE(v100) = 12;
  LODWORD(h) = 5;
  this->hasP2P = 0;
  text_20 = 7;
  text_16 = 0;
  LOWORD(result.score) = 0;
  std::wstring::assign((std::wstring *)&result.score, L"Gears", LODWORD(h));
  LOBYTE(v100) = 13;
  v4 = acTranslate(&result.name, (const std::wstring *)&result.score);
  LOBYTE(v100) = 14;
  this->formTitle->setText(this->formTitle, v4);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  LOBYTE(v100) = 12;
  result.name._Myres = 7;
  result.name._Mysize = 0;
  result.name._Bx._Buf[0] = 0;
  if ( text_20 >= 8 )
    operator delete((void *)result.score);
  this->devApp = 0;
  this->car = acar;
  ksgui::Form::setSize(this, 196.0, 206.0);
  ksgui::Form::setAutoHideMode(this, 1);
  v5 = (Font *)operator new(0x18u);
  v87._Ptr = v5;
  LOBYTE(v100) = 15;
  if ( v5 )
    Font::Font(v5, eFontMonospaced, 120.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v100) = 12;
  v87 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v87, v6);
  v7 = this->font._Rep;
  this->font = v87;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Weaks, 0xFFFFFFFF) )
        v7->_Delete_this(v7);
    }
  }
  v8 = this->font._Ptr;
  LODWORD(h) = 284;
  v8->shadowed = 1;
  v9 = (Font *)operator new(LODWORD(h));
  v87._Ptr = v9;
  LOBYTE(v100) = 16;
  if ( v9 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v85[24] = 7;
    *(_DWORD *)&v85[20] = 0;
    *(_WORD *)&v85[4] = 0;
    std::wstring::assign((std::wstring *)&v85[4], L"N", aN_0[0] != 0);
    ksgui::Label::Label((ksgui::Label *)v9, *(std::wstring *)&v85[4], (ksgui::GUI *)LODWORD(h));
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  LOBYTE(v100) = 12;
  this->labGear = (ksgui::Label *)v11;
  v12 = *(float *)(v11 + 264);
  v13 = *(float *)(v11 + 40) - *(float *)(v11 + 36);
  v14 = *(float *)(v11 + 32) - *(float *)(v11 + 28);
  *(_DWORD *)(v11 + 36) = 1114636288;
  *(_DWORD *)(v11 + 28) = 0;
  v15 = v13 + 60.0;
  *(float *)(v11 + 32) = v14;
  *(float *)(v11 + 40) = v15;
  if ( v12 == 0.0 && *(float *)(v11 + 272) == 0.0 )
  {
    *(_DWORD *)(v11 + 264) = 0;
    *(_DWORD *)(v11 + 272) = 1114636288;
    *(float *)(v11 + 268) = v14;
    *(float *)(v11 + 276) = v15;
  }
  ((void (*)(ksgui::Label *, int, int))this->labGear->setSize)(this->labGear, 1125908480, 1107296256);
  v16 = (Font *)operator new(0x18u);
  v87._Ptr = v16;
  LOBYTE(v100) = 17;
  if ( v16 )
    Font::Font(v16, eFontMonospaced, 98.0, 0, 0);
  else
    v17 = 0;
  LOBYTE(v100) = 12;
  v87 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v87, v17);
  v18 = this->labGear;
  v19 = (volatile signed __int32 *)v18->font._Rep;
  v18->font = v87;
  if ( v19 )
  {
    if ( !_InterlockedExchangeAdd(v19 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v19)(v19);
      if ( !_InterlockedExchangeAdd(v19 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v19 + 4))(v19);
    }
  }
  v20 = this->labGear;
  LODWORD(h) = &_Pval;
  v20->foreColor = (vec4f)_xmm;
  this->labGear->font._Ptr->shadowed = 1;
  this->labGear->fontAlign = eAlignCenter;
  _Pval._Ptr = (Font *)this->labGear;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)LODWORD(h));
  LODWORD(h) = 284;
  *(_DWORD *)&_Pval._Ptr[6].shadowed = this;
  v21 = (Font *)operator new(LODWORD(h));
  v87._Ptr = v21;
  LOBYTE(v100) = 18;
  if ( v21 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v85[24] = 7;
    *(_DWORD *)&v85[20] = 0;
    *(_WORD *)&v85[4] = 0;
    std::wstring::assign((std::wstring *)&v85[4], L"145", 3u);
    ksgui::Label::Label((ksgui::Label *)v21, *(std::wstring *)&v85[4], (ksgui::GUI *)LODWORD(h));
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  LOBYTE(v100) = 12;
  this->labSpeed = (ksgui::Label *)v23;
  v24 = *(float *)(v23 + 264);
  v25 = *(float *)(v23 + 40) - *(float *)(v23 + 36);
  v26 = *(float *)(v23 + 32) - *(float *)(v23 + 28);
  *(_DWORD *)(v23 + 36) = 1125842944;
  *(_DWORD *)(v23 + 28) = 0;
  v27 = v25 + 155.0;
  *(float *)(v23 + 32) = v26;
  *(float *)(v23 + 40) = v27;
  if ( v24 == 0.0 && *(float *)(v23 + 272) == 0.0 )
  {
    *(_DWORD *)(v23 + 264) = 0;
    *(_DWORD *)(v23 + 272) = 1125842944;
    *(float *)(v23 + 268) = v26;
    *(float *)(v23 + 276) = v27;
  }
  ((void (*)(ksgui::Label *, int, int))this->labSpeed->setSize)(this->labSpeed, 1125908480, 1107296256);
  v28 = (Font *)operator new(0x18u);
  v87._Ptr = v28;
  LOBYTE(v100) = 19;
  if ( v28 )
    Font::Font(v28, eFontMonospaced, 36.0, 0, 0);
  else
    v29 = 0;
  LOBYTE(v100) = 12;
  v87 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v87, v29);
  v30 = this->labSpeed;
  v31 = (volatile signed __int32 *)v30->font._Rep;
  v30->font = v87;
  if ( v31 )
  {
    if ( !_InterlockedExchangeAdd(v31 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v31)(v31);
      if ( !_InterlockedExchangeAdd(v31 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v31 + 4))(v31);
    }
  }
  this->labSpeed->font._Ptr->shadowed = 1;
  this->labSpeed->foreColor = (vec4f)_xmm;
  this->labSpeed->fontAlign = eAlignCenter;
  _Pval._Ptr = (Font *)this->labSpeed;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&_Pval);
  LODWORD(h) = 284;
  *(_DWORD *)&_Pval._Ptr[6].shadowed = this;
  v32 = (Font *)operator new(LODWORD(h));
  v87._Ptr = v32;
  LOBYTE(v100) = 20;
  if ( v32 )
  {
    h = *(float *)&this->gui;
    *(_DWORD *)&v85[24] = 7;
    *(_DWORD *)&v85[20] = 0;
    *(_WORD *)&v85[4] = 0;
    std::wstring::assign((std::wstring *)&v85[4], L"kmh", 3u);
    ksgui::Label::Label((ksgui::Label *)v32, *(std::wstring *)&v85[4], (ksgui::GUI *)LODWORD(h));
    v34 = v33;
  }
  else
  {
    v34 = 0;
  }
  LOBYTE(v100) = 12;
  this->labSmallSpeed = (ksgui::Label *)v34;
  v35 = *(float *)(v34 + 264);
  v36 = *(float *)(v34 + 40) - *(float *)(v34 + 36);
  v37 = *(float *)(v34 + 32) - *(float *)(v34 + 28);
  *(_DWORD *)(v34 + 36) = 1128136704;
  *(_DWORD *)(v34 + 28) = 0;
  v38 = v36 + 190.0;
  *(float *)(v34 + 32) = v37;
  *(float *)(v34 + 40) = v38;
  if ( v35 == 0.0 && *(float *)(v34 + 272) == 0.0 )
  {
    *(_DWORD *)(v34 + 264) = 0;
    *(_DWORD *)(v34 + 272) = 1128136704;
    *(float *)(v34 + 268) = v37;
    *(float *)(v34 + 276) = v38;
  }
  ((void (*)(ksgui::Label *, int, int))this->labSmallSpeed->setSize)(
    this->labSmallSpeed,
    1125908480,
    1107296256);
  v39 = (Font *)operator new(0x18u);
  v87._Ptr = v39;
  LOBYTE(v100) = 21;
  if ( v39 )
    Font::Font(v39, eFontMonospaced, 12.0, 0, 0);
  else
    v40 = 0;
  LOBYTE(v100) = 12;
  v87 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v87, v40);
  v41 = this->labSmallSpeed;
  v42 = (volatile signed __int32 *)v41->font._Rep;
  v41->font = v87;
  if ( v42 )
  {
    if ( !_InterlockedExchangeAdd(v42 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v42)(v42);
      if ( !_InterlockedDecrement(v42 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v42 + 4))(v42);
    }
  }
  this->labSmallSpeed->font._Ptr->shadowed = 1;
  this->labSmallSpeed->foreColor = (vec4f)_xmm;
  this->labSmallSpeed->fontAlign = eAlignCenter;
  if ( Speed::useMPH )
  {
    text_20 = 7;
    text_16 = 0;
    LOWORD(result.score) = 0;
    std::wstring::assign((std::wstring *)&result.score, L"mph", 3u);
    LOBYTE(v100) = 22;
    this->labSmallSpeed->setText(this->labSmallSpeed, (const std::wstring *)&result.score);
    LOBYTE(v100) = 12;
    if ( text_20 >= 8 )
      operator delete((void *)result.score);
  }
  _Pval._Ptr = (Font *)this->labSmallSpeed;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&_Pval);
  LODWORD(h) = 13;
  *(_DWORD *)&v85[24] = L"ksCircularRPM";
  text_20 = 7;
  *(_DWORD *)&_Pval._Ptr[6].shadowed = this;
  text_16 = 0;
  LOWORD(result.score) = 0;
  std::wstring::assign((std::wstring *)&result.score, *(const wchar_t **)&v85[24], LODWORD(h));
  LOBYTE(v100) = 23;
  v43 = GraphicsManager::getShader(
          this->gui->graphics,
          (unsigned int)operator delete,
          (const std::wstring *)&result.score);
  LOBYTE(v100) = 12;
  v44 = text_20 < 8;
  this->rpmShader = v43;
  if ( !v44 )
    operator delete((void *)result.score);
  std::wstring::wstring(&result.name, L"angleRPM");
  LOBYTE(v100) = 24;
  v45 = Shader::getVar(this->rpmShader, &result.name);
  LOBYTE(v100) = 12;
  v44 = result.name._Myres < 8;
  this->rpmAngleVar = v45;
  if ( !v44 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"kersType");
  LOBYTE(v100) = 25;
  v46 = Shader::getVar(this->rpmShader, &result.name);
  LOBYTE(v100) = 12;
  v44 = result.name._Myres < 8;
  this->kersVar = v46;
  if ( !v44 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/rpm_off.png");
  LOBYTE(v100) = 26;
  v47 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 27;
  this->offTexture.kid = v47->kid;
  if ( &this->offTexture.fileName != &v47->fileName )
    std::wstring::assign(&this->offTexture.fileName, &v47->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 26;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/rpm_on.png");
  LOBYTE(v100) = 28;
  v48 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 29;
  this->onTexture.kid = v48->kid;
  if ( &this->onTexture.fileName != &v48->fileName )
    std::wstring::assign(&this->onTexture.fileName, &v48->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 28;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/turbo_off.png");
  LOBYTE(v100) = 30;
  v49 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 31;
  this->offTextureTurbo.kid = v49->kid;
  if ( &this->offTextureTurbo.fileName != &v49->fileName )
    std::wstring::assign(&this->offTextureTurbo.fileName, &v49->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 30;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/turbo_on.png");
  LOBYTE(v100) = 32;
  v50 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 33;
  this->onTextureTurbo.kid = v50->kid;
  if ( &this->onTextureTurbo.fileName != &v50->fileName )
    std::wstring::assign(&this->onTextureTurbo.fileName, &v50->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 32;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/kers_left_off.png");
  LOBYTE(v100) = 34;
  v51 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 35;
  this->kersLeftOffTexture.kid = v51->kid;
  if ( &this->kersLeftOffTexture.fileName != &v51->fileName )
    std::wstring::assign(&this->kersLeftOffTexture.fileName, &v51->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 34;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/kers_right_off.png");
  LOBYTE(v100) = 36;
  v52 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 37;
  this->kersRightOffTexture.kid = v52->kid;
  if ( &this->kersRightOffTexture.fileName != &v52->fileName )
    std::wstring::assign(&this->kersRightOffTexture.fileName, &v52->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 36;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/kersmotor_on.png");
  LOBYTE(v100) = 38;
  v53 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 39;
  this->batteryOnTexture.kid = v53->kid;
  if ( &this->batteryOnTexture.fileName != &v53->fileName )
    std::wstring::assign(&this->batteryOnTexture.fileName, &v53->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 38;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/battery_on.png");
  LOBYTE(v100) = 40;
  v54 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 41;
  this->kersOnTexture.kid = v54->kid;
  if ( &this->kersOnTexture.fileName != &v54->fileName )
    std::wstring::assign(&this->kersOnTexture.fileName, &v54->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 40;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/kersload_on.png");
  LOBYTE(v100) = 42;
  v55 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 43;
  this->kersLoadOnTexture.kid = v55->kid;
  if ( &this->kersLoadOnTexture.fileName != &v55->fileName )
    std::wstring::assign(&this->kersLoadOnTexture.fileName, &v55->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 42;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::wstring::wstring(&result.name, L"content/texture/kers_inner_right_off.png");
  LOBYTE(v100) = 44;
  v56 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, (Texture *)&result.score, &result.name, 0);
  LOBYTE(v100) = 45;
  this->kersInnerRightOffTexture.kid = v56->kid;
  if ( &this->kersInnerRightOffTexture.fileName != &v56->fileName )
    std::wstring::assign(&this->kersInnerRightOffTexture.fileName, &v56->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v100) = 44;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&result.score);
  LOBYTE(v100) = 12;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v57 = 0;
  _Pval._Ptr = 0;
  v58 = v91->sim;
  if ( v58->cars._Mylast - v58->cars._Myfirst )
  {
    _Val = 0;
    do
    {
      v59 = Sim::getCar(v58, v57);
      v60 = std::operator+<wchar_t>((std::wstring *)&result.score, L"content/cars/", &v59->unixName);
      LOBYTE(v100) = 46;
      v61 = std::operator+<wchar_t>(&result.name, v60, L"/data/engine.ini");
      LOBYTE(v100) = 47;
      INIReader::INIReader(&engineIni, v61);
      if ( result.name._Myres >= 8 )
        operator delete(result.name._Bx._Ptr);
      result.name._Myres = 7;
      result.name._Mysize = 0;
      result.name._Bx._Buf[0] = 0;
      LOBYTE(v100) = 50;
      if ( text_20 >= 8 )
        operator delete((void *)result.score);
      text_20 = 7;
      text_16 = 0;
      LOWORD(result.score) = 0;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &turboSection,
        3,
        1);
      LOBYTE(v100) = 51;
      v62 = 0.0;
      v87._Ptr = 0;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->maxTurbos, (int *)&v87);
      for ( h = 0.0; ; h = v62 )
      {
        v63 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)turboSection.gap10, "TURBO_");
        std::wostream::operator<<(v63, LODWORD(h));
        v64 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &turboSection,
                &result.name);
        LOBYTE(v100) = 52;
        v65 = INIReader::hasSection(&engineIni, v64);
        LOBYTE(v100) = 51;
        v90 = v65;
        if ( result.name._Myres >= 8 )
        {
          operator delete(result.name._Bx._Ptr);
          v65 = v90;
        }
        if ( !v65 )
          break;
        std::wstring::wstring((std::wstring *)&result.score, L"DISPLAY_MAX_BOOST");
        LOBYTE(v100) = 53;
        v66 = this->maxTurbos._Mylast;
        v67 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                &turboSection,
                &result.name);
        LOBYTE(v100) = 54;
        *(v66 - 1) = INIReader::getFloat(&engineIni, v67, (const std::wstring *)&result.score) + *(v66 - 1);
        if ( result.name._Myres >= 8 )
          operator delete(result.name._Bx._Ptr);
        LOBYTE(v100) = 51;
        result.name._Bx._Buf[0] = 0;
        result.name._Myres = 7;
        result.name._Mysize = 0;
        if ( text_20 >= 8 )
        {
          LODWORD(h) = text_20 + 1;
          *(_DWORD *)&v85[24] = result.score;
          v68 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                             (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&result.score,
                                             &v92);
          std::allocator<wchar_t>::deallocate(v68, *(wchar_t **)&v85[24], LODWORD(h));
        }
        text_20 = 7;
        std::wstring::_Eos((std::wstring *)&result.score, 0);
        std::wstring::wstring(&result.name, word_17BE9D8);
        LOBYTE(v100) = 55;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &turboSection,
          &result.name);
        LOBYTE(v100) = 51;
        std::wstring::~wstring(&result);
        ++LODWORD(v62);
      }
      v69 = (Material *)_Pval._Ptr;
      v70 = Sim::getCar(v91->sim, (unsigned int)_Pval._Ptr);
      std::vector<bool>::push_back(&this->kersOn, &_Val);
      if ( v70->physicsInfo.hasKERS || v70->physicsInfo.hasERS )
      {
        LODWORD(h) = 1;
        v71 = std::vector<bool>::back(&this->kersOn, &v94);
        std::_Vb_reference<std::_Wrap_alloc<std::allocator<unsigned int>>>::operator=(v71, SLOBYTE(h));
      }
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&turboSection);
      LOBYTE(v100) = 12;
      INIReader::~INIReader(&engineIni);
      v57 = (unsigned int)v69->name._Bx._Buf + 1;
      _Pval._Ptr = (Font *)v57;
      v58 = v91->sim;
    }
    while ( v57 < v58->cars._Mylast - v58->cars._Myfirst );
  }
  v72 = GameObject::getGameObject<PushToPassManager>(this->car->sim) != 0;
  this->hasP2P = v72;
  if ( v72 )
  {
    v73 = (Font *)operator new(0x11Cu);
    v87._Ptr = v73;
    LOBYTE(v100) = 56;
    if ( v73 )
    {
      h = *(float *)&this->gui;
      std::wstring::wstring((std::wstring *)&v85[4], L"P2PLBL");
      ksgui::Label::Label((ksgui::Label *)v73, *(std::wstring *)&v85[4], (ksgui::GUI *)LODWORD(h));
    }
    else
    {
      v74 = 0;
    }
    LOBYTE(v100) = 12;
    this->p2pLabel = v74;
    ksgui::Form::setPosition((ksgui::Form *)v74, 146.0, 47.0);
    ((void (*)(ksgui::Label *, int, int))this->p2pLabel->setSize)(this->p2pLabel, 1106247680, 1107296256);
    v75 = (Font *)operator new(0x18u);
    v87._Ptr = v75;
    LOBYTE(v100) = 57;
    if ( v75 )
      Font::Font(v75, eFontMonospaced, 15.0, 0, 0);
    else
      v76 = 0;
    LOBYTE(v100) = 12;
    std::shared_ptr<Font>::shared_ptr<Font>(&_Pval, v76);
    std::shared_ptr<Font>::operator=(&this->p2pLabel->font, v77);
    std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&_Pval);
    v78 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->p2pLabel->font);
    LODWORD(h) = L"P2P";
    v78->name._Bx._Alias[0] = 1;
    this->p2pLabel->foreColor = (vec4f)_xmm;
    this->p2pLabel->fontAlign = eAlignCenter;
    std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(h));
    LOBYTE(v100) = 58;
    this->p2pLabel->setText(this->p2pLabel, (const std::wstring *)&result);
    LOBYTE(v100) = 12;
    std::wstring::~wstring(&result);
    ksgui::Control::addControl(this, this->p2pLabel);
    v79 = (Font *)operator new(0x11Cu);
    v87._Ptr = v79;
    LOBYTE(v100) = 59;
    if ( v79 )
    {
      h = *(float *)&this->gui;
      std::wstring::wstring((std::wstring *)&v85[4], L"P2PVAL");
      ksgui::Label::Label((ksgui::Label *)v79, *(std::wstring *)&v85[4], (ksgui::GUI *)LODWORD(h));
    }
    else
    {
      v80 = 0;
    }
    LOBYTE(v100) = 12;
    this->p2pValue = v80;
    ksgui::Form::setPosition((ksgui::Form *)v80, 146.0, 59.0);
    ((void (*)(ksgui::Label *, int, int))this->p2pValue->setSize)(this->p2pValue, 1106247680, 1107296256);
    v81 = (Font *)operator new(0x18u);
    v87._Ptr = v81;
    LOBYTE(v100) = 60;
    if ( v81 )
      Font::Font(v81, eFontMonospaced, 25.0, 0, 0);
    else
      v82 = 0;
    LOBYTE(v100) = 12;
    std::shared_ptr<Font>::shared_ptr<Font>(&_Pval, v82);
    std::shared_ptr<Font>::operator=(&this->p2pValue->font, v83);
    std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&_Pval);
    v84 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->p2pValue->font);
    LODWORD(h) = L"15";
    v84->name._Bx._Alias[0] = 1;
    this->p2pValue->foreColor = (vec4f)_xmm;
    this->p2pValue->fontAlign = eAlignCenter;
    std::wstring::wstring(&result.name, (const wchar_t *)LODWORD(h));
    LOBYTE(v100) = 61;
    this->p2pValue->setText(this->p2pValue, (const std::wstring *)&result);
    LOBYTE(v100) = 12;
    std::wstring::~wstring(&result);
    ksgui::Control::addControl(this, this->p2pValue);
  }
  ksgui::Control::scaleByMult(this);
}
FormGear *FormGear::`scalar deleting destructor'(FormGear *this, unsigned int a2)
{
  FormGear::~FormGear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormGear::~FormGear(FormGear *this)
{
  this->__vftable = (FormGear_vtbl *)&FormGear::`vftable';
  if ( this->maxTurbos._Myfirst )
  {
    operator delete(this->maxTurbos._Myfirst);
    this->maxTurbos._Myfirst = 0;
    this->maxTurbos._Mylast = 0;
    this->maxTurbos._Myend = 0;
  }
  this->kersOn._Mysize = 0;
  if ( this->kersOn._Myvec._Myfirst )
  {
    operator delete(this->kersOn._Myvec._Myfirst);
    this->kersOn._Myvec._Myfirst = 0;
    this->kersOn._Myvec._Mylast = 0;
    this->kersOn._Myvec._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->kersInnerRightOffTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->kersLoadOnTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->batteryOnTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->kersOnTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->kersRightOffTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->kersLeftOffTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->onTextureTurbo);
  OnSetupAppCreated::~OnSetupAppCreated(&this->offTextureTurbo);
  OnSetupAppCreated::~OnSetupAppCreated(&this->onTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->offTexture);
  this->__vftable = (FormGear_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void FormGear::render(FormGear *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax
  unsigned int v5; // eax
  CarAvatar *v6; // ecx
  int v7; // edi
  Sim *v8; // ecx
  float v9; // xmm0_4
  CarAvatar *v10; // eax
  int v11; // eax
  CarAvatar *v12; // edx
  int *v13; // ecx
  float v14; // xmm2_4
  int *v15; // edx
  float v16; // xmm2_4
  ksgui::Label *v17; // eax
  __int128 v18; // xmm0
  float v19; // xmm0_4
  float v20; // xmm0_4
  const std::wstring *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  ShaderVariable *v24; // ecx
  GraphicsManager *v25; // ecx
  float v26; // xmm1_4
  GLRenderer *v27; // edi
  CarAvatar *v28; // eax
  float v29; // xmm3_4
  float v30; // xmm1_4
  ShaderVariable *v31; // ecx
  CarAvatar *v32; // eax
  float v33; // xmm0_4
  float v34; // xmm1_4
  ShaderVariable *v35; // ecx
  vec4f v36; // xmm0
  const std::wstring *v37; // eax
  __int64 v38; // [esp+2Ch] [ebp-11Ch]
  float v39; // [esp+34h] [ebp-114h]
  float v40; // [esp+40h] [ebp-108h] BYREF
  float v41; // [esp+44h] [ebp-104h] BYREF
  GLRenderer *v42; // [esp+48h] [ebp-100h]
  float height; // [esp+4Ch] [ebp-FCh]
  float v44; // [esp+50h] [ebp-F8h]
  unsigned int v45; // [esp+54h] [ebp-F4h]
  float v46; // [esp+58h] [ebp-F0h] BYREF
  unsigned int *v47; // [esp+5Ch] [ebp-ECh]
  float value; // [esp+60h] [ebp-E8h] BYREF
  float v49; // [esp+64h] [ebp-E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v50; // [esp+68h] [ebp-E0h] BYREF
  std::wstring result; // [esp+11Ch] [ebp-2Ch] BYREF
  int v52; // [esp+144h] [ebp-4h]

  v42 = 0;
  v3 = Sim::getFocusedCarIndex(this->car->sim);
  v4 = Sim::getCar(this->car->sim, v3);
  this->car = v4;
  v5 = Sim::getFocusedCarIndex(v4->sim);
  v6 = this->car;
  v47 = this->kersOn._Myvec._Myfirst;
  v7 = v5 & 0x1F;
  v8 = v6->sim;
  v45 = v5 >> 5;
  v9 = this->maxTurbos._Myfirst[Sim::getFocusedCarIndex(v8)];
  v10 = this->car;
  v44 = v9;
  v11 = v10->physicsState.gear;
  if ( v11 < 0 || v11 >= 11 )
    this->labGear->setText(this->labGear, &gears_0[10]);
  else
    this->labGear->setText(this->labGear, &gears_0[v11]);
  v12 = this->car;
  v13 = &v12->physicsState.limiterRPM;
  v14 = v12->physicsState.engineRPM;
  v15 = &v12->physicsInfo.engineDamageRPM;
  v16 = (float)((float)(v14 - this->currentRPM) * (float)((float)(dt * 62.499996) * 0.2)) + this->currentRPM;
  this->currentRPM = v16;
  v17 = this->labGear;
  if ( *v13 < *v15 )
    v15 = v13;
  v49 = (float)*v15;
  if ( v16 <= (float)(v49 * 0.99000001) )
    v18 = _xmm;
  else
    v18 = _xmm;
  v17->foreColor = (vec4f)v18;
  *(_DWORD *)v50.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v50.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v50.gap68);
  v52 = 0;
  v42 = (GLRenderer *)1;
  std::wiostream::basic_iostream<wchar_t>(&v50, &v50.gap10[8], 0);
  v52 = 1;
  *(_DWORD *)&v50.gap0[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v49 + *(_DWORD *)(*(_DWORD *)v50.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v50.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v50.gap10[8]);
  *(_DWORD *)&v50.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v50.gap10[64] = 0;
  *(_DWORD *)&v50.gap10[68] = 0;
  v52 = 3;
  v19 = this->car->physicsState.speed.value;
  if ( Speed::useMPH )
    v20 = v19 * 2.2369363;
  else
    v20 = v19 * 3.5999999;
  std::wostream::operator<<(v50.gap10, (int)(float)(v20 + 0.5));
  v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v50, &result);
  LOBYTE(v52) = 4;
  this->labSpeed->setText(this->labSpeed, v21);
  LOBYTE(v52) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ksgui::Control::render(this, v7, (int)this, dt, v38, v39);
  v22 = this->currentRPM / v49;
  v41 = 0.0;
  height = this->scaleMult * 156.0;
  v23 = FLOAT_1_0;
  if ( v22 > 1.0 || (v23 = 0.0, v22 < 0.0) )
    v22 = v23;
  v24 = this->rpmAngleVar;
  value = (float)(v22 * 0.84000003) + 0.079999998;
  ShaderVariable::set(v24, &value);
  ShaderVariable::set(this->kersVar, &v41);
  CBuffer::commit(this->rpmAngleVar->buffer);
  CBuffer::commit(this->kersVar->buffer);
  v25 = this->gui->graphics;
  v42 = v25->gl;
  GraphicsManager::setTexture(v25, 0, &this->offTexture);
  GraphicsManager::setTexture(this->gui->graphics, 1, &this->onTexture);
  GLRenderer::color3f(v42, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v42,
    this->rect.left,
    (float)(this->scaleMult * 40.0) + this->rect.top,
    height,
    height,
    1,
    this->rpmShader);
  v46 = 0.0;
  if ( v44 != 0.0 )
  {
    v26 = this->car->physicsState.turboBoost / v44;
    if ( v26 <= 1.0 )
    {
      if ( v26 < 0.0 )
        v26 = 0.0;
    }
    else
    {
      v26 = FLOAT_1_0;
    }
    v46 = (float)(v26 * 0.84000003) + 0.079999998;
  }
  ShaderVariable::set(this->rpmAngleVar, &v46);
  CBuffer::commit(this->rpmAngleVar->buffer);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->offTextureTurbo);
  GraphicsManager::setTexture(this->gui->graphics, 1, &this->onTextureTurbo);
  GLRenderer::color3f(v42, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v42,
    this->rect.left,
    (float)(this->scaleMult * 40.0) + this->rect.top,
    height,
    height,
    1,
    this->rpmShader);
  v40 = 0.0;
  v41 = 1.0;
  LODWORD(v44) = 1 << v7;
  if ( ((1 << v7) & v47[v45]) != 0 )
    v40 = (float)(this->car->physicsState.kersInput * 0.56999999) + 0.17;
  ShaderVariable::set(this->rpmAngleVar, &v40);
  ShaderVariable::set(this->kersVar, &v41);
  CBuffer::commit(this->rpmAngleVar->buffer);
  CBuffer::commit(this->kersVar->buffer);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->kersLeftOffTexture);
  GraphicsManager::setTexture(this->gui->graphics, 1, &this->kersOnTexture);
  v27 = v42;
  GLRenderer::color3f(v42, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v27,
    this->rect.left,
    (float)(this->scaleMult * 40.0) + this->rect.top,
    height,
    height,
    1,
    this->rpmShader);
  v40 = 0.92499995;
  v41 = 2.0;
  if ( (LODWORD(v44) & v47[v45]) != 0 )
    v40 = (float)((float)((float)(1.0 - this->car->physicsState.kersCharge) * 0.56999999) * 0.5) + 0.63;
  ShaderVariable::set(this->rpmAngleVar, &v40);
  ShaderVariable::set(this->kersVar, &v41);
  CBuffer::commit(this->rpmAngleVar->buffer);
  CBuffer::commit(this->kersVar->buffer);
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->batteryOnTexture);
  GraphicsManager::setTexture(this->gui->graphics, 1, &this->kersRightOffTexture);
  GLRenderer::color3f(v27, 1.0, 1.0, 1.0);
  GLRenderer::quad(
    v27,
    this->rect.left,
    (float)(this->scaleMult * 40.0) + this->rect.top,
    height,
    height,
    1,
    this->rpmShader);
  v28 = this->car;
  v29 = FLOAT_1000_0;
  if ( v28->physicsInfo.kersMaxJ > 0.0 )
  {
    v40 = 0.92499995;
    v41 = 3.0;
    v30 = (float)(v28->physicsState.kersCurrentKJ / v28->physicsInfo.kersMaxJ) * 1000.0;
    if ( v30 <= 1.0 )
    {
      if ( v30 < 0.0 )
        v30 = 0.0;
    }
    else
    {
      v30 = FLOAT_1_0;
    }
    v31 = this->rpmAngleVar;
    v40 = (float)((float)(v30 * 0.56999999) * 0.5) + 0.63;
    ShaderVariable::set(v31, &v40);
    ShaderVariable::set(this->kersVar, &v41);
    CBuffer::commit(this->rpmAngleVar->buffer);
    CBuffer::commit(this->kersVar->buffer);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->kersLoadOnTexture);
    GraphicsManager::setTexture(this->gui->graphics, 1, &this->kersInnerRightOffTexture);
    GLRenderer::color3f(v27, 1.0, 1.0, 1.0);
    GLRenderer::quad(
      v27,
      this->rect.left,
      (float)(this->scaleMult * 40.0) + this->rect.top,
      height,
      height,
      1,
      this->rpmShader);
    v29 = FLOAT_1000_0;
  }
  v32 = this->car;
  if ( v32->physicsInfo.ersMaxJ > 0.0 )
  {
    v40 = 0.92499995;
    v41 = 3.0;
    v33 = FLOAT_1_0;
    v34 = (float)(v32->physicsState.kersCurrentKJ / v32->physicsInfo.ersMaxJ) * v29;
    if ( v34 <= 1.0 )
    {
      if ( v34 >= 0.0 )
        v33 = (float)(v32->physicsState.kersCurrentKJ / v32->physicsInfo.ersMaxJ) * v29;
      else
        v33 = 0.0;
    }
    v35 = this->rpmAngleVar;
    v40 = (float)((float)(v33 * 0.56999999) * 0.5) + 0.63;
    ShaderVariable::set(v35, &v40);
    ShaderVariable::set(this->kersVar, &v41);
    CBuffer::commit(this->rpmAngleVar->buffer);
    CBuffer::commit(this->kersVar->buffer);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->kersLoadOnTexture);
    GraphicsManager::setTexture(this->gui->graphics, 1, &this->kersInnerRightOffTexture);
    GLRenderer::color3f(v27, 1.0, 1.0, 1.0);
    GLRenderer::quad(
      v27,
      this->rect.left,
      (float)(this->scaleMult * 40.0) + this->rect.top,
      height,
      height,
      1,
      this->rpmShader);
  }
  if ( this->hasP2P )
  {
    switch ( this->car->physicsState.p2pStatus )
    {
      case 1u:
        v36 = (vec4f)_xmm;
        break;
      case 2u:
        v36 = (vec4f)_xmm;
        break;
      case 3u:
        v36 = (vec4f)_xmm;
        break;
      default:
        goto LABEL_48;
    }
    this->p2pValue->foreColor = v36;
LABEL_48:
    v37 = std::to_wstring(&result, this->car->physicsState.p2pActivations);
    LOBYTE(v52) = 5;
    this->p2pValue->setText(this->p2pValue, v37);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  *(_DWORD *)&v50.gap0[*(_DWORD *)(*(_DWORD *)v50.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v49 + *(_DWORD *)(*(_DWORD *)v50.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v50.gap0 + 4) - 104;
  *(_DWORD *)&v50.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v50.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v50.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v50.gap68);
}
