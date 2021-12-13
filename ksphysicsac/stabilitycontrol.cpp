#include "stabilitycontrol.h"
void StabilityControl::init(StabilityControl *this, Car *car)
{
  this->car = car;
  this->maxGain = 30.0;
  this->gain = 0.0;
  this->useBeta = 0;
}
void StabilityControl::step(StabilityControl *this, float dt)
{
  char v3; // dl
  float v4; // xmm4_4
  float v5; // xmm1_4
  int v6; // xmm0_4
  Car *v7; // ecx
  Speed *v8; // eax
  bool v9; // bl
  Car *v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm0_4
  Car *v13; // eax
  float v14; // [esp+4h] [ebp-24h]
  float v15; // [esp+4h] [ebp-24h]
  int v16; // [esp+4h] [ebp-24h]
  Speed result; // [esp+8h] [ebp-20h] BYREF
  float v18; // [esp+Ch] [ebp-1Ch]
  int v19[3]; // [esp+10h] [ebp-18h] BYREF
  char v20[8]; // [esp+1Ch] [ebp-Ch] BYREF
  float v21; // [esp+24h] [ebp-4h]

  v3 = 0;
  v14 = 0.0;
  v18 = 0.0;
  v4 = this->gain;
  if ( this->gain > 0.0 )
  {
    if ( this->useBeta )
    {
      this->car->body->getLocalVelocity(this->car->body, (vec3f *)v20);
      if ( v21 <= 5.0 )
        return;
      v5 = __libm_sse2_atanf().m128_f32[0];
      v15 = FLOAT_0_52358997;
      if ( v5 <= 0.52358997 )
      {
        v15 = FLOAT_N0_52358997;
        if ( v5 >= -0.52358997 )
          v15 = v5;
      }
      *(float *)&v16 = ((double (*)(IRigidBody *))this->car->body->getMass)(this->car->body)
                     * (float)((float)(this->gain * v15) * 10.0);
      v6 = v16;
      goto LABEL_22;
    }
    v7 = this->car;
    v18 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7->tyres[3].status.slipAngleRAD + v7->tyres[2].status.slipAngleRAD) & _xmm)
                - COERCE_FLOAT(COERCE_UNSIGNED_INT(v7->tyres[1].status.slipAngleRAD + v7->tyres[0].status.slipAngleRAD) & _xmm))
        * 0.5;
    v9 = 0;
    if ( v18 > 0.0 && v4 > 0.0 )
    {
      v8 = Car::getSpeed(v7, &result);
      v3 = 1;
      if ( (float)(v8->value * 3.5999999) > 5.0 )
        v9 = 1;
    }
    if ( (v3 & 1) != 0 )
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    if ( v9 )
    {
      v10 = this->car;
      v11 = v10->tyres[2].status.slipAngleRAD;
      if ( v11 <= 0.0 )
      {
        if ( v11 >= 0.0 )
        {
LABEL_21:
          result.value = v10->body->getMass(v10->body);
          v6 = COERCE_UNSIGNED_INT((float)((float)((float)(result.value * v18) * this->gain) * this->maxGain) * v14) ^ _xmm;
LABEL_22:
          v13 = this->car;
          v19[0] = 0;
          v19[1] = v6;
          v19[2] = 0;
          v13->body->addLocalTorque(v13->body, (const vec3f *)v19);
          return;
        }
        v12 = FLOAT_N1_0;
      }
      else
      {
        v12 = FLOAT_1_0;
      }
      v14 = v12;
      goto LABEL_21;
    }
  }
}
