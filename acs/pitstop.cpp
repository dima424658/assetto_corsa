#include "pitstop.h
double PitStop::getPitStopTyrePercentage(PitStop *this)
{
  float v1; // xmm2_4

  v1 = (float)(this->pitTimer - (float)(this->maxPitTimer - this->tyreTime)) / this->tyreTime;
  if ( v1 > 1.0 )
    return 1.0 - 1.0;
  if ( v1 >= 0.0 )
    return 1.0 - v1;
  return 1.0 - 0.0;
}
void PitStop::PitStop(PitStop *this, Sim *aSim)
{
  unsigned int v3; // ebx
  std::vector<int> *v4; // ebp
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  PitCrew *v7; // eax
  Font *v8; // eax
  volatile signed __int32 *v9; // esi
  PitCrew *v10; // esi
  Model *v11; // eax
  Game *v12; // eax
  Model *v13; // ecx
  Game *v14; // eax
  Sim *v15; // ecx
  CarAvatar *v16; // eax
  unsigned int v17; // eax
  Model *v18; // eax
  __m128i v19; // xmm0
  int v20; // eax
  bool v21; // cf
  PitCrew *v22; // esi
  ksgui::Control *v23; // eax
  Game *v24; // eax
  ksgui::Control *v25; // eax
  PitCrew *v26; // esi
  int *v27; // eax
  int *v28; // esi
  int v29; // eax
  float v30; // xmm0_4
  Sim *v31; // ecx
  CarAvatar *v32; // eax
  PitStop::{ctor}::__l65::<lambda_9c16e304e7e2c085ae3f98eceac1031e> v33; // ebp
  Sim *v34; // ecx
  std::wostream *v35; // eax
  ksgui::ActiveButton *v36; // esi
  int v37; // eax
  int v38; // ebx
  Sim *v39; // ecx
  CarAvatar *v40; // eax
  const std::wstring *v41; // eax
  std::wstring *v42; // ecx
  std::wstring *v43; // ebp
  wchar_t *v44; // eax
  std::wstring *v45; // ecx
  int v46; // xmm0_4
  float left; // xmm0_4
  CarAvatar *v48; // eax
  PitCrew *v49; // ebp
  const std::wstring *v50; // eax
  unsigned int v51; // esi
  std::wostream *v52; // eax
  Sim *v53; // ecx
  CarAvatar *v54; // eax
  PitCrew *v55; // esi
  ksgui::ActiveButton *v56; // eax
  ksgui::ActiveButton *v57; // ecx
  ksgui::ActiveButton *v58; // ecx
  Event<OnMouseWheelMovedEvent> *v59; // ecx
  PitCrew *v60; // esi
  PitStopFuel *v61; // eax
  PitStopFuel *v62; // ecx
  PitStopFuel_vtbl *v63; // eax
  PitCrew *v64; // esi
  ksgui::ActiveButton *v65; // eax
  ksgui::ActiveButton *v66; // ecx
  ksgui::ActiveButton *v67; // ecx
  Event<OnMouseWheelMovedEvent> *v68; // ecx
  PitCrew *v69; // esi
  ksgui::ActiveButton *v70; // eax
  ksgui::ActiveButton *v71; // ecx
  ksgui::ActiveButton *v72; // ecx
  Event<OnMouseWheelMovedEvent> *v73; // ecx
  PitCrew *v74; // esi
  ksgui::ActiveButton *v75; // eax
  ksgui::ActiveButton *v76; // ecx
  ksgui::ActiveButton *v77; // ecx
  int v78; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v79; // ecx
  PitCrew *v80; // esi
  ksgui::ActiveButton *v81; // eax
  ksgui::ActiveButton *v82; // ecx
  ksgui::ActiveButton *v83; // ecx
  int v84; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v85; // ecx
  PitCrew *v86; // esi
  ksgui::ActiveButton *v87; // eax
  ksgui::ActiveButton *v88; // ecx
  ksgui::ActiveButton *v89; // ecx
  int v90; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v91; // ecx
  int v92; // ecx
  ksgui::Control *v93; // ecx
  double v94; // st7
  ksgui::ActiveButton *v95; // ecx
  int v96; // ecx
  PitCrew *v97; // esi
  ksgui::ActiveButton *v98; // eax
  ksgui::ActiveButton *v99; // ecx
  ksgui::Control *v100; // esi
  ksgui::Control_vtbl **v101; // eax
  PitStop::{ctor}::__l47::<lambda_53f637ed5ae27b6058387f0697b093c3> *v102; // eax
  PitStop::{ctor}::__l51::<lambda_97f858d078361660960f46ec1dfa1142> *v103; // eax
  PitStop::{ctor}::__l55::<lambda_fcf8135cce28782398f609f867708197> *v104; // eax
  PitStop::{ctor}::__l59::<lambda_1290f339c00a0b2d2425f2377cebc6d8> *v105; // eax
  PitStop::{ctor}::__l63::<lambda_178fecdc963779ab0a7b9ba17e429953> *v106; // eax
  ResourceStore *v107; // eax
  const Texture *v108; // eax
  ResourceStore *v109; // eax
  const Texture *v110; // eax
  ResourceStore *v111; // eax
  const Texture *v112; // eax
  Sim *v113; // ecx
  CarAvatar *v114; // eax
  std::wstring *v115; // esi
  Sim *v116; // ecx
  CarAvatar *v117; // eax
  std::wstring *v118; // eax
  std::wstring *v119; // eax
  PitCrew *v120; // esi
  Sim *v121; // ecx
  CarAvatar *v122; // eax
  PitCrew *v123; // eax
  PitCrew *v124; // esi
  PitStop::{ctor}::__l65::<lambda_9c16e304e7e2c085ae3f98eceac1031e> *v125; // eax
  _BYTE top[84]; // [esp+A4h] [ebp-358h] BYREF
  PitCrew *pitCrew; // [esp+F8h] [ebp-304h] BYREF
  float v128; // [esp+FCh] [ebp-300h]
  PitStop::{ctor}::__l65::<lambda_9c16e304e7e2c085ae3f98eceac1031e> v129; // [esp+100h] [ebp-2FCh] BYREF
  PitStopStrategy str; // [esp+104h] [ebp-2F8h] BYREF
  int v131; // [esp+110h] [ebp-2ECh]
  ksgui::ActiveButton *btTyre; // [esp+114h] [ebp-2E8h] BYREF
  int v133; // [esp+118h] [ebp-2E4h]
  int _Val; // [esp+11Ch] [ebp-2E0h] BYREF
  int v135; // [esp+120h] [ebp-2DCh]
  int v136; // [esp+124h] [ebp-2D8h]
  PitStop *v137; // [esp+128h] [ebp-2D4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+12Ch] [ebp-2D0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > wsName; // [esp+1DCh] [ebp-220h] BYREF
  mat44f pos; // [esp+28Ch] [ebp-170h] BYREF
  std::wstring compound; // [esp+2CCh] [ebp-130h] BYREF
  std::wstring myText; // [esp+2E8h] [ebp-114h] BYREF
  std::wstring skin; // [esp+300h] [ebp-FCh] BYREF
  unsigned int v144; // [esp+318h] [ebp-E4h]
  int v145; // [esp+31Ch] [ebp-E0h]
  Texture filename; // [esp+320h] [ebp-DCh] BYREF
  INIReaderDocuments gameplayINI; // [esp+33Ch] [ebp-C0h] BYREF
  KN5IO kn5; // [esp+380h] [ebp-7Ch] BYREF
  int v149; // [esp+3F8h] [ebp-4h]

  v3 = 0;
  v133 = 0;
  v137 = this;
  *(_DWORD *)&top[24] = aSim->game;
  *(_DWORD *)&top[20] = 7;
  *(_DWORD *)&top[16] = 0;
  *(_WORD *)top = 0;
  std::wstring::assign((std::wstring *)top, L"PIT_STOP", 8u);
  GameObject::GameObject(this, *(std::wstring *)top, *(Game **)&top[24]);
  this->__vftable = (PitStop_vtbl *)&PitStop::`vftable';
  v149 = 0;
  this->evPitStopCommit.handlers._Myfirst = 0;
  this->evPitStopCommit.handlers._Mylast = 0;
  this->evPitStopCommit.handlers._Myend = 0;
  this->evPitStopOver.handlers._Myfirst = 0;
  this->evPitStopOver.handlers._Mylast = 0;
  this->evPitStopOver.handlers._Myend = 0;
  this->strategies._Myfirst = 0;
  this->strategies._Mylast = 0;
  this->strategies._Myend = 0;
  this->displayingPitMenu = 0;
  this->pitTimer = 0.0;
  this->pitRandomModifier = 0.0;
  this->maxPitTimer = 10.0;
  this->currentStrategyIndex = 0;
  this->fuelTime = 0.0;
  this->repairTime = 0.0;
  this->tyreTime = 0.0;
  *(_WORD *)&this->indicatorOnlyInPitline = 1;
  this->avatar = 0;
  this->sim = aSim;
  this->pitIndicator = 0;
  this->pitPosition.x = 0.0;
  this->pitPosition.y = 0.0;
  this->pitPosition.z = 0.0;
  *(_DWORD *)&top[24] = 0;
  this->desiredTyreCompound._Myres = 7;
  this->desiredTyreCompound._Mysize = 0;
  *(_DWORD *)&top[20] = word_17BE9D8;
  LOBYTE(v149) = 3;
  this->desiredTyreCompound._Bx._Buf[0] = 0;
  std::wstring::assign(&this->desiredTyreCompound, *(const wchar_t **)&top[20], *(unsigned int *)&top[24]);
  this->font._Ptr = 0;
  this->font._Rep = 0;
  v4 = (std::vector<int> *)&this->btTyres;
  this->state = ScrewingTyre;
  this->parentControl = 0;
  this->btTyres._Myfirst = 0;
  this->btTyres._Mylast = 0;
  this->btTyres._Myend = 0;
  this->confirmButton = 0;
  this->fuelControl = 0;
  this->btFuelUp = 0;
  this->btFuelDown = 0;
  this->btFuelFill = 0;
  this->btRepairSusp = 0;
  this->btRepairBody = 0;
  this->btRepairEngine = 0;
  this->txRepairing.kid = 0;
  this->txRepairing.fileName._Myres = 7;
  this->txRepairing.fileName._Mysize = 0;
  this->txRepairing.fileName._Bx._Buf[0] = 0;
  this->txFueling.kid = 0;
  this->txFueling.fileName._Myres = 7;
  this->txFueling.fileName._Mysize = 0;
  this->txFueling.fileName._Bx._Buf[0] = 0;
  this->txTyreChanging.kid = 0;
  this->txTyreChanging.fileName._Myres = 7;
  this->txTyreChanging.fileName._Mysize = 0;
  this->txTyreChanging.fileName._Bx._Buf[0] = 0;
  this->newCompound = -1;
  this->wings._Myfirst = 0;
  this->wings._Mylast = 0;
  this->wings._Myend = 0;
  this->psi._Myfirst = 0;
  this->psi._Mylast = 0;
  this->psi._Myend = 0;
  this->getFuel = 0.0;
  *(_WORD *)&this->rbody = 0;
  this->rengine = 0;
  *(_DWORD *)&top[24] = 0;
  v5 = this->sim;
  LOBYTE(v149) = 11;
  v6 = Sim::getCar(v5, 0);
  *(_DWORD *)&top[24] = 24;
  this->avatar = v6;
  *(float *)&v7 = COERCE_FLOAT(operator new(*(_DWORD *)&top[24]));
  pitCrew = v7;
  LOBYTE(v149) = 12;
  if ( *(float *)&v7 == 0.0 )
    v8 = 0;
  else
    Font::Font((Font *)v7, eFontMonospaced, 14.0, 0, 1);
  LOBYTE(v149) = 11;
  *(float *)&pitCrew = 0.0;
  v128 = 0.0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&pitCrew, v8);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&pitCrew);
  v9 = (volatile signed __int32 *)LODWORD(v128);
  if ( v128 != 0.0 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v128) + 4), 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v9)(v9);
      if ( !_InterlockedDecrement(v9 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v9 + 4))(v9);
    }
    v4 = (std::vector<int> *)&this->btTyres;
  }
  *(float *)&v10 = COERCE_FLOAT(operator new(212));
  pitCrew = v10;
  v11 = 0;
  LOBYTE(v149) = 13;
  if ( *(float *)&v10 != 0.0 )
  {
    *(_DWORD *)&top[24] = 7;
    *(_DWORD *)&top[20] = 0;
    *(_WORD *)&top[4] = 0;
    std::wstring::assign((std::wstring *)&top[4], L"PIT_INDICATOR", 0xDu);
    Model::Model((Model *)v10, *(std::wstring *)&top[4]);
  }
  this->pitIndicator = v11;
  v12 = this->game;
  LOBYTE(v149) = 11;
  KN5IO::KN5IO(&kn5, v12->graphics);
  LOBYTE(v149) = 14;
  compound._Myres = 7;
  compound._Mysize = 0;
  compound._Bx._Buf[0] = 0;
  std::wstring::assign(&compound, L"content/objects3D/pit_indicator.kn5", 0x23u);
  v13 = this->pitIndicator;
  *(_DWORD *)&top[24] = &kn5;
  v14 = this->game;
  LOBYTE(v149) = 15;
  Model::load(v13, &compound, v14->graphics, &kn5);
  LOBYTE(v149) = 14;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  GraphicsManager::compile(this->game->graphics, this->pitIndicator);
  this->sim->trackNode->addChild(this->sim->trackNode, this->pitIndicator);
  compound._Myres = 7;
  compound._Mysize = 0;
  compound._Bx._Buf[0] = 0;
  std::wstring::assign(&compound, L"PIT", 3u);
  LOBYTE(v149) = 16;
  *(float *)&pitCrew = COERCE_FLOAT(&top[4]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"PIT", 3u);
  v15 = this->sim;
  LOBYTE(v149) = 17;
  v16 = Sim::getCar(v15, 0);
  LOBYTE(v149) = 16;
  v17 = CarAvatar::getSpawnPositionIndex(v16, *(std::wstring *)&top[4]);
  TrackAvatar::getSpawnPosition(this->sim->track, &pos, &compound, v17);
  LOBYTE(v149) = 14;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  v18 = this->pitIndicator;
  v19 = _mm_loadu_si128((const __m128i *)&pos);
  *(_DWORD *)&top[24] = 0;
  *(__m128i *)&v18->matrix.M11 = v19;
  *(__m128i *)&v18->matrix.M21 = _mm_loadu_si128((const __m128i *)&pos.M21);
  *(__m128i *)&v18->matrix.M31 = _mm_loadu_si128((const __m128i *)&pos.M31);
  *(__m128i *)&v18->matrix.M41 = _mm_loadu_si128((const __m128i *)&pos.M41);
  v19.m128i_i32[0] = LODWORD(pos.M43);
  *(_QWORD *)&this->pitPosition.x = _mm_unpacklo_ps((__m128)LODWORD(pos.M41), (__m128)LODWORD(pos.M42)).m128_u64[0];
  *(_DWORD *)&str.fixBody = v19.m128i_i32[0];
  LODWORD(this->pitPosition.z) = v19.m128i_i32[0];
  *(_DWORD *)&top[20] = 7;
  *(_DWORD *)&top[16] = 0;
  *(_WORD *)top = 0;
  std::wstring::assign((std::wstring *)top, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&gameplayINI, 0, *(std::wstring *)top, top[24]);
  LOBYTE(v149) = 18;
  if ( gameplayINI.ready )
  {
    compound._Myres = 7;
    compound._Mysize = 0;
    compound._Bx._Buf[0] = 0;
    std::wstring::assign(&compound, L"ONLY_IN_PITLINE", 0xFu);
    LOBYTE(v149) = 19;
    myText._Myres = 7;
    myText._Mysize = 0;
    myText._Bx._Buf[0] = 0;
    std::wstring::assign(&myText, L"PIT_INDICATOR", 0xDu);
    LOBYTE(v149) = 20;
    HIBYTE(v131) = INIReader::hasKey(&gameplayINI, &myText, &compound);
    if ( myText._Myres >= 8 )
      operator delete(myText._Bx._Ptr);
    myText._Myres = 7;
    myText._Mysize = 0;
    myText._Bx._Buf[0] = 0;
    LOBYTE(v149) = 18;
    if ( compound._Myres >= 8 )
      operator delete(compound._Bx._Ptr);
    if ( HIBYTE(v131) )
    {
      std::wstring::wstring(&myText, L"ONLY_IN_PITLINE");
      LOBYTE(v149) = 21;
      std::wstring::wstring(&compound, L"PIT_INDICATOR");
      LOBYTE(v149) = 22;
      v20 = INIReader::getInt(&gameplayINI, &compound, &myText);
      v21 = compound._Myres < 8;
      this->indicatorOnlyInPitline = v20 > 0;
      if ( !v21 )
        operator delete(compound._Bx._Ptr);
      compound._Myres = 7;
      compound._Mysize = 0;
      compound._Bx._Buf[0] = 0;
      LOBYTE(v149) = 18;
      if ( myText._Myres >= 8 )
        operator delete(myText._Bx._Ptr);
    }
  }
  *(float *)&v22 = COERCE_FLOAT(operator new(280));
  pitCrew = v22;
  v23 = 0;
  LOBYTE(v149) = 23;
  if ( *(float *)&v22 != 0.0 )
  {
    compound._Myres = 7;
    compound._Mysize = 0;
    compound._Bx._Buf[0] = 0;
    std::wstring::assign(&compound, L"PIT_STOP_PARENT_CONTROL", 0x17u);
    v24 = this->game;
    v3 = 1;
    LOBYTE(v149) = 24;
    v133 = 1;
    ksgui::Control::Control((ksgui::Control *)v22, &compound, v24->gui);
  }
  this->parentControl = v23;
  v149 = 18;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( compound._Myres >= 8 )
      operator delete(compound._Bx._Ptr);
  }
  ((void (*)(ksgui::Control *, int, int))this->parentControl->setSize)(
    this->parentControl,
    1143111680,
    1142292480);
  this->parentControl->drawBackground = 0;
  v25 = this->parentControl;
  *(_DWORD *)&top[24] = 1117126656;
  v25->drawBorder = 0;
  this->parentControl->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colDarkBar_4);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->parentControl,
    (float)(this->game->graphics->videoSettings.width / 2)
  - (float)((float)(this->parentControl->rect.right - this->parentControl->rect.left) * 0.5),
    *(float *)&top[24]);
  *(float *)&v26 = COERCE_FLOAT(operator new(448));
  pitCrew = v26;
  LOBYTE(v149) = 26;
  if ( *(float *)&v26 == 0.0 )
  {
    v28 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->game->gui;
    *(_DWORD *)&top[20] = 7;
    *(_DWORD *)&top[16] = 0;
    *(_WORD *)top = 0;
    std::wstring::assign((std::wstring *)top, L"DO_NOT_CHANGE", 0xDu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v26, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
    v28 = v27;
  }
  LOBYTE(v149) = 18;
  btTyre = (ksgui::ActiveButton *)v28;
  compound._Myres = 7;
  compound._Mysize = 0;
  compound._Bx._Buf[0] = 0;
  std::wstring::assign(&compound, L"NO CHANGE", 9u);
  v29 = *v28;
  LOBYTE(v149) = 27;
  (*(void (**)(int *, std::wstring *))(v29 + 68))(v28, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  (*(void (**)(int *, int, int))(*v28 + 28))(v28, 1113587712, 1113587712);
  ksgui::Form::setPosition((ksgui::Form *)v28, 50.0, 40.0);
  v30 = *((float *)v28 + 10) - *((float *)v28 + 9);
  *(float *)&pitCrew = 0.0;
  v28[70] = 0;
  *(_DWORD *)&top[24] = this;
  v128 = v30;
  *((float *)v28 + 71) = v30;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_fe54ec64e3a577c09bc4ce22ef9833a9_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[8] = v28;
  *(_DWORD *)&top[16] = top;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v28 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"content/gui/pitstop/tyre_no_change", 0x22u);
  ksgui::ActiveButton::setMultipleTexture((ksgui::ActiveButton *)v28, v3, *(std::wstring *)&top[4]);
  std::vector<CarAvatar *>::push_back(v4, (int *)&btTyre);
  this->parentControl->addControl(this->parentControl, btTyre);
  v31 = this->sim;
  v136 = 0;
  v32 = Sim::getCar(v31, 0);
  if ( v32->physicsInfo.tyreCompounds._Mylast - v32->physicsInfo.tyreCompounds._Myfirst )
  {
    *(float *)&v33.pitCrew = 0.0;
    str.fuel = 0.0;
    *(float *)&v129.pitCrew = 0.0;
    v135 = 200;
    do
    {
      *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(ws.gap68);
      LOBYTE(v149) = 29;
      btTyre = (ksgui::ActiveButton *)(v3 | 2);
      v133 = v3 | 2;
      std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
      v149 = 30;
      *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(PitStop **)((char *)&v137 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = (PitStop *)(*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)
                                                                                     - 104);
      std::wstreambuf::wstreambuf(&ws.gap10[8]);
      *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&ws.gap10[64] = 0;
      *(_DWORD *)&ws.gap10[68] = 0;
      v34 = this->sim;
      LOBYTE(v149) = 32;
      *(_DWORD *)&top[24] = (char *)v33.pitCrew + (unsigned int)Sim::getCar(v34, 0)->physicsInfo.tyreCompounds._Myfirst;
      v35 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ws.gap10, "BUTTON_");
      std::operator<<<wchar_t>(v35, *(const std::wstring **)&top[24]);
      v36 = (ksgui::ActiveButton *)operator new(448);
      _Val = (int)v36;
      LOBYTE(v149) = 33;
      if ( v36 )
      {
        *(_DWORD *)&top[24] = this->game->gui;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &ws,
          (std::wstring *)top);
        ksgui::ActiveButton::ActiveButton(v36, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
        v38 = v37;
      }
      else
      {
        v38 = 0;
      }
      v39 = this->sim;
      LOBYTE(v149) = 32;
      _Val = v38;
      v40 = Sim::getCar(v39, 0);
      *(_DWORD *)&top[24] = -1;
      *(_DWORD *)&top[20] = 0;
      v41 = (const std::wstring *)((char *)v33.pitCrew + (unsigned int)v40->physicsInfo.tyreCompounds._Myfirst);
      myText._Bx._Buf[0] = 0;
      myText._Myres = 7;
      myText._Mysize = 0;
      std::wstring::assign(&myText, v41, 0, 0xFFFFFFFF);
      v42 = &myText;
      *(float *)&v43 = COERCE_FLOAT(&myText);
      LOBYTE(v149) = 34;
      if ( myText._Myres >= 8 )
        v42 = (std::wstring *)myText._Bx._Ptr;
      if ( myText._Myres >= 8 )
        v43 = (std::wstring *)myText._Bx._Ptr;
      v44 = &v42->_Bx._Buf[myText._Mysize];
      v45 = &myText;
      if ( myText._Myres >= 8 )
        v45 = (std::wstring *)myText._Bx._Ptr;
      if ( v45 == (std::wstring *)v44 )
        pitCrew = (PitCrew *)v43;
      else
        std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&pitCrew,
          v45->_Bx._Buf,
          v44,
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v43,
          _toupper);
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v38 + 68))(v38, &myText);
      (*(void (**)(int, int, int))(*(_DWORD *)v38 + 28))(v38, 1113587712, 1113587712);
      *(float *)&v46 = *(float *)(v38 + 40) - *(float *)(v38 + 36);
      *(float *)(v38 + 280) = str.fuel;
      *(_DWORD *)&top[24] = 1109393408;
      str.tyreCompound = v46;
      left = (float)v135;
      *(_DWORD *)(v38 + 284) = str.tyreCompound;
      ksgui::Form::setPosition((ksgui::Form *)v38, left, *(float *)&top[24]);
      v48 = Sim::getCar(this->sim, 0);
      v49 = v129.pitCrew;
      *(_DWORD *)&top[24] = -1;
      *(_DWORD *)&top[20] = 0;
      v50 = (const std::wstring *)((char *)v129.pitCrew + (unsigned int)v48->physicsInfo.tyreCompounds._Myfirst);
      compound._Bx._Buf[0] = 0;
      compound._Myres = 7;
      compound._Mysize = 0;
      std::wstring::assign(&compound, v50, 0, 0xFFFFFFFF);
      *(_DWORD *)&top[24] = this;
      LOBYTE(v149) = 35;
      skin._Bx._Buf[2] = 0;
      skin._Bx._Ptr = (wchar_t *)this;
      v144 = 7;
      skin._Myres = 0;
      std::wstring::assign((std::wstring *)&skin._Bx._Alias[4], &compound, 0, 0xFFFFFFFF);
      v145 = v38;
      LOBYTE(v149) = 36;
      std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
        (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)top,
        (PitStop::{ctor}::__l20::<lambda_22ce6e0707c6a0d99aefde3918cef02e> *)&skin);
      Event<ksgui::OnControlClicked>::addHandler(
        (Event<OnMouseWheelMovedEvent> *)(v38 + 156),
        *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
        *(void **)&top[24]);
      LOBYTE(v149) = 35;
      if ( v144 >= 8 )
        operator delete(*(_DWORD *)&skin._Bx._Alias[4]);
      *(_DWORD *)wsName.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)wsName.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(wsName.gap68);
      LOBYTE(v149) = 37;
      btTyre = (ksgui::ActiveButton *)((unsigned int)btTyre | 4);
      v133 = (int)btTyre;
      std::wiostream::basic_iostream<wchar_t>(&wsName, &wsName.gap10[8], 0);
      v149 = 38;
      *(_DWORD *)&wsName.gap0[*(_DWORD *)(*(_DWORD *)wsName.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&ws.gap68[*(_DWORD *)(*(_DWORD *)wsName.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)wsName.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&wsName.gap10[8]);
      *(_DWORD *)&wsName.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&wsName.gap10[64] = 0;
      *(_DWORD *)&wsName.gap10[68] = 0;
      v51 = v136 + 1;
      LOBYTE(v149) = 40;
      *(_DWORD *)&top[24] = ++v136;
      v52 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)wsName.gap10,
              L"content/gui/pitstop/tyre_");
      std::wostream::operator<<(v52, *(_DWORD *)&top[24]);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
        &wsName,
        (std::wstring *)&top[4]);
      ksgui::ActiveButton::setMultipleTexture((ksgui::ActiveButton *)v38, v38, *(std::wstring *)&top[4]);
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->btTyres, &_Val);
      this->parentControl->addControl(this->parentControl, (ksgui::Control *)_Val);
      LOBYTE(v149) = 35;
      *(_DWORD *)&wsName.gap0[*(_DWORD *)(*(_DWORD *)wsName.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&ws.gap68[*(_DWORD *)(*(_DWORD *)wsName.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)wsName.gap0 + 4) - 104;
      *(_DWORD *)&wsName.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&wsName.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&wsName.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&wsName.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(wsName.gap68);
      if ( compound._Myres >= 8 )
        operator delete(compound._Bx._Ptr);
      compound._Myres = 7;
      compound._Mysize = 0;
      compound._Bx._Buf[0] = 0;
      if ( myText._Myres >= 8 )
        operator delete(myText._Bx._Ptr);
      myText._Myres = 7;
      myText._Bx._Buf[0] = 0;
      myText._Mysize = 0;
      LOBYTE(v149) = 18;
      *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(PitStop **)((char *)&v137 + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = (PitStop *)(*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)
                                                                                     - 104);
      *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&ws.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&ws.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(ws.gap68);
      v53 = this->sim;
      v33.pitCrew = (PitCrew *)&v49->name._Mysize;
      v135 += 112;
      v129.pitCrew = v33.pitCrew;
      v54 = Sim::getCar(v53, 0);
      v3 = (unsigned int)btTyre;
    }
    while ( v51 < v54->physicsInfo.tyreCompounds._Mylast - v54->physicsInfo.tyreCompounds._Myfirst );
  }
  *(float *)&v55 = COERCE_FLOAT(operator new(448));
  pitCrew = v55;
  LOBYTE(v149) = 41;
  if ( *(float *)&v55 == 0.0 )
  {
    v56 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_FUEL_DOWN");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v55, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  this->btFuelDown = v56;
  LOBYTE(v149) = 18;
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"content/gui/pitstop/fuel_minus", 0x1Eu);
  ksgui::ActiveButton::setMultipleTexture(this->btFuelDown, v3, *(std::wstring *)&top[4]);
  compound._Myres = 7;
  compound._Mysize = 0;
  compound._Bx._Buf[0] = 0;
  std::wstring::assign(&compound, word_17BE9D8, 0);
  v57 = this->btFuelDown;
  LOBYTE(v149) = 42;
  v57->setText(v57, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  v58 = this->btFuelDown;
  str.fuel = 0.0;
  str.tyreCompound = 1109393408;
  v58->textCoord.x = 0.0;
  LODWORD(v58->textCoord.y) = str.tyreCompound;
  ((void (*)(ksgui::ActiveButton *, int, int))this->btFuelDown->setSize)(
    this->btFuelDown,
    1111490560,
    1111490560);
  ksgui::Form::setPosition((ksgui::Form *)this->btFuelDown, 35.0, 200.0);
  *(_DWORD *)&top[24] = this;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_9a831349607677f0992b10b1cd26b24e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v59 = (Event<OnMouseWheelMovedEvent> *)&this->btFuelDown->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v59,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    this);
  this->parentControl->addControl(this->parentControl, this->btFuelDown);
  *(float *)&v60 = COERCE_FLOAT(operator new(288));
  pitCrew = v60;
  LOBYTE(v149) = 44;
  if ( *(float *)&v60 == 0.0 )
  {
    v62 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"FUEL_CONTROL");
    PitStopFuel::PitStopFuel((PitStopFuel *)v60, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
    v62 = v61;
  }
  this->fuelControl = v62;
  v63 = v62->__vftable;
  LOBYTE(v149) = 18;
  ((void (*)(PitStopFuel *, int, int))v63->setSize)(v62, 1133936640, 1100480512);
  ksgui::Form::setPosition((ksgui::Form *)this->fuelControl, 90.0, 215.0);
  this->parentControl->addControl(this->parentControl, this->fuelControl);
  *(float *)&v64 = COERCE_FLOAT(operator new(448));
  pitCrew = v64;
  LOBYTE(v149) = 45;
  if ( *(float *)&v64 == 0.0 )
  {
    v65 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_FUEL_UP");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v64, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->btFuelUp = v65;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/fuel_plus");
  ksgui::ActiveButton::setMultipleTexture(this->btFuelUp, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, word_17BE9D8);
  v66 = this->btFuelUp;
  LOBYTE(v149) = 46;
  v66->setText(v66, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  v67 = this->btFuelUp;
  str.fuel = 0.0;
  str.tyreCompound = 1109393408;
  v67->textCoord.x = 0.0;
  LODWORD(v67->textCoord.y) = str.tyreCompound;
  ((void (*)(ksgui::ActiveButton *, int, int))this->btFuelUp->setSize)(
    this->btFuelUp,
    1111490560,
    1111490560);
  *(_DWORD *)&top[24] = this;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_79e20b683d136f5683260955e7a5af8c_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v68 = (Event<OnMouseWheelMovedEvent> *)&this->btFuelUp->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v68,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    this);
  ksgui::Form::setPosition((ksgui::Form *)this->btFuelUp, 400.0, 200.0);
  this->parentControl->addControl(this->parentControl, this->btFuelUp);
  *(float *)&v69 = COERCE_FLOAT(operator new(448));
  pitCrew = v69;
  LOBYTE(v149) = 48;
  if ( *(float *)&v69 == 0.0 )
  {
    v70 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_FUEL_FILL");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v69, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->btFuelFill = v70;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/fuel_fill");
  ksgui::ActiveButton::setMultipleTexture(this->btFuelFill, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, word_17BE9D8);
  v71 = this->btFuelFill;
  LOBYTE(v149) = 49;
  v71->setText(v71, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  v72 = this->btFuelFill;
  str.fuel = 0.0;
  str.tyreCompound = 1109393408;
  v72->textCoord.x = 0.0;
  LODWORD(v72->textCoord.y) = str.tyreCompound;
  ((void (*)(ksgui::ActiveButton *, int, int))this->btFuelFill->setSize)(
    this->btFuelFill,
    1111490560,
    1111490560);
  *(_DWORD *)&top[24] = this;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_ef86f3a3b2675b5a03bf301d657f5386_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v73 = (Event<OnMouseWheelMovedEvent> *)&this->btFuelFill->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v73,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    this);
  ksgui::Form::setPosition((ksgui::Form *)this->btFuelFill, 550.0, 200.0);
  this->parentControl->addControl(this->parentControl, this->btFuelFill);
  *(float *)&v74 = COERCE_FLOAT(operator new(448));
  pitCrew = v74;
  LOBYTE(v149) = 51;
  if ( *(float *)&v74 == 0.0 )
  {
    v75 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_REPAIR_SUSP");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v74, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->btRepairSusp = v75;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/repair_sus");
  ksgui::ActiveButton::setMultipleTexture(this->btRepairSusp, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, L"REPAIR BODY + SUSPENSION");
  v76 = this->btRepairSusp;
  LOBYTE(v149) = 52;
  v76->setText(v76, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btRepairSusp->setSize)(
    this->btRepairSusp,
    1115684864,
    1115684864);
  v77 = this->btRepairSusp;
  str.fuel = 0.0;
  *(_DWORD *)&top[24] = this;
  *(float *)&v78 = v77->rect.bottom - v77->rect.top;
  v77->textCoord.x = 0.0;
  str.tyreCompound = v78;
  v77->textCoord.y = *(float *)&v78;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_2dcf80c3bdb6e700a23ccce0517e41f3_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v79 = (Event<OnMouseWheelMovedEvent> *)&this->btRepairSusp->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v79,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  ksgui::Form::setPosition((ksgui::Form *)this->btRepairSusp, 66.0, 360.0);
  this->parentControl->addControl(this->parentControl, this->btRepairSusp);
  *(float *)&v80 = COERCE_FLOAT(operator new(448));
  pitCrew = v80;
  LOBYTE(v149) = 54;
  if ( *(float *)&v80 == 0.0 )
  {
    v81 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_REPAIR_BODY");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v80, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->btRepairBody = v81;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/repair_body");
  ksgui::ActiveButton::setMultipleTexture(this->btRepairBody, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, L"REPAIR BODY");
  v82 = this->btRepairBody;
  LOBYTE(v149) = 55;
  v82->setText(v82, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btRepairBody->setSize)(
    this->btRepairBody,
    1115684864,
    1115684864);
  v83 = this->btRepairBody;
  str.fuel = 0.0;
  *(_DWORD *)&top[24] = this;
  *(float *)&v84 = v83->rect.bottom - v83->rect.top;
  v83->textCoord.x = 0.0;
  str.tyreCompound = v84;
  v83->textCoord.y = *(float *)&v84;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_0eaafe90cf3ef3efbedd79d82ce4dc16_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v85 = (Event<OnMouseWheelMovedEvent> *)&this->btRepairBody->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v85,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->btRepairBody,
    (float)((float)(this->parentControl->rect.right - this->parentControl->rect.left) * 0.5)
  - (float)((float)(this->btRepairSusp->rect.right - this->btRepairSusp->rect.left) * 0.5),
    360.0);
  this->parentControl->addControl(this->parentControl, this->btRepairBody);
  *(float *)&v86 = COERCE_FLOAT(operator new(448));
  pitCrew = v86;
  LOBYTE(v149) = 57;
  if ( *(float *)&v86 == 0.0 )
  {
    v87 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_REPAIR_ENGINE");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v86, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->btRepairEngine = v87;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/repair_engine");
  ksgui::ActiveButton::setMultipleTexture(this->btRepairEngine, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, L"REPAIR ENGINE");
  v88 = this->btRepairEngine;
  LOBYTE(v149) = 58;
  v88->setText(v88, &compound);
  LOBYTE(v149) = 18;
  if ( compound._Myres >= 8 )
    operator delete(compound._Bx._Ptr);
  ((void (*)(ksgui::ActiveButton *, int, int))this->btRepairEngine->setSize)(
    this->btRepairEngine,
    1115684864,
    1115684864);
  v89 = this->btRepairEngine;
  str.fuel = 0.0;
  *(_DWORD *)&top[24] = this;
  *(float *)&v90 = v89->rect.bottom - v89->rect.top;
  v89->textCoord.x = 0.0;
  str.tyreCompound = v90;
  v89->textCoord.y = *(float *)&v90;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_a5b8a3eb2ac5847a8a5fd35fce9089a3_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v91 = (Event<OnMouseWheelMovedEvent> *)&this->btRepairEngine->evClicked;
  LOBYTE(v149) = 18;
  Event<ksgui::OnControlClicked>::addHandler(
    v91,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  *(_DWORD *)&top[24] = v92;
  v93 = this->parentControl;
  *(_DWORD *)&top[24] = 1135869952;
  v94 = ksgui::Control::getWidth(v93);
  v95 = this->btRepairSusp;
  *(float *)&pitCrew = v94;
  *(float *)&v129.pitCrew = ksgui::Control::getWidth(v95);
  *(_DWORD *)&top[20] = v96;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->btRepairEngine,
    (float)(*(float *)&pitCrew - *(float *)&v129.pitCrew) - 50.0,
    *(float *)&top[24]);
  this->parentControl->addControl(this->parentControl, this->btRepairEngine);
  *(float *)&v97 = COERCE_FLOAT(operator new(448));
  pitCrew = v97;
  LOBYTE(v149) = 60;
  if ( *(float *)&v97 == 0.0 )
  {
    v98 = 0;
  }
  else
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    std::wstring::wstring((std::wstring *)top, L"BUT_VOTE_NEXT_PAGE");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v97, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
  }
  LOBYTE(v149) = 18;
  this->confirmButton = v98;
  std::wstring::wstring((std::wstring *)&top[4], L"content/gui/pitstop/confirm_button");
  ksgui::ActiveButton::setMultipleTexture(this->confirmButton, v3, *(std::wstring *)&top[4]);
  std::wstring::wstring(&compound, word_17BE9D8);
  v99 = this->confirmButton;
  LOBYTE(v149) = 61;
  v99->setText(v99, &compound);
  LOBYTE(v149) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&compound);
  ((void (*)(ksgui::ActiveButton *, int, int))this->confirmButton->setSize)(
    this->confirmButton,
    1115684864,
    1115684864);
  v100 = this->confirmButton;
  *(float *)&top[24] = ksgui::Control::getHeight(v100);
  vec2f::vec2f((vec2f *)&str, 0.0, *(float *)&top[24]);
  v100[1].__vftable = *v101;
  v100[1].name._Bx._Ptr = (wchar_t *)v101[1];
  ksgui::Form::setPosition((ksgui::Form *)this->confirmButton, 450.0, 515.0);
  *(_DWORD *)&top[24] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&pitCrew,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)top,
    v102);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->confirmButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  this->parentControl->addControl(this->parentControl, this->confirmButton);
  *(_DWORD *)&top[24] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&pitCrew,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (OnMouseDownEvent const &)>::function<void __cdecl (OnMouseDownEvent const &)>(
    (std::function<void __cdecl(OnMouseDownEvent const &)> *)top,
    v103);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseDown,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  *(_DWORD *)&top[24] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&pitCrew,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (OnMouseUpEvent const &)>::function<void __cdecl (OnMouseUpEvent const &)>(
    (std::function<void __cdecl(OnMouseUpEvent const &)> *)top,
    v104);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseUp,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  *(_DWORD *)&top[24] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&pitCrew,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (OnMouseMoveEvent const &)>::function<void __cdecl (OnMouseMoveEvent const &)>(
    (std::function<void __cdecl(OnMouseMoveEvent const &)> *)top,
    v105);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->game->window.evOnMouseMove,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)top,
    *(void **)&top[24]);
  *(_DWORD *)&top[24] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&pitCrew,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (OnNewSessionEvent const &)>::function<void __cdecl (OnNewSessionEvent const &)>(
    (std::function<void __cdecl(OnNewSessionEvent const &)> *)top,
    v106);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->sim->evOnNewSession,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)top,
    *(void **)&top[24]);
  std::wstring::wstring(&myText, L"content/gui/pitstop/operating_repair.png");
  *(_DWORD *)&top[24] = 0;
  LOBYTE(v149) = 62;
  *(_DWORD *)&top[20] = &myText;
  *(_DWORD *)&top[16] = &compound;
  v107 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->game->graphics->resourceStore);
  v108 = ResourceStore::getTexture(v107, *(Texture **)&top[16], *(const std::wstring **)&top[20], top[24]);
  LOBYTE(v149) = 63;
  Texture::operator=(&this->txRepairing, v108);
  LOBYTE(v149) = 62;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&compound);
  LOBYTE(v149) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&myText);
  std::wstring::wstring((std::wstring *)&filename, L"content/gui/pitstop/operating_fuel.png");
  *(_DWORD *)&top[24] = 0;
  LOBYTE(v149) = 64;
  *(_DWORD *)&top[20] = &filename;
  *(_DWORD *)&top[16] = &compound;
  v109 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->game->graphics->resourceStore);
  v110 = ResourceStore::getTexture(v109, *(Texture **)&top[16], *(const std::wstring **)&top[20], top[24]);
  LOBYTE(v149) = 65;
  Texture::operator=(&this->txFueling, v110);
  LOBYTE(v149) = 64;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&compound);
  LOBYTE(v149) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  std::wstring::wstring(&skin, L"content/gui/pitstop/operating_tyres.png");
  LOBYTE(v149) = 66;
  *(_DWORD *)&top[24] = 0;
  *(_DWORD *)&top[20] = &skin;
  *(_DWORD *)&top[16] = &filename;
  v111 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->game->graphics->resourceStore);
  v112 = ResourceStore::getTexture(v111, *(Texture **)&top[16], *(const std::wstring **)&top[20], top[24]);
  LOBYTE(v149) = 67;
  Texture::operator=(&this->txTyreChanging, v112);
  LOBYTE(v149) = 66;
  OnSetupAppCreated::~OnSetupAppCreated(&filename);
  LOBYTE(v149) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
  v113 = this->sim;
  *(_DWORD *)&top[24] = &myText;
  v114 = Sim::getCar(v113, 0);
  v115 = CarAvatar::getCurrentSkin(v114, *(std::wstring **)&top[24]);
  v116 = this->sim;
  LOBYTE(v149) = 68;
  v117 = Sim::getCar(v116, 0);
  v118 = std::operator+<wchar_t>(&compound, L"content/cars/", &v117->unixName);
  LOBYTE(v149) = 69;
  v119 = std::operator+<wchar_t>((std::wstring *)&filename, v118, L"/skins/");
  LOBYTE(v149) = 70;
  std::operator+<wchar_t>(&skin, v119, v115);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&compound);
  LOBYTE(v149) = 74;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&myText);
  *(float *)&v120 = COERCE_FLOAT(operator new(100));
  pitCrew = v120;
  LOBYTE(v149) = 75;
  if ( *(float *)&v120 == 0.0 )
  {
    *(float *)&v124 = 0.0;
  }
  else
  {
    *(float *)&v129.pitCrew = COERCE_FLOAT(&top[4]);
    std::wstring::wstring((std::wstring *)&top[4], &skin);
    v121 = this->sim;
    LOBYTE(v149) = 76;
    v122 = Sim::getCar(v121, 0);
    LOBYTE(v149) = 75;
    PitCrew::PitCrew(v120, v122, *(std::wstring *)&top[4]);
    v124 = v123;
  }
  LOBYTE(v149) = 74;
  pitCrew = v124;
  GameObject::addGameObject<ProximityIndicator>(this, v124);
  this->sim->blurredNode->addChild(this->sim->blurredNode, v124->pitcrews);
  *(_DWORD *)&top[24] = this;
  std::_Callable_obj<_lambda_4b59d039ab703025dddb443a6cef518a_,0>::_Callable_obj<_lambda_4b59d039ab703025dddb443a6cef518a_,0>(
    &v129,
    &pitCrew);
  std::function<void __cdecl (float const &)>::function<void __cdecl (float const &)>(
    (std::function<void __cdecl(float const &)> *)top,
    v125);
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->sim->game->evOnPostUpdate,
    *(std::function<void __cdecl(SessionInfo const &)> *)top,
    *(void **)&top[24]);
  LOBYTE(v149) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
  PitStopStrategy::PitStopStrategy(&str);
  str.tyreCompound = 2;
  std::vector<PitStopStrategy>::push_back((std::vector<PenaltyRecord> *)&this->strategies, (PenaltyRecord *)&str);
  LOBYTE(v149) = 14;
  INIReaderDocuments::~INIReaderDocuments(&gameplayINI);
  LOBYTE(v149) = 11;
  KN5IO::~KN5IO(&kn5);
}
void PitStop::~PitStop(PitStop *this)
{
  std::vector<float> *v2; // edi
  std::vector<std::pair<int,float>> *v3; // edi
  std::vector<ksgui::ActiveButton *> *v4; // edi
  std::_Ref_count_base *v5; // edi

  this->__vftable = (PitStop_vtbl *)&PitStop::`vftable';
  v2 = &this->psi;
  if ( this->psi._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->psi);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->wings;
  if ( this->wings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->wings);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->wings._Mylast = 0;
    this->wings._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->txTyreChanging);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txFueling);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txRepairing);
  v4 = &this->btTyres;
  if ( this->btTyres._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->btTyres);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->btTyres._Mylast = 0;
    this->btTyres._Myend = 0;
  }
  v5 = this->font._Rep;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v5->_Weaks) )
        v5->_Delete_this(v5);
    }
  }
  if ( this->desiredTyreCompound._Myres >= 8 )
    operator delete(this->desiredTyreCompound._Bx._Ptr);
  this->desiredTyreCompound._Myres = 7;
  this->desiredTyreCompound._Mysize = 0;
  this->desiredTyreCompound._Bx._Buf[0] = 0;
  if ( this->strategies._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->strategies);
    operator delete(this->strategies._Myfirst);
    this->strategies._Myfirst = 0;
    this->strategies._Mylast = 0;
    this->strategies._Myend = 0;
  }
  if ( this->evPitStopOver.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evPitStopOver);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evPitStopOver,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evPitStopOver.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evPitStopOver.handlers._Mylast);
    operator delete(this->evPitStopOver.handlers._Myfirst);
    this->evPitStopOver.handlers._Myfirst = 0;
    this->evPitStopOver.handlers._Mylast = 0;
    this->evPitStopOver.handlers._Myend = 0;
  }
  if ( this->evPitStopCommit.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evPitStopCommit);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evPitStopCommit,
      (Task *)this->evPitStopCommit.handlers._Myfirst,
      (Task *)this->evPitStopCommit.handlers._Mylast);
    operator delete(this->evPitStopCommit.handlers._Myfirst);
    this->evPitStopCommit.handlers._Myfirst = 0;
    this->evPitStopCommit.handlers._Mylast = 0;
    this->evPitStopCommit.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
