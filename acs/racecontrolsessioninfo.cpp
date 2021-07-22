#include "racecontrolsessioninfo.h
void RaceControlSessionInfo::RaceControlSessionInfo(RaceControlSessionInfo *this, Sim *aSim)
{
  Game *v3; // eax
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  Font *v7; // eax
  Font *v8; // eax
  std::_Ref_count_base *v9; // edi
  Sim *v10; // eax
  Texture *v11; // eax
  Sim *v12; // eax
  Texture *v13; // eax
  Sim *v14; // eax
  Texture *v15; // eax
  Sim *v16; // eax
  Texture *v17; // eax
  Sim *v18; // eax
  Texture *v19; // eax
  Sim *v20; // eax
  Texture *v21; // eax
  Sim *v22; // eax
  Texture *v23; // eax
  std::shared_ptr<Font> _Right; // [esp+20h] [ebp-6Ch] BYREF
  RaceControlSessionInfo *v25; // [esp+28h] [ebp-64h]
  std::wstring iname; // [esp+2Ch] [ebp-60h] BYREF
  Texture result; // [esp+44h] [ebp-48h] BYREF
  Texture v28; // [esp+60h] [ebp-2Ch] BYREF
  int v29; // [esp+88h] [ebp-4h]

  v25 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_SESSION_INFO", 0x19u);
  v3 = aSim->game;
  v29 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (RaceControlSessionInfo_vtbl *)&RaceControlSessionInfo::`vftable';
  this->sim = aSim;
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  this->dataFont._Ptr = 0;
  this->dataFont._Rep = 0;
  this->txRemainingTime.kid = 0;
  this->txRemainingTime.fileName._Myres = 7;
  this->txRemainingTime.fileName._Mysize = 0;
  this->txRemainingTime.fileName._Bx._Buf[0] = 0;
  this->txTrackConditions.kid = 0;
  this->txTrackConditions.fileName._Myres = 7;
  this->txTrackConditions.fileName._Mysize = 0;
  this->txTrackConditions.fileName._Bx._Buf[0] = 0;
  this->txTimeOfTheDay.kid = 0;
  this->txTimeOfTheDay.fileName._Myres = 7;
  this->txTimeOfTheDay.fileName._Mysize = 0;
  this->txTimeOfTheDay.fileName._Bx._Buf[0] = 0;
  this->txAirTemperature.kid = 0;
  this->txAirTemperature.fileName._Myres = 7;
  this->txAirTemperature.fileName._Mysize = 0;
  this->txAirTemperature.fileName._Bx._Buf[0] = 0;
  this->txAsphaltTemperature.kid = 0;
  this->txAsphaltTemperature.fileName._Myres = 7;
  this->txAsphaltTemperature.fileName._Mysize = 0;
  this->txAsphaltTemperature.fileName._Bx._Buf[0] = 0;
  this->txNextSession.kid = 0;
  this->txNextSession.fileName._Myres = 7;
  this->txNextSession.fileName._Mysize = 0;
  this->txNextSession.fileName._Bx._Buf[0] = 0;
  this->txWindIndicator.kid = 0;
  this->txWindIndicator.fileName._Myres = 7;
  this->txWindIndicator.fileName._Mysize = 0;
  this->txWindIndicator.fileName._Bx._Buf[0] = 0;
  LOBYTE(v29) = 11;
  v4 = (Font *)operator new(24);
  _Right._Ptr = v4;
  LOBYTE(v29) = 12;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 14.0, 1, 1);
  else
    v5 = 0;
  LOBYTE(v29) = 11;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->titleFont, &_Right);
  v6 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v7 = (Font *)operator new(24);
  _Right._Ptr = v7;
  LOBYTE(v29) = 13;
  if ( v7 )
    Font::Font(v7, eFontProportional, 14.0, 0, 1);
  else
    v8 = 0;
  LOBYTE(v29) = 11;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v8);
  std::shared_ptr<Font>::operator=(&this->dataFont, &_Right);
  v9 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v9->_Destroy(v9);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v9->_Weaks) )
        v9->_Delete_this(v9);
    }
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/remaining.png", 0x25u);
  v10 = this->sim;
  LOBYTE(v29) = 14;
  v11 = ResourceStore::getTexture(v10->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txRemainingTime.kid = v11->kid;
  LOBYTE(v29) = 15;
  if ( &this->txRemainingTime.fileName != &v11->fileName )
    std::wstring::assign(&this->txRemainingTime.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 14;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/conditions.png", 0x26u);
  v12 = this->sim;
  LOBYTE(v29) = 16;
  v13 = ResourceStore::getTexture(v12->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txTrackConditions.kid = v13->kid;
  LOBYTE(v29) = 17;
  if ( &this->txTrackConditions.fileName != &v13->fileName )
    std::wstring::assign(&this->txTrackConditions.fileName, &v13->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 16;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/time_of_day.png", 0x27u);
  v14 = this->sim;
  LOBYTE(v29) = 18;
  v15 = ResourceStore::getTexture(v14->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txTimeOfTheDay.kid = v15->kid;
  LOBYTE(v29) = 19;
  if ( &this->txTimeOfTheDay.fileName != &v15->fileName )
    std::wstring::assign(&this->txTimeOfTheDay.fileName, &v15->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 18;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/air_temp.png", 0x24u);
  v16 = this->sim;
  LOBYTE(v29) = 20;
  v17 = ResourceStore::getTexture(v16->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txAirTemperature.kid = v17->kid;
  LOBYTE(v29) = 21;
  if ( &this->txAirTemperature.fileName != &v17->fileName )
    std::wstring::assign(&this->txAirTemperature.fileName, &v17->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 20;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/asphalt_temp.png", 0x28u);
  v18 = this->sim;
  LOBYTE(v29) = 22;
  v19 = ResourceStore::getTexture(v18->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txAsphaltTemperature.kid = v19->kid;
  LOBYTE(v29) = 23;
  if ( &this->txAsphaltTemperature.fileName != &v19->fileName )
    std::wstring::assign(&this->txAsphaltTemperature.fileName, &v19->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 22;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"content/gui/raceControl/next_session.png", 0x28u);
  v20 = this->sim;
  LOBYTE(v29) = 24;
  v21 = ResourceStore::getTexture(v20->game->graphics->resourceStore._Myptr, &result, &iname, 0);
  this->txNextSession.kid = v21->kid;
  LOBYTE(v29) = 25;
  if ( &this->txNextSession.fileName != &v21->fileName )
    std::wstring::assign(&this->txNextSession.fileName, &v21->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 24;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v29) = 11;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/wind_indicator.png", 0x1Eu);
  v22 = this->sim;
  LOBYTE(v29) = 26;
  v23 = ResourceStore::getTexture(v22->game->graphics->resourceStore._Myptr, &v28, (const std::wstring *)&result, 0);
  this->txWindIndicator.kid = v23->kid;
  LOBYTE(v29) = 27;
  if ( &this->txWindIndicator.fileName != &v23->fileName )
    std::wstring::assign(&this->txWindIndicator.fileName, &v23->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v29) = 26;
  OnSetupAppCreated::~OnSetupAppCreated(&v28);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  *(_WORD *)&this->drawBorder = 0;
}
void RaceControlSessionInfo::~RaceControlSessionInfo(RaceControlSessionInfo *this)
{
  std::_Ref_count_base *v2; // esi
  std::_Ref_count_base *v3; // esi

  this->__vftable = (RaceControlSessionInfo_vtbl *)&RaceControlSessionInfo::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->txWindIndicator);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txNextSession);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txAsphaltTemperature);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txAirTemperature);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txTimeOfTheDay);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txTrackConditions);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txRemainingTime);
  v2 = this->dataFont._Rep;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Weaks, 0xFFFFFFFF) )
        v2->_Delete_this(v2);
    }
  }
  v3 = this->titleFont._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  ksgui::Control::~Control(this);
}
RaceControlSessionInfo *RaceControlSessionInfo::`scalar deleting destructor'(RaceControlSessionInfo *this, unsigned int a2)
{
  RaceControlSessionInfo::~RaceControlSessionInfo(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge RaceControlSessionInfo::render(RaceControlSessionInfo *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  RaceControlSessionInfo_vtbl *v5; // eax
  Sim *v6; // eax
  GLRenderer *v7; // ebp
  const std::wstring *v8; // eax
  Font *v9; // ecx
  unsigned int v10; // edi
  Sim *v11; // ecx
  Session *v12; // eax
  std::wstring *v13; // ecx
  std::wstring *v14; // eax
  wchar_t *v15; // eax
  std::wstring *v16; // ecx
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  const std::wstring *v19; // eax
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  Session *v23; // eax
  int v24; // ecx
  RaceManager *v25; // ecx
  Sim *v26; // ecx
  Session *v27; // esi
  int v28; // ecx
  std::wostream *v29; // eax
  long double v30; // st7
  const std::wstring *v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // eax
  float v34; // xmm0_4
  float v35; // xmm0_4
  const std::wstring *v36; // eax
  Font *v37; // ecx
  const std::wstring *v38; // eax
  Sim *v39; // ecx
  std::wostream *v40; // eax
  std::wostream *v41; // eax
  std::wostream *v42; // eax
  Texture *v43; // edi
  unsigned int v44; // esi
  unsigned int v45; // eax
  float v46; // xmm0_4
  float v47; // xmm0_4
  const std::wstring *v48; // eax
  Font *v49; // ecx
  __m128 v50; // xmm2
  float v51; // xmm4_4
  float v52; // xmm4_4
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  float v55; // xmm1_4
  float v56; // xmm1_4
  const std::wstring *v57; // eax
  std::wostream *v58; // eax
  std::wostream *v59; // eax
  std::wostream *v60; // eax
  std::wostream *v61; // esi
  int v62; // eax
  Texture *v63; // edi
  unsigned int v64; // esi
  unsigned int v65; // eax
  float v66; // xmm0_4
  float v67; // xmm0_4
  const std::wstring *v68; // eax
  Font *v69; // ecx
  int v70; // esi
  Sim *v71; // ecx
  const std::wstring *v72; // eax
  std::wostream *v73; // eax
  std::wostream *v74; // eax
  std::wostream *v75; // eax
  unsigned int v76; // edi
  unsigned int v77; // eax
  float v78; // xmm0_4
  float v79; // xmm0_4
  const std::wstring *v80; // eax
  Font *v81; // ecx
  std::wstring *v82; // eax
  const std::wstring *v83; // eax
  Sim *v84; // ecx
  std::wostream *v85; // eax
  std::wostream *v86; // eax
  std::wostream *v87; // eax
  const std::wstring *v88; // eax
  Font *v89; // ecx
  Texture *v90; // edi
  unsigned int v91; // eax
  unsigned int v92; // ecx
  float v93; // xmm0_4
  float v94; // xmm0_4
  int v95; // esi
  Sim *v96; // ecx
  const std::wstring *v97; // eax
  std::wostream *v98; // eax
  std::wostream *v99; // eax
  std::wostream *v100; // eax
  unsigned int v101; // edi
  unsigned int v102; // eax
  float v103; // xmm0_4
  float v104; // xmm0_4
  const std::wstring *v105; // eax
  Font *v106; // ecx
  Sim *v107; // ecx
  unsigned int v108; // esi
  unsigned int v109; // eax
  RaceManager *v110; // ecx
  int v111; // eax
  const std::wstring *v112; // eax
  std::wostream *v113; // eax
  float v114; // ecx
  float v115; // edi
  wchar_t *v116; // eax
  float v117; // ecx
  std::wostream *v118; // eax
  std::wostream *v119; // eax
  std::wostream *v120; // eax
  std::wostream *v121; // eax
  std::wostream *v122; // eax
  std::wostream *v123; // eax
  std::wostream *v124; // eax
  const std::wstring *v125; // eax
  Texture *v126; // edi
  unsigned int v127; // esi
  unsigned int v128; // eax
  float v129; // xmm0_4
  float v130; // xmm0_4
  const std::wstring *v131; // eax
  Font *v132; // ecx
  float r; // [esp+54h] [ebp-594h]
  float height; // [esp+58h] [ebp-590h]
  int heighta; // [esp+58h] [ebp-590h]
  float heightb; // [esp+58h] [ebp-590h]
  float heightc; // [esp+58h] [ebp-590h]
  int heightd; // [esp+58h] [ebp-590h]
  float heighte; // [esp+58h] [ebp-590h]
  int heightf; // [esp+58h] [ebp-590h]
  float heightg; // [esp+58h] [ebp-590h]
  float heighth; // [esp+58h] [ebp-590h]
  int b; // [esp+5Ch] [ebp-58Ch]
  int ba; // [esp+5Ch] [ebp-58Ch]
  const std::wstring *a; // [esp+60h] [ebp-588h]
  const char *aa; // [esp+60h] [ebp-588h]
  const char *ab; // [esp+60h] [ebp-588h]
  const char *ac; // [esp+60h] [ebp-588h]
  const std::wstring *ad; // [esp+60h] [ebp-588h]
  const std::wstring *ae; // [esp+60h] [ebp-588h]
  __int64 v151; // [esp+64h] [ebp-584h]
  const char *v152; // [esp+64h] [ebp-584h]
  float v153; // [esp+6Ch] [ebp-57Ch]
  ksgui::ksRect wrect; // [esp+90h] [ebp-558h] BYREF
  int v155; // [esp+A0h] [ebp-548h]
  unsigned int v156; // [esp+A4h] [ebp-544h]
  double result; // [esp+A8h] [ebp-540h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > data; // [esp+B0h] [ebp-538h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v159; // [esp+160h] [ebp-488h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v160; // [esp+210h] [ebp-3D8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v161; // [esp+2C0h] [ebp-328h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v162; // [esp+370h] [ebp-278h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v163; // [esp+420h] [ebp-1C8h] BYREF
  Session nsi; // [esp+4D0h] [ebp-118h] BYREF
  std::wstring text; // [esp+530h] [ebp-B8h] BYREF
  std::wstring sessionName; // [esp+548h] [ebp-A0h] BYREF
  TemperatureInfo ti; // [esp+560h] [ebp-88h] BYREF
  int v168; // [esp+570h] [ebp-78h]
  unsigned int v169; // [esp+574h] [ebp-74h]
  Session v170; // [esp+578h] [ebp-70h] BYREF
  int v171; // [esp+5E0h] [ebp-8h]
  int v172; // [esp+5E4h] [ebp-4h]
  int retaddr; // [esp+5E8h] [ebp+0h]

  LODWORD(result) = 0;
  ksgui::Control::render(this, a2, a3, dt, v151, v153);
  v5 = this->__vftable;
  wrect.left = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v5->getWorldRect(this, &wrect);
  v6 = this->sim;
  wrect.left = this->rect.left + wrect.left;
  wrect.top = this->rect.top + wrect.top;
  v7 = v6->game->graphics->gl;
  GLRenderer::color4f(v7, colTitleBar_6.x, colTitleBar_6.y, colTitleBar_6.z, colTitleBar_6.w);
  GLRenderer::quad(v7, wrect.left, wrect.top, this->rect.right - this->rect.left, 20.0, 0, 0);
  Font::setColor(this->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  sessionName._Myres = 7;
  sessionName._Mysize = 0;
  sessionName._Bx._Buf[0] = 0;
  std::wstring::assign(&sessionName, L"SESSION INFORMATION", 0x13u);
  v172 = 0;
  v8 = acTranslate((std::wstring *)&ti, &sessionName);
  v9 = this->titleFont._Ptr;
  LOBYTE(v172) = 1;
  Font::blitString(v9, wrect.left + 10.0, wrect.top + 1.0, v8, 1.0, eAlignLeft);
  if ( v169 >= 8 )
    operator delete(LODWORD(ti.ambientTemperature));
  v169 = 7;
  v168 = 0;
  LOWORD(ti.ambientTemperature) = 0;
  v172 = -1;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  wrect.top = wrect.top + 20.0;
  GLRenderer::color4f(v7, colDarkBar_6.x, colDarkBar_6.y, colDarkBar_6.z, colDarkBar_6.w);
  GLRenderer::quad(v7, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)data.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)data.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(data.gap68);
  v172 = 2;
  v10 = 2;
  v156 = 2;
  LODWORD(result) = 2;
  std::wiostream::basic_iostream<wchar_t>(&data, &data.gap10[8], 0);
  v172 = 3;
  *(_DWORD *)&data.gap0[*(_DWORD *)(*(_DWORD *)data.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&result + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)data.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&data.gap10[8]);
  *(_DWORD *)&data.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&data.gap10[64] = 0;
  *(_DWORD *)&data.gap10[68] = 0;
  v11 = this->sim;
  v172 = 5;
  v12 = RaceManager::getCurrentSession(v11->raceManager, &nsi);
  std::wstring::wstring(&sessionName, &v12->name);
  LOBYTE(v172) = 6;
  if ( nsi.name._Myres >= 8 )
    operator delete(nsi.name._Bx._Ptr);
  nsi.name._Myres = 7;
  nsi.name._Mysize = 0;
  nsi.name._Bx._Buf[0] = 0;
  if ( nsi.spawSet._Myres >= 8 )
    operator delete(nsi.spawSet._Bx._Ptr);
  v13 = &sessionName;
  nsi.spawSet._Bx._Buf[0] = 0;
  v14 = &sessionName;
  nsi.spawSet._Myres = 7;
  if ( sessionName._Myres >= 8 )
    v14 = (std::wstring *)sessionName._Bx._Ptr;
  nsi.spawSet._Mysize = 0;
  if ( sessionName._Myres >= 8 )
    v13 = (std::wstring *)sessionName._Bx._Ptr;
  LODWORD(result) = v14;
  v15 = &v13->_Bx._Buf[sessionName._Mysize];
  v16 = &sessionName;
  if ( sessionName._Myres >= 8 )
    v16 = (std::wstring *)sessionName._Bx._Ptr;
  if ( v16 != (std::wstring *)v15 )
    std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&result,
      v16->_Bx._Buf,
      v15,
      LODWORD(result),
      _toupper);
  result = RaceManager::getTimeToSessionStart(this->sim->raceManager);
  v169 = 7;
  v168 = 0;
  LOWORD(ti.ambientTemperature) = 0;
  if ( result > 0.0 )
  {
    std::wstring::assign((std::wstring *)&ti, L"not started", 0xBu);
    LOBYTE(v172) = 7;
    a = acTranslate(&text, (const std::wstring *)&ti);
    LOBYTE(v172) = 8;
    v17 = std::operator<<<wchar_t>((std::wostream *)data.gap10, &sessionName);
    v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, " ");
    std::operator<<<wchar_t>(v18, a);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    LOBYTE(v172) = 6;
    if ( v169 >= 8 )
      operator delete(LODWORD(ti.ambientTemperature));
    goto LABEL_44;
  }
  std::wstring::assign((std::wstring *)&ti, L"remaining", 9u);
  LOBYTE(v172) = 9;
  v19 = acTranslate(&text, (const std::wstring *)&ti);
  LOBYTE(v172) = 10;
  v20 = std::operator<<<wchar_t>((std::wostream *)data.gap10, v19);
  v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, ": ");
  v22 = std::operator<<<wchar_t>(v21, &sessionName);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v22, " - ");
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 6;
  if ( v169 >= 8 )
    operator delete(LODWORD(ti.ambientTemperature));
  if ( RaceManager::getCurrentSessionType(this->sim->raceManager) != Race )
  {
    v24 = 2;
    goto LABEL_30;
  }
  v23 = RaceManager::getCurrentSession(this->sim->raceManager, &v170);
  v24 = 3;
  v156 = 3;
  if ( v23->isTimedRace )
  {
LABEL_30:
    HIBYTE(v155) = 0;
    goto LABEL_31;
  }
  HIBYTE(v155) = 1;
