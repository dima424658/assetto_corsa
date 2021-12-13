#include "weathergenerator.h"
char __cdecl WeatherGenerator::loadPreset(const std::wstring *name, GraphicsManager *graphics, float pp_off_mult)
{
  const std::wstring *v3; // edi
  double v4; // st7
  bool v5; // cf
  double v6; // st7
  double v7; // st7
  vec3f *v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  float v11; // xmm1_4
  double v12; // st7
  double v13; // st7
  float v14; // xmm0_4
  char v15; // bl
  std::wstring key; // [esp+1Ch] [ebp-9Ch] BYREF
  std::wstring section; // [esp+34h] [ebp-84h] BYREF
  std::wstring v19; // [esp+4Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+64h] [ebp-54h] BYREF
  int v21; // [esp+B4h] [ebp-4h]

  v3 = name;
  INIReader::INIReader(&ini, name);
  v21 = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"COLOR", 5u);
    LOBYTE(v21) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CLOUDS", 6u);
    LOBYTE(v21) = 2;
    v4 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    graphics->lightingSettings.cloudColor = v4 * pp_off_mult;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"COVER", 5u);
    LOBYTE(v21) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CLOUDS", 6u);
    LOBYTE(v21) = 4;
    v6 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    graphics->lightingSettings.cloudCover = v6;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CUTOFF", 6u);
    LOBYTE(v21) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CLOUDS", 6u);
    LOBYTE(v21) = 6;
    v7 = INIReader::getFloat(&ini, &section, &key);
    v5 = section._Myres < 8;
    graphics->lightingSettings.cloudCutoff = v7;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v19._Myres = 7;
    v19._Mysize = 0;
    v19._Bx._Buf[0] = 0;
    std::wstring::assign(&v19, L"COLOR", 5u);
    LOBYTE(v21) = 7;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FOG", 3u);
    LOBYTE(v21) = 8;
    v8 = INIReader::getFloat3(&ini, (vec3f *)&section, &key, &v19);
    v5 = key._Myres < 8;
    v9 = (__m128)LODWORD(v8->x);
    v10 = (__m128)LODWORD(v8->y);
    v9.m128_f32[0] = v9.m128_f32[0] * pp_off_mult;
    v10.m128_f32[0] = v10.m128_f32[0] * pp_off_mult;
    v11 = v8->z * pp_off_mult;
    *(_QWORD *)&graphics->lightingSettings.fogColor.x = _mm_unpacklo_ps(v9, v10).m128_u64[0];
    graphics->lightingSettings.fogColor.z = v11;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( v19._Myres >= 8 )
      operator delete(v19._Bx._Ptr);
    v19._Myres = 7;
    v19._Mysize = 0;
    v19._Bx._Buf[0] = 0;
    std::wstring::assign(&v19, L"BLEND", 5u);
    LOBYTE(v21) = 9;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FOG", 3u);
    LOBYTE(v21) = 10;
    v12 = INIReader::getFloat(&ini, &key, &v19);
    v5 = key._Myres < 8;
    graphics->lightingSettings.fogBlend = v12;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( v19._Myres >= 8 )
      operator delete(v19._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DISTANCE", 8u);
    LOBYTE(v21) = 11;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FOG", 3u);
    LOBYTE(v21) = 12;
    v13 = INIReader::getFloat(&ini, &key, &section);
    v5 = key._Myres < 8;
    graphics->lightingSettings.fogLinear = v13;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v21) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v14 = graphics->lightingSettings.fogLinear;
    section._Bx._Buf[0] = 0;
    section._Myres = 7;
    section._Mysize = 0;
    if ( v14 == 0.0 )
      graphics->lightingSettings.fogLinear = 1.0;
    GraphicsManager::updateLightingSetttings(graphics);
    v15 = 1;
  }
  else
  {
    if ( name->_Myres >= 8 )
      v3 = (const std::wstring *)name->_Bx._Ptr;
    _printf("ERROR: Could not open: %S\n", v3->_Bx._Buf);
    graphics->lightingSettings.fogLinear = 1.0;
    v15 = 0;
  }
  v21 = -1;
  INIReader::~INIReader(&ini);
  return v15;
}
