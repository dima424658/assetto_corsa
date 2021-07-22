#include "telemetry.h
void Telemetry::Telemetry(Telemetry *this)
{
  std::wstring *v2; // ecx

  this->channels._Myfirst = 0;
  this->channels._Mylast = 0;
  this->channels._Myend = 0;
  v2 = &this->driverName;
  this->isEnabled = 0;
  v2->_Myres = 7;
  v2->_Mysize = 0;
  v2->_Bx._Buf[0] = 0;
  std::wstring::assign(v2, L"Assetto Corsa", 0xDu);
  *(_WORD *)&this->debugPhysics = 0;
  this->totLift = 0.0;
  this->totDrag = 0.0;
  this->aiTargetSpeed = 0.0;
  this->aiBGTargetSpeed = 0.0;
  this->aiOutsideOffset = 0.0;
  this->rpms = 0.0;
  this->exportEntireSession = 0;
  this->awdFrontShare = 0.0;
  this->awdCenterLock = 0.0;
  this->oversteerFactor = 0.0;
  this->rearSpeedRatio = 0.0;
  this->ebbInstant = 0.0;
  this->clutchOpenState = 0.0;
  this->engineVel = 0.0;
  this->driveVel = 0.0;
  this->rootVel = 0.0;
  this->clutchSlip = 0.0;
  this->splinePosition = 0.0;
}
void Telemetry::~Telemetry(Telemetry *this)
{
  if ( this->driverName._Myres >= 8 )
    operator delete(this->driverName._Bx._Ptr);
  this->driverName._Myres = 7;
  this->driverName._Mysize = 0;
  this->driverName._Bx._Buf[0] = 0;
  if ( this->channels._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)this);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TelemetryChannel>>>(
      this->channels._Myfirst,
      this->channels._Mylast);
    operator delete(this->channels._Myfirst);
    this->channels._Myfirst = 0;
    this->channels._Mylast = 0;
    this->channels._Myend = 0;
  }
}
void Telemetry::init(Telemetry *this, Car *car)
{
  std::_Allocator_base<std::vector<LeaderboardEntry> > v3; // al
  int v4; // eax
  bool v5; // cf
  int v6; // eax
  int v7; // eax
  TelemetryChannel *v8; // eax
  int v9; // esi
  Wing *v10; // eax
  Wing *v11; // esi
  float *v12; // edi
  Wing *v13; // esi
  Wing *v14; // ecx
  TelemetryChannel *v15; // edi
  TelemetryChannel *v16; // eax
  TelemetryChannel *v17; // eax
  TelemetryChannel *v18; // eax
  TelemetryChannel *v19; // eax
  TelemetryChannel *v20; // eax
  TelemetryChannel *v21; // eax
  TelemetryChannel *v22; // eax
  TelemetryChannel *v23; // eax
  TelemetryChannel *v24; // eax
  TelemetryChannel *v25; // eax
  TelemetryChannel *v26; // eax
  TelemetryChannel *v27; // eax
  TelemetryChannel *v28; // eax
  TelemetryChannel *v29; // eax
  TelemetryChannel *v30; // eax
  TelemetryChannel *v31; // eax
  TelemetryChannel *v32; // eax
  TelemetryChannel *v33; // eax
  TelemetryChannel *v34; // eax
  TelemetryChannel *v35; // eax
  TelemetryChannel *v36; // eax
  TelemetryChannel *v37; // eax
  TelemetryChannel *v38; // eax
  TelemetryChannel *v39; // eax
  TelemetryChannel *v40; // eax
  TelemetryChannel *v41; // eax
  TelemetryChannel *v42; // eax
  TelemetryChannel *v43; // eax
  TelemetryChannel *v44; // eax
  TelemetryChannel *v45; // eax
  std::allocator<wchar_t> *v46; // eax
  TelemetryChannel *v47; // eax
  TelemetryChannel *v48; // eax
  TelemetryChannel *v49; // eax
  TelemetryChannel *v50; // eax
  TelemetryChannel *v51; // eax
  TelemetryChannel *v52; // eax
  TelemetryChannel *v53; // eax
  TelemetryChannel *v54; // eax
  TelemetryChannel *v55; // eax
  TelemetryChannel *v56; // eax
  TelemetryChannel *v57; // eax
  TelemetryChannel *v58; // eax
  TelemetryChannel *v59; // eax
  TelemetryChannel *v60; // eax
  TelemetryChannel *v61; // eax
  TelemetryChannel *v62; // eax
  TelemetryChannel *v63; // eax
  TelemetryChannel *v64; // eax
  TelemetryChannel *v65; // eax
  TelemetryChannel *v66; // eax
  TelemetryChannel *v67; // eax
  TelemetryChannel *v68; // eax
  TelemetryChannel *v69; // eax
  TelemetryChannel *v70; // eax
  TelemetryChannel *v71; // eax
  TelemetryChannel *v72; // eax
  TelemetryChannel *v73; // eax
  TelemetryChannel *v74; // eax
  TelemetryChannel *v75; // eax
  TelemetryChannel *v76; // eax
  TelemetryChannel *v77; // eax
  TelemetryChannel *v78; // eax
  TelemetryChannel *v79; // eax
  TelemetryChannel *v80; // eax
  TelemetryChannel *v81; // eax
  TelemetryChannel *v82; // eax
  TelemetryChannel *v83; // eax
  TelemetryChannel *v84; // eax
  TelemetryChannel *v85; // eax
  TelemetryChannel *v86; // eax
  TelemetryChannel *v87; // eax
  TelemetryChannel *v88; // eax
  TelemetryChannel *v89; // eax
  std::vector<TyreCompoundDef> *v90; // ebp
  int v91; // edi
  TyreCompoundDef *v92; // esi
  std::string *v93; // eax
  const std::string *v94; // eax
  TelemetryChannel *v95; // eax
  int v96; // edi
  TyreCompoundDef *v97; // esi
  std::string *v98; // eax
  const std::string *v99; // eax
  TelemetryChannel *v100; // eax
  int v101; // edi
  TyreCompoundDef *v102; // esi
  std::string *v103; // eax
  const std::string *v104; // eax
  TelemetryChannel *v105; // eax
  int v106; // edi
  TyreCompoundDef *v107; // esi
  std::string *v108; // eax
  const std::string *v109; // eax
  TelemetryChannel *v110; // eax
  int v111; // edi
  TyreCompoundDef *v112; // esi
  std::string *v113; // eax
  const std::string *v114; // eax
  TelemetryChannel *v115; // eax
  int v116; // edi
  TyreCompoundDef *v117; // esi
  std::string *v118; // eax
  const std::string *v119; // eax
  TelemetryChannel *v120; // eax
  int v121; // edi
  TyreCompoundDef *v122; // esi
  std::string *v123; // eax
  const std::string *v124; // eax
  TelemetryChannel *v125; // eax
  TelemetryChannel *v126; // eax
  TelemetryChannel *v127; // eax
  TelemetryChannel *v128; // eax
  TelemetryChannel *v129; // eax
  TelemetryChannel *v130; // eax
  TelemetryChannel *v131; // eax
  TelemetryChannel *v132; // eax
  wchar_t *v133; // [esp-4h] [ebp-46Ch]
  unsigned int scale; // [esp+0h] [ebp-468h]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing> > > _S20; // [esp+18h] [ebp-450h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing> > > _S21; // [esp+1Ch] [ebp-44Ch] BYREF
  std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > v137; // [esp+23h] [ebp-445h] BYREF
  void *v138; // [esp+24h] [ebp-444h]
  void *v139; // [esp+28h] [ebp-440h]
  std::wstring key; // [esp+2Ch] [ebp-43Ch] BYREF
  TelemetryChannel v141; // [esp+44h] [ebp-424h] BYREF
  std::wstring section; // [esp+84h] [ebp-3E4h] BYREF
  std::string v143; // [esp+9Ch] [ebp-3CCh] BYREF
  std::string result; // [esp+B4h] [ebp-3B4h] BYREF
  std::string v145; // [esp+CCh] [ebp-39Ch] BYREF
  std::wstring ifilename; // [esp+E4h] [ebp-384h] BYREF
  std::string v147; // [esp+FCh] [ebp-36Ch] BYREF
  std::string _Right; // [esp+114h] [ebp-354h] BYREF
  std::string v149; // [esp+12Ch] [ebp-33Ch] BYREF
  std::string v150; // [esp+144h] [ebp-324h] BYREF
  std::string v151; // [esp+15Ch] [ebp-30Ch] BYREF
  std::string v152; // [esp+174h] [ebp-2F4h] BYREF
  std::string v153; // [esp+18Ch] [ebp-2DCh] BYREF
  std::string v154; // [esp+1A4h] [ebp-2C4h] BYREF
  std::string v155; // [esp+1BCh] [ebp-2ACh] BYREF
  std::string v156; // [esp+1D4h] [ebp-294h] BYREF
  std::string v157; // [esp+1ECh] [ebp-27Ch] BYREF
  std::string v158; // [esp+204h] [ebp-264h] BYREF
  std::string v159; // [esp+21Ch] [ebp-24Ch] BYREF
  std::string v160; // [esp+234h] [ebp-234h] BYREF
  std::string v161; // [esp+24Ch] [ebp-21Ch] BYREF
  std::string v162; // [esp+264h] [ebp-204h] BYREF
  std::string v163; // [esp+27Ch] [ebp-1ECh] BYREF
  std::string v164; // [esp+294h] [ebp-1D4h] BYREF
  std::string v165; // [esp+2ACh] [ebp-1BCh] BYREF
  std::string v166; // [esp+2C4h] [ebp-1A4h] BYREF
  std::string v167; // [esp+2DCh] [ebp-18Ch] BYREF
  std::string v168; // [esp+2F4h] [ebp-174h] BYREF
  std::string name; // [esp+30Ch] [ebp-15Ch] BYREF
  std::string v170; // [esp+324h] [ebp-144h] BYREF
  std::string v171; // [esp+33Ch] [ebp-12Ch] BYREF
  std::string v172; // [esp+354h] [ebp-114h] BYREF
  std::string v173; // [esp+36Ch] [ebp-FCh] BYREF
  std::string v174; // [esp+384h] [ebp-E4h] BYREF
  std::string v175; // [esp+39Ch] [ebp-CCh] BYREF
  std::string v176; // [esp+3B4h] [ebp-B4h] BYREF
  std::string v177; // [esp+3CCh] [ebp-9Ch] BYREF
  std::string v178; // [esp+3E4h] [ebp-84h] BYREF
  std::string v179; // [esp+3FCh] [ebp-6Ch] BYREF
  INIReader ini; // [esp+414h] [ebp-54h] BYREF
  int v181; // [esp+464h] [ebp-4h]

  this->car = car;
  if ( !car->physicsGUID )
    this->isEnabled = 1;
  this->susTravel[0] = 0.0;
  this->wheelSpeed[0] = 0.0;
  this->avgSurfaceTemps[0] = 0.0;
  this->practicalTemps[0] = 0.0;
  this->susTravel[1] = 0.0;
  this->wheelSpeed[1] = 0.0;
  this->avgSurfaceTemps[1] = 0.0;
  this->practicalTemps[1] = 0.0;
  this->susTravel[2] = 0.0;
  this->wheelSpeed[2] = 0.0;
  this->avgSurfaceTemps[2] = 0.0;
  this->practicalTemps[2] = 0.0;
  this->susTravel[3] = 0.0;
  this->wheelSpeed[3] = 0.0;
  this->avgSurfaceTemps[3] = 0.0;
  this->practicalTemps[3] = 0.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  v181 = 0;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v181) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"TELEMETRY", 9u);
  LOBYTE(v181) = 3;
  v3 = (std::_Allocator_base<std::vector<LeaderboardEntry> >)INIReader::hasSection(&ini, &section);
  v137.std::_Allocator_base<std::vector<LeaderboardEntry> > = v3;
  LOBYTE(v181) = 2;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v3 = v137.std::_Allocator_base<std::vector<LeaderboardEntry> >;
  }
  if ( v3 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EXPORT_ENTIRE_SESSION", 0x15u);
    LOBYTE(v181) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TELEMETRY", 9u);
    LOBYTE(v181) = 5;
    v4 = INIReader::getInt(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->exportEntireSession = v4 != 0;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v181) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DEBUG_PHYSICS", 0xDu);
    LOBYTE(v181) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TELEMETRY", 9u);
    LOBYTE(v181) = 7;
    v6 = INIReader::getInt(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->debugPhysics = v6 != 0;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v181) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DEBUG_AI", 8u);
    LOBYTE(v181) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TELEMETRY", 9u);
    LOBYTE(v181) = 9;
    v7 = INIReader::getInt(&ini, &section, &key);
    v5 = section._Myres < 8;
    this->debugAI = v7 != 0;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v181) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  this->roty = 0.0;
  this->lapBeacon = 0.0;
  this->aiTargetSpeed = 0.0;
  this->timeTransponder = 0;
  _Right._Myres = 15;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  std::string::assign(&_Right, "LAP_BEACON", 0xAu);
  v141.name._Myres = 15;
  v141.name._Mysize = 0;
  v141.name._Bx._Buf[0] = 0;
  *(__m128i *)&v141.data.values._Myfirst = _mm_load_si128((const __m128i *)&_xmm);
  v141.data.frequency = 100;
  LOBYTE(v181) = 12;
  std::string::assign(&v141.name, &_Right, 0, 0xFFFFFFFF);
  v141.dataSource = &this->lapBeacon;
  v141.data.units = eUnitGeneric;
  v141.lastTickTime = 0.0;
  v141.data.frequency = 100;
  v141.scale = 1.0;
  v8 = this->channels._Mylast;
  LOBYTE(v181) = 13;
  if ( &v141 >= v8 || this->channels._Myfirst > &v141 )
  {
    if ( v8 == this->channels._Myend )
      std::vector<TelemetryChannel>::_Reserve(&this->channels, 1u);
    v15 = this->channels._Mylast;
    v139 = v15;
    v138 = v15;
    LOBYTE(v181) = 16;
    if ( v15 )
    {
      v15->name._Myres = 15;
      v15->name._Mysize = 0;
      v15->name._Bx._Buf[0] = 0;
      std::string::assign(&v15->name, &v141.name, 0, 0xFFFFFFFF);
      LOBYTE(v181) = 17;
      std::vector<unsigned int>::vector<unsigned int>(
        (std::vector<unsigned int> *)&v15->data,
        (const std::vector<unsigned int> *)&v141.data);
      v15->data.units = v141.data.units;
      v15->data.frequency = v141.data.frequency;
      v15->dataSource = v141.dataSource;
      v15->lastTickTime = v141.lastTickTime;
      v15->scale = v141.scale;
    }
  }
  else
  {
    v9 = (char *)&v141 - (char *)this->channels._Myfirst;
    if ( v8 == this->channels._Myend )
      std::vector<TelemetryChannel>::_Reserve(&this->channels, 1u);
    v10 = (Wing *)this->channels._Mylast;
    v11 = (Wing *)&this->channels._Myfirst->name._Bx._Buf[v9 & 0xFFFFFFC0];
    _S21._Ptr = v11;
    _S20._Ptr = v10;
    v138 = v10;
    v139 = v10;
    LOBYTE(v181) = 14;
    if ( v10 )
    {
      v10->data.name._Myres = 15;
      v10->data.name._Mysize = 0;
      v10->data.name._Bx._Alias[0] = 0;
      std::string::assign((std::string *)v10, (const std::string *)v11, 0, 0xFFFFFFFF);
      v12 = &v11->data.chord;
      LOBYTE(v181) = 15;
      v13 = _S20._Ptr;
      std::vector<unsigned int>::vector<unsigned int>(
        (std::vector<unsigned int> *)&_S20._Ptr->data.chord,
        (const std::vector<unsigned int> *)v12);
      v14 = _S21._Ptr;
      _S20._Ptr->data.position.y = v12[3];
      v13->data.position.z = v12[4];
      v13->data.lutAOA_CL.__vftable = v14->data.lutAOA_CL.__vftable;
      *(_QWORD *)&v13->data.lutAOA_CL.references._Myfirst = *(_QWORD *)&v14->data.lutAOA_CL.references._Myfirst;
      v13->data.lutAOA_CL.references._Myend = v14->data.lutAOA_CL.references._Myend;
    }
  }
  ++this->channels._Mylast;
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( _Right._Myres >= 0x10 )
    operator delete(_Right._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "G_LAT", 5u);
  LOBYTE(v181) = 18;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &car->accG.x, eUnitG, 20, 1.0);
  LOBYTE(v181) = 19;
  std::vector<TelemetryChannel>::push_back(&this->channels, v16);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "ROTY", 4u);
  LOBYTE(v181) = 20;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->roty, eUnitRadSec, 20, 1.0);
  LOBYTE(v181) = 21;
  std::vector<TelemetryChannel>::push_back(&this->channels, v17);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "STEERANGLE", 0xAu);
  LOBYTE(v181) = 22;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->steerAngle, eUnitDeg, 20, 1.0);
  LOBYTE(v181) = 23;
  std::vector<TelemetryChannel>::push_back(&this->channels, v18);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "SPEED", 5u);
  LOBYTE(v181) = 24;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->carSpeedMS, eUnitMeterSec, 20, 1.0);
  LOBYTE(v181) = 25;
  std::vector<TelemetryChannel>::push_back(&this->channels, v19);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "THROTTLE", 8u);
  LOBYTE(v181) = 26;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->gas, eUnitPercentage, 20, 1.0);
  LOBYTE(v181) = 27;
  std::vector<TelemetryChannel>::push_back(&this->channels, v20);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "BRAKE", 5u);
  LOBYTE(v181) = 28;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->brake, eUnitPercentage, 20, 1.0);
  LOBYTE(v181) = 29;
  std::vector<TelemetryChannel>::push_back(&this->channels, v21);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "GEAR", 4u);
  LOBYTE(v181) = 30;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->gear, eUnitNumber, 20, 1.0);
  LOBYTE(v181) = 31;
  std::vector<TelemetryChannel>::push_back(&this->channels, v22);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "G_LON", 5u);
  LOBYTE(v181) = 32;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &car->accG.z, eUnitG, 20, 1.0);
  LOBYTE(v181) = 33;
  std::vector<TelemetryChannel>::push_back(&this->channels, v23);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "CLUTCH", 6u);
  LOBYTE(v181) = 34;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->clutch, eUnitPercentage, 20, 1.0);
  LOBYTE(v181) = 35;
  std::vector<TelemetryChannel>::push_back(&this->channels, v24);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 15;
  key._Mysize = 0;
  key._Bx._Alias[0] = 0;
  std::string::assign((std::string *)&key, "RPMS", 4u);
  LOBYTE(v181) = 36;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->rpms, eUnitRPM, 20, 1.0);
  LOBYTE(v181) = 37;
  std::vector<TelemetryChannel>::push_back(&this->channels, v25);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  std::string::string((std::string *)&key, "SPLINE_POSITION");
  LOBYTE(v181) = 38;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->splinePosition, eUnitPercentage, 20, 1.0);
  LOBYTE(v181) = 39;
  std::vector<TelemetryChannel>::push_back(&this->channels, v26);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  std::string::string((std::string *)&key, "SUS_TRAVEL_LF");
  LOBYTE(v181) = 40;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, this->susTravel, eUnitMillimiters, 200, 1.0);
  LOBYTE(v181) = 41;
  std::vector<TelemetryChannel>::push_back(&this->channels, v27);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  std::string::string((std::string *)&key, "SUS_TRAVEL_RF");
  LOBYTE(v181) = 42;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->susTravel[1], eUnitMillimiters, 200, 1.0);
  LOBYTE(v181) = 43;
  std::vector<TelemetryChannel>::push_back(&this->channels, v28);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  std::string::string((std::string *)&key, "SUS_TRAVEL_LR");
  LOBYTE(v181) = 44;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->susTravel[2], eUnitMillimiters, 200, 1.0);
  LOBYTE(v181) = 45;
  std::vector<TelemetryChannel>::push_back(&this->channels, v29);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  std::string::string((std::string *)&key, "SUS_TRAVEL_RR");
  LOBYTE(v181) = 46;
  TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->susTravel[3], eUnitMillimiters, 200, 1.0);
  LOBYTE(v181) = 47;
  std::vector<TelemetryChannel>::push_back(&this->channels, v30);
  TelemetryChannel::~TelemetryChannel(&v141);
  LOBYTE(v181) = 2;
  if ( key._Myres >= 0x10 )
    operator delete(key._Bx._Ptr);
  if ( this->debugPhysics )
  {
    std::string::string((std::string *)&key, "WHEEL_SPEED_LF");
    LOBYTE(v181) = 48;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, this->wheelSpeed, eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 49;
    std::vector<TelemetryChannel>::push_back(&this->channels, v31);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_SPEED_RF");
    LOBYTE(v181) = 50;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->wheelSpeed[1], eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 51;
    std::vector<TelemetryChannel>::push_back(&this->channels, v32);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_SPEED_LR");
    LOBYTE(v181) = 52;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->wheelSpeed[2], eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 53;
    std::vector<TelemetryChannel>::push_back(&this->channels, v33);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_SPEED_RR");
    LOBYTE(v181) = 54;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->wheelSpeed[3], eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 55;
    std::vector<TelemetryChannel>::push_back(&this->channels, v34);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "ENGINE_VEL");
    LOBYTE(v181) = 56;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->engineVel, eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 57;
    std::vector<TelemetryChannel>::push_back(&this->channels, v35);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "ROOT_VEL");
    LOBYTE(v181) = 58;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->rootVel, eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 59;
    std::vector<TelemetryChannel>::push_back(&this->channels, v36);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "DRIVE_VEL");
    LOBYTE(v181) = 60;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->driveVel, eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 61;
    std::vector<TelemetryChannel>::push_back(&this->channels, v37);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "CLUTCH_OPEN_STATE");
    LOBYTE(v181) = 62;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->clutchOpenState, eUnitRadSec, 200, 1.0);
    LOBYTE(v181) = 63;
    std::vector<TelemetryChannel>::push_back(&this->channels, v38);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "CLUTCH_SLIP");
    LOBYTE(v181) = 64;
    TelemetryChannel::TelemetryChannel(&v141, (const std::string *)&key, &this->clutchSlip, eUnitPercentage, 200, 1.0);
    LOBYTE(v181) = 65;
    std::vector<TelemetryChannel>::push_back(&this->channels, v39);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_LOAD_LF");
    LOBYTE(v181) = 66;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[0].status.load,
      eUnitGeneric,
      200,
      1.0);
    LOBYTE(v181) = 67;
    std::vector<TelemetryChannel>::push_back(&this->channels, v40);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_LOAD_RF");
    LOBYTE(v181) = 68;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[1].status.load,
      eUnitGeneric,
      200,
      1.0);
    LOBYTE(v181) = 69;
    std::vector<TelemetryChannel>::push_back(&this->channels, v41);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_LOAD_LR");
    LOBYTE(v181) = 70;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[2].status.load,
      eUnitGeneric,
      200,
      1.0);
    LOBYTE(v181) = 71;
    std::vector<TelemetryChannel>::push_back(&this->channels, v42);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_LOAD_RR");
    LOBYTE(v181) = 72;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[3].status.load,
      eUnitGeneric,
      200,
      1.0);
    LOBYTE(v181) = 73;
    std::vector<TelemetryChannel>::push_back(&this->channels, v43);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_SA_LF");
    LOBYTE(v181) = 74;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[0].status.slipAngleRAD,
      eUnitRad,
      200,
      1.0);
    LOBYTE(v181) = 75;
    std::vector<TelemetryChannel>::push_back(&this->channels, v44);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
      operator delete(key._Bx._Ptr);
    std::string::string((std::string *)&key, "WHEEL_SA_RF");
    LOBYTE(v181) = 76;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&key,
      &car->tyres[1].status.slipAngleRAD,
      eUnitRad,
      200,
      1.0);
    LOBYTE(v181) = 77;
    std::vector<TelemetryChannel>::push_back(&this->channels, v45);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    if ( key._Myres >= 0x10 )
    {
      scale = key._Myres + 1;
      v133 = key._Bx._Ptr;
      v46 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                         (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&key,
                                         &v137);
      std::allocator<wchar_t>::deallocate(v46, v133, scale);
    }
    key._Myres = 15;
    std::string::_Eos((std::string *)&key, 0);
    std::string::string((std::string *)&section, "WHEEL_SA_LR");
    LOBYTE(v181) = 78;
    TelemetryChannel::TelemetryChannel(
      &v141,
      (const std::string *)&section,
      &car->tyres[2].status.slipAngleRAD,
      eUnitRad,
      200,
      1.0);
    LOBYTE(v181) = 79;
    std::vector<TelemetryChannel>::push_back(&this->channels, v47);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string((std::string *)&section);
    std::string::string(&name, "WHEEL_SA_RR");
    LOBYTE(v181) = 80;
    TelemetryChannel::TelemetryChannel(&v141, &name, &car->tyres[3].status.slipAngleRAD, eUnitRad, 200, 1.0);
    LOBYTE(v181) = 81;
    std::vector<TelemetryChannel>::push_back(&this->channels, v48);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&name);
    std::string::string(&v170, "WHEEL_SR_LF");
    LOBYTE(v181) = 82;
    TelemetryChannel::TelemetryChannel(&v141, &v170, &car->tyres[0].status.slipRatio, eUnitGeneric, 200, 100.0);
    LOBYTE(v181) = 83;
    std::vector<TelemetryChannel>::push_back(&this->channels, v49);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v170);
    std::string::string(&v172, "WHEEL_SR_RF");
    LOBYTE(v181) = 84;
    TelemetryChannel::TelemetryChannel(&v141, &v172, &car->tyres[1].status.slipRatio, eUnitGeneric, 200, 100.0);
    LOBYTE(v181) = 85;
    std::vector<TelemetryChannel>::push_back(&this->channels, v50);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v172);
    std::string::string(&v174, "WHEEL_SR_LR");
    LOBYTE(v181) = 86;
    TelemetryChannel::TelemetryChannel(&v141, &v174, &car->tyres[2].status.slipRatio, eUnitGeneric, 200, 100.0);
    LOBYTE(v181) = 87;
    std::vector<TelemetryChannel>::push_back(&this->channels, v51);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v174);
    std::string::string(&v176, "WHEEL_SR_RR");
    LOBYTE(v181) = 88;
    TelemetryChannel::TelemetryChannel(&v141, &v176, &car->tyres[3].status.slipRatio, eUnitGeneric, 200, 100.0);
    LOBYTE(v181) = 89;
    std::vector<TelemetryChannel>::push_back(&this->channels, v52);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v176);
    std::string::string(&v178, "WHEEL_FX_LF");
    LOBYTE(v181) = 90;
    TelemetryChannel::TelemetryChannel(&v141, &v178, &car->tyres[0].status.Fx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 91;
    std::vector<TelemetryChannel>::push_back(&this->channels, v53);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v178);
    std::string::string(&v151, "WHEEL_FX_RF");
    LOBYTE(v181) = 92;
    TelemetryChannel::TelemetryChannel(&v141, &v151, &car->tyres[1].status.Fx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 93;
    std::vector<TelemetryChannel>::push_back(&this->channels, v54);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v151);
    std::string::string(&v173, "WHEEL_FX_LR");
    LOBYTE(v181) = 94;
    TelemetryChannel::TelemetryChannel(&v141, &v173, &car->tyres[2].status.Fx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 95;
    std::vector<TelemetryChannel>::push_back(&this->channels, v55);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v173);
    std::string::string(&v153, "WHEEL_FX_RR");
    LOBYTE(v181) = 96;
    TelemetryChannel::TelemetryChannel(&v141, &v153, &car->tyres[3].status.Fx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 97;
    std::vector<TelemetryChannel>::push_back(&this->channels, v56);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v153);
    std::string::string(&v167, "WHEEL_FY_LF");
    LOBYTE(v181) = 98;
    TelemetryChannel::TelemetryChannel(&v141, &v167, &car->tyres[0].status.Fy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 99;
    std::vector<TelemetryChannel>::push_back(&this->channels, v57);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v167);
    std::string::string(&v155, "WHEEL_FY_RF");
    LOBYTE(v181) = 100;
    TelemetryChannel::TelemetryChannel(&v141, &v155, &car->tyres[1].status.Fy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 101;
    std::vector<TelemetryChannel>::push_back(&this->channels, v58);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v155);
    std::string::string(&v177, "WHEEL_FY_LR");
    LOBYTE(v181) = 102;
    TelemetryChannel::TelemetryChannel(&v141, &v177, &car->tyres[2].status.Fy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 103;
    std::vector<TelemetryChannel>::push_back(&this->channels, v59);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v177);
    std::string::string(&v157, "WHEEL_FY_RR");
    LOBYTE(v181) = 104;
    TelemetryChannel::TelemetryChannel(&v141, &v157, &car->tyres[3].status.Fy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 105;
    std::vector<TelemetryChannel>::push_back(&this->channels, v60);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v157);
    std::string::string(&v149, "WHEEL_DY_LF");
    LOBYTE(v181) = 106;
    TelemetryChannel::TelemetryChannel(&v141, &v149, &car->tyres[0].status.Dy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 107;
    std::vector<TelemetryChannel>::push_back(&this->channels, v61);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v149);
    std::string::string(&v159, "WHEEL_DY_RF");
    LOBYTE(v181) = 108;
    TelemetryChannel::TelemetryChannel(&v141, &v159, &car->tyres[1].status.Dy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 109;
    std::vector<TelemetryChannel>::push_back(&this->channels, v62);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v159);
    std::string::string(&v175, "WHEEL_DY_LR");
    LOBYTE(v181) = 110;
    TelemetryChannel::TelemetryChannel(&v141, &v175, &car->tyres[2].status.Dy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 111;
    std::vector<TelemetryChannel>::push_back(&this->channels, v63);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v175);
    std::string::string(&v161, "WHEEL_DY_RR");
    LOBYTE(v181) = 112;
    TelemetryChannel::TelemetryChannel(&v141, &v161, &car->tyres[3].status.Dy, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 113;
    std::vector<TelemetryChannel>::push_back(&this->channels, v64);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v161);
    std::string::string(&v171, "WHEEL_DX_LF");
    LOBYTE(v181) = 114;
    TelemetryChannel::TelemetryChannel(&v141, &v171, &car->tyres[0].status.Dx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 115;
    std::vector<TelemetryChannel>::push_back(&this->channels, v65);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v171);
    std::string::string(&v163, "WHEEL_DX_RF");
    LOBYTE(v181) = 116;
    TelemetryChannel::TelemetryChannel(&v141, &v163, &car->tyres[1].status.Dx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 117;
    std::vector<TelemetryChannel>::push_back(&this->channels, v66);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v163);
    std::string::string(&v179, "WHEEL_DX_LR");
    LOBYTE(v181) = 118;
    TelemetryChannel::TelemetryChannel(&v141, &v179, &car->tyres[2].status.Dx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 119;
    std::vector<TelemetryChannel>::push_back(&this->channels, v67);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v179);
    std::string::string(&v165, "WHEEL_DX_RR");
    LOBYTE(v181) = 120;
    TelemetryChannel::TelemetryChannel(&v141, &v165, &car->tyres[3].status.Dx, eUnitGeneric, 200, 1.0);
    LOBYTE(v181) = 121;
    std::vector<TelemetryChannel>::push_back(&this->channels, v68);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v165);
    std::string::string(&v150, "CAMBER_LF");
    LOBYTE(v181) = 122;
    TelemetryChannel::TelemetryChannel(&v141, &v150, &car->tyres[0].status.camberRAD, eUnitDeg, 200, 57.29578);
    LOBYTE(v181) = 123;
    std::vector<TelemetryChannel>::push_back(&this->channels, v69);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v150);
    std::string::string(&v152, "CAMBER_RF");
    LOBYTE(v181) = 124;
    TelemetryChannel::TelemetryChannel(&v141, &v152, &car->tyres[1].status.camberRAD, eUnitDeg, 200, -57.29578);
    LOBYTE(v181) = 125;
    std::vector<TelemetryChannel>::push_back(&this->channels, v70);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v152);
    std::string::string(&v154, "CAMBER_LR");
    LOBYTE(v181) = 126;
    TelemetryChannel::TelemetryChannel(&v141, &v154, &car->tyres[2].status.camberRAD, eUnitDeg, 200, 57.29578);
    LOBYTE(v181) = 127;
    std::vector<TelemetryChannel>::push_back(&this->channels, v71);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v154);
    std::string::string(&v156, "CAMBER_RR");
    LOBYTE(v181) = 0x80;
    TelemetryChannel::TelemetryChannel(&v141, &v156, &car->tyres[3].status.camberRAD, eUnitDeg, 200, -57.29578);
    LOBYTE(v181) = -127;
    std::vector<TelemetryChannel>::push_back(&this->channels, v72);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v156);
    std::string::string(&v158, "WHEEL_TEMP_LF");
    LOBYTE(v181) = -126;
    TelemetryChannel::TelemetryChannel(&v141, &v158, &car->tyres[0].thermalModel.coreTemp, eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -125;
    std::vector<TelemetryChannel>::push_back(&this->channels, v73);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v158);
    std::string::string(&v160, "WHEEL_TEMP_RF");
    LOBYTE(v181) = -124;
    TelemetryChannel::TelemetryChannel(&v141, &v160, &car->tyres[1].thermalModel.coreTemp, eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -123;
    std::vector<TelemetryChannel>::push_back(&this->channels, v74);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v160);
    std::string::string(&v162, "WHEEL_TEMP_LR");
    LOBYTE(v181) = -122;
    TelemetryChannel::TelemetryChannel(&v141, &v162, &car->tyres[2].thermalModel.coreTemp, eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -121;
    std::vector<TelemetryChannel>::push_back(&this->channels, v75);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v162);
    std::string::string(&v164, "WHEEL_TEMP_RR");
    LOBYTE(v181) = -120;
    TelemetryChannel::TelemetryChannel(&v141, &v164, &car->tyres[3].thermalModel.coreTemp, eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -119;
    std::vector<TelemetryChannel>::push_back(&this->channels, v76);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v164);
    std::string::string(&v166, "AVG_SURF_TEMP_LF");
    LOBYTE(v181) = -118;
    TelemetryChannel::TelemetryChannel(&v141, &v166, this->avgSurfaceTemps, eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -117;
    std::vector<TelemetryChannel>::push_back(&this->channels, v77);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v166);
    std::string::string(&v168, "AVG_SURF_TEMP_RF");
    LOBYTE(v181) = -116;
    TelemetryChannel::TelemetryChannel(&v141, &v168, &this->avgSurfaceTemps[1], eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -115;
    std::vector<TelemetryChannel>::push_back(&this->channels, v78);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v168);
    std::string::string(&v147, "AVG_SURF_TEMP_LR");
    LOBYTE(v181) = -114;
    TelemetryChannel::TelemetryChannel(&v141, &v147, &this->avgSurfaceTemps[2], eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -113;
    std::vector<TelemetryChannel>::push_back(&this->channels, v79);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v147);
    std::string::string(&v145, "AVG_SURF_TEMP_RR");
    LOBYTE(v181) = -112;
    TelemetryChannel::TelemetryChannel(&v141, &v145, &this->avgSurfaceTemps[3], eUnitGeneric, 10, 1.0);
    LOBYTE(v181) = -111;
    std::vector<TelemetryChannel>::push_back(&this->channels, v80);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v145);
    std::string::string(&result, "OVERSTEER_FACT");
    LOBYTE(v181) = -110;
    TelemetryChannel::TelemetryChannel(&v141, &result, &this->oversteerFactor, eUnitGeneric, 20, 1.0);
    LOBYTE(v181) = -109;
    std::vector<TelemetryChannel>::push_back(&this->channels, v81);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&result);
    std::string::string(&v143, "REAR_SPEED_RATIO");
    LOBYTE(v181) = -108;
    TelemetryChannel::TelemetryChannel(&v141, &v143, &this->rearSpeedRatio, eUnitGeneric, 20, 1.0);
    LOBYTE(v181) = -107;
    std::vector<TelemetryChannel>::push_back(&this->channels, v82);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v143);
    if ( Drivetrain::getTractionType(&car->drivetrain) == AWD )
    {
      std::string::string(&v143, "AWD_FS");
      LOBYTE(v181) = -106;
      TelemetryChannel::TelemetryChannel(&v141, &v143, &this->awdFrontShare, eUnitGeneric, 20, 1.0);
      LOBYTE(v181) = -105;
      std::vector<TelemetryChannel>::push_back(&this->channels, v83);
      TelemetryChannel::~TelemetryChannel(&v141);
      LOBYTE(v181) = 2;
      std::string::~string(&v143);
      std::string::string(&result, "AWD_CETER_LOCK");
      LOBYTE(v181) = -104;
      TelemetryChannel::TelemetryChannel(&v141, &result, &this->awdCenterLock, eUnitGeneric, 20, 1.0);
      LOBYTE(v181) = -103;
      std::vector<TelemetryChannel>::push_back(&this->channels, v84);
      TelemetryChannel::~TelemetryChannel(&v141);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
    }
    if ( BrakeSystem::isUsingEBB(&car->brakeSystem) )
    {
      std::string::string(&v143, "EBB_INSTANT");
      LOBYTE(v181) = -102;
      TelemetryChannel::TelemetryChannel(&v141, &v143, &this->ebbInstant, eUnitGeneric, 20, 1.0);
      LOBYTE(v181) = -101;
      std::vector<TelemetryChannel>::push_back(&this->channels, v85);
      TelemetryChannel::~TelemetryChannel(&v141);
      LOBYTE(v181) = 2;
      std::string::~string(&v143);
    }
    std::string::string(&v143, "FF_GYRO");
    LOBYTE(v181) = -100;
    TelemetryChannel::TelemetryChannel(&v141, &v143, &car->lastGyroFF, eUnitGeneric, 20, 1.0);
    LOBYTE(v181) = -99;
    std::vector<TelemetryChannel>::push_back(&this->channels, v86);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v143);
    std::string::string(&result, "FF_PURE");
    LOBYTE(v181) = -98;
    TelemetryChannel::TelemetryChannel(&v141, &result, &car->lastPureMZFF, eUnitGeneric, 20, 1.0);
    LOBYTE(v181) = -97;
    std::vector<TelemetryChannel>::push_back(&this->channels, v87);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&result);
    std::string::string(&v145, "TOT_LIFT");
    LOBYTE(v181) = -96;
    TelemetryChannel::TelemetryChannel(&v141, &v145, &this->totLift, eUnitForceKG, 50, 1.0);
    LOBYTE(v181) = -95;
    std::vector<TelemetryChannel>::push_back(&this->channels, v88);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v145);
    std::string::string(&v147, "TOT_DRAG");
    LOBYTE(v181) = -94;
    TelemetryChannel::TelemetryChannel(&v141, &v147, &this->totDrag, eUnitForceKG, 50, 1.0);
    LOBYTE(v181) = -93;
    std::vector<TelemetryChannel>::push_back(&this->channels, v89);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v147);
    v90 = (std::vector<TyreCompoundDef> *)&car->aeroMap.wings;
    v91 = 0;
    std::vector<SetupTab *>::begin(
      (std::vector<TyreCompoundDef> *)&car->aeroMap.wings,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      (std::vector<TyreCompoundDef> *)&car->aeroMap.wings,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v92 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v93 = std::to_string(&result, v91);
      LOBYTE(v181) = -92;
      v94 = std::operator+<char>(&v143, "LIFT_W", v93);
      LOBYTE(v181) = -91;
      TelemetryChannel::TelemetryChannel(&v141, v94, &v92->modelData.brakeDXMod, eUnitForceKG, 50, 1.0);
      LOBYTE(v181) = -90;
      std::vector<TelemetryChannel>::push_back(&this->channels, v95);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v91;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v96 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v97 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v98 = std::to_string(&result, v96);
      LOBYTE(v181) = -89;
      v99 = std::operator+<char>(&v143, "DRAG_W", v98);
      LOBYTE(v181) = -88;
      TelemetryChannel::TelemetryChannel(&v141, v99, &v97->modelData.cfXmult, eUnitForceKG, 50, 1.0);
      LOBYTE(v181) = -87;
      std::vector<TelemetryChannel>::push_back(&this->channels, v100);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v96;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v101 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v102 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v103 = std::to_string(&result, v101);
      LOBYTE(v181) = -86;
      v104 = std::operator+<char>(&v143, "GROUNDH_W", v103);
      LOBYTE(v181) = -85;
      TelemetryChannel::TelemetryChannel(&v141, v104, &v102->modelData.maxWearMult, eUnitMillimiters, 50, 1000.0);
      LOBYTE(v181) = -84;
      std::vector<TelemetryChannel>::push_back(&this->channels, v105);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v101;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v106 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v107 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v108 = std::to_string(&result, v106);
      LOBYTE(v181) = -83;
      v109 = std::operator+<char>(&v143, "AOA_W", v108);
      LOBYTE(v181) = -82;
      TelemetryChannel::TelemetryChannel(&v141, v109, &v107->modelData.lsMultY, eUnitDeg, 50, 1.0);
      LOBYTE(v181) = -81;
      std::vector<TelemetryChannel>::push_back(&this->channels, v110);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v106;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v111 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v112 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v113 = std::to_string(&result, v111);
      LOBYTE(v181) = -80;
      v114 = std::operator+<char>(&v143, "GREFF_LIFT_W", v113);
      LOBYTE(v181) = -79;
      TelemetryChannel::TelemetryChannel(
        &v141,
        v114,
        (float *)&v112->modelData.dCamberCurve.references,
        eUnitPercentage,
        50,
        100.0);
      LOBYTE(v181) = -78;
      std::vector<TelemetryChannel>::push_back(&this->channels, v115);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v111;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v116 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v117 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v118 = std::to_string(&result, v116);
      LOBYTE(v181) = -77;
      v119 = std::operator+<char>(&v143, "GREFF_DRAG_W", v118);
      LOBYTE(v181) = -76;
      TelemetryChannel::TelemetryChannel(
        &v141,
        v119,
        (float *)&v117->modelData.dCamberCurve.references._Mylast,
        eUnitPercentage,
        50,
        100.0);
      LOBYTE(v181) = -75;
      std::vector<TelemetryChannel>::push_back(&this->channels, v120);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v116;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
    v121 = 0;
    std::vector<SetupTab *>::begin(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
    std::vector<Mesh *>::end(
      v90,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
    {
      v122 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
      v123 = std::to_string(&result, v121);
      LOBYTE(v181) = -74;
      v124 = std::operator+<char>(&v143, "WINGMULT_W", v123);
      LOBYTE(v181) = -73;
      TelemetryChannel::TelemetryChannel(
        &v141,
        v124,
        (float *)&v122->modelData.dCamberCurve,
        eUnitPercentage,
        50,
        100.0);
      LOBYTE(v181) = -72;
      std::vector<TelemetryChannel>::push_back(&this->channels, v125);
      TelemetryChannel::~TelemetryChannel(&v141);
      std::string::~string(&v143);
      LOBYTE(v181) = 2;
      std::string::~string(&result);
      ++v121;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Wing>>>::operator++(&_S20);
    }
  }
  else
  {
    std::string::string(&v143, "WHEEL_SPEED_LF");
    LOBYTE(v181) = -71;
    TelemetryChannel::TelemetryChannel(&v141, &v143, this->wheelSpeed, eUnitRadSec, 20, 1.0);
    LOBYTE(v181) = -70;
    std::vector<TelemetryChannel>::push_back(&this->channels, v126);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v143);
    std::string::string(&result, "WHEEL_SPEED_RF");
    LOBYTE(v181) = -69;
    TelemetryChannel::TelemetryChannel(&v141, &result, &this->wheelSpeed[1], eUnitRadSec, 20, 1.0);
    LOBYTE(v181) = -68;
    std::vector<TelemetryChannel>::push_back(&this->channels, v127);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&result);
    std::string::string(&v145, "WHEEL_SPEED_LR");
    LOBYTE(v181) = -67;
    TelemetryChannel::TelemetryChannel(&v141, &v145, &this->wheelSpeed[2], eUnitRadSec, 20, 1.0);
    LOBYTE(v181) = -66;
    std::vector<TelemetryChannel>::push_back(&this->channels, v128);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v145);
    std::string::string(&v147, "WHEEL_SPEED_RR");
    LOBYTE(v181) = -65;
    TelemetryChannel::TelemetryChannel(&v141, &v147, &this->wheelSpeed[3], eUnitRadSec, 20, 1.0);
    LOBYTE(v181) = -64;
    std::vector<TelemetryChannel>::push_back(&this->channels, v129);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v147);
  }
  if ( this->debugAI )
  {
    std::string::string(&v143, "AI_TARGET_SPEED");
    LOBYTE(v181) = -63;
    TelemetryChannel::TelemetryChannel(&v141, &v143, &this->aiTargetSpeed, eUnitMeterSec, 100, 1.0);
    LOBYTE(v181) = -62;
    std::vector<TelemetryChannel>::push_back(&this->channels, v130);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&v143);
    std::string::string(&result, "AI_BG_TSPEED");
    LOBYTE(v181) = -61;
    TelemetryChannel::TelemetryChannel(&v141, &result, &this->aiBGTargetSpeed, eUnitMeterSec, 100, 1.0);
    LOBYTE(v181) = -60;
    std::vector<TelemetryChannel>::push_back(&this->channels, v131);
    TelemetryChannel::~TelemetryChannel(&v141);
    LOBYTE(v181) = 2;
    std::string::~string(&result);
    std::string::string(&v145, "AI_OUTSIDE_OFFSET");
    LOBYTE(v181) = -59;
    TelemetryChannel::TelemetryChannel(&v141, &v145, &this->aiOutsideOffset, eUnitMeters, 100, 1.0);
    LOBYTE(v181) = -58;
    std::vector<TelemetryChannel>::push_back(&this->channels, v132);
    TelemetryChannel::~TelemetryChannel(&v141);
    std::string::~string(&v145);
  }
  this->exportEntireSession = 1;
  v181 = -1;
  INIReader::~INIReader(&ini);
}
void Telemetry::save(Telemetry *this, std::wstring filename)
{
  std::wstring *v3; // eax
  Car *v4; // eax
  std::string *v5; // eax
  const char *v6; // ecx
  const std::wstring *v7; // eax
  std::string *v8; // eax
  const char *v9; // ecx
  std::string *v10; // eax
  const char *v11; // ecx
  TelemetryChannel *v12; // esi
  int v13; // edx
  int v14; // ebx
  int v15; // edi
  float *v16; // ecx
  unsigned int v17; // ebp
  int v18; // esi
  Telemetry *v19; // edx
  TelemetryChannel *v20; // edi
  int *v21; // ecx
  float v22; // xmm2_4
  float **v23; // ebx
  float v24; // xmm0_4
  int v25; // ecx
  float v26; // xmm1_4
  double v27; // xmm0_8
  float *v28; // eax
  unsigned int v29; // ebp
  const char *v30; // ecx
  bool v31; // cf
  int v32; // ecx
  int v33; // eax
  const char *v34; // eax
  _BYTE *v35; // esi
  int v36; // ecx
  float v37; // [esp+20h] [ebp-AF0h] BYREF
  float v38; // [esp+24h] [ebp-AECh] BYREF
  Telemetry *v39; // [esp+28h] [ebp-AE8h]
  int *v40; // [esp+2Ch] [ebp-AE4h]
  float v41; // [esp+30h] [ebp-AE0h]
  std::ofstream out; // [esp+34h] [ebp-ADCh] BYREF
  std::string result; // [esp+DCh] [ebp-A34h] BYREF
  std::wstring v44; // [esp+F4h] [ebp-A1Ch] BYREF
  STelemetryChannel c; // [esp+10Ch] [ebp-A04h] BYREF
  TelemetryHeader header; // [esp+538h] [ebp-5D8h] BYREF
  int v47; // [esp+B0Ch] [ebp-4h]

  v39 = this;
  v3 = &filename;
  if ( filename._Myres >= 8 )
    v3 = (std::wstring *)filename._Bx._Ptr;
  v47 = 0;
  std::ofstream::ofstream(&out, v3->_Bx._Buf, 34, 64, 1);
  v4 = this->car;
  LOBYTE(v47) = 1;
  v5 = wstring2string(&result, &v4->unixName);
  v6 = (const char *)v5;
  if ( v5->_Myres >= 0x10 )
    v6 = v5->_Bx._Ptr;
  strcpy(header.car, v6);
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
  v7 = Track::getName(this->car->ksPhysics->track, &v44);
  LOBYTE(v47) = 2;
  v8 = wstring2string(&result, v7);
  v9 = (const char *)v8;
  if ( v8->_Myres >= 0x10 )
    v9 = v8->_Bx._Ptr;
  strcpy(header.track, v9);
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
  result._Myres = 15;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v47) = 1;
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  header.driver_firstname[0] = 0;
  v10 = wstring2string((std::string *)&v44, &this->driverName);
  v11 = (const char *)v10;
  if ( v10->_Myres >= 0x10 )
    v11 = v10->_Bx._Ptr;
  strcpy(header.driver_lastname, v11);
  if ( v44._Myres >= 0x10 )
    operator delete(v44._Bx._Ptr);
  header.channelsCount = this->channels._Mylast - this->channels._Myfirst;
  header.filemagic = -767;
  std::ostream::write(&out, &header, 1480, 0);
  v12 = this->channels._Myfirst;
  v13 = 0;
  v14 = 0;
  v38 = *(float *)&v12;
  v15 = 0;
  v16 = v12->data.values._Myfirst;
  v17 = (unsigned int)((char *)v12->data.values._Mylast - (char *)v16 + 3) >> 2;
  if ( v16 > v12->data.values._Mylast )
    v17 = 0;
  if ( v17 )
  {
    v18 = 0;
    do
    {
      if ( (float)v18 == *v16 )
      {
        ++v13;
      }
      else
      {
        v14 += v13;
        v13 = 0;
        v18 = (int)*v16;
      }
      ++v15;
      ++v16;
    }
    while ( v15 != v17 );
    *(float *)&v12 = v38;
  }
  v19 = v39;
  if ( v39->exportEntireSession )
    v14 = v12->data.values._Mylast - v12->data.values._Myfirst;
  v20 = v39->channels._Mylast;
  if ( v12 != v20 )
  {
    v21 = &v12->data.frequency;
    v22 = (float)v14;
    v40 = &v12->data.frequency;
    v23 = &v12->data.values._Mylast;
    v41 = v22;
    do
    {
      v24 = (float)*v21;
      v25 = *v23 - *(v23 - 1);
      v26 = (float)(int)v23[3] / v24;
      v27 = (double)v25 + _xmm[(unsigned int)((char *)*v23 - (char *)*(v23 - 1)) >> 31];
      v28 = &v38;
      v38 = v26 * v22;
      v37 = v27;
      if ( v37 <= (float)(v26 * v22) )
        v28 = &v37;
      v29 = (int)*v28;
      if ( v19->exportEntireSession )
        v29 = v25;
      if ( (unsigned int)*(v23 - 2) < 0x10 )
        v30 = (const char *)v12;
      else
        v30 = v12->name._Bx._Ptr;
      strcpy(c.name, v30);
      v31 = (unsigned int)*(v23 - 2) < 0x10;
      v32 = (int)v23[3];
      v33 = (int)v23[2];
      c.dataCount = v29;
      c.frequency = v32;
      c.units = v33;
      if ( v31 )
        v34 = (const char *)v12;
      else
        v34 = v12->name._Bx._Ptr;
      _printf("Saving telemetry channel %s with %u samples @ %d\n", v34, v29, v32);
      std::ostream::write(&out, &c, 1068, 0);
      std::ostream::write(&out, *(v23 - 1), 4 * v29, 0);
      v22 = v41;
      ++v12;
      v19 = v39;
      v23 += 16;
      v21 = v40;
    }
    while ( v12 != v20 );
  }
  v35 = &out.gap0[4];
  if ( *(_DWORD *)&out._Filebuffer[4] )
  {
    if ( !std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]) )
      v35 = 0;
    if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
      v35 = 0;
  }
  else
  {
    v35 = 0;
  }
  out._Filebuffer[0] = 0;
  out.gap0[73] = 0;
  std::streambuf::_Init(&out.gap0[4]);
  *(_DWORD *)&out._Filebuffer[4] = 0;
  *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&out.gap0[68] = 0;
  if ( !v35 )
    std::ios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
  LOBYTE(v47) = 0;
  *(_DWORD *)&out.gap0[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = &std::ofstream::`vftable';
  *(_DWORD *)((char *)&v41 + *(_DWORD *)(*(_DWORD *)out.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)out.gap0 + 4) - 96;
  v36 = *(_DWORD *)&out._Filebuffer[4];
  *(_DWORD *)&out.gap0[4] = &std::filebuf::`vftable';
  if ( *(_DWORD *)&out._Filebuffer[4] && **(std::ofstream ***)&out.gap0[16] == (std::ofstream *)&out.gap0[72] )
  {
    std::streambuf::setg(&out.gap0[4], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[64]);
    v36 = *(_DWORD *)&out._Filebuffer[4];
  }
  if ( out._Filebuffer[0] )
  {
    if ( v36 )
    {
      std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]);
      _fclose(*(FILE **)&out._Filebuffer[4]);
    }
    out._Filebuffer[0] = 0;
    out.gap0[73] = 0;
    std::streambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
  }
  std::streambuf::~streambuf<char,std::char_traits<char>>(&out.gap0[4]);
  std::ostream::~ostream<char,std::char_traits<char>>(&out.gap0[8]);
  std::ios::~ios<char,std::char_traits<char>>(&out.gap58[8]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void Telemetry::step(Telemetry *this, float td)
{
  Car *v3; // ecx
  float v4; // xmm0_4
  int v5; // eax
  Car *v6; // ecx
  Car *v7; // ecx
  float *v8; // edi
  int v9; // ebx
  Car *v10; // eax
  int v11; // ecx
  float v12; // eax
  Car *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  double v17; // st7
  Car *v18; // ecx
  double v19; // st7
  Car *v20; // ecx
  double v21; // st7
  double v22; // st7
  Car *v23; // eax
  float *v24; // ebx
  int v25; // edi
  ICarControlsProvider *v26; // eax
  AIDriver *v27; // eax
  AIDriver *v28; // edi
  Car *v29; // [esp-14h] [ebp-28h]
  Speed result; // [esp+4h] [ebp-10h] BYREF
  vec3f v31; // [esp+8h] [ebp-Ch] BYREF

  if ( (dword_186F2A4 & 1) == 0 )
  {
    perfCounter_45.name = "Telemetry::step";
    dword_186F2A4 |= 1u;
    perfCounter_45.group = Physics;
    perfCounter_45.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Telemetry::step" | 0xFF000000;
  }
  if ( this->isEnabled )
  {
    v3 = this->car;
    if ( !v3->physicsGUID )
    {
      v4 = (float)v3->transponder.lapCount;
      this->lapBeacon = v4;
      this->steerAngle = v3->steerLock * v3->controls.steer;
      v5 = (int)v3->body->getAngularVelocity(v3->body, &v31);
      v6 = this->car;
      this->roty = *(float *)(v5 + 4);
      this->carSpeedMS = Car::getSpeed(v6, &result)->value;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      v7 = this->car;
      this->gas = (float)(int)(float)(v7->controls.gas * 100.0);
      this->brake = (float)(int)(float)(v7->controls.brake * 100.0);
      this->gear = (float)(v7->drivetrain.currentGear - 1);
      this->clutch = (float)(int)(float)(100.0 - (float)(v7->controls.clutch * 100.0));
      result.value = Drivetrain::getEngineRPM(&v7->drivetrain);
      v8 = this->wheelSpeed;
      v9 = 0;
      v10 = this->car;
      this->rpms = (float)(int)result.value;
      this->splinePosition = v10->splineLocatorData.npos;
      do
      {
        v11 = *(int *)((char *)this->car->suspensions._Myfirst + (unsigned int)v8++ - (_DWORD)this - 120);
        *(v8 - 5) = *(float *)(*(int (**)(int))(*(_DWORD *)v11 + 36))(v11) * 1000.0;
        v12 = this->car->tyres[v9++].status.angularVelocity;
        *(v8 - 1) = v12;
      }
      while ( v9 < 4 );
      if ( this->debugPhysics )
      {
        v13 = this->car;
        this->clutchOpenState = (float)v13->drivetrain.clutchOpenState;
        v14 = v13->drivetrain.rootVelocity;
        this->rootVel = v14;
        v15 = v13->drivetrain.drive.velocity;
        this->driveVel = v15;
        v16 = v13->drivetrain.engine.velocity;
        this->engineVel = v16;
        this->clutchSlip = v13->drivetrain.rootVelocity / v13->drivetrain.engine.velocity - 1.0;
        v17 = AeroMap::getCurrentLiftKG(&v13->aeroMap);
        v18 = this->car;
        this->totLift = v17;
        v19 = AeroMap::getCurrentDragKG(&v18->aeroMap);
        v20 = this->car;
        this->totDrag = v19;
        this->awdFrontShare = (float)(int)(float)(v20->drivetrain.awdFrontShare * 100.0);
        this->awdCenterLock = v20->drivetrain.awdCenterDiff.preload;
        v21 = DynamicController::getRearSpeedRatio(v20);
        v29 = this->car;
        this->rearSpeedRatio = v21;
        v22 = DynamicController::getOversteerFactor(v29);
        v23 = this->car;
        v24 = this->avgSurfaceTemps;
        this->oversteerFactor = v22;
        v25 = 0;
        this->ebbInstant = v23->brakeSystem.ebbInstant * 100.0;
        do
          *v24++ = TyreThermalModel::getAvgSurfaceTemp(&this->car->tyres[v25++].thermalModel);
        while ( v25 < 4 );
      }
      if ( this->debugAI )
      {
        v26 = Car::getControlsProvider(this->car);
        v27 = (AIDriver *)__RTDynamicCast(
                            v26,
                            0,
                            &ICarControlsProvider `RTTI Type Descriptor',
                            &AIDriver `RTTI Type Descriptor',
                            0);
        v28 = v27;
        if ( v27 )
        {
          this->aiTargetSpeed = AIDriver::getBrakeTargetSpeed(v27) * 3.5999999;
          this->aiBGTargetSpeed = v28->targetSpeed * 3.5999999;
          this->aiOutsideOffset = v28->outsideOffset;
        }
      }
      *(Telemetry **)&result.value = this;
      std::_For_each<TelemetryChannel *,_lambda_6285e9abfaf719bb651f976d9ca47e10_>(
        this->channels._Myfirst,
        this->channels._Mylast,
        (Telemetry::step::__l25::<lambda_6285e9abfaf719bb651f976d9ca47e10> *)&result);
    }
  }
}
