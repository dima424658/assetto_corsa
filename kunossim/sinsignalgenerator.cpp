#include "sinsignalgenerator.h"
void SinSignalGenerator::SinSignalGenerator(SinSignalGenerator *this)
{
  SignalGenerator::SignalGenerator(this);
  this->__vftable = (SinSignalGenerator_vtbl *)&SinSignalGenerator::`vftable';
}
void SinSignalGenerator::~SinSignalGenerator(SinSignalGenerator *this)
{
  this->__vftable = (SinSignalGenerator_vtbl *)&SinSignalGenerator::`vftable';
  SignalGenerator::~SignalGenerator(this);
}
SinSignalGenerator *SinSignalGenerator::`scalar deleting destructor'(SinSignalGenerator *this, unsigned int a2)
{
  this->__vftable = (SinSignalGenerator_vtbl *)&SinSignalGenerator::`vftable';
  SignalGenerator::~SignalGenerator(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double SinSignalGenerator::getValue(SinSignalGenerator *this)
{
  float v1; // xmm0_4
  float Px; // [esp+4h] [ebp-4h] BYREF

  LODWORD(v1) = __libm_sse2_sinf().m128_u32[0];
  Px = v1;
  if ( __fdtest(&Px) > 0 )
    _printf("WARNING: SinSignalGenerator::getValue NaN res\n");
  return v1;
}
