#include "raceengineer.h
Car *RaceEngineer::getCar(RaceEngineer *this)
{
  return this->car;
}
              && RaceEngineer::getCar(_Val->car->raceEngineer._Myptr)->isRetired )
            {
              goto LABEL_21;
            }
            && RaceEngineer::getCar(b->car->raceEngineer._Myptr)->isRetired )
          {
            return 1;
          }
void RaceEngineer::RaceEngineer(RaceEngineer *this, Car *icar)
{
  this->car = icar;
  this->__vftable = (RaceEngineer_vtbl *)&RaceEngineer::`vftable';
  this->fuelPerLapEvaluated = 0.0;
}
void RaceEngineer::~RaceEngineer(RaceEngineer *this)
{
  this->__vftable = (RaceEngineer_vtbl *)&RaceEngineer::`vftable';
}
RaceEngineer *RaceEngineer::`vector deleting destructor'(RaceEngineer *this, unsigned int a2)
{
  this->__vftable = (RaceEngineer_vtbl *)&RaceEngineer::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double RaceEngineer::evalAvailableBrake(RaceEngineer *this, float speed, float latg, float weight)
{
  double v5; // st7
  Car *v6; // ecx
  float v7; // xmm1_4
  double v8; // st7
  double v9; // st7
  Car *v10; // eax
  float v11; // xmm3_4
  float v12; // xmm0_4
  float speedMS_4; // [esp+4h] [ebp-20h]
  float speedMS_4a; // [esp+4h] [ebp-20h]
  WheelValues result; // [esp+10h] [ebp-14h] BYREF
  float v17; // [esp+20h] [ebp-4h]
  float latga; // [esp+2Ch] [ebp+8h]
  float weightb; // [esp+30h] [ebp+Ch]
  float weightc; // [esp+30h] [ebp+Ch]
  float weighta; // [esp+30h] [ebp+Ch]

  v17 = 1.0 / weight;
  v5 = RaceEngineer::projectWingsLift(this, speed);
  v6 = this->car;
  weightb = v5;
  v7 = (float)((float)(weightb * v17) * 0.10197838) + 1.0;
  weightc = v6->ksPhysics->track->dynamicGripLevel;
  RaceEngineer::evalTyreLoad(
    this,
    &result,
    speed,
    latg,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(v6->tyres[0].modelData.Dx0 * v7) ^ _xmm));
  speedMS_4 = Tyre::getDX(this->car->tyres, result.lf);
  v8 = Tyre::getCorrectedD(this->car->tyres, speedMS_4, 0);
  latga = v8 * result.lf * weightc;
  speedMS_4a = Tyre::getDX(&this->car->tyres[1], result.rf);
  v9 = Tyre::getCorrectedD(&this->car->tyres[1], speedMS_4a, 0);
  v10 = this->car;
  weighta = v9 * result.rf * weightc;
  v11 = latga
      / (float)((float)((float)(v10->tyres[0].modelData.speedSensitivity * speed) * v10->tyres[0].slipProvider.maxSlip)
              + 1.0);
  v12 = (float)((float)(v10->tyres[1].modelData.speedSensitivity * speed) * v10->tyres[1].slipProvider.maxSlip) + 1.0;
  if ( (float)(weighta / v12) <= v11 )
    v11 = weighta / v12;
  return (float)((float)((float)(v11 * 4.0) * v17) * 0.10197838);
}
double RaceEngineer::evalFrontRideHeight(RaceEngineer *this)
{
  ISuspension *v2; // ecx
  int v3; // ecx
  int v4; // eax
  Car *v5; // edx
  float v6; // xmm1_4
  ISuspension **v7; // eax
  ISuspension *v8; // ecx
  ISuspension *v9; // eax
  double v10; // st7
  Car *v11; // esi
  float v13; // [esp+Ch] [ebp-28h]
  float v14; // [esp+10h] [ebp-24h]
  float v15; // [esp+10h] [ebp-24h]
  float v16; // [esp+14h] [ebp-20h]
  float v17; // [esp+14h] [ebp-20h]
  float v18; // [esp+14h] [ebp-20h]
  float v19; // [esp+18h] [ebp-1Ch]
  char v20; // [esp+1Ch] [ebp-18h] BYREF
  char v21[12]; // [esp+28h] [ebp-Ch] BYREF

  v16 = Car::getTotalMass(this->car, 1);
  v2 = *this->car->suspensions._Myfirst;
  v14 = v2->getBasePosition(v2, (vec3f *)&v20)->z;
  v3 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
  v4 = (*(int (**)(int, char *))(*(_DWORD *)v3 + 40))(v3, v21);
  v5 = this->car;
  v6 = v14 - *(float *)(v4 + 8);
  v7 = v5->suspensions._Myfirst;
  v8 = v7[1];
  v9 = *v7;
  v19 = (float)((float)(1.0 - (float)(COERCE_FLOAT(LODWORD(v14) & _xmm) / COERCE_FLOAT(LODWORD(v6) & _xmm))) * v16)
      * 9.8059998;
  v13 = (float)(v9->k + v8->k) * 0.5;
  v15 = (float)(v9->rodLength + v8->rodLength) * 0.5;
  if ( v13 == 0.0 )
  {
    v13 = v5->heaveSprings[0].k;
    v15 = v5->heaveSprings[0].rodLength;
  }
  v17 = Tyre::getDynamicK(&v5->tyres[1]);
  v10 = Tyre::getDynamicK(this->car->tyres);
  v11 = this->car;
  v18 = (v10 + v17) * 0.5;
  return (float)(v11->ridePickupPoint[0].y
               + (float)((float)(v11->tyres[0].data.radius
                               - *(float *)((*(int (**)(ISuspension *, char *))(**(_DWORD **)v11->suspensions._Myfirst
                                                                                         + 40))(
                                              *v11->suspensions._Myfirst,
                                              v21)
                                          + 4))
                       - (float)((float)((float)(v19 * 0.5) / (float)((float)(v18 * v13) / (float)(v18 + v13))) - v15)));
}
double RaceEngineer::evalLateralGFromLoads(RaceEngineer *this, const float speed, const float aeroRatio, const float mass, const float *loads)
{
  double v6; // st7
  Car *v7; // eax
  float v8; // xmm0_4
  Car *v9; // eax
  int v10; // eax
  float v11; // xmm1_4
  Car *v12; // eax
  Car *v13; // eax
  Car *v14; // eax
  int v15; // edi
  int v16; // esi
  float v17; // xmm0_4
  int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float load; // [esp+4h] [ebp-60h]
  float v28; // [esp+20h] [ebp-44h] BYREF
  float v29; // [esp+24h] [ebp-40h]
  float v30; // [esp+28h] [ebp-3Ch]
  float v31; // [esp+2Ch] [ebp-38h]
  float v32; // [esp+30h] [ebp-34h]
  int v33; // [esp+34h] [ebp-30h]
  float v34; // [esp+38h] [ebp-2Ch]
  float v35; // [esp+3Ch] [ebp-28h]
  float v36; // [esp+40h] [ebp-24h]
  float v37; // [esp+44h] [ebp-20h] BYREF
  float v38; // [esp+48h] [ebp-1Ch]
  float v39; // [esp+4Ch] [ebp-18h] BYREF
  int v40[5]; // [esp+50h] [ebp-14h] BYREF
  float retaddr; // [esp+64h] [ebp+0h]

  v36 = *(float *)&loads;
  v39 = *(float *)&this;
  v6 = Car::getCGHeight(this->car);
  v7 = this->car;
  v34 = v6;
  v8 = *(float *)((*(int (**)(ISuspension *, float *))(**(_DWORD **)v7->suspensions._Myfirst + 40))(
                    *v7->suspensions._Myfirst,
                    &v28)
                + 8);
  v9 = this->car;
  v36 = v8;
  LODWORD(v37) = LODWORD(v8) & _xmm;
  v10 = (*(int (**)(_DWORD, int *))(**((_DWORD **)v9->suspensions._Myfirst + 2) + 40))(
          *((_DWORD *)v9->suspensions._Myfirst + 2),
          v40);
  v11 = v35 - *(float *)(v10 + 8);
  v12 = this->car;
  v29 = 1.0 - (float)(v36 / COERCE_FLOAT(LODWORD(v11) & _xmm));
  v35 = 0.0;
  if ( v12 )
    LODWORD(v35) = COERCE_UNSIGNED_INT(
                     *(float *)(*(int (**)(ISuspension *, float *))(**(_DWORD **)v12->suspensions._Myfirst
                                                                             + 40))(
                                 *v12->suspensions._Myfirst,
                                 &v39)
                   * 2.0) & _xmm;
  else
    v36 = 0.0;
  v13 = this->car;
  if ( v13 )
    LODWORD(v34) = COERCE_UNSIGNED_INT(
                     *(float *)(*(int (**)(_DWORD, float *))(**((_DWORD **)v13->suspensions._Myfirst + 2) + 40))(
                                 *((_DWORD *)v13->suspensions._Myfirst + 2),
                                 &v39)
                   * 2.0) & _xmm;
  v14 = this->car;
  v15 = 0;
  v16 = 0;
  v17 = v14->ksPhysics->track->dynamicGripLevel;
  v18 = v33 - (_DWORD)&v37;
  v32 = v17;
  v33 -= (int)&v37;
  do
  {
    load = Tyre::getDY((Tyre *)(v16 + *(_DWORD *)(LODWORD(v36) + 4) + 2040), *(float *)((char *)&v37 + 4 * v15 + v18));
    v29 = Tyre::getCorrectedD((Tyre *)(v16 + *(_DWORD *)(LODWORD(v36) + 4) + 2040), load, 0);
    v19 = (float)(v29
                / (float)((float)((float)(*(float *)(v16 + *(_DWORD *)(LODWORD(v36) + 4) + 2152) * *(float *)&v40[3])
                                * *(float *)(v16 + *(_DWORD *)(LODWORD(v36) + 4) + 3120))
                        + 1.0))
        * v32;
    *(&v37 + v15) = v19;
    if ( !v15 || v30 > v19 )
      v30 = v19;
    v16 += 1632;
    v18 = v33;
    *(&v37 + v15) = v19 * *(float *)((char *)&v37 + 4 * v15 + v33);
    ++v15;
  }
  while ( v16 < 6528 );
  v20 = v39 + *(float *)v40;
  v21 = v37 + v38;
  if ( (float)((float)((float)(v39 + *(float *)v40) * v28) / (float)(1.0 - v28)) <= (float)(v37 + v38) )
    v21 = (float)((float)(v39 + *(float *)v40) * v28) / (float)(1.0 - v28);
  if ( (float)((float)((float)(1.0 - v28) * (float)(v37 + v38)) / v28) <= v20 )
    v20 = (float)((float)(1.0 - v28) * (float)(v37 + v38)) / v28;
  v22 = v20 + v21;
  v23 = v35;
  if ( v34 <= v35 )
    v23 = v34;
  v24 = (float)(v22 / retaddr) * 0.10197838;
  v25 = (float)((float)(v23 * 0.5) / v31) * *(float *)&v40[4];
  if ( v24 <= v25 )
    return v24;
  v36 = v25;
  return v25;
}
double RaceEngineer::evalLateralGrip(RaceEngineer *this, float speed, float mass, float aeroModifier, float *in_loads, float current_lift_kg)
{
  ISuspension *v7; // ecx
  float v8; // xmm0_4
  Car *v9; // eax
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  double v14; // st7
  float v15; // xmm2_4
  float v16; // xmm0_4
  float aeroRatio; // xmm2_4
  Tyre *v18; // ecx
  double v19; // st7
  Car *v20; // eax
  float v21; // xmm0_4
  Car *v22; // eax
  Car *v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm2_4
  float v33; // xmm4_4
  float v34; // xmm7_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  vec3f v38; // [esp+28h] [ebp-40h] BYREF
  float v39; // [esp+34h] [ebp-34h]
  float v40; // [esp+38h] [ebp-30h]
  float v41; // [esp+3Ch] [ebp-2Ch]
  float v42; // [esp+40h] [ebp-28h]
  __int128 v43; // [esp+44h] [ebp-24h]
  __m128 loads; // [esp+54h] [ebp-14h] BYREF

  v7 = *this->car->suspensions._Myfirst;
  v8 = v7->getBasePosition(v7, &v38)->z;
  v9 = this->car;
  *((float *)&v43 + 3) = v8;
  DWORD2(v43) = LODWORD(v8) & _xmm;
  v10 = (*(int (**)(_DWORD, __int16 *))(**((_DWORD **)v9->suspensions._Myfirst + 2) + 40))(
          *((_DWORD *)v9->suspensions._Myfirst + 2),
          &loads.m128_i16[2]);
  v11 = FLOAT_1_0;
  v12 = 1.0
      - (float)(*((float *)&v43 + 2)
              / COERCE_FLOAT(COERCE_UNSIGNED_INT(*((float *)&v43 + 3) - *(float *)(v10 + 8)) & _xmm));
  v13 = current_lift_kg;
  *((float *)&v43 + 1) = v12;
  if ( current_lift_kg <= 0.0 )
  {
    v14 = RaceEngineer::projectWingsLift(this, speed);
    v11 = FLOAT_1_0;
    v12 = *((float *)&v43 + 1);
    *((float *)&v43 + 3) = v14 * aeroModifier;
    v13 = *((float *)&v43 + 3);
    current_lift_kg = *((float *)&v43 + 3);
  }
  v15 = v13;
  v16 = mass * 9.8059998;
  v39 = mass * 9.8059998;
  aeroRatio = (float)((float)(v15 / mass) * 0.10197838) + v11;
  *((float *)&v43 + 3) = aeroRatio;
  if ( in_loads )
  {
    loads = (__m128)_mm_loadu_si128((const __m128i *)in_loads);
  }
  else
  {
    v18 = this->car->tyres;
    *(float *)&v43 = v16 * v12;
    v19 = Tyre::getDY(v18, (float)((float)(v16 * v12) * 0.5) * aeroRatio);
    v20 = this->car;
    *((float *)&v43 + 2) = v19 * 0.89999998 * *((float *)&v43 + 3);
    v21 = 0.0;
    if ( v20 )
      LODWORD(v41) = COERCE_UNSIGNED_INT(
                       *(float *)(*(int (**)(ISuspension *, __int16 *))(**(_DWORD **)v20->suspensions._Myfirst
                                                                                 + 40))(
                                   *v20->suspensions._Myfirst,
                                   &loads.m128_i16[2])
                     * 2.0) & _xmm;
    else
      v41 = 0.0;
    v22 = this->car;
    if ( v22 )
      LODWORD(v21) = COERCE_UNSIGNED_INT(
                       *(float *)(*(int (**)(_DWORD, __int16 *))(**((_DWORD **)v22->suspensions._Myfirst + 2)
                                                                          + 40))(
                                   *((_DWORD *)v22->suspensions._Myfirst + 2),
                                   &loads.m128_i16[2])
                     * 2.0) & _xmm;
    v23 = this->car;
    v42 = v21;
    v40 = Car::getCGHeight(v23);
    v24 = FLOAT_1_0;
    v25 = (float)(v40 / v41) * *((float *)&v43 + 2);
    v26 = v25 + 0.5;
    if ( (float)(v25 + 0.5) <= 1.0 )
    {
      if ( v26 < 0.0 )
        v26 = 0.0;
    }
    else
    {
      v26 = FLOAT_1_0;
    }
    v27 = *(float *)&v43;
    v28 = *(float *)&v43 * v26;
    v29 = 0.5 - v25;
    *(float *)&v43 = v28;
    if ( (float)(0.5 - v25) <= 1.0 )
    {
      if ( v29 < 0.0 )
        v29 = 0.0;
    }
    else
    {
      v29 = FLOAT_1_0;
    }
    v30 = v27 * v29;
    v31 = (float)(v40 / v42) * *((float *)&v43 + 2);
    v32 = v31 + 0.5;
    if ( (float)(v31 + 0.5) <= 1.0 )
    {
      if ( v32 < 0.0 )
        v32 = 0.0;
    }
    else
    {
      v32 = FLOAT_1_0;
    }
    v33 = (float)(1.0 - *((float *)&v43 + 1)) * v39;
    v34 = v33 * v32;
    if ( (float)(0.5 - v31) <= 1.0 )
    {
      if ( (float)(0.5 - v31) >= 0.0 )
        v24 = 0.5 - v31;
      else
        v24 = 0.0;
    }
    v35 = (float)(current_lift_kg * *((float *)&v43 + 1)) * 0.5;
    v36 = (float)((float)(1.0 - *((float *)&v43 + 1)) * current_lift_kg) * 0.5;
    loads.m128_f32[0] = *(float *)&v43 + v35;
    aeroRatio = *((float *)&v43 + 3);
    loads.m128_f32[1] = v30 + v35;
    loads.m128_f32[2] = v34 + v36;
    loads.m128_f32[3] = (float)(v33 * v24) + v36;
    loads = _mm_max_ps((__m128)0i64, loads);
  }
  return RaceEngineer::evalLateralGFromLoads(this, speed, aeroRatio, mass, loads.m128_f32);
}
double RaceEngineer::evalRearRideHeight(RaceEngineer *this)
{
  ISuspension *v2; // ecx
  int v3; // ecx
  int v4; // eax
  Car *v5; // esi
  float v6; // xmm0_4
  ISuspension **v7; // eax
  ISuspension *v8; // ecx
  ISuspension *v9; // eax
  double v10; // st7
  Car *v11; // esi
  float v13; // [esp+Ch] [ebp-28h]
  float v14; // [esp+10h] [ebp-24h]
  float v15; // [esp+10h] [ebp-24h]
  float v16; // [esp+14h] [ebp-20h]
  float v17; // [esp+14h] [ebp-20h]
  float v18; // [esp+14h] [ebp-20h]
  float v19; // [esp+18h] [ebp-1Ch]
  char v20; // [esp+1Ch] [ebp-18h] BYREF
  char v21[12]; // [esp+28h] [ebp-Ch] BYREF

  v16 = Car::getTotalMass(this->car, 1);
  v2 = *this->car->suspensions._Myfirst;
  v14 = v2->getBasePosition(v2, (vec3f *)&v20)->z;
  v3 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
  v4 = (*(int (**)(int, char *))(*(_DWORD *)v3 + 40))(v3, v21);
  v5 = this->car;
  v6 = v14 - *(float *)(v4 + 8);
  v7 = v5->suspensions._Myfirst;
  v8 = v7[3];
  v9 = v7[2];
  v19 = (float)((float)(1.0
                      - (float)(1.0 - (float)(COERCE_FLOAT(LODWORD(v14) & _xmm) / COERCE_FLOAT(LODWORD(v6) & _xmm))))
              * v16)
      * 9.8059998;
  v13 = (float)(v9->k + v8->k) * 0.5;
  v15 = (float)(v9->rodLength + v8->rodLength) * 0.5;
  if ( v13 == 0.0 )
  {
    v13 = v5->heaveSprings[1].k;
    v15 = v5->heaveSprings[1].rodLength;
  }
  v17 = Tyre::getDynamicK(&v5->tyres[2]);
  v10 = Tyre::getDynamicK(&v5->tyres[3]);
  v11 = this->car;
  v18 = (v10 + v17) * 0.5;
  return (float)(v11->ridePickupPoint[1].y
               + (float)((float)(v11->tyres[2].data.radius
                               - *(float *)((*(int (**)(_DWORD, char *))(**((_DWORD **)v11->suspensions._Myfirst
                                                                                     + 2)
                                                                                  + 40))(
                                              *((_DWORD *)v11->suspensions._Myfirst + 2),
                                              v21)
                                          + 4))
                       - (float)((float)((float)(v19 * 0.5) / (float)((float)(v18 * v13) / (float)(v18 + v13))) - v15)));
}
double RaceEngineer::evalRideHeight(RaceEngineer *this, int index)
{
  double result; // st7

  if ( index )
    result = RaceEngineer::evalRearRideHeight(this);
  else
    result = RaceEngineer::evalFrontRideHeight(this);
  return result;
}
WheelValues *RaceEngineer::evalTyreLoad(RaceEngineer *this, WheelValues *result, float speedMS, float latg, float longg)
{
  ISuspension *v6; // ecx
  float v7; // xmm0_4
  Car *v8; // eax
  int v9; // eax
  double v10; // st7
  Car *v11; // ecx
  double v12; // st7
  Car *v13; // ecx
  double v14; // st7
  Car *v15; // eax
  ISuspension **v16; // eax
  ISuspension *v17; // edi
  float *v18; // esi
  int v19; // eax
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  RaceEngineer *v23; // edi
  Car *v24; // eax
  float v25; // xmm0_4
  float *v26; // eax
  float v27; // xmm4_4
  Car *v28; // eax
  float v29; // xmm1_4
  float *v30; // eax
  WheelValues *v31; // eax
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm5_4
  vec3f v38; // [esp+14h] [ebp-2Ch] BYREF
  vec3f v39; // [esp+20h] [ebp-20h] BYREF
  float v40; // [esp+2Ch] [ebp-14h]
  RaceEngineer *v41; // [esp+30h] [ebp-10h]
  float v42; // [esp+34h] [ebp-Ch]
  float v43; // [esp+38h] [ebp-8h]
  float v44; // [esp+3Ch] [ebp-4h]
  float speedMSa; // [esp+48h] [ebp+8h]

  v41 = this;
  v6 = *this->car->suspensions._Myfirst;
  v7 = v6->getBasePosition(v6, &v39)->z;
  v8 = this->car;
  v42 = v7;
  LODWORD(v43) = LODWORD(v7) & _xmm;
  v9 = (*(int (**)(_DWORD, vec3f *))(**((_DWORD **)v8->suspensions._Myfirst + 2) + 40))(
         *((_DWORD *)v8->suspensions._Myfirst + 2),
         &v38);
  v42 = 1.0 - (float)(v43 / COERCE_FLOAT(COERCE_UNSIGNED_INT(v42 - *(float *)(v9 + 8)) & _xmm));
  v10 = RaceEngineer::projectWingsLift(this, speedMS);
  v11 = this->car;
  v40 = v10;
  v12 = Car::getTotalMass(v11, 1);
  v13 = this->car;
  v43 = v12 * 9.8059998;
  v14 = Car::getCGHeight(v13);
  v15 = this->car;
  v44 = v14;
  v16 = v15->suspensions._Myfirst;
  v17 = v16[2];
  v18 = &(*v16)->getBasePosition(*v16, &v38)->z;
  v19 = (int)v17->getBasePosition(v17, &v39);
  v20 = 0.0;
  v21 = v44;
  v22 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v44 / (float)(*v18 - *(float *)(v19 + 8))) * longg) ^ _xmm) + v42;
  speedMSa = v22;
  if ( v22 <= 1.0 )
  {
    if ( v22 < 0.0 )
      speedMSa = 0.0;
  }
  else
  {
    speedMSa = FLOAT_1_0;
  }
  v23 = v41;
  v24 = v41->car;
  if ( v24 )
  {
    v26 = (float *)(*(int (**)(ISuspension *, vec3f *))(**(_DWORD **)v24->suspensions._Myfirst + 40))(
                     *v24->suspensions._Myfirst,
                     &v38);
    v21 = v44;
    v20 = 0.0;
    LODWORD(v25) = COERCE_UNSIGNED_INT(*v26 * 2.0) & _xmm;
  }
  else
  {
    v25 = 0.0;
  }
  v27 = FLOAT_0_5;
  v28 = v23->car;
  result->lr = 0.0;
  result->rr = 0.0;
  v29 = speedMSa * v43;
  result->lf = (float)((float)((float)(v21 / v25) * latg) + 0.5) * (float)(speedMSa * v43);
  result->rf = (float)(0.5 - (float)((float)(v21 / v25) * latg)) * v29;
  if ( v28 )
  {
    v30 = (float *)(*(int (**)(_DWORD, vec3f *))(**((_DWORD **)v28->suspensions._Myfirst + 2) + 40))(
                     *((_DWORD *)v28->suspensions._Myfirst + 2),
                     &v38);
    v27 = FLOAT_0_5;
    v21 = v44;
    LODWORD(v20) = COERCE_UNSIGNED_INT(*v30 * 2.0) & _xmm;
  }
  v31 = result;
  v32 = (float)(v21 / v20) * latg;
  v33 = (float)(v40 * v42) * v27;
  v34 = (float)(1.0 - speedMSa) * v43;
  v35 = result->lf + v33;
  v36 = v33 + result->rf;
  v37 = (float)((float)(1.0 - v42) * v40) * v27;
  result->lf = v35;
  result->rf = v36;
  result->lr = (float)((float)(v32 + v27) * v34) + v37;
  result->rr = (float)((float)(v27 - v32) * v34) + v37;
  return v31;
}
double __usercall RaceEngineer::evaluateFuelPerLapFromTrackSpline@<st0>(RaceEngineer *this@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  std::wstring *v6; // eax
  AISpline *v7; // eax
  AISpline *v8; // eax
  AISpline *v9; // ecx
  int v10; // eax
  Car *v11; // ecx
  int v12; // ecx
  float v13; // xmm1_4
  std::vector<Turbo> *v14; // eax
  unsigned int v15; // esi
  AISplinePayload *v16; // eax
  AISplinePayload *v17; // eax
  unsigned int v18; // edi
  AISplinePayload *v19; // eax
  float v20; // xmm0_4
  AISplinePayload *v21; // eax
  float v22; // xmm0_4
  InterpolatingSpline *v23; // esi
  int v24; // eax
  vec3f *v25; // edi
  vec3f *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  Turbo *v30; // edi
  Turbo *v31; // esi
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // eax
  float v35; // xmm0_4
  double v36; // st7
  float *v37; // eax
  RaceEngineer *v38; // esi
  float v39; // xmm1_4
  Car *v40; // eax
  float v41; // xmm0_4
  bool v42; // zf
  Turbo *v43; // edi
  Turbo *v44; // esi
  __int64 dt; // [esp+10h] [ebp-144h]
  __int64 dta; // [esp+10h] [ebp-144h]
  float v47; // [esp+20h] [ebp-134h]
  int v48; // [esp+24h] [ebp-130h] BYREF
  RaceEngineer *v49; // [esp+28h] [ebp-12Ch]
  float v50; // [esp+2Ch] [ebp-128h]
  float v51; // [esp+30h] [ebp-124h]
  float v52; // [esp+34h] [ebp-120h]
  float v53; // [esp+38h] [ebp-11Ch]
  float v54; // [esp+3Ch] [ebp-118h]
  float v55; // [esp+40h] [ebp-114h] BYREF
  std::vector<Turbo> v56; // [esp+44h] [ebp-110h] BYREF
  float v57; // [esp+50h] [ebp-104h] BYREF
  float v58; // [esp+54h] [ebp-100h]
  float v59; // [esp+58h] [ebp-FCh]
  unsigned int index; // [esp+5Ch] [ebp-F8h]
  float gas; // [esp+60h] [ebp-F4h]
  Speed v62; // [esp+64h] [ebp-F0h] BYREF
  float v63; // [esp+68h] [ebp-ECh] BYREF
  AISplinePayload v64; // [esp+6Ch] [ebp-E8h] BYREF
  AISplinePayload v65; // [esp+C0h] [ebp-94h] BYREF
  std::wstring result; // [esp+114h] [ebp-40h] BYREF
  std::wstring path; // [esp+12Ch] [ebp-28h] BYREF
  int v68; // [esp+150h] [ebp-4h]

  v49 = this;
  v62.value = this->fuelPerLapEvaluated;
  if ( v62.value != 0.0 )
    return v62.value;
  if ( RaceEngineer::trackSpline._Myptr )
  {
LABEL_14:
    if ( this->car->drivetrain.acEngine.getLimiterRPM(&this->car->drivetrain.acEngine) )
      v10 = this->car->drivetrain.acEngine.getLimiterRPM(&this->car->drivetrain.acEngine);
    else
      v10 = this->car->autoShift.changeUpRpm;
    v11 = this->car;
    LODWORD(dt) = v11->drivetrain.gears._Mylast - v11->drivetrain.gears._Myfirst;
    v54 = (float)v10;
    v53 = (float)v11->autoShift.changeDnRpm;
    v52 = v11->fuelConsumptionK;
    _printf("MAX NUMBER OF GEARS %llu\n", dt);
    v12 = this->car->drivetrain.gears._Mylast - this->car->drivetrain.gears._Myfirst;
    if ( v12 <= 8 )
    {
      if ( v12 < 0 )
        v12 = 0;
    }
    else
    {
      v12 = 8;
    }
    v58 = FLOAT_225_0;
    v13 = RaceEngineer::getMaxSpeedFromGear(this, &v62, v12 - 4)->value * 3.5999999;
    if ( v13 <= 225.0 )
    {
      if ( v13 >= 0.0 )
        v58 = v13;
      else
        v58 = 0.0;
    }
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v62);
    _printf("MAX SPEED %f MIN_SPEED %f\n", v58, DOUBLE_1_0);
    v56._Myfirst = 0;
    v56._Mylast = 0;
    v56._Myend = 0;
    v14 = &this->car->drivetrain.acEngine.turbos;
    v68 = 4;
    std::vector<Turbo>::operator=(&v56, v14);
    v63 = 0.0;
    v15 = 0;
    for ( gas = 0.0; v15 < AISpline::pointsCount(RaceEngineer::trackSpline._Myptr); ++v15 )
    {
      v16 = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v65, v15);
      if ( v16->speedMS >= v63 && v16->speedMS < 300.0 )
        v63 = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v65, v15)->speedMS;
      v17 = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v65, v15);
      if ( v17->gas >= gas )
        gas = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v64, v15)->gas;
    }
    LODWORD(dta) = v56._Mylast - v56._Myfirst;
    _printf("MAX SPEED %f TURBOS %llu\n", v63, dta);
    v18 = 0;
    v59 = 0.0;
    *(float *)&index = 0.0;
    if ( AISpline::pointsCount(RaceEngineer::trackSpline._Myptr) )
    {
      v48 = 0;
      v51 = 1.0 / v63;
      v50 = 1.0 / gas;
      v54 = v54 - v53;
      v58 = v58 - 1.0;
      do
      {
        v19 = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v64, v18);
        v20 = FLOAT_1_0;
        v63 = v19->speedMS * v51;
        if ( v63 > 1.0 || (v20 = 0.0, v63 < 0.0) )
          v63 = v20;
        v21 = AISpline::payloadAtSplineIndex(RaceEngineer::trackSpline._Myptr, &v64, v18);
        gas = v21->gas * v50;
        v22 = gas;
        if ( gas <= 1.0 )
        {
          if ( gas < 0.0 )
          {
            v22 = 0.0;
            gas = 0.0;
          }
        }
        else
        {
          v22 = FLOAT_1_0;
          gas = FLOAT_1_0;
        }
        v23 = &RaceEngineer::trackSpline._Myptr->spline;
        v55 = (float)(v54 * v22) + v53;
        v62.value = (float)(v58 * v63) + 1.0;
        v24 = Spline::wrapIndex(&RaceEngineer::trackSpline._Myptr->spline, v18 - 1);
        v25 = Spline::pointAt(v23, (vec3f *)&result._Bx._Alias[12], v24);
        v26 = Spline::pointAt(v23, (vec3f *)&path._Bx._Alias[12], index);
        v27 = v26->z - v25->z;
        v28 = (float)((float)((float)(v26->y - v25->y) * (float)(v26->y - v25->y))
                    + (float)((float)(v26->x - v25->x) * (float)(v26->x - v25->x)))
            + (float)(v27 * v27);
        if ( v28 == 0.0 )
          v29 = 0.0;
        else
          v29 = fsqrt(v28);
        v30 = v56._Mylast;
        v31 = v56._Myfirst;
        v32 = v29 / (float)(v62.value * 0.27777779);
        v33 = 0.0;
        v62.value = v32;
        v63 = 0.0;
        if ( v56._Myfirst != v56._Mylast )
        {
          v34 = &v55;
          v57 = 0.0;
          if ( v55 <= 0.0 )
            v34 = &v57;
          v35 = *v34;
          v57 = v63;
          v47 = v35;
          do
          {
            Turbo::step(v31, gas, v35, v32);
            v36 = Turbo::getBoost(v31++);
            v32 = v62.value;
            v35 = v47;
            v57 = v36 + v57;
            v63 = v57;
          }
          while ( v31 != v30 );
          v33 = v63;
        }
        v37 = &v63;
        if ( v33 <= 0.0 )
          v37 = (float *)&v48;
        v18 = ++index;
        v59 = (float)((float)((float)((float)((float)((float)(*v37 * 1.1) + 1.0)
                                            * (float)(COERCE_FLOAT(LODWORD(v55) & _xmm) * gas))
                                    * v52)
                            * 0.001)
                    * v32)
            + v59;
      }
      while ( v18 < AISpline::pointsCount(RaceEngineer::trackSpline._Myptr) );
    }
    v38 = v49;
    v39 = v59 * 1.25;
    v40 = v49->car;
    v59 = v39;
    *(float *)&index = v39;
    v41 = v40->maxFuel;
    if ( v39 <= v41 )
    {
      if ( v39 >= 0.0 )
      {
LABEL_61:
        _printf("FINAL FUEL : %f\n", v39);
        _printf("MAX FUEL : %f\n", (double)v38->car->maxFuel);
        v42 = v56._Myfirst == 0;
        v38->fuelPerLapEvaluated = v59;
        v68 = -1;
        if ( !v42 )
        {
          std::_Container_base0::_Orphan_all(&v56);
          v43 = v56._Mylast;
          v44 = v56._Myfirst;
          if ( v56._Myfirst != v56._Mylast )
          {
            do
              dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v44++);
            while ( v44 != v43 );
            v44 = v56._Myfirst;
          }
          operator delete(v44);
        }
        return *(float *)&index;
      }
      v39 = 0.0;
      v59 = 0.0;
    }
    else
    {
      v39 = v40->maxFuel;
      v59 = v39;
    }
    *(float *)&index = v39;
    goto LABEL_61;
  }
  v6 = Track::getDataFolder(this->car->ksPhysics->track, &result);
  v68 = 0;
  std::operator+<wchar_t>(&path, v6, L"/data/ideal_line.ai");
  LOBYTE(v68) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists(a2, &path, 0) )
  {
    _printf("RaceEngineer :: LOADING IDEAL LINE\n");
    *(float *)&v7 = COERCE_FLOAT(operator new(128));
    v52 = *(float *)&v7;
    LOBYTE(v68) = 3;
    if ( *(float *)&v7 == 0.0 )
      v8 = 0;
    else
      AISpline::AISpline(v7);
    v9 = RaceEngineer::trackSpline._Myptr;
    LOBYTE(v68) = 2;
    RaceEngineer::trackSpline._Myptr = v8;
    if ( v9 )
    {
      ((void (*)(AISpline *, int))v9->~AISpline)(v9, 1);
      v8 = RaceEngineer::trackSpline._Myptr;
    }
    AISpline::loadFast(v8, a3, a4, &path);
    v68 = -1;
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    goto LABEL_14;
  }
  _printf("RaceEngineer :: NO IDEAL LINE FOUND\n");
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  return 30.0;
}
int RaceEngineer::findTyreCompound(RaceEngineer *this, FindTyreCompoundLogic logic)
{
  std::wstring *v2; // eax
  int result; // eax
  Car *v4; // esi
  int v5; // ebx
  TyreCompoundDef *v6; // edi
  TyreCompoundDef *i; // esi
  double v8; // st7
  int v9; // esi
  float v10; // [esp+1Ch] [ebp-30h]
  float dy; // [esp+20h] [ebp-2Ch]
  std::wstring v12; // [esp+24h] [ebp-28h] BYREF
  int v13; // [esp+48h] [ebp-4h]

  if ( logic )
  {
    if ( logic == Fastest )
    {
      v4 = this->car;
      v5 = -1;
      v10 = 0.0;
      v6 = v4->tyres[0].compoundDefs._Mylast;
      for ( i = v4->tyres[0].compoundDefs._Myfirst; i != v6; ++i )
      {
        if ( i->modelData.version < 5 )
          v8 = Tyre::loadSensLinearD(i->modelData.Dy0, i->modelData.Dy1, 3000.0);
        else
          v8 = Tyre::loadSensExpD(i->modelData.lsExpY, i->modelData.lsMultY, 3000.0);
        dy = v8;
        if ( dy > v10 )
        {
          v5 = i->index;
          v10 = v8;
        }
      }
      result = v5;
    }
    else
    {
      if ( logic != Preferred )
      {
        std::wstring::wstring(&v12, L"RaceEngineer::findTyreCompound logic not found");
        v2 = &v12;
        v13 = 0;
        if ( v12._Myres >= 8 )
          v2 = (std::wstring *)v12._Bx._Ptr;
        _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v2->_Bx._Buf);
        ksGenerateCrash();
        if ( v12._Myres >= 8 )
          operator delete(v12._Bx._Ptr);
      }
      result = -1;
    }
  }
  else
  {
    v9 = this->car->tyres[0].compoundDefs._Mylast - this->car->tyres[0].compoundDefs._Myfirst;
    result = (int)(float)((float)((float)_rand() * 0.000030518509) * (float)(unsigned int)v9);
  }
  return result;
}
float *RaceEngineer::getAccelerationProfile(RaceEngineer *this, float *a2)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  int v5; // edi
  double v6; // st7
  Car *v7; // ecx
  float v8; // xmm0_4
  Car *v9; // eax
  Tyre *v10; // ecx
  float v11; // xmm0_4
  float *result; // eax
  float gas; // [esp+0h] [ebp-28h]
  float v14; // [esp+14h] [ebp-14h]
  float v15; // [esp+18h] [ebp-10h]
  float v16; // [esp+1Ch] [ebp-Ch]
  float v17; // [esp+20h] [ebp-8h]
  float v18; // [esp+20h] [ebp-8h]
  float drag; // [esp+24h] [ebp-4h]

  v3 = 0.0;
  v4 = FLOAT_1_0;
  v5 = 5;
  v16 = 0.0;
  v15 = FLOAT_1_0;
  drag = AeroMap::getCurrentDragKG(&this->car->aeroMap) * 9.8059998;
  do
  {
    v14 = (float)(v4 + v3) * 0.5;
    v6 = Engine::getThrottleResponseGas(&this->car->drivetrain.acEngine, v14, 0.0);
    v7 = this->car;
    v17 = v6;
    gas = v7->drivetrain.engine.velocity * 0.1591550715257987 * 60.0;
    v18 = Engine::getTorqueAtRPM(&v7->drivetrain.acEngine, gas, v17);
    if ( v18 <= 0.0 )
      v8 = FLOAT_1_0;
    else
      v8 = this->car->drivetrain.acEngine.status.turboBoost + 1.0;
    v9 = this->car;
    if ( v9 )
    {
      v10 = v9->tyres;
      if ( v9->drivetrain.tractionType != FWD )
        v10 = &v9->tyres[2];
    }
    else
    {
      v10 = 0;
    }
    v11 = (float)(v8 * v18) * v9->drivetrain.ratio / v10->data.radius;
    if ( drag <= v11 )
    {
      v4 = v14;
      v3 = v16;
      v15 = v14;
    }
    else
    {
      v3 = v14;
      v4 = v15;
      v16 = v14;
    }
    --v5;
  }
  while ( v5 );
  result = a2;
  *a2 = (float)(v4 + v3) * 0.5;
  return result;
}
double RaceEngineer::getAntiSquat(RaceEngineer *this)
{
  float *v2; // eax
  double result; // st7
  float v4; // xmm6_4
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  _DWORD *v14; // eax
  int v15; // xmm1_4
  int v16; // xmm2_4
  int v17; // xmm0_4
  Car *v18; // eax
  double v19; // st7
  Car *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // [esp+Ch] [ebp-64h]
  float v27; // [esp+10h] [ebp-60h]
  float v28; // [esp+10h] [ebp-60h]
  float v29; // [esp+14h] [ebp-5Ch]
  char v30; // [esp+18h] [ebp-58h] BYREF
  float v31; // [esp+1Ch] [ebp-54h]
  float v32; // [esp+20h] [ebp-50h]
  int v33[3]; // [esp+24h] [ebp-4Ch] BYREF
  char v34[64]; // [esp+30h] [ebp-40h] BYREF

  v2 = (float *)__RTDynamicCast(
                  *((_DWORD *)this->car->suspensions._Myfirst + 2),
                  0,
                  &ISuspension `RTTI Type Descriptor',
                  &Suspension `RTTI Type Descriptor',
                  0);
  if ( !v2 )
    return -666.0;
  v4 = v2[67] - v2[64];
  v5 = v2[58];
  v6 = v2[63];
  if ( v4 == 0.0 )
    v7 = FLOAT_1_0e10;
  else
    v7 = (float)(v2[66] - v6) / v4;
  v8 = v2[61] - v5;
  if ( v8 == 0.0 )
    v9 = FLOAT_1_0e10;
  else
    v9 = (float)(v2[60] - v2[57]) / v8;
  v10 = v6 - (float)(v2[64] * v7);
  v11 = v2[57] - (float)(v5 * v9);
  v12 = (float)(v7 * -1.0) - (float)(v9 * -1.0);
  if ( v12 == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / v12;
  v27 = (float)((float)(v11 * -1.0) - (float)(v10 * -1.0)) * v13;
  v26 = (float)((float)(v10 * v9) - (float)(v11 * v7)) * v13;
  v14 = (_DWORD *)(*(int (**)(float *, char *))(*(_DWORD *)v2 + 4))(v2, v34);
  v15 = v14[13];
  v16 = v14[14];
  v17 = v14[12];
  v18 = this->car;
  v33[0] = v17;
  v33[1] = v15;
  v33[2] = v16;
  v18->body->worldToLocal(v18->body, (vec3f *)&v30, (const vec3f *)v33);
  v19 = Car::getCGHeight(this->car);
  v20 = this->car;
  if ( v20->torqueModeEx )
  {
    v28 = __libm_sse2_atanf().m128_f32[0];
    result = (float)(v28 / __libm_sse2_atanf().m128_f32[0]);
  }
  else
  {
    v21 = 0.0;
    v22 = v31 - v20->tyres[2].status.loadedRadius;
    if ( (float)(v27 - v32) == 0.0 )
      v23 = FLOAT_1_0e10;
    else
      v23 = (float)(v26 - v22) / (float)(v27 - v32);
    v24 = v22 - (float)(v23 * v32);
    v25 = (float)(v23 * -1.0) - -1.0e10;
    if ( v25 != 0.0 )
      v21 = 1.0 / v25;
    v29 = v19;
    result = 1.0
           - COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)((float)(v24 * 1.0e10) - (float)(v23 * 10.0)) * v21) / v29) ^ _xmm);
  }
  return result;
}
double RaceEngineer::getBaseCarHeight(RaceEngineer *this)
{
  Car *v2; // esi
  float v3; // xmm2_4
  double result; // st7
  int v5; // [esp+0h] [ebp-18h]
  char v6[4]; // [esp+8h] [ebp-10h] BYREF
  char v7[12]; // [esp+Ch] [ebp-Ch] BYREF

  v2 = this->car;
  (*(int (**)(ISuspension *, char *))(**(_DWORD **)v2->suspensions._Myfirst + 40))(
    *v2->suspensions._Myfirst,
    v7);
  LODWORD(v3) = COERCE_UNSIGNED_INT(
                  *(float *)((*(int (**)(_DWORD, char *))(**((_DWORD **)v2->suspensions._Myfirst + 2) + 40))(
                               *((_DWORD *)v2->suspensions._Myfirst + 2),
                               v6)
                           + 4)
                - this->car->tyres[2].data.radius) ^ _xmm;
  if ( COERCE_FLOAT(v5 ^ _xmm) <= v3 )
    result = v3;
  else
    result = COERCE_FLOAT(v5 ^ _xmm);
  return result;
}
double RaceEngineer::getBetaRAD(RaceEngineer *this)
{
  float v1; // xmm2_4
  float v2; // xmm0_4
  double result; // st7
  vec3f localvel; // [esp+8h] [ebp-Ch] BYREF

  this->car->body->getLocalVelocity(this->car->body, &localvel);
  v1 = localvel.x;
  v2 = fsqrt((float)((float)(localvel.y * localvel.y) + (float)(v1 * v1)) + (float)(localvel.z * localvel.z));
  if ( v2 != 0.0 )
    v1 = localvel.x / v2;
  if ( v1 <= -1.0 || v1 >= 1.0 )
    result = 1.5707964;
  else
    result = __libm_sse2_asinf().m128_f32[0];
  return result;
}
double RaceEngineer::getCasterRAD(RaceEngineer *this, ISuspension *isus)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)__RTDynamicCast(isus, 0, &ISuspension `RTTI Type Descriptor', &Suspension `RTTI Type Descriptor', 0);
  if ( v2 )
    return __libm_sse2_atanf(v2[37], v2[38], v2[39]).m128_f32[0];
  if ( __RTDynamicCast(isus, 0, &ISuspension `RTTI Type Descriptor', &SuspensionStrut `RTTI Type Descriptor', 0) )
    return ((__m128 (*)(void))__libm_sse2_atanf)().m128_f32[0];
  return 0.0;
}
double __cdecl RaceEngineer::getCompoundDY(const TyreCompoundDef *def, float load)
{
  double result; // st7

  if ( def->modelData.version < 5 )
    result = Tyre::loadSensLinearD(def->modelData.Dy0, def->modelData.Dy1, load);
  else
    result = Tyre::loadSensExpD(def->modelData.lsExpY, def->modelData.lsMultY, load);
  return result;
}
double RaceEngineer::getDrivingTyresSlip(RaceEngineer *this)
{
  Car *v1; // eax
  float v2; // xmm0_4
  float v3; // xmm1_4
  double result; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4

  v1 = this->car;
  if ( v1->drivetrain.tractionType == FWD )
  {
    v2 = v1->tyres[0].status.ndSlip;
    v3 = v1->tyres[1].status.ndSlip;
    if ( v2 <= v3 )
      result = v3;
    else
      result = v2;
  }
  else
  {
    v5 = v1->tyres[2].status.ndSlip;
    v6 = v1->tyres[3].status.ndSlip;
    if ( v5 <= v6 )
      result = v6;
    else
      result = v5;
  }
  return result;
}
double RaceEngineer::getDynamicIndex(RaceEngineer *this)
{
  Car *v2; // eax
  ISuspension **v4; // eax
  ISuspension *v5; // esi
  float v6; // [esp+Ch] [ebp-30h]
  float v7; // [esp+10h] [ebp-2Ch]
  float v8; // [esp+14h] [ebp-28h]
  char v9[4]; // [esp+18h] [ebp-24h] BYREF
  float v10; // [esp+1Ch] [ebp-20h]
  vec3f v11; // [esp+24h] [ebp-18h] BYREF
  vec3f v12; // [esp+30h] [ebp-Ch] BYREF

  v2 = this->car;
  if ( !v2 )
    return 0.0;
  v4 = v2->suspensions._Myfirst;
  v5 = *v4;
  LODWORD(v7) = LODWORD(v4[2]->getBasePosition(v4[2], &v11)->z) & _xmm;
  v6 = v5->getBasePosition(v5, &v12)->z;
  v8 = this->car->body->getMass(this->car->body);
  this->car->body->getLocalInertia(this->car->body, (vec3f *)v9);
  return (float)(v10 / (float)((float)(COERCE_FLOAT(LODWORD(v6) & _xmm) * v7) * v8));
}
double RaceEngineer::getFrontCasterRAD(RaceEngineer *this)
{
  return RaceEngineer::getCasterRAD(this, *this->car->suspensions._Myfirst);
}
std::tuple<float,float> *RaceEngineer::getFrontDampingRatio(RaceEngineer *this, std::tuple<float,float> *result)
{
  ISuspension *v3; // ecx
  double v4; // st7
  Car *v5; // eax
  int v6; // xmm0_4
  Car *v7; // eax
  Car *v8; // eax
  ISuspension *v9; // ecx
  float v10; // xmm0_4
  Car *v11; // eax
  int v12; // eax
  IRigidBody *v13; // ecx
  float v14; // xmm1_4
  float (*v15)(IRigidBody *); // eax
  double v16; // st7
  ISuspension **v17; // eax
  ISuspension *v18; // ecx
  ISuspension_vtbl *v19; // eax
  float v20; // xmm0_4
  Car *v21; // eax
  int v22; // eax
  IRigidBody *v23; // ecx
  float v24; // xmm1_4
  float (*v25)(IRigidBody *); // eax
  std::tuple<float,float> *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  vec3f v29; // [esp+8h] [ebp-30h] BYREF
  vec3f v30; // [esp+14h] [ebp-24h] BYREF
  float v31; // [esp+20h] [ebp-18h]
  float v32; // [esp+24h] [ebp-14h]
  float v33; // [esp+28h] [ebp-10h]
  float v34; // [esp+2Ch] [ebp-Ch]
  float v35; // [esp+30h] [ebp-8h]
  float v36; // [esp+34h] [ebp-4h]

  v3 = *this->car->suspensions._Myfirst;
  v4 = ((double (*)(ISuspension *))v3->getK)(v3);
  v5 = this->car;
  v36 = v4;
  v6 = *(_DWORD *)((*(int (**)(ISuspension *))(**(_DWORD **)v5->suspensions._Myfirst + 48))(*v5->suspensions._Myfirst)
                 + 8);
  v7 = this->car;
  v34 = *(float *)&v6;
  v35 = *(float *)(*(int (**)(ISuspension *))(**(_DWORD **)v7->suspensions._Myfirst + 48))(*v7->suspensions._Myfirst);
  if ( v36 == 0.0 )
  {
    v8 = this->car;
    if ( v8->heaveSprings[0].isPresent )
    {
      v36 = v8->heaveSprings[0].k;
      v34 = v8->heaveSprings[0].damper.bumpSlow;
      v35 = v8->heaveSprings[0].damper.reboundSlow;
    }
  }
  v9 = *this->car->suspensions._Myfirst;
  v10 = v9->getBasePosition(v9, &v30)->z;
  v11 = this->car;
  v33 = v10;
  v12 = (*(int (**)(_DWORD, vec3f *))(**((_DWORD **)v11->suspensions._Myfirst + 2) + 40))(
          *((_DWORD *)v11->suspensions._Myfirst + 2),
          &v29);
  v13 = this->car->body;
  v14 = COERCE_FLOAT(LODWORD(v33) & _xmm) / COERCE_FLOAT(COERCE_UNSIGNED_INT(v33 - *(float *)(v12 + 8)) & _xmm);
  v15 = v13->getMass;
  v33 = 1.0 - v14;
  v16 = ((double (*)(IRigidBody *))v15)(v13);
  v17 = this->car->suspensions._Myfirst;
  v18 = *v17;
  v19 = (*v17)->__vftable;
  v31 = v16 * v33 * 0.5;
  v20 = v19->getBasePosition(v18, &v29)->z;
  v21 = this->car;
  v33 = v20;
  v22 = (*(int (**)(_DWORD, float *))(**((_DWORD **)v21->suspensions._Myfirst + 2) + 40))(
          *((_DWORD *)v21->suspensions._Myfirst + 2),
          &v30.x);
  v23 = this->car->body;
  v24 = COERCE_FLOAT(LODWORD(v33) & _xmm) / COERCE_FLOAT(COERCE_UNSIGNED_INT(v33 - *(float *)(v22 + 8)) & _xmm);
  v25 = v23->getMass;
  v33 = 1.0 - v24;
  v32 = v25(v23);
  v26 = result;
  v27 = v31 * v36;
  v28 = v34;
  result->std::tuple<float>::_Myfirst._Val = v35 / (float)(fsqrt((float)((float)(v33 * v32) * 0.5) * v36) * 2.0);
  result->_Myfirst._Val = v28 / (float)(fsqrt(v27) * 2.0);
  return v26;
}
double RaceEngineer::getFrontNaturalFrequencyHZ(RaceEngineer *this)
{
  ISuspension *v2; // ecx
  Car *v3; // eax
  ISuspension *v4; // ecx
  int v5; // ecx
  float v7; // [esp+8h] [ebp-24h]
  float v8; // [esp+Ch] [ebp-20h]
  float v9; // [esp+Ch] [ebp-20h]
  float v10; // [esp+10h] [ebp-1Ch]
  vec3f v11; // [esp+14h] [ebp-18h] BYREF
  char v12[12]; // [esp+20h] [ebp-Ch] BYREF

  v2 = *this->car->suspensions._Myfirst;
  v7 = v2->getK(v2);
  if ( v7 == 0.0 )
  {
    v3 = this->car;
    if ( v3->heaveSprings[0].isPresent )
      v7 = v3->heaveSprings[0].k;
  }
  v4 = *this->car->suspensions._Myfirst;
  v8 = v4->getBasePosition(v4, &v11)->z;
  v5 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
  v9 = 1.0
     - (float)(COERCE_FLOAT(LODWORD(v8) & _xmm)
             / COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 - *(float *)((*(int (**)(int, char *))(*(_DWORD *)v5 + 40))(
                                                                  v5,
                                                                  v12)
                                                              + 8)) & _xmm));
  v10 = this->car->body->getMass(this->car->body);
  return (float)(fsqrt(v7 / (float)((float)(v9 * v10) * 0.5)) * 0.15957616);
}
double RaceEngineer::getFrontTrack(RaceEngineer *this)
{
  Car *v1; // eax
  double result; // st7
  char v3[12]; // [esp+8h] [ebp-Ch] BYREF

  v1 = this->car;
  if ( v1 )
    result = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                            *(float *)(*(int (**)(ISuspension *, char *))(**(_DWORD **)v1->suspensions._Myfirst
                                                                                   + 40))(
                                        *v1->suspensions._Myfirst,
                                        v3)
                          * 2.0) & _xmm);
  else
    result = 0.0;
  return result;
}
KPI *RaceEngineer::getKPI_RAD(RaceEngineer *this, KPI *result, int index)
{
  ISuspension *v3; // esi
  float *v4; // eax
  float *v5; // edi
  float v6; // xmm0_4
  KPI *v7; // eax
  float *v8; // eax
  float *v9; // esi
  float v10; // [esp+8h] [ebp-10h]
  float v11; // [esp+10h] [ebp-8h]
  float v12; // [esp+10h] [ebp-8h]

  v3 = this->car->suspensions._Myfirst[index];
  v4 = (float *)__RTDynamicCast(v3, 0, &ISuspension `RTTI Type Descriptor', &Suspension `RTTI Type Descriptor', 0);
  v5 = v4;
  if ( v4 )
  {
    v11 = (float)(v4[40] - v4[37]) / (float)(v4[38] - v4[41]);
    LODWORD(v10) = __libm_sse2_atanf().m128_u32[0] ^ _xmm;
    v6 = (float)((float)(this->car->tyres[index].data.radius + v5[41]) * v11) + v5[40];
LABEL_3:
    v7 = result;
    result->angleRAD = v10;
    LODWORD(result->scrubRadius) = LODWORD(v6) ^ _xmm;
    return v7;
  }
  v8 = (float *)__RTDynamicCast(v3, 0, &ISuspension `RTTI Type Descriptor', &SuspensionStrut `RTTI Type Descriptor', 0);
  v9 = v8;
  if ( v8 )
  {
    v12 = (float)(v8[26] - v8[23]) / (float)(v8[24] - v8[27]);
    LODWORD(v10) = __libm_sse2_atanf().m128_u32[0] ^ _xmm;
    v6 = (float)((float)(this->car->tyres[index].data.radius + v9[27]) * v12) + v9[26];
    goto LABEL_3;
  }
  v7 = result;
  result->angleRAD = 0.0;
  result->scrubRadius = 0.0;
  return v7;
}
Car *RaceEngineer::getLeftDrivenTyre(RaceEngineer *this)
{
  Car *result; // eax

  result = this->car;
  if ( result )
  {
    if ( result->drivetrain.tractionType == FWD )
      result = (Car *)((char *)result + 2040);
    else
      result = (Car *)((char *)result + 5304);
  }
  return result;
}
double RaceEngineer::getMaxBrakingForce(RaceEngineer *this)
{
  float v3; // [esp+4h] [ebp-4h]

  v3 = BrakeSystem::getBrakePower(&this->car->brakeSystem);
  return (float)((float)((float)((float)(v3 - (float)(this->car->brakeSystem.frontBias * v3))
                               / this->car->tyres[2].data.radius)
                       + (float)((float)(this->car->brakeSystem.frontBias * v3) / this->car->tyres[0].data.radius))
               * 2.0999999);
}
Speed *RaceEngineer::getMaxSpeedFromGear(RaceEngineer *this, Speed *result, unsigned int relativeCarIndex)
{
  Car *v4; // ecx
  TractionType v5; // eax
  float v6; // xmm0_4
  double *v7; // esi
  float v8; // xmm0_4
  float v10; // [esp+Ch] [ebp-8h]

  v4 = this->car;
  v5 = v4->drivetrain.tractionType;
  if ( v5 && v5 == FWD )
    v6 = v4->tyres[0].data.radius;
  else
    v6 = v4->tyres[2].data.radius;
  v7 = &v4->drivetrain.gears._Myfirst[relativeCarIndex + 2].ratio;
  v10 = v6 * 2.0;
  v8 = (float)v4->drivetrain.acEngine.getLimiterRPM(&v4->drivetrain.acEngine);
  Speed::fromMPH(result, (float)((float)(v8 * v10) * 39.0) / (this->car->drivetrain.finalRatio * *v7 * 336.0));
  return result;
}
double RaceEngineer::getOptimalBrake(RaceEngineer *this)
{
  Car *v2; // esi
  double v3; // st7
  Car *v4; // edi
  double v5; // st7
  Car *v6; // esi
  double v7; // st7
  Car *v8; // edi
  double result; // st7
  float load; // [esp+0h] [ebp-20h]
  float loada; // [esp+0h] [ebp-20h]
  float loadb; // [esp+0h] [ebp-20h]
  float loadc; // [esp+0h] [ebp-20h]
  float pedal_fronta; // [esp+14h] [ebp-Ch]
  float pedal_frontb; // [esp+14h] [ebp-Ch]
  float pedal_front; // [esp+14h] [ebp-Ch]
  float maxBrakingTorqueRear; // [esp+18h] [ebp-8h]
  float maxBrakingTorqueReara; // [esp+18h] [ebp-8h]
  float maxBrakingTorqueRearb; // [esp+18h] [ebp-8h]
  float maxBrakingTorqueFronta; // [esp+1Ch] [ebp-4h]
  float maxBrakingTorqueFrontb; // [esp+1Ch] [ebp-4h]
  float maxBrakingTorqueFront; // [esp+1Ch] [ebp-4h]

  v2 = this->car;
  load = Tyre::getDX(&v2->tyres[1], v2->tyres[1].status.load);
  v3 = Tyre::getCorrectedD(&this->car->tyres[1], load, 0);
  v4 = this->car;
  maxBrakingTorqueRear = v3 * v2->tyres[1].status.load;
  loada = Tyre::getDX(v2->tyres, v2->tyres[0].status.load);
  v5 = Tyre::getCorrectedD(this->car->tyres, loada, 0);
  v6 = this->car;
  pedal_fronta = v5;
  maxBrakingTorqueFronta = (float)((float)(pedal_fronta * v4->tyres[0].status.load) + maxBrakingTorqueRear) * 0.5;
  loadb = Tyre::getDX(&v4->tyres[2], v4->tyres[2].status.load);
  v7 = Tyre::getCorrectedD(&this->car->tyres[2], loadb, 0);
  v8 = this->car;
  pedal_frontb = v7 * v6->tyres[2].status.load;
  loadc = Tyre::getDX(&v6->tyres[3], v6->tyres[3].status.load);
  maxBrakingTorqueReara = Tyre::getCorrectedD(&this->car->tyres[3], loadc, 0);
  maxBrakingTorqueFrontb = v8->tyres[0].status.loadedRadius * maxBrakingTorqueFronta;
  maxBrakingTorqueRearb = v8->tyres[2].status.loadedRadius
                        * (float)((float)((float)(maxBrakingTorqueReara * v8->tyres[3].status.load) + pedal_frontb) * 0.5);
  pedal_front = maxBrakingTorqueFrontb / (BrakeSystem::getBrakePower(&v8->brakeSystem) * v8->brakeSystem.frontBias);
  maxBrakingTorqueFront = maxBrakingTorqueRearb
                        / (BrakeSystem::getBrakePower(&v8->brakeSystem)
                         * (float)(1.0 - v8->brakeSystem.frontBias));
  if ( maxBrakingTorqueFront <= pedal_front )
    result = maxBrakingTorqueFront;
  else
    result = pedal_front;
  return result;
}
double RaceEngineer::getPointFrontShare(RaceEngineer *this, vec3f *p)
{
  ISuspension *v3; // ecx
  int v4; // ecx
  float v6; // [esp+8h] [ebp-10h]
  vec3f v7; // [esp+Ch] [ebp-Ch] BYREF

  v3 = *this->car->suspensions._Myfirst;
  v6 = v3->getBasePosition(v3, &v7)->z;
  v4 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
  return (float)(1.0
               - (float)((float)(p->z - v6)
                       / (float)(*(float *)((*(int (**)(int, vec3f *))(*(_DWORD *)v4 + 40))(v4, &v7) + 8) - v6)));
}
double RaceEngineer::getPointGroundHeight(RaceEngineer *this, const vec3f *p)
{
  float *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm3_4
  float v5; // xmm5_4
  float v6; // xmm7_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v38; // [esp+4h] [ebp-20h]
  float v39; // [esp+8h] [ebp-1Ch]
  float v40; // [esp+Ch] [ebp-18h]
  float v41; // [esp+Ch] [ebp-18h]
  float v42; // [esp+10h] [ebp-14h]
  float v43; // [esp+14h] [ebp-10h]
  float v44; // [esp+18h] [ebp-Ch]
  float v45; // [esp+1Ch] [ebp-8h]
  float v46; // [esp+20h] [ebp-4h]

  v2 = (float *)this->car;
  v45 = 0.0;
  v44 = 0.0;
  v43 = 0.0;
  v3 = v2[708];
  v4 = v2[1524] - v3;
  v5 = v2[1116] - v3;
  v6 = v2[709];
  v7 = v2[1118] - v2[710];
  v8 = v2[1526] - v2[710];
  v9 = v2[1117] - v6;
  v46 = v2[1525] - v6;
  v40 = (float)(v4 * v7) - (float)(v8 * v5);
  v10 = (float)(v46 * v5) - (float)(v4 * v9);
  v11 = (float)(v8 * v9) - (float)(v46 * v7);
  v12 = (float)((float)(v40 * v40) + (float)(v11 * v11)) + (float)(v10 * v10);
  if ( v12 <= 0.0 )
  {
    v14 = 0.0;
  }
  else
  {
    v13 = 1.0 / fsqrt(v12);
    v44 = v13 * v40;
    v45 = v13 * v11;
    v43 = v13 * v10;
    LODWORD(v14) = COERCE_UNSIGNED_INT(
                     (float)((float)(v6 * (float)(v13 * v40)) + (float)(v2[708] * (float)(v13 * v11)))
                   + (float)(v2[710] * (float)(v13 * v10))) ^ _xmm;
  }
  v15 = v2[708];
  v16 = v2[1932] - v15;
  v17 = v2[709];
  v18 = v2[1116] - v15;
  v19 = v2[1117] - v17;
  v20 = v2[1118] - v2[710];
  v39 = 0.0;
  v42 = 0.0;
  v41 = v2[1933] - v17;
  v21 = v2[1934] - v2[710];
  v22 = (float)(v21 * v19) - (float)(v41 * v20);
  v23 = (float)(v16 * v20) - (float)(v21 * v18);
  v24 = (float)(v41 * v18) - (float)(v16 * v19);
  v25 = v22;
  v38 = v23;
  v26 = 0.0;
  v27 = (float)((float)(v23 * v23) + (float)(v25 * v25)) + (float)(v24 * v24);
  if ( v27 <= 0.0 )
  {
    v32 = 0.0;
    v33 = 0.0;
  }
  else
  {
    v28 = 1.0 / fsqrt(v27);
    v29 = v28 * v25;
    v30 = v2[709] * (float)(v28 * v38);
    v42 = v28 * v38;
    v31 = v2[708] * (float)(v28 * v25);
    v32 = v28 * v24;
    v39 = v29;
    LODWORD(v33) = COERCE_UNSIGNED_INT((float)(v30 + v31) + (float)(v2[710] * v32)) ^ _xmm;
  }
  v34 = (float)((float)(v44 * -1.0) + (float)(v45 * 0.0)) + (float)(v43 * 0.0);
  if ( v34 == 0.0 )
    v35 = 0.0;
  else
    v35 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)(p->x * v45) + (float)(p->y * v44)) + (float)(p->z * v43))
                                       + v14)
                               / v34) ^ _xmm)
                * -1.0)
        + p->y;
  v36 = (float)((float)(v42 * -1.0) + (float)(v39 * 0.0)) + (float)(v32 * 0.0);
  if ( v36 != 0.0 )
    v26 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                 (float)((float)((float)((float)(p->x * v39) + (float)(p->y * v42)) + (float)(p->z * v32))
                                       + v33)
                               / v36) ^ _xmm)
                * -1.0)
        + p->y;
  return (float)((float)((float)(p->y - v26) + (float)(p->y - v35)) * 0.5);
}
std::tuple<float,float> *RaceEngineer::getRearDampingRatio(RaceEngineer *this, std::tuple<float,float> *result)
{
  ISuspension **v3; // eax
  ISuspension *v4; // esi
  float v5; // xmm0_4
  Car *v6; // eax
  int v7; // eax
  IRigidBody *v8; // ecx
  float v9; // xmm1_4
  float (*v10)(IRigidBody *); // eax
  double v11; // st7
  float (*v12)(ISuspension *); // eax
  double v13; // st7
  ISuspension_vtbl *v14; // eax
  float v15; // xmm0_4
  Car *v16; // eax
  ISuspension **v17; // eax
  ISuspension *v18; // esi
  float v19; // xmm0_4
  Car *v20; // eax
  int v21; // eax
  IRigidBody *v22; // ecx
  float v23; // xmm2_4
  float (*v24)(IRigidBody *); // eax
  double v25; // st7
  float (*v26)(ISuspension *); // eax
  double v27; // st7
  ISuspension_vtbl *v28; // eax
  float v29; // xmm0_4
  std::tuple<float,float> *v30; // eax
  float v31; // xmm1_4
  vec3f v32; // [esp+8h] [ebp-2Ch] BYREF
  vec3f v33; // [esp+14h] [ebp-20h] BYREF
  float v34; // [esp+20h] [ebp-14h]
  float v35; // [esp+24h] [ebp-10h]
  float v36; // [esp+28h] [ebp-Ch]
  float v37; // [esp+2Ch] [ebp-8h]
  float v38; // [esp+30h] [ebp-4h]

  v3 = this->car->suspensions._Myfirst;
  v4 = v3[2];
  v5 = (*v3)->getBasePosition(*v3, &v33)->z;
  v6 = this->car;
  v38 = v5;
  v7 = (*(int (**)(_DWORD, vec3f *))(**((_DWORD **)v6->suspensions._Myfirst + 2) + 40))(
         *((_DWORD *)v6->suspensions._Myfirst + 2),
         &v32);
  v8 = this->car->body;
  v9 = COERCE_FLOAT(LODWORD(v38) & _xmm) / COERCE_FLOAT(COERCE_UNSIGNED_INT(v38 - *(float *)(v7 + 8)) & _xmm);
  v10 = v8->getMass;
  v38 = 1.0 - (float)(1.0 - v9);
  v11 = ((double (*)(IRigidBody *))v10)(v8);
  v12 = v4->getK;
  v36 = v11 * v38 * 0.5;
  v13 = ((double (*)(ISuspension *))v12)(v4);
  v14 = v4->__vftable;
  v35 = v13;
  v15 = v14->getDamper(v4)->bumpSlow;
  v16 = this->car;
  v34 = v15;
  v17 = v16->suspensions._Myfirst;
  v18 = v17[2];
  v19 = (*v17)->getBasePosition(*v17, &v32)->z;
  v20 = this->car;
  v38 = v19;
  v21 = (*(int (**)(_DWORD, vec3f *))(**((_DWORD **)v20->suspensions._Myfirst + 2) + 40))(
          *((_DWORD *)v20->suspensions._Myfirst + 2),
          &v33);
  v22 = this->car->body;
  v23 = v38 - *(float *)(v21 + 8);
  v24 = v22->getMass;
  v38 = 1.0 - (float)(1.0 - (float)(COERCE_FLOAT(LODWORD(v38) & _xmm) / COERCE_FLOAT(LODWORD(v23) & _xmm)));
  v25 = ((double (*)(IRigidBody *))v24)(v22);
  v26 = v18->getK;
  v38 = v25 * v38 * 0.5;
  v27 = ((double (*)(ISuspension *))v26)(v18);
  v28 = v18->__vftable;
  v37 = v27;
  v29 = v28->getDamper(v18)->reboundSlow;
  v30 = result;
  v31 = v34;
  result->std::tuple<float>::_Myfirst._Val = v29 / (float)(fsqrt(v38 * v37) * 2.0);
  result->_Myfirst._Val = v31 / (float)(fsqrt(v36 * v35) * 2.0);
  return v30;
}
double RaceEngineer::getRearNaturalFrequencyHZ(RaceEngineer *this)
{
  ISuspension **v2; // eax
  ISuspension *v3; // edi
  int v4; // ecx
  float v6; // [esp+8h] [ebp-1Ch]
  float v7; // [esp+8h] [ebp-1Ch]
  float v8; // [esp+8h] [ebp-1Ch]
  float v9; // [esp+8h] [ebp-1Ch]
  vec3f v10; // [esp+Ch] [ebp-18h] BYREF
  char v11[12]; // [esp+18h] [ebp-Ch] BYREF

  v2 = this->car->suspensions._Myfirst;
  v3 = v2[2];
  v6 = (*v2)->getBasePosition(*v2, &v10)->z;
  v4 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
  v7 = 1.0
     - (float)(1.0
             - (float)(COERCE_FLOAT(LODWORD(v6) & _xmm)
                     / COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                      v6
                                    - *(float *)((*(int (**)(int, char *))(*(_DWORD *)v4 + 40))(v4, v11) + 8)) & _xmm)));
  v8 = ((double (*)(IRigidBody *))this->car->body->getMass)(this->car->body) * v7 * 0.5;
  v9 = ((double (*)(ISuspension *))v3->getK)(v3) / v8;
  return (float)(fsqrt(v9) * 0.15957616);
}
double RaceEngineer::getRearTrack(RaceEngineer *this)
{
  Car *v1; // eax
  double result; // st7
  char v3[12]; // [esp+8h] [ebp-Ch] BYREF

  v1 = this->car;
  if ( v1 )
    result = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                            *(float *)(*(int (**)(_DWORD, char *))(**((_DWORD **)v1->suspensions._Myfirst + 2)
                                                                            + 40))(
                                        *((_DWORD *)v1->suspensions._Myfirst + 2),
                                        v3)
                          * 2.0) & _xmm);
  else
    result = 0.0;
  return result;
}
Car *RaceEngineer::getRightDrivenTyre(RaceEngineer *this)
{
  Car *result; // eax

  result = this->car;
  if ( result )
  {
    if ( result->drivetrain.tractionType == FWD )
      result = (Car *)((char *)result + 3672);
    else
      result = (Car *)((char *)result + 6936);
  }
  return result;
}
double RaceEngineer::getTorqueToGripRatio(RaceEngineer *this)
{
  double result; // st7
  float v3; // xmm0_4
  Tyre *v4; // edi
  Tyre *v5; // ebx
  float *v6; // edi
  float load; // [esp+0h] [ebp-20h]
  float engine_force; // [esp+14h] [ebp-Ch]
  float v9; // [esp+18h] [ebp-8h]
  float v10; // [esp+1Ch] [ebp-4h]

  if ( !this->car )
    return 0.0;
  v10 = RaceEngineer::projectCarForwardForceAtGas(this, 1.0);
  v3 = 0.0;
  if ( v10 <= 0.0 )
    return 1.0;
  v4 = this->car->tyres;
  engine_force = 0.0;
  v5 = v4 + 4;
  if ( v4 == &v4[4] )
    goto LABEL_12;
  v6 = &v4->status.load;
  do
  {
    if ( *((_BYTE *)v6 + 593) )
    {
      load = Tyre::getDX((Tyre *)(v6 - 133), *v6);
      v9 = Tyre::getCorrectedD((Tyre *)(v6 - 133), load, 0);
      v3 = (float)((float)(v9 * *(v6 - 129)) * *v6) + engine_force;
      engine_force = v3;
    }
    v6 += 408;
  }
  while ( v6 - 133 != (float *)v5 );
  if ( v3 == 0.0 )
LABEL_12:
    result = 1.0;
  else
    result = v10 / engine_force;
  return result;
}
double RaceEngineer::projectCarForwardForceAtGas(RaceEngineer *this, const float gas)
{
  double v3; // st7
  Car *v4; // ecx
  float v5; // xmm0_4
  Car *v6; // eax
  Tyre *v7; // ecx
  float gasa; // [esp+0h] [ebp-Ch]
  float torquea; // [esp+10h] [ebp+4h]
  float torque; // [esp+10h] [ebp+4h]

  v3 = Engine::getThrottleResponseGas(&this->car->drivetrain.acEngine, gas, 0.0);
  v4 = this->car;
  torquea = v3;
  gasa = v4->drivetrain.engine.velocity * 0.1591550715257987 * 60.0;
  torque = Engine::getTorqueAtRPM(&v4->drivetrain.acEngine, gasa, torquea);
  if ( torque <= 0.0 )
    v5 = FLOAT_1_0;
  else
    v5 = this->car->drivetrain.acEngine.status.turboBoost + 1.0;
  v6 = this->car;
  if ( v6 )
  {
    v7 = v6->tyres;
    if ( v6->drivetrain.tractionType != FWD )
      v7 = &v6->tyres[2];
  }
  else
  {
    v7 = 0;
  }
  return (float)((float)(v5 * torque) * v6->drivetrain.ratio / v7->data.radius);
}
double RaceEngineer::projectWingsDrag(RaceEngineer *this, float speed)
{
  Car *v3; // esi
  Wing *v4; // edi
  Wing *v5; // esi
  double v6; // st7
  float v7; // xmm0_4
  float drag; // [esp+10h] [ebp-8h]
  float v10; // [esp+14h] [ebp-4h]
  float speeda; // [esp+1Ch] [ebp+4h]

  drag = 0.0;
  v3 = this->car;
  v4 = v3->aeroMap.wings._Mylast;
  v5 = v3->aeroMap.wings._Myfirst;
  if ( v5 != v4 )
  {
    speeda = speed * speed;
    do
    {
      v6 = Curve::getValue(&v5->data.lutAOA_CD, v5->status.angle + v5->status.aoa) * v5->data.cdGain;
      v7 = this->car->aeroMap.airDensity * v5->data.area;
      ++v5;
      v10 = v6;
      drag = (float)((float)((float)(v7 * 0.5) * speeda) * v10) + drag;
    }
    while ( v5 != v4 );
  }
  return drag;
}
double RaceEngineer::projectWingsLift(RaceEngineer *this, float speed)
{
  Car *v2; // esi
  Wing *v3; // edi
  float v4; // xmm0_4
  Wing *v5; // esi
  double v6; // st7
  float v7; // xmm0_4
  double v8; // st7
  float lift; // [esp+Ch] [ebp-8h]
  float v11; // [esp+10h] [ebp-4h]
  float speeda; // [esp+18h] [ebp+4h]

  lift = 0.0;
  v2 = this->car;
  v3 = v2->aeroMap.wings._Mylast;
  v4 = (float)(speed * speed) * v2->aeroMap.airDensity;
  v5 = v2->aeroMap.wings._Myfirst;
  for ( speeda = v4; v5 != v3; lift = (float)((float)((float)(v7 * 0.5) * speeda) * v11) + lift )
  {
    v6 = Curve::getValue(&v5->data.lutAOA_CL, v5->status.angle + v5->status.aoa);
    v7 = v5->data.area;
    v8 = v6 * v5->data.clGain;
    ++v5;
    v11 = v8;
  }
  return lift;
}
