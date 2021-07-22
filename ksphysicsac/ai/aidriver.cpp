#include "aidriver.h
bool AIDriver::getAction(AIDriver *this, DriverActions anAction)
{
  return 0;
}
void AIDriver::AIDriver(AIDriver *this, Car *icar)
{
  char *v2; // edi
  int v3; // eax
  int v4; // eax
  float *v5; // ebx
  float *v6; // edi
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  int v10; // eax
  AISplineRecorder *v11; // ecx
  int v12; // eax
  unsigned int v13; // et2
  int v14; // eax
  float v15; // xmm0_4
  char *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // ebx
  Engine *v19; // ecx
  double v20; // st7
  float v21; // xmm1_4
  int v22; // ebx
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v23; // al
  int v24; // eax
  bool v25; // cf
  int v26; // eax
  int v27; // eax
  bool v28; // zf
  int v29; // ecx
  float v30; // xmm1_4
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v31; // al
  double v32; // st7
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v33; // al
  double v34; // st7
  double v35; // st7
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v36; // al
  double v37; // st7
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v38; // al
  double v39; // st7
  double v40; // st7
  double v41; // st7
  int v42; // ecx
  bool v43; // bl
  SetupManager *v44; // ecx
  SetupItem *v45; // ebx
  double v46; // st7
  bool v47; // bl
  double v48; // st7
  Event<OnPhysicsStepCompleted> *v49; // ecx
  int v50; // eax
  bool v51; // cl
  int v52; // eax
  Event<vec3f> *v53; // ecx
  int v54; // ecx
  AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> *v55; // eax
  int v56; // eax
  std::wstring *v57; // eax
  const std::wstring *v58; // eax
  bool v59; // al
  bool v60; // bl
  int v61; // esi
  std::wstring *v62; // eax
  int v63; // ecx
  int v64; // eax
  int v65; // ecx
  double v66; // st7
  int v67; // esi
  void (*v68)(const char *const, ...); // ebx
  std::wstring *v69; // eax
  const std::wstring *v70; // eax
  Car *v71; // ecx
  bool v72; // al
  bool v73; // bl
  SetupManager *v74; // ecx
  int v75; // eax
  const std::wstring *v76; // eax
  std::vector<float> *v77; // eax
  int v78; // esi
  float *v79; // eax
  int i; // esi
  std::wstring *v81; // eax
  std::wstring *v82; // eax
  double v83; // st7
  double v84; // st7
  AISpline *v85; // eax
  double v86; // st7
  int v87; // ecx
  Drivetrain *v88; // ecx
  int v89; // ecx
  Drivetrain *v90; // ecx
  double v91; // st7
  AISplineRecorder *v92; // ecx
  std::vector<AIStraightData> *v93; // esi
  TyreCompoundDef *v94; // eax
  unsigned int v95; // edi
  AIStraightData *v96; // esi
  std::vector<TyreCompoundDef> *v97; // esi
  TyreCompoundDef *v98; // eax
  float *v99; // eax
  float v100; // xmm0_4
  int v101; // [esp+0h] [ebp-3A4h] BYREF
  _BYTE v102[64]; // [esp+4h] [ebp-3A0h] BYREF
  AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a> v103; // [esp+53h] [ebp-351h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIKersArea> > > _S17; // [esp+54h] [ebp-350h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIStraightData> > > _S11; // [esp+58h] [ebp-34Ch] BYREF
  float kers_total_time; // [esp+5Ch] [ebp-348h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIKersArea> > > _S18; // [esp+60h] [ebp-344h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIKersArea> > > _S15; // [esp+64h] [ebp-340h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIStraightData> > > _S12; // [esp+68h] [ebp-33Ch] BYREF
  float v110; // [esp+6Ch] [ebp-338h]
  AIDriver *v111; // [esp+70h] [ebp-334h]
  AIKersArea ka; // [esp+74h] [ebp-330h] BYREF
  int v113; // [esp+84h] [ebp-320h]
  unsigned int v114; // [esp+88h] [ebp-31Ch]
  AIWingSetup ws; // [esp+8Ch] [ebp-318h] BYREF
  int v116; // [esp+9Ch] [ebp-308h]
  unsigned int v117; // [esp+A0h] [ebp-304h]
  std::wstring key; // [esp+A4h] [ebp-300h] BYREF
  std::wstring aifilename; // [esp+BCh] [ebp-2E8h] BYREF
  INIReader r; // [esp+D4h] [ebp-2D0h] BYREF
  std::wstring result; // [esp+11Ch] [ebp-288h] BYREF
  std::wstring v122; // [esp+134h] [ebp-270h] BYREF
  std::wstring v123; // [esp+14Ch] [ebp-258h] BYREF
  std::wstring setup_filename; // [esp+164h] [ebp-240h] BYREF
  INIReader sini; // [esp+17Ch] [ebp-228h] BYREF
  Curve lutg; // [esp+1C4h] [ebp-1E0h] BYREF
  Curve p; // [esp+214h] [ebp-190h] BYREF
  std::wstring v128; // [esp+264h] [ebp-140h] BYREF
  std::wstring v129; // [esp+27Ch] [ebp-128h] BYREF
  std::wstring v130; // [esp+294h] [ebp-110h] BYREF
  std::wstring v131; // [esp+2ACh] [ebp-F8h] BYREF
  Curve luta; // [esp+2C4h] [ebp-E0h] BYREF
  INIReader it; // [esp+314h] [ebp-90h] BYREF
  int v134; // [esp+3A0h] [ebp-4h]

  v2 = (char *)this;
  _S18._Ptr = (AIKersArea *)this;
  v111 = this;
  _S12._Ptr = (AIStraightData *)icar;
  *(_WORD *)&this->isAutoclutchNeeded = 0;
  this->keyboardEnabled = 1;
  this->ffEnabled = 1;
  v110 = 0.0;
  this->ffFilter = 0.0;
  this->suppressPenalties = 0;
  this->__vftable = (AIDriver_vtbl *)&AIDriver::`vftable';
  this->STRAIGHT_RADIUS = 250.0;
  this->aggression = 0.0;
  this->brakePoint.wasObstacle = 0;
  this->brakePoint.lateralOffset = 0.0;
  this->brakePoint.speedDiff = 0.0;
  this->brakePoint.targetSpeed = -1.0;
  this->brakePoint.targetNormalized = -1.0;
  this->brakePoint.apexNormalized = -1.0;
  v134 = 0;
  this->steerTarget.x = 0.0;
  this->steerTarget.y = 0.0;
  this->steerTarget.z = 0.0;
  PIDController::PIDController(&this->pidSteer);
  *((_DWORD *)v2 + 25) = 1065353216;
  *((_DWORD *)v2 + 26) = 1065353216;
  *((_DWORD *)v2 + 28) = 1061997773;
  *((_OWORD *)v2 + 8) = _xmm;
  *((_DWORD *)v2 + 36) = 0;
  *((_DWORD *)v2 + 37) = 0;
  *(_OWORD *)(v2 + 152) = 0i64;
  *((_DWORD *)v2 + 42) = 0;
  *((_DWORD *)v2 + 44) = 0;
  *((_DWORD *)v2 + 45) = 1065353216;
  *((_DWORD *)v2 + 46) = 1065353216;
  *((_DWORD *)v2 + 47) = 0;
  *((_DWORD *)v2 + 48) = 0;
  *((_DWORD *)v2 + 52) = 1065353216;
  *((_DWORD *)v2 + 53) = 0;
  *((_DWORD *)v2 + 54) = 1065353216;
  v2[300] = 1;
  *((_DWORD *)v2 + 76) = 1065353216;
  *((_DWORD *)v2 + 77) = 0;
  *((_DWORD *)v2 + 78) = 0;
  *((_DWORD *)v2 + 79) = 1065353216;
  *((_OWORD *)v2 + 20) = 0i64;
  *((_WORD *)v2 + 168) = 0;
  *((_DWORD *)v2 + 91) = 0;
  *((double *)v2 + 43) = (float)((float)((float)_rand() * 0.000030518509) * 10.0);
  v3 = _rand();
  *((_DWORD *)v2 + 90) = 0;
  *(_DWORD *)&v102[24] = icar;
  *((double *)v2 + 44) = (float)((float)((float)((float)v3 * 0.000030518509) * 0.40000001) + 0.80000001);
  *((_DWORD *)v2 + 104) = icar;
  v2[420] = 0;
  v2[424] = 0;
  *((_DWORD *)v2 + 107) = -1;
  RaceEngineer::RaceEngineer((RaceEngineer *)v2 + 36, *(Car **)&v102[24]);
  *((_DWORD *)v2 + 111) = 1065353216;
  v2[448] = 0;
  *((_DWORD *)v2 + 113) = 1065353216;
  *((_DWORD *)v2 + 114) = 1041865114;
  _S15._Ptr = (AIKersArea *)(v2 + 460);
  *((_DWORD *)v2 + 115) = 0;
  *((_DWORD *)v2 + 116) = 0;
  *((_DWORD *)v2 + 117) = 0;
  *((_DWORD *)v2 + 118) = 0;
  *((_DWORD *)v2 + 119) = 1064682127;
  *((_DWORD *)v2 + 128) = 0;
  *((_DWORD *)v2 + 130) = 0;
  *((_DWORD *)v2 + 131) = 0;
  AISplinePayload::AISplinePayload((AISplinePayload *)(v2 + 528));
  *((double *)v2 + 77) = DOUBLE_5000_0;
  v2[624] = 0;
  *((_DWORD *)v2 + 157) = 0;
  *((_DWORD *)v2 + 158) = 0;
  *((_DWORD *)v2 + 159) = 0;
  *((_DWORD *)v2 + 160) = 0;
  *((_DWORD *)v2 + 161) = 0;
  *((_DWORD *)v2 + 162) = 0;
  *((_DWORD *)v2 + 163) = 0;
  *((_DWORD *)v2 + 164) = 0;
  *((_DWORD *)v2 + 165) = -1;
  v2[664] = 0;
  v2[668] = 0;
  *((_DWORD *)v2 + 168) = 0;
  *((_DWORD *)v2 + 169) = 0;
  *((_DWORD *)v2 + 170) = 0;
  v2[684] = 0;
  *((_DWORD *)v2 + 172) = 0;
  *((_DWORD *)v2 + 173) = 0;
  *((_DWORD *)v2 + 174) = 0;
  *((_DWORD *)v2 + 175) = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)v2 + 87);
  *((_DWORD *)v2 + 174) = v4;
  *((_DWORD *)v2 + 183) = 0;
  *((_DWORD *)v2 + 176) = 0;
  *(_OWORD *)(v2 + 712) = 0i64;
  *((_DWORD *)v2 + 182) = 0;
  *((_DWORD *)v2 + 184) = 0;
  *((_DWORD *)v2 + 185) = 0;
  *((_DWORD *)v2 + 186) = 0;
  *((_DWORD *)v2 + 187) = 1065353216;
  v2[760] = 0;
  *((_DWORD *)v2 + 191) = 0;
  *((_DWORD *)v2 + 192) = 1065353216;
  *((_DWORD *)v2 + 193) = 1065353216;
  *((_DWORD *)v2 + 194) = 0;
  *((_DWORD *)v2 + 195) = 1065353216;
  *((_DWORD *)v2 + 196) = 1112014848;
  *((_DWORD *)v2 + 197) = 1065353216;
  v2[792] = 0;
  *((_DWORD *)v2 + 201) = 0;
  *((_DWORD *)v2 + 202) = 0;
  *((_DWORD *)v2 + 203) = 0;
  *((_QWORD *)v2 + 102) = 0i64;
  *((_DWORD *)v2 + 206) = 0;
  *((_DWORD *)v2 + 207) = 0;
  *((_DWORD *)v2 + 208) = 0;
  *(_DWORD *)&v102[24] = "AI GENOME:";
  LOBYTE(v134) = 8;
  *((_QWORD *)v2 + 105) = 0i64;
  *((_DWORD *)v2 + 216) = 1065353216;
  *((_DWORD *)v2 + 217) = 0;
  _printf(*(const char *const *)&v102[24]);
  v5 = (float *)(v2 + 220);
  if ( v2 + 220 != v2 + 300 )
  {
    v6 = (float *)(v2 + 300);
    do
    {
      v7 = (float)((float)((float)((float)_rand() * 0.000030518509) * 0.039999999) - 0.02) + 1.0;
      *v5 = v7;
      _printf(" %.3f", v7);
      ++v5;
    }
    while ( v5 != v6 );
    v2 = (char *)_S18._Ptr;
  }
  _printf("\n");
  *((_DWORD *)v2 + 212) = 0;
  *((_DWORD *)v2 + 213) = 0;
  *((_DWORD *)v2 + 214) = 0;
  *((_DWORD *)v2 + 215) = 0;
  AIDriver::initSetup((AIDriver *)v2, (unsigned int)v5);
  v8 = _rand();
  v2[12] = 1;
  *((float *)v2 + 119) = (float)((float)((float)((float)v8 * 0.000030518509) * 0.02) - 0.0099999998) + 0.95999998;
  v9 = _rand();
  v2[116] = 0;
  *((_DWORD *)v2 + 153) = 10000;
  *((_DWORD *)v2 + 100) = -1082130432;
  *((_DWORD *)v2 + 6) = 1094713344;
  *((float *)v2 + 194) = (float)((float)v9 * 0.000030518509) * 10.0;
  *((_DWORD *)v2 + 188) = 0;
  *((_DWORD *)v2 + 189) = 0;
  v10 = *((_DWORD *)v2 + 104);
  *((_DWORD *)v2 + 45) = 1065353216;
  *((_DWORD *)v2 + 7) = 1092616192;
  v11 = *(AISplineRecorder **)(*(_DWORD *)(*(_DWORD *)(v10 + 168) + 308) + 96);
  *((_DWORD *)v2 + 124) = v11;
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 125) = AISplineRecorder::getBestLapSpline(v11);
  v12 = *((_DWORD *)v2 + 104);
  *((double *)v2 + 49) = DOUBLE_1000_0;
  *((_DWORD *)v2 + 101) = 1065353216;
  *((double *)v2 + 25) = DOUBLE_N1_0;
  *((_DWORD *)v2 + 95) = 0;
  *((_DWORD *)v2 + 94) = 0;
  *((_DWORD *)v2 + 96) = 0;
  *((_DWORD *)v2 + 27) = 1169915904;
  v13 = *(_DWORD *)(v12 + 9492) % 5u;
  v2[516] = 0;
  *((_DWORD *)v2 + 103) = v13;
  v14 = _rand();
  *((_DWORD *)v2 + 52) = 1065353216;
  *((_DWORD *)v2 + 23) = 1028443341;
  *((_DWORD *)v2 + 26) = 1065353216;
  v15 = (float)v14;
  v16 = (char *)&_S12._Ptr[19].length;
  *((_DWORD *)v2 + 25) = 1065353216;
  *(_DWORD *)&v102[24] = v16;
  *(_DWORD *)&v102[20] = L"content/cars/";
  *(_DWORD *)&v102[16] = &result;
  *((double *)v2 + 77) = (float)((float)((float)(v15 * 0.000030518509) * 5500.0) + 1500.0);
  v17 = std::operator+<wchar_t>(
          *(std::wstring **)&v102[16],
          *(const wchar_t **)&v102[20],
          *(const std::wstring **)&v102[24]);
  LOBYTE(v134) = 9;
  v18 = std::operator+<wchar_t>(&v122, v17, L"/data/ai.ini");
  aifilename._Myres = 7;
  aifilename._Mysize = 0;
  aifilename._Bx._Buf[0] = 0;
  if ( v18->_Myres >= 8 )
  {
    aifilename._Bx._Ptr = v18->_Bx._Ptr;
    v18->_Bx._Ptr = 0;
  }
  else if ( v18->_Mysize != -1 )
  {
    _memmove(&aifilename, v18, 2 * (v18->_Mysize + 1));
  }
  aifilename._Mysize = v18->_Mysize;
  aifilename._Myres = v18->_Myres;
  v18->_Myres = 7;
  v18->_Mysize = 0;
  v18->_Bx._Buf[0] = 0;
  if ( v122._Myres >= 8 )
    operator delete(v122._Bx._Ptr);
  v122._Myres = 7;
  v122._Mysize = 0;
  v122._Bx._Buf[0] = 0;
  LOBYTE(v134) = 11;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &aifilename);
  v19 = (Engine *)(*((_DWORD *)v2 + 104) + 720);
  LOBYTE(v134) = 12;
  v20 = Engine::getMaxTorqueRPM(v19);
  v21 = *((float *)v2 + 27);
  kers_total_time = v20;
  _printf("AI changeDnRPM=%d chup=%f %.2f\n", (int)kers_total_time, v21, (float)((float)(int)kers_total_time / v21));
  if ( r.ready )
  {
    v114 = 7;
    v113 = 0;
    v22 = 1;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"HEADER", 6u);
    LOBYTE(v134) = 13;
    v23 = (AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a>)INIReader::hasSection(
                                                                                &r,
                                                                                (const std::wstring *)&ka);
    v103 = v23;
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
    {
      operator delete(LODWORD(ka.start));
      v23 = v103;
    }
    if ( v23 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"VERSION", 7u);
      LOBYTE(v134) = 14;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"HEADER", 6u);
      LOBYTE(v134) = 15;
      v22 = INIReader::getInt(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      if ( v114 >= 8 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v117 = 7;
    v116 = 0;
    LOWORD(ws.index) = 0;
    std::wstring::assign((std::wstring *)&ws, L"UP", 2u);
    LOBYTE(v134) = 16;
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"GEARS", 5u);
    LOBYTE(v134) = 17;
    v24 = INIReader::getInt(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
    v25 = v114 < 8;
    *((float *)v2 + 27) = (float)v24;
    if ( !v25 )
      operator delete(LODWORD(ka.start));
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    LOBYTE(v134) = 12;
    if ( v117 >= 8 )
      operator delete(ws.index);
    if ( v22 >= 4 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"DOWN", 4u);
      LOBYTE(v134) = 18;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"GEARS", 5u);
      LOBYTE(v134) = 19;
      v26 = INIReader::getInt(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 28) = (float)v26 * 0.0099999998;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v27 = _rand();
    v28 = *(_DWORD *)(*((_DWORD *)v2 + 104) + 9492) == 0;
    kers_total_time = (float)((float)((float)v27 * 0.000030518509) * 0.15000001) - 0.075000003;
    if ( !v28 )
    {
      _printf("CHANGE DN: %f -> ", *((float *)v2 + 28));
      *(_DWORD *)&v102[12] = v29;
      v30 = (float)(kers_total_time + 1.0) * *((float *)v2 + 28);
      *(double *)&v102[20] = kers_total_time;
      *((float *)v2 + 28) = v30;
      _printf("%f (VAR: %f)\n", v30, *(double *)&v102[20]);
    }
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"STEER", 5u);
    LOBYTE(v134) = 20;
    v31 = (AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a>)INIReader::hasSection(
                                                                                &r,
                                                                                (const std::wstring *)&ka);
    v103 = v31;
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
    {
      operator delete(LODWORD(ka.start));
      v31 = v103;
    }
    if ( v31 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"STEER_GAIN", 0xAu);
      LOBYTE(v134) = 21;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"STEER", 5u);
      LOBYTE(v134) = 22;
      v32 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 23) = v32;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"LOOKAHEAD", 9u);
    LOBYTE(v134) = 23;
    v33 = (AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a>)INIReader::hasSection(
                                                                                &r,
                                                                                (const std::wstring *)&ka);
    v103 = v33;
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
    {
      operator delete(LODWORD(ka.start));
      v33 = v103;
    }
    if ( v33 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"BASE", 4u);
      LOBYTE(v134) = 24;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"LOOKAHEAD", 9u);
      LOBYTE(v134) = 25;
      v34 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 6) = v34;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
      if ( v22 <= 1 )
      {
        v117 = 7;
        v116 = 0;
        LOWORD(ws.index) = 0;
        std::wstring::assign((std::wstring *)&ws, L"GAS_BRAKE_LOOKAHEAD", 0x13u);
        LOBYTE(v134) = 26;
        v114 = 7;
        v113 = 0;
        LOWORD(ka.start) = 0;
        std::wstring::assign((std::wstring *)&ka, L"LOOKAHEAD", 9u);
        LOBYTE(v134) = 27;
        v35 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
        v25 = v114 < 8;
        *((float *)v2 + 7) = v35;
        if ( !v25 )
          operator delete(LODWORD(ka.start));
        v114 = 7;
        v113 = 0;
        LOWORD(ka.start) = 0;
        LOBYTE(v134) = 12;
        if ( v117 >= 8 )
          operator delete(ws.index);
      }
    }
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"UNDERSTEER", 0xAu);
    LOBYTE(v134) = 28;
    v36 = (AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a>)INIReader::hasSection(
                                                                                &r,
                                                                                (const std::wstring *)&ka);
    v103 = v36;
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
    {
      operator delete(LODWORD(ka.start));
      v36 = v103;
    }
    if ( v36 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"HINT", 4u);
      LOBYTE(v134) = 29;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"UNDERSTEER", 0xAu);
      LOBYTE(v134) = 30;
      v37 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 76) = v37;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"TYRES", 5u);
    LOBYTE(v134) = 31;
    v38 = (AIDriver::{ctor}::__l69::<lambda_d2f07653d40c3c1f2fc5b2b0a3b01c4a>)INIReader::hasSection(
                                                                                &r,
                                                                                (const std::wstring *)&ka);
    v103 = v38;
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
    {
      operator delete(LODWORD(ka.start));
      v38 = v103;
    }
    if ( v38 )
    {
      v117 = 7;
      v116 = 0;
      LOWORD(ws.index) = 0;
      std::wstring::assign((std::wstring *)&ws, L"HINT", 4u);
      LOBYTE(v134) = 32;
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      std::wstring::assign((std::wstring *)&ka, L"TYRES", 5u);
      LOBYTE(v134) = 33;
      v39 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 46) = v39;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v117 = 7;
    v116 = 0;
    LOWORD(ws.index) = 0;
    std::wstring::assign((std::wstring *)&ws, L"BRAKE_HINT", 0xAu);
    LOBYTE(v134) = 34;
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"PEDALS", 6u);
    LOBYTE(v134) = 35;
    v40 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
    v25 = v114 < 8;
    *((float *)v2 + 25) = v40;
    if ( !v25 )
      operator delete(LODWORD(ka.start));
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    LOBYTE(v134) = 12;
    if ( v117 >= 8 )
      operator delete(ws.index);
    if ( *((float *)v2 + 25) == 0.0 )
      *((_DWORD *)v2 + 25) = 1065353216;
    *((_DWORD *)v2 + 26) = *((_DWORD *)v2 + 25);
    if ( v22 >= 3 )
    {
      std::wstring::wstring((std::wstring *)&ws, L"AERO_HINT");
      LOBYTE(v134) = 36;
      std::wstring::wstring((std::wstring *)&ka, L"PHYSICS_HINTS");
      LOBYTE(v134) = 37;
      v41 = INIReader::getFloat(&r, (const std::wstring *)&ka, (const std::wstring *)&ws);
      v25 = v114 < 8;
      *((float *)v2 + 45) = v41;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( v117 >= 8 )
        operator delete(ws.index);
    }
    v42 = *((_DWORD *)v2 + 104);
    if ( *(_BYTE *)(v42 + 1052) && *(_DWORD *)(v42 + 1300) == *(_DWORD *)(v42 + 1304) )
    {
      v2[424] = 1;
      *((_DWORD *)v2 + 107) = 1;
    }
    v114 = 7;
    v113 = 0;
    LOWORD(ka.start) = 0;
    std::wstring::assign((std::wstring *)&ka, L"BRAKE_BIAS", 0xAu);
    LOBYTE(v134) = 38;
    v43 = INIReader::hasSection(&r, (const std::wstring *)&ka);
    LOBYTE(v134) = 12;
    if ( v114 >= 8 )
      operator delete(LODWORD(ka.start));
    if ( v43 )
    {
      std::wstring::wstring((std::wstring *)&ka, L"FRONT_BIAS");
      v44 = (SetupManager *)*((_DWORD *)v2 + 104);
      LOBYTE(v134) = 39;
      v45 = SetupManager::getSetupItem(v44 + 212, (const std::wstring *)&ka);
      LOBYTE(v134) = 12;
      if ( v114 >= 8 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      if ( v45 )
      {
        *(_DWORD *)&v102[24] = L"VALUE";
        v45->attached = 1;
        std::wstring::wstring(&key, *(const wchar_t **)&v102[24]);
        LOBYTE(v134) = 40;
        std::wstring::wstring((std::wstring *)&ws, L"BRAKE_BIAS");
        LOBYTE(v134) = 41;
        v46 = INIReader::getFloat(&r, (const std::wstring *)&ws, &key);
        v25 = v117 < 8;
        v45->newValue = v46;
        if ( !v25 )
          operator delete(ws.index);
        v117 = 7;
        v116 = 0;
        LOWORD(ws.index) = 0;
        LOBYTE(v134) = 12;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        *(double *)&v102[20] = v45->newValue;
        _printf("AI car %d overriding Brake bias to %f\n", *(_DWORD *)&v102[20], *(double *)&v102[24]);
      }
    }
    std::wstring::wstring(&key, L"WING_VARIATION");
    LOBYTE(v134) = 42;
    v47 = INIReader::hasSection(&r, &key);
    LOBYTE(v134) = 12;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v47 )
    {
      std::wstring::wstring(&key, L"VALUE");
      LOBYTE(v134) = 43;
      std::wstring::wstring((std::wstring *)&ka, L"WING_VARIATION");
      LOBYTE(v134) = 44;
      v48 = INIReader::getFloat(&r, (const std::wstring *)&ka, &key);
      v25 = v114 < 8;
      *((float *)v2 + 114) = v48;
      if ( !v25 )
        operator delete(LODWORD(ka.start));
      v114 = 7;
      v113 = 0;
      LOWORD(ka.start) = 0;
      LOBYTE(v134) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      *(double *)&v102[20] = *((float *)v2 + 114);
      _printf("AI car %d overriding wingVariation to %f\n", *(_DWORD *)&v102[20], *(double *)&v102[24]);
    }
  }
  if ( *((float *)v2 + 6) == 0.0 )
    *((_DWORD *)v2 + 6) = 1094713344;
  *((_DWORD *)v2 + 7) = 0;
  *((_DWORD *)v2 + 102) = 100;
  *((_DWORD *)v2 + 8) = 1065353216;
  *((_QWORD *)v2 + 46) = 0i64;
  PIDController::setPID((PIDController *)(v2 + 72), 0.30000001, 0.02, 0.02);
  *((_DWORD *)v2 + 126) = 0;
  *((_DWORD *)v2 + 127) = 0;
  *((_DWORD *)v2 + 30) = 0;
  AIDriver::initTyreStrategies((AIDriver *)v2);
  *(_DWORD *)&v102[24] = v2;
  *(_DWORD *)v102 = &std::_Func_impl<std::_Callable_obj<_lambda_c63e5c2c5fcdba473b5343f692790cb7_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v102[4] = v2;
  *(_DWORD *)&v102[16] = v102;
  v49 = (Event<OnPhysicsStepCompleted> *)(*((_DWORD *)v2 + 104) + 40);
  LOBYTE(v134) = 12;
  Event<std::wstring>::addHandler(v49, *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v102, v2);
  v50 = *((_DWORD *)v2 + 104);
  v51 = *(_BYTE *)(v50 + 1729) && *(_BYTE *)(v50 + 1728);
  v2[792] = v51;
  *(_BYTE *)(v50 + 1729) = 0;
  v52 = *((_DWORD *)v2 + 104);
  *(_DWORD *)&v102[24] = v2;
  *(_BYTE *)(v52 + 1837) = 0;
  *(_BYTE *)(*((_DWORD *)v2 + 104) + 9832) = 0;
  *(_BYTE *)(*((_DWORD *)v2 + 104) + 9244) = 1;
  *(_BYTE *)(*((_DWORD *)v2 + 104) + 9245) = 1;
  *(_QWORD *)(*((_DWORD *)v2 + 104) + 1632) = 0i64;
  *(_BYTE *)(*((_DWORD *)v2 + 104) + 9720) = 1;
  *(_DWORD *)(*((_DWORD *)v2 + 104) + 8588) = 1065353216;
  *(_DWORD *)v102 = &std::_Func_impl<std::_Callable_obj<_lambda_c68e5ae7a467f872cbd5cba48930e040_,0>,std::allocator<std::_Func_class<void,vec3f const &>>,void,vec3f const &>::`vftable';
  *(_DWORD *)&v102[4] = v2;
  *(_DWORD *)&v102[16] = v102;
  v53 = (Event<vec3f> *)(*((_DWORD *)v2 + 104) + 64);
  LOBYTE(v134) = 12;
  Event<vec3f>::addHandler(v53, *(std::function<void __cdecl(vec3f const &)> *)v102, *(void **)&v102[24]);
  AIDriver::selectTimeStartTime((AIDriver *)v2);
  *(_DWORD *)&v102[24] = v2;
  kers_total_time = *(float *)&v2;
  ws.index = (int)v102;
  *(_DWORD *)&v102[16] = 0;
  v101 = v54;
  LOBYTE(v134) = 47;
  std::allocator<std::_Func_class<void,SessionInfo const &>>::allocator<std::_Func_class<void,SessionInfo const &>>(
    (std::allocator<std::_Func_class<void,SessionInfo const &> > *)&v101,
    (const std::allocator<std::_Func_class<void,SessionInfo const &> > *)&v103);
  v55 = std::forward<_lambda_b1b5a2018750bb2261f39e860a2780a3_>((AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> *)&kers_total_time);
  std::_Func_class<void,SessionInfo const &>::_Do_alloc<std::_Func_impl<std::_Callable_obj<_lambda_b1b5a2018750bb2261f39e860a2780a3_,0>,std::allocator<std::_Func_class<void,SessionInfo const &>>,void,SessionInfo const &>,_lambda_b1b5a2018750bb2261f39e860a2780a3_,std::allocator<std::_Func_class<void,SessionInfo const &>>>(
    (std::_Func_class<void,SessionInfo const &> *)v102,
    v55,
    (std::allocator<std::_Func_class<void,SessionInfo const &> >)v101);
  v56 = *((_DWORD *)v2 + 104);
  LOBYTE(v134) = 12;
  Event<float>::addHandler(
    (Event<SessionInfo> *)(*(_DWORD *)(v56 + 168) + 84),
    *(std::function<void __cdecl(SessionInfo const &)> *)v102,
    *(void **)&v102[24]);
  AIDriver::setUltraGrip((AIDriver *)v2, 1.2);
  v57 = std::operator+<wchar_t>(&v131, L"content/cars/", (const std::wstring *)(*((_DWORD *)v2 + 104) + 236));
  LOBYTE(v134) = 50;
  v58 = std::operator+<wchar_t>(&v128, v57, L"/data/tyres.ini");
  LOBYTE(v134) = 51;
  INIReader::INIReader(&it, v58);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v128);
  LOBYTE(v134) = 54;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v131);
  std::wstring::wstring(&key, L"COMPOUND_DEFAULT");
  LOBYTE(v134) = 55;
  v59 = INIReader::hasSection(&it, &key);
  LOBYTE(v134) = 54;
  v60 = v59;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  if ( v60 )
  {
    std::wstring::wstring((std::wstring *)&ka, L"INDEX");
    LOBYTE(v134) = 56;
    std::wstring::wstring(&key, L"COMPOUND_DEFAULT");
    LOBYTE(v134) = 57;
    *((_DWORD *)v2 + 165) = INIReader::getInt(&it, &key, (const std::wstring *)&ka);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v134) = 54;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ka);
    v61 = *((_DWORD *)v2 + 104);
    *(_DWORD *)&v102[24] = *((_DWORD *)v2 + 165);
    v62 = std::wstring::c_str((std::wstring *)(v61 + 236));
    _printf_s(
      "AI, preferred compound for car: %u %S is %d\n",
      *(_DWORD *)(v61 + 9492),
      v62->_Bx._Buf,
      *(_DWORD *)&v102[24]);
  }
  *(_DWORD *)&v102[24] = v2;
  std::function<void __cdecl (OnCollisionEvent const &)>::function<void __cdecl (OnCollisionEvent const &)>(
    (std::function<void __cdecl(OnCollisionEvent const &)> *)v102,
    &v103);
  Event<float>::addHandler(
    (Event<SessionInfo> *)(*((_DWORD *)v2 + 104) + 88),
    *(std::function<void __cdecl(SessionInfo const &)> *)v102,
    *(void **)&v102[24]);
  Curve::Curve(&lutg);
  LOBYTE(v134) = 58;
  Curve::addValue(&lutg, 0.69999999, 4.0);
  Curve::addValue(&lutg, 1.0, 3.0);
  Curve::addValue(&lutg, 1.3, 2.0);
  Curve::addValue(&lutg, 1.55, 1.0);
  Curve::addValue(&lutg, 2.0, 0.60000002);
  kers_total_time = Car::getTotalMass((Car *)*((_DWORD *)v2 + 104), 1);
  *(_DWORD *)&v102[24] = v63;
  *(float *)&_S17._Ptr = Tyre::getDY(
                           (Tyre *)(*((_DWORD *)v2 + 104) + 5304),
                           (float)(kers_total_time * 0.25) * 9.8059998);
  kers_total_time = Curve::getValue(&lutg, *(float *)&_S17._Ptr);
  Curve::Curve(&luta);
  LOBYTE(v134) = 59;
  Curve::addValue(&luta, 0.0, 1.0);
  Curve::addValue(&luta, 0.2, 0.2);
  Curve::addValue(&luta, 1.0, 0.0);
  v64 = *((_DWORD *)v2 + 104);
  *(_DWORD *)&v102[24] = v65;
  v66 = Curve::getValue(&luta, (float)(1.0 - *(float *)(v64 + 5732)) * *(float *)&_S17._Ptr);
  v67 = *((_DWORD *)v2 + 104);
  *(float *)&_S11._Ptr = v66 * kers_total_time + 1.0;
  *((float *)v2 + 187) = *(float *)&_S11._Ptr;
  if ( Drivetrain::getTractionType((Drivetrain *)(v67 + 504)) )
    *((float *)v2 + 187) = *(float *)&_S11._Ptr * 1.3;
  v68 = (void (*)(const char *const, ...))_printf;
  _printf(
    "AI OVERSTEER FACTOR: %f , grip: %f , asy: %f (%f)\n",
    *((float *)v2 + 187),
    *(float *)&_S17._Ptr,
    *(float *)(v67 + 5732),
    (float)((float)(1.0 - *(float *)(v67 + 5732)) * *(float *)&_S17._Ptr));
  v69 = std::operator+<wchar_t>(&v130, L"content/cars/", (const std::wstring *)(*((_DWORD *)v2 + 104) + 236));
  LOBYTE(v134) = 60;
  v70 = std::operator+<wchar_t>(&v129, v69, L"/data/setup.ini");
  v71 = (Car *)*((_DWORD *)v2 + 104);
  LOBYTE(v134) = 61;
  Car::getConfigPath(v71, &setup_filename, v70);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v129);
  LOBYTE(v134) = 64;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v130);
  INIReader::INIReader(&sini, &setup_filename);
  LOBYTE(v134) = 65;
  if ( sini.ready )
  {
    _printf("AI SETUP FOUND\n");
    std::wstring::wstring(&key, L"FINAL_GEAR_RATIO");
    LOBYTE(v134) = 66;
    v72 = INIReader::hasSection(&sini, &key);
    LOBYTE(v134) = 65;
    v73 = v72;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    if ( v73
      && (std::wstring::wstring(&key, L"FINAL_RATIO"),
          v74 = (SetupManager *)*((_DWORD *)v2 + 104),
          LOBYTE(v134) = 67,
          *((_DWORD *)v2 + 200) = SetupManager::getSetupItem(v74 + 212, &key),
          LOBYTE(v134) = 65,
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key),
          (v75 = *((_DWORD *)v2 + 200)) != 0) )
    {
      v68 = (void (*)(const char *const, ...))_printf;
      if ( *(_BYTE *)(v75 + 68) )
      {
        _printf("AI can change final ratio\n");
        std::wstring::wstring((std::wstring *)&ka, L"RATIOS");
        LOBYTE(v134) = 68;
        std::wstring::wstring(&key, L"FINAL_GEAR_RATIO");
        LOBYTE(v134) = 69;
        v76 = INIReader::getString(&sini, &v123, &key, (const std::wstring *)&ka);
        *(_DWORD *)&v102[24] = *((_DWORD *)v2 + 104);
        LOBYTE(v134) = 70;
        v77 = loadGearRatiosFromFile((std::vector<float> *)&ws, v76, *(Car **)&v102[24]);
        LOBYTE(v134) = 71;
        std::vector<float>::operator=((std::vector<float> *)v2 + 67, v77);
        std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&ws);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v123);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        LOBYTE(v134) = 65;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ka);
        std::vector<SetupTab *>::begin(
          (std::vector<TyreCompoundDef> *)v2 + 67,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11);
        std::vector<Mesh *>::end(
          (std::vector<TyreCompoundDef> *)v2 + 67,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
        if ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
               (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11,
               (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17) )
        {
          v78 = 0;
          do
          {
            v79 = (float *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11);
            _printf("RATIO %d: %f\n", v78++, *v79);
            std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > *)&_S11);
          }
          while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                    (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11,
                    (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17) );
        }
      }
    }
    else
    {
      v68 = (void (*)(const char *const, ...))_printf;
    }
    for ( i = 0; i < 10; ++i )
    {
      v81 = std::to_wstring(&v123, i);
      LOBYTE(v134) = 72;
      std::operator+<wchar_t>((std::wstring *)&ka, L"WING_", v81);
      LOBYTE(v134) = 74;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v123);
      v82 = std::wstring::c_str((std::wstring *)&ka);
      v68("Checking: %S\n", v82->_Bx._Buf);
      if ( INIReader::hasSection(&sini, (const std::wstring *)&ka) )
      {
        AIWingSetup::AIWingSetup(&ws);
        v68("yes\n");
        ws.item = SetupManager::getSetupItem((SetupManager *)(*((_DWORD *)v2 + 104) + 10176), (const std::wstring *)&ka);
        if ( ws.item )
        {
          v68("oi\n");
          ws.index = i;
          std::wstring::wstring(&key, L"MAX");
          LOBYTE(v134) = 75;
          v83 = INIReader::getFloat(&sini, (const std::wstring *)&ka, &key);
          LOBYTE(v134) = 74;
          ws.maxValue = v83;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
          std::wstring::wstring(&key, L"MIN");
          LOBYTE(v134) = 76;
          v84 = INIReader::getFloat(&sini, (const std::wstring *)&ka, &key);
          LOBYTE(v134) = 74;
          ws.minValue = v84;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
          std::vector<AIKersArea>::push_back((std::vector<AIWingSetup> *)(v2 + 824), &ws);
          v68("AI can change Wing: %d (%f, %f)\n", i, ws.minValue, ws.maxValue);
        }
      }
      LOBYTE(v134) = 65;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ka);
    }
  }
  v85 = AISplineRecorder::getBestLapSpline(*((AISplineRecorder **)v2 + 124));
  v86 = AISpline::getStraightFactor(v85);
  v68("STRAIGHT FACTOR: %f\n", v86);
  kers_total_time = Autoclutch::getDownshiftSequenceDuration((Autoclutch *)(*((_DWORD *)v2 + 104) + 9232));
  if ( kers_total_time > 0.5 )
  {
    v68("AI creating new downshift profile\n");
    Curve::Curve(&p);
    LOBYTE(v134) = 77;
    Curve::addValue(&p, 0.0, 1.0);
    Curve::addValue(&p, 0.0099999998, 0.0);
    *(_DWORD *)&v102[24] = v87;
    v88 = (Drivetrain *)(*((_DWORD *)v2 + 104) + 504);
    *(_DWORD *)&v102[24] = 0;
    *(float *)&v102[20] = Drivetrain::getGearDnTime(v88);
    Curve::addValue(&p, *(float *)&v102[20], *(float *)&v102[24]);
    *(_DWORD *)&v102[24] = v89;
    v90 = (Drivetrain *)(*((_DWORD *)v2 + 104) + 504);
    *(_DWORD *)&v102[24] = 1065353216;
    *(double *)&ws.index = Drivetrain::getGearDnTime(v90);
    *(float *)&v102[20] = *(double *)&ws.index * 2.5;
    Curve::addValue(&p, *(float *)&v102[20], *(float *)&v102[24]);
    Curve::print(&p);
    Autoclutch::setDownshiftProfile((Autoclutch *)(*((_DWORD *)v2 + 104) + 9232), &p);
    LOBYTE(v134) = 65;
    Curve::~Curve(&p);
  }
  v68("Car half width: %f\n", *(float *)(*((_DWORD *)v2 + 104) + 124));
  if ( Kers::isPresent((Kers *)(*((_DWORD *)v2 + 104) + 10276)) )
  {
    v68("INITIALIZING AI KERS STRATEGY\n");
    v91 = Kers::getDischargeTimeS((Kers *)(*((_DWORD *)v2 + 104) + 10276));
    v92 = (AISplineRecorder *)*((_DWORD *)v2 + 124);
    kers_total_time = v91;
    *(float *)&_S17._Ptr = 0.0;
    v93 = &AISplineRecorder::getBestLapSpline(v92)->straights;
    ws.index = (int)v93;
    std::vector<SetupTab *>::begin(
      (std::vector<TyreCompoundDef> *)v93,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11);
    std::vector<Mesh *>::end(
      (std::vector<TyreCompoundDef> *)v93,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S12);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S12) )
    {
      v94 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S11);
      *(float *)&_S17._Ptr = *(float *)&v94->name._Bx._Alias[4] + *(float *)&_S17._Ptr;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIStraightData>>>::operator++(&_S11);
    }
    v68("Kers total straight length: %f\n", *(float *)&_S17._Ptr);
    *(float *)&_S11._Ptr = 0.0;
    v95 = 0;
    v68("KERS total time: %f\n", kers_total_time);
    do
    {
      if ( v95 >= std::vector<AIStraightData>::size(v93) )
        break;
      v96 = std::vector<AIStraightData>::operator[](v93, v95);
      *(float *)&_S11._Ptr = (float)(v96->length / *(float *)&_S17._Ptr) + *(float *)&_S11._Ptr;
      AIWingSetup::AIWingSetup((AIWingSetup *)&ka);
      ka.start = v96->start;
      ka.end = v96->end;
      ka.length = v96->length;
      std::vector<AIKersArea>::push_back((std::vector<AIWingSetup> *)_S15._Ptr, (const AIWingSetup *)&ka);
      v68(
        "Using straight %d for kers, %f to %f tot: %f, length: %f\n",
        v95,
        v96->start,
        v96->end,
        *(float *)&_S11._Ptr,
        v96->length);
      v93 = (std::vector<AIStraightData> *)ws.index;
      ++v95;
    }
    while ( *(float *)&_S11._Ptr < 0.5 );
    v97 = (std::vector<TyreCompoundDef> *)_S15._Ptr;
    std::vector<SetupTab *>::begin(
      (std::vector<TyreCompoundDef> *)_S15._Ptr,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
    std::vector<Mesh *>::end(
      v97,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S15);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
              (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17,
              (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S15) )
    {
      v98 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
      v110 = *(float *)&v98->name._Bx._Alias[4] + v110;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIKersArea>>>::operator++(&_S17);
    }
    std::vector<SetupTab *>::begin(
      v97,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
    std::vector<Mesh *>::end(
      v97,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S18);
    if ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
           (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17,
           (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S18) )
    {
      *(float *)&ws.index = 1.0 / v110;
      do
      {
        v99 = (float *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
        v100 = (float)(v99[2] * *(float *)&ws.index) * kers_total_time;
        v99[3] = v100;
        v68("KERS AREA: %f -> %f time: %f\n", *v99, v99[1], v100);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AIKersArea>>>::operator++(&_S17);
      }
      while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17,
                (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S18) );
    }
  }
  LOBYTE(v134) = 64;
  INIReader::~INIReader(&sini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setup_filename);
  LOBYTE(v134) = 58;
  Curve::~Curve(&luta);
  LOBYTE(v134) = 54;
  Curve::~Curve(&lutg);
  LOBYTE(v134) = 12;
  INIReader::~INIReader(&it);
  LOBYTE(v134) = 11;
  INIReader::~INIReader(&r);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&aifilename);
}
void AIDriver::~AIDriver(AIDriver *this)
{
  Event<OnLapCompletedEvent> *v2; // ecx
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v3; // [esp-4h] [ebp-24h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+10h] [ebp-10h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  this->__vftable = (AIDriver_vtbl *)&AIDriver::`vftable';
  v2 = &this->car->evOnLapCompleted;
  v5 = 8;
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)v2, this);
  Event<OnStepCompleteEvent>::removeHandler(&this->car->evOnForcedPositionCompleted, this);
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)&this->car->ksPhysics->evOnNewSessionPhysics, this);
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)&this->car->evOnCollisionEvent, this);
  if ( this->aiSetup.wings._Myfirst )
  {
    operator delete(this->aiSetup.wings._Myfirst);
    this->aiSetup.wings._Myfirst = 0;
    this->aiSetup.wings._Mylast = 0;
    this->aiSetup.wings._Myend = 0;
  }
  if ( this->aiSetup.ratios._Myfirst )
  {
    operator delete(this->aiSetup.ratios._Myfirst);
    this->aiSetup.ratios._Myfirst = 0;
    this->aiSetup.ratios._Mylast = 0;
    this->aiSetup.ratios._Myend = 0;
  }
  v3 = this->tyreStrategies._Myhead;
  LOBYTE(v5) = 6;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    &this->tyreStrategies,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v3->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v3);
  operator delete(this->tyreStrategies._Myhead);
  if ( this->brakeProfiler.items._Myfirst )
  {
    operator delete(this->brakeProfiler.items._Myfirst);
    this->brakeProfiler.items._Myfirst = 0;
    this->brakeProfiler.items._Mylast = 0;
    this->brakeProfiler.items._Myend = 0;
  }
  if ( this->brakeObstacles._Myfirst )
  {
    operator delete(this->brakeObstacles._Myfirst);
    this->brakeObstacles._Myfirst = 0;
    this->brakeObstacles._Mylast = 0;
    this->brakeObstacles._Myend = 0;
  }
  if ( this->opponentData._Myfirst )
  {
    operator delete(this->opponentData._Myfirst);
    this->opponentData._Myfirst = 0;
    this->opponentData._Mylast = 0;
    this->opponentData._Myend = 0;
  }
  if ( this->kersAreas._Myfirst )
  {
    operator delete(this->kersAreas._Myfirst);
    this->kersAreas._Myfirst = 0;
    this->kersAreas._Mylast = 0;
    this->kersAreas._Myend = 0;
  }
  LOBYTE(v5) = 1;
  RaceEngineer::~RaceEngineer(&this->engineer);
  LOBYTE(v5) = 0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->pidSteer);
  this->__vftable = (AIDriver_vtbl *)&ICarControlsProvider::`vftable';
}
AIDriver *AIDriver::`scalar deleting destructor'(AIDriver *this, unsigned int a2)
{
  AIDriver::~AIDriver(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void AIDriver::acquireControls(AIDriver *this, CarControls *controls, float dt, CarControlsInput *input)
{
  float v4; // edi
  Car *v5; // ecx
  int v6; // ecx
  int v7; // esi
  long double v8; // st7
  long double v9; // st7
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  AISplineRecorder *v13; // ecx
  double v14; // st7
  float v15; // xmm0_4
  Car *v16; // ecx
  Speed *v17; // esi
  int v18; // ecx
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  Car *v22; // ecx
  float v23; // eax
  const __m128i *v24; // edi
  const __m128i *v25; // esi
  float v26; // xmm3_4
  __m128i v27; // xmm0
  CarControls *v28; // esi
  const __m128i *v29; // eax
  __m128i v30; // xmm0
  int v31; // eax
  float *v32; // eax
  int v33; // edx
  char v34; // cl
  bool v35; // cf
  Car *v36; // ecx
  int v37; // ecx
  float v38; // xmm2_4
  float v39; // xmm0_4
  Car *v40; // ecx
  float v41; // xmm1_4
  float v42; // xmm2_4
  AISplineRecorder *v43; // ecx
  int v44; // ecx
  double v45; // xmm1_8
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float normalizedPos; // [esp+3Ch] [ebp-44h]
  float normalizedPosa; // [esp+3Ch] [ebp-44h]
  unsigned int v53; // [esp+48h] [ebp-38h]
  vec3f ihed; // [esp+68h] [ebp-18h] BYREF
  Speed result; // [esp+74h] [ebp-Ch] BYREF
  float right; // [esp+78h] [ebp-8h] BYREF
  float left; // [esp+7Ch] [ebp-4h] BYREF

  v4 = *(float *)&this;
  left = *(float *)&this;
  if ( (dword_186F218 & 1) == 0 )
  {
    perfCounter_40.name = "AIDriver::acquireControls";
    dword_186F218 |= 1u;
    perfCounter_40.group = Physics;
    perfCounter_40.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"AIDriver::acquireControls" | 0xFF000000;
  }
  this->car->stabilityControl.useBeta = 1;
  v5 = this->car;
  if ( v5->ksPhysics->physicsTime - v5->lastCollisionTime <= 1000.0 )
    v5->stabilityControl.gain = 0.0;
  else
    v5->stabilityControl.gain = 2.0;
  AIDriver::stepPushVariations((AIDriver *)LODWORD(v4), dt);
  AIDriver::stepSetup((AIDriver *)LODWORD(v4), dt);
  v6 = *(_DWORD *)(LODWORD(v4) + 416);
  if ( *(_DWORD *)(LODWORD(v4) + 704) == 3 )
  {
    v7 = *(_DWORD *)(LODWORD(v4) + 728) - *(_DWORD *)(v6 + 340) - 1;
    if ( !*(_BYTE *)(LODWORD(v4) + 116) && *(float *)(v6 + 11008) > 0.5 && v7 > 1 )
    {
      if ( *(int *)(LODWORD(v4) + 612) <= 1 )
      {
        *(_QWORD *)&ihed.y = *(_QWORD *)(v6 + 11664);
        v8 = FuelLapEvaluator::getFuelLaps((FuelLapEvaluator *)(v6 + 11048));
        _printf_s(
          "STINT IS OVER FOR CAR: %u REQUESTING PIT STOP, FUEL:%.1f FUELLAPS: %.1f\n",
          *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 9492),
          *(double *)&ihed.y,
          (double)v8);
LABEL_21:
        *(_BYTE *)(LODWORD(v4) + 116) = 1;
        goto LABEL_22;
      }
      right = FuelLapEvaluator::getFuelLaps((FuelLapEvaluator *)(v6 + 11048));
      if ( right >= 0.0 && right < 2.0 )
      {
        _printf_s(
          "OUT OF FUEL! CAR: %u REQUESTING PIT STOP, FUEL:%.1f FUELLAPS: %.2f, RACE LAPS:%d LAPS:%d, LTG:%d\n",
          *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 9492),
          *(double *)(*(_DWORD *)(LODWORD(v4) + 416) + 11664),
          right,
          *(_DWORD *)(LODWORD(v4) + 728),
          *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 340),
          v7);
        goto LABEL_21;
      }
    }
  }
  else
  {
    v9 = FuelLapEvaluator::getFuelLaps((FuelLapEvaluator *)(v6 + 11048));
    v10 = *(_BYTE *)(LODWORD(v4) + 116) == 0;
    right = v9;
    if ( v10 && (*(int *)(LODWORD(v4) + 612) <= 1 || right >= 0.0 && right < 2.0) )
    {
      v11 = *(_DWORD *)(LODWORD(v4) + 416);
      if ( *(float *)(v11 + 11008) > 0.5 )
      {
        _printf(
          "Car %d: requesting stop for end of fuel. fpl: %f laps to complete: %d\n",
          *(_DWORD *)(v11 + 9492),
          right,
          *(_DWORD *)(LODWORD(v4) + 612));
        goto LABEL_21;
      }
    }
  }
