#include "tyre.h"
void Tyre::Tyre(Tyre *this)
{
  this->inputs.handBrakeTorque = 0.0;
  this->inputs.electricTorque = 0.0;
  this->inputs.brakeTorque = 0.0;
  TyreData::TyreData(&this->data);
  TyreModelData::TyreModelData(&this->modelData);
  TyreStatus::TyreStatus(&this->status);
  mat44f::mat44f(&this->worldRotation);
  this->unmodifiedContactPoint.x = 0.0;
  this->unmodifiedContactPoint.y = 0.0;
  this->unmodifiedContactPoint.z = 0.0;
  this->contactPoint.x = 0.0;
  this->contactPoint.y = 0.0;
  this->contactPoint.z = 0.0;
  this->contactNormal.x = 0.0;
  this->contactNormal.y = 0.0;
  this->contactNormal.z = 0.0;
  TyreThermalModel::TyreThermalModel(&this->thermalModel);
  this->compoundDefs._Myfirst = 0;
  this->compoundDefs._Mylast = 0;
  this->compoundDefs._Myend = 0;
  this->onStepCompleted._Impl = 0;
  this->aiMult = 1.0;
  BrushSlipProvider::BrushSlipProvider(&this->slipProvider);
  this->externalInputs.isActive = 0;
  this->roadRight.x = 0.0;
  this->roadRight.y = 0.0;
  this->roadRight.z = 0.0;
  this->roadHeading.x = 0.0;
  this->roadHeading.y = 0.0;
  this->roadHeading.z = 0.0;
  *(_WORD *)&this->useLoadForVKM = 0;
  mat44f::mat44f(&this->localWheelRotation);
  this->worldPosition.x = 0.0;
  this->worldPosition.y = 0.0;
  this->worldPosition.z = 0.0;
  this->rayCaster = 0;
  SinSignalGenerator::SinSignalGenerator(&this->shakeGenerator);
  this->currentCompoundIndex = 0;
  this->tyreBlanketsOn = 1;
  this->flatSpotK = 0.15000001;
  this->tyreModel = 0;
  SCTM::SCTM(&this->scTM);
  this->explosionTemperature = 350.0;
  this->blanketTemperature = 80.0;
  this->pressureTemperatureGain = 0.16;
  this->localMX = 0.0;
}
void Tyre::~Tyre(Tyre *this)
{
  IRayCaster *v2; // ecx
  std::_Func_base<void> *v3; // ecx
  std::function<void __cdecl(void)> *v4; // edi
  std::_Func_base<void> *v5; // ecx

  v2 = this->rayCaster;
  if ( v2 )
    v2->release(v2);
  SCTM::~SCTM(&this->scTM);
  SinSignalGenerator::~SinSignalGenerator(&this->shakeGenerator);
  BrushSlipProvider::~BrushSlipProvider(&this->slipProvider);
  v3 = this->onStepCompleted._Impl;
  v4 = &this->onStepCompleted;
  if ( v3 )
  {
    ((void (__stdcall *)(bool))v3->_Delete_this)(v3 != (std::_Func_base<void> *)v4);
    this->onStepCompleted._Impl = 0;
  }
  v5 = this->onStepCompleted._Impl;
  if ( v5 )
  {
    ((void (__stdcall *)(bool))v5->_Delete_this)(v5 != (std::_Func_base<void> *)v4);
    this->onStepCompleted._Impl = 0;
  }
  std::vector<TyreCompoundDef>::_Tidy(&this->compoundDefs);
  TyreThermalModel::~TyreThermalModel(&this->thermalModel);
  Curve::~Curve(&this->modelData.dCamberCurve);
  Curve::~Curve(&this->modelData.dxLoadCurve);
  Curve::~Curve(&this->modelData.dyLoadCurve);
  Curve::~Curve(&this->modelData.wearCurve);
}
void Tyre::addGroundContact(Tyre *this, const vec3f *pos, const vec3f *normal)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  ISuspension *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  bool v12; // cc
  float v13; // xmm0_4
  ISuspension *v14; // ecx
  float v15; // xmm1_4
  BOOL v16; // [esp-8h] [ebp-28h]
  int v17[3]; // [esp+8h] [ebp-18h] BYREF
  int v18[3]; // [esp+14h] [ebp-Ch] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    perfCounter_35.name = "Tyre::addGroundContact";
    _S2_1 |= 1u;
    perfCounter_35.group = Physics;
    perfCounter_35.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Tyre::addGroundContact" | 0xFF000000;
  }
  v4 = (float)((float)((float)(this->worldPosition.y - pos->y) * (float)(this->worldPosition.y - pos->y))
             + (float)((float)(this->worldPosition.x - pos->x) * (float)(this->worldPosition.x - pos->x)))
     + (float)((float)(this->worldPosition.z - pos->z) * (float)(this->worldPosition.z - pos->z));
  v5 = 0.0;
  if ( v4 != 0.0 )
    v5 = fsqrt(v4);
  v6 = this->hub;
  this->status.distToGround = v5;
  v6->getPointVelocity(v6, (vec3f *)v18, pos);
  v7 = this->data.radiusRaiseK;
  if ( v7 == 0.0 )
    v8 = this->data.radius;
  else
    v8 = (float)(COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) * v7) + this->data.radius;
  v9 = this->status.inflation;
  if ( v9 < 1.0 )
    v8 = (float)((float)(v8 - this->data.rimRadius) * v9) + this->data.rimRadius;
  v10 = this->status.distToGround;
  this->status.liveRadius = v8;
  this->status.effectiveRadius = v8;
  if ( v8 < v10 )
  {
    this->status.depth = 0.0;
    this->status.Fx = 0.0;
    this->status.Mz = 0.0;
    this->status.Fy = 0.0;
    this->rSlidingVelocityY = 0.0;
    this->rSlidingVelocityX = 0.0;
    this->status.loadedRadius = v8;
    this->status.ndSlip = 0.0;
LABEL_18:
    this->status.load = 0.0;
    goto LABEL_19;
  }
  v11 = v8 - v10;
  this->status.depth = v8 - v10;
  v12 = (float)(v8 - (float)(v8 - v10)) <= this->data.rimRadius;
  this->status.loadedRadius = v8 - (float)(v8 - v10);
  if ( v12 )
  {
    v13 = FLOAT_200000_0;
  }
  else
  {
    v13 = (float)((float)(this->status.pressureDynamic - this->modelData.pressureRef)
                * this->modelData.pressureSpringGain)
        + this->data.k;
    if ( v13 < 0.0 )
      v13 = 0.0;
  }
  v14 = this->hub;
  v15 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                       (float)((float)((float)(normal->x * *(float *)v18) + (float)(*(float *)&v18[1] * normal->y))
                             + (float)(normal->z * *(float *)&v18[2]))
                     * this->data.d) ^ _xmm)
      + (float)(v11 * v13);
  this->status.load = v15;
  *(float *)v17 = normal->x * v15;
  *(float *)&v17[1] = v15 * normal->y;
  v16 = this->driven;
  *(float *)&v17[2] = normal->z * v15;
  v14->addForceAtPos(v14, (const vec3f *)v17, pos, v16, 0);
  if ( this->status.load < 0.0 )
    goto LABEL_18;
LABEL_19:
  if ( this->externalInputs.isActive )
    this->status.load = this->externalInputs.load;
}
void Tyre::addTyreForceToHub(Tyre *this, const vec3f *pos, const vec3f *force)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm7
  __m128 v6; // xmm3
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  Car *v12; // eax
  float v13; // xmm4_4
  float v14; // xmm1_4
  TorqueModeEX v15; // eax
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm5_4
  __int32 v22; // eax
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  float v29; // xmm0_4
  float v30; // [esp+8h] [ebp-108h]
  float v31; // [esp+8h] [ebp-108h]
  float v32; // [esp+10h] [ebp-100h]
  unsigned __int64 v33; // [esp+14h] [ebp-FCh] BYREF
  int v34; // [esp+1Ch] [ebp-F4h]
  __m128 v35; // [esp+20h] [ebp-F0h]
  __m128i v36; // [esp+30h] [ebp-E0h]
  __m128i v37; // [esp+40h] [ebp-D0h]
  __m128i v38; // [esp+50h] [ebp-C0h]
  __m128 v39; // [esp+60h] [ebp-B0h]
  unsigned __int64 v40; // [esp+70h] [ebp-A0h] BYREF
  float v41; // [esp+78h] [ebp-98h]
  float v42; // [esp+7Ch] [ebp-94h]
  __m128 v43; // [esp+80h] [ebp-90h] BYREF
  __m128 v44; // [esp+90h] [ebp-80h]
  __m128 pDeterminant; // [esp+A0h] [ebp-70h] BYREF
  __m128 v46; // [esp+B0h] [ebp-60h]
  __m128 v47; // [esp+C0h] [ebp-50h]
  mat44f v48; // [esp+D0h] [ebp-40h] BYREF

  v36 = _mm_loadu_si128((const __m128i *)&this->worldRotation);
  v37 = _mm_loadu_si128((const __m128i *)&this->worldRotation.M21);
  v38 = _mm_loadu_si128((const __m128i *)&this->worldRotation.M31);
  v39 = (__m128)_mm_loadu_si128((const __m128i *)&this->worldRotation.M41);
  v39.m128_u64[0] = *(_QWORD *)&this->worldPosition.x;
  v39.m128_i32[2] = LODWORD(this->worldPosition.z);
  mat44f::mat44f(&v48);
  v4 = (__m128)_mm_loadu_si128((const __m128i *)&this->worldRotation.M21);
  v5 = (__m128)_mm_loadu_si128((const __m128i *)&this->worldRotation.M31);
  v44 = v39;
  v6 = DirectX::XMMatrixInverse(
         &pDeterminant,
         (__m128)_mm_loadu_si128((const __m128i *)&this->worldRotation),
         v4,
         v5,
         v39);
  v7 = force->y;
  v8 = force->z;
  v9 = force->x * v6.m128_f32[0];
  pDeterminant = _mm_shuffle_ps(v4, v4, 85);
  v35 = v4;
  v43 = v5;
  v46 = _mm_shuffle_ps(v6, v6, 85);
  v47 = v6;
  v42 = (float)(v9 + (float)(v7 * v4.m128_f32[0])) + (float)(v8 * v5.m128_f32[0]);
  v10 = _mm_shuffle_ps(v5, v5, 85).m128_f32[0];
  v5.m128_f32[0] = _mm_shuffle_ps(v6, v6, 170).m128_f32[0];
  v4.m128_f32[0] = _mm_shuffle_ps(v4, v4, 170).m128_f32[0];
  v30 = (float)((float)(force->x * v46.m128_f32[0]) + (float)(v7 * pDeterminant.m128_f32[0])) + (float)(v8 * v10);
  v6.m128_f32[0] = _mm_shuffle_ps(v43, v43, 170).m128_f32[0];
  v32 = (float)((float)(force->x * v5.m128_f32[0]) + (float)(v7 * v4.m128_f32[0])) + (float)(v8 * v6.m128_f32[0]);
  v11 = pos->y;
  v12 = this->car;
  v13 = pos->x * v47.m128_f32[0];
  v33 = 0i64;
  v14 = pos->z;
  v34 = 0;
  v40 = 0i64;
  v41 = 0.0;
  v15 = v12->torqueModeEx;
  v16 = pos->x;
  v43.m128_f32[0] = (float)((float)(v13 + (float)(v11 * v35.m128_f32[0])) + (float)(v14 * v43.m128_f32[0]))
                  + v39.m128_f32[0];
  v17 = (float)((float)((float)(v16 * v46.m128_f32[0]) + (float)(v11 * pDeterminant.m128_f32[0])) + (float)(v14 * v10))
      + _mm_shuffle_ps(v44, v44, 85).m128_f32[0];
  v4.m128_f32[0] = (float)((float)((float)(pos->x * v5.m128_f32[0]) + (float)(v11 * v4.m128_f32[0]))
                         + (float)(v14 * v6.m128_f32[0]))
                 + v39.m128_f32[2];
  v18 = (float)(v30 * v43.m128_f32[0]) - (float)(v17 * v42);
  v19 = v30 * v4.m128_f32[0];
  v31 = v18;
  v20 = (float)(v32 * v17) - v19;
  v21 = (float)(v4.m128_f32[0] * v42) - (float)(v32 * v43.m128_f32[0]);
  v22 = v15 - 1;
  if ( !v22 )
  {
    v27 = (__m128)v37.m128i_u32[0];
    v28 = (__m128)v37.m128i_u32[1];
    v27.m128_f32[0] = (float)((float)(*(float *)v37.m128i_i32 * v21) + (float)(*(float *)v36.m128i_i32 * 0.0))
                    + (float)(*(float *)v38.m128i_i32 * v18);
    v28.m128_f32[0] = (float)((float)(*(float *)&v37.m128i_i32[1] * v21) + (float)(*(float *)&v36.m128i_i32[1] * 0.0))
                    + (float)(*(float *)&v38.m128i_i32[1] * v18);
    v29 = *(float *)&v36.m128i_i32[2] * 0.0;
    goto LABEL_7;
  }
  if ( v22 == 1 )
  {
    if ( this->driven )
    {
      v23 = (__m128)v36.m128i_u32[0];
      v24 = (__m128)v36.m128i_u32[1];
      v43.m128_u64[0] = v37.m128i_u32[0];
      v23.m128_f32[0] = (float)((float)(*(float *)v36.m128i_i32 * v20) + (float)(*(float *)v37.m128i_i32 * 0.0))
                      + (float)(*(float *)v38.m128i_i32 * 0.0);
      v24.m128_f32[0] = (float)((float)(*(float *)&v36.m128i_i32[1] * v20) + (float)(*(float *)&v37.m128i_i32[1] * 0.0))
                      + (float)(*(float *)&v38.m128i_i32[1] * 0.0);
      v23.m128_u64[0] = _mm_unpacklo_ps(v23, v24).m128_u64[0];
      v25 = (__m128)_mm_loadl_epi64((const __m128i *)&v43);
      v40 = v23.m128_u64[0];
      v26 = (__m128)v37.m128i_u32[1];
      v41 = (float)((float)(*(float *)&v36.m128i_i32[2] * v20) + (float)(*(float *)&v37.m128i_i32[2] * 0.0))
          + (float)(*(float *)&v38.m128i_i32[2] * 0.0);
      v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v21) + (float)(*(float *)v36.m128i_i32 * 0.0))
                      + (float)(*(float *)v38.m128i_i32 * v31);
      v35.m128_f32[2] = (float)((float)(*(float *)&v37.m128i_i32[2] * v21) + (float)(*(float *)&v36.m128i_i32[2] * 0.0))
                      + (float)(*(float *)&v38.m128i_i32[2] * v31);
      v26.m128_f32[0] = (float)((float)(*(float *)&v37.m128i_i32[1] * v21) + (float)(*(float *)&v36.m128i_i32[1] * 0.0))
                      + (float)(*(float *)&v38.m128i_i32[1] * v31);
      v33 = _mm_unpacklo_ps(v25, v26).m128_u64[0];
LABEL_8:
      v34 = v35.m128_i32[2];
      goto LABEL_9;
    }
    v27 = (__m128)v37.m128i_u32[0];
    v28 = (__m128)v37.m128i_u32[1];
    v27.m128_f32[0] = (float)((float)(*(float *)v37.m128i_i32 * v21) + (float)(*(float *)v36.m128i_i32 * v20))
                    + (float)(*(float *)v38.m128i_i32 * v18);
    v28.m128_f32[0] = (float)((float)(*(float *)&v37.m128i_i32[1] * v21) + (float)(*(float *)&v36.m128i_i32[1] * v20))
                    + (float)(*(float *)&v38.m128i_i32[1] * v18);
    v29 = *(float *)&v36.m128i_i32[2] * v20;
LABEL_7:
    v33 = _mm_unpacklo_ps(v27, v28).m128_u64[0];
    v35.m128_f32[2] = (float)((float)(*(float *)&v37.m128i_i32[2] * v21) + v29)
                    + (float)(*(float *)&v38.m128i_i32[2] * v18);
    goto LABEL_8;
  }
