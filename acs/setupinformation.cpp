#include "setupinformation.h"
void SetupInformation::SetupInformation(SetupInformation *this, Sim *aSim)
{
  Game *v3; // eax
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  Sim *v7; // eax
  Texture *v8; // eax
  CarInfoFront *v9; // eax
  CarInfoFront *v10; // eax
  CarInfoRear *v11; // eax
  CarInfoRear *v12; // eax
  ksgui::Label *v13; // edi
  ksgui::Label *v14; // eax
  std::wstring *v15; // eax
  ksgui::Label *v16; // ecx
  Font *v17; // edi
  ksgui::Label *v18; // eax
  std::wstring *v19; // eax
  ksgui::Label *v20; // ecx
  std::wstring v21; // [esp-Ch] [ebp-B0h] BYREF
  float h; // [esp+Ch] [ebp-98h]
  std::shared_ptr<Font> _Right; // [esp+20h] [ebp-84h] BYREF
  void *v24; // [esp+28h] [ebp-7Ch]
  SetupInformation *v25; // [esp+2Ch] [ebp-78h]
  std::wstring iname; // [esp+30h] [ebp-74h] BYREF
  std::wstring text; // [esp+48h] [ebp-5Ch] BYREF
  std::wstring v28; // [esp+60h] [ebp-44h] BYREF
  Texture result; // [esp+78h] [ebp-2Ch] BYREF
  int v30; // [esp+A0h] [ebp-4h]

  v25 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"SETUP_INFORMATION", 0x11u);
  v3 = aSim->game;
  v30 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (SetupInformation_vtbl *)&SetupInformation::`vftable';
  this->sim = aSim;
  this->carView.kid = 0;
  this->carView.fileName._Myres = 7;
  this->carView.fileName._Mysize = 0;
  this->carView.fileName._Bx._Buf[0] = 0;
  LOBYTE(v30) = 3;
  ksgui::Control::setSize(this, 470.0, 600.0);
  v4 = (Font *)operator new(24);
  v24 = v4;
  LOBYTE(v30) = 4;
  if ( v4 )
    Font::Font(v4, eFontProportional, 14.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v30) = 3;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v6 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  this->backColor = (vec4f)_xmm;
  *(_WORD *)&this->drawBorder = 257;
  LODWORD(h) = 33;
  v21._Myres = (unsigned int)L"content/gui/setupApps/carView.png";
  this->borderColor = (vec4f)_xmm;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)v21._Myres, LODWORD(h));
  v7 = this->sim;
  LOBYTE(v30) = 5;
  v8 = ResourceStore::getTexture(v7->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->carView.kid = v8->kid;
  LOBYTE(v30) = 6;
  if ( &this->carView.fileName != &v8->fileName )
    std::wstring::assign(&this->carView.fileName, &v8->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v30) = 5;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v30) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v9 = (CarInfoFront *)operator new(24);
  if ( v9 )
  {
    v9->frontTemperature = 0;
    v9->frontCamber = 0;
    v9->frontCaster = 0;
    v9->frontPressure = 0;
    v9->frontToe = 0;
    v9->grainBlister = 0;
  }
  else
  {
    v9 = 0;
  }
  this->LF = v9;
  SetupInformation::setFrontValues(this, v9, 20.0, 50.0);
  ksgui::Control::addControl(this, this->LF->frontCamber);
  ksgui::Control::addControl(this, this->LF->frontCaster);
  ksgui::Control::addControl(this, this->LF->frontPressure);
  ksgui::Control::addControl(this, this->LF->frontTemperature);
  ksgui::Control::addControl(this, this->LF->frontToe);
  ksgui::Control::addControl(this, this->LF->grainBlister);
  v10 = (CarInfoFront *)operator new(24);
  if ( v10 )
  {
    v10->frontTemperature = 0;
    v10->frontCamber = 0;
    v10->frontCaster = 0;
    v10->frontPressure = 0;
    v10->frontToe = 0;
    v10->grainBlister = 0;
  }
  else
  {
    v10 = 0;
  }
  this->RF = v10;
  SetupInformation::setFrontValues(this, v10, 250.0, 50.0);
  ksgui::Control::addControl(this, this->RF->frontCamber);
  ksgui::Control::addControl(this, this->RF->frontCaster);
  ksgui::Control::addControl(this, this->RF->frontPressure);
  ksgui::Control::addControl(this, this->RF->frontTemperature);
  ksgui::Control::addControl(this, this->RF->frontToe);
  ksgui::Control::addControl(this, this->RF->grainBlister);
  v11 = (CarInfoRear *)operator new(20);
  if ( v11 )
  {
    v11->rearTemperature = 0;
    v11->rearCamber = 0;
    v11->rearPressure = 0;
    v11->rearToe = 0;
    v11->grainBlister = 0;
  }
  else
  {
    v11 = 0;
  }
  this->LR = v11;
  SetupInformation::setRearValues(this, v11, 20.0, 480.0);
  ksgui::Control::addControl(this, this->LR->rearCamber);
  ksgui::Control::addControl(this, this->LR->rearPressure);
  ksgui::Control::addControl(this, this->LR->rearTemperature);
  ksgui::Control::addControl(this, this->LR->rearToe);
  ksgui::Control::addControl(this, this->LR->grainBlister);
  v12 = (CarInfoRear *)operator new(20);
  if ( v12 )
  {
    v12->rearTemperature = 0;
    v12->rearCamber = 0;
    v12->rearPressure = 0;
    v12->rearToe = 0;
    v12->grainBlister = 0;
  }
  else
  {
    v12 = 0;
  }
  this->RR = v12;
  SetupInformation::setRearValues(this, v12, 250.0, 480.0);
  ksgui::Control::addControl(this, this->RR->rearCamber);
  ksgui::Control::addControl(this, this->RR->rearPressure);
  ksgui::Control::addControl(this, this->RR->rearTemperature);
  ksgui::Control::addControl(this, this->RR->rearToe);
  ksgui::Control::addControl(this, this->RR->grainBlister);
  v13 = (ksgui::Label *)operator new(284);
  v24 = v13;
  LOBYTE(v30) = 7;
  if ( v13 )
  {
    h = *(float *)&this->sim->game->gui;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"FRONT_HEIGHT", 0xCu);
    ksgui::Label::Label(v13, v21, (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v14 = 0;
  }
  this->frontHeight = v14;
  LOBYTE(v30) = 3;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Front Height", 0xCu);
  LOBYTE(v30) = 8;
  v15 = acTranslate(&v28, &iname);
  LOBYTE(v30) = 9;
  LODWORD(h) = std::operator+<wchar_t>(&text, v15, L":");
  v16 = this->frontHeight;
  LOBYTE(v30) = 10;
  v16->setText(v16, (const std::wstring *)LODWORD(h));
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( v28._Myres >= 8 )
    operator delete(v28._Bx._Ptr);
  v28._Myres = 7;
  v28._Mysize = 0;
  v28._Bx._Buf[0] = 0;
  LOBYTE(v30) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->frontHeight->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)this->frontHeight, 90.0, 180.0);
  ksgui::Control::addControl(this, this->frontHeight);
  v17 = (Font *)operator new(284);
  _Right._Ptr = v17;
  LOBYTE(v30) = 11;
  if ( v17 )
  {
    h = *(float *)&this->sim->game->gui;
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    std::wstring::assign(&v21, L"REAR_HEIGHT", 0xBu);
    ksgui::Label::Label((ksgui::Label *)v17, v21, (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v18 = 0;
  }
  this->rearHeight = v18;
  LOBYTE(v30) = 3;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Rear Height", 0xBu);
  LOBYTE(v30) = 12;
  v19 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v30) = 13;
  LODWORD(h) = std::operator+<wchar_t>(&v28, v19, L":");
  v20 = this->rearHeight;
  LOBYTE(v30) = 14;
  v20->setText(v20, (const std::wstring *)LODWORD(h));
  if ( v28._Myres >= 8 )
    operator delete(v28._Bx._Ptr);
  v28._Myres = 7;
  v28._Mysize = 0;
  v28._Bx._Buf[0] = 0;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  LOBYTE(v30) = 3;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->rearHeight->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)this->rearHeight, 90.0, 420.0);
  ksgui::Control::addControl(this, this->rearHeight);
}
SetupInformation *SetupInformation::`vector deleting destructor'(SetupInformation *this, unsigned int a2)
{
  this->__vftable = (SetupInformation_vtbl *)&SetupInformation::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->carView);
  ksgui::Control::~Control(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *SetupInformation::cutDecimals(SetupInformation *this, std::wstring *result, const std::wstring *s, int decimalCount)
{
  int v4; // eax

  v4 = std::wstring::find_last_of((std::wstring *)s, L".", 0xFFFFFFFF, 1u);
  if ( decimalCount )
    v4 += decimalCount + 1;
  std::wstring::substr((std::wstring *)s, result, 0, v4);
  return result;
}
double SetupInformation::getTOE(SetupInformation *this, int tyreIndex)
{
  CarAvatar *v3; // eax
  Sim *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm2_4
  CarAvatar *v7; // eax
  vec3f result; // [esp+4h] [ebp-18h] BYREF
  vec3f pos; // [esp+10h] [ebp-Ch] BYREF

  v3 = Sim::getCar(this->sim, 0);
  v4 = this->sim;
  v5 = v3->physicsState.suspensionMatrix[tyreIndex].M31;
  LODWORD(v6) = LODWORD(v3->physicsState.suspensionMatrix[tyreIndex].M33) ^ _xmm;
  LODWORD(pos.y) = LODWORD(v3->physicsState.suspensionMatrix[tyreIndex].M32) ^ _xmm;
  pos.z = v6;
  LODWORD(pos.x) = LODWORD(v5) ^ _xmm;
  v7 = Sim::getCar(v4, 0);
  pos = *Node::worldToLocalNormal(v7->bodyTransform, &result, &pos);
  return (float)(__libm_sse2_asinf().m128_f32[0] * 57.29578);
}
void __userpurge SetupInformation::render(SetupInformation *this@<ecx>, int a2@<esi>, float dt)
{
  SetupInformation_vtbl *v4; // eax
  const std::wstring *v5; // eax
  std::shared_ptr<Font> *v6; // ebx
  float y; // xmm0_4
  Font *v8; // ecx
  CarAvatar *v9; // eax
  Sim *v10; // ecx
  float *v11; // esi
  TyreThermalState *v12; // ebp
  __m128 v13; // xmm1
  float v14; // xmm4_4
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  float v17; // xmm2_4
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  ksgui::Label *v20; // edx
  Font *v21; // ecx
  __m128 v22; // xmm1
  float v23; // xmm4_4
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  float v26; // xmm2_4
  const std::wstring *v27; // eax
  const std::wstring *v28; // eax
  ksgui::Label *v29; // edx
  Font *v30; // ecx
  __m128 v31; // xmm1
  float v32; // xmm4_4
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  float v35; // xmm2_4
  const std::wstring *v36; // eax
  const std::wstring *v37; // eax
  ksgui::Label *v38; // edx
  Font *v39; // ecx
  __m128 v40; // xmm1
  float v41; // xmm4_4
  __m128 v42; // xmm3
  __m128 v43; // xmm0
  float v44; // xmm2_4
  const std::wstring *v45; // eax
  const std::wstring *v46; // eax
  ksgui::Label *v47; // edx
  Font *v48; // ecx
  std::wstring *v49; // esi
  int v50; // ecx
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  const std::wstring *v54; // eax
  ksgui::Label *v55; // edx
  Font *v56; // ecx
  std::wstring *v57; // esi
  int v58; // ecx
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  std::wstring *v61; // eax
  const std::wstring *v62; // eax
  ksgui::Label *v63; // edx
  Font *v64; // ecx
  std::wstring *v65; // esi
  int v66; // ecx
  std::wstring *v67; // eax
  std::wstring *v68; // eax
  std::wstring *v69; // eax
  const std::wstring *v70; // eax
  ksgui::Label *v71; // edx
  Font *v72; // ecx
  std::wstring *v73; // esi
  int v74; // ecx
  std::wstring *v75; // eax
  std::wstring *v76; // eax
  std::wstring *v77; // eax
  const std::wstring *v78; // eax
  ksgui::Label *v79; // edx
  Font *v80; // ecx
  __m128 v81; // xmm1
  float v82; // xmm4_4
  __m128 v83; // xmm3
  __m128 v84; // xmm0
  float v85; // xmm2_4
  const std::wstring *v86; // eax
  const std::wstring *v87; // eax
  ksgui::Label *v88; // edx
  Font *v89; // ecx
  __m128 v90; // xmm1
  float v91; // xmm4_4
  __m128 v92; // xmm3
  __m128 v93; // xmm0
  float v94; // xmm2_4
  const std::wstring *v95; // eax
  const std::wstring *v96; // eax
  ksgui::Label *v97; // edx
  Font *v98; // ecx
  std::wstring *v99; // esi
  int v100; // ecx
  std::wstring *v101; // eax
  std::wstring *v102; // eax
  std::wstring *v103; // eax
  const std::wstring *v104; // eax
  ksgui::Label *v105; // edx
  Font *v106; // ecx
  std::wstring *v107; // esi
  int v108; // ecx
  std::wstring *v109; // eax
  std::wstring *v110; // eax
  std::wstring *v111; // eax
  const std::wstring *v112; // eax
  ksgui::Label *v113; // edx
  Font *v114; // ecx
  std::wstring *v115; // esi
  int v116; // ecx
  std::wstring *v117; // eax
  std::wstring *v118; // eax
  std::wstring *v119; // eax
  const std::wstring *v120; // eax
  ksgui::Label *v121; // edx
  Font *v122; // ecx
  std::wstring *v123; // esi
  int v124; // ecx
  std::wstring *v125; // eax
  std::wstring *v126; // eax
  std::wstring *v127; // eax
  const std::wstring *v128; // eax
  ksgui::Label *v129; // edx
  Font *v130; // ecx
  const std::wstring *v131; // eax
  ksgui::Label *v132; // edx
  Font *v133; // ecx
  const std::wstring *v134; // eax
  ksgui::Label *v135; // edx
  Font *v136; // ecx
  const std::wstring *v137; // eax
  ksgui::Label *v138; // edx
  Font *v139; // ecx
  const std::wstring *v140; // eax
  ksgui::Label *v141; // edx
  Font *v142; // ecx
  __m128 v143; // xmm1
  __m128 v144; // xmm3
  __m128 v145; // xmm0
  float v146; // xmm2_4
  const std::wstring *v147; // eax
  const std::wstring *v148; // eax
  ksgui::Label *v149; // edx
  Font *v150; // ecx
  __m128 v151; // xmm1
  __m128 v152; // xmm3
  __m128 v153; // xmm0
  float v154; // xmm2_4
  const std::wstring *v155; // eax
  const std::wstring *v156; // eax
  ksgui::Label *v157; // edx
  Font *v158; // ecx
  __m128 v159; // xmm1
  __m128 v160; // xmm3
  __m128 v161; // xmm0
  float v162; // xmm2_4
  const std::wstring *v163; // eax
  const std::wstring *v164; // eax
  ksgui::Label *v165; // edx
  Font *v166; // ecx
  __m128 v167; // xmm1
  __m128 v168; // xmm3
  __m128 v169; // xmm0
  float v170; // xmm2_4
  const std::wstring *v171; // eax
  const std::wstring *v172; // eax
  ksgui::Label *v173; // edx
  Font *v174; // ecx
  Font *v175; // ecx
  __m128 v176; // xmm2
  __m128 v177; // xmm0
  float v178; // xmm1_4
  float v179; // xmm5_4
  __m128 v180; // xmm6
  float v181; // xmm5_4
  float v182; // xmm4_4
  float v183; // xmm1_4
  std::wstring *v184; // eax
  std::wstring *v185; // esi
  const std::wstring *v186; // eax
  std::wstring *v187; // eax
  std::wstring *v188; // eax
  std::wstring *v189; // eax
  const std::wstring *v190; // eax
  ksgui::Label *v191; // edx
  Font *v192; // ecx
  float v193; // xmm0_4
  Font *v194; // eax
  Font *v195; // eax
  std::wstring *v196; // esi
  const std::wstring *v197; // eax
  std::wstring *v198; // eax
  std::wstring *v199; // eax
  std::wstring *v200; // eax
  std::wstring *v201; // eax
  ksgui::Label *v202; // edx
  float v203; // xmm0_4
  Font *v204; // eax
  float x; // [esp+4h] [ebp-178h]
  int g; // [esp+Ch] [ebp-170h]
  const std::wstring *ga; // [esp+Ch] [ebp-170h]
  int ascale; // [esp+10h] [ebp-16Ch]
  __int64 v209; // [esp+18h] [ebp-164h]
  float v210; // [esp+20h] [ebp-15Ch]
  float v211; // [esp+2Ch] [ebp-150h]
  float v212; // [esp+2Ch] [ebp-150h]
  float v213; // [esp+2Ch] [ebp-150h]
  float v214; // [esp+2Ch] [ebp-150h]
  float v215; // [esp+2Ch] [ebp-150h]
  ksgui::ksRect wrect; // [esp+30h] [ebp-14Ch] BYREF
  float v217; // [esp+40h] [ebp-13Ch]
  float _Val; // [esp+44h] [ebp-138h]
  float v219; // [esp+48h] [ebp-134h]
  std::wstring v220; // [esp+4Ch] [ebp-130h] BYREF
  std::wstring result; // [esp+64h] [ebp-118h] BYREF
  std::wstring v222; // [esp+7Ch] [ebp-100h] BYREF
  std::wstring text; // [esp+94h] [ebp-E8h] BYREF
  std::wstring v224; // [esp+ACh] [ebp-D0h] BYREF
  std::wstring min; // [esp+C4h] [ebp-B8h] BYREF
  std::wstring v226; // [esp+DCh] [ebp-A0h] BYREF
  std::wstring v227; // [esp+F4h] [ebp-88h] BYREF
  std::wstring v228; // [esp+10Ch] [ebp-70h] BYREF
  std::wstring v229; // [esp+124h] [ebp-58h] BYREF
  std::wstring v230; // [esp+13Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v231; // [esp+154h] [ebp-28h] BYREF
  int v232; // [esp+178h] [ebp-4h]

  ksgui::Control::render(this, (int)this, a2, dt, v209, v210);
  v4 = this->__vftable;
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)&this->rect);
  v4->getWorldRect(this, &wrect);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Car Status", 0xAu);
  v232 = 0;
  v5 = acTranslate(&result, &text);
  v6 = &this->font;
  y = this->rect.top + 12.0;
  v8 = this->font._Ptr;
  LOBYTE(v232) = 1;
  Font::blitString(v8, (float)((float)(wrect.right - wrect.left) * 0.5) + wrect.left, y, v5, 1.4, eAlignCenter);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v232 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(v6->_Ptr, 1.0, 1.0, 1.0, 1.0);
  v9 = Sim::getCar(this->sim, 0);
  v10 = this->sim;
  v11 = (float *)&v9->physicsState.physicsGUID;
  LODWORD(v217) = &v9->physicsState;
  v12 = Sim::getCar(v10, 0)->physicsState.tyreThermalStates;
  Sim::getCar(this->sim, 0);
  v13.m128_f32[0] = FLOAT_8388608_0;
  v14 = (float)(v11[426] * 57.29578) * 100.0;
  v15.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v14);
  v16.m128_i32[0] = LODWORD(v14) ^ LODWORD(FLOAT_N0_0) & LODWORD(v14);
  v16.m128_f32[0] = _mm_cmplt_ss(v16, v13).m128_f32[0];
  v17 = (float)(v14 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v16.m128_i32[0] | v15.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v16.m128_i32[0] | v15.m128_i32[0]);
  v16.m128_f32[0] = v17 - v14;
  v18 = std::to_wstring(
          &v222,
          (float)(v17 - COERCE_FLOAT(_mm_cmpgt_ss(v16, v15).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 2;
  v19 = SetupInformation::cutDecimals(this, &result, v18, 2);
  v20 = this->LF->frontCamber;
  v21 = v6->_Ptr;
  LOBYTE(v232) = 3;
  Font::blitString(
    v21,
    (float)(v20->rect.right + wrect.left) + 100.0,
    (float)(v20->rect.top + wrect.top) + 2.0,
    v19,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v22.m128_f32[0] = FLOAT_8388608_0;
  v23 = (float)(v11[427] * 57.29578) * 100.0;
  v24.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v23);
  v25.m128_i32[0] = LODWORD(v23) ^ LODWORD(FLOAT_N0_0) & LODWORD(v23);
  v25.m128_f32[0] = _mm_cmplt_ss(v25, v22).m128_f32[0];
  v26 = (float)(v23 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v25.m128_i32[0] | v24.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v25.m128_i32[0] | v24.m128_i32[0]);
  v25.m128_f32[0] = v26 - v23;
  v27 = std::to_wstring(
          &v222,
          (float)(v26 - COERCE_FLOAT(_mm_cmpgt_ss(v25, v24).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 4;
  v28 = SetupInformation::cutDecimals(this, &result, v27, 2);
  v29 = this->RF->frontCamber;
  v30 = v6->_Ptr;
  LOBYTE(v232) = 5;
  Font::blitString(
    v30,
    (float)(v29->rect.right + wrect.left) + 100.0,
    (float)(v29->rect.top + wrect.top) + 2.0,
    v28,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v31.m128_f32[0] = FLOAT_8388608_0;
  v32 = (float)(v11[428] * 57.29578) * 100.0;
  v33.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v32);
  v34.m128_i32[0] = LODWORD(v32) ^ LODWORD(FLOAT_N0_0) & LODWORD(v32);
  v34.m128_f32[0] = _mm_cmplt_ss(v34, v31).m128_f32[0];
  v35 = (float)(v32 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v34.m128_i32[0] | v33.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v34.m128_i32[0] | v33.m128_i32[0]);
  v34.m128_f32[0] = v35 - v32;
  v36 = std::to_wstring(
          &v222,
          (float)(v35 - COERCE_FLOAT(_mm_cmpgt_ss(v34, v33).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 6;
  v37 = SetupInformation::cutDecimals(this, &result, v36, 2);
  v38 = this->LR->rearCamber;
  v39 = v6->_Ptr;
  LOBYTE(v232) = 7;
  Font::blitString(
    v39,
    (float)(v38->rect.right + wrect.left) + 100.0,
    (float)(v38->rect.top + wrect.top) + 2.0,
    v37,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v40.m128_f32[0] = FLOAT_8388608_0;
  v41 = (float)(v11[429] * 57.29578) * 100.0;
  v42.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v41);
  v43.m128_i32[0] = LODWORD(v41) ^ LODWORD(FLOAT_N0_0) & LODWORD(v41);
  v43.m128_f32[0] = _mm_cmplt_ss(v43, v40).m128_f32[0];
  v44 = (float)(v41 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v43.m128_i32[0] | v42.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v43.m128_i32[0] | v42.m128_i32[0]);
  v43.m128_f32[0] = v44 - v41;
  v45 = std::to_wstring(
          &v222,
          (float)(v44 - COERCE_FLOAT(_mm_cmpgt_ss(v43, v42).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 8;
  v46 = SetupInformation::cutDecimals(this, &result, v45, 2);
  v47 = this->RR->rearCamber;
  v48 = v6->_Ptr;
  LOBYTE(v232) = 9;
  Font::blitString(
    v48,
    (float)(v47->rect.right + wrect.left) + 100.0,
    (float)(v47->rect.top + wrect.top) + 2.0,
    v46,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v49 = std::to_wstring(&v222, (int)v12->lastBlister);
  v50 = (int)v12->lastGrain;
  v232 = 10;
  v51 = std::to_wstring(&v220, v50);
  LOBYTE(v232) = 11;
  v52 = std::operator+<wchar_t>(&v224, v51, L"% / ");
  LOBYTE(v232) = 12;
  v53 = std::operator+<wchar_t>(&text, v52, v49);
  LOBYTE(v232) = 13;
  v54 = std::operator+<wchar_t>(&result, v53, L"%");
  v55 = this->LF->grainBlister;
  v56 = v6->_Ptr;
  LOBYTE(v232) = 14;
  Font::blitString(
    v56,
    (float)(v55->rect.right + wrect.left) + 100.0,
    (float)(v55->rect.top + wrect.top) + 2.0,
    v54,
    1.0,
    eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v57 = std::to_wstring(&v222, (int)v12[1].lastBlister);
  v58 = (int)v12[1].lastGrain;
  v232 = 15;
  v59 = std::to_wstring(&text, v58);
  LOBYTE(v232) = 16;
  v60 = std::operator+<wchar_t>(&result, v59, L"% / ");
  LOBYTE(v232) = 17;
  v61 = std::operator+<wchar_t>(&v224, v60, v57);
  LOBYTE(v232) = 18;
  v62 = std::operator+<wchar_t>(&v220, v61, L"%");
  v63 = this->RF->grainBlister;
  v64 = v6->_Ptr;
  LOBYTE(v232) = 19;
  Font::blitString(
    v64,
    (float)(v63->rect.right + wrect.left) + 100.0,
    (float)(v63->rect.top + wrect.top) + 2.0,
    v62,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v65 = std::to_wstring(&v222, (int)v12[2].lastBlister);
  v66 = (int)v12[2].lastGrain;
  v232 = 20;
  v67 = std::to_wstring(&text, v66);
  LOBYTE(v232) = 21;
  v68 = std::operator+<wchar_t>(&result, v67, L"% / ");
  LOBYTE(v232) = 22;
  v69 = std::operator+<wchar_t>(&v224, v68, v65);
  LOBYTE(v232) = 23;
  v70 = std::operator+<wchar_t>(&v220, v69, L"%");
  v71 = this->LR->grainBlister;
  v72 = v6->_Ptr;
  LOBYTE(v232) = 24;
  Font::blitString(
    v72,
    (float)(v71->rect.right + wrect.left) + 100.0,
    (float)(v71->rect.top + wrect.top) + 2.0,
    v70,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v73 = std::to_wstring(&v222, (int)v12[3].lastBlister);
  v74 = (int)v12[3].lastGrain;
  v232 = 25;
  v75 = std::to_wstring(&text, v74);
  LOBYTE(v232) = 26;
  v76 = std::operator+<wchar_t>(&result, v75, L"% / ");
  LOBYTE(v232) = 27;
  v77 = std::operator+<wchar_t>(&v224, v76, v73);
  LOBYTE(v232) = 28;
  v78 = std::operator+<wchar_t>(&v220, v77, L"%");
  v79 = this->RR->grainBlister;
  v80 = v6->_Ptr;
  LOBYTE(v232) = 29;
  Font::blitString(
    v80,
    (float)(v79->rect.right + wrect.left) + 100.0,
    (float)(v79->rect.top + wrect.top) + 2.0,
    v78,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v81.m128_f32[0] = FLOAT_8388608_0;
  v82 = Sim::getCar(this->sim, 0)->physicsState.caster[0] * 100.0;
  v83.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v82);
  v84.m128_i32[0] = LODWORD(v82) ^ LODWORD(FLOAT_N0_0) & LODWORD(v82);
  v84.m128_f32[0] = _mm_cmplt_ss(v84, v81).m128_f32[0];
  v85 = (float)(v82 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v84.m128_i32[0] | v83.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v84.m128_i32[0] | v83.m128_i32[0]);
  v84.m128_f32[0] = v85 - v82;
  v86 = std::to_wstring(
          &v222,
          (float)(v85 - COERCE_FLOAT(_mm_cmpgt_ss(v84, v83).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 30;
  v87 = SetupInformation::cutDecimals(this, &v220, v86, 2);
  v88 = this->LF->frontCaster;
  v89 = v6->_Ptr;
  LOBYTE(v232) = 31;
  Font::blitString(
    v89,
    (float)(v88->rect.right + wrect.left) + 100.0,
    (float)(v88->rect.top + wrect.top) + 2.0,
    v87,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v90.m128_f32[0] = FLOAT_8388608_0;
  v91 = Sim::getCar(this->sim, 0)->physicsState.caster[0] * 100.0;
  v92.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v91);
  v93.m128_i32[0] = LODWORD(v91) ^ LODWORD(FLOAT_N0_0) & LODWORD(v91);
  v93.m128_f32[0] = _mm_cmplt_ss(v93, v90).m128_f32[0];
  v94 = (float)(v91 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v93.m128_i32[0] | v92.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v93.m128_i32[0] | v92.m128_i32[0]);
  v93.m128_f32[0] = v94 - v91;
  v95 = std::to_wstring(
          &v222,
          (float)(v94 - COERCE_FLOAT(_mm_cmpgt_ss(v93, v92).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 32;
  v96 = SetupInformation::cutDecimals(this, &v220, v95, 2);
  v97 = this->RF->frontCaster;
  v98 = v6->_Ptr;
  LOBYTE(v232) = 33;
  Font::blitString(
    v98,
    (float)(v97->rect.right + wrect.left) + 100.0,
    (float)(v97->rect.top + wrect.top) + 2.0,
    v96,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v99 = std::to_wstring(&v222, (int)v12->dynamicPressure);
  v100 = (int)v12->staticPressure;
  v232 = 34;
  v101 = std::to_wstring(&text, v100);
  LOBYTE(v232) = 35;
  v102 = std::operator+<wchar_t>(&result, L"Cold:", v101);
  LOBYTE(v232) = 36;
  v103 = std::operator+<wchar_t>(&v224, v102, L" Hot:");
  LOBYTE(v232) = 37;
  v104 = std::operator+<wchar_t>(&v220, v103, v99);
  v105 = this->LF->frontPressure;
  v106 = v6->_Ptr;
  LOBYTE(v232) = 38;
  Font::blitString(
    v106,
    (float)(v105->rect.right + wrect.left) + 100.0,
    (float)(v105->rect.top + wrect.top) + 2.0,
    v104,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v107 = std::to_wstring(&v222, (int)v12[1].dynamicPressure);
  v108 = (int)v12[1].staticPressure;
  v232 = 39;
  v109 = std::to_wstring(&text, v108);
  LOBYTE(v232) = 40;
  v110 = std::operator+<wchar_t>(&result, L"Cold:", v109);
  LOBYTE(v232) = 41;
  v111 = std::operator+<wchar_t>(&v224, v110, L" Hot:");
  LOBYTE(v232) = 42;
  v112 = std::operator+<wchar_t>(&v220, v111, v107);
  v113 = this->RF->frontPressure;
  v114 = v6->_Ptr;
  LOBYTE(v232) = 43;
  Font::blitString(
    v114,
    (float)(v113->rect.right + wrect.left) + 100.0,
    (float)(v113->rect.top + wrect.top) + 2.0,
    v112,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v115 = std::to_wstring(&v222, (int)v12[2].dynamicPressure);
  v116 = (int)v12[2].staticPressure;
  v232 = 44;
  v117 = std::to_wstring(&text, v116);
  LOBYTE(v232) = 45;
  v118 = std::operator+<wchar_t>(&result, L"Cold:", v117);
  LOBYTE(v232) = 46;
  v119 = std::operator+<wchar_t>(&v224, v118, L" Hot:");
  LOBYTE(v232) = 47;
  v120 = std::operator+<wchar_t>(&v220, v119, v115);
  v121 = this->LR->rearPressure;
  v122 = v6->_Ptr;
  LOBYTE(v232) = 48;
  Font::blitString(
    v122,
    (float)(v121->rect.right + wrect.left) + 100.0,
    (float)(v121->rect.top + wrect.top) + 2.0,
    v120,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v123 = std::to_wstring(&v222, (int)v12[3].dynamicPressure);
  v124 = (int)v12[3].staticPressure;
  v232 = 49;
  v125 = std::to_wstring(&text, v124);
  LOBYTE(v232) = 50;
  v126 = std::operator+<wchar_t>(&result, L"Cold:", v125);
  LOBYTE(v232) = 51;
  v127 = std::operator+<wchar_t>(&v224, v126, L" Hot:");
  LOBYTE(v232) = 52;
  v128 = std::operator+<wchar_t>(&v220, v127, v123);
  v129 = this->RR->rearPressure;
  v130 = v6->_Ptr;
  LOBYTE(v232) = 53;
  Font::blitString(
    v130,
    (float)(v129->rect.right + wrect.left) + 100.0,
    (float)(v129->rect.top + wrect.top) + 2.0,
    v128,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v131 = tempToString(&v222, v12->lastSetIMO);
  v132 = this->LF->frontTemperature;
  v133 = v6->_Ptr;
  v232 = 54;
  Font::blitString(
    v133,
    (float)(v132->rect.right + wrect.left) + 100.0,
    (float)(v132->rect.top + wrect.top) + 2.0,
    v131,
    1.0,
    eAlignLeft);
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v134 = tempToString(&v222, v12[1].lastSetIMO);
  v135 = this->RF->frontTemperature;
  v136 = v6->_Ptr;
  v232 = 55;
  Font::blitString(
    v136,
    (float)(v135->rect.right + wrect.left) + 100.0,
    (float)(v135->rect.top + wrect.top) + 2.0,
    v134,
    1.0,
    eAlignLeft);
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v137 = tempToString(&v222, v12[2].lastSetIMO);
  v138 = this->LR->rearTemperature;
  v139 = v6->_Ptr;
  v232 = 56;
  Font::blitString(
    v139,
    (float)(v138->rect.right + wrect.left) + 100.0,
    (float)(v138->rect.top + wrect.top) + 2.0,
    v137,
    1.0,
    eAlignLeft);
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v140 = tempToString(&v222, v12[3].lastSetIMO);
  v141 = this->RR->rearTemperature;
  v142 = v6->_Ptr;
  v232 = 57;
  Font::blitString(
    v142,
    (float)(v141->rect.right + wrect.left) + 100.0,
    (float)(v141->rect.top + wrect.top) + 2.0,
    v140,
    1.0,
    eAlignLeft);
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v143.m128_f32[0] = FLOAT_8388608_0;
  v211 = SetupInformation::getTOE(this, 0) * 100.0;
  v144.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v211);
  v145.m128_i32[0] = LODWORD(v211) ^ LODWORD(FLOAT_N0_0) & LODWORD(v211);
  v145.m128_f32[0] = _mm_cmplt_ss(v145, v143).m128_f32[0];
  v146 = (float)(v211 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v145.m128_i32[0] | v144.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v145.m128_i32[0] | v144.m128_i32[0]);
  v145.m128_f32[0] = v146 - v211;
  v147 = std::to_wstring(
           &v222,
           (float)(v146 - COERCE_FLOAT(_mm_cmpgt_ss(v145, v144).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 58;
  v148 = SetupInformation::cutDecimals(this, &v220, v147, 2);
  v149 = this->LF->frontToe;
  v150 = v6->_Ptr;
  LOBYTE(v232) = 59;
  Font::blitString(
    v150,
    (float)(v149->rect.right + wrect.left) + 100.0,
    (float)(v149->rect.top + wrect.top) + 2.0,
    v148,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v151.m128_f32[0] = FLOAT_8388608_0;
  v212 = SetupInformation::getTOE(this, 1) * 100.0;
  v152.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v212);
  v153.m128_i32[0] = LODWORD(v212) ^ LODWORD(FLOAT_N0_0) & LODWORD(v212);
  v153.m128_f32[0] = _mm_cmplt_ss(v153, v151).m128_f32[0];
  v154 = (float)(v212 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v153.m128_i32[0] | v152.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v153.m128_i32[0] | v152.m128_i32[0]);
  v153.m128_f32[0] = v154 - v212;
  v155 = std::to_wstring(
           &v222,
           (float)(v154 - COERCE_FLOAT(_mm_cmpgt_ss(v153, v152).m128_u32[0] & LODWORD(FLOAT_1_0))) * -0.0099999998);
  v232 = 60;
  v156 = SetupInformation::cutDecimals(this, &v220, v155, 2);
  v157 = this->RF->frontToe;
  v158 = v6->_Ptr;
  LOBYTE(v232) = 61;
  Font::blitString(
    v158,
    (float)(v157->rect.right + wrect.left) + 100.0,
    (float)(v157->rect.top + wrect.top) + 2.0,
    v156,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v159.m128_f32[0] = FLOAT_8388608_0;
  v213 = SetupInformation::getTOE(this, 2) * 100.0;
  v160.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v213);
  v161.m128_i32[0] = LODWORD(v213) ^ LODWORD(FLOAT_N0_0) & LODWORD(v213);
  v161.m128_f32[0] = _mm_cmplt_ss(v161, v159).m128_f32[0];
  v162 = (float)(v213 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v161.m128_i32[0] | v160.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v161.m128_i32[0] | v160.m128_i32[0]);
  v161.m128_f32[0] = v162 - v213;
  v163 = std::to_wstring(
           &v222,
           (float)(v162 - COERCE_FLOAT(_mm_cmpgt_ss(v161, v160).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.0099999998);
  v232 = 62;
  v164 = SetupInformation::cutDecimals(this, &v220, v163, 2);
  v165 = this->LR->rearToe;
  v166 = v6->_Ptr;
  LOBYTE(v232) = 63;
  Font::blitString(
    v166,
    (float)(v165->rect.right + wrect.left) + 100.0,
    (float)(v165->rect.top + wrect.top) + 2.0,
    v164,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v167.m128_f32[0] = FLOAT_8388608_0;
  v214 = SetupInformation::getTOE(this, 3) * 100.0;
  v168.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v214);
  v169.m128_i32[0] = LODWORD(v214) ^ LODWORD(FLOAT_N0_0) & LODWORD(v214);
  v169.m128_f32[0] = _mm_cmplt_ss(v169, v167).m128_f32[0];
  v170 = (float)(v214 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v169.m128_i32[0] | v168.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v169.m128_i32[0] | v168.m128_i32[0]);
  v169.m128_f32[0] = v170 - v214;
  v171 = std::to_wstring(
           &v222,
           (float)(v170 - COERCE_FLOAT(_mm_cmpgt_ss(v169, v168).m128_u32[0] & LODWORD(FLOAT_1_0))) * -0.0099999998);
  v232 = 64;
  v172 = SetupInformation::cutDecimals(this, &v220, v171, 2);
  v173 = this->RR->rearToe;
  v174 = v6->_Ptr;
  LOBYTE(v232) = 65;
  Font::blitString(
    v174,
    (float)(v173->rect.right + wrect.left) + 100.0,
    (float)(v173->rect.top + wrect.top) + 2.0,
    v172,
    1.0,
    eAlignLeft);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  v232 = -1;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v219 = Sim::getCar(this->sim, 0)->physicsInfo.minHeightM;
  min._Myres = 7;
  min._Mysize = 0;
  min._Bx._Buf[0] = 0;
  v175 = v6->_Ptr;
  v232 = 66;
  v215 = *(float *)(LODWORD(v217) + 1892);
  v217 = *(float *)(LODWORD(v217) + 1896);
  if ( v219 <= v215 )
    Font::setColor(v175, 1.0, 1.0, 1.0, 1.0);
  else
    Font::setColor(v175, 1.0, 0.0, 0.0, 1.0);
  v176.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v215 * 1000.0);
  v177.m128_i32[0] = COERCE_UNSIGNED_INT(v215 * 1000.0) ^ v176.m128_i32[0];
  v177.m128_f32[0] = _mm_cmplt_ss(v177, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
  _Val = (float)((float)(v215 * 1000.0) + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v177.m128_i32[0] | v176.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v177.m128_i32[0] | v176.m128_i32[0]);
  v177.m128_f32[0] = _Val - (float)(v215 * 1000.0);
  v177.m128_f32[0] = _mm_cmpgt_ss(v177, v176).m128_f32[0];
  v176.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v217 * 1000.0);
  v217 = v217 * 1000.0;
  v178 = _Val - COERCE_FLOAT(v177.m128_i32[0] & LODWORD(FLOAT_1_0));
  v177.m128_i32[0] = LODWORD(v217) ^ v176.m128_i32[0];
  v177.m128_f32[0] = _mm_cmplt_ss(v177, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
  _Val = v178;
  v179 = (float)(v217 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v177.m128_i32[0] | v176.m128_i32[0]))
       - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v177.m128_i32[0] | v176.m128_i32[0]);
  v177.m128_f32[0] = v179 - v217;
  v180.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v219 * 1000.0);
  v181 = v179 - COERCE_FLOAT(_mm_cmpgt_ss(v177, v176).m128_u32[0] & LODWORD(FLOAT_1_0));
  v177.m128_i32[0] = COERCE_UNSIGNED_INT(v219 * 1000.0) ^ v180.m128_i32[0];
  LODWORD(v182) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v177, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | v180.m128_i32[0];
  v177.m128_f32[0] = (float)((float)((float)(v219 * 1000.0) + v182) - v182) - (float)(v219 * 1000.0);
  v183 = (float)((float)((float)(v219 * 1000.0) + v182) - v182)
       - COERCE_FLOAT(_mm_cmpgt_ss(v177, v180).m128_u32[0] & LODWORD(FLOAT_1_0));
  v217 = v183;
  if ( v183 >= 0.0 )
  {
    v184 = std::to_wstring(&v222, v183);
    std::wstring::operator=(&min, v184);
    if ( v222._Myres >= 8 )
      operator delete(v222._Bx._Ptr);
  }
  else
  {
    std::wstring::assign(&min, L"--");
  }
  if ( _Val == v217 )
    Font::setColor(v6->_Ptr, 1.0, 1.0, 0.0, 1.0);
  v185 = SetupInformation::cutDecimals(this, &v226, &min, 0);
  LOBYTE(v232) = 67;
  v186 = std::to_wstring(&v222, _Val);
  LOBYTE(v232) = 68;
  v187 = SetupInformation::cutDecimals(this, &text, v186, 0);
  LOBYTE(v232) = 69;
  v188 = std::operator+<wchar_t>(&result, L"~", v187);
  LOBYTE(v232) = 70;
  v189 = std::operator+<wchar_t>(&v224, v188, L" mm - min: ");
  LOBYTE(v232) = 71;
  v190 = std::operator+<wchar_t>(&v220, v189, v185);
  v191 = this->frontHeight;
  v192 = v6->_Ptr;
  v193 = v191->rect.top + wrect.top;
  LOBYTE(v232) = 72;
  Font::blitString(v192, (float)(v191->rect.right + wrect.left) + 170.0, v193 + 2.0, v190, 1.0, eAlignCenter);
  if ( v220._Myres >= 8 )
    operator delete(v220._Bx._Ptr);
  v220._Myres = 7;
  v220._Mysize = 0;
  v220._Bx._Buf[0] = 0;
  if ( v224._Myres >= 8 )
    operator delete(v224._Bx._Ptr);
  v224._Myres = 7;
  v224._Mysize = 0;
  v224._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( v222._Myres >= 8 )
    operator delete(v222._Bx._Ptr);
  v222._Myres = 7;
  v222._Mysize = 0;
  v222._Bx._Buf[0] = 0;
  LOBYTE(v232) = 66;
  if ( v226._Myres >= 8 )
    operator delete(v226._Bx._Ptr);
  if ( v217 <= v181 )
  {
    ascale = 1065353216;
    g = 1065353216;
  }
  else
  {
    ascale = 0;
    g = 0;
  }
  v194 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
  Font::setColor(v194, 1.0, *(float *)&g, *(float *)&ascale, 1.0);
  if ( v181 == v217 )
  {
    v195 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
    Font::setColor(v195, 1.0, 1.0, 0.0, 1.0);
  }
  v196 = SetupInformation::cutDecimals(this, &v231.name, &min, 0);
  LOBYTE(v232) = 73;
  v197 = std::to_wstring(&v229, v181);
  LOBYTE(v232) = 74;
  v198 = SetupInformation::cutDecimals(this, &v228, v197, 0);
  LOBYTE(v232) = 75;
  v199 = std::operator+<wchar_t>(&v227, L"~", v198);
  LOBYTE(v232) = 76;
  v200 = std::operator+<wchar_t>(&v230, v199, L" mm - min: ");
  LOBYTE(v232) = 77;
  v201 = std::operator+<wchar_t>(&v226, v200, v196);
  v202 = this->rearHeight;
  v203 = v202->rect.top + wrect.top;
  ga = v201;
  LOBYTE(v232) = 78;
  x = (float)(v202->rect.right + wrect.left) + 170.0;
  v204 = (Font *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&this->font);
  Font::blitString(v204, x, v203 + 2.0, ga, 1.0, eAlignCenter);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v226);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v230);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v227);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v228);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v229);
  std::wstring::~wstring(&v231);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&min);
}
void SetupInformation::setFrontValues(SetupInformation *this, CarInfoFront *info, float x, float y)
{
  ksgui::Label *v5; // edi
  ksgui::Label *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  ksgui::Label *v9; // ecx
  ksgui::Label *v10; // eax
  ksgui::Label *v11; // edi
  ksgui::Label *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  ksgui::Label *v15; // ecx
  ksgui::Label *v16; // eax
  ksgui::Label *v17; // edi
  ksgui::Label *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  ksgui::Label *v21; // ecx
  ksgui::Label *v22; // eax
  ksgui::Label *v23; // edi
  ksgui::Label *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  ksgui::Label *v27; // ecx
  ksgui::Label *v28; // eax
  ksgui::Label *v29; // edi
  ksgui::Label *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  ksgui::Label *v33; // ecx
  ksgui::Label *v34; // eax
  ksgui::Label *v35; // edi
  ksgui::Label *v36; // eax
  std::wstring *v37; // eax
  std::wstring *v38; // eax
  ksgui::Label *v39; // ecx
  ksgui::Label *v40; // eax
  std::wstring v41; // [esp+4h] [ebp-D4h] BYREF
  float top; // [esp+1Ch] [ebp-BCh]
  ksgui::Label *v43; // [esp+30h] [ebp-A8h]
  ksgui::Label *v44; // [esp+34h] [ebp-A4h]
  std::wstring text; // [esp+38h] [ebp-A0h] BYREF
  std::wstring result; // [esp+50h] [ebp-88h] BYREF
  std::wstring v47; // [esp+68h] [ebp-70h] BYREF
  std::wstring v48; // [esp+80h] [ebp-58h] BYREF
  std::wstring v49; // [esp+98h] [ebp-40h] BYREF
  std::wstring v50; // [esp+B0h] [ebp-28h] BYREF
  int v51; // [esp+D4h] [ebp-4h]
  float ya; // [esp+E4h] [ebp+Ch]
  float yb; // [esp+E4h] [ebp+Ch]
  float yc; // [esp+E4h] [ebp+Ch]
  float yd; // [esp+E4h] [ebp+Ch]
  float ye; // [esp+E4h] [ebp+Ch]

  v5 = (ksgui::Label *)operator new(284);
  v43 = v5;
  v6 = 0;
  v51 = 0;
  if ( v5 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"FRONT_CAMBER", 0xCu);
    ksgui::Label::Label(v5, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->frontCamber = v6;
  v51 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Camber", 6u);
  v51 = 1;
  v7 = acTranslate(&result, &text);
  LOBYTE(v51) = 2;
  v8 = std::operator+<wchar_t>(&v47, v7, L":");
  v9 = info->frontCamber;
  LOBYTE(v51) = 3;
  v9->setText(v9, v8);
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v51 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v10 = info->frontCamber;
  top = y;
  v10->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->frontCamber, x, top);
  ya = y + 20.0;
  v11 = (ksgui::Label *)operator new(284);
  v44 = v11;
  v12 = 0;
  v51 = 4;
  if ( v11 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"FRONT_CASTER", 0xCu);
    ksgui::Label::Label(v11, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->frontCaster = v12;
  v51 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Caster", 6u);
  v51 = 5;
  v13 = acTranslate(&v47, &text);
  LOBYTE(v51) = 6;
  v14 = std::operator+<wchar_t>(&result, v13, L":");
  v15 = info->frontCaster;
  LOBYTE(v51) = 7;
  v15->setText(v15, v14);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  v51 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v16 = info->frontCaster;
  top = ya;
  v16->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->frontCaster, x, top);
  yb = ya + 20.0;
  v17 = (ksgui::Label *)operator new(284);
  v44 = v17;
  v18 = 0;
  v51 = 8;
  if ( v17 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"FRONT_PRESSURE", 0xEu);
    ksgui::Label::Label(v17, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->frontPressure = v18;
  v51 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Pressure", 8u);
  v51 = 9;
  v19 = acTranslate(&v47, &text);
  LOBYTE(v51) = 10;
  v20 = std::operator+<wchar_t>(&result, v19, L":");
  v21 = info->frontPressure;
  LOBYTE(v51) = 11;
  v21->setText(v21, v20);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  v51 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v22 = info->frontPressure;
  top = yb;
  v22->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->frontPressure, x, top);
  yc = yb + 20.0;
  v23 = (ksgui::Label *)operator new(284);
  v44 = v23;
  v24 = 0;
  v51 = 12;
  if ( v23 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"FRONT_TEMPERATURE", 0x11u);
    ksgui::Label::Label(v23, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->frontTemperature = v24;
  v51 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Temp", 4u);
  v51 = 13;
  v25 = acTranslate(&v47, &text);
  LOBYTE(v51) = 14;
  v26 = std::operator+<wchar_t>(&result, v25, L":");
  v27 = info->frontTemperature;
  LOBYTE(v51) = 15;
  v27->setText(v27, v26);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  v51 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v28 = info->frontTemperature;
  top = yc;
  v28->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->frontTemperature, x, top);
  yd = yc + 20.0;
  v29 = (ksgui::Label *)operator new(284);
  v44 = v29;
  v30 = 0;
  v51 = 16;
  if ( v29 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"FRONT_TOE", 9u);
    ksgui::Label::Label(v29, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->frontToe = v30;
  v51 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"TOE", 3u);
  v51 = 17;
  v31 = acTranslate(&v47, &text);
  LOBYTE(v51) = 18;
  v32 = std::operator+<wchar_t>(&result, v31, L":");
  v33 = info->frontToe;
  LOBYTE(v51) = 19;
  v33->setText(v33, v32);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  v51 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v34 = info->frontToe;
  top = yd;
  v34->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->frontToe, x, top);
  ye = yd + 20.0;
  v35 = (ksgui::Label *)operator new(284);
  v44 = v35;
  v36 = 0;
  v51 = 20;
  if ( v35 )
  {
    top = *(float *)&this->sim->game->gui;
    v41._Myres = 7;
    v41._Mysize = 0;
    v41._Bx._Buf[0] = 0;
    std::wstring::assign(&v41, L"GRAIN_BLISTER", 0xDu);
    ksgui::Label::Label(v35, v41, (ksgui::GUI *)LODWORD(top));
  }
  info->grainBlister = v36;
  v51 = -1;
  v48._Myres = 7;
  v48._Mysize = 0;
  v48._Bx._Buf[0] = 0;
  std::wstring::assign(&v48, L"Grain/Blister", 0xDu);
  v51 = 21;
  v37 = acTranslate(&v50, &v48);
  LOBYTE(v51) = 22;
  v38 = std::operator+<wchar_t>(&v49, v37, L":");
  v39 = info->grainBlister;
  LOBYTE(v51) = 23;
  v39->setText(v39, v38);
  if ( v49._Myres >= 8 )
    operator delete(v49._Bx._Ptr);
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  v51 = -1;
  if ( v48._Myres >= 8 )
    operator delete(v48._Bx._Ptr);
  v48._Bx._Buf[0] = 0;
  v40 = info->grainBlister;
  v48._Myres = 7;
  v48._Mysize = 0;
  top = ye;
  v40->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->grainBlister, x, top);
}
void SetupInformation::setRearValues(SetupInformation *this, CarInfoRear *info, float x, float y)
{
  ksgui::Label *v5; // edi
  ksgui::Label *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  ksgui::Label *v9; // ecx
  ksgui::Label *v10; // eax
  ksgui::Label *v11; // edi
  ksgui::Label *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  ksgui::Label *v15; // ecx
  ksgui::Label *v16; // eax
  ksgui::Label *v17; // edi
  ksgui::Label *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  ksgui::Label *v21; // ecx
  ksgui::Label *v22; // eax
  ksgui::Label *v23; // edi
  ksgui::Label *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  ksgui::Label *v27; // ecx
  ksgui::Label *v28; // eax
  ksgui::Label *v29; // edi
  ksgui::Label *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  ksgui::Label *v33; // ecx
  ksgui::Label *v34; // eax
  std::wstring v35; // [esp+0h] [ebp-D4h] BYREF
  float top; // [esp+18h] [ebp-BCh]
  ksgui::Label *v37; // [esp+2Ch] [ebp-A8h]
  ksgui::Label *v38; // [esp+30h] [ebp-A4h]
  std::wstring text; // [esp+34h] [ebp-A0h] BYREF
  std::wstring result; // [esp+4Ch] [ebp-88h] BYREF
  std::wstring v41; // [esp+64h] [ebp-70h] BYREF
  std::wstring v42; // [esp+7Ch] [ebp-58h] BYREF
  std::wstring v43; // [esp+94h] [ebp-40h] BYREF
  std::wstring v44; // [esp+ACh] [ebp-28h] BYREF
  int v45; // [esp+D0h] [ebp-4h]
  float ya; // [esp+E0h] [ebp+Ch]
  float yb; // [esp+E0h] [ebp+Ch]
  float yc; // [esp+E0h] [ebp+Ch]
  float yd; // [esp+E0h] [ebp+Ch]

  v5 = (ksgui::Label *)operator new(284);
  v37 = v5;
  v6 = 0;
  v45 = 0;
  if ( v5 )
  {
    top = *(float *)&this->sim->game->gui;
    v35._Myres = 7;
    v35._Mysize = 0;
    v35._Bx._Buf[0] = 0;
    std::wstring::assign(&v35, L"REAR_CAMBER", 0xBu);
    ksgui::Label::Label(v5, v35, (ksgui::GUI *)LODWORD(top));
  }
  info->rearCamber = v6;
  v45 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Camber", 6u);
  v45 = 1;
  v7 = acTranslate(&result, &text);
  LOBYTE(v45) = 2;
  v8 = std::operator+<wchar_t>(&v41, v7, L":");
  v9 = info->rearCamber;
  LOBYTE(v45) = 3;
  v9->setText(v9, v8);
  if ( v41._Myres >= 8 )
    operator delete(v41._Bx._Ptr);
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v45 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v10 = info->rearCamber;
  top = y;
  v10->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->rearCamber, x, top);
  ya = y + 20.0;
  v11 = (ksgui::Label *)operator new(284);
  v38 = v11;
  v12 = 0;
  v45 = 4;
  if ( v11 )
  {
    top = *(float *)&this->sim->game->gui;
    v35._Myres = 7;
    v35._Mysize = 0;
    v35._Bx._Buf[0] = 0;
    std::wstring::assign(&v35, L"REAR_PRESSURE", 0xDu);
    ksgui::Label::Label(v11, v35, (ksgui::GUI *)LODWORD(top));
  }
  info->rearPressure = v12;
  v45 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Pressure", 8u);
  v45 = 5;
  v13 = acTranslate(&v41, &text);
  LOBYTE(v45) = 6;
  v14 = std::operator+<wchar_t>(&result, v13, L":");
  v15 = info->rearPressure;
  LOBYTE(v45) = 7;
  v15->setText(v15, v14);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v41._Myres >= 8 )
    operator delete(v41._Bx._Ptr);
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  v45 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v16 = info->rearPressure;
  top = ya;
  v16->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->rearPressure, x, top);
  yb = ya + 20.0;
  v17 = (ksgui::Label *)operator new(284);
  v38 = v17;
  v18 = 0;
  v45 = 8;
  if ( v17 )
  {
    top = *(float *)&this->sim->game->gui;
    v35._Myres = 7;
    v35._Mysize = 0;
    v35._Bx._Buf[0] = 0;
    std::wstring::assign(&v35, L"REAR_TEMPERATURE", 0x10u);
    ksgui::Label::Label(v17, v35, (ksgui::GUI *)LODWORD(top));
  }
  info->rearTemperature = v18;
  v45 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Temp", 4u);
  v45 = 9;
  v19 = acTranslate(&v41, &text);
  LOBYTE(v45) = 10;
  v20 = std::operator+<wchar_t>(&result, v19, L":");
  v21 = info->rearTemperature;
  LOBYTE(v45) = 11;
  v21->setText(v21, v20);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v41._Myres >= 8 )
    operator delete(v41._Bx._Ptr);
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  v45 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v22 = info->rearTemperature;
  top = yb;
  v22->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->rearTemperature, x, top);
  yc = yb + 20.0;
  v23 = (ksgui::Label *)operator new(284);
  v38 = v23;
  v24 = 0;
  v45 = 12;
  if ( v23 )
  {
    top = *(float *)&this->sim->game->gui;
    v35._Myres = 7;
    v35._Mysize = 0;
    v35._Bx._Buf[0] = 0;
    std::wstring::assign(&v35, L"REAR_TOE", 8u);
    ksgui::Label::Label(v23, v35, (ksgui::GUI *)LODWORD(top));
  }
  info->rearToe = v24;
  v45 = -1;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"TOE", 3u);
  v45 = 13;
  v25 = acTranslate(&v41, &text);
  LOBYTE(v45) = 14;
  v26 = std::operator+<wchar_t>(&result, v25, L":");
  v27 = info->rearToe;
  LOBYTE(v45) = 15;
  v27->setText(v27, v26);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v41._Myres >= 8 )
    operator delete(v41._Bx._Ptr);
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  v45 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v28 = info->rearToe;
  top = yc;
  v28->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->rearToe, x, top);
  yd = yc + 20.0;
  v29 = (ksgui::Label *)operator new(284);
  v38 = v29;
  v30 = 0;
  v45 = 16;
  if ( v29 )
  {
    top = *(float *)&this->sim->game->gui;
    v35._Myres = 7;
    v35._Mysize = 0;
    v35._Bx._Buf[0] = 0;
    std::wstring::assign(&v35, L"GRAIN_BLISTER", 0xDu);
    ksgui::Label::Label(v29, v35, (ksgui::GUI *)LODWORD(top));
  }
  info->grainBlister = v30;
  v45 = -1;
  v42._Myres = 7;
  v42._Mysize = 0;
  v42._Bx._Buf[0] = 0;
  std::wstring::assign(&v42, L"Grain/Blister", 0xDu);
  v45 = 17;
  v31 = acTranslate(&v44, &v42);
  LOBYTE(v45) = 18;
  v32 = std::operator+<wchar_t>(&v43, v31, L":");
  v33 = info->grainBlister;
  LOBYTE(v45) = 19;
  v33->setText(v33, v32);
  if ( v43._Myres >= 8 )
    operator delete(v43._Bx._Ptr);
  v43._Myres = 7;
  v43._Mysize = 0;
  v43._Bx._Buf[0] = 0;
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  v44._Myres = 7;
  v44._Mysize = 0;
  v44._Bx._Buf[0] = 0;
  v45 = -1;
  if ( v42._Myres >= 8 )
    operator delete(v42._Bx._Ptr);
  v42._Bx._Buf[0] = 0;
  v34 = info->grainBlister;
  v42._Myres = 7;
  v42._Mysize = 0;
  top = yd;
  v34->fontAlign = eAlignLeft;
  ksgui::Form::setPosition((ksgui::Form *)info->grainBlister, x, top);
}