LABEL_22:
  v12 = *(_DWORD *)(LODWORD(v4) + 416);
  if ( *(double *)(v12 + 11664) < 1.0 )
  {
    *(double *)(v12 + 11664) = DOUBLE_1_0;
    *(_BYTE *)(LODWORD(v4) + 116) = 1;
  }
  v13 = *(AISplineRecorder **)(LODWORD(v4) + 496);
  normalizedPos = *(float *)(LODWORD(v4) + 736);
  *(_BYTE *)(LODWORD(v4) + 420) = *(double *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 168) + 16)
                                - *(double *)(*(_DWORD *)(LODWORD(v4) + 416) + 11296) < 1000.0;
  v14 = AISplineRecorder::getBrakeHintAtSplinePos(v13, normalizedPos);
  v15 = *(float *)(LODWORD(v4) + 100);
  right = v14;
  *(float *)(LODWORD(v4) + 104) = v15 * right;
  AIDriver::stepHumanizer((AIDriver *)LODWORD(v4), dt);
  AIDriver::stepSplineSelection((AIDriver *)LODWORD(v4), dt);
  AIDriver::stepPitLaneMode((AIDriver *)LODWORD(v4), dt);
  v16 = *(Car **)(LODWORD(v4) + 416);
  *(double *)(LODWORD(v4) + 344) = (float)(dt * 0.2) + *(double *)(LODWORD(v4) + 344);
  right = *(float *)(LODWORD(v4) + 540) + *(float *)(LODWORD(v4) + 536);
  v17 = Car::getSpeed(v16, &result);
  LODWORD(v19) = __libm_sse2_sinf(v18).m128_u32[0];
  v20 = FLOAT_1_0;
  v21 = (float)(v17->value * 0.2) - 1.0;
  if ( v21 > 1.0 || (v20 = 0.0, v21 < 0.0) )
    v21 = v20;
  *(float *)(LODWORD(v4) + 360) = (float)(v21 * v19) * (float)(right * 0.1);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( *(_DWORD *)(LODWORD(v4) + 672) != *(_DWORD *)(LODWORD(v4) + 676) )
  {
    v22 = *(Car **)(LODWORD(v4) + 416);
    right = *(float *)(LODWORD(v4) + 736);
    ihed.z = Car::getSpeed(v22, &result)->value;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    v23 = left;
    v24 = *(const __m128i **)(LODWORD(v4) + 676);
    v25 = *(const __m128i **)(LODWORD(left) + 672);
    if ( v25 != v24 )
    {
      v26 = FLOAT_3_5999999;
      do
      {
        v27 = _mm_loadu_si128(v25);
        if ( *(float *)v27.m128i_i32 > *(float *)(LODWORD(v23) + 688) && right >= *(float *)v27.m128i_i32 )
        {
          _printf(
            "PROFILER AT: %.2f SPEED:%.1f vs %.1f DIFF:%.1f AX:%.1f -> %.1f AZ:%.1f -> %.1f\n",
            right,
            (float)(ihed.z * v26),
            (float)(*(float *)&v27.m128i_i32[1] * v26),
            (float)((float)(ihed.z - *(float *)&v27.m128i_i32[1]) * v26),
            *(float *)(*(_DWORD *)(LODWORD(v23) + 416) + 316),
            *(float *)&v27.m128i_i32[2],
            *(float *)(*(_DWORD *)(LODWORD(v23) + 416) + 324),
            (float)(*(float *)&v27.m128i_i32[3] * 0.10197838));
          v26 = FLOAT_3_5999999;
          v23 = left;
        }
        ++v25;
      }
      while ( v25 != v24 );
    }
    v4 = left;
    *(float *)(LODWORD(left) + 688) = right;
  }
  v28 = controls;
  v29 = *(const __m128i **)(*(_DWORD *)(LODWORD(v4) + 416) + 168);
  v53 = _mm_loadu_si128(v29 + 17).m128i_u32[0];
  v30 = _mm_loadu_si128(v29 + 18);
  v31 = *(_DWORD *)(LODWORD(v4) + 412);
  if ( v31 < 4 )
  {
    *(_DWORD *)(LODWORD(v4) + 412) = v31 + 1;
  }
  else
  {
    v10 = *(_BYTE *)(LODWORD(v4) + 760) == 0;
    *(float *)&controls = dt * 5.0;
    if ( v10 && COERCE_FLOAT(*(_DWORD *)(LODWORD(v4) + 520) & _xmm) <= 0.1
      || !AISplineRecorder::getDangerAtSplinePos(
            *(AISplineRecorder **)(LODWORD(v4) + 496),
            *(float *)(LODWORD(v4) + 736),
            &left,
            &right) )
    {
      *(_DWORD *)(LODWORD(v4) + 452) = 1065353216;
    }
    else
    {
      v32 = &right;
      if ( right <= left )
        v32 = &left;
      *(float *)(LODWORD(v4) + 452) = 1.0 - (float)(*v32 * 0.2);
    }
    if ( (dword_186F218 & 2) == 0 )
    {
      perfCounter_41.name = "AIDriver::acquireControls (step)";
      dword_186F218 |= 2u;
      perfCounter_41.group = Physics;
      perfCounter_41.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"AIDriver::acquireControls (step)" | 0xFF000000;
    }
    *(float *)(LODWORD(v4) + 176) = AIDriver::getDistanceToNextCorner((AIDriver *)LODWORD(v4), 25.0);
    AIDriver::updateCurrentSplinePos((AIDriver *)LODWORD(v4));
    AIDriver::stepCarsAwareness2((AIDriver *)LODWORD(v4), *(float *)&controls);
    AIDriver::stepSteer((AIDriver *)LODWORD(v4), *(float *)&controls);
    AIDriver::stepGears((AIDriver *)LODWORD(v4), dt, v28);
    AIDriver::stepGasBrake((AIDriver *)LODWORD(v4), *(float *)&controls);
    AIDriver::stepTurbo((AIDriver *)LODWORD(v4), *(float *)&controls);
    if ( *(_BYTE *)(*(_DWORD *)(LODWORD(v4) + 416) + 10248) )
      AIDriver::stepDRS((AIDriver *)LODWORD(v4), v28, *(float *)&controls);
    v33 = *(_DWORD *)(LODWORD(v4) + 416);
    if ( *(_BYTE *)(v33 + 10288) )
    {
      v34 = 0;
      if ( *(float *)(LODWORD(v4) + 176) > 100.0 )
      {
        v34 = 0;
        v35 = *(_DWORD *)(v33 + 1564) < (unsigned int)(((*(_DWORD *)(v33 + 660) - *(_DWORD *)(v33 + 656)) >> 5) - 2);
        controls = (CarControls *)1;
        if ( v35 )
          v34 = (char)controls;
      }
      v28->kers = v34;
    }
    else
    {
      v28->kers = 0;
    }
    *(double *)(LODWORD(v4) + 392) = Car::getSpeed(*(Car **)(LODWORD(v4) + 416), (Speed *)&controls)->value * 0.001
                                   + *(double *)(LODWORD(v4) + 392) * 0.999;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&controls);
    if ( *(double *)(LODWORD(v4) + 392) < 8.0 )
    {
      v36 = *(Car **)(LODWORD(v4) + 416);
      if ( !v36->isRetired
        && !Car::isInPits(v36)
        && (v53 != 3 || *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 340) < v30.m128i_i32[2]) )
      {
        _printf(
          "CAR %u RETIRED Session %d : LC:%u\\%d\n",
          *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 9492),
          v53,
          *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 340),
          v30.m128i_i32[2]);
        *(_BYTE *)(*(_DWORD *)(LODWORD(v4) + 416) + 132) = 1;
      }
    }
    v37 = *(_DWORD *)(LODWORD(v4) + 416);
    if ( *(_BYTE *)(v37 + 132) )
    {
      LODWORD(v38) = *(_DWORD *)(v37 + 10984) ^ _xmm;
      LODWORD(v39) = *(_DWORD *)(v37 + 10976) ^ _xmm;
      LODWORD(ihed.y) = *(_DWORD *)(v37 + 10980) ^ _xmm;
      ihed.x = v39;
      ihed.z = v38;
      Car::forceRotation((Car *)v37, &ihed);
      v40 = *(Car **)(LODWORD(v4) + 416);
      v41 = v40->pitPosition.M42;
      v42 = v40->pitPosition.M43;
      ihed.x = v40->pitPosition.M41;
      ihed.y = v41;
      ihed.z = v42;
      Car::forcePosition(v40, &ihed, 1);
      v43 = *(AISplineRecorder **)(LODWORD(v4) + 496);
      *(_DWORD *)(LODWORD(v4) + 508) = 1065353216;
      *(_DWORD *)(LODWORD(v4) + 504) = 0;
      *(_DWORD *)(LODWORD(v4) + 512) = 0;
      *(_DWORD *)(LODWORD(v4) + 500) = AISplineRecorder::getPitLaneSpline(v43);
    }
    v44 = *(_DWORD *)(LODWORD(v4) + 416);
    if ( _mm_cvtsi128_si32(_mm_loadu_si128((const __m128i *)(*(_DWORD *)(v44 + 168) + 272))) == 3
      && *(_BYTE *)(v44 + 988) )
    {
      AIDriver::stepP2P((AIDriver *)LODWORD(v4), dt);
    }
    *(_DWORD *)(LODWORD(v4) + 412) = 0;
  }
  v45 = *(double *)(LODWORD(v4) + 200);
  if ( v45 > 0.0 )
    *(double *)(LODWORD(v4) + 200) = v45 - dt;
  if ( !*(_DWORD *)(LODWORD(v4) + 384) )
    *(_DWORD *)(LODWORD(v4) + 384) = (unsigned int)*(double *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 168) + 16);
  if ( !AISpline::pointsCount(*(AISpline **)(LODWORD(v4) + 500)) )
  {
    *(_DWORD *)(LODWORD(v4) + 512) = 0;
    *(_DWORD *)(LODWORD(v4) + 504) = 0;
    *(_DWORD *)(LODWORD(v4) + 508) = 0;
    *(_WORD *)&v28->gearUp = 0;
  }
  v46 = *(float *)(LODWORD(v4) + 512);
  v47 = FLOAT_1_0;
  if ( v46 <= 1.0 )
  {
    v48 = FLOAT_N1_0;
    if ( v46 >= -1.0 )
      v48 = *(float *)(LODWORD(v4) + 512);
  }
  else
  {
    v48 = FLOAT_1_0;
  }
  v28->steer = v48;
  v49 = *(float *)(LODWORD(v4) + 504);
  if ( v49 <= 1.0 )
  {
    if ( v49 < 0.0 )
      v49 = 0.0;
  }
  else
  {
    v49 = FLOAT_1_0;
  }
  v28->gas = v49;
  v50 = *(float *)(LODWORD(v4) + 508);
  if ( v50 <= 1.0 )
  {
    if ( v50 >= 0.0 )
      v47 = *(float *)(LODWORD(v4) + 508);
    else
      v47 = 0.0;
  }
  v28->brake = v47;
  normalizedPosa = dt;
  v28->clutch = 1.0;
  AIDriver::stepSuperhuman((AIDriver *)LODWORD(v4), v28, normalizedPosa);
  *(_BYTE *)(*(_DWORD *)(LODWORD(v4) + 416) + 11360) = *(_BYTE *)(LODWORD(v4) + 116);
  *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 416) + 11364) = *(_DWORD *)(LODWORD(v4) + 612);
}
void AIDriver::calcMinForwardSides(AIDriver *this, float forwardDistance)
{
  double v3; // st7
  float *v4; // edi
  float *v5; // ebx
  float *v6; // eax
  float *v7; // eax
  float pos; // [esp+18h] [ebp-14h]
  float v9; // [esp+1Ch] [ebp-10h]
  float step_dist; // [esp+20h] [ebp-Ch]
  float sides[2]; // [esp+24h] [ebp-8h] BYREF

  pos = this->locNpos;
  v9 = 0.0;
  v3 = Spline::length(&this->currentSpline->spline);
  v4 = this->minForwardSides;
  v5 = &this->minForwardSides[1];
  this->minForwardSides[0] = 10000.0;
  for ( this->minForwardSides[1] = 10000.0; forwardDistance > v9; v9 = v9 + 10.0 )
  {
    AISpline::getSidesAtPos(this->currentSpline, pos, sides, 1u);
    v6 = sides;
    if ( *v4 <= sides[0] )
      v6 = this->minForwardSides;
    *v4 = *v6;
    v7 = &sides[1];
    if ( *v5 <= sides[1] )
      v7 = &this->minForwardSides[1];
    step_dist = 10.0 / v3;
    pos = step_dist + pos;
    *v5 = *v7;
  }
}
int AIDriver::findTyreForQualify(AIDriver *this)
{
  AISpline *v2; // eax
  double v3; // st7
  Car *v4; // eax
  Car *v5; // edi
  int v6; // esi
  int v7; // eax
  const TyreCompoundDef *v8; // edi
  std::map<std::wstring,TyreCompoundStrategy> *v9; // ebx
  std::wstring *v10; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v11; // esi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v12; // ebx
  const wchar_t *v13; // eax
  const wchar_t *v14; // eax
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v15; // eax
  int v16; // eax
  int v17; // eax
  std::tuple<> v18; // [esp+1Fh] [ebp-21h] BYREF
  int v19; // [esp+20h] [ebp-20h]
  float lap_length; // [esp+24h] [ebp-1Ch]
  AIDriver *v21; // [esp+28h] [ebp-18h]
  TyreCompoundStrategy ts; // [esp+2Ch] [ebp-14h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+30h] [ebp-10h] BYREF
  float v24; // [esp+34h] [ebp-Ch]
  float dy; // [esp+38h] [ebp-8h]
  const TyreCompoundDef *v26; // [esp+3Ch] [ebp-4h]

  v21 = this;
  v2 = AISplineRecorder::getBestLapSpline(this->car->ksPhysics->track->aiSplineRecorder._Myptr);
  v3 = Spline::length(&v2->spline);
  v4 = this->car;
  lap_length = v3;
  v24 = lap_length * 2.5;
  _printf(
    "AI CAR:%u looking for qualify tyre, lap length: %.1f REQUEST:%.1f\n",
    v4->physicsGUID,
    lap_length,
    (float)(lap_length * 2.5));
  v5 = this->car;
  v6 = -1;
  v19 = -1;
  lap_length = 0.0;
  v7 = (int)v5->tyres[0].compoundDefs._Mylast;
  v8 = v5->tyres[0].compoundDefs._Myfirst;
  v26 = (const TyreCompoundDef *)v7;
  if ( v8 == (const TyreCompoundDef *)v7 )
    goto LABEL_25;
  v9 = &this->tyreStrategies;
  v10 = &v8->shortName;
  do
  {
    v11 = v9->_Myhead;
    v12 = v9->_Myhead->_Parent;
    while ( !v12->_Isnil )
    {
      if ( v10->_Myres < 8 )
        v13 = (const wchar_t *)v10;
      else
        v13 = v10->_Bx._Ptr;
      if ( std::wstring::compare((std::wstring *)&v12->_Myval.first, 0, v12->_Myval.first._Mysize, v13, v10->_Mysize) >= 0 )
      {
        v11 = v12;
        v12 = v12->_Left;
      }
      else
      {
        v12 = v12->_Right;
      }
    }
    v9 = &v21->tyreStrategies;
    if ( v11 == v21->tyreStrategies._Myhead )
      goto LABEL_15;
    v14 = v11->_Myval.first._Bx._Buf;
    if ( v11->_Myval.first._Myres >= 8 )
      v14 = *(const wchar_t **)v14;
    if ( std::wstring::compare(v10, 0, v10->_Mysize, v14, v11->_Myval.first._Mysize) < 0 )
    {
LABEL_15:
      *(std::wstring **)&ts.maxKm = v10;
      v15 = (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)std::_Tree_buy<std::pair<std::wstring const,TyreCompoundStrategy>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::wstring const &>,std::tuple<>>(
                                                                                             v9,
                                                                                             &piecewise_construct_88,
                                                                                             (std::tuple<std::wstring const &> *)&ts,
                                                                                             &v18);
      std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,enum DynamicControllerInput>>,0>>::_Insert_hint<std::pair<std::wstring const,enum DynamicControllerInput> &,std::_Tree_node<std::pair<std::wstring const,enum DynamicControllerInput>,void *> *>(
        v9,
        &result,
        (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v11,
        &v15->_Myval,
        v15);
      v11 = result._Ptr;
    }
    LODWORD(ts.maxKm) = v11->_Myval.second;
    dy = RaceEngineer::getCompoundDY(v8, 3000.0);
    if ( ts.maxKm <= v24 || dy <= lap_length )
    {
      v6 = v19;
    }
    else
    {
      v6 = v8->index;
      v19 = v8->index;
      lap_length = dy;
    }
    ++v8;
    v10 = (std::wstring *)((char *)v10 + 712);
  }
  while ( v8 != v26 );
  if ( v6 == -1 )
  {
LABEL_25:
    _printf("No tyre found, return -1 and get default\n");
    v17 = v6;
  }
  else
  {
    v16 = (int)&v21->car->tyres[0].compoundDefs._Myfirst[v6].shortName;
    if ( *(_DWORD *)(v16 + 20) >= 8u )
      v16 = *(_DWORD *)v16;
    _printf("And the winner is %d : %S\n", v6, (const wchar_t *)v16);
    v17 = v6;
  }
  return v17;
}
void AIDriver::generatePitStopStrategy(AIDriver *this, int laps)
{
  Car *v3; // ecx
  const wchar_t *v4; // eax
  double v6; // xmm0_8
  int v7; // esi
  double v8; // [esp+18h] [ebp-8h]
  float fuel_per_lap; // [esp+24h] [ebp+4h]

  v3 = this->car;
  v4 = v3->unixName._Bx._Buf;
  if ( v3->unixName._Myres >= 8 )
    v4 = *(const wchar_t **)v4;
  _printf("Race strategy for car %d [%S], race laps:%d\n", v3->physicsGUID, v4, laps);
  fuel_per_lap = Car::getFuelPerLap(this->car);
  v8 = this->car->maxFuel / fuel_per_lap;
  _printf("Max laps with max fuel:%f\n", v8);
  v6 = (double)laps;
  if ( (double)laps <= v8 )
  {
    Car::setFuelForLaps(this->car, laps + 1, 1.2);
    this->lapsToComplete = 10000;
  }
  else
  {
    _printf("Divide race in %d stints\n", (int)(v6 / v8) + 1);
    if ( (int)(v6 / v8) + 1 <= 2 )
    {
      v7 = (int)(float)((float)((float)((float)_rand() * 0.000030518509)
                              * (float)((float)((float)laps * 0.33333334) + 0.5))
                      + (float)(laps / 3));
      _printf("Fill for stint of %d laps (base %d)\n", v7, laps / 3);
      Car::setFuelForLaps(this->car, v7 + 1, 1.2);
      this->lapsToComplete = v7;
    }
    else
    {
      Car::setRequestedFuel(this->car, this->car->maxFuel, 1);
      this->lapsToComplete = 10000;
    }
  }
}
void AIDriver::generatePitlaneWait(AIDriver *this)
{
  Car *v2; // ecx
  int v3; // edi
  int v4; // ebp
  double v5; // xmm0_8
  long double v6; // xmm0_8
  AISplineRecorder *v7; // ecx
  AISpline *v8; // eax
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  Car *v13; // ecx
  float fuel_to_add; // [esp+0h] [ebp-38h]
  double v15; // [esp+8h] [ebp-30h]
  PitStopTime result; // [esp+28h] [ebp-10h] BYREF

  if ( this->currentSessionInfo.type == Race )
  {
    _printf("AI RACE PITSTOP, car %d\n", this->car->physicsGUID);
    _printf("Race laps:%d, completed:%d\n", this->currentSessionInfo.laps, this->car->transponder.lapCount);
    v2 = this->car;
    v3 = this->currentSessionInfo.laps - v2->transponder.lapCount + 1;
    *(long double *)&result.total = v2->fuel;
    v4 = Car::setFuelForLaps(v2, v3, 1.2);
    if ( v4 != v3 )
    {
      _printf("Heads up, too much fuel requested!");
      v3 = v4;
    }
    v15 = this->car->fuel;
    *(double *)&result.total = v15 - *(double *)&result.total;
    _printf("Putting fuel for %d laps, filled to %f L, added %f L\n", v3, v15, *(double *)&result.total);
    v5 = *(double *)&result.total;
    this->runLapCounter = 0;
    fuel_to_add = v5;
    v6 = Car::getPitstopTime(this->car, &result, fuel_to_add, 1, 1, 0, 1, 1)->total;
    this->timeToStart = v6;
    _printf("Pitstop TIME: %f\n", (double)v6);
    v7 = this->aiSplineRecorder;
    this->splineSelection = Pits;
    v8 = AISplineRecorder::getPitLaneSpline(v7);
    this->lapsToComplete = v3;
    this->currentSpline = v8;
  }
  else
  {
    v9 = _rand();
    v10 = !this->turbo.active;
    this->runLapCounter = 0;
    this->timeToStart = (float)((float)((float)v9 * 0.000030518509) * 120.0);
    if ( v10 || (v11 = this->turbo.qualifyHotLaps, v11 <= 0) )
      v12 = (int)(float)((float)((float)((float)_rand() * 0.000030518509) * 5.0) + 3.0);
    else
      v12 = v11 + 2;
    v13 = this->car;
    this->lapsToComplete = v12;
    if ( !v13->physicsGUID )
    {
      this->timeToStart = DOUBLE_5_0;
      this->lapsToComplete = 10;
    }
    Car::setFuelForLaps(v13, this->lapsToComplete + 3, 1.1);
  }
}
double AIDriver::getBrakeTargetSpeed(AIDriver *this)
{
  return this->brakePoint.targetSpeed;
}
double AIDriver::getClosestFollowingCarTTI(AIDriver *this)
{
  int v2; // edi
  PhysicsEngine *v3; // eax
  Car **v4; // esi
  Car **v5; // eax
  unsigned int v6; // ebx
  Car *v7; // ecx
  Car *v8; // eax
  float v9; // xmm1_4
  Speed *v10; // eax
  float v11; // xmm0_4
  float *v12; // eax
  float tti; // [esp+4h] [ebp-10h] BYREF
  float v15; // [esp+8h] [ebp-Ch]
  float v16; // [esp+Ch] [ebp-8h] BYREF
  Speed result; // [esp+10h] [ebp-4h] BYREF

  v15 = FLOAT_100000_0;
  tti = FLOAT_100000_0;
  v2 = 0;
  v3 = this->car->ksPhysics;
  v4 = v3->cars._Myfirst;
  v5 = v3->cars._Mylast;
  v6 = (unsigned int)((char *)v5 - (char *)v4 + 3) >> 2;
  if ( v4 > v5 )
    v6 = 0;
  if ( v6 )
  {
    do
    {
      v7 = *v4;
      v8 = this->car;
      if ( *v4 != v8 )
      {
        v9 = v8->splineLocatorData.npos - v7->splineLocatorData.npos;
        if ( v9 < 0.0 )
          v9 = v9 + 1.0;
        v16 = v8->splineLocatorData.splineLength * v9;
        v10 = Car::getSpeed(v7, &result);
        v11 = v16 / v10->value;
        v12 = &v16;
        v16 = v11;
        if ( v15 <= v11 )
          v12 = &tti;
        v15 = *v12;
        tti = v15;
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      }
      ++v2;
      ++v4;
    }
    while ( v2 != v6 );
  }
  return tti;
}
double AIDriver::getDistanceToApex(AIDriver *this, float offset, float resolution)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float dist; // [esp+10h] [ebp-14h]
  float pos; // [esp+14h] [ebp-10h]
  float sstep; // [esp+18h] [ebp-Ch]
  float sides[2]; // [esp+1Ch] [ebp-8h] BYREF

  dist = 0.0;
  pos = this->locNpos;
  v4 = pos;
  sstep = resolution / Spline::length(&this->currentSpline->spline);
  while ( 1 )
  {
    AISpline::getSidesAtPos(this->currentSpline, v4, sides, 1u);
    v5 = this->car->carHalfWidth;
    if ( v5 > (float)(sides[0] + offset) || v5 > (float)(sides[1] - offset) )
      break;
    dist = dist + resolution;
    pos = InterpolatingSpline::wrapPosition(&this->currentSpline->spline, sstep + pos);
    if ( dist >= 500.0 )
      return 1000.0;
    v4 = pos;
  }
  return dist;
}
double AIDriver::getDistanceToNextCorner(AIDriver *this, float resolution)
{
  double v3; // st7
  Car *v4; // ecx
  AISplineRecorder *v5; // ecx
  double v6; // st7
  AISpline *v7; // ecx
  double v8; // st7
  float v9; // xmm0_4
  float normalizedPos; // [esp+14h] [ebp-14h]
  float dist; // [esp+18h] [ebp-10h]
  Speed result; // [esp+1Ch] [ebp-Ch] BYREF
  float radius; // [esp+20h] [ebp-8h]
  float sstep; // [esp+24h] [ebp-4h]

  dist = 0.0;
  normalizedPos = this->locNpos;
  v3 = Spline::length(&this->currentSpline->spline);
  v4 = this->car;
  sstep = resolution / v3;
  Car::getSpeed(v4, &result);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  while ( 1 )
  {
    v5 = this->aiSplineRecorder;
    result.value = this->car->carHalfWidth;
    v6 = AISplineRecorder::getHintAtSplinePos(v5, normalizedPos);
    v7 = this->currentSpline;
    radius = v6;
    v8 = AISpline::getCornerRadiusAt(v7, normalizedPos, 15.0, 0.0, result.value);
    v9 = this->STRAIGHT_RADIUS;
    radius = v8 * radius;
    if ( v9 >= radius )
      break;
    dist = dist + resolution;
    radius = InterpolatingSpline::wrapPosition(&this->currentSpline->spline, sstep + normalizedPos);
    if ( dist >= 500.0 )
      return 500.0;
    normalizedPos = radius;
  }
  return dist;
}
double AIDriver::getEngagedDesiredOffset(AIDriver *this, float left, float right, float lateral, float *tti, float sideL, float sideR, float eng_speedL, float eng_speedR)
{
  float *v9; // eax
  float v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v15; // xmm4_4
  float *v16; // eax
  float v17; // xmm0_4
  Car *v18; // eax
  float v19; // xmm4_4
  float *v20; // eax
  float v21; // xmm0_4
  Car *v22; // eax
  float *v23; // eax
  float *v24; // eax

  v9 = &eng_speedR;
  if ( eng_speedR <= eng_speedL )
    v9 = &eng_speedL;
  v10 = *v9;
  v11 = &eng_speedR;
  eng_speedL = 0.0;
  eng_speedR = v10;
  if ( v10 <= 0.0 )
    v11 = &eng_speedL;
  v12 = (float)((float)(*v11 * 0.029999999) + 1.0) * (float)(this->car->carHalfWidth * 3.0);
  if ( right <= 0.0 && left <= 0.0 )
    return 0.0;
  v13 = lateral;
  if ( left > 0.0 )
  {
    if ( right > 0.0 )
      return (float)((float)((float)((float)(left + right) * 0.5) - left) + lateral);
    v15 = (float)(v12 * 1.5) - sideL;
    eng_speedR = v15;
    if ( v12 > left )
    {
      *tti = 0.5;
      v16 = &lateral;
      lateral = (float)(v12 - left) + lateral;
      if ( lateral <= v15 )
        v16 = &eng_speedR;
      v17 = *v16;
      v18 = this->car;
      lateral = v17;
      if ( !v18->physicsGUID )
        _printf("ENGAGE LEFT returning: %f\n", v17);
      return lateral;
    }
    if ( v15 > lateral )
      return eng_speedR;
  }
  if ( right <= 0.0 )
  {
LABEL_25:
    *tti = 3.0;
    if ( v13 <= 0.0 )
    {
      if ( left > 0.0 )
      {
        v24 = (float *)&tti;
        tti = (float *)(LODWORD(v13) ^ _xmm);
        eng_speedR = left - v12;
        if ( (float)(left - v12) <= COERCE_FLOAT(LODWORD(v13) ^ _xmm) )
          v24 = &eng_speedR;
        return *v24 + lateral;
      }
    }
    else if ( right > 0.0 )
    {
      v23 = &lateral;
      *(float *)&tti = right - v12;
      if ( (float)(right - v12) <= v13 )
        v23 = (float *)&tti;
      return lateral - *v23;
    }
    return 0.0;
  }
  LODWORD(v19) = COERCE_UNSIGNED_INT((float)(v12 * 1.5) - sideR) ^ _xmm;
  eng_speedR = v19;
  if ( v12 <= right )
  {
    if ( lateral > v19 )
      return eng_speedR;
    goto LABEL_25;
  }
  *tti = 0.5;
  v20 = &lateral;
  lateral = v13 - (float)(v12 - right);
  if ( v19 <= lateral )
    v20 = &eng_speedR;
  v21 = *v20;
  v22 = this->car;
  lateral = v21;
  if ( v22->physicsGUID )
    return lateral;
  _printf("ENGAGE RIGHT returning: %f\n", v21);
  return lateral;
}
double AIDriver::getLABraking(AIDriver *this)
{
  double v2; // st7
  Car *v3; // ecx
  double v4; // st7
  AISpline *v5; // ecx
  double v6; // st7
  AISplineRecorder *v7; // ecx
  double v8; // st7
  AISpline *v9; // ecx
  double v10; // st7
  bool v11; // zf
  float speed; // xmm1_4
  float v13; // xmm0_4
  double v14; // st7
  float *v15; // eax
  float *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm1_4
  bool v19; // cc
  double v20; // st7
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  double v24; // st7
  double v25; // st7
  float *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm1_4
  float *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm3_4
  float v34; // eax
  AIBrakeObstacle *v35; // edx
  AIBrakeObstacle *v36; // ecx
  float v37; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  double v40; // st7
  Car *v41; // ecx
  double v42; // st7
  float *v43; // eax
  double v44; // st7
  float *v45; // eax
  double v46; // st7
  float v47; // xmm0_4
  float v48; // xmm0_4
  double v49; // st7
  float *v50; // eax
  AISpline *v51; // ecx
  double v52; // st7
  AISpline *v53; // ecx
  double v54; // st7
  Speed *v55; // eax
  char v56; // cl
  char v57; // bl
  double v58; // st7
  float normalizedPos; // [esp+10h] [ebp-60h]
  float speedMS; // [esp+20h] [ebp-50h]
  float availBrake; // [esp+24h] [ebp-4Ch] BYREF
  float v62; // [esp+28h] [ebp-48h]
  float radius; // [esp+2Ch] [ebp-44h] BYREF
  float mass; // [esp+30h] [ebp-40h]
  float reqspeed2; // [esp+34h] [ebp-3Ch] BYREF
  float latg; // [esp+38h] [ebp-38h] BYREF
  float lpush; // [esp+3Ch] [ebp-34h]
  float v68; // [esp+40h] [ebp-30h]
  float v69; // [esp+44h] [ebp-2Ch]
  float reqLatG; // [esp+48h] [ebp-28h] BYREF
  float brake_stopping_power; // [esp+4Ch] [ebp-24h] BYREF
  float latg2; // [esp+50h] [ebp-20h] BYREF
  float sl; // [esp+54h] [ebp-1Ch]
  float brake_power_gain; // [esp+58h] [ebp-18h]
  Speed result; // [esp+5Ch] [ebp-14h] BYREF
  AISplineSlimPayload pl; // [esp+60h] [ebp-10h] BYREF

  LODWORD(result.value) = 0;
  if ( (_S33 & 1) == 0 )
  {
    perfCounter_43.name = "AIDriver::getLABraking";
    _S33 |= 1u;
    perfCounter_43.group = Physics;
    perfCounter_43.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"AIDriver::getLABraking" | 0xFF000000;
  }
  v2 = Car::getTotalMass(this->car, 1);
  v3 = this->car;
  mass = v2;
  speedMS = Car::getSpeed(v3, (Speed *)&brake_stopping_power)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&brake_stopping_power);
  pl.isPitlane = 0;
  v62 = 0.0;
  availBrake = this->locNpos;
  pl.camber = this->currentPayload.camber;
  pl.grade = this->currentPayload.grade;
  pl.grip = this->currentPayload.grip;
  v4 = AIDriver::getLateralPush(this);
  v5 = this->currentSpline;
  brake_power_gain = v4;
  sl = 4.0 / Spline::length(&v5->spline);
  v68 = 1.0 / mass;
  v6 = RaceEngineer::getMaxBrakingForce(&this->engineer);
  reqLatG = this->currentOffset;
  v7 = this->aiSplineRecorder;
  brake_stopping_power = v6 * (float)(1.0 / mass);
  v8 = AISplineRecorder::getHintAtSplinePos(v7, availBrake);
  v9 = this->currentSpline;
  v69 = v8;
  v10 = AISpline::getCornerRadiusAt(v9, availBrake, 15.0, reqLatG, 0.0);
  v11 = !this->brakePoint.wasObstacle;
  radius = v10 * v69;
  if ( !v11 || this->currentOffset != this->brakePoint.lateralOffset || this->brakePoint.targetSpeed <= 0.0 )
    this->brakePoint.targetSpeed = -1.0;
  v69 = speedMS;
  speed = speedMS;
  lpush = AIDriver::getLateralPush(this);
  if ( speedMS <= 0.0 )
  {
LABEL_51:
    this->brakePoint.targetSpeed = -1.0;
    goto LABEL_52;
  }
  while ( 1 )
  {
    v13 = v62;
    if ( v62 >= 300.0 )
      break;
    v14 = RaceEngineer::evalLateralGrip(&this->engineer, speed, mass, this->aeroHint, 0, -1.0);
    latg = v14 * pl.grip * this->tyresHint;
    reqspeed2 = ksSpeedFromRadius(radius, latg);
    if ( pl.isPitlane )
    {
      latg2 = 22.222223;
      v20 = AIDriver::getLateralPush(this);
      v15 = &latg2;
      v16 = &reqLatG;
      reqLatG = v20;
      v18 = reqspeed2 - (float)((float)(1.0 - reqLatG) * 22.222223);
      v19 = v18 <= 22.222223;
    }
    else
    {
      v15 = &reqLatG;
      v16 = &reqspeed2;
      v17 = reqspeed2;
      reqspeed2 = reqspeed2 * 0.5;
      v18 = v17 - (float)((float)(1.0 - lpush) * 22.222223);
      v19 = v18 <= reqspeed2;
    }
    v21 = speedMS;
    if ( v19 )
      v15 = v16;
    v22 = FLOAT_N1_0;
    reqLatG = v18;
    reqLatG = *v15;
    if ( speedMS > reqLatG )
    {
      v23 = this->brakePoint.targetSpeed;
      if ( v23 == -1.0 || v23 >= reqLatG )
      {
        v24 = RaceEngineer::evalLateralGrip(&this->engineer, v69, mass, this->aeroHint, 0, -1.0);
        latg2 = v24 * pl.grip * this->tyresHint;
        v25 = ksSpeedFromRadius(radius, latg2);
        v26 = &latg2;
        reqspeed2 = v25;
        v27 = reqspeed2;
        reqspeed2 = reqspeed2 * 0.5;
        latg2 = v27 - (float)((float)(1.0 - lpush) * 22.222223);
        if ( latg2 <= reqspeed2 )
          v26 = &reqspeed2;
        v28 = *v26;
        reqspeed2 = *v26;
        if ( pl.isPitlane )
        {
          v29 = &latg2;
          latg2 = 22.222223;
          if ( v28 <= 22.222223 )
            v29 = &reqspeed2;
          v28 = *v29;
        }
        v30 = v69;
        v21 = speedMS;
        if ( v69 > v28 )
        {
          v31 = reqLatG;
          if ( reqLatG <= v28 )
          {
            this->brakePoint.targetSpeed = v28;
            v32 = v30 - v28;
          }
          else
          {
            this->brakePoint.targetSpeed = reqLatG;
            v32 = speedMS - v31;
          }
          v33 = availBrake;
          v34 = this->currentOffset;
          v22 = FLOAT_N1_0;
          this->brakePoint.speedDiff = v32;
          this->brakePoint.targetNormalized = v33;
          this->brakePoint.wasObstacle = 0;
          this->brakePoint.lateralOffset = v34;
          goto LABEL_30;
        }
        v22 = FLOAT_N1_0;
      }
    }
    v33 = availBrake;
LABEL_30:
    v35 = this->brakeObstacles._Mylast;
    v36 = this->brakeObstacles._Myfirst;
    if ( v36 != v35 )
    {
      v37 = v62;
      do
      {
        if ( v37 > v36->distance || v36->distance < 4.0 )
        {
          v38 = v36->speedMS;
          if ( v21 > v38 )
          {
            v39 = this->brakePoint.targetSpeed;
            if ( v39 == v22 || v39 > v38 )
            {
              this->brakePoint.targetSpeed = v38;
              this->brakePoint.targetNormalized = v33;
              this->brakePoint.wasObstacle = 1;
              this->brakePoint.speedDiff = v21 - v38;
              v36->odata->isBlocker = 1;
              this->brakePoint.lateralOffset = this->currentOffset;
            }
          }
        }
        ++v36;
      }
      while ( v36 != v35 );
    }
    reqspeed2 = InterpolatingSpline::wrapPosition(&this->currentSpline->spline, sl + v33);
    v40 = ksGFromRadius(radius, speedMS);
    v41 = this->car;
    reqLatG = v40;
    normalizedPos = Car::getTotalMass(v41, 1);
    v42 = RaceEngineer::evalAvailableBrake(&this->engineer, speedMS, reqLatG, normalizedPos);
    radius = v42 * pl.grip;
    if ( latg <= reqLatG )
    {
      v49 = RaceEngineer::projectWingsDrag(&this->engineer, speedMS);
      availBrake = v49 * v68;
      v48 = availBrake;
    }
    else
    {
      v43 = &latg;
      if ( radius <= latg )
        v43 = &radius;
      latg2 = (float)(*v43 * lpush) * 9.8059998;
      availBrake = latg2;
      v44 = RaceEngineer::projectWingsDrag(&this->engineer, speedMS);
      v45 = &brake_stopping_power;
      v46 = v44 * v68;
      v47 = this->brakeHintLive;
      if ( latg2 <= brake_stopping_power )
        v45 = &availBrake;
      availBrake = v46 + *v45;
      v48 = v47 * availBrake;
    }
    v50 = &latg2;
    reqLatG = 0.0;
    latg2 = (float)(brake_power_gain * v48) + (float)(pl.grade * 9.8059998);
    if ( latg2 <= 0.0 )
      v50 = &reqLatG;
    v51 = this->currentSpline;
    speedMS = speedMS - (float)((float)(4.0 / speedMS) * *v50);
    v62 = v62 + 4.0;
    availBrake = reqspeed2;
    AISpline::getSlimPayloadAt(v51, reqspeed2, &pl);
    latg2 = this->currentOffset;
    v52 = AISplineRecorder::getHintAtSplinePos(this->aiSplineRecorder, reqspeed2);
    v53 = this->currentSpline;
    reqLatG = v52;
    v54 = AISpline::getCornerRadiusAt(v53, reqspeed2, 15.0, latg2, 0.0);
    speed = speedMS;
    radius = v54 * reqLatG;
    if ( speedMS <= 0.0 )
    {
      v13 = v62;
      break;
    }
  }
  if ( v13 < 4.0 )
    goto LABEL_51;
