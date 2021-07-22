#include "acdriverperformance.h
void __userpurge ACDriverPerformance::ACDriverPerformance(ACDriverPerformance *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar)
{
  std::wstring *v4; // ebx
  std::wstring *v5; // ebp
  const std::wstring *v6; // eax
  std::wstring *v7; // eax
  int v8; // eax
  char v9; // al
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  CarAvatar *v17; // ebx
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  unsigned int *v20; // eax
  unsigned __int64 v21; // xmm2_8
  float v22; // eax
  wchar_t *v23; // eax
  Font *v24; // eax
  std::_Ref_count_base *v25; // ebx
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  DriverInfo *v28; // eax
  double v29; // st7
  bool v30; // cf
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  const perf *v35; // eax
  const perf *v36; // eax
  const perf *v37; // eax
  const perf *v38; // eax
  const perf *v39; // eax
  const perf *v40; // eax
  const perf *v41; // eax
  const perf *v42; // eax
  const perf *v43; // eax
  _BYTE w[28]; // [esp-Ch] [ebp-1A8h] BYREF
  float h; // [esp+10h] [ebp-18Ch]
  int v46; // [esp+28h] [ebp-174h]
  CarAvatar *v47; // [esp+2Ch] [ebp-170h]
  ACDriverPerformance *v48; // [esp+30h] [ebp-16Ch]
  std::wstring result; // [esp+34h] [ebp-168h] BYREF
  std::wstring v50; // [esp+4Ch] [ebp-150h] BYREF
  std::wstring key; // [esp+64h] [ebp-138h] BYREF
  std::wstring text; // [esp+7Ch] [ebp-120h] BYREF
  perf v53; // [esp+94h] [ebp-108h] BYREF
  std::wstring v54; // [esp+E8h] [ebp-B4h] BYREF
  std::wstring aName; // [esp+100h] [ebp-9Ch] BYREF
  std::wstring v56; // [esp+118h] [ebp-84h] BYREF
  std::wstring v57; // [esp+130h] [ebp-6Ch] BYREF
  INIReader r; // [esp+148h] [ebp-54h] BYREF
  int v59; // [esp+198h] [ebp-4h]

  v47 = aCar;
  h = 0.0;
  v48 = this;
  *(_DWORD *)&w[24] = aCar->sim->game->gui;
  *(_DWORD *)&w[20] = 7;
  *(_DWORD *)&w[16] = 0;
  *(_WORD *)w = 0;
  std::wstring::assign((std::wstring *)w, L"ACDriverPerformance", 0x13u);
  ksgui::Form::Form(this, a2, *(std::wstring *)w, *(ksgui::GUI **)&w[24], SLOBYTE(h));
  v59 = 0;
  this->__vftable = (ACDriverPerformance_vtbl *)&ACDriverPerformance::`vftable';
  this->perfs._Myfirst = 0;
  this->perfs._Mylast = 0;
  this->perfs._Myend = 0;
  this->previousCarPosition.x = 0.0;
  this->previousCarPosition.y = 0.0;
  this->previousCarPosition.z = 0.0;
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  v4 = &this->trackConfigName;
  this->trackConfigName._Myres = 7;
  this->trackConfigName._Mysize = 0;
  this->trackConfigName._Bx._Buf[0] = 0;
  this->driverName._Myres = 7;
  this->driverName._Mysize = 0;
  this->driverName._Bx._Buf[0] = 0;
  v5 = &this->fileName;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  LOBYTE(v59) = 6;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Driver performances", 0x13u);
  LOBYTE(v59) = 7;
  v6 = acTranslate(&result, &text);
  LOBYTE(v59) = 8;
  this->formTitle->setText(this->formTitle, v6);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v59) = 6;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v7 = TrackAvatar::getConfig(v47->sim->track, &key);
  LOBYTE(v59) = 9;
  v8 = std::wstring::compare(v7, 0, v7->_Mysize, word_17BE9D8, 0);
  LOBYTE(v59) = 6;
  v9 = v8 != 0;
  HIBYTE(v46) = v9;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v9 = HIBYTE(v46);
  }
  if ( v9 )
  {
    v10 = TrackAvatar::getConfig(v47->sim->track, &key);
    LOBYTE(v59) = 10;
    v11 = std::operator+<wchar_t>(&result, v10, L"/");
    v50._Bx._Ptr = (wchar_t *)v11;
    if ( v4 != v11 )
    {
      if ( this->trackConfigName._Myres >= 8 )
      {
        operator delete(v4->_Bx._Ptr);
        v11 = (std::wstring *)v50._Bx._Ptr;
      }
      this->trackConfigName._Myres = 7;
      this->trackConfigName._Mysize = 0;
      v4->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->trackConfigName, v11);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v59) = 6;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v12 = Path::getDocumentPath(&v57);
  LOBYTE(v59) = 11;
  v13 = std::operator+<wchar_t>(&key, v12, L"/Assetto Corsa/savedData/driverPerformances/");
  LOBYTE(v59) = 12;
  v14 = std::operator+<wchar_t>(&aName, v13, &v47->sim->track->name);
  LOBYTE(v59) = 13;
  v15 = std::operator+<wchar_t>(&v56, v14, L"/");
  LOBYTE(v59) = 14;
  v16 = std::operator+<wchar_t>(&v54, v15, &this->trackConfigName);
  v17 = v47;
  LOBYTE(v59) = 15;
  v18 = std::operator+<wchar_t>(&text, v16, &v47->unixName);
  LOBYTE(v59) = 16;
  v19 = std::operator+<wchar_t>(&result, v18, L".ini");
  v50._Bx._Ptr = (wchar_t *)v19;
  if ( v5 != v19 )
  {
    if ( this->fileName._Myres >= 8 )
    {
      operator delete(v5->_Bx._Ptr);
      v19 = (std::wstring *)v50._Bx._Ptr;
    }
    this->fileName._Myres = 7;
    this->fileName._Mysize = 0;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->fileName, v19);
  }
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
  if ( v54._Myres >= 8 )
    operator delete(v54._Bx._Ptr);
  v54._Myres = 7;
  v54._Mysize = 0;
  v54._Bx._Buf[0] = 0;
  if ( v56._Myres >= 8 )
    operator delete(v56._Bx._Ptr);
  v56._Myres = 7;
  v56._Mysize = 0;
  v56._Bx._Buf[0] = 0;
  if ( aName._Myres >= 8 )
    operator delete(aName._Bx._Ptr);
  aName._Myres = 7;
  aName._Mysize = 0;
  aName._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v59) = 6;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  this->version = 2;
  this->car = v17;
  v20 = (unsigned int *)v17->bodyTransform;
  h = 570.0;
  *(_DWORD *)&w[24] = 1141473280;
  v21 = _mm_unpacklo_ps((__m128)v20[13], (__m128)v20[14]).m128_u64[0];
  *(_DWORD *)&v50._Bx._Alias[8] = v20[15];
  v22 = *(float *)&v50._Bx._Alias[8];
  *(_QWORD *)&this->previousCarPosition.x = v21;
  this->previousCarPosition.z = v22;
  this->stopLimit = 1.0;
  this->timeToWait = 5.0;
  this->waitingTime = 0.0;
  this->currentDistance = 0.0;
  ksgui::Form::setSize(this, *(float *)&w[24], h);
  LODWORD(h) = 24;
  this->stringFontSize = 15.0;
  this->secondsFontSize = 24.0;
  this->brakeThreshold = 0.1;
  v23 = (wchar_t *)operator new(LODWORD(h));
  v50._Bx._Ptr = v23;
  LOBYTE(v59) = 17;
  if ( v23 )
    Font::Font((Font *)v23, eFontMonospaced, 10.0, 0, 0);
  else
    v24 = 0;
  LOBYTE(v59) = 6;
  *(_QWORD *)v50._Bx._Buf = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&v50, v24);
  v25 = this->font._Rep;
  this->font = *(std::shared_ptr<Font> *)v50._Bx._Buf;
  if ( v25 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v25->_Uses, 0xFFFFFFFF) )
    {
      v25->_Destroy(v25);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v25->_Weaks) )
        v25->_Delete_this(v25);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
  v26 = &this->car->unixName;
  if ( &this->carName != v26 )
    std::wstring::assign(&this->carName, v26, 0, 0xFFFFFFFF);
  v27 = &this->car->sim->track->name;
  if ( &this->trackName != v27 )
    std::wstring::assign(&this->trackName, v27, 0, 0xFFFFFFFF);
  v28 = &this->car->driverInfo;
  if ( &this->driverName != (std::wstring *)v28 )
    std::wstring::assign(&this->driverName, &v28->name, 0, 0xFFFFFFFF);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"system/cfg/driver_performances.ini", 0x22u);
  LOBYTE(v59) = 18;
  INIReader::INIReader(&r, &text);
  LOBYTE(v59) = 20;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"STRING_FONT_SIZE", 0x10u);
    LOBYTE(v59) = 21;
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    std::wstring::assign(&v50, L"MAIN", 4u);
    LOBYTE(v59) = 22;
    v29 = INIReader::getFloat(&r, &v50, &result);
    v30 = v50._Myres < 8;
    this->stringFontSize = v29;
    if ( !v30 )
      operator delete(v50._Bx._Ptr);
    LOBYTE(v59) = 20;
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"SECONDS_FONT_SIZE", 0x11u);
    LOBYTE(v59) = 23;
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    std::wstring::assign(&v50, L"MAIN", 4u);
    LOBYTE(v59) = 24;
    v31 = INIReader::getFloat(&r, &v50, &result);
    v30 = v50._Myres < 8;
    this->secondsFontSize = v31;
    if ( !v30 )
      operator delete(v50._Bx._Ptr);
    LOBYTE(v59) = 20;
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&key, L"STOP_LIMIT_KMH");
    LOBYTE(v59) = 25;
    std::wstring::wstring(&result, L"MAIN");
    LOBYTE(v59) = 26;
    v32 = INIReader::getFloat(&r, &result, &key);
    v30 = result._Myres < 8;
    this->stopLimit = v32;
    if ( !v30 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v59) = 20;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"TIME_TO_WAIT_SEC");
    LOBYTE(v59) = 27;
    std::wstring::wstring(&result, L"MAIN");
    LOBYTE(v59) = 28;
    v33 = INIReader::getFloat(&r, &result, &key);
    v30 = result._Myres < 8;
    this->timeToWait = v33;
    if ( !v30 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v59) = 20;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"BRAKE_THRESHOLD_PERCENTAGE");
    LOBYTE(v59) = 29;
    std::wstring::wstring(&result, L"MAIN");
    LOBYTE(v59) = 30;
    v34 = INIReader::getFloat(&r, &result, &key);
    v30 = result._Myres < 8;
    this->brakeThreshold = v34 * 0.0099999998;
    if ( !v30 )
      operator delete(result._Bx._Ptr);
    LOBYTE(v59) = 20;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( !ACDriverPerformance::loadDriverRecords(this, (unsigned int)v25) )
  {
    LODWORD(h) = 1;
    *(float *)&v50._Bx._Ptr = FLOAT_50_0;
    std::wstring::wstring((std::wstring *)&w[4], L"0 -> 50 -> 0 (Km/h)");
    perf::perf(&v53, (unsigned int)v50._Bx._Ptr, *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 31;
    std::vector<perf>::push_back(&this->perfs, v35);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    LODWORD(h) = 1;
    std::wstring::wstring((std::wstring *)&w[4], L"0 -> 100 -> 0 (Km/h)");
    perf::perf(&v53, LODWORD(FLOAT_100_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 32;
    std::vector<perf>::push_back(&this->perfs, v36);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    LODWORD(h) = 1;
    std::wstring::wstring((std::wstring *)&w[4], L"0 -> 120 -> 0 (Km/h)");
    perf::perf(&v53, LODWORD(FLOAT_120_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 33;
    std::vector<perf>::push_back(&this->perfs, v37);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    LODWORD(h) = 1;
    std::wstring::wstring((std::wstring *)&w[4], L"0 -> 160 -> 0 (Km/h)");
    perf::perf(&v53, LODWORD(FLOAT_160_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 34;
    std::vector<perf>::push_back(&this->perfs, v38);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    h = 0.0;
    std::wstring::wstring((std::wstring *)&w[4], L"Dist. 100 m");
    perf::perf(&v53, LODWORD(FLOAT_100_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 35;
    std::vector<perf>::push_back(&this->perfs, v39);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    h = 0.0;
    std::wstring::wstring((std::wstring *)&w[4], L"Dist. 120 m");
    perf::perf(&v53, LODWORD(FLOAT_120_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 36;
    std::vector<perf>::push_back(&this->perfs, v40);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    h = 0.0;
    std::wstring::wstring((std::wstring *)&w[4], L"Dist. 160 m");
    perf::perf(&v53, LODWORD(FLOAT_160_0), *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 37;
    std::vector<perf>::push_back(&this->perfs, v41);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    h = 0.0;
    *(float *)&v50._Bx._Ptr = FLOAT_400_0;
    std::wstring::wstring((std::wstring *)&w[4], L"Dist. 400 m");
    perf::perf(&v53, (unsigned int)v50._Bx._Ptr, *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 38;
    std::vector<perf>::push_back(&this->perfs, v42);
    LOBYTE(v59) = 20;
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
    h = 0.0;
    *(float *)&v50._Bx._Ptr = FLOAT_1000_0;
    std::wstring::wstring((std::wstring *)&w[4], L"Dist. 1 Km");
    perf::perf(&v53, (unsigned int)v50._Bx._Ptr, *(std::wstring *)&w[4], SLODWORD(h));
    LOBYTE(v59) = 39;
    std::vector<perf>::push_back(&this->perfs, v43);
    if ( v53.name._Myres >= 8 )
      operator delete(v53.name._Bx._Ptr);
  }
  LOBYTE(v59) = 6;
  INIReader::~INIReader(&r);
}
ACDriverPerformance *ACDriverPerformance::`scalar deleting destructor'(ACDriverPerformance *this, unsigned int a2)
{
  ACDriverPerformance::~ACDriverPerformance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __usercall ACDriverPerformance::updateData(ACDriverPerformance *this@<ecx>, float a2@<xmm1>)
{
  CarAvatar *v5; // ecx
  float *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm0_4
  unsigned int *v9; // eax
  perf *v10; // ecx
  unsigned __int64 v11; // xmm2_8
  float v12; // eax
  float v13; // xmm3_4
  eDriverPerformanceType v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned int *v18; // eax
  unsigned __int64 v19; // xmm2_8
  float v20; // eax
  Node *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm0_4

  v5 = this->car;
  v6 = (float *)v5->bodyTransform;
  v7 = (float)((float)((float)(this->previousCarPosition.y - v6[14]) * (float)(this->previousCarPosition.y - v6[14]))
             + (float)((float)(this->previousCarPosition.x - v6[13]) * (float)(this->previousCarPosition.x - v6[13])))
     + (float)((float)(this->previousCarPosition.z - v6[15]) * (float)(this->previousCarPosition.z - v6[15]));
  if ( v7 == 0.0 )
    v8 = 0.0;
  else
    v8 = fsqrt(v7);
  this->currentDistance = v8 + this->currentDistance;
  v9 = (unsigned int *)v5->bodyTransform;
  v10 = this->perfs._Myfirst;
  v11 = _mm_unpacklo_ps((__m128)v9[13], (__m128)v9[14]).m128_u64[0];
  v12 = *((float *)v9 + 15);
  *(_QWORD *)&this->previousCarPosition.x = v11;
  this->previousCarPosition.z = v12;
  while ( v10 < this->perfs._Mylast )
  {
    v13 = this->car->physicsState.speed.value * 3.5999999;
    if ( this->stopLimit <= v13 )
    {
      if ( !v10->beaten )
      {
        v14 = v10->type;
        v15 = a2 + v10->seconds;
        v10->seconds = v15;
        if ( v14 )
        {
          if ( v14 == eCar && v13 >= v10->objective )
          {
            v16 = v10->record;
            *(_WORD *)&v10->countDownActive = 257;
            v10->lastSeconds = v15;
            if ( v16 > v15 )
              goto LABEL_16;
          }
        }
        else if ( this->currentDistance >= v10->objective )
        {
          v17 = v10->record;
          v10->beaten = 1;
          v10->lastSpeed = v13;
          v10->lastSeconds = v15;
          if ( v17 > v15 )
          {
            v10->speedAtCheckpoint = v13;
LABEL_16:
            v10->record = v15;
            goto LABEL_17;
          }
        }
      }
    }
    else
    {
      this->currentDistance = 0.0;
      v10->beaten = 0;
      v10->seconds = 0.0;
    }
LABEL_17:
    if ( v10->type == eCar && v10->countDownActive )
    {
      if ( this->car->physicsState.brake > this->brakeThreshold )
      {
        if ( v10->startedToBrake )
          goto LABEL_23;
        v10->startedToBrake = 1;
        v18 = (unsigned int *)this->car->bodyTransform;
        v19 = _mm_unpacklo_ps((__m128)v18[13], (__m128)v18[14]).m128_u64[0];
        v20 = *((float *)v18 + 15);
        *(_QWORD *)&v10->startedToBrakePosition.x = v19;
        v10->startedToBrakePosition.z = v20;
      }
      if ( v10->startedToBrake )
      {
LABEL_23:
        v21 = this->car->bodyTransform;
        v22 = (float)((float)((float)(v10->startedToBrakePosition.y - v21->matrix.M42)
                            * (float)(v10->startedToBrakePosition.y - v21->matrix.M42))
                    + (float)((float)(v10->startedToBrakePosition.x - v21->matrix.M41)
                            * (float)(v10->startedToBrakePosition.x - v21->matrix.M41)))
            + (float)((float)(v10->startedToBrakePosition.z - v21->matrix.M43)
                    * (float)(v10->startedToBrakePosition.z - v21->matrix.M43));
        v23 = 0.0;
        if ( v22 != 0.0 )
          v23 = fsqrt(v22);
        v10->distanceBreaking = v23;
        v24 = this->stopLimit;
        if ( v13 <= v24 || v10->objective < v13 )
        {
          if ( v24 >= v13 )
          {
            v25 = v10->secondsBreaking;
            v26 = v10->recordBreaking;
            v10->lastBreakingSeconds = v25;
            if ( v26 > v25 )
              v10->recordBreaking = v25;
            v10->countDownActive = 0;
          }
          if ( v13 > v10->objective )
            v10->distanceBreaking = 0.0;
          v10->secondsBreaking = 0.0;
          v10->startedToBrake = 0;
        }
        else
        {
          v10->secondsBreaking = v10->secondsBreaking + a2;
        }
        goto LABEL_35;
      }
    }
LABEL_35:
    ++v10;
  }
}
void ACDriverPerformance::renderOnVideo(ACDriverPerformance *this)
{
  ACDriverPerformance *v1; // edi
  ACDriverPerformance_vtbl *v2; // eax
  const std::wstring *v3; // eax
  perf *v4; // esi
  ACDriverPerformance_vtbl *v5; // eax
  unsigned int v6; // eax
  __m128i v7; // xmm0
  ACDriverPerformance_vtbl *v8; // eax
  eDriverPerformanceType v9; // eax
  float v10; // xmm2_4
  float v11; // eax
  std::wstring *v12; // eax
  float v13; // xmm2_4
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  Font *v16; // ecx
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  float v19; // xmm2_4
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  float v23; // eax
  float *v24; // ecx
  float v25; // eax
  std::wstring *v26; // eax
  float *v27; // ecx
  float v28; // eax
  float v29; // xmm1_4
  ACDriverPerformance_vtbl *v30; // eax
  std::wstring *v31; // edi
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  const std::wstring *v34; // eax
  ACDriverPerformance_vtbl *v35; // eax
  std::wstring *v36; // edi
  std::wstring *v37; // eax
  std::wstring *v38; // eax
  const std::wstring *v39; // eax
  float v40; // xmm2_4
  std::wstring *v41; // eax
  const std::wstring *v42; // eax
  float v43; // eax
  Font *v44; // ecx
  std::wstring *v45; // eax
  float *v46; // ecx
  float v47; // eax
  ACDriverPerformance_vtbl *v48; // eax
  std::wstring *v49; // edi
  std::wstring *v50; // eax
  std::wstring *v51; // eax
  const std::wstring *v52; // eax
  Font *v53; // ecx
  ACDriverPerformance_vtbl *v54; // eax
  std::wstring *v55; // eax
  std::wstring *v56; // eax
  const std::wstring *v57; // eax
  int v58; // eax
  float v59; // [esp+44h] [ebp-36Ch]
  int v60; // [esp+44h] [ebp-36Ch]
  vec2f pos; // [esp+48h] [ebp-368h] BYREF
  __int64 x; // [esp+50h] [ebp-360h] BYREF
  ACDriverPerformance *v63; // [esp+58h] [ebp-358h]
  __int64 v64; // [esp+5Ch] [ebp-354h] BYREF
  int v65[2]; // [esp+64h] [ebp-34Ch] BYREF
  int v66[2]; // [esp+6Ch] [ebp-344h] BYREF
  vec2f right; // [esp+74h] [ebp-33Ch] BYREF
  int v68[2]; // [esp+7Ch] [ebp-334h] BYREF
  vec2f left; // [esp+84h] [ebp-32Ch] BYREF
  int v70[2]; // [esp+8Ch] [ebp-324h] BYREF
  int v71[2]; // [esp+94h] [ebp-31Ch] BYREF
  int v72[2]; // [esp+9Ch] [ebp-314h] BYREF
  vec2f v73; // [esp+A4h] [ebp-30Ch] BYREF
  vec2f v74; // [esp+ACh] [ebp-304h] BYREF
  std::wstring seconds; // [esp+B4h] [ebp-2FCh] BYREF
  std::wstring text; // [esp+CCh] [ebp-2E4h] BYREF
  std::wstring result; // [esp+E4h] [ebp-2CCh] BYREF
  std::wstring v78; // [esp+FCh] [ebp-2B4h] BYREF
  std::wstring v79; // [esp+114h] [ebp-29Ch] BYREF
  ACDriverPerformance v80; // [esp+12Ch] [ebp-284h] BYREF
  unsigned int v81; // [esp+320h] [ebp-90h]
  std::wstring v82; // [esp+324h] [ebp-8Ch] BYREF
  void *v83[5]; // [esp+33Ch] [ebp-74h] BYREF
  unsigned int v84; // [esp+350h] [ebp-60h]
  std::wstring v85; // [esp+354h] [ebp-5Ch] BYREF
  void *v86[6]; // [esp+36Ch] [ebp-44h] BYREF
  void *v87[6]; // [esp+384h] [ebp-2Ch] BYREF
  int v88; // [esp+3ACh] [ebp-4h]

  v1 = this;
  v63 = this;
  if ( this->timeToWait <= this->waitingTime )
  {
    v4 = this->perfs._Myfirst;
    v59 = FLOAT_25_0;
    if ( v4 < this->perfs._Mylast )
    {
      do
      {
        Font::setColor(v1->font._Ptr, 1.0, 1.0, 1.0, 1.0);
        v5 = v1->__vftable;
        v72[0] = 1125515264;
        *(float *)&v72[1] = v59;
        v5->localToWorld(v1, (vec2f *)&x, (const vec2f *)v72);
        v1->font._Ptr->scale = v1->stringFontSize;
        Font::blitString(v1->font._Ptr, *(float *)&x, *((float *)&x + 1), &v4->name, 1.0, eAlignLeft);
        v6 = (int)v1->secondsFontSize;
        v70[0] = 1125515264;
        v7 = _mm_cvtsi32_si128(v6);
        v8 = v1->__vftable;
        *(float *)&v60 = _mm_cvtepi32_ps(v7).m128_f32[0] + v59;
        v70[1] = v60;
        x = (__int64)*v8->localToWorld(v1, &v74, (const vec2f *)v70);
        seconds._Myres = 7;
        seconds._Mysize = 0;
        seconds._Bx._Buf[0] = 0;
        v88 = 2;
        v9 = v4->type;
        if ( v9 )
        {
          if ( v9 == eCar )
          {
            v10 = v4->secondsBreaking;
            if ( v10 == 0.0 && v4->seconds == 0.0 )
            {
              v11 = COERCE_FLOAT(ACDriverPerformance::fromFloatToString(v4->lastSeconds, (ACDriverPerformance *)&result));
              pos.x = v11;
              if ( &seconds != (std::wstring *)LODWORD(v11) )
              {
                if ( seconds._Myres >= 8 )
                {
                  operator delete(seconds._Bx._Ptr);
                  v11 = pos.x;
                }
                seconds._Myres = 7;
                seconds._Bx._Buf[0] = 0;
                seconds._Mysize = 0;
                std::wstring::_Assign_rv(&seconds, (std::wstring *)LODWORD(v11));
              }
              if ( result._Myres >= 8 )
                operator delete(result._Bx._Ptr);
              result._Myres = 7;
              result._Bx._Buf[0] = 0;
              result._Mysize = 0;
              v12 = std::operator+<wchar_t>(&text, &seconds, L"|");
              LODWORD(pos.x) = v12;
              if ( &seconds != v12 )
              {
                if ( seconds._Myres >= 8 )
                {
                  operator delete(seconds._Bx._Ptr);
                  v12 = (std::wstring *)LODWORD(pos.x);
                }
                seconds._Myres = 7;
                seconds._Bx._Buf[0] = 0;
                seconds._Mysize = 0;
                std::wstring::_Assign_rv(&seconds, v12);
              }
              if ( text._Myres >= 8 )
                operator delete(text._Bx._Ptr);
              v13 = v4->lastBreakingSeconds;
              text._Bx._Buf[0] = 0;
              text._Myres = 7;
              text._Mysize = 0;
              v14 = (std::wstring *)ACDriverPerformance::fromFloatToString(v13, &v80);
              LOBYTE(v88) = 10;
              v15 = std::operator+<wchar_t>((std::wstring *)&v80.currentDistance, &seconds, v14);
              LODWORD(pos.x) = v15;
              if ( &seconds != v15 )
              {
                if ( seconds._Myres >= 8 )
                {
                  operator delete(seconds._Bx._Ptr);
                  v15 = (std::wstring *)LODWORD(pos.x);
                }
                seconds._Myres = 7;
                seconds._Bx._Buf[0] = 0;
                seconds._Mysize = 0;
                std::wstring::_Assign_rv(&seconds, v15);
              }
              if ( LODWORD(v80.brakeThreshold) >= 8 )
                operator delete((void *)LODWORD(v80.currentDistance));
              LOBYTE(v88) = 2;
              LODWORD(v80.brakeThreshold) = 7;
              v80.previousCarPosition.z = 0.0;
              LOWORD(v80.currentDistance) = 0;
              if ( v80.name._Mysize >= 8 )
                operator delete(v80.__vftable);
              v16 = v1->font._Ptr;
              v80.name._Mysize = 7;
              *(_DWORD *)&v80.name._Bx._Alias[12] = 0;
              LOWORD(v80.__vftable) = 0;
              Font::setColor(v16, 1.0, 1.0, 1.0, 1.0);
              v1->font._Ptr->scale = v1->secondsFontSize;
            }
            else if ( v10 == 0.0 )
            {
              if ( v4->beaten )
              {
                v17 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                        v4->lastSeconds,
                                        (ACDriverPerformance *)v83);
                std::wstring::operator=(&seconds, v17);
                if ( v84 >= 8 )
                  operator delete(v83[0]);
                v84 = 7;
                LOWORD(v83[0]) = 0;
                v83[4] = 0;
                v18 = std::operator+<wchar_t>((std::wstring *)&v80.backColor.y, &seconds, L"|");
                std::wstring::operator=(&seconds, v18);
                if ( LODWORD(v80.borderColor.z) >= 8 )
                  operator delete((void *)LODWORD(v80.backColor.y));
                v19 = v4->lastBreakingSeconds;
                LOWORD(v80.backColor.y) = 0;
                LODWORD(v80.borderColor.z) = 7;
                v80.borderColor.y = 0.0;
                v20 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                        v19,
                                        (ACDriverPerformance *)&v80.highlightTextColor.y);
                LOBYTE(v88) = 11;
                v21 = std::operator+<wchar_t>(&v78, &seconds, v20);
                std::wstring::operator=(&seconds, v21);
                if ( v78._Myres >= 8 )
                  operator delete(v78._Bx._Ptr);
                LOBYTE(v88) = 2;
                v78._Myres = 7;
                v78._Mysize = 0;
                v78._Bx._Buf[0] = 0;
                if ( LODWORD(v80.backTextureColor.y) >= 8 )
                  operator delete((void *)LODWORD(v80.highlightTextColor.y));
                LODWORD(v80.backTextureColor.y) = 7;
                v80.backTextureColor.x = 0.0;
                LOWORD(v80.highlightTextColor.y) = 0;
                Font::setColor(v1->font._Ptr, 1.0, 1.0, 1.0, 1.0);
              }
              else
              {
                v22 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                        v4->seconds,
                                        (ACDriverPerformance *)&v80.fileName._Bx._Alias[12]);
                std::wstring::operator=(&seconds, v22);
                if ( v81 >= 8 )
                  operator delete(*(void **)&v80.fileName._Bx._Alias[12]);
                v81 = 7;
                v80.secondsFontSize = 0.0;
                v80.fileName._Bx._Buf[6] = 0;
                Font::setColor(v1->font._Ptr, 0.0, 1.0, 0.0, 1.0);
              }
            }
            else
            {
              v23 = COERCE_FLOAT(ACDriverPerformance::fromFloatToString(v10, (ACDriverPerformance *)&v80.controls._Myend));
              pos.x = v23;
              if ( &seconds != (std::wstring *)LODWORD(v23) )
              {
                if ( seconds._Myres >= 8 )
                {
                  operator delete(seconds._Bx._Ptr);
                  v23 = pos.x;
                }
                seconds._Myres = 7;
                seconds._Bx._Buf[0] = 0;
                seconds._Mysize = 0;
                std::wstring::_Assign_rv(&seconds, (std::wstring *)LODWORD(v23));
              }
              if ( v80.evClicked.handlers._Myend >= (std::pair<void *,std::function<void __cdecl(ksgui::OnControlClicked const &)> > *)8 )
                operator delete(v80.controls._Myend);
              v24 = &v1->font._Ptr->scale;
              LOWORD(v80.controls._Myend) = 0;
              v25 = v1->secondsFontSize;
              v80.evClicked.handlers._Myend = (std::pair<void *,std::function<void __cdecl(ksgui::OnControlClicked const &)> > *)7;
              v80.evClicked.handlers._Mylast = 0;
              *v24 = v25;
              Font::setColor(v1->font._Ptr, 1.0, 0.0, 0.0, 1.0);
            }
            v26 = std::operator+<wchar_t>((std::wstring *)&v80.carName._Bx._Alias[12], &seconds, L"s");
            LODWORD(pos.x) = v26;
            if ( &seconds != v26 )
            {
              if ( seconds._Myres >= 8 )
              {
                operator delete(seconds._Bx._Ptr);
                v26 = (std::wstring *)LODWORD(pos.x);
              }
              seconds._Myres = 7;
              seconds._Bx._Buf[0] = 0;
              seconds._Mysize = 0;
              std::wstring::_Assign_rv(&seconds, v26);
            }
            if ( *(_DWORD *)&v80.trackName._Bx._Alias[8] >= 8u )
              operator delete(*(void **)&v80.carName._Bx._Alias[12]);
            v27 = &v1->font._Ptr->scale;
            v80.carName._Bx._Buf[6] = 0;
            v28 = v1->secondsFontSize;
            *(_QWORD *)&v80.trackName._Bx._Alias[4] = 0x700000000i64;
            *v27 = v28;
            Font::blitString(v1->font._Ptr, *(float *)&x, *((float *)&x + 1), &seconds, 1.0, eAlignLeft);
            v29 = FLOAT_3_4028235e38;
            if ( v4->record != 3.4028235e38 )
            {
              Font::setColor(v1->font._Ptr, 0.0, 1.0, 0.0, 1.0);
              v30 = v1->__vftable;
              v68[0] = 0;
              v68[1] = v60;
              v30->localToWorld(v1, &v73, (const vec2f *)v68);
              v31 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                      v4->record,
                                      (ACDriverPerformance *)&v80.trackConfigName._Bx._Alias[12]);
              LOBYTE(v88) = 12;
              v32 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                      v4->lastSeconds,
                                      (ACDriverPerformance *)&v80.gui);
              LOBYTE(v88) = 13;
              v33 = std::operator+<wchar_t>(&v85, v32, L"/");
              LOBYTE(v88) = 14;
              v34 = std::operator+<wchar_t>((std::wstring *)&v80.backTexture.fileName._Mysize, v33, v31);
              v1 = v63;
              LOBYTE(v88) = 15;
              Font::blitString(v63->font._Ptr, v73.x, *((float *)&x + 1), v34, 1.0, eAlignLeft);
              if ( v80.text._Bx._Ptr >= (wchar_t *)8 )
                operator delete((void *)v80.backTexture.fileName._Mysize);
              v80.text._Bx._Ptr = (wchar_t *)7;
              v80.fontScale = 0.0;
              LOWORD(v80.backTexture.fileName._Mysize) = 0;
              if ( v85._Myres >= 8 )
                operator delete(v85._Bx._Ptr);
              v85._Myres = 7;
              v85._Mysize = 0;
              v85._Bx._Buf[0] = 0;
              if ( v80.controlGLR >= (GLRenderer *)8 )
                operator delete(v80.gui);
              LOBYTE(v88) = 2;
              v80.controlGLR = (GLRenderer *)7;
              v80.scaleMult = 0.0;
              LOWORD(v80.gui) = 0;
              if ( *(_DWORD *)&v80.driverName._Bx._Alias[8] >= 8u )
                operator delete(*(void **)&v80.trackConfigName._Bx._Alias[12]);
              v29 = FLOAT_3_4028235e38;
              *(_QWORD *)&v80.driverName._Bx._Alias[4] = 0x700000000i64;
              v80.trackConfigName._Bx._Buf[6] = 0;
            }
            if ( v4->recordBreaking != v29 )
            {
              Font::setColor(v1->font._Ptr, 1.0, 0.0, 0.0, 1.0);
              v35 = v1->__vftable;
              v65[0] = 1133903872;
              v65[1] = v60;
              v35->localToWorld(v1, (vec2f *)&v64, (const vec2f *)v65);
              v36 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                      v4->recordBreaking,
                                      (ACDriverPerformance *)&v80.borderColor.w);
              LOBYTE(v88) = 16;
              v37 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                      v4->lastBreakingSeconds,
                                      (ACDriverPerformance *)&v80.name._Myres);
              LOBYTE(v88) = 17;
              v38 = std::operator+<wchar_t>(&v79, v37, L"/");
              LOBYTE(v88) = 18;
              v39 = std::operator+<wchar_t>((std::wstring *)&v80.scaleToBeSaved, v38, v36);
              v1 = v63;
              LOBYTE(v88) = 19;
              Font::blitString(v63->font._Ptr, *(float *)&v64, *((float *)&v64 + 1), v39, 1.0, eAlignLeft);
              if ( v80.zoomOutIcon >= (ksgui::Control *)8 )
                operator delete((void *)LODWORD(v80.scaleToBeSaved));
              v80.zoomOutIcon = (ksgui::Control *)7;
              v80.zoomInIcon = 0;
              LOWORD(v80.scaleToBeSaved) = 0;
              if ( v79._Myres >= 8 )
                operator delete(v79._Bx._Ptr);
              v79._Myres = 7;
              v79._Mysize = 0;
              v79._Bx._Buf[0] = 0;
              if ( LODWORD(v80.backColor.x) >= 8 )
                operator delete((void *)v80.name._Myres);
              LOBYTE(v88) = 2;
              LODWORD(v80.backColor.x) = 7;
              v80.rect.bottom = 0.0;
              LOWORD(v80.name._Myres) = 0;
              if ( LODWORD(v80.highlightTextColor.x) >= 8 )
                operator delete((void *)LODWORD(v80.borderColor.w));
              v40 = v4->distanceBreaking;
              LOWORD(v80.borderColor.w) = 0;
              LODWORD(v80.highlightTextColor.x) = 7;
              v80.foreColor.w = 0.0;
              v41 = (std::wstring *)ACDriverPerformance::fromFloatToString(v40, (ACDriverPerformance *)v86);
              LOBYTE(v88) = 20;
              v42 = std::operator+<wchar_t>((std::wstring *)&v80.backTextureColor.z, L"M : ", v41);
              LOBYTE(v88) = 21;
              Font::blitString(v1->font._Ptr, *(float *)&v64 + 150.0, *((float *)&x + 1), v42, 1.0, eAlignLeft);
              if ( v80.controls._Mylast >= (ksgui::Control **)8 )
                operator delete((void *)LODWORD(v80.backTextureColor.z));
              v80.controls._Mylast = (ksgui::Control **)7;
              v80.controls._Myfirst = 0;
              LOWORD(v80.backTextureColor.z) = 0;
              if ( v86[5] >= (void *)8 )
                operator delete(v86[0]);
            }
          }
        }
        else
        {
          v43 = COERCE_FLOAT(ACDriverPerformance::fromFloatToString(v4->seconds, (ACDriverPerformance *)&v80.tag));
          pos.x = v43;
          if ( &seconds != (std::wstring *)LODWORD(v43) )
          {
            if ( seconds._Myres >= 8 )
            {
              operator delete(seconds._Bx._Ptr);
              v43 = pos.x;
            }
            seconds._Myres = 7;
            seconds._Bx._Buf[0] = 0;
            seconds._Mysize = 0;
            std::wstring::_Assign_rv(&seconds, (std::wstring *)LODWORD(v43));
          }
          if ( *(_DWORD *)&v80.backTexture.fileName._Bx._Alias[12] >= 8u )
            operator delete(v80.tag);
          v44 = v1->font._Ptr;
          *(_QWORD *)&v80.backTexture.fileName._Bx._Alias[8] = 0x700000000i64;
          LOWORD(v80.tag) = 0;
          Font::setColor(v44, 1.0, 1.0, 1.0, 1.0);
          v45 = std::operator+<wchar_t>((std::wstring *)&v80.text._Bx._Alias[4], &seconds, L"s");
          LODWORD(pos.x) = v45;
          if ( &seconds != v45 )
          {
            if ( seconds._Myres >= 8 )
            {
              operator delete(seconds._Bx._Ptr);
              v45 = (std::wstring *)LODWORD(pos.x);
            }
            seconds._Myres = 7;
            seconds._Bx._Buf[0] = 0;
            seconds._Mysize = 0;
            std::wstring::_Assign_rv(&seconds, v45);
          }
          if ( *(_DWORD *)&v80.isHighlight >= 8u )
            operator delete(*(void **)&v80.text._Bx._Alias[4]);
          v46 = &v1->font._Ptr->scale;
          v80.text._Bx._Buf[2] = 0;
          v47 = v1->secondsFontSize;
          *(_DWORD *)&v80.isHighlight = 7;
          v80.text._Myres = 0;
          *v46 = v47;
          Font::blitString(v1->font._Ptr, *(float *)&x, *((float *)&x + 1), &seconds, 1.0, eAlignLeft);
          if ( v4->record != 3.4028235e38 )
          {
            Font::setColor(v1->font._Ptr, 0.0, 1.0, 0.0, 1.0);
            v48 = v1->__vftable;
            v71[0] = 0;
            v71[1] = v60;
            v48->localToWorld(v1, &left, (const vec2f *)v71);
            v49 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                    v4->record,
                                    (ACDriverPerformance *)&v80.trackName._Bx._Alias[12]);
            LOBYTE(v88) = 3;
            v50 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                    v4->lastSeconds,
                                    (ACDriverPerformance *)&v80.timeToWait);
            LOBYTE(v88) = 4;
            v51 = std::operator+<wchar_t>((std::wstring *)&v80.HEADER_HEIGHT, v50, L"/");
            LOBYTE(v88) = 5;
            v52 = std::operator+<wchar_t>((std::wstring *)&v80.rectBase, v51, v49);
            v1 = v63;
            LOBYTE(v88) = 6;
            Font::blitString(v63->font._Ptr, left.x, left.y, v52, 1.0, eAlignLeft);
            if ( *(_DWORD *)&v80.devApp >= 8u )
              operator delete((void *)LODWORD(v80.rectBase.left));
            *(_DWORD *)&v80.devApp = 7;
            v80.formTitle = 0;
            LOWORD(v80.rectBase.left) = 0;
            if ( v80.perfs._Myend >= (perf *)8 )
              operator delete((void *)LODWORD(v80.HEADER_HEIGHT));
            v80.perfs._Myend = (perf *)7;
            v80.perfs._Mylast = 0;
            LOWORD(v80.HEADER_HEIGHT) = 0;
            if ( *(_DWORD *)&v80.carName._Bx._Alias[8] >= 8u )
              operator delete((void *)LODWORD(v80.timeToWait));
            LOBYTE(v88) = 2;
            *(_QWORD *)&v80.carName._Bx._Alias[4] = 0x700000000i64;
            LOWORD(v80.timeToWait) = 0;
            if ( *(_DWORD *)&v80.trackConfigName._Bx._Alias[8] >= 8u )
              operator delete(*(void **)&v80.trackName._Bx._Alias[12]);
            v53 = v1->font._Ptr;
            *(_QWORD *)&v80.trackConfigName._Bx._Alias[4] = 0x700000000i64;
            v80.trackName._Bx._Buf[6] = 0;
            Font::setColor(v53, 1.0, 1.0, 0.0, 1.0);
            v54 = v1->__vftable;
            v66[0] = 1133903872;
            v66[1] = v60;
            v54->localToWorld(v1, &right, (const vec2f *)v66);
            v55 = (std::wstring *)ACDriverPerformance::fromFloatToString(
                                    v4->speedAtCheckpoint,
                                    (ACDriverPerformance *)v87);
            LOBYTE(v88) = 7;
            v56 = std::operator+<wchar_t>(&v82, L" Speed: ", v55);
            LOBYTE(v88) = 8;
            v57 = std::operator+<wchar_t>((std::wstring *)&v80.driverName._Bx._Alias[12], v56, L" Km/h");
            LOBYTE(v88) = 9;
            Font::blitString(v1->font._Ptr, right.x, right.y, v57, 1.0, eAlignLeft);
            if ( *(_DWORD *)&v80.fileName._Bx._Alias[8] >= 8u )
              operator delete(*(void **)&v80.driverName._Bx._Alias[12]);
            *(_QWORD *)&v80.fileName._Bx._Alias[4] = 0x700000000i64;
            v80.driverName._Bx._Buf[6] = 0;
            if ( v82._Myres >= 8 )
              operator delete(v82._Bx._Ptr);
            v82._Myres = 7;
            v82._Mysize = 0;
            v82._Bx._Buf[0] = 0;
            if ( v87[5] >= (void *)8 )
              operator delete(v87[0]);
          }
        }
        v58 = (int)v1->secondsFontSize;
        v88 = -1;
        v59 = (float)(2 * v58) + *(float *)&v60;
        if ( seconds._Myres >= 8 )
          operator delete(seconds._Bx._Ptr);
        ++v4;
      }
      while ( v4 < v1->perfs._Mylast );
    }
  }
  else
  {
    v2 = this->__vftable;
    v64 = 0x4170000041700000i64;
    v2->localToWorld(this, &pos, (const vec2f *)&v64);
    v1->font._Ptr->scale = v1->stringFontSize * 5.0;
    Font::setColor(v1->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"HEATING UP...", 0xDu);
    v88 = 0;
    v3 = acTranslate(&result, &text);
    LOBYTE(v88) = 1;
    Font::blitString(v1->font._Ptr, pos.x, pos.y, v3, 1.0, eAlignLeft);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
}
ACDriverPerformance *__userpurge ACDriverPerformance::fromFloatToString@<eax>(float a1@<xmm2>, ACDriverPerformance *this)
{
  int v4; // ecx
  float v5; // xmm5_4
  float v6; // xmm2_4
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  float v9; // xmm1_4
  float v10; // xmm0_4
  ACDriverPerformance *v11; // esi
  int v13; // [esp+24h] [ebp-C8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v14; // [esp+28h] [ebp-C4h] BYREF
  int v15; // [esp+E8h] [ebp-4h]

  *(_DWORD *)v14.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v14.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v14.gap68);
  v15 = 0;
  v13 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v14, &v14.gap10[8], 0);
  v15 = 1;
  *(_DWORD *)&v14.gap0[*(_DWORD *)(*(_DWORD *)v14.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v13 + *(_DWORD *)(*(_DWORD *)v14.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v14.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v14.gap10[8]);
  *(_DWORD *)&v14.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v14.gap10[64] = 0;
  *(_DWORD *)&v14.gap10[68] = 0;
  v15 = 3;
  v5 = __libm_sse2_powf(v4).m128_f32[0];
  v6 = v5 * a1;
  v7.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v6);
  v8.m128_i32[0] = LODWORD(v6) ^ LODWORD(FLOAT_N0_0) & LODWORD(v6);
  LODWORD(v9) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v8, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v6);
  v8.m128_f32[0] = (float)((float)(v6 + v9) - v9) - v6;
  LODWORD(v10) = _mm_cmpgt_ss(v8, v7).m128_u32[0] & LODWORD(FLOAT_1_0);
  if ( (float)((float)((float)((float)(v6 + v9) - v9) - v10) / v5) == 0.0 )
  {
    v11 = this;
    this->name._Mysize = 7;
    *(_DWORD *)&this->name._Bx._Alias[12] = 0;
    LOWORD(this->__vftable) = 0;
    std::wstring::assign((std::wstring *)this, L"-", 1u);
  }
  else
  {
    std::wostream::operator<<(v14.gap10, (float)((float)((float)(v6 + v9) - v9) - v10) / v5);
    v11 = this;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v14, (std::wstring *)this);
  }
  *(_DWORD *)&v14.gap0[*(_DWORD *)(*(_DWORD *)v14.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v13 + *(_DWORD *)(*(_DWORD *)v14.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v14.gap0 + 4) - 104;
  *(_DWORD *)&v14.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v14.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v14.gap68);
  return v11;
}
char ACDriverPerformance::saveDriverRecords(ACDriverPerformance *this)
{
  std::wstring *v2; // eax
  void (__cdecl *v3)(void *); // ebx
  std::wstring *v4; // esi
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  std::wstring *v9; // esi
  std::wstring *v10; // eax
  bool v11; // zf
  int v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  int v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  int v19; // eax
  int v20; // esi
  unsigned int v21; // ebx
  std::wostream *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  std::wostream *v25; // eax
  std::wostream *v26; // eax
  std::wostream *v27; // eax
  int v28; // eax
  std::wostream *v29; // eax
  int v30; // eax
  std::wostream *v31; // eax
  int v32; // eax
  perf *v33; // ecx
  std::wostream *v34; // eax
  std::wostream *v35; // eax
  std::wostream *v36; // eax
  perf *v37; // ecx
  std::wostream *v38; // eax
  std::wostream *v39; // eax
  std::wostream *v40; // eax
  _BYTE *v41; // esi
  int v42; // ecx
  const char *v44; // [esp+44h] [ebp-12Ch]
  int v45; // [esp+4Ch] [ebp-124h]
  int v46; // [esp+4Ch] [ebp-124h]
  perf *v47; // [esp+4Ch] [ebp-124h]
  eDriverPerformanceType v48; // [esp+50h] [ebp-120h]
  float v49; // [esp+50h] [ebp-120h]
  float v50; // [esp+50h] [ebp-120h]
  float v51; // [esp+50h] [ebp-120h]
  float v52; // [esp+50h] [ebp-120h]
  char v53[4]; // [esp+64h] [ebp-10Ch]
  std::wofstream out; // [esp+68h] [ebp-108h] BYREF
  std::wstring pathName; // [esp+114h] [ebp-5Ch] BYREF
  std::wstring v56; // [esp+12Ch] [ebp-44h] BYREF
  std::wstring result; // [esp+144h] [ebp-2Ch] BYREF
  int v58; // [esp+16Ch] [ebp-4h]

  pathName._Myres = 7;
  pathName._Mysize = 0;
  pathName._Bx._Buf[0] = 0;
  v58 = 0;
  v2 = Path::getDocumentPath(&result);
  LOBYTE(v58) = 1;
  v3 = operator delete;
  v4 = std::operator+<wchar_t>(&v56, v2, L"/Assetto Corsa/savedData/");
  if ( &pathName != v4 )
  {
    pathName._Myres = 7;
    pathName._Mysize = 0;
    pathName._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&pathName, v4);
  }
  if ( v56._Myres >= 8 )
    operator delete(v56._Bx._Ptr);
  v56._Myres = 7;
  LOBYTE(v58) = 0;
  v56._Mysize = 0;
  v56._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Path::createFolder(&pathName);
  v5 = std::operator+<wchar_t>(&result, &pathName, L"driverPerformances/");
  if ( &pathName != v5 )
  {
    if ( pathName._Myres >= 8 )
      operator delete(pathName._Bx._Ptr);
    pathName._Myres = 7;
    pathName._Mysize = 0;
    pathName._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&pathName, v5);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Path::createFolder(&pathName);
  v6 = std::operator+<wchar_t>(&result, &pathName, &this->trackName);
  LOBYTE(v58) = 2;
  v7 = std::operator+<wchar_t>(&v56, v6, L"/");
  if ( &pathName != v7 )
  {
    if ( pathName._Myres >= 8 )
      operator delete(pathName._Bx._Ptr);
    pathName._Myres = 7;
    pathName._Mysize = 0;
    pathName._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&pathName, v7);
  }
  if ( v56._Myres >= 8 )
    operator delete(v56._Bx._Ptr);
  v56._Myres = 7;
  LOBYTE(v58) = 0;
  v56._Mysize = 0;
  v56._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Path::createFolder(&pathName);
  if ( std::wstring::compare(&this->trackConfigName, 0, this->trackConfigName._Mysize, word_17BE9D8, 0) )
  {
    v8 = std::operator+<wchar_t>(&result, &pathName, &this->trackConfigName);
    LOBYTE(v58) = 3;
    v9 = std::operator+<wchar_t>(&v56, v8, L"/");
    if ( &pathName != v9 )
    {
      if ( pathName._Myres >= 8 )
        operator delete(pathName._Bx._Ptr);
      pathName._Myres = 7;
      pathName._Mysize = 0;
      pathName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&pathName, v9);
    }
    if ( v56._Myres >= 8 )
      operator delete(v56._Bx._Ptr);
    v56._Myres = 7;
    LOBYTE(v58) = 0;
    v56._Mysize = 0;
    v56._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Path::createFolder(&pathName);
  }
  std::wofstream::wofstream(&out, 1);
  v10 = &this->fileName;
  LOBYTE(v58) = 4;
  if ( this->fileName._Myres >= 8 )
    v10 = (std::wstring *)v10->_Bx._Ptr;
  v11 = std::wfilebuf::open((std::wfilebuf *)&out.gap0[4], v10->_Bx._Buf, 2, 64) == 0;
  v12 = *(_DWORD *)(*(_DWORD *)out.gap0 + 4);
  if ( v11 )
    std::wios::setstate((char *)&out + v12, 2, 0);
  else
    std::wios::clear((char *)&out + v12, 0, 0);
  v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "[MAIN]");
  std::wostream::operator<<(v13);
  v45 = this->version;
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "VERSION=");
  v15 = std::wostream::operator<<(v14, v45);
  std::wostream::operator<<(v15);
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "CAR_NAME=");
  v17 = std::operator<<<wchar_t>(v16, &this->carName);
  std::wostream::operator<<(v17);
  v46 = this->perfs._Mylast - this->perfs._Myfirst;
  v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "PERF_SIZE=");
  v19 = std::wostream::operator<<(v18, v46);
  std::wostream::operator<<(v19);
  if ( this->perfs._Mylast - this->perfs._Myfirst )
  {
    v20 = 0;
    v21 = 0;
    do
    {
      v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&out, "[PERF_");
      v23 = (std::wostream *)std::wostream::operator<<(v22, v21);
      v24 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v23, v44);
      std::wostream::operator<<(v24);
      v47 = &this->perfs._Myfirst[v20];
      v25 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "NAME=");
      v26 = std::operator<<<wchar_t>(v25, &v47->name);
      std::wostream::operator<<(v26);
      v48 = this->perfs._Myfirst[v20].type;
      v27 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "TYPE=");
      v28 = std::wostream::operator<<(v27, v48);
      std::wostream::operator<<(v28);
      v49 = this->perfs._Myfirst[v20].objective;
      v29 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "OBJECTIVE=");
      v30 = std::wostream::operator<<(v29, LODWORD(v49));
      std::wostream::operator<<(v30);
      v50 = this->perfs._Myfirst[v20].speedAtCheckpoint;
      v31 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "CP_SPEED=");
      v32 = std::wostream::operator<<(v31, LODWORD(v50));
      std::wostream::operator<<(v32);
      v33 = this->perfs._Myfirst;
      if ( v33[v20].record == 3.4028235e38 )
      {
        v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "RECORD=");
        v35 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v34, "0");
      }
      else
      {
        v51 = v33[v20].record;
        v36 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "RECORD=");
        v35 = (std::wostream *)std::wostream::operator<<(v36, LODWORD(v51));
      }
      std::wostream::operator<<(v35);
      v37 = this->perfs._Myfirst;
      if ( v37[v20].recordBreaking == 3.4028235e38 )
      {
        v38 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "RECORD_COUNT_DOWN=");
        v39 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v38, "0");
      }
      else
      {
        v52 = v37[v20].recordBreaking;
        v40 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&out.gap0[4], "RECORD_COUNT_DOWN=");
        v39 = (std::wostream *)std::wostream::operator<<(v40, LODWORD(v52));
      }
      std::wostream::operator<<(v39);
      ++v21;
      ++v20;
    }
    while ( v21 < this->perfs._Mylast - this->perfs._Myfirst );
    v3 = operator delete;
  }
  v41 = &out.gap0[4];
  if ( *(_DWORD *)&out._Filebuffer[4] )
  {
    if ( !std::wfilebuf::_Endwrite((std::wfilebuf *)&out.gap0[4]) )
      v41 = 0;
    if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
      v41 = 0;
  }
  else
  {
    v41 = 0;
  }
  out._Filebuffer[0] = 0;
  out.gap0[74] = 0;
  std::wstreambuf::_Init(&out.gap0[4]);
  *(_DWORD *)&out._Filebuffer[4] = 0;
  *(_DWORD *)&out.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&out.gap0[68] = 0;
  if ( !v41 )
    std::wios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
  LOBYTE(v58) = 0;
  *(_DWORD *)&out.gap0[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = &std::wofstream::`vftable';
  *(_DWORD *)&v53[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = *(_DWORD *)(*(_DWORD *)out.gap0 + 4) - 96;
  v42 = *(_DWORD *)&out._Filebuffer[4];
  *(_DWORD *)&out.gap0[4] = &std::wfilebuf::`vftable';
  if ( *(_DWORD *)&out._Filebuffer[4] && **(std::wofstream ***)&out.gap0[16] == (std::wofstream *)&out.gap0[72] )
  {
    std::wstreambuf::setg(&out.gap0[4], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[64]);
    v42 = *(_DWORD *)&out._Filebuffer[4];
  }
  if ( out._Filebuffer[0] )
  {
    if ( v42 )
    {
      std::wfilebuf::_Endwrite((std::wfilebuf *)&out.gap0[4]);
      _fclose(*(FILE **)&out._Filebuffer[4]);
    }
    out._Filebuffer[0] = 0;
    out.gap0[74] = 0;
    std::wstreambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
  }
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&out.gap0[4]);
  std::wostream::~wostream<wchar_t,std::char_traits<wchar_t>>(&out.gap0[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
  if ( pathName._Myres >= 8 )
    v3(pathName._Bx._Ptr);
  return 1;
}
char __usercall ACDriverPerformance::loadDriverRecords@<al>(ACDriverPerformance *this@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // esi
  char result; // al
  bool v5; // bl
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::vector<perf> *v8; // ebx
  std::vector<perf> *v9; // ecx
  unsigned int v10; // edi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  char v14; // bl
  std::wstring v15; // [esp-1Ch] [ebp-238h] BYREF
  int v16; // [esp-4h] [ebp-220h]
  float v17; // [esp+14h] [ebp-208h]
  int v18; // [esp+18h] [ebp-204h]
  unsigned int v19; // [esp+1Ch] [ebp-200h]
  int v20; // [esp+20h] [ebp-1FCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > _Istr; // [esp+24h] [ebp-1F8h] BYREF
  std::wstring nameField; // [esp+D4h] [ebp-148h] BYREF
  std::wstring number; // [esp+ECh] [ebp-130h] BYREF
  std::wstring section; // [esp+104h] [ebp-118h] BYREF
  std::wstring key; // [esp+11Ch] [ebp-100h] BYREF
  std::wstring v26; // [esp+134h] [ebp-E8h] BYREF
  std::wstring v27; // [esp+14Ch] [ebp-D0h] BYREF
  perf dp; // [esp+164h] [ebp-B8h] BYREF
  INIReaderDocuments r; // [esp+1BCh] [ebp-60h] BYREF
  int v30; // [esp+218h] [ebp-4h]

  v3 = &this->fileName;
  v18 = 0;
  result = Path::fileExists(a2, &this->fileName, 0);
  if ( result )
  {
    v16 = 0;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, v3, 0, 0xFFFFFFFF);
    INIReaderDocuments::INIReaderDocuments(&r, a2, v15, v16);
    v30 = 0;
    if ( r.ready )
    {
      std::wstring::wstring(&number, L"VERSION");
      LOBYTE(v30) = 1;
      std::wstring::wstring(&nameField, L"MAIN");
      LOBYTE(v30) = 2;
      v5 = INIReader::getInt(&r, &nameField, &number) >= this->version;
      if ( nameField._Myres >= 8 )
        operator delete(nameField._Bx._Ptr);
      nameField._Myres = 7;
      LOBYTE(v30) = 0;
      nameField._Mysize = 0;
      nameField._Bx._Buf[0] = 0;
      if ( number._Myres >= 8 )
        operator delete(number._Bx._Ptr);
      if ( v5 )
      {
        std::wstring::wstring(&key, L"CAR_NAME");
        LOBYTE(v30) = 3;
        std::wstring::wstring(&nameField, L"MAIN");
        LOBYTE(v30) = 4;
        v6 = INIReader::getString(&r, &number, &nameField, &key);
        std::wstring::operator=(&this->carName, v6);
        if ( number._Myres >= 8 )
          operator delete(number._Bx._Ptr);
        number._Myres = 7;
        number._Mysize = 0;
        number._Bx._Buf[0] = 0;
        if ( nameField._Myres >= 8 )
          operator delete(nameField._Bx._Ptr);
        nameField._Myres = 7;
        LOBYTE(v30) = 0;
        nameField._Mysize = 0;
        nameField._Bx._Buf[0] = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        v7 = &this->car->unixName;
        if ( this->car->unixName._Myres >= 8 )
          v7 = (std::wstring *)v7->_Bx._Ptr;
        if ( !std::wstring::compare(&this->carName, 0, this->carName._Mysize, v7->_Bx._Buf, this->car->unixName._Mysize)
          && !std::operator!=<wchar_t>(&this->driverName, &this->car->driverInfo.name) )
        {
          std::wstring::wstring(&number, L"PERF_SIZE");
          LOBYTE(v30) = 5;
          std::wstring::wstring(&section, L"MAIN");
          LOBYTE(v30) = 6;
          v19 = INIReader::getInt(&r, &section, &number);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
          LOBYTE(v30) = 0;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&number);
          v8 = &this->perfs;
          std::vector<perf>::_Destroy(v9, this->perfs._Myfirst, this->perfs._Mylast);
          v10 = 0;
          for ( v8->_Mylast = v8->_Myfirst; v10 < v19; ++v10 )
          {
            *(_DWORD *)_Istr.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)_Istr.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(_Istr.gap68);
            LOBYTE(v30) = 7;
            v18 |= 1u;
            std::wiostream::basic_iostream<wchar_t>(&_Istr, &_Istr.gap10[8], 0);
            v30 = 8;
            *(_DWORD *)&_Istr.gap0[*(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(int *)((char *)&v20 + *(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)
                                                                            - 104;
            std::wstreambuf::wstreambuf(&_Istr.gap10[8]);
            *(_DWORD *)&_Istr.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&_Istr.gap10[64] = 0;
            *(_DWORD *)&_Istr.gap10[68] = 0;
            number._Myres = 7;
            number._Mysize = 0;
            number._Bx._Buf[0] = 0;
            LOBYTE(v30) = 11;
            std::wostream::operator<<(_Istr.gap10, v10);
            std::operator>><wchar_t>(&_Istr, &number);
            std::operator+<wchar_t>(&nameField, L"PERF_", &number);
            LOBYTE(v30) = 12;
            std::wstring::wstring(&key, L"TYPE");
            LOBYTE(v30) = 13;
            std::wstring::wstring(&v26, L"OBJECTIVE");
            LOBYTE(v30) = 14;
            std::wstring::wstring(&v27, L"NAME");
            LOBYTE(v30) = 15;
            v16 = INIReader::getInt(&r, &nameField, &key);
            v17 = INIReader::getFloat(&r, &nameField, &v26);
            INIReader::getString(&r, &v15, &nameField, &v27);
            perf::perf(&dp, LODWORD(v17), v15, (eDriverPerformanceType)v16);
            if ( v27._Myres >= 8 )
              operator delete(v27._Bx._Ptr);
            v27._Myres = 7;
            v27._Mysize = 0;
            v27._Bx._Buf[0] = 0;
            if ( v26._Myres >= 8 )
              operator delete(v26._Bx._Ptr);
            v26._Myres = 7;
            v26._Mysize = 0;
            v26._Bx._Buf[0] = 0;
            LOBYTE(v30) = 19;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            dp.seconds = 0.0;
            std::wstring::wstring(&section, L"RECORD");
            LOBYTE(v30) = 20;
            v11 = INIReader::getFloat(&r, &nameField, &section);
            LOBYTE(v30) = 19;
            dp.record = v11;
            if ( section._Myres >= 8 )
              operator delete(section._Bx._Ptr);
            std::wstring::wstring(&section, L"RECORD_COUNT_DOWN");
            LOBYTE(v30) = 21;
            v12 = INIReader::getFloat(&r, &nameField, &section);
            LOBYTE(v30) = 19;
            dp.recordBreaking = v12;
            if ( section._Myres >= 8 )
              operator delete(section._Bx._Ptr);
            std::wstring::wstring(&section, L"CP_SPEED");
            LOBYTE(v30) = 22;
            v13 = INIReader::getFloat(&r, &nameField, &section);
            LOBYTE(v30) = 19;
            dp.speedAtCheckpoint = v13;
            if ( section._Myres >= 8 )
              operator delete(section._Bx._Ptr);
            if ( dp.record == 0.0 )
              dp.record = 3.4028235e38;
            if ( dp.recordBreaking == 0.0 )
              dp.recordBreaking = 3.4028235e38;
            std::vector<perf>::push_back(v8, &dp);
            if ( dp.name._Myres >= 8 )
              operator delete(dp.name._Bx._Ptr);
            dp.name._Myres = 7;
            dp.name._Mysize = 0;
            dp.name._Bx._Buf[0] = 0;
            if ( nameField._Myres >= 8 )
              operator delete(nameField._Bx._Ptr);
            nameField._Myres = 7;
            nameField._Mysize = 0;
            nameField._Bx._Buf[0] = 0;
            if ( number._Myres >= 8 )
              operator delete(number._Bx._Ptr);
            LOBYTE(v30) = 0;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&_Istr);
          }
          v14 = 1;
          goto LABEL_45;
        }
        _printf("ERROR: ACDriver Performance :: wrong car or driver\n");
      }
    }
    v14 = 0;
LABEL_45:
    v30 = -1;
    INIReaderDocuments::~INIReaderDocuments(&r);
    result = v14;
  }
  return result;
}
void ACDriverPerformance::~ACDriverPerformance(ACDriverPerformance *this)
{
  std::vector<perf> *v2; // ecx
  perf *v3; // eax

  this->__vftable = (ACDriverPerformance_vtbl *)&ACDriverPerformance::`vftable';
  ACDriverPerformance::saveDriverRecords(this);
  if ( this->fileName._Myres >= 8 )
    operator delete(this->fileName._Bx._Ptr);
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  if ( this->driverName._Myres >= 8 )
    operator delete(this->driverName._Bx._Ptr);
  this->driverName._Myres = 7;
  this->driverName._Mysize = 0;
  this->driverName._Bx._Buf[0] = 0;
  if ( this->trackConfigName._Myres >= 8 )
    operator delete(this->trackConfigName._Bx._Ptr);
  this->trackConfigName._Myres = 7;
  this->trackConfigName._Mysize = 0;
  this->trackConfigName._Bx._Buf[0] = 0;
  if ( this->trackName._Myres >= 8 )
    operator delete(this->trackName._Bx._Ptr);
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  if ( this->carName._Myres >= 8 )
    operator delete(this->carName._Bx._Ptr);
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  v3 = this->perfs._Myfirst;
  if ( v3 )
  {
    std::vector<perf>::_Destroy(v2, v3, this->perfs._Mylast);
    operator delete(this->perfs._Myfirst);
    this->perfs._Myfirst = 0;
    this->perfs._Mylast = 0;
    this->perfs._Myend = 0;
  }
  this->__vftable = (ACDriverPerformance_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