LABEL_9:
  this->hub->addLocalForceAndTorque(this->hub, force, (const vec3f *)&v33, (const vec3f *)&v40);
  LODWORD(this->localMX) = LODWORD(v20) ^ _xmm;
}
void Tyre::addTyreForces(Tyre *this, const vec3f *pos, const vec3f *normal, SurfaceDef *surfaceDef, float dt)
{
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  float v8; // xmm5_4
  __m128 v9; // xmm7
  __m128 v10; // xmm6
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  float v16; // eax
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  double v31; // st7
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float svx; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  double v42; // st7
  double v43; // st7
  float v44; // xmm3_4
  int v45; // xmm2_4
  double v46; // st7
  float v47; // xmm2_4
  float *v48; // eax
  float v49; // xmm3_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float *v52; // eax
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  double v56; // st7
  float v57; // xmm0_4
  float v58; // xmm4_4
  bool v59; // cc
  double v60; // xmm1_8
  double v61; // xmm0_8
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm0_4
  float v66; // xmm5_4
  int v67; // xmm0_4
  float *v68; // eax
  float v69; // xmm0_4
  float v70; // ecx
  float v71; // xmm1_4
  float v72; // xmm4_4
  float v73; // xmm0_4
  float v74; // xmm3_4
  ITyreModel *v75; // ecx
  float v76; // xmm2_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm0_4
  float v80; // xmm2_4
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm0_4
  Car *v84; // eax
  float v85; // xmm1_4
  Car *v86; // eax
  float v87; // xmm1_4
  double v88; // st7
  float v89; // xmm4_4
  float v90; // xmm0_4
  float v91; // xmm3_4
  float v92; // xmm5_4
  float v93; // xmm6_4
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm0_4
  float v97; // xmm5_4
  float v98; // xmm4_4
  float v99; // xmm6_4
  float v100; // xmm0_4
  float v101; // xmm3_4
  ISuspension *v102; // ecx
  float v103; // xmm1_4
  float v104; // xmm2_4
  float v105; // xmm2_4
  float v106; // xmm5_4
  float v107; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm2_4
  float v110; // xmm4_4
  float v111; // xmm0_4
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  Car *v115; // eax
  BOOL vy; // [esp+10h] [ebp-B4h]
  float vx; // [esp+14h] [ebp-B0h]
  float vxa; // [esp+14h] [ebp-B0h]
  int v119[6]; // [esp+20h] [ebp-A4h] BYREF
  float v120; // [esp+38h] [ebp-8Ch] BYREF
  float v121; // [esp+3Ch] [ebp-88h]
  float v122; // [esp+40h] [ebp-84h]
  const vec3f *v123; // [esp+44h] [ebp-80h]
  float v124; // [esp+48h] [ebp-7Ch] BYREF
  float v125; // [esp+4Ch] [ebp-78h]
  float v126; // [esp+50h] [ebp-74h]
  int v127; // [esp+54h] [ebp-70h] BYREF
  float dy; // [esp+58h] [ebp-6Ch] BYREF
  float v129; // [esp+5Ch] [ebp-68h]
  float v130; // [esp+60h] [ebp-64h] BYREF
  float Px; // [esp+64h] [ebp-60h] BYREF
  TyreModelOutput v132; // [esp+68h] [ebp-5Ch] BYREF
  int v133[12]; // [esp+84h] [ebp-40h] BYREF
  float out; // [esp+B4h] [ebp-10h] BYREF
  _BYTE v135[12]; // [esp+B8h] [ebp-Ch] BYREF

  v123 = pos;
  if ( (dword_186F1CC & 1) == 0 )
  {
    perfCounter_37.name = "Tyre::addTyreForces";
    dword_186F1CC |= 1u;
    perfCounter_37.group = Physics;
    perfCounter_37.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Tyre::addTyreForces" | 0xFF000000;
  }
  v6 = (__m128)LODWORD(this->worldRotation.M31);
  v7 = (__m128)LODWORD(this->worldRotation.M32);
  v8 = this->worldRotation.M33;
  *(_QWORD *)v135 = LODWORD(this->worldRotation.M11);
  Px = this->worldRotation.M12;
  v130 = this->worldRotation.M13;
  v9 = _mm_xor_ps(v6, (__m128)(unsigned int)_xmm);
  v10 = _mm_xor_ps(v7, (__m128)(unsigned int)_xmm);
  LODWORD(v11) = LODWORD(v8) ^ _xmm;
  v12 = (float)((float)(v9.m128_f32[0] * normal->x) + (float)(v10.m128_f32[0] * normal->y)) + (float)(v11 * normal->z);
  v9.m128_f32[0] = v9.m128_f32[0] - (float)(v12 * normal->x);
  v10.m128_f32[0] = v10.m128_f32[0] - (float)(v12 * normal->y);
  v13 = v11 - (float)(v12 * normal->z);
  v9.m128_u64[0] = _mm_unpacklo_ps(v9, v10).m128_u64[0];
  v14 = (__m128)LODWORD(Px);
  *(_QWORD *)&this->roadHeading.x = v9.m128_u64[0];
  v15 = (__m128)_mm_loadl_epi64((const __m128i *)v135);
  v126 = v13;
  v16 = v13;
  v17 = v130;
  this->roadHeading.z = v16;
  v18 = (float)((float)(v15.m128_f32[0] * normal->x) + (float)(v14.m128_f32[0] * normal->y)) + (float)(v17 * normal->z);
  v15.m128_f32[0] = v15.m128_f32[0] - (float)(v18 * normal->x);
  v14.m128_f32[0] = v14.m128_f32[0] - (float)(v18 * normal->y);
  v19 = v17 - (float)(v18 * normal->z);
  *(_QWORD *)&this->roadRight.x = _mm_unpacklo_ps(v15, v14).m128_u64[0];
  v126 = v19;
  this->roadRight.z = v19;
  v20 = this->roadRight.y;
  v21 = this->roadRight.x;
  v22 = this->roadRight.z;
  v23 = fsqrt((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22));
  if ( v23 != 0.0 )
  {
    this->roadRight.x = (float)(1.0 / v23) * v21;
    this->roadRight.y = (float)(1.0 / v23) * v20;
    this->roadRight.z = (float)(1.0 / v23) * v22;
  }
  v24 = this->roadHeading.y;
  v25 = this->roadHeading.x;
  v26 = this->roadHeading.z;
  v27 = fsqrt((float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v26 * v26));
  if ( v27 != 0.0 )
  {
    this->roadHeading.x = (float)(1.0 / v27) * v25;
    this->roadHeading.y = (float)(1.0 / v27) * v24;
    this->roadHeading.z = (float)(1.0 / v27) * v26;
  }
  this->hub->getPointVelocity(this->hub, (vec3f *)&v124, pos);
  v28 = v124;
  v29 = (float)((float)(this->roadRight.y * v125) + (float)(v124 * this->roadRight.x))
      + (float)(this->roadRight.z * v126);
  this->slidingVelocityY = v29;
  v30 = (float)((float)(this->roadHeading.y * v125) + (float)(v28 * this->roadHeading.x))
      + (float)(this->roadHeading.z * v126);
  this->roadVelocityX = v30;
  v31 = ksCalcSlipAngleRAD(v29, v30);
  this->status.slipRatio = 0.0;
  this->status.slipAngleRAD = v31;
  Px = ksCalcCamberRAD(&this->contactNormal, &this->worldRotation);
  this->status.camberRAD = Px;
  v32 = __libm_sse2_sinf().m128_f32[0];
  v33 = this->status.angularVelocity * this->status.effectiveRadius;
  v34 = v32 * this->modelData.camberGain;
  this->roadVelocityY = this->slidingVelocityY;
  v35 = v33 + this->roadVelocityX;
  v130 = v34;
  this->slidingVelocityX = v35;
  Px = v35;
  if ( __fdtest(&Px) > 0 || (Px = this->slidingVelocityY, __fdtest(&Px) > 0) )
    _printf("SLIDING VELOCITY NAN!\n");
  svx = this->slidingVelocityX;
  if ( svx != 0.0 || this->slidingVelocityY != 0.0 )
  {
    this->totalHubVelocity = fsqrt(
                               (float)(this->roadVelocityY * this->roadVelocityY)
                             + (float)(this->roadVelocityX * this->roadVelocityX));
    Tyre::stepRelaxationLength(
      this,
      svx,
      this->slidingVelocityY,
      COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) * this->status.effectiveRadius,
      dt);
    v37 = this->rSlidingVelocityX;
    v38 = this->roadVelocityX;
    v39 = (float)(v38 * v130) + this->rSlidingVelocityY;
    v130 = v39;
    if ( v37 == 0.0 && v39 == 0.0 )
      this->totalSlideVelocity = 0.0;
    else
      this->totalSlideVelocity = fsqrt((float)(v37 * v37) + (float)(v39 * v39));
    if ( v38 == 0.0 )
      this->status.slipRatio = 0.0;
    else
      LODWORD(this->status.slipRatio) = COERCE_UNSIGNED_INT(this->slidingVelocityX / v38) ^ _xmm;
    v40 = this->totalSlideVelocity;
    if ( v40 == 0.0 )
    {
      this->status.Fy = 0.0;
      this->status.Fx = 0.0;
      this->status.Mz = 0.0;
    }
    else
    {
      v41 = this->totalHubVelocity;
      if ( v41 > 1.0 )
        v40 = v40 / v41;
      v129 = v40;
      v42 = Tyre::getDY(this, this->status.load);
      vx = this->status.load;
      dy = v42 * this->aiMult;
      v43 = Tyre::getDX(this, vx);
      v44 = this->status.camberRAD;
      v45 = LODWORD(this->status.camberRAD) & _xmm;
      Px = v43;
      if ( v44 > 0.0 && v130 > 0.0 || v44 < 0.0 && v130 < 0.0 )
        v45 ^= _xmm;
      v46 = Tyre::getCamberedDy(this, COERCE_FLOAT(v45 ^ _xmm), dy);
      v47 = 1.0 / this->totalSlideVelocity;
      *(_DWORD *)&v135[4] = 0;
      v48 = (float *)&v135[4];
      dy = v46;
      if ( dy >= 0.0 )
        v48 = &dy;
      v49 = *v48;
      v50 = v47;
      v51 = v47 * v130;
      v52 = (float *)&v135[4];
      if ( Px >= 0.0 )
        v52 = &Px;
      *(_DWORD *)&v135[4] = 0;
      LODWORD(v53) = LODWORD(v51) & _xmm;
      v54 = *v52;
      LODWORD(v55) = COERCE_UNSIGNED_INT(v50 * this->rSlidingVelocityX) & _xmm;
      this->status.normalizedSlideX = v55;
      this->status.normalizedSlideY = v53;
      this->status.Dx = v54;
      this->status.Dy = v49;
      v56 = Tyre::getCorrectedD(
              this,
              fsqrt((float)((float)(v55 * v54) * (float)(v55 * v54)) + (float)((float)(v53 * v49) * (float)(v53 * v49))),
              &this->status.wearMult);
      v57 = this->modelData.speedSensitivity * this->totalSlideVelocity;
      *(float *)&v135[4] = v56;
      v58 = *(float *)&v135[4] / (float)(v57 + 1.0);
      v59 = this->data.rimRadius <= this->status.loadedRadius;
      Px = v58;
      if ( !v59 )
      {
        v58 = FLOAT_0_30000001;
        Px = FLOAT_0_30000001;
      }
      v60 = this->status.grain * 0.01;
      this->status.D = v58;
      if ( v60 <= 1.0 )
      {
        v61 = 0.0;
        if ( v60 >= 0.0 )
          v61 = v60;
      }
      else
      {
        v61 = DOUBLE_1_0;
      }
      v62 = v61 + 1.0;
      v63 = v129 / v62;
      v119[1] = LODWORD(surfaceDef->gripMod);
      v64 = this->status.load;
      *(float *)v119 = v63;
      *(float *)&v119[2] = v64;
      v65 = this->status.slipRatio;
      if ( v65 <= 0.0 )
      {
        if ( v65 >= 0.0 )
          v66 = 0.0;
        else
          v66 = FLOAT_N1_0;
      }
      else
      {
        v66 = FLOAT_1_0;
      }
      *(float *)&v67 = this->status.normalizedSlideX * v66;
      *(float *)&v119[5] = v58;
      v119[3] = v67;
      v119[4] = LODWORD(this->status.normalizedSlideY);
      if ( surfaceDef->granularity == 0.0 )
      {
        v68 = (float *)((int (*)(BrushSlipProvider *, int *, int *, bool))this->slipProvider.getSlipForce)(
                         &this->slipProvider,
                         &v127,
                         v119,
                         this->aiMult <= 1.0);
        v69 = Px;
        v70 = *v68;
        *(float *)&v135[4] = v68[1];
        v71 = *(float *)&v135[4];
        *(float *)v135 = v70;
        v72 = v70;
        v129 = *(float *)&v135[4];
      }
      else
      {
        v73 = __libm_sse2_expf().m128_f32[0];
        v71 = v129;
        v72 = 1.0 - v73;
        v69 = FLOAT_0_64999998;
        surfaceDef->gripMod = 1.0;
      }
      v74 = this->status.load;
      this->status.ndSlip = v71;
      v75 = this->tyreModel;
      *(float *)v133 = v74;
      v76 = (float)(v74 * v72) * v69;
      v133[5] = 1065353216;
      v77 = v74 * v71;
      v78 = 1.0 / this->totalSlideVelocity;
      this->status.slipFactor = v77;
      v79 = v76 * v130;
      v80 = (float)(v76 * this->rSlidingVelocityX) * v78;
      LODWORD(v81) = COERCE_UNSIGNED_INT(v79 * v78) ^ _xmm;
      v82 = this->roadVelocityX;
      this->status.Fy = v81;
      v133[3] = LODWORD(this->status.camberRAD);
      v133[1] = LODWORD(this->status.slipAngleRAD);
      v83 = this->status.angularVelocity * this->status.effectiveRadius;
      LODWORD(this->status.Fx) = LODWORD(v80) ^ _xmm;
      *(float *)&v133[2] = (float)(v83 + v82) / COERCE_FLOAT(LODWORD(v82) & _xmm);
      v133[4] = LODWORD(this->totalHubVelocity);
      v75->solve(v75, &v132, (const TyreModelInput *)v133);
      v84 = this->car;
      v85 = FLOAT_1_0;
      if ( v84 )
        v85 = v84->ksPhysics->track->dynamicGripLevel;
      this->status.Fx = (float)(v85 * surfaceDef->gripMod) * this->status.Fx;
      LODWORD(vxa) = COERCE_UNSIGNED_INT(this->status.angularVelocity * this->status.effectiveRadius) & _xmm;
      this->status.Fy = (float)(v85 * surfaceDef->gripMod) * this->status.Fy;
      Tyre::stepDirtyLevel(this, dt, vxa);
      TyreThermalModel::getIMO(&this->thermalModel, &out);
      v86 = this->car;
      if ( v86 )
      {
        if ( v86->ksPhysics->mechanicalDamageRate > 0.0 )
        {
          v87 = this->explosionTemperature;
          if ( out > v87 || *(float *)v135 > v87 || *(float *)&v135[4] > v87 )
            this->status.inflation = 0.0;
        }
      }
      v88 = ksCalcContactPatchLength(this->status.liveRadius, this->status.depth);
      v89 = 1.0 - (float)(v129 * 0.80000001);
      *(float *)&v135[4] = v88;
      if ( v89 <= 1.0 )
      {
        if ( v89 < 0.0 )
          v89 = 0.0;
      }
      else
      {
        v89 = FLOAT_1_0;
      }
      v90 = this->totalHubVelocity;
      v91 = (float)((float)((float)((float)((float)(3.0 - (float)(v89 * 2.0)) * (float)(v89 * v89)) * 1.1) - 0.1)
                  * *(float *)&v135[4])
          * 0.12;
      if ( v90 <= 1.0 )
      {
        if ( v90 < 0.0 )
          v90 = 0.0;
      }
      else
      {
        v90 = FLOAT_1_0;
      }
      this->status.Mz = 0.0;
      v92 = this->roadHeading.y;
      v93 = this->roadHeading.z;
      v94 = this->roadRight.y;
      v95 = this->roadRight.z;
      Px = v90 * v91;
      v96 = this->status.Fx;
      v97 = v92 * v96;
      v98 = v96 * this->roadHeading.x;
      v99 = v93 * v96;
      v100 = this->status.Fy;
      v101 = (float)(v100 * this->roadRight.x) + v98;
      v121 = (float)(v94 * v100) + v97;
      v120 = v101;
      *(float *)&v135[4] = v101;
      v122 = (float)(v95 * v100) + v99;
      if ( __fdtest((float *)&v135[4]) > 0 || (v130 = v121, __fdtest(&v130) > 0) || (dy = v122, __fdtest(&dy) > 0) )
        _printf("TYRE GENERATED NAN FORCE\n");
      v102 = this->hub;
      v103 = this->roadHeading.y * Px;
      v104 = this->roadHeading.z * Px;
      out = (float)(this->roadHeading.x * Px) + v123->x;
      *(float *)v135 = v123->y + v103;
      vy = this->driven;
      *(float *)&v135[4] = v123->z + v104;
      v102->addForceAtPos(v102, (const vec3f *)&v120, (const vec3f *)&out, vy, 1);
      v105 = this->status.angularVelocity;
      LODWORD(v106) = LODWORD(this->status.angularVelocity) & _xmm;
      LODWORD(this->status.Mz) = COERCE_UNSIGNED_INT(Px * this->status.Fy) ^ _xmm;
      if ( v106 > 1.0 )
      {
        v107 = this->status.pressureDynamic;
        v108 = 0.0;
        v109 = v105 * this->status.effectiveRadius;
        v110 = (float)((float)((float)(this->modelData.idealPressure / v107) - 1.0) * this->modelData.pressureRRGain)
             + 1.0;
        if ( v107 <= 0.0 )
          v110 = 0.0;
        if ( v109 <= 0.0 )
        {
          if ( v109 >= 0.0 )
            v111 = 0.0;
          else
            v111 = FLOAT_N1_0;
        }
        else
        {
          v111 = FLOAT_1_0;
        }
        v112 = (float)((float)((float)((float)(v109 * v109) * this->modelData.rr1) + this->modelData.rr0) * v111) * v110;
        if ( v106 > 20.0 )
        {
          if ( this->modelData.version < 2 )
          {
            LODWORD(v114) = LODWORD(this->status.slipRatio) & _xmm;
            if ( v114 <= 1.0 )
            {
              if ( v114 >= 0.0 )
                LODWORD(v108) = LODWORD(this->status.slipRatio) & _xmm;
            }
            else
            {
              v108 = FLOAT_1_0;
            }
            v112 = (float)((float)((float)((float)(v108 * (float)(this->modelData.rr_sr * v110))
                                         + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(this->status.slipAngleRAD * 57.29578) & _xmm)
                                                 * (float)(this->modelData.rr_sa * v110)))
                                 * 0.001)
                         + 1.0)
                 * v112;
          }
          else
          {
            v113 = this->status.ndSlip;
            if ( v113 <= 1.0 )
            {
              if ( v113 >= 0.0 )
                v108 = this->status.ndSlip;
            }
            else
            {
              v108 = FLOAT_1_0;
            }
            v112 = (float)((float)((float)((float)(this->modelData.rr_slip * v108) * v110) * 0.001) + 1.0) * v112;
          }
        }
        LODWORD(this->status.rollingResistence) = COERCE_UNSIGNED_INT(
                                                    (float)((float)(this->status.load * 0.001) * v112)
                                                  * this->status.effectiveRadius) ^ _xmm;
      }
      v115 = this->car;
      if ( v115 )
        this->status.virtualKM = (float)((float)(this->totalSlideVelocity * dt) * v115->ksPhysics->tyreConsumptionRate)
                               * 0.001
                               + this->status.virtualKM;
    }
  }
}
void __userpurge Tyre::addTyreForcesV10(Tyre *this@<ecx>, int a2@<edi>, const vec3f *pos, const vec3f *normal, SurfaceDef *surfaceDef, float dt, float a7)
{
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  float v10; // xmm5_4
  float v11; // xmm5_4
  __m128 v12; // xmm7
  __m128 v13; // xmm6
  float v14; // xmm4_4
  float v15; // xmm5_4
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm7
  float v19; // xmm0_4
  __m128 v20; // xmm1
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  ISuspension *v31; // ecx
  ISuspension_vtbl *v32; // eax
  float vy; // xmm5_4
  double v34; // st7
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  double v40; // st7
  float v41; // xmm4_4
  float v42; // xmm2_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm6_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float v49; // xmm4_4
  float v50; // xmm7_4
  float v51; // xmm3_4
  float v52; // xmm3_4
  float v53; // xmm7_4
  float v54; // xmm3_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  Car *v58; // eax
  float v59; // xmm0_4
  double v60; // st7
  double v61; // st7
  float v62; // xmm0_4
  double v63; // st7
  float v64; // xmm0_4
  ITyreModel *v65; // ecx
  float v66; // xmm0_4
  Car *v67; // eax
  float v68; // xmm1_4
  float v69; // xmm0_4
  float v70; // xmm4_4
  float v71; // xmm5_4
  float v72; // xmm6_4
  float v73; // xmm0_4
  float v74; // xmm3_4
  float v75; // xmm2_4
  Car *v76; // eax
  ISuspension *v77; // ecx
  float v78; // xmm2_4
  float v79; // xmm5_4
  float v80; // xmm1_4
  float v81; // xmm3_4
  float v82; // xmm0_4
  float v83; // xmm4_4
  float v84; // xmm0_4
  float v85; // xmm3_4
  float v86; // xmm0_4
  float v87; // xmm0_4
  Car *v88; // eax
  double v89; // st7
  float v90; // xmm0_4
  float vx; // [esp+28h] [ebp-A4h]
  float vxa; // [esp+28h] [ebp-A4h]
  float v93; // [esp+34h] [ebp-98h] BYREF
  float v94; // [esp+38h] [ebp-94h]
  int v95[3]; // [esp+3Ch] [ebp-90h] BYREF
  vec3f force; // [esp+48h] [ebp-84h] BYREF
  vec3f *v97; // [esp+54h] [ebp-78h]
  float v98; // [esp+58h] [ebp-74h] BYREF
  float Px; // [esp+5Ch] [ebp-70h] BYREF
  float v100; // [esp+60h] [ebp-6Ch]
  float v101; // [esp+64h] [ebp-68h] BYREF
  float v102; // [esp+68h] [ebp-64h]
  float v103; // [esp+6Ch] [ebp-60h]
  float v104; // [esp+70h] [ebp-5Ch]
  int v105; // [esp+74h] [ebp-58h] BYREF
  float v106; // [esp+78h] [ebp-54h]
  float v107; // [esp+80h] [ebp-4Ch]
  float v108; // [esp+84h] [ebp-48h]
  float v109; // [esp+88h] [ebp-44h]
  float v110; // [esp+90h] [ebp-3Ch]
  float v111; // [esp+94h] [ebp-38h]
  float v112; // [esp+98h] [ebp-34h]
  float v113; // [esp+9Ch] [ebp-30h]
  float v114; // [esp+A0h] [ebp-2Ch]
  float v115; // [esp+A4h] [ebp-28h]
  int v116; // [esp+A8h] [ebp-24h]
  float v117; // [esp+ACh] [ebp-20h]
  float v118; // [esp+B0h] [ebp-1Ch]
  float v119; // [esp+B4h] [ebp-18h]
  float v120; // [esp+B8h] [ebp-14h]
  float out; // [esp+BCh] [ebp-10h] BYREF
  float v122; // [esp+C0h] [ebp-Ch]
  float v123; // [esp+C4h] [ebp-8h]

  v97 = (vec3f *)pos;
  Px = *(float *)&surfaceDef;
  if ( (dword_186F1BC & 1) == 0 )
  {
    perfCounter_36.name = "Tyre::addTyreForcesV10";
    dword_186F1BC |= 1u;
    perfCounter_36.group = Physics;
    perfCounter_36.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Tyre::addTyreForcesV10" | 0xFF000000;
  }
  v8 = (__m128)LODWORD(this->worldRotation.M31);
  v9 = (__m128)LODWORD(this->worldRotation.M32);
  v10 = this->worldRotation.M33;
  v102 = this->worldRotation.M11;
  v100 = this->worldRotation.M12;
  v103 = this->worldRotation.M13;
  LODWORD(v11) = LODWORD(v10) ^ _xmm;
  v12 = _mm_xor_ps(v8, (__m128)(unsigned int)_xmm);
  v13 = _mm_xor_ps(v9, (__m128)(unsigned int)_xmm);
  v14 = (float)((float)(v12.m128_f32[0] * normal->x) + (float)(v13.m128_f32[0] * normal->y)) + (float)(v11 * normal->z);
  v12.m128_f32[0] = v12.m128_f32[0] - (float)(v14 * normal->x);
  v13.m128_f32[0] = v13.m128_f32[0] - (float)(v14 * normal->y);
  v15 = v11 - (float)(v14 * normal->z);
  v12.m128_u64[0] = _mm_unpacklo_ps(v12, v13).m128_u64[0];
  v16 = (__m128)LODWORD(v102);
  *(_QWORD *)&this->roadHeading.x = v12.m128_u64[0];
  v17 = v16;
  v18 = (__m128)LODWORD(v100);
  v123 = v15;
  v19 = v100;
  this->roadHeading.z = v15;
  v20 = v18;
  v21 = (float)((float)(v16.m128_f32[0] * normal->x) + (float)(v19 * normal->y)) + (float)(v103 * normal->z);
  v17.m128_f32[0] = v16.m128_f32[0] - (float)(v21 * normal->x);
  v20.m128_f32[0] = v18.m128_f32[0] - (float)(v21 * normal->y);
  v22 = v103 - (float)(v21 * normal->z);
  *(_QWORD *)&this->roadRight.x = _mm_unpacklo_ps(v17, v20).m128_u64[0];
  v123 = v22;
  this->roadRight.z = v22;
  v23 = this->roadRight.y;
  v24 = this->roadRight.x;
  v25 = this->roadRight.z;
  v26 = fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v25 * v25));
  if ( v26 != 0.0 )
  {
    this->roadRight.x = (float)(1.0 / v26) * v24;
    this->roadRight.y = (float)(1.0 / v26) * v23;
    this->roadRight.z = (float)(1.0 / v26) * v25;
  }
  v27 = this->roadHeading.y;
  v28 = this->roadHeading.x;
  v29 = this->roadHeading.z;
  v30 = fsqrt((float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29));
  if ( v30 != 0.0 )
  {
    this->roadHeading.x = (float)(1.0 / v30) * v28;
    this->roadHeading.y = (float)(1.0 / v30) * v27;
    this->roadHeading.z = (float)(1.0 / v30) * v29;
  }
  ((void (*)(ISuspension *, int *, int))this->hub->getHubAngularVelocity)(this->hub, v95, a2);
  v31 = this->hub;
  v32 = v31->__vftable;
  v102 = (float)((float)((float)(*(float *)&v95[2] * v101) + (float)(*(float *)&v95[1] * v103)) + (float)(force.x * v104))
       + this->status.angularVelocity;
  v32->getPointVelocity(v31, (vec3f *)&v93, (const vec3f *)LODWORD(v98));
  vy = (float)((float)(this->roadRight.y * v94) + (float)(this->roadRight.x * v93))
     + (float)(this->roadRight.z * *(float *)v95);
  this->slidingVelocityY = vy;
  LODWORD(vx) = COERCE_UNSIGNED_INT(
                  (float)((float)(this->roadHeading.y * v94) + (float)(this->roadHeading.x * v93))
                + (float)(this->roadHeading.z * *(float *)v95)) ^ _xmm;
  this->roadVelocityX = vx;
  v34 = ksCalcSlipAngleRAD(vy, vx);
  v35 = this->status.effectiveRadius;
  v36 = this->roadVelocityX;
  v103 = v34;
  v37 = (float)(v35 * v102) - v36;
  LODWORD(v38) = LODWORD(v36) & _xmm;
  this->slidingVelocityX = v37;
  if ( v38 == 0.0 )
    v104 = 0.0;
  else
    v104 = v37 / v38;
  if ( this->externalInputs.isActive )
  {
    v39 = this->externalInputs.slipAngle;
    v104 = this->externalInputs.slipRatio;
  }
  else
  {
    v39 = v103;
  }
  v103 = v39;
  v40 = ksCalcCamberRAD(&this->contactNormal, &this->worldRotation);
  v41 = this->slidingVelocityY;
  v42 = this->status.load / this->modelData.Fz0;
  v102 = v40;
  this->status.camberRAD = v102;
  v43 = this->modelData.relaxationLength;
  v44 = this->status.ndSlip;
  v45 = (float)(this->roadVelocityX * this->roadVelocityX) + (float)(v41 * v41);
  Px = v41 * v41;
  v46 = fsqrt(v45);
  v101 = v46;
  this->totalHubVelocity = v46;
  v47 = (float)((float)((float)(v42 * v43) - v43) * 0.30000001) + v43;
  if ( v44 <= 1.0 )
  {
    if ( v44 < 0.0 )
      v44 = 0.0;
  }
  else
  {
    v44 = FLOAT_1_0;
  }
  v48 = (float)((float)(v43 - (float)(v47 * 2.0)) * v44) + (float)(v47 * 2.0);
  if ( v46 >= 1.0 )
  {
    v49 = v103;
  }
  else
  {
    v104 = this->slidingVelocityX * 0.5;
    if ( v104 <= 1.0 )
    {
      if ( v104 < -1.0 )
        v104 = FLOAT_N1_0;
    }
    else
    {
      v104 = FLOAT_1_0;
    }
    v49 = v41 * -5.5;
    if ( v49 <= 1.0 )
    {
      if ( v49 < -1.0 )
        v49 = FLOAT_N1_0;
    }
    else
    {
      v49 = FLOAT_1_0;
    }
  }
  v50 = v104 - this->status.slipRatio;
  if ( v48 == 0.0 )
    goto LABEL_33;
  v51 = (float)(v101 * a7) / v48;
  if ( v51 > 1.0 )
    goto LABEL_33;
  if ( v51 < 0.039999999 )
  {
    v52 = (float)(0.039999999 * v50) + this->status.slipRatio;
    goto LABEL_34;
  }
  if ( v51 >= 1.0 )