LABEL_52:
  if ( this->brakePoint.targetSpeed == -1.0 )
  {
    v56 = LOBYTE(result.value);
  }
  else
  {
    v55 = Car::getSpeed(this->car, &result);
    v56 = 1;
    if ( this->brakePoint.targetSpeed <= v55->value && this->locNpos <= this->brakePoint.targetNormalized )
    {
      v57 = 0;
      goto LABEL_58;
    }
  }
  v57 = 1;
LABEL_58:
  if ( (v56 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v57 )
  {
    v68 = 0.0;
    v58 = 0.0;
    this->brakePoint.targetSpeed = -1.0;
  }
  else
  {
    v68 = (float)(Car::getSpeed(this->car, &result)->value - this->brakePoint.targetSpeed) * 0.5;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    v58 = v68;
  }
  return v58;
}
double AIDriver::getLateralPush(AIDriver *this)
{
  float v1; // xmm2_4
  int v2; // edx
  float v4; // xmm1_4
  float pit_variation; // [esp+0h] [ebp-4h]

  v1 = FLOAT_1_0;
  pit_variation = FLOAT_1_0;
  if ( this->splineSelection == Pits )
  {
    v1 = FLOAT_0_92000002;
    pit_variation = FLOAT_0_92000002;
  }
  v2 = (int)(float)(this->locNpos * 20.0);
  if ( v2 <= 20 )
  {
    if ( v2 < 0 )
      v2 = 0;
  }
  else
  {
    v2 = 20;
  }
  if ( !this->car->physicsGUID )
    return this->dynamicPush * this->basePush * pit_variation * this->engagedPush;
  v4 = (float)((float)((float)((float)(this->aiVariation.currentPush * this->dynamicPush) * v1) * this->engagedPush)
             * this->dangerPush)
     * this->genome[v2];
  if ( v4 > 1.0 )
    return 1.0;
  if ( v4 >= 0.0 )
    return v4;
  return 0.0;
}
double AIDriver::getLookAhead(AIDriver *this, const float factor, const float speed)
{
  float v4; // xmm1_4

  if ( this->splineSelection && this->pitLaneStartFlag )
    return 4.0;
  v4 = speed * 0.017999999;
  if ( (float)(speed * 0.017999999) > 1.0 )
    return 1.0 * factor + 3.0;
  if ( v4 >= 0.0 )
    return v4 * factor + 3.0;
  return 0.0 * factor + 3.0;
}
const char *AIDriver::getName(AIDriver *this)
{
  return "A.I.";
}
double AIDriver::getOutsideOffset(AIDriver *this)
{
  float rightness; // [esp+8h] [ebp-5Ch]
  AISplinePayload result; // [esp+Ch] [ebp-58h] BYREF

  if ( this->splineSelection )
    return 0.0;
  rightness = 1.0;
  if ( AISpline::payloadAtPosition(this->currentSpline, &result, this->locNpos)->direction <= 0.0 )
    rightness = -1.0;
  return (this->car->splineLocatorData.lateralOffset - (this->currentOffset + this->sinOffsetData.lastFinalOffset))
       * rightness;
}
double AIDriver::getSteerAtDistance(AIDriver *this, float distance, AISpline *spline, AISplinePayload *payload, float dt)
{
  float v6; // eax
  float v7; // xmm3_4
  float v8; // xmm0_4
  Car *v9; // eax
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  bool v14; // zf
  float v15; // xmm1_4
  float v16; // xmm0_4
  unsigned int *v17; // eax
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  float v20; // eax
  __int64 normDistance; // [esp+20h] [ebp-8Ch] BYREF
  vec3f nextpos; // [esp+28h] [ebp-84h] BYREF
  float normalizedPos; // [esp+34h] [ebp-78h]
  float left; // [esp+38h] [ebp-74h] BYREF
  vec3f local_next_pos; // [esp+3Ch] [ebp-70h] BYREF
  float v27; // [esp+50h] [ebp-5Ch]
  AISplinePayload pl; // [esp+54h] [ebp-58h] BYREF

  if ( (dword_186F234 & 1) == 0 )
  {
    perfCounter_42.name = "AIDriver::getSteerAtDistance";
    dword_186F234 |= 1u;
    perfCounter_42.group = Physics;
    perfCounter_42.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"AIDriver::getSteerAtDistance" | 0xFF000000;
  }
  *(float *)&normDistance = distance / Spline::length(&spline->spline);
  normalizedPos = this->locNpos;
  *(float *)&normDistance = InterpolatingSpline::wrapPosition(&spline->spline, normalizedPos + *(float *)&normDistance);
  AISpline::payloadAtPosition(spline, &pl, *(float *)&normDistance);
  v6 = pl.compression;
  v7 = FLOAT_1_0;
  *(__m128i *)&payload->speedMS = _mm_loadu_si128((const __m128i *)&pl);
  *(__m128i *)&payload->camber = _mm_loadu_si128((const __m128i *)&pl.camber);
  *(__m128i *)&payload->normal.z = _mm_loadu_si128((const __m128i *)&pl.normal.z);
  *(__m128i *)&payload->length = _mm_loadu_si128((const __m128i *)&pl.length);
  *(__m128i *)&payload->grip = _mm_loadu_si128((const __m128i *)&pl.grip);
  payload->compression = v6;
  v8 = payload->distFromCorner * 0.0033333334;
  if ( v8 <= 1.0 )
  {
    if ( v8 < 0.0 )
      v8 = 0.0;
  }
  else
  {
    v8 = FLOAT_1_0;
  }
  v9 = this->car;
  v10 = pl.sides[1];
  v11 = this->sinOffsetData.steerOffset * v8;
  this->offsetDistFromCorner = payload->distFromCorner;
  v12 = v9->carHalfWidth * 1.5;
  v13 = v10 - v12;
  if ( v11 <= v13 )
  {
    if ( (float)(v12 - pl.sides[0]) > v11 )
      v11 = v12 - pl.sides[0];
  }
  else
  {
    v11 = v13;
  }
  if ( this->splineSelection == Pits || this->isEngaged )
    v11 = 0.0;
  if ( (float)(dt * 7.0) <= 1.0 )
  {
    if ( (float)(dt * 7.0) >= 0.0 )
      v7 = dt * 7.0;
    else
      v7 = 0.0;
  }
  v14 = !this->isEngaged;
  v15 = (float)((float)(v11 - this->sinOffsetData.lastFinalOffset) * v7) + this->sinOffsetData.lastFinalOffset;
  v16 = this->currentOffset + v15;
  this->sinOffsetData.lastFinalOffset = v15;
  this->liveOffset = v16;
  if ( !v14
    && AISplineRecorder::getDangerAtSplinePos(this->aiSplineRecorder, normalizedPos, &left, (float *)&normDistance + 1) )
  {
    pl.sides[0] = pl.sides[0] - left;
    pl.sides[1] = pl.sides[1] - *((float *)&normDistance + 1);
  }
  AISpline::getPointWithOffset(
    spline,
    &nextpos,
    *(float *)&normDistance,
    this->liveOffset,
    this->car->carHalfWidth,
    &pl);
  if ( this->isSteeringToPit )
  {
    v17 = (unsigned int *)this->car;
    v18 = (__m128)v17[2748];
    v19 = (__m128)v17[2749];
    v27 = *((float *)v17 + 2750);
    *(_QWORD *)&nextpos.x = _mm_unpacklo_ps(v18, v19).m128_u64[0];
    nextpos.z = v27;
  }
  this->car->body->worldToLocal(this->car->body, &local_next_pos, &nextpos);
  v20 = nextpos.z;
  *(_QWORD *)&this->steerTarget.x = *(_QWORD *)&nextpos.x;
  this->steerTarget.z = v20;
  return (float)(__libm_sse2_asinf().m128_f32[0] * 7.0);
}
double AIDriver::getUltraGrip(AIDriver *this)
{
  return this->ultraGrip;
}
void __usercall AIDriver::initSetup(AIDriver *this@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // esi
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  Car *v10; // eax
  std::wstring *v11; // esi
  std::wstring *v12; // ecx
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // ecx
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring sys_filename; // [esp+Ch] [ebp-130h] BYREF
  std::wstring doc_filename; // [esp+24h] [ebp-118h] BYREF
  std::wstring v21; // [esp+3Ch] [ebp-100h] BYREF
  std::wstring result; // [esp+54h] [ebp-E8h] BYREF
  std::wstring v23; // [esp+6Ch] [ebp-D0h] BYREF
  std::wstring v24; // [esp+84h] [ebp-B8h] BYREF
  std::wstring v25; // [esp+9Ch] [ebp-A0h] BYREF
  std::wstring v26; // [esp+B4h] [ebp-88h] BYREF
  std::wstring v27; // [esp+CCh] [ebp-70h] BYREF
  std::wstring v28; // [esp+E4h] [ebp-58h] BYREF
  std::wstring v29; // [esp+FCh] [ebp-40h] BYREF
  std::wstring v30; // [esp+114h] [ebp-28h] BYREF
  int v31; // [esp+138h] [ebp-4h]

  v3 = Track::getName(this->car->ksPhysics->track, &result);
  v31 = 0;
  v4 = Path::getDocumentPath(&v29);
  LOBYTE(v31) = 1;
  v5 = std::operator+<wchar_t>(&v21, v4, L"/Assetto Corsa/setups/");
  v6 = &this->car->unixName;
  LOBYTE(v31) = 2;
  v7 = std::operator+<wchar_t>(&v27, v5, v6);
  LOBYTE(v31) = 3;
  v8 = std::operator+<wchar_t>(&v23, v7, L"/");
  LOBYTE(v31) = 4;
  v9 = std::operator+<wchar_t>(&v25, v8, v3);
  LOBYTE(v31) = 5;
  std::operator+<wchar_t>(&doc_filename, v9, L"/ai_default.ini");
  if ( v25._Myres >= 8 )
    operator delete(v25._Bx._Ptr);
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  if ( v23._Myres >= 8 )
    operator delete(v23._Bx._Ptr);
  v23._Myres = 7;
  v23._Mysize = 0;
  v23._Bx._Buf[0] = 0;
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  if ( v29._Myres >= 8 )
    operator delete(v29._Bx._Ptr);
  v29._Myres = 7;
  v29._Mysize = 0;
  v29._Bx._Buf[0] = 0;
  LOBYTE(v31) = 12;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v10 = this->car;
  result._Mysize = 0;
  v11 = Track::getName(v10->ksPhysics->track, &v30);
  v12 = &this->car->unixName;
  LOBYTE(v31) = 13;
  v13 = std::operator+<wchar_t>(&v28, L"system/setups/", v12);
  LOBYTE(v31) = 14;
  v14 = std::operator+<wchar_t>(&v26, v13, L"/");
  LOBYTE(v31) = 15;
  v15 = std::operator+<wchar_t>(&v24, v14, v11);
  LOBYTE(v31) = 16;
  std::operator+<wchar_t>(&sys_filename, v15, L"/ai_default.ini");
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  if ( v26._Myres >= 8 )
    operator delete(v26._Bx._Ptr);
  v26._Myres = 7;
  v26._Mysize = 0;
  v26._Bx._Buf[0] = 0;
  if ( v28._Myres >= 8 )
    operator delete(v28._Bx._Ptr);
  v28._Myres = 7;
  v28._Mysize = 0;
  v28._Bx._Buf[0] = 0;
  LOBYTE(v31) = 21;
  if ( v30._Myres >= 8 )
    operator delete(v30._Bx._Ptr);
  v30._Myres = 7;
  v30._Mysize = 0;
  v30._Bx._Buf[0] = 0;
  _printf("Looking for AI setups in:\n");
  v16 = &sys_filename;
  v17 = &doc_filename;
  if ( sys_filename._Myres >= 8 )
    v16 = (std::wstring *)sys_filename._Bx._Ptr;
  if ( doc_filename._Myres >= 8 )
    v17 = (std::wstring *)doc_filename._Bx._Ptr;
  _printf("%S\n%S\n", v17->_Bx._Buf, v16->_Bx._Buf);
  if ( Path::fileExists(a2, &doc_filename, 0) )
  {
    v18 = &doc_filename;
LABEL_29:
    SetupManager::load(&this->car->setupManager, v18);
    goto LABEL_31;
  }
  if ( Path::fileExists(a2, &sys_filename, 0) )
  {
    v18 = &sys_filename;
    goto LABEL_29;
  }
  _printf("Could not find any AI setup files\n");
LABEL_31:
  if ( sys_filename._Myres >= 8 )
    operator delete(sys_filename._Bx._Ptr);
  sys_filename._Myres = 7;
  sys_filename._Mysize = 0;
  sys_filename._Bx._Buf[0] = 0;
  if ( doc_filename._Myres >= 8 )
    operator delete(doc_filename._Bx._Ptr);
}
void AIDriver::initTyreStrategies(AIDriver *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  Car *v4; // edi
  TyreCompoundDef *v5; // esi
  TyreCompoundDef *v6; // edi
  const std::wstring *v7; // ebx
  const wchar_t *v8; // eax
  double v9; // st7
  float tcs; // [esp+14h] [ebp-A0h]
  std::wstring key; // [esp+18h] [ebp-9Ch] BYREF
  std::wstring v12; // [esp+30h] [ebp-84h] BYREF
  std::wstring result; // [esp+48h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+60h] [ebp-54h] BYREF
  int v15; // [esp+B0h] [ebp-4h]

  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  v15 = 0;
  v3 = std::operator+<wchar_t>(&v12, v2, L"/data/ai_tyres.ini");
  LOBYTE(v15) = 1;
  INIReader::INIReader(&ini, v3);
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  LOBYTE(v15) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    v4 = this->car;
    v5 = v4->tyres[0].compoundDefs._Myfirst;
    v6 = v4->tyres[0].compoundDefs._Mylast;
    if ( v5 != v6 )
    {
      v7 = &v5->shortName;
      do
      {
        if ( INIReader::hasSection(&ini, v7) )
        {
          if ( v7->_Myres < 8 )
            v8 = (const wchar_t *)v7;
          else
            v8 = v7->_Bx._Ptr;
          _printf("Loading tyre strategy for %S\n", v8);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          std::wstring::assign(&key, L"MAX_KM", 6u);
          LOBYTE(v15) = 5;
          v9 = INIReader::getFloat(&ini, v7, &key);
          LOBYTE(v15) = 4;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          tcs = v9 * 1000.0;
          std::map<std::wstring,TyreCompoundStrategy>::operator[](&this->tyreStrategies, v7)->maxKm = tcs;
        }
        ++v5;
        v7 = (const std::wstring *)((char *)v7 + 712);
      }
      while ( v5 != v6 );
    }
  }
  v15 = -1;
  INIReader::~INIReader(&ini);
}
void AIDriver::onNewSession(AIDriver *this, SessionInfo si)
{
  bool v3; // zf
  __m128i v4; // xmm0
  __m128i v5; // xmm0
  Car *v6; // eax
  AIWingSetup *v7; // esi
  AIWingSetup *i; // edi
  int v9; // eax
  float v10; // xmm2_4
  float v11; // xmm3_4
  SetupItem *v12; // ecx
  float v13; // xmm1_4
  char v14[24]; // [esp+30h] [ebp-20h] BYREF
  int v15; // [esp+48h] [ebp-8h]

  _printf("AIDriver::onNewSession: %d\n", si.type);
  *(_OWORD *)&v14[8] = 0i64;
  *(_QWORD *)v14 = 0i64;
  v3 = si.type == Race;
  v4 = _mm_loadu_si128((const __m128i *)v14);
  v15 = 0;
  *(_OWORD *)&this->humanize.minTimeBetweenMistakesMS = _xmm;
  this->lapsToComplete = 10000;
  *(__m128i *)&this->humanize.brakeMistakeTime = v4;
  this->requestPitStop = 0;
  v5 = _mm_loadu_si128((const __m128i *)&v14[16]);
  this->hasChoosenTyres = 0;
  *(__m128i *)&this->humanize.nextTractionMistake = v5;
  if ( v3 )
    AIDriver::generatePitStopStrategy(this, si.laps);
  v6 = this->car;
  *(__m128i *)&this->currentSessionInfo.type = _mm_loadu_si128((const __m128i *)&si);
  *(__m128i *)&this->currentSessionInfo.timeSecs = _mm_loadu_si128((const __m128i *)&si.timeSecs);
  if ( v6->physicsGUID )
  {
    v7 = this->aiSetup.wings._Myfirst;
    for ( i = this->aiSetup.wings._Mylast; v7 != i; ++v7 )
    {
      v9 = _rand();
      v10 = v7->maxValue;
      v11 = v7->minValue;
      v12 = v7->item;
      v13 = (float)((float)((float)(v10 - v11) * (float)((float)((float)((float)v9 * 0.000030518509) * 2.0) - 1.0))
                  * this->wingVariation)
          + *v12->connectedFloat;
      if ( v13 <= v10 )
      {
        if ( v11 <= v13 )
          v10 = (float)((float)((float)(v7->maxValue - v11)
                              * (float)((float)((float)((float)v9 * 0.000030518509) * 2.0) - 1.0))
                      * this->wingVariation)
              + *v12->connectedFloat;
        else
          v10 = v7->minValue;
      }
      v12->newValue = (float)(int)v10;
      v7->item->attached = 1;
      _printf(
        "AI car %d changes Wing%d %f -> %f\n",
        this->car->physicsGUID,
        v7->index,
        *v7->item->connectedFloat,
        v7->item->newValue);
    }
  }
}
void AIDriver::selectTimeStartTime(AIDriver *this)
{
  int v2; // eax
  AISplineRecorder *v3; // ecx
  AISpline *v4; // eax
  AISplineRecorder *v5; // ecx
  AISpline *v6; // eax

  v2 = _mm_cvtsi128_si32(_mm_loadu_si128((const __m128i *)&this->car->ksPhysics->sessionInfo));
  if ( v2 >= 0 )
  {
    if ( v2 <= 2 )
    {
      AIDriver::generatePitlaneWait(this);
      v5 = this->aiSplineRecorder;
      this->splineSelection = Pits;
      v6 = AISplineRecorder::getPitLaneSpline(v5);
      this->pitLaneStartFlag = 1;
      this->currentSpline = v6;
    }
    else if ( v2 == 3 && !this->requestPitStop )
    {
      v3 = this->aiSplineRecorder;
      this->timeToStart = DOUBLE_N1_0;
      this->splineSelection = FastLane;
      v4 = AISplineRecorder::getBestLapSpline(v3);
      this->pitLaneStartFlag = 0;
      this->currentSpline = v4;
      AIDriver::updateCurrentSplinePos(this);
      return;
    }
  }
  AIDriver::updateCurrentSplinePos(this);
}
void AIDriver::setUltraGrip(AIDriver *this, float value)
{
  this->ultraGrip = value;
}
void AIDriver::stepCarsAwareness2(AIDriver *this, float dt)
{
  AIDriver *v2; // edi
  Car *v3; // ecx
  Car *v4; // eax
  int v5; // ecx
  float v6; // xmm0_4
  PhysicsEngine *v7; // esi
  Car *v8; // ecx
  Car *v9; // esi
  bool v10; // cc
  float *v11; // edx
  float *v12; // ecx
  PhysicsEngine *v13; // eax
  Car **v14; // esi
  unsigned int v15; // eax
  float v16; // ecx
  Car *v17; // eax
  Car *v18; // eax
  IRigidBody_vtbl *v19; // edi
  int v20; // eax
  int v21; // eax
  __int64 v22; // xmm0_8
  IRigidBody *v23; // ecx
  IRigidBody_vtbl *v24; // eax
  float *v25; // edi
  float *v26; // eax
  float v27; // xmm2_4
  float v28; // xmm1_4
  Car *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  Car *v33; // eax
  Car *v34; // ecx
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  Car *v39; // ecx
  float v40; // xmm1_4
  float v41; // xmm0_4
  vec3f *v42; // eax
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  Car *v47; // xmm4_4
  float *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm0_4
  float *v51; // eax
  float v52; // xmm0_4
  Speed *v53; // eax
  float left; // xmm3_4
  float right; // xmm2_4
  char v56; // al
  float eng_speedR; // xmm0_4
  bool v58; // zf
  int v59; // eax
  double v60; // st7
  Car *v61; // eax
  double v62; // st7
  float v63; // xmm2_4
  float v64; // xmm0_4
  float *v65; // eax
  float v66; // xmm3_4
  float v67; // xmm0_4
  AIOpponentData *v68; // ecx
  float v69; // edi
  float v70; // xmm1_4
  float v71; // xmm2_4
  float v72; // esi
  int v73; // edi
  AIDriver *v74; // ecx
  Car *v75; // eax
  Car *v76; // edx
  float v77; // xmm0_4
  float v78; // xmm2_4
  float v79; // xmm2_4
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm4_4
  float v83; // xmm2_4
  float v84; // xmm0_4
  Car *v85; // xmm0_4
  Speed *v86; // eax
  float v87; // xmm2_4
  char v88; // al
  char v89; // al
  float v90; // xmm0_4
  float v91; // xmm0_4
  float v92; // xmm0_4
  float v93; // xmm0_4
  float v94; // xmm0_4
  float v95; // xmm0_4
  AIDriver *v96; // ecx
  float v97; // xmm2_4
  int v98; // eax
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm4_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float *v104; // eax
  float v105; // xmm3_4
  float v106; // xmm2_4
  float v107; // xmm1_4
  char v108[12]; // [esp+28h] [ebp-10Ch] BYREF
  vec3f v109; // [esp+34h] [ebp-100h] BYREF
  vec3f v110; // [esp+40h] [ebp-F4h] BYREF
  vec3f v111; // [esp+4Ch] [ebp-E8h] BYREF
  vec3f v112; // [esp+58h] [ebp-DCh] BYREF
  vec3f v113; // [esp+64h] [ebp-D0h] BYREF
  __int64 v114; // [esp+70h] [ebp-C4h]
  float v115; // [esp+78h] [ebp-BCh]
  AIOpponentData _Val; // [esp+7Ch] [ebp-B8h] BYREF
  float v117; // [esp+C4h] [ebp-70h]
  float v118[2]; // [esp+C8h] [ebp-6Ch] BYREF
  std::vector<AISplineHint> *v119; // [esp+D0h] [ebp-64h]
  Speed v120; // [esp+D4h] [ebp-60h] BYREF
  float v121; // [esp+D8h] [ebp-5Ch]
  AISplineHint v122; // [esp+DCh] [ebp-58h] BYREF
  float v123; // [esp+E8h] [ebp-4Ch]
  float v124; // [esp+ECh] [ebp-48h]
  float v125; // [esp+F0h] [ebp-44h]
  float eng_speedL; // [esp+F4h] [ebp-40h]
  float v127; // [esp+F8h] [ebp-3Ch] BYREF
  int v128; // [esp+FCh] [ebp-38h]
  float v129; // [esp+100h] [ebp-34h]
  float v130; // [esp+104h] [ebp-30h]
  float v131; // [esp+108h] [ebp-2Ch]
  Speed v132; // [esp+10Ch] [ebp-28h] BYREF
  bool v133; // [esp+113h] [ebp-21h]
  Speed result; // [esp+114h] [ebp-20h] BYREF
  float v135; // [esp+118h] [ebp-1Ch] BYREF
  float v136; // [esp+11Ch] [ebp-18h]
  float v137; // [esp+120h] [ebp-14h]
  AIDriver *v138; // [esp+124h] [ebp-10h]
  Car *v139; // [esp+128h] [ebp-Ch] BYREF
  float v140; // [esp+12Ch] [ebp-8h] BYREF
  bool v141; // [esp+132h] [ebp-2h]
  bool v142; // [esp+133h] [ebp-1h]

  v2 = this;
  v138 = this;
  v117 = this->aggressionHint * this->aggression;
  AIDriver::calcMinForwardSides(this, 100.0);
  v2->brakeObstacles._Mylast = v2->brakeObstacles._Myfirst;
  v119 = (std::vector<AISplineHint> *)&v2->brakeObstacles;
  v3 = v2->car;
  v2->nextCarModifier = 0.0;
  if ( Car::isInPitLane(v3) )
    return;
  v4 = v2->car;
  v5 = (char *)v2->opponentData._Mylast - (char *)v2->opponentData._Myfirst;
  v6 = v4->carHalfWidth;
  v7 = v4->ksPhysics;
  LODWORD(v121) = &v2->opponentData;
  v131 = v6 * 2.5;
  v125 = FLOAT_3_0;
  if ( v7->cars._Mylast - v7->cars._Myfirst > (unsigned int)(v5 / 72) )
    std::vector<AIOpponentData>::resize(&v2->opponentData, v7->cars._Mylast - v7->cars._Myfirst);
  v8 = v2->car;
  v2->desiredOffset = 0.0;
  v128 = 0;
  v136 = FLOAT_N1_0;
  v137 = FLOAT_N1_0;
  eng_speedL = 0.0;
  v130 = 0.0;
  v123 = Car::getSpeed(v8, &result)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v2->opponentData._Mylast = v2->opponentData._Myfirst;
  v9 = v2->car;
  v10 = v9->tyres[3].status.ndSlip <= v9->tyres[2].status.ndSlip;
  v11 = &v9->tyres[2].status.ndSlip;
  v135 = 0.0;
  v12 = &v9->tyres[0].status.ndSlip;
  result.value = 0.0;
  if ( !v10 )
    v11 = &v9->tyres[3].status.ndSlip;
  if ( v9->tyres[1].status.ndSlip > *v12 )
    v12 = &v9->tyres[1].status.ndSlip;
  v13 = v9->ksPhysics;
  v14 = v13->cars._Myfirst;
  v15 = (unsigned int)v13->cars._Mylast;
  if ( *v11 > *v12 )
    v12 = v11;
  v133 = *v12 >= (float)((float)(v117 * 0.19999999) + 0.80000001);
  LODWORD(v16) = (v15 - (unsigned int)v14 + 3) >> 2;
  if ( (unsigned int)v14 > v15 )
    v16 = 0.0;
  v129 = v16;
  if ( v16 == 0.0 )
  {
    right = v137;
    left = v137;
LABEL_61:
    v56 = 0;
    goto LABEL_62;
  }
  do
  {
    v17 = *v14;
    v139 = v17;
    if ( v17 != v2->car )
    {
      if ( !Car::isInPitLane(v17) )
      {
        AIOpponentData::AIOpponentData(&_Val);
        v18 = v2->car;
        _Val.car = v139;
        _Val.isUnderAttack = 0.0;
        v19 = v18->body->__vftable;
        v20 = ((int (*)(IRigidBody *, char *, _DWORD))v139->body->getPosition)(v139->body, v108, 0);
        v21 = (int)v19->worldToLocal(v138->car->body, &v111, (const vec3f *)v20);
        v22 = *(_QWORD *)v21;
        v23 = v139->body;
        v140 = *(float *)(v21 + 8);
        _Val.relPos.z = v140;
        *(_QWORD *)v118 = v22;
        v24 = v23->__vftable;
        *(_QWORD *)&_Val.relPos.x = v22;
        v25 = (float *)v24->getVelocity(v23, &v109);
        v26 = (float *)v138->car->body->getVelocity(v138->car->body, &v112);
        v27 = v26[1] - v25[1];
        v28 = v26[2] - v25[2];
        *(float *)&v22 = *v26 - *v25;
        v2 = v138;
        v122.endPos = v27;
        v122.value = v28;
        v29 = v138->car;
        LODWORD(v122.startPos) = v22;
        v29->body->worldToLocalNormal(v29->body, &v113, (const vec3f *)&v122);
        if ( _Val.relPos.x <= 0.0 )
        {
          if ( _Val.relPos.x >= 0.0 )
            v30 = 0.0;
          else
            v30 = FLOAT_N1_0;
        }
        else
        {
          v30 = FLOAT_1_0;
        }
        v124 = v30 * v113.x;
        _Val.relXSpeed = v30 * v113.x;
        v114 = *(_QWORD *)v118;
        v115 = v140;
        v140 = _Val.relPos.z;
        LODWORD(v31) = __libm_sse2_asinf().m128_u32[0];
        if ( v140 <= 0.0 )
        {
          if ( v140 >= 0.0 )
            v32 = 0.0;
          else
            v32 = FLOAT_N1_0;
        }
        else
        {
          v32 = FLOAT_1_0;
        }
        v33 = v139;
        v34 = v2->car;
        v35 = v34->splineLocatorData.npos;
        v118[1] = (float)(v32 * v31) * 57.29578;
        _Val.relAngle = v118[1];
        v36 = v139->splineLocatorData.npos - v35;
        v37 = v35 - v139->splineLocatorData.npos;
        if ( v36 < 0.0 )
          v36 = v36 + 1.0;
        if ( v37 < 0.0 )
          v37 = v37 + 1.0;
        v38 = v34->splineLocatorData.splineLength;
        v39 = v139;
        v120.value = v38 * v37;
        _Val.dist_back = v38 * v37;
        v40 = v139->splineLocatorData.lateralOffset;
        *(float *)&v139 = v38 * v36;
        _Val.dist_front = v38 * v36;
        v41 = v33->splineLocatorData.sidesFromIL[0] + v40;
        _Val.lateral_offset = v40;
        _Val.spaceLeft = v41;
        _Val.spaceRight = v33->splineLocatorData.sidesFromIL[1] - v40;
        v42 = Car::getVelocity(v39, &v110);
        v43 = (float)((float)(v42->x * v42->x) + (float)(v42->y * v42->y)) + (float)(v42->z * v42->z);
        if ( v43 == 0.0 )
          v44 = 0.0;
        else
          v44 = fsqrt(v43);
        v45 = v140;
        _Val.speedMS = v44;
        v46 = v123 - v44;
        if ( v140 <= 0.0 || v46 <= 0.0 )
        {
          v47 = v139;
          v52 = v123 * 100.0;
          _Val.tti = 100.0;
        }
        else
        {
          v47 = v139;
          v48 = &v140;
          v49 = 1.0 / v46;
          v127 = 0.0099999998;
          v140 = *(float *)&v139 - 6.0;
          if ( (float)(*(float *)&v139 - 6.0) <= 0.0099999998 )
            v48 = &v127;
          v50 = *v48;
          v51 = &v127;
          v140 = 0.0099999998;
          _Val.tti = v50 * v49;
          v127 = *(float *)&v139 - 3.0;
          if ( (float)(*(float *)&v139 - 3.0) <= 0.0099999998 )
            v51 = &v140;
          v52 = (float)((float)(*v51 * v49) * v123) * 0.80000001;
        }
        _Val.distToPass = v52;
        if ( COERCE_FLOAT(LODWORD(v45) & _xmm) >= 8.0
          || *(float *)&v47 >= 15.0 && v120.value >= 15.0
          || COERCE_FLOAT(LODWORD(v118[1]) & _xmm) <= 25.0 )
        {
          _Val.isEngaged = 0;
        }
        else
        {
          ++LODWORD(v135);
          _Val.isEngaged = 1;
          if ( _Val.relPos.x <= 0.0 )
          {
            if ( v137 < 0.0 || v137 > COERCE_FLOAT(LODWORD(_Val.relPos.x) ^ _xmm) )
            {
              LODWORD(v137) = LODWORD(_Val.relPos.x) ^ _xmm;
              v130 = v124;
            }
          }
          else if ( v136 < 0.0 || v136 > _Val.relPos.x )
          {
            v136 = _Val.relPos.x;
            eng_speedL = v124;
          }
        }
        v53 = Car::getSpeed(v2->car, &v132);
        v142 = (float)((float)((float)(v53->value * 3.5999999) * 0.2) + 20.0) > *(float *)&v139;
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v132);
        if ( v142 )
          ++v128;
        std::vector<AIOpponentData>::push_back(&v2->opponentData, &_Val);
      }
      v16 = v129;
    }
    ++v14;
    ++LODWORD(result.value);
  }
  while ( LODWORD(result.value) != LODWORD(v16) );
  left = v136;
  right = v137;
  if ( v136 <= 0.0 && v137 <= 0.0 )
    goto LABEL_61;
  v56 = 1;
