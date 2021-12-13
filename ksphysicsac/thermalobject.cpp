#include "thermalobject.h"
void ThermalObject::ThermalObject(ThermalObject *this)
{
  this->__vftable = (ThermalObject_vtbl *)&ThermalObject::`vftable';
  this->tmass = 1.0;
  this->coolSpeedK = 0.0;
  this->coolFactor = 0.2;
  this->heatFactor = 1.0;
  this->t = 0.0;
  this->heatAccumulator = 0.0;
}
void ThermalObject::~ThermalObject(ThermalObject *this)
{
  this->__vftable = (ThermalObject_vtbl *)&ThermalObject::`vftable';
}
ThermalObject *ThermalObject::`scalar deleting destructor'(ThermalObject *this, unsigned int a2)
{
  this->__vftable = (ThermalObject_vtbl *)&ThermalObject::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ThermalObject::addHeadSource(ThermalObject *this, float heat)
{
  this->heatAccumulator = heat + this->heatAccumulator;
}
void ThermalObject::step(ThermalObject *this, const float dt, const float ambientTemp, const Speed *speed)
{
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm2_4

  v4 = 1.0 / this->tmass;
  v5 = this->heatAccumulator;
  v6 = 1.0 - (float)(this->coolSpeedK * speed->value);
  this->heatAccumulator = 0.0;
  v7 = (float)((float)((float)((float)((float)(v6 * ambientTemp) - this->t) * v4) * dt) * this->coolFactor) + this->t;
  this->t = v7;
  if ( v5 != 0.0 )
    this->t = (float)((float)((float)((float)(v5 - v7) * v4) * dt) * this->heatFactor) + v7;
}
