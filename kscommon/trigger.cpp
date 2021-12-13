#include "trigger.h"
void Trigger::Trigger(Trigger *this)
{
  this->accumulator = 0.0;
  this->accumulatorLimit = 0.0;
  *(_WORD *)&this->state = 0;
}
bool Trigger::ignoreSubsequentTrue(Trigger *this, bool value)
{
  bool result; // al

  if ( !value || this->lastState )
  {
    this->state = 0;
  }
  else
  {
    this->state = 1;
    this->lastState = value;
  }
  result = this->state;
  if ( !value )
    this->lastState = 0;
  return result;
}
bool Trigger::keepSteady(Trigger *this, float dt, bool value)
{
  bool result; // al
  float v4; // xmm0_4
  float v5; // xmm0_4
  bool v6; // cf

  if ( value && this->accumulator == 0.0 )
  {
    result = 1;
    this->accumulator = dt;
  }
  else
  {
    v4 = this->accumulator;
    if ( v4 == 0.0 )
    {
      result = 0;
    }
    else
    {
      v5 = v4 + dt;
      v6 = v5 < this->accumulatorLimit;
      this->accumulator = v5;
      if ( !v6 )
        this->accumulator = 0.0;
      result = 1;
    }
  }
  return result;
}