LABEL_62:
  eng_speedR = v130;
  v2->isEngaged = v56;
  v132.value = AIDriver::getEngagedDesiredOffset(
                 v2,
                 left,
                 right,
                 v2->car->splineLocatorData.lateralOffset,
                 &v132.value,
                 v2->minForwardSides[0],
                 v2->minForwardSides[1],
                 eng_speedL,
                 eng_speedR);
  v58 = v132.value == 0.0;
  v2->desiredOffset = v132.value;
  if ( !v58 )
    v125 = FLOAT_4_0;
  if ( v136 <= 0.0 || v137 <= 0.0 )
  {
    v59 = LODWORD(v135);
    v2->engagedPush = 1.0;
    if ( v59 > 1 )
      v2->engagedPush = 1.0 - (float)((float)((float)v59 - 1.0) * 0.1);
  }
  else
  {
    v2->engagedPush = 0.89999998;
  }
  v60 = AIDriver::getDistanceToApex(v2, v2->car->carHalfWidth * 2.0, 10.0);
  v61 = v2->car;
  *(float *)&v139 = v60;
  v62 = AIDriver::getDistanceToApex(v2, v61->carHalfWidth * -2.0, 10.0);
  v63 = v2->desiredOffset;
  LODWORD(v64) = LODWORD(v2->desiredOffset) & _xmm;
  v135 = v62;
  if ( v64 < 0.2 )
  {
    v65 = (float *)&v139;
    if ( *(float *)&v139 <= v135 )
      v65 = &v135;
    if ( *v65 < 200.0 )
    {
      v66 = v131;
      if ( v136 > 0.0 )
        v2->desiredOffset = (float)(v131 * 1.5) + v63;
      if ( v137 > 0.0 )
        v2->desiredOffset = v2->desiredOffset - (float)(v66 * 1.5);
    }
  }
  v67 = v2->car->splineLocatorData.lateralOffset;
  v68 = v2->opponentData._Mylast;
  v69 = v121;
  result.value = v67;
  std::_Sort<AIOpponentData *,int,_lambda_00b575d47c1d4b385daca99a01dfbd27_>(
    *(AIOpponentData **)LODWORD(v121),
    v68,
    ((int)v68 - *(_DWORD *)LODWORD(v121)) / 72,
    LOBYTE(dt));
  v70 = FLOAT_1_0;
  v71 = FLOAT_8_0;
  v72 = *(float *)LODWORD(v69);
  v73 = *(_DWORD *)(LODWORD(v69) + 4);
  v142 = 0;
  v121 = (float)((float)((float)v128 * 0.050000001) + 1.0) * (float)((float)(v123 * 0.07) + 8.0);
  if ( LODWORD(v72) == v73 )
    goto LABEL_147;
  v74 = v138;
  while ( 1 )
  {
    if ( *(_BYTE *)(LODWORD(v72) + 12) )
      goto LABEL_137;
    v75 = *(Car **)(LODWORD(v72) + 64);
    if ( v75->splineLocatorData.isOutsideTrackLimits && *(float *)(LODWORD(v72) + 16) < 20.0 )
      goto LABEL_137;
    if ( v71 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(LODWORD(v72) + 8) - v74->car->splineLocatorData.lateralOffset) & _xmm) )
      goto LABEL_137;
    Car::getEngagement(v75, 8.0, &v132.value, &v118[1]);
    v74 = v138;
    v76 = v138->car;
    v77 = (float)(v76->powerClassIndex - *(float *)(*(_DWORD *)(LODWORD(v72) + 64) + 12)) * 0.0099999998;
    if ( v77 <= 6.0 )
    {
      if ( v77 >= 0.0 )
        v78 = (float)(v76->powerClassIndex - *(float *)(*(_DWORD *)(LODWORD(v72) + 64) + 12)) * 0.0099999998;
      else
        v78 = 0.0;
    }
    else
    {
      v78 = FLOAT_6_0;
    }
    v79 = v78 + 1.5;
    if ( v77 <= 6.0 )
    {
      if ( v77 < 0.0 )
        v77 = 0.0;
    }
    else
    {
      v77 = FLOAT_6_0;
    }
    v80 = *(float *)LODWORD(v72);
    v124 = v77 + v121;
    if ( (float)(v77 + v121) <= v80 )
    {
      v81 = *(float *)(LODWORD(v72) + 20);
      if ( v79 <= v81 )
      {
        if ( v121 > v80
          && (float)(v131 * 1.5) > COERCE_FLOAT(COERCE_UNSIGNED_INT(result.value - *(float *)(LODWORD(v72) + 8)) & _xmm) )
        {
          v93 = v138->nextCarModifier;
          if ( *(float *)(LODWORD(v72) + 16) <= v123 )
            v94 = v93 + 1.0;
          else
            v94 = v93 + 0.5;
          v138->nextCarModifier = v94;
LABEL_143:
          v95 = *(float *)LODWORD(v72) - 8.0;
          goto LABEL_145;
        }
        if ( v81 < 3.0 )
          goto LABEL_143;
        goto LABEL_136;
      }
    }
    v82 = 0.0;
    v83 = 0.0;
    v140 = 0.0;
    if ( (v136 < 0.0 || v136 > (float)(v131 * 2.0)) && (v132.value < 0.0 || v132.value > (float)(v131 * 2.0)) )
    {
      v82 = *(float *)(LODWORD(v72) + 24);
      v140 = v82;
    }
    if ( (v137 < 0.0 || v137 > (float)(v131 * 2.0)) && (v118[1] < 0.0 || v118[1] > (float)(v131 * 2.0)) )
      v83 = *(float *)(LODWORD(v72) + 28);
    if ( v82 <= v83 )
    {
      v140 = v83;
      v129 = v131 * 1.5;
      v130 = (float)(v131 * 1.5) + *(float *)(LODWORD(v72) + 8);
      eng_speedL = COERCE_FLOAT(COERCE_UNSIGNED_INT(v130 - v138->currentOffset) & _xmm) / v125;
      v85 = v139;
    }
    else
    {
      v84 = *(float *)(LODWORD(v72) + 8) - (float)(v131 * 1.5);
      v129 = v131 * 1.5;
      v130 = v84;
      eng_speedL = COERCE_FLOAT(COERCE_UNSIGNED_INT(v84 - v138->currentOffset) & _xmm) / v125;
      *(float *)&v85 = v135;
    }
    v141 = *(float *)&v85 > *(float *)(LODWORD(v72) + 60) || *(float *)&v85 > 200.0;
    v86 = Car::getSpeed(v76, &v120);
    v127 = v86->value / v138->targetSpeed;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v120);
    v74 = v138;
    if ( v117 > v127 && v138->targetSpeed > 0.0 && !v133 )
    {
      v87 = FLOAT_1_0;
LABEL_126:
      v88 = 1;
      goto LABEL_120;
    }
    v87 = FLOAT_1_0;
    if ( *(float *)(LODWORD(v72) + 16) < 1.0 )
      goto LABEL_126;
    v88 = v141;
