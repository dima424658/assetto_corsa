#include "gametime.h"
void GameTime::GameTime(GameTime *this)
{
  double v2; // st7

  this->__vftable = (GameTime_vtbl *)&GameTime::`vftable';
  this->m_isUsingHRT = 1;
  v2 = ksGetTime();
  this->deltaT = 0.0;
  this->startTime = v2;
  this->smoothDeltaT = 0.0;
  this->fps = 0.0;
  this->now = 0.0;
  this->useStabilizer = 0;
  this->cappedFPS = 0.0;
}
void GameTime::~GameTime(GameTime *this)
{
  this->__vftable = (GameTime_vtbl *)&GameTime::`vftable';
}
GameTime *GameTime::`vector deleting destructor'(GameTime *this, unsigned int a2)
{
  this->__vftable = (GameTime_vtbl *)&GameTime::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GameTime::update(GameTime *this)
{
  bool v2; // bl
  double v3; // xmm0_8
  double i; // xmm2_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float v7; // xmm0_4
  bool v8; // zf
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4

  if ( this->now == 0.0 )
  {
    this->now = ksGetTime();
  }
  else
  {
    v2 = ksTimeSyncAndCheck();
    if ( v2 != this->m_isUsingHRT )
      _printf("WARNING: Timer was switched to low res timer\n");
    v3 = this->cappedFPS;
    this->m_isUsingHRT = v2;
    if ( v3 == 0.0 )
    {
      i = ksGetTime();
    }
    else
    {
      for ( i = ksGetTime(); this->cappedFPS > i - this->now; i = ksGetTime() )
        ;
    }
    v5 = i - this->now;
    if ( v5 < 0.0 )
      v5 = 0.0;
    v6 = v5 * 0.001;
    v7 = FLOAT_0_2;
    this->deltaT = v6;
    if ( v6 <= 0.2 )
      v7 = v6;
    v8 = !this->useStabilizer;
    v9 = this->smoothDeltaT;
    this->deltaT = v7;
    v10 = (float)(v9 * 0.99000001) + (float)(v7 * 0.0099999998);
    this->smoothDeltaT = v10;
    if ( !v8 )
      this->deltaT = v10;
    v11 = (float)(v10 * 0.89999998) + (float)(this->deltaT * 0.1);
    this->smoothDeltaT = v11;
    if ( v11 == 0.0 )
    {
      this->fps = 1.0;
      this->now = i;
    }
    else
    {
      this->now = i;
      this->fps = 1.0 / v11;
    }
  }
}