LABEL_33:
    v52 = v104;
  else
    v52 = (float)(v51 * v50) + this->status.slipRatio;
LABEL_34:
  v53 = this->status.slipAngleRAD;
  this->status.slipRatio = v52;
  v54 = v49 - v53;
  if ( v48 == 0.0 )
    goto LABEL_40;
  v55 = (float)(v101 * a7) / v48;
  if ( v55 > 1.0 )
    goto LABEL_40;
  if ( v55 < 0.039999999 )
  {
    v56 = (float)(0.039999999 * v54) + v53;
    goto LABEL_41;
  }
  if ( v55 >= 1.0 )
LABEL_40:
    v56 = v49;
  else
    v56 = (float)(v55 * v54) + v53;
LABEL_41:
  v57 = this->status.load;
  this->status.slipAngleRAD = v56;
  if ( v57 <= 0.0 )
  {
    this->status.slipRatio = 0.0;
    this->status.slipAngleRAD = 0.0;
  }
  v58 = this->car;
  v103 = 1.0;
  if ( v58 )
    v103 = v58->ksPhysics->track->dynamicGripLevel;
  v59 = this->slidingVelocityX * this->slidingVelocityX;
  v110 = v57;
  v104 = fsqrt(v59 + Px);
  v113 = v102;
  v111 = this->status.slipAngleRAD;
  v112 = this->status.slipRatio;
  v114 = v101;
  v60 = Tyre::getCorrectedD(this, 1.0, &this->status.wearMult);
  v61 = v60 * *(float *)(LODWORD(v100) + 136);
  vxa = this->status.depth;
  v62 = this->status.liveRadius;
  v116 = this->index;
  v115 = v61 * v103;
  v63 = ksCalcContactPatchLength(v62, vxa);
  v64 = this->status.grain;
  v65 = this->tyreModel;
  v117 = v63;
  v118 = v64;
  v66 = this->status.blister;
  v119 = v66;
  v120 = (float)(this->status.pressureDynamic / this->modelData.idealPressure) - 1.0;
  LOBYTE(out) = this->aiMult > 1.0;
  ((void (*)(ITyreModel *, int *))v65->solve)(v65, &v105);
  this->status.Dx = v109;
  this->status.Dy = v108;
  LODWORD(this->status.Fx) = v105 ^ _xmm;
  this->status.Fy = v104 * this->aiMult;
  Tyre::stepDirtyLevel(
    this,
    dt,
    COERCE_CONST_FLOAT(COERCE_UNSIGNED_INT(this->status.effectiveRadius * this->status.angularVelocity) & _xmm));
  TyreThermalModel::getIMO(&this->thermalModel, &out);
  v67 = this->car;
  if ( v67 )
  {
    if ( v67->ksPhysics->mechanicalDamageRate > 0.0 )
    {
      v68 = this->explosionTemperature;
      if ( out > v68 || v122 > v68 || v123 > v68 )
        this->status.inflation = 0.0;
    }
  }
  this->status.Mz = v106;
  v69 = this->status.Fx;
  v70 = this->roadHeading.x * v69;
  v71 = this->roadHeading.y * v69;
  v72 = this->roadHeading.z * v69;
  v73 = this->status.Fy;
  v74 = (float)(v73 * this->roadRight.x) + v70;
  v75 = (float)(this->roadRight.z * v73) + v72;
  force.y = (float)(this->roadRight.y * v73) + v71;
  force.x = v74;
  Px = v74;
  force.z = v75;
  if ( __fdtest(&Px) > 0 || (v98 = force.y, __fdtest(&v98) > 0) || (v101 = force.z, __fdtest(&v101) > 0) )
    _printf("TYRE GENERATED NAN FORCE\n");
  v76 = this->car;
  if ( v76 && v76->torqueModeEx )
  {
    Tyre::addTyreForceToHub(this, v97, &force);
  }
  else
  {
    this->hub->addForceAtPos(this->hub, &force, v97, this->driven, 1);
    LODWORD(this->localMX) = COERCE_UNSIGNED_INT(this->status.loadedRadius * this->status.Fx) ^ _xmm;
  }
  v77 = this->hub;
  out = normal->x * v106;
  v122 = normal->y * v106;
  v123 = normal->z * v106;
  v77->addTorque(v77, (const vec3f *)&out);
  v78 = FLOAT_1_0;
  LODWORD(v79) = LODWORD(this->status.angularVelocity) & _xmm;
  if ( v79 > 1.0 )
  {
    v80 = 0.0;
    v81 = this->status.effectiveRadius * this->status.angularVelocity;
    v82 = this->status.pressureDynamic;
    v83 = (float)((float)((float)(this->modelData.idealPressure / v82) - 1.0) * this->modelData.pressureRRGain) + 1.0;
    if ( v82 <= 0.0 )
      v83 = 0.0;
    if ( v81 <= 0.0 )
    {
      if ( v81 >= 0.0 )
        v84 = 0.0;
      else
        v84 = FLOAT_N1_0;
    }
    else
    {
      v84 = FLOAT_1_0;
    }
    v85 = (float)((float)((float)((float)(v81 * v81) * this->modelData.rr1) + this->modelData.rr0) * v84) * v83;
    if ( v79 > 20.0 )
    {
      if ( this->modelData.version < 2 )
      {
        LODWORD(v87) = LODWORD(this->status.slipRatio) & _xmm;
        if ( v87 <= 1.0 )
        {
          if ( v87 >= 0.0 )
            LODWORD(v80) = LODWORD(this->status.slipRatio) & _xmm;
        }
        else
        {
          v80 = FLOAT_1_0;
        }
        v85 = (float)((float)((float)((float)(v80 * (float)(this->modelData.rr_sr * v83))
                                    + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(this->status.slipAngleRAD * 57.29578) & _xmm)
                                            * (float)(this->modelData.rr_sa * v83)))
                            * 0.001)
                    + 1.0)
            * v85;
      }
      else
      {
        v86 = this->status.ndSlip;
        if ( v86 <= 1.0 )
        {
          if ( v86 >= 0.0 )
            v80 = this->status.ndSlip;
        }
        else
        {
          v80 = FLOAT_1_0;
        }
        v85 = (float)((float)((float)((float)(this->modelData.rr_slip * v80) * v83) * 0.001) + 1.0) * v85;
      }
    }
    LODWORD(this->status.rollingResistence) = COERCE_UNSIGNED_INT(
                                                (float)((float)(this->status.load * 0.001) * v85)
                                              * this->status.effectiveRadius) ^ _xmm;
  }
  v88 = this->car;
  if ( v88 )
  {
    if ( this->useLoadForVKM )
      v78 = this->status.load / this->modelData.Fz0;
    this->status.virtualKM = (float)((float)((float)(v103 * dt) * v88->ksPhysics->tyreConsumptionRate) * v78) * 0.001
                           + this->status.virtualKM;
  }
  v89 = SCTM::getStaticDY(&this->scTM, this->status.load);
  v90 = v107;
  this->status.D = v89;
  this->status.ndSlip = v90;
}
char Tyre::generateCompoundNames(Tyre *this)
{
  Tyre *v1; // edi
  int v2; // ecx
  int v3; // esi
  int v4; // ebx
  std::wstring *v5; // esi
  std::wstring *v6; // esi
  int v7; // ecx
  std::wstring *v8; // eax
  std::wstring *v9; // esi
  std::wstring *v10; // edi
  std::wstring *v11; // esi
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // edi
  std::wstring *v15; // esi
  std::wstring *v16; // ecx
  int v17; // edi
  int v18; // ecx
  unsigned int v19; // ebx
  Tyre *v20; // ebp
  int v21; // esi
  int v22; // edi
  std::wstring *v23; // ecx
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  int v26; // ecx
  std::wstring *v27; // edi
  std::wstring *v28; // esi
  std::vector<std::wstring> candidate; // [esp+14h] [ebp-88h] BYREF
  int v31; // [esp+20h] [ebp-7Ch]
  Tyre *v32; // [esp+24h] [ebp-78h]
  int _Val; // [esp+28h] [ebp-74h]
  std::wstring c; // [esp+2Ch] [ebp-70h] BYREF
  std::wstring result; // [esp+44h] [ebp-58h] BYREF
  std::wstring v36; // [esp+5Ch] [ebp-40h] BYREF
  std::wstring v37; // [esp+74h] [ebp-28h] BYREF
  int v38; // [esp+98h] [ebp-4h]

  v1 = this;
  v32 = this;
  candidate._Myfirst = 0;
  candidate._Mylast = 0;
  candidate._Myend = 0;
  v2 = (char *)this->compoundDefs._Mylast - (char *)this->compoundDefs._Myfirst;
  v38 = 0;
  _Val = 0;
  if ( v2 / 712 )
  {
    v3 = 0;
    v31 = 0;
    do
    {
      v4 = 1;
      while ( 1 )
      {
        c._Myres = 7;
        c._Mysize = 0;
        c._Bx._Buf[0] = 0;
        LOBYTE(v38) = 1;
        if ( v4 == 1 )
        {
          v5 = std::wstring::substr((std::wstring *)((char *)&v1->compoundDefs._Myfirst->name + v3), &result, 0, 1u);
          if ( &c != v5 )
          {
            if ( c._Myres >= 8 )
              operator delete(c._Bx._Ptr);
            c._Myres = 7;
            c._Mysize = 0;
            c._Bx._Buf[0] = 0;
            if ( v5->_Myres >= 8 )
            {
              c._Bx._Ptr = v5->_Bx._Ptr;
              v5->_Bx._Ptr = 0;
            }
            else if ( v5->_Mysize != -1 )
            {
              _memmove(&c, v5, 2 * (v5->_Mysize + 1));
            }
            c._Mysize = v5->_Mysize;
            c._Myres = v5->_Myres;
            v5->_Myres = 7;
            v5->_Mysize = 0;
            v5->_Bx._Buf[0] = 0;
          }
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
        }
        else
        {
          v6 = std::to_wstring(&v36, v4);
          v7 = (int)&v1->compoundDefs._Myfirst->name;
          LOBYTE(v38) = 2;
          v8 = std::wstring::substr((std::wstring *)(v31 + v7), &result, 0, 1u);
          LOBYTE(v38) = 3;
          v9 = std::operator+<wchar_t>(&v37, v8, v6);
          if ( &c != v9 )
          {
            if ( c._Myres >= 8 )
              operator delete(c._Bx._Ptr);
            c._Myres = 7;
            c._Mysize = 0;
            c._Bx._Buf[0] = 0;
            if ( v9->_Myres >= 8 )
            {
              c._Bx._Ptr = v9->_Bx._Ptr;
              v9->_Bx._Ptr = 0;
            }
            else if ( v9->_Mysize != -1 )
            {
              _memmove(&c, v9, 2 * (v9->_Mysize + 1));
            }
            c._Mysize = v9->_Mysize;
            c._Myres = v9->_Myres;
            v9->_Myres = 7;
            v9->_Mysize = 0;
            v9->_Bx._Buf[0] = 0;
          }
          if ( v37._Myres >= 8 )
            operator delete(v37._Bx._Ptr);
          v37._Myres = 7;
          v37._Mysize = 0;
          v37._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          LOBYTE(v38) = 1;
          if ( v36._Myres >= 8 )
            operator delete(v36._Bx._Ptr);
        }
        v10 = candidate._Mylast;
        v11 = candidate._Myfirst;
        if ( candidate._Myfirst == candidate._Mylast )
          break;
        do
        {
          v12 = &c;
          if ( c._Myres >= 8 )
            v12 = (std::wstring *)c._Bx._Ptr;
          if ( !std::wstring::compare(v11, 0, v11->_Mysize, v12->_Bx._Buf, c._Mysize) )
            break;
          ++v11;
        }
        while ( v11 != v10 );
        if ( v11 == v10 )
          break;
        if ( ++v4 == 10 )
        {
          v13 = std::to_wstring(&v36, _Val);
          v14 = v13;
          v15 = candidate._Mylast;
          LOBYTE(v38) = 4;
          if ( v13 >= candidate._Mylast || (v16 = candidate._Myfirst, candidate._Myfirst > v13) )
          {
            if ( candidate._Mylast == candidate._Myend )
            {
              std::vector<std::wstring>::_Reserve(&candidate, 1u);
              v15 = candidate._Mylast;
            }
          }
          else
          {
            v17 = v13 - candidate._Myfirst;
            if ( candidate._Mylast == candidate._Myend )
            {
              std::vector<std::wstring>::_Reserve(&candidate, 1u);
              v15 = candidate._Mylast;
              v16 = candidate._Myfirst;
            }
            v14 = &v16[v17];
          }
          if ( v15 )
          {
            v15->_Mysize = 0;
            v15->_Myres = 7;
            v15->_Mysize = 0;
            v15->_Bx._Buf[0] = 0;
            if ( v14->_Myres >= 8 )
            {
              v15->_Bx._Ptr = v14->_Bx._Ptr;
              v14->_Bx._Ptr = 0;
            }
            else if ( v14->_Mysize != -1 )
            {
              _memmove(v15, v14, 2 * (v14->_Mysize + 1));
            }
            v15->_Mysize = v14->_Mysize;
            v15->_Myres = v14->_Myres;
            v14->_Myres = 7;
            v14->_Mysize = 0;
            v14->_Bx._Buf[0] = 0;
            v15 = candidate._Mylast;
          }
          candidate._Mylast = v15 + 1;
          if ( v36._Myres >= 8 )
            operator delete(v36._Bx._Ptr);
        }
        v1 = v32;
        v3 = v31;
        if ( c._Myres >= 8 )
          operator delete(c._Bx._Ptr);
      }
      std::vector<std::wstring>::push_back(&candidate, &c);
      LOBYTE(v38) = 0;
      if ( c._Myres >= 8 )
        operator delete(c._Bx._Ptr);
      v1 = v32;
      v3 = v31 + 712;
      ++_Val;
      v18 = (char *)v32->compoundDefs._Mylast - (char *)v32->compoundDefs._Myfirst;
      v31 += 712;
    }
    while ( _Val < (unsigned int)(v18 / 712) );
  }
  v19 = 0;
  if ( v1->compoundDefs._Mylast - v1->compoundDefs._Myfirst )
  {
    v20 = v32;
    v21 = 0;
    v22 = 0;
    do
    {
      v23 = &v20->compoundDefs._Myfirst[v21].shortName;
      if ( v23 != &candidate._Myfirst[v22] )
        std::wstring::assign(v23, &candidate._Myfirst[v22], 0, 0xFFFFFFFF);
      v24 = std::operator+<wchar_t>(&v36, L" (", &v20->compoundDefs._Myfirst[v21].shortName);
      LOBYTE(v38) = 5;
      v25 = std::operator+<wchar_t>(&result, v24, L")");
      v26 = (int)&v20->compoundDefs._Myfirst->name;
      LOBYTE(v38) = 6;
      std::wstring::append((std::wstring *)(v21 * 712 + v26), v25, 0, 0xFFFFFFFF);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v38) = 0;
      if ( v36._Myres >= 8 )
        operator delete(v36._Bx._Ptr);
      ++v19;
      ++v22;
      ++v21;
    }
    while ( v19 < v20->compoundDefs._Mylast - v20->compoundDefs._Myfirst );
  }
  v38 = -1;
  if ( candidate._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&candidate);
    v27 = candidate._Mylast;
    v28 = candidate._Myfirst;
    if ( candidate._Myfirst != candidate._Mylast )
    {
      do
      {
        if ( v28->_Myres >= 8 )
          operator delete(v28->_Bx._Ptr);
        v28->_Myres = 7;
        v28->_Mysize = 0;
        v28->_Bx._Buf[0] = 0;
        ++v28;
      }
      while ( v28 != v27 );
      v28 = candidate._Myfirst;
    }
    operator delete(v28);
  }
  return 1;
}
double Tyre::getCamberedDy(Tyre *this, float camberRAD, float dy)
{
  Curve *v4; // ecx
  double result; // st7
  float v6; // xmm1_4
  float ref; // [esp+0h] [ebp-Ch]

  if ( Curve::getCount(&this->modelData.dCamberCurve) )
  {
    v4 = &this->modelData.dCamberCurve;
    ref = camberRAD * 57.29578;
    if ( this->modelData.useSmoothDCamberCurve )
      result = Curve::getCubicSplineValue(v4, ref) * dy;
    else
      result = Curve::getValue(v4, ref) * dy;
  }
  else
  {
    v6 = (float)(this->modelData.dcamber0 * camberRAD)
       - (float)((float)(camberRAD * camberRAD) * this->modelData.dcamber1);
    if ( v6 <= -1.0 )
      v6 = FLOAT_N0_89999998;
    result = (float)(dy / (float)(v6 + 1.0));
  }
  return result;
}
double Tyre::getCorrectedD(Tyre *this, float d, float *wear_mult)
{
  double result; // st7
  float camberRAD; // [esp+4h] [ebp-10h]
  float v6; // [esp+10h] [ebp-4h]
  float db; // [esp+18h] [ebp+4h]
  float da; // [esp+18h] [ebp+4h]

  db = TyreThermalModel::getCorrectedD(&this->thermalModel, d, this->status.camberRAD);
  da = db
     / (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(this->status.pressureDynamic - this->modelData.idealPressure) & _xmm)
                     * this->modelData.pressureGainD)
             + 1.0);
  if ( !Curve::getCount(&this->modelData.wearCurve) )
    return da;
  camberRAD = this->status.virtualKM;
  v6 = Curve::getValue(&this->modelData.wearCurve, camberRAD);
  result = (float)(v6 * da);
  if ( wear_mult )
    *wear_mult = v6;
  return result;
}
double Tyre::getDX(Tyre *this, float load)
{
  int v3; // ecx
  double v4; // xmm0_8
  double v5; // xmm1_8
  double result; // st7
  float v7; // xmm0_4
  double v8; // xmm2_8
  double v9; // xmm1_8
  float v10; // xmm0_4
  double v11; // xmm0_8
  double v12; // xmm1_8
  double v13; // [esp+Ch] [ebp-8h]
  float loada; // [esp+18h] [ebp+4h]

  if ( Curve::getCount(&this->modelData.dxLoadCurve) <= 0 )
  {
    v7 = 0.0;
    if ( this->modelData.lsExpX == 0.0 )
    {
      v11 = this->status.blister * 0.01;
      if ( v11 <= 1.0 )
      {
        v12 = 0.0;
        if ( v11 >= 0.0 )
          v12 = this->status.blister * 0.01;
      }
      else
      {
        v12 = DOUBLE_1_0;
      }
      loada = (float)((float)(this->modelData.Dx1 * (float)(load * 0.00050000002)) + this->modelData.Dx0)
            / (v12 * 0.2000000029802322 + 1.0);
      result = loada;
    }
    else
    {
      if ( load != 0.0 )
        v7 = (float)(__libm_sse2_powf(v3).m128_f32[0] * this->modelData.lsMultX) / load;
      v8 = this->status.blister * 0.01;
      if ( v8 <= 1.0 )
      {
        v9 = 0.0;
        if ( v8 >= 0.0 )
          v9 = this->status.blister * 0.01;
      }
      else
      {
        v9 = DOUBLE_1_0;
      }
      v10 = v7 / (v9 * 0.2000000029802322 + 1.0);
      result = v10;
    }
  }
  else
  {
    v4 = this->status.blister * 0.01;
    v5 = DOUBLE_1_0;
    if ( v4 > 1.0 || (v5 = 0.0, v4 < 0.0) )
      v13 = v5;
    else
      v13 = this->status.blister * 0.01;
    result = Curve::getCubicSplineValue(&this->modelData.dxLoadCurve, load) / (v13 * 0.2000000029802322 + 1.0);
  }
  return result;
}
double Tyre::getDY(Tyre *this, float load)
{
  double result; // st7
  int v4; // ecx
  double v5; // xmm0_8
  double v6; // xmm1_8
  float v7; // xmm0_4
  double v8; // xmm2_8
  float v9; // xmm0_4
  double v10; // xmm1_8
  float v11; // xmm0_4
  double v12; // xmm0_8
  double v13; // xmm1_8
  double v14; // [esp+Ch] [ebp-8h]
  float loada; // [esp+18h] [ebp+4h]

  if ( load <= 0.0 )
    return 0.0;
  if ( Curve::getCount(&this->modelData.dyLoadCurve) <= 0 )
  {
    if ( this->modelData.lsExpY == 0.0 )
    {
      v12 = this->status.blister * 0.01;
      if ( v12 <= 1.0 )
      {
        v13 = 0.0;
        if ( v12 >= 0.0 )
          v13 = this->status.blister * 0.01;
      }
      else
      {
        v13 = DOUBLE_1_0;
      }
      loada = (float)((float)(this->modelData.Dy1 * (float)(load * 0.00050000002)) + this->modelData.Dy0)
            / (v13 * 0.2000000029802322 + 1.0);
      result = loada;
    }
    else
    {
      v7 = __libm_sse2_powf(v4).m128_f32[0];
      v8 = this->status.blister * 0.01;
      v9 = (float)(v7 * this->modelData.lsMultY) / load;
      if ( v8 <= 1.0 )
      {
        v10 = 0.0;
        if ( v8 >= 0.0 )
          v10 = this->status.blister * 0.01;
      }
      else
      {
        v10 = DOUBLE_1_0;
      }
      v11 = v9 / (v10 * 0.2000000029802322 + 1.0);
      result = v11;
    }
  }
  else
  {
    v5 = this->status.blister * 0.01;
    v6 = DOUBLE_1_0;
    if ( v5 > 1.0 || (v6 = 0.0, v5 < 0.0) )
      v14 = v6;
    else
      v14 = this->status.blister * 0.01;
    result = Curve::getCubicSplineValue(&this->modelData.dyLoadCurve, load) / (v14 * 0.2000000029802322 + 1.0);
  }
  return result;
}
double Tyre::getDynamicK(Tyre *this)
{
  float v1; // xmm1_4
  double result; // st7

  v1 = (float)((float)(this->status.pressureDynamic - this->modelData.pressureRef) * this->modelData.pressureSpringGain)
     + this->data.k;
  if ( v1 >= 0.0 )
    result = v1;
  else
    result = 0.0;
  return result;
}
mat44f *Tyre::getFinalTyreRotation(Tyre *this, mat44f *result)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm2
  __int128 v9; // xmm3
  mat44f *v10; // eax
  DirectX::XMMATRIX M2; // [esp+10h] [ebp-40h] BYREF

  mat44f::mat44f(result);
  v3 = *(__m128 *)&this->worldRotation.M21;
  v4 = *(__m128 *)&this->worldRotation.M31;
  v5 = *(__m128 *)&this->worldRotation.M41;
  M2.r[0] = *(__m128 *)&this->worldRotation.M11;
  v6 = *(__m128 *)&this->localWheelRotation.M11;
  M2.r[1] = v3;
  v7 = *(_OWORD *)&this->localWheelRotation.M21;
  M2.r[2] = v4;
  v8 = *(_OWORD *)&this->localWheelRotation.M31;
  M2.r[3] = v5;
  v9 = *(_OWORD *)&this->localWheelRotation.M41;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2.r, v6);
  v10 = result;
  *(_OWORD *)&result->M21 = v7;
  *(_OWORD *)&result->M31 = v8;
  *(_OWORD *)&result->M41 = v9;
  return v10;
}
vec3f *Tyre::getWorldPosition(Tyre *this, vec3f *result)
{
  vec3f *v2; // eax
  __int64 v3; // xmm0_8
  float v4; // ecx

  v2 = result;
  v3 = *(_QWORD *)&this->worldPosition.x;
  v4 = this->worldPosition.z;
  *(_QWORD *)&result->x = v3;
  result->z = v4;
  return v2;
}
void Tyre::init(Tyre *this, ISuspension *ihub, IRayTrackCollisionProvider *rcp, std::wstring dataPath, int index, int carID, Car *car)
{
  Car *v8; // edx
  int v9; // edi
  Car *v10; // [esp+4h] [ebp-20h]

  v8 = car;
  v10 = car;
  this->tyreModel = &this->scTM;
  this->car = v8;
  TyreThermalModel::init(&this->thermalModel, 12, 3, v10);
  v9 = index;
  this->index = index;
  this->rayCaster = (IRayCaster *)((int (*)(IRayTrackCollisionProvider *, int))rcp->createRayCaster)(
                                    rcp,
                                    1077936128);
  this->rayCollisionProvider = rcp;
  this->hub = ihub;
  mat44f::loadIdentity(&this->localWheelRotation);
  this->oldAngularVelocity = 0.0;
  this->rSlidingVelocityX = 0.0;
  this->rSlidingVelocityY = 0.0;
  this->status.depth = 0.0;
  this->status.ndSlip = 0.0;
  this->status.load = 0.0;
  this->status.slipFactor = 0.0;
  this->surfaceDef = 0;
  this->status.Fy = 0.0;
  this->totalSlideVelocity = 0.0;
  this->totalHubVelocity = 0.0;
  this->slidingVelocityY = 0.0;
  this->slidingVelocityX = 0.0;
  this->roadVelocityX = 0.0;
  this->roadVelocityY = 0.0;
  this->debugOutput = 0;
  this->absOverride = 1.0;
  Tyre::initCompounds(this, &dataPath, v9);
  Tyre::setCompound(this, 0);
  ((void (__stdcall *)(_DWORD))this->shakeGenerator.step)((float)v9 * 0.5);
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void Tyre::initCompounds(Tyre *this, const std::wstring *dataPath, int index)
{
  Tyre *v3; // ebx
  TyreCompoundDef *v4; // esi
  Car *v5; // ecx
  std::wstring *v6; // esi
  bool v7; // al
  double v8; // st7
  bool v9; // cf
  bool v10; // al
  int v11; // eax
  bool v12; // al
  double v13; // st7
  double v14; // st7
  float v15; // xmm0_4
  TyreCompoundDef *v16; // edi
  std::wostream *v17; // eax
  const std::wstring *v18; // eax
  bool v19; // al
  bool v20; // al
  std::wstring *v21; // esi
  std::wstring *v22; // esi
  std::wstring *v23; // eax
  const std::wstring *v24; // eax
  std::wstring *v25; // eax
  float maxAngle; // xmm1_4
  float v27; // xmm2_4
  double v28; // st7
  char v29; // bl
  char v30; // bl
  int v31; // ecx
  int v32; // ecx
  float v33; // xmm0_4
  int v34; // ecx
  int v35; // ecx
  char v36; // bl
  const Curve *v37; // eax
  char v38; // al
  char v39; // bl
  const Curve *v40; // eax
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  double v48; // st7
  double v49; // st7
  double v50; // st7
  double v51; // st7
  double v52; // st7
  double v53; // st7
  double v54; // st7
  char v55; // al
  char v56; // bl
  const Curve *v57; // eax
  int v58; // eax
  int v59; // eax
  float v60; // xmm0_4
  double v61; // st7
  double v62; // st7
  double v63; // st7
  double v64; // st7
  double v65; // st7
  float v66; // xmm0_4
  double v67; // st7
  double v68; // st7
  double v69; // st7
  double v70; // st7
  double v71; // st7
  std::wstring *v72; // esi
  std::wostream *v73; // eax
  std::wostream *v74; // eax
  std::wstring *v75; // eax
  const std::wstring *v76; // edi
  double v77; // st7
  double v78; // st7
  double v79; // st7
  double v80; // st7
  double v81; // st7
  double v82; // st7
  char v83; // al
  char v84; // bl
  double v85; // st7
  double v86; // st7
  std::wstring *v87; // eax
  const std::wstring *v88; // eax
  const std::wstring *v89; // eax
  const std::wstring *v90; // eax
  int v91; // esi
  int v92; // esi
  int i; // esi
  int v94; // eax
  double v95; // st7
  double v96; // st7
  double v97; // st7
  double v98; // st7
  double v99; // st7
  float v100; // xmm1_4
  Car *v101; // ecx
  std::wstring *v102; // eax
  TyreCompoundDef *v103; // eax
  int v104; // eax
  TyreCompoundDef *v105; // esi
  Car *v106; // [esp+1Ch] [ebp-6E4h]
  double maxAngle_4; // [esp+24h] [ebp-6DCh]
  double maxAngle_4a; // [esp+24h] [ebp-6DCh]
  double maxAngle_4b; // [esp+24h] [ebp-6DCh]
  double maxAngle_4c; // [esp+24h] [ebp-6DCh]
  std::wstring *v111; // [esp+28h] [ebp-6D8h]
  bool v112; // [esp+47h] [ebp-6B9h]
  bool v113; // [esp+47h] [ebp-6B9h]
  bool v114; // [esp+47h] [ebp-6B9h]
  bool v115; // [esp+47h] [ebp-6B9h]
  float brushMax; // [esp+48h] [ebp-6B8h]
  float brushMaxa; // [esp+48h] [ebp-6B8h]
  float brushMaxb; // [esp+48h] [ebp-6B8h]
  float max_slip_gain; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gaina; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gainb; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gainc; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gaind; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gaine; // [esp+4Ch] [ebp-6B4h]
  float max_slip_gainf; // [esp+4Ch] [ebp-6B4h]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > _S6; // [esp+50h] [ebp-6B0h] BYREF
  float load; // [esp+54h] [ebp-6ACh]
  float ref_load; // [esp+58h] [ebp-6A8h]
  float max_slip; // [esp+5Ch] [ebp-6A4h] BYREF
  float maximum; // [esp+60h] [ebp-6A0h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > _S7; // [esp+64h] [ebp-69Ch] BYREF
  float temp_spread; // [esp+68h] [ebp-698h]
  Tyre *v133; // [esp+6Ch] [ebp-694h]
  std::wstring *_Left; // [esp+70h] [ebp-690h]
  std::vector<TyreCompoundDef> rejectedCompounds; // [esp+74h] [ebp-68Ch] BYREF
  int v136; // [esp+80h] [ebp-680h]
  std::wstring *_Str; // [esp+84h] [ebp-67Ch]
  std::pair<float,float> v; // [esp+88h] [ebp-678h] BYREF
  std::pair<float,float> v139; // [esp+90h] [ebp-670h] BYREF
  std::pair<float,float> p; // [esp+98h] [ebp-668h] BYREF
  BrushSlipProvider brush_provider; // [esp+A0h] [ebp-660h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v142; // [esp+D0h] [ebp-630h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ss2; // [esp+180h] [ebp-580h] BYREF
  TyreCompoundDef def; // [esp+230h] [ebp-4D0h] BYREF
  std::wstring result; // [esp+4F8h] [ebp-208h] BYREF
  std::wstring sec; // [esp+510h] [ebp-1F0h] BYREF
  std::wstring tcurve_filename; // [esp+528h] [ebp-1D8h] BYREF
  INIReader r; // [esp+540h] [ebp-1C0h] BYREF
  std::wstring tini; // [esp+584h] [ebp-17Ch] BYREF
  std::wstring v150; // [esp+59Ch] [ebp-164h] BYREF
  std::wstring v151; // [esp+5B4h] [ebp-14Ch] BYREF
  std::wstring wcfn; // [esp+5CCh] [ebp-134h] BYREF
  Curve v153; // [esp+5E4h] [ebp-11Ch] BYREF
  std::wstring names[4]; // [esp+630h] [ebp-D0h] BYREF
  std::wstring thermal_sections[4]; // [esp+690h] [ebp-70h] BYREF
  int v156; // [esp+6FCh] [ebp-4h]

  v3 = this;
  v133 = this;
  v4 = 0;
  _Left = (std::wstring *)dataPath;
  _S6._Ptr = 0;
  std::operator+<wchar_t>(&tini, dataPath, L"tyres.ini");
  v5 = v3->car;
  v156 = 0;
  if ( v5 )
  {
    v6 = Car::getConfigPath(v5, &result, &tini);
    if ( &tini != v6 )
    {
      if ( tini._Myres >= 8 )
        operator delete(tini._Bx._Ptr);
      tini._Myres = 7;
      tini._Mysize = 0;
      tini._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&tini, v6);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v4 = _S6._Ptr;
  }
  INIReader::INIReader(&r, &tini);
  LOBYTE(v156) = 1;
  _S7._Ptr = 0;
  names[0]._Myres = 7;
  names[0]._Mysize = 0;
  names[0]._Bx._Buf[0] = 0;
  std::wstring::assign(names, L"FRONT", 5u);
  LOBYTE(v156) = 2;
  names[1]._Myres = 7;
  names[1]._Mysize = 0;
  names[1]._Bx._Buf[0] = 0;
  std::wstring::assign(&names[1], L"FRONT", 5u);
  LOBYTE(v156) = 3;
  names[2]._Myres = 7;
  names[2]._Mysize = 0;
  names[2]._Bx._Buf[0] = 0;
  std::wstring::assign(&names[2], L"REAR", 4u);
  LOBYTE(v156) = 4;
  names[3]._Myres = 7;
  names[3]._Mysize = 0;
  names[3]._Bx._Buf[0] = 0;
  std::wstring::assign(&names[3], L"REAR", 4u);
  LOBYTE(v156) = 5;
  tcurve_filename._Myres = 7;
  tcurve_filename._Mysize = 0;
  tcurve_filename._Bx._Buf[0] = 0;
  std::wstring::assign(&tcurve_filename, L"VERSION", 7u);
  LOBYTE(v156) = 6;
  sec._Myres = 7;
  sec._Mysize = 0;
  sec._Bx._Buf[0] = 0;
  std::wstring::assign(&sec, L"HEADER", 6u);
  LOBYTE(v156) = 7;
  v136 = INIReader::getInt(&r, &sec, &tcurve_filename);
  if ( sec._Myres >= 8 )
    operator delete(sec._Bx._Ptr);
  sec._Myres = 7;
  sec._Mysize = 0;
  sec._Bx._Buf[0] = 0;
  if ( tcurve_filename._Myres >= 8 )
    operator delete(tcurve_filename._Bx._Ptr);
  rejectedCompounds._Myfirst = 0;
  rejectedCompounds._Mylast = 0;
  rejectedCompounds._Myend = 0;
  LOBYTE(v156) = 8;
  tcurve_filename._Myres = 7;
  tcurve_filename._Mysize = 0;
  tcurve_filename._Bx._Buf[0] = 0;
  std::wstring::assign(&tcurve_filename, L"EXPLOSION", 9u);
  LOBYTE(v156) = 9;
  v7 = INIReader::hasSection(&r, &tcurve_filename);
  v112 = v7;
  LOBYTE(v156) = 8;
  if ( tcurve_filename._Myres >= 8 )
  {
    operator delete(tcurve_filename._Bx._Ptr);
    v7 = v112;
  }
  if ( v7 )
  {
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    std::wstring::assign(&tcurve_filename, L"TEMPERATURE", 0xBu);
    LOBYTE(v156) = 10;
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    std::wstring::assign(&sec, L"EXPLOSION", 9u);
    LOBYTE(v156) = 11;
    v8 = INIReader::getFloat(&r, &sec, &tcurve_filename);
    v9 = sec._Myres < 8;
    v3->explosionTemperature = v8;
    if ( !v9 )
      operator delete(sec._Bx._Ptr);
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    LOBYTE(v156) = 8;
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
  }
  tcurve_filename._Myres = 7;
  tcurve_filename._Mysize = 0;
  tcurve_filename._Bx._Buf[0] = 0;
  std::wstring::assign(&tcurve_filename, L"VIRTUALKM", 9u);
  LOBYTE(v156) = 12;
  v10 = INIReader::hasSection(&r, &tcurve_filename);
  v113 = v10;
  LOBYTE(v156) = 8;
  if ( tcurve_filename._Myres >= 8 )
  {
    operator delete(tcurve_filename._Bx._Ptr);
    v10 = v113;
  }
  if ( v10 )
  {
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    std::wstring::assign(&tcurve_filename, L"USE_LOAD", 8u);
    LOBYTE(v156) = 13;
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    std::wstring::assign(&sec, L"VIRTUALKM", 9u);
    LOBYTE(v156) = 14;
    v11 = INIReader::getInt(&r, &sec, &tcurve_filename);
    v9 = sec._Myres < 8;
    v3->useLoadForVKM = v11 != 0;
    if ( !v9 )
      operator delete(sec._Bx._Ptr);
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    LOBYTE(v156) = 8;
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
  }
  tcurve_filename._Myres = 7;
  tcurve_filename._Mysize = 0;
  tcurve_filename._Bx._Buf[0] = 0;
  std::wstring::assign(&tcurve_filename, L"ADDITIONAL1", 0xBu);
  LOBYTE(v156) = 15;
  v12 = INIReader::hasSection(&r, &tcurve_filename);
  v114 = v12;
  LOBYTE(v156) = 8;
  if ( tcurve_filename._Myres >= 8 )
  {
    operator delete(tcurve_filename._Bx._Ptr);
    v12 = v114;
  }
  if ( v12 )
  {
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    std::wstring::assign(&tcurve_filename, L"BLANKETS_TEMP", 0xDu);
    LOBYTE(v156) = 16;
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    std::wstring::assign(&sec, L"ADDITIONAL1", 0xBu);
    LOBYTE(v156) = 17;
    v13 = INIReader::getFloat(&r, &sec, &tcurve_filename);
    v9 = sec._Myres < 8;
    v3->blanketTemperature = v13;
    if ( !v9 )
      operator delete(sec._Bx._Ptr);
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    LOBYTE(v156) = 8;
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
    sec._Myres = 7;
    sec._Mysize = 0;
    sec._Bx._Buf[0] = 0;
    std::wstring::assign(&sec, L"PRESSURE_TEMPERATURE_GAIN", 0x19u);
    LOBYTE(v156) = 18;
    std::wstring::wstring(&tcurve_filename, L"ADDITIONAL1");
    LOBYTE(v156) = 19;
    v14 = INIReader::getFloat(&r, &tcurve_filename, &sec);
    v9 = tcurve_filename._Myres < 8;
    v3->pressureTemperatureGain = v14;
    if ( !v9 )
      operator delete(tcurve_filename._Bx._Ptr);
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    LOBYTE(v156) = 8;
    if ( sec._Myres >= 8 )
      operator delete(sec._Bx._Ptr);
    std::wstring::wstring(&sec, L"CAMBER_TEMP_SPREAD_K");
    LOBYTE(v156) = 20;
    std::wstring::wstring(&tcurve_filename, L"ADDITIONAL1");
    LOBYTE(v156) = 21;
    temp_spread = INIReader::getFloat(&r, &tcurve_filename, &sec);
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    LOBYTE(v156) = 8;
    if ( sec._Myres >= 8 )
      operator delete(sec._Bx._Ptr);
    v15 = temp_spread;
    if ( temp_spread != 0.0 )
    {
      v3->thermalModel.camberSpreadK = temp_spread;
      _printf("Using custom thermal spread: %f\n", v15);
    }
  }
  v16 = 0;
  LODWORD(temp_spread) = 24 * index;
  _Str = &names[index];
  while ( 1 )
  {
    *(_DWORD *)v142.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v142.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v142.gap68);
    LOBYTE(v156) = 22;
    _S6._Ptr = (TyreCompoundDef *)((unsigned int)v4 | 1);
    std::wiostream::basic_iostream<wchar_t>(&v142, &v142.gap10[8], 0);
    v156 = 23;
    *(_DWORD *)&v142.gap0[*(_DWORD *)(*(_DWORD *)v142.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&brush_provider.maxSlip + *(_DWORD *)(*(_DWORD *)v142.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v142.gap0 + 4)
                                                                                         - 104;
    std::wstreambuf::wstreambuf(&v142.gap10[8]);
    *(_DWORD *)&v142.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v142.gap10[64] = 0;
    *(_DWORD *)&v142.gap10[68] = 0;
    LOBYTE(v156) = 25;
    std::operator<<<wchar_t>((std::wostream *)v142.gap10, _Str);
    if ( (int)v16 > 0 )
    {
      v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v142.gap10, "_");
      std::wostream::operator<<(v17, v16);
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v142, &sec);
    LOBYTE(v156) = 26;
    v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v142, &result);
    LOBYTE(v156) = 27;
    v19 = INIReader::hasSection(&r, v18);
    LOBYTE(v156) = 26;
    v20 = !v19;
    v115 = v20;
    if ( result._Myres >= 8 )
    {
      operator delete(result._Bx._Ptr);
      v20 = v115;
    }
    if ( v20 )
      break;
    TyreCompoundDef::TyreCompoundDef(&def);
    LOBYTE(v156) = 28;
    std::wstring::wstring(&result, L"VERSION");
    LOBYTE(v156) = 29;
    std::wstring::wstring(&tcurve_filename, L"HEADER");
    LOBYTE(v156) = 30;
    def.modelData.version = INIReader::getInt(&r, &tcurve_filename, &result);
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    def.index = v3->compoundDefs._Mylast - v3->compoundDefs._Myfirst;
    std::wstring::wstring(&result, L"NAME");
    LOBYTE(v156) = 31;
    v21 = INIReader::getString(&r, &tcurve_filename, &sec, &result);
    if ( &def.name != v21 )
    {
      if ( def.name._Myres >= 8 )
        operator delete(def.name._Bx._Ptr);
      def.name._Myres = 7;
      def.name._Mysize = 0;
      def.name._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&def.name, v21);
    }
    if ( tcurve_filename._Myres >= 8 )
      operator delete(tcurve_filename._Bx._Ptr);
    tcurve_filename._Myres = 7;
    tcurve_filename._Mysize = 0;
    tcurve_filename._Bx._Buf[0] = 0;
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( def.modelData.version >= 4 )
    {
      std::wstring::wstring(&result, L"SHORT_NAME");
      LOBYTE(v156) = 32;
      v22 = INIReader::getString(&r, &tcurve_filename, &sec, &result);
      if ( &def.shortName != v22 )
      {
        if ( def.shortName._Myres >= 8 )
          operator delete(def.shortName._Bx._Ptr);
        def.shortName._Myres = 7;
        def.shortName._Mysize = 0;
        def.shortName._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&def.shortName, v22);
      }
      if ( tcurve_filename._Myres >= 8 )
        operator delete(tcurve_filename._Bx._Ptr);
      tcurve_filename._Myres = 7;
      tcurve_filename._Mysize = 0;
      tcurve_filename._Bx._Buf[0] = 0;
      LOBYTE(v156) = 28;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v23 = std::operator+<wchar_t>(&result, L" (", &def.shortName);
      LOBYTE(v156) = 33;
      v24 = std::operator+<wchar_t>(&tcurve_filename, v23, L")");
      LOBYTE(v156) = 34;
      std::wstring::append(&def.name, v24, 0, 0xFFFFFFFF);
      if ( tcurve_filename._Myres >= 8 )
        operator delete(tcurve_filename._Bx._Ptr);
      tcurve_filename._Myres = 7;
      tcurve_filename._Mysize = 0;
      tcurve_filename._Bx._Buf[0] = 0;
      LOBYTE(v156) = 28;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    v25 = &def.name;
    if ( def.name._Myres >= 8 )
      v25 = (std::wstring *)def.name._Bx._Ptr;
    _printf("LOADING TYRE COMPOUND %S\n", v25->_Bx._Buf);
    std::wstring::wstring(&result, L"WIDTH");
    LOBYTE(v156) = 35;
    def.data.width = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( def.data.width <= 0.0 )
      def.data.width = 0.15000001;
    std::wstring::wstring(&result, L"RADIUS");
    LOBYTE(v156) = 36;
    def.data.radius = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( def.modelData.version < 3 )
    {
      def.data.rimRadius = 0.13;
    }
    else
    {
      std::wstring::wstring(&result, L"RIM_RADIUS");
      LOBYTE(v156) = 37;
      def.data.rimRadius = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 28;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    std::wstring::wstring(&result, L"FLEX");
    LOBYTE(v156) = 38;
    def.modelData.flexK = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FRICTION_LIMIT_ANGLE");
    LOBYTE(v156) = 39;
    brushMax = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"XMU");
    LOBYTE(v156) = 40;
    ref_load = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 28;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    maxAngle = brushMax;
    if ( brushMax == 0.0 )
      maxAngle = FLOAT_7_5;
    if ( def.modelData.version < 5 )
    {
      v27 = ref_load;
    }
    else
    {
      v27 = 0.0;
      ref_load = 0.0;
    }
    BrushSlipProvider::BrushSlipProvider(&brush_provider, maxAngle, v27, def.modelData.flexK);
    LOBYTE(v156) = 41;
    if ( def.modelData.version >= 10 )
    {
      std::wstring::wstring(&result, L"CX_MULT");
      LOBYTE(v156) = 42;
      def.modelData.cfXmult = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"RADIUS_ANGULAR_K");
      LOBYTE(v156) = 43;
      v28 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.data.radiusRaiseK = v28 * 0.001;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"BRAKE_DX_MOD");
      LOBYTE(v156) = 44;
      v29 = INIReader::hasKey(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v29 )
      {
        std::wstring::wstring(&result, L"BRAKE_DX_MOD");
        LOBYTE(v156) = 45;
        def.modelData.brakeDXMod = INIReader::getFloat(&r, &sec, &result);
        LOBYTE(v156) = 41;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        if ( def.modelData.brakeDXMod == 0.0 )
          def.modelData.brakeDXMod = 1.0;
        else
          def.modelData.brakeDXMod = def.modelData.brakeDXMod + 1.0;
      }
      std::wstring::wstring(&result, L"COMBINED_FACTOR");
      LOBYTE(v156) = 46;
      v30 = INIReader::hasKey(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v30 )
      {
        std::wstring::wstring(&result, L"COMBINED_FACTOR");
        LOBYTE(v156) = 47;
        def.modelData.combinedFactor = INIReader::getFloat(&r, &sec, &result);
        LOBYTE(v156) = 41;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        _printf("Using Stereo's combined factor: %f\n", def.modelData.combinedFactor);
      }
    }
    if ( def.modelData.version < 5 )
    {
      std::wstring::wstring(&result, L"DY0");
      LOBYTE(v156) = 60;
      v41 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.Dy0 = v41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"DY1");
      LOBYTE(v156) = 61;
      v42 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.Dy1 = v42;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"DX0");
      LOBYTE(v156) = 62;
      v43 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.Dx0 = v43;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"DX1");
      LOBYTE(v156) = 63;
      v44 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.Dx1 = v44;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      brush_provider.asy = 0.85000002;
      brush_provider.brushModel.data.xu = ref_load;
    }
    else
    {
      std::wstring::wstring(&result, L"FZ0");
      LOBYTE(v156) = 48;
      ref_load = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"LS_EXPX");
      LOBYTE(v156) = 49;
      def.modelData.lsExpX = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"LS_EXPY");
      LOBYTE(v156) = 50;
      def.modelData.lsExpY = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"DX_REF");
      LOBYTE(v156) = 51;
      def.modelData.Dx0 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"DY_REF");
      LOBYTE(v156) = 52;
      def.modelData.Dy0 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      load = ref_load;
      max_slip_gain = def.modelData.Dx0 * ref_load;
      def.modelData.lsMultX = max_slip_gain / __libm_sse2_powf(v31).m128_f32[0];
      max_slip_gaina = def.modelData.Dy0 * ref_load;
      v33 = __libm_sse2_powf(v32).m128_f32[0];
      brush_provider.asy = 0.92000002;
      def.modelData.lsMultY = max_slip_gaina / v33;
      brush_provider.brushModel.data.Fz0 = ref_load;
      std::wstring::wstring(&result, L"FLEX_GAIN");
      LOBYTE(v156) = 53;
      INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LODWORD(brush_provider.brushModel.data.maxSlip0) = __libm_sse2_tanf(v34).m128_u32[0];
      LODWORD(brush_provider.brushModel.data.maxSlip1) = __libm_sse2_tanf(v35).m128_u32[0];
      brush_provider.version = 5;
      std::wstring::wstring(&result, L"DY_CURVE");
      LOBYTE(v156) = 54;
      v36 = INIReader::hasKey(&r, &sec, &result);
      LOBYTE(v156) = 41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v36 )
      {
        std::wstring::wstring(&result, L"DY_CURVE");
        LOBYTE(v156) = 55;
        v37 = INIReader::getCurve(&r, &v153, &sec, &result);
        LOBYTE(v156) = 56;
        Curve::operator=(&def.modelData.dyLoadCurve, v37);
        LOBYTE(v156) = 55;
        Curve::~Curve(&v153);
        LOBYTE(v156) = 41;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      }
      std::wstring::wstring(&result, L"DX_CURVE");
      LOBYTE(v156) = 57;
      v38 = INIReader::hasKey(&r, &sec, &result);
      LOBYTE(v156) = 41;
      v39 = v38;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      if ( v39 )
      {
        std::wstring::wstring(&result, L"DX_CURVE");
        LOBYTE(v156) = 58;
        v40 = INIReader::getCurve(&r, &v153, &sec, &result);
        LOBYTE(v156) = 59;
        Curve::operator=(&def.modelData.dxLoadCurve, v40);
        LOBYTE(v156) = 58;
        Curve::~Curve(&v153);
        LOBYTE(v156) = 41;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      }
      BrushSlipProvider::calcMaximum(&brush_provider, load * 0.5, &maximum, &max_slip);
      maxAngle_4 = Tyre::loadSensExpD(def.modelData.lsExpY, def.modelData.lsMultY, load * 0.5);
      max_slip_gainb = atan();
      _printf(
        "TEST MAX, LOAD:%.1f %.2f @ %.2f D:%.2f\n",
        (float)(load * 0.5),
        maximum,
        (float)(max_slip_gainb * 57.29578),
        maxAngle_4);
      BrushSlipProvider::calcMaximum(&brush_provider, load, &maximum, &max_slip);
      maxAngle_4a = Tyre::loadSensExpD(def.modelData.lsExpY, def.modelData.lsMultY, load);
      max_slip_gainc = atan();
      _printf(
        "TEST MAX, LOAD:%.1f %.2f @ %.2f D:%.2f\n",
        load,
        maximum,
        (float)(max_slip_gainc * 57.29578),
        maxAngle_4a);
      BrushSlipProvider::calcMaximum(&brush_provider, load * 2.0, &maximum, &max_slip);
      maxAngle_4b = Tyre::loadSensExpD(def.modelData.lsExpY, def.modelData.lsMultY, load * 2.0);
      max_slip_gaind = atan();
      _printf(
        "TEST MAX, LOAD:%.1f %.2f @ %.2f D:%.2f\n",
        (float)(load * 2.0),
        maximum,
        (float)(max_slip_gaind * 57.29578),
        maxAngle_4b);
      load = load * 4.0;
      BrushSlipProvider::calcMaximum(&brush_provider, load, &maximum, &max_slip);
      maxAngle_4c = Tyre::loadSensExpD(def.modelData.lsExpY, def.modelData.lsMultY, load);
      max_slip_gaine = atan();
      _printf(
        "TEST MAX, LOAD:%.1f %.2f @ %.2f D:%.2f\n",
        load,
        maximum,
        (float)(max_slip_gaine * 57.29578),
        maxAngle_4c);
    }
    BrushSlipProvider::recomputeMaximum(&brush_provider);
    if ( def.modelData.version >= 7 )
    {
      std::wstring::wstring(&result, L"FALLOFF_LEVEL");
      LOBYTE(v156) = 64;
      v45 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      brush_provider.asy = v45;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"FALLOFF_SPEED");
      LOBYTE(v156) = 65;
      v46 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      brush_provider.brushModel.data.falloffSpeed = v46;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    }
    BrushSlipProvider::operator=(&def.slipProvider, &brush_provider);
    std::wstring::wstring(&result, L"SPEED_SENSITIVITY");
    LOBYTE(v156) = 66;
    v47 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.speedSensitivity = v47;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"RELAXATION_LENGTH");
    LOBYTE(v156) = 67;
    v48 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.relaxationLength = v48;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"ROLLING_RESISTANCE_0");
    LOBYTE(v156) = 68;
    v49 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.rr0 = v49;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"ROLLING_RESISTANCE_1");
    LOBYTE(v156) = 69;
    v50 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.rr1 = v50;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.version == 1 )
    {
      std::wstring::wstring(&result, L"ROLLING_RESISTANCE_SA");
      LOBYTE(v156) = 70;
      v51 = INIReader::getFloat(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.rr_sa = v51;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"ROLLING_RESISTANCE_SR");
      LOBYTE(v156) = 71;
      def.modelData.rr_sr = INIReader::getFloat(&r, &sec, &result);
    }
    else
    {
      std::wstring::wstring(&result, L"ROLLING_RESISTANCE_SLIP");
      LOBYTE(v156) = 72;
      def.modelData.rr_slip = INIReader::getFloat(&r, &sec, &result);
    }
    LOBYTE(v156) = 41;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"CAMBER_GAIN");
    LOBYTE(v156) = 73;
    v52 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.camberGain = v52;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"DCAMBER_0");
    LOBYTE(v156) = 74;
    v53 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.dcamber0 = v53;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"DCAMBER_1");
    LOBYTE(v156) = 75;
    v54 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.dcamber1 = v54;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.dcamber0 == 0.0 || def.modelData.dcamber1 == 0.0 )
    {
      def.modelData.dcamber0 = 0.1;
      def.modelData.dcamber1 = -0.80000001;
    }
    std::wstring::wstring(&result, L"DCAMBER_LUT");
    LOBYTE(v156) = 76;
    v55 = INIReader::hasKey(&r, &sec, &result);
    LOBYTE(v156) = 41;
    v56 = v55;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( v56 )
    {
      _printf("Using camber LUT\n");
      std::wstring::wstring(&result, L"DCAMBER_LUT");
      LOBYTE(v156) = 77;
      v57 = INIReader::getCurve(&r, &v153, &sec, &result);
      LOBYTE(v156) = 78;
      Curve::operator=(&def.modelData.dCamberCurve, v57);
      LOBYTE(v156) = 77;
      Curve::~Curve(&v153);
      LOBYTE(v156) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"DCAMBER_LUT_SMOOTH");
      LOBYTE(v156) = 79;
      v58 = INIReader::getInt(&r, &sec, &result);
      LOBYTE(v156) = 41;
      def.modelData.useSmoothDCamberCurve = v58 != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      if ( def.modelData.useSmoothDCamberCurve )
      {
        v59 = Curve::getCount(&def.modelData.dCamberCurve);
        _printf("SMOOTH %d\n\n", v59);
        v60 = FLOAT_N20_0;
        brushMaxa = FLOAT_N20_0;
        do
        {
          v61 = Curve::getCubicSplineValue(&def.modelData.dCamberCurve, v60);
          _printf("%f: %f\n", brushMaxa, v61);
          v60 = brushMaxa + 0.5;
          brushMaxa = brushMaxa + 0.5;
        }
        while ( brushMaxa <= 20.0 );
      }
    }
    std::wstring::wstring(&result, L"ANGULAR_INERTIA");
    LOBYTE(v156) = 80;
    v62 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.data.angularInertia = v62;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"DAMP");
    LOBYTE(v156) = 81;
    v63 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.data.d = v63;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"RATE");
    LOBYTE(v156) = 82;
    v64 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.data.k = v64;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.data.angularInertia == 0.0 )
      def.data.angularInertia = 1.2;
    if ( def.data.d == 0.0 )
      def.data.d = 400.0;
    if ( def.data.k == 0.0 )
      def.data.k = 220000.0;
    if ( def.modelData.Dx0 == 0.0 )
      def.modelData.Dx0 = def.modelData.Dy0 * 1.2;
    if ( def.modelData.Dx1 == 0.0 )
      def.modelData.Dx1 = def.modelData.Dy1 * 0.1;
    std::wstring::wstring(&result, L"PRESSURE_STATIC");
    LOBYTE(v156) = 83;
    v65 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.pressureStatic = v65;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v66 = def.pressureStatic;
    if ( def.pressureStatic == 0.0 )
    {
      v66 = FLOAT_26_0;
      def.pressureStatic = FLOAT_26_0;
    }
    v3 = v133;
    def.modelData.pressureRef = v66;
    v133->status.pressureDynamic = v66;
    std::wstring::wstring(&result, L"PRESSURE_SPRING_GAIN");
    LOBYTE(v156) = 84;
    v67 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.pressureSpringGain = v67;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.pressureSpringGain == 0.0 )
      def.modelData.pressureSpringGain = 1000.0;
    std::wstring::wstring(&result, L"PRESSURE_FLEX_GAIN");
    LOBYTE(v156) = 85;
    v68 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.pressureFlexGain = v68;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.pressureFlexGain == 0.0 )
      def.modelData.pressureFlexGain = 0.0;
    std::wstring::wstring(&result, L"PRESSURE_RR_GAIN");
    LOBYTE(v156) = 86;
    v69 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.pressureRRGain = v69;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.pressureRRGain == 0.0 )
      v3->modelData.pressureRRGain = 0.0;
    std::wstring::wstring(&result, L"PRESSURE_D_GAIN");
    LOBYTE(v156) = 87;
    v70 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.pressureGainD = v70;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&result, L"PRESSURE_IDEAL");
    LOBYTE(v156) = 88;
    v71 = INIReader::getFloat(&r, &sec, &result);
    LOBYTE(v156) = 41;
    def.modelData.idealPressure = v71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( def.modelData.idealPressure == 0.0 )
      def.modelData.idealPressure = 26.0;
    std::wstring::wstring(thermal_sections, L"THERMAL_FRONT");
    LOBYTE(v156) = 89;
    std::wstring::wstring(&thermal_sections[1], L"THERMAL_FRONT");
    LOBYTE(v156) = 90;
    std::wstring::wstring(&thermal_sections[2], L"THERMAL_REAR");
    LOBYTE(v156) = 91;
    std::wstring::wstring(&thermal_sections[3], L"THERMAL_REAR");
    LOBYTE(v156) = 92;
    if ( (int)v16 > 0 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &ss2,
        3,
        1);
      LOBYTE(v156) = 93;
      v72 = (std::wstring *)((char *)thermal_sections + LODWORD(temp_spread));
      v73 = std::operator<<<wchar_t>(
              (std::wostream *)ss2.gap10,
              (std::wstring *)((char *)thermal_sections + LODWORD(temp_spread)));
      v74 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v73, "_");
      std::wostream::operator<<(v74, v16);
      v75 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ss2, &result);
      std::wstring::operator=(v72, v75);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v156) = 92;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ss2);
    }
    v76 = (std::wstring *)((char *)thermal_sections + LODWORD(temp_spread));
    if ( INIReader::hasSection(&r, (std::wstring *)((char *)thermal_sections + LODWORD(temp_spread))) )
    {
      std::wstring::wstring(&result, L"SURFACE_TRANSFER");
      LOBYTE(v156) = 94;
      v77 = INIReader::getFloat(&r, v76, &result);
      LOBYTE(v156) = 92;
      def.thermalPatchData.surfaceTransfer = v77;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"PATCH_TRANSFER");
      LOBYTE(v156) = 95;
      v78 = INIReader::getFloat(&r, v76, &result);
      LOBYTE(v156) = 92;
      def.thermalPatchData.patchTransfer = v78;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"CORE_TRANSFER");
      LOBYTE(v156) = 96;
      v79 = INIReader::getFloat(&r, v76, &result);
      LOBYTE(v156) = 92;
      def.thermalPatchData.patchCoreTransfer = v79;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"FRICTION_K");
      LOBYTE(v156) = 97;
      v80 = INIReader::getFloat(&r, v76, &result);
      LOBYTE(v156) = 92;
      def.data.thermalFrictionK = v80;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::wstring(&result, L"ROLLING_K");
      LOBYTE(v156) = 98;
      v81 = INIReader::getFloat(&r, v76, &result);
      LOBYTE(v156) = 92;
      def.data.thermalRollingK = v81;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      if ( def.modelData.version >= 5 )
      {
        std::wstring::wstring(&result, L"INTERNAL_CORE_TRANSFER");
        LOBYTE(v156) = 99;
        v82 = INIReader::getFloat(&r, v76, &result);
        LOBYTE(v156) = 92;
        def.thermalPatchData.internalCoreTransfer = v82;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        std::wstring::wstring(&result, L"COOL_FACTOR");
        LOBYTE(v156) = 100;
        v83 = INIReader::hasKey(&r, v76, &result);
        LOBYTE(v156) = 92;
        v84 = v83;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        if ( v84 )
        {
          std::wstring::wstring(&result, L"COOL_FACTOR");
          LOBYTE(v156) = 101;
          v85 = INIReader::getFloat(&r, v76, &result);
          LOBYTE(v156) = 92;
          max_slip_gainf = v85;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          def.thermalPatchData.coolFactorGain = (float)(max_slip_gainf - 1.0) * 0.00032399999;
          _printf("COOL FACTOR FINAL:%f\n", def.thermalPatchData.coolFactorGain);
        }
        v3 = v133;
      }
      if ( def.modelData.version >= 6 )
      {
        std::wstring::wstring(&result, L"SURFACE_ROLLING_K");
        LOBYTE(v156) = 102;
        v86 = INIReader::getFloat(&r, v76, &result);
        LOBYTE(v156) = 92;
        def.data.thermalRollingSurfaceK = v86;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      }
      std::wstring::wstring(&result, L"PERFORMANCE_CURVE");
      LOBYTE(v156) = 103;
      v87 = INIReader::getString(&r, &v151, v76, &result);
      LOBYTE(v156) = 104;
      std::operator+<wchar_t>(&tcurve_filename, _Left, v87);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v151);
      LOBYTE(v156) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      v88 = getConfigPath(&v150, &tcurve_filename, v3->car);
      LOBYTE(v156) = 108;
      Curve::load(&def.thermalPerformanceCurve, v88);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v150);
      LOBYTE(v156) = 92;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tcurve_filename);
    }
    std::wstring::wstring(&result, L"WEAR_CURVE");
    LOBYTE(v156) = 109;
    INIReader::getString(&r, &wcfn, &sec, &result);
    LOBYTE(v156) = 111;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v89 = std::operator+<wchar_t>(&v151, _Left, &wcfn);
    v106 = v3->car;
    LOBYTE(v156) = 112;
    v90 = getConfigPath(&v150, v89, v106);
    LOBYTE(v156) = 113;
    Curve::load(&def.modelData.wearCurve, v90);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v150);
    LOBYTE(v156) = 111;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v151);
    Curve::scale(&def.modelData.wearCurve, 0.0099999998);
    v91 = 0;
    if ( Curve::getCount(&def.thermalPerformanceCurve) > 0 )
    {
      while ( 1 )
      {
        Curve::getPairAtIndex(&def.thermalPerformanceCurve, &p, v91);
        if ( p.second >= 1.0 )
          break;
        if ( ++v91 >= Curve::getCount(&def.thermalPerformanceCurve) )
          goto LABEL_185;
      }
      def.data.grainThreshold = p.first;
    }