LABEL_31:
  if ( (v24 & 1) != 0 )
  {
    v156 = v24 & 0xFFFFFFFE;
    Session::~Session(&v170);
  }
  v25 = this->sim->raceManager;
  if ( HIBYTE(v155) )
  {
    RaceManager::getLeaderboard(v25, (std::vector<LeaderboardEntry> *)&ti);
    v26 = this->sim;
    LOBYTE(v172) = 11;
    v27 = RaceManager::getCurrentSession(v26->raceManager, &v170);
    LOBYTE(v172) = 12;
    v28 = v27->laps - RaceManager::getLapCount(this->sim->raceManager, *(CarAvatar **)LODWORD(ti.ambientTemperature));
    if ( v28 <= 9999 )
    {
      if ( v28 < 0 )
        v28 = 0;
    }
    else
    {
      v28 = 9999;
    }
    v29 = (std::wostream *)std::wostream::operator<<(data.gap10, v28);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v29, " L");
    Session::~Session(&v170);
    LOBYTE(v172) = 6;
    if ( LODWORD(ti.ambientTemperature) )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&ti);
      operator delete(LODWORD(ti.ambientTemperature));
    }
  }
  else
  {
    result = RaceManager::getSessionTimeLeft(v25);
    if ( result > 0.0 )
    {
      v30 = RaceManager::getSessionTimeLeft(this->sim->raceManager);
      v31 = timeToWString(&text, (int)v30, 0, 0);
      LOBYTE(v172) = 13;
      std::operator<<<wchar_t>((std::wostream *)data.gap10, v31);
      LOBYTE(v172) = 6;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
  }
  v10 = v156;
LABEL_44:
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txRemainingTime);
  if ( this->txRemainingTime.kid )
    v32 = kglTextureGetHeight(this->txRemainingTime.kid);
  else
    v32 = 0;
  if ( this->txRemainingTime.kid )
    v33 = kglTextureGetWidth(this->txRemainingTime.kid);
  else
    v33 = 0;
  v34 = (float)v32;
  height = v34;
  v35 = (float)v33;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v35, height, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &text);
  v37 = this->dataFont._Ptr;
  LOBYTE(v172) = 14;
  Font::blitString(v37, wrect.left + 30.0, wrect.top + 6.0999999, v36, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  wrect.top = wrect.top + 30.5;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  sessionName._Myres = 7;
  sessionName._Bx._Buf[0] = 0;
  sessionName._Mysize = 0;
  v172 = -1;
  *(_DWORD *)&data.gap0[*(_DWORD *)(*(_DWORD *)data.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&result + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)data.gap0 + 4) - 104;
  *(_DWORD *)&data.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&data.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&data.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&data.gap10[20]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&data.gap68[4]);
  GLRenderer::color4f(v7, colDarkTransp_5.x, colDarkTransp_5.y, colDarkTransp_5.z, colDarkTransp_5.w);
  GLRenderer::quad(v7, wrect.right, wrect.bottom, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)&v160.gap0[4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)&v160.gap10[4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(&v160.gap68[4]);
  retaddr = 15;
  LODWORD(result) = v10 | 4;
  HIDWORD(result) = v10 | 4;
  std::wiostream::basic_iostream<wchar_t>(&v160.gap0[4], &v160.gap10[12], 0);
  v171 = 16;
  *(_DWORD *)&v159.gap68[*(_DWORD *)(*(_DWORD *)&v159.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v159.gap68[*(_DWORD *)(*(_DWORD *)&v159.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v159.gap68[68] + 4)
                                                                           - 104;
  std::wstreambuf::wstreambuf(&v160.gap10[4]);
  *(_DWORD *)&v160.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v160.gap10[60] = 0;
  *(_DWORD *)&v160.gap10[64] = 0;
  v171 = 18;
  sessionName._Mysize = 7;
  *(_DWORD *)&sessionName._Bx._Alias[12] = 0;
  LOWORD(text._Myres) = 0;
  std::wstring::assign((std::wstring *)&text._Myres, L"track grip", 0xAu);
  LOBYTE(v171) = 19;
  v38 = acTranslate((std::wstring *)(&nsi.leaderCompletedLaps + 1), (const std::wstring *)&text._Myres);
  v39 = this->sim;
  LOBYTE(v171) = 20;
  heighta = (int)(float)(v39->physicsAvatar->engine.track->dynamicGripLevel * 100.0);
  v40 = std::operator<<<wchar_t>((std::wostream *)((char *)&v160._Chcount + 4), v38);
  v41 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v40, ": ");
  v42 = (std::wostream *)std::wostream::operator<<(v41, heighta);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v42, aa);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 18;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  v43 = &this->txTrackConditions;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txTrackConditions);
  if ( this->txTrackConditions.kid )
    v44 = kglTextureGetHeight(v43->kid);
  else
    v44 = 0;
  if ( v43->kid )
    v45 = kglTextureGetWidth(v43->kid);
  else
    v45 = 0;
  v46 = (float)v44;
  heightb = v46;
  v47 = (float)v45;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v47, heightb, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v48 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v160, &text);
  v49 = this->dataFont._Ptr;
  LOBYTE(v172) = 21;
  Font::blitString(v49, wrect.left + 30.0, wrect.top + 6.0999999, v48, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v172 = -1;
  wrect.top = wrect.top + 30.5;
  *(_DWORD *)&v160.gap0[*(_DWORD *)(*(_DWORD *)v160.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v159.gap68[*(_DWORD *)(*(_DWORD *)v160.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v160.gap0 + 4) - 104;
  *(_DWORD *)&v160.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v160.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v160.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v160.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v160.gap68);
  GLRenderer::color4f(v7, colDarkBar_6.x, colDarkBar_6.y, colDarkBar_6.z, colDarkBar_6.w);
  GLRenderer::quad(v7, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  v50.m128_f32[0] = FLOAT_8388608_0;
  v51 = this->sim->game->graphics->lightingSettings.angle;
  *(_DWORD *)v159.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v159.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v52 = (float)((float)(v51 + 80.0) * 0.0625) + 8.0;
  v53.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v54.m128_i32[0] = LODWORD(v52) ^ LODWORD(FLOAT_N0_0) & LODWORD(v52);
  v54.m128_f32[0] = _mm_cmplt_ss(v54, v50).m128_f32[0];
  v55 = (float)(v52 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v54.m128_i32[0] | v53.m128_i32[0]))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v54.m128_i32[0] | v53.m128_i32[0]);
  v54.m128_f32[0] = v55 - v52;
  v56 = v55 - COERCE_FLOAT(_mm_cmpgt_ss(v54, v53).m128_u32[0] & LODWORD(FLOAT_1_0));
  std::wios::wios(v159.gap68);
  v172 = 22;
  v156 |= 8u;
  LODWORD(result) = v156;
  std::wiostream::basic_iostream<wchar_t>(&v159, &v159.gap10[8], 0);
  v172 = 23;
  *(_DWORD *)&v159.gap0[*(_DWORD *)(*(_DWORD *)v159.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&data.gap68[*(_DWORD *)(*(_DWORD *)v159.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v159.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v159.gap10[8]);
  *(_DWORD *)&v159.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v159.gap10[64] = 0;
  *(_DWORD *)&v159.gap10[68] = 0;
  v172 = 25;
  sessionName._Myres = 7;
  sessionName._Mysize = 0;
  sessionName._Bx._Buf[0] = 0;
  std::wstring::assign(&sessionName, L"time", 4u);
  LOBYTE(v172) = 26;
  v57 = acTranslate(&text, &sessionName);
  LOBYTE(v172) = 27;
  v58 = std::operator<<<wchar_t>((std::wostream *)v159.gap10, v57);
  v59 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v58, ": ");
  v60 = (std::wostream *)std::wostream::operator<<(v59, (int)v56);
  v61 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v60, v152);
  *(_WORD *)&v61->gap0[*(_DWORD *)(*(_DWORD *)v61->gap0 + 4) + 64] = 48;
  v62 = std::setw(&ti.roadTemperature, 2, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v62)(
    &v61->gap0[*(_DWORD *)(*(_DWORD *)v61->gap0 + 4)],
    *(_DWORD *)(v62 + 8),
    *(_DWORD *)(v62 + 12));
  std::wostream::operator<<(v61, (int)(float)((float)(v52 - v56) * 60.0));
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 25;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  v63 = &this->txTimeOfTheDay;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txTimeOfTheDay);
  if ( this->txTimeOfTheDay.kid )
    v64 = kglTextureGetHeight(v63->kid);
  else
    v64 = 0;
  if ( v63->kid )
    v65 = kglTextureGetWidth(v63->kid);
  else
    v65 = 0;
  v66 = (float)v64;
  heightc = v66;
  v67 = (float)v65;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v67, heightc, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v159, &text);
  v69 = this->dataFont._Ptr;
  LOBYTE(v172) = 28;
  Font::blitString(v69, wrect.left + 30.0, wrect.top + 6.0999999, v68, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v172 = -1;
  wrect.top = wrect.top + 30.5;
  *(_DWORD *)&v159.gap0[*(_DWORD *)(*(_DWORD *)v159.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&data.gap68[*(_DWORD *)(*(_DWORD *)v159.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v159.gap0 + 4) - 104;
  *(_DWORD *)&v159.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v159.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v159.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v159.gap10[20]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v159.gap68[4]);
  GLRenderer::color4f(v7, colDarkTransp_5.x, colDarkTransp_5.y, colDarkTransp_5.z, colDarkTransp_5.w);
  GLRenderer::quad(v7, wrect.right, wrect.bottom, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)&v162.gap0[4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)&v162.gap10[4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(&v162.gap68[4]);
  v70 = LODWORD(result) | 0x10;
  retaddr = 29;
  HIDWORD(result) = LODWORD(result) | 0x10;
  std::wiostream::basic_iostream<wchar_t>(&v162.gap0[4], &v162.gap10[12], 0);
  v171 = 30;
  *(_DWORD *)&v161.gap68[*(_DWORD *)(*(_DWORD *)&v161.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v161.gap68[*(_DWORD *)(*(_DWORD *)&v161.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v161.gap68[68] + 4)
                                                                           - 104;
  std::wstreambuf::wstreambuf(&v162.gap10[4]);
  *(_DWORD *)&v162.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v162.gap10[60] = 0;
  *(_DWORD *)&v162.gap10[64] = 0;
  v71 = this->sim;
  v171 = 32;
  PhysicsAvatar::getTemperatureInfo(v71->physicsAvatar, (TemperatureInfo *)&sessionName._Myres);
  sessionName._Mysize = 7;
  *(_DWORD *)&sessionName._Bx._Alias[12] = 0;
  LOWORD(text._Myres) = 0;
  std::wstring::assign((std::wstring *)&text._Myres, L"air", 3u);
  LOBYTE(v171) = 33;
  v72 = acTranslate((std::wstring *)(&nsi.leaderCompletedLaps + 1), (const std::wstring *)&text._Myres);
  LOBYTE(v171) = 34;
  heightd = (int)*(float *)&sessionName._Myres;
  v73 = std::operator<<<wchar_t>((std::wostream *)((char *)&v162._Chcount + 4), v72);
  v74 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v73, ": ");
  v75 = (std::wostream *)std::wostream::operator<<(v74, heightd);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v75, ab);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 32;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txAirTemperature);
  if ( this->txAirTemperature.kid )
    v76 = kglTextureGetHeight(this->txAirTemperature.kid);
  else
    v76 = 0;
  if ( this->txAirTemperature.kid )
    v77 = kglTextureGetWidth(this->txAirTemperature.kid);
  else
    v77 = 0;
  v78 = (float)v76;
  heighte = v78;
  v79 = (float)v77;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v79, heighte, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v80 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v162, &text);
  v81 = this->dataFont._Ptr;
  LOBYTE(v172) = 35;
  Font::blitString(v81, wrect.left + 30.0, wrect.top + 6.0999999, v80, 1.0, eAlignLeft);
  LOBYTE(v172) = 32;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  std::wstring::wstring(&sessionName, word_17BE9D8);
  LOBYTE(v172) = 36;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v162.gap10[8]);
  v82 = &sessionName;
  if ( sessionName._Myres >= 8 )
    v82 = (std::wstring *)sessionName._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v162.gap10[8], v82->_Bx._Buf, sessionName._Mysize, *(int *)&v162.gap10[68]);
  LOBYTE(v172) = 32;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  std::wstring::wstring(&sessionName, L"wind");
  LOBYTE(v172) = 37;
  v83 = acTranslate(&text, &sessionName);
  v84 = this->sim;
  LOBYTE(v172) = 38;
  b = (int)(float)(v84->physicsAvatar->windData.speed.value * 3.5999999);
  v85 = std::operator<<<wchar_t>((std::wostream *)v162.gap10, v83);
  v86 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v85, ": ");
  v87 = (std::wostream *)std::wostream::operator<<(v86, b);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v87, " km/h");
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 32;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  v88 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v162, &text);
  v89 = this->dataFont._Ptr;
  LOBYTE(v172) = 39;
  Font::blitString(v89, wrect.left + 170.0, wrect.top + 6.0999999, v88, 1.0, eAlignLeft);
  LOBYTE(v172) = 32;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v90 = &this->txWindIndicator;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txWindIndicator);
  if ( this->txWindIndicator.kid )
    v91 = kglTextureGetHeight(v90->kid);
  else
    v91 = 0;
  LODWORD(result) = v91;
  if ( v90->kid )
    v92 = kglTextureGetWidth(v90->kid);
  else
    v92 = 0;
  v93 = (float)LODWORD(result);
  r = v93;
  v94 = (float)v92;
  GLRenderer::quadCentredRotated(
    v7,
    v70,
    wrect.left + 155.0,
    wrect.top + 15.0,
    v94,
    r,
    this->sim->physicsAvatar->windData.directionDEG * 0.017453,
    1,
    0);
  v172 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v162);
  GLRenderer::color4f(v7, colDarkBar_6.x, colDarkBar_6.y, colDarkBar_6.z, colDarkBar_6.w);
  GLRenderer::quad(v7, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)v163.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v163.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v163.gap68);
  retaddr = 40;
  v95 = v70 | 0x20;
  HIDWORD(result) = v95;
  std::wiostream::basic_iostream<wchar_t>(&v163.gap0[4], &v163.gap10[12], 0);
  v171 = 41;
  *(_DWORD *)&v162.gap68[*(_DWORD *)(*(_DWORD *)&v162.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v162.gap68[*(_DWORD *)(*(_DWORD *)&v162.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v162.gap68[68] + 4)
                                                                           - 104;
  std::wstreambuf::wstreambuf(&v163.gap10[4]);
  *(_DWORD *)&v163.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v163.gap10[60] = 0;
  *(_DWORD *)&v163.gap10[64] = 0;
  v96 = this->sim;
  v171 = 43;
  PhysicsAvatar::getTemperatureInfo(v96->physicsAvatar, (TemperatureInfo *)&sessionName._Myres);
  std::wstring::wstring((std::wstring *)&text._Myres, L"asphalt");
  LOBYTE(v171) = 44;
  v97 = acTranslate((std::wstring *)(&nsi.leaderCompletedLaps + 1), (const std::wstring *)&text._Myres);
  LOBYTE(v171) = 45;
  heightf = (int)ti.ambientTemperature;
  v98 = std::operator<<<wchar_t>((std::wostream *)((char *)&v163._Chcount + 4), v97);
  v99 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v98, ": ");
  v100 = (std::wostream *)std::wostream::operator<<(v99, heightf);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v100, ac);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v172) = 43;
  if ( sessionName._Myres >= 8 )
    operator delete(sessionName._Bx._Ptr);
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txAsphaltTemperature);
  if ( this->txAsphaltTemperature.kid )
    v101 = kglTextureGetHeight(this->txAsphaltTemperature.kid);
  else
    v101 = 0;
  if ( this->txAsphaltTemperature.kid )
    v102 = kglTextureGetWidth(this->txAsphaltTemperature.kid);
  else
    v102 = 0;
  v103 = (float)v101;
  heightg = v103;
  v104 = (float)v102;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v104, heightg, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v105 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v163, &text);
  v106 = this->dataFont._Ptr;
  LOBYTE(v172) = 46;
  Font::blitString(v106, wrect.left + 30.0, wrect.top + 6.0999999, v105, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v172 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v163);
  GLRenderer::color4f(v7, colDarkTransp_5.x, colDarkTransp_5.y, colDarkTransp_5.z, colDarkTransp_5.w);
  GLRenderer::quad(v7, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)v161.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v161.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v161.gap68);
  v172 = 47;
  LODWORD(result) = v95 | 0x40;
  std::wiostream::basic_iostream<wchar_t>(&v161, &v161.gap10[8], 0);
  v172 = 48;
  *(_DWORD *)&v161.gap0[*(_DWORD *)(*(_DWORD *)v161.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v160.gap68[*(_DWORD *)(*(_DWORD *)v161.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v161.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v161.gap10[8]);
  *(_DWORD *)&v161.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v161.gap10[64] = 0;
  *(_DWORD *)&v161.gap10[68] = 0;
  v107 = this->sim;
  v172 = 50;
  v108 = RaceManager::getCurrentSessionIndex(v107->raceManager) + 1;
  v109 = RaceManager::getSessionCount(this->sim->raceManager);
  v110 = this->sim->raceManager;
  if ( v108 >= v109 )
  {
    if ( RaceManager::getSessionCount(v110) == 1 )
    {
      std::wstring::wstring(&sessionName, L"single session");
      LOBYTE(v172) = 57;
      v125 = acTranslate(&text, &sessionName);
      LOBYTE(v172) = 58;
    }
    else
    {
      std::wstring::wstring(&sessionName, L"last session");
      LOBYTE(v172) = 59;
      v125 = acTranslate(&text, &sessionName);
      LOBYTE(v172) = 60;
    }
    std::operator<<<wchar_t>((std::wostream *)v161.gap10, v125);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v172) = 50;
    text._Bx._Buf[0] = 0;
    text._Mysize = 0;
    text._Myres = 7;
    if ( sessionName._Myres >= 8 )
      operator delete(sessionName._Bx._Ptr);
  }
  else
  {
    v111 = RaceManager::getCurrentSessionIndex(v110);
    RaceManager::getSessionInfo(this->sim->raceManager, &nsi, v111 + 1);
    LOBYTE(v172) = 51;
    std::wstring::wstring(&sessionName, L"next session");
    LOBYTE(v172) = 52;
    v112 = acTranslate(&text, &sessionName);
    LOBYTE(v172) = 53;
    v113 = std::operator<<<wchar_t>((std::wostream *)v161.gap10, v112);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v113, ": ");
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    LOBYTE(v172) = 51;
    if ( sessionName._Myres >= 8 )
      operator delete(sessionName._Bx._Ptr);
    v169 = 7;
    LOWORD(ti.ambientTemperature) = 0;
    v168 = 0;
    std::wstring::assign((std::wstring *)&ti, &nsi.name, 0, 0xFFFFFFFF);
    v114 = COERCE_FLOAT(&ti);
    v115 = COERCE_FLOAT(&ti);
    LOBYTE(v172) = 54;
    if ( v169 >= 8 )
      v114 = ti.ambientTemperature;
    if ( v169 >= 8 )
      v115 = ti.ambientTemperature;
    v116 = (wchar_t *)(LODWORD(v114) + 2 * v168);
    v117 = COERCE_FLOAT(&ti);
    if ( v169 >= 8 )
      v117 = ti.ambientTemperature;
    if ( (wchar_t *)LODWORD(v117) != v116 )
      std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&result,
        (wchar_t *)LODWORD(v117),
        v116,
        LODWORD(v115),
        _toupper);
    if ( nsi.sessionType == Race )
    {
      if ( nsi.isTimedRace )
      {
        ad = timeToWString(&text, (int)(float)(nsi.durationMinutes * 60000.0), 1, 0);
        LOBYTE(v172) = 55;
        v118 = std::operator<<<wchar_t>((std::wostream *)v161.gap10, (const std::wstring *)&ti);
        v119 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v118, " - ");
        std::operator<<<wchar_t>(v119, ad);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      }
      else
      {
        ba = nsi.laps;
        v120 = std::operator<<<wchar_t>((std::wostream *)v161.gap10, (const std::wstring *)&ti);
        v121 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v120, " - ");
        v122 = (std::wostream *)std::wostream::operator<<(v121, ba);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v122, " L");
      }
    }
    else
    {
      ae = timeToWString(&text, (int)(float)(nsi.durationMinutes * 60000.0), 1, 0);
      LOBYTE(v172) = 56;
      v123 = std::operator<<<wchar_t>((std::wostream *)v161.gap10, (const std::wstring *)&ti);
      v124 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v123, " - ");
      std::operator<<<wchar_t>(v124, ae);
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    if ( v169 >= 8 )
      operator delete(LODWORD(ti.ambientTemperature));
    v169 = 7;
    v168 = 0;
    LOWORD(ti.ambientTemperature) = 0;
    LOBYTE(v172) = 50;
    Session::~Session(&nsi);
  }
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, 1.0);
  v126 = &this->txNextSession;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->txNextSession);
  if ( this->txNextSession.kid )
    v127 = kglTextureGetHeight(v126->kid);
  else
    v127 = 0;
  if ( v126->kid )
    v128 = kglTextureGetWidth(v126->kid);
  else
    v128 = 0;
  v129 = (float)v127;
  heighth = v129;
  v130 = (float)v128;
  GLRenderer::quad(v7, wrect.left + 5.0, wrect.top + 8.0, v130, heighth, 1, 0);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v131 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v161, &text);
  v132 = this->dataFont._Ptr;
  LOBYTE(v172) = 61;
  Font::blitString(v132, wrect.left + 30.0, wrect.top + 6.0999999, v131, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v161);
}
