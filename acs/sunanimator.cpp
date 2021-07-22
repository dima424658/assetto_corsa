#include "sunanimator.h"
void SunAnimator::SunAnimator(SunAnimator *this, Sim *aSim, float baseAngle, float velocityMult, float cloudSpeed)
{
  double v6; // st7
  Game *v7; // eax
  std::wstring v8; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v9; // [esp-4h] [ebp-24h]
  SunAnimator *v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-4h]

  v10 = this;
  v9 = aSim->game;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"SUN_ANIMATOR", 0xCu);
  GameObject::GameObject(this, v8, v9);
  this->baseAngle = baseAngle;
  this->cloudSpeed = cloudSpeed;
  v11 = 0;
  this->__vftable = (SunAnimator_vtbl *)&SunAnimator::`vftable';
  this->timeMult = 1.0;
  this->timePassed = 0.0;
  this->velocityMultiplier = velocityMult;
  this->sim = aSim;
  v6 = ksGetTime();
  v7 = this->game;
  this->startTime = v6;
  v9 = (Game *)this;
  v7->graphics->lightingSettings.gameTime = v7->gameTime.now - v7->gameTime.startTime;
  v8._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_ea14262656fe58370fe0eeb64f5a5586_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v8._Bx._Alias[4] = this;
  v8._Mysize = (unsigned int)&v8;
  LOBYTE(v11) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&aSim->evOnReplayStatusChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v8,
    v9);
  this->skybox = Sim::getSceneCamera(aSim)->skyBox;
}
SunAnimator *SunAnimator::`scalar deleting destructor'(SunAnimator *this, unsigned int a2)
{
  this->__vftable = (SunAnimator_vtbl *)&SunAnimator::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SunAnimator::enableCustomSunDirection(SunAnimator *this, bool value)
{
  this->game->graphics->useCustomSunDirection = value;
  this->isActive = !value;
}
double SunAnimator::getVelocityMultiplier(SunAnimator *this)
{
  return this->velocityMultiplier;
}
void __userpurge SunAnimator::setSunDirection(SunAnimator *this@<ecx>, int a2@<esi>, __m128 a3@<xmm4>, float zenith, float azimuth, float nordOffset)
{
  __m128 v7; // xmm2
  float v8; // xmm3_4
  unsigned __int64 v9; // xmm4_8
  float v10; // ecx
  float v11; // xmm0_4
  vec3f v12; // [esp-10h] [ebp-2Ch]
  int v14; // [esp-4h] [ebp-20h]
  int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+0h] [ebp-1Ch]
  unsigned __int64 v17; // [esp+Ch] [ebp-10h]
  float v18; // [esp+18h] [ebp-4h]
  float nordOffseta; // [esp+28h] [ebp+Ch]

  nordOffseta = __libm_sse2_sinf().m128_f32[0];
  v18 = __libm_sse2_cosf(a2, v15).m128_f32[0] * nordOffseta;
  v7 = _mm_xor_ps((__m128)__libm_sse2_cosf(v14, v16).m128_u32[0], (__m128)(unsigned int)_xmm);
  LODWORD(v8) = LODWORD(v18) ^ _xmm;
  a3.m128_i32[0] = LODWORD(v18) ^ _xmm;
  v9 = _mm_unpacklo_ps(a3, v7).m128_u64[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(__libm_sse2_sinf().m128_f32[0] * (float)(nordOffseta * -1.0)) ^ _xmm;
  v11 = fsqrt((float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10));
  if ( v11 != 0.0 )
  {
    *(float *)&v17 = v8 * (float)(1.0 / v11);
    *((float *)&v17 + 1) = (float)(1.0 / v11) * *((float *)&v9 + 1);
    v9 = v17;
    v10 = (float)(1.0 / v11) * v10;
  }
  *(_QWORD *)&v12.x = v9;
  v12.z = v10;
  GraphicsManager::setCustomSunDirection(this->game->graphics, v12);
}
void SunAnimator::update(SunAnimator *this, float dt)
{
  Sim *v3; // ecx
  bool v4; // al
  SkyBox *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  Game *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // [esp+8h] [ebp-4h]

  v3 = this->sim;
  v11 = dt * this->timeMult;
  if ( !v3->pauseMenu->visible )
  {
    v4 = ReplayManager::isInReplaymode(v3->replayManager);
    v5 = this->skybox;
    v6 = (float)(this->velocityMultiplier * dt) * this->timeMult;
    if ( v4 )
    {
      SkyBox::updateCloudsAnimation(v5, v6 * this->sim->replayManager->timeMult);
      this->game->graphics->lightingSettings.angle = ReplayManager::getCurrentSunAngle(this->sim->replayManager);
      this->game->graphics->lightingSettings.gameTime = (float)(v11 * 1000.0)
                                                      + this->game->graphics->lightingSettings.gameTime;
      this->game->graphics->lightingSettings.cloudOffset = (float)((float)(this->timePassed * 0.0044)
                                                                 * this->velocityMultiplier)
                                                         * this->cloudSpeed;
      GraphicsManager::updateLightingSetttings(this->game->graphics);
    }
    else
    {
      SkyBox::updateCloudsAnimation(v5, v6);
      v7 = this->timePassed + dt;
      v8 = this->game;
      v9 = FLOAT_80_0;
      this->timePassed = v7;
      v8->graphics->lightingSettings.cloudOffset = (float)((float)(v7 * 0.0044) * this->velocityMultiplier)
                                                 * this->cloudSpeed;
      v10 = (float)((float)(this->timePassed * 0.0044) * this->velocityMultiplier) + this->baseAngle;
      if ( v10 <= 80.0 )
      {
        v9 = FLOAT_N80_0;
        if ( v10 >= -80.0 )
          v9 = (float)((float)(this->timePassed * 0.0044) * this->velocityMultiplier) + this->baseAngle;
      }
      this->game->graphics->lightingSettings.angle = v9;
      this->game->graphics->lightingSettings.gameTime = (float)(v11 * 1000.0)
                                                      + this->game->graphics->lightingSettings.gameTime;
      GraphicsManager::updateLightingSetttings(this->game->graphics);
    }
  }
}
