#include "sctm.h"
void SCTM::SCTM(SCTM *this)
{
  this->__vftable = (SCTM_vtbl *)&SCTM::`vftable';
  this->lsMultY = 0.0;
  this->lsExpY = 0.0;
  this->lsMultX = 0.0;
  this->lsExpX = 0.0;
  this->Fz0 = 0.0;
  this->maxSlip0 = 0.0;
  this->maxSlip1 = 0.0;
  this->asy = 0.0;
  this->falloffSpeed = 0.0;
  this->speedSensitivity = 0.0;
  this->camberGain = 0.0;
  this->dcamber0 = 0.0;
  this->dcamber1 = 0.0;
  this->cfXmult = 1.0;
  Curve::Curve(&this->dyLoadCurve);
  Curve::Curve(&this->dxLoadCurve);
  this->pressureCfGain = 0.1;
  this->brakeDXMod = 1.0;
  Curve::Curve(&this->dCamberCurve);
  this->useSmoothDCamberCurve = 0;
  this->dCamberBlend = 1.0;
  this->combinedFactor = 2.0;
}
SCTM *SCTM::`vector deleting destructor'(SCTM *this, unsigned int a2)
{
  this->__vftable = (SCTM_vtbl *)&SCTM::`vftable';
  Curve::~Curve(&this->dCamberCurve);
  Curve::~Curve(&this->dxLoadCurve);
  Curve::~Curve(&this->dyLoadCurve);
  this->__vftable = (SCTM_vtbl *)&ITyreModel::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SCTM::~SCTM(SCTM *this)
{
  this->__vftable = (SCTM_vtbl *)&SCTM::`vftable';
  Curve::~Curve(&this->dCamberCurve);
  Curve::~Curve(&this->dxLoadCurve);
  Curve::~Curve(&this->dyLoadCurve);
  this->__vftable = (SCTM_vtbl *)&ITyreModel::`vftable';
}
TyreModelOutput *SCTM::solve(SCTM *this, TyreModelOutput *result, const TyreModelInput *in)
{
  const TyreModelInput *v3; // edi
  int v5; // ecx
  float v6; // xmm0_4
  double v7; // st7
  double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  double v16; // st7
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  Curve *v20; // ecx
  double v21; // st7
  double v22; // st7
  float v23; // xmm2_4
  double v24; // st7
  float v25; // xmm1_4
  float v26; // xmm0_4
  const TyreModelInput *v27; // xmm2_4
  float v28; // xmm1_4
  float *v29; // eax
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float _X; // xmm2_4
  double v34; // st7
  float v35; // xmm3_4
  const TyreModelInput *v36; // xmm6_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm4_4
  float v40; // xmm1_4
  float v41; // xmm3_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  float v44; // xmm6_4
  double v45; // st7
  float v46; // xmm0_4
  double v47; // st7
  TyreModelOutput *v48; // eax
  float v49; // xmm1_4
  float va; // [esp+10h] [ebp-24h]
  float v; // [esp+10h] [ebp-24h]
  float v52; // [esp+14h] [ebp-20h]
  float speed_factor; // [esp+18h] [ebp-1Ch]
  float speed_factora; // [esp+18h] [ebp-1Ch]
  float slx; // [esp+1Ch] [ebp-18h]
  float slxa; // [esp+1Ch] [ebp-18h]
  float v57; // [esp+20h] [ebp-14h]
  float rcambera; // [esp+24h] [ebp-10h]
  float rcamber; // [esp+24h] [ebp-10h]
  float slip_angle_camber; // [esp+28h] [ebp-Ch]
  float slip_angle_cambera; // [esp+28h] [ebp-Ch]
  float v62; // [esp+2Ch] [ebp-8h]
  float v63; // [esp+2Ch] [ebp-8h]
  float v64; // [esp+30h] [ebp-4h]
  float v65; // [esp+30h] [ebp-4h]
  float v66; // [esp+30h] [ebp-4h]

  v3 = in;
  if ( in->load <= 0.0 || in->slipAngleRAD == 0.0 && in->slipRatio == 0.0 && in->camberRAD == 0.0 )
  {
    v48 = result;
    result->Fx = 0.0;
    result->Fy = 0.0;
    result->Mz = 0.0;
    result->trail = 0.0;
    result->ndSlip = 0.0;
    result->Dx = 0.0;
    result->Dy = 0.0;
  }
  else
  {
    v52 = this->asy;
    if ( in->useSimpleModel )
      this->asy = 1.0;
    in = (const TyreModelInput *)LODWORD(v3->slipAngleRAD);
    slip_angle_camber = sin() * this->camberGain + *(float *)&in;
    v6 = *(double *)_libm_sse2_tan_precise(v5).m128_u64;
    v64 = v6;
    speed_factor = sin();
    v7 = saturate(v3->blister * 0.0099999998);
    va = v3->load;
    *(float *)&in = v7 * 0.2 + 1.0;
    v8 = SCTM::getStaticDY(this, va);
    v9 = v3->load;
    result->Dy = v8 / *(float *)&in;
    v10 = SCTM::getStaticDX(this, v9);
    v11 = v10 / *(float *)&in;
    v12 = v3->u;
    v13 = result->Dy * v12;
    v14 = v12 * v11;
    result->Dx = v11;
    slx = v13;
    v15 = v3->slipRatio >= 0.0;
    *(float *)&in = v13;
    v62 = v14;
    if ( !v15 )
      v62 = this->brakeDXMod * v14;
    v16 = fabs(v3->camberRAD);
    v17 = v3->camberRAD;
    if ( (v17 < 0.0 || slip_angle_camber < 0.0) && (v17 > 0.0 || slip_angle_camber > 0.0) )
    {
      rcambera = v16;
      LODWORD(v18) = LODWORD(rcambera) ^ _xmm;
    }
    else
    {
      v18 = v16;
    }
    LODWORD(v19) = LODWORD(v18) ^ _xmm;
    if ( Curve::getCount(&this->dCamberCurve) )
    {
      v20 = &this->dCamberCurve;
      v = v19 * 57.29578;
      if ( this->useSmoothDCamberCurve )
        v21 = Curve::getCubicSplineValue(v20, v);
      else
        v21 = Curve::getValue(v20, v);
      v22 = v21 * *(float *)&in;
    }
    else
    {
      v23 = (float)(this->dcamber0 * v19) - (float)((float)(v19 * v19) * this->dcamber1);
      if ( v23 <= -1.0 )
        v23 = FLOAT_N0_89999998;
      v22 = lerp(slx, slx / (float)(v23 + 1.0), this->dCamberBlend);
    }
    *(float *)&in = v22;
    slxa = cos() * (float)(v3->speed * v3->slipRatio);
    speed_factora = sqrt(
                      (float)((float)(v3->speed * speed_factor) * (float)(v3->speed * speed_factor))
                    + (float)(slxa * slxa))
                  * this->speedSensitivity
                  + 1.0;
    slip_angle_cambera = *(float *)&in / speed_factora;
    v63 = v62 / speed_factora;
    v24 = lerp(1.0, v3->u, 0.75);
    v25 = v3->load - this->Fz0;
    v26 = this->maxSlip1 - this->maxSlip0;
    *(float *)&in = v24;
    v27 = in;
    v28 = v25 / this->Fz0;
    *(float *)&in = -0.99998999;
    rcamber = (float)((float)((float)((float)(1.0
                                            / (float)(*(float *)&v27 * (float)((float)(v28 * v26) + this->maxSlip0)))
                                    * 3.0)
                            * 78.125)
                    / (float)((float)(v3->grain * 0.0099999998) + 1.0))
            * (float)((float)(this->pressureCfGain * v3->pressureRatio) + 1.0);
    v29 = (float *)std::max<float>((const float *)&in, &v3->slipRatio);
    v30 = this->combinedFactor;
    v31 = *v29 + 1.0;
    v32 = v3->slipRatio / v31;
    _X = v64 / v31;
    v57 = v32;
    v65 = v64 / v31;
    if ( v30 <= 0.0 || v30 == 2.0 )
    {
      v34 = sqrt((float)(_X * _X) + (float)(v32 * v32));
    }
    else
    {
      fabs(_X);
      *(float *)&in = pow();
      fabs(v32);
      pow();
      v34 = pow();
    }
    v35 = (float)(rcamber * 2.0) * 0.0063999998;
    *(float *)&in = v34;
    v36 = in;
    v37 = 1.0 / (float)(v35 / 3.0);
    if ( v37 < *(float *)&in )
      v38 = (float)((float)(1.0 / (float)((float)((float)(*(float *)&in - v37) * this->falloffSpeed) + 1.0))
                  * (float)(1.0 - this->asy))
          + this->asy;
    else
      v38 = (float)((float)(3.0 - (float)((float)(*(float *)&in / v37) * 2.0))
                  * (float)((float)(*(float *)&in / v37) * (float)(*(float *)&in / v37)))
          + (float)((float)((float)(1.0 - (float)(*(float *)&in / v37)) * (float)(1.0 - (float)(*(float *)&in / v37)))
                  * (float)(v35 * *(float *)&in));
    v39 = v38 * slip_angle_cambera;
    v40 = (float)((float)(this->cfXmult * rcamber) * 2.0) * 0.0063999998;
    v41 = 1.0 / (float)(v40 / 3.0);
    if ( v41 < *(float *)&in )
      v42 = (float)((float)(1.0 / (float)((float)((float)(*(float *)&in - v41) * this->falloffSpeed) + 1.0))
                  * (float)(1.0 - this->asy))
          + this->asy;
    else
      v42 = (float)((float)((float)(1.0 - (float)(*(float *)&in / v41)) * (float)(1.0 - (float)(*(float *)&in / v41)))
                  * (float)(v40 * *(float *)&in))
          + (float)((float)(3.0 - (float)((float)(*(float *)&in / v41) * 2.0))
                  * (float)((float)(*(float *)&in / v41) * (float)(*(float *)&in / v41)));
    v66 = (float)((float)(v65 / *(float *)&in) * v39) * v3->load;
    result->Fy = v66;
    v43 = v57 / *(float *)&v36;
    v44 = *(float *)&v36 / v37;
    result->ndSlip = v44;
    result->Fx = (float)(v43 * (float)(v42 * v63)) * v3->load;
    v45 = saturate(1.0 - (float)(v44 * 0.80000001));
    v46 = v3->speed;
    *(float *)&in = v45;
    v47 = saturate(v46);
    v48 = result;
    *(float *)&in = v47
                  * (float)((float)((float)((float)((float)((float)(3.0 - (float)(*(float *)&in * 2.0))
                                                          * (float)(*(float *)&in * *(float *)&in))
                                                  * 1.1)
                                          - 0.1)
                                  * v3->cpLength)
                          * 0.12);
    v49 = v66 * *(float *)&in;
    result->trail = *(float *)&in;
    result->Dy = slip_angle_cambera;
    result->Dx = v63;
    this->asy = v52;
    LODWORD(result->Mz) = LODWORD(v49) ^ _xmm;
  }
  return v48;
}
double SCTM::getStaticDY(SCTM *this, float load)
{
  if ( Curve::getCount(&this->dyLoadCurve) > 0 )
    return Curve::getCubicSplineValue(&this->dyLoadCurve, load);
  if ( load == 0.0 )
    return 0.0;
  return (float)(pow() * this->lsMultY / load);
}
float __usercall SCTM::getStaticDX@<xmm0>(SCTM *this@<ecx>, float ref@<xmm1>)
{
  float result; // xmm0_4
  float v5; // [esp+10h] [ebp-4h]
  float v6; // [esp+10h] [ebp-4h]

  if ( Curve::getCount(&this->dxLoadCurve) <= 0 )
  {
    result = 0.0;
    if ( ref != 0.0 )
    {
      v6 = pow() * this->lsMultX / ref;
      result = v6;
    }
  }
  else
  {
    v5 = Curve::getCubicSplineValue(&this->dxLoadCurve, ref);
    result = v5;
  }
  return result;
}
