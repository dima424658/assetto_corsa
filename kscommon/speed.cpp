#include "speed.h"
double Speed::kmh(Speed *this)
{
  return this->value * 3.5999999;
}
double Speed::toSystemDefault(Speed *this)
{
  double v1; // st7
  double result; // st7

  v1 = this->value;
  if ( Speed::useMPH )
    result = v1 * 2.2369363;
  else
    result = v1 * 3.5999999;
  return result;
}
void Speed::Speed(Speed *this, float v)
{
  this->value = v;
}
Speed *__cdecl Speed::fromKMH(Speed *result, float ms)
{
  Speed *v2; // eax

  v2 = result;
  result->value = ms * 0.27777779;
  return v2;
}
Speed *__cdecl Speed::fromMPH(Speed *result, float ms)
{
  Speed *v2; // eax

  v2 = result;
  result->value = ms * 0.44703999;
  return v2;
}
Speed *__cdecl Speed::fromMS(Speed *result, float ms)
{
  Speed *v2; // eax

  v2 = result;
  result->value = ms;
  return v2;
}
Speed *Speed::operator*(Speed *this, Speed *result, const float v2)
{
  Speed::Speed(result, this->value * v2);
  return result;
}
