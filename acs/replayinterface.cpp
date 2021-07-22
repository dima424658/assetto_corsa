#include "replayinterface.h"
void ReplayInterface::ReplayInterface(ReplayInterface *this, ReplayManager *aReplayManager, Sim *aSim)
{
  int v4; // ebx
  Game *v5; // eax
  Texture *v6; // ebp
  ksgui::Label *v7; // edi
  ksgui::Label *v8; // eax
  ksgui::GUI *v9; // eax
  Texture *v10; // eax
  Font *v11; // eax
  Font *v12; // eax
  std::_Ref_count_base *v13; // edi
  ksgui::GUI *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm0_4
  GraphicsManager *v17; // eax
  GraphicsManager *v18; // eax
  ksgui::GUI *v19; // ecx
  float v20; // xmm0_4
  float v21; // eax
  float v22; // xmm0_4
  Event<bool> *v23; // ecx
  Font *v24; // edi
  ksgui::TextInput *v25; // eax
  Font *v26; // edi
  ksgui::Control *v27; // eax
  ksgui::Control *v28; // ecx
  Event<OnMouseWheelMovedEvent> *v29; // ecx
  Font *v30; // edi
  ksgui::Slider *v31; // eax
  Event<ksgui::OnListBoxItemClickedEvent> *v32; // ecx
  Event<ksgui::OnListBoxItemClickedEvent> *v33; // ecx
  Font *v34; // edi
  ksgui::ActiveButton *v35; // eax
  ksgui::ActiveButton *v36; // ecx
  ksgui::ActiveButton *v37; // ecx
  ksgui::GUI *v38; // eax
  Texture *v39; // edx
  ksgui::ActiveButton *v40; // ecx
  void *v41; // eax
  const std::wstring *v42; // edx
  std::wstring *v43; // ecx
  Font *v44; // edi
  ksgui::ActiveButton *v45; // eax
  ksgui::ActiveButton *v46; // ecx
  ksgui::ActiveButton *v47; // ecx
  ksgui::GUI *v48; // eax
  Texture *v49; // edx
  ksgui::ActiveButton *v50; // ecx
  void *v51; // eax
  const std::wstring *v52; // edx
  std::wstring *v53; // ecx
  Font *v54; // edi
  ksgui::ActiveButton *v55; // eax
  ksgui::ActiveButton *v56; // ecx
  ksgui::ActiveButton *v57; // ecx
  ksgui::GUI *v58; // eax
  Texture *v59; // edx
  ksgui::ActiveButton *v60; // ecx
  void *v61; // eax
  const std::wstring *v62; // edx
  std::wstring *v63; // ecx
  Font *v64; // edi
  ksgui::ActiveButton *v65; // eax
  ksgui::ActiveButton *v66; // ecx
  ksgui::ActiveButton *v67; // ecx
  ksgui::GUI *v68; // eax
  Texture *v69; // edx
  ksgui::ActiveButton *v70; // ecx
  void *v71; // eax
  const std::wstring *v72; // edx
  std::wstring *v73; // ecx
  Font *v74; // edi
  ksgui::ActiveButton *v75; // eax
  ksgui::ActiveButton *v76; // ecx
  ksgui::ActiveButton *v77; // ecx
  ksgui::GUI *v78; // eax
  Texture *v79; // edx
  ksgui::ActiveButton *v80; // ecx
  void *v81; // eax
  const std::wstring *v82; // edx
  std::wstring *v83; // ecx
  Font *v84; // edi
  ksgui::ActiveButton *v85; // eax
  ksgui::ActiveButton *v86; // ecx
  ksgui::ActiveButton *v87; // ecx
  ksgui::GUI *v88; // eax
  Texture *v89; // edx
  ksgui::ActiveButton *v90; // ecx
  void *v91; // eax
  const std::wstring *v92; // edx
  std::wstring *v93; // ecx
  Font *v94; // edi
  ksgui::ActiveButton *v95; // eax
  ksgui::ActiveButton *v96; // ecx
  ksgui::ActiveButton *v97; // ecx
  ksgui::GUI *v98; // eax
  Texture *v99; // edx
  ksgui::ActiveButton *v100; // ecx
  void *v101; // eax
  const std::wstring *v102; // edx
  std::wstring *v103; // ecx
  Font *v104; // edi
  ksgui::Spinner *v105; // eax
  Font *v106; // edi
  ksgui::Spinner *v107; // eax
  ksgui::Spinner *v108; // eax
  ksgui::Spinner *v109; // eax
  Font *v110; // edi
  ksgui::Spinner *v111; // eax
  int v112; // eax
  ksgui::Spinner *v113; // ecx
  Font *v114; // edi
  ksgui::ActiveButton *v115; // eax
  ksgui::ActiveButton *v116; // ecx
  ksgui::ActiveButton *v117; // edx
  float *v118; // eax
  ResourceStore *v119; // eax
  const Texture *v120; // eax
  ksgui::ActiveButton *v121; // ecx
  Font *v122; // edi
  ksgui::ActiveButton *v123; // eax
  ResourceStore *v124; // eax
  const Texture *v125; // eax
  ksgui::ActiveButton *v126; // ecx
  ksgui::ActiveButton *v127; // edx
  float *v128; // eax
  ReplayInterface::{ctor}::__l21::<lambda_8ec564c1fafc3b78e3b22242472fcb12> *v129; // eax
  ReplayInterface::{ctor}::__l22::<lambda_d76d3ed440978395be2c62933bd80879> *v130; // eax
  ReplayInterface::{ctor}::__l26::<lambda_2c673dac99c55c56eb775ef604d618ac> *v131; // eax
  ReplayInterface::{ctor}::__l27::<lambda_6cfe70df1760800e6c28a04fadc9c931> *v132; // eax
  ReplayInterface::{ctor}::__l33::<lambda_88aebe8e7e92e65ebcfe9e6d819c36f1> *v133; // eax
  ReplayInterface::{ctor}::__l42::<lambda_a63156a1d7c34b821283a3c485846a4c> *v134; // eax
  ReplayInterface::{ctor}::__l49::<lambda_ddf4e618080d258d39c9dc6f8d48e76a> *v135; // eax
  ReplayInterface::{ctor}::__l56::<lambda_79170e56906ff677fef98aaeb3a1b15b> *v136; // eax
  ReplayInterface::{ctor}::__l62::<lambda_b277ad41c224a3784fddb53c761bdd3c> *v137; // eax
  ReplayInterface::{ctor}::__l70::<lambda_fe5209ac42930180669aeef8a67ad028> *v138; // eax
  ReplayInterface::{ctor}::__l76::<lambda_02b27eb1b8b27a7348662550d52c5c9b> *v139; // eax
  ReplayInterface::{ctor}::__l80::<lambda_f73a00d2f2b08264ee277e757078d1c4> *v140; // eax
  ReplayInterface::{ctor}::__l100::<lambda_e8cfa7e9aaddd05432aa7ad70daf9ed5> *v141; // eax
  double v142; // st7
  ksgui::ActiveButton *v143; // ecx
  double v144; // st7
  ksgui::ActiveButton *v145; // ecx
  double v146; // st7
  ksgui::ActiveButton *v147; // ecx
  double v148; // st7
  ksgui::ActiveButton *v149; // ecx
  double v150; // st7
  ksgui::ActiveButton *v151; // ecx
  double v152; // st7
  ksgui::ActiveButton *v153; // ecx
  double v154; // st7
  ksgui::ActiveButton *v155; // ecx
  double v156; // st7
  ksgui::ksRect *v157; // ecx
  double v158; // st7
  ksgui::Spinner *v159; // ecx
  double v160; // st7
  ksgui::Spinner *v161; // ecx
  double v162; // st7
  Sim *v163; // ecx
  CameraForward *v164; // eax
  ResourceStore *v165; // eax
  const Texture *v166; // eax
  Font *v167; // edi
  ksgui::Spinner *v168; // eax
  ksgui::Spinner *v169; // eax
  ReplayInterface::{ctor}::__l112::<lambda_186c93b6935219ead332f0f0905cfbd1> *v170; // eax
  Font *v171; // edi
  ksgui::Spinner *v172; // eax
  ksgui::Spinner *v173; // eax
  ReplayInterface::{ctor}::__l121::<lambda_8833ae9cb03aa9e139720c80dcd22fbb> *v174; // eax
  Font *v175; // edi
  ksgui::Spinner *v176; // eax
  ksgui::Spinner *v177; // eax
  ReplayInterface::{ctor}::__l135::<lambda_6a47848197992ab31b5c4f6837bc4391> *v178; // eax
  Font *v179; // edi
  ksgui::Spinner *v180; // eax
  ksgui::Spinner *v181; // eax
  ReplayInterface::{ctor}::__l149::<lambda_e25430da128598e0160ba43a9249a5cc> *v182; // eax
  Font *v183; // edi
  ksgui::CustomSpinner *v184; // eax
  ResourceStore *v185; // eax
  ksgui::CustomSpinner *v186; // eax
  ResourceStore *v187; // eax
  ksgui::CustomSpinner *v188; // eax
  ReplayInterface::{ctor}::__l150::<lambda_58949d9e7c57671f4497bc964d44c8cb> *v189; // eax
  ReplayInterface::{ctor}::__l151::<lambda_fee5ffb9cf08fa100b3ca23cf4b1f997> *v190; // eax
  Font *v191; // edi
  ksgui::CustomSpinner *v192; // eax
  ResourceStore *v193; // eax
  ksgui::CustomSpinner *v194; // eax
  ResourceStore *v195; // eax
  ksgui::CustomSpinner *v196; // eax
  ReplayInterface::{ctor}::__l152::<lambda_f14e3f2b70dac5c0cb2269a52f45865d> *v197; // eax
  ReplayInterface::{ctor}::__l153::<lambda_4f8c8057e5106a3c35749d1d3d395180> *v198; // eax
  Font *v199; // edi
  ksgui::CustomSpinner *v200; // eax
  ResourceStore *v201; // eax
  ksgui::CustomSpinner *v202; // eax
  ResourceStore *v203; // eax
  ksgui::CustomSpinner *v204; // eax
  ReplayInterface::{ctor}::__l156::<lambda_fa8842fb027ab1e4e5be5feb1b601442> *v205; // eax
  ReplayInterface::{ctor}::__l159::<lambda_2ded351382148aadca8693d28545c375> *v206; // eax
  Font *v207; // edi
  ksgui::ActiveButton *v208; // eax
  std::wstring *v209; // eax
  ksgui::ActiveButton *v210; // ecx
  ksgui::ActiveButton *v211; // edx
  float *v212; // eax
  ResourceStore *v213; // eax
  const Texture *v214; // eax
  ksgui::ActiveButton *v215; // ecx
  ReplayInterface::{ctor}::__l160::<lambda_ded3707ff4d4c34e080072b4586eb339> *v216; // eax
  double v217; // st7
  ksgui::Spinner *v218; // ecx
  double v219; // st7
  ksgui::Spinner *v220; // ecx
  double v221; // st7
  ksgui::Spinner *v222; // ecx
  double v223; // st7
  ksgui::CustomSpinner *v224; // ecx
  double v225; // st7
  ksgui::CustomSpinner *v226; // ecx
  double v227; // st7
  ksgui::CustomSpinner *v228; // ecx
  double v229; // st7
  ksgui::ksRect *v230; // ecx
  double v231; // st7
  _BYTE v232[28]; // [esp+B4h] [ebp-CCh] BYREF
  float top; // [esp+D0h] [ebp-B0h]
  float v234; // [esp+F8h] [ebp-88h]
  float left; // [esp+FCh] [ebp-84h]
  std::shared_ptr<Font> _Right; // [esp+100h] [ebp-80h] BYREF
  ReplayInterface *v237; // [esp+108h] [ebp-78h]
  std::wstring text; // [esp+10Ch] [ebp-74h] BYREF
  std::wstring iname; // [esp+124h] [ebp-5Ch] BYREF
  Texture result; // [esp+13Ch] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v241; // [esp+158h] [ebp-28h] BYREF
  int v242; // [esp+17Ch] [ebp-4h]

  *(float *)&v4 = 0.0;
  v237 = this;
  left = 0.0;
  v234 = *(float *)&aSim;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"REPLAY_INTERFACE", 0x10u);
  v5 = aSim->game;
  v242 = 0;
  ksgui::Control::Control(this, &iname, v5->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (ReplayInterface_vtbl *)&ReplayInterface::`vftable';
  this->slowMo = 0;
  this->lapIndicatorTexture.kid = 0;
  this->lapIndicatorTexture.fileName._Myres = 7;
  this->lapIndicatorTexture.fileName._Mysize = 0;
  this->lapIndicatorTexture.fileName._Bx._Buf[0] = 0;
  this->cameraNames._Myfirst = 0;
  this->cameraNames._Mylast = 0;
  this->cameraNames._Myend = 0;
  v6 = &this->viewFinder;
  this->currentAzimuth = 0.0;
  this->currentZenith = 0.0;
  this->prevStatus = eReplayStop;
  this->viewFinder.kid = 0;
  this->viewFinder.fileName._Myres = 7;
  this->viewFinder.fileName._Mysize = 0;
  this->viewFinder.fileName._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  *(float *)&v7 = COERCE_FLOAT(operator new(284));
  left = *(float *)&v7;
  v8 = 0;
  LOBYTE(v242) = 6;
  if ( *(float *)&v7 != 0.0 )
  {
    top = *(float *)&this->gui;
    *(_DWORD *)&v232[24] = 7;
    *(_DWORD *)&v232[20] = 0;
    *(_WORD *)&v232[4] = 0;
    std::wstring::assign((std::wstring *)&v232[4], L"MYLABEL", 7u);
    ksgui::Label::Label(v7, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  LOBYTE(v242) = 5;
  this->debugLabel = v8;
  ksgui::Form::setPosition((ksgui::Form *)v8, 0.0, -50.0);
  ksgui::Control::setVisible(this->debugLabel, 0);
  ksgui::Control::addControl(this, this->debugLabel);
  *(float *)&this->sim = v234;
  LODWORD(top) = 35;
  *(_DWORD *)&v232[24] = L"content\\gui\\replay\\lapIndicator.png";
  this->forceCamera = 0;
  this->lastSelected = 0;
  this->cm = 0;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v232[24], LODWORD(top));
  v9 = this->gui;
  LOBYTE(v242) = 7;
  v10 = ResourceStore::getTexture(v9->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->lapIndicatorTexture.kid = v10->kid;
  LOBYTE(v242) = 8;
  if ( &this->lapIndicatorTexture.fileName != &v10->fileName )
    std::wstring::assign(&this->lapIndicatorTexture.fileName, &v10->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v11 = (Font *)operator new(24);
  _Right._Ptr = v11;
  LOBYTE(v242) = 9;
  if ( v11 )
    Font::Font(v11, eFontProportional, 12.0, 0, 0);
  else
    v12 = 0;
  LOBYTE(v242) = 5;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v12);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v13 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v13->_Destroy(v13);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v13->_Weaks) )
        v13->_Delete_this(v13);
    }
    v6 = &this->viewFinder;
  }
  v14 = this->gui;
  v15 = (float)v14->graphics->videoSettings.height;
  this->stayUpCounter = 3.0;
  v16 = v15 - 105.0;
  this->targetY = v16;
  v17 = v14->graphics;
  top = v16;
  left = (float)((float)v17->videoSettings.width * 0.0099999998) * 13.5;
  ksgui::Form::setPosition((ksgui::Form *)this, left, v16);
  v18 = this->gui->graphics;
  left = left * 2.0;
  ksgui::Control::setSize(this, (float)v18->videoSettings.width - left, 105.0);
  v19 = this->gui;
  this->backColor = (vec4f)_xmm;
  LODWORD(top) = this;
  this->borderColor = (vec4f)_xmm;
  v20 = (float)v19->graphics->videoSettings.height;
  this->stayUpPhotoMode = 10.0;
  this->targetYPhoto = v20 - 210.0;
  v21 = v234;
  v22 = (float)v19->graphics->videoSettings.width - left;
  this->replayHeight = v22;
  this->photoHeight = v22 * 2.0;
  this->gs = *(ksgui::GameScreen **)(LODWORD(v21) + 144);
  this->repMng = aReplayManager;
  *(_DWORD *)&v232[4] = &std::_Func_impl<std::_Callable_obj<_lambda_fc5392bda296b6208225c89f1bb76f2d_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v232[8] = this;
  *(_DWORD *)&v232[20] = &v232[4];
  v23 = &this->repMng->evDidFinishedSavingReplay;
  LOBYTE(v242) = 5;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v23,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  v24 = (Font *)operator new(344);
  _Right._Ptr = v24;
  v25 = 0;
  LOBYTE(v242) = 11;
  if ( v24 )
  {
    top = *(float *)&this->gui;
    *(_DWORD *)&v232[24] = 7;
    *(_DWORD *)&v232[20] = 0;
    *(_WORD *)&v232[4] = 0;
    std::wstring::assign((std::wstring *)&v232[4], L"REPLAY_SAVE_NAME_TEXT_INPUT", 0x1Bu);
    ksgui::TextInput::TextInput((ksgui::TextInput *)v24, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  top = 0.0;
  LOBYTE(v242) = 5;
  this->textInput = v25;
  ksgui::Control::setVisible(v25, SLODWORD(top));
  this->textInput->backColor = (vec4f)_xmm;
  this->textInput->borderColor = (vec4f)_xmm;
  this->textInput->backColorUnfocus = (vec4f)_xmm;
  this->textInput->backColorFocus = (vec4f)_xmm;
  ksgui::Control::addControl(this, this->textInput);
  v26 = (Font *)operator new(280);
  _Right._Ptr = v26;
  v27 = 0;
  LOBYTE(v242) = 12;
  if ( v26 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Confirm Save", 0xCu);
    top = *(float *)&this->gui;
    LOBYTE(v242) = 13;
    v4 = 1;
    LODWORD(left) = 1;
    ksgui::Control::Control((ksgui::Control *)v26, &iname, (ksgui::GUI *)LODWORD(top));
  }
  this->butConfirmSave = v27;
  v242 = 5;
  if ( (v4 & 1) != 0 )
  {
    v4 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  ((void (*)(ksgui::Control *, int, int))this->butConfirmSave->setSize)(
    this->butConfirmSave,
    1112014848,
    1103626240);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Ok", 2u);
  v28 = this->butConfirmSave;
  LOBYTE(v242) = 15;
  v28->setText(v28, &iname);
  LOBYTE(v242) = 5;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->textInput->addControl(this->textInput, this->butConfirmSave);
  LODWORD(top) = this;
  *(_DWORD *)&v232[4] = &std::_Func_impl<std::_Callable_obj<_lambda_4f4aa9af08cede00e65e0651e2fa733d_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v232[8] = this;
  *(_DWORD *)&v232[20] = &v232[4];
  v29 = (Event<OnMouseWheelMovedEvent> *)&this->butConfirmSave->evClicked;
  LOBYTE(v242) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    v29,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    this);
  v30 = (Font *)operator new(320);
  _Right._Ptr = v30;
  v31 = 0;
  LOBYTE(v242) = 17;
  if ( v30 )
  {
    LODWORD(top) = 1;
    *(_DWORD *)&v232[24] = this->gui;
    *(_DWORD *)&v232[20] = 7;
    *(_DWORD *)&v232[16] = 0;
    *(_WORD *)v232 = 0;
    std::wstring::assign((std::wstring *)v232, L"POSITION_SLIDER", 0xFu);
    ksgui::Slider::Slider((ksgui::Slider *)v30, *(std::wstring *)v232, *(ksgui::GUI **)&v232[24], SLOBYTE(top));
  }
  LODWORD(top) = v31;
  LOBYTE(v242) = 5;
  this->posSlider = v31;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(top));
  LODWORD(top) = this;
  *(_DWORD *)&v232[4] = &std::_Func_impl<std::_Callable_obj<_lambda_553279367ad7b1ec0113a9a6af66da2b_,0>,std::allocator<std::_Func_class<void,ksgui::OnSliderInteraction const &>>,void,ksgui::OnSliderInteraction const &>::`vftable';
  *(_DWORD *)&v232[8] = this;
  *(_DWORD *)&v232[20] = &v232[4];
  v32 = (Event<ksgui::OnListBoxItemClickedEvent> *)&this->posSlider->evOnSliderInteraction;
  LOBYTE(v242) = 5;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    v32,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v232[4],
    this);
  LODWORD(top) = this;
  *(_DWORD *)&v232[4] = &std::_Func_impl<std::_Callable_obj<_lambda_51c5d3b44fb8385ab20fdf91837a9892_,0>,std::allocator<std::_Func_class<void,ksgui::OnCutExtremesChanged const &>>,void,ksgui::OnCutExtremesChanged const &>::`vftable';
  *(_DWORD *)&v232[8] = this;
  *(_DWORD *)&v232[20] = &v232[4];
  v33 = (Event<ksgui::OnListBoxItemClickedEvent> *)&this->posSlider->evOnCutExtremesChanged;
  LOBYTE(v242) = 5;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    v33,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v232[4],
    this);
  v34 = (Font *)operator new(448);
  _Right._Ptr = v34;
  v35 = 0;
  LOBYTE(v242) = 20;
  if ( v34 )
  {
    top = *(float *)&this->gui;
    *(_DWORD *)&v232[24] = 7;
    *(_DWORD *)&v232[20] = 0;
    *(_WORD *)&v232[4] = 0;
    std::wstring::assign((std::wstring *)&v232[4], L"BUT_SAVE_EDIT", 0xDu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v34, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  LODWORD(top) = L"SAVE REPLAY";
  LOBYTE(v242) = 5;
  this->butSaveEdit = v35;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 21;
  LODWORD(top) = acTranslate(&iname, &text);
  v36 = this->butSaveEdit;
  LOBYTE(v242) = 22;
  v36->setText(v36, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v37 = this->butSaveEdit;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v37->textCoord.x = 0.0;
  LODWORD(v37->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butSaveEdit->setSize)(
    this->butSaveEdit,
    1115684864,
    1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/save.png");
  v38 = this->gui;
  LOBYTE(v242) = 23;
  v39 = ResourceStore::getTexture(v38->graphics->resourceStore._Myptr, &result, &text, 0);
  v40 = this->butSaveEdit;
  v41 = v39->kid;
  v42 = &v39->fileName;
  LOBYTE(v242) = 24;
  v40->backTexture.kid = v41;
  v43 = &v40->backTexture.fileName;
  if ( v43 != v42 )
    std::wstring::assign(v43, v42, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 23;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butSaveEdit);
  v44 = (Font *)operator new(448);
  _Right._Ptr = v44;
  LOBYTE(v242) = 25;
  if ( v44 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_REWIND");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v44, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v45 = 0;
  }
  LODWORD(top) = L"REWIND";
  LOBYTE(v242) = 5;
  this->butRewind = v45;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 26;
  LODWORD(top) = acTranslate(&iname, &text);
  v46 = this->butRewind;
  LOBYTE(v242) = 27;
  v46->setText(v46, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v47 = this->butRewind;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v47->textCoord.x = 0.0;
  LODWORD(v47->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butRewind->setSize)(
    this->butRewind,
    1115684864,
    1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/rew.png");
  v48 = this->gui;
  LOBYTE(v242) = 28;
  v49 = ResourceStore::getTexture(v48->graphics->resourceStore._Myptr, &result, &text, 0);
  v50 = this->butRewind;
  v51 = v49->kid;
  v52 = &v49->fileName;
  LOBYTE(v242) = 29;
  v50->backTexture.kid = v51;
  v53 = &v50->backTexture.fileName;
  if ( v53 != v52 )
    std::wstring::assign(v53, v52, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 28;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butRewind);
  v54 = (Font *)operator new(448);
  _Right._Ptr = v54;
  LOBYTE(v242) = 30;
  if ( v54 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_STOP");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v54, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v55 = 0;
  }
  LODWORD(top) = L"STOP";
  LOBYTE(v242) = 5;
  this->butStop = v55;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 31;
  LODWORD(top) = acTranslate(&iname, &text);
  v56 = this->butStop;
  LOBYTE(v242) = 32;
  v56->setText(v56, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v57 = this->butStop;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v57->textCoord.x = 0.0;
  LODWORD(v57->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butStop->setSize)(this->butStop, 1115684864, 1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/stop.png");
  v58 = this->gui;
  LOBYTE(v242) = 33;
  v59 = ResourceStore::getTexture(v58->graphics->resourceStore._Myptr, &result, &text, 0);
  v60 = this->butStop;
  v61 = v59->kid;
  v62 = &v59->fileName;
  LOBYTE(v242) = 34;
  v60->backTexture.kid = v61;
  v63 = &v60->backTexture.fileName;
  if ( v63 != v62 )
    std::wstring::assign(v63, v62, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 33;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butStop);
  v64 = (Font *)operator new(448);
  _Right._Ptr = v64;
  LOBYTE(v242) = 35;
  if ( v64 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_PLAY");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v64, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v65 = 0;
  }
  LODWORD(top) = L"PLAY";
  LOBYTE(v242) = 5;
  this->butPlay = v65;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 36;
  LODWORD(top) = acTranslate(&iname, &text);
  v66 = this->butPlay;
  LOBYTE(v242) = 37;
  v66->setText(v66, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v67 = this->butPlay;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v67->textCoord.x = 0.0;
  LODWORD(v67->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butPlay->setSize)(this->butPlay, 1115684864, 1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/playPause.png");
  v68 = this->gui;
  LOBYTE(v242) = 38;
  v69 = ResourceStore::getTexture(v68->graphics->resourceStore._Myptr, &result, &text, 0);
  v70 = this->butPlay;
  v71 = v69->kid;
  v72 = &v69->fileName;
  LOBYTE(v242) = 39;
  v70->backTexture.kid = v71;
  v73 = &v70->backTexture.fileName;
  if ( v73 != v72 )
    std::wstring::assign(v73, v72, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 38;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butPlay);
  v74 = (Font *)operator new(448);
  _Right._Ptr = v74;
  LOBYTE(v242) = 40;
  if ( v74 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_SLOW");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v74, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v75 = 0;
  }
  LODWORD(top) = L"SLOW";
  LOBYTE(v242) = 5;
  this->butSlowMotion = v75;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 41;
  LODWORD(top) = acTranslate(&iname, &text);
  v76 = this->butSlowMotion;
  LOBYTE(v242) = 42;
  v76->setText(v76, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v77 = this->butSlowMotion;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v77->textCoord.x = 0.0;
  LODWORD(v77->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butSlowMotion->setSize)(
    this->butSlowMotion,
    1104674816,
    1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/slomo.png");
  v78 = this->gui;
  LOBYTE(v242) = 43;
  v79 = ResourceStore::getTexture(v78->graphics->resourceStore._Myptr, &result, &text, 0);
  v80 = this->butSlowMotion;
  v81 = v79->kid;
  v82 = &v79->fileName;
  LOBYTE(v242) = 44;
  v80->backTexture.kid = v81;
  v83 = &v80->backTexture.fileName;
  if ( v83 != v82 )
    std::wstring::assign(v83, v82, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 43;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butSlowMotion);
  v84 = (Font *)operator new(448);
  _Right._Ptr = v84;
  LOBYTE(v242) = 45;
  if ( v84 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_FAST_FORWARD");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v84, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v85 = 0;
  }
  LODWORD(top) = L"FAST FORWARD";
  LOBYTE(v242) = 5;
  this->butFastForward = v85;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 46;
  LODWORD(top) = acTranslate(&iname, &text);
  v86 = this->butFastForward;
  LOBYTE(v242) = 47;
  v86->setText(v86, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v87 = this->butFastForward;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v87->textCoord.x = 0.0;
  LODWORD(v87->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butFastForward->setSize)(
    this->butFastForward,
    1115684864,
    1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/ffd.png");
  v88 = this->gui;
  LOBYTE(v242) = 48;
  v89 = ResourceStore::getTexture(v88->graphics->resourceStore._Myptr, &result, &text, 0);
  v90 = this->butFastForward;
  v91 = v89->kid;
  v92 = &v89->fileName;
  LOBYTE(v242) = 49;
  v90->backTexture.kid = v91;
  v93 = &v90->backTexture.fileName;
  if ( v93 != v92 )
    std::wstring::assign(v93, v92, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 48;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butFastForward);
  v94 = (Font *)operator new(448);
  _Right._Ptr = v94;
  LOBYTE(v242) = 50;
  if ( v94 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"BUT_EXIT");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v94, *(std::wstring *)&v232[4], (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v95 = 0;
  }
  LODWORD(top) = L"EXIT";
  LOBYTE(v242) = 5;
  this->butExit = v95;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 51;
  LODWORD(top) = acTranslate(&iname, &text);
  v96 = this->butExit;
  LOBYTE(v242) = 52;
  v96->setText(v96, (const std::wstring *)LODWORD(top));
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v97 = this->butExit;
  _Right._Ptr = 0;
  _Right._Rep = (std::_Ref_count_base *)1111490560;
  v97->textCoord.x = 0.0;
  LODWORD(v97->textCoord.y) = _Right._Rep;
  ((void (*)(ksgui::ActiveButton *, int, int))this->butExit->setSize)(this->butExit, 1115684864, 1111490560);
  std::wstring::wstring(&text, L"content/gui/replay/exit.png");
  v98 = this->gui;
  LOBYTE(v242) = 53;
  v99 = ResourceStore::getTexture(v98->graphics->resourceStore._Myptr, &result, &text, 0);
  v100 = this->butExit;
  v101 = v99->kid;
  v102 = &v99->fileName;
  LOBYTE(v242) = 54;
  v100->backTexture.kid = v101;
  v103 = &v100->backTexture.fileName;
  if ( v103 != v102 )
    std::wstring::assign(v103, v102, 0, 0xFFFFFFFF);
  LOBYTE(v242) = 53;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Control::addControl(this, this->butExit);
  v104 = (Font *)operator new(444);
  _Right._Ptr = v104;
  LOBYTE(v242) = 55;
  if ( v104 )
  {
    std::wstring::wstring(&text, L"SlowMotion Level");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 56;
    v4 |= 2u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v104, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v105 = 0;
  }
  this->slowMoSpinner = v105;
  v242 = 5;
  if ( (v4 & 2) != 0 )
  {
    v4 &= 0xFFFFFFFD;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->slowMoSpinner->setSize)(
    this->slowMoSpinner,
    1117782016,
    1102577664);
  this->slowMoSpinner->minValue = 2;
  this->slowMoSpinner->maxValue = 12;
  ksgui::Spinner::setValue(this->slowMoSpinner, (int)this->repMng->slowMoLevel);
  this->slowMoSpinner->displayCentralValue = 0;
  this->slowMoSpinner->drawUnderline = 0;
  this->slowMoSpinner->displayLabel = 0;
  ksgui::Control::addControl(this, this->slowMoSpinner);
  v106 = (Font *)operator new(444);
  _Right._Ptr = v106;
  LOBYTE(v242) = 58;
  if ( v106 )
  {
    std::wstring::wstring(&text, L"Camera");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 59;
    v4 |= 4u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v106, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v107 = 0;
  }
  this->cameraSpinner = v107;
  v242 = 5;
  if ( (v4 & 4) != 0 )
  {
    v4 &= 0xFFFFFFFB;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->cameraSpinner->setSize)(
    this->cameraSpinner,
    1117782016,
    1102577664);
  v108 = this->cameraSpinner;
  LODWORD(top) = 1;
  v108->minValue = 1;
  this->cameraSpinner->maxValue = 4;
  ksgui::Spinner::setValue(this->cameraSpinner, SLODWORD(top));
  v109 = this->cameraSpinner;
  LODWORD(top) = 1;
  v109->drawUnderline = 0;
  this->cameraSpinner->displayLabel = 0;
  ksgui::Spinner::setDrawArrows(this->cameraSpinner, SLOBYTE(top));
  ksgui::Control::addControl(this, this->cameraSpinner);
  v110 = (Font *)operator new(444);
  _Right._Ptr = v110;
  LOBYTE(v242) = 61;
  if ( v110 )
  {
    std::wstring::wstring(&text, L"Car");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 62;
    v4 |= 8u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v110, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v111 = 0;
  }
  this->carSpinner = v111;
  v242 = 5;
  if ( (v4 & 8) != 0 )
  {
    v4 &= 0xFFFFFFF7;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  }
  ((void (*)(ksgui::Spinner *, int, int))this->carSpinner->setSize)(this->carSpinner, 1117782016, 1102577664);
  this->carSpinner->minValue = 1;
  v112 = Sim::getCarsCount(this->sim);
  v113 = this->carSpinner;
  LODWORD(top) = 1;
  v113->maxValue = v112;
  ksgui::Spinner::setValue(this->carSpinner, SLODWORD(top));
  this->carSpinner->drawUnderline = 0;
  this->carSpinner->displayLabel = 0;
  ksgui::Control::addControl(this, this->carSpinner);
  v114 = (Font *)operator new(448);
  _Right._Ptr = v114;
  LOBYTE(v242) = 64;
  if ( v114 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"PhotoMode");
    ksgui::ActiveButton::ActiveButton(
      (ksgui::ActiveButton *)v114,
      *(std::wstring *)&v232[4],
      (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v115 = 0;
  }
  LODWORD(top) = L"PHOTO MODE";
  LOBYTE(v242) = 5;
  this->butPhotoMode = v115;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 65;
  LODWORD(top) = acTranslate(&v241.name, &text);
  v116 = this->butPhotoMode;
  LOBYTE(v242) = 66;
  v116->setText(v116, (const std::wstring *)LODWORD(top));
  std::wstring::~wstring(&v241);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  vec2f::vec2f((vec2f *)&_Right, 0.0, 48.0);
  v117 = this->butPhotoMode;
  v117->textCoord.x = *v118;
  v117->textCoord.y = v118[1];
  ((void (*)(ksgui::ActiveButton *, int, int))this->butPhotoMode->setSize)(
    this->butPhotoMode,
    1115684864,
    1111490560);
  std::wstring::wstring(&iname, L"content/gui/photoMode/icn_photomode.png");
  top = 0.0;
  LOBYTE(v242) = 67;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v119 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v120 = ResourceStore::getTexture(v119, *(Texture **)&v232[20], *(const std::wstring **)&v232[24], SLOBYTE(top));
  v121 = this->butPhotoMode;
  LOBYTE(v242) = 68;
  Texture::operator=(&v121->backTexture, v120);
  LOBYTE(v242) = 67;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ksgui::Control::addControl(this, this->butPhotoMode);
  v122 = (Font *)operator new(448);
  _Right._Ptr = v122;
  LOBYTE(v242) = 69;
  if ( v122 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"NextFrame");
    ksgui::ActiveButton::ActiveButton(
      (ksgui::ActiveButton *)v122,
      *(std::wstring *)&v232[4],
      (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v123 = 0;
  }
  LODWORD(top) = L"content/gui/replay/1_ffd.png";
  LOBYTE(v242) = 5;
  this->butNextFrame = v123;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  top = 0.0;
  LOBYTE(v242) = 70;
  *(_DWORD *)&v232[24] = &text;
  *(_DWORD *)&v232[20] = &result;
  v124 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v125 = ResourceStore::getTexture(v124, *(Texture **)&v232[20], *(const std::wstring **)&v232[24], SLOBYTE(top));
  v126 = this->butNextFrame;
  LOBYTE(v242) = 71;
  Texture::operator=(&v126->backTexture, v125);
  LOBYTE(v242) = 70;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  vec2f::vec2f((vec2f *)&_Right, 0.0, 48.0);
  v127 = this->butNextFrame;
  v127->textCoord.x = *v128;
  v127->textCoord.y = v128[1];
  ((void (*)(ksgui::ActiveButton *, int, int))this->butNextFrame->setSize)(
    this->butNextFrame,
    1115684864,
    1111490560);
  ksgui::Control::addControl(this, this->butNextFrame);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v129);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->cameraSpinner->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v130);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->carSpinner->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v131);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->slowMoSpinner->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (std::wstring const &)>::function<void __cdecl (std::wstring const &)>(
    (std::function<void __cdecl(std::wstring const &)> *)&v232[4],
    v132);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->textInput->evValidate,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v133);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSaveEdit->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v134);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butSlowMotion->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v135);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butRewind->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v136);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butFastForward->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v137);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butPlay->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v138);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butExit->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v139);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butStop->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v140);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butNextFrame->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v141);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butPhotoMode->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  v142 = ksgui::ksRect::getWidth(&this->butNextFrame->rect);
  v143 = this->butExit;
  v234 = v142;
  v144 = ksgui::ksRect::getWidth(&v143->rect);
  v145 = this->butSaveEdit;
  left = v144;
  left = v234 + left;
  v146 = ksgui::ksRect::getWidth(&v145->rect);
  v147 = this->butRewind;
  v234 = v146;
  left = left + v234;
  v148 = ksgui::ksRect::getWidth(&v147->rect);
  v149 = this->butStop;
  v234 = v148;
  left = left + v234;
  v150 = ksgui::ksRect::getWidth(&v149->rect);
  v151 = this->butPlay;
  v234 = v150;
  left = left + v234;
  v152 = ksgui::ksRect::getWidth(&v151->rect);
  v153 = this->butFastForward;
  v234 = v152;
  left = left + v234;
  v154 = ksgui::ksRect::getWidth(&v153->rect);
  v155 = this->butPhotoMode;
  v234 = v154;
  left = left + v234;
  v156 = ksgui::ksRect::getWidth(&v155->rect);
  v157 = &this->slowMoSpinner->rect;
  v234 = v156 + left + 40.0;
  this->totalWidth = v234;
  v158 = ksgui::ksRect::getWidth(v157);
  v159 = this->cameraSpinner;
  left = v158;
  left = left + v234;
  v160 = ksgui::ksRect::getWidth(&v159->rect);
  v161 = this->carSpinner;
  v234 = v160;
  left = left + v234;
  v162 = ksgui::ksRect::getWidth(&v161->rect);
  v163 = this->sim;
  v234 = left;
  this->totalWidth = v162 + left + 60.0;
  v164 = Sim::getSceneCamera(v163);
  LODWORD(top) = L"content//gui//photoMode//viewFinder.png";
  this->camera = v164;
  this->photoModeActive = 0;
  std::wstring::wstring(&iname, (const wchar_t *)LODWORD(top));
  top = 0.0;
  LOBYTE(v242) = 72;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v165 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v166 = ResourceStore::getTexture(v165, *(Texture **)&v232[20], *(const std::wstring **)&v232[24], SLOBYTE(top));
  LOBYTE(v242) = 73;
  Texture::operator=(v6, v166);
  LOBYTE(v242) = 72;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  v167 = (Font *)operator new(444);
  _Right._Ptr = v167;
  LOBYTE(v242) = 74;
  if ( v167 )
  {
    std::wstring::wstring(&text, L"EXPO");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 75;
    v4 |= 0x10u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v167, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v168 = 0;
  }
  this->spiExpo = v168;
  v242 = 5;
  if ( (v4 & 0x10) != 0 )
  {
    v4 &= 0xFFFFFFEF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  }
  this->spiExpo->minValue = 5;
  v169 = this->spiExpo;
  top = 23.0;
  *(_DWORD *)&v232[24] = 1120403456;
  v169->maxValue = 1500;
  this->spiExpo->step = 5;
  this->spiExpo->displayLabel = 0;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spiExpo->setSize)(
    this->spiExpo,
    *(_DWORD *)&v232[24],
    LODWORD(top));
  ksgui::Control::addControl(this, this->spiExpo);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v170);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spiExpo->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  v171 = (Font *)operator new(444);
  _Right._Ptr = v171;
  LOBYTE(v242) = 77;
  if ( v171 )
  {
    std::wstring::wstring(&text, L"FOV");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 78;
    v4 |= 0x20u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v171, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v172 = 0;
  }
  this->spiFov = v172;
  v242 = 5;
  if ( (v4 & 0x20) != 0 )
  {
    v4 &= 0xFFFFFFDF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  }
  this->spiFov->minValue = 1;
  v173 = this->spiFov;
  top = 23.0;
  *(_DWORD *)&v232[24] = 1117782016;
  v173->maxValue = 180;
  this->spiFov->step = 1;
  this->spiFov->displayLabel = 0;
  this->spiFov->drawUnderline = 0;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spiFov->setSize)(
    this->spiFov,
    *(_DWORD *)&v232[24],
    LODWORD(top));
  ksgui::Control::addControl(this, this->spiFov);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v174);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spiFov->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  v175 = (Font *)operator new(444);
  _Right._Ptr = v175;
  LOBYTE(v242) = 80;
  if ( v175 )
  {
    std::wstring::wstring(&text, L"DOFFACTOR");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 81;
    v4 |= 0x40u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v175, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v176 = 0;
  }
  this->spiDofFactor = v176;
  v242 = 5;
  if ( (v4 & 0x40) != 0 )
  {
    v4 &= 0xFFFFFFBF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  }
  this->spiDofFactor->minValue = 5;
  v177 = this->spiDofFactor;
  top = 23.0;
  *(_DWORD *)&v232[24] = 1120403456;
  v177->maxValue = 1000;
  this->spiDofFactor->step = 5;
  this->spiDofFactor->displayLabel = 0;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spiDofFactor->setSize)(
    this->spiDofFactor,
    *(_DWORD *)&v232[24],
    LODWORD(top));
  ksgui::Control::addControl(this, this->spiDofFactor);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v178);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spiDofFactor->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  v179 = (Font *)operator new(444);
  _Right._Ptr = v179;
  LOBYTE(v242) = 83;
  if ( v179 )
  {
    std::wstring::wstring(&text, L"DOFFOCUS");
    top = 0.0;
    *(_DWORD *)&v232[24] = 1;
    *(_DWORD *)&v232[20] = this->gui;
    LOBYTE(v242) = 84;
    v4 |= 0x80u;
    left = *(float *)&v4;
    ksgui::Spinner::Spinner((ksgui::Spinner *)v179, &text, *(ksgui::GUI **)&v232[20], 1, 0);
  }
  else
  {
    v180 = 0;
  }
  this->spiDofFocus = v180;
  v242 = 5;
  if ( (v4 & 0x80u) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  this->spiDofFocus->minValue = 1;
  v181 = this->spiDofFocus;
  top = 23.0;
  *(_DWORD *)&v232[24] = 1120403456;
  v181->maxValue = 10000;
  this->spiDofFocus->step = 1;
  this->spiDofFocus->displayLabel = 0;
  ((void (*)(ksgui::Spinner *, _DWORD, _DWORD))this->spiDofFocus->setSize)(
    this->spiDofFocus,
    *(_DWORD *)&v232[24],
    LODWORD(top));
  ksgui::Control::addControl(this, this->spiDofFocus);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>::function<void __cdecl (ksgui::OnSpinnerValueChanged const &)>(
    (std::function<void __cdecl(ksgui::OnSpinnerValueChanged const &)> *)&v232[4],
    v182);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->spiDofFocus->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v232[4],
    (void *)LODWORD(top));
  v183 = (Font *)operator new(340);
  _Right._Ptr = v183;
  LOBYTE(v242) = 86;
  if ( v183 )
  {
    top = 0.0;
    *(_DWORD *)&v232[24] = this->gui;
    std::wstring::wstring((std::wstring *)v232, L"ROLL");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v183,
      *(std::wstring *)v232,
      *(ksgui::GUI **)&v232[24],
      SLODWORD(top));
  }
  else
  {
    v184 = 0;
  }
  LODWORD(top) = L"content/gui/controls/spinner/leftContainerArrow.png";
  LOBYTE(v242) = 5;
  this->spiCameraRoll = v184;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  top = 0.0;
  LOBYTE(v242) = 87;
  *(_DWORD *)&v232[24] = &text;
  *(_DWORD *)&v232[20] = &result;
  v185 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v185,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v186 = this->spiCameraRoll;
  LOBYTE(v242) = 88;
  Texture::operator=(&v186->leftButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 87;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  std::wstring::wstring(&iname, L"content/gui/controls/spinner/rightContainerArrow.png");
  top = 0.0;
  LOBYTE(v242) = 89;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v187 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v187,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v188 = this->spiCameraRoll;
  LOBYTE(v242) = 90;
  Texture::operator=(&v188->rightButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 89;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiCameraRoll->setSize)(
    this->spiCameraRoll,
    1114636288,
    1102577664);
  ksgui::Control::addControl(this, this->spiCameraRoll);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v189);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiCameraRoll->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v190);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiCameraRoll->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  v191 = (Font *)operator new(340);
  _Right._Ptr = v191;
  LOBYTE(v242) = 91;
  if ( v191 )
  {
    top = 0.0;
    *(_DWORD *)&v232[24] = this->gui;
    std::wstring::wstring((std::wstring *)v232, L"AZIMUTH");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v191,
      *(std::wstring *)v232,
      *(ksgui::GUI **)&v232[24],
      SLODWORD(top));
  }
  else
  {
    v192 = 0;
  }
  LODWORD(top) = L"content/gui/controls/spinner/leftContainerArrow.png";
  LOBYTE(v242) = 5;
  this->spiSunAzimuth = v192;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  top = 0.0;
  LOBYTE(v242) = 92;
  *(_DWORD *)&v232[24] = &text;
  *(_DWORD *)&v232[20] = &result;
  v193 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v193,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v194 = this->spiSunAzimuth;
  LOBYTE(v242) = 93;
  Texture::operator=(&v194->leftButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 92;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  std::wstring::wstring(&iname, L"content/gui/controls/spinner/rightContainerArrow.png");
  top = 0.0;
  LOBYTE(v242) = 94;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v195 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v195,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v196 = this->spiSunAzimuth;
  LOBYTE(v242) = 95;
  Texture::operator=(&v196->rightButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 94;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiSunAzimuth->setSize)(
    this->spiSunAzimuth,
    1114636288,
    1102577664);
  ksgui::Control::addControl(this, this->spiSunAzimuth);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v197);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunAzimuth->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v198);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunAzimuth->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  v199 = (Font *)operator new(340);
  _Right._Ptr = v199;
  LOBYTE(v242) = 96;
  if ( v199 )
  {
    top = 0.0;
    *(_DWORD *)&v232[24] = this->gui;
    std::wstring::wstring((std::wstring *)v232, L"ZENITH");
    ksgui::CustomSpinner::CustomSpinner(
      (ksgui::CustomSpinner *)v199,
      *(std::wstring *)v232,
      *(ksgui::GUI **)&v232[24],
      SLODWORD(top));
  }
  else
  {
    v200 = 0;
  }
  LODWORD(top) = L"content/gui/controls/spinner/leftMinus.png";
  LOBYTE(v242) = 5;
  this->spiSunZenith = v200;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  top = 0.0;
  LOBYTE(v242) = 97;
  *(_DWORD *)&v232[24] = &text;
  *(_DWORD *)&v232[20] = &result;
  v201 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v201,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v202 = this->spiSunZenith;
  LOBYTE(v242) = 98;
  Texture::operator=(&v202->leftButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 97;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  std::wstring::wstring(&iname, L"content/gui/controls/spinner/rightPlus.png");
  top = 0.0;
  LOBYTE(v242) = 99;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v203 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  LODWORD(top) = ResourceStore::getTexture(
                   v203,
                   *(Texture **)&v232[20],
                   *(const std::wstring **)&v232[24],
                   SLOBYTE(top));
  v204 = this->spiSunZenith;
  LOBYTE(v242) = 100;
  Texture::operator=(&v204->rightButton->backTexture, (const Texture *)LODWORD(top));
  LOBYTE(v242) = 99;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ((void (*)(ksgui::CustomSpinner *, int, int))this->spiSunZenith->setSize)(
    this->spiSunZenith,
    1114636288,
    1102577664);
  ksgui::Control::addControl(this, this->spiSunZenith);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v205);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunZenith->rightButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v206);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->spiSunZenith->leftButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  v207 = (Font *)operator new(448);
  _Right._Ptr = v207;
  LOBYTE(v242) = 101;
  if ( v207 )
  {
    top = *(float *)&this->gui;
    std::wstring::wstring((std::wstring *)&v232[4], L"TakePic");
    ksgui::ActiveButton::ActiveButton(
      (ksgui::ActiveButton *)v207,
      *(std::wstring *)&v232[4],
      (ksgui::GUI *)LODWORD(top));
  }
  else
  {
    v208 = 0;
  }
  LODWORD(top) = L"TAKE PICTURE ";
  LOBYTE(v242) = 5;
  this->butTakePic = v208;
  std::wstring::wstring(&text, (const wchar_t *)LODWORD(top));
  LOBYTE(v242) = 102;
  v209 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v242) = 103;
  LODWORD(top) = std::operator+<wchar_t>(&v241.name, v209, L"(F8)");
  v210 = this->butTakePic;
  LOBYTE(v242) = 104;
  v210->setText(v210, (const std::wstring *)LODWORD(top));
  std::wstring::~wstring(&v241);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  vec2f::vec2f((vec2f *)&_Right, 0.0, 48.0);
  v211 = this->butTakePic;
  v211->textCoord.x = *v212;
  v211->textCoord.y = v212[1];
  ((void (*)(ksgui::ActiveButton *, int, int))this->butTakePic->setSize)(
    this->butTakePic,
    1115684864,
    1111490560);
  std::wstring::wstring(&iname, L"content/gui/photoMode/icn_screenshot.png");
  top = 0.0;
  LOBYTE(v242) = 105;
  *(_DWORD *)&v232[24] = &iname;
  *(_DWORD *)&v232[20] = &result;
  v213 = (ResourceStore *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->gui->graphics->resourceStore);
  v214 = ResourceStore::getTexture(v213, *(Texture **)&v232[20], *(const std::wstring **)&v232[24], SLOBYTE(top));
  v215 = this->butTakePic;
  LOBYTE(v242) = 106;
  Texture::operator=(&v215->backTexture, v214);
  LOBYTE(v242) = 105;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v242) = 5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  ksgui::Control::addControl(this, this->butTakePic);
  LODWORD(top) = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&_Right,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v232[4],
    v216);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butTakePic->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v232[4],
    (void *)LODWORD(top));
  v217 = ksgui::ksRect::getWidth(&this->spiFov->rect);
  v218 = this->spiExpo;
  v234 = v217;
  v219 = ksgui::ksRect::getWidth(&v218->rect);
  v220 = this->spiDofFactor;
  left = v219;
  left = v234 + left;
  v221 = ksgui::ksRect::getWidth(&v220->rect);
  v222 = this->spiDofFocus;
  v234 = v221;
  left = left + v234;
  v223 = ksgui::ksRect::getWidth(&v222->rect);
  v224 = this->spiSunAzimuth;
  v234 = v223;
  left = left + v234;
  v225 = ksgui::ksRect::getWidth(&v224->rect);
  v226 = this->spiSunZenith;
  v234 = v225;
  left = left + v234;
  v227 = ksgui::ksRect::getWidth(&v226->rect);
  v228 = this->spiCameraRoll;
  v234 = v227;
  left = left + v234;
  v229 = ksgui::ksRect::getWidth(&v228->rect);
  v230 = &this->butTakePic->rect;
  left = v229 + left + 160.0;
  v234 = left;
  this->totalWidthPhoto = left;
  v231 = ksgui::ksRect::getWidth(v230);
  this->totalWidthPhoto = v231 + left;
}
void ReplayInterface::~ReplayInterface(ReplayInterface *this)
{
  std::vector<std::wstring> *v2; // edi

  this->__vftable = (ReplayInterface_vtbl *)&ReplayInterface::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->viewFinder);
  v2 = &this->cameraNames;
  if ( this->cameraNames._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cameraNames);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v2->_Myfirst, this->cameraNames._Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->cameraNames._Mylast = 0;
    this->cameraNames._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->lapIndicatorTexture);
  ksgui::Control::~Control(this);
}
ReplayInterface *ReplayInterface::`vector deleting destructor'(ReplayInterface *this, unsigned int a2)
{
  ReplayInterface::~ReplayInterface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ReplayInterface::didFinishedSavingReplay(ReplayInterface *this, bool response)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Sim *v5; // ecx
  const std::wstring *v6; // esi
  const std::wstring *v7; // eax
  SystemMessage *v8; // ecx
  std::wstring v9; // [esp+Ch] [ebp-B8h] BYREF
  std::wstring text; // [esp+24h] [ebp-A0h] BYREF
  std::wstring v11; // [esp+3Ch] [ebp-88h] BYREF
  std::wstring v12; // [esp+54h] [ebp-70h] BYREF
  std::wstring v13; // [esp+6Ch] [ebp-58h] BYREF
  std::wstring result; // [esp+84h] [ebp-40h] BYREF
  std::wstring v15; // [esp+9Ch] [ebp-28h] BYREF
  int v16; // [esp+C0h] [ebp-4h]

  this->butSaveEdit->drawBackground = 0;
  if ( response )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Replay saved", 0xCu);
    v16 = 0;
    v3 = acTranslate(&result, &text);
    LOBYTE(v16) = 1;
    v4 = std::operator+<wchar_t>(&v12, v3, L" : ");
    v5 = this->sim;
    LOBYTE(v16) = 2;
    SystemMessage::addMessage(v5->systemMessage, v4, &v5->replayManager->lastFilename, eDefault);
    if ( v12._Myres >= 8 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  else
  {
    v11._Myres = 7;
    v11._Mysize = 0;
    v11._Bx._Buf[0] = 0;
    std::wstring::assign(&v11, L"Replay not saved", 0x10u);
    v16 = 3;
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"ERROR", 5u);
    LOBYTE(v16) = 4;
    v6 = acTranslate(&v15, &v11);
    LOBYTE(v16) = 5;
    v7 = acTranslate(&v13, &v9);
    v8 = this->sim->systemMessage;
    LOBYTE(v16) = 6;
    SystemMessage::addMessage(v8, v7, v6, eDefault);
    if ( v13._Myres >= 8 )
      operator delete(v13._Bx._Ptr);
    v13._Myres = 7;
    v13._Mysize = 0;
    v13._Bx._Buf[0] = 0;
    if ( v15._Myres >= 8 )
      operator delete(v15._Bx._Ptr);
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    if ( v9._Myres >= 8 )
      operator delete(v9._Bx._Ptr);
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    if ( v11._Myres >= 8 )
      operator delete(v11._Bx._Ptr);
  }
}
void ReplayInterface::onMouseMove(ReplayInterface *this, const OnMouseMoveEvent *message)
{
  unsigned int i; // edi
  ksgui::Control *v4; // ecx
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm2_4

  for ( i = 0; i < this->controls._Mylast - this->controls._Myfirst; ++i )
  {
    v4 = this->controls._Myfirst[i];
    v4->onMouseMove(v4, message);
  }
  if ( this->textInput->visible )
    v5 = FLOAT_155_0;
  else
    v5 = FLOAT_105_0;
  v6 = (float)this->gui->graphics->videoSettings.height;
  if ( (float)message->y <= (float)(v6 - v5) )
    v7 = v6 + 10.0;
  else
    v7 = (float)(v6 - 105.0) + 5.0;
  this->targetY = v7;
}
void ReplayInterface::onMouseWheelMovedEvent(ReplayInterface *this, const OnMouseWheelMovedEvent *message)
{
  bool v3; // zf
  float v4; // xmm0_4
  Camera *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  if ( this->visible && this->repMng->status == ePhotoMode )
  {
    v3 = GetAsyncKeyState(2) == 0;
    v4 = message->delta;
    if ( v3 )
    {
      v5 = this->camera;
      if ( v4 <= 0.0 )
      {
        if ( v5->fov < 180.0 )
        {
          v7 = ksgui::Spinner::getValue(this->spiFov);
          ksgui::Spinner::setValue(this->spiFov, (int)(float)((float)v7 + 1.0));
        }
      }
      else if ( v5->fov > 1.0 )
      {
        v6 = ksgui::Spinner::getValue(this->spiFov);
        ksgui::Spinner::setValue(this->spiFov, (int)(float)((float)v6 - 1.0));
      }
    }
    else
    {
      v8 = ksgui::Spinner::getValue(this->spiDofFocus);
      if ( v4 <= 0.0 )
        ksgui::Spinner::setValue(this->spiDofFocus, v8 - 1);
      else
        ksgui::Spinner::setValue(this->spiDofFocus, v8 + 1);
    }
  }
}
void ReplayInterface::onReplayManagerStatusChanged(ReplayInterface *this, eReplayStatus status)
{
  Sim *v3; // eax
  ACCameraManager *v4; // ecx

  if ( status == ePhotoMode )
  {
    v3 = this->sim;
    v4 = this->cm;
    this->prevCameraMode = v3->cameraManager->mode;
    ACCameraManager::setMode(v4, eFree, 1, 0);
    this->prevStatus = ePhotoMode;
  }
}
void ReplayInterface::onSliderSelection(ReplayInterface *this, const ksgui::OnSliderInteraction *message)
{
  ReplayManager *v3; // eax
  Sim *v4; // ebx
  int v5; // xmm1_4
  int v6; // xmm0_4
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > *v7; // esi
  std::_Func_base<void,OnReplayStatusChanged const &> **v8; // edi
  int v9[3]; // [esp+Ch] [ebp-Ch] BYREF

  ReplayManager::setNormalizedPosition(this->repMng, message->value);
  v3 = this->repMng;
  v4 = this->sim;
  v5 = LODWORD(v3->slowMoLevel);
  v6 = LODWORD(v3->timeMult);
  v9[0] = 10;
  v9[1] = v6;
  v9[2] = v5;
  v7 = v4->evOnReplayStatusChanged.handlers._Myfirst;
  if ( v7 != v4->evOnReplayStatusChanged.handlers._Mylast )
  {
    v8 = &v7->second._Impl;
    do
    {
      if ( !*v8 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x641E9A);
      }
      (*v8)->_Do_call(*v8, (const OnReplayStatusChanged *)v9);
      ++v7;
      v8 += 8;
    }
    while ( v7 != v4->evOnReplayStatusChanged.handlers._Mylast );
  }
}
void ReplayInterface::onVisibleChanged(ReplayInterface *this, bool newValue)
{
  ACCameraManager *v2; // eax

  v2 = this->cm;
  if ( v2 )
  {
    this->forceCamera = 1;
    ksgui::Spinner::setValue(this->cameraSpinner, v2->currentGlobalCameraIndex + 1);
  }
}
void __userpurge ReplayInterface::render(ReplayInterface *this@<ecx>, int i@<esi>, float dt)
{
  ACCameraManager *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  Event<int> *v12; // ecx
  Sim *v13; // ecx
  unsigned int v14; // eax
  float *v15; // esi
  ksgui::GUI *v16; // eax
  unsigned int v17; // ecx
  GraphicsManager *v18; // eax
  ksgui::Slider *v19; // eax
  float v20; // xmm0_4
  unsigned int v21; // xmm1_4
  unsigned int v22; // xmm0_4
  ReplayInterface_vtbl *v23; // eax
  ReplayManager *v24; // eax
  ReplayManager *v25; // eax
  float v26; // xmm0_4
  ksgui::ActiveButton *v27; // eax
  ksgui::ActiveButton *v28; // ecx
  std::wstring *v29; // eax
  ksgui::ActiveButton *v30; // ecx
  ksgui::ActiveButton *v31; // eax
  ksgui::ActiveButton *v32; // ecx
  std::wstring *v33; // esi
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  ksgui::ActiveButton *v36; // ecx
  ksgui::ActiveButton *v37; // eax
  ksgui::ActiveButton *v38; // ecx
  std::wstring *v39; // esi
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  ksgui::ActiveButton *v42; // ecx
  std::wstring *v43; // eax
  ksgui::ActiveButton *v44; // ecx
  ksgui::ActiveButton *v45; // eax
  ksgui::ActiveButton *v46; // ecx
  eReplayStatus v47; // eax
  ksgui::ActiveButton *v48; // ecx
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  ksgui::ActiveButton *v51; // ecx
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  ksgui::ActiveButton *v54; // ecx
  std::wstring *v55; // eax
  float v56; // ecx
  ReplayManager *v57; // eax
  std::wstring *v58; // esi
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  ksgui::ActiveButton *v61; // ecx
  ksgui::TextInput *v62; // ecx
  Font *v63; // ecx
  std::wstring *v64; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v65; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v66; // ecx
  Font *v67; // ecx
  ksgui::GUI *v68; // eax
  ksgui::Spinner *v69; // ecx
  std::wstring *v70; // eax
  std::wstring *v71; // esi
  ksgui::Spinner *v72; // ecx
  int v73; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v74; // ecx
  Font *v75; // ecx
  ksgui::Spinner *v76; // ecx
  std::wstring *v77; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v78; // ecx
  Font *v79; // ecx
  ksgui::Slider *v80; // ecx
  int v81; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v82; // ecx
  std::wstring *v83; // esi
  int v84; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v85; // ecx
  std::wstring *v86; // esi
  GraphicsManager *v87; // eax
  GLRenderer *v88; // esi
  Sim *v89; // ecx
  std::wstring *v90; // eax
  std::wstring *v91; // eax
  const std::wstring *v92; // eax
  std::allocator<wchar_t> *v93; // eax
  ksgui::Spinner *v94; // ecx
  std::wstring *v95; // eax
  Font *v96; // eax
  ksgui::Spinner *v97; // ecx
  std::wstring *v98; // eax
  Font *v99; // eax
  ksgui::Spinner *v100; // ecx
  std::wstring *v101; // eax
  Font *v102; // eax
  ksgui::Spinner *v103; // ecx
  std::wstring *v104; // eax
  Font *v105; // eax
  ksgui::CustomSpinner *v106; // ecx
  std::wstring *v107; // eax
  Font *v108; // eax
  ksgui::CustomSpinner *v109; // ecx
  std::wstring *v110; // eax
  Font *v111; // eax
  ksgui::CustomSpinner *v112; // ecx
  std::wstring *v113; // eax
  Font *v114; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v115; // [esp+4Ch] [ebp-2A8h] BYREF
  float a; // [esp+64h] [ebp-290h]
  __int64 v117; // [esp+68h] [ebp-28Ch]
  float v118; // [esp+70h] [ebp-284h]
  int v119; // [esp+78h] [ebp-27Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v120; // [esp+7Ch] [ebp-278h] BYREF
  __m128i v121; // [esp+12Ch] [ebp-1C8h] BYREF
  __m128i v122; // [esp+13Ch] [ebp-1B8h] BYREF
  __m128i v123; // [esp+14Ch] [ebp-1A8h] BYREF
  __m128i v124; // [esp+15Ch] [ebp-198h] BYREF
  float v125; // [esp+16Ch] [ebp-188h]
  std::vector<float> argumentLapFrames; // [esp+170h] [ebp-184h] BYREF
  int v127[2]; // [esp+17Ch] [ebp-178h] BYREF
  int v128; // [esp+184h] [ebp-170h]
  GLRenderer *v129; // [esp+188h] [ebp-16Ch]
  std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > v130; // [esp+18Fh] [ebp-165h] BYREF
  float v131; // [esp+190h] [ebp-164h]
  std::wstring v132; // [esp+194h] [ebp-160h] BYREF
  std::wstring v133; // [esp+1ACh] [ebp-148h] BYREF
  std::wstring v134; // [esp+1C4h] [ebp-130h] BYREF
  std::wstring v135; // [esp+1DCh] [ebp-118h] BYREF
  std::wstring v136; // [esp+1F4h] [ebp-100h] BYREF
  std::wstring v137; // [esp+20Ch] [ebp-E8h] BYREF
  std::wstring description; // [esp+224h] [ebp-D0h] BYREF
  std::wstring v139; // [esp+23Ch] [ebp-B8h] BYREF
  std::wstring s; // [esp+254h] [ebp-A0h] BYREF
  std::wstring v141; // [esp+26Ch] [ebp-88h] BYREF
  std::wstring v142; // [esp+284h] [ebp-70h] BYREF
  std::wstring v143; // [esp+29Ch] [ebp-58h] BYREF
  std::wstring result; // [esp+2B4h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement text; // [esp+2CCh] [ebp-28h] BYREF
  int v146; // [esp+2F0h] [ebp-4h]

  v131 = 0.0;
  if ( !this->cm )
  {
    v4 = GameObject::getGameObject<ACCameraManager>(this->sim);
    this->cm = v4;
    if ( v4 )
    {
      std::wstring::wstring(&text.name, L"Cockpit");
      v146 = 0;
      v5 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 1;
      std::vector<std::wstring>::push_back(&this->cameraNames, v5);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      std::wstring::wstring(&text.name, L"Chase 1");
      v146 = 2;
      v6 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 3;
      std::vector<std::wstring>::push_back(&this->cameraNames, v6);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      std::wstring::wstring(&text.name, L"Chase 2");
      v146 = 4;
      v7 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 5;
      std::vector<std::wstring>::push_back(&this->cameraNames, v7);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      std::wstring::wstring(&text.name, (const wchar_t *)&stru_17C4688.text._Myres);
      v146 = 6;
      v8 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 7;
      std::vector<std::wstring>::push_back(&this->cameraNames, v8);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      std::wstring::wstring(&text.name, (const wchar_t *)&stru_17C4688.labWarning);
      v146 = 8;
      v9 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 9;
      std::vector<std::wstring>::push_back(&this->cameraNames, v9);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      std::wstring::wstring(&text.name, L"Dash");
      v146 = 10;
      v10 = acTranslate(&result, &text.name);
      LOBYTE(v146) = 11;
      std::vector<std::wstring>::push_back(&this->cameraNames, v10);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      v146 = -1;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      for ( i = 0; i < CameraTrack::getCameraTrackCount(this->cm->cameraTrack); ++i )
      {
        v11 = CameraTrack::getCameraSetName(this->cm->cameraTrack, &text.name, i);
        v146 = 12;
        std::vector<std::wstring>::push_back(&this->cameraNames, v11);
        v146 = -1;
        if ( text.name._Myres >= 8 )
          operator delete(text.name._Bx._Ptr);
      }
      this->cameraSpinner->minValue = 1;
      this->cameraSpinner->maxValue = this->cameraNames._Mylast - this->cameraNames._Myfirst;
      ksgui::Spinner::setValue(this->cameraSpinner, this->sim->cameraManager->currentGlobalCameraIndex + 1);
      LODWORD(a) = this;
      v115._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_1300a5c7456b1ec813b458f89c214224_,0>,std::allocator<std::_Func_class<void,int const &>>,void,int const &>::`vftable';
      v115._Space._Pfn[1] = (void (__cdecl *)())this;
      v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v115;
      v12 = &this->cm->evOnCameraSelectedIndex;
      v146 = -1;
      Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)v12, v115, this);
    }
  }
  this->carSpinner->maxValue = this->sim->cars._Mylast - this->sim->cars._Myfirst;
  argumentLapFrames._Myfirst = 0;
  argumentLapFrames._Mylast = 0;
  argumentLapFrames._Myend = 0;
  v13 = this->sim;
  LODWORD(a) = &argumentLapFrames;
  v146 = 14;
  v14 = Sim::getFocusedCarIndex(v13);
  ReplayManager::getNormalizedLapChange(this->repMng, v14, (std::vector<float> *)LODWORD(a));
  ksgui::Control::render(this, (int)this, i, dt, v117, v118);
  v15 = argumentLapFrames._Myfirst;
  v16 = this->gui;
  v17 = (unsigned int)((char *)argumentLapFrames._Mylast - (char *)argumentLapFrames._Myfirst + 3) >> 2;
  v128 = 0;
  v18 = v16->graphics;
  if ( argumentLapFrames._Myfirst > argumentLapFrames._Mylast )
    *(float *)&v17 = 0.0;
  v131 = *(float *)&v17;
  v129 = v18->gl;
  if ( *(float *)&v17 != 0.0 )
  {
    do
    {
      v19 = this->posSlider;
      v20 = *v15;
      LODWORD(a) = &v143._Mysize;
      v125 = v20;
      v21 = LODWORD(v19->rect.top);
      v22 = LODWORD(v19->rect.left);
      v23 = this->__vftable;
      v143._Mysize = v22;
      v143._Myres = v21;
      v23->localToWorld(this, (vec2f *)v127, (const vec2f *)&v143._Mysize);
      *(float *)v127 = (float)((float)(this->posSlider->rect.right - this->posSlider->rect.left) * v125)
                     + *(float *)v127;
      GLRenderer::color4f(v129, 1.0, 1.0, 0.0, 0.40000001);
      GraphicsManager::setTexture(this->gui->graphics, 0, &this->lapIndicatorTexture);
      GLRenderer::quad(v129, *(float *)v127 - 6.0, *(float *)&v127[1] - 15.0, 12.0, 30.0, 1, 0);
      ++v15;
      ++v128;
    }
    while ( v128 != LODWORD(v131) );
  }
  v24 = this->repMng;
  a = dt;
  if ( v24->status == ePhotoMode )
    ReplayInterface::updateUIElementPositionPhotoMode(this, a);
  else
    ReplayInterface::updateUIElementPosition(this, a);
  *(_DWORD *)v120.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v120.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v120.gap68);
  LOBYTE(v146) = 15;
  LODWORD(v131) = 1;
  std::wiostream::basic_iostream<wchar_t>(&v120, &v120.gap10[8], 0);
  v146 = 16;
  *(_DWORD *)&v120.gap0[*(_DWORD *)(*(_DWORD *)v120.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v119 + *(_DWORD *)(*(_DWORD *)v120.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v120.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v120.gap10[8]);
  *(_DWORD *)&v120.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v120.gap10[64] = 0;
  *(_DWORD *)&v120.gap10[68] = 0;
  v25 = this->repMng;
  LOBYTE(v146) = 18;
  LODWORD(v26) = LODWORD(v25->timeMult) & _xmm;
  if ( (int)v26 >= 5 )
    LODWORD(a) = 5;
  else
    LODWORD(a) = (int)v26;
  std::wostream::operator<<(v120.gap10, LODWORD(a));
  switch ( this->repMng->status )
  {
    case eReplayPlay:
      v27 = this->lastSelected;
      v28 = this->butPlay;
      if ( v27 )
        v27->selected = 0;
      v28->selected = 1;
      LODWORD(a) = 5;
      this->lastSelected = v28;
      v141._Myres = 7;
      v141._Mysize = 0;
      v141._Bx._Buf[0] = 0;
      std::wstring::assign(&v141, L"PAUSE", LODWORD(a));
      LOBYTE(v146) = 19;
      v29 = acTranslate(&v134, &v141);
      v30 = this->butPlay;
      LOBYTE(v146) = 20;
      v30->setText(v30, v29);
      if ( v134._Myres >= 8 )
        operator delete(v134._Bx._Ptr);
      v134._Myres = 7;
      v134._Mysize = 0;
      v134._Bx._Buf[0] = 0;
      LOBYTE(v146) = 18;
      if ( v141._Myres >= 8 )
        operator delete(v141._Bx._Ptr);
      break;
    case eReplayRewind:
      v31 = this->lastSelected;
      v32 = this->butRewind;
      if ( v31 )
        v31->selected = 0;
      v32->selected = 1;
      LODWORD(a) = 8;
      this->lastSelected = v32;
      v143._Myres = 7;
      v143._Mysize = 0;
      v143._Bx._Buf[0] = 0;
      std::wstring::assign(&v143, L"X REWIND", LODWORD(a));
      LOBYTE(v146) = 21;
      v33 = acTranslate(&description, &v143);
      LOBYTE(v146) = 22;
      v34 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v120, &v135);
      LOBYTE(v146) = 23;
      v35 = std::operator+<wchar_t>(&v136, v34, v33);
      v36 = this->butRewind;
      LOBYTE(v146) = 24;
      v36->setText(v36, v35);
      if ( v136._Myres >= 8 )
        operator delete(v136._Bx._Ptr);
      v136._Myres = 7;
      v136._Mysize = 0;
      v136._Bx._Buf[0] = 0;
      if ( v135._Myres >= 8 )
        operator delete(v135._Bx._Ptr);
      v135._Myres = 7;
      v135._Mysize = 0;
      v135._Bx._Buf[0] = 0;
      if ( description._Myres >= 8 )
        operator delete(description._Bx._Ptr);
      description._Myres = 7;
      description._Mysize = 0;
      description._Bx._Buf[0] = 0;
      LOBYTE(v146) = 18;
      if ( v143._Myres >= 8 )
        operator delete(v143._Bx._Ptr);
      break;
    case eReplayFastForward:
      v37 = this->lastSelected;
      v38 = this->butFastForward;
      if ( v37 )
        v37->selected = 0;
      v38->selected = 1;
      LODWORD(a) = 14;
      this->lastSelected = v38;
      v133._Myres = 7;
      v133._Mysize = 0;
      v133._Bx._Buf[0] = 0;
      std::wstring::assign(&v133, L"X FAST FORWARD", LODWORD(a));
      LOBYTE(v146) = 25;
      v39 = acTranslate(&v142, &v133);
      LOBYTE(v146) = 26;
      v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v120, &s);
      LOBYTE(v146) = 27;
      v41 = std::operator+<wchar_t>(&v137, v40, v39);
      v42 = this->butFastForward;
      LOBYTE(v146) = 28;
      v42->setText(v42, v41);
      if ( v137._Myres >= 8 )
        operator delete(v137._Bx._Ptr);
      v137._Myres = 7;
      v137._Mysize = 0;
      v137._Bx._Buf[0] = 0;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
      s._Myres = 7;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      if ( v142._Myres >= 8 )
        operator delete(v142._Bx._Ptr);
      v142._Myres = 7;
      v142._Mysize = 0;
      v142._Bx._Buf[0] = 0;
      LOBYTE(v146) = 18;
      if ( v133._Myres >= 8 )
        operator delete(v133._Bx._Ptr);
      break;
    case eReplaySlowMotion:
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"PAUSE", 5u);
      LOBYTE(v146) = 29;
      v43 = acTranslate(&text.name, &result);
      v44 = this->butPlay;
      LOBYTE(v146) = 30;
      v44->setText(v44, v43);
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      text.name._Myres = 7;
      text.name._Mysize = 0;
      text.name._Bx._Buf[0] = 0;
      LOBYTE(v146) = 18;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v45 = this->butSlowMotion;
      goto LABEL_74;
    case ePhotoMode:
      v45 = this->butPhotoMode;
LABEL_74:
      v46 = this->lastSelected;
      if ( v46 )
        v46->selected = 0;
      v45->selected = 1;
      this->lastSelected = v45;
      break;
    default:
      this->butPlay->selected = 0;
      this->butFastForward->selected = 0;
      this->butRewind->selected = 0;
      this->butSlowMotion->selected = 0;
      this->butPhotoMode->selected = 0;
      break;
  }
  v47 = this->repMng->status;
  if ( v47 )
  {
    if ( v47 != eReplaySlowMotion )
    {
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"PLAY (1X)", 9u);
      v48 = this->butPlay;
      LOBYTE(v146) = 31;
      v48->setText(v48, &result);
      LOBYTE(v146) = 18;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
  }
  if ( this->repMng->status != eReplayRewind )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"X REWIND", 8u);
    LOBYTE(v146) = 32;
    v49 = acTranslate(&v142, &result);
    LOBYTE(v146) = 33;
    v50 = std::operator+<wchar_t>(&text.name, L"2", v49);
    v51 = this->butRewind;
    LOBYTE(v146) = 34;
    v51->setText(v51, v50);
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( v142._Myres >= 8 )
      operator delete(v142._Bx._Ptr);
    v142._Myres = 7;
    v142._Mysize = 0;
    v142._Bx._Buf[0] = 0;
    LOBYTE(v146) = 18;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( this->repMng->status != eReplayFastForward )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"X FAST FORWARD", 0xEu);
    LOBYTE(v146) = 35;
    v52 = acTranslate(&v142, &result);
    LOBYTE(v146) = 36;
    v53 = std::operator+<wchar_t>(&text.name, L"2", v52);
    v54 = this->butFastForward;
    LOBYTE(v146) = 37;
    v54->setText(v54, v53);
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( v142._Myres >= 8 )
      operator delete(v142._Bx._Ptr);
    v142._Myres = 7;
    v142._Mysize = 0;
    v142._Bx._Buf[0] = 0;
    LOBYTE(v146) = 18;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v141._Myres = 7;
  v141._Mysize = 0;
  v141._Bx._Buf[0] = 0;
  std::wstring::assign(&v141, word_17BE9D8, 0);
  LOBYTE(v146) = 38;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v120.gap10[8]);
  a = *(float *)&v120.gap10[68];
  v55 = &v141;
  (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)v141._Mysize;
  if ( v141._Myres >= 8 )
    v55 = (std::wstring *)v141._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v120.gap10[8], v55->_Bx._Buf, (unsigned int)(&v115._Impl)[1], SLODWORD(a));
  LOBYTE(v146) = 18;
  if ( v141._Myres >= 8 )
    operator delete(v141._Bx._Ptr);
  v57 = this->repMng;
  a = v56;
  a = v57->slowMoLevel;
  std::wostream::operator<<(v120.gap10);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"X SLOW", 6u);
  LOBYTE(v146) = 39;
  v58 = acTranslate(&s, &result);
  LOBYTE(v146) = 40;
  v59 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v120, &v142);
  LOBYTE(v146) = 41;
  v60 = std::operator+<wchar_t>(&text.name, v59, v58);
  v61 = this->butSlowMotion;
  LOBYTE(v146) = 42;
  v61->setText(v61, v60);
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  if ( v142._Myres >= 8 )
    operator delete(v142._Bx._Ptr);
  v142._Myres = 7;
  v142._Mysize = 0;
  v142._Bx._Buf[0] = 0;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  LOBYTE(v146) = 18;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v62 = this->textInput;
  LODWORD(a) = &v121;
  v121 = _mm_loadu_si128((const __m128i *)&v62->rect);
  v62->getWorldRect(v62, (ksgui::ksRect *)&v121);
  if ( this->textInput->visible )
  {
    v63 = this->font._Ptr;
    *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v143._Bx + 8) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
    Font::setColor(v63, (const vec4f *)&v143._Bx._Alias[8]);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"Replay name", 0xBu);
    LOBYTE(v146) = 43;
    v64 = acTranslate(&v142, &result);
    LOBYTE(v146) = 44;
    v65 = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)std::operator+<wchar_t>(&text.name, v64, L" :");
    LODWORD(a) = 2;
    (&v115._Impl)[1] = v66;
    v67 = this->font._Ptr;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1067030938;
    v115._Impl = v65;
    v68 = this->gui;
    LOBYTE(v146) = 45;
    Font::blitString(
      v67,
      (float)v68->graphics->videoSettings.width * 0.5,
      *(float *)&v121.m128i_i32[2] - 25.0,
      (const std::wstring *)v115._Impl,
      1.2,
      eAlignCenter);
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( v142._Myres >= 8 )
      operator delete(v142._Bx._Ptr);
    v142._Myres = 7;
    v142._Mysize = 0;
    v142._Bx._Buf[0] = 0;
    LOBYTE(v146) = 18;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v69 = this->cameraSpinner;
  LODWORD(a) = &v123;
  v123 = _mm_loadu_si128((const __m128i *)&v69->rect);
  v69->getWorldRect(v69, (ksgui::ksRect *)&v123);
  if ( this->cameraNames._Myfirst != this->cameraNames._Mylast )
  {
    std::wstring::wstring(&result, L"CAMERA");
    LOBYTE(v146) = 46;
    v70 = acTranslate(&v142, &result);
    LOBYTE(v146) = 47;
    v71 = std::operator+<wchar_t>(&text.name, v70, L" ");
    v72 = this->cameraSpinner;
    LOBYTE(v146) = 48;
    v73 = ksgui::Spinner::getValue(v72);
    std::operator+<wchar_t>(&s, v71, &this->cameraNames._Myfirst[v73 - 1]);
    if ( text.name._Myres >= 8 )
      operator delete(text.name._Bx._Ptr);
    text.name._Myres = 7;
    text.name._Mysize = 0;
    text.name._Bx._Buf[0] = 0;
    if ( v142._Myres >= 8 )
      operator delete(v142._Bx._Ptr);
    v142._Myres = 7;
    v142._Mysize = 0;
    v142._Bx._Buf[0] = 0;
    LOBYTE(v146) = 52;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = v74;
    v75 = this->font._Ptr;
    result._Bx._Buf[0] = 0;
    result._Myres = 7;
    result._Mysize = 0;
    Font::blitString(
      v75,
      (float)((float)(*(float *)&v123.m128i_i32[1] - *(float *)v123.m128i_i32) * 0.5) + *(float *)v123.m128i_i32,
      *(float *)&v123.m128i_i32[3] + 13.0,
      &s,
      1.0,
      eAlignCenter);
    LOBYTE(v146) = 18;
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
  }
  v76 = this->carSpinner;
  LODWORD(a) = &v122;
  v122 = _mm_loadu_si128((const __m128i *)&v76->rect);
  v76->getWorldRect(v76, (ksgui::ksRect *)&v122);
  std::wstring::wstring(&result, L"CAR");
  LOBYTE(v146) = 53;
  v77 = acTranslate(&text.name, &result);
  LOBYTE(v146) = 54;
  std::operator+<wchar_t>(&v132, v77, L"#");
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  text.name._Myres = 7;
  text.name._Mysize = 0;
  text.name._Bx._Buf[0] = 0;
  LOBYTE(v146) = 57;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LODWORD(a) = 2;
  (&v115._Impl)[1] = v78;
  v79 = this->font._Ptr;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  Font::blitString(
    v79,
    (float)((float)(*(float *)&v122.m128i_i32[1] - *(float *)v122.m128i_i32) * 0.5) + *(float *)v122.m128i_i32,
    *(float *)&v122.m128i_i32[3] + 13.0,
    &v132,
    1.0,
    eAlignCenter);
  v139._Myres = 7;
  v139._Mysize = 0;
  v139._Bx._Buf[0] = 0;
  v80 = this->posSlider;
  LODWORD(a) = &v124;
  LOBYTE(v146) = 58;
  v124 = _mm_loadu_si128((const __m128i *)&v80->rect);
  v80->getWorldRect(v80, (ksgui::ksRect *)&v124);
  v81 = ReplayManager::getCurrentFrame(this->repMng);
  v83 = timeToWString(&text.name, (int)((double)v81 * ReplayRecorder::recordIntervalMS), 0, 1);
  if ( &v139 != v83 )
  {
    if ( v139._Myres >= 8 )
      operator delete(v139._Bx._Ptr);
    v139._Myres = 7;
    v139._Mysize = 0;
    v139._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&v139, v83);
  }
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  LODWORD(a) = 1;
  (&v115._Impl)[1] = v82;
  Font::blitString(
    this->font._Ptr,
    *(float *)v124.m128i_i32 - 35.0,
    *(float *)&v124.m128i_i32[2] - 12.0,
    &v139,
    1.3,
    eAlignRight);
  v84 = ReplayManager::getRecordedFrames(this->repMng);
  v86 = timeToWString(&text.name, (int)((double)v84 * ReplayRecorder::recordIntervalMS), 0, 1);
  if ( &v139 != v86 )
  {
    if ( v139._Myres >= 8 )
      operator delete(v139._Bx._Ptr);
    v139._Myres = 7;
    v139._Mysize = 0;
    v139._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&v139, v86);
  }
  if ( text.name._Myres >= 8 )
    operator delete(text.name._Bx._Ptr);
  a = 0.0;
  (&v115._Impl)[1] = v85;
  Font::blitString(
    this->font._Ptr,
    *(float *)&v124.m128i_i32[1] + 35.0,
    *(float *)&v124.m128i_i32[2] - 12.0,
    &v139,
    1.3,
    eAlignLeft);
  if ( this->repMng->status == ePhotoMode )
  {
    v87 = this->gui->graphics;
    a = 1.0;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v88 = v87->gl;
    GLRenderer::color4f(v88, 1.0, 1.0, 1.0, 1.0);
    GraphicsManager::setTexture(this->gui->graphics, 0, &this->viewFinder);
    GLRenderer::quad(
      v88,
      0.0,
      0.0,
      (float)this->gui->graphics->videoSettings.width,
      (float)this->gui->graphics->videoSettings.height,
      1,
      0);
    if ( GetAsyncKeyState(4) )
    {
      std::wstring::wstring(&text.name, word_17BE9D8);
      v89 = this->sim;
      LOBYTE(v146) = 59;
      ScreenCapturer::takeScreen(v89->screenCapturer, &text.name);
      LOBYTE(v146) = 58;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      v90 = Path::getDocumentPath(&text.name);
      LOBYTE(v146) = 60;
      std::operator+<wchar_t>(&description, v90, L"\\Assetto Corsa\\screens");
      LOBYTE(v146) = 62;
      if ( text.name._Myres >= 8 )
        operator delete(text.name._Bx._Ptr);
      text.name._Myres = 7;
      text.name._Mysize = 0;
      text.name._Bx._Buf[0] = 0;
      std::wstring::wstring(&v137, L"Screen saved in");
      LOBYTE(v146) = 63;
      v91 = acTranslate(&s, &v137);
      LOBYTE(v146) = 64;
      v92 = std::operator+<wchar_t>(&v142, v91, L" : ");
      LOBYTE(v146) = 65;
      SystemMessage::addMessage(this->sim->systemMessage, v92, &description, eDefault);
      if ( v142._Myres >= 8 )
        operator delete(v142._Bx._Ptr);
      v142._Myres = 7;
      v142._Bx._Buf[0] = 0;
      v142._Mysize = 0;
      if ( s._Myres >= 8 )
      {
        LODWORD(a) = s._Myres + 1;
        (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)s._Bx._Ptr;
        v93 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                           (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&s,
                                           &v130);
        std::allocator<wchar_t>::deallocate(v93, (wchar_t *)(&v115._Impl)[1], LODWORD(a));
      }
      s._Myres = 7;
      std::wstring::_Eos(&s, 0);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v137);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    }
    std::wstring::wstring(&v141);
    v94 = this->spiDofFactor;
    LODWORD(a) = &v143._Bx._Alias[8];
    LOBYTE(v146) = 66;
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v94->rect);
    v94->getWorldRect(v94, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&text.name, L"DOF FACTOR");
    LOBYTE(v146) = 67;
    v95 = acTranslate(&v134, &text.name);
    std::wstring::operator=(&v141, v95);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v134);
    LOBYTE(v146) = 66;
    std::wstring::~wstring(&text);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v96 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v96,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v97 = this->spiDofFocus;
    LODWORD(a) = &v143._Bx._Alias[8];
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v97->rect);
    v97->getWorldRect(v97, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&v142, L"DOF FOCUS");
    LOBYTE(v146) = 68;
    v98 = acTranslate(&text.name, &v142);
    std::wstring::operator=(&v141, v98);
    std::wstring::~wstring(&text);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v142);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v99 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v99,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v100 = this->spiExpo;
    LODWORD(a) = &v143._Bx._Alias[8];
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v100->rect);
    v100->getWorldRect(v100, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&s, L"EXP. MULT.");
    LOBYTE(v146) = 69;
    v101 = acTranslate(&text.name, &s);
    std::wstring::operator=(&v141, v101);
    std::wstring::~wstring(&text);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v102 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v102,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v103 = this->spiFov;
    LODWORD(a) = &v143._Bx._Alias[8];
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v103->rect);
    v103->getWorldRect(v103, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&v137, L"FOV");
    LOBYTE(v146) = 70;
    v104 = acTranslate(&text.name, &v137);
    std::wstring::operator=(&v141, v104);
    std::wstring::~wstring(&text);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v137);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v105 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v105,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v106 = this->spiCameraRoll;
    LODWORD(a) = &v143._Bx._Alias[8];
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v106->rect);
    v106->getWorldRect(v106, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&description, L"ROLL");
    LOBYTE(v146) = 71;
    v107 = acTranslate(&text.name, &description);
    std::wstring::operator=(&v141, v107);
    std::wstring::~wstring(&text);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v108 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v108,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v109 = this->spiSunAzimuth;
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v109->rect);
    v109->getWorldRect(v109, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&v135, L"AZIMUTH");
    LOBYTE(v146) = 72;
    v110 = acTranslate(&text.name, &v135);
    std::wstring::operator=(&v141, v110);
    std::wstring::~wstring(&text);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v135);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v111 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v111,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    v112 = this->spiSunZenith;
    LODWORD(a) = &v143._Bx._Alias[8];
    *(__m128i *)((char *)&v143._Bx + 8) = _mm_loadu_si128((const __m128i *)&v112->rect);
    v112->getWorldRect(v112, (ksgui::ksRect *)&v143._Bx._Alias[8]);
    std::wstring::wstring(&v136, L"ZENITH");
    LOBYTE(v146) = 73;
    v113 = acTranslate(&v142, &v136);
    std::wstring::operator=(&v141, v113);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v142);
    LOBYTE(v146) = 66;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v136);
    LODWORD(a) = 2;
    (&v115._Impl)[1] = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)1065353216;
    v115._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v141;
    *(float *)&v115._Space._Alias[12] = *(float *)&v143._Myres + 10.0;
    v131 = ksgui::ksRect::getWidth((ksgui::ksRect *)&v143._Bx._Alias[8]);
    *(float *)&v115._Space._Pfn[2] = (float)(v131 * 0.5) + *(float *)&v143._Bx._Alias[8];
    v114 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::blitString(
      v114,
      *(float *)&v115._Space._Pfn[2],
      *(float *)&v115._Space._Alias[12],
      (const std::wstring *)v115._Impl,
      *(float *)&(&v115._Impl)[1],
      SLODWORD(a));
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v141);
  }
  else if ( this->prevStatus == ePhotoMode )
  {
    ACCameraManager::setMode(this->cm, this->prevCameraMode, 1, 0);
    this->prevStatus = this->repMng->status;
  }
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v139);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v132);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v120);
  std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&argumentLapFrames);
}
void ReplayInterface::resetCuts(ReplayInterface *this)
{
  ksgui::Slider::resetMarkers(this->posSlider);
}
void ReplayInterface::updateUIElementPosition(ReplayInterface *this, float dt)
{
  Sim *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm1_4
  ReplayInterface_vtbl *v7; // eax
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  bool v12; // al
  float v13; // xmm4_4
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  float v16; // xmm1_4
  ksgui::Slider *v17; // ecx
  __m128 v18; // xmm1
  float v19; // xmm4_4
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  float v22; // xmm2_4
  ksgui::Form *v23; // ecx
  __m128 v24; // xmm1
  float v25; // xmm4_4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm5_4
  float v31; // xmm5_4
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  float v34; // xmm1_4
  float v35; // xmm4_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm4_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm2_4
  float v54; // xmm4_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  __m128 v57; // xmm4
  __m128i top_8; // [esp+1Ch] [ebp-24h] BYREF
  float v59; // [esp+2Ch] [ebp-14h]
  float y; // [esp+30h] [ebp-10h]
  float v61; // [esp+34h] [ebp-Ch]
  float v62; // [esp+38h] [ebp-8h]
  float top; // [esp+3Ch] [ebp-4h]
  float dta; // [esp+44h] [ebp+4h]
  float dtb; // [esp+44h] [ebp+4h]

  ksgui::Control::resetBaseRect(this);
  v3 = this->sim;
  v62 = (float)this->gui->graphics->videoSettings.width;
  if ( Sim::isInTripleScreenMode(v3) )
  {
    v4 = (float)this->gui->graphics->videoSettings.width * 0.33333334;
    v62 = v4;
  }
  else
  {
    v4 = v62;
  }
  v61 = (float)(v4 * 0.0099999998) * 13.5;
  v5 = v4 - (float)(v61 * 2.0);
  y = v5;
  if ( v5 < 700.0 )
  {
    v5 = FLOAT_700_0;
    y = FLOAT_700_0;
  }
  ((void (*)(ReplayInterface *, _DWORD, _DWORD))this->setSize)(
    this,
    LODWORD(v5),
    LODWORD(this->replayHeight));
  v6 = this->stayUpCounter;
  v59 = (float)((float)this->gui->graphics->videoSettings.height - 105.0) + 5.0;
  top = v59;
  if ( v6 == 0.0 )
  {
    v7 = this->__vftable;
    top_8 = _mm_loadu_si128((const __m128i *)&this->rect);
    v7->getWorldRect(this, (ksgui::ksRect *)&top_8);
    v8 = this->targetY;
    v9 = dt * 300.0;
    if ( *(float *)&top_8.m128i_i32[2] <= v8 )
    {
      if ( v8 <= *(float *)&top_8.m128i_i32[2] )
      {
        v10 = top;
      }
      else
      {
        v10 = *(float *)&top_8.m128i_i32[2] + v9;
        top = *(float *)&top_8.m128i_i32[2] + v9;
      }
    }
    else
    {
      v10 = *(float *)&top_8.m128i_i32[2] - v9;
      top = *(float *)&top_8.m128i_i32[2] - v9;
    }
    if ( v9 > COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 - *(float *)&top_8.m128i_i32[2]) & _xmm) )
    {
      v10 = v8;
      top = v8;
    }
    if ( v10 == v59 )
      this->stayUpCounter = 3.0;
  }
  else
  {
    v11 = v6 - dt;
    this->stayUpCounter = v11;
    if ( dt > v11 )
      this->stayUpCounter = 0.0;
  }
  v12 = Sim::isInTripleScreenMode(this->sim);
  v13 = v61;
  if ( v12 )
    v13 = v61 + v62;
  v14.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v13);
  v15.m128_i32[0] = LODWORD(v13) ^ LODWORD(FLOAT_N0_0) & LODWORD(v13);
  LODWORD(v16) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v15, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v13);
  v15.m128_f32[0] = (float)((float)(v13 + v16) - v16) - v13;
  ksgui::Form::setPosition(
    (ksgui::Form *)this,
    (float)((float)(v13 + v16) - v16) - COERCE_FLOAT(_mm_cmpgt_ss(v15, v14).m128_u32[0] & LODWORD(FLOAT_1_0)),
    top);
  v17 = this->posSlider;
  v61 = (float)(this->rect.right - this->rect.left) * 0.5;
  if ( (float)(v17->rect.right - v17->rect.left) == 0.0 )
  {
    v18.m128_f32[0] = FLOAT_8388608_0;
    v19 = (float)(this->rect.right - this->rect.left) - (float)((float)((float)(y * 2.0) * 0.014285714) * 9.0);
    v20.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v19);
    v21.m128_i32[0] = LODWORD(v19) ^ LODWORD(FLOAT_N0_0) & LODWORD(v19);
    v21.m128_f32[0] = _mm_cmplt_ss(v21, v18).m128_f32[0];
    v22 = (float)(v19 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v21.m128_i32[0] | v20.m128_i32[0]))
        - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v21.m128_i32[0] | v20.m128_i32[0]);
    v21.m128_f32[0] = v22 - v19;
    ((void (*)(ksgui::Slider *, _DWORD, int))v17->setSize)(
      v17,
      v22 - COERCE_FLOAT(_mm_cmpgt_ss(v21, v20).m128_u32[0] & LODWORD(FLOAT_1_0)),
      1086324736);
  }
  ksgui::Slider::updateMarkers(this->posSlider);
  v23 = (ksgui::Form *)this->posSlider;
  v24.m128_f32[0] = FLOAT_8388608_0;
  v25 = v61 - (float)((float)(v23->rect.right - v23->rect.left) * 0.5);
  v26.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v25);
  v27.m128_i32[0] = LODWORD(v25) ^ LODWORD(FLOAT_N0_0) & LODWORD(v25);
  v27.m128_f32[0] = _mm_cmplt_ss(v27, v24).m128_f32[0];
  v28 = (float)(v25 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v27.m128_i32[0] | v26.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v27.m128_i32[0] | v26.m128_i32[0]);
  v27.m128_f32[0] = v28 - v25;
  ksgui::Form::setPosition(v23, v28 - COERCE_FLOAT(_mm_cmpgt_ss(v27, v26).m128_u32[0] & LODWORD(FLOAT_1_0)), 15.0);
  dta = ReplayManager::getNormalizedPosition(this->repMng);
  if ( dta <= 1.0 )
  {
    v29 = 0.0;
    if ( dta >= 0.0 )
      v29 = dta;
  }
  else
  {
    v29 = FLOAT_1_0;
  }
  v30 = v61;
  this->posSlider->value = v29;
  dtb = this->posSlider->rect.bottom + 8.0;
  v31 = v30 - (float)(this->totalWidth * 0.5);
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v31);
  v33.m128_i32[0] = LODWORD(v31) ^ LODWORD(FLOAT_N0_0) & LODWORD(v31);
  LODWORD(v34) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v33, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v31);
  v33.m128_f32[0] = (float)((float)(v31 + v34) - v34) - v31;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butExit,
    (float)((float)(v31 + v34) - v34) - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v35 = this->butExit->rect.right + 5.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v35);
  v33.m128_i32[0] = LODWORD(v35) ^ LODWORD(FLOAT_N0_0) & LODWORD(v35);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v37 = (float)(v35 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v37 - v35;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butSaveEdit,
    v37 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v38 = this->butSaveEdit->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v38);
  v33.m128_i32[0] = LODWORD(v38) ^ LODWORD(FLOAT_N0_0) & LODWORD(v38);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v39 = (float)(v38 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v39 - v38;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butRewind,
    v39 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v40 = this->butRewind->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v33.m128_i32[0] = LODWORD(v40) ^ LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v41 = (float)(v40 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v41 - v40;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butStop,
    v41 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v42 = this->butStop->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v42);
  v33.m128_i32[0] = LODWORD(v42) ^ LODWORD(FLOAT_N0_0) & LODWORD(v42);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v43 = (float)(v42 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v43 - v42;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butPlay,
    v43 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v44 = this->butPlay->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v44);
  v33.m128_i32[0] = LODWORD(v44) ^ LODWORD(FLOAT_N0_0) & LODWORD(v44);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v45 = (float)(v44 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v45 - v44;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butNextFrame,
    v45 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v46 = this->butNextFrame->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v46);
  v33.m128_i32[0] = LODWORD(v46) ^ LODWORD(FLOAT_N0_0) & LODWORD(v46);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v47 = (float)(v46 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v47 - v46;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butFastForward,
    v47 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v48 = this->butFastForward->rect.right + 20.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  y = dtb + 12.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v48);
  v33.m128_i32[0] = LODWORD(v48) ^ LODWORD(FLOAT_N0_0) & LODWORD(v48);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v49 = (float)(v48 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v49 - v48;
  ksgui::Spinner::setPosition(
    this->slowMoSpinner,
    v49 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb + 12.0);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v50 = (float)((float)(this->slowMoSpinner->rect.bottom - this->slowMoSpinner->rect.top)
              + this->slowMoSpinner->rect.left)
      + 4.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v50);
  v33.m128_i32[0] = LODWORD(v50) ^ LODWORD(FLOAT_N0_0) & LODWORD(v50);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v51 = (float)(v50 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v51 - v50;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butSlowMotion,
    v51 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v52 = this->slowMoSpinner->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v33.m128_i32[0] = LODWORD(v52) ^ LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v53 = (float)(v52 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v53 - v52;
  ksgui::Spinner::setPosition(
    this->cameraSpinner,
    v53 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    y);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v54 = this->cameraSpinner->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v54);
  v33.m128_i32[0] = LODWORD(v54) ^ LODWORD(FLOAT_N0_0) & LODWORD(v54);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v55 = (float)(v54 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v55 - v54;
  ksgui::Spinner::setPosition(
    this->carSpinner,
    v55 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    y);
  v32.m128_f32[0] = FLOAT_8388608_0;
  v56 = this->carSpinner->rect.right + 20.0;
  v57.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v56);
  v33.m128_i32[0] = LODWORD(v56) ^ LODWORD(FLOAT_N0_0) & LODWORD(v56);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v32).m128_f32[0];
  v36.m128_f32[0] = (float)(v56 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v57.m128_i32[0]))
                  - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v57.m128_i32[0]);
  v33.m128_f32[0] = v36.m128_f32[0] - v56;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butPhotoMode,
    v36.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v33, v57).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  ksgui::Control::setVisible(this->butTakePic, 0);
  ksgui::Control::setVisible(this->spiExpo, 0);
  ksgui::Control::setVisible(this->spiFov, 0);
  ksgui::Control::setVisible(this->spiDofFactor, 0);
  ksgui::Control::setVisible(this->spiDofFocus, 0);
  ksgui::Control::setVisible(this->spiSunAzimuth, 0);
  ksgui::Control::setVisible(this->spiSunZenith, 0);
  ksgui::Control::setVisible(this->spiCameraRoll, 0);
}
void ReplayInterface::updateUIElementPositionPhotoMode(ReplayInterface *this, float dt)
{
  Sim *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm1_4
  ReplayInterface_vtbl *v7; // eax
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  bool v12; // al
  float v13; // xmm4_4
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  float v16; // xmm1_4
  ksgui::Slider *v17; // ecx
  __m128 v18; // xmm1
  float v19; // xmm4_4
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  float v22; // xmm2_4
  ksgui::Form *v23; // ecx
  __m128 v24; // xmm1
  float v25; // xmm4_4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm4_4
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  float v34; // xmm1_4
  float v35; // xmm4_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm4_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm2_4
  float v54; // xmm4_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm2_4
  float v58; // xmm4_4
  float v59; // xmm2_4
  float v60; // xmm4_4
  float v61; // xmm2_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm4_4
  float v65; // xmm2_4
  float v66; // xmm4_4
  float v67; // xmm2_4
  float v68; // xmm4_4
  float v69; // xmm2_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  float v72; // xmm2_4
  __m128 v73; // xmm4
  __m128i top_8; // [esp+1Ch] [ebp-24h] BYREF
  float v75; // [esp+2Ch] [ebp-14h]
  float y; // [esp+30h] [ebp-10h]
  float v77; // [esp+34h] [ebp-Ch]
  float v78; // [esp+38h] [ebp-8h]
  float top; // [esp+3Ch] [ebp-4h]
  float dta; // [esp+44h] [ebp+4h]
  float dtb; // [esp+44h] [ebp+4h]
  float dtc; // [esp+44h] [ebp+4h]

  ksgui::Control::resetBaseRect(this);
  v3 = this->sim;
  v78 = (float)this->gui->graphics->videoSettings.width;
  if ( Sim::isInTripleScreenMode(v3) )
  {
    v4 = (float)this->gui->graphics->videoSettings.width * 0.33333334;
    v78 = v4;
  }
  else
  {
    v4 = v78;
  }
  v77 = (float)(v4 * 0.0099999998) * 13.5;
  v5 = v4 - (float)(v77 * 2.0);
  y = v5;
  if ( v5 < 700.0 )
  {
    v5 = FLOAT_700_0;
    y = FLOAT_700_0;
  }
  ((void (*)(ReplayInterface *, _DWORD, _DWORD))this->setSize)(
    this,
    LODWORD(v5),
    LODWORD(this->replayHeight));
  v6 = this->stayUpPhotoMode;
  v75 = (float)((float)this->gui->graphics->videoSettings.height - 210.0) + 5.0;
  top = v75;
  if ( v6 == 0.0 )
  {
    v7 = this->__vftable;
    top_8 = _mm_loadu_si128((const __m128i *)&this->rect);
    v7->getWorldRect(this, (ksgui::ksRect *)&top_8);
    v8 = this->targetYPhoto;
    v9 = dt * 300.0;
    if ( *(float *)&top_8.m128i_i32[2] <= v8 )
    {
      if ( v8 <= *(float *)&top_8.m128i_i32[2] )
      {
        v10 = top;
      }
      else
      {
        v10 = *(float *)&top_8.m128i_i32[2] + v9;
        top = *(float *)&top_8.m128i_i32[2] + v9;
      }
    }
    else
    {
      v10 = *(float *)&top_8.m128i_i32[2] - v9;
      top = *(float *)&top_8.m128i_i32[2] - v9;
    }
    if ( v9 > COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 - *(float *)&top_8.m128i_i32[2]) & _xmm) )
    {
      v10 = v8;
      top = v8;
    }
    if ( v10 == v75 )
      this->stayUpPhotoMode = 3.0;
  }
  else
  {
    v11 = v6 - dt;
    this->stayUpPhotoMode = v11;
    if ( dt > v11 )
      this->stayUpPhotoMode = 0.0;
  }
  v12 = Sim::isInTripleScreenMode(this->sim);
  v13 = v77;
  if ( v12 )
    v13 = v77 + v78;
  v14.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v13);
  v15.m128_i32[0] = LODWORD(v13) ^ LODWORD(FLOAT_N0_0) & LODWORD(v13);
  LODWORD(v16) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v15, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v13);
  v15.m128_f32[0] = (float)((float)(v13 + v16) - v16) - v13;
  ksgui::Form::setPosition(
    (ksgui::Form *)this,
    (float)((float)(v13 + v16) - v16) - COERCE_FLOAT(_mm_cmpgt_ss(v15, v14).m128_u32[0] & LODWORD(FLOAT_1_0)),
    top);
  v17 = this->posSlider;
  v78 = (float)(this->rect.right - this->rect.left) * 0.5;
  if ( (float)(v17->rect.right - v17->rect.left) == 0.0 )
  {
    v18.m128_f32[0] = FLOAT_8388608_0;
    v19 = (float)(this->rect.right - this->rect.left) - (float)((float)((float)(y * 2.0) * 0.014285714) * 9.0);
    v20.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v19);
    v21.m128_i32[0] = LODWORD(v19) ^ LODWORD(FLOAT_N0_0) & LODWORD(v19);
    v21.m128_f32[0] = _mm_cmplt_ss(v21, v18).m128_f32[0];
    v22 = (float)(v19 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v21.m128_i32[0] | v20.m128_i32[0]))
        - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v21.m128_i32[0] | v20.m128_i32[0]);
    v21.m128_f32[0] = v22 - v19;
    ((void (*)(ksgui::Slider *, _DWORD, int))v17->setSize)(
      v17,
      v22 - COERCE_FLOAT(_mm_cmpgt_ss(v21, v20).m128_u32[0] & LODWORD(FLOAT_1_0)),
      1086324736);
  }
  ksgui::Slider::updateMarkers(this->posSlider);
  v23 = (ksgui::Form *)this->posSlider;
  v24.m128_f32[0] = FLOAT_8388608_0;
  v25 = v78 - (float)((float)(v23->rect.right - v23->rect.left) * 0.5);
  v26.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v25);
  v27.m128_i32[0] = LODWORD(v25) ^ LODWORD(FLOAT_N0_0) & LODWORD(v25);
  v27.m128_f32[0] = _mm_cmplt_ss(v27, v24).m128_f32[0];
  v28 = (float)(v25 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v27.m128_i32[0] | v26.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v27.m128_i32[0] | v26.m128_i32[0]);
  v27.m128_f32[0] = v28 - v25;
  ksgui::Form::setPosition(v23, v28 - COERCE_FLOAT(_mm_cmpgt_ss(v27, v26).m128_u32[0] & LODWORD(FLOAT_1_0)), 30.0);
  dta = ReplayManager::getNormalizedPosition(this->repMng);
  if ( dta <= 1.0 )
  {
    v29 = 0.0;
    if ( dta >= 0.0 )
      v29 = dta;
  }
  else
  {
    v29 = FLOAT_1_0;
  }
  v30 = v78;
  this->posSlider->value = v29;
  dtb = this->posSlider->rect.bottom + 8.0;
  v31 = v30 - (float)(this->totalWidth * 0.5);
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v31);
  v33.m128_i32[0] = LODWORD(v31) ^ LODWORD(FLOAT_N0_0) & LODWORD(v31);
  LODWORD(v34) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v33, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v31);
  v33.m128_f32[0] = (float)((float)(v31 + v34) - v34) - v31;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butExit,
    (float)((float)(v31 + v34) - v34) - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v35 = this->butExit->rect.right + 5.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v35);
  v33.m128_i32[0] = LODWORD(v35) ^ LODWORD(FLOAT_N0_0) & LODWORD(v35);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v37 = (float)(v35 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v37 - v35;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butSaveEdit,
    v37 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v38 = this->butSaveEdit->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v38);
  v33.m128_i32[0] = LODWORD(v38) ^ LODWORD(FLOAT_N0_0) & LODWORD(v38);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v39 = (float)(v38 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v39 - v38;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butRewind,
    v39 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v40 = this->butRewind->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v33.m128_i32[0] = LODWORD(v40) ^ LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v41 = (float)(v40 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v41 - v40;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butStop,
    v41 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v42 = this->butStop->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v42);
  v33.m128_i32[0] = LODWORD(v42) ^ LODWORD(FLOAT_N0_0) & LODWORD(v42);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v43 = (float)(v42 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v43 - v42;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butPlay,
    v43 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v44 = this->butPlay->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v44);
  v33.m128_i32[0] = LODWORD(v44) ^ LODWORD(FLOAT_N0_0) & LODWORD(v44);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v45 = (float)(v44 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v45 - v44;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butNextFrame,
    v45 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v46 = this->butNextFrame->rect.right + 5.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v46);
  v33.m128_i32[0] = LODWORD(v46) ^ LODWORD(FLOAT_N0_0) & LODWORD(v46);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v47 = (float)(v46 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v47 - v46;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butFastForward,
    v47 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v48 = this->butFastForward->rect.right + 20.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  y = dtb + 12.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v48);
  v33.m128_i32[0] = LODWORD(v48) ^ LODWORD(FLOAT_N0_0) & LODWORD(v48);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v49 = (float)(v48 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v49 - v48;
  ksgui::Spinner::setPosition(
    this->slowMoSpinner,
    v49 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb + 12.0);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v50 = (float)((float)(this->slowMoSpinner->rect.bottom - this->slowMoSpinner->rect.top)
              + this->slowMoSpinner->rect.left)
      + 4.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v50);
  v33.m128_i32[0] = LODWORD(v50) ^ LODWORD(FLOAT_N0_0) & LODWORD(v50);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v51 = (float)(v50 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v51 - v50;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butSlowMotion,
    v51 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v52 = this->slowMoSpinner->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v33.m128_i32[0] = LODWORD(v52) ^ LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v53 = (float)(v52 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v53 - v52;
  ksgui::Spinner::setPosition(
    this->cameraSpinner,
    v53 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    y);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v54 = this->cameraSpinner->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v54);
  v33.m128_i32[0] = LODWORD(v54) ^ LODWORD(FLOAT_N0_0) & LODWORD(v54);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v55 = (float)(v54 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v55 - v54;
  ksgui::Spinner::setPosition(
    this->carSpinner,
    v55 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    y);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v56 = this->carSpinner->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v56);
  v33.m128_i32[0] = LODWORD(v56) ^ LODWORD(FLOAT_N0_0) & LODWORD(v56);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v57 = (float)(v56 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v57 - v56;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butPhotoMode,
    v57 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtb);
  dtc = this->carSpinner->rect.bottom + 50.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  v58 = v78 - (float)(this->totalWidthPhoto * 0.5);
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v58);
  v33.m128_i32[0] = COERCE_UNSIGNED_INT(v78 - (float)(this->totalWidthPhoto * 0.5)) ^ LODWORD(FLOAT_N0_0) & LODWORD(v58);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v59 = (float)(v58 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v59 - v58;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->butTakePic,
    v59 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc - 12.0);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v60 = this->butTakePic->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v60);
  v33.m128_i32[0] = LODWORD(v60) ^ LODWORD(FLOAT_N0_0) & LODWORD(v60);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v61 = (float)(v60 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v61 - v60;
  ksgui::Spinner::setPosition(
    this->spiExpo,
    v61 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v62 = this->spiExpo->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v62);
  v33.m128_i32[0] = LODWORD(v62) ^ LODWORD(FLOAT_N0_0) & LODWORD(v62);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v63 = (float)(v62 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v63 - v62;
  ksgui::Spinner::setPosition(
    this->spiFov,
    v63 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v64 = this->spiFov->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v64);
  v33.m128_i32[0] = LODWORD(v64) ^ LODWORD(FLOAT_N0_0) & LODWORD(v64);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v65 = (float)(v64 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v65 - v64;
  ksgui::Spinner::setPosition(
    this->spiDofFactor,
    v65 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v66 = this->spiDofFactor->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v66);
  v33.m128_i32[0] = LODWORD(v66) ^ LODWORD(FLOAT_N0_0) & LODWORD(v66);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v67 = (float)(v66 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v67 - v66;
  ksgui::Spinner::setPosition(
    this->spiDofFocus,
    v67 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v36.m128_f32[0] = FLOAT_8388608_0;
  v68 = this->spiDofFocus->rect.right + 20.0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v68);
  v33.m128_i32[0] = LODWORD(v68) ^ LODWORD(FLOAT_N0_0) & LODWORD(v68);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v69 = (float)(v68 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v69 - v68;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->spiSunAzimuth,
    v69 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v70 = this->spiSunAzimuth->rect.right + 20.0;
  v36.m128_f32[0] = FLOAT_8388608_0;
  v32.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v70);
  v33.m128_i32[0] = LODWORD(v70) ^ LODWORD(FLOAT_N0_0) & LODWORD(v70);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v36).m128_f32[0];
  v71 = (float)(v70 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v32.m128_i32[0]);
  v33.m128_f32[0] = v71 - v70;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->spiSunZenith,
    v71 - COERCE_FLOAT(_mm_cmpgt_ss(v33, v32).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
  v32.m128_f32[0] = FLOAT_8388608_0;
  v72 = this->spiSunZenith->rect.right + 20.0;
  v73.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v72);
  v33.m128_i32[0] = LODWORD(v72) ^ LODWORD(FLOAT_N0_0) & LODWORD(v72);
  v33.m128_f32[0] = _mm_cmplt_ss(v33, v32).m128_f32[0];
  v36.m128_f32[0] = (float)(v72 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v73.m128_i32[0]))
                  - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v33.m128_i32[0] | v73.m128_i32[0]);
  v33.m128_f32[0] = v36.m128_f32[0] - v72;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->spiCameraRoll,
    v36.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v33, v73).m128_u32[0] & LODWORD(FLOAT_1_0)),
    dtc);
}