LABEL_120:
    if ( v142
      || v140 <= (float)((float)((float)((float)v128 * 0.2) + v87) * v131)
      || *(float *)(LODWORD(v72) + 20) <= eng_speedL
      || !v88 )
    {
      break;
    }
    v142 = 1;
    v138->desiredOffset = v130;
LABEL_136:
    v71 = FLOAT_8_0;
LABEL_137:
    LODWORD(v72) += 72;
    if ( LODWORD(v72) == v73 )
      goto LABEL_146;
  }
  v89 = 0;
  if ( v124 > *(float *)LODWORD(v72)
    && v129 > COERCE_FLOAT(COERCE_UNSIGNED_INT(result.value - *(float *)(LODWORD(v72) + 8)) & _xmm) )
  {
    v90 = *(float *)(LODWORD(v72) + 16);
    if ( v90 > v87 )
    {
      v10 = v90 <= v123;
      v91 = v138->nextCarModifier;
      if ( v10 )
        v92 = v91 + v87;
      else
        v92 = v91 + 0.5;
      v138->nextCarModifier = v92;
      v89 = 1;
    }
  }
  if ( *(float *)(LODWORD(v72) + 20) >= 2.0 && !v89 )
    goto LABEL_136;
  v95 = *(float *)LODWORD(v72) - 7.0;
