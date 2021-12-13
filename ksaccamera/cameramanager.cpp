#include "cameramanager.h"
void CameraManager::CameraManager(CameraManager *this, const std::wstring *filename)
{
  std::wstring v3; // [esp-1Ch] [ebp-38h] BYREF
  BOOL v4; // [esp-4h] [ebp-20h]
  CameraManager *v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+18h] [ebp-4h]

  v5 = this;
  this->__vftable = (CameraManager_vtbl *)&CameraManager::`vftable';
  this->cameras._Myfirst = 0;
  this->cameras._Mylast = 0;
  this->cameras._Myend = 0;
  v6 = 0;
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  v4 = 0;
  LOBYTE(v6) = 1;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, filename, 0, 0xFFFFFFFF);
  CameraManager::load(this, v3, v4);
  this->currentCamera = 0;
}
CameraManager *CameraManager::`scalar deleting destructor'(CameraManager *this, unsigned int a2)
{
  CameraManager::~CameraManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraManager::~CameraManager(CameraManager *this)
{
  ACCamera *v2; // esi
  ACCamera *i; // edi
  ACCamera *v4; // esi
  ACCamera *j; // edi
  ACCamera c; // [esp+18h] [ebp-E8h] BYREF
  int v7; // [esp+FCh] [ebp-4h]

  this->__vftable = (CameraManager_vtbl *)&CameraManager::`vftable';
  v7 = 1;
  v2 = this->cameras._Myfirst;
  for ( i = this->cameras._Mylast; v2 != i; ++v2 )
  {
    ACCamera::ACCamera(&c, v2);
    LOBYTE(v7) = 2;
    if ( c.spline )
      ((void (*)(Spline *, int))c.spline->~Spline)(c.spline, 1);
    LOBYTE(v7) = 1;
    c.__vftable = (ACCamera_vtbl *)&ACCamera::`vftable';
    if ( c.splineFileName._Myres >= 8 )
      operator delete(c.splineFileName._Bx._Ptr);
    c.splineFileName._Myres = 7;
    c.splineFileName._Mysize = 0;
    c.splineFileName._Bx._Buf[0] = 0;
    if ( c.name._Myres >= 8 )
      operator delete(c.name._Bx._Ptr);
  }
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  v7 = -1;
  v4 = this->cameras._Myfirst;
  if ( v4 )
  {
    for ( j = this->cameras._Mylast; v4 != j; ++v4 )
      ((void (*)(ACCamera *, _DWORD))v4->~ACCamera)(v4, 0);
    operator delete(this->cameras._Myfirst);
    this->cameras._Myfirst = 0;
    this->cameras._Mylast = 0;
    this->cameras._Myend = 0;
  }
}
void CameraManager::load(CameraManager *this, std::wstring filename, bool merge)
{
  std::wstring *v4; // eax
  std::wstring *v5; // edi
  int v6; // edi
  std::wostream *v7; // eax
  std::wstring *v8; // edi
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm0_4
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  float v16; // xmm7_4
  float v17; // xmm0_4
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm0_4
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  float v27; // xmm1_4
  __m128 v28; // xmm0
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  int v38; // edi
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
  std::wstring *v49; // edi
  double v50; // st7
  double v51; // st7
  double v52; // st7
  int v53; // eax
  int v54; // eax
  int v55; // [esp+Ch] [ebp-294h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v56; // [esp+10h] [ebp-290h] BYREF
  vec3f v57; // [esp+C0h] [ebp-1E0h]
  int v58; // [esp+CCh] [ebp-1D4h]
  std::vector<ACCamera> *v59; // [esp+D0h] [ebp-1D0h]
  vec3f v60; // [esp+D4h] [ebp-1CCh] BYREF
  vec3f v61; // [esp+E0h] [ebp-1C0h] BYREF
  int v62; // [esp+ECh] [ebp-1B4h]
  int v63; // [esp+F0h] [ebp-1B0h]
  vec3f v64; // [esp+F4h] [ebp-1ACh] BYREF
  std::wstring *v65; // [esp+100h] [ebp-1A0h]
  float v66; // [esp+104h] [ebp-19Ch]
  float v67; // [esp+108h] [ebp-198h]
  float v68; // [esp+10Ch] [ebp-194h]
  float v69; // [esp+110h] [ebp-190h]
  ACCamera _Val; // [esp+114h] [ebp-18Ch] BYREF
  INIReader v71; // [esp+1ECh] [ebp-B4h] BYREF
  std::wstring key; // [esp+230h] [ebp-70h] BYREF
  std::wstring result; // [esp+248h] [ebp-58h] BYREF
  std::wstring section; // [esp+260h] [ebp-40h] BYREF
  std::wstring v75; // [esp+278h] [ebp-28h] BYREF
  int v76; // [esp+29Ch] [ebp-4h]

  v69 = *(float *)&this;
  v62 = 0;
  v76 = 0;
  INIReader::INIReader(&v71, &filename);
  LOBYTE(v76) = 1;
  if ( v71.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VERSION", 7u);
    LOBYTE(v76) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v76) = 3;
    v58 = INIReader::getInt(&v71, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v76) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( !merge )
      std::vector<ACCamera>::clear(&this->cameras);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CAMERA_COUNT", 0xCu);
    LOBYTE(v76) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v76) = 5;
    v63 = INIReader::getInt(&v71, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v76) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SET_NAME", 8u);
    LOBYTE(v76) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v76) = 7;
    v4 = INIReader::getString(&v71, &result, &section, &key);
    v5 = &this->name;
    v65 = v4;
    if ( v5 != v4 )
    {
      if ( v5->_Myres >= 8 )
      {
        operator delete(v5->_Bx._Ptr);
        v4 = v65;
      }
      v5->_Myres = 7;
      v5->_Mysize = 0;
      v5->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(v5, v4);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v76) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v6 = 0;
    v66 = 0.0;
    v68 = 0.0;
    v67 = 0.0;
    v65 = 0;
    if ( v63 > 0 )
    {
      v59 = (std::vector<ACCamera> *)(LODWORD(v69) + 4);
      while ( 1 )
      {
        *(_DWORD *)v56.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v56.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v56.gap68);
        LOBYTE(v76) = 8;
        v62 |= 1u;
        std::wiostream::basic_iostream<wchar_t>(&v56, &v56.gap10[8], 0);
        v76 = 9;
        *(_DWORD *)&v56.gap0[*(_DWORD *)(*(_DWORD *)v56.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(int *)((char *)&v55 + *(_DWORD *)(*(_DWORD *)v56.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v56.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&v56.gap10[8]);
        *(_DWORD *)&v56.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v56.gap10[64] = 0;
        *(_DWORD *)&v56.gap10[68] = 0;
        LOBYTE(v76) = 11;
        v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v56.gap10, "CAMERA_");
        std::wostream::operator<<(v7, v6);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v56, &section);
        LOBYTE(v76) = 12;
        ACCamera::ACCamera(&_Val);
        LOBYTE(v76) = 13;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"NAME", 4u);
        LOBYTE(v76) = 14;
        v8 = INIReader::getString(&v71, &v75, &section, &result);
        if ( &_Val.name != v8 )
        {
          if ( _Val.name._Myres >= 8 )
            operator delete(_Val.name._Bx._Ptr);
          _Val.name._Myres = 7;
          _Val.name._Mysize = 0;
          _Val.name._Bx._Buf[0] = 0;
          if ( v8->_Myres >= 8 )
          {
            _Val.name._Bx._Ptr = v8->_Bx._Ptr;
            v8->_Bx._Ptr = 0;
          }
          else if ( v8->_Mysize != -1 )
          {
            _memmove(&_Val.name, v8, 2 * (v8->_Mysize + 1));
          }
          _Val.name._Mysize = v8->_Mysize;
          _Val.name._Myres = v8->_Myres;
          v8->_Myres = 7;
          v8->_Mysize = 0;
          v8->_Bx._Buf[0] = 0;
        }
        if ( v75._Myres >= 8 )
          operator delete(v75._Bx._Ptr);
        LOBYTE(v76) = 13;
        v75._Myres = 7;
        v75._Mysize = 0;
        v75._Bx._Buf[0] = 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"POSITION", 8u);
        LOBYTE(v76) = 15;
        INIReader::getFloat3(&v71, &v61, &section, &result);
        LOBYTE(v76) = 13;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v9 = (float)((float)(v61.x - v66) * (float)(v61.x - v66)) + (float)((float)(v61.y - v68) * (float)(v61.y - v68));
        *(_QWORD *)&v61.x = _mm_unpacklo_ps((__m128)LODWORD(v61.x), (__m128)LODWORD(v61.y)).m128_u64[0];
        v57 = v61;
        result._Myres = 7;
        result._Mysize = 0;
        _Val.isCameraStretch = (float)(v9 + (float)((float)(v61.z - v67) * (float)(v61.z - v67))) < 1.0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"FORWARD", 7u);
        LOBYTE(v76) = 16;
        INIReader::getFloat3(&v71, &v60, &section, &result);
        LOBYTE(v76) = 13;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"UP", 2u);
        LOBYTE(v76) = 17;
        INIReader::getFloat3(&v71, &v64, &section, &result);
        LOBYTE(v76) = 13;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v10 = v60.x;
        v11 = v60.y;
        v12 = v60.z;
        v13 = fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12));
        if ( v13 != 0.0 )
        {
          v10 = (float)(1.0 / v13) * v60.x;
          v11 = (float)(1.0 / v13) * v60.y;
          v60.x = v10;
          v60.y = v11;
          v12 = (float)(1.0 / v13) * v60.z;
          v60.z = v12;
        }
        v14 = (__m128)LODWORD(v64.x);
        v15 = (__m128)LODWORD(v64.y);
        v16 = v64.z;
        v17 = fsqrt(
                (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15.m128_f32[0] * v15.m128_f32[0]))
              + (float)(v16 * v16));
        if ( v17 != 0.0 )
        {
          v18 = (__m128)LODWORD(FLOAT_1_0);
          v18.m128_f32[0] = 1.0 / v17;
          v19 = v18;
          v19.m128_f32[0] = v18.m128_f32[0] * v64.x;
          v14 = v19;
          v20 = v18;
          v20.m128_f32[0] = v18.m128_f32[0] * v64.y;
          v15 = v20;
          v16 = v18.m128_f32[0] * v64.z;
        }
        v21 = (float)(v16 * v11) - (float)(v15.m128_f32[0] * v12);
        v22 = v14.m128_f32[0];
        v15.m128_f32[0] = (float)(v15.m128_f32[0] * v10) - (float)(v14.m128_f32[0] * v11);
        v67 = v21;
        v14.m128_f32[0] = v21;
        v23 = (float)(v22 * v12) - (float)(v16 * v10);
        v68 = v23;
        v24 = fsqrt(
                (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v23 * v23))
              + (float)(v15.m128_f32[0] * v15.m128_f32[0]));
        if ( v24 != 0.0 )
        {
          v25 = (__m128)LODWORD(FLOAT_1_0);
          v25.m128_f32[0] = 1.0 / v24;
          v26 = v25;
          v26.m128_f32[0] = v25.m128_f32[0] * v14.m128_f32[0];
          v14 = v26;
          v26.m128_f32[0] = v25.m128_f32[0] * v23;
          v25.m128_f32[0] = v25.m128_f32[0] * v15.m128_f32[0];
          v23 = v26.m128_f32[0];
          v15 = v25;
        }
        v27 = (float)(v23 * v12) - (float)(v15.m128_f32[0] * v11);
        v28 = v14;
        v15.m128_f32[0] = (float)(v15.m128_f32[0] * v10) - (float)(v14.m128_f32[0] * v12);
        v28.m128_f32[0] = v27;
        *(float *)&key._Myres = (float)(v14.m128_f32[0] * v11) - (float)(v23 * v10);
        *(_QWORD *)&v64.x = _mm_unpacklo_ps(v28, v15).m128_u64[0];
        v64.z = *(float *)&key._Myres;
        v29 = fsqrt(
                (float)((float)(v27 * v27) + (float)(v15.m128_f32[0] * v15.m128_f32[0]))
              + (float)(*(float *)&key._Myres * *(float *)&key._Myres));
        if ( v29 == 0.0 )
        {
          v31 = v64.z;
          v30 = v64.y;
          v32 = v64.x;
        }
        else
        {
          v30 = (float)(1.0 / v29) * v64.y;
          v31 = (float)(1.0 / v29) * v64.z;
          v32 = (float)(1.0 / v29) * v27;
          v64.y = v30;
          v64.z = v31;
          v64.x = v32;
        }
        v67 = v31;
        v66 = (float)(v31 * v11) - (float)(v30 * v12);
        v69 = (float)(v32 * v12) - (float)(v31 * v10);
        v68 = (float)(v30 * v10) - (float)(v32 * v11);
        v33 = fsqrt((float)((float)(v66 * v66) + (float)(v69 * v69)) + (float)(v68 * v68));
        if ( v33 != 0.0 )
        {
          v66 = (float)(1.0 / v33) * v66;
          v69 = (float)(1.0 / v33) * v69;
          v68 = (float)(1.0 / v33) * v68;
        }
        _Val.matrix.M21 = v32;
        LODWORD(_Val.matrix.M31) = LODWORD(v10) ^ _xmm;
        LODWORD(_Val.matrix.M32) = LODWORD(v11) ^ _xmm;
        _Val.matrix.M11 = v66;
        _Val.matrix.M12 = v69;
        _Val.matrix.M13 = v68;
        *(vec3f *)&_Val.matrix.M41 = v61;
        LODWORD(_Val.matrix.M33) = LODWORD(v12) ^ _xmm;
        _Val.matrix.M22 = v30;
        _Val.matrix.M23 = v31;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"MIN_FOV", 7u);
        LOBYTE(v76) = 18;
        v34 = INIReader::getFloat(&v71, &section, &result);
        LOBYTE(v76) = 13;
        _Val.minFov = v34;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"MAX_FOV", 7u);
        LOBYTE(v76) = 19;
        v35 = INIReader::getFloat(&v71, &section, &result);
        LOBYTE(v76) = 13;
        _Val.maxFov = v35;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"IN_POINT", 8u);
        LOBYTE(v76) = 20;
        v36 = INIReader::getFloat(&v71, &section, &result);
        LOBYTE(v76) = 13;
        _Val.inPoint = v36;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        std::wstring::wstring(&v75, L"OUT_POINT");
        LOBYTE(v76) = 21;
        v37 = INIReader::getFloat(&v71, &section, &v75);
        LOBYTE(v76) = 13;
        _Val.outPoint = v37;
        if ( v75._Myres >= 8 )
          operator delete(v75._Bx._Ptr);
        v38 = v58;
        if ( v58 >= 2 )
        {
          std::wstring::wstring(&v75, L"SHADOW_SPLIT0");
          LOBYTE(v76) = 22;
          v39 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.shadowSplits[0] = v39;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"SHADOW_SPLIT1");
          LOBYTE(v76) = 23;
          v40 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.shadowSplits[1] = v40;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"SHADOW_SPLIT2");
          LOBYTE(v76) = 24;
          v41 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.shadowSplits[2] = v41;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"NEAR_PLANE");
          LOBYTE(v76) = 25;
          v42 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.nearPlane = v42;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"FAR_PLANE");
          LOBYTE(v76) = 26;
          v43 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.farPlane = v43;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          if ( _Val.nearPlane == 0.0 )
          {
            _Val.nearPlane = 0.1;
            _Val.farPlane = 35000.0;
          }
        }
        if ( v38 >= 3 )
        {
          std::wstring::wstring(&v75, L"MIN_EXPOSURE");
          LOBYTE(v76) = 27;
          v44 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.minExposure = v44;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"MAX_EXPOSURE");
          LOBYTE(v76) = 28;
          v45 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.maxExposure = v45;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"DOF_FACTOR");
          LOBYTE(v76) = 29;
          v46 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.dofFactor = v46;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"DOF_FOCUS");
          LOBYTE(v76) = 30;
          v47 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.dofFocus = v47;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"DOF_RANGE");
          LOBYTE(v76) = 31;
          v48 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.dofRange = v48;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          _Val.dofManual = 0;
          std::wstring::wstring(&result, L"SPLINE");
          LOBYTE(v76) = 32;
          v49 = INIReader::getString(&v71, &v75, &section, &result);
          if ( &_Val.splineFileName != v49 )
          {
            if ( _Val.splineFileName._Myres >= 8 )
              operator delete(_Val.splineFileName._Bx._Ptr);
            _Val.splineFileName._Myres = 7;
            _Val.splineFileName._Mysize = 0;
            _Val.splineFileName._Bx._Buf[0] = 0;
            std::wstring::_Assign_rv(&_Val.splineFileName, v49);
          }
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          LOBYTE(v76) = 13;
          v75._Myres = 7;
          v75._Mysize = 0;
          v75._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          std::wstring::wstring(&v75, L"SPLINE_ROTATION");
          LOBYTE(v76) = 33;
          v50 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.splineRotationY = v50;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          std::wstring::wstring(&v75, L"FOV_GAMMA");
          LOBYTE(v76) = 34;
          v51 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.fovGamma = v51;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          if ( _Val.fovGamma <= 0.0 )
            _Val.fovGamma = 1.0;
          std::wstring::wstring(&v75, L"SPLINE_ANIMATION_LENGTH");
          LOBYTE(v76) = 35;
          v52 = INIReader::getFloat(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.splineAnimationLength = v52;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
          if ( _Val.splineAnimationLength == 0.0 )
            _Val.splineAnimationLength = 10.0;
          std::wstring::wstring(&v75, L"DOF_MANUAL");
          LOBYTE(v76) = 36;
          v53 = INIReader::getInt(&v71, &section, &v75);
          LOBYTE(v76) = 13;
          _Val.dofManual = v53 > 0;
          if ( v75._Myres >= 8 )
            operator delete(v75._Bx._Ptr);
        }
        std::wstring::wstring(&v75, L"IS_FIXED");
        LOBYTE(v76) = 37;
        v54 = INIReader::getInt(&v71, &section, &v75);
        LOBYTE(v76) = 13;
        _Val.isFixed = v54 != 0;
        if ( v75._Myres >= 8 )
          operator delete(v75._Bx._Ptr);
        std::vector<ACCamera>::push_back(v59, &_Val);
        ACCamera::~ACCamera(&_Val);
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v76) = 1;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v56);
        v6 = (int)v65->_Bx._Buf + 1;
        v65 = (std::wstring *)v6;
        if ( v6 >= v63 )
          break;
        v67 = v57.z;
        v68 = v57.y;
        v66 = v57.x;
      }
    }
  }
  LOBYTE(v76) = 0;
  INIReader::~INIReader(&v71);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
