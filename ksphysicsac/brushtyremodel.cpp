#include "brushtyremodel.h"
void BrushTyreModel::BrushTyreModel(BrushTyreModel *this)
{
  this->data.Fz0 = 2000.0;
  this->data.maxSlip0 = 0.2;
  this->data.maxSlip1 = 0.40000001;
  this->data.falloffSpeed = 2.0;
  this->data.CF = 1200.0;
  this->data.xu = 0.0;
  this->data.CF1 = -10.0;
}
double BrushTyreModel::getCFFromSlipAngle(BrushTyreModel *this, float angle)
{
  return (float)((float)((float)(1.0 / __libm_sse2_tanf(this).m128_f32[0]) * 3.0) * 78.125);
}
BrushOutput *BrushTyreModel::solve(BrushTyreModel *this, BrushOutput *result, float slip, float friction, float load, float cf1_mix, float asy)
{
  BrushOutput *v7; // eax
  float v8; // xmm3_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm1_4

  v7 = result;
  v8 = this->data.CF * 0.33333334;
  result->force = 0.0;
  result->slip = 0.0;
  if ( v8 <= (float)((float)((float)((float)((float)(load * 0.00050000002) - 1.0) * this->data.CF1) * cf1_mix)
                   + this->data.CF) )
    v8 = (float)((float)((float)((float)(load * 0.00050000002) - 1.0) * this->data.CF1) * cf1_mix) + this->data.CF;
  v9 = (float)((float)(v8 * 2.0) * 0.079999998) * 0.079999998;
  v10 = v9 / (float)(friction * 3.0);
  v11 = slip / (float)(1.0 / v10);
  result->slip = v11;
  if ( (float)(1.0 / v10) < slip )
    v12 = (float)((float)(1.0 - asy) / (float)((float)((float)(slip - (float)(1.0 / v10)) * 2.0) + 1.0)) + asy;
  else
    v12 = (float)((float)((float)((float)(1.0 - v11) * (float)(1.0 - v11)) * (float)(v9 * slip))
                * (float)((float)(this->data.xu * friction) + 1.0))
        + (float)((float)(3.0 - (float)(v11 * 2.0)) * (float)(v11 * v11));
  result->force = v12;
  return v7;
}
BrushOutput *BrushTyreModel::solveV5(BrushTyreModel *this, BrushOutput *result, float slip, float load, float asy)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  BrushOutput *v7; // eax
  float v8; // xmm4_4
  float v9; // xmm6_4

  v5 = this->data.maxSlip1 - this->data.maxSlip0;
  v6 = (float)(load - this->data.Fz0) / this->data.Fz0;
  v7 = result;
  result->force = 0.0;
  v8 = (float)((float)((float)((float)(1.0 / (float)((float)(v6 * v5) + this->data.maxSlip0)) * 3.0) * 78.125) * 2.0)
     * 0.0063999998;
  v9 = 1.0 / (float)(v8 * 0.33333334);
  result->slip = slip / v9;
  if ( v9 < slip )
    result->force = (float)((float)(1.0 - asy) / (float)((float)((float)(slip - v9) * this->data.falloffSpeed) + 1.0))
                  + asy;
  else
    result->force = (float)((float)((float)(1.0 - (float)(slip / v9)) * (float)(1.0 - (float)(slip / v9)))
                          * (float)(v8 * slip))
                  + (float)((float)(3.0 - (float)((float)(slip / v9) * 2.0))
                          * (float)((float)(slip / v9) * (float)(slip / v9)));
  return v7;
}
