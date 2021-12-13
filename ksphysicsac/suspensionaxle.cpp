#include "suspensionaxle.h"
void SuspensionAxle::SuspensionAxle(SuspensionAxle *this, Car *car, RigidAxleSide side, const std::wstring *carDataPath)
{
  Car *v5; // eax
  const std::wstring *v6; // eax
  const std::wstring *v7; // eax
  int v8; // esi
  double v9; // st7
  bool v10; // cf
  double v11; // st7
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  float v15; // eax
  double v16; // st7
  IRigidBody *v17; // eax
  float v18; // xmm0_4
  IRigidBody_vtbl *v19; // esi
  int v20; // esi
  mat44f *v21; // eax
  int v22; // eax
  float v23; // esi
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  const std::wstring *v26; // eax
  const std::wstring *v27; // eax
  AxleJoint *v28; // eax
  IRigidBody *v29; // esi
  AxleJoint *v30; // ecx
  float v31; // edx
  IRigidBody *v32; // esi
  AxleJoint *v33; // ecx
  float v34; // esi
  char *v35; // esi
  float v36; // esi
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  double v48; // st7
  double v49; // st7
  double v50; // st7
  float v51; // xmm0_4
  std::vector<AxleJoint> *v52; // eax
  AxleJoint *v53; // edi
  AxleJoint *v54; // esi
  float v55; // [esp+60h] [ebp-250h]
  char v56[8]; // [esp+7Ch] [ebp-234h] BYREF
  AxleJoint v57; // [esp+84h] [ebp-22Ch] BYREF
  __int64 v58; // [esp+BCh] [ebp-1F4h] BYREF
  char v59[16]; // [esp+C4h] [ebp-1ECh] BYREF
  __int64 v60; // [esp+D4h] [ebp-1DCh] BYREF
  int v61; // [esp+DCh] [ebp-1D4h]
  SuspensionAxle *v62; // [esp+E0h] [ebp-1D0h]
  vec3f v63; // [esp+E4h] [ebp-1CCh] BYREF
  vec3f v64; // [esp+F0h] [ebp-1C0h] BYREF
  __int64 v65; // [esp+FCh] [ebp-1B4h] BYREF
  float v66; // [esp+104h] [ebp-1ACh]
  SuspensionAxle *v67; // [esp+108h] [ebp-1A8h]
  IPhysicsCore *v68; // [esp+10Ch] [ebp-1A4h]
  int v69; // [esp+110h] [ebp-1A0h]
  unsigned int v70; // [esp+114h] [ebp-19Ch]
  float v71; // [esp+118h] [ebp-198h]
  float i; // [esp+11Ch] [ebp-194h]
  Car *v73; // [esp+120h] [ebp-190h]
  std::wstring v74; // [esp+124h] [ebp-18Ch] BYREF
  std::wstring v75; // [esp+13Ch] [ebp-174h] BYREF
  std::wstring v76; // [esp+154h] [ebp-15Ch] BYREF
  std::wstring result; // [esp+16Ch] [ebp-144h] BYREF
  INIReader v78; // [esp+184h] [ebp-12Ch] BYREF
  std::wstring v79; // [esp+1C8h] [ebp-E8h] BYREF
  std::wstring v80; // [esp+1E0h] [ebp-D0h] BYREF
  std::wstring key; // [esp+1F8h] [ebp-B8h] BYREF
  std::wstring _Left; // [esp+210h] [ebp-A0h] BYREF
  std::wstring section; // [esp+228h] [ebp-88h] BYREF
  std::wstring ptr; // [esp+240h] [ebp-70h] BYREF
  std::wstring v85; // [esp+258h] [ebp-58h] BYREF
  std::wstring v86; // [esp+270h] [ebp-40h] BYREF
  std::wstring v87; // [esp+288h] [ebp-28h] BYREF
  int v88; // [esp+2ACh] [ebp-4h]

  v67 = this;
  i = 0.0;
  v62 = this;
  v73 = car;
  this->bumpStopProgressive = 0.0;
  this->baseCFM = 0.0000001;
  v88 = 0;
  this->__vftable = (SuspensionAxle_vtbl *)&SuspensionAxle::`vftable';
  this->side = side;
  Damper::Damper(&this->damper);
  v5 = v73;
  this->car = v73;
  this->axle = v5->rigidAxle;
  this->status.travel = 0.0;
  this->status.damperSpeedMS = 0.0;
  this->axleBasePos.x = 0.0;
  this->axleBasePos.y = 0.0;
  this->axleBasePos.z = 0.0;
  this->track = 0.0;
  this->referenceY = 0.0;
  this->joints._Myfirst = 0;
  this->joints._Mylast = 0;
  this->joints._Myend = 0;
  this->leafSpringK.x = 0.0;
  this->leafSpringK.y = 0.0;
  this->leafSpringK.z = 0.0;
  LOBYTE(v88) = 2;
  this->attachRelativePos = 1.0;
  _printf("SuspensionAxle side: %d\n", side);
  v6 = std::operator+<wchar_t>(&result, carDataPath, L"suspensions.ini");
  LOBYTE(v88) = 3;
  v7 = Car::getConfigPath(v73, &v74, v6);
  LOBYTE(v88) = 4;
  INIReader::INIReader(&v78, v7);
  if ( v74._Myres >= 8 )
    operator delete(v74._Bx._Ptr);
  v74._Myres = 7;
  v74._Mysize = 0;
  v74._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"VERSION", 7u);
  LOBYTE(v88) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v88) = 9;
  v8 = INIReader::getInt(&v78, &section, &key);
  v69 = v8;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v88) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v88) = 11;
  v9 = INIReader::getFloat(&v78, &section, &key);
  v10 = section._Myres < 8;
  this->track = v9 * 0.5;
  if ( !v10 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v88) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v88) = 13;
  v11 = INIReader::getFloat(&v78, &section, &key);
  v10 = section._Myres < 8;
  this->referenceY = v11;
  if ( !v10 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WHEELBASE", 9u);
  LOBYTE(v88) = 14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v88) = 15;
  v71 = INIReader::getFloat(&v78, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CG_LOCATION", 0xBu);
  LOBYTE(v88) = 16;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v88) = 17;
  *(float *)&v70 = INIReader::getFloat(&v78, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v88) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v12 = (__m128)v70;
  v12.m128_f32[0] = *(float *)&v70 * v71;
  v13 = (__m128)LODWORD(this->referenceY);
  v14 = _mm_xor_ps(v12, (__m128)_xmm);
  v66 = v14.m128_f32[0];
  v14.m128_f32[0] = 0.0;
  v15 = v66;
  *(_QWORD *)&this->axleBasePos.x = _mm_unpacklo_ps(v14, v13).m128_u64[0];
  this->axleBasePos.z = v15;
  if ( v8 >= 4 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ATTACH_REL_POS", 0xEu);
    LOBYTE(v88) = 18;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AXLE", 4u);
    LOBYTE(v88) = 19;
    v16 = INIReader::getFloat(&v78, &section, &key);
    v10 = section._Myres < 8;
    this->attachRelativePos = v16;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v88) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( side == Left )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HUB_MASS", 8u);
    LOBYTE(v88) = 20;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REAR", 4u);
    v17 = this->axle;
    v18 = this->track * 2.0;
    LOBYTE(v88) = 21;
    v19 = v17->__vftable;
    v55 = INIReader::getFloat(&v78, &section, &key);
    ((void (*)(IRigidBody *, _DWORD, _DWORD, int, int))v19->setMassBox)(
      this->axle,
      LODWORD(v55),
      LODWORD(v18),
      1045220557,
      1056964608);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v88) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    SuspensionAxle::setPositions(this);
    v68 = PhysicsEngine::getCore(v73->ksPhysics);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LINK_COUNT", 0xAu);
    LOBYTE(v88) = 22;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AXLE", 4u);
    LOBYTE(v88) = 23;
    *(float *)&v20 = COERCE_FLOAT(INIReader::getInt(&v78, &section, &key));
    i = *(float *)&v20;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v88) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _printf("car matrix\n");
    v21 = (mat44f *)((int (*)(IRigidBody *, char *, _DWORD))v73->body->getWorldMatrix)(v73->body, v56, 0);
    mat44f::print(v21);
    *(float *)&v22 = 0.0;
    *(float *)&v70 = 0.0;
    if ( v20 > 0 )
    {
      v23 = 0.0;
      v71 = 0.0;
      do
      {
        v24 = std::to_wstring(&v76, v22);
        LOBYTE(v88) = 24;
        v25 = std::operator+<wchar_t>(&v75, L"J", v24);
        LOBYTE(v88) = 25;
        std::operator+<wchar_t>(&_Left, v25, L"_");
        if ( v75._Myres >= 8 )
          operator delete(v75._Bx._Ptr);
        v75._Myres = 7;
        v75._Mysize = 0;
        v75._Bx._Buf[0] = 0;
        LOBYTE(v88) = 28;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        v80._Myres = 7;
        v80._Mysize = 0;
        v80._Bx._Buf[0] = 0;
        std::wstring::assign(&v80, L"AXLE", 4u);
        LOBYTE(v88) = 29;
        v26 = std::operator+<wchar_t>(&v79, &_Left, L"CAR");
        LOBYTE(v88) = 30;
        INIReader::getFloat3(&v78, &v64, &v80, v26);
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
        v79._Myres = 7;
        v79._Mysize = 0;
        v79._Bx._Buf[0] = 0;
        LOBYTE(v88) = 28;
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        v80._Myres = 7;
        v80._Mysize = 0;
        v80._Bx._Buf[0] = 0;
        std::wstring::assign(&v80, L"AXLE", 4u);
        LOBYTE(v88) = 31;
        v27 = std::operator+<wchar_t>(&v79, &_Left, L"AXLE");
        LOBYTE(v88) = 32;
        INIReader::getFloat3(&v78, &v63, &v80, v27);
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
        v79._Myres = 7;
        v79._Mysize = 0;
        v79._Bx._Buf[0] = 0;
        LOBYTE(v88) = 28;
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        AxleJoint::AxleJoint(&v57);
        std::vector<AxleJoint>::push_back(&this->joints, v28);
        *(vec3f *)((char *)&this->joints._Myfirst->ballCar.relToAxle + LODWORD(v23)) = v64;
        v29 = v73->body;
        this->axle->localToWorld(this->axle, (vec3f *)&v59[4], &v64);
        v29->worldToLocal(v29, (vec3f *)&v60, (const vec3f *)&v59[4]);
        v30 = this->joints._Myfirst;
        v31 = v71;
        *(_QWORD *)((char *)&v30->ballCar.relToCar.x + LODWORD(v71)) = v60;
        *(_DWORD *)((char *)&v30->ballCar.relToCar.z + LODWORD(v31)) = v61;
        *(vec3f *)((char *)&this->joints._Myfirst->ballAxle.relToAxle + LODWORD(v31)) = v63;
        v32 = v73->body;
        this->axle->localToWorld(this->axle, (vec3f *)&v58, &v63);
        v32->worldToLocal(v32, (vec3f *)&v65, (const vec3f *)&v58);
        v33 = this->joints._Myfirst;
        v34 = v71;
        *(_QWORD *)((char *)&v33->ballAxle.relToCar.x + LODWORD(v71)) = v65;
        *(float *)((char *)&v33->ballAxle.relToCar.z + LODWORD(v34)) = v66;
        v73->body->localToWorld(
          v73->body,
          (vec3f *)&section._Bx._Alias[12],
          (vec3f *)((char *)&this->joints._Myfirst->ballCar.relToCar + LODWORD(v34)));
        v73->body->localToWorld(
          v73->body,
          (vec3f *)&key._Bx._Alias[12],
          (vec3f *)((char *)&this->joints._Myfirst->ballAxle.relToCar + LODWORD(v34)));
        v35 = (char *)this->joints._Myfirst + LODWORD(v71);
        *((_DWORD *)v35 + 13) = v68->createDistanceJoint(
                                  v68,
                                  v73->body,
                                  this->axle,
                                  (const vec3f *)&section._Bx._Alias[12],
                                  (const vec3f *)&key._Bx._Alias[12]);
        _printf("creating joint\n");
        v36 = v71;
        _printf(
          "%s: (%f , %f , %f)\n",
          "ballCar",
          *(float *)((char *)&this->joints._Myfirst->ballCar.relToCar.x + LODWORD(v71)),
          *(float *)((char *)&this->joints._Myfirst->ballCar.relToCar.y + LODWORD(v71)),
          *(float *)((char *)&this->joints._Myfirst->ballCar.relToCar.z + LODWORD(v71)));
        _printf(
          "%s: (%f , %f , %f)\n",
          "axle",
          *(float *)((char *)&this->joints._Myfirst->ballAxle.relToCar.x + LODWORD(v36)),
          *(float *)((char *)&this->joints._Myfirst->ballAxle.relToCar.y + LODWORD(v36)),
          *(float *)((char *)&this->joints._Myfirst->ballAxle.relToCar.z + LODWORD(v36)));
        LOBYTE(v88) = 7;
        if ( _Left._Myres >= 8 )
          operator delete(_Left._Bx._Ptr);
        LODWORD(v23) = LODWORD(v36) + 56;
        v22 = v70 + 1;
        v71 = v23;
        v70 = v22;
      }
      while ( v22 < SLODWORD(i) );
    }
    v8 = v69;
  }
  ptr._Myres = 7;
  ptr._Mysize = 0;
  ptr._Bx._Buf[0] = 0;
  std::wstring::assign(&ptr, L"FRONT", 5u);
  LOBYTE(v88) = 33;
  v85._Myres = 7;
  v85._Mysize = 0;
  v85._Bx._Buf[0] = 0;
  std::wstring::assign(&v85, L"FRONT", 5u);
  LOBYTE(v88) = 34;
  std::wstring::wstring(&v86, L"REAR");
  LOBYTE(v88) = 35;
  std::wstring::wstring(&v87, L"REAR");
  LOBYTE(v88) = 36;
  std::wstring::wstring(&_Left, L"BUMPSTOP_UP");
  LOBYTE(v88) = 37;
  v37 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->bumpStopUp = v37;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"BUMPSTOP_DN");
  LOBYTE(v88) = 38;
  v38 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  i = v38;
  LODWORD(this->bumpStopDn) = LODWORD(i) ^ _xmm;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"ROD_LENGTH");
  LOBYTE(v88) = 39;
  v39 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->rodLength = v39;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  _printf("INIT ROD LENGTH:%f\n", this->rodLength);
  std::wstring::wstring(&_Left, L"TOE_OUT");
  LOBYTE(v88) = 40;
  v40 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->toeOUT_Linear = v40;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"SPRING_RATE");
  LOBYTE(v88) = 41;
  v41 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->k = v41;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"PROGRESSIVE_SPRING_RATE");
  LOBYTE(v88) = 42;
  v42 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->progressiveK = v42;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_BUMP");
  LOBYTE(v88) = 43;
  v43 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.bumpSlow = v43;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_REBOUND");
  LOBYTE(v88) = 44;
  v44 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.reboundSlow = v44;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_FAST_BUMP");
  LOBYTE(v88) = 45;
  v45 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.bumpFast = v45;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_FAST_REBOUND");
  LOBYTE(v88) = 46;
  v46 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.reboundFast = v46;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_FAST_BUMPTHRESHOLD");
  LOBYTE(v88) = 47;
  v47 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.fastThresholdBump = v47;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  std::wstring::wstring(&_Left, L"DAMP_FAST_REBOUNDTHRESHOLD");
  LOBYTE(v88) = 48;
  v48 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->damper.fastThresholdRebound = v48;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  if ( this->damper.fastThresholdBump == 0.0 )
    this->damper.fastThresholdBump = 0.2;
  if ( this->damper.fastThresholdRebound == 0.0 )
    this->damper.fastThresholdRebound = 0.2;
  if ( this->damper.bumpFast == 0.0 )
    this->damper.bumpFast = this->damper.bumpSlow;
  if ( this->damper.reboundFast == 0.0 )
    this->damper.reboundFast = this->damper.reboundSlow;
  std::wstring::wstring(&_Left, L"BUMP_STOP_RATE");
  LOBYTE(v88) = 49;
  v49 = INIReader::getFloat(&v78, &v86, &_Left);
  v10 = _Left._Myres < 8;
  this->bumpStopRate = v49;
  LOBYTE(v88) = 36;
  if ( !v10 )
    operator delete(_Left._Bx._Ptr);
  if ( this->bumpStopRate == 0.0 )
    this->bumpStopRate = 500000.0;
  if ( v8 >= 3 )
  {
    std::wstring::wstring(&_Left, L"LEAF_SPRING_LAT_K");
    LOBYTE(v88) = 50;
    std::wstring::wstring(&v80, L"AXLE");
    LOBYTE(v88) = 51;
    v50 = INIReader::getFloat(&v78, &v80, &_Left);
    v10 = v80._Myres < 8;
    this->leafSpringK.x = v50;
    if ( !v10 )
      operator delete(v80._Bx._Ptr);
    v80._Myres = 7;
    v80._Mysize = 0;
    v80._Bx._Buf[0] = 0;
    LOBYTE(v88) = 36;
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
  }
  std::wstring::wstring(&_Left, L"RIGIDITY");
  LOBYTE(v88) = 52;
  LODWORD(i) = 1;
  INIReader::hasSection(&v78, &_Left);
  v88 = 36;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v51 = this->baseCFM;
  v52 = &this->joints;
  v53 = this->joints._Mylast;
  v54 = v52->_Myfirst;
  for ( i = v51; v54 != v53; ++v54 )
  {
    ((void (*)(IJoint *, int, float))v54->ballAxle.joint->setERPCFM)(
      v54->ballAxle.joint,
      1050253722,
      COERCE_FLOAT(LODWORD(v51)));
    v51 = i;
  }
  LOBYTE(v88) = 7;
  `eh vector destructor iterator'(&ptr, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v88) = 2;
  INIReader::~INIReader(&v78);
}
SuspensionAxle *SuspensionAxle::`scalar deleting destructor'(SuspensionAxle *this, unsigned int a2)
{
  this->__vftable = (SuspensionAxle_vtbl *)&SuspensionAxle::`vftable';
  if ( this->joints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->joints);
    operator delete(this->joints._Myfirst);
    this->joints._Myfirst = 0;
    this->joints._Mylast = 0;
    this->joints._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->damper);
  this->__vftable = (SuspensionAxle_vtbl *)&ISuspension::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionAxle::addForceAtPos(SuspensionAxle *this, const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque)
{
  this->axle->addForceAtPos(this->axle, force, pos);
}
void SuspensionAxle::addLocalForceAndTorque(SuspensionAxle *this, const vec3f *force, const vec3f *torque, const vec3f *driveTorque)
{
  int v5[3]; // [esp+4h] [ebp-Ch] BYREF

  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 0;
  this->axle->addForceAtLocalPos(this->axle, force, (const vec3f *)v5);
  this->axle->addTorque(this->axle, torque);
  if ( driveTorque->x != 0.0 || driveTorque->y != 0.0 || driveTorque->z != 0.0 )
    this->car->body->addTorque(this->car->body, driveTorque);
}
void SuspensionAxle::addTorque(SuspensionAxle *this, const vec3f *torque)
{
  this->axle->addTorque(this->axle, torque);
}
vec3f *SuspensionAxle::getBasePosition(SuspensionAxle *this, vec3f *result)
{
  vec3f *v2; // eax
  float v4; // ecx
  float v5; // xmm0_4

  v2 = result;
  if ( this->side )
  {
    LODWORD(v5) = LODWORD(this->track) ^ _xmm;
    result->y = this->axleBasePos.y;
    v4 = this->axleBasePos.z;
    result->x = v5;
  }
  else
  {
    v4 = this->axleBasePos.z;
    result->x = this->track;
    result->y = this->axleBasePos.y;
  }
  result->z = v4;
  return v2;
}
std::vector<DebugLine> *SuspensionAxle::getDebugLines(SuspensionAxle *this, std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix)
{
  SuspensionAxle *v4; // edx
  std::vector<DebugLine> *v5; // ecx
  bool v6; // zf
  AxleJoint *v7; // edi
  AxleJoint *v8; // esi
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float *v19; // eax
  float v20; // xmm2_4
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  float v23; // xmm0_4
  __m128 v24; // xmm6
  float v25; // xmm2_4
  float v26; // xmm4_4
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  float v30; // xmm4_4
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  float v35; // xmm7_4
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  DebugLine _Val; // [esp+Ch] [ebp-A8h] BYREF
  float v40; // [esp+40h] [ebp-74h]
  float v41; // [esp+4Ch] [ebp-68h]
  __m128i v42; // [esp+50h] [ebp-64h]
  __m128i v43; // [esp+60h] [ebp-54h]
  __m128i v44; // [esp+70h] [ebp-44h]
  __m128i v45; // [esp+80h] [ebp-34h]
  int v46; // [esp+90h] [ebp-24h]
  float v47; // [esp+94h] [ebp-20h]
  float v48; // [esp+98h] [ebp-1Ch]
  float v49; // [esp+9Ch] [ebp-18h]
  float v50; // [esp+A0h] [ebp-14h]
  float v51; // [esp+A4h] [ebp-10h]
  int v52; // [esp+B0h] [ebp-4h]
  const mat44f *hubMatrixa; // [esp+C0h] [ebp+Ch]

  v4 = this;
  v48 = *(float *)&this;
  v46 = 0;
  v5 = result;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v6 = v4->side == Left;
  v52 = 0;
  v46 = 1;
  if ( !v6 )
    return result;
  v7 = v4->joints._Mylast;
  v8 = v4->joints._Myfirst;
  v9 = hubMatrix->M11;
  v10 = hubMatrix->M12;
  v11 = hubMatrix->M13;
  v42 = _mm_loadu_si128((const __m128i *)hubMatrix);
  v43 = _mm_loadu_si128((const __m128i *)&hubMatrix->M21);
  v44 = _mm_loadu_si128((const __m128i *)&hubMatrix->M31);
  v12 = *(float *)&v44.m128i_i32[2];
  v13 = *(float *)&v44.m128i_i32[1];
  v14 = *(float *)v44.m128i_i32;
  v45 = _mm_loadu_si128((const __m128i *)&hubMatrix->M41);
  LODWORD(v15) = LODWORD(v4->track) ^ _xmm;
  v16 = (float)(v9 * v15) + hubMatrix->M41;
  v17 = (float)(v10 * v15) + hubMatrix->M42;
  v18 = (float)(v11 * v15) + hubMatrix->M43;
  v51 = v16;
  v49 = v17;
  *(float *)&hubMatrixa = v18;
  if ( v8 != v7 )
  {
    v19 = &v8->ballAxle.relToAxle.z;
    LODWORD(v50) = &v8->ballAxle.relToAxle.z;
    do
    {
      v20 = *(v19 - 1);
      v21 = (__m128)*((unsigned int *)v19 - 2);
      v22 = v21;
      _Val.seconds = 0.0;
      v23 = v20 * *(float *)&v43.m128i_i32[1];
      v22.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * *(float *)v42.m128i_i32)
                                      + (float)(v20 * *(float *)v43.m128i_i32))
                              + (float)(*v19 * *(float *)v44.m128i_i32))
                      + v16;
      v24 = v21;
      v21.m128_f32[0] = (float)(v21.m128_f32[0] * *(float *)&v42.m128i_i32[2])
                      + (float)(v20 * *(float *)&v43.m128i_i32[2]);
      v25 = *(v19 - 4);
      v21.m128_f32[0] = (float)(v21.m128_f32[0] + (float)(*v19 * *(float *)&v44.m128i_i32[2])) + v18;
      v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] * *(float *)&v42.m128i_i32[1]) + v23)
                              + (float)(*v19 * *(float *)&v44.m128i_i32[1]))
                      + v17;
      v26 = *(v19 - 6);
      v27 = (__m128)LODWORD(v26);
      v40 = v21.m128_f32[0];
      v28 = (__m128)*((unsigned int *)v19 - 5);
      v29 = v28;
      *(_QWORD *)&_Val.p1.x = _mm_unpacklo_ps(v22, v24).m128_u64[0];
      v27.m128_f32[0] = (float)((float)((float)(v26 * bodyMatrix->M11) + (float)(v28.m128_f32[0] * bodyMatrix->M21))
                              + (float)(v25 * bodyMatrix->M31))
                      + bodyMatrix->M41;
      v29.m128_f32[0] = (float)(v28.m128_f32[0] * bodyMatrix->M22) + (float)(v26 * bodyMatrix->M12);
      v30 = (float)((float)(v26 * bodyMatrix->M13) + (float)(v28.m128_f32[0] * bodyMatrix->M23))
          + (float)(v25 * bodyMatrix->M33);
      v29.m128_f32[0] = v29.m128_f32[0] + (float)(v25 * bodyMatrix->M32);
      _Val.color = (vec4f)_xmm;
      v29.m128_f32[0] = v29.m128_f32[0] + bodyMatrix->M42;
      v41 = v30 + bodyMatrix->M43;
      _Val.p0.z = v41;
      _Val.p1.z = v40;
      *(_QWORD *)&_Val.p0.x = _mm_unpacklo_ps(v27, v29).m128_u64[0];
      std::vector<DebugLine>::push_back(v5, &_Val);
      ++v8;
      v16 = v51;
      v19 = (float *)(LODWORD(v50) + 56);
      v17 = v49;
      v18 = *(float *)&hubMatrixa;
      v5 = result;
      LODWORD(v50) += 56;
    }
    while ( v8 != v7 );
    v12 = *(float *)&v44.m128i_i32[2];
    v13 = *(float *)&v44.m128i_i32[1];
    v14 = *(float *)v44.m128i_i32;
    v4 = (SuspensionAxle *)LODWORD(v48);
  }
  v31 = (__m128)LODWORD(v4->track);
  v32 = _mm_xor_ps(v31, (__m128)_xmm);
  _Val.seconds = 0.0;
  v33 = v32;
  v48 = v14 * 0.0;
  v47 = v12 * 0.0;
  v33.m128_f32[0] = (float)((float)(v32.m128_f32[0] * *(float *)v42.m128i_i32) + (float)(*(float *)v43.m128i_i32 * 0.0))
                  + (float)(v14 * 0.0);
  v34 = v32;
  v33.m128_f32[0] = v33.m128_f32[0] + v16;
  v51 = *(float *)&v43.m128i_i32[1] * 0.0;
  v50 = v13 * 0.0;
  v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * *(float *)&v42.m128i_i32[1])
                          + (float)(*(float *)&v43.m128i_i32[1] * 0.0))
                  + (float)(v13 * 0.0);
  v35 = v49;
  v49 = *(float *)&v43.m128i_i32[2] * 0.0;
  v34.m128_f32[0] = v34.m128_f32[0] + v35;
  v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * *(float *)&v42.m128i_i32[2])
                          + (float)(*(float *)&v43.m128i_i32[2] * 0.0))
                  + (float)(v12 * 0.0);
  v36 = v31;
  *(_QWORD *)&_Val.p1.x = _mm_unpacklo_ps(v33, v34).m128_u64[0];
  v41 = v32.m128_f32[0] + *(float *)&hubMatrixa;
  v37 = v31;
  _Val.p1.z = v41;
  _Val.color = (vec4f)_xmm;
  v36.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] * *(float *)v42.m128i_i32)
                                  + (float)(*(float *)v43.m128i_i32 * 0.0))
                          + v48)
                  + v16;
  v37.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] * *(float *)&v42.m128i_i32[1])
                                  + (float)(*(float *)&v43.m128i_i32[1] * 0.0))
                          + v50)
                  + v35;
  v40 = (float)((float)((float)(v31.m128_f32[0] * *(float *)&v42.m128i_i32[2])
                      + (float)(*(float *)&v43.m128i_i32[2] * 0.0))
              + v47)
      + *(float *)&hubMatrixa;
  _Val.p0.z = v40;
  *(_QWORD *)&_Val.p0.x = _mm_unpacklo_ps(v36, v37).m128_u64[0];
  std::vector<DebugLine>::push_back(result, &_Val);
  return result;
}
vec3f *SuspensionAxle::getHubAngularVelocity(SuspensionAxle *this, vec3f *result)
{
  this->axle->getAngularVelocity(this->axle, result);
  return result;
}
mat44f *SuspensionAxle::getHubWorldMatrix(SuspensionAxle *this, mat44f *result)
{
  mat44f *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4

  ((void (*)(IRigidBody *, mat44f *, _DWORD))this->axle->getWorldMatrix)(this->axle, result, 0);
  v3 = result;
  v4 = result->M12;
  v5 = this->track;
  if ( this->side )
  {
    LODWORD(v5) ^= _xmm;
    v6 = result->M11 * v5;
  }
  else
  {
    v6 = v5 * result->M11;
  }
  v7 = (float)(result->M13 * v5) + result->M43;
  result->M41 = v6 + result->M41;
  v8 = (float)(v4 * v5) + result->M42;
  result->M43 = v7;
  result->M42 = v8;
  return v3;
}
double SuspensionAxle::getMass(SuspensionAxle *this)
{
  return ((double (*)(IRigidBody *))this->axle->getMass)(this->axle) * 0.5;
}
vec3f *SuspensionAxle::getPointVelocity(SuspensionAxle *this, vec3f *result, const vec3f *p)
{
  this->axle->getPointVelocity(this->axle, result, p);
  return result;
}
SuspensionStatus *SuspensionAxle::getStatus(SuspensionAxle *this)
{
  return &this->status;
}
void SuspensionAxle::getSteerBasis(SuspensionAxle *this, vec3f *center, vec3f *axis)
{
  std::wstring *v3; // eax
  std::wstring v4; // [esp+4h] [ebp-28h] BYREF
  int v5; // [esp+28h] [ebp-4h]

  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"SuspensionAxle::getSteerBasis not implemented", 0x2Du);
  v3 = &v4;
  v5 = 0;
  if ( v4._Myres >= 8 )
    v3 = (std::wstring *)v4._Bx._Ptr;
  _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v3->_Bx._Buf);
  ksGenerateCrash();
  if ( v4._Myres >= 8 )
    operator delete(v4._Bx._Ptr);
}
vec3f *SuspensionAxle::getVelocity(SuspensionAxle *this, vec3f *result)
{
  float v2; // xmm0_4
  bool v3; // zf
  IRigidBody *v4; // ecx
  int v6[3]; // [esp+0h] [ebp-Ch] BYREF

  v2 = this->track;
  v3 = this->side == Left;
  v4 = this->axle;
  v6[1] = 0;
  v6[2] = 0;
  if ( !v3 )
    LODWORD(v2) ^= _xmm;
  *(float *)v6 = v2;
  v4->getLocalPointVelocity(v4, result, (const vec3f *)v6);
  return result;
}
void SuspensionAxle::printRollCenter(SuspensionAxle *this, float tyreRadius)
{
  ;
}
void SuspensionAxle::setERPCFM(SuspensionAxle *this, float erp, float cfm)
{
  AxleJoint *v3; // esi
  AxleJoint *i; // edi

  v3 = this->joints._Myfirst;
  for ( i = this->joints._Mylast; v3 != i; ++v3 )
    ((void (*)(IJoint *, _DWORD, _DWORD))v3->ballAxle.joint->setERPCFM)(
      v3->ballAxle.joint,
      LODWORD(erp),
      LODWORD(cfm));
}
void SuspensionAxle::setPositions(SuspensionAxle *this)
{
  mat44f *v2; // eax
  vec3f hubPos; // [esp+20h] [ebp-8Ch] BYREF
  mat44f bodyMatrix; // [esp+2Ch] [ebp-80h] BYREF
  char v5[64]; // [esp+6Ch] [ebp-40h] BYREF

  if ( this->side == Left )
  {
    ((void (*)(IRigidBody *, mat44f *, _DWORD))this->car->body->getWorldMatrix)(
      this->car->body,
      &bodyMatrix,
      0);
    this->car->body->localToWorld(this->car->body, &hubPos, &this->axleBasePos);
    this->axle->setRotation(this->axle, &bodyMatrix);
    this->axle->setPosition(this->axle, &hubPos);
    v2 = (mat44f *)((int (*)(IRigidBody *, char *, _DWORD))this->axle->getWorldMatrix)(this->axle, v5, 0);
    mat44f::print(v2);
  }
}
void SuspensionAxle::step(SuspensionAxle *this, float dt)
{
  float v3; // xmm0_4
  Car *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  IRigidBody *v9; // edi
  __m128 v10; // xmm0
  float v11; // xmm3_4
  __m128 v12; // xmm6
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  SuspensionAxle_vtbl *v23; // eax
  IRigidBody_vtbl *v24; // eax
  vec3f *v25; // eax
  float v26; // xmm1_4
  IRigidBody *v27; // ecx
  IRigidBody_vtbl *v28; // eax
  float *v29; // eax
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  SuspensionAxle_vtbl *v33; // eax
  IRigidBody_vtbl *v34; // eax
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  IRigidBody_vtbl *v38; // eax
  float *v39; // eax
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  SuspensionAxle_vtbl *v43; // eax
  IRigidBody_vtbl *v44; // eax
  float v45; // xmm3_4
  IRigidBody_vtbl *v46; // eax
  float *v47; // eax
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  SuspensionAxle_vtbl *v51; // eax
  IRigidBody_vtbl *v52; // eax
  float v; // xmm2_4
  double v54; // st7
  SuspensionAxle_vtbl *v55; // eax
  IRigidBody_vtbl *v56; // eax
  unsigned __int64 v57; // [esp+B4h] [ebp-100h] BYREF
  float v58; // [esp+BCh] [ebp-F8h]
  float v59; // [esp+C0h] [ebp-F4h]
  float v60; // [esp+C4h] [ebp-F0h]
  float v61; // [esp+C8h] [ebp-ECh]
  float v62; // [esp+CCh] [ebp-E8h]
  float v63; // [esp+D0h] [ebp-E4h]
  float v64; // [esp+D4h] [ebp-E0h] BYREF
  float v65; // [esp+D8h] [ebp-DCh]
  float v66; // [esp+DCh] [ebp-D8h]
  float v67; // [esp+E0h] [ebp-D4h] BYREF
  float v68; // [esp+E4h] [ebp-D0h]
  float v69; // [esp+E8h] [ebp-CCh]
  float v70; // [esp+ECh] [ebp-C8h] BYREF
  float v71; // [esp+F0h] [ebp-C4h]
  float v72; // [esp+F4h] [ebp-C0h]
  float v73; // [esp+F8h] [ebp-BCh] BYREF
  float v74[2]; // [esp+FCh] [ebp-B8h]
  int v75[3]; // [esp+104h] [ebp-B0h] BYREF
  int v76[3]; // [esp+110h] [ebp-A4h] BYREF
  float v77[3]; // [esp+11Ch] [ebp-98h] BYREF
  int v78[12]; // [esp+128h] [ebp-8Ch] BYREF
  float v79; // [esp+158h] [ebp-5Ch]
  float v80; // [esp+15Ch] [ebp-58h]
  float v81; // [esp+160h] [ebp-54h]
  char v82[8]; // [esp+168h] [ebp-4Ch] BYREF
  float v83; // [esp+170h] [ebp-44h]
  char v84[64]; // [esp+174h] [ebp-40h] BYREF

  ((void (*)(IRigidBody *, int *, _DWORD))this->axle->getWorldMatrix)(this->axle, v78, 0);
  v3 = this->track;
  if ( this->side )
    LODWORD(v3) ^= _xmm;
  v4 = this->car;
  v5 = *(float *)v78 * v3;
  v6 = *(float *)&v78[1] * v3;
  v7 = *(float *)&v78[2] * v3;
  v8 = this->attachRelativePos;
  v79 = v79 + (float)(v5 * v8);
  v80 = v80 + (float)(v6 * v8);
  v81 = v81 + (float)(v7 * v8);
  v64 = v79;
  v65 = v80;
  v66 = v81;
  v9 = v4->body;
  v9->worldToLocal(v9, (vec3f *)v75, (const vec3f *)&v64);
  this->getBasePosition(this, (vec3f *)&v73);
  v73 = this->attachRelativePos * v73;
  v74[0] = v74[0] + 0.2;
  v10 = ((__m128 (*)(IRigidBody *, float *, float *))v9->localToWorld)(v9, &v70, &v73);
  v11 = v70 - v64;
  v12 = (__m128)LODWORD(v71);
  v12.m128_f32[0] = v71 - v65;
  v10.m128_f32[0] = v70 - v64;
  v57 = _mm_unpacklo_ps(v10, v12).m128_u64[0];
  v83 = v72 - v66;
  v13 = *((float *)&v57 + 1);
  v58 = v72 - v66;
  v14 = v72 - v66;
  v15 = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v83 * v83);
  v16 = fsqrt(v15);
  if ( v16 == 0.0 )
  {
    v17 = *(float *)&v57;
  }
  else
  {
    v17 = v11 * (float)(1.0 / v16);
    v13 = *((float *)&v57 + 1) * (float)(1.0 / v16);
    v14 = v14 * (float)(1.0 / v16);
  }
  v62 = v17;
  v63 = v13;
  v61 = v14;
  if ( v15 == 0.0 )
    v18 = 0.0;
  else
    v18 = fsqrt(v15);
  v19 = 0.2 - v18;
  v20 = this->progressiveK;
  v21 = v19 + this->rodLength;
  this->status.travel = v21;
  LODWORD(v22) = COERCE_UNSIGNED_INT((float)((float)(v20 * v21) + this->k) * v21) ^ _xmm;
  v60 = v22;
  if ( v22 < 0.0 )
  {
    v23 = this->__vftable;
    *(float *)&v57 = v17 * v22;
    *((float *)&v57 + 1) = v13 * v22;
    v58 = v14 * v22;
    v23->addForceAtPos(this, (const vec3f *)&v57, (const vec3f *)&v64, 0, 0);
    v24 = v9->__vftable;
    *(float *)&v57 = v62 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    *((float *)&v57 + 1) = v63 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    v58 = v61 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    v24->addForceAtPos(v9, (const vec3f *)&v57, (const vec3f *)&v70);
  }
  if ( this->leafSpringK.x != 0.0 )
  {
    v25 = this->getBasePosition(this, v82);
    v26 = *(float *)v75 - (float)(this->attachRelativePos * v25->x);
    v27 = this->car->body;
    v28 = v27->__vftable;
    v59 = this->leafSpringK.x * v26;
    v29 = (float *)((int (*)(IRigidBody *, char *, _DWORD))v28->getWorldMatrix)(v27, v84, 0);
    v30 = *v29;
    v31 = v29[1];
    v32 = v29[2];
    v33 = this->__vftable;
    *(float *)&v57 = v30 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    *((float *)&v57 + 1) = v31 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    v58 = v32 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    v33->addForceAtPos(this, (const vec3f *)&v57, (const vec3f *)&v64, 0, 0);
    v34 = v9->__vftable;
    v57 = LODWORD(v59);
    v58 = 0.0;
    v34->addLocalForceAtLocalPos(v9, (const vec3f *)&v57, (const vec3f *)v75);
  }
  v35 = this->bumpStopUp;
  v36 = *(float *)&v75[1] - this->referenceY;
  v37 = FLOAT_500000_0;
  v59 = v36;
  if ( v35 != 0.0 && v36 > v35 && this->k != 0.0 )
  {
    v38 = v9->__vftable;
    v60 = (float)(v36 - v35) * 500000.0;
    v39 = (float *)((int (*)(IRigidBody *, char *, _DWORD))v38->getWorldMatrix)(v9, v84, 0);
    v40 = v39[4];
    v41 = v39[5];
    v42 = v39[6];
    v43 = this->__vftable;
    *(float *)&v57 = v40 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    *((float *)&v57 + 1) = v41 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    v58 = v42 * COERCE_FLOAT(LODWORD(v60) ^ _xmm);
    v43->addForceAtPos(this, (const vec3f *)&v57, (const vec3f *)&v64, 0, 0);
    v44 = v9->__vftable;
    LODWORD(v57) = 0;
    *((float *)&v57 + 1) = v60;
    v58 = 0.0;
    v44->addLocalForceAtLocalPos(v9, (const vec3f *)&v57, (const vec3f *)v75);
    v36 = v59;
    v37 = FLOAT_500000_0;
  }
  v45 = this->bumpStopDn;
  if ( v45 != 0.0 && v45 > v36 && this->k != 0.0 )
  {
    v46 = v9->__vftable;
    v59 = (float)(v36 - v45) * v37;
    v47 = (float *)((int (*)(IRigidBody *, char *, _DWORD))v46->getWorldMatrix)(v9, v84, 0);
    v48 = v47[4];
    v49 = v47[5];
    v50 = v47[6];
    v51 = this->__vftable;
    *(float *)&v57 = v48 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    *((float *)&v57 + 1) = v49 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    v58 = v50 * COERCE_FLOAT(LODWORD(v59) ^ _xmm);
    v51->addForceAtPos(this, (const vec3f *)&v57, (const vec3f *)&v64, 0, 0);
    v52 = v9->__vftable;
    LODWORD(v57) = 0;
    *((float *)&v57 + 1) = v59;
    v58 = 0.0;
    v52->addLocalForceAtLocalPos(v9, (const vec3f *)&v57, (const vec3f *)v75);
  }
  this->getVelocity(this, (vec3f *)v76);
  v9->getPointVelocity(v9, (vec3f *)v77, (const vec3f *)&v70);
  v = (float)((float)((float)(*(float *)v76 - v77[0]) * v62) + (float)((float)(*(float *)&v76[1] - v77[1]) * v63))
    + (float)((float)(*(float *)&v76[2] - v77[2]) * v61);
  this->status.damperSpeedMS = v;
  v54 = Damper::getForce(&this->damper, v);
  v55 = this->__vftable;
  v60 = v54;
  v67 = v62 * v60;
  v68 = v63 * v60;
  v69 = v61 * v60;
  v55->addForceAtPos(this, (const vec3f *)&v67, (const vec3f *)&v64, 0, 0);
  v56 = v9->__vftable;
  LODWORD(v57) = LODWORD(v67) ^ _xmm;
  HIDWORD(v57) = LODWORD(v68) ^ _xmm;
  LODWORD(v58) = LODWORD(v69) ^ _xmm;
  v56->addForceAtPos(v9, (const vec3f *)&v57, (const vec3f *)&v70);
}
void SuspensionAxle::stop(SuspensionAxle *this)
{
  ((void (*)(IRigidBody *, int))this->axle->stop)(this->axle, 1065353216);
}
