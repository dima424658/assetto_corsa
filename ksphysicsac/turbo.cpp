#include "turbo.h"
double Turbo::getWastegate(Turbo *this)
{
  return this->data.wastegate;
}
void Turbo::Turbo(Turbo *this, TurboDef *data)
{
  this->userSetting = 1.0;
  this->data.isAdjustable = 0;
  this->data.maxBoost = 0.0;
  this->data.lagUP = 0.0;
  this->data.lagDN = 0.0;
  this->data.rpmRef = 6000.0;
  this->data.gamma = 1.0;
  this->data.wastegate = 0.0;
  *(__m128i *)&this->data.maxBoost = _mm_loadu_si128((const __m128i *)data);
  *(_QWORD *)&this->data.gamma = *(_QWORD *)&data->gamma;
  *(_DWORD *)&this->data.isAdjustable = *(_DWORD *)&data->isAdjustable;
  this->rotation = 0.0;
}
double Turbo::getBoost(Turbo *this)
{
  return this->data.maxBoost * this->rotation;
}
void Turbo::setTurboBoostLevel(Turbo *this, float value)
{
  if ( this->data.isAdjustable )
    this->userSetting = value;
  else
    this->userSetting = 1.0;
}
void Turbo::step(Turbo *this, float gas, float rpms, float dt)
{
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4

  v5 = FLOAT_1_0;
  v6 = 0.0;
  if ( rpms > 0.0 && gas > 0.0 )
  {
    LODWORD(v6) = __libm_sse2_powf(this).m128_u32[0];
    v5 = FLOAT_1_0;
  }
  v7 = this->rotation;
  if ( v6 <= v7 )
    v8 = this->data.lagDN;
  else
    v8 = this->data.lagUP;
  v9 = v8 * dt;
  if ( v9 <= v5 )
  {
    if ( v9 >= 0.0 )
      v5 = v9;
    else
      v5 = 0.0;
  }
  v10 = (float)((float)(v6 - v7) * v5) + v7;
  v11 = this->data.wastegate;
  this->rotation = v10;
  if ( v11 != 0.0 )
  {
    v12 = v11 * this->userSetting;
    if ( (float)(this->data.maxBoost * this->rotation) > v12 )
      this->rotation = v12 / this->data.maxBoost;
  }
}
