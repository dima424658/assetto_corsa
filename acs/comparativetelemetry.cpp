#include "comparativetelemetry.h
void __userpurge ComparativeTelemetry::ComparativeTelemetry(ComparativeTelemetry *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  Game *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  void (***v7)(_DWORD); // edx
  unsigned int v8; // ecx
  Sim *v9; // eax
  GameObject **v10; // esi
  ComparativeTelemetryRecorder *v11; // eax
  ksgui::Graph *v12; // esi
  ksgui::Graph *v13; // eax
  ksgui::Graph *v14; // esi
  ksgui::Graph *v15; // eax
  ksgui::Graph *v16; // eax
  ksgui::Graph *v17; // esi
  int v18; // eax
  ksgui::Graph *v19; // eax
  ksgui::Graph *v20; // esi
  ksgui::Graph *v21; // eax
  Sim *v22; // ecx
  ksgui::CheckBox *v23; // esi
  ksgui::CheckBox *v24; // eax
  std::wstring *v25; // esi
  Sim *v26; // ecx
  CarAvatar *v27; // eax
  std::wstring *v28; // eax
  ksgui::CheckBox *v29; // ecx
  Event<ksgui::OnListBoxItemClickedEvent> *v30; // ecx
  ksgui::CheckBox *v31; // eax
  ksgui::CheckBox *v32; // esi
  ksgui::CheckBox *v33; // eax
  std::wstring *v34; // esi
  Sim *v35; // ecx
  CarAvatar *v36; // eax
  std::wstring *v37; // eax
  ksgui::CheckBox *v38; // ecx
  Event<ksgui::OnListBoxItemClickedEvent> *v39; // ecx
  ksgui::CheckBox *v40; // eax
  ksgui::Control *v41; // esi
  ksgui::Control *v42; // eax
  bool v43; // zf
  ksgui::Control *v44; // ecx
  Event<OnMouseWheelMovedEvent> *v45; // ecx
  ksgui::Control *v46; // ecx
  __m128i v47; // xmm0
  _BYTE v48[36]; // [esp-14h] [ebp-B4h] BYREF
  ComparativeTelemetry *v49; // [esp+24h] [ebp-7Ch]
  int v50; // [esp+28h] [ebp-78h]
  Sim *v51; // [esp+2Ch] [ebp-74h]
  std::wstring v52; // [esp+30h] [ebp-70h] BYREF
  std::wstring result; // [esp+48h] [ebp-58h] BYREF
  std::wstring iname; // [esp+60h] [ebp-40h] BYREF
  std::wstring text; // [esp+78h] [ebp-28h] BYREF
  int v56; // [esp+9Ch] [ebp-4h]

  v50 = 0;
  *(_DWORD *)&v48[28] = 0;
  v49 = this;
  v4 = aSim->game;
  v51 = aSim;
  *(_DWORD *)&v48[24] = v4->gui;
  *(_DWORD *)&v48[20] = 7;
  *(_DWORD *)&v48[16] = 0;
  *(_WORD *)v48 = 0;
  std::wstring::assign((std::wstring *)v48, L"COMPARATIVE_TELEMETRY", 0x15u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v48, *(ksgui::GUI **)&v48[24], v48[28]);
  this->__vftable = (ComparativeTelemetry_vtbl *)&ComparativeTelemetry::`vftable';
  v56 = 0;
  this->bestData._Myfirst = 0;
  this->bestData._Mylast = 0;
  this->bestData._Myend = 0;
  this->seriesTime._Myfirst = 0;
  this->seriesTime._Mylast = 0;
  this->seriesTime._Myend = 0;
  this->opponents._Myfirst = 0;
  this->opponents._Mylast = 0;
  this->opponents._Myend = 0;
  LOBYTE(v56) = 3;
  v5 = (Font *)operator new(24);
  text._Myres = (unsigned int)v5;
  LOBYTE(v56) = 4;
  if ( v5 )
    Font::Font(v5, eFontMonospaced, 16.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v56) = 3;
  text._Mysize = 0;
  text._Myres = 0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&text._Mysize, v6);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&text._Mysize);
  v7 = (void (***)(_DWORD))text._Myres;
  if ( text._Myres )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(text._Myres + 4), 0xFFFFFFFF) )
    {
      (**v7)(v7);
      v8 = text._Myres;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(text._Myres + 8), 0xFFFFFFFF) )
        (*(void (**)(unsigned int))(*(_DWORD *)v8 + 4))(v8);
    }
  }
  text._Myres = 0;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->seriesTime,
    (ICollisionObject *const *)&text._Myres);
  text._Myres = 0;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->seriesTime,
    (ICollisionObject *const *)&text._Myres);
  text._Myres = 0;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->seriesTime,
    (ICollisionObject *const *)&text._Myres);
  v9 = v51;
  this->sim = aSim;
  v10 = aSim->gameObjects._Myfirst;
  if ( v10 == v9->gameObjects._Mylast )
  {
LABEL_11:
    v11 = 0;
  }
  else
  {
    while ( 1 )
    {
      v11 = (ComparativeTelemetryRecorder *)__RTDynamicCast(
                                              *v10,
                                              0,
                                              &GameObject `RTTI Type Descriptor',
                                              &ComparativeTelemetryRecorder `RTTI Type Descriptor',
                                              0);
      if ( v11 )
        break;
      if ( ++v10 == v51->gameObjects._Mylast )
        goto LABEL_11;
    }
  }
  this->backColor = (vec4f)_xmm;
  *(_DWORD *)&v48[28] = 0;
  *(_DWORD *)&v48[24] = word_17BE9D8;
  this->ctr = v11;
  this->borderColor = (vec4f)_xmm;
  std::wstring::assign(&this->text, *(const wchar_t **)&v48[24], *(unsigned int *)&v48[28]);
  ksgui::Control::setVisible(this->formTitle, 0);
  *(_DWORD *)&v48[28] = 320;
  this->currentPerc = -1.0;
  v12 = (ksgui::Graph *)operator new(*(_DWORD *)&v48[28]);
  text._Myres = (unsigned int)v12;
  v13 = 0;
  LOBYTE(v56) = 5;
  if ( v12 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"BRAKE_GRAPH", 0xBu);
    ksgui::Graph::Graph(v12, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  *(_DWORD *)&v48[28] = v13;
  LOBYTE(v56) = 3;
  this->graphBrake = v13;
  ksgui::Control::addControl(this, *(ksgui::Control **)&v48[28]);
  this->graphBrake->maxY = 1.05;
  this->graphBrake->minY = -0.050000001;
  this->graphBrake->maxValuesCount = 0;
  this->graphBrake->borderColor = 0i64;
  this->graphBrake->backColor = 0i64;
  *(vec3f *)&v48[20] = serieColors[0];
  ksgui::Graph::addSerie(this->graphBrake, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[1];
  ksgui::Graph::addSerie(this->graphBrake, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[2];
  ksgui::Graph::addSerie(this->graphBrake, *(__int128 *)&v48[20]);
  v14 = (ksgui::Graph *)operator new(320);
  text._Myres = (unsigned int)v14;
  v15 = 0;
  LOBYTE(v56) = 6;
  if ( v14 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"SPEED_GRAPH", 0xBu);
    ksgui::Graph::Graph(v14, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  this->graphSpeed = v15;
  v15->autoAdjustMaxValue = 1;
  v16 = this->graphSpeed;
  LOBYTE(v56) = 3;
  v16->maxY = 220.0;
  this->graphSpeed->minY = -5.0;
  this->graphSpeed->maxValuesCount = 0;
  this->graphSpeed->borderColor = 0i64;
  this->graphSpeed->backColor = 0i64;
  *(vec3f *)&v48[20] = serieColors[0];
  ksgui::Graph::addSerie(this->graphSpeed, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[1];
  ksgui::Graph::addSerie(this->graphSpeed, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[2];
  ksgui::Graph::addSerie(this->graphSpeed, *(__int128 *)&v48[20]);
  ksgui::Control::addControl(this, this->graphSpeed);
  v17 = (ksgui::Graph *)operator new(320);
  text._Myres = (unsigned int)v17;
  v18 = 0;
  LOBYTE(v56) = 7;
  if ( v17 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"GAS_GRAPH", 9u);
    ksgui::Graph::Graph(v17, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  this->graphGas = (ksgui::Graph *)v18;
  *(_DWORD *)(v18 + 284) = 1065772646;
  v19 = this->graphGas;
  LOBYTE(v56) = 3;
  v19->minY = -0.050000001;
  this->graphGas->maxValuesCount = 0;
  this->graphGas->borderColor = 0i64;
  this->graphGas->backColor = 0i64;
  *(vec3f *)&v48[20] = serieColors[0];
  ksgui::Graph::addSerie(this->graphGas, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[1];
  ksgui::Graph::addSerie(this->graphGas, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[2];
  ksgui::Graph::addSerie(this->graphGas, *(__int128 *)&v48[20]);
  ksgui::Control::addControl(this, this->graphGas);
  v20 = (ksgui::Graph *)operator new(320);
  text._Myres = (unsigned int)v20;
  v21 = 0;
  LOBYTE(v56) = 8;
  if ( v20 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"GEAR_GRAPH", 0xAu);
    ksgui::Graph::Graph(v20, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  v22 = this->sim;
  *(_DWORD *)&v48[28] = 0;
  LOBYTE(v56) = 3;
  this->graphGear = v21;
  this->graphGear->maxY = (float)Sim::getCar(v22, *(unsigned int *)&v48[28])->physicsInfo.maxGear + 2.0;
  this->graphGear->minY = -0.5;
  this->graphGear->maxValuesCount = 0;
  this->graphGear->borderColor = 0i64;
  this->graphGear->backColor = 0i64;
  *(vec3f *)&v48[20] = serieColors[0];
  ksgui::Graph::addSerie(this->graphGear, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[1];
  ksgui::Graph::addSerie(this->graphGear, *(__int128 *)&v48[20]);
  *(vec3f *)&v48[20] = serieColors[2];
  ksgui::Graph::addSerie(this->graphGear, *(__int128 *)&v48[20]);
  ksgui::Control::addControl(this, this->graphGear);
  v23 = (ksgui::CheckBox *)operator new(304);
  text._Myres = (unsigned int)v23;
  v24 = 0;
  LOBYTE(v56) = 9;
  if ( v23 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"CB_PLAYER_BEST", 0xEu);
    ksgui::CheckBox::CheckBox(v23, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  this->cbPlayerBest = v24;
  LOBYTE(v56) = 3;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Best", 4u);
  LOBYTE(v56) = 10;
  v25 = acTranslate(&result, &text);
  v26 = this->sim;
  LOBYTE(v56) = 11;
  v27 = Sim::getCar(v26, 0);
  v28 = std::operator+<wchar_t>(&v52, &v27->driverInfo.name, L" ");
  LOBYTE(v56) = 12;
  *(_DWORD *)&v48[28] = std::operator+<wchar_t>(&iname, v28, v25);
  v29 = this->cbPlayerBest;
  LOBYTE(v56) = 13;
  v29->setText(v29, *(const std::wstring **)&v48[28]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( v52._Myres >= 8 )
    operator delete(v52._Bx._Ptr);
  v52._Myres = 7;
  v52._Mysize = 0;
  v52._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v56) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::CheckBox::setCheck(this->cbPlayerBest, 1);
  *(_DWORD *)&v48[28] = this;
  *(_DWORD *)&v48[4] = &std::_Func_impl<std::_Callable_obj<_lambda_262c53f26e1cda69c2ac1ba1a0abd7fa_,0>,std::allocator<std::_Func_class<void,ksgui::OnCheckBoxChanged const &>>,void,ksgui::OnCheckBoxChanged const &>::`vftable';
  *(_DWORD *)&v48[8] = this;
  *(_DWORD *)&v48[20] = &v48[4];
  v30 = (Event<ksgui::OnListBoxItemClickedEvent> *)&this->cbPlayerBest->evOnCheckBoxChanged;
  LOBYTE(v56) = 3;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    v30,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v48[4],
    this);
  v31 = this->cbPlayerBest;
  *(vec3f *)&text._Bx._Alias[8] = serieColors[0];
  text._Myres = 1065353216;
  v31->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&text._Bx._Buf[4]);
  ksgui::Control::addControl(this, this->cbPlayerBest);
  v32 = (ksgui::CheckBox *)operator new(304);
  text._Myres = (unsigned int)v32;
  v33 = 0;
  LOBYTE(v56) = 15;
  if ( v32 )
  {
    *(_DWORD *)&v48[28] = this->gui;
    *(_DWORD *)&v48[24] = 7;
    *(_DWORD *)&v48[20] = 0;
    *(_WORD *)&v48[4] = 0;
    std::wstring::assign((std::wstring *)&v48[4], L"CB_PLAYER_CURRENT_BEST", 0x16u);
    ksgui::CheckBox::CheckBox(v32, *(std::wstring *)&v48[4], *(ksgui::GUI **)&v48[28]);
  }
  this->cbPlayerLastBest = v33;
  LOBYTE(v56) = 3;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Last", 4u);
  LOBYTE(v56) = 16;
  v34 = acTranslate(&iname, &text);
  v35 = this->sim;
  LOBYTE(v56) = 17;
  v36 = Sim::getCar(v35, 0);
  v37 = std::operator+<wchar_t>(&v52, &v36->driverInfo.name, L" ");
  LOBYTE(v56) = 18;
  *(_DWORD *)&v48[28] = std::operator+<wchar_t>(&result, v37, v34);
  v38 = this->cbPlayerLastBest;
  LOBYTE(v56) = 19;
  v38->setText(v38, *(const std::wstring **)&v48[28]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v52._Myres >= 8 )
    operator delete(v52._Bx._Ptr);
  v52._Myres = 7;
  v52._Mysize = 0;
  v52._Bx._Buf[0] = 0;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v56) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::CheckBox::setCheck(this->cbPlayerLastBest, 1);
  *(_DWORD *)&v48[28] = this;
  *(_DWORD *)&v48[4] = &std::_Func_impl<std::_Callable_obj<_lambda_48fa2377d72a9e519bfea48caaa99668_,0>,std::allocator<std::_Func_class<void,ksgui::OnCheckBoxChanged const &>>,void,ksgui::OnCheckBoxChanged const &>::`vftable';
  *(_DWORD *)&v48[8] = this;
  *(_DWORD *)&v48[20] = &v48[4];
  v39 = (Event<ksgui::OnListBoxItemClickedEvent> *)&this->cbPlayerLastBest->evOnCheckBoxChanged;
  LOBYTE(v56) = 3;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    v39,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v48[4],
    this);
  v40 = this->cbPlayerLastBest;
  *(vec3f *)&text._Bx._Alias[8] = serieColors[1];
  text._Myres = 1065353216;
  v40->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&text._Bx._Buf[4]);
  ksgui::Control::addControl(this, this->cbPlayerLastBest);
  v41 = (ksgui::Control *)operator new(280);
  text._Myres = (unsigned int)v41;
  v42 = 0;
  LOBYTE(v56) = 21;
  if ( v41 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"SELECT_OPPONENT", 0xFu);
    v50 = 1;
    *(_DWORD *)&v48[28] = this->gui;
    LOBYTE(v56) = 22;
    ksgui::Control::Control(v41, &iname, *(ksgui::GUI **)&v48[28]);
  }
  v43 = (v50 & 1) == 0;
  this->butOpponent = v42;
  v56 = 3;
  if ( !v43 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Select Opponent", 0xFu);
  LOBYTE(v56) = 24;
  *(_DWORD *)&v48[28] = acTranslate(&result, &iname);
  v44 = this->butOpponent;
  LOBYTE(v56) = 25;
  v44->setText(v44, *(const std::wstring **)&v48[28]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v56) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Control::addControl(this, this->butOpponent);
  *(_DWORD *)&v48[28] = this;
  *(_DWORD *)&v48[4] = &std::_Func_impl<std::_Callable_obj<_lambda_15c4da1adb98043da5888ad9a0ea76bf_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v48[8] = this;
  *(_DWORD *)&v48[20] = &v48[4];
  v45 = (Event<OnMouseWheelMovedEvent> *)&this->butOpponent->evClicked;
  LOBYTE(v56) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v45,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v48[4],
    this);
  v46 = this->butOpponent;
  *(vec3f *)&text._Bx._Alias[8] = serieColors[2];
  text._Myres = 1065353216;
  v47 = _mm_loadu_si128((const __m128i *)&text._Bx._Buf[4]);
  v48[28] = 0;
  v46->foreColor = (vec4f)v47;
  ComparativeTelemetry::updateBestPlayerData(this, v48[28]);
  ComparativeTelemetry::updateLastPlayerData(this, 0);
  ComparativeTelemetry::initOpponentSelectionForm(this, a2);
}
void ComparativeTelemetry::~ComparativeTelemetry(ComparativeTelemetry *this)
{
  std::vector<CTDriver> *v2; // esi
  std::vector<unsigned int> *v3; // esi
  std::vector<CTData> *v4; // esi

  v2 = &this->opponents;
  this->__vftable = (ComparativeTelemetry_vtbl *)&ComparativeTelemetry::`vftable';
  if ( this->opponents._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->opponents);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<CTDriver>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->seriesTime;
  if ( this->seriesTime._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->seriesTime);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->seriesTime._Mylast = 0;
    this->seriesTime._Myend = 0;
  }
  v4 = &this->bestData;
  if ( this->bestData._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestData);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->bestData._Mylast = 0;
    this->bestData._Myend = 0;
  }
  ksgui::Form::~Form(this);
}
ComparativeTelemetry *ComparativeTelemetry::`vector deleting destructor'(ComparativeTelemetry *this, unsigned int a2)
{
  ComparativeTelemetry::~ComparativeTelemetry(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __usercall ComparativeTelemetry::initOpponentSelectionForm(ComparativeTelemetry *this@<ecx>, unsigned int a2@<ebx>)
{
  ksgui::Form *v3; // edi
  ksgui::Form *v4; // eax
  ksgui::Form *v5; // ecx
  ComparativeTelemetry_vtbl *v6; // eax
  std::wstring *v7; // eax
  ksgui::Form *v8; // ecx
  ksgui::Form *v9; // eax
  ksgui::ListBox *v10; // edi
  int v11; // eax
  int v12; // edi
  ComparativeTelemetryRecorder *v13; // ecx
  unsigned int v14; // ebp
  int v15; // ebx
  CTDriver *v16; // eax
  CTDriver *v17; // ecx
  _BYTE v18[56]; // [esp-18h] [ebp-E0h] BYREF
  ksgui::ListBox *v19; // [esp+3Ch] [ebp-8Ch]
  ksgui::Form *v20; // [esp+40h] [ebp-88h]
  std::wstring text; // [esp+44h] [ebp-84h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-6Ch] BYREF
  ksgui::ListBoxRowData row; // [esp+74h] [ebp-54h] BYREF
  int v24; // [esp+C4h] [ebp-4h]

  v3 = (ksgui::Form *)operator new(320);
  v20 = v3;
  v24 = 0;
  if ( v3 )
  {
    *(_DWORD *)&v18[52] = 0;
    *(_DWORD *)&v18[48] = this->gui;
    *(_DWORD *)&v18[44] = 7;
    *(_DWORD *)&v18[40] = 0;
    *(_WORD *)&v18[24] = 0;
    std::wstring::assign((std::wstring *)&v18[24], L"OPPONENT_SELECTION_FORM", 0x17u);
    ksgui::Form::Form(v3, a2, *(std::wstring *)&v18[24], *(ksgui::GUI **)&v18[48], v18[52]);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = this->__vftable;
  this->osForm = v5;
  v24 = -1;
  v6->addControl(this, v5);
  ksgui::Form::setIconVisible(this->osForm, 0);
  ksgui::Control::setVisible(this->osForm, 0);
  ((void (*)(ksgui::Form *, int, int))this->osForm->setSize)(this->osForm, 1133903872, 1132068864);
  ksgui::Form::setPosition(this->osForm, 0.0, 0.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Select the record", 0x11u);
  v24 = 1;
  v7 = acTranslate(&result, &text);
  v8 = this->osForm;
  LOBYTE(v24) = 2;
  v8->formTitle->setText(v8->formTitle, v7);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v24 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  *(_DWORD *)&v18[52] = 7;
  *(_DWORD *)&v18[48] = 0;
  *(_WORD *)&v18[32] = 0;
  std::wstring::assign((std::wstring *)&v18[32], L"content/gui/ctelemetry/close.png", 0x20u);
  ksgui::Form::setIcon(this->osForm, a2, *(std::wstring *)&v18[32]);
  ksgui::Form::setIconSize(this->osForm, 23.0, 23.0);
  v9 = this->osForm;
  *(_DWORD *)&v18[52] = 368;
  v9->backColor = (vec4f)_xmm;
  v10 = (ksgui::ListBox *)operator new(*(_DWORD *)&v18[52]);
  v19 = v10;
  v24 = 3;
  if ( v10 )
  {
    *(_DWORD *)&v18[52] = 1;
    *(_DWORD *)&v18[48] = this->gui;
    *(_DWORD *)&v18[44] = 1;
    *(_DWORD *)&v18[40] = 10;
    *(_DWORD *)&v18[36] = 7;
    *(_DWORD *)&v18[32] = 0;
    *(_WORD *)&v18[16] = 0;
    std::wstring::assign((std::wstring *)&v18[16], L"OS_LISTBOX", 0xAu);
    ksgui::ListBox::ListBox(
      v10,
      *(std::wstring *)&v18[16],
      *(unsigned int *)&v18[40],
      *(unsigned int *)&v18[44],
      *(ksgui::GUI **)&v18[48],
      v18[52]);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = this->ctr;
  v24 = -1;
  if ( v13 )
    ComparativeTelemetryRecorder::getCTOpponents(v13, &this->opponents);
  ksgui::Control::setVisible(*(ksgui::Control **)(v12 + 312), 0);
  ksgui::ListBox::drawCellsBackgrounds((ksgui::ListBox *)v12, 0);
  v14 = 0;
  if ( this->opponents._Mylast - this->opponents._Myfirst )
  {
    v15 = 0;
    do
    {
      v16 = &this->opponents._Myfirst[v15];
      *(_DWORD *)&v18[52] = 7;
      *(_DWORD *)&v18[48] = 0;
      *(_WORD *)&v18[32] = 0;
      std::wstring::assign((std::wstring *)&v18[32], &v16->driverName, 0, 0xFFFFFFFF);
      ksgui::ListBoxRowData::ListBoxRowData(&row, *(std::wstring *)&v18[32]);
      v17 = this->opponents._Myfirst;
      v24 = 4;
      *(_OWORD *)&v18[40] = _xmm;
      *(_OWORD *)&v18[24] = _xmm;
      timeToString((std::wstring *)v18, v17[v15].time, 3);
      ksgui::ListBoxRowData::addData(&row, *(std::wstring *)v18, *(vec4f *)&v18[24], *(vec4f *)&v18[40]);
      ksgui::ListBox::addItem((ksgui::ListBox *)v12, &row);
      v24 = -1;
      ksgui::ListBoxRowData::~ListBoxRowData(&row);
      ++v14;
      ++v15;
    }
    while ( v14 < this->opponents._Mylast - this->opponents._Myfirst );
  }
  ksgui::Form::setPosition((ksgui::Form *)v12, 0.0, 50.0);
  (*(void (**)(int, _DWORD, _DWORD))(*(_DWORD *)v12 + 28))(
    v12,
    this->osForm->rect.right - this->osForm->rect.left,
    (float)(this->osForm->rect.bottom - this->osForm->rect.top) - 50.0);
  *(_DWORD *)&v18[52] = this;
  *(_BYTE *)(v12 + 280) = 1;
  *(_DWORD *)&v18[28] = &std::_Func_impl<std::_Callable_obj<_lambda_2b7065a4bbd033e503c86552e643968e_,0>,std::allocator<std::_Func_class<void,ksgui::OnListBoxItemClickedEvent const &>>,void,ksgui::OnListBoxItemClickedEvent const &>::`vftable';
  *(_DWORD *)&v18[32] = this;
  *(_DWORD *)&v18[44] = &v18[28];
  v24 = -1;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    (Event<ksgui::OnListBoxItemClickedEvent> *)(v12 + 288),
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v18[28],
    *(void **)&v18[52]);
  this->osForm->addControl(this->osForm, (ksgui::Control *)v12);
  ksgui::ListBox::setItemsFontSize((ksgui::ListBox *)v12, 15.0);
  *(_DWORD *)&v18[52] = this;
  *(_OWORD *)(v12 + 44) = _xmm;
  *(_OWORD *)(v12 + 60) = _xmm;
  *(_DWORD *)&v18[28] = &std::_Func_impl<std::_Callable_obj<_lambda_bf284045a6ef436797ad753c4166a82c_,0>,std::allocator<std::_Func_class<void,ksgui::OnListBoxItemClickedEvent const &>>,void,ksgui::OnListBoxItemClickedEvent const &>::`vftable';
  *(_DWORD *)&v18[32] = this;
  *(_DWORD *)&v18[44] = &v18[28];
  v24 = -1;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    (Event<ksgui::OnListBoxItemClickedEvent> *)(v12 + 300),
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v18[28],
    *(void **)&v18[52]);
}
void ComparativeTelemetry::onMouseMove(ComparativeTelemetry *this, const OnMouseMoveEvent *message)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  ComparativeTelemetry_vtbl *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+Ch] [ebp-14h]
  vec2f myPos; // [esp+10h] [ebp-10h] BYREF
  vec2f v12; // [esp+18h] [ebp-8h] BYREF
  const OnMouseMoveEvent *messagea; // [esp+24h] [ebp+4h]

  v9 = 0;
  v10 = 0;
  this->localToWorld(this, &myPos, (const vec2f *)&v9);
  v4 = (float)message->x;
  *(float *)&messagea = v4;
  if ( v4 > myPos.x && (float)((float)(this->rect.right - this->rect.left) + myPos.x) > v4 )
  {
    v5 = (float)message->y;
    if ( v5 > myPos.y && (float)((float)(this->rect.bottom - this->rect.top) + myPos.y) > v5 )
    {
      v6 = this->__vftable;
      v9 = 0;
      v10 = 0;
      v7 = (float)(*(float *)&messagea - v6->localToWorld(this, &v12, (const vec2f *)&v9)->x)
         / (float)(this->rect.right - this->rect.left);
      v8 = FLOAT_1_0;
      if ( v7 <= 1.0 )
      {
        v8 = 0.0;
        if ( v7 >= 0.0 )
          v8 = v7;
      }
      this->currentPerc = v8;
      ksgui::Form::onMouseMove(this, message);
    }
  }
}
void ComparativeTelemetry::onVisibleChanged(ComparativeTelemetry *this, bool newValue)
{
  if ( newValue )
  {
    ComparativeTelemetry::updateBestPlayerData(this, 1);
    ComparativeTelemetry::updateLastPlayerData(this, 1);
  }
}
void ComparativeTelemetry::render(ComparativeTelemetry *this, float dt)
{
  ksgui::Form *v3; // ecx
  ksgui::Control *v4; // eax
  float v5; // xmm0_4
  float v6; // ebx
  float v7; // xmm0_4
  ComparativeTelemetry_vtbl *v8; // eax
  float *v9; // esi
  int v10; // eax
  float v11; // xmm1_4
  ComparativeTelemetry_vtbl *v12; // eax
  float *v13; // esi
  int v14; // eax
  Sim *v15; // ecx
  AISpline *v16; // eax
  std::wostream *v17; // eax
  float v18; // xmm1_4
  std::wstring *v19; // esi
  Font *v20; // ebx
  ComparativeTelemetry_vtbl *v21; // edx
  float *v22; // edi
  int v23; // eax
  ksgui::Graph *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  ComparativeTelemetry_vtbl *v27; // eax
  int v28; // eax
  float v29; // ecx
  ksgui::Graph *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  ComparativeTelemetry_vtbl *v33; // eax
  int v34; // eax
  float v35; // ecx
  std::wstring *v36; // eax
  const std::wstring *v37; // eax
  Font *v38; // ecx
  float v39; // xmm0_4
  ksgui::Graph *v40; // eax
  float v41; // xmm0_4
  float v42; // xmm1_4
  ComparativeTelemetry_vtbl *v43; // eax
  int v44; // eax
  float v45; // ecx
  ksgui::Graph *v46; // eax
  float v47; // xmm0_4
  float v48; // xmm1_4
  ComparativeTelemetry_vtbl *v49; // eax
  int v50; // eax
  float v51; // ecx
  std::wstring *v52; // eax
  const std::wstring *v53; // eax
  ksgui::Graph *v54; // edx
  ksgui::Graph *v55; // eax
  float v56; // xmm0_4
  float v57; // xmm1_4
  ComparativeTelemetry_vtbl *v58; // eax
  int v59; // eax
  float v60; // ecx
  ksgui::Graph *v61; // eax
  float v62; // xmm0_4
  float v63; // xmm1_4
  ComparativeTelemetry_vtbl *v64; // eax
  int v65; // eax
  float v66; // ecx
  std::wstring *v67; // eax
  const std::wstring *v68; // eax
  ksgui::Graph *v69; // edx
  ksgui::Graph *v70; // eax
  float v71; // xmm0_4
  float v72; // xmm1_4
  ComparativeTelemetry_vtbl *v73; // eax
  int v74; // eax
  float v75; // ecx
  ksgui::Graph *v76; // eax
  float v77; // xmm0_4
  float v78; // xmm1_4
  ComparativeTelemetry_vtbl *v79; // eax
  int v80; // eax
  float v81; // ecx
  std::wstring *v82; // eax
  const std::wstring *v83; // eax
  ksgui::Graph *v84; // edx
  ksgui::Graph *v85; // eax
  float v86; // xmm1_4
  float v87; // xmm0_4
  ComparativeTelemetry_vtbl *v88; // eax
  int v89; // eax
  float v90; // ecx
  ksgui::Graph *v91; // eax
  float v92; // xmm1_4
  int v93; // xmm0_4
  ComparativeTelemetry_vtbl *v94; // eax
  int v95; // eax
  float v96; // ecx
  ksgui::Form *v97; // ecx
  int v98[3]; // [esp+DCh] [ebp-154h] BYREF
  vec2f p1; // [esp+E8h] [ebp-148h] BYREF
  vec2f l1; // [esp+F0h] [ebp-140h] BYREF
  vec2f l2; // [esp+F8h] [ebp-138h] BYREF
  vec2f v102; // [esp+100h] [ebp-130h] BYREF
  int v103; // [esp+108h] [ebp-128h] BYREF
  float z; // [esp+10Ch] [ebp-124h] BYREF
  vec2f v1; // [esp+110h] [ebp-120h] BYREF
  vec2f v2; // [esp+118h] [ebp-118h]
  int v107; // [esp+120h] [ebp-110h]
  std::wostream _Ostr; // [esp+124h] [ebp-10Ch] BYREF
  int v109[3]; // [esp+17Ch] [ebp-B4h] BYREF
  int v110[18]; // [esp+188h] [ebp-A8h] BYREF
  vec2f v111; // [esp+1D0h] [ebp-60h] BYREF
  std::wstring text; // [esp+1D8h] [ebp-58h] BYREF
  std::wstring result; // [esp+1F0h] [ebp-40h] BYREF
  std::wstring v114; // [esp+208h] [ebp-28h] BYREF
  int v115; // [esp+220h] [ebp-10h]
  int v116; // [esp+22Ch] [ebp-4h]

  l2.x = 0.0;
  ksgui::Form::setPosition(this->osForm, 0.0, 0.0);
  ComparativeTelemetry::updateBestPlayerData(this, 0);
  ComparativeTelemetry::updateLastPlayerData(this, 0);
  ((void (*)(ksgui::Graph *, _DWORD, _DWORD))this->graphBrake->setSize)(
    this->graphBrake,
    this->rect.right - this->rect.left,
    (float)(this->rect.bottom - this->rect.top) * 0.15000001);
  ((void (*)(ksgui::Graph *, _DWORD, _DWORD))this->graphSpeed->setSize)(
    this->graphSpeed,
    this->rect.right - this->rect.left,
    (float)(this->rect.bottom - this->rect.top) * 0.40000001);
  ((void (*)(ksgui::Graph *, _DWORD, _DWORD))this->graphGas->setSize)(
    this->graphGas,
    this->rect.right - this->rect.left,
    (float)(this->rect.bottom - this->rect.top) * 0.15000001);
  ((void (*)(ksgui::Graph *, _DWORD, _DWORD))this->graphGear->setSize)(
    this->graphGear,
    this->rect.right - this->rect.left,
    (float)(this->rect.bottom - this->rect.top) * 0.15000001);
  ((void (*)(ksgui::CheckBox *, _DWORD, int))this->cbPlayerBest->setSize)(
    this->cbPlayerBest,
    (float)(this->rect.right - this->rect.left) * 0.33333334,
    1095761920);
  ((void (*)(ksgui::CheckBox *, _DWORD, int))this->cbPlayerLastBest->setSize)(
    this->cbPlayerLastBest,
    (float)(this->rect.right - this->rect.left) * 0.33333334,
    1095761920);
  ((void (*)(ksgui::Control *, _DWORD, int))this->butOpponent->setSize)(
    this->butOpponent,
    (float)(this->rect.right - this->rect.left) * 0.33333334,
    1103626240);
  ksgui::Form::setPosition((ksgui::Form *)this->graphBrake, 0.0, 0.0);
  ksgui::Form::setPosition((ksgui::Form *)this->graphSpeed, 0.0, this->graphBrake->rect.bottom);
  ksgui::Form::setPosition((ksgui::Form *)this->graphGas, 0.0, this->graphSpeed->rect.bottom);
  ksgui::Form::setPosition((ksgui::Form *)this->graphGear, 0.0, this->graphGas->rect.bottom);
  ksgui::Form::setPosition((ksgui::Form *)this->cbPlayerBest, 10.0, this->graphGear->rect.bottom + 8.0);
  ksgui::Form::setPosition((ksgui::Form *)this->cbPlayerLastBest, 10.0, this->cbPlayerBest->rect.top + 25.0);
  ksgui::Form::setPosition((ksgui::Form *)this->butOpponent, 10.0, this->cbPlayerLastBest->rect.top + 25.0);
  v3 = this->osForm;
  v4 = this->butOpponent;
  ksgui::Form::setPosition(
    v3,
    (float)((float)((float)(v4->rect.right - v4->rect.left) * 0.5) + v4->rect.left)
  - (float)((float)(v3->rect.right - v3->rect.left) * 0.5),
    v4->rect.top - (float)(v3->rect.bottom - v3->rect.top));
  FormOpenVR::render((CarLabel *)this, dt);
  v5 = this->currentPerc;
  v6 = *(float *)&this->gui->graphics->gl;
  l1.x = v6;
  if ( v5 >= 0.0 )
  {
    GLRenderer::color4f((GLRenderer *)LODWORD(v6), 1.0, 1.0, 0.0, 1.0);
    GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
    v7 = this->rect.right - this->rect.left;
    v8 = this->__vftable;
    v1.y = 0.0;
    v1.x = v7 * this->currentPerc;
    v9 = (float *)((int (*)(ComparativeTelemetry *, vec2f *))v8->localToWorld)(this, &l2);
    v10 = ((int (*)(ComparativeTelemetry *))this->localToWorld)(this);
    GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), *v9, *(float *)(v10 + 4), COERCE_FLOAT((vec2f *)&l2.y));
    v11 = (float)(this->rect.right - this->rect.left) * this->currentPerc;
    v12 = this->__vftable;
    v1.x = this->graphGear->rect.bottom;
    z = v11;
    v13 = (float *)((int (*)(ComparativeTelemetry *, float *))v12->localToWorld)(this, &l1.y);
    v14 = ((int (*)(ComparativeTelemetry *, vec2f *, int *, _DWORD))this->localToWorld)(this, &p1, &v103, 0);
    GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), *v13, *(float *)(v14 + 4), COERCE_FLOAT(&z));
    GLRenderer::end((GLRenderer *)LODWORD(v6));
    Font::setColor(this->font._Ptr, 1.0, 1.0, 0.0, 1.0);
    LODWORD(v1.y) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)_Ostr.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v109);
    v115 = 0;
    LODWORD(p1.y) = 1;
    std::wiostream::basic_iostream<wchar_t>(&v1.y, &_Ostr.gap0[8], 0);
    v115 = 1;
    *(_DWORD *)((char *)&v1.y + *(_DWORD *)(LODWORD(v1.y) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v1.x + *(_DWORD *)(LODWORD(v1.y) + 4)) = *(_DWORD *)(LODWORD(v1.y) + 4) - 104;
    std::wstreambuf::wstreambuf(&_Ostr.gap0[8]);
    *(_DWORD *)&_Ostr.gap0[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&_Ostr.gap0[64] = 0;
    *(_DWORD *)&_Ostr.gap0[68] = 0;
    v15 = this->sim;
    v115 = 3;
    v16 = TrackAvatar::getAISpline(v15->track);
    p1.y = Spline::length(&v16->spline) * this->currentPerc;
    v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&_Ostr, "Km : ");
    std::wostream::operator<<(v17);
    v18 = (float)(this->rect.right - this->rect.left) - 75.0;
    v98[1] = LODWORD(this->cbPlayerLastBest->rect.top);
    *(float *)v98 = v18;
    v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&v1.y,
            (std::wstring *)&text._Bx._Alias[12]);
    v20 = this->font._Ptr;
    v21 = this->__vftable;
    LOBYTE(v115) = 4;
    v22 = (float *)v21->localToWorld(this, (vec2f *)&l1.y, (const vec2f *)v98);
    v23 = ((int (*)(ComparativeTelemetry *, float *, int *, std::wstring *, int, _DWORD))this->localToWorld)(
            this,
            &l2.y,
            v98,
            v19,
            1065353216,
            0);
    Font::blitString(v20, *v22 - 20.0, *(float *)(v23 + 4), (const std::wstring *)&z, 0.0, (eFontAlign)&v1);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v116 = -1;
    *(int *)((char *)&v107 + *(_DWORD *)(v107 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v2.y + *(_DWORD *)(v107 + 4)) = *(_DWORD *)(v107 + 4) - 104;
    *(_DWORD *)&_Ostr.gap0[20] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&_Ostr.gap0[20]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&_Ostr.gap0[20]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&_Ostr.gap0[28]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v110);
    v6 = l1.x;
  }
  ComparativeTelemetry::renderPlayerStats(this);
  Font::setColor(this->font._Ptr, 0.5, 0.5, 0.5, 1.0);
  GLRenderer::color4f((GLRenderer *)LODWORD(v6), 0.5, 0.5, 0.5, 1.0);
  GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
  v24 = this->graphBrake;
  v25 = v24->rect.left;
  v26 = v24->rect.top;
  v27 = this->__vftable;
  p1.x = v25;
  p1.y = v26;
  v28 = (int)v27->localToWorld(this, &v102, &p1);
  v29 = *(float *)v28;
  l1.y = *(float *)(v28 + 4);
  l1.x = v29;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v29, l1.y, 0.0);
  v30 = this->graphBrake;
  v31 = v30->rect.right;
  v32 = v30->rect.top;
  v33 = this->__vftable;
  p1.x = v31;
  p1.y = v32;
  v34 = (int)v33->localToWorld(this, &v102, &p1);
  v35 = *(float *)v34;
  l2.y = *(float *)(v34 + 4);
  l2.x = v35;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v35, l2.y, 0.0);
  GLRenderer::end((GLRenderer *)LODWORD(v6));
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"BRAKE", 5u);
  v116 = 5;
  v36 = acTranslate(&result, &text);
  LOBYTE(v116) = 6;
  v37 = std::operator+<wchar_t>(&v114, L" ", v36);
  v38 = this->font._Ptr;
  v39 = this->graphBrake->rect.bottom - this->graphBrake->rect.top;
  LOBYTE(v116) = 7;
  Font::blitString(v38, l1.x, (float)(v39 * 0.5) + l1.y, v37, 1.0, eAlignLeft);
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  v114._Myres = 7;
  v114._Mysize = 0;
  v114._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v116 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
  v40 = this->graphSpeed;
  v41 = v40->rect.left;
  v42 = v40->rect.top;
  v43 = this->__vftable;
  p1.x = v41;
  p1.y = v42;
  v44 = (int)v43->localToWorld(this, &v102, &p1);
  v45 = *(float *)v44;
  l1.y = *(float *)(v44 + 4);
  l1.x = v45;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v45, l1.y, 0.0);
  v46 = this->graphSpeed;
  v47 = v46->rect.right;
  v48 = v46->rect.top;
  v49 = this->__vftable;
  p1.x = v47;
  p1.y = v48;
  v50 = (int)v49->localToWorld(this, &v102, &p1);
  v51 = *(float *)v50;
  l2.y = *(float *)(v50 + 4);
  l2.x = v51;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v51, l2.y, 0.0);
  GLRenderer::end((GLRenderer *)LODWORD(v6));
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"SPEED", 5u);
  v116 = 8;
  v52 = acTranslate(&v114, &text);
  LOBYTE(v116) = 9;
  v53 = std::operator+<wchar_t>(&result, L" ", v52);
  v54 = this->graphSpeed;
  LOBYTE(v116) = 10;
  Font::blitString(
    this->font._Ptr,
    l1.x,
    (float)((float)(v54->rect.bottom - v54->rect.top) * 0.5) + l1.y,
    v53,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  v114._Myres = 7;
  v114._Mysize = 0;
  v114._Bx._Buf[0] = 0;
  v116 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
  v55 = this->graphGas;
  v56 = v55->rect.left;
  v57 = v55->rect.top;
  v58 = this->__vftable;
  p1.x = v56;
  p1.y = v57;
  v59 = (int)v58->localToWorld(this, &v102, &p1);
  v60 = *(float *)v59;
  l1.y = *(float *)(v59 + 4);
  l1.x = v60;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v60, l1.y, 0.0);
  v61 = this->graphGas;
  v62 = v61->rect.right;
  v63 = v61->rect.top;
  v64 = this->__vftable;
  p1.x = v62;
  p1.y = v63;
  v65 = (int)v64->localToWorld(this, &v102, &p1);
  v66 = *(float *)v65;
  l2.y = *(float *)(v65 + 4);
  l2.x = v66;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v66, l2.y, 0.0);
  GLRenderer::end((GLRenderer *)LODWORD(v6));
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"GAS", 3u);
  v116 = 11;
  v67 = acTranslate(&v114, &text);
  LOBYTE(v116) = 12;
  v68 = std::operator+<wchar_t>(&result, L" ", v67);
  v69 = this->graphGas;
  LOBYTE(v116) = 13;
  Font::blitString(
    this->font._Ptr,
    l1.x,
    (float)((float)(v69->rect.bottom - v69->rect.top) * 0.5) + l1.y,
    v68,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  v114._Myres = 7;
  v114._Mysize = 0;
  v114._Bx._Buf[0] = 0;
  v116 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
  v70 = this->graphGear;
  v71 = v70->rect.left;
  v72 = v70->rect.top;
  v73 = this->__vftable;
  p1.x = v71;
  p1.y = v72;
  v74 = (int)v73->localToWorld(this, &v102, &p1);
  v75 = *(float *)v74;
  l1.y = *(float *)(v74 + 4);
  l1.x = v75;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v75, l1.y, 0.0);
  v76 = this->graphGear;
  v77 = v76->rect.right;
  v78 = v76->rect.top;
  v79 = this->__vftable;
  p1.x = v77;
  p1.y = v78;
  v80 = (int)v79->localToWorld(this, &v102, &p1);
  v81 = *(float *)v80;
  l2.y = *(float *)(v80 + 4);
  l2.x = v81;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v81, l2.y, 0.0);
  GLRenderer::end((GLRenderer *)LODWORD(v6));
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"GEAR", 4u);
  v116 = 14;
  v82 = acTranslate(&v114, &text);
  LOBYTE(v116) = 15;
  v83 = std::operator+<wchar_t>(&result, L" ", v82);
  v84 = this->graphGear;
  LOBYTE(v116) = 16;
  Font::blitString(
    this->font._Ptr,
    l1.x,
    (float)((float)(v84->rect.bottom - v84->rect.top) * 0.5) + l1.y,
    v83,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  v114._Myres = 7;
  v114._Mysize = 0;
  v114._Bx._Buf[0] = 0;
  v116 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  GLRenderer::begin((GLRenderer *)LODWORD(v6), eLines, 0);
  v85 = this->graphGear;
  v86 = v85->rect.bottom;
  v87 = v85->rect.left;
  v88 = this->__vftable;
  p1.x = v87;
  p1.y = v86;
  v89 = (int)v88->localToWorld(this, &v102, &p1);
  v90 = *(float *)v89;
  l1.y = *(float *)(v89 + 4);
  l1.x = v90;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v90, l1.y, 0.0);
  v91 = this->graphGear;
  v92 = v91->rect.bottom;
  v93 = LODWORD(v91->rect.right);
  v94 = this->__vftable;
  v103 = v93;
  z = v92;
  v95 = (int)v94->localToWorld(this, &v111, (const vec2f *)&v103);
  v96 = *(float *)v95;
  l2.y = *(float *)(v95 + 4);
  l2.x = v96;
  GLRenderer::vertex3f((GLRenderer *)LODWORD(v6), v96, l2.y, 0.0);
  GLRenderer::end((GLRenderer *)LODWORD(v6));
  v97 = this->osForm;
  if ( v97->visible )
    ((void (__stdcall *)(_DWORD))v97->render)(LODWORD(dt));
}
void ComparativeTelemetry::renderPlayerStats(ComparativeTelemetry *this)
{
  int v2; // ebx
  ksgui::CheckBox *v3; // eax
  Font *v4; // ecx
  float v5; // xmm0_4
  int i; // edi
  ComparativeTelemetry_vtbl *v7; // eax
  ksgui::ValueSerie *v8; // ecx
  const std::wstring *v9; // eax
  const std::wstring *v10; // eax
  Font *v11; // ecx
  const std::wstring *v12; // eax
  const std::wstring *v13; // eax
  Font *v14; // ecx
  std::wstring *v15; // eax
  float v16; // xmm0_4
  int v17; // eax
  std::wostream *v18; // eax
  ComparativeTelemetry_vtbl *v19; // eax
  const std::wstring *v20; // eax
  Font *v21; // ecx
  std::wstring *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  ComparativeTelemetry_vtbl *v25; // eax
  const std::wstring *v26; // eax
  Font *v27; // ecx
  std::wstring *v28; // eax
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  ComparativeTelemetry_vtbl *v31; // eax
  const std::wstring *v32; // eax
  Font *v33; // ecx
  std::wstring *v34; // eax
  std::wostream *v35; // eax
  ComparativeTelemetry_vtbl *v36; // eax
  const std::wstring *v37; // eax
  Font *v38; // ecx
  const char *b; // [esp+4Ch] [ebp-1A4h]
  int ba; // [esp+4Ch] [ebp-1A4h]
  const char *bb; // [esp+4Ch] [ebp-1A4h]
  int bc; // [esp+4Ch] [ebp-1A4h]
  const char *bd; // [esp+4Ch] [ebp-1A4h]
  const char *a; // [esp+50h] [ebp-1A0h]
  vec2f position; // [esp+6Ch] [ebp-184h] BYREF
  float v46; // [esp+74h] [ebp-17Ch]
  double gear; // [esp+78h] [ebp-178h]
  int v48; // [esp+80h] [ebp-170h]
  float v49; // [esp+84h] [ebp-16Ch]
  float v50; // [esp+88h] [ebp-168h]
  int v51; // [esp+8Ch] [ebp-164h]
  float v52; // [esp+90h] [ebp-160h]
  int v53[2]; // [esp+94h] [ebp-15Ch] BYREF
  int v54[3]; // [esp+9Ch] [ebp-154h] BYREF
  int v55; // [esp+A8h] [ebp-148h] BYREF
  int v56[3]; // [esp+ACh] [ebp-144h] BYREF
  int v57; // [esp+B8h] [ebp-138h] BYREF
  float v58; // [esp+BCh] [ebp-134h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v59; // [esp+C0h] [ebp-130h] BYREF
  int v60[3]; // [esp+170h] [ebp-80h] BYREF
  int v61; // [esp+17Ch] [ebp-74h] BYREF
  int v62; // [esp+180h] [ebp-70h] BYREF
  int v63[3]; // [esp+188h] [ebp-68h] BYREF
  std::wstring text; // [esp+194h] [ebp-5Ch] BYREF
  std::wstring v65; // [esp+1ACh] [ebp-44h] BYREF
  std::wstring result; // [esp+1C4h] [ebp-2Ch] BYREF
  int v67; // [esp+1ECh] [ebp-4h]

  v2 = 0;
  LODWORD(gear) = 0;
  if ( this->currentPerc != -1.0 )
  {
    v3 = this->cbPlayerBest;
    v4 = this->font._Ptr;
    v46 = v3->rect.top;
    v5 = this->rect.right - this->rect.left;
    *(float *)v53 = v5 * 0.34999999;
    v49 = v5 * 0.47;
    v52 = v5 * 0.58999997;
    v50 = v5 * 0.72000003;
    *(float *)&v51 = v5 * 0.83999997;
    Font::setColor(v4, 1.0, 1.0, 1.0, 1.0);
    for ( i = 0; i < ksgui::Graph::getSeriesCount(this->graphSpeed); ++i )
    {
      Font::setColor(this->font._Ptr, serieColors[i].x, serieColors[i].y, serieColors[i].z, 1.0);
      *(_DWORD *)v59.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v59.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v59.gap68);
      v67 = 0;
      v2 |= 1u;
      LODWORD(gear) = v2;
      std::wiostream::basic_iostream<wchar_t>(&v59, &v59.gap10[8], 0);
      v67 = 1;
      *(_DWORD *)&v59.gap0[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v58 + *(_DWORD *)(*(_DWORD *)v59.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v59.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v59.gap10[8]);
      *(_DWORD *)&v59.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v59.gap10[64] = 0;
      *(_DWORD *)&v59.gap10[68] = 0;
      v7 = this->__vftable;
      v55 = v53[0];
      v67 = 3;
      *(float *)v56 = v46;
      v7->localToWorld(this, &position, (const vec2f *)&v55);
      v8 = this->graphSpeed->series._Myfirst[i];
      if ( (((char *)v8->values._Mylast - (char *)v8->values._Myfirst) & 0xFFFFFFFC) != 0 )
      {
        v12 = timeToString(&v65, this->seriesTime._Myfirst[i], 3);
        LOBYTE(v67) = 10;
        std::operator<<<wchar_t>((std::wostream *)v59.gap10, v12);
        LOBYTE(v67) = 3;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v65);
        v14 = this->font._Ptr;
        LOBYTE(v67) = 11;
        Font::blitString(v14, position.x, position.y, v13, 1.0, eAlignLeft);
        LOBYTE(v67) = 3;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, word_17BE9D8, 0);
        LOBYTE(v67) = 12;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
        v15 = &text;
        if ( text._Myres >= 8 )
          v15 = (std::wstring *)text._Bx._Ptr;
        std::wstringbuf::_Init((std::wstringbuf *)&v59.gap10[8], v15->_Bx._Buf, text._Mysize, *(int *)&v59.gap10[68]);
        LOBYTE(v67) = 3;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        v16 = this->currentPerc;
        if ( Speed::useMPH )
        {
          a = "Mph";
          gear = ksgui::Graph::getValuesAtPercentage(this->graphSpeed, i, v16) * 0.6213727366498067;
          v17 = (int)gear;
        }
        else
        {
          a = "Km/h";
          v17 = (int)ksgui::Graph::getValuesAtPercentage(this->graphSpeed, i, v16);
        }
        v18 = (std::wostream *)std::wostream::operator<<(v59.gap10, v17);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v18, b);
        v19 = this->__vftable;
        v56[0] = v48;
        v56[1] = LODWORD(position.y);
        position = *(vec2f *)((int (*)(ComparativeTelemetry *, int *, int *, const char *))v19->localToWorld)(
                               this,
                               &v62,
                               v56,
                               a);
        v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v65);
        v21 = this->font._Ptr;
        LOBYTE(v67) = 13;
        Font::blitString(v21, position.x, position.y, v20, 1.0, eAlignLeft);
        LOBYTE(v67) = 3;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, word_17BE9D8, 0);
        LOBYTE(v67) = 14;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
        v22 = &text;
        if ( text._Myres >= 8 )
          v22 = (std::wstring *)text._Bx._Ptr;
        std::wstringbuf::_Init((std::wstringbuf *)&v59.gap10[8], v22->_Bx._Buf, text._Mysize, *(int *)&v59.gap10[68]);
        LOBYTE(v67) = 3;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        *(float *)&gear = ksgui::Graph::getValuesAtPercentage(this->graphGas, i, this->currentPerc) * 100.0;
        ba = (int)*(float *)&gear;
        v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v59.gap10, "T : ");
        v24 = (std::wostream *)std::wostream::operator<<(v23, ba);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v24, bb);
        v25 = this->__vftable;
        v53[0] = v51;
        v53[1] = LODWORD(position.y);
        position = *(vec2f *)((int (*)(ComparativeTelemetry *, int *, int *, const char *))v25->localToWorld)(
                               this,
                               v60,
                               v53,
                               " %");
        v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v65);
        v27 = this->font._Ptr;
        LOBYTE(v67) = 15;
        Font::blitString(v27, position.x, position.y, v26, 1.0, eAlignLeft);
        LOBYTE(v67) = 3;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, word_17BE9D8, 0);
        LOBYTE(v67) = 16;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
        v28 = &text;
        if ( text._Myres >= 8 )
          v28 = (std::wstring *)text._Bx._Ptr;
        std::wstringbuf::_Init((std::wstringbuf *)&v59.gap10[8], v28->_Bx._Buf, text._Mysize, *(int *)&v59.gap10[68]);
        LOBYTE(v67) = 3;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        *(float *)&gear = ksgui::Graph::getValuesAtPercentage(this->graphBrake, i, this->currentPerc) * 100.0;
        bc = (int)*(float *)&gear;
        v29 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v59.gap10, "B : ");
        v30 = (std::wostream *)std::wostream::operator<<(v29, bc);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v30, bd);
        v31 = this->__vftable;
        *(float *)v54 = v49;
        v54[1] = LODWORD(position.y);
        position = *(vec2f *)((int (*)(ComparativeTelemetry *, int *, int *, const char *))v31->localToWorld)(
                               this,
                               v63,
                               v54,
                               " %");
        v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v65);
        v33 = this->font._Ptr;
        LOBYTE(v67) = 17;
        Font::blitString(v33, position.x, position.y, v32, 1.0, eAlignLeft);
        LOBYTE(v67) = 3;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, word_17BE9D8, 0);
        LOBYTE(v67) = 18;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
        v34 = &text;
        if ( text._Myres >= 8 )
          v34 = (std::wstring *)text._Bx._Ptr;
        std::wstringbuf::_Init((std::wstringbuf *)&v59.gap10[8], v34->_Bx._Buf, text._Mysize, *(int *)&v59.gap10[68]);
        LOBYTE(v67) = 3;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        *(float *)&gear = ksgui::Graph::getValuesAtPercentage(this->graphGear, i, this->currentPerc);
        if ( *(float *)&gear > 1.0 )
        {
          v35 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v59.gap10, "G :");
          std::wostream::operator<<(v35);
        }
        else
        {
          std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v59.gap10, "G :N");
        }
        v36 = this->__vftable;
        v57 = v51;
        v58 = v46;
        position = *v36->localToWorld(this, (vec2f *)&v61, (const vec2f *)&v57);
        v37 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v59, &v65);
        v38 = this->font._Ptr;
        LOBYTE(v67) = 19;
        Font::blitString(v38, position.x, position.y, v37, 1.0, eAlignLeft);
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        v65._Myres = 7;
        v65._Mysize = 0;
        v65._Bx._Buf[0] = 0;
        v46 = v46 + 25.0;
        goto LABEL_54;
      }
      v46 = v46 + 25.0;
      if ( i )
      {
        if ( i == 1 && this->cbPlayerLastBest->boxValue )
        {
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"NO RECORD FOUND", 0xFu);
          LOBYTE(v67) = 6;
          v9 = acTranslate(&result, &text);
          LOBYTE(v67) = 7;
          goto LABEL_10;
        }
      }
      else if ( this->cbPlayerBest->boxValue )
      {
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, L"NO RECORD FOUND", 0xFu);
        LOBYTE(v67) = 4;
        v9 = acTranslate(&result, &text);
        LOBYTE(v67) = 5;
LABEL_10:
        Font::blitString(this->font._Ptr, position.x, position.y, v9, 1.0, eAlignLeft);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        LOBYTE(v67) = 3;
        result._Bx._Buf[0] = 0;
        result._Mysize = 0;
        result._Myres = 7;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        goto LABEL_14;
      }
LABEL_14:
      if ( i == 2 )
      {
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::assign(&text, L"NO RECORD FOUND", 0xFu);
        LOBYTE(v67) = 8;
        v10 = acTranslate(&result, &text);
        v11 = this->font._Ptr;
        LOBYTE(v67) = 9;
        Font::blitString(v11, position.x, position.y, v10, 1.0, eAlignLeft);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
      }
LABEL_54:
      v67 = -1;
      *(_DWORD *)&v59.gap0[*(_DWORD *)(*(_DWORD *)v59.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v58 + *(_DWORD *)(*(_DWORD *)v59.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v59.gap0 + 4) - 104;
      *(_DWORD *)&v59.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v59.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v59.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v59.gap68);
    }
  }
}
void ComparativeTelemetry::updateBestPlayerData(ComparativeTelemetry *this, bool force)
{
  ComparativeTelemetryRecorder *v3; // ecx
  unsigned int *v4; // esi
  unsigned int *v5; // esi
  std::vector<CTData> *v6; // eax
  ComparativeTelemetryRecorder *v7; // ecx
  std::vector<CTData> *v8; // eax
  unsigned int v9; // ebp
  CTData *v10; // edi
  int v11; // esi
  std::vector<CTData> bestPlayer; // [esp+18h] [ebp-18h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  v3 = this->ctr;
  if ( v3 )
  {
    if ( ComparativeTelemetryRecorder::getBestTime(v3) != -1 )
    {
      v4 = this->seriesTime._Myfirst;
      if ( *v4 != ComparativeTelemetryRecorder::getBestTime(this->ctr) || force )
      {
        v5 = this->seriesTime._Myfirst;
        *v5 = ComparativeTelemetryRecorder::getBestTime(this->ctr);
        v6 = ComparativeTelemetryRecorder::getBestTimeData(this->ctr);
        std::vector<CTData>::vector<CTData>(&bestPlayer, v6);
        v7 = this->ctr;
        v13 = 0;
        v8 = ComparativeTelemetryRecorder::getBestTimeData(v7);
        std::vector<CTData>::operator=(
          (std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element> > *)&this->bestData,
          (const std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element> > *)v8);
        this->graphBrake->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphSpeed->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGas->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGear->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        ksgui::Graph::clearSerie(this->graphBrake, 0);
        ksgui::Graph::clearSerie(this->graphSpeed, 0);
        ksgui::Graph::clearSerie(this->graphGas, 0);
        ksgui::Graph::clearSerie(this->graphGear, 0);
        this->graphBrake->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        v9 = 0;
        this->graphSpeed->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGas->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGear->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        v10 = bestPlayer._Myfirst;
        if ( bestPlayer._Mylast - bestPlayer._Myfirst )
        {
          v11 = 0;
          do
          {
            ksgui::Graph::addValue(this->graphBrake, 0, v10[v11].brake);
            ksgui::Graph::addValue(this->graphSpeed, 0, v10[v11].speed);
            ksgui::Graph::addValue(this->graphGas, 0, v10[v11].gas);
            ksgui::Graph::addValue(this->graphGear, 0, (float)v10[v11].gear);
            v10 = bestPlayer._Myfirst;
            ++v9;
            ++v11;
          }
          while ( v9 < bestPlayer._Mylast - bestPlayer._Myfirst );
        }
        v13 = -1;
        if ( v10 )
        {
          std::_Container_base0::_Orphan_all(&bestPlayer);
          operator delete(bestPlayer._Myfirst);
        }
      }
    }
  }
}
void ComparativeTelemetry::updateLastPlayerData(ComparativeTelemetry *this, bool force)
{
  ComparativeTelemetryRecorder *v3; // ecx
  unsigned int *v4; // esi
  unsigned int *v5; // esi
  std::vector<CTData> *v6; // eax
  ksgui::Graph *v7; // ecx
  unsigned int v8; // ebp
  CTData *v9; // ebx
  int v10; // esi
  std::vector<CTData> bestPlayer; // [esp+18h] [ebp-18h] BYREF
  int v12; // [esp+2Ch] [ebp-4h]

  v3 = this->ctr;
  if ( v3 )
  {
    if ( ComparativeTelemetryRecorder::getLastTime(v3) != -1 )
    {
      v4 = this->seriesTime._Myfirst;
      if ( v4[1] != ComparativeTelemetryRecorder::getLastTime(this->ctr) || force )
      {
        v5 = this->seriesTime._Myfirst;
        v5[1] = ComparativeTelemetryRecorder::getLastTime(this->ctr);
        v6 = ComparativeTelemetryRecorder::getLastTimeData(this->ctr);
        std::vector<CTData>::vector<CTData>(&bestPlayer, v6);
        v7 = this->graphBrake;
        v12 = 0;
        ksgui::Graph::clearSerie(v7, 1u);
        ksgui::Graph::clearSerie(this->graphSpeed, 1u);
        ksgui::Graph::clearSerie(this->graphGas, 1u);
        ksgui::Graph::clearSerie(this->graphGear, 1u);
        v8 = 0;
        this->graphBrake->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphSpeed->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGas->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        this->graphGear->maxValuesCount = bestPlayer._Mylast - bestPlayer._Myfirst;
        v9 = bestPlayer._Myfirst;
        if ( bestPlayer._Mylast - bestPlayer._Myfirst )
        {
          v10 = 0;
          do
          {
            ksgui::Graph::addValue(this->graphBrake, 1u, v9[v10].brake);
            ksgui::Graph::addValue(this->graphSpeed, 1u, v9[v10].speed);
            ksgui::Graph::addValue(this->graphGas, 1u, v9[v10].gas);
            ksgui::Graph::addValue(this->graphGear, 1u, (float)v9[v10].gear);
            v9 = bestPlayer._Myfirst;
            ++v8;
            ++v10;
          }
          while ( v8 < bestPlayer._Mylast - bestPlayer._Myfirst );
        }
        v12 = -1;
        if ( v9 )
        {
          std::_Container_base0::_Orphan_all(&bestPlayer);
          operator delete(bestPlayer._Myfirst);
        }
      }
    }
  }
}
