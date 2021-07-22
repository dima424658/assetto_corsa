#include "cameradrivablemanager.h
void __userpurge CameraDrivableManager::CameraDrivableManager(CameraDrivableManager *this@<ecx>, unsigned int a2@<ebx>, Sim *sim, CameraForward *camera)
{
  CameraDrivableManager *v4; // edi
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  int v9; // ecx
  __int128 v10; // xmm3
  __int128 v11; // xmm1
  __int128 v12; // xmm2
  unsigned int v13; // eax
  double v14; // st7
  bool v15; // cf
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // eax
  double v20; // st7
  unsigned int v21; // esi
  Sim *v22; // edi
  CarAvatar *v23; // eax
  std::wstring *v24; // eax
  vec3f *v25; // eax
  __int64 v26; // xmm0_8
  float v27; // eax
  vec3f *v28; // eax
  __int64 v29; // xmm0_8
  float v30; // eax
  std::wstring *v31; // esi
  std::wstring *v32; // esi
  vec3f *v33; // eax
  __int64 v34; // xmm0_8
  int v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // esi
  CarAvatar *v38; // eax
  std::wstring *v39; // eax
  vec3f *v40; // eax
  __int64 v41; // xmm0_8
  float v42; // eax
  double v43; // st7
  unsigned int v44; // esi
  CarAvatar *v45; // eax
  CarAvatar *v46; // eax
  __m128 v47; // xmm1
  float v48; // xmm0_4
  unsigned int v49; // eax
  std::wstring v50; // [esp-1Ch] [ebp-3E0h] BYREF
  Game *v51; // [esp-4h] [ebp-3C8h]
  int v52; // [esp+0h] [ebp-3C4h]
  int v53; // [esp+4h] [ebp-3C0h]
  char v54; // [esp+13h] [ebp-3B1h] BYREF
  unsigned int index; // [esp+14h] [ebp-3B0h]
  Sim *v56; // [esp+18h] [ebp-3ACh]
  float v57; // [esp+1Ch] [ebp-3A8h]
  float v58; // [esp+20h] [ebp-3A4h]
  float v59; // [esp+24h] [ebp-3A0h]
  std::vector<std::wstring> keyes; // [esp+28h] [ebp-39Ch] BYREF
  std::vector<vec3f> *v61; // [esp+34h] [ebp-390h]
  __int64 v62; // [esp+38h] [ebp-38Ch]
  float v63; // [esp+40h] [ebp-384h]
  mat44f v64; // [esp+44h] [ebp-380h] BYREF
  std::vector<std::wstring> *v65; // [esp+88h] [ebp-33Ch]
  std::vector<std::wstring> *v66; // [esp+8Ch] [ebp-338h]
  CarAvatar *v67; // [esp+90h] [ebp-334h]
  std::vector<AxleJoint> *v68; // [esp+94h] [ebp-330h]
  std::vector<std::wstring> *v69; // [esp+98h] [ebp-32Ch]
  CameraDrivableManager *v70; // [esp+9Ch] [ebp-328h]
  vec3f _Val; // [esp+A0h] [ebp-324h] BYREF
  vec3f v72; // [esp+ACh] [ebp-318h] BYREF
  vec3f v73; // [esp+B8h] [ebp-30Ch] BYREF
  __int64 v74; // [esp+D4h] [ebp-2F0h]
  vec3f v75; // [esp+E8h] [ebp-2DCh] BYREF
  std::wstring v76; // [esp+F4h] [ebp-2D0h] BYREF
  std::wstring key; // [esp+10Ch] [ebp-2B8h] BYREF
  std::wstring section; // [esp+124h] [ebp-2A0h] BYREF
  std::wstring v79; // [esp+13Ch] [ebp-288h] BYREF
  std::wstring v80; // [esp+154h] [ebp-270h] BYREF
  std::wstring _Left; // [esp+16Ch] [ebp-258h] BYREF
  std::wstring ifilename; // [esp+184h] [ebp-240h] BYREF
  std::wstring v83; // [esp+19Ch] [ebp-228h] BYREF
  std::wstring _Right; // [esp+1B4h] [ebp-210h] BYREF
  std::wstring result; // [esp+1CCh] [ebp-1F8h] BYREF
  std::wstring filename; // [esp+1E4h] [ebp-1E0h] BYREF
  INIReader v87; // [esp+1FCh] [ebp-1C8h] BYREF
  INIReaderDocuments v88; // [esp+244h] [ebp-180h] BYREF
  INIReader v89; // [esp+28Ch] [ebp-138h] BYREF
  INIReaderDocuments v90; // [esp+2D4h] [ebp-F0h] BYREF
  INIReaderDocuments v91; // [esp+31Ch] [ebp-A8h] BYREF
  INIReader v92; // [esp+364h] [ebp-60h] BYREF
  int v93; // [esp+3C0h] [ebp-4h]

  v4 = this;
  v70 = this;
  v65 = (std::vector<std::wstring> *)this;
  v56 = sim;
  v51 = sim->game;
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"CAMERA_DRIVABLE_MANAGER", 0x17u);
  GameObject::GameObject(v4, v50, v51);
  v4->__vftable = (CameraDrivableManager_vtbl *)&CameraDrivableManager::`vftable';
  v93 = 0;
  v4->chaseCamData[0].distance = 4.5;
  v4->chaseCamData[0].height = 1.9;
  v4->chaseCamData[0].pitchRAD = 0.0;
  v4->chaseCamData[1].distance = 4.5;
  v4->chaseCamData[1].height = 1.9;
  v4->chaseCamData[1].pitchRAD = 0.0;
  v68 = (std::vector<AxleJoint> *)&v4->drivableCameraPositions;
  v4->drivableCameraPositions._Myfirst = 0;
  v4->drivableCameraPositions._Mylast = 0;
  v4->drivableCameraPositions._Myend = 0;
  mat44f::mat44f(&v4->cameraMatrix);
  v4->currentOffset.x = 0.0;
  v4->currentOffset.y = 0.0;
  v4->currentOffset.z = 0.0;
  v61 = &v4->lookBackPoints;
  v4->lookBackPoints._Myfirst = 0;
  v4->lookBackPoints._Mylast = 0;
  v4->lookBackPoints._Myend = 0;
  LOBYTE(v93) = 2;
  v4->isWorldAligned = 0;
  v4->accGXMul = 0.40000001;
  v4->accGZMul = -0.2;
  v4->chaseIndex = 0;
  v4->rotationDegrees = 60.0;
  v4->rotationSpeed = 1.0;
  v4->rotationAnimation = 0.0;
  v4->rotationChase = 0.0;
  v4->sim = sim;
  v4->camera = camera;
  v4->chaseCamFilter = 3.0;
  mat44f::loadIdentity(&v4->cameraMatrix);
  v5 = fsqrt(1.0);
  v6 = FLOAT_N1_0;
  v7 = 0.0;
  v8 = 0.0;
  if ( v5 != 0.0 )
  {
    v7 = (float)(1.0 / v5) * 0.0;
    v8 = v7;
    v6 = (float)(1.0 / v5) * -1.0;
  }
  v4->cameraMatrix.M31 = -0.0;
  v4->cameraMatrix.M32 = -0.0;
  v4->cameraMatrix.M33 = -1.0;
  v4->cameraMatrix.M21 = 0.0;
  v4->cameraMatrix.M22 = 1.0;
  v4->cameraMatrix.M23 = 0.0;
  v4->cameraMatrix.M11 = v6;
  v4->cameraMatrix.M12 = v7;
  v4->cameraMatrix.M13 = v8;
  LODWORD(v57) = __libm_sse2_cosf(v52, v53).m128_u32[0];
  index = __libm_sse2_sinf(v9).m128_u32[0];
  v59 = 1.0 - v57;
  mat44f::mat44f(&v64);
  v64.M44 = 1.0;
  v64.M11 = v59 + v57;
  v64.M22 = (float)(v59 * 0.0) + v57;
  v64.M33 = v64.M22;
  v10 = *(_OWORD *)&v4->cameraMatrix.M41;
  v64.M12 = (float)(*(float *)&index * 0.0) + (float)(v59 * 0.0);
  v64.M21 = (float)(v59 * 0.0) - (float)(*(float *)&index * 0.0);
  v64.M13 = v64.M21;
  v64.M31 = v64.M12;
  v64.M23 = *(float *)&index + (float)(v59 * 0.0);
  v64.M32 = (float)(v59 * 0.0) - *(float *)&index;
  v11 = *(_OWORD *)&v4->cameraMatrix.M21;
  v12 = *(_OWORD *)&v4->cameraMatrix.M31;
  *(__m128 *)&v4->cameraMatrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&v64, *(__m128 *)&v4->cameraMatrix.M11);
  *(_OWORD *)&v4->cameraMatrix.M21 = v11;
  *(_OWORD *)&v4->cameraMatrix.M31 = v12;
  *(_OWORD *)&v4->cameraMatrix.M41 = v10;
  v4->cameraMatrix.M41 = 0.0;
  v4->cameraMatrix.M42 = 1.9;
  v4->cameraMatrix.M43 = -4.5;
  v4->currentMode = eChase;
  v13 = Sim::getFocusedCarIndex(sim);
  v67 = Sim::getCar(sim, v13);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/camera_drivable.ini", 0x1Eu);
  LOBYTE(v93) = 3;
  INIReader::INIReader(&v92, &ifilename);
  LOBYTE(v93) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( v92.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_DEGREES", 0xBu);
    LOBYTE(v93) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ROTATION", 8u);
    LOBYTE(v93) = 7;
    v14 = INIReader::getFloat(&v92, &section, &key);
    v15 = section._Myres < 8;
    v4->rotationDegrees = v14;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SPEED", 5u);
    LOBYTE(v93) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ROTATION", 8u);
    LOBYTE(v93) = 9;
    v16 = INIReader::getFloat(&v92, &section, &key);
    v15 = section._Myres < 8;
    v4->rotationSpeed = v16;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v51 = 0;
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"cfg/camera_manager.ini", 0x16u);
  INIReaderDocuments::INIReaderDocuments(&v91, a2, v50, (bool)v51);
  LOBYTE(v93) = 10;
  if ( v91.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GFORCEX", 7u);
    LOBYTE(v93) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHAKE", 5u);
    LOBYTE(v93) = 12;
    v17 = INIReader::getFloat(&v91, &section, &key);
    v15 = section._Myres < 8;
    v4->accGXMul = v17 * v4->accGXMul;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GFORCEZ", 7u);
    LOBYTE(v93) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHAKE", 5u);
    LOBYTE(v93) = 14;
    v18 = INIReader::getFloat(&v91, &section, &key);
    v15 = section._Myres < 8;
    v4->accGZMul = v18 * v4->accGZMul;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v51 = 0;
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"cfg/camera_onboard.ini", 0x16u);
  INIReaderDocuments::INIReaderDocuments(&v90, a2, v50, (bool)v51);
  LOBYTE(v93) = 15;
  if ( v90.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"IS_WORLD_ALIGNED", 0x10u);
    LOBYTE(v93) = 16;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MODE", 4u);
    LOBYTE(v93) = 17;
    v19 = INIReader::getInt(&v90, &section, &key);
    v15 = section._Myres < 8;
    v4->isWorldAligned = v19 != 0;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 15;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SPEED", 5u);
    LOBYTE(v93) = 18;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ROTATION", 8u);
    LOBYTE(v93) = 19;
    v20 = INIReader::getFloat(&v90, &section, &key);
    v15 = section._Myres < 8;
    v4->rotationSpeed = v20;
    if ( !v15 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v93) = 15;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  *(float *)&v21 = 0.0;
  *(float *)&index = 0.0;
  if ( v56->cars._Mylast - v56->cars._Myfirst )
  {
    v22 = v56;
    do
    {
      _Left._Myres = 7;
      _Left._Mysize = 0;
      _Left._Bx._Buf[0] = 0;
      std::wstring::assign(&_Left, L"content/cars/", 0xDu);
      LOBYTE(v93) = 20;
      v23 = Sim::getCar(v22, v21);
      v24 = std::operator+<wchar_t>(&result, &_Left, &v23->unixName);
      LOBYTE(v93) = 21;
      std::operator+<wchar_t>(&filename, v24, L"/data/car.ini");
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v93) = 24;
      if ( _Left._Myres >= 8 )
        operator delete(_Left._Bx._Ptr);
      _Left._Bx._Buf[0] = 0;
      _Left._Myres = 7;
      _Left._Mysize = 0;
      CarAvatar::openINI(v67, &v87, &filename);
      LOBYTE(v93) = 25;
      *(_OWORD *)&v64.M11 = 0i64;
      v64.M41 = 0.0;
      *(_OWORD *)&v64.M21 = 0i64;
      LOWORD(v64.M42) = 0;
      *(_OWORD *)&v64.M31 = 0i64;
      v57 = 0.0;
      *(float *)&v56 = 0.0;
      v59 = 0.0;
      if ( v87.ready )
      {
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        std::wstring::assign(&v76, L"BUMPER_CAMERA_POS", 0x11u);
        LOBYTE(v93) = 26;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"GRAPHICS", 8u);
        LOBYTE(v93) = 27;
        v25 = INIReader::getFloat3(&v87, &v75, &key, &v76);
        v26 = *(_QWORD *)&v25->x;
        v27 = v25->z;
        *(_QWORD *)&v64.M11 = v26;
        v64.M13 = v27;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v93) = 25;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        std::wstring::assign(&v76, L"BONNET_CAMERA_POS", 0x11u);
        LOBYTE(v93) = 28;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"GRAPHICS", 8u);
        LOBYTE(v93) = 29;
        v28 = INIReader::getFloat3(&v87, &v73, &key, &v76);
        v29 = *(_QWORD *)&v28->x;
        v30 = v28->z;
        *(_QWORD *)&v64.M21 = v29;
        v64.M23 = v30;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        keyes._Myfirst = 0;
        keyes._Mylast = 0;
        keyes._Myend = 0;
        LOBYTE(v93) = 30;
        v51 = (Game *)&keyes;
        std::wstring::wstring(&v50, L"GRAPHICS");
        INIReader::getKeyes(&v87, v50, (std::vector<std::wstring> *)v51);
        v31 = keyes._Mylast;
        LOBYTE(v66) = 0;
        v51 = (Game *)v66;
        if ( std::_Find<std::wstring *,wchar_t const [20]>(
               keyes._Myfirst,
               keyes._Mylast,
               (const wchar_t (*)[20])L"BUMPER_CAMERA_PITCH") != v31 )
        {
          std::wstring::wstring(&v80, L"BUMPER_CAMERA_PITCH");
          LOBYTE(v93) = 31;
          std::wstring::wstring(&v76, L"GRAPHICS");
          LOBYTE(v93) = 32;
          v64.M14 = INIReader::getFloat(&v87, &v76, &v80) * 0.017453;
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v93) = 30;
          if ( v80._Myres >= 8 )
            operator delete(v80._Bx._Ptr);
        }
        v32 = keyes._Mylast;
        LOBYTE(v69) = 0;
        v51 = (Game *)v69;
        if ( std::_Find<std::wstring *,wchar_t const [20]>(
               keyes._Myfirst,
               keyes._Mylast,
               (const wchar_t (*)[20])L"BONNET_CAMERA_PITCH") != v32 )
        {
          std::wstring::wstring(&v80, L"BONNET_CAMERA_PITCH");
          LOBYTE(v93) = 33;
          std::wstring::wstring(&v76, L"GRAPHICS");
          LOBYTE(v93) = 34;
          v64.M24 = INIReader::getFloat(&v87, &v76, &v80) * 0.017453;
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v93) = 30;
          if ( v80._Myres >= 8 )
            operator delete(v80._Bx._Ptr);
        }
        std::wstring::wstring(&v80, L"DRIVABLE_LOOKBACK_OFFSET");
        LOBYTE(v93) = 35;
        std::wstring::wstring(&v76, L"GRAPHICS");
        LOBYTE(v93) = 36;
        v54 = INIReader::hasKey(&v87, &v76, &v80);
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v93) = 30;
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        if ( v54 )
        {
          std::wstring::wstring(&v80, L"DRIVABLE_LOOKBACK_OFFSET");
          LOBYTE(v93) = 37;
          std::wstring::wstring(&v76, L"GRAPHICS");
          LOBYTE(v93) = 38;
          v33 = INIReader::getFloat3(&v87, &v72, &v76, &v80);
          v34 = *(_QWORD *)&v33->x;
          v35 = LODWORD(v33->z);
          v62 = v34;
          v63 = *(float *)&v35;
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          if ( v80._Myres >= 8 )
            operator delete(v80._Bx._Ptr);
          v59 = v63;
          v56 = (Sim *)HIDWORD(v62);
          v57 = *(float *)&v62;
        }
        LOBYTE(v93) = 25;
        if ( keyes._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&keyes);
          v51 = (Game *)v65;
          v50._Myres = (unsigned int)&v54;
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(keyes._Myfirst, keyes._Mylast);
          operator delete(keyes._Myfirst);
          keyes._Myfirst = 0;
          keyes._Mylast = 0;
          keyes._Myend = 0;
        }
      }
      std::wstring::wstring(&v80, L"content/cars/");
      v37 = v36;
      LOBYTE(v93) = 39;
      v38 = Sim::getCar(v22, index);
      v39 = std::operator+<wchar_t>(&key, v37, &v38->unixName);
      LOBYTE(v93) = 40;
      std::operator+<wchar_t>(&v83, v39, L"/data/dash_cam.ini");
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v93) = 43;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Bx._Buf[0] = 0;
      v80._Mysize = 0;
      INIReader::INIReader(&v89, &v83);
      LOBYTE(v93) = 44;
      if ( !v89.ready )
        goto LABEL_87;
      std::wstring::wstring(&v79, L"POS");
      LOBYTE(v93) = 45;
      std::wstring::wstring(&v76, L"DASH_CAM");
      LOBYTE(v93) = 46;
      v40 = INIReader::getFloat3(&v89, (vec3f *)&section, &v76, &v79);
      v41 = *(_QWORD *)&v40->x;
      v42 = v40->z;
      *(_QWORD *)&v64.M32 = v41;
      v64.M34 = v42;
      if ( v76._Myres >= 8 )
        operator delete(v76._Bx._Ptr);
      v76._Myres = 7;
      v76._Mysize = 0;
      v76._Bx._Buf[0] = 0;
      LOBYTE(v93) = 44;
      if ( v79._Myres >= 8 )
        operator delete(v79._Bx._Ptr);
      std::wstring::wstring(&v79, L"EXP");
      LOBYTE(v93) = 47;
      std::wstring::wstring(&v76, L"DASH_CAM");
      LOBYTE(v93) = 48;
      v54 = INIReader::hasKey(&v89, &v76, &v79);
      if ( v76._Myres >= 8 )
        operator delete(v76._Bx._Ptr);
      v76._Myres = 7;
      v76._Mysize = 0;
      v76._Bx._Buf[0] = 0;
      LOBYTE(v93) = 44;
      if ( v79._Myres >= 8 )
        operator delete(v79._Bx._Ptr);
      if ( v54 )
      {
        std::wstring::wstring(&v79, L"EXP");
        LOBYTE(v93) = 49;
        std::wstring::wstring(&v76, L"DASH_CAM");
        LOBYTE(v93) = 50;
        v43 = INIReader::getFloat(&v89, &v76, &v79);
        v44 = index;
        v58 = v43;
        v45 = Sim::getCar(v22, index);
        v45->dashBoardExposure = v58;
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v93) = 44;
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
      }
      else
      {
LABEL_87:
        v44 = index;
      }
      std::wstring::wstring(&_Right, L"cfg/camera_manager.ini");
      v51 = 0;
      LOBYTE(v93) = 51;
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      std::wstring::assign(&v50, &_Right, 0, 0xFFFFFFFF);
      INIReaderDocuments::INIReaderDocuments(&v88, a2, v50, (bool)v51);
      LOBYTE(v93) = 52;
      if ( v88.ready )
      {
        std::wstring::wstring(&v79, L"BONNET_EXTERNAL");
        LOBYTE(v93) = 53;
        std::wstring::wstring(&v76, L"AUDIO");
        LOBYTE(v93) = 54;
        v54 = INIReader::hasKey(&v88, &v76, &v79);
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v93) = 52;
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
        if ( v54 )
        {
          std::wstring::wstring(&v79, L"BONNET_EXTERNAL");
          LOBYTE(v93) = 55;
          std::wstring::wstring(&v76, L"AUDIO");
          LOBYTE(v93) = 56;
          BYTE1(v64.M42) = INIReader::getInt(&v88, &v76, &v79) != 0;
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v93) = 52;
          if ( v79._Myres >= 8 )
            operator delete(v79._Bx._Ptr);
        }
        std::wstring::wstring(&v79, L"BUMPER_EXTERNAL");
        LOBYTE(v93) = 57;
        std::wstring::wstring(&v76, L"AUDIO");
        LOBYTE(v93) = 58;
        v54 = INIReader::hasKey(&v88, &v76, &v79);
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        LOBYTE(v93) = 52;
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
        if ( v54 )
        {
          std::wstring::wstring(&v79, L"BUMPER_EXTERNAL");
          LOBYTE(v93) = 59;
          std::wstring::wstring(&v76, L"AUDIO");
          LOBYTE(v93) = 60;
          LOBYTE(v64.M42) = INIReader::getInt(&v88, &v76, &v79) != 0;
          if ( v76._Myres >= 8 )
            operator delete(v76._Bx._Ptr);
          v76._Myres = 7;
          v76._Mysize = 0;
          v76._Bx._Buf[0] = 0;
          LOBYTE(v93) = 52;
          if ( v79._Myres >= 8 )
            operator delete(v79._Bx._Ptr);
        }
      }
      std::vector<AxleJoint>::push_back(v68, (AxleJoint *)&v64);
      v46 = Sim::getCar(v22, v44);
      v47 = (__m128)_mm_loadu_si128((const __m128i *)&v46->modelBoundaries);
      v74 = *(_QWORD *)&v46->modelBoundaries.top;
      v48 = _mm_shuffle_ps(v47, v47, 255).m128_f32[0] + v46->modelBoundaries.left;
      _Val.y = *(float *)&v56 + *(float *)&v74;
      _Val.z = v59 + _mm_shuffle_ps(v47, v47, 85).m128_f32[0];
      _Val.x = (float)(v48 * 0.5) + v57;
      std::vector<DRSZone>::push_back(v61, &_Val);
      LOBYTE(v93) = 51;
      INIReaderDocuments::~INIReaderDocuments(&v88);
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      LOBYTE(v93) = 43;
      INIReader::~INIReader(&v89);
      if ( v83._Myres >= 8 )
        operator delete(v83._Bx._Ptr);
      v83._Myres = 7;
      v83._Mysize = 0;
      v83._Bx._Buf[0] = 0;
      LOBYTE(v93) = 24;
      INIReader::~INIReader(&v87);
      LOBYTE(v93) = 15;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      v21 = v44 + 1;
      v49 = v22->cars._Mylast - v22->cars._Myfirst;
      index = v21;
    }
    while ( v21 < v49 );
    v4 = v70;
  }
  CameraDrivableManager::initChaseCamFromINI(v4);
  LOBYTE(v93) = 10;
  INIReaderDocuments::~INIReaderDocuments(&v90);
  LOBYTE(v93) = 5;
  INIReaderDocuments::~INIReaderDocuments(&v91);
  LOBYTE(v93) = 2;
  INIReader::~INIReader(&v92);
}
void CameraDrivableManager::~CameraDrivableManager(CameraDrivableManager *this)
{
  std::vector<vec3f> *v2; // esi

  v2 = &this->lookBackPoints;
  this->__vftable = (CameraDrivableManager_vtbl *)&CameraDrivableManager::`vftable';
  if ( this->lookBackPoints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lookBackPoints);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  if ( this->drivableCameraPositions._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->drivableCameraPositions);
    operator delete(this->drivableCameraPositions._Myfirst);
    this->drivableCameraPositions._Myfirst = 0;
    this->drivableCameraPositions._Mylast = 0;
    this->drivableCameraPositions._Myend = 0;
  }
  GameObject::~GameObject(this);
}
CameraDrivableManager *CameraDrivableManager::`vector deleting destructor'(CameraDrivableManager *this, unsigned int a2)
{
  CameraDrivableManager::~CameraDrivableManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraDrivableManager::initChaseCamFromINI(CameraDrivableManager *this)
{
  double v2; // st7
  bool v3; // cf
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  std::wstring section; // [esp+8h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+20h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+38h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+50h] [ebp-54h] BYREF
  int v13; // [esp+A0h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/chase_cam.ini", 0x18u);
  v13 = 0;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v13) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE", 8u);
    LOBYTE(v13) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_0", 7u);
    LOBYTE(v13) = 4;
    v2 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[0].distance = v2;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PITCH", 5u);
    LOBYTE(v13) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_0", 7u);
    LOBYTE(v13) = 6;
    v4 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[0].pitchRAD = v4;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HEIGHT", 6u);
    LOBYTE(v13) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_0", 7u);
    LOBYTE(v13) = 8;
    v5 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[0].height = v5;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE", 8u);
    LOBYTE(v13) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_1", 7u);
    LOBYTE(v13) = 10;
    v6 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[1].distance = v6;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PITCH", 5u);
    LOBYTE(v13) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_1", 7u);
    LOBYTE(v13) = 12;
    v7 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[1].pitchRAD = v7;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HEIGHT", 6u);
    LOBYTE(v13) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHASE_1", 7u);
    LOBYTE(v13) = 14;
    v8 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->chaseCamData[1].height = v8;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v13 = -1;
  INIReader::~INIReader(&ini);
}
void CameraDrivableManager::lookBack(CameraDrivableManager *this)
{
  unsigned int v2; // eax
  CarAvatar *v3; // esi
  CameraForward *v4; // ecx
  float v5; // xmm5_4
  float v6; // xmm1_4
  vec3f lookPoint; // [esp+Ch] [ebp-Ch]

  v2 = Sim::getFocusedCarIndex(this->sim);
  v3 = Sim::getCar(this->sim, v2);
  lookPoint = this->lookBackPoints._Myfirst[Sim::getFocusedCarIndex(this->sim)];
  v4 = this->camera;
  v5 = (float)((float)((float)(v3->bodyMatrix.M22 * lookPoint.y) + (float)(v3->bodyMatrix.M12 * lookPoint.x))
             + (float)(v3->bodyMatrix.M32 * lookPoint.z))
     + v3->bodyMatrix.M42;
  v6 = (float)((float)((float)(v3->bodyMatrix.M23 * lookPoint.y) + (float)(v3->bodyMatrix.M13 * lookPoint.x))
             + (float)(v3->bodyMatrix.M33 * lookPoint.z))
     + v3->bodyMatrix.M43;
  v4->matrix.M41 = (float)((float)((float)(v3->bodyMatrix.M21 * lookPoint.y) + (float)(v3->bodyMatrix.M11 * lookPoint.x))
                         + (float)(v3->bodyMatrix.M31 * lookPoint.z))
                 + v3->bodyMatrix.M41;
  v4->matrix.M42 = v5;
  v4->matrix.M43 = v6;
  Camera::rotateHeading(v4, (int)v3, 3.1415401);
}
char CameraDrivableManager::nextMode(CameraDrivableManager *this)
{
  if ( ++this->currentMode < (eDash|eChase2) )
    return 0;
  this->currentMode = eChase;
  return 1;
}
void CameraDrivableManager::setCurrentCamera(CameraDrivableManager *this, int cameraIndex)
{
  if ( (unsigned int)cameraIndex <= 4 )
    this->currentMode = cameraIndex;
}
void CameraDrivableManager::setDrivableCameraDefAt(CameraDrivableManager *this, int index, DrivableCameraDef def)
{
  int v3; // edx
  DrivableCameraDef *v4; // eax

  v3 = index;
  v4 = this->drivableCameraPositions._Myfirst;
  *(__m128i *)&v4[v3].bumperCameraPos.x = _mm_loadu_si128((const __m128i *)&def);
  *(__m128i *)&v4[v3].bonnetCameraPos.x = _mm_loadu_si128((const __m128i *)&def.bonnetCameraPos);
  *(__m128i *)&v4[v3].chaseCameraPitch = _mm_loadu_si128((const __m128i *)&def.chaseCameraPitch);
  *(_QWORD *)&v4[v3].rotationOffset = *(_QWORD *)&def.rotationOffset;
}
bool CameraDrivableManager::shouldUseInternalSounds(CameraDrivableManager *this)
{
  bool result; // al

  switch ( this->currentMode )
  {
    case eBonnet:
      result = !this->drivableCameraPositions._Myfirst[Sim::getFocusedCarIndex(this->sim)].bonnetExternalSound;
      break;
    case eBumper:
      result = !this->drivableCameraPositions._Myfirst[Sim::getFocusedCarIndex(this->sim)].bumperExternalSound;
      break;
    case eDash:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
void CameraDrivableManager::update(CameraDrivableManager *this, float deltaT)
{
  Sim *v3; // ecx
  unsigned int v4; // eax
  float v5; // xmm0_4
  unsigned int v6; // eax
  float v7; // eax
  unsigned int v8; // eax

  this->camera->chromaticAberrationEnabled = 0;
  this->camera->lensFlare = 1;
  this->camera->tripleScreenAvailable = 1;
  this->camera->nearPlane = 0.1;
  this->camera->farPlane = 15000.0;
  switch ( this->currentMode )
  {
    case eChase:
      this->chaseIndex = 0;
      goto LABEL_3;
    case eChase2:
      this->chaseIndex = 1;
LABEL_3:
      CameraDrivableManager::updateChase(this, (int)this, deltaT);
      break;
    case eBonnet:
      CameraDrivableManager::updateBonnet(this, deltaT);
      break;
    case eBumper:
      CameraDrivableManager::updateBumper(this, deltaT);
      break;
    case eDash:
      CameraDrivableManager::updateDash(this, deltaT);
      break;
    default:
      break;
  }
  v3 = this->sim;
  if ( this->currentMode == eDash )
  {
    v4 = Sim::getFocusedCarIndex(v3);
    v5 = Sim::getCar(this->sim, v4)->dashBoardExposure;
    v6 = Sim::getFocusedCarIndex(this->sim);
    if ( v5 == 0.0 )
      v7 = Sim::getCar(this->sim, v6)->onBoardExposure;
    else
      v7 = Sim::getCar(this->sim, v6)->dashBoardExposure;
  }
  else
  {
    v8 = Sim::getFocusedCarIndex(v3);
    v7 = Sim::getCar(this->sim, v8)->outBoardExposure;
  }
  this->camera->exposure = v7;
  this->camera->minExposure = this->sim->hdrLevels.minExposure;
  this->camera->maxExposure = this->sim->hdrLevels.maxExposure;
  CameraDrivableManager::updateLook(this, deltaT);
}
void CameraDrivableManager::updateBonnet(CameraDrivableManager *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // esi
  float v5; // xmm4_4
  float v6; // xmm6_4
  CameraForward *v7; // ecx
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  unsigned int v14; // eax
  unsigned int v15; // ecx
  DrivableCameraDef *v16; // eax
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  CameraForward *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm1_4
  unsigned int v23; // eax
  CarAvatar *v24; // eax
  float v25; // [esp+18h] [ebp-10h]
  float v26; // [esp+20h] [ebp-8h]
  float v27; // [esp+24h] [ebp-4h]

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  CameraShadowMapped::setShadowMapsSplits(this->camera, 2.0, 30.0, 150.0, 500.0);
  this->camera->fov = 60.0;
  v5 = v4->physicsState.worldMatrix.M23;
  v6 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M32) ^ _xmm) * -1.0;
  v7 = this->camera;
  v8 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M33) ^ _xmm) * -1.0;
  v9 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M31) ^ _xmm) * -1.0;
  v25 = v4->physicsState.worldMatrix.M22;
  v10 = (float)(v6 * v5) - (float)(v8 * v25);
  v27 = v5;
  v26 = v4->physicsState.worldMatrix.M21;
  v11 = (float)(v8 * v26) - (float)(v9 * v5);
  v12 = (float)(v9 * v25) - (float)(v6 * v26);
  v13 = fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
  if ( v13 != 0.0 )
  {
    v10 = v10 * (float)(1.0 / v13);
    v12 = (float)(1.0 / v13) * v12;
    v11 = (float)(1.0 / v13) * v11;
  }
  v7->matrix.M11 = v10;
  LODWORD(v7->matrix.M31) = LODWORD(v9) ^ _xmm;
  LODWORD(v7->matrix.M32) = LODWORD(v6) ^ _xmm;
  v7->matrix.M21 = v26;
  v7->matrix.M22 = v25;
  LODWORD(v7->matrix.M33) = LODWORD(v8) ^ _xmm;
  v7->matrix.M23 = v27;
  v7->matrix.M12 = v11;
  v7->matrix.M13 = v12;
  v14 = Sim::getFocusedCarIndex(this->sim);
  Camera::rotatePitch(this->camera, (int)v4, this->drivableCameraPositions._Myfirst[v14].bonnetCameraPitch);
  v15 = Sim::getFocusedCarIndex(this->sim);
  v16 = this->drivableCameraPositions._Myfirst;
  v17 = v16[v15].bonnetCameraPos.y;
  v18 = v16[v15].bonnetCameraPos.x;
  v19 = v16[v15].bonnetCameraPos.z;
  v20 = this->camera;
  v21 = (float)((float)((float)(v4->physicsState.worldMatrix.M12 * v18) + (float)(v4->physicsState.worldMatrix.M22 * v17))
              + (float)(v4->physicsState.worldMatrix.M32 * v19))
      + v4->physicsState.worldMatrix.M42;
  v22 = (float)((float)((float)(v4->physicsState.worldMatrix.M13 * v18) + (float)(v4->physicsState.worldMatrix.M23 * v17))
              + (float)(v4->physicsState.worldMatrix.M33 * v19))
      + v4->physicsState.worldMatrix.M43;
  v20->matrix.M41 = (float)((float)((float)(v4->physicsState.worldMatrix.M21 * v17)
                                  + (float)(v4->physicsState.worldMatrix.M11 * v18))
                          + (float)(v4->physicsState.worldMatrix.M31 * v19))
                  + v4->physicsState.worldMatrix.M41;
  v20->matrix.M42 = v21;
  v20->matrix.M43 = v22;
  v20->dofFactor = 0.0;
  this->camera->nearPlane = 0.050000001;
  v23 = Sim::getFocusedCarIndex(this->sim);
  v24 = Sim::getCar(this->sim, v23);
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &v24->physicsState.velocity);
}
void CameraDrivableManager::updateBumper(CameraDrivableManager *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // edi
  float v5; // xmm4_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  CameraForward *v15; // ecx
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm1_4
  unsigned int v20; // eax
  unsigned int v21; // ecx
  DrivableCameraDef *v22; // eax
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  CameraForward *v26; // eax
  float v27; // xmm3_4
  float v28; // xmm1_4
  unsigned int v29; // eax
  CarAvatar *v30; // eax
  float v31; // [esp+18h] [ebp-14h]
  float v32; // [esp+1Ch] [ebp-10h]
  float v33; // [esp+20h] [ebp-Ch]
  float v34; // [esp+24h] [ebp-8h]

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  CameraShadowMapped::setShadowMapsSplits(this->camera, 10.0, 50.0, 150.0, 500.0);
  this->camera->fov = 60.0;
  this->camera->nearPlane = 0.050000001;
  v5 = v4->bodyMatrix.M21;
  v6 = COERCE_FLOAT(LODWORD(v4->bodyMatrix.M32) ^ _xmm) * -1.0;
  v7 = COERCE_FLOAT(LODWORD(v4->bodyMatrix.M31) ^ _xmm) * -1.0;
  v8 = COERCE_FLOAT(LODWORD(v4->bodyMatrix.M33) ^ _xmm) * -1.0;
  v31 = v4->bodyMatrix.M23;
  v9 = v4->bodyMatrix.M22;
  v34 = v8;
  v32 = v5;
  v33 = v9;
  v10 = fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
  if ( v10 != 0.0 )
  {
    v8 = v8 * (float)(1.0 / v10);
    v7 = v7 * (float)(1.0 / v10);
    v6 = v6 * (float)(1.0 / v10);
    v34 = v8;
  }
  v11 = fsqrt((float)((float)(v9 * v9) + (float)(v5 * v5)) + (float)(v31 * v31));
  if ( v11 == 0.0 )
  {
    v14 = v4->bodyMatrix.M23;
  }
  else
  {
    v5 = (float)(1.0 / v11) * v5;
    v12 = 1.0 / v11;
    v32 = v5;
    v13 = v12 * v9;
    v14 = v12 * v31;
    v33 = v13;
    v31 = v14;
  }
  v15 = this->camera;
  v16 = (float)(v14 * v6) - (float)(v33 * v8);
  v17 = (float)(v5 * v8) - (float)(v31 * v7);
  v18 = (float)(v33 * v7) - (float)(v32 * v6);
  v19 = fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18));
  if ( v19 != 0.0 )
  {
    v18 = v18 * (float)(1.0 / v19);
    v16 = (float)(1.0 / v19) * v16;
    v17 = (float)(1.0 / v19) * v17;
  }
  LODWORD(v15->matrix.M31) = LODWORD(v7) ^ _xmm;
  LODWORD(v15->matrix.M33) = LODWORD(v34) ^ _xmm;
  v15->matrix.M21 = v32;
  v15->matrix.M22 = v33;
  LODWORD(v15->matrix.M32) = LODWORD(v6) ^ _xmm;
  v15->matrix.M23 = v31;
  v15->matrix.M11 = v16;
  v15->matrix.M12 = v17;
  v15->matrix.M13 = v18;
  v20 = Sim::getFocusedCarIndex(this->sim);
  Camera::rotatePitch(this->camera, (int)this, this->drivableCameraPositions._Myfirst[v20].bumperCameraPitch);
  v21 = Sim::getFocusedCarIndex(this->sim);
  v22 = this->drivableCameraPositions._Myfirst;
  v23 = v22[v21].bumperCameraPos.x;
  v24 = v22[v21].bumperCameraPos.y;
  v25 = v22[v21].bumperCameraPos.z;
  v26 = this->camera;
  v27 = (float)((float)((float)(v4->physicsState.worldMatrix.M12 * v23) + (float)(v4->physicsState.worldMatrix.M22 * v24))
              + (float)(v4->physicsState.worldMatrix.M32 * v25))
      + v4->physicsState.worldMatrix.M42;
  v28 = (float)((float)((float)(v4->physicsState.worldMatrix.M13 * v23) + (float)(v4->physicsState.worldMatrix.M23 * v24))
              + (float)(v4->physicsState.worldMatrix.M33 * v25))
      + v4->physicsState.worldMatrix.M43;
  v26->matrix.M41 = (float)((float)((float)(v4->physicsState.worldMatrix.M21 * v24)
                                  + (float)(v23 * v4->physicsState.worldMatrix.M11))
                          + (float)(v4->physicsState.worldMatrix.M31 * v25))
                  + v4->physicsState.worldMatrix.M41;
  v26->matrix.M42 = v27;
  v26->matrix.M43 = v28;
  v26->dofFactor = 0.0;
  v29 = Sim::getFocusedCarIndex(this->sim);
  v30 = Sim::getCar(this->sim, v29);
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &v30->physicsState.velocity);
}
void __userpurge CameraDrivableManager::updateChase(CameraDrivableManager *this@<ecx>, int a2@<esi>, float dt)
{
  unsigned int v4; // eax
  CarAvatar *v5; // eax
  int v6; // ecx
  float v7; // xmm2_4
  bool v8; // cf
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // ecx
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // edx
  float v23; // xmm5_4
  __int64 v24; // xmm0_8
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  float v27; // xmm7_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  __int64 v30; // xmm2_8
  int v31; // eax
  float v32; // xmm2_4
  float v33; // xmm3_4
  __m128 v34; // xmm6
  unsigned int v35; // xmm1_4
  __m128 v36; // xmm7
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm5_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm5_4
  _DWORD *v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  const __m128i *v58; // eax
  CameraForward *v59; // ecx
  unsigned int v60; // eax
  int v61; // eax
  float v62; // xmm4_4
  float v63; // xmm0_4
  float v64; // xmm5_4
  float v65; // xmm5_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm1_4
  float v71; // esi
  _DWORD *v72; // eax
  float v73; // xmm7_4
  float v74; // xmm3_4
  float v75; // xmm5_4
  float v76; // xmm2_4
  float v77; // xmm1_4
  float v78; // xmm4_4
  float v79; // xmm2_4
  int v80; // xmm3_4
  float v81; // xmm0_4
  int v82; // xmm2_4
  float v83; // xmm0_4
  int v84; // xmm1_4
  float v85; // xmm1_4
  Sim *v86; // ecx
  float v87; // xmm3_4
  float v88; // xmm2_4
  unsigned int v89; // eax
  Node *v90; // eax
  float v91; // xmm3_4
  float v92; // xmm2_4
  float v93; // xmm1_4
  CameraForward *v94; // eax
  float *v95; // eax
  float v96; // xmm0_4
  float v97; // xmm2_4
  float v98; // xmm2_4
  float v99; // esi
  float v100; // xmm0_4
  float v101; // xmm3_4
  float v102; // xmm1_4
  _DWORD *v103; // eax
  float v104; // xmm7_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm6_4
  int v108; // xmm1_4
  float v109; // xmm0_4
  int v110; // xmm2_4
  float v111; // xmm6_4
  int v112; // xmm0_4
  Sim *v113; // ecx
  float v114; // xmm0_4
  float v115; // xmm2_4
  float v116; // xmm1_4
  unsigned int v117; // eax
  Node *v118; // eax
  float v119; // xmm3_4
  float v120; // xmm2_4
  float v121; // xmm1_4
  CameraForward *v122; // eax
  CameraForward *v123; // esi
  float v124; // xmm1_4
  float v125; // xmm0_4
  const __m128i *v126; // eax
  unsigned int v127; // eax
  CarAvatar *v128; // eax
  int v129; // [esp+10h] [ebp-88h]
  int v130; // [esp+14h] [ebp-84h]
  mat44f result; // [esp+18h] [ebp-80h] BYREF
  vec3f cameraTarget; // [esp+58h] [ebp-40h] BYREF
  vec3f cameraPosition; // [esp+64h] [ebp-34h] BYREF
  float v134; // [esp+70h] [ebp-28h]
  float v135; // [esp+74h] [ebp-24h]
  float v136; // [esp+78h] [ebp-20h]
  float v137; // [esp+7Ch] [ebp-1Ch]
  float v138; // [esp+80h] [ebp-18h]
  float v139; // [esp+84h] [ebp-14h]
  float v140; // [esp+88h] [ebp-10h]
  float v141; // [esp+8Ch] [ebp-Ch]
  float v142; // [esp+90h] [ebp-8h]
  float v143; // [esp+94h] [ebp-4h]
  float dta; // [esp+9Ch] [ebp+4h]
  float dtc; // [esp+9Ch] [ebp+4h]
  float dtd; // [esp+9Ch] [ebp+4h]
  float dtb; // [esp+9Ch] [ebp+4h]
  float dte; // [esp+9Ch] [ebp+4h]
  float dtf; // [esp+9Ch] [ebp+4h]

  mat44f::loadIdentity(&this->cameraMatrix);
  v4 = Sim::getFocusedCarIndex(this->sim);
  *(float *)&v5 = COERCE_FLOAT(Sim::getCar(this->sim, v4));
  v6 = this->chaseIndex;
  v7 = 0.0;
  v138 = *(float *)&v5;
  v8 = v5->physicsState.worldMatrix.M22 > 0.0;
  v9 = this->chaseCamData[v6].height;
  LODWORD(v10) = LODWORD(this->chaseCamData[v6].distance) ^ _xmm;
  this->cameraMatrix.M41 = 0.0;
  this->cameraMatrix.M43 = v10;
  if ( !v8 )
    LODWORD(v9) ^= _xmm;
  this->cameraMatrix.M42 = v9;
  v141 = (float)(v5->physicsState.speed.value * 3.5999999) * 0.1;
  if ( v141 <= 1.0 )
  {
    if ( v141 >= 0.0 )
      goto LABEL_7;
  }
  else
  {
    v7 = FLOAT_1_0;
  }
  v141 = v7;
LABEL_7:
  CameraShadowMapped::setShadowMapsSplits(this->camera, 10.0, 50.0, 150.0, 500.0);
  v11 = v138;
  v12 = FLOAT_0_5;
  v13 = this->cameraMatrix.M42;
  v14 = FLOAT_N0_5;
  v15 = *(float *)(LODWORD(v138) + 1992) * this->accGXMul;
  cameraPosition.y = v13;
  if ( v15 <= 0.5 )
  {
    if ( v15 < -0.5 )
      v15 = FLOAT_N0_5;
  }
  else
  {
    v15 = FLOAT_0_5;
  }
  v16 = *(float *)(LODWORD(v138) + 2000) * this->accGZMul;
  v17 = (float)(v15 * v141) + this->cameraMatrix.M41;
  cameraPosition.x = v17;
  if ( v16 <= 0.5 )
  {
    if ( v16 >= -0.5 )
      v14 = v16;
  }
  else
  {
    v14 = FLOAT_0_5;
  }
  v18 = this->currentOffset.y;
  v19 = (float)(v14 * v141) + this->cameraMatrix.M43;
  v20 = (float)(this->currentOffset.x - v17) * (float)(this->currentOffset.x - v17);
  v21 = this->currentOffset.z - v19;
  cameraPosition.z = v19;
  v22 = v19;
  if ( (float)((float)((float)((float)(v18 - v13) * (float)(v18 - v13)) + v20) + (float)(v21 * v21)) >= 2.0 )
  {
    v30 = *(_QWORD *)&cameraPosition.x;
    *(_QWORD *)&this->currentOffset.x = *(_QWORD *)&cameraPosition.x;
    this->currentOffset.z = v19;
  }
  else
  {
    v23 = this->chaseCamFilter * dt;
    v24 = *(_QWORD *)&this->currentOffset.x;
    cameraTarget.z = this->currentOffset.z;
    *(_QWORD *)&cameraTarget.x = v24;
    if ( v23 <= 1.0 )
    {
      if ( v23 < 0.0 )
        v23 = 0.0;
    }
    else
    {
      v23 = FLOAT_1_0;
    }
    v25 = (__m128)LODWORD(cameraTarget.x);
    v26 = (__m128)LODWORD(cameraTarget.y);
    v27 = (float)(v13 - cameraTarget.y) * v23;
    v28 = (float)(v19 - cameraTarget.z) * v23;
    v25.m128_f32[0] = cameraTarget.x + (float)((float)(v17 - cameraTarget.x) * v23);
    v12 = FLOAT_0_5;
    v26.m128_f32[0] = cameraTarget.y + v27;
    v29 = cameraTarget.z + v28;
    *(_QWORD *)&this->currentOffset.x = _mm_unpacklo_ps(v25, v26).m128_u64[0];
    v30 = *(_QWORD *)&cameraPosition.x;
    cameraTarget.z = v29;
    this->currentOffset.z = v29;
  }
  if ( (float)(*(float *)(LODWORD(v11) + 1056) * 3.5999999) < 2.0 )
  {
    *(_QWORD *)&this->currentOffset.x = v30;
    this->currentOffset.z = v22;
  }
  v31 = *(_DWORD *)(LODWORD(v11) + 272);
  v32 = *(float *)(LODWORD(v11) + 680) + *(float *)(LODWORD(v11) + 744);
  v33 = *(float *)(LODWORD(v11) + 684) + *(float *)(LODWORD(v11) + 748);
  v34 = (__m128)_mm_loadu_si128((const __m128i *)(v31 + 20));
  v35 = _mm_loadu_si128((const __m128i *)(v31 + 4)).m128i_u32[0];
  *(__m128i *)&result.M41 = _mm_loadu_si128((const __m128i *)(v31 + 52));
  v36 = (__m128)_mm_loadu_si128((const __m128i *)(v31 + 36));
  v37 = this->currentOffset.z;
  v38 = v33 * v12;
  v39 = (float)(*(float *)(LODWORD(v11) + 676) + *(float *)(LODWORD(v11) + 740)) * v12;
  v40 = v32 * v12;
  v41 = *(float *)&v35;
  v139 = v39;
  v42 = *(float *)(v31 + 8);
  v140 = v40;
  v43 = this->currentOffset.x;
  v137 = v38;
  v44 = this->currentOffset.y;
  v45 = (float)((float)(v41 * v43) + (float)(v34.m128_f32[0] * v44)) + (float)(v36.m128_f32[0] * v37);
  v46 = _mm_shuffle_ps(v34, v34, 85).m128_f32[0];
  v34.m128_f32[0] = *(float *)(v31 + 28) * v44;
  v47 = (float)(v42 * v43) + (float)(v46 * v44);
  v48 = _mm_shuffle_ps(v36, v36, 85).m128_f32[0] * v37;
  v36.m128_f32[0] = *(float *)(v31 + 44) * v37;
  v49 = v137;
  v50 = v47 + v48;
  v51 = *(float *)(v31 + 12);
  v52 = v50 + v140;
  v53 = v45 + v139;
  this->camera->fov = 60.0;
  v54 = *(_DWORD **)(LODWORD(v11) + 272);
  cameraPosition.y = v52;
  cameraPosition.x = v53;
  v55 = (float)((float)(v51 * v43) + v34.m128_f32[0]) + v36.m128_f32[0];
  LODWORD(v56) = v54[10] ^ _xmm;
  LODWORD(v57) = v54[11] ^ _xmm;
  cameraPosition.z = v55 + v49;
  cameraTarget.x = v139 + (float)(COERCE_FLOAT(v54[9] ^ _xmm) * -4.0);
  cameraTarget.y = v140 + (float)(v56 * -4.0);
  cameraTarget.z = v49 + (float)(v57 * -4.0);
  v58 = (const __m128i *)mat44f::createTarget(&result, &cameraPosition, &cameraTarget);
  v59 = this->camera;
  *(__m128i *)&v59->matrix.M11 = _mm_loadu_si128(v58);
  *(__m128i *)&v59->matrix.M21 = _mm_loadu_si128(v58 + 1);
  *(__m128i *)&v59->matrix.M31 = _mm_loadu_si128(v58 + 2);
  *(__m128i *)&v59->matrix.M41 = _mm_loadu_si128(v58 + 3);
  this->camera->dofFactor = 0.0;
  this->camera->nearPlane = 1.0;
  Camera::rotatePitch(this->camera, a2, this->chaseCamData[this->chaseIndex].pitchRAD);
  dta = this->rotationSpeed * dt;
  v60 = Sim::getFocusedCarIndex(this->sim);
  v61 = Sim::getCar(this->sim, v60)->physicsState.actionsState.state;
  if ( (v61 & 0x200) != 0 || (v61 & 1) != 0 && (v61 & 2) != 0 )
  {
    LODWORD(v137) = __libm_sse2_cosf(v129, v130).m128_u32[0];
    LODWORD(v139) = __libm_sse2_sinf().m128_u32[0];
    dte = 1.0 - v137;
    mat44f::mat44f(&result);
    v98 = dte * 0.0;
    v99 = v138;
    v100 = v139 * 0.0;
    v101 = this->cameraMatrix.M41;
    v102 = (float)(dte * 0.0) + v137;
    dtf = dte + v137;
    v103 = *(_DWORD **)(LODWORD(v138) + 272);
    v104 = v98 - (float)(v139 * 0.0);
    v141 = v102;
    v134 = (float)(v139 * 0.0) + v98;
    v140 = v98 - v139;
    v139 = v139 + v98;
    v142 = v134;
    v105 = this->cameraMatrix.M42;
    v137 = v98 - v100;
    v106 = this->cameraMatrix.M43 - 2.0;
    v136 = (float)((float)((float)(v104 * v105) + (float)(v141 * v101)) + (float)(v139 * v106)) + result.M41;
    v135 = (float)((float)((float)(dtf * v105) + (float)(v134 * v101)) + (float)(v137 * v106)) + result.M42;
    v107 = v134 * v105;
    v108 = v103[11];
    v109 = v141 * v106;
    v110 = v103[9];
    v111 = (float)(v107 + (float)(v140 * v101)) + v109;
    v112 = v103[10];
    v143 = v111 + result.M43;
    v113 = this->sim;
    v114 = COERCE_FLOAT(v112 ^ _xmm) * -4.0;
    v115 = COERCE_FLOAT(v110 ^ _xmm) * -4.0;
    v116 = COERCE_FLOAT(v108 ^ _xmm) * -4.0;
    v138 = (float)((float)((float)(v115 * v141) + (float)(v104 * v114)) + (float)(v139 * v116)) + result.M41;
    dtb = (float)((float)((float)(dtf * v114) + (float)(v134 * v115)) + (float)(v137 * v116)) + result.M42;
    v142 = (float)((float)((float)(v134 * v114) + (float)(v140 * v115)) + (float)(v141 * v116)) + result.M43;
    v117 = Sim::getFocusedCarIndex(v113);
    v118 = Sim::getCar(this->sim, v117)->bodyTransform;
    v119 = (float)((float)((float)(v118->matrix.M21 * v135) + (float)(v136 * v118->matrix.M11))
                 + (float)(v118->matrix.M31 * v143))
         + v118->matrix.M41;
    v120 = (float)((float)((float)(v118->matrix.M22 * v135) + (float)(v118->matrix.M12 * v136))
                 + (float)(v118->matrix.M32 * v143))
         + v118->matrix.M42;
    v121 = (float)((float)((float)(v118->matrix.M23 * v135) + (float)(v118->matrix.M13 * v136))
                 + (float)(v118->matrix.M33 * v143))
         + v118->matrix.M43;
    v122 = this->camera;
    v122->matrix.M42 = v120;
    v122->matrix.M41 = v119;
    v122->matrix.M43 = v121;
    v95 = *(float **)(LODWORD(v99) + 272);
    v96 = v95[13] + v138;
    v97 = v95[15] + v142;
    goto LABEL_62;
  }
  v62 = FLOAT_N1_0;
  if ( (v61 & 1) != 0 )
  {
    v63 = FLOAT_1_0;
  }
  else if ( (v61 & 2) != 0 )
  {
    v63 = FLOAT_N1_0;
  }
  else
  {
    v63 = 0.0;
  }
  v64 = this->rotationChase;
  if ( v64 != 0.0 )
  {
    if ( v63 == 0.0 )
    {
      if ( COERCE_FLOAT(LODWORD(v64) & _xmm) <= (float)((float)(dta * 2.0) * 0.017453) )
        goto LABEL_59;
      if ( v64 <= 0.0 )
        v66 = v64 >= 0.0 ? 0.0 : FLOAT_N1_0;
      else
        v66 = FLOAT_1_0;
      if ( v64 <= 0.0 )
        v67 = v64 >= 0.0 ? 0.0 : FLOAT_N1_0;
      else
        v67 = FLOAT_1_0;
      this->rotationChase = COERCE_FLOAT(COERCE_UNSIGNED_INT(v67 * dta) ^ _xmm) + v64;
      if ( v66 <= 0.0 )
        v68 = v66 >= 0.0 ? 0.0 : FLOAT_N1_0;
      else
        v68 = FLOAT_1_0;
      v69 = this->rotationChase;
      if ( v69 <= 0.0 )
      {
        if ( v69 >= 0.0 )
          v62 = 0.0;
      }
      else
      {
        v62 = FLOAT_1_0;
      }
      if ( v68 != v62 )
LABEL_59:
        this->rotationChase = 0.0;
      goto LABEL_60;
    }
LABEL_36:
    v65 = v64 + (float)(v63 * dta);
    if ( (float)(this->rotationDegrees * 0.017453) > COERCE_FLOAT(LODWORD(v65) & _xmm) )
      this->rotationChase = v65;
LABEL_60:
    LODWORD(v139) = __libm_sse2_cosf(v129, v130).m128_u32[0];
    LODWORD(v140) = __libm_sse2_sinf().m128_u32[0];
    dtc = 1.0 - v139;
    mat44f::mat44f(&result);
    v70 = dtc * 0.0;
    v71 = v138;
    dtd = dtc + v139;
    v72 = *(_DWORD **)(LODWORD(v138) + 272);
    v73 = (float)(v140 * 0.0) + v70;
    v74 = v70 - v140;
    v75 = v140 + v70;
    v139 = v139 + v70;
    v143 = v70 - (float)(v140 * 0.0);
    v142 = this->cameraMatrix.M42;
    v141 = v73;
    v76 = this->cameraMatrix.M41;
    v137 = v143;
    v77 = this->cameraMatrix.M43;
    v136 = v74;
    v140 = v75;
    v134 = (float)((float)((float)(v142 * v143) + (float)(v76 * v139)) + (float)(v77 * v75)) + result.M41;
    v78 = v76 * v73;
    v79 = v76 * v74;
    v80 = v72[9];
    v81 = (float)(v142 * v73) + v79;
    v82 = v72[11];
    v135 = (float)((float)(v78 + (float)(v142 * dtd)) + (float)(v77 * v143)) + result.M42;
    v83 = v81 + (float)(v77 * v139);
    v84 = v72[10];
    v142 = v83 + result.M43;
    v85 = COERCE_FLOAT(v84 ^ _xmm) * -4.0;
    v86 = this->sim;
    v87 = COERCE_FLOAT(v80 ^ _xmm) * -4.0;
    v88 = COERCE_FLOAT(v82 ^ _xmm) * -4.0;
    v143 = v143 * v85;
    v143 = (float)((float)(v143 + (float)(v139 * v87)) + (float)(v75 * v88)) + result.M41;
    dtb = (float)((float)((float)(dtd * v85) + (float)(v73 * v87)) + (float)(v137 * v88)) + result.M42;
    v141 = (float)((float)((float)(v73 * v85) + (float)(v136 * v87)) + (float)(v139 * v88)) + result.M43;
    v89 = Sim::getFocusedCarIndex(v86);
    v90 = Sim::getCar(this->sim, v89)->bodyTransform;
    v91 = (float)((float)((float)(v90->matrix.M21 * v135) + (float)(v134 * v90->matrix.M11))
                + (float)(v90->matrix.M31 * v142))
        + v90->matrix.M41;
    v92 = (float)((float)((float)(v90->matrix.M22 * v135) + (float)(v90->matrix.M12 * v134))
                + (float)(v90->matrix.M32 * v142))
        + v90->matrix.M42;
    v93 = (float)((float)((float)(v90->matrix.M23 * v135) + (float)(v90->matrix.M13 * v134))
                + (float)(v90->matrix.M33 * v142))
        + v90->matrix.M43;
    v94 = this->camera;
    v94->matrix.M42 = v92;
    v94->matrix.M41 = v91;
    v94->matrix.M43 = v93;
    v95 = *(float **)(LODWORD(v71) + 272);
    v96 = v95[13] + v143;
    v97 = v95[15] + v141;
LABEL_62:
    v123 = this->camera;
    v124 = v95[14] + dtb;
    cameraTarget.x = v96;
    cameraPosition.x = v123->matrix.M41;
    cameraPosition.y = v123->matrix.M42;
    v125 = v123->matrix.M43;
    cameraTarget.y = v124;
    cameraTarget.z = v97;
    cameraPosition.z = v125;
    v126 = (const __m128i *)mat44f::createTarget(&result, &cameraPosition, &cameraTarget);
    *(__m128i *)&v123->matrix.M11 = _mm_loadu_si128(v126);
    *(__m128i *)&v123->matrix.M21 = _mm_loadu_si128(v126 + 1);
    *(__m128i *)&v123->matrix.M31 = _mm_loadu_si128(v126 + 2);
    *(__m128i *)&v123->matrix.M41 = _mm_loadu_si128(v126 + 3);
    goto LABEL_63;
  }
  if ( v63 != 0.0 )
    goto LABEL_36;
LABEL_63:
  v127 = Sim::getFocusedCarIndex(this->sim);
  v128 = Sim::getCar(this->sim, v127);
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &v128->physicsState.velocity);
}
void CameraDrivableManager::updateDash(CameraDrivableManager *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // esi
  CameraForward *v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int v14; // ecx
  DrivableCameraDef *v15; // eax
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  CameraForward *v19; // eax
  Sim *v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm1_4
  unsigned int v23; // eax
  CarAvatar *v24; // eax
  float v25; // [esp+18h] [ebp-10h]
  float v26; // [esp+1Ch] [ebp-Ch]
  float v27; // [esp+20h] [ebp-8h]

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  CameraShadowMapped::setShadowMapsSplits(this->camera, 1.3, 80.0, 250.0, 500.0);
  this->camera->farPlane = this->sim->cameraManager->cameraOnBoard->farPlane;
  this->camera->nearPlane = 0.050000001;
  std::wstring::assign(&this->camera->name, L"DASH_CAMERA", 0xBu);
  this->camera->lensFlare = 0;
  this->camera->fov = this->sim->cameraManager->cameraOnBoard->onBoardFov;
  this->camera->dofFactor = 0.0;
  v25 = v4->physicsState.worldMatrix.M23;
  v5 = this->camera;
  v27 = v4->physicsState.worldMatrix.M22;
  v26 = v4->physicsState.worldMatrix.M21;
  v6 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M33) ^ _xmm) * -1.0;
  v7 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M32) ^ _xmm) * -1.0;
  v8 = COERCE_FLOAT(LODWORD(v4->physicsState.worldMatrix.M31) ^ _xmm) * -1.0;
  v9 = (float)(v7 * v25) - (float)(v6 * v27);
  v10 = (float)(v6 * v26) - (float)(v8 * v25);
  v11 = (float)(v8 * v27) - (float)(v7 * v26);
  v12 = fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11));
  if ( v12 != 0.0 )
  {
    v13 = 1.0 / v12;
    v9 = v9 * v13;
    v11 = v13 * v11;
    v10 = v13 * v10;
  }
  LODWORD(v5->matrix.M31) = LODWORD(v8) ^ _xmm;
  LODWORD(v5->matrix.M33) = LODWORD(v6) ^ _xmm;
  v5->matrix.M21 = v26;
  v5->matrix.M22 = v27;
  LODWORD(v5->matrix.M32) = LODWORD(v7) ^ _xmm;
  v5->matrix.M23 = v25;
  v5->matrix.M11 = v9;
  v5->matrix.M12 = v10;
  v5->matrix.M13 = v11;
  v14 = Sim::getFocusedCarIndex(this->sim);
  v15 = this->drivableCameraPositions._Myfirst;
  v16 = v15[v14].dashCameraPos.y;
  v17 = v15[v14].dashCameraPos.x;
  v18 = v15[v14].dashCameraPos.z;
  v19 = this->camera;
  v20 = this->sim;
  v21 = (float)((float)((float)(v4->bodyMatrix.M12 * v17) + (float)(v4->bodyMatrix.M22 * v16))
              + (float)(v4->bodyMatrix.M32 * v18))
      + v4->bodyMatrix.M42;
  v22 = (float)((float)((float)(v4->bodyMatrix.M13 * v17) + (float)(v4->bodyMatrix.M23 * v16))
              + (float)(v4->bodyMatrix.M33 * v18))
      + v4->bodyMatrix.M43;
  v19->matrix.M41 = (float)((float)((float)(v4->bodyMatrix.M21 * v16) + (float)(v4->bodyMatrix.M11 * v17))
                          + (float)(v4->bodyMatrix.M31 * v18))
                  + v4->bodyMatrix.M41;
  v19->matrix.M42 = v21;
  v19->matrix.M43 = v22;
  v23 = Sim::getFocusedCarIndex(v20);
  v24 = Sim::getCar(this->sim, v23);
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &v24->physicsState.velocity);
}
void CameraDrivableManager::updateLook(CameraDrivableManager *this, float deltaT)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax
  float v5; // xmm4_4
  float v6; // xmm2_4
  bool v7; // zf
  float v8; // xmm7_4
  int v9; // eax
  DrivableCamera v10; // ecx
  float v11; // xmm6_4
  float *v12; // esi
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned int v18; // eax
  float v19; // [esp+10h] [ebp-4h]

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  v5 = 0.0;
  v6 = 0.0;
  this->camera->blurRadialSpeed = v4->physicsState.speed.value;
  v7 = (v4->physicsState.actionsState.state & 1) == 0;
  v8 = this->rotationSpeed * deltaT;
  deltaT = 0.0;
  if ( !v7 )
  {
    v6 = FLOAT_1_0;
    deltaT = FLOAT_1_0;
  }
  v9 = v4->physicsState.actionsState.state;
  if ( (v9 & 2) != 0 )
  {
    v6 = FLOAT_N1_0;
    deltaT = FLOAT_N1_0;
  }
  v10 = this->currentMode;
  if ( v10 == eBumper || v10 == eBonnet || v10 == eDash )
  {
    if ( (v9 & 0x200) == 0 && ((v9 & 1) == 0 || (v9 & 2) == 0) )
    {
      v11 = this->rotationAnimation;
      v12 = &this->rotationAnimation;
      v13 = COERCE_FLOAT(COERCE_UNSIGNED_INT(this->rotationDegrees * v6) & _xmm) * 0.017453;
      if ( (float)(COERCE_FLOAT(LODWORD(v13) & _xmm) - COERCE_FLOAT(LODWORD(this->rotationAnimation) & _xmm)) > v8 )
      {
        *v12 = (float)(v6 * v8) + v11;
LABEL_34:
        v18 = Sim::getFocusedCarIndex(this->sim);
        Camera::rotateHeading(this->camera, (int)v12, this->drivableCameraPositions._Myfirst[v18].rotationOffset + *v12);
        return;
      }
      if ( v13 == 0.0 )
      {
LABEL_28:
        v16 = *v12;
        if ( *v12 <= 0.0 )
        {
          if ( v16 < 0.0 )
            v5 = FLOAT_N1_0;
        }
        else
        {
          v5 = FLOAT_1_0;
        }
        v17 = (float)(COERCE_FLOAT(LODWORD(v16) & _xmm) - v8) * v5;
        *v12 = v17;
        if ( v8 > (float)(COERCE_FLOAT(LODWORD(v17) & _xmm) - v8) )
          *v12 = 0.0;
        goto LABEL_34;
      }
      if ( v6 <= 0.0 )
      {
        if ( v6 < 0.0 )
        {
          v15 = FLOAT_N1_0;
          v14 = FLOAT_N1_0;
LABEL_20:
          if ( v11 <= 0.0 )
          {
            if ( v11 < 0.0 )
              v5 = v15;
          }
          else
          {
            v5 = FLOAT_1_0;
          }
          if ( v14 == v5 )
          {
            *v12 = v13 * v6;
            goto LABEL_34;
          }
          deltaT = sign<float>(&deltaT);
          v19 = sign<float>(&this->rotationAnimation);
          if ( deltaT == v19 )
            goto LABEL_34;
          v5 = 0.0;
          goto LABEL_28;
        }
        v14 = 0.0;
      }
      else
      {
        v14 = FLOAT_1_0;
      }
      v15 = FLOAT_N1_0;
      goto LABEL_20;
    }
    CameraDrivableManager::lookBack(this);
  }
}
