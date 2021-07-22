#include "drivernamedisplayer.h
void __userpurge DriverNameDisplayer::DriverNameDisplayer(DriverNameDisplayer *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  char v4; // bl
  bool v5; // bl
  char v6; // bl
  bool v7; // bl
  char v8; // bl
  float v9; // xmm0_4
  bool v10; // cf
  vec3f *v11; // eax
  double v12; // st7
  int v13; // eax
  bool v14; // bl
  int v15; // eax
  unsigned int i; // esi
  CarLabel *v17; // eax
  CarLabel *v18; // eax
  Sim *v19; // ecx
  CameraForward *v20; // eax
  std::wstring v21; // [esp-10h] [ebp-134h] BYREF
  unsigned int v22; // [esp+8h] [ebp-11Ch]
  CarLabel *label; // [esp+20h] [ebp-104h] BYREF
  int v24; // [esp+24h] [ebp-100h]
  DriverNameDisplayer *v25; // [esp+28h] [ebp-FCh]
  std::wstring key; // [esp+2Ch] [ebp-F8h] BYREF
  std::wstring v27; // [esp+44h] [ebp-E0h] BYREF
  std::wstring section; // [esp+5Ch] [ebp-C8h] BYREF
  std::wstring ifilename; // [esp+74h] [ebp-B0h] BYREF
  INIReader doc; // [esp+8Ch] [ebp-98h] BYREF
  INIReaderDocuments docINI; // [esp+D0h] [ebp-54h] BYREF
  int v32; // [esp+120h] [ebp-4h]

  v24 = 0;
  v25 = this;
  v22 = (unsigned int)aSim->game;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"DRIVER_NAME_DISPLAYER", 0x15u);
  GameObject::GameObject(this, v21, (Game *)v22);
  this->__vftable = (DriverNameDisplayer_vtbl *)&DriverNameDisplayer::`vftable';
  this->sim = aSim;
  this->cameraTripleScreen = 0;
  v32 = 0;
  this->fontColor.x = 0.0;
  this->fontColor.y = 0.0;
  this->fontColor.z = 0.0;
  this->cars._Myfirst = 0;
  this->cars._Mylast = 0;
  this->cars._Myend = 0;
  this->carDisplayers._Myfirst = 0;
  this->carDisplayers._Mylast = 0;
  this->carDisplayers._Myend = 0;
  LOBYTE(v32) = 2;
  mat44f::mat44f(&this->currentCameraMatrix);
  mat44f::mat44f(&this->currentViewProjectionMatrixSingleScreen);
  v22 = 29;
  this->drawFocusedCar = 0;
  v21._Myres = (unsigned int)L"system/cfg/name_displayer.ini";
  this->scale = 1.0;
  this->type = Flag;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v21._Myres, v22);
  LOBYTE(v32) = 3;
  INIReader::INIReader(&doc, &ifilename);
  LOBYTE(v32) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( doc.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SIMPLE_LABEL", 0xCu);
    LOBYTE(v32) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MAIN", 4u);
    LOBYTE(v32) = 7;
    v4 = INIReader::hasKey(&doc, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v32) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v4 )
    {
      std::wstring::wstring(&v27, L"SIMPLE_LABEL");
      LOBYTE(v32) = 8;
      std::wstring::wstring(&key, L"MAIN");
      LOBYTE(v32) = 9;
      v5 = INIReader::getInt(&doc, &key, &v27) > 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v32) = 5;
      if ( v27._Myres >= 8 )
        operator delete(v27._Bx._Ptr);
      if ( v5 )
      {
        this->type = Simple;
      }
      else
      {
        std::wstring::wstring(&v27, L"RENDER_FLAG");
        LOBYTE(v32) = 10;
        std::wstring::wstring(&key, L"MAIN");
        LOBYTE(v32) = 11;
        v6 = INIReader::hasKey(&doc, &key, &v27);
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v32) = 5;
        if ( v27._Myres >= 8 )
          operator delete(v27._Bx._Ptr);
        if ( v6 )
        {
          std::wstring::wstring(&key, L"RENDER_FLAG");
          LOBYTE(v32) = 12;
          std::wstring::wstring(&v27, L"MAIN");
          LOBYTE(v32) = 13;
          v7 = INIReader::getInt(&doc, &v27, &key) <= 0;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v27);
          LOBYTE(v32) = 5;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
          if ( v7 )
            this->type = WithoutFlag;
        }
      }
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SCALE", 5u);
    LOBYTE(v32) = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MAIN", 4u);
    LOBYTE(v32) = 15;
    v8 = INIReader::hasKey(&doc, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v32) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v8 )
    {
      std::wstring::wstring(&v27, L"SCALE");
      LOBYTE(v32) = 16;
      std::wstring::wstring(&key, L"MAIN");
      LOBYTE(v32) = 17;
      v9 = FLOAT_4_0;
      *(float *)&label = INIReader::getFloat(&doc, &key, &v27);
      if ( *(float *)&label <= 4.0 )
      {
        v9 = FLOAT_0_2;
        if ( *(float *)&label >= 0.2 )
          v9 = *(float *)&label;
      }
      v10 = key._Myres < 8;
      this->scale = v9;
      if ( !v10 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v32) = 5;
      if ( v27._Myres >= 8 )
        operator delete(v27._Bx._Ptr);
    }
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"FONT_COLOR", 0xAu);
    LOBYTE(v32) = 18;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAIN", 4u);
    LOBYTE(v32) = 19;
    v11 = INIReader::getFloat3(&doc, (vec3f *)&section, &key, &v27);
    v10 = key._Myres < 8;
    this->fontColor = *v11;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v32) = 5;
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"MAX_DISTANCE", 0xCu);
    LOBYTE(v32) = 20;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAIN", 4u);
    LOBYTE(v32) = 21;
    v12 = INIReader::getFloat(&doc, &key, &v27);
    v10 = key._Myres < 8;
    this->maxDistance = v12;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v32) = 5;
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"DRAW_FOCUSEDCAR", 0xFu);
    LOBYTE(v32) = 22;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAIN", 4u);
    LOBYTE(v32) = 23;
    LOBYTE(a2) = INIReader::hasKey(&doc, &key, &v27);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v32) = 5;
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    if ( (_BYTE)a2 )
    {
      std::wstring::wstring(&key, L"DRAW_FOCUSEDCAR");
      LOBYTE(v32) = 24;
      std::wstring::wstring(&v27, L"MAIN");
      LOBYTE(v32) = 25;
      v13 = INIReader::getInt(&doc, &v27, &key);
      v10 = v27._Myres < 8;
      this->drawFocusedCar = v13 != 0;
      if ( !v10 )
        operator delete(v27._Bx._Ptr);
      v27._Myres = 7;
      v27._Mysize = 0;
      v27._Bx._Buf[0] = 0;
      LOBYTE(v32) = 5;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  v22 = 0;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&docINI, a2, v21, v22);
  LOBYTE(v32) = 26;
  v14 = 0;
  if ( docINI.ready )
  {
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"DRIVER_NAME_DISPLAYER", 0x15u);
    LOBYTE(v32) = 27;
    v24 = 1;
    if ( INIReader::hasSection(&docINI, &v27) )
      v14 = 1;
  }
  v32 = 26;
  if ( (v24 & 1) != 0 && v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  if ( v14 )
  {
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"IS_ACTIVE", 9u);
    LOBYTE(v32) = 28;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DRIVER_NAME_DISPLAYER", 0x15u);
    LOBYTE(v32) = 29;
    v15 = INIReader::getInt(&docINI, &key, &v27);
    v10 = key._Myres < 8;
    this->isActive = v15 != 0;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v32) = 26;
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
  }
  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++i )
  {
    *(float *)&v17 = COERCE_FLOAT(operator new(408));
    label = v17;
    LOBYTE(v32) = 30;
    if ( *(float *)&v17 == 0.0 )
      *(float *)&v18 = 0.0;
    else
      CarLabel::CarLabel(v17, i, this->maxDistance, this->type, this->sim);
    LOBYTE(v32) = 26;
    label = v18;
    ksgui::Control::setVisible(v18, 0);
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->carDisplayers,
      (ICollisionObject *const *)&label);
  }
  v19 = this->sim;
  v22 = 0;
  v21._Myres = (unsigned int)&CameraTripleScreen `RTTI Type Descriptor';
  v21._Mysize = (unsigned int)&Camera `RTTI Type Descriptor';
  *(_DWORD *)&v21._Bx._Alias[12] = 0;
  v20 = Sim::getSceneCamera(v19);
  this->cameraTripleScreen = (CameraTripleScreen *)__RTDynamicCast(
                                                     v20,
                                                     *(_DWORD *)&v21._Bx._Alias[12],
                                                     v21._Mysize,
                                                     v21._Myres,
                                                     v22);
  LOBYTE(v32) = 5;
  INIReaderDocuments::~INIReaderDocuments(&docINI);
  LOBYTE(v32) = 2;
  INIReader::~INIReader(&doc);
}
void DriverNameDisplayer::~DriverNameDisplayer(DriverNameDisplayer *this)
{
  this->__vftable = (DriverNameDisplayer_vtbl *)&DriverNameDisplayer::`vftable';
  if ( this->carDisplayers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->carDisplayers);
    operator delete(this->carDisplayers._Myfirst);
    this->carDisplayers._Myfirst = 0;
    this->carDisplayers._Mylast = 0;
    this->carDisplayers._Myend = 0;
  }
  if ( this->cars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cars);
    operator delete(this->cars._Myfirst);
    this->cars._Myfirst = 0;
    this->cars._Mylast = 0;
    this->cars._Myend = 0;
  }
  GameObject::~GameObject(this);
}
DriverNameDisplayer *DriverNameDisplayer::`scalar deleting destructor'(DriverNameDisplayer *this, unsigned int a2)
{
  DriverNameDisplayer::~DriverNameDisplayer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
vec2f *DriverNameDisplayer::projectPoint(DriverNameDisplayer *this, vec2f *result, vec3f worldSpacePoint, vec3f *outDirection)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  int v6; // edi
  CameraTripleScreen *v7; // edx
  unsigned int v8; // ecx
  float *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  unsigned int v15; // eax
  unsigned int v16; // ecx
  __m128 v17; // xmm1
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  vec2f *v25; // eax
  GraphicsManager *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  __m128i v30; // xmm0
  float v31; // eax
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm4_4
  float v36; // xmm0_4
  vec2f v37; // [esp+4h] [ebp-8h]
  GraphicsManager *v38; // [esp+8h] [ebp-4h]
  float v39; // [esp+8h] [ebp-4h]
  float worldSpacePoint_8; // [esp+1Ch] [ebp+10h]

  v4 = (__m128)LODWORD(worldSpacePoint.y);
  v5 = (__m128)LODWORD(worldSpacePoint.x);
  if ( this->cameraTripleScreen )
  {
    v38 = this->game->graphics;
    v6 = v38->videoSettings.width / 3;
    v7 = this->cameraTripleScreen;
    v8 = 0;
    v9 = &v7->tripleScreen.currentViewProj[0].M31;
    while ( 1 )
    {
      v10 = (float)((float)((float)(*(v9 - 8) * worldSpacePoint.x) + (float)(*(v9 - 4) * v4.m128_f32[0]))
                  + (float)(worldSpacePoint.z * *v9))
          + v9[4];
      v11 = (float)((float)((float)(*(v9 - 7) * worldSpacePoint.x) + (float)(*(v9 - 3) * v4.m128_f32[0]))
                  + (float)(v9[1] * worldSpacePoint.z))
          + v9[5];
      v12 = 1.0
          / (float)((float)((float)((float)(*(v9 - 5) * worldSpacePoint.x) + (float)(*(v9 - 1) * v4.m128_f32[0]))
                          + (float)(v9[3] * worldSpacePoint.z))
                  + v9[7]);
      v13 = v12 * v11;
      v14 = v12 * v10;
      if ( v14 >= -1.0 && v13 >= -1.0 && v14 <= 1.0 && v13 <= 1.0 )
        break;
      ++v8;
      v9 += 16;
      if ( v8 >= 3 )
        goto LABEL_17;
      v4.m128_i32[0] = LODWORD(worldSpacePoint.y);
    }
    v15 = v8;
    v16 = v8 << 6;
    v17 = (__m128)LODWORD(worldSpacePoint.y);
    v17.m128_f32[0] = worldSpacePoint.y - *(float *)((char *)&v7->tripleScreen.currentCameraMatrix[0].M42 + v16);
    v5.m128_f32[0] = worldSpacePoint.x - *(float *)((char *)&v7->tripleScreen.currentCameraMatrix[0].M41 + v16);
    v18 = (float)(v6 * v15);
    v37.x = (float)((float)((float)(v14 + 1.0) * 0.5) * (float)v6) + v18;
    v19 = worldSpacePoint.z - *(float *)((char *)&v7->tripleScreen.currentCameraMatrix[0].M43 + v16);
    v37.y = (float)((float)(1.0 - v13) * 0.5) * (float)v38->videoSettings.height;
    *(_QWORD *)&outDirection->x = _mm_unpacklo_ps(v5, v17).m128_u64[0];
    outDirection->z = v19;
    v20 = outDirection->y;
    v21 = outDirection->x;
    v22 = outDirection->z;
    v23 = fsqrt((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22));
    if ( v23 != 0.0 )
    {
      outDirection->x = (float)(1.0 / v23) * v21;
      outDirection->y = (float)(1.0 / v23) * v20;
      outDirection->z = (float)(1.0 / v23) * v22;
    }
    v24 = __libm_sse2_acosf().m128_f32[0];
    v25 = result;
    if ( v24 < 1.5707951 )
    {
      *result = v37;
      return v25;
    }
  }
  else
  {
    v26 = this->game->graphics;
    v5.m128_f32[0] = worldSpacePoint.x - this->currentCameraMatrix.M41;
    v4.m128_f32[0] = worldSpacePoint.y - this->currentCameraMatrix.M42;
    v27 = 1.0
        / (float)((float)((float)((float)(this->currentViewProjectionMatrixSingleScreen.M14 * worldSpacePoint.x)
                                + (float)(this->currentViewProjectionMatrixSingleScreen.M24 * worldSpacePoint.y))
                        + (float)(this->currentViewProjectionMatrixSingleScreen.M34 * worldSpacePoint.z))
                + this->currentViewProjectionMatrixSingleScreen.M44);
    v28 = v27
        * (float)((float)((float)((float)(this->currentViewProjectionMatrixSingleScreen.M12 * worldSpacePoint.x)
                                + (float)(this->currentViewProjectionMatrixSingleScreen.M22 * worldSpacePoint.y))
                        + (float)(this->currentViewProjectionMatrixSingleScreen.M32 * worldSpacePoint.z))
                + this->currentViewProjectionMatrixSingleScreen.M42);
    v29 = (float)((float)((float)(v27
                                * (float)((float)((float)((float)(this->currentViewProjectionMatrixSingleScreen.M21
                                                                * worldSpacePoint.y)
                                                        + (float)(worldSpacePoint.x
                                                                * this->currentViewProjectionMatrixSingleScreen.M11))
                                                + (float)(this->currentViewProjectionMatrixSingleScreen.M31
                                                        * worldSpacePoint.z))
                                        + this->currentViewProjectionMatrixSingleScreen.M41))
                        + 1.0)
                * 0.5)
        * (float)v26->videoSettings.width;
    v30 = _mm_cvtsi32_si128(v26->videoSettings.height);
    v31 = worldSpacePoint.z - this->currentCameraMatrix.M43;
    v39 = v29;
    *(_QWORD *)&outDirection->x = _mm_unpacklo_ps(v5, v4).m128_u64[0];
    outDirection->z = v31;
    v32 = (float)(1.0 - v28) * 0.5;
    v33 = outDirection->y;
    v34 = outDirection->z;
    worldSpacePoint_8 = v32 * _mm_cvtepi32_ps(v30).m128_f32[0];
    v35 = outDirection->x;
    v36 = fsqrt((float)((float)(v35 * v35) + (float)(v33 * v33)) + (float)(v34 * v34));
    if ( v36 != 0.0 )
    {
      outDirection->x = (float)(1.0 / v36) * v35;
      outDirection->y = (float)(1.0 / v36) * v33;
      outDirection->z = (float)(1.0 / v36) * v34;
    }
    if ( __libm_sse2_acosf().m128_f32[0] < 1.5707951 )
    {
      v25 = result;
      result->x = v39;
      result->y = worldSpacePoint_8;
      return v25;
    }
LABEL_17:
    v25 = result;
  }
  v25->y = -1.0;
  v25->x = -1.0;
  return v25;
}
void DriverNameDisplayer::renderHUD(DriverNameDisplayer *this, float deltaT)
{
  Sim *v3; // edx
  CameraMode v4; // eax
  Sim *v5; // ecx
  unsigned int i; // edi
  DriverNameDisplayer::CarDistandeOrder *v7; // esi
  DriverNameDisplayer::CarDistandeOrder *v8; // edi
  DriverNameDisplayer::CarDistandeOrder *j; // esi
  CameraForward *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  SessionType v15; // eax
  Sim *v16; // ecx
  unsigned int v17; // eax
  CarAvatar *v18; // eax
  int v19; // eax
  DriverNameDisplayer::CarDistandeOrder *v20; // esi
  DriverNameDisplayer::CarDistandeOrder *v21; // edi
  int v22; // eax
  CarLabel **v23; // ecx
  int v24; // ebp
  ksgui::Control *v25; // ecx
  Sim *v26; // ecx
  CameraMode v27; // eax
  CarAvatar *v28; // eax
  Node *v29; // ecx
  int v30; // eax
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  const std::wstring *v33; // eax
  Sim *v34; // ecx
  RaceManager *v35; // ecx
  int v36; // eax
  bool v37; // zf
  float v38; // xmm0_4
  unsigned int v39; // ebp
  int v40; // ecx
  int v41; // eax
  ACClient *v42; // ecx
  float scale; // xmm0_4
  std::wstring v44; // [esp-24h] [ebp-124h] BYREF
  std::wstring v45; // [esp-Ch] [ebp-10Ch] BYREF
  bool v46; // [esp+23h] [ebp-DDh]
  unsigned int v47; // [esp+24h] [ebp-DCh]
  vec2f coords; // [esp+28h] [ebp-D8h] BYREF
  int k; // [esp+30h] [ebp-D0h]
  vec3f direction; // [esp+34h] [ebp-CCh] BYREF
  std::wstring *v51; // [esp+44h] [ebp-BCh]
  vec3f finalPoint; // [esp+48h] [ebp-B8h]
  mat44f v53; // [esp+54h] [ebp-ACh] BYREF
  CarLabel::CarData data; // [esp+94h] [ebp-6Ch] BYREF
  std::wstring nationCode; // [esp+D8h] [ebp-28h] BYREF
  int v56; // [esp+FCh] [ebp-4h]

  v3 = this->sim;
  if ( !v3->pauseMenu->visible
    && !v3->escMenu->visible
    && this->isActive
    && (!this->cameraTripleScreen || (v4 = v3->cameraManager->mode) == eCockpit || v4 == eDrivable || v4 == eFree) )
  {
    if ( ((((char *)v3->cars._Mylast - (char *)v3->cars._Myfirst) ^ (((char *)this->cars._Mylast
                                                                    - (char *)this->cars._Myfirst) >> 1)) & 0xFFFFFFFC) != 0 )
    {
      std::vector<DriverNameDisplayer::CarDistandeOrder>::resize(&this->cars, v3->cars._Mylast - v3->cars._Myfirst);
      v5 = this->sim;
      for ( i = 0; i < v5->cars._Mylast - v5->cars._Myfirst; v5 = this->sim )
      {
        v7 = this->cars._Myfirst;
        v7[i].avatar = Sim::getCar(v5, i);
        ++i;
      }
    }
    v8 = this->cars._Mylast;
    for ( j = this->cars._Myfirst; j != v8; ++j )
    {
      v10 = Sim::getSceneCamera(this->sim);
      v11 = j->avatar->physicsState.worldMatrix.M42 - v10->matrix.M42;
      v12 = (float)((float)(j->avatar->physicsState.worldMatrix.M41 - v10->matrix.M41)
                  * (float)(j->avatar->physicsState.worldMatrix.M41 - v10->matrix.M41))
          + (float)(v11 * v11);
      v13 = 0.0;
      v14 = v12
          + (float)((float)(j->avatar->physicsState.worldMatrix.M43 - v10->matrix.M43)
                  * (float)(j->avatar->physicsState.worldMatrix.M43 - v10->matrix.M43));
      if ( v14 != 0.0 )
        v13 = fsqrt(v14);
      j->distance = v13;
    }
    std::_Sort<DriverNameDisplayer::CarDistandeOrder *,int,_lambda_f0867d60f64da2cb3f33bccaed49f9ac_>(
      this->cars._Myfirst,
      this->cars._Mylast,
      this->cars._Mylast - this->cars._Myfirst,
      (DriverNameDisplayer::renderHUD::__l21::<lambda_f0867d60f64da2cb3f33bccaed49f9ac>)k);
    v15 = RaceManager::getCurrentSessionType(this->sim->raceManager);
    v16 = this->sim;
    v46 = v15 == Race;
    v17 = Sim::getFocusedCarIndex(v16);
    v18 = Sim::getCar(this->sim, v17);
    v19 = RaceManager::getLapCount(this->sim->raceManager, v18);
    v20 = this->cars._Myfirst;
    v21 = this->cars._Mylast;
    for ( k = v19; v20 != v21; ++v20 )
    {
      v22 = CarAvatar::getGuid(v20->avatar);
      v23 = this->carDisplayers._Myfirst;
      v24 = v22;
      v45._Myres = 0;
      v25 = v23[v22];
      v47 = 4 * v22;
      ksgui::Control::setVisible(v25, 0);
      if ( CarAvatar::isConnected(v20->avatar) )
      {
        if ( (v26 = this->sim, v27 = v26->cameraManager->mode, v27 != eCar) && v27 != eDrivable
          || v24 != Sim::getFocusedCarIndex(v26) )
        {
          v28 = v20->avatar;
          v45._Myres = (unsigned int)&v53;
          direction.x = 0.0;
          direction.y = 0.0;
          v29 = v28->bodyTransform;
          direction.z = 0.0;
          v30 = (int)v29->getWorldMatrix(v29, &v53);
          v31 = (__m128)*(unsigned int *)(v30 + 48);
          v32 = (__m128)*(unsigned int *)(v30 + 52);
          v32.m128_f32[0] = v32.m128_f32[0] + 1.5;
          finalPoint.z = *(float *)(v30 + 56);
          *(_QWORD *)&v45._Bx._Alias[8] = _mm_unpacklo_ps(v31, v32).m128_u64[0];
          v45._Mysize = LODWORD(finalPoint.z);
          DriverNameDisplayer::projectPoint(this, &coords, *(vec3f *)&v45._Bx._Alias[8], &direction);
          if ( (coords.x != -1.0 || coords.y != -1.0)
            && coords.x > 0.0
            && coords.y > 0.0
            && (float)this->game->graphics->videoSettings.width > coords.x
            && (float)this->game->graphics->videoSettings.height > coords.y
            && this->maxDistance > v20->distance
            && (this->drawFocusedCar || v24 != Sim::getFocusedCarIndex(this->sim)) )
          {
            std::wstring::wstring(&nationCode, &v20->avatar->driverInfo.nationCode);
            v56 = 0;
            v51 = &v45;
            std::wstring::wstring(&v45, &nationCode);
            v33 = &v20->avatar->driverInfo.name;
            LOBYTE(v56) = 1;
            std::wstring::wstring(&v44, v33);
            LOBYTE(v56) = 0;
            CarLabel::CarData::CarData(&data, v44, v45);
            v34 = this->sim;
            v45._Myres = (unsigned int)v20->avatar;
            LOBYTE(v56) = 2;
            v35 = v34->raceManager;
            if ( v46 )
              v36 = RaceManager::getCarRealTimePosition(v35, (CarAvatar *)v45._Myres) + 1;
            else
              v36 = RaceManager::getCarLeaderboardPosition(v35, (CarAvatar *)v45._Myres);
            v37 = this->type == Flag;
            v38 = v20->distance;
            v39 = v47;
            data.position = v36;
            data.distance = v38;
            if ( v37 && std::operator!=<wchar_t>(&this->carDisplayers._Myfirst[v47 / 4]->nationCode, &nationCode) )
              data.texture = Sim::getNationFlag(this->sim, &nationCode);
            data.ahead = -1;
            if ( v46 )
            {
              v40 = RaceManager::getLapCount(this->sim->raceManager, v20->avatar);
              if ( v40 <= k )
              {
                v41 = data.ahead;
                v47 = 0;
                if ( v40 < k )
                  v41 = v47;
                data.ahead = v41;
              }
              else
              {
                data.ahead = 1;
              }
            }
            v42 = this->sim->client;
            if ( v42 )
              data.ping = ACClient::getPing(v42, v20->avatar);
            scale = this->scale;
            v45._Myres = (unsigned int)v42;
            CarLabel::updatePilotData(*(CarLabel **)((char *)this->carDisplayers._Myfirst + v39), &data, scale);
            ksgui::Form::setPosition(
              *(ksgui::Form **)((char *)this->carDisplayers._Myfirst + v39),
              (float)(int)coords.x,
              (float)((int)coords.y - 45));
            ksgui::Control::setVisible(*(ksgui::Control **)((char *)this->carDisplayers._Myfirst + v39), 1);
            (*(void (**)(_DWORD, _DWORD))(**(_DWORD **)((char *)this->carDisplayers._Myfirst + v39) + 12))(
              *(CarLabel **)((char *)this->carDisplayers._Myfirst + v39),
              LODWORD(deltaT));
            CarLabel::CarData::~CarData(&data);
            v56 = -1;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&nationCode);
          }
        }
      }
    }
  }
}
void DriverNameDisplayer::setActive(DriverNameDisplayer *this, bool active)
{
  this->isActive = active;
}
void DriverNameDisplayer::shutdown(DriverNameDisplayer *this)
{
  bool v2; // zf
  std::wstring *v3; // eax
  std::wstring *v4; // esi
  const wchar_t *v5; // edx
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  int v8; // [esp+Ch] [ebp-124h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v9; // [esp+10h] [ebp-120h] BYREF
  std::wstring parameter; // [esp+C0h] [ebp-70h] BYREF
  std::wstring path; // [esp+D8h] [ebp-58h] BYREF
  std::wstring section; // [esp+F0h] [ebp-40h] BYREF
  std::wstring result; // [esp+108h] [ebp-28h] BYREF
  int v14; // [esp+12Ch] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DRIVER_NAME_DISPLAYER", 0x15u);
  v14 = 0;
  parameter._Myres = 7;
  parameter._Mysize = 0;
  parameter._Bx._Buf[0] = 0;
  std::wstring::assign(&parameter, L"IS_ACTIVE", 9u);
  LOBYTE(v14) = 1;
  *(_DWORD *)v9.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v9.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v9.gap68);
  LOBYTE(v14) = 2;
  v8 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v9, &v9.gap10[8], 0);
  v14 = 3;
  *(_DWORD *)&v9.gap0[*(_DWORD *)(*(_DWORD *)v9.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v8 + *(_DWORD *)(*(_DWORD *)v9.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v9.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v9.gap10[8]);
  *(_DWORD *)&v9.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v9.gap10[64] = 0;
  *(_DWORD *)&v9.gap10[68] = 0;
  v2 = !this->isActive;
  LOBYTE(v14) = 5;
  if ( v2 )
    std::wostream::operator<<(v9.gap10, 0);
  else
    std::wostream::operator<<(v9.gap10, 1);
  Path::getDocumentPath(&path);
  LOBYTE(v14) = 6;
  std::wstring::append(&path, L"/Assetto Corsa/cfg/gameplay.ini", 0x1Fu);
  v3 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v9, &result);
  v4 = &path;
  v5 = (const wchar_t *)v3;
  if ( path._Myres >= 8 )
    v4 = (std::wstring *)path._Bx._Ptr;
  if ( v3->_Myres >= 8 )
    v5 = v3->_Bx._Ptr;
  v6 = &parameter;
  if ( parameter._Myres >= 8 )
    v6 = (std::wstring *)parameter._Bx._Ptr;
  v7 = &section;
  if ( section._Myres >= 8 )
    v7 = (std::wstring *)section._Bx._Ptr;
  WritePrivateProfileStringW(v7->_Bx._Buf, v6->_Bx._Buf, v5, v4->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Bx._Buf[0] = 0;
  path._Mysize = 0;
  LOBYTE(v14) = 1;
  *(_DWORD *)&v9.gap0[*(_DWORD *)(*(_DWORD *)v9.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v8 + *(_DWORD *)(*(_DWORD *)v9.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v9.gap0 + 4) - 104;
  *(_DWORD *)&v9.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v9.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v9.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v9.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v9.gap68);
  if ( parameter._Myres >= 8 )
    operator delete(parameter._Bx._Ptr);
  parameter._Myres = 7;
  parameter._Mysize = 0;
  parameter._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void DriverNameDisplayer::update(DriverNameDisplayer *this, float deltaT)
{
  CameraForward *v3; // esi
  __int128 v4; // xmm1
  __int128 v5; // xmm2
  __int128 v6; // xmm3
  __m128i v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  _QWORD M2[9]; // [esp+8h] [ebp-88h] BYREF
  __m128 v12[4]; // [esp+50h] [ebp-40h] BYREF

  if ( !this->cameraTripleScreen )
  {
    v3 = Sim::getSceneCamera(this->sim);
    v3->getPerspectiveMatrix(v3, (mat44f *)&M2[1]);
    v3->getViewMatrix(v3, (mat44f *)v12);
    v4 = *(_OWORD *)&M2[3];
    v5 = *(_OWORD *)&M2[5];
    v6 = *(_OWORD *)&M2[7];
    *(__m128i *)&this->currentCameraMatrix.M11 = _mm_loadu_si128((const __m128i *)&v3->matrix);
    *(__m128i *)&this->currentCameraMatrix.M21 = _mm_loadu_si128((const __m128i *)&v3->matrix.M21);
    *(__m128i *)&this->currentCameraMatrix.M31 = _mm_loadu_si128((const __m128i *)&v3->matrix.M31);
    v7 = _mm_loadu_si128((const __m128i *)&v3->matrix.M41);
    *(_OWORD *)&M2[3] = v4;
    v8 = v12[1];
    *(__m128i *)&this->currentCameraMatrix.M41 = v7;
    *(_OWORD *)&M2[5] = v5;
    v9 = v12[2];
    *(_OWORD *)&M2[7] = v6;
    v10 = v12[3];
    *(__m128 *)&this->currentViewProjectionMatrixSingleScreen.M11 = DirectX::XMMatrixMultiply((__m128 *)&M2[1], v12[0]);
    *(__m128 *)&this->currentViewProjectionMatrixSingleScreen.M21 = v8;
    *(__m128 *)&this->currentViewProjectionMatrixSingleScreen.M31 = v9;
    *(__m128 *)&this->currentViewProjectionMatrixSingleScreen.M41 = v10;
  }
}