LABEL_145:
  v122.startPos = v95;
  v122.endPos = *(float *)(LODWORD(v72) + 16);
  v122.value = v72;
  std::vector<AISplineHint>::push_back(v119, &v122);
LABEL_146:
  v70 = FLOAT_1_0;
LABEL_147:
  v96 = v138;
  v97 = v138->nextCarModifier;
  if ( v97 <= v70 )
  {
    if ( v97 < 0.0 )
      v97 = 0.0;
  }
  else
  {
    v97 = v70;
  }
  v98 = v128;
  v138->nextCarModifier = v97;
  if ( v98 <= 1 )
    v96->dynamicPush = 1.0;
  else
    v96->dynamicPush = v70 - (float)((float)v98 * 0.001);
  v99 = v96->desiredOffset;
  if ( v99 == 0.0 )
  {
    if ( v136 >= 0.0 || v137 >= 0.0 )
      v102 = FLOAT_0_0020000001;
    else
      v102 = FLOAT_0_0099999998;
    v103 = v96->currentOffset;
    if ( v102 < COERCE_FLOAT(COERCE_UNSIGNED_INT(v103 - v99) & _xmm) )
    {
      if ( v99 <= v103 )
        v99 = v103 - v102;
      else
        v99 = v103 + v102;
    }
  }
  else
  {
    v100 = v96->currentOffset;
    v101 = v125 * dt;
    if ( (float)(v125 * dt) < COERCE_FLOAT(COERCE_UNSIGNED_INT(v100 - v99) & _xmm) )
    {
      if ( v99 <= v100 )
        v99 = v100 - v101;
      else
        v99 = v100 + v101;
    }
  }
  v104 = (float *)v96->car;
  v105 = v99;
  v96->currentOffset = v99;
  v106 = v104[31] - v104[2758];
  v107 = v104[2759] - v104[31];
  if ( v105 <= v107 )
  {
    if ( v106 > v105 )
    {
      v96->currentOffset = v106;
      return;
    }
    v107 = v105;
  }
  v96->currentOffset = v107;
}
void AIDriver::stepDRS(AIDriver *this, CarControls *controls, float dt)
{
  Car *v4; // ecx

  if ( controls->drs )
    goto LABEL_9;
  v4 = this->car;
  if ( v4->drs.isActive )
    this->lastDRSActivationTime = v4->ksPhysics->physicsTime;
  if ( this->distToNextCorner <= 200.0 || v4->drs.isActive || !v4->drs.isAvailable )
  {
LABEL_9:
    controls->drs = 0;
  }
  else if ( v4->ksPhysics->physicsTime - this->lastDRSActivationTime > 5000.0 )
  {
    controls->drs = 1;
  }
}
void AIDriver::stepGasBrake(AIDriver *this, float dt)
{
  AISpline *v3; // esi
  double v4; // st7
  float v5; // xmm0_4
  double v6; // st7
  AISpline *v7; // ecx
  Car *v8; // eax
  AISplineRecorder *v9; // ecx
  double v10; // st7
  AISpline *v11; // ecx
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  double v19; // st7
  float *v20; // esi
  AISplineRecorder *v21; // ecx
  float v22; // xmm7_4
  Speed *v23; // eax
  bool v24; // cc
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm5_4
  Car *v28; // edx
  float *v29; // ecx
  float v30; // xmm1_4
  float *v31; // ecx
  bool v32; // cf
  float v33; // xmm0_4
  float *v34; // esi
  float *v35; // ecx
  float v36; // xmm0_4
  float *v37; // eax
  PhysicsEngine *v38; // eax
  __m128d v39; // xmm2
  long double v40; // xmm1_8
  double v41; // st7
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  double v46; // st7
  float v47; // xmm0_4
  AIBrakePointData *v48; // eax
  Car *v49; // ecx
  float v50; // xmm0_4
  float *v51; // esi
  Speed *v52; // eax
  float v53; // xmm3_4
  float v54; // xmm2_4
  Speed *v55; // eax
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm5_4
  float v62; // xmm1_4
  Speed *v63; // eax
  Car *v64; // ecx
  float v65; // xmm4_4
  IRigidBody *v66; // ecx
  IRigidBody_vtbl *v67; // eax
  mat44f *(*v68)(IRigidBody *, mat44f *, float); // eax
  _DWORD *v69; // eax
  float v70; // xmm1_4
  int v71; // xmm0_4
  float v72; // xmm2_4
  Speed *v73; // eax
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  Speed *v78; // eax
  Car *v79; // eax
  float v80; // xmm2_4
  float v81; // xmm1_4
  float v82; // xmm0_4
  Car *v83; // esi
  double v84; // st7
  float v85; // xmm0_4
  Car *v86; // ecx
  Car *v87; // eax
  Speed *v88; // eax
  Car *v89; // ecx
  float v90; // xmm0_4
  int i; // esi
  ISuspension *v92; // ecx
  float *v93; // esi
  float v94; // xmm0_4
  float *v95; // eax
  float v96; // xmm2_4
  float v97; // xmm0_4
  float normalizedPosition; // [esp+4h] [ebp-F4h]
  float distance; // [esp+8h] [ebp-F0h]
  float pos; // [esp+10h] [ebp-E8h]
  float posa; // [esp+10h] [ebp-E8h]
  float v102[2]; // [esp+1Ch] [ebp-DCh] BYREF
  float speed; // [esp+24h] [ebp-D4h]
  float radius; // [esp+28h] [ebp-D0h]
  float v105; // [esp+2Ch] [ebp-CCh] BYREF
  float v106; // [esp+30h] [ebp-C8h] BYREF
  float normalizedPos; // [esp+34h] [ebp-C4h]
  float v108; // [esp+38h] [ebp-C0h] BYREF
  Speed v109; // [esp+3Ch] [ebp-BCh] BYREF
  float v110; // [esp+40h] [ebp-B8h] BYREF
  Speed v111; // [esp+44h] [ebp-B4h] BYREF
  bool v112; // [esp+4Bh] [ebp-ADh]
  AISplinePayload v113; // [esp+4Ch] [ebp-ACh] BYREF
  AISplinePayload result; // [esp+A0h] [ebp-58h] BYREF

  v109.value = 0.0;
  RaceEngineer::getAccelerationProfile(&this->engineer, v102);
  v3 = this->currentSpline;
  v4 = Spline::length(&v3->spline);
  v5 = this->gasBrakeLookahead;
  v111.value = v4;
  v6 = InterpolatingSpline::wrapPosition(&v3->spline, (float)(v5 / v111.value) + this->locNpos);
  v7 = this->currentSpline;
  normalizedPos = v6;
  AISpline::payloadAtPosition(v7, &result, normalizedPos);
  speed = Car::getSpeed(this->car, &v111)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v111);
  v8 = this->car;
  radius = this->currentOffset;
  v9 = this->aiSplineRecorder;
  v111.value = v8->carHalfWidth;
  v10 = AISplineRecorder::getHintAtSplinePos(v9, normalizedPos);
  v11 = this->currentSpline;
  v106 = v10;
  v12 = AISpline::getCornerRadiusAt(v11, normalizedPos, 15.0, radius, v111.value);
  v13 = this->smoothLoads[1];
  v14 = this->car->tyres[0].status.load - this->smoothLoads[0];
  radius = v12 * v106;
  this->smoothLoads[0] = (float)(v14 * 0.1) + this->smoothLoads[0];
  v15 = (float)((float)(this->car->tyres[1].status.load - v13) * 0.1) + v13;
  v16 = this->smoothLoads[2];
  this->smoothLoads[1] = v15;
  v17 = (float)((float)(this->car->tyres[2].status.load - v16) * 0.1) + v16;
  v18 = this->smoothLoads[3];
  this->smoothLoads[2] = v17;
  this->smoothLoads[3] = (float)((float)(this->car->tyres[3].status.load - v18) * 0.1) + v18;
  pos = AeroMap::getCurrentLiftKG(&this->car->aeroMap);
  distance = this->aeroHint;
  normalizedPosition = Car::getTotalMass(this->car, 1);
  v19 = RaceEngineer::evalLateralGrip(&this->engineer, speed, normalizedPosition, distance, this->smoothLoads, pos);
  v111.value = v19 * result.grip * this->tyresHint;
  v106 = ksSpeedFromRadius(radius, v111.value);
  v20 = &this->targetSpeed;
  this->targetSpeed = v106;
  v111.value = AIDriver::getLateralPush(this);
  v21 = this->aiSplineRecorder;
  posa = this->locNpos;
  this->targetSpeed = v106 - (float)((float)(1.0 - v111.value) * 22.222223);
  v22 = FLOAT_0_27777779;
  v111.value = AISplineRecorder::getMaxSpeedHintAtSplinePos(v21, posa);
  if ( v111.value > 0.0 )
  {
    v23 = &v111;
    v24 = (float)(v111.value * 0.27777779) <= *v20;
    v111.value = v111.value * 0.27777779;
    if ( !v24 )
      v23 = (Speed *)&this->targetSpeed;
    *v20 = v23->value;
  }
  if ( this->splineSelection )
  {
    v25 = 0.0;
  }
  else
  {
    if ( AISpline::payloadAtPosition(this->currentSpline, &v113, this->locNpos)->direction <= 0.0 )
      v26 = FLOAT_N1_0;
    else
      v26 = FLOAT_1_0;
    v22 = FLOAT_0_27777779;
    v25 = (float)(this->car->splineLocatorData.lateralOffset
                - (float)(this->sinOffsetData.lastFinalOffset + this->currentOffset))
        * v26;
  }
  this->outsideOffset = v25;
  if ( v25 > 0.0 && this->splineSelection == FastLane )
  {
    LODWORD(v27) = COERCE_UNSIGNED_INT(this->targetSteerFinal * 0.66666669) & _xmm;
    if ( v27 <= 1.0 )
    {
      if ( v27 < 0.0 )
        v27 = 0.0;
    }
    else
    {
      v27 = FLOAT_1_0;
    }
    *v20 = (float)((float)((float)(speed / (float)((float)(v25 * 0.055) + 1.0)) - *v20) * v27) + *v20;
  }
  v28 = this->car;
  v29 = &v28->tyres[2].status.ndSlip;
  this->splineTargetSpeed = *v20;
  if ( v28->tyres[3].status.ndSlip > v28->tyres[2].status.ndSlip )
    v29 = &v28->tyres[3].status.ndSlip;
  v24 = v28->tyres[1].status.ndSlip <= v28->tyres[0].status.ndSlip;
  v30 = *v29;
  v31 = &v28->tyres[0].status.ndSlip;
  v111.value = v30;
  if ( !v24 )
    v31 = &v28->tyres[1].status.ndSlip;
  v108 = v30;
  v32 = v28->tyres[0].status.load > 0.0;
  v33 = *v31;
  radius = v33;
  v110 = v33;
  if ( !v32 && v28->tyres[1].status.load <= 0.0 )
  {
    v33 = FLOAT_1_0;
    radius = FLOAT_1_0;
    v110 = FLOAT_1_0;
  }
  if ( v28->tyres[2].status.load <= 0.0 && v28->tyres[3].status.load <= 0.0 )
  {
    v30 = FLOAT_1_0;
    v111.value = FLOAT_1_0;
    v108 = FLOAT_1_0;
  }
  v34 = &v108;
  v35 = &this->targetSpeed;
  if ( v30 <= v33 )
    v34 = &v110;
  if ( result.isPitlane )
  {
    v36 = *v35;
    v37 = &v106;
    v106 = 22.222223;
    if ( v36 <= 22.222223 )
      v37 = &this->targetSpeed;
    *v35 = *v37;
  }
  if ( this->pitLaneStartFlag )
    *v35 = (float)((float)((float)(1.0 - COERCE_FLOAT(LODWORD(this->steerRequest) & _xmm)) * 40.0) + 20.0) * v22;
  v38 = v28->ksPhysics;
  v39 = (__m128d)_mm_loadu_si128((const __m128i *)&v38->sessionInfo);
  v40 = this->reactionTime + _mm_unpackhi_pd(v39, v39).m128d_f64[0];
  *(__m128i *)&v113.distFromCorner = _mm_loadu_si128((const __m128i *)&v38->sessionInfo.timeSecs);
  if ( v38->physicsTime <= v40 || this->timeToStart > 0.0 )
  {
    v28->isRetired = 0;
    this->avgSpeed = DOUBLE_1000_0;
    AIDriver::stepGasBrakeStart(this);
    AIDriver::updateTyres(this);
    return;
  }
  v41 = RaceEngineer::getOptimalBrake(&this->engineer);
  v42 = this->humanize.brakeMistakeTime;
  v106 = v41 * 0.99000001;
  if ( v42 <= 0.0 || this->useAbs )
    v43 = v106;
  else
    v43 = v106 * 2.0;
  v106 = v43;
  v44 = FLOAT_1_0;
  normalizedPos = AIDriver::getLABraking(this);
  v45 = normalizedPos;
  if ( normalizedPos > 1.0 || (v44 = 0.0, normalizedPos < 0.0) )
    v45 = v44;
  normalizedPos = v45 * v106;
  v109.value = v45 * v106;
  this->brakeRequest = v45 * v106;
  v46 = RaceEngineer::getTorqueToGripRatio(&this->engineer);
  v47 = this->brakePoint.targetSpeed;
  v105 = v46;
  if ( v47 > 0.0 )
  {
    v48 = (AIBrakePointData *)&this->targetSpeed;
    if ( this->targetSpeed > this->brakePoint.targetSpeed )
      v48 = &this->brakePoint;
    this->targetSpeed = v48->targetSpeed;
  }
  v49 = this->car;
  this->understeerFactor = radius - v111.value;
  if ( (float)(Car::getSpeed(v49, &v111)->value * 3.5999999) <= 30.0 )
  {
    v51 = &this->targetSpeed;
  }
  else
  {
    v50 = this->understeerHint * *v34;
    v51 = &this->targetSpeed;
    if ( v50 > 1.0 && this->understeerFactor > 0.0 && *v51 > speed )
    {
      v112 = 1;
      goto LABEL_56;
    }
  }
  v112 = 0;
LABEL_56:
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v111);
  if ( v112 )
  {
    v52 = Car::getSpeed(this->car, &v111);
    v53 = this->understeerFactor;
    if ( v53 <= 1.0 )
    {
      if ( v53 < 0.0 )
        v53 = 0.0;
    }
    else
    {
      v53 = FLOAT_1_0;
    }
    v54 = 1.0 - (float)((float)(v53 * 0.2) * this->understeerHint);
    if ( v54 <= 1.0 )
    {
      if ( v54 < 0.0 )
        v54 = 0.0;
    }
    else
    {
      v54 = FLOAT_1_0;
    }
    *v51 = v54 * v52->value;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v111);
  }
  else
  {
    this->understeerFactor = 0.0;
  }
  v55 = &v111;
  v56 = *v51;
  v111.value = speed + 15.0;
  v57 = 1.0 / v105;
  if ( v56 <= (float)(speed + 15.0) )
    v55 = (Speed *)v51;
  v58 = v55->value;
  *v51 = v55->value;
  v59 = (float)((float)(v57 * 0.60000002) * (float)(v58 - speed)) + v102[0];
  v110 = v59;
  if ( v59 <= 1.0 )
  {
    if ( v59 >= 0.0 )
      goto LABEL_74;
    v59 = 0.0;
  }
  else
  {
    v59 = FLOAT_1_0;
  }
  v110 = v59;
LABEL_74:
  v60 = this->brakePoint.targetSpeed;
  v108 = v59;
  if ( v60 > 0.0 )
  {
    v59 = 0.0;
    v110 = 0.0;
    v108 = 0.0;
  }
  if ( normalizedPos > 0.0 )
  {
    v59 = v59 - (float)(normalizedPos * 4.0);
    v110 = v59;
    if ( v59 <= 1.0 )
    {
      if ( v59 >= 0.0 )
      {
LABEL_82:
        v108 = v59;
        goto LABEL_83;
      }
      v59 = 0.0;
    }
    else
    {
      v59 = FLOAT_1_0;
    }
    v110 = v59;
    goto LABEL_82;
  }