PitStop *PitStop::`scalar deleting destructor'(PitStop *this, unsigned int a2)
{
  PitStop::~PitStop(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PitStop::commitChanges(PitStop *this)
{
  unsigned int v2; // esi
  std::wstring *v3; // ebx
  CarAvatar *v4; // eax
  Car *v5; // eax
  Sim *v6; // ecx
  std::function<void __cdecl(void)> v7; // [esp-18h] [ebp-3Ch] BYREF
  int v8; // [esp+20h] [ebp-4h]

  v2 = 0;
  v3 = &this->desiredTyreCompound;
  do
  {
    v4 = Sim::getCar(this->sim, 0);
    CarAvatar::setTyreCompound(v4, v2++, v3);
  }
  while ( v2 < 4 );
  v5 = RaceEngineer::getCar(this->avatar->raceEngineer._Myptr);
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_9aaec0a55a35c1b6a7a6ec5f0ab24beb_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  *(_QWORD *)&v7._Space._Alias[4] = __PAIR64__((unsigned int)this, (unsigned int)v5);
  v7._Impl = (std::_Func_base<void> *)&v7;
  v6 = this->sim;
  v8 = -1;
  PhysicsAvatar::executeOnPhysicsThread(v6->physicsAvatar, v7);
}
void PitStop::commitQuickMenuChanges(PitStop *this)
{
  Sim *v2; // edi
  GameObject **v3; // esi
  QuickMenuPitstop *v4; // ecx
  CarAvatar *v5; // eax
  int v6; // xmm0_4
  int v7; // ecx
  unsigned __int64 v8; // xmm0_8
  int v9; // eax
  Sim *v10; // ecx
  std::function<void __cdecl(void)> v11; // [esp-18h] [ebp-4Ch] BYREF
  int v12; // [esp+10h] [ebp-24h]
  int v13; // [esp+14h] [ebp-20h]
  float v14; // [esp+18h] [ebp-1Ch]
  unsigned __int64 v15; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+24h] [ebp-10h]
  int v17; // [esp+30h] [ebp-4h]

  v2 = this->sim;
  v3 = v2->gameObjects._Myfirst;
  if ( v3 == v2->gameObjects._Mylast )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = (QuickMenuPitstop *)__RTDynamicCast(
                                 *v3,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &QuickMenuPitstop `RTTI Type Descriptor',
                                 0);
      if ( v4 )
        break;
      if ( ++v3 == v2->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  v5 = this->avatar;
  *(float *)&v6 = this->getFuel + v5->physicsState.fuel;
  v14 = v5->physicsState.fuel;
  v13 = v6;
  *(float *)&v12 = QuickMenuPitstop::getMaxFuel(v4);
  if ( *(float *)&v6 <= *(float *)&v12 )
  {
    if ( v14 <= *(float *)&v6 )
      v12 = v6;
    else
      *(float *)&v12 = v14;
  }
  v15 = __PAIR64__((unsigned int)RaceEngineer::getCar(this->avatar->raceEngineer._Myptr), (unsigned int)this);
  v16 = v12;
  v14 = COERCE_FLOAT(&v11);
  v11._Impl = 0;
  v17 = 0;
  v7 = operator new(20);
  if ( !v7 )
    std::_Xbad_alloc();
  v8 = v15;
  v9 = v16;
  *(_DWORD *)v7 = &std::_Func_impl<std::_Callable_obj<_lambda_3195e212f93afa368f8c03c3d10cbb05_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  *(_QWORD *)(v7 + 4) = v8;
  *(_DWORD *)(v7 + 12) = v9;
  v11._Impl = (std::_Func_base<void> *)v7;
  v10 = this->sim;
  v17 = -1;
  PhysicsAvatar::executeOnPhysicsThread(v10->physicsAvatar, v11);
}
double PitStop::getEstimatedTime(PitStop *this)
{
  bool v2; // bl
  float v3; // xmm1_4
  float v5; // [esp+20h] [ebp-20h]
  bool repairSus; // [esp+24h] [ebp-1Ch]
  bool repairEngine; // [esp+28h] [ebp-18h]
  bool changeTyres; // [esp+2Ch] [ebp-14h]
  PitStopTime result; // [esp+30h] [ebp-10h] BYREF

  v2 = this->btRepairBody->selected || this->btRepairSusp->selected;
  repairSus = this->btRepairSusp->selected;
  repairEngine = this->btRepairEngine->selected;
  changeTyres = std::wstring::compare(&this->desiredTyreCompound, 0, this->desiredTyreCompound._Mysize, word_17BE9D8, 0) != 0;
  if ( SetupScreen::isFixedFuel(this->sim->escMenu->setupScreen) )
  {
    v5 = SetupScreen::getFixedFuel(this->sim->escMenu->setupScreen);
    v3 = v5;
  }
  else
  {
    v3 = this->avatar->physicsInfo.maxFuel;
  }
  return CarAvatar::getPitstopTime(
           this->avatar,
           &result,
           this->fuelControl->requestedFuelToAddPercentage * v3,
           changeTyres,
           v2,
           repairEngine,
           repairSus,
           0)->total;
}
double PitStop::getPitStopFuelingPercentage(PitStop *this)
{
  float v1; // xmm2_4

  v1 = (float)(this->pitTimer - (float)(this->maxPitTimer - this->fuelTime)) / this->fuelTime;
  if ( v1 > 1.0 )
    return 1.0 - 1.0;
  if ( v1 >= 0.0 )
    return 1.0 - v1;
  return 1.0 - 0.0;
}
double PitStop::getPitStopRepairingPercentage(PitStop *this)
{
  float v1; // xmm2_4

  v1 = (float)(this->pitTimer - (float)(this->maxPitTimer - this->repairTime)) / this->repairTime;
  if ( v1 > 1.0 )
    return 1.0 - 1.0;
  if ( v1 >= 0.0 )
    return 1.0 - v1;
  return 1.0 - 0.0;
}
double PitStop::getRealMaxFuel(PitStop *this)
{
  double result; // st7

  if ( SetupScreen::isFixedFuel(this->sim->escMenu->setupScreen) )
    result = SetupScreen::getFixedFuel(this->sim->escMenu->setupScreen);
  else
    result = this->avatar->physicsInfo.maxFuel;
  return result;
}
bool PitStop::isCarInPitLane(PitStop *this)
{
  CarAvatar *v1; // eax

  v1 = Sim::getCar(this->sim, 0);
  return CarAvatar::isInPitlane(v1);
}
char PitStop::isCarOutOfPitArea(PitStop *this)
{
  mat44f *v2; // eax
  float v3; // xmm2_4

  v2 = &Sim::getCar(this->sim, 0)->bodyMatrix;
  v3 = (float)((float)((float)(this->pitPosition.y - v2->M42) * (float)(this->pitPosition.y - v2->M42))
             + (float)((float)(this->pitPosition.x - v2->M41) * (float)(this->pitPosition.x - v2->M41)))
     + (float)((float)(this->pitPosition.z - v2->M43) * (float)(this->pitPosition.z - v2->M43));
  if ( v3 == 0.0 || fsqrt(v3) < 3.0 )
    return 0;
  this->pitIndicator->isActive = 1;
  return 1;
}
BOOL PitStop::isChangingTyres(PitStop *this)
{
  BOOL result; // eax

  if ( this->sim->useMousePitstop )
    result = std::wstring::compare(&this->desiredTyreCompound, 0, this->desiredTyreCompound._Mysize, word_17BE9D8, 0) != 0;
  else
    result = this->newCompound >= 0;
  return result;
}
bool PitStop::isInPitPosition(PitStop *this)
{
  bool v2; // bl
  CarAvatar *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  bool v6; // al
  Sim *v7; // ecx
  CarAvatar *v9; // eax
  ICarControlsProvider *v10; // eax
  KeyboardCarControl *v11; // eax
  bool v12; // cl
  CarAvatar *v13; // esi
  double v14; // st7
  int v15; // edx
  ksgui::ActiveButton **v16; // ecx
  unsigned int v17; // esi
  ksgui::ActiveButton *v18; // eax

  v2 = this->displayingPitMenu;
  v3 = Sim::getCar(this->sim, 0);
  v4 = this->pitPosition.y - v3->bodyMatrix.M42;
  v5 = (float)((float)((float)(this->pitPosition.x - v3->bodyMatrix.M41)
                     * (float)(this->pitPosition.x - v3->bodyMatrix.M41))
             + (float)(v4 * v4))
     + (float)((float)(this->pitPosition.z - v3->bodyMatrix.M43) * (float)(this->pitPosition.z - v3->bodyMatrix.M43));
  v6 = (v5 == 0.0 || fsqrt(v5) < 3.0)
    && ((float)(Sim::getCar(this->sim, 0)->physicsState.speed.value * 3.5999999) < 1.5 || this->displayingPitMenu);
  this->displayingPitMenu = v6;
  if ( v6 && (float)(Sim::getCar(this->sim, 0)->physicsState.speed.value * 3.5999999) >= 2.0 )
    this->displayingPitMenu = 0;
  v7 = this->sim;
  if ( !v7->useMousePitstop )
    return this->displayingPitMenu;
  if ( !v2 )
  {
    if ( !this->displayingPitMenu )
      return 0;
    v9 = Sim::getCar(v7, 0);
    v10 = CarAvatar::getControlsProvider(v9);
    v11 = (KeyboardCarControl *)__RTDynamicCast(
                                  v10,
                                  0,
                                  &ICarControlsProvider `RTTI Type Descriptor',
                                  &KeyboardCarControl `RTTI Type Descriptor',
                                  0);
    if ( v11 )
    {
      v12 = v11->mouseSteering;
      this->mouseSteeringEnabled = v12;
      if ( v12 )
        KeyboardCarControl::setMouseSteering(v11, 0);
    }
    v13 = this->avatar;
    v14 = PitStop::getRealMaxFuel(this);
    v15 = 0;
    this->fuelControl->fuelPercentage = v13->physicsState.fuel / v14;
    this->fuelControl->requestedFuelToAddPercentage = 0.0;
    v16 = this->btTyres._Myfirst;
    v17 = (unsigned int)((char *)this->btTyres._Mylast - (char *)v16 + 3) >> 2;
    if ( v16 > this->btTyres._Mylast )
      v17 = 0;
    if ( v17 )
    {
      do
      {
        v18 = *v16++;
        ++v15;
        v18->selected = 0;
      }
      while ( v15 != v17 );
    }
    (*this->btTyres._Myfirst)->selected = 1;
    std::wstring::assign(&this->desiredTyreCompound, word_17BE9D8, 0);
    this->btRepairBody->selected = 0;
    this->btRepairEngine->selected = 0;
    this->btRepairSusp->selected = 0;
  }
  if ( this->displayingPitMenu )
  {
    ksgui::Control::setVisible(this->parentControl, 1);
    return 1;
  }
  return 0;
}
BOOL PitStop::isPitStopDone(PitStop *this, float dt)
{
  CarAvatar *v3; // eax
  Sim *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm0_4
  CarAvatar *v7; // eax
  ICarControlsProvider *v8; // eax
  KeyboardCarControl *v9; // eax
  float v11; // [esp+4h] [ebp-4h]

  v3 = Sim::getCar(this->sim, 0);
  CarAvatar::setControlsLock(v3, 1);
  this->sim->gameScreen->appInteractionEnabled = 0;
  this->pitIndicator->isActive = 0;
  v4 = this->sim;
  v11 = v4->game->gameTime.now;
  Sim::getCar(v4, 0)->lastPitstopTime = v11;
  v5 = this->pitTimer;
  if ( v5 > 0.0 )
  {
    v6 = v5 - dt;
    this->pitTimer = v6;
    if ( v6 <= 0.0 )
    {
      if ( this->sim->useMousePitstop )
      {
        ksgui::Control::setVisible(this->parentControl, 0);
        PitStop::commitChanges(this);
        v7 = Sim::getCar(this->sim, 0);
        v8 = CarAvatar::getControlsProvider(v7);
        v9 = (KeyboardCarControl *)__RTDynamicCast(
                                     v8,
                                     0,
                                     &ICarControlsProvider `RTTI Type Descriptor',
                                     &KeyboardCarControl `RTTI Type Descriptor',
                                     0);
        if ( v9 && this->mouseSteeringEnabled )
          KeyboardCarControl::setMouseSteering(v9, 1);
      }
      else
      {
        PitStop::commitQuickMenuChanges(this);
      }
      this->sim->gameScreen->appInteractionEnabled = 1;
    }
  }
  return this->pitTimer <= 0.0;
}
void __userpurge PitStop::renderHUD(PitStop *this@<ecx>, float dt, int a3)
{
  Sim *v4; // ecx
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  GLRenderer *v7; // ebx
  PitStopState v8; // eax
  __int32 v9; // eax
  __int64 v10; // rax
  int v11; // esi
  GraphicsManager *v12; // edi
  float v13; // xmm0_4
  int v14; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  Game *v18; // eax
  Font *v19; // ecx
  Game *v20; // eax
  Font *v21; // ecx
  Game *v22; // eax
  Font *v23; // ecx
  std::wostream *v24; // eax
  std::wostream *v25; // eax
  std::wostream *v26; // eax
  std::wostream *v27; // eax
  const std::wstring *v28; // eax
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  const std::wstring *v31; // eax
  int width; // [esp+18h] [ebp-1B4h]
  const char *widtha; // [esp+18h] [ebp-1B4h]
  float height; // [esp+1Ch] [ebp-1B0h]
  float heighta; // [esp+1Ch] [ebp-1B0h]
  float heightb; // [esp+1Ch] [ebp-1B0h]
  int a; // [esp+24h] [ebp-1A8h]
  const wchar_t *v38; // [esp+28h] [ebp-1A4h]
  float y; // [esp+40h] [ebp-18Ch]
  float v40; // [esp+40h] [ebp-18Ch]
  float v41; // [esp+40h] [ebp-18Ch]
  float v42; // [esp+44h] [ebp-188h]
  float v43; // [esp+44h] [ebp-188h]
  float v44; // [esp+44h] [ebp-188h]
  float x; // [esp+48h] [ebp-184h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+4Ch] [ebp-180h] BYREF
  std::wstring v47; // [esp+FCh] [ebp-D0h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement s; // [esp+118h] [ebp-B4h] BYREF
  std::wstring _Newstr; // [esp+144h] [ebp-88h] BYREF
  std::wstring v50; // [esp+15Ch] [ebp-70h] BYREF
  std::wstring v51; // [esp+178h] [ebp-54h] BYREF
  std::wstring result; // [esp+190h] [ebp-3Ch] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v53; // [esp+1A8h] [ebp-24h] BYREF
  int v54; // [esp+1C8h] [ebp-4h]
  void *retaddr; // [esp+1CCh] [ebp+0h]

  x = 0.0;
  v4 = this->sim;
  if ( !v4->pauseMenu->visible && !ReplayManager::isInReplaymode(v4->replayManager) )
  {
    v5 = this->sim;
    if ( !v5->escMenu->visible )
    {
      if ( this->indicatorOnlyInPitline )
      {
        v6 = Sim::getCar(v5, 0);
        this->pitIndicator->isActive = CarAvatar::isInPitlane(v6);
      }
      if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
      {
        if ( Sim::getCar(this->sim, 0)->physicsState.lockControlsTime > 0.0 )
          this->state = Finishing;
        v7 = this->game->graphics->gl;
        *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(ws.gap68);
        v54 = 0;
        LODWORD(x) = 1;
        std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
        v54 = 1;
        *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)((char *)&x + *(_DWORD *)(*(_DWORD *)ws.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&ws.gap10[8]);
        *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&ws.gap10[64] = 0;
        *(_DWORD *)&ws.gap10[68] = 0;
        v8 = this->state;
        v54 = 3;
        v9 = v8 - 2;
        if ( v9 )
        {
          if ( v9 == 1 )
          {
            GLRenderer::color4f(v7, &colDarkTransp_3);
            GLRenderer::quad(
              v7,
              (float)(this->game->graphics->videoSettings.width / 2 - 75),
              (float)(this->game->graphics->videoSettings.height / 2 - 110),
              150.0,
              220.0,
              0,
              0);
            v10 = this->game->graphics->videoSettings.width;
            v11 = (((int)v10 - HIDWORD(v10)) >> 1) - 73;
            v12 = this->game->graphics;
            v13 = (float)(Texture::width(&this->txTyreChanging) - 63 + v12->videoSettings.width / 2);
            v14 = v12->videoSettings.height / 2 - 100;
            x = v13;
            y = (float)v14;
            GraphicsManager::setTexture(v12, 0, &this->txTyreChanging);
            GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
            height = (float)Texture::height(&this->txTyreChanging);
            v15 = (float)Texture::width(&this->txTyreChanging);
            GLRenderer::quad(v7, (float)v11, y, v15, height, 1, 0);
            GLRenderer::color4f(v7, &colTitleBar_4);
            v42 = PitStop::getPitStopTyrePercentage(this);
            GLRenderer::quad(v7, x, y + 12.0, (float)(1.0 - v42) * 80.0, 20.0, 0, 0);
            v40 = y + 75.0;
            GraphicsManager::setTexture(this->game->graphics, 0, &this->txRepairing);
            GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
            heighta = (float)Texture::height(&this->txRepairing);
            v16 = (float)Texture::width(&this->txRepairing);
            GLRenderer::quad(v7, (float)v11, v40, v16, heighta, 1, 0);
            GLRenderer::color4f(v7, &colTitleBar_4);
            v43 = PitStop::getPitStopRepairingPercentage(this);
            GLRenderer::quad(v7, x, v40 + 12.0, (float)(1.0 - v43) * 80.0, 20.0, 0, 0);
            v41 = v40 + 75.0;
            GraphicsManager::setTexture(this->game->graphics, 0, &this->txFueling);
            GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
            heightb = (float)Texture::height(&this->txFueling);
            v17 = (float)Texture::width(&this->txFueling);
            GLRenderer::quad(v7, (float)v11, v41, v17, heightb, 1, 0);
            GLRenderer::color4f(v7, &colTitleBar_4);
            v44 = PitStop::getPitStopFuelingPercentage(this);
            GLRenderer::quad(v7, x, v41 + 12.0, (float)(1.0 - v44) * 80.0, 20.0, 0, 0);
          }
        }
        else
        {
          GLRenderer::color4f(v7, &colTitleBar_4);
          GLRenderer::quad(v7, (float)(this->game->graphics->videoSettings.width / 2) - 325.0, 75.0, 650.0, 20.0, 0, 0);
          Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
          std::wstring::wstring((std::wstring *)&s.name._Myres, L"SELECT TYRES COMPOUND");
          v18 = this->game;
          v19 = this->font._Ptr;
          LOBYTE(v54) = 4;
          Font::blitString(
            v19,
            (float)(v18->graphics->videoSettings.width / 2),
            75.0,
            (const std::wstring *)&s.name._Myres,
            1.0,
            eAlignCenter);
          LOBYTE(v54) = 3;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s.name._Myres);
          GLRenderer::color4f(v7, &colDarkTransp_3);
          GLRenderer::quad(v7, (float)(this->game->graphics->videoSettings.width / 2) - 325.0, 95.0, 650.0, 115.0, 0, 0);
          GLRenderer::color4f(v7, &colTitleBar_4);
          GLRenderer::quad(v7, (float)(this->game->graphics->videoSettings.width / 2) - 325.0, 235.0, 650.0, 20.0, 0, 0);
          Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
          std::wstring::wstring(&v50, L"SELECT FUEL AMOUNT");
          v20 = this->game;
          v21 = this->font._Ptr;
          LOBYTE(v54) = 5;
          Font::blitString(v21, (float)(v20->graphics->videoSettings.width / 2), 235.0, &v50, 1.0, eAlignCenter);
          LOBYTE(v54) = 3;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v50);
          GLRenderer::color4f(v7, &colDarkTransp_3);
          GLRenderer::quad(
            v7,
            (float)(this->game->graphics->videoSettings.width / 2) - 325.0,
            255.0,
            650.0,
            115.0,
            0,
            0);
          GLRenderer::color4f(v7, &colTitleBar_4);
          GLRenderer::quad(v7, (float)(this->game->graphics->videoSettings.width / 2) - 325.0, 395.0, 650.0, 20.0, 0, 0);
          Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
          std::wstring::wstring(&v47, L"SELECT DAMAGE REPAIR");
          v22 = this->game;
          v23 = this->font._Ptr;
          LOBYTE(v54) = 6;
          Font::blitString(v23, (float)(v22->graphics->videoSettings.width / 2), 395.0, &v47, 1.0, eAlignCenter);
          LOBYTE(v54) = 3;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v47);
          GLRenderer::color4f(v7, &colDarkTransp_3);
          GLRenderer::quad(
            v7,
            (float)(this->game->graphics->videoSettings.width / 2) - 325.0,
            415.0,
            650.0,
            115.0,
            0,
            0);
          GLRenderer::color4f(v7, &colDarkTransp_3);
          GLRenderer::quad(
            v7,
            (float)(this->game->graphics->videoSettings.width / 2) - 325.0,
            575.0,
            650.0,
            115.0,
            0,
            0);
          GLRenderer::color4f(v7, &colTitleBar_4);
          GLRenderer::quad(v7, (float)(this->game->graphics->videoSettings.width / 2) - 325.0, 612.5, 650.0, 20.0, 0, 0);
          std::wstring::wstring(&_Newstr, word_17BE9D8);
          LOBYTE(v54) = 7;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &_Newstr);
          LOBYTE(v54) = 3;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Newstr);
          PitStop::getRealMaxFuel(this);
          width = (int)this->avatar->physicsState.fuel;
          v24 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ws.gap10, L"Tank :");
          v25 = (std::wostream *)std::wostream::operator<<(v24, width);
          v26 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v25, widtha);
          v27 = (std::wostream *)std::wostream::operator<<(v26, " L Add ");
          std::operator<<<wchar_t,std::char_traits<wchar_t>>(v27, v38);
          v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                  (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&ws.gap0[4],
                  &result);
          Font::blitString(
            this->font._Ptr,
            this->parentControl->rect.left + 100.0,
            (float)(this->parentControl->rect.top + 200.0) + 50.0,
            v28,
            1.0,
            eAlignLeft);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::wstring(&v51, word_17BE9D8);
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&ws.gap0[4],
            &v51);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51);
          a = (int)PitStop::getEstimatedTime(this);
          v29 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
                  (std::wostream *)&ws.gap10[4],
                  L"ESTIMATED PIT STOP TIME : ");
          v30 = (std::wostream *)std::wostream::operator<<(v29, a);
          std::operator<<<wchar_t,std::char_traits<wchar_t>>(v30, " sec");
          Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
          v31 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                  (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&ws.gap0[4],
                  &v53.name);
          Font::blitString(
            this->font._Ptr,
            (float)(this->game->graphics->videoSettings.width / 2 - 50),
            612.5,
            v31,
            1.0,
            eAlignCenter);
          std::wstring::~wstring(&v53);
          std::wstring::wstring(&s.name, L"CONFIRM");
          Font::blitString(
            this->font._Ptr,
            (float)((float)(this->game->graphics->videoSettings.width / 2) + 325.0) - 50.0,
            612.5,
            &s.name,
            1.0,
            eAlignRight);
          LOBYTE(retaddr) = 3;
          std::wstring::~wstring(&s);
          ((void (*)(ksgui::Control *, int))this->parentControl->render)(this->parentControl, a3);
        }
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ws);
      }
    }
  }
}
void PitStop::update(PitStop *this, float dt)
{
  Sim *v3; // ecx
  Sim *v4; // ecx
  QuickMenuPitstop *v5; // ebp
  QuickMenuPitstopItem *v6; // esi
  QuickMenuPitstopItem *v7; // edi
  float *v8; // eax
  double v9; // st7
  int v10; // eax
  int v11; // eax
  bool v12; // cl
  unsigned int v13; // esi
  float i; // xmm2_4
  std::pair<int,float> *v15; // ecx
  float v16; // xmm1_4
  bool v17; // zf
  CarAvatar *v18; // eax
  float v19; // [esp+28h] [ebp-24h] BYREF
  float ti; // [esp+2Ch] [ebp-20h] BYREF
  PitStopStart pitStart; // [esp+30h] [ebp-1Ch] BYREF
  PitStopTime t; // [esp+3Ch] [ebp-10h] BYREF

  if ( !Sim::getCar(this->sim, 0)->isBlackFlagged )
  {
    if ( !ReplayManager::isInReplaymode(this->sim->replayManager)
      && (RaceManager::getCurrentSessionType(this->sim->raceManager) == Race
       || RaceManager::getCurrentSessionType(this->sim->raceManager) == Qualify
       || RaceManager::getCurrentSessionType(this->sim->raceManager) == Pratice)
      && (v3 = this->sim, !v3->pauseMenu->visible) )
    {
      if ( RaceManager::isRaceOver(v3->raceManager, 0) || this->sim->escMenu->visible )
        this->state = Finishing;
      switch ( this->state )
      {
        case Idle:
          if ( PitStop::isCarInPitLane(this) )
          {
            this->pitIndicator->isActive = 1;
            this->state = GoingToPosition;
          }
          goto LABEL_57;
        case GoingToPosition:
          if ( PitStop::isInPitPosition(this) )
          {
            v4 = this->sim;
            if ( v4->useMousePitstop )
            {
              this->state = UnScrewingTyre;
            }
            else
            {
              v5 = GameObject::getGameObject<QuickMenuPitstop>(v4);
              std::_Container_base0::_Orphan_all(&this->psi);
              this->psi._Mylast = this->psi._Myfirst;
              std::_Container_base0::_Orphan_all(&this->wings);
              this->wings._Mylast = this->wings._Myfirst;
              v6 = v5->items._Myfirst;
              v7 = v5->items._Mylast;
              if ( v6 != v7 )
              {
                while ( 2 )
                {
                  switch ( v6->type )
                  {
                    case Fuel:
                      ti = QuickMenuPitstop::getMaxFuel(v5) - this->avatar->physicsState.fuel;
                      v19 = QuickMenuPitstop::getValue(v5, v6);
                      v8 = &ti;
                      if ( v19 <= ti )
                        v8 = &v19;
                      this->getFuel = *v8;
                      goto LABEL_34;
                    case Wing:
                      v9 = QuickMenuPitstop::getValue(v5, v6);
                      LODWORD(pitStart.tyreChangeTime) = v6->componentIndex;
                      ti = v9;
                      pitStart.totalTime = ti;
                      std::vector<std::pair<int,float>>::push_back(&this->wings, (std::pair<int,float> *)&pitStart);
                      goto LABEL_33;
                    case TyreCompound:
                      this->newCompound = (int)QuickMenuPitstop::getValue(v5, v6);
                      goto LABEL_34;
                    case TyrePressure:
                      ti = QuickMenuPitstop::getValue(v5, v6);
                      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->psi, (int *)&ti);
                      goto LABEL_34;
                    case Repair:
                      v10 = v6->componentIndex;
                      if ( v10 )
                      {
                        v11 = v10 - 1;
                        if ( v11 )
                        {
                          if ( v11 != 1 )
                            goto LABEL_34;
                          ti = QuickMenuPitstop::getValue(v5, v6);
                          this->rengine = ti != 0.0;
                        }
                        else
                        {
                          ti = QuickMenuPitstop::getValue(v5, v6);
                          this->rsusp = ti != 0.0;
                        }
                      }
                      else
                      {
                        ti = QuickMenuPitstop::getValue(v5, v6);
                        this->rbody = ti != 0.0;
                      }
LABEL_33:
                      QuickMenuPitstop::resetControls(v5, v6->index, 0.0);
LABEL_34:
                      if ( ++v6 == v7 )
                        break;
                      continue;
                    default:
                      goto LABEL_34;
                  }
                }
              }
              v12 = this->rbody || this->rsusp;
              CarAvatar::getPitstopTime(
                this->avatar,
                &t,
                this->getFuel,
                this->newCompound != -1,
                v12,
                this->rengine,
                this->rsusp,
                1);
              v13 = 0;
              for ( i = t.total; v13 < this->wings._Mylast - this->wings._Myfirst; ++v13 )
              {
                v15 = this->wings._Myfirst;
                if ( (int)v15[v13].second )
                {
                  ti = QuickMenuPitstop::getWingPitstopTime(v5, v15[v13].first);
                  i = t.total + ti;
                  t.total = t.total + ti;
                  t.repair = t.repair + ti;
                }
              }
              v16 = t.tyres;
              this->repairTime = t.repair;
              this->fuelTime = t.fuel;
              this->pitTimer = i;
              this->tyreTime = v16;
              this->maxPitTimer = i;
              if ( i <= 0.0 )
              {
                this->state = ScrewingTyre;
              }
              else
              {
                v17 = !v5->STAY_IN_CAR;
                pitStart.tyreChangeTime = v16;
                pitStart.forceChangeCamera = v17;
                pitStart.totalTime = i;
                Event<std::wstring>::trigger(
                  (Event<OnGearRequestEvent> *)&this->evPitStopCommit,
                  (const OnGearRequestEvent *)&pitStart);
                this->state = ChangingTyre;
              }
            }
          }
          goto $LN11_3;
        case UnScrewingTyre:
$LN11_3:
          if ( !PitStop::isInPitPosition(this) )
            this->state = GoingToPosition;
          goto LABEL_57;
        case ChangingTyre:
          if ( PitStop::isPitStopDone(this, dt) )
          {
            LOBYTE(dt) = 1;
            Event<std::wstring>::trigger(
              (Event<OnGearRequestEvent> *)&this->evPitStopOver,
              (const OnGearRequestEvent *)&dt);
            this->displayingPitMenu = 0;
            this->state = ScrewingTyre;
          }
          goto LABEL_57;
        case ScrewingTyre:
          this->pitIndicator->isActive = 0;
          if ( PitStop::isCarOutOfPitArea(this) )
            goto LABEL_56;
          goto LABEL_57;
        case Finishing:
          this->pitIndicator->isActive = 0;
          this->pitTimer = 0.0;
          if ( PitStop::isCarOutOfPitArea(this) )
            goto LABEL_56;
          goto LABEL_57;
        default:
          this->pitIndicator->isActive = 0;
LABEL_56:
          this->state = Idle;
LABEL_57:
          v18 = Sim::getCar(this->sim, 0);
          if ( !CarAvatar::isInPitlane(v18) && this->state != Finishing )
            this->state = Idle;
          break;
      }
    }
    else
    {
      this->pitIndicator->isActive = 0;
    }
  }
}
