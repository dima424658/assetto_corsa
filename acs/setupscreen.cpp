#include "setupscreen.h
void SetupScreen::SetupScreen(SetupScreen *this, Sim *sim)
{
  int v3; // edi
  TabBar *v4; // eax
  Event<ksgui::OnListBoxItemClickedEvent> *v5; // ecx
  ICollisionObject *v6; // eax
  SetupIOManager *v7; // eax
  SetupIOManager *v8; // ecx
  TabBar *v9; // eax
  float v10; // xmm4_4
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  float v13; // xmm1_4
  std::wstring *v14; // eax
  CarAvatar *v15; // eax
  SetupGearManager *v16; // eax
  SetupGearManager *v17; // ecx
  TabBar *v18; // eax
  __m128 v19; // xmm1
  float v20; // xmm4_4
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  float v23; // xmm2_4
  std::wstring *v24; // eax
  CarAvatar *v25; // eax
  SetupTyresManager *v26; // eax
  SetupTyresManager *v27; // ecx
  TabBar *v28; // eax
  __m128 v29; // xmm1
  float v30; // xmm4_4
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  float v33; // xmm2_4
  std::wstring *v34; // eax
  CarAvatar *v35; // eax
  SetupFuelManager *v36; // eax
  SetupFuelManager *v37; // ecx
  TabBar *v38; // eax
  __m128 v39; // xmm1
  float v40; // xmm4_4
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  float v43; // xmm2_4
  std::wstring *v44; // eax
  CarAvatar *v45; // eax
  SetupElectronics *v46; // eax
  SetupElectronics *v47; // ecx
  int v48; // eax
  __m128 v49; // xmm1
  float v50; // xmm4_4
  __m128 v51; // xmm3
  __m128 v52; // xmm0
  float v53; // xmm2_4
  std::wstring *v54; // eax
  ICollisionObject *v55; // eax
  SetupInformation *v56; // eax
  SetupInformation *v57; // ecx
  SetupIOManager *v58; // eax
  __m128 v59; // xmm1
  float v60; // xmm4_4
  __m128 v61; // xmm3
  __m128 v62; // xmm0
  float v63; // xmm2_4
  ICollisionObject *v64; // eax
  TabBar *v65; // eax
  Sim *v66; // eax
  CarAvatar *v67; // eax
  SetupPitstopPresets *v68; // eax
  SetupPitstopPresets *v69; // ecx
  TabBar *v70; // eax
  __m128 v71; // xmm3
  float v72; // xmm2_4
  __m128 v73; // xmm4
  __m128 v74; // xmm0
  float v75; // xmm1_4
  std::wstring *v76; // eax
  TabBar *v77; // eax
  TabBar *v78; // edi
  unsigned int v79; // eax
  std::wstring *v80; // eax
  std::wstring *v81; // eax
  bool v82; // cf
  TabBar *v83; // edi
  char v84; // al
  std::wstring *v85; // eax
  std::wstring *v86; // eax
  std::wstring v87; // [esp-14h] [ebp-9Ch] BYREF
  float top; // [esp+4h] [ebp-84h]
  TabBar *v89; // [esp+18h] [ebp-70h]
  unsigned int v90; // [esp+1Ch] [ebp-6Ch]
  ICollisionObject *_Val; // [esp+20h] [ebp-68h] BYREF
  char v92; // [esp+27h] [ebp-61h]
  Sim *aSim; // [esp+28h] [ebp-60h]
  TabBar *v94; // [esp+2Ch] [ebp-5Ch] BYREF
  std::wstring result; // [esp+30h] [ebp-58h] BYREF
  std::wstring name; // [esp+48h] [ebp-40h] BYREF
  std::wstring iname; // [esp+60h] [ebp-28h] BYREF
  int v98; // [esp+84h] [ebp-4h]

  aSim = sim;
  v3 = 0;
  v90 = 0;
  v89 = (TabBar *)this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"SETUP_SCREEN", 0xCu);
  v98 = 0;
  ksgui::Control::Control(this, &iname, sim->game->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (SetupScreen_vtbl *)&SetupScreen::`vftable';
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  this->sim = 0;
  this->tabBar = 0;
  this->tabs._Myfirst = 0;
  this->tabs._Mylast = 0;
  this->tabs._Myend = 0;
  LOBYTE(v98) = 4;
  this->setupInfo = 0;
  this->ioManager = 0;
  this->gearManager = 0;
  top = 0.0;
  this->tyresManager = 0;
  this->fuelManager = 0;
  this->electronicsManager = 0;
  this->pitstopManager = 0;
  this->backColor = 0i64;
  ksgui::Form::setPosition((ksgui::Form *)this, 100.0, top);
  LODWORD(top) = 380;
  this->sim = aSim;
  this->visible = 0;
  *(_WORD *)&this->drawBorder = 0;
  v94 = (TabBar *)operator new(LODWORD(top));
  LOBYTE(v98) = 5;
  if ( v94 )
  {
    top = *(float *)&this->gui;
    v87._Myres = 7;
    v87._Mysize = 0;
    v87._Bx._Buf[0] = 0;
    std::wstring::assign(&v87, L"TAB BAR", 7u);
    TabBar::TabBar(v94, v87, (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v4 = 0;
  }
  LODWORD(top) = v4;
  LOBYTE(v98) = 4;
  this->tabBar = v4;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(top));
  LODWORD(top) = this;
  v87._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_f3bf81b48c9e50cc0a810c999e0f6e84_,0>,std::allocator<std::_Func_class<void,OnCellSelected const &>>,void,OnCellSelected const &>::`vftable';
  *(_DWORD *)&v87._Bx._Alias[4] = this;
  v87._Mysize = (unsigned int)&v87;
  v5 = (Event<ksgui::OnListBoxItemClickedEvent> *)&this->tabBar->evOnCellSelected;
  LOBYTE(v98) = 4;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    v5,
    (std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)>)v87,
    this);
  v6 = (ICollisionObject *)operator new(428);
  _Val = v6;
  LOBYTE(v98) = 7;
  if ( v6 )
  {
    SetupIOManager::SetupIOManager((SetupIOManager *)v6, aSim);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = this->tabBar;
  this->ioManager = v8;
  v10 = v9->rect.left;
  v11.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v10);
  LOBYTE(v98) = 4;
  v12.m128_i32[0] = LODWORD(v10) ^ LODWORD(FLOAT_N0_0) & LODWORD(v10);
  LODWORD(v13) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v12, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v10);
  v12.m128_f32[0] = (float)((float)(v10 + v13) - v13) - v10;
  ksgui::Form::setPosition(
    (ksgui::Form *)v8,
    (float)((float)(v10 + v13) - v13) - COERCE_FLOAT(_mm_cmpgt_ss(v12, v11).m128_u32[0] & LODWORD(FLOAT_1_0)),
    65.0);
  LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
  v14 = &this->ioManager->name;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  std::wstring::assign(&v87, v14, 0, 0xFFFFFFFF);
  TabBar::addTab(this->tabBar, v87, LODWORD(top));
  v94 = (TabBar *)this->ioManager;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tabs, (ICollisionObject *const *)&v94);
  SetupIOManager::setSelectedTrack(this->ioManager, &aSim->track->name);
  v94 = (TabBar *)operator new(352);
  LOBYTE(v98) = 8;
  if ( v94 )
  {
    v15 = Sim::getCar(aSim, 0);
    SetupGearManager::SetupGearManager((SetupGearManager *)v94, v15);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  v18 = this->tabBar;
  v19.m128_f32[0] = FLOAT_8388608_0;
  this->gearManager = v17;
  v20 = v18->rect.left;
  v21.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v20);
  LOBYTE(v98) = 4;
  v22.m128_i32[0] = LODWORD(v20) ^ LODWORD(FLOAT_N0_0) & LODWORD(v20);
  v22.m128_f32[0] = _mm_cmplt_ss(v22, v19).m128_f32[0];
  v23 = (float)(v20 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v22.m128_i32[0] | v21.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v22.m128_i32[0] | v21.m128_i32[0]);
  v22.m128_f32[0] = v23 - v20;
  ksgui::Form::setPosition(
    (ksgui::Form *)v17,
    v23 - COERCE_FLOAT(_mm_cmpgt_ss(v22, v21).m128_u32[0] & LODWORD(FLOAT_1_0)),
    65.0);
  LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
  v24 = &this->gearManager->name;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  std::wstring::assign(&v87, v24, 0, 0xFFFFFFFF);
  TabBar::addTab(this->tabBar, v87, LODWORD(top));
  v94 = (TabBar *)this->gearManager;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tabs, (ICollisionObject *const *)&v94);
  ksgui::Control::setVisible(this->gearManager, 0);
  v94 = (TabBar *)operator new(328);
  LOBYTE(v98) = 9;
  if ( v94 )
  {
    v25 = Sim::getCar(aSim, 0);
    SetupTyresManager::SetupTyresManager((SetupTyresManager *)v94, v25);
    v27 = v26;
  }
  else
  {
    v27 = 0;
  }
  v28 = this->tabBar;
  v29.m128_f32[0] = FLOAT_8388608_0;
  this->tyresManager = v27;
  v30 = v28->rect.left;
  v31.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v30);
  LOBYTE(v98) = 4;
  v32.m128_i32[0] = LODWORD(v30) ^ LODWORD(FLOAT_N0_0) & LODWORD(v30);
  v32.m128_f32[0] = _mm_cmplt_ss(v32, v29).m128_f32[0];
  v33 = (float)(v30 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v32.m128_i32[0] | v31.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v32.m128_i32[0] | v31.m128_i32[0]);
  v32.m128_f32[0] = v33 - v30;
  ksgui::Form::setPosition(
    (ksgui::Form *)v27,
    v33 - COERCE_FLOAT(_mm_cmpgt_ss(v32, v31).m128_u32[0] & LODWORD(FLOAT_1_0)),
    65.0);
  LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
  v34 = &this->tyresManager->name;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  std::wstring::assign(&v87, v34, 0, 0xFFFFFFFF);
  TabBar::addTab(this->tabBar, v87, LODWORD(top));
  v94 = (TabBar *)this->tyresManager;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tabs, (ICollisionObject *const *)&v94);
  ksgui::Control::setVisible(this->tyresManager, 0);
  v94 = (TabBar *)operator new(380);
  LOBYTE(v98) = 10;
  if ( v94 )
  {
    v35 = Sim::getCar(aSim, 0);
    SetupFuelManager::SetupFuelManager((SetupFuelManager *)v94, v35);
    v37 = v36;
  }
  else
  {
    v37 = 0;
  }
  v38 = this->tabBar;
  v39.m128_f32[0] = FLOAT_8388608_0;
  this->fuelManager = v37;
  v40 = v38->rect.left;
  v41.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v40);
  LOBYTE(v98) = 4;
  v42.m128_i32[0] = LODWORD(v40) ^ LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v42.m128_f32[0] = _mm_cmplt_ss(v42, v39).m128_f32[0];
  v43 = (float)(v40 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v42.m128_i32[0] | v41.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v42.m128_i32[0] | v41.m128_i32[0]);
  v42.m128_f32[0] = v43 - v40;
  ksgui::Form::setPosition(
    (ksgui::Form *)v37,
    v43 - COERCE_FLOAT(_mm_cmpgt_ss(v42, v41).m128_u32[0] & LODWORD(FLOAT_1_0)),
    65.0);
  LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
  v44 = &this->fuelManager->name;
  v87._Myres = 7;
  v87._Mysize = 0;
  v87._Bx._Buf[0] = 0;
  std::wstring::assign(&v87, v44, 0, 0xFFFFFFFF);
  TabBar::addTab(this->tabBar, v87, LODWORD(top));
  v94 = (TabBar *)this->fuelManager;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tabs, (ICollisionObject *const *)&v94);
  ksgui::Control::setVisible(this->fuelManager, 0);
  v94 = (TabBar *)operator new(340);
  LOBYTE(v98) = 11;
  if ( v94 )
  {
    v45 = Sim::getCar(aSim, 0);
    SetupElectronics::SetupElectronics((SetupElectronics *)v94, v45);
    v47 = v46;
  }
  else
  {
    v47 = 0;
  }
  this->electronicsManager = v47;
  v48 = (char *)v47->spinnerDatas._Mylast - (char *)v47->spinnerDatas._Myfirst;
  LOBYTE(v98) = 4;
  if ( (v48 & 0xFFFFFFFC) != 0 )
  {
    v49.m128_f32[0] = FLOAT_8388608_0;
    v50 = this->tabBar->rect.left;
    v51.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v50);
    v52.m128_i32[0] = LODWORD(v50) ^ LODWORD(FLOAT_N0_0) & LODWORD(v50);
    v52.m128_f32[0] = _mm_cmplt_ss(v52, v49).m128_f32[0];
    v53 = (float)(v50 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v52.m128_i32[0] | v51.m128_i32[0]))
        - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v52.m128_i32[0] | v51.m128_i32[0]);
    v52.m128_f32[0] = v53 - v50;
    ksgui::Form::setPosition(
      (ksgui::Form *)v47,
      v53 - COERCE_FLOAT(_mm_cmpgt_ss(v52, v51).m128_u32[0] & LODWORD(FLOAT_1_0)),
      65.0);
    LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
    v54 = &this->electronicsManager->name;
    v87._Myres = 7;
    v87._Mysize = 0;
    v87._Bx._Buf[0] = 0;
    std::wstring::assign(&v87, v54, 0, 0xFFFFFFFF);
    TabBar::addTab(this->tabBar, v87, LODWORD(top));
    v94 = (TabBar *)this->electronicsManager;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->tabs,
      (ICollisionObject *const *)&v94);
  }
  ksgui::Control::setVisible(this->electronicsManager, 0);
  v55 = (ICollisionObject *)operator new(336);
  _Val = v55;
  LOBYTE(v98) = 12;
  if ( v55 )
  {
    SetupInformation::SetupInformation((SetupInformation *)v55, aSim);
    v57 = v56;
  }
  else
  {
    v57 = 0;
  }
  v58 = this->ioManager;
  v59.m128_f32[0] = FLOAT_8388608_0;
  this->setupInfo = v57;
  v60 = v58->rect.right + 100.0;
  LOBYTE(v98) = 4;
  v61.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v60);
  v62.m128_i32[0] = LODWORD(v60) ^ LODWORD(FLOAT_N0_0) & LODWORD(v60);
  v62.m128_f32[0] = _mm_cmplt_ss(v62, v59).m128_f32[0];
  v63 = (float)(v60 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v62.m128_i32[0] | v61.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v62.m128_i32[0] | v61.m128_i32[0]);
  v62.m128_f32[0] = v63 - v60;
  ksgui::Form::setPosition(
    (ksgui::Form *)v57,
    v63 - COERCE_FLOAT(_mm_cmpgt_ss(v62, v61).m128_u32[0] & LODWORD(FLOAT_1_0)),
    65.0);
  ksgui::Control::addControl(this, this->setupInfo);
  ksgui::Control::addControl(this, this->tyresManager);
  ksgui::Control::addControl(this, this->gearManager);
  ksgui::Control::addControl(this, this->ioManager);
  ksgui::Control::addControl(this, this->fuelManager);
  ksgui::Control::addControl(this, this->electronicsManager);
  if ( Sim::getCar(aSim, 0)->raceEngineer._Myptr )
  {
    if ( aSim->useMousePitstop )
    {
      v94 = v89;
    }
    else
    {
      v64 = (ICollisionObject *)operator new(292);
      _Val = v64;
      LOBYTE(v98) = 13;
      if ( v64 )
        QuickMenuPitstop::QuickMenuPitstop((QuickMenuPitstop *)v64, aSim);
      else
        v65 = 0;
      v94 = v65;
      _Val = (ICollisionObject *)v65;
      LOBYTE(v98) = 4;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&aSim->gameObjects, &_Val);
      LODWORD(v94->rect.top) = aSim;
    }
    SetupScreen::loadINI(this);
    SetupScreen::resetTabsValueToDefault(this);
    v66 = aSim;
    if ( !aSim->useMousePitstop )
    {
      _Val = (ICollisionObject *)operator new(372);
      LOBYTE(v98) = 14;
      if ( _Val )
      {
        LODWORD(top) = v94;
        v67 = Sim::getCar(aSim, 0);
        SetupPitstopPresets::SetupPitstopPresets((SetupPitstopPresets *)_Val, v67, (QuickMenuPitstop *)LODWORD(top));
        v69 = v68;
      }
      else
      {
        v69 = 0;
      }
      v70 = this->tabBar;
      v71.m128_f32[0] = FLOAT_8388608_0;
      this->pitstopManager = v69;
      v72 = v70->rect.left;
      v73.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v72);
      LOBYTE(v98) = 4;
      v74.m128_i32[0] = LODWORD(v72) ^ LODWORD(FLOAT_N0_0) & LODWORD(v72);
      v74.m128_f32[0] = _mm_cmplt_ss(v74, v71).m128_f32[0];
      v75 = (float)(v72 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v74.m128_i32[0] | v73.m128_i32[0]))
          - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v74.m128_i32[0] | v73.m128_i32[0]);
      v74.m128_f32[0] = v75 - v72;
      ksgui::Form::setPosition(
        (ksgui::Form *)v69,
        v75 - COERCE_FLOAT(_mm_cmpgt_ss(v74, v73).m128_u32[0] & LODWORD(FLOAT_1_0)),
        65.0);
      LODWORD(top) = this->tabs._Mylast - this->tabs._Myfirst;
      v76 = &this->pitstopManager->name;
      v87._Myres = 7;
      v87._Mysize = 0;
      v87._Bx._Buf[0] = 0;
      std::wstring::assign(&v87, v76, 0, 0xFFFFFFFF);
      TabBar::addTab(this->tabBar, v87, LODWORD(top));
      _Val = (ICollisionObject *)this->pitstopManager;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tabs, &_Val);
      ksgui::Control::setVisible(this->pitstopManager, 0);
      ksgui::Control::addControl(this, this->pitstopManager);
      v66 = aSim;
    }
    v77 = (TabBar *)Sim::getCar(v66, 0)->physics;
    v94 = v77;
    if ( !LOBYTE(v77[29].highlightTextColor.x) )
    {
LABEL_60:
      if ( !LOBYTE(v77[29].tag) )
        return;
      if ( *(float *)(*(_DWORD *)(LODWORD(v77[22].fontScale) + 8) + 4) == 0.0
        && (std::wstring::wstring(&name, L"ROD_LENGTH_LR"),
            v3 |= 4u,
            LOBYTE(v98) = 19,
            aSim = (Sim *)v3,
            v90 = v3,
            !SetupManager::getSetupItem((SetupManager *)&v94[26].topIndex, &name)->attached) )
      {
        v83 = v94;
      }
      else
      {
        std::wstring::wstring(&iname, L"ROD_LENGTH_HR");
        v98 = 20;
        v90 = v3 | 8;
        aSim = (Sim *)(v3 | 8);
        v83 = v94;
        if ( SetupManager::getSetupItem((SetupManager *)&v94[26].topIndex, &iname)->attached )
        {
          v92 = 1;
LABEL_67:
          v84 = (char)aSim;
          if ( ((unsigned __int8)aSim & 8) != 0 )
          {
            v84 = (unsigned __int8)aSim & 0xF7;
            aSim = (Sim *)((unsigned int)aSim & 0xFFFFFFF7);
            if ( iname._Myres >= 8 )
            {
              operator delete(iname._Bx._Ptr);
              v84 = (char)aSim;
            }
            iname._Myres = 7;
            iname._Mysize = 0;
            iname._Bx._Buf[0] = 0;
          }
          v98 = 4;
          if ( (v84 & 4) != 0 && name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
          if ( v92 )
          {
            v85 = std::operator+<wchar_t>(&result, L"ERROR: Car ", (const std::wstring *)&v83->isHighlight);
            LOBYTE(v98) = 21;
            v86 = std::operator+<wchar_t>(
                    &name,
                    v85,
                    L" cannot have setup items for ROD_LENGTH_HR when a rear suspension is also present");
            v82 = v86->_Myres < 8;
            LOBYTE(v98) = 22;
            if ( !v82 )
              v86 = (std::wstring *)v86->_Bx._Ptr;
            _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v86->_Bx._Buf);
            ksGenerateCrash();
            if ( name._Myres >= 8 )
              operator delete(name._Bx._Ptr);
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            if ( result._Myres >= 8 )
              operator delete(result._Bx._Ptr);
          }
          return;
        }
      }
      v92 = 0;
      goto LABEL_67;
    }
    if ( *(float *)(*(_DWORD *)LODWORD(v77[22].fontScale) + 4) == 0.0
      && (std::wstring::wstring(&name, L"ROD_LENGTH_LF"),
          v3 = 1,
          LOBYTE(v98) = 15,
          aSim = (Sim *)1,
          v90 = 1,
          !SetupManager::getSetupItem((SetupManager *)&v94[26].topIndex, &name)->attached) )
    {
      v78 = v94;
    }
    else
    {
      std::wstring::wstring(&iname, L"ROD_LENGTH_HF");
      v98 = 16;
      v90 = v3 | 2;
      aSim = (Sim *)(v3 | 2);
      v78 = v94;
      if ( SetupManager::getSetupItem((SetupManager *)&v94[26].topIndex, &iname)->attached )
      {
        v92 = 1;
LABEL_45:
        v79 = (unsigned int)aSim;
        if ( ((unsigned __int8)aSim & 2) != 0 )
        {
          v79 = (unsigned int)aSim & 0xFFFFFFFD;
          aSim = (Sim *)v79;
          v90 = v79;
          if ( iname._Myres >= 8 )
          {
            operator delete(iname._Bx._Ptr);
            v79 = (unsigned int)aSim;
          }
          iname._Myres = 7;
          iname._Mysize = 0;
          iname._Bx._Buf[0] = 0;
        }
        v98 = 4;
        if ( (v79 & 1) != 0 )
        {
          aSim = (Sim *)(v79 & 0xFFFFFFFE);
          v90 = v79 & 0xFFFFFFFE;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
        }
        if ( v92 )
        {
          v80 = std::operator+<wchar_t>(&name, L"ERROR: Car ", (const std::wstring *)&v78->isHighlight);
          LOBYTE(v98) = 17;
          v81 = std::operator+<wchar_t>(
                  &iname,
                  v80,
                  L" cannot have setup items for ROD_LENGTH_HF when a front suspension is also present");
          v82 = v81->_Myres < 8;
          LOBYTE(v98) = 18;
          if ( !v82 )
            v81 = (std::wstring *)v81->_Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v81->_Bx._Buf);
          ksGenerateCrash();
          if ( iname._Myres >= 8 )
            operator delete(iname._Bx._Ptr);
          iname._Myres = 7;
          iname._Mysize = 0;
          iname._Bx._Buf[0] = 0;
          LOBYTE(v98) = 4;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
        }
        v3 = (int)aSim;
        v77 = v94;
        goto LABEL_60;
      }
    }
    v92 = 0;
    goto LABEL_45;
  }
}
void SetupScreen::~SetupScreen(SetupScreen *this)
{
  std::vector<SetupTab *> *v2; // edi

  v2 = &this->tabs;
  this->__vftable = (SetupScreen_vtbl *)&SetupScreen::`vftable';
  if ( this->tabs._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->tabs);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  if ( this->carName._Myres >= 8 )
    operator delete(this->carName._Bx._Ptr);
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  ksgui::Control::~Control(this);
}
SetupScreen *SetupScreen::`vector deleting destructor'(SetupScreen *this, unsigned int a2)
{
  SetupScreen::~SetupScreen(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double SetupScreen::getFixedFuel(SetupScreen *this)
{
  return SetupFuelManager::getSetupFuel(this->fuelManager);
}
SetupTab *SetupScreen::getSetupTab(SetupScreen *this, std::wstring name)
{
  SetupTab **v2; // esi
  std::vector<ICollisionObject *> *v3; // ebx
  SetupTab **v4; // edi
  SetupTab *v5; // ebp
  std::wstring *v6; // eax
  std::wstring *v7; // ecx
  SetupTab *v8; // esi
  TabBar **v9; // edi
  SetupTab *v10; // eax
  ICollisionObject **v11; // eax
  int v12; // esi
  ICollisionObject **v13; // ecx
  _DWORD *v14; // eax
  float v15; // xmm3_4
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  float v18; // xmm2_4
  _BYTE v20[28]; // [esp-18h] [ebp-4Ch] BYREF
  float top; // [esp+4h] [ebp-30h]
  SetupScreen *v22; // [esp+1Ch] [ebp-18h]
  SetupTab *nt[2]; // [esp+20h] [ebp-14h] BYREF
  int v24; // [esp+30h] [ebp-4h]

  v22 = this;
  v2 = this->tabs._Myfirst;
  v3 = (std::vector<ICollisionObject *> *)&this->tabs;
  v4 = this->tabs._Mylast;
  v24 = 0;
  if ( v2 == v4 )
  {
LABEL_6:
    v8 = (SetupTab *)operator new(316);
    nt[1] = v8;
    v9 = (TabBar **)v22;
    LOBYTE(v24) = 1;
    if ( v8 )
    {
      top = *(float *)&v22->sim;
      *(_DWORD *)&v20[24] = *(_DWORD *)(*(_DWORD *)(LODWORD(top) + 4) + 252);
      *(_DWORD *)&v20[20] = 7;
      *(_DWORD *)&v20[16] = 0;
      *(_WORD *)v20 = 0;
      std::wstring::assign((std::wstring *)v20, &name, 0, 0xFFFFFFFF);
      SetupTab::SetupTab(v8, *(std::wstring *)v20, *(ksgui::GUI **)&v20[24], (Sim *)LODWORD(top));
      v5 = v10;
    }
    else
    {
      v5 = 0;
    }
    LOBYTE(v24) = 0;
    nt[0] = v5;
    ksgui::Control::setVisible(v5, 0);
    LODWORD(top) = v3->_Mylast - v3->_Myfirst;
    *(_DWORD *)&v20[24] = 7;
    *(_DWORD *)&v20[20] = 0;
    *(_WORD *)&v20[4] = 0;
    std::wstring::assign((std::wstring *)&v20[4], &name, 0, 0xFFFFFFFF);
    TabBar::addTab(v9[77], *(std::wstring *)&v20[4], LODWORD(top));
    v11 = v3->_Mylast;
    if ( nt >= (SetupTab **)v11 || v3->_Myfirst > (ICollisionObject **)nt )
    {
      if ( v11 == v3->_Myend )
        std::vector<SVar *>::_Reserve(v3, 1u);
      v14 = v3->_Mylast;
      if ( v14 )
        *v14 = v5;
    }
    else
    {
      v12 = ((char *)nt - (char *)v3->_Myfirst) >> 2;
      if ( v11 == v3->_Myend )
        std::vector<SVar *>::_Reserve(v3, 1u);
      v13 = v3->_Mylast;
      if ( v13 )
        *v13 = v3->_Myfirst[v12];
    }
    ++v3->_Mylast;
    v15 = v9[77]->rect.left;
    v16.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v15);
    v17.m128_i32[0] = LODWORD(v15) ^ LODWORD(FLOAT_N0_0) & LODWORD(v15);
    LODWORD(v18) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v17, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v15);
    v17.m128_f32[0] = (float)((float)(v15 + v18) - v18) - v15;
    ksgui::Form::setPosition(
      (ksgui::Form *)v5,
      (float)((float)(v15 + v18) - v18) - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & LODWORD(FLOAT_1_0)),
      65.0);
    (*(void (**)(TabBar **, SetupTab *))&(*v9)->name._Bx._Alias[4])(v9, v5);
  }
  else
  {
    while ( 1 )
    {
      v5 = *v2;
      v6 = &name;
      v7 = &(*v2)->name;
      top = *(float *)&name._Mysize;
      if ( name._Myres >= 8 )
        v6 = (std::wstring *)name._Bx._Ptr;
      if ( !std::wstring::compare(v7, 0, v7->_Mysize, v6->_Bx._Buf, LODWORD(top)) )
        break;
      if ( ++v2 == v4 )
        goto LABEL_6;
    }
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v5;
}
bool SetupScreen::isFixedFuel(SetupScreen *this)
{
  return SetupFuelManager::isFixedFuel(this->fuelManager);
}
void SetupScreen::loadINI(SetupScreen *this)
{
  char *v1; // edi
  Sim *v2; // ecx
  CarAvatar *v3; // eax
  std::wstring *v4; // eax
  Sim *v5; // ecx
  std::wstring *v6; // eax
  int v7; // eax
  _DWORD *v8; // esi
  QuickMenuPitstop *v9; // eax
  char v10; // al
  int v11; // eax
  CarAvatar *v12; // eax
  SetupManager *v13; // eax
  SetupItem *v14; // esi
  SetupItem *v15; // edi
  const std::wstring *v16; // eax
  const std::wstring *v17; // eax
  std::wstring *v18; // eax
  SetupItemDef *v19; // eax
  SetupItemDef *v20; // eax
  double v21; // st7
  double v22; // st7
  int v23; // eax
  SetupItemDef *v24; // eax
  char v25; // al
  int v26; // esi
  std::wostream *v27; // eax
  const std::wstring *v28; // eax
  char v29; // al
  Sim *v30; // ecx
  int v31; // edi
  int v32; // esi
  std::wostream *v33; // eax
  std::wostream *v34; // eax
  GearDef *v35; // esi
  const std::wstring *v36; // esi
  const std::wstring *v37; // eax
  CarAvatar *v38; // eax
  const std::wstring *v39; // eax
  std::wstring *v40; // eax
  std::wostream *v41; // eax
  int v42; // esi
  std::wostream *v43; // eax
  const std::wstring *v44; // eax
  std::wostream *v45; // eax
  const std::wstring *v46; // eax
  std::wstring *v47; // eax
  const std::wstring *v48; // eax
  std::wstring *v49; // eax
  const std::wstring *v50; // eax
  std::wstring *v51; // eax
  const std::wstring *v52; // eax
  std::wstring *v53; // edi
  std::wstring *v54; // eax
  std::wstring *v55; // esi
  CarAvatar *v56; // eax
  std::wstring *v57; // eax
  std::wstring *v58; // eax
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  std::wstring *v61; // eax
  std::wstring *v62; // eax
  Sim *v63; // ecx
  std::wstring *v64; // eax
  std::wstring *v65; // eax
  std::wstring *v66; // eax
  std::wstring *v67; // edi
  std::wstring *v68; // eax
  std::wstring *v69; // esi
  CarAvatar *v70; // eax
  std::wstring *v71; // eax
  std::wstring *v72; // eax
  std::wstring *v73; // eax
  TyreCompoundDef *v74; // eax
  unsigned int v75; // esi
  const std::wstring *v76; // eax
  TabBar *v77; // esi
  int v78; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *v79; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *v80; // esi
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *v81; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *v82; // eax
  _BYTE v83[36]; // [esp-24h] [ebp-60Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v84; // [esp+1Ch] [ebp-5CCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v85; // [esp+CCh] [ebp-51Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v86; // [esp+17Ch] [ebp-46Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v87; // [esp+22Ch] [ebp-3BCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v88; // [esp+2DCh] [ebp-30Ch] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > v89; // [esp+38Ch] [ebp-25Ch] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > v90; // [esp+390h] [ebp-258h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > v91; // [esp+394h] [ebp-254h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > v92; // [esp+398h] [ebp-250h] BYREF
  std::wstring *id; // [esp+39Ch] [ebp-24Ch]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > absoluteGearIndex; // [esp+3A0h] [ebp-248h] BYREF
  bool v95; // [esp+3A7h] [ebp-241h] BYREF
  SetupItemDef v96; // [esp+3A8h] [ebp-240h] BYREF
  std::wstring ifilename; // [esp+408h] [ebp-1E0h] BYREF
  std::wstring v98; // [esp+420h] [ebp-1C8h] BYREF
  DriverInfo v99; // [esp+438h] [ebp-1B0h] BYREF
  std::wstring result; // [esp+498h] [ebp-150h] BYREF
  std::wstring _Left; // [esp+4B0h] [ebp-138h] BYREF
  INIReader carsetup; // [esp+4C8h] [ebp-120h] BYREF
  GearDef v103; // [esp+50Ch] [ebp-DCh] BYREF
  std::wstring _Right; // [esp+530h] [ebp-B8h] BYREF
  std::wstring v105; // [esp+548h] [ebp-A0h] BYREF
  std::wstring v106; // [esp+560h] [ebp-88h] BYREF
  std::wstring v107; // [esp+578h] [ebp-70h] BYREF
  std::wstring v108; // [esp+590h] [ebp-58h] BYREF
  std::wstring section; // [esp+5A8h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement key; // [esp+5C0h] [ebp-28h] BYREF
  int v111; // [esp+5E4h] [ebp-4h]

  v1 = (char *)this;
  v90._Ptr = (TyreCompoundDef *)this;
  v91._Ptr = 0;
  _printf("Loading setup.ini\n");
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v2 = (Sim *)*((_DWORD *)v1 + 76);
  v111 = 0;
  v3 = Sim::getCar(v2, 0);
  v4 = std::operator+<wchar_t>(&result, &_Left, &v3->unixName);
  LOBYTE(v111) = 1;
  std::operator+<wchar_t>(&ifilename, v4, L"/data/setup.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v111) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v5 = (Sim *)*((_DWORD *)v1 + 76);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  v6 = &Sim::getCar(v5, 0)->unixName;
  if ( v1 + 280 != (char *)v6 )
    std::wstring::assign((std::wstring *)(v1 + 280), v6, 0, 0xFFFFFFFF);
  INIReader::INIReader(&carsetup, &ifilename);
  v7 = *((_DWORD *)v1 + 76);
  LOBYTE(v111) = 5;
  absoluteGearIndex._Ptr = (TyreCompoundDef *)v7;
  v8 = *(_DWORD **)(v7 + 40);
  if ( v8 == *(_DWORD **)(v7 + 44) )
  {
LABEL_10:
    v9 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = (QuickMenuPitstop *)__RTDynamicCast(
                                 *v8,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &QuickMenuPitstop `RTTI Type Descriptor',
                                 0);
      if ( v9 )
        break;
      if ( ++v8 == (_DWORD *)absoluteGearIndex._Ptr->shortName._Mysize )
        goto LABEL_10;
    }
  }
  if ( carsetup.ready )
  {
    if ( v9 )
      QuickMenuPitstop::buildControls(v9, &carsetup);
    LOBYTE(absoluteGearIndex._Ptr) = 0;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GEARS", 5u);
    LOBYTE(v111) = 6;
    v10 = INIReader::hasSection(&carsetup, &section);
    v95 = v10;
    LOBYTE(v111) = 5;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v10 = v95;
    }
    if ( v10 )
    {
      std::wstring::wstring(&key.name, L"USE_GEARSET");
      LOBYTE(v111) = 7;
      std::wstring::wstring(&section, L"GEARS");
      LOBYTE(v111) = 8;
      v95 = INIReader::getInt(&carsetup, &section, &key.name) > 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v111) = 5;
      if ( key.name._Myres >= 8 )
        operator delete(key.name._Bx._Ptr);
      v11 = LOBYTE(absoluteGearIndex._Ptr);
      if ( v95 )
        v11 = 1;
      absoluteGearIndex._Ptr = (TyreCompoundDef *)v11;
    }
    v12 = Sim::getCar(*((Sim **)v1 + 76), 0);
    v13 = CarAvatar::getSetupManager(v12);
    v14 = v13->items._Myfirst;
    v15 = v13->items._Mylast;
    if ( v13->items._Myfirst != v15 )
    {
      v16 = &v14->name;
      id = &v14->name;
      do
      {
        if ( INIReader::hasSection(&carsetup, v16) )
        {
          v106._Myres = 7;
          v106._Mysize = 0;
          v106._Bx._Buf[0] = 0;
          std::wstring::assign(&v106, L"TAB", 3u);
          LOBYTE(v111) = 9;
          v17 = INIReader::getString(&carsetup, &v108, id, &v106);
          LOBYTE(v111) = 10;
          acLocaleGetString(&_Right, v17);
          if ( v108._Myres >= 8 )
            operator delete(v108._Bx._Ptr);
          v108._Myres = 7;
          v108._Mysize = 0;
          v108._Bx._Buf[0] = 0;
          LOBYTE(v111) = 13;
          if ( v106._Myres >= 8 )
            operator delete(v106._Bx._Ptr);
          v106._Myres = 7;
          v106._Mysize = 0;
          v106._Bx._Buf[0] = 0;
          if ( !std::wstring::compare(&_Right, 0, _Right._Mysize, word_17BE9D8, 0) )
          {
            section._Myres = 7;
            section._Mysize = 0;
            section._Bx._Buf[0] = 0;
            std::wstring::assign(&section, L"TAB", 3u);
            LOBYTE(v111) = 14;
            v18 = INIReader::getString(&carsetup, &v107, id, &section);
            v92._Ptr = (TyreCompoundDef *)v18;
            if ( &_Right != v18 )
            {
              if ( _Right._Myres >= 8 )
              {
                operator delete(_Right._Bx._Ptr);
                v18 = (std::wstring *)v92._Ptr;
              }
              _Right._Myres = 7;
              _Right._Bx._Buf[0] = 0;
              _Right._Mysize = 0;
              std::wstring::_Assign_rv(&_Right, v18);
            }
            if ( v107._Myres >= 8 )
              operator delete(v107._Bx._Ptr);
            v107._Myres = 7;
            v107._Mysize = 0;
            v107._Bx._Buf[0] = 0;
            LOBYTE(v111) = 13;
            if ( section._Myres >= 8 )
              operator delete(section._Bx._Ptr);
          }
          *(_DWORD *)&v83[32] = 7;
          *(_DWORD *)&v83[28] = 0;
          *(_WORD *)&v83[12] = 0;
          std::wstring::assign((std::wstring *)&v83[12], &_Right, 0, 0xFFFFFFFF);
          *(float *)&v89._Ptr = COERCE_FLOAT(SetupScreen::getSetupTab((SetupScreen *)v90._Ptr, *(std::wstring *)&v83[12]));
          *(_OWORD *)&v96.minValue = _xmm;
          v96.name._Myres = 7;
          v96.name._Mysize = 0;
          v96.name._Bx._Buf[0] = 0;
          v96.connection = 0;
          v96.step = DOUBLE_1_0;
          v96.px = 0.0;
          v96.py = 0.0;
          v96.defaultValue = 0;
          v96.helpKey._Myres = 7;
          v96.helpKey._Mysize = 0;
          v96.helpKey._Bx._Buf[0] = 0;
          v96.showClicksMode = eShowClicksNone;
          LOBYTE(v111) = 15;
          v19 = (SetupItemDef *)acLocaleGetString(&key.name, id);
          v92._Ptr = (TyreCompoundDef *)v19;
          if ( &v96 != v19 )
          {
            if ( v96.name._Myres >= 8 )
            {
              operator delete(v96.name._Bx._Ptr);
              v19 = (SetupItemDef *)v92._Ptr;
            }
            v96.name._Myres = 7;
            v96.name._Bx._Buf[0] = 0;
            v96.name._Mysize = 0;
            std::wstring::_Assign_rv(&v96.name, &v19->name);
          }
          if ( key.name._Myres >= 8 )
            operator delete(key.name._Bx._Ptr);
          if ( !std::wstring::compare(&v96.name, 0, v96.name._Mysize, word_17BE9D8, 0) )
          {
            section._Myres = 7;
            section._Mysize = 0;
            section._Bx._Buf[0] = 0;
            std::wstring::assign(&section, L"NAME", 4u);
            LOBYTE(v111) = 16;
            v20 = (SetupItemDef *)INIReader::getString(&carsetup, &v108, id, &section);
            v92._Ptr = (TyreCompoundDef *)v20;
            if ( &v96 != v20 )
            {
              if ( v96.name._Myres >= 8 )
              {
                operator delete(v96.name._Bx._Ptr);
                v20 = (SetupItemDef *)v92._Ptr;
              }
              v96.name._Myres = 7;
              v96.name._Bx._Buf[0] = 0;
              v96.name._Mysize = 0;
              std::wstring::_Assign_rv(&v96.name, &v20->name);
            }
            if ( v108._Myres >= 8 )
              operator delete(v108._Bx._Ptr);
            v108._Myres = 7;
            v108._Mysize = 0;
            v108._Bx._Buf[0] = 0;
            LOBYTE(v111) = 15;
            if ( section._Myres >= 8 )
              operator delete(section._Bx._Ptr);
          }
          *(_DWORD *)&v83[32] = 5;
          *(_DWORD *)&v83[28] = L"POS_X";
          v96.connection = v14;
          id[2]._Bx._Alias[12] = 1;
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, *(const wchar_t **)&v83[28], *(unsigned int *)&v83[32]);
          LOBYTE(v111) = 17;
          v96.px = INIReader::getFloat(&carsetup, id, &section);
          LOBYTE(v111) = 15;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"POS_Y", 5u);
          LOBYTE(v111) = 18;
          v96.py = INIReader::getFloat(&carsetup, id, &section);
          LOBYTE(v111) = 15;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"MIN", 3u);
          *(_DWORD *)&v83[32] = &section;
          *(_DWORD *)&v83[28] = id;
          LOBYTE(v111) = 19;
          v92._Ptr = (TyreCompoundDef *)(id[3]._Mysize & _xmm);
          v21 = INIReader::getFloat(&carsetup, id, &section);
          LOBYTE(v111) = 15;
          v96.minValue = v21 / *(float *)&v92._Ptr;
          if ( section._Myres >= 8 )
            operator delete(section._Bx._Ptr);
          std::wstring::wstring(&key.name, L"MAX");
          *(_DWORD *)&v83[32] = &key;
          *(_DWORD *)&v83[28] = id;
          LOBYTE(v111) = 20;
          v92._Ptr = (TyreCompoundDef *)(id[3]._Mysize & _xmm);
          v22 = INIReader::getFloat(&carsetup, id, &key.name);
          LOBYTE(v111) = 15;
          v96.maxValue = v22 / *(float *)&v92._Ptr;
          if ( key.name._Myres >= 8 )
            operator delete(key.name._Bx._Ptr);
          std::wstring::wstring(&key.name, L"STEP");
          LOBYTE(v111) = 21;
          v23 = INIReader::getInt(&carsetup, id, &key.name);
          LOBYTE(v111) = 15;
          v96.step = (double)v23;
          if ( key.name._Myres >= 8 )
            operator delete(key.name._Bx._Ptr);
          std::wstring::wstring(&key.name, L"HELP");
          LOBYTE(v111) = 22;
          v24 = (SetupItemDef *)INIReader::getString(&carsetup, &v108, id, &key.name);
          v92._Ptr = (TyreCompoundDef *)v24;
          if ( &v96.helpKey != (std::wstring *)v24 )
          {
            if ( v96.helpKey._Myres >= 8 )
            {
              operator delete(v96.helpKey._Bx._Ptr);
              v24 = (SetupItemDef *)v92._Ptr;
            }
            v96.helpKey._Myres = 7;
            v96.helpKey._Bx._Buf[0] = 0;
            v96.helpKey._Mysize = 0;
            std::wstring::_Assign_rv(&v96.helpKey, &v24->name);
          }
          if ( v108._Myres >= 8 )
            operator delete(v108._Bx._Ptr);
          v108._Myres = 7;
          v108._Mysize = 0;
          v108._Bx._Buf[0] = 0;
          LOBYTE(v111) = 15;
          if ( key.name._Myres >= 8 )
            operator delete(key.name._Bx._Ptr);
          v96.showClicksMode = eShowClicksNone;
          std::wstring::wstring(&key.name, L"DISPLAY_METHOD");
          LOBYTE(v111) = 23;
          v25 = INIReader::hasSection(&carsetup, &key.name);
          v95 = v25;
          LOBYTE(v111) = 15;
          if ( key.name._Myres >= 8 )
          {
            operator delete(key.name._Bx._Ptr);
            v25 = v95;
          }
          if ( v25 )
          {
            std::wstring::wstring(&key.name, L"SHOW_CLICKS");
            LOBYTE(v111) = 24;
            v96.showClicksMode = INIReader::getInt(&carsetup, id, &key.name);
            LOBYTE(v111) = 15;
            if ( key.name._Myres >= 8 )
              operator delete(key.name._Bx._Ptr);
          }
          SetupTab::addItem((SetupTab *)v89._Ptr, &v96);
          SetupItemDef::~SetupItemDef(&v96);
          LOBYTE(v111) = 5;
          if ( _Right._Myres >= 8 )
            operator delete(_Right._Bx._Ptr);
        }
        ++v14;
        v16 = (std::wstring *)((char *)id + 104);
        id = (std::wstring *)((char *)id + 104);
      }
      while ( v14 != v15 );
    }
    if ( LOBYTE(absoluteGearIndex._Ptr) )
    {
      *(_DWORD *)v86.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      absoluteGearIndex._Ptr = 0;
      *(_DWORD *)v86.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v86.gap68);
      LOBYTE(v111) = 25;
      v26 = 1;
      v91._Ptr = (TyreCompoundDef *)1;
      std::wiostream::basic_iostream<wchar_t>(&v86, &v86.gap10[8], 0);
      v111 = 26;
      *(_DWORD *)&v86.gap0[*(_DWORD *)(*(_DWORD *)v86.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v85.gap68[*(_DWORD *)(*(_DWORD *)v86.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v86.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v86.gap10[8]);
      *(_DWORD *)&v86.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v86.gap10[64] = 0;
      *(_DWORD *)&v86.gap10[68] = 0;
      *(_DWORD *)&v83[32] = 0;
      LOBYTE(v111) = 28;
      v27 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v86.gap10, "GEAR_SET_");
      std::wostream::operator<<(v27, *(_DWORD *)&v83[32]);
      v1 = (char *)v90._Ptr;
      while ( 1 )
      {
        v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v86, &key.name);
        LOBYTE(v111) = 29;
        v29 = INIReader::hasSection(&carsetup, v28);
        v95 = v29;
        if ( key.name._Myres >= 8 )
        {
          operator delete(key.name._Bx._Ptr);
          v29 = v95;
        }
        if ( !v29 )
          break;
        *(_DWORD *)&v106._Bx._Alias[12] = 0;
        v106._Mysize = 0;
        v106._Myres = 0;
        v30 = (Sim *)*((_DWORD *)v1 + 76);
        LOBYTE(v111) = 30;
        if ( Sim::getCar(v30, 0)->physicsInfo.maxGear > 0 )
        {
          v31 = 2;
          do
          {
            v103.setupManagerName._Myres = 7;
            v103.setupManagerName._Mysize = 0;
            v103.setupManagerName._Bx._Buf[0] = 0;
            v103.values._Myfirst = 0;
            v103.values._Mylast = 0;
            v103.values._Myend = 0;
            LOBYTE(v111) = 31;
            *(_DWORD *)v88.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v88.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v88.gap68);
            LOBYTE(v111) = 32;
            v32 = v26 | 2;
            v91._Ptr = (TyreCompoundDef *)v32;
            std::wiostream::basic_iostream<wchar_t>(&v88, &v88.gap10[8], 0);
            v111 = 33;
            *(_DWORD *)&v88.gap0[*(_DWORD *)(*(_DWORD *)v88.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v87.gap68[*(_DWORD *)(*(_DWORD *)v88.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v88.gap0 + 4)
                                                                             - 104;
            std::wstreambuf::wstreambuf(&v88.gap10[8]);
            *(_DWORD *)&v88.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v88.gap10[64] = 0;
            *(_DWORD *)&v88.gap10[68] = 0;
            LOBYTE(v111) = 35;
            *(_DWORD *)&v83[32] = v31 - 1;
            v33 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v88.gap10, "GEAR_");
            std::wostream::operator<<(v33, *(_DWORD *)&v83[32]);
            *(_DWORD *)v87.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v87.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v87.gap68);
            LOBYTE(v111) = 36;
            v91._Ptr = (TyreCompoundDef *)(v32 | 4);
            std::wiostream::basic_iostream<wchar_t>(&v87, &v87.gap10[8], 0);
            v111 = 37;
            *(_DWORD *)&v87.gap0[*(_DWORD *)(*(_DWORD *)v87.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v86.gap68[*(_DWORD *)(*(_DWORD *)v87.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v87.gap0 + 4)
                                                                             - 104;
            std::wstreambuf::wstreambuf(&v87.gap10[8]);
            *(_DWORD *)&v87.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v87.gap10[64] = 0;
            *(_DWORD *)&v87.gap10[68] = 0;
            *(_DWORD *)&v83[32] = v31;
            LOBYTE(v111) = 39;
            v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v87.gap10, "INTERNAL_GEAR_");
            std::wostream::operator<<(v34, *(_DWORD *)&v83[32]);
            v35 = (GearDef *)std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                               &v87,
                               &key.name);
            if ( &v103 != v35 )
            {
              if ( v103.setupManagerName._Myres >= 8 )
                operator delete(v103.setupManagerName._Bx._Ptr);
              v103.setupManagerName._Myres = 7;
              v103.setupManagerName._Mysize = 0;
              v103.setupManagerName._Bx._Buf[0] = 0;
              std::wstring::_Assign_rv(&v103.setupManagerName, &v35->setupManagerName);
            }
            if ( key.name._Myres >= 8 )
              operator delete(key.name._Bx._Ptr);
            v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                    &v88,
                    &key.name);
            LOBYTE(v111) = 40;
            v37 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v86, &v107);
            LOBYTE(v111) = 41;
            *(float *)&v89._Ptr = INIReader::getFloat(&carsetup, v37, v36);
            if ( v107._Myres >= 8 )
              operator delete(v107._Bx._Ptr);
            v107._Myres = 7;
            v107._Mysize = 0;
            v107._Bx._Buf[0] = 0;
            LOBYTE(v111) = 39;
            if ( key.name._Myres >= 8 )
              operator delete(key.name._Bx._Ptr);
            std::vector<CarAvatar *>::push_back((std::vector<int> *)&v103.values, (int *)&v89);
            std::vector<GearDef>::push_back((std::vector<GearDef> *)&v106._Bx._Alias[12], &v103);
            LOBYTE(v111) = 35;
            *(_DWORD *)&v87.gap0[*(_DWORD *)(*(_DWORD *)v87.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v86.gap68[*(_DWORD *)(*(_DWORD *)v87.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v87.gap0 + 4)
                                                                             - 104;
            *(_DWORD *)&v87.gap10[8] = &std::wstringbuf::`vftable';
            std::wstringbuf::_Tidy((std::wstringbuf *)&v87.gap10[8]);
            std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v87.gap10[8]);
            std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v87.gap10[16]);
            std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v87.gap68);
            LOBYTE(v111) = 31;
            *(_DWORD *)&v88.gap0[*(_DWORD *)(*(_DWORD *)v88.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(_DWORD *)&v87.gap68[*(_DWORD *)(*(_DWORD *)v88.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v88.gap0 + 4)
                                                                             - 104;
            *(_DWORD *)&v88.gap10[8] = &std::wstringbuf::`vftable';
            std::wstringbuf::_Tidy((std::wstringbuf *)&v88.gap10[8]);
            std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v88.gap10[8]);
            std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v88.gap10[16]);
            std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v88.gap68);
            LOBYTE(v111) = 30;
            AnimationSet::~AnimationSet((AnimationSet *)&v103);
            ++v31;
            v38 = Sim::getCar((Sim *)v90._Ptr->modelData.dxLoadCurve.references._Mylast, 0);
            v26 = (int)v91._Ptr;
          }
          while ( v31 - 2 < v38->physicsInfo.maxGear );
          v1 = (char *)v90._Ptr;
        }
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        std::wstring::assign(&section, L"NAME", 4u);
        LOBYTE(v111) = 42;
        v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v86, &key.name);
        LOBYTE(v111) = 43;
        INIReader::getString(&carsetup, &v108, v39, &section);
        if ( key.name._Myres >= 8 )
          operator delete(key.name._Bx._Ptr);
        key.name._Myres = 7;
        key.name._Mysize = 0;
        key.name._Bx._Buf[0] = 0;
        LOBYTE(v111) = 46;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        *(float *)&v89._Ptr = COERCE_FLOAT(&v83[24]);
        section._Bx._Buf[0] = 0;
        section._Mysize = 0;
        std::vector<GearDef>::vector<GearDef>(
          (std::vector<GearDef> *)&v83[24],
          (const std::vector<GearDef> *)&v106._Bx._Alias[12]);
        LOBYTE(v111) = 47;
        *(_DWORD *)&v83[20] = 7;
        *(_DWORD *)&v83[16] = 0;
        *(_WORD *)v83 = 0;
        std::wstring::assign((std::wstring *)v83, &v108, 0, 0xFFFFFFFF);
        LOBYTE(v111) = 46;
        SetupGearManager::addGearSet(*((SetupGearManager **)v1 + 83), *(std::wstring *)v83, *(GearSetDef *)&v83[24]);
        ++absoluteGearIndex._Ptr;
        std::wstring::wstring(&v107, word_17BE9D8);
        LOBYTE(v111) = 48;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v86.gap10[8]);
        *(_DWORD *)&v83[32] = *(_DWORD *)&v86.gap10[68];
        v40 = &v107;
        *(_DWORD *)&v83[28] = v107._Mysize;
        if ( v107._Myres >= 8 )
          v40 = (std::wstring *)v107._Bx._Ptr;
        std::wstringbuf::_Init(
          (std::wstringbuf *)&v86.gap10[8],
          v40->_Bx._Buf,
          *(unsigned int *)&v83[28],
          *(int *)&v83[32]);
        LOBYTE(v111) = 46;
        if ( v107._Myres >= 8 )
          operator delete(v107._Bx._Ptr);
        *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v83[32] = absoluteGearIndex;
        v41 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v86.gap10, "GEAR_SET_");
        std::wostream::operator<<(v41, *(_DWORD *)&v83[32]);
        if ( v108._Myres >= 8 )
          operator delete(v108._Bx._Ptr);
        v108._Myres = 7;
        v108._Mysize = 0;
        v108._Bx._Buf[0] = 0;
        LOBYTE(v111) = 28;
        if ( *(_DWORD *)&v106._Bx._Alias[12] )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v106._Bx._Alias[12]);
          *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *)&v83[32] = v89;
          *(_DWORD *)&v83[28] = &v95;
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<GearDef>>>(
            *(GearDef **)&v106._Bx._Alias[12],
            (GearDef *)v106._Mysize);
          operator delete(*(_DWORD *)&v106._Bx._Alias[12]);
          *(_DWORD *)&v106._Bx._Alias[12] = 0;
          v106._Mysize = 0;
          v106._Myres = 0;
        }
      }
      LOBYTE(v111) = 5;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v86);
    }
    else
    {
      v1 = (char *)v90._Ptr;
      if ( Sim::getCar((Sim *)v90._Ptr->modelData.dxLoadCurve.references._Mylast, 0)->physicsInfo.maxGear > 0 )
      {
        v42 = 2;
        absoluteGearIndex._Ptr = (TyreCompoundDef *)2;
        do
        {
          *(_DWORD *)v85.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v85.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v85.gap68);
          v91._Ptr = (TyreCompoundDef *)((unsigned int)v91._Ptr | 8);
          LOBYTE(v111) = 49;
          std::wiostream::basic_iostream<wchar_t>(&v85, &v85.gap10[8], 0);
          v111 = 50;
          *(_DWORD *)&v85.gap0[*(_DWORD *)(*(_DWORD *)v85.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v84.gap68[*(_DWORD *)(*(_DWORD *)v85.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v85.gap0 + 4) - 104;
          std::wstreambuf::wstreambuf(&v85.gap10[8]);
          *(_DWORD *)&v85.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v85.gap10[64] = 0;
          *(_DWORD *)&v85.gap10[68] = 0;
          LOBYTE(v111) = 52;
          *(_DWORD *)&v83[32] = v42 - 1;
          v43 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v85.gap10, "GEAR_");
          std::wostream::operator<<(v43, *(_DWORD *)&v83[32]);
          v44 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v85, &key.name);
          LOBYTE(v111) = 53;
          v95 = INIReader::hasSection(&carsetup, v44);
          LOBYTE(v111) = 52;
          std::wstring::~wstring(&key);
          if ( v95 )
          {
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
              &v84,
              3,
              1);
            *(_DWORD *)&v83[32] = v42;
            LOBYTE(v111) = 54;
            v45 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v84.gap10, "INTERNAL_GEAR_");
            std::wostream::operator<<(v45, *(_DWORD *)&v83[32]);
            SetupItemText::SetupItemText(&v99);
            LOBYTE(v111) = 55;
            v46 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v84, &v108);
            LOBYTE(v111) = 56;
            v47 = acLocaleGetString(&key.name, v46);
            std::wstring::operator=(&v99.name, v47);
            std::wstring::~wstring(&key);
            LOBYTE(v111) = 55;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
            if ( std::operator==<wchar_t>(&v99.name, word_17BE9D8) )
            {
              std::wstring::wstring(&key.name, L"NAME");
              LOBYTE(v111) = 57;
              v48 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v85, &v107);
              LOBYTE(v111) = 58;
              v49 = INIReader::getString(&carsetup, &v108, v48, &key.name);
              std::wstring::operator=(&v99.name, v49);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
              LOBYTE(v111) = 55;
              std::wstring::~wstring(&key);
            }
            std::wstring::wstring(&key.name, L"HELP");
            LOBYTE(v111) = 59;
            v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v85, &v107);
            LOBYTE(v111) = 60;
            v51 = INIReader::getString(&carsetup, &v108, v50, &key.name);
            std::wstring::operator=(&v99.nationCode, v51);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
            LOBYTE(v111) = 55;
            std::wstring::~wstring(&key);
            std::wstring::wstring(&key.name, L"RATIOS");
            LOBYTE(v111) = 61;
            v52 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v85, &v105);
            LOBYTE(v111) = 62;
            v53 = INIReader::getString(&carsetup, &v98, v52, &key.name);
            LOBYTE(v111) = 63;
            std::wstring::wstring(&v106, L"content/cars/");
            v55 = v54;
            LOBYTE(v111) = 64;
            v56 = Sim::getCar((Sim *)v90._Ptr->modelData.dxLoadCurve.references._Mylast, 0);
            v57 = std::operator+<wchar_t>(&section, v55, &v56->unixName);
            LOBYTE(v111) = 65;
            v58 = std::operator+<wchar_t>(&v107, v57, L"/data/");
            LOBYTE(v111) = 66;
            v59 = std::operator+<wchar_t>(&v108, v58, v53);
            std::wstring::operator=(&v99.nationality, v59);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v106);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v98);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
            LOBYTE(v111) = 55;
            std::wstring::~wstring(&key);
            v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v84, &v105);
            std::wstring::operator=(&v99.team, v60);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
            v1 = (char *)v90._Ptr;
            v42 = (int)absoluteGearIndex._Ptr;
            SetupGearManager::addSetupItem(
              (SetupGearManager *)v90._Ptr->modelData.dxLoadCurve.cSpline.__vftable,
              (int)absoluteGearIndex._Ptr,
              (const SetupItemText *)&v99);
            SetupItemText::~SetupItemText(&v99);
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v84);
          }
          else
          {
            v61 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v85, &v105);
            v62 = std::wstring::c_str(v61);
            _printf("ERROR: GEAR COULD NOT FIND %S\n", v62->_Bx._Buf);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
          }
          LOBYTE(v111) = 5;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v85);
          v63 = (Sim *)*((_DWORD *)v1 + 76);
          absoluteGearIndex._Ptr = (TyreCompoundDef *)++v42;
        }
        while ( v42 - 2 < Sim::getCar(v63, 0)->physicsInfo.maxGear );
      }
    }
    std::wstring::wstring(&key.name, L"FINAL_GEAR_RATIO");
    LOBYTE(v111) = 67;
    v95 = INIReader::hasSection(&carsetup, &key.name);
    LOBYTE(v111) = 5;
    std::wstring::~wstring(&key);
    if ( v95 )
    {
      SetupItemText::SetupItemText(&v99);
      LOBYTE(v111) = 68;
      std::wstring::wstring(&key.name, L"INTERNAL_FINAL_RATIO");
      LOBYTE(v111) = 69;
      v64 = acLocaleGetString(&v105, &key.name);
      std::wstring::operator=(&v99.name, v64);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
      LOBYTE(v111) = 68;
      std::wstring::~wstring(&key);
      if ( std::operator==<wchar_t>(&v99.name, word_17BE9D8) )
      {
        std::wstring::wstring(&v108, L"NAME");
        LOBYTE(v111) = 70;
        std::wstring::wstring(&key.name, L"FINAL_GEAR_RATIO");
        LOBYTE(v111) = 71;
        v65 = INIReader::getString(&carsetup, &v105, &key.name, &v108);
        std::wstring::operator=(&v99.name, v65);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
        std::wstring::~wstring(&key);
        LOBYTE(v111) = 68;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
      }
      std::wstring::wstring(&v108, L"HELP");
      LOBYTE(v111) = 72;
      std::wstring::wstring(&key.name, L"FINAL_GEAR_RATIO");
      LOBYTE(v111) = 73;
      v66 = INIReader::getString(&carsetup, &v105, &key.name, &v108);
      std::wstring::operator=(&v99.nationCode, v66);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
      std::wstring::~wstring(&key);
      LOBYTE(v111) = 68;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
      std::wstring::wstring(&v107, L"RATIOS");
      LOBYTE(v111) = 74;
      std::wstring::wstring(&key.name, L"FINAL_GEAR_RATIO");
      LOBYTE(v111) = 75;
      v67 = INIReader::getString(&carsetup, &v106, &key.name, &v107);
      LOBYTE(v111) = 76;
      std::wstring::wstring(&section, L"content/cars/");
      v69 = v68;
      LOBYTE(v111) = 77;
      v70 = Sim::getCar((Sim *)v90._Ptr->modelData.dxLoadCurve.references._Mylast, 0);
      v71 = std::operator+<wchar_t>(&v108, v69, &v70->unixName);
      LOBYTE(v111) = 78;
      v72 = std::operator+<wchar_t>(&v98, v71, L"/data/");
      LOBYTE(v111) = 79;
      v73 = std::operator+<wchar_t>(&v105, v72, v67);
      std::wstring::operator=(&v99.nationality, v73);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v98);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v108);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v106);
      std::wstring::~wstring(&key);
      LOBYTE(v111) = 68;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
      std::wstring::assign(&v99.team, L"FINAL_RATIO");
      v1 = (char *)v90._Ptr;
      SetupGearManager::addSetupItem(
        (SetupGearManager *)v90._Ptr->modelData.dxLoadCurve.cSpline.__vftable,
        -1,
        (const SetupItemText *)&v99);
      LOBYTE(v111) = 5;
      SetupItemText::~SetupItemText(&v99);
    }
  }
  absoluteGearIndex._Ptr = (TyreCompoundDef *)4;
  v89._Ptr = (SetupTab **)(v1 + 312);
  std::vector<SetupTab *>::begin((std::vector<TyreCompoundDef> *)v1 + 26, &v91);
  std::vector<Mesh *>::end((std::vector<TyreCompoundDef> *)v1 + 26, &v90);
  if ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(&v91, &v90) )
  {
    while ( 1 )
    {
      v74 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(&v91);
      *(_DWORD *)&v83[32] = L"ELECTRONICS";
      v75 = v74->index;
      std::wstring::wstring(&key.name, L"ELECTRONICS");
      LOBYTE(v111) = 80;
      v76 = acTranslate(&v105, &key.name);
      LOBYTE(v111) = 81;
      v95 = std::operator==<wchar_t>((const std::wstring *)(v75 + 4), v76);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v105);
      LOBYTE(v111) = 5;
      std::wstring::~wstring(&key);
      if ( v95 )
        break;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > *)&v91);
      if ( !std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(&v91, &v90) )
        goto LABEL_130;
    }
    absoluteGearIndex._Ptr = (TyreCompoundDef *)5;
  }
LABEL_130:
  v77 = (TabBar *)*((_DWORD *)v1 + 77);
  v78 = TabBar::getTabNamesCount(v77);
  TabBar::orderAlphabetically(v77, (unsigned int)absoluteGearIndex._Ptr, v78);
  v79 = std::vector<Mesh *>::end((std::vector<TyreCompoundDef> *)v89._Ptr, &v92);
  *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v83[32] = absoluteGearIndex;
  v80 = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *)v79;
  *(_DWORD *)&v83[28] = &v89;
  v81 = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > *)std::vector<SetupTab *>::begin(
                                                                                       (std::vector<TyreCompoundDef> *)v89._Ptr,
                                                                                       &absoluteGearIndex);
  v82 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *>>>::operator+(
          v81,
          *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > > **)&v83[28],
          *(int *)&v83[32]);
  std::sort<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *>>>,_lambda_d0860adfc7865b83237ab17dc7c59510_>(
    (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > >)v82->_Ptr,
    (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<SetupTab *> > >)v80->_Ptr,
    (SetupScreen::loadINI::__l63::<lambda_d0860adfc7865b83237ab17dc7c59510>)v89._Ptr);
  LOBYTE(v111) = 4;
  INIReader::~INIReader(&carsetup);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ifilename);
}
bool __userpurge SetupScreen::loadSetupAbsolutePath@<al>(SetupScreen *this@<ecx>, unsigned int i@<ebx>, const std::wstring *loadPath, BOOL isFixed)
{
  SetupTab *v5; // eax
  SetupPitstopPresets *v6; // ecx
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  unsigned int v9; // eax
  std::wstring *v10; // eax
  SetupPitstopPresets *v11; // ecx
  std::wstring v13; // [esp-1Ch] [ebp-114h] BYREF
  BOOL v14; // [esp-4h] [ebp-FCh]
  std::wstring v15; // [esp+18h] [ebp-E0h] BYREF
  std::wstring v16; // [esp+30h] [ebp-C8h] BYREF
  std::wstring result; // [esp+48h] [ebp-B0h] BYREF
  INIReaderDocuments ini; // [esp+60h] [ebp-98h] BYREF
  INIReaderDocuments v19; // [esp+A4h] [ebp-54h] BYREF
  int v20; // [esp+F4h] [ebp-4h]

  LOBYTE(i) = 0;
  if ( Path::fileExists((unsigned __int16)i, loadPath, 0) )
  {
    v14 = 0;
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    std::wstring::assign(&v13, loadPath, 0, 0xFFFFFFFF);
    INIReaderDocuments::INIReaderDocuments(&ini, (unsigned __int16)i, v13, v14);
    v20 = 0;
    if ( ini.ready )
    {
      for ( i = 0; i < this->tabs._Mylast - this->tabs._Myfirst; v5->modifiedValues = 0 )
      {
        this->tabs._Myfirst[i]->loadFromINI(this->tabs._Myfirst[i], &ini, isFixed);
        v5 = this->tabs._Myfirst[i++];
      }
      LOBYTE(i) = 1;
    }
    v20 = -1;
    INIReaderDocuments::~INIReaderDocuments(&ini);
  }
  v6 = this->pitstopManager;
  if ( v6 )
  {
    if ( isFixed )
      SetupPitstopPresets::loadFixed(v6, loadPath);
    v7 = std::wstring::substr((std::wstring *)loadPath, &result, 0, loadPath->_Mysize - 4);
    v20 = 1;
    v8 = std::operator+<wchar_t>(&v16, v7, L".sp");
    LOBYTE(v20) = 2;
    BYTE1(i) = Path::fileExists((unsigned __int16)i, v8, 0);
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    v20 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( BYTE1(i) )
    {
      v9 = loadPath->_Mysize;
      v14 = 0;
      v10 = std::wstring::substr((std::wstring *)loadPath, &v15, 0, v9 - 4);
      v20 = 3;
      std::operator+<wchar_t>(&v13, v10, L".sp");
      INIReaderDocuments::INIReaderDocuments(&v19, (unsigned __int16)i, v13, v14);
      LOBYTE(v20) = 5;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
      v11 = this->pitstopManager;
      v15._Bx._Buf[0] = 0;
      v15._Myres = 7;
      v15._Mysize = 0;
      SetupPitstopPresets::loadPresets(v11, &v19);
      v20 = -1;
      INIReaderDocuments::~INIReaderDocuments(&v19);
    }
  }
  return i;
}
char SetupScreen::needToSave(SetupScreen *this)
{
  int v2; // edx
  SetupTab **i; // ecx

  v2 = 0;
  if ( !(this->tabs._Mylast - this->tabs._Myfirst) )
    return 0;
  for ( i = this->tabs._Myfirst; !(*i)->modifiedValues; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->tabs._Mylast - this->tabs._Myfirst) )
      return 0;
  }
  return 1;
}
void SetupScreen::resetTabsValueToDefault(SetupScreen *this)
{
  unsigned int i; // edi
  SetupTab *v3; // ecx

  for ( i = 0; i < this->tabs._Mylast - this->tabs._Myfirst; ++i )
  {
    v3 = this->tabs._Myfirst[i];
    v3->resetToDefaultValues(v3);
  }
}
char SetupScreen::saveSetupAbsolutePath(SetupScreen *this, const std::wstring *savePath)
{
  unsigned int v4; // edi
  int v5; // eax
  SetupTab *v6; // ecx
  const std::wstring *v7; // eax
  std::wostream *v8; // eax
  SetupTab *v9; // eax
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  _BYTE *v13; // edi
  std::wstring *v14; // eax
  const std::wstring *v15; // eax
  SetupPitstopPresets *v16; // ecx
  _BYTE *v17; // esi
  std::wofstream file; // [esp+10h] [ebp-190h] BYREF
  std::wofstream file2; // [esp+B8h] [ebp-E8h] BYREF
  std::wstring result; // [esp+160h] [ebp-40h] BYREF
  std::wstring v21; // [esp+178h] [ebp-28h] BYREF
  int v22; // [esp+19Ch] [ebp-4h]

  if ( !std::wstring::compare((std::wstring *)savePath, 0, savePath->_Mysize, word_17BE9D8, 0) )
    return 0;
  std::wofstream::wofstream(&file, savePath, 2, 64, 1);
  v4 = 0;
  v5 = this->tabs._Mylast - this->tabs._Myfirst;
  v22 = 0;
  if ( v5 )
  {
    do
    {
      v6 = this->tabs._Myfirst[v4];
      v7 = v6->getStringToSave(v6, &result);
      LOBYTE(v22) = 1;
      v8 = std::operator<<<wchar_t>(&file, v7);
      std::wostream::operator<<(v8);
      LOBYTE(v22) = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v9 = this->tabs._Myfirst[v4++];
      v9->modifiedValues = 0;
    }
    while ( v4 < this->tabs._Mylast - this->tabs._Myfirst );
  }
  v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, L"[CAR]");
  std::wostream::operator<<(v10);
  v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, L"MODEL=");
  v12 = std::operator<<<wchar_t>(v11, &this->carName);
  std::wostream::operator<<(v12);
  v13 = &file.gap0[4];
  if ( *(_DWORD *)&file._Filebuffer[4] )
  {
    if ( !std::wfilebuf::_Endwrite((std::wfilebuf *)&file.gap0[4]) )
      v13 = 0;
    if ( _fclose(*(FILE **)&file._Filebuffer[4]) )
      v13 = 0;
  }
  else
  {
    v13 = 0;
  }
  file._Filebuffer[0] = 0;
  file.gap0[74] = 0;
  std::wstreambuf::_Init(&file.gap0[4]);
  *(_DWORD *)&file._Filebuffer[4] = 0;
  *(_DWORD *)&file.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&file.gap0[68] = 0;
  if ( !v13 )
    std::wios::setstate((char *)&file + *(_DWORD *)(*(_DWORD *)file.gap0 + 4), 2, 0);
  if ( this->pitstopManager )
  {
    v14 = std::wstring::substr((std::wstring *)savePath, &result, 0, savePath->_Mysize - 4);
    LOBYTE(v22) = 2;
    v15 = std::operator+<wchar_t>(&v21, v14, L".sp");
    LOBYTE(v22) = 3;
    std::wofstream::wofstream(&file2, v15, 2, 64, 1);
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    LOBYTE(v22) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v16 = this->pitstopManager;
    result._Bx._Buf[0] = 0;
    result._Myres = 7;
    result._Mysize = 0;
    SetupPitstopPresets::savePresets(v16, &file2);
    v17 = &file2.gap0[4];
    if ( *(_DWORD *)&file2._Filebuffer[4] )
    {
      if ( !std::wfilebuf::_Endwrite((std::wfilebuf *)&file2.gap0[4]) )
        v17 = 0;
      if ( _fclose(*(FILE **)&file2._Filebuffer[4]) )
        v17 = 0;
    }
    else
    {
      v17 = 0;
    }
    file2._Filebuffer[0] = 0;
    file2.gap0[74] = 0;
    std::wstreambuf::_Init(&file2.gap0[4]);
    *(_DWORD *)&file2._Filebuffer[4] = 0;
    *(_DWORD *)&file2.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&file2.gap0[68] = 0;
    if ( !v17 )
      std::wios::setstate((char *)&file2 + *(_DWORD *)(*(_DWORD *)file2.gap0 + 4), 2, 0);
    std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&file2.gap58[8]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file2.gap58[8]);
  }
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&file.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap58[8]);
  return 1;
}
void SetupScreen::switchVisibility(SetupScreen *this)
{
  this->visible = !this->visible;
}
