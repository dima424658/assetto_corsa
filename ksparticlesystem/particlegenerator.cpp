#include "particlegenerator.h
void __userpurge ParticleGenerator::ParticleGenerator(ParticleGenerator *this@<ecx>, __m128 a2@<xmm0>, ParticleSystem *a_particleSystem, std::wstring a_filename, float aFrequency)
{
  ParticleGenerator *v5; // esi
  std::wstring *v6; // ecx
  float v7; // xmm0_4

  v5 = this;
  v6 = &this->filename;
  this->velocityBase.x = 0.0;
  v5->velocityBase.y = 0.0;
  v5->velocityBase.z = 0.0;
  v5->velocityRandom.x = 0.0;
  v5->velocityRandom.y = 0.0;
  v5->velocityRandom.z = 0.0;
  v5->sizeBase.x = 0.0;
  v5->sizeBase.y = 0.0;
  v5->sizeRandom.x = 0.0;
  v5->sizeRandom.y = 0.0;
  v5->sizeVelocityBase.x = 0.0;
  v5->sizeVelocityBase.y = 0.0;
  v5->sizeVelocityRandom.x = 0.0;
  v5->sizeVelocityRandom.y = 0.0;
  v5->colorBase.x = 0.0;
  v5->colorBase.y = 0.0;
  v5->colorBase.z = 0.0;
  v5->colorRandom.x = 0.0;
  v5->colorRandom.y = 0.0;
  v5->colorRandom.z = 0.0;
  v6->_Myres = 7;
  v6->_Mysize = 0;
  v6->_Bx._Buf[0] = 0;
  a2.m128_f32[0] = 1.0;
  v5->particleSystem = a_particleSystem;
  *(_QWORD *)&v5->colorBase.x = _mm_unpacklo_ps(a2, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  v5->sizeBase.x = 1.0;
  v5->sizeBase.y = 1.0;
  *(_QWORD *)&v5->colorRandom.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1)).m128_u64[0];
  v7 = aFrequency;
  v5->colorBase.z = 1.0;
  v5->colorRandom.z = 0.1;
  v5->sizeVelocityBase.x = 0.40000001;
  v5->sizeVelocityBase.y = 0.40000001;
  v5->sizeVelocityRandom.x = 0.1;
  v5->frequency = v7;
  v5->sizeVelocityRandom.y = 0.1;
  *(_QWORD *)&v5->velocityRandom.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  v5->dragBase = 0.1;
  v5->gravityBase = 0.1;
  v5->gravityRandom = 0.0;
  v5->opacityBase = 0.30000001;
  v5->opacityRandom = 0.2;
  v5->opacityVelocityBase = -0.0099999998;
  v5->opacityVelocityRandom = 0.0;
  v5->velocityRandom.z = 1.0;
  v5->dragRandom = 0.0;
  v5->lastGenerationTime = 0.0;
  if ( v6 != &a_filename )
    std::wstring::assign(v6, &a_filename, 0, 0xFFFFFFFF);
  v5->velocityRotationAxisRandom = 0.0;
  ParticleGenerator::loadINI(v5);
  if ( a_filename._Myres >= 8 )
    operator delete(a_filename._Bx._Ptr);
}
void ParticleGenerator::~ParticleGenerator(ParticleGenerator *this)
{
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
}
void ParticleGenerator::generateParticle(ParticleGenerator *this, const vec3f *pos, const vec3f *velocity, long double now, long double timeRate)
{
  double v6; // xmm2_8
  float v7; // eax
  int v8; // eax
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  int v11; // eax
  int v12; // eax
  __m128 v13; // xmm4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  __m128 v17; // xmm1
  int v18; // eax
  ParticleSystem *v19; // esi
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // [esp+0h] [ebp-58h]
  float v23; // [esp+4h] [ebp-54h]
  float v24; // [esp+4h] [ebp-54h]
  float v25; // [esp+4h] [ebp-54h]
  float v26; // [esp+Ch] [ebp-4Ch]
  float v27; // [esp+Ch] [ebp-4Ch]
  Particle np; // [esp+10h] [ebp-48h] BYREF

  v6 = this->frequency;
  if ( v6 == -1.0 || 1.0 / (v6 * timeRate) <= now - this->lastGenerationTime )
  {
    this->lastGenerationTime = now;
    Particle::Particle(&np);
    v7 = pos->z;
    *(_QWORD *)&np.position.x = *(_QWORD *)&pos->x;
    np.position.z = v7;
    v23 = (float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0;
    v22 = (float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0;
    v8 = _rand();
    v9 = (__m128)LODWORD(velocity->x);
    v10 = (__m128)LODWORD(velocity->y);
    v10.m128_f32[0] = (float)(v10.m128_f32[0] + this->velocityBase.y) + (float)(this->velocityRandom.y * v22);
    v9.m128_f32[0] = (float)(v9.m128_f32[0] + this->velocityBase.x)
                   + (float)((float)((float)((float)((float)v8 * 0.000030518509) * 2.0) - 1.0) * this->velocityRandom.x);
    v26 = (float)(velocity->z + this->velocityBase.z) + (float)(this->velocityRandom.z * v23);
    *(_QWORD *)&np.velocity.x = _mm_unpacklo_ps(v9, v10).m128_u64[0];
    np.velocity.z = v26;
    v24 = (float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0;
    v11 = _rand();
    v10.m128_f32[0] = (float)(this->sizeBase.y + (float)(this->sizeRandom.y * v24)) * 0.5;
    np.halfSize.x = (float)(this->sizeBase.x
                          + (float)(this->sizeRandom.x
                                  * (float)((float)((float)((float)v11 * 0.000030518509) * 2.0) - 1.0)))
                  * 0.5;
    LODWORD(np.halfSize.y) = v10.m128_i32[0];
    v12 = _rand();
    v13 = (__m128)LODWORD(this->colorBase.x);
    v10.m128_f32[0] = (float)((float)((float)v12 * 0.000030518509) * 2.0) - 1.0;
    v14 = this->colorRandom.z * v10.m128_f32[0];
    v15 = v10.m128_f32[0] * this->colorRandom.x;
    v16 = this->colorRandom.y * v10.m128_f32[0];
    v17 = (__m128)LODWORD(this->colorBase.y);
    v13.m128_f32[0] = v13.m128_f32[0] + v15;
    v17.m128_f32[0] = v17.m128_f32[0] + v16;
    v27 = this->colorBase.z + v14;
    *(_QWORD *)&np.color.x = _mm_unpacklo_ps(v13, v17).m128_u64[0];
    np.color.z = v27;
    np.drag = (float)(this->dragRandom * (float)((float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0))
            + this->dragBase;
    np.gravity = (float)(this->gravityRandom * (float)((float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0))
               + this->gravityBase;
    np.opacity = (float)(this->opacityRandom * (float)((float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0))
               + this->opacityBase;
    np.opacityVelocity = (float)(this->opacityVelocityRandom
                               * (float)((float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0))
                       + this->opacityVelocityBase;
    v18 = _rand();
    v19 = this->particleSystem;
    v20 = (float)((float)((float)v18 * 0.000030518509) * 2.0) - 1.0;
    v25 = this->sizeVelocityBase.x + (float)(v20 * this->sizeVelocityRandom.x);
    v21 = this->sizeVelocityBase.y + (float)(this->sizeVelocityRandom.y * v20);
    np.sizeVelocity.x = v25;
    np.sizeVelocity.y = v21;
    if ( (unsigned int)(v19->particles._Mylast - v19->particles._Myfirst) < v19->maxParticlesCount )
      std::vector<Particle>::push_back(&v19->particles, &np);
  }
}
void ParticleGenerator::loadINI(ParticleGenerator *this)
{
  vec2f *v2; // eax
  bool v3; // cf
  vec2f *v4; // eax
  vec3f *v5; // eax
  vec3f *v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  vec2f *v15; // eax
  vec2f *v16; // eax
  vec3f *v17; // eax
  vec3f *v18; // eax
  double v19; // st7
  double v20; // xmm0_8
  std::wstring key; // [esp+Ch] [ebp-A8h] BYREF
  std::wstring v22; // [esp+24h] [ebp-90h] BYREF
  std::wstring section; // [esp+3Ch] [ebp-78h] BYREF
  INIReader r; // [esp+54h] [ebp-60h] BYREF
  int v25; // [esp+B0h] [ebp-4h]

  INIReader::INIReader(&r, &this->filename);
  v25 = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EMISSIVE_BLEND", 0xEu);
    LOBYTE(v25) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v25) = 2;
    this->particleSystem->emissiveBlend = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    LOBYTE(v25) = 0;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"SIZE_BASE", 9u);
    LOBYTE(v25) = 3;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 4;
    v2 = INIReader::getFloat2(&r, (vec2f *)&section, &key, &v22);
    v3 = key._Myres < 8;
    this->sizeBase = *v2;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"SIZE_RANDOM", 0xBu);
    LOBYTE(v25) = 5;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 6;
    v4 = INIReader::getFloat2(&r, (vec2f *)&section, &key, &v22);
    v3 = key._Myres < 8;
    this->sizeRandom = *v4;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"COLOR_BASE", 0xAu);
    LOBYTE(v25) = 7;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 8;
    v5 = INIReader::getFloat3(&r, (vec3f *)&section, &key, &v22);
    v3 = key._Myres < 8;
    this->colorBase = *v5;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"COLOR_RANDOM", 0xCu);
    LOBYTE(v25) = 9;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 10;
    v6 = INIReader::getFloat3(&r, (vec3f *)&section, &key, &v22);
    v3 = key._Myres < 8;
    this->colorRandom = *v6;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"DRAG_BASE", 9u);
    LOBYTE(v25) = 11;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 12;
    v7 = INIReader::getFloat(&r, &key, &v22);
    v3 = key._Myres < 8;
    this->dragBase = v7;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"DRAG_RANDOM", 0xBu);
    LOBYTE(v25) = 13;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 14;
    v8 = INIReader::getFloat(&r, &key, &v22);
    v3 = key._Myres < 8;
    this->dragRandom = v8;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"GRAVITY_BASE", 0xCu);
    LOBYTE(v25) = 15;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 16;
    v9 = INIReader::getFloat(&r, &key, &v22);
    v3 = key._Myres < 8;
    this->gravityBase = v9;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"GRAVITY_RANDOM", 0xEu);
    LOBYTE(v25) = 17;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 18;
    v10 = INIReader::getFloat(&r, &key, &v22);
    v3 = key._Myres < 8;
    this->gravityRandom = v10;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    std::wstring::assign(&v22, L"OPACITY_BASE", 0xCu);
    LOBYTE(v25) = 19;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SETTINGS", 8u);
    LOBYTE(v25) = 20;
    v11 = INIReader::getFloat(&r, &key, &v22);
    v3 = key._Myres < 8;
    this->opacityBase = v11;
    if ( !v3 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    LOBYTE(v25) = 0;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    std::wstring::wstring(&key, L"OPACITY_RANDOM");
    LOBYTE(v25) = 21;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 22;
    v12 = INIReader::getFloat(&r, &v22, &key);
    v3 = v22._Myres < 8;
    this->opacityRandom = v12;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"OPACITY_VELOCITY_BASE");
    LOBYTE(v25) = 23;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 24;
    v13 = INIReader::getFloat(&r, &v22, &key);
    v3 = v22._Myres < 8;
    this->opacityVelocityBase = v13;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"OPACITY_VELOCITY_RANDOM");
    LOBYTE(v25) = 25;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 26;
    v14 = INIReader::getFloat(&r, &v22, &key);
    v3 = v22._Myres < 8;
    this->opacityVelocityRandom = v14;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SIZE_VELOCITY_BASE");
    LOBYTE(v25) = 27;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 28;
    v15 = INIReader::getFloat2(&r, (vec2f *)&section, &v22, &key);
    v3 = v22._Myres < 8;
    this->sizeVelocityBase = *v15;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SIZE_VELOCITY_RANDOM");
    LOBYTE(v25) = 29;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 30;
    v16 = INIReader::getFloat2(&r, (vec2f *)&section, &v22, &key);
    v3 = v22._Myres < 8;
    this->sizeVelocityRandom = *v16;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"VELOCITY_RANDOM");
    LOBYTE(v25) = 31;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 32;
    v17 = INIReader::getFloat3(&r, (vec3f *)&section, &v22, &key);
    v3 = v22._Myres < 8;
    this->velocityRandom = *v17;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"VELOCITY_BASE");
    LOBYTE(v25) = 33;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 34;
    v18 = INIReader::getFloat3(&r, (vec3f *)&section, &v22, &key);
    v3 = v22._Myres < 8;
    this->velocityBase = *v18;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    LOBYTE(v25) = 0;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"VELOCITY_ROTATION_AXIS_RANDOM");
    LOBYTE(v25) = 35;
    std::wstring::wstring(&v22, L"SETTINGS");
    LOBYTE(v25) = 36;
    v19 = INIReader::getFloat(&r, &v22, &key);
    v3 = v22._Myres < 8;
    this->velocityRotationAxisRandom = v19;
    if ( !v3 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v20 = this->frequency;
    key._Bx._Buf[0] = 0;
    key._Myres = 7;
    key._Mysize = 0;
    if ( v20 == 0.0 )
      this->frequency = DOUBLE_60_0;
  }
  v25 = -1;
  INIReader::~INIReader(&r);
}