LABEL_83:
  v61 = this->nextCarModifier;
  if ( v61 != 0.0 )
  {
    if ( v59 <= 0.0 || normalizedPos >= 0.0099999998 )
    {
      v110 = 0.0;
      v108 = 0.0;
      if ( v61 <= 1.0 )
      {
        if ( v61 < 0.0 )
          v61 = 0.0;
      }
      else
      {
        v61 = FLOAT_1_0;
      }
      v63 = (Speed *)&v105;
      v105 = v61 * v106;
      if ( (float)(v61 * v106) <= normalizedPos )
        v63 = &v109;
      normalizedPos = v63->value;
    }
    else
    {
      v62 = v59 - v61;
      v110 = v62;
      if ( v62 <= 1.0 )
      {
        if ( v62 >= 0.0 )
        {
          v108 = v62;
        }
        else
        {
          v110 = 0.0;
          v108 = 0.0;
        }
      }
      else
      {
        v110 = FLOAT_1_0;
        v108 = FLOAT_1_0;
      }
    }
  }
  if ( this->splineSelection == FastLane )
  {
    v64 = this->car;
    v65 = v64->carHalfWidth * 2.0;
    if ( COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm) > (float)(v64->splineLocatorData.lateralOffset + v65)
      || (float)(v64->splineLocatorData.lateralOffset - v65) > result.sides[1] )
    {
      v66 = v64->body;
      LODWORD(v105) = LODWORD(result.forwardVector.x) ^ _xmm;
      v67 = v66->__vftable;
      LODWORD(v109.value) = (Speed)(LODWORD(result.forwardVector.y) ^ _xmm);
      v68 = v67->getWorldMatrix;
      LODWORD(v111.value) = (Speed)(LODWORD(result.forwardVector.z) ^ _xmm);
      v69 = (_DWORD *)((int (__stdcall *)(float *, _DWORD))v68)(&v113.direction, 0);
      LODWORD(v70) = v69[8] ^ _xmm;
      v71 = v69[10];
      LODWORD(v72) = v69[9] ^ _xmm;
      v73 = &v109;
      v74 = v70 * v105;
      v105 = 0.0;
      v75 = (float)((float)(v72 * v109.value) + v74) + (float)(COERCE_FLOAT(v71 ^ _xmm) * v111.value);
      v76 = *v51;
      v109.value = v75;
      if ( v75 <= 0.0 )
        v73 = (Speed *)&v105;
      v77 = v73->value;
      v78 = &v109;
      v109.value = (float)(v77 * 10.0) + 20.0;
      if ( v76 <= v109.value )
        v78 = (Speed *)v51;
      *v51 = v78->value;
      v79 = this->car;
      v80 = v79->splineLocatorData.lateralOffset;
      if ( v80 >= 0.0 )
        v81 = (float)(v80 - (float)(v79->carHalfWidth * 2.0)) - result.sides[1];
      else
        v81 = (float)(v79->carHalfWidth * 2.0) - (float)(v80 + result.sides[0]);
      if ( v81 < 12.0 )
      {
        v109.value = AIDriver::getClosestFollowingCarTTI(this);
        if ( v109.value < 5.0 )
        {
          *v51 = 0.0;
          this->avgSpeed = DOUBLE_20_0;
        }
      }
      if ( speed <= *v51 )
      {
        v82 = FLOAT_0_2;
        normalizedPos = 0.0;
      }
      else
      {
        normalizedPos = FLOAT_1_0;
        v82 = 0.0;
      }
      v108 = v82;
      v110 = v82;
    }
  }
  v83 = this->car;
  v84 = Drivetrain::getEngineRPM(&v83->drivetrain);
  v85 = v83->drivetrain.acEngine.rpmDamageThreshold * 0.99000001;
  v109.value = v84;
  if ( v109.value < v85 )
  {
    if ( v110 <= 0.0 )
    {
LABEL_121:
      v83->tyres[0].aiMult = this->ultraGrip;
      this->car->tyres[1].aiMult = this->ultraGrip;
      this->car->tyres[2].aiMult = this->ultraGrip;
      this->car->tyres[3].aiMult = this->ultraGrip;
      goto LABEL_122;
    }
  }
  else
  {
    v110 = FLOAT_0_5;
    v108 = FLOAT_0_5;
  }
  if ( normalizedPos != 0.0 || this->isEngaged )
    goto LABEL_121;
  v83->tyres[0].aiMult = 1.001;
  this->car->tyres[1].aiMult = 1.001;
  this->car->tyres[2].aiMult = 1.001;
  this->car->tyres[3].aiMult = 1.001;
LABEL_122:
  if ( !this->raceStartFlag )
  {
    v86 = this->car;
    if ( v86->drivetrain.autoCutOffTime <= 0.0 && Drivetrain::isChangingGear(&v86->drivetrain) && this->isChangingUp )
    {
      v110 = 0.0;
      v108 = 0.0;
    }
  }
  if ( (float)(Car::getSpeed(this->car, &v109)->value * 3.5999999) <= 10.0
    || (v87 = this->car, v87->autoClutch.clutchSequence.isDone)
    || (v24 = v87->controls.clutch >= 0.89999998, v112 = 1, v24) )
  {
    v112 = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v109);
  if ( v112 )
  {
    v88 = (Speed *)&v108;
    v109.value = this->car->controls.clutch;
    if ( v109.value <= v110 )
      v88 = &v109;
    v110 = v88->value;
    v108 = v110;
  }
  v89 = this->car;
  this->isRetiring = 0;
  if ( (float)v89->drivetrain.acEngine.lifeLeft <= 0.0 )
  {
    v110 = 0.0;
    v108 = 0.0;
    normalizedPos = FLOAT_0_30000001;
    v112 = (float)(Car::getSpeed(v89, &v109)->value * 3.5999999) < 50.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v109);
    if ( v112 )
    {
      if ( result.sides[1] <= result.sides[0] )
        this->currentOffset = result.sides[1] + 4.0;
      else
        this->currentOffset = COERCE_FLOAT(LODWORD(result.sides[0]) ^ _xmm) - 4.0;
      if ( COERCE_FLOAT(LODWORD(this->steerRequest) & _xmm) >= 0.1 )
        v90 = 0.0;
      else
        v90 = FLOAT_0_2;
      normalizedPos = v90;
      this->isRetiring = 1;
    }
  }
  for ( i = 0; i < 4; ++i )
  {
    v92 = this->car->suspensions._Myfirst[i];
    v109.value = v92->getDamage(v92);
    if ( v109.value > 0.30000001 )
      this->isRetiring = 1;
  }
  v93 = &this->mongolinoMaxGas;
  this->brakeRequest = normalizedPos;
  v94 = this->basePush;
  if ( v94 >= 0.89999998 )
    *v93 = 1.0;
  else
    *v93 = 1.0 - (float)((float)(0.89999998 - v94) * 2.0);
  v109.value = v110;
  if ( __fdtest(&v109.value) <= 0 )
  {
    v95 = &v108;
    if ( *v93 <= v110 )
      v95 = &this->mongolinoMaxGas;
    this->gasRequest = *v95;
  }
  if ( this->humanize.tractionMistake > 0.0 )
  {
    v96 = this->humanize.tractioMistakeSeverity * this->gasRequest;
    v97 = FLOAT_1_0;
    if ( v96 <= 1.0 )
    {
      if ( v96 < 0.0 )
      {
        this->gasRequest = 0.0;
        return;
      }
      v97 = this->humanize.tractioMistakeSeverity * this->gasRequest;
    }
    this->gasRequest = v97;
  }
}
void AIDriver::stepGasBrakeStart(AIDriver *this)
{
  Car *v2; // ecx
  PhysicsEngine *v3; // eax
  __m128i v4; // xmm1
  __m128d v5; // xmm2
  float v6; // xmm0_4
  float v7; // xmm1_4
  InterpolatingSpline *v8; // ecx
  bool v9; // zf
  float pos; // [esp+0h] [ebp-44h]
  float v11; // [esp+8h] [ebp-3Ch]
  vec3f result; // [esp+Ch] [ebp-38h] BYREF
  float v13[3]; // [esp+18h] [ebp-2Ch] BYREF
  __m128d v14; // [esp+24h] [ebp-20h]
  __m128i v15; // [esp+34h] [ebp-10h]

  v2 = this->car;
  v3 = v2->ksPhysics;
  v4 = _mm_loadu_si128((const __m128i *)&v3->sessionInfo);
  v5 = _mm_unpackhi_pd((__m128d)v4, (__m128d)v4);
  v5.m128d_f64[0] = v5.m128d_f64[0] - v3->physicsTime;
  v15 = _mm_loadu_si128((const __m128i *)&v3->sessionInfo.timeSecs);
  this->gasRequest = 0.0;
  v14 = v5;
  if ( _mm_cvtsi128_si32(v4) == 3 && v5.m128d_f64[0] > -1000.0 )
  {
    if ( this->timeToStartRevvingAtStart > v5.m128d_f64[0] )
    {
      v6 = FLOAT_1_0;
      v11 = (this->changeUpRPM - Drivetrain::getEngineRPM(&v2->drivetrain)) * 0.001;
      v7 = v11 + this->gasRequest;
      this->gasRequest = v7;
      if ( v7 <= 1.0 )
      {
        v6 = 0.0;
        if ( v7 >= 0.0 )
          v6 = v7;
      }
      v5.m128d_f64[0] = v14.m128d_f64[0];
      this->gasRequest = v6;
      this->raceStartFlag = 1;
    }
    if ( this->reactionTime + v5.m128d_f64[0] < 80.0 )
      this->gasRequest = 1.0;
    if ( v5.m128d_f64[0] < 1000.0 && v5.m128d_f64[0] > 500.0 )
      this->reactionTime = (float)((float)((float)((float)_rand() * 0.000030518509) * 350.0) + 50.0);
  }
  pos = this->locNpos;
  v8 = &this->currentSpline->spline;
  this->brakeRequest = 0.85000002;
  InterpolatingSpline::splineToWorld(v8, &result, pos);
  this->car->body->worldToLocal(this->car->body, (vec3f *)v13, &result);
  v9 = this->splineSelection == Pits;
  this->currentOffset = v13[0];
  if ( v9 )
    this->currentOffset = 0.0;
}
void AIDriver::stepGears(AIDriver *this, float dt, CarControls *controls)
{
  Car *v4; // ebx
  PhysicsEngine *v5; // eax
  long double v6; // xmm1_8
  double v7; // xmm0_8
  Drivetrain *v8; // ebx
  double v9; // st7
  Car *v10; // edx
  bool v11; // zf
  float *v12; // ecx
  float *v13; // ecx
  Speed *v15; // eax
  char v16; // cl
  Car *v17; // eax
  double v18; // xmm1_8
  Car *v19; // eax
  float v20; // xmm1_4
  Car *v21; // eax
  Car *v22; // eax
  float v23; // [esp+Ch] [ebp-2Ch]
  Speed result; // [esp+10h] [ebp-28h] BYREF
  float slip; // [esp+14h] [ebp-24h]
  __m128i v26; // [esp+28h] [ebp-10h]
  char controlsa; // [esp+40h] [ebp+8h]
  float controlsc; // [esp+40h] [ebp+8h]
  char controlsb; // [esp+40h] [ebp+8h]

  v4 = this->car;
  v5 = v4->ksPhysics;
  v6 = this->reactionTime + v5->sessionInfo.startTimeMS;
  v26 = _mm_loadu_si128((const __m128i *)&v5->sessionInfo.timeSecs);
  if ( v5->physicsTime <= v6 )
  {
    *(_WORD *)&controls->gearUp = 0;
    return;
  }
  v7 = v4->drivetrain.engine.velocity;
  v8 = &v4->drivetrain;
  v9 = RaceEngineer::getDrivingTyresSlip(&this->engineer);
  v10 = this->car;
  v11 = v10->drivetrain.tractionType == FWD;
  slip = v9;
  if ( v11 )
  {
    v12 = &v10->tyres[0].status.slipRatio;
    if ( v10->tyres[1].status.slipRatio > v10->tyres[0].status.slipRatio )
      v12 = &v10->tyres[1].status.slipRatio;
    v23 = *v12;
  }
  else
  {
    v13 = &v10->tyres[3].status.slipRatio;
    if ( v10->tyres[2].status.slipRatio > v10->tyres[3].status.slipRatio )
      v13 = &v10->tyres[2].status.slipRatio;
    v23 = *v13;
  }
  if ( (float)(int)(v7 * 0.1591550715257987 * 60.0) <= this->changeUpRPM
    || controls->gearUp
    || v10->drivetrain.cutOff > 0.0
    || Drivetrain::isChangingGear(v8) )
  {
    v16 = 0;
LABEL_22:
    controlsa = 0;
    goto LABEL_23;
  }
  v15 = Car::getSpeed(this->car, &result);
  v16 = 1;
  if ( v15->value >= 1.0 && v23 >= 1.0 )
    goto LABEL_22;
  v17 = this->car;
  if ( v17->controls.clutch <= 0.99000001 && v8->currentGear != 1 )
    goto LABEL_22;
  v18 = v17->ksPhysics->physicsTime;
  if ( v18 - this->lastGearDNChangeTime <= 1000.0 || v18 - this->lastGearUPChangeTime <= 1000.0 )
    goto LABEL_22;
  controlsa = 1;
LABEL_23:
  if ( (v16 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( controlsa )
  {
    *(_WORD *)&controls->gearUp = 1;
    v19 = this->car;
    this->isChangingUp = 1;
    this->lastGearUPChangeTime = v19->ksPhysics->physicsTime;
  }
  else
  {
    controls->gearUp = 0;
    controlsc = Drivetrain::projectRPMAtDownshift(v8);
    v20 = controlsc;
    this->prjDNRPM = controlsc;
    if ( controlsc <= 0.0 || (controlsb = 1, (float)(this->changeDnPerc * this->changeUpRPM) <= v20) )
      controlsb = 0;
    if ( Drivetrain::isChangingGear(v8)
      || (v21 = this->car, v21->controls.clutch <= 0.98000002)
      || !controlsb
      || v8->currentGear <= 2
      || slip >= 1.7
      || v21->ksPhysics->physicsTime - this->lastGearUPChangeTime <= 1000.0 )
    {
      controls->gearDn = 0;
    }
    else
    {
      controls->gearDn = 1;
      v22 = this->car;
      this->isChangingUp = 0;
      this->lastGearDNChangeTime = v22->ksPhysics->physicsTime;
    }
  }
}
void AIDriver::stepHumanizer(AIDriver *this, float dt)
{
  Car *v3; // eax
  int v4; // eax
  float v5; // xmm0_4
  Car *v6; // eax
  float v7; // xmm0_4

  v3 = this->car;
  if ( v3->physicsGUID )
  {
    if ( v3->ksPhysics->physicsTime > this->humanize.nextBrakeMistake )
    {
      v4 = _rand();
      this->humanize.nextBrakeMistake = 0.0;
      this->humanize.brakeMistakeTime = (float)((float)v4 * 0.000030518509) * 2.0;
    }
    if ( this->car->ksPhysics->physicsTime > this->humanize.nextTractionMistake )
    {
      this->humanize.tractionMistake = 0.0;
      this->humanize.nextTractionMistake = 0.0;
    }
    if ( this->humanize.nextBrakeMistake == 0.0 )
      this->humanize.nextBrakeMistake = (float)((float)_rand() * 0.000030518509) * this->humanize.timeBetweenMistakesMS
                                      + this->car->ksPhysics->physicsTime
                                      + this->humanize.minTimeBetweenMistakesMS;
    if ( this->humanize.nextTractionMistake == 0.0 )
    {
      this->humanize.nextTractionMistake = (float)((float)_rand() * 0.000030518509)
                                         * this->humanize.timeBetweenMistakesMS
                                         + this->car->ksPhysics->physicsTime
                                         + this->humanize.minTimeBetweenMistakesMS;
      this->humanize.tractioMistakeSeverity = (float)((float)((float)_rand() * 0.000030518509) * 0.5) + 1.0;
    }
    v5 = this->humanize.tractionMistake;
    if ( v5 >= 0.0 )
    {
      v6 = this->car;
      this->humanize.tractionMistake = v5 - dt;
      v6->stabilityControl.gain = 0.0;
    }
    v7 = this->humanize.brakeMistakeTime;
    if ( v7 >= 0.0 )
      this->humanize.brakeMistakeTime = v7 - dt;
  }
}
void AIDriver::stepP2P(AIDriver *this, float dt)
{
  float v3; // xmm1_4
  const __m128i *v4; // eax
  float v5; // xmm1_4
  AISplineRecorder *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  AISpline *v10; // eax
  int v11; // eax
  Car *normalizedPos; // [esp+0h] [ebp-30h]
  Speed result; // [esp+Ch] [ebp-24h] BYREF
  __m128i v14; // [esp+10h] [ebp-20h]

  v3 = Car::getSpeed(this->car, &result)->value * 3.5999999;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v3 >= 50.0 )
  {
    normalizedPos = this->car;
    v4 = (const __m128i *)normalizedPos->ksPhysics;
    v5 = (float)normalizedPos->drivetrain.acEngine.p2p.activations;
    v14 = _mm_loadu_si128(v4 + 17);
    v6 = this->aiSplineRecorder;
    v7 = (float)(_mm_cvtsi128_si32(_mm_srli_si128(_mm_loadu_si128(v4 + 18), 8)) - normalizedPos->transponder.lapCount);
    v8 = v5 / v7;
    v9 = this->locNpos;
    result.value = v8;
    v10 = AISplineRecorder::getBestLapSpline(v6);
    v11 = AISpline::isInStraight(v10, v9);
    if ( v11 != -1 && result.value > (float)v11 )
      this->car->controls.kers = 1;
  }
}
void AIDriver::stepPitLaneMode(AIDriver *this, float dt)
{
  int v3; // ebx
  double v4; // xmm0_8
  Car *v5; // eax
  float v6; // xmm0_4
  PhysicsEngine *v7; // edi
  Car **v8; // esi
  Car **i; // edi
  float v10; // xmm0_4
  float v11; // xmm0_4
  Car *v12; // ecx
  char v13; // [esp+17h] [ebp-21h]
  Car *car; // [esp+18h] [ebp-20h]
  float v15; // [esp+20h] [ebp-18h]
  Speed v16; // [esp+24h] [ebp-14h] BYREF
  Speed result; // [esp+28h] [ebp-10h] BYREF
  int v18; // [esp+34h] [ebp-4h]

  v3 = 0;
  if ( this->splineSelection == Pits )
  {
    v4 = this->timeToStart;
    if ( v4 > 0.0 && v4 < 1.0 )
    {
      if ( this->currentSessionInfo.type != Race )
      {
        v5 = this->car;
        v6 = (float)v5->transponder.bestLap;
        if ( v5->ksPhysics->physicsTime > *(double *)_mm_loadu_si128((const __m128i *)&v5->ksPhysics->sessionInfo.timeSecs).m128i_i64
                                        * 1000.0
                                        + v5->ksPhysics->sessionInfo.startTimeMS
                                        - (float)(v6 * 1.2) )
          this->timeToStart = DOUBLE_100_0;
      }
      v7 = this->car->ksPhysics;
      v8 = v7->cars._Myfirst;
      for ( i = v7->cars._Mylast; v8 != i; ++v8 )
      {
        car = *v8;
        if ( *v8 != this->car )
        {
          v3 |= 1u;
          v10 = Car::getSpeed(*v8, &result)->value * 3.5999999;
          v18 = 0;
          if ( v10 <= 2.0
            || !Car::isInPitLane(car)
            || (v11 = Car::getSpeed(car, &v16)->value,
                v3 |= 2u,
                v12 = this->car,
                v18 = 1,
                v13 = 1,
                v15 = Car::getBackDistanceFromCar(v12, car) / v11,
                v15 >= 10.0) )
          {
            v13 = 0;
          }
          v18 = 0;
          if ( (v3 & 2) != 0 )
          {
            v3 &= 0xFFFFFFFD;
            dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v16);
          }
          v18 = -1;
          if ( (v3 & 1) != 0 )
          {
            v3 &= 0xFFFFFFFE;
            dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
          }
          if ( v13 )
            this->timeToStart = this->timeToStart + 1.0;
        }
      }
    }
  }
}
void AIDriver::stepPushVariations(AIDriver *this, float dt)
{
  int v3; // eax
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm2_4

  if ( this->aiVariation.accum > this->aiVariation.variationTime )
  {
    this->aiVariation.startPush = this->aiVariation.currentPush;
    this->aiVariation.targetPush = this->basePush
                                 + (float)((float)((float)((float)_rand() * 0.000030518509) * 0.079999998) - 0.039999999);
    v3 = _rand();
    this->aiVariation.accum = 0.0;
    this->aiVariation.variationTime = (float)((float)((float)v3 * 0.000030518509) * 570.0) + 30.0;
  }
  v4 = this->aiVariation.accum;
  v5 = FLOAT_1_0;
  v6 = (float)((float)(this->aiVariation.targetPush - this->aiVariation.startPush)
             * (float)(v4 / this->aiVariation.variationTime))
     + this->aiVariation.startPush;
  if ( v6 <= 1.0 )
  {
    v5 = 0.0;
    if ( v6 >= 0.0 )
      v5 = (float)((float)(this->aiVariation.targetPush - this->aiVariation.startPush)
                 * (float)(this->aiVariation.accum / this->aiVariation.variationTime))
         + this->aiVariation.startPush;
  }
  this->aiVariation.currentPush = v5;
  this->aiVariation.accum = v4 + dt;
}
void AIDriver::stepSetup(AIDriver *this, float dt)
{
  Car *v3; // ecx
  float *v4; // eax
  float *v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // [esp+14h] [ebp-4h]

  v3 = this->car;
  if ( v3->ksPhysics->physicsTime - this->aiSetup.lastSetupChangeTime >= 10000.0 )
  {
    if ( this->aiSetup.finalRatio )
    {
      if ( v3->drivetrain.currentGear == v3->drivetrain.gears._Mylast - v3->drivetrain.gears._Myfirst - 1
        && v3->drivetrain.acEngine.isLimiterOn(&v3->drivetrain.acEngine) )
      {
        v4 = this->aiSetup.ratios._Myfirst;
        v5 = this->aiSetup.ratios._Mylast;
        if ( v4 != v5 )
        {
          v6 = this->car->drivetrain.finalRatio;
          while ( 1 )
          {
            v7 = *v4;
            v8 = *v4;
            if ( v6 > *v4 )
              break;
            if ( ++v4 == v5 )
              goto LABEL_12;
          }
          if ( v7 > 0.0 )
          {
            _printf("AI increasing final ratio %f -> %f\n", v6, v7);
            this->aiSetup.finalRatio->newValue = v8;
            this->aiSetup.lastSetupChangeTime = this->car->ksPhysics->physicsTime;
          }
        }
      }
    }
LABEL_12:
    this->car->brakeSystem.brakePowerMultiplier = 1.0;
  }
}
void AIDriver::stepSplineSelection(AIDriver *this, float dt)
{
  SplineSelection v3; // eax
  AISplineRecorder *v4; // ecx
  AISpline *v5; // eax
  bool v6; // zf
  AISpline *v7; // eax
  Car *v8; // ecx
  InterpolatingSpline *v9; // esi
  float v10; // xmm1_4
  float v11; // xmm2_4
  const vec3f *v12; // eax
  Car *v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  const vec3f *v16; // eax
  const vec3f *v17; // eax
  float v18; // xmm2_4
  Car *v19; // ecx
  float v20; // xmm2_4
  float v21; // xmm0_4
  Car *v22; // ecx
  float v23; // xmm1_4
  float v24; // xmm2_4
  int v25; // esi
  float v26; // xmm0_4
  AISplineRecorder *v27; // ecx
  AISpline *v28; // eax
  Car *v29; // ecx
  AISpline *v30; // eax
  AISplineRecorder *v31; // ecx
  AISpline *v32; // esi
  float *v33; // edi
  vec3f *v34; // eax
  float v35; // xmm2_4
  float v36; // xmm0_4
  AISpline *v37; // eax
  const vec3f *v; // [esp+10h] [ebp-74h]
  float v39; // [esp+1Ch] [ebp-68h]
  float v40; // [esp+20h] [ebp-64h]
  float v41; // [esp+20h] [ebp-64h]
  vec3f point; // [esp+24h] [ebp-60h] BYREF
  vec3f pos; // [esp+30h] [ebp-54h] BYREF
  vec3f ihed; // [esp+3Ch] [ebp-48h] BYREF
  vec3f v45; // [esp+48h] [ebp-3Ch] BYREF
  char v46[12]; // [esp+54h] [ebp-30h] BYREF
  char v47[12]; // [esp+60h] [ebp-24h] BYREF
  char v48[12]; // [esp+6Ch] [ebp-18h] BYREF
  vec3f result; // [esp+78h] [ebp-Ch] BYREF

  v3 = this->splineSelection;
  if ( v3 )
  {
    if ( v3 == Pits )
    {
      v4 = this->aiSplineRecorder;
      this->currentOffset = 0.0;
      v5 = AISplineRecorder::getPitLaneSpline(v4);
      v6 = !this->requestPitStop;
      this->currentSpline = v5;
      if ( v6 )
        goto LABEL_10;
      v7 = AISplineRecorder::getPitLaneSpline(this->aiSplineRecorder);
      v8 = this->car;
      v9 = &v7->spline;
      v10 = v8->pitPosition.M42;
      v11 = v8->pitPosition.M43;
      point.x = v8->pitPosition.M41;
      point.y = v10;
      point.z = v11;
      v12 = InterpolatingSpline::closestPointIndex(&v7->spline, &point, 0);
      v13 = this->car;
      v14 = v13->pitPosition.M42;
      v15 = v13->pitPosition.M43;
      pos.x = v13->pitPosition.M41;
      pos.y = v14;
      pos.z = v15;
      v39 = InterpolatingSpline::worldToSpline(v9, &pos, (int)v12);
      v16 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getPosition)(
                             this->car->body,
                             v46,
                             0);
      v = InterpolatingSpline::closestPointIndex(v9, v16, 0);
      v17 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getPosition)(
                             this->car->body,
                             v47,
                             0);
      v40 = InterpolatingSpline::worldToSpline(v9, v17, (int)v);
      v18 = v40;
      v41 = Spline::length(&this->currentSpline->spline) * (float)(v39 - v40);
      if ( v41 < 20.0 )
        this->isSteeringToPit = 1;
      if ( v18 <= v39 )
      {
LABEL_10:
        v26 = this->locNpos;
        if ( v26 <= 0.0 || (v27 = this->aiSplineRecorder, v26 < v27->pitLaneSplineAttachPoint) )
        {
          this->currentSpline = AISplineRecorder::getPitLaneSpline(this->aiSplineRecorder);
        }
        else
        {
          this->brakePoint.targetSpeed = -1.0;
          this->splineSelection = FastLane;
          v28 = AISplineRecorder::getBestLapSpline(v27);
          v29 = this->car;
          this->currentSpline = v28;
          Car::resetSplineLocator(v29);
        }
      }
      else
      {
        v19 = this->car;
        LODWORD(v20) = LODWORD(v19->pitPosition.M33) ^ _xmm;
        LODWORD(v21) = LODWORD(v19->pitPosition.M31) ^ _xmm;
        LODWORD(ihed.y) = LODWORD(v19->pitPosition.M32) ^ _xmm;
        ihed.x = v21;
        ihed.z = v20;
        Car::forceRotation(v19, &ihed);
        v22 = this->car;
        v23 = v22->pitPosition.M42;
        v24 = v22->pitPosition.M43;
        v45.x = v22->pitPosition.M41;
        v45.y = v23;
        v45.z = v24;
        Car::forcePosition(v22, &v45, 0);
        Car::setDamageLevel(this->car, 0.0);
        Car::resetSuspensionDamageLevel(this->car);
        AIDriver::generatePitlaneWait(this);
        this->requestPitStop = 0;
        v25 = 0;
        this->isSteeringToPit = 0;
        do
        {
          Tyre::setCompound(&this->car->tyres[v25], this->car->tyres[v25].currentCompoundIndex);
          ++v25;
        }
        while ( v25 < 4 );
      }
    }
  }
  else
  {
    v30 = AISplineRecorder::getBestLapSpline(this->aiSplineRecorder);
    v6 = !this->requestPitStop;
    v31 = this->aiSplineRecorder;
    this->currentSpline = v30;
    if ( v6
      || (v32 = AISplineRecorder::getPitLaneSpline(v31),
          v33 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getPosition)(
                           this->car->body,
                           v48,
                           0),
          v34 = Spline::pointAt(&v32->spline, &result, 0),
          v31 = this->aiSplineRecorder,
          v35 = v34->y - v33[1],
          v36 = v34->z - v33[2],
          (float)((float)((float)(v35 * v35) + (float)((float)(v34->x - *v33) * (float)(v34->x - *v33)))
                + (float)(v36 * v36)) >= 25.0) )
    {
      this->currentSpline = AISplineRecorder::getBestLapSpline(v31);
    }
    else
    {
      v37 = AISplineRecorder::getPitLaneSpline(v31);
      this->splineSelection = Pits;
      this->currentSpline = v37;
    }
  }
}
void AIDriver::stepSteer(AIDriver *this, float dt)
{
  Speed *v3; // eax
  double v4; // st7
  bool v5; // zf
  float v6; // xmm0_4
  float v7; // xmm3_4
  float *v8; // eax
  PhysicsEngine *v9; // eax
  long double v10; // xmm1_8
  float v11; // xmm0_4
  float v12; // xmm0_4
  Car *v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  char v21[40]; // [esp+1Ch] [ebp-A4h] BYREF
  _QWORD v22[3]; // [esp+44h] [ebp-7Ch]
  AISplinePayload payload; // [esp+5Ch] [ebp-64h] BYREF
  float v24; // [esp+B0h] [ebp-10h]
  float Px; // [esp+B4h] [ebp-Ch] BYREF
  bool v26; // [esp+BBh] [ebp-5h]
  Speed result; // [esp+BCh] [ebp-4h] BYREF
  float dta; // [esp+C4h] [ebp+4h]
  bool dt_3; // [esp+C7h] [ebp+7h]

  v26 = (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) < 5.0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v26 )
    PIDController::reset(&this->pidSteer);
  v3 = Car::getSpeed(this->car, &result);
  Px = AIDriver::getLookAhead(this, this->steerMinLookahead, v3->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  AISplinePayload::AISplinePayload(&payload);
  v4 = AIDriver::getSteerAtDistance(this, Px, this->currentSpline, &payload, dt);
  v5 = this->splineSelection == Pits;
  v6 = this->steerGain * 0.27000001;
  result.value = v4;
  v7 = result.value;
  this->targetSteerFinal = result.value;
  this->pidSteer.P = v6;
  if ( v5 )
  {
    if ( !this->pitLaneStartFlag )
      goto LABEL_11;
    this->pidSteer.P = v6;
    if ( COERCE_FLOAT(LODWORD(v7) & _xmm) < 1.0 )
    {
      v8 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getWorldMatrix)(
                      this->car->body,
                      v21,
                      0);
      v7 = result.value;
      if ( (float)((float)((float)(payload.forwardVector.x * v8[8]) + (float)(payload.forwardVector.y * v8[9]))
                 + (float)(payload.forwardVector.z * v8[10])) > 0.85000002 )
        this->pitLaneStartFlag = 0;
    }
  }
  if ( this->pitLaneStartFlag && this->splineSelection != Pits )
    this->pitLaneStartFlag = 0;
