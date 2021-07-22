#include "signalgenerator.h
void SignalGenerator::SignalGenerator(SignalGenerator *this)
{
  this->__vftable = (SignalGenerator_vtbl *)&SignalGenerator::`vftable';
  this->value = 0;
  this->freqScale = 1.0;
}
void SignalGenerator::~SignalGenerator(SignalGenerator *this)
{
  this->__vftable = (SignalGenerator_vtbl *)&SignalGenerator::`vftable';
}
SignalGenerator *SignalGenerator::`scalar deleting destructor'(SignalGenerator *this, unsigned int a2)
{
  this->__vftable = (SignalGenerator_vtbl *)&SignalGenerator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SignalGenerator::step(SignalGenerator *this, float dt)
{
  this->value += (int)(float)((float)(dt * 1000.0) * this->freqScale);
}
