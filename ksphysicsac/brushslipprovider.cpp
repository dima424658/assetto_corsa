#include "brushslipprovider.h"
BrushSlipProvider *BrushSlipProvider::operator=(BrushSlipProvider *this, const BrushSlipProvider *__that)
{
  *(__m128i *)&this->brushModel.data.CF = _mm_loadu_si128((const __m128i *)&__that->brushModel);
  *(_QWORD *)&this->brushModel.data.maxSlip0 = *(_QWORD *)&__that->brushModel.data.maxSlip0;
  this->brushModel.data.falloffSpeed = __that->brushModel.data.falloffSpeed;
  this->asy = __that->asy;
  this->version = __that->version;
  this->maximum = __that->maximum;
  this->maxSlip = __that->maxSlip;
  return this;
}
void BrushSlipProvider::BrushSlipProvider(BrushSlipProvider *this, float maxAngle, float xu, float flex)
{
  double v5; // st7

  this->__vftable = (BrushSlipProvider_vtbl *)&BrushSlipProvider::`vftable';
  BrushTyreModel::BrushTyreModel(&this->brushModel);
  this->asy = 1.0;
  this->version = 0;
  this->maximum = 0.0;
  this->maxSlip = 0.0;
  v5 = BrushTyreModel::getCFFromSlipAngle(&this->brushModel, maxAngle);
  this->brushModel.data.CF1 = flex * -50000.0;
  this->brushModel.data.CF = v5;
  BrushSlipProvider::calcMaximum(this, 2000.0, &this->maximum, &this->maxSlip);
}
void BrushSlipProvider::BrushSlipProvider(BrushSlipProvider *this)
{
  this->__vftable = (BrushSlipProvider_vtbl *)&BrushSlipProvider::`vftable';
  BrushTyreModel::BrushTyreModel(&this->brushModel);
  this->asy = 1.0;
  this->version = 0;
  this->maximum = 0.0;
  this->maxSlip = 0.0;
}
void BrushSlipProvider::~BrushSlipProvider(BrushSlipProvider *this)
{
  this->__vftable = (BrushSlipProvider_vtbl *)&BrushSlipProvider::`vftable';
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->brushModel);
}
void BrushSlipProvider::calcMaximum(BrushSlipProvider *this, float load, float *maximum, float *max_slip)
{
  float v4; // xmm2_4
  float slip; // xmm1_4
  BrushTyreModel *v7; // eax
  BrushOutput *v8; // eax
  float v9; // [esp+20h] [ebp-1Ch]
  BrushOutput result; // [esp+2Ch] [ebp-10h] BYREF
  BrushOutput v11; // [esp+34h] [ebp-8h] BYREF

  v4 = load;
  slip = 0.0;
  v9 = 0.0;
  if ( load < 0.0 )
  {
    v4 = FLOAT_2000_0;
    load = FLOAT_2000_0;
  }
  v7 = &this->brushModel;
  *maximum = 0.0;
  *max_slip = 0.0;
  do
  {
    if ( this->version >= 5 )
      v8 = BrushTyreModel::solveV5(v7, &v11, slip, v4, this->asy);
    else
      v8 = BrushTyreModel::solve(v7, &result, slip, 1.0, v4, 1.0, this->asy);
    if ( v8->force > *maximum )
    {
      *maximum = v8->force;
      *max_slip = v9;
    }
    slip = v9 + 0.001;
    v7 = &this->brushModel;
    v4 = load;
    v9 = slip;
  }
  while ( slip < 1.0 );
}
const TyreSlipInput *BrushSlipProvider::getSlipForce(BrushSlipProvider *this, const TyreSlipInput *input, const TyreSlipInput *useasy, bool useasya)
{
  float asy; // xmm0_4
  BrushOutput *v5; // eax
  float v6; // ecx
  const TyreSlipInput *v7; // eax
  float res_4; // [esp+18h] [ebp-Ch]
  BrushOutput result; // [esp+1Ch] [ebp-8h] BYREF

  if ( this->version < 5 )
  {
    v5 = BrushTyreModel::solve(&this->brushModel, &result, useasy->slip, 1.0, useasy->load, 1.0, 1.0);
  }
  else
  {
    if ( useasya )
      asy = this->asy;
    else
      asy = FLOAT_1_0;
    v5 = BrushTyreModel::solveV5(&this->brushModel, &result, useasy->slip, useasy->load, asy);
  }
  v6 = v5->force;
  res_4 = v5->slip;
  v7 = input;
  input->friction = res_4;
  input->slip = v6;
  return v7;
}
void BrushSlipProvider::recomputeMaximum(BrushSlipProvider *this)
{
  BrushSlipProvider::calcMaximum(this, 2000.0, &this->maximum, &this->maxSlip);
}