LABEL_11:
  v9 = this->car->ksPhysics;
  v10 = this->reactionTime + v9->sessionInfo.startTimeMS;
  *(__m128i *)&v22[1] = _mm_loadu_si128((const __m128i *)&v9->sessionInfo.timeSecs);
  if ( v9->physicsTime <= v10 || this->timeToStart > 0.0 )
  {
    this->steerRequest = 0.0;
    this->oldSteer = 0.0;
    return;
  }
  dta = PIDController::eval(&this->pidSteer, 0.0, v7, dt);
  result.value = dta;
  Px = dta;
  if ( __fdtest(&Px) <= 0 )
  {
    v11 = dta;
  }
  else
  {
    v11 = 0.0;
    result.value = 0.0;
  }
  if ( v11 > 0.89999998 )
  {
    v12 = FLOAT_0_89999998;
LABEL_20:
    result.value = v12;
    goto LABEL_21;
  }
  if ( v11 < -0.89999998 )
  {
    v12 = FLOAT_N0_89999998;
    goto LABEL_20;
  }
LABEL_21:
  v13 = this->car;
  v14 = v13->tyres[0].status.slipAngleRAD;
  if ( v13->tyres[1].status.load > v13->tyres[0].status.load )
    v14 = v13->tyres[1].status.slipAngleRAD;
  v24 = v14 * 57.29578;
  dt_3 = (float)(Car::getSpeed(v13, (Speed *)&Px)->value * 3.5999999) > 30.0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&Px);
  if ( dt_3 )
  {
    v15 = this->oldSteer;
    v16 = 1.0 / this->car->steerLock;
    v17 = (float)((float)((float)(v24 - 10.0) * 12.0) * v16) + v15;
    v18 = (float)((float)((float)(v24 + 10.0) * 12.0) * v16) + v15;
  }
  else
  {
    v18 = FLOAT_0_89999998;
    v17 = FLOAT_N0_89999998;
  }
  v19 = result.value;
  v20 = this->steerRequest;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result.value - v20) & _xmm) > 0.40000001 )
  {
    if ( result.value <= v20 )
      v19 = v20 - 0.40000001;
    else
      v19 = v20 + 0.40000001;
  }
  if ( this->isReactingSlow )
  {
    v19 = (float)((float)(v19 - this->oldSteer) * 0.1) + this->oldSteer;
    this->steerRequest = v19;
  }
  if ( v19 <= v18 )
  {
    if ( v17 <= v19 )
      v18 = v19;
    else
      v18 = v17;
  }
  this->steerRequest = v18;
  this->oldSteer = this->steerRequest;
}
void AIDriver::stepSuperhuman(AIDriver *this, CarControls *controls, float dt)
{
  Car *v4; // esi
  int *v5; // edx
  float *v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  bool v10; // zf
  Car *v11; // eax
  float v12; // xmm1_4
  Car *v13; // eax
  Car *v14; // eax
  Car *v15; // eax
  Car *v16; // eax
  RaceEngineer *v17; // ecx
  float *v18; // edi
  Car *v19; // eax
  float v20; // xmm0_4
  float *v21; // eax
  float v22; // esi
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // eax
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  Car *v29; // ecx
  char v30; // al
  Speed *v31; // eax
  char v32; // cl
  double v33; // st7
  int v34; // eax
  AISpline *v35; // eax
  int v36; // edi
  double v37; // st7
  float v38; // xmm0_4
  double v39; // st7
  int v40; // eax
  CarControls *v41; // eax
  float v42; // [esp+8h] [ebp-2Ch] BYREF
  int v43; // [esp+Ch] [ebp-28h]
  float v44; // [esp+10h] [ebp-24h]
  Speed v45; // [esp+14h] [ebp-20h] BYREF
  Speed v46; // [esp+18h] [ebp-1Ch] BYREF
  int v47; // [esp+1Ch] [ebp-18h]
  Speed result; // [esp+20h] [ebp-14h] BYREF
  float v49; // [esp+24h] [ebp-10h]
  float v50; // [esp+28h] [ebp-Ch]
  float v51; // [esp+2Ch] [ebp-8h]
  bool v52; // [esp+33h] [ebp-1h]

  *(AIDriver **)&result.value = this;
  v47 = 0;
  v4 = this->car;
  v5 = (int *)&v4->tyres[0].status.ndSlip;
  v6 = &v4->tyres[2].status.ndSlip;
  if ( v4->tyres[1].status.ndSlip > v4->tyres[0].status.ndSlip )
    v5 = (int *)&v4->tyres[1].status.ndSlip;
  v7 = (float)(v4->tyres[1].status.load + v4->tyres[0].status.load) + v4->tyres[2].status.load;
  v49 = *(float *)v5;
  v8 = v7 + v4->tyres[3].status.load;
  if ( v4->tyres[3].status.ndSlip > *v6 )
    v6 = &v4->tyres[3].status.ndSlip;
  v9 = *v6;
  v4->tyres[0].absOverride = 1.0;
  v10 = !this->useAbs;
  v50 = v9;
  if ( v10 && this->humanize.brakeMistakeTime > 0.0 )
  {
    v12 = FLOAT_1_0;
  }
  else
  {
    v11 = this->car;
    v12 = FLOAT_1_0;
    if ( v11->tyres[0].status.ndSlip > 1.0
      && (v11->tyres[0].driven || (float)(v11->tyres[0].status.load / v8) > 0.050000001) )
    {
      v11->tyres[0].absOverride = 0.0;
    }
  }
  this->car->tyres[1].absOverride = 1.0;
  if ( this->useAbs || this->humanize.brakeMistakeTime <= 0.0 )
  {
    v13 = this->car;
    if ( v13->tyres[1].status.ndSlip > v12
      && (v13->tyres[1].driven || (float)(v13->tyres[1].status.load / v8) > 0.050000001) )
    {
      v13->tyres[1].absOverride = 0.0;
    }
  }
  this->car->tyres[2].absOverride = 1.0;
  if ( this->useAbs || this->humanize.brakeMistakeTime <= 0.0 )
  {
    v14 = this->car;
    if ( v14->tyres[2].status.ndSlip > v12
      && (v14->tyres[2].driven || (float)(v14->tyres[2].status.load / v8) > 0.050000001) )
    {
      v14->tyres[2].absOverride = 0.0;
    }
  }
  this->car->tyres[3].absOverride = 1.0;
  if ( this->useAbs || this->humanize.brakeMistakeTime <= 0.0 )
  {
    v15 = this->car;
    if ( v15->tyres[3].status.ndSlip > v12
      && (v15->tyres[3].driven || (float)(v15->tyres[3].status.load / v8) > 0.050000001) )
    {
      v15->tyres[3].absOverride = 0.0;
    }
  }
  v16 = RaceEngineer::getRightDrivenTyre(&this->engineer);
  v17 = &this->engineer;
  v18 = (float *)&v16->drivetrain.outShaftL.inertia + 1;
  v19 = RaceEngineer::getLeftDrivenTyre(v17);
  v20 = *v18;
  v21 = (float *)&v19->drivetrain.outShaftL.inertia + 1;
  v22 = result.value;
  v51 = FLOAT_1_0;
  v23 = *(_DWORD *)(LODWORD(result.value) + 416);
  if ( v20 > *v21 )
    v21 = v18;
  v24 = *v21;
  v25 = *(_DWORD *)(v23 + 1560);
  v45.value = v24;
  switch ( v25 )
  {
    case 0:
      v26 = v50;
      goto LABEL_36;
    case 1:
      goto $LN19_7;
    case 2:
    case 3:
      v26 = v50 * 1.2;
LABEL_36:
      if ( v26 > v49 )
$LN19_7:
        v51 = *(float *)(LODWORD(result.value) + 748);
      break;
    default:
      break;
  }
  v50 = FLOAT_0_2;
  v49 = Car::getSpeed((Car *)v23, &result)->value * 3.5999999;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v10 = *(_BYTE *)(LODWORD(v22) + 624) == 0;
  result.value = FLOAT_4_0;
  if ( !v10 )
  {
    v50 = FLOAT_0_5;
    v51 = v49 >= 20.0 ? FLOAT_4_0 : (float)((float)(20.0 - v49) * 10.0) + 4.0;
    v52 = (float)(Car::getSpeed(*(Car **)(LODWORD(v22) + 416), &v46)->value * 3.5999999) > 50.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v46);
    if ( v52 )
      *(_BYTE *)(LODWORD(v22) + 624) = 0;
  }
  if ( v45.value > v51 && (v49 > 5.0 || *(_DWORD *)(LODWORD(v22) + 96) == 1) )
  {
    v27 = FLOAT_1_0;
    if ( *(float *)(LODWORD(v22) + 148) <= 0.0 )
    {
      v28 = *(float *)(LODWORD(v22) + 504) * v50;
      if ( v28 <= 1.0 )
      {
        if ( v28 < 0.0 )
          v28 = 0.0;
        controls->gas = v28;
      }
      else
      {
        controls->gas = FLOAT_1_0;
      }
    }
  }
  else
  {
    v27 = FLOAT_1_0;
  }
  v29 = *(Car **)(LODWORD(v22) + 416);
  if ( v29->physicsGUID || *(_BYTE *)(LODWORD(v22) + 300) )
  {
    v30 = *(_BYTE *)(LODWORD(v22) + 760);
    v51 = FLOAT_2_0;
    if ( v30 )
      v50 = FLOAT_2_0;
    else
      v50 = v27;
    if ( v30 )
      result.value = FLOAT_6_0;
    v10 = *(_DWORD *)(LODWORD(v22) + 96) == 0;
    v49 = v29->splineLocatorData.lateralOffset
        - (float)(*(float *)(LODWORD(v22) + 520) + *(float *)(LODWORD(v22) + 364));
    if ( v10 && v29->ksPhysics->physicsTime - v29->lastCollisionTime > 1000.0 )
    {
      v31 = Car::getSpeed(v29, &v45);
      v32 = 1;
      if ( (float)(v31->value * 3.5999999) > 20.0 && result.value > COERCE_FLOAT(LODWORD(v49) & _xmm) )
      {
        v52 = 1;
LABEL_68:
        if ( (v32 & 1) != 0 )
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v45);
        if ( v52 )
        {
          Car::getSpeed(*(Car **)(LODWORD(v22) + 416), &v45);
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v45);
          if ( v49 <= 2.0 )
          {
            v51 = FLOAT_N2_0;
            if ( v49 >= -2.0 )
              v51 = v49;
          }
          v33 = ((double (*)(_DWORD))*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(LODWORD(v22) + 416) + 152) + 20))(*(_DWORD *)(*(_DWORD *)(LODWORD(v22) + 416) + 152));
          v34 = *(_DWORD *)(LODWORD(v22) + 416);
          v43 = 0;
          v44 = 0.0;
          v45.value = v51 * v50;
          v42 = v33 * (float)(v51 * v50);
          (*(void (**)(_DWORD, float *))(**(_DWORD **)(v34 + 152) + 108))(*(_DWORD *)(v34 + 152), &v42);
        }
        Car::getSpeed(*(Car **)(LODWORD(v22) + 416), &v45);
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v45);
        if ( !*(_DWORD *)(LODWORD(v22) + 96) && *(float *)(LODWORD(v22) + 36) > 0.0 )
        {
          v35 = AISplineRecorder::getBestLapSpline(*(AISplineRecorder **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v22) + 416)
                                                                                                + 168)
                                                                                    + 308)
                                                                        + 96));
          v36 = *(_DWORD *)(LODWORD(v22) + 416);
          v37 = Spline::length(&v35->spline);
          v45.value = *(float *)(LODWORD(v22) + 40) - *(float *)(v36 + 11008);
          v45.value = v37 * v45.value;
          if ( v45.value < 50.0 )
          {
            v38 = *(float *)(LODWORD(v22) + 56) * 0.30000001;
            if ( v38 <= 1.0 )
            {
              if ( v38 >= 0.0 )
                v51 = *(float *)(LODWORD(v22) + 56) * 0.30000001;
              else
                v51 = 0.0;
            }
            else
            {
              v51 = 1.0;
            }
            v39 = ((double (*)(_DWORD))*(_DWORD *)(**(_DWORD **)(v36 + 152) + 20))(*(_DWORD *)(v36 + 152));
            v40 = *(_DWORD *)(LODWORD(v22) + 416);
            v42 = 0.0;
            v43 = 0;
            v45.value = v39 * v51 * -5.0;
            v44 = v45.value;
            (*(void (**)(_DWORD, float *))(**(_DWORD **)(v40 + 152) + 108))(*(_DWORD *)(v40 + 152), &v42);
          }
        }
        goto LABEL_84;
      }
    }
    else
    {
      v32 = v47;
    }
    v52 = 0;
    goto LABEL_68;
  }
LABEL_84:
  if ( *(float *)(LODWORD(v22) + 692) > 0.0 )
  {
    v41 = controls;
    controls->brake = 1.0;
    v41->gas = 0.0;
    v45.value = Car::getSpeed(*(Car **)(LODWORD(v22) + 416), (Speed *)&controls)->value;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&controls);
    if ( v45.value < 1.0 )
      *(float *)(LODWORD(v22) + 692) = *(float *)(LODWORD(v22) + 692) - dt;
  }
}
void AIDriver::stepTurbo(AIDriver *this, float dt)
{
  Car *v3; // ecx
  float v4; // xmm0_4
  int v5; // ecx
  float value; // xmm1_4
  bool v7; // zf
  Car *v8; // ecx
  float safe_level; // [esp+Ch] [ebp-24h]
  unsigned int sessioninfo; // [esp+10h] [ebp-20h]

  v7 = !this->turbo.active;
  v3 = this->car;
  sessioninfo = _mm_loadu_si128((const __m128i *)&v3->ksPhysics->sessionInfo).m128i_u32[0];
  if ( v7 )
    return;
  safe_level = Engine::getSafeTurboLevel(&v3->drivetrain.acEngine);
  if ( sessioninfo == 1 )
  {
    v4 = safe_level * 0.80000001;
    goto LABEL_17;
  }
  if ( sessioninfo != 2 )
  {
    if ( sessioninfo != 3 )
    {
      value = FLOAT_1_0;
      goto LABEL_20;
    }
    v4 = safe_level;
    goto LABEL_17;
  }
  v5 = this->runLapCounter;
  if ( v5 )
    value = FLOAT_1_0;
  else
    value = (float)(int)(float)((float)(safe_level * 0.5) * 10.0) * 0.1;
  v7 = v5 == 0;
  if ( v5 > 0 )
  {
    if ( v5 <= this->turbo.qualifyHotLaps )
    {
LABEL_14:
      value = FLOAT_1_0;
      goto LABEL_15;
    }
    v7 = v5 == 0;
  }
  if ( v7 && this->locNpos > 0.80000001 )
    goto LABEL_14;
LABEL_15:
  if ( v5 > this->turbo.qualifyHotLaps )
  {
    v4 = safe_level * 0.5;
LABEL_17:
    value = (float)(int)(float)(v4 * 10.0) * 0.1;
  }
LABEL_20:
  v8 = this->car;
  if ( (float)v8->drivetrain.acEngine.lifeLeft < 10.0 )
    value = (float)(int)(float)(safe_level * 10.0) * 0.1;
  Engine::setTurboBoostLevel(&v8->drivetrain.acEngine, value);
}
void AIDriver::updateCurrentSplinePos(AIDriver *this)
{
  Car *v2; // eax
  const vec3f *v3; // eax
  AISplinePayload *v4; // eax
  char v5[12]; // [esp+10h] [ebp-64h] BYREF
  AISplinePayload result; // [esp+1Ch] [ebp-58h] BYREF

  v2 = this->car;
  if ( this->splineSelection )
  {
    v3 = (const vec3f *)((int (*)(IRigidBody *, char *, _DWORD))v2->body->getPosition)(v2->body, v5, 0);
    this->locNpos = SplineLocator::locateOnSpline(this->currentSpline, v3, &this->currentPitLineIndex);
  }
  else
  {
    this->locNpos = v2->splineLocatorData.npos;
  }
  v4 = AISpline::payloadAtPosition(this->currentSpline, &result, this->locNpos);
  *(__m128i *)&this->currentPayload.speedMS = _mm_loadu_si128((const __m128i *)v4);
  *(__m128i *)&this->currentPayload.camber = _mm_loadu_si128((const __m128i *)&v4->camber);
  *(__m128i *)&this->currentPayload.normal.z = _mm_loadu_si128((const __m128i *)&v4->normal.z);
  *(__m128i *)&this->currentPayload.length = _mm_loadu_si128((const __m128i *)&v4->length);
  *(__m128i *)&this->currentPayload.grip = _mm_loadu_si128((const __m128i *)&v4->grip);
  this->currentPayload.compression = v4->compression;
}
void AIDriver::updateTyres(AIDriver *this)
{
  Car *v2; // eax
  const __m128i *v3; // eax
  __m128i v4; // xmm0
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  float *v8; // eax
  int v9; // ebp
  int v10; // esi
  Car *v11; // ecx
  float *v12; // [esp+1Ch] [ebp-40h]
  float v13; // [esp+20h] [ebp-3Ch]
  RaceEngineer eng; // [esp+24h] [ebp-38h] BYREF
  __m128i v15; // [esp+40h] [ebp-1Ch]
  int v16; // [esp+58h] [ebp-4h]

  if ( !this->hasChoosenTyres )
  {
    RaceEngineer::RaceEngineer(&eng, this->car);
    v2 = this->car;
    v16 = 0;
    v3 = (const __m128i *)v2->ksPhysics;
    v4 = _mm_loadu_si128(v3 + 18);
    v5 = _mm_cvtsi128_si32(_mm_loadu_si128(v3 + 17));
    v15 = v4;
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        v7 = AIDriver::findTyreForQualify(this);
      }
      else
      {
        v7 = this->preferredCompound;
        if ( v7 == -1 )
          v7 = RaceEngineer::findTyreCompound(&eng, Fastest);
      }
    }
    else
    {
      v7 = RaceEngineer::findTyreCompound(&eng, Random);
      if ( !this->car->physicsGUID )
        v7 = this->preferredCompound;
    }
    v8 = this->tyreStopMinValueVKM;
    v9 = 0;
    v10 = 0;
    v12 = this->tyreStopMinValueVKM;
    do
    {
      v11 = this->car;
      if ( v11->tyres[v10].currentCompoundIndex != v7 )
      {
        _printf("AI car: %u  setting compound: %d  for tyre:%d\n", v11->physicsGUID, v7, v9);
        Tyre::setCompound(&this->car->tyres[v10], v7);
        v13 = getVKMForMult(
                &this->car->tyres[v10].compoundDefs._Myfirst[v7].modelData.wearCurve,
                this->tyreStopMinValue);
        *v12 = v13;
        _printf("tyreStopMinValueVKM[%d]=%f\n", v9, v13);
        v8 = v12;
      }
      ++v8;
      ++v10;
      ++v9;
      v12 = v8;
    }
    while ( v10 < 4 );
    this->hasChoosenTyres = 1;
    v16 = -1;
    RaceEngineer::~RaceEngineer(&eng);
  }
}
