#include "pidcontroller.h"
void PIDController::PIDController(PIDController *this)
{
  this->P = 0.0;
  this->I = 0.0;
  this->D = 0.0;
  this->currentError = 0.0;
  this->integral = 0.0;
}
double PIDController::eval(PIDController *this, float targetv, float currentv, float dt)
{
  float v4; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float out; // [esp+4h] [ebp+4h]

  currentv = targetv - currentv;
  v4 = currentv;
  v6 = this->I;
  v7 = (float)(currentv * dt) + this->integral;
  v8 = (float)((float)(currentv - this->currentError) / dt) * this->D;
  v9 = this->P * currentv;
  this->integral = v7;
  this->currentError = v4;
  dt = v8 + (float)((float)(v6 * v7) + v9);
  out = dt;
  if ( __fdtest(&currentv) > 0
    || (currentv = dt, __fdtest(&currentv) > 0)
    || (currentv = this->integral, __fdtest(&currentv) > 0) )
  {
    out = 0.0;
    this->currentError = 0.0;
    this->integral = 0.0;
  }
  return out;
}
void PIDController::reset(PIDController *this)
{
  this->integral = 0.0;
  this->currentError = 0.0;
}
void PIDController::setPID(PIDController *this, float p, float i, float d)
{
  this->P = p;
  this->I = i;
  this->D = d;
}