LABEL_185:
    v92 = Curve::getCount(&def.thermalPerformanceCurve) - 1;
    if ( v92 > 0 )
    {
      while ( 1 )
      {
        Curve::getPairAtIndex(&def.thermalPerformanceCurve, &v139, v92);
        if ( v139.second >= 1.0 )
          break;
        if ( --v92 <= 0 )
          goto LABEL_190;
      }
      def.data.blisterThreshold = v139.first;
      def.data.optimumTemp = v139.first;
    }
LABEL_190:
    def.modelData.maxWearMult = 100.0;
    for ( i = 0; i < Curve::getCount(&def.modelData.wearCurve); ++i )
    {
      Curve::getPairAtIndex(&def.modelData.wearCurve, &v, i);
      if ( def.modelData.maxWearMult > v.second )
        *(std::pair<float,float> *)&def.modelData.maxWearKM = v;
    }
    _printf("MAX WEAR AT: %f vKM , mult %f\n", def.modelData.maxWearKM, def.modelData.maxWearMult);
    v94 = def.modelData.version;
    if ( def.modelData.version >= 3 )
    {
      std::wstring::wstring(&tcurve_filename, L"BLISTER_GAMMA");
      LOBYTE(v156) = 114;
      v95 = INIReader::getFloat(&r, v76, &tcurve_filename);
      LOBYTE(v156) = 111;
      def.data.blisterGamma = v95;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tcurve_filename);
      std::wstring::wstring(&tcurve_filename, L"BLISTER_GAIN");
      LOBYTE(v156) = 115;
      v96 = INIReader::getFloat(&r, v76, &tcurve_filename);
      LOBYTE(v156) = 111;
      def.data.blisterGain = v96;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tcurve_filename);
      std::wstring::wstring(&tcurve_filename, L"GRAIN_GAMMA");
      LOBYTE(v156) = 116;
      v97 = INIReader::getFloat(&r, v76, &tcurve_filename);
      LOBYTE(v156) = 111;
      def.data.grainGamma = v97;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tcurve_filename);
      std::wstring::wstring(&tcurve_filename, L"GRAIN_GAIN");
      LOBYTE(v156) = 117;
      v98 = INIReader::getFloat(&r, v76, &tcurve_filename);
      LOBYTE(v156) = 111;
      def.data.grainGain = v98;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tcurve_filename);
      v94 = def.modelData.version;
    }
    if ( v94 < 5 )
      v99 = Tyre::loadSensLinearD(def.modelData.Dy0, def.modelData.Dy1, 3000.0);
    else
      v99 = Tyre::loadSensExpD(def.modelData.lsExpY, def.modelData.lsMultY, 3000.0);
    brushMaxb = v99;
    v100 = brushMaxb - 1.0;
    if ( (float)(brushMaxb - 1.0) < 0.0 )
      v100 = 0.0;
    def.data.softnessIndex = v100;
    _printf("SOFTNESS INDEX: %f\n", v100);
    v101 = v3->car;
    if ( !v101 || PhysicsEngine::isTyreLegal(v101->ksPhysics, &def.shortName) )
    {
      std::vector<TyreCompoundDef>::push_back(&v3->compoundDefs, &def);
      v103 = std::vector<TyreCompoundDef>::back(&v3->compoundDefs);
      v104 = Curve::getCount(&v103->modelData.dCamberCurve);
      _printf("cback: %d\n", v104);
    }
    else
    {
      v111 = std::wstring::c_str(&def.shortName);
      v102 = std::wstring::c_str(&def.name);
      _printf("TYRE COMPOUND %S [%S] rejected because it is not legal in this race\n", v102->_Bx._Buf, v111->_Bx._Buf);
      std::vector<TyreCompoundDef>::push_back(&rejectedCompounds, &def);
    }
    v16 = ++_S7._Ptr;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&wcfn);
    LOBYTE(v156) = 41;
    `eh vector destructor iterator'(thermal_sections, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
    LOBYTE(v156) = 28;
    BrushSlipProvider::~BrushSlipProvider(&brush_provider);
    LOBYTE(v156) = 26;
    TyreCompoundDef::~TyreCompoundDef(&def);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&sec);
    LOBYTE(v156) = 8;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v142);
    v4 = _S6._Ptr;
  }
  if ( sec._Myres >= 8 )
    operator delete(sec._Bx._Ptr);
  sec._Myres = 7;
  sec._Mysize = 0;
  sec._Bx._Buf[0] = 0;
  LOBYTE(v156) = 8;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v142);
  if ( std::vector<Turbo>::empty(&v3->compoundDefs) )
  {
    _printf(
      "ERROR: Every compound has been discarded because not legal. This is a mistake, reenabling all the compounds to avoid crashes\n");
    std::vector<SetupTab *>::begin(&rejectedCompounds, &_S6);
    std::vector<Mesh *>::end(&rejectedCompounds, &_S7);
    while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(&_S6, &_S7) )
    {
      v105 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(&_S6);
      v105->index = std::vector<TyreCompoundDef>::size(&v3->compoundDefs);
      std::vector<TyreCompoundDef>::push_back(&v3->compoundDefs, v105);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator++(&_S6);
    }
  }
  if ( v136 < 4 )
    Tyre::generateCompoundNames(v3);
  std::vector<TyreCompoundDef>::~vector<TyreCompoundDef>(&rejectedCompounds);
  LOBYTE(v156) = 1;
  `eh vector destructor iterator'(names, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v156) = 0;
  INIReader::~INIReader(&r);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tini);
}
double __cdecl Tyre::loadSensExpD(const float exp, const float mult, const float load)
{
  int v3; // ecx
  double result; // st7

  if ( load == 0.0 )
    result = 0.0;
  else
    result = (float)((float)(__libm_sse2_powf(v3).m128_f32[0] * mult) / load);
  return result;
}
double __cdecl Tyre::loadSensLinearD(const float d0, const float d1, const float load)
{
  return (float)((float)((float)(load * 0.00050000002) * d1) + d0);
}
void Tyre::rayCast(Tyre *this, const vec3f *org, const vec3f *dir, RayCastResult *res)
{
  IRayCaster *v4; // edx
  const __m128i *v5; // eax
  __m128i v6; // xmm1
  __int64 v7; // xmm0_8
  float v8; // eax
  ICollisionObject *v9; // esi
  ICollisionObject *v10; // ecx
  SurfaceDef *v11; // eax
  RayCastHit hit; // [esp+Ch] [ebp-40h]
  RayCastHit v13; // [esp+2Ch] [ebp-20h] BYREF

  v4 = this->rayCaster;
  if ( v4 )
  {
    v5 = (const __m128i *)v4->rayCast(v4, &v13, org, dir);
    v6 = _mm_loadu_si128(v5);
    *(__m128i *)&hit.normal.y = _mm_loadu_si128(v5 + 1);
    LODWORD(hit.normal.x) = v6.m128i_i32[3];
    if ( (unsigned __int8)_mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&hit.normal.y, 12)) )
    {
      v7 = *(_QWORD *)&hit.normal.x;
      v8 = hit.normal.z;
      v9 = hit.collisionObject;
      v10 = hit.collisionObject;
      *(_QWORD *)&res->pos.x = v6.m128i_i64[0];
      *(_QWORD *)&res->normal.x = v7;
      LODWORD(res->pos.z) = _mm_cvtsi128_si32(_mm_srli_si128(v6, 8));
      res->normal.z = v8;
      v11 = (SurfaceDef *)v10->getUserPointer(v10);
      res->collisionObject = v9;
      res->surfaceDef = v11;
      res->hasHit = 1;
    }
    else
    {
      res->hasHit = 0;
    }
  }
  else
  {
    ((void (*)(IRayTrackCollisionProvider *, const vec3f *, const vec3f *, RayCastResult *, int))this->rayCollisionProvider->rayCast)(
      this->rayCollisionProvider,
      org,
      dir,
      res,
      0x40000000);
  }
}
void Tyre::reset(Tyre *this)
{
  long double v2; // xmm0_8
  ISuspension *v3; // ecx
  const __m128i *v4; // eax
  float v5; // eax
  mat44f v6; // [esp+10h] [ebp-40h] BYREF

  v2 = this->status.grain;
  v3 = this->hub;
  *(float *)&v2 = v2;
  this->status.angularVelocity = 0.0;
  this->status.isLocked = 1;
  this->status.slipRatio = 0.0;
  this->status.slipAngleRAD = 0.0;
  this->status.Fx = 0.0;
  this->status.flatSpot = 0.0;
  this->status.lastGrain = *(float *)&v2;
  *(float *)&v2 = this->status.blister;
  this->status.Fy = 0.0;
  this->status.Mz = 0.0;
  this->rSlidingVelocityX = 0.0;
  this->rSlidingVelocityY = 0.0;
  this->status.inflation = 1.0;
  *(_OWORD *)&this->status.grain = 0i64;
  this->status.lastBlister = *(float *)&v2;
  v4 = (const __m128i *)v3->getHubWorldMatrix(v3, &v6);
  *(__m128i *)&this->worldRotation.M11 = _mm_loadu_si128(v4);
  *(__m128i *)&this->worldRotation.M21 = _mm_loadu_si128(v4 + 1);
  *(__m128i *)&this->worldRotation.M31 = _mm_loadu_si128(v4 + 2);
  *(__m128i *)&this->worldRotation.M41 = _mm_loadu_si128(v4 + 3);
  v5 = this->worldRotation.M43;
  *(_QWORD *)&this->worldPosition.x = _mm_unpacklo_ps(
                                        (__m128)LODWORD(this->worldRotation.M41),
                                        (__m128)LODWORD(this->worldRotation.M42)).m128_u64[0];
  this->worldPosition.z = v5;
  this->worldRotation.M41 = 0.0;
  this->worldRotation.M42 = 0.0;
  this->worldRotation.M43 = 0.0;
  if ( this->status.virtualKM > 0.001000000047497451 )
    TyreThermalModel::getIMO(&this->thermalModel, this->status.lastTempIMO);
  this->status.dirtyLevel = 0.0;
  this->status.virtualKM = 0.0;
  this->status.feedbackTorque = 0.0;
  this->absOverride = 1.0;
  TyreThermalModel::reset(&this->thermalModel);
  this->tyreBlanketsOn = 1;
}
char Tyre::setCompound(Tyre *this, int cindex)
{
  TyreCompoundDef *v3; // esi
  Car *v4; // ecx
  float v5; // xmm0_4
  OnGearRequestEvent message; // [esp+Ch] [ebp-8h] BYREF

  if ( cindex < 0 || cindex >= (unsigned int)(this->compoundDefs._Mylast - this->compoundDefs._Myfirst) )
    return 0;
  v3 = &this->compoundDefs._Myfirst[cindex];
  TyreModelData::operator=(&this->modelData, &v3->modelData);
  *(__m128i *)&this->data.width = _mm_loadu_si128((const __m128i *)&v3->data);
  *(__m128i *)&this->data.angularInertia = _mm_loadu_si128((const __m128i *)&v3->data.angularInertia);
  *(__m128i *)&this->data.grainThreshold = _mm_loadu_si128((const __m128i *)&v3->data.grainThreshold);
  *(__m128i *)&this->data.grainGain = _mm_loadu_si128((const __m128i *)&v3->data.grainGain);
  *(_QWORD *)&this->data.softnessIndex = *(_QWORD *)&v3->data.softnessIndex;
  *(__m128i *)&this->thermalModel.patchData.surfaceTransfer = _mm_loadu_si128((const __m128i *)&v3->thermalPatchData);
  this->thermalModel.patchData.coolFactorGain = v3->thermalPatchData.coolFactorGain;
  Curve::operator=(&this->thermalModel.performanceCurve, &v3->thermalPerformanceCurve);
  *(__m128i *)&this->slipProvider.brushModel.data.CF = _mm_loadu_si128((const __m128i *)&v3->slipProvider.brushModel);
  *(_QWORD *)&this->slipProvider.brushModel.data.maxSlip0 = *(_QWORD *)&v3->slipProvider.brushModel.data.maxSlip0;
  this->slipProvider.brushModel.data.falloffSpeed = v3->slipProvider.brushModel.data.falloffSpeed;
  this->slipProvider.asy = v3->slipProvider.asy;
  this->slipProvider.version = v3->slipProvider.version;
  this->slipProvider.maximum = v3->slipProvider.maximum;
  this->slipProvider.maxSlip = v3->slipProvider.maxSlip;
  this->currentCompoundIndex = cindex;
  this->status.pressureStatic = v3->pressureStatic;
  this->status.pressureDynamic = v3->pressureStatic;
  this->status.dirtyLevel = 0.0;
  this->status.virtualKM = 0.0;
  TyreThermalModel::reset(&this->thermalModel);
  Tyre::reset(this);
  v4 = this->car;
  if ( v4 )
  {
    message.request = this->index;
    message.nextGear = cindex;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v4->evOnTyreCompoundChanged, &message);
  }
  this->scTM.falloffSpeed = this->slipProvider.brushModel.data.falloffSpeed;
  v5 = this->slipProvider.asy;
  this->scTM.Fz0 = this->slipProvider.brushModel.data.Fz0;
  this->scTM.lsExpX = this->modelData.lsExpX;
  this->scTM.lsExpY = this->modelData.lsExpY;
  this->scTM.lsMultX = this->modelData.lsMultX;
  this->scTM.lsMultY = this->modelData.lsMultY;
  this->scTM.maxSlip0 = this->slipProvider.brushModel.data.maxSlip0;
  this->scTM.maxSlip1 = this->slipProvider.brushModel.data.maxSlip1;
  this->scTM.speedSensitivity = this->modelData.speedSensitivity;
  this->scTM.camberGain = this->modelData.camberGain;
  this->scTM.dcamber0 = this->modelData.dcamber0;
  this->scTM.dcamber1 = this->modelData.dcamber1;
  this->modelData.asy = v5;
  this->scTM.asy = v5;
  Curve::operator=(&this->scTM.dyLoadCurve, &this->modelData.dyLoadCurve);
  Curve::operator=(&this->scTM.dxLoadCurve, &this->modelData.dxLoadCurve);
  this->scTM.pressureCfGain = this->modelData.pressureFlexGain;
  this->scTM.cfXmult = this->modelData.cfXmult;
  this->scTM.brakeDXMod = this->modelData.brakeDXMod;
  Curve::operator=(&this->scTM.dCamberCurve, &this->modelData.dCamberCurve);
  this->scTM.useSmoothDCamberCurve = this->modelData.useSmoothDCamberCurve;
  this->scTM.combinedFactor = this->modelData.combinedFactor;
  return 1;
}
void __userpurge Tyre::step(Tyre *this@<ecx>, float a2@<edi>, float dt)
{
  Tyre *v3; // esi
  ISuspension *v4; // ecx
  const __m128i *v5; // eax
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  float v8; // eax
  void (*v9)(const char *const, ...); // edi
  Car *v10; // eax
  ISuspension *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  SurfaceDef *v19; // ecx
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  float v22; // xmm7_4
  __m128 v23; // xmm3
  float v24; // xmm6_4
  float v25; // xmm4_4
  float v26; // eax
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm2_4
  int v33; // edi
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  __m128 v37; // xmm1
  __int64 v38; // xmm0_8
  float v39; // eax
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  int v52; // edi
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // eax
  SurfaceDef *v57; // eax
  float v58; // xmm1_4
  Car *v59; // eax
  IRigidBody *v60; // ecx
  float *v61; // eax
  IRigidBody *v62; // ecx
  double v63; // st7
  Car *v64; // eax
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  bool v73; // cc
  float v74; // xmm3_4
  float v75; // xmm4_4
  float v76; // xmm1_4
  std::_Func_base<void> *v77; // ecx
  const vec3f *v78; // [esp+Ch] [ebp-BCh]
  int v80; // [esp+20h] [ebp-A8h]
  mat44f v81; // [esp+24h] [ebp-A4h] BYREF
  vec3f result; // [esp+64h] [ebp-64h] BYREF
  SurfaceDef *v83; // [esp+70h] [ebp-58h] BYREF
  _BYTE v84[20]; // [esp+74h] [ebp-54h] BYREF
  float normal_8; // [esp+88h] [ebp-40h]
  char v86; // [esp+8Ch] [ebp-3Ch]
  int org; // [esp+90h] [ebp-38h]
  vec3f org_4; // [esp+94h] [ebp-34h] BYREF
  float v89; // [esp+A0h] [ebp-28h]
  float v90; // [esp+A4h] [ebp-24h]
  float Px; // [esp+A8h] [ebp-20h] BYREF
  vec3f v; // [esp+ACh] [ebp-1Ch] BYREF
  vec3f v93; // [esp+B8h] [ebp-10h] BYREF

  v3 = this;
  v89 = *(float *)&this;
  if ( (dword_186F19C & 1) == 0 )
  {
    perfCounter_34.name = "Tyre::step";
    dword_186F19C |= 1u;
    perfCounter_34.group = Physics;
    perfCounter_34.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Tyre::step" | 0xFF000000;
  }
  v4 = this->hub;
  v3->status.feedbackTorque = 0.0;
  v3->status.Fx = 0.0;
  v3->status.Mz = 0.0;
  v3->status.slipFactor = 0.0;
  v3->status.rollingResistence = 0.0;
  v3->slidingVelocityX = 0.0;
  v3->slidingVelocityY = 0.0;
  v3->totalSlideVelocity = 0.0;
  v3->totalHubVelocity = 0.0;
  v3->surfaceDef = 0;
  v5 = (const __m128i *)v4->getHubWorldMatrix(v4, &v81);
  *(__m128i *)&v3->worldRotation.M11 = _mm_loadu_si128(v5);
  *(__m128i *)&v3->worldRotation.M21 = _mm_loadu_si128(v5 + 1);
  *(__m128i *)&v3->worldRotation.M31 = _mm_loadu_si128(v5 + 2);
  *(__m128i *)&v3->worldRotation.M41 = _mm_loadu_si128(v5 + 3);
  v6 = (__m128)LODWORD(v3->worldRotation.M41);
  v7 = (__m128)LODWORD(v3->worldRotation.M42);
  v.z = v3->worldRotation.M43;
  v8 = v.z;
  *(_QWORD *)&v3->worldPosition.x = _mm_unpacklo_ps(v6, v7).m128_u64[0];
  v3->worldPosition.z = v8;
  v3->worldRotation.M41 = 0.0;
  v3->worldRotation.M42 = 0.0;
  v3->worldRotation.M43 = 0.0;
  Px = v3->status.angularVelocity;
  v9 = (void (*)(const char *const, ...))_printf;
  if ( __fdtest(&Px) > 0 )
  {
    _printf("TYRE ANG VELOCITY IS NAN!\n");
    v3->status.angularVelocity = 0.0;
  }
  if ( !v3->status.isLocked )
  {
    v10 = v3->car;
    if ( v10 )
    {
      if ( v10->torqueModeEx == reactionTorques )
      {
        v11 = v3->hub;
        v12 = (float)(v3->inputs.electricTorque + v3->inputs.brakeTorque) + v3->inputs.handBrakeTorque;
        v13 = v3->worldRotation.M12 * v12;
        v14 = v3->worldRotation.M13 * v12;
        v93.x = v3->worldRotation.M11 * v12;
        v93.y = v13;
        v93.z = v14;
        v11->addTorque(v11, &v93);
      }
    }
  }
  v15 = FLOAT_N1_0;
  if ( v3->rayCollisionProvider )
  {
    *(_OWORD *)v84 = 0i64;
    org_4.x = v3->worldPosition.x;
    v16 = v3->worldPosition.y + 2.0;
    *(_DWORD *)&v84[16] = 0;
    normal_8 = 0.0;
    org_4.y = v16;
    v17 = v3->worldPosition.z;
    v83 = 0;
    v86 = 0;
    org = 0;
    v93.x = 0.0;
    v93.y = -1.0;
    v93.z = 0.0;
    org_4.z = v17;
    Tyre::rayCast(v3, &org_4, &v93, (RayCastResult *)&v83);
    if ( v86 && v3->worldRotation.M22 > 0.34999999 )
    {
      v18 = *(float *)&v84[8];
      v19 = v83;
      v20 = (__m128)*(unsigned int *)&v84[4];
      v21 = (__m128)*(unsigned int *)v84;
      v22 = *(float *)&v84[4];
      v23 = (__m128)*(unsigned int *)&v84[12];
      v24 = *(float *)v84;
      v25 = *(float *)&v84[16];
      v26 = *(float *)&v84[8];
      v27 = normal_8;
      v3->surfaceDef = v83;
      v28 = v18 - v3->worldPosition.z;
      v29 = v24 - v3->worldPosition.x;
      v30 = v22 - v3->worldPosition.y;
      v21.m128_u64[0] = _mm_unpacklo_ps(v21, v20).m128_u64[0];
      *(_QWORD *)&v3->unmodifiedContactPoint.x = v21.m128_u64[0];
      Px = v28;
      v3->unmodifiedContactPoint.z = v26;
      v20.m128_f32[0] = v23.m128_f32[0] * v3->worldRotation.M21;
      v31 = v25 * v3->worldRotation.M22;
      *(_QWORD *)&v93.y = v21.m128_u64[0];
      *(_QWORD *)v84 = v21.m128_u64[0];
      *(_QWORD *)&org_4.y = v23.m128_u64[0];
      v32 = (float)(v31 + v20.m128_f32[0]) + (float)(v27 * v3->worldRotation.M23);
      if ( v32 <= 0.95999998 )
      {
        if ( v32 <= -1.0 || v32 >= 1.0 )
        {
          v40 = 0.0;
        }
        else
        {
          v40 = v25;
          __libm_sse2_acosf();
        }
        v90 = v40;
        LODWORD(v41) = __libm_sse2_acosf().m128_u32[0];
        v42 = v3->worldRotation.M22;
        v43 = v3->worldRotation.M23;
        v44 = v3->worldRotation.M21;
        Px = v41;
        v.x = (float)(v43 * *(float *)&v84[16]) - (float)(v42 * normal_8);
        v45 = *(float *)_mm_loadl_epi64((const __m128i *)&org_4.y).m128i_i32;
        v.y = (float)(v44 * normal_8) - (float)(v43 * v45);
        v.z = (float)(v42 * v45) - (float)(v44 * *(float *)&v84[16]);
        normalize(&result, &v);
        mat44f::createFromAxisAngle((int)v3, &v81, &result);
        v46 = *(float *)_mm_loadl_epi64((const __m128i *)&org_4.y).m128i_i32;
        v33 = (int)&v3->contactPoint;
        v47 = (__m128)LODWORD(v81.M11);
        v48 = (__m128)LODWORD(v81.M12);
        v19 = v83;
        v47.m128_f32[0] = (float)((float)((float)(v81.M11 * v46) + (float)(v81.M21 * *(float *)&v84[16]))
                                + (float)(v81.M31 * normal_8))
                        + v81.M41;
        v48.m128_f32[0] = (float)((float)((float)(v81.M12 * v46) + (float)(v81.M22 * *(float *)&v84[16]))
                                + (float)(v81.M32 * normal_8))
                        + v81.M42;
        v49 = (float)((float)(v81.M13 * v46) + (float)(v81.M23 * *(float *)&v84[16])) + (float)(v81.M33 * normal_8);
        *(_QWORD *)&org_4.y = _mm_unpacklo_ps(v47, v48).m128_u64[0];
        *(_QWORD *)&v84[12] = *(_QWORD *)&org_4.y;
        *(_QWORD *)&v3->contactPoint.x = *(_QWORD *)&v93.y;
        result.z = v49 + v81.M43;
        normal_8 = v49 + v81.M43;
        v39 = *(float *)&v84[8];
      }
      else
      {
        v33 = (int)&v3->contactPoint;
        v34 = (float)((float)(v25 * v30) + (float)(v23.m128_f32[0] * v29)) + (float)(v27 * Px);
        v35 = v27 * v34;
        v23.m128_f32[0] = (float)(v23.m128_f32[0] * v34) + v3->worldPosition.x;
        v36 = v25 * v34;
        v37 = (__m128)LODWORD(v3->worldPosition.y);
        v37.m128_f32[0] = v37.m128_f32[0] + v36;
        v.z = v3->worldPosition.z + v35;
        v38 = *(_QWORD *)&v84[12];
        v39 = v.z;
        *(_QWORD *)&v3->contactPoint.x = _mm_unpacklo_ps(v23, v37).m128_u64[0];
        *(_QWORD *)&org_4.y = v38;
      }
      *(float *)(v33 + 8) = v39;
      v90 = *(float *)&v33;
      if ( v19 && v19->sinHeight != 0.0 )
      {
        LODWORD(Px) = __libm_sse2_cosf(LODWORD(a2), v80).m128_u32[0];
        v50 = __libm_sse2_sinf().m128_f32[0];
        v19 = v83;
        v3->contactPoint.y = v3->contactPoint.y - (float)((float)((float)(Px * v50) + 1.0) * v83->sinHeight);
      }
      if ( v19->granularity != 0.0 )
      {
        v51 = v3->contactPoint.y;
        v52 = 0;
        v93.x = 1.0;
        v93.y = 5.8000002;
        v93.z = 11.4;
        v.x = 0.0049999999;
        v.y = 0.0049999999;
        v.z = 0.0099999998;
        Px = v51;
        do
        {
          LODWORD(v90) = __libm_sse2_sinf().m128_u32[0];
          v53 = __libm_sse2_cosf(LODWORD(a2), v80).m128_f32[0];
          v54 = (float)((float)(v90 * v53) + 1.0) * *(float *)((char *)&v.x + v52);
          v52 += 4;
          v55 = Px - (float)(v54 * 0.60000002);
          Px = v55;
        }
        while ( v52 < 12 );
        v3 = (Tyre *)LODWORD(v89);
        *(float *)(LODWORD(v89) + 796) = v55;
      }
      v56 = normal_8;
      *(_QWORD *)&v3->contactNormal.x = *(_QWORD *)&org_4.y;
      v3->contactNormal.z = v56;
      Tyre::addGroundContact(v3, &v3->contactPoint, (const vec3f *)&v84[12]);
      v78 = &v3->contactPoint;
      if ( v3->modelData.version < 10 )
        Tyre::addTyreForces(v3, v78, (const vec3f *)&v84[12], v83, dt);
      else
        Tyre::addTyreForcesV10(v3, (int)&v3->contactPoint, v78, (const vec3f *)&v84[12], v83, dt, a2);
      v57 = v3->surfaceDef;
      if ( v57 )
      {
        v58 = v57->damping;
        if ( v58 > 0.0 )
        {
          v59 = v3->car;
          v.x = 0.0;
          v.y = 0.0;
          v.z = 0.0;
          v60 = v59->body;
          LODWORD(v89) = LODWORD(v58) ^ _xmm;
          v61 = (float *)v60->getVelocity(v60, &result);
          Px = *v61 * v89;
          v90 = v61[1] * v89;
          v62 = v3->car->body;
          org_4.z = v61[2] * v89;
          v63 = ((double (*)(IRigidBody *))v62->getMass)(v62);
          v64 = v3->car;
          v89 = v63;
          v93.x = Px * v89;
          v93.y = v90 * v89;
          v93.z = org_4.z * v89;
          v64->body->addForceAtLocalPos(v64->body, &v93, &v);
        }
      }
      v9 = (void (*)(const char *const, ...))_printf;
    }
    else
    {
      v3->status.ndSlip = 0.0;
      v3->status.Fy = 0.0;
    }
    v15 = FLOAT_N1_0;
  }
  else
  {
    v3->status.Fy = 0.0;
    v3->status.ndSlip = 0.0;
  }
  v65 = v3->inputs.brakeTorque * v3->absOverride;
  if ( v65 <= v3->inputs.handBrakeTorque )
    v65 = v3->inputs.handBrakeTorque;
  v66 = v3->status.angularVelocity;
  if ( v3->modelData.version < 10 )
  {
    if ( v66 <= 0.0 )
    {
      if ( v66 >= 0.0 )
        v15 = 0.0;
    }
    else
    {
      v15 = FLOAT_1_0;
    }
    v67 = (float)((float)(v3->status.loadedRadius * v3->status.Fx) - (float)(v15 * v65)) + v3->status.rollingResistence;
  }
  else
  {
    if ( v66 <= 0.0 )
    {
      if ( v66 >= 0.0 )
        v15 = 0.0;
    }
    else
    {
      v15 = FLOAT_1_0;
    }
    v67 = v3->status.rollingResistence - (float)((float)(v15 * v65) + v3->localMX);
  }
  v68 = v67 + v3->inputs.electricTorque;
  v3->status.feedbackTorque = v68;
  org_4.z = v68;
  if ( __fdtest(&org_4.z) > 0 )
  {
    v9("NaN feedbackTorque\n");
    v9("status.Fx=%f\n", v3->status.Fx);
    v9("data.radius:%f\n", v3->data.radius);
    v9("status.loadedRadius:%f\n", v3->status.loadedRadius);
    v9("inputs.brakeTorque:%f\n", v3->inputs.brakeTorque);
    v9("status.angularVelocity:%f\n", v3->status.angularVelocity);
    v9("absOverride:%f\n", v3->absOverride);
    v9("rolling:%f\n", v3->status.rollingResistence);
    v9("inputs.handBrakeTorque:%f\n", v3->inputs.handBrakeTorque);
    v9("inputs.electricTorque%f\n", v3->inputs.electricTorque);
  }
  if ( !v3->driven )
  {
    Tyre::updateAngularSpeed(v3, dt);
    Tyre::stepRotationMatrix(v3, dt);
    goto LABEL_69;
  }
  if ( v3->status.isLocked )
  {
    v69 = v3->inputs.brakeTorque * v3->absOverride;
    v3->status.isLocked = 0;
    org_4.z = v69;
    org_4.z = v3->inputs.handBrakeTorque;
  }
  v70 = v3->oldAngularVelocity;
  if ( v70 > 0.0 )
  {
    v71 = FLOAT_1_0;
    v72 = FLOAT_1_0;
LABEL_60:
    v74 = FLOAT_N1_0;
    goto LABEL_61;
  }
  v73 = v70 >= 0.0;
  v71 = FLOAT_1_0;
  if ( v73 )
  {
    v72 = 0.0;
    goto LABEL_60;
  }
  v74 = FLOAT_N1_0;
  v72 = FLOAT_N1_0;
LABEL_61:
  v75 = v3->status.angularVelocity;
  if ( v75 <= 0.0 )
  {
    if ( v75 >= 0.0 )
      v74 = 0.0;
  }
  else
  {
    v74 = v71;
  }
  if ( v72 != v74 && v71 > v3->totalHubVelocity )
    v3->status.isLocked = 1;
  v3->oldAngularVelocity = v3->status.angularVelocity;
LABEL_69:
  v76 = v3->totalHubVelocity;
  if ( v76 < 10.0 )
    v3->status.slipFactor = COERCE_FLOAT(COERCE_UNSIGNED_INT(v76 * 0.1) & _xmm) * v3->status.slipFactor;
  Tyre::stepThermalModel(v3, dt);
  v3->status.pressureDynamic = (float)((float)(v3->thermalModel.coreTemp - 26.0) * v3->pressureTemperatureGain)
                             + v3->status.pressureStatic;
  Tyre::stepGrainBlister(v3, dt, v3->totalHubVelocity);
  Tyre::stepFlatSpot(v3, dt, v3->totalHubVelocity);
  if ( v3->onStepCompleted._Impl )
  {
    v77 = v3->onStepCompleted._Impl;
    if ( !v77 )
      std::_Xbad_function_call();
    v77->_Do_call(v77);
  }
}
void Tyre::stepDirtyLevel(Tyre *this, float dt, const float hubSpeed)
{
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4

  v3 = this->status.dirtyLevel;
  if ( v3 < 5.0 )
    this->status.dirtyLevel = (float)((float)((float)(this->surfaceDef->dirtAdditiveK * hubSpeed) * 0.029999999) * dt)
                            + v3;
  v4 = 0.0;
  if ( this->surfaceDef->dirtAdditiveK == 0.0 )
  {
    v5 = this->status.dirtyLevel;
    if ( v5 > 0.0 )
      this->status.dirtyLevel = v5 - (float)((float)(hubSpeed * 0.015) * dt);
    if ( this->status.dirtyLevel < 0.0 )
      this->status.dirtyLevel = 0.0;
  }
  v6 = this->status.dirtyLevel * 0.050000001;
  if ( v6 <= 1.0 )
  {
    if ( v6 >= 0.0 )
      v7 = this->status.dirtyLevel * 0.050000001;
    else
      v7 = 0.0;
  }
  else
  {
    v7 = FLOAT_1_0;
  }
  v8 = 1.0 - v7;
  v9 = FLOAT_0_80000001;
  if ( v8 > 0.80000001 )
  {
    if ( v6 <= 1.0 )
    {
      if ( v6 >= 0.0 )
        v4 = this->status.dirtyLevel * 0.050000001;
    }
    else
    {
      v4 = FLOAT_1_0;
    }
    v9 = 1.0 - v4;
  }
  if ( this->aiMult == 1.0 )
  {
    this->status.Fx = v9 * this->status.Fx;
    v10 = v9 * this->status.Fy;
    v11 = v9 * this->status.Mz;
    this->status.Fy = v10;
    this->status.Mz = v11;
  }
}
void Tyre::stepFlatSpot(Tyre *this, float dt, float hubVelocity)
{
  SurfaceDef *v3; // edx
  Car *v4; // eax
  float v5; // xmm3_4
  float v6; // xmm2_4
  long double v7; // xmm1_8

  if ( COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) <= 0.30000001 || this->status.slipRatio < -0.98000002 )
  {
    v3 = this->surfaceDef;
    if ( v3 )
    {
      if ( hubVelocity > 3.0 )
      {
        v4 = this->car;
        if ( v4 )
        {
          v5 = v4->ksPhysics->mechanicalDamageRate;
          if ( v5 != 0.0 )
          {
            v6 = v3->gripMod;
            if ( v6 >= 0.95 )
            {
              v7 = (float)((float)((float)((float)this->flatSpotK * hubVelocity) * this->status.load) * v6)
                 * 0.00001
                 * dt
                 * v5
                 * this->data.softnessIndex
                 + this->status.flatSpot;
              this->status.flatSpot = v7;
              if ( v7 > 1.0 )
                this->status.flatSpot = DOUBLE_1_0;
            }
          }
        }
      }
    }
  }
}
void Tyre::stepGrainBlister(Tyre *this, float dt, float hubVelocity)
{
  Car *v4; // eax
  unsigned int v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  SurfaceDef *v9; // eax
  float v10; // xmm0_4
  SurfaceDef *v11; // eax
  float v12; // xmm4_4
  float v13; // xmm3_4
  SurfaceDef *v14; // eax
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm0_4
  double v18; // xmm1_8
  double v19; // xmm0_8
  double v20; // xmm1_8
  float v21; // [esp+Ch] [ebp-1Ch]
  float v22; // [esp+10h] [ebp-18h]
  double Px; // [esp+18h] [ebp-10h] BYREF
  double _X; // [esp+20h] [ebp-8h]

  v4 = this->car;
  if ( v4 && v4->ksPhysics->tyreConsumptionRate > 0.0 )
  {
    if ( this->status.load <= 0.0 )
      return;
    v22 = this->thermalModel.coreTemp;
    v5 = __libm_sse2_powf(this).m128_u32[0];
    v6 = this->data.grainGain;
    v7 = hubVelocity;
    v21 = *(float *)&v5;
    if ( v6 > 0.0 )
    {
      v8 = this->data.grainThreshold;
      if ( v8 > v22 )
      {
        v9 = this->surfaceDef;
        if ( v9 )
        {
          if ( hubVelocity > 2.0 )
          {
            v10 = v9->gripMod;
            if ( v10 >= 0.94999999 )
            {
              Px = (float)((float)(v10 * hubVelocity) * v6) * ((float)(v8 - v22) * 0.0001);
              v7 = hubVelocity;
              if ( isfinite<double>(Px) )
                this->status.grain = v21 * dt * Px * this->car->ksPhysics->tyreConsumptionRate + this->status.grain;
            }
          }
        }
      }
    }
    v11 = this->surfaceDef;
    if ( v11 )
    {
      _X = (float)((float)(v11->gripMod * v7) * this->data.grainGain) * 0.00005;
      Px = _X;
      if ( __dtest(&Px) <= 0 && _X > 0.0 )
        this->status.grain = this->status.grain - v21 * dt * _X * this->car->ksPhysics->tyreConsumptionRate;
    }
    v12 = this->data.blisterGain;
    if ( v12 > 0.0 )
    {
      v13 = this->data.blisterThreshold;
      if ( v22 > v13 )
      {
        v14 = this->surfaceDef;
        if ( v14 )
        {
          if ( hubVelocity > 2.0 )
          {
            v15 = v14->gripMod;
            if ( v15 >= 0.95 )
            {
              _X = (float)((float)(this->totalHubVelocity * v15) * v12) * ((float)(v22 - v13) * 0.0001);
              if ( isfinite<double>(_X) )
              {
                v17 = __libm_sse2_powf(v16).m128_f32[0];
                this->status.blister = v17 * dt * _X * this->car->ksPhysics->tyreConsumptionRate + this->status.blister;
              }
            }
          }
        }
      }
    }
    v18 = this->status.grain;
    v19 = DOUBLE_100_0;
    if ( v18 <= 100.0 )
    {
      if ( v18 < 0.0 )
        v18 = 0.0;
    }
    else
    {
      v18 = DOUBLE_100_0;
    }
    this->status.grain = v18;
    v20 = this->status.blister;
    if ( v20 <= 100.0 )
    {
      if ( v20 < 0.0 )
      {
        this->status.blister = 0.0;
        return;
      }
      v19 = this->status.blister;
    }
    this->status.blister = v19;
  }
  else
  {
    *(_OWORD *)&this->status.grain = 0i64;
  }
}
void Tyre::stepRelaxationLength(Tyre *this, float svx, float svy, float hubVelocity, float dt)
{
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v5 = this->modelData.relaxationLength;
  v6 = this->status.ndSlip;
  if ( v6 <= 1.0 )
  {
    if ( v6 < 0.0 )
      v6 = 0.0;
  }
  else
  {
    v6 = FLOAT_1_0;
  }
  v7 = (float)((float)((float)((float)(this->status.load / this->modelData.Fz0) * v5) - v5) * 0.30000001) + v5;
  v8 = (float)((float)(v5 - (float)(v7 * 2.0)) * v6) + (float)(v7 * 2.0);
  if ( v8 == 0.0 )
  {
    this->rSlidingVelocityX = 0.0;
    this->rSlidingVelocityY = 0.0;
  }
  else
  {
    v9 = (float)(hubVelocity * dt) / v8;
    if ( v9 <= 1.0 )
    {
      if ( v9 < 0.039999999 )
      {
        v9 = FLOAT_0_039999999;
LABEL_10:
        v10 = (float)(v9 * (float)(svx - this->rSlidingVelocityX)) + this->rSlidingVelocityX;
        this->rSlidingVelocityY = (float)(v9 * (float)(svy - this->rSlidingVelocityY)) + this->rSlidingVelocityY;
        this->rSlidingVelocityX = v10;
        return;
      }
      if ( v9 < 1.0 )
        goto LABEL_10;
    }
    this->rSlidingVelocityX = svx;
    this->rSlidingVelocityY = svy;
  }
}
void Tyre::stepRotationMatrix(Tyre *this, float dt)
{
  Car *v3; // ecx
  const __m128i *v4; // eax
  mat44f *v5; // esi
  mat44f result; // [esp+8h] [ebp-8Ch] BYREF
  mat44f matrix1; // [esp+48h] [ebp-4Ch] BYREF
  vec3f axis; // [esp+88h] [ebp-Ch] BYREF

  v3 = this->car;
  if ( v3 && COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) > 0.1 && !Car::isSleeping(v3) )
  {
    axis.x = 1.0;
    axis.y = 0.0;
    axis.z = 0.0;
    v4 = (const __m128i *)mat44f::createFromAxisAngle((int)this, &result, &axis);
    v5 = &this->localWheelRotation;
    *(__m128i *)&matrix1.M11 = _mm_loadu_si128(v4);
    *(__m128i *)&matrix1.M21 = _mm_loadu_si128(v4 + 1);
    *(__m128i *)&matrix1.M31 = _mm_loadu_si128(v4 + 2);
    *(__m128i *)&matrix1.M41 = _mm_loadu_si128(v4 + 3);
    mul(v5, &matrix1, v5);
    v5->M41 = 0.0;
    v5->M42 = 0.0;
    v5->M43 = 0.0;
  }
}
void Tyre::stepThermalModel(Tyre *this, float dt)
{
  Car *v3; // eax
  float v4; // xmm2_4
  SurfaceDef *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  int v11; // eax
  Car *v12; // eax
  float Px; // [esp+14h] [ebp-4h] BYREF

  if ( (dword_186F1DC & 1) == 0 )
  {
    perfCounter_38.name = "Tyre::stepThermalModel";
    dword_186F1DC |= 1u;
    perfCounter_38.group = Physics;
    perfCounter_38.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Tyre::stepThermalModel" | 0xFF000000;
  }
  v3 = this->car;
  v4 = FLOAT_1_0;
  if ( v3 )
    v4 = v3->ksPhysics->track->dynamicGripLevel;
  v5 = this->surfaceDef;
  v6 = (float)(fsqrt(
                 (float)(this->slidingVelocityX * this->slidingVelocityX)
               + (float)(this->slidingVelocityY * this->slidingVelocityY))
             * (float)((float)(this->status.D * this->status.load) * this->data.thermalFrictionK))
     * v4;
  this->status.thermalInput = v6;
  if ( v5 )
    this->status.thermalInput = v5->gripMod * v6;
  Px = this->status.thermalInput;
  if ( __fdtest(&Px) <= 0 )
  {
    v7 = this->modelData.idealPressure;
    v8 = this->status.pressureDynamic;
    v9 = this->data.thermalRollingK;
    Px = v9;
    v10 = (float)((float)((float)(v7 / v8) - 1.0) * this->modelData.pressureRRGain) + 1.0;
    if ( v8 >= 0.0 )
    {
      v9 = v9 * v10;
      Px = v9;
    }
    v11 = this->modelData.version;
    if ( v11 < 5 )
      this->status.thermalInput = (float)((float)((float)(this->status.angularVelocity * v9) * this->status.load) * 0.001)
                                + this->status.thermalInput;
    if ( v11 >= 6 )
      this->status.thermalInput = (float)((float)((float)((float)(this->data.thermalRollingSurfaceK * v10)
                                                        * this->status.angularVelocity)
                                                * this->status.load)
                                        * 0.001)
                                + this->status.thermalInput;
    TyreThermalModel::addThermalInput(
      &this->thermalModel,
      this->status.camberRAD,
      (float)(v8 / v7) - 1.0,
      this->status.thermalInput);
    if ( this->modelData.version >= 5 )
      TyreThermalModel::addThermalCoreInput(
        &this->thermalModel,
        (float)((float)(this->status.angularVelocity * Px) * this->status.load) * 0.001);
    TyreThermalModel::step(&this->thermalModel, dt, this->status.angularVelocity, this->status.camberRAD);
  }
  v12 = this->car;
  if ( v12 )
  {
    if ( v12->ksPhysics->allowTyreBlankets )
      Tyre::stepTyreBlankets(this, dt);
  }
}
void Tyre::stepTyreBlankets(Tyre *this, float dt)
{
  bool v3; // bl
  float optimumTemp; // xmm0_4
  Speed result; // [esp+8h] [ebp-4h] BYREF

  if ( this->tyreBlanketsOn )
  {
    v3 = (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) > 10.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    if ( v3 )
      this->tyreBlanketsOn = 0;
    optimumTemp = this->blanketTemperature;
    if ( this->data.optimumTemp <= optimumTemp )
      optimumTemp = this->data.optimumTemp;
    TyreThermalModel::setTemperature(&this->thermalModel, optimumTemp);
  }
}
void Tyre::updateAngularSpeed(Tyre *this, float dt)
{
  float v2; // xmm0_4
  bool v3; // al
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  bool v9; // zf

  if ( this->status.isLocked )
  {
    v2 = this->absOverride * this->inputs.brakeTorque;
    if ( v2 <= this->inputs.handBrakeTorque )
      v2 = this->inputs.handBrakeTorque;
    v3 = COERCE_FLOAT(LODWORD(v2) & _xmm) >= COERCE_FLOAT(COERCE_UNSIGNED_INT(this->status.loadedRadius * this->status.Fx) & _xmm)
      && COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) < 1.0
      && !this->driven;
    this->status.isLocked = v3;
  }
  v4 = FLOAT_N1_0;
  v5 = (float)((float)(this->status.feedbackTorque / this->data.angularInertia) * dt) + this->status.angularVelocity;
  this->status.angularVelocity = v5;
  v6 = this->oldAngularVelocity;
  if ( v6 <= 0.0 )
  {
    if ( v6 >= 0.0 )
      v7 = 0.0;
    else
      v7 = FLOAT_N1_0;
  }
  else
  {
    v7 = FLOAT_1_0;
  }
  v8 = this->status.angularVelocity;
  if ( v8 <= 0.0 )
  {
    if ( v8 >= 0.0 )
      v4 = 0.0;
  }
  else
  {
    v4 = FLOAT_1_0;
  }
  if ( v7 != v4 )
    this->status.isLocked = 1;
  v9 = !this->status.isLocked;
  this->oldAngularVelocity = v5;
  if ( !v9 )
    this->status.angularVelocity = 0.0;
  if ( COERCE_FLOAT(LODWORD(this->status.angularVelocity) & _xmm) < 1.0 )
    this->status.angularVelocity = this->status.angularVelocity * 0.89999998;
}
