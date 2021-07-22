#include "heavespring.h
void HeaveSpring::HeaveSpring(HeaveSpring *this)
{
  this->isPresent = 0;
  this->rodLength = 0.0;
  this->status.travel = 0.0;
  this->k = 0.0;
  this->progressiveK = 0.0;
  this->packerRange = 0.0;
  this->bumpStopRate = 0.0;
  this->bumpStopUp = 0.0;
  this->bumpStopDn = 0.0;
  Damper::Damper(&this->damper);
  this->isFront = 0;
}
void HeaveSpring::~HeaveSpring(HeaveSpring *this)
{
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->damper);
}
void HeaveSpring::init(HeaveSpring *this, Car *car, Suspension *s0, Suspension *s1, bool isFront)
{
  this->isFront = isFront;
  this->car = car;
  this->suspensions[0] = s0;
  this->suspensions[1] = s1;
  this->rodLength = 0.0;
  this->k = 0.0;
  this->progressiveK = 0.0;
  HeaveSpring::initData(this);
}
void HeaveSpring::initData(HeaveSpring *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  Car *v4; // ecx
  double v5; // st7
  bool v6; // cf
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  float v19; // [esp+8h] [ebp-D0h]
  std::wstring ifilename; // [esp+Ch] [ebp-CCh] BYREF
  INIReader v21; // [esp+24h] [ebp-B4h] BYREF
  std::wstring v22; // [esp+68h] [ebp-70h] BYREF
  std::wstring result; // [esp+80h] [ebp-58h] BYREF
  std::wstring section; // [esp+98h] [ebp-40h] BYREF
  std::wstring key; // [esp+B0h] [ebp-28h] BYREF
  int v26; // [esp+D4h] [ebp-4h]

  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  v26 = 0;
  v3 = std::operator+<wchar_t>(&v22, v2, L"/data/suspensions.ini");
  v4 = this->car;
  LOBYTE(v26) = 1;
  Car::getConfigPath(v4, &ifilename, v3);
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  LOBYTE(v26) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&v21, &ifilename);
  if ( v21.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 6;
    if ( this->isFront )
      std::wstring::assign(&section, L"HEAVE_FRONT", 0xBu);
    else
      std::wstring::assign(&section, L"HEAVE_REAR", 0xAu);
    if ( INIReader::hasSection(&v21, &section) )
    {
      this->isPresent = 1;
      std::wstring::wstring(&key, L"BUMPSTOP_UP");
      LOBYTE(v26) = 7;
      v5 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->bumpStopUp = v5;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"BUMPSTOP_DN");
      LOBYTE(v26) = 8;
      v7 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      v19 = v7;
      LODWORD(this->bumpStopDn) = LODWORD(v19) ^ _xmm;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"ROD_LENGTH");
      LOBYTE(v26) = 9;
      v8 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->rodLength = v8;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"SPRING_RATE");
      LOBYTE(v26) = 10;
      v9 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->k = v9;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"PROGRESSIVE_SPRING_RATE");
      LOBYTE(v26) = 11;
      v10 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->progressiveK = v10;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_BUMP");
      LOBYTE(v26) = 12;
      v11 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.bumpSlow = v11;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_REBOUND");
      LOBYTE(v26) = 13;
      v12 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.reboundSlow = v12;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_FAST_BUMP");
      LOBYTE(v26) = 14;
      v13 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.bumpFast = v13;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_FAST_REBOUND");
      LOBYTE(v26) = 15;
      v14 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.reboundFast = v14;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_FAST_BUMPTHRESHOLD");
      LOBYTE(v26) = 16;
      v15 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.fastThresholdBump = v15;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"DAMP_FAST_REBOUNDTHRESHOLD");
      LOBYTE(v26) = 17;
      v16 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->damper.fastThresholdRebound = v16;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      if ( this->damper.fastThresholdBump == 0.0 )
        this->damper.fastThresholdBump = 0.2;
      if ( this->damper.fastThresholdRebound == 0.0 )
        this->damper.fastThresholdRebound = 0.2;
      if ( this->damper.bumpFast == 0.0 )
        this->damper.bumpFast = this->damper.bumpSlow;
      if ( this->damper.reboundFast == 0.0 )
        this->damper.reboundFast = this->damper.reboundSlow;
      std::wstring::wstring(&key, L"BUMP_STOP_RATE");
      LOBYTE(v26) = 18;
      v17 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->bumpStopRate = v17;
      LOBYTE(v26) = 6;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      if ( this->bumpStopRate == 0.0 )
        this->bumpStopRate = 500000.0;
      std::wstring::wstring(&key, L"PACKER_RANGE");
      LOBYTE(v26) = 19;
      v18 = INIReader::getFloat(&v21, &section, &key);
      v6 = key._Myres < 8;
      this->packerRange = v18;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
    }
    else
    {
      this->isPresent = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  LOBYTE(v26) = 4;
  INIReader::~INIReader(&v21);
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
}
void HeaveSpring::step(HeaveSpring *this, float dt)
{
  IRigidBody_vtbl *v3; // esi
  int v4; // eax
  IRigidBody_vtbl *v5; // esi
  int v6; // eax
  Suspension *v7; // ecx
  Suspension *v8; // edx
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  int v13; // eax
  Suspension *v14; // esi
  float v15; // xmm2_4
  float v16; // xmm3_4
  IRigidBody *v17; // ecx
  Suspension_vtbl *v18; // esi
  int v19; // eax
  Suspension *v20; // eax
  IRigidBody *v21; // ecx
  Suspension_vtbl *v22; // esi
  int v23; // eax
  Car *v24; // eax
  Car *v25; // eax
  float v26; // xmm2_4
  Suspension *v27; // esi
  float v28; // xmm3_4
  float v29; // xmm0_4
  IRigidBody *v30; // ecx
  float v31; // xmm0_4
  Suspension_vtbl *v32; // esi
  int v33; // eax
  Suspension *v34; // eax
  IRigidBody *v35; // ecx
  Suspension_vtbl *v36; // esi
  int v37; // eax
  Car *v38; // eax
  Car *v39; // eax
  float v40; // xmm2_4
  Suspension *v41; // eax
  IRigidBody *v42; // ecx
  float v43; // xmm0_4
  Suspension_vtbl *v44; // esi
  int v45; // eax
  Suspension *v46; // eax
  IRigidBody *v47; // ecx
  Suspension_vtbl *v48; // esi
  int v49; // eax
  Car *v50; // eax
  Car *v51; // eax
  IRigidBody *v52; // esi
  vec3f *v53; // edi
  float *v54; // eax
  float v55; // xmm2_4
  float v56; // xmm0_4
  IRigidBody *v57; // ecx
  float v58; // xmm1_4
  IRigidBody_vtbl *v59; // eax
  float v60; // xmm2_4
  float v61; // xmm0_4
  float *v62; // esi
  vec3f *v63; // eax
  double v64; // st7
  Suspension *v65; // eax
  Suspension_vtbl *v66; // esi
  int v67; // eax
  Suspension *v68; // eax
  Suspension_vtbl *v69; // esi
  int v70; // eax
  Car *v71; // eax
  Car *v72; // eax
  float v73; // [esp+138h] [ebp-ACh] BYREF
  float v74; // [esp+13Ch] [ebp-A8h]
  float v75; // [esp+140h] [ebp-A4h] BYREF
  float v76; // [esp+144h] [ebp-A0h]
  float v77; // [esp+148h] [ebp-9Ch]
  float v78; // [esp+14Ch] [ebp-98h]
  float v79; // [esp+150h] [ebp-94h]
  __int64 v80; // [esp+154h] [ebp-90h]
  float v81; // [esp+15Ch] [ebp-88h]
  __int64 v82; // [esp+160h] [ebp-84h] BYREF
  vec3f v83; // [esp+168h] [ebp-7Ch] BYREF
  __int64 v84; // [esp+174h] [ebp-70h] BYREF
  float v85; // [esp+17Ch] [ebp-68h]
  vec3f v86; // [esp+180h] [ebp-64h] BYREF
  char v87; // [esp+18Ch] [ebp-58h] BYREF
  float v88[2]; // [esp+190h] [ebp-54h]
  char v89; // [esp+198h] [ebp-4Ch] BYREF
  float v90; // [esp+19Ch] [ebp-48h]
  char v91[64]; // [esp+1A4h] [ebp-40h] BYREF

  v3 = this->car->body->__vftable;
  v4 = ((int (*)(IRigidBody *, float *, _DWORD))this->suspensions[0]->hub->getPosition)(
         this->suspensions[0]->hub,
         &v73,
         0);
  v3->worldToLocal(this->car->body, (vec3f *)&v89, (const vec3f *)v4);
  v5 = this->car->body->__vftable;
  v6 = ((int (*)(IRigidBody *, float *, _DWORD))this->suspensions[1]->hub->getPosition)(
         this->suspensions[1]->hub,
         &v73,
         0);
  v5->worldToLocal(this->car->body, (vec3f *)&v87, (const vec3f *)v6);
  v7 = this->suspensions[0];
  v8 = this->suspensions[1];
  v84 = *(_QWORD *)&v7->dataRelToWheel.refPoint.x;
  v85 = v7->dataRelToWheel.refPoint.z;
  v86 = v8->dataRelToWheel.refPoint;
  if ( v7->k != 0.0 || v8->k != 0.0 )
    this->rodLength = (float)(v8->rodLength + v7->rodLength) * 0.5;
  v9 = this->packerRange;
  v10 = this->progressiveK;
  v78 = (float)(v88[0] + v90) * 0.5;
  v11 = (float)(v78 - v7->dataRelToWheel.refPoint.y) + this->rodLength;
  this->status.travel = v11;
  v12 = (float)((float)(v10 * v11) + this->k) * v11;
  v77 = v12;
  if ( v9 != 0.0 && v11 > v9 )
    v77 = (float)((float)(v11 - v9) * this->bumpStopRate) + v12;
  v13 = ((int (*)(IRigidBody *, char *, _DWORD))this->car->body->getWorldMatrix)(this->car->body, v91, 0);
  v14 = this->suspensions[0];
  v15 = *(float *)(v13 + 20);
  v16 = *(float *)(v13 + 24);
  v17 = v14->hub;
  HIDWORD(v80) = *(_DWORD *)(v13 + 16);
  v73 = *((float *)&v80 + 1) * COERCE_FLOAT(LODWORD(v77) ^ _xmm);
  v79 = v15;
  v74 = v15 * COERCE_FLOAT(LODWORD(v77) ^ _xmm);
  *(float *)&v80 = v16;
  LODWORD(v76) = LODWORD(v77) ^ _xmm;
  v75 = v16 * COERCE_FLOAT(LODWORD(v77) ^ _xmm);
  v18 = v14->__vftable;
  v19 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v17->getPosition)(v17, &v83, 0, 0, 0);
  ((void (*)(Suspension *, float *, int))v18->addForceAtPos)(this->suspensions[0], &v75, v19);
  v20 = this->suspensions[1];
  v21 = v20->hub;
  v73 = *((float *)&v80 + 1) * v76;
  v74 = v79 * v76;
  v75 = *(float *)&v80 * v76;
  v22 = v20->__vftable;
  v23 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v21->getPosition)(v21, &v83, 0, 0, 0);
  ((void (*)(Suspension *, float *, int))v22->addForceAtPos)(this->suspensions[1], &v75, v23);
  v24 = this->car;
  v73 = 0.0;
  v74 = v77;
  v75 = 0.0;
  v24->body->addLocalForceAtLocalPos(v24->body, (const vec3f *)&v73, (const vec3f *)&v84);
  v73 = 0.0;
  v25 = this->car;
  v74 = v77;
  v75 = 0.0;
  v25->body->addLocalForceAtLocalPos(v25->body, (const vec3f *)&v73, &v86);
  v26 = this->bumpStopUp;
  v27 = this->suspensions[0];
  v28 = FLOAT_500000_0;
  v29 = v78 - v27->dataRelToWheel.refPoint.y;
  v78 = v29;
  if ( v26 != 0.0 && v29 > v26 )
  {
    v30 = v27->hub;
    v31 = (float)(v29 - v26) * 500000.0;
    v77 = v31;
    LODWORD(v76) = LODWORD(v31) ^ _xmm;
    v73 = *((float *)&v80 + 1) * COERCE_FLOAT(LODWORD(v31) ^ _xmm);
    v74 = v79 * COERCE_FLOAT(LODWORD(v31) ^ _xmm);
    v75 = *(float *)&v80 * COERCE_FLOAT(LODWORD(v31) ^ _xmm);
    v32 = v27->__vftable;
    v33 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v30->getPosition)(v30, &v83, 0, 0, 0);
    ((void (*)(Suspension *, float *, int))v32->addForceAtPos)(this->suspensions[0], &v75, v33);
    v34 = this->suspensions[1];
    v35 = v34->hub;
    v73 = *((float *)&v80 + 1) * v76;
    v74 = v79 * v76;
    v75 = *(float *)&v80 * v76;
    v36 = v34->__vftable;
    v37 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v35->getPosition)(v35, &v83, 0, 0, 0);
    ((void (*)(Suspension *, float *, int))v36->addForceAtPos)(this->suspensions[1], &v75, v37);
    v38 = this->car;
    v73 = 0.0;
    v74 = v77;
    v75 = 0.0;
    v38->body->addLocalForceAtLocalPos(v38->body, (const vec3f *)&v73, (const vec3f *)&v84);
    v39 = this->car;
    v73 = 0.0;
    v74 = v77;
    v75 = 0.0;
    v39->body->addLocalForceAtLocalPos(v39->body, (const vec3f *)&v73, &v86);
    v29 = v78;
    v28 = FLOAT_500000_0;
  }
  v40 = this->bumpStopDn;
  if ( v40 != 0.0 && v40 > v29 )
  {
    v41 = this->suspensions[0];
    v42 = v41->hub;
    v43 = (float)(v29 - v40) * v28;
    v78 = v43;
    LODWORD(v76) = LODWORD(v43) ^ _xmm;
    v73 = *((float *)&v80 + 1) * COERCE_FLOAT(LODWORD(v43) ^ _xmm);
    v74 = v79 * COERCE_FLOAT(LODWORD(v43) ^ _xmm);
    v75 = *(float *)&v80 * COERCE_FLOAT(LODWORD(v43) ^ _xmm);
    v44 = v41->__vftable;
    v45 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v42->getPosition)(v42, &v83, 0, 0, 0);
    ((void (*)(Suspension *, float *, int))v44->addForceAtPos)(this->suspensions[0], &v75, v45);
    v46 = this->suspensions[1];
    v47 = v46->hub;
    v73 = *((float *)&v80 + 1) * v76;
    v74 = v79 * v76;
    v75 = *(float *)&v80 * v76;
    v48 = v46->__vftable;
    v49 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v47->getPosition)(v47, &v83, 0, 0, 0);
    ((void (*)(Suspension *, float *, int))v48->addForceAtPos)(this->suspensions[1], &v75, v49);
    v50 = this->car;
    v73 = 0.0;
    v74 = v78;
    v75 = 0.0;
    v50->body->addLocalForceAtLocalPos(v50->body, (const vec3f *)&v73, (const vec3f *)&v84);
    v51 = this->car;
    v73 = 0.0;
    v74 = v78;
    v75 = 0.0;
    v51->body->addLocalForceAtLocalPos(v51->body, (const vec3f *)&v73, &v86);
  }
  v52 = this->suspensions[0]->hub;
  v53 = this->suspensions[1]->hub->getVelocity(this->suspensions[1]->hub, &v83);
  v54 = (float *)v52->getVelocity(v52, (vec3f *)&v73);
  v55 = v54[1];
  v56 = v54[2];
  v57 = this->car->body;
  v58 = (float)(*v54 + v53->x) * 0.5;
  v59 = v57->__vftable;
  v60 = (float)(v55 + v53->y) * 0.5;
  v61 = (float)(v56 + v53->z) * 0.5;
  v76 = v58;
  v77 = v60;
  v78 = v61;
  v62 = (float *)v59->getLocalPointVelocity(v57, &v83, &v86);
  v63 = this->car->body->getLocalPointVelocity(this->car->body, &v73, &v84);
  v64 = Damper::getForce(
          &this->damper,
          (float)((float)((float)(v77 - (float)((float)(v63->y + v62[1]) * 0.5)) * v79)
                + (float)((float)(v76 - (float)((float)(v63->x + *v62) * 0.5)) * *((float *)&v80 + 1)))
        + (float)((float)(v78 - (float)((float)(v63->z + v62[2]) * 0.5)) * *(float *)&v80));
  v65 = this->suspensions[0];
  v76 = v64;
  v81 = *((float *)&v80 + 1) * v76;
  *(float *)&v82 = v79 * v76;
  *((float *)&v82 + 1) = *(float *)&v80 * v76;
  v66 = v65->__vftable;
  v67 = ((int (__stdcall *)(vec3f *, _DWORD, _DWORD, _DWORD))v65->hub->getPosition)(&v83, 0, 0, 0);
  ((void (*)(Suspension *, char *, int))v66->addForceAtPos)(this->suspensions[0], (char *)&v82 + 4, v67);
  v68 = this->suspensions[1];
  v69 = v68->__vftable;
  v70 = ((int (*)(IRigidBody *, vec3f *, _DWORD, _DWORD, _DWORD))v68->hub->getPosition)(
          v68->hub,
          &v83,
          0,
          0,
          0);
  ((void (*)(Suspension *, char *, int))v69->addForceAtPos)(this->suspensions[1], (char *)&v82 + 4, v70);
  v71 = this->car;
  v73 = v81 * -1.0;
  v74 = *(float *)&v82 * -1.0;
  v75 = *((float *)&v82 + 1) * -1.0;
  v71->body->addForceAtLocalPos(v71->body, (const vec3f *)&v73, (const vec3f *)&v84);
  v72 = this->car;
  v73 = v81 * -1.0;
  v74 = *(float *)&v82 * -1.0;
  v75 = *((float *)&v82 + 1) * -1.0;
  v72->body->addForceAtLocalPos(v72->body, (const vec3f *)&v73, &v86);
}
