#include "damper.h
void Damper::Damper(Damper *this)
{
  this->reboundSlow = 5000.0;
  this->reboundFast = 300.0;
  this->bumpSlow = 2000.0;
  this->bumpFast = 300.0;
  this->fastThresholdBump = 0.2;
  this->fastThresholdRebound = 0.2;
}
double Damper::getForce(Damper *this, float v)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  double result; // st7
  float v5; // xmm2_4
  float v6; // xmm0_4

  if ( v <= 0.0 )
  {
    v5 = this->fastThresholdRebound;
    if ( COERCE_FLOAT(LODWORD(v) & _xmm) <= v5 )
      LODWORD(v6) = COERCE_UNSIGNED_INT(this->reboundSlow * v) ^ _xmm;
    else
      v6 = (float)(v5 * this->reboundSlow) - (float)((float)(v5 + v) * this->reboundFast);
    result = v6;
  }
  else
  {
    v2 = this->fastThresholdBump;
    v3 = this->bumpSlow;
    if ( v <= v2 )
      result = COERCE_FLOAT(COERCE_UNSIGNED_INT(v3 * v) ^ _xmm);
    else
      result = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v - v2) * this->bumpFast) + (float)(v3 * v2)) ^ _xmm);
  }
  return result;
}