ACCamera *CameraManager::getActiveCamera(CameraManager *this, float normalizedSplinePosition)
{
  ACCamera *v3; // eax
  ACCamera *v4; // edx
  ACCamera *v5; // ecx
  ACCamera *v6; // ecx
  ACCamera *result; // eax
  ACCamera *candidate; // [esp+4h] [ebp-Ch] BYREF
  CameraManager::getActiveCamera::__l6::<lambda_d3941f6d703475ff830cadf6b94202ed> _Func; // [esp+8h] [ebp-8h] BYREF

  _Func.candidate = &candidate;
  v3 = this->currentCamera;
  v4 = this->cameras._Mylast;
  v5 = this->cameras._Myfirst;
  candidate = v3;
  _Func.normalizedSplinePosition = &normalizedSplinePosition;
  std::_For_each<ACCamera *,_lambda_d3941f6d703475ff830cadf6b94202ed_>(v5, v4, &_Func);
  v6 = candidate;
  if ( !candidate && this->cameras._Myfirst != this->cameras._Mylast )
  {
    v6 = this->cameras._Myfirst;
    candidate = v6;
  }
  v6->wasTriggered = this->currentCamera != v6;
  result = candidate;
  this->currentCamera = candidate;
  return result;
}
void CameraManager::initCamerasDistanceRanges(CameraManager *this, const Spline *spline)
{
  ACCamera *v2; // edx
  ACCamera *v3; // ecx
  CameraManager::initCamerasDistanceRanges::__l14::<lambda_1859dab662e780a0b6d323c7a676d06f> _Func; // [esp+0h] [ebp-4h] BYREF

  _Func.spline = (const Spline **)this;
  v2 = this->cameras._Mylast;
  v3 = this->cameras._Myfirst;
  _Func.spline = &spline;
  std::_For_each<ACCamera *,_lambda_1859dab662e780a0b6d323c7a676d06f_>(v3, v2, &_Func);
}
