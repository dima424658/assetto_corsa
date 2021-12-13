#include "yebispp.h"
void YebisPP::YebisPP(YebisPP *this, GraphicsManager *graphics, int width, int height, ID3D11RenderTargetView *rtv)
{
  int v6; // eax

  this->width = width;
  this->height = height;
  this->pp.dofApertureFrontLevelsNumber = -1;
  this->pp.dofApertureBackLevelsNumber = -1;
  this->pp.dofBackgroundMaskThreshold = 0.1;
  this->pp.dofEdgeQuality = -1;
  this->exposure = 30.0;
  this->pPfxContext = 0;
  this->currentAutoExposure = 0.0;
  this->graphics = graphics;
  this->pHeatShimmerParticleManager = 0;
  this->currentPPSet._Myres = 7;
  this->currentPPSet._Mysize = 0;
  this->currentPPSet._Bx._Buf[0] = 0;
  this->frameBuffer = rtv;
  _printf("YebisPP %d %d\n", width, height);
  this->pp.heatParticleEnabled = graphics->videoSettings.ppHeatShimmer;
  this->pp.glareQuality = graphics->videoSettings.ppGlare;
  this->pp.dofQuality = graphics->videoSettings.ppDof;
  this->pp.godraysEnabled = graphics->videoSettings.ppRaysOfGod;
  v6 = graphics->videoSettings.ppGlare != 0;
  this->pp.antialiasEnabled = 0;
  this->pp.glareEnabled = v6;
}
void YebisPP::~YebisPP(YebisPP *this)
{
  if ( this->currentPPSet._Myres >= 8 )
    operator delete(this->currentPPSet._Bx._Ptr);
  this->currentPPSet._Myres = 7;
  this->currentPPSet._Mysize = 0;
  this->currentPPSet._Bx._Buf[0] = 0;
}
void __userpurge YebisPP::applyPostProcessing(YebisPP *this@<ecx>, _DWORD *a2@<ebx>, ID3D11ShaderResourceView *srcSRV, DXGI_FORMAT srcFormat, ID3D11ShaderResourceView *srcDepthSRV, ID3D11RenderTargetView *dstRTV, DXGI_FORMAT dstFormat)
{
  PPFX::IPfxContext_Dx11 *v8; // eax

  v8 = this->pPfxContext;
  if ( v8 )
  {
    PPFX::IPfxBaseContext::SetDestination(v8, dstRTV, this->width, this->height, dstFormat, 1, 0);
    if ( PPFX::IPfxBaseContext::SetEffectSource(
           this->pPfxContext,
           srcSRV,
           this->width,
           this->height,
           (GPUUTIL *)srcFormat) < 0 )
    {
      _printf("ERROR: FAILED pPfxContext->SetEffectSource(renderTarget\n");
      goto LABEL_4;
    }
    if ( srcDepthSRV )
    {
      if ( PPFX::IPfxBaseContext::SetDepthFactorSource(
             this->pPfxContext,
             PFXDFSRC_R,
             srcDepthSRV,
             this->width,
             this->height,
             (GPUUTIL *)0x27,
             PFXDFFMT_DEPTHVALUE,
             1065353216i64) < 0 )
      {
        _printf("ERROR: FAILED pPfxContext->SetDepthFactorSource(renderTarget) pointer is : %p\n", srcDepthSRV);
        _fflush(0);
      }
    }
    if ( PPFX::IPfxBaseContext::ApplyEffects(a2, this->pPfxContext, 0) < 0 )
    {
      _printf("ERROR: FAILED ApplyEffects()\n");
LABEL_4:
      _fflush(0);
      _exit(1);
    }
  }
}
void __userpurge YebisPP::updatePPCameraValues(YebisPP *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt, Camera *camera, float a6, float a7, float a8, float a9, vec3f cameraPosition, vec3f cameraTarget, mat44f result, __m128i a13, __m128i a14, __m128i a15, __m128i a16)
{
  Camera *v17; // edi
  float v18; // xmm0_4
  bool v19; // zf
  float v20; // xmm0_4
  GraphicsManager *v21; // eax
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  GraphicsManager *v26; // eax
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  __m128 v32; // xmm0
  float v33; // xmm2_4
  float v34; // xmm4_4
  Camera_vtbl *v35; // eax
  mat44f *(*v36)(Camera *, mat44f *); // eax
  float *v37; // eax
  float v38; // xmm4_4
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  unsigned __int64 v44; // [esp+4h] [ebp-B0h]
  float v45; // [esp+Ch] [ebp-A8h]
  char v46[44]; // [esp+74h] [ebp-40h] BYREF
  vec3f *v47; // [esp+A0h] [ebp-14h]
  vec3f *v48; // [esp+A4h] [ebp-10h]
  mat44f *v49; // [esp+A8h] [ebp-Ch]

  v17 = camera;
  this->pp.dt = dt;
  this->exposure = v17->exposure;
  this->pp.cameraVerticalFOVRad = v17->fov * 0.017453;
  this->pp.cameraNearPlane = v17->nearPlane;
  v18 = v17->farPlane;
  this->pp.cameraFarPlane = v18;
  if ( v18 <= 1000.0 )
  {
    if ( v18 < 1.0 )
      v18 = FLOAT_1_0;
  }
  else
  {
    v18 = FLOAT_1000_0;
  }
  this->pp.cameraFarPlane = v18;
  v19 = !this->pp.godraysUseSunLightColor;
  this->pp.dofActive = v17->dofFactor != 0.0;
  this->pp.chromabActive = 0;
  this->pp.dofFocusDistance = v17->dofFocus;
  this->pp.glareGhostActive = 0;
  if ( !v19 )
  {
    v20 = __libm_sse2_powf(this).m128_f32[0];
    v21 = this->graphics;
    v22 = (float)((float)(v21->lightingSettings.sunLow.x - v21->lightingSettings.sunHigh.x) * v20)
        + v21->lightingSettings.sunHigh.x;
    v23 = (float)((float)(v21->lightingSettings.sunLow.y - v21->lightingSettings.sunHigh.y) * v20)
        + v21->lightingSettings.sunHigh.y;
    v24 = (float)((float)(v21->lightingSettings.sunLow.z - v21->lightingSettings.sunHigh.z) * v20)
        + v21->lightingSettings.sunHigh.z;
    v44 = __PAIR64__(LODWORD(v23), LODWORD(v22));
    v45 = v24;
    v25 = fsqrt((float)((float)(v23 * v23) + (float)(v22 * v22)) + (float)(v24 * v24));
    if ( v25 != 0.0 )
    {
      *(float *)&v44 = (float)(1.0 / v25) * v22;
      *((float *)&v44 + 1) = (float)(1.0 / v25) * v23;
      v45 = (float)(1.0 / v25) * v24;
    }
    *(_QWORD *)this->pp.godraysColor = v44;
    this->pp.godraysColor[2] = v45;
    this->pp.godraysColor[3] = 1.0;
  }
  *(__m128i *)this->pp.cameraMatrix = _mm_loadu_si128((const __m128i *)&v17->matrix);
  *(__m128i *)&this->pp.cameraMatrix[4] = _mm_loadu_si128((const __m128i *)&v17->matrix.M21);
  *(__m128i *)&this->pp.cameraMatrix[8] = _mm_loadu_si128((const __m128i *)&v17->matrix.M31);
  *(__m128i *)&this->pp.cameraMatrix[12] = _mm_loadu_si128((const __m128i *)&v17->matrix.M41);
  ((void (*)(Camera *, char *, int, int))v17->getViewMatrix)(v17, v46, a2, a3);
  v26 = this->graphics;
  *(__m128i *)this->pp.viewMatrix = _mm_loadu_si128(&a13);
  *(__m128i *)&this->pp.viewMatrix[4] = _mm_loadu_si128(&a14);
  *(__m128i *)&this->pp.viewMatrix[8] = _mm_loadu_si128(&a15);
  *(__m128i *)&this->pp.viewMatrix[12] = _mm_loadu_si128(&a16);
  LODWORD(v27) = LODWORD(v26->lightingSettings.lightDirection.x) ^ _xmm;
  LODWORD(v28) = LODWORD(v26->lightingSettings.lightDirection.y) ^ _xmm;
  LODWORD(v29) = LODWORD(v26->lightingSettings.lightDirection.z) ^ _xmm;
  if ( (float)((float)((float)(COERCE_FLOAT(LODWORD(v17->matrix.M32) ^ _xmm) * v28)
                     + (float)(COERCE_FLOAT(LODWORD(v17->matrix.M31) ^ _xmm) * v27))
             + (float)(COERCE_FLOAT(LODWORD(v17->matrix.M33) ^ _xmm) * v29)) <= 0.0 )
  {
    this->pp.godraysInCameraFustrum = 0;
  }
  else
  {
    v49 = (mat44f *)&dt;
    v48 = &cameraTarget;
    v47 = &cameraPosition;
    dt = v17->matrix.M21;
    camera = (Camera *)LODWORD(v17->matrix.M22);
    a6 = v17->matrix.M23;
    LODWORD(v30) = LODWORD(v17->matrix.M31) ^ _xmm;
    a9 = v27 * 1000.0;
    cameraTarget.x = v30;
    LODWORD(v31) = LODWORD(v17->matrix.M32) ^ _xmm;
    a8 = v28 * 1000.0;
    cameraTarget.y = v31;
    v32 = _mm_xor_ps((__m128)LODWORD(v17->matrix.M33), (__m128)(unsigned int)_xmm);
    a7 = v29 * 1000.0;
    LODWORD(cameraTarget.z) = v32.m128_i32[0];
    cameraPosition.x = 0.0;
    cameraPosition.y = 0.0;
    cameraPosition.z = 0.0;
    mat44f::createLookAt(v32, &result, &cameraPosition, &cameraTarget, (const vec3f *)&dt);
    v33 = a9;
    v34 = a7;
    v35 = v17->__vftable;
    v49 = &result;
    v36 = v35->getPerspectiveMatrix;
    v32.m128_f32[0] = result.M12 * a9;
    a9 = (float)((float)((float)(result.M21 * a8) + (float)(result.M11 * a9)) + (float)(result.M31 * a7)) + result.M41;
    a7 = (float)((float)((float)(result.M22 * a8) + v32.m128_f32[0]) + (float)(result.M32 * a7)) + result.M42;
    a8 = (float)((float)((float)(result.M23 * a8) + (float)(result.M13 * v33)) + (float)(result.M33 * v34)) + result.M43;
    v37 = (float *)v36(v17, &result);
    v38 = (float)((float)((float)(v37[5] * a7) + (float)(v37[1] * a9)) + (float)(v37[9] * a8)) + v37[13];
    v39 = (__m128)LODWORD(FLOAT_1_0);
    v39.m128_f32[0] = 1.0
                    / (float)((float)((float)((float)(v37[7] * a7) + (float)(v37[3] * a9)) + (float)(v37[11] * a8))
                            + v37[15]);
    v40 = v39;
    v41 = v39;
    v40.m128_f32[0] = v39.m128_f32[0]
                    * (float)((float)((float)((float)(v37[4] * a7) + (float)(*v37 * a9)) + (float)(v37[8] * a8))
                            + v37[12]);
    cameraTarget.z = v39.m128_f32[0]
                   * (float)((float)((float)((float)(v37[6] * a7) + (float)(v37[2] * a9)) + (float)(v37[10] * a8))
                           + v37[14]);
    v41.m128_f32[0] = v39.m128_f32[0] * v38;
    cameraPosition.z = cameraTarget.z;
    *(_QWORD *)&cameraPosition.x = _mm_unpacklo_ps(v40, v41).m128_u64[0];
    v39.m128_i32[0] = LODWORD(cameraPosition.y);
    this->pp.godraysOrigin[0] = (float)(v40.m128_f32[0] + 1.0) * 0.5;
    this->pp.godraysOrigin[1] = 1.0 - (float)((float)(v39.m128_f32[0] + 1.0) * 0.5);
    this->pp.godraysInCameraFustrum = 1;
  }
}
void YebisPP::updatePP(YebisPP *this, bool updateExp)
{
  PPFX::IPfxContext_Dx11 *v3; // eax
  double v4; // st7
  int v5; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  int v14; // eax
  char v15; // cl
  int v16; // edx
  const __m128i *v17; // edi
  KGLYebisParticleManager *v18; // eax
  KGLYebisParticleSet *v19; // ecx
  float v20; // xmm0_4
  bool v21; // al
  float v22; // xmm0_4
  bool v23; // zf
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  PPFX::IPfxContext_Dx11 *v28; // [esp+4h] [ebp-A8h]
  _BYTE v29[12]; // [esp+8h] [ebp-A4h]
  __int64 v30; // [esp+8h] [ebp-A4h]
  int v31; // [esp+8h] [ebp-A4h]
  __int64 v32; // [esp+8h] [ebp-A4h]
  PPFX::IPfxContext_Dx11 *v33; // [esp+Ch] [ebp-A0h]
  __int64 v34; // [esp+Ch] [ebp-A0h]
  _BYTE v35[12]; // [esp+10h] [ebp-9Ch]
  int v36; // [esp+10h] [ebp-9Ch]
  _BYTE v37[12]; // [esp+10h] [ebp-9Ch]
  __int64 v38; // [esp+14h] [ebp-98h]
  PPFX::IPfxContext_Dx11 *v39; // [esp+14h] [ebp-98h]
  __int64 v40; // [esp+14h] [ebp-98h]
  float v41; // [esp+18h] [ebp-94h]
  bool v42; // [esp+28h] [ebp-84h]
  bool v43; // [esp+28h] [ebp-84h]
  int v44; // [esp+28h] [ebp-84h]
  int v45[2]; // [esp+2Ch] [ebp-80h] BYREF
  struct PPFX::PFX_GLARESHAPEDEF v46; // [esp+34h] [ebp-78h] BYREF
  int v47[3]; // [esp+80h] [ebp-2Ch] BYREF
  KGLVolume v; // [esp+8Ch] [ebp-20h] BYREF

  v3 = this->pPfxContext;
  if ( v3 )
  {
    *(_QWORD *)&v29[4] = *(_QWORD *)&this->pp.cameraFarPlane;
    *(float *)v29 = this->pp.cameraNearPlane;
    PPFX::IPfxBaseContext::SetRenderSceneParameters(
      (int)this,
      v3,
      *(__int64 *)v29,
      this->pp.cameraVerticalFOVRad,
      this->pp.dt,
      1.0);
    PPFX::IPfxBaseContext::SetRenderSceneCameraMatrix(this->pPfxContext, this->pp.cameraMatrix, 0);
    PPFX::IPfxBaseContext::SetRenderSceneViewMatrix(this->pPfxContext, (const __m128i *)this->pp.viewMatrix, 0);
    *(_QWORD *)&v35[4] = *(_QWORD *)&this->pp.cameraFarPlane;
    *(float *)v35 = this->pp.cameraNearPlane;
    PPFX::IPfxBaseContext::SetRenderScenePerspective(
      (int)this,
      this->pPfxContext,
      *(__int64 *)v35,
      this->pp.cameraVerticalFOVRad);
    if ( updateExp )
    {
      v42 = this->pp.autoExposureEnabled != 0;
      PPFX::IPfxBaseContext::SetAutoExposureEnable(this->pPfxContext, -1, v42);
      this->currentAutoExposure = this->pp.tonemapExposure;
      if ( v42 )
      {
        v4 = PPFX::IPfxBaseContext::GetAutoExposureAdjusted(this->pPfxContext, -1);
        v41 = this->pp.autoExposureDelay;
        v33 = this->pPfxContext;
        this->currentAutoExposure = v4;
        PPFX::IPfxBaseContext::SetAutoExposureDelay(v33, -1, PFXAAD_PHYSICALTIME, v41);
        PPFX::IPfxBaseContext::SetAutoExposureRange(this->pPfxContext, -1, *(_QWORD *)&this->pp.autoExposureMin);
        HIDWORD(v38) = LODWORD(this->pp.autoExposureInfluencedByGlare);
        *(float *)&v38 = (float)((float)(this->exposure * 0.033333335) * this->pp.autoExposureTarget)
                       * this->graphics->exposureMultiplier;
        PPFX::IPfxBaseContext::SetAutoExposureMiddleGray(this->pPfxContext, -1, v38);
      }
      if ( this->pp.tonemapUseHDRSpace == 1 )
        v36 = this->pp.tonemapFunc;
      else
        v36 = 196610;
      HIDWORD(v30) = LODWORD(this->pp.tonemapGamma);
      *(float *)&v30 = this->currentAutoExposure;
      PPFX::IPfxBaseContext::SetTonemapParameters(
        this->pPfxContext,
        v30,
        (enum PPFX::EPFX_TONEMAP)v36,
        this->pp.tonemapMappingFactor,
        -3.4028235e38);
      PPFX::IPfxBaseContext::SetTonemapViewportScale(
        this->pPfxContext,
        *(_QWORD *)&this->pp.tonemapViewPortScaleWidth,
        this->pp.tonemapViewPortOffsetX,
        this->pp.tonemapViewPortOffsetY);
    }
    if ( this->pp.heatParticleEnabled )
    {
      v43 = this->pp.heatParticleActive != 0;
      PPFX::IPfxBaseContext::SetHeatShimmerParticleEnable(this->pPfxContext, v43);
      if ( v43 )
      {
        v5 = dword_1873924;
        if ( (dword_1873924 & 1) != 0 )
        {
          v6 = s_vShimmerIntensity_0.w;
          v7 = s_vShimmerIntensity_0.z;
          v8 = s_vShimmerIntensity_0.y;
          v9 = s_vShimmerIntensity_0.x;
        }
        else
        {
          v5 = dword_1873924 | 1;
          v6 = FLOAT_1_0;
          v7 = FLOAT_1_0;
          dword_1873924 |= 1u;
          v8 = FLOAT_1_0;
          s_vShimmerIntensity_0.w = FLOAT_1_0;
          v9 = FLOAT_1_0;
          s_vShimmerIntensity_0.z = FLOAT_1_0;
          s_vShimmerIntensity_0.y = FLOAT_1_0;
          s_vShimmerIntensity_0.x = FLOAT_1_0;
        }
        if ( (v5 & 2) != 0 )
        {
          v10 = s_vShimmerScale_0.y;
          v11 = s_vShimmerScale_0.x;
        }
        else
        {
          v10 = FLOAT_1_0;
          v11 = FLOAT_1_0;
          dword_1873924 = v5 | 2;
          s_vShimmerScale_0.y = FLOAT_1_0;
          s_vShimmerScale_0.x = FLOAT_1_0;
        }
        v12 = this->pp.heatParticleCoord;
        v47[2] = 0;
        *(float *)v45 = v12 * v11;
        *(float *)&v45[1] = v12 * v10;
        v13 = this->pp.heatParticleShimmer;
        v47[1] = 0;
        v47[0] = 0;
        v.center[0] = v13 * v9;
        v.center[1] = v13 * v8;
        v.center[2] = v13 * v7;
        v31 = LODWORD(this->pp.heatParticleRadius);
        v28 = this->pPfxContext;
        v.width = v13 * v6;
        PPFX::IPfxBaseContext::SetHeatShimmerParticleParameters(
          (int)v28,
          v31,
          1065353216,
          (const __m128i *)&v,
          v45,
          (int)v47);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleFractalOctave(
          this->pPfxContext,
          (int)this->pp.heatParticleFractalOctaves,
          2.7,
          0.28);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleFalloffDistance(this->pPfxContext, 1077936128i64, 1);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleColor(
          this->pPfxContext,
          this->pp.heatParticleColor[0],
          this->pp.heatParticleColor[1],
          this->pp.heatParticleColor[2]);
        v14 = 0;
        v15 = 0;
        v44 = 0;
        if ( this->pp.heatParticleSetsNumber > 0 )
        {
          v16 = 0;
          v17 = (const __m128i *)&this->pp.heatParticleSets[0].volume;
          v45[0] = 0;
          do
          {
            if ( v17[-1].m128i_i32[3] )
            {
              v18 = this->pHeatShimmerParticleManager;
              *(__m128i *)v.center = _mm_loadu_si128(v17);
              v19 = (KGLYebisParticleSet *)((char *)v18->sets._Myfirst + v16);
              *(_QWORD *)&v.depth = v17[1].m128i_i64[0];
              KGLYebisParticleSet::update(v19, &v, &this->pp);
              v16 = v45[0];
              v15 = 1;
              v14 = v44;
            }
            ++v14;
            v16 += 12;
            v17 = (const __m128i *)((char *)v17 + 28);
            v44 = v14;
            v45[0] = v16;
          }
          while ( v14 < this->pp.heatParticleSetsNumber );
          if ( v15 )
            KGLYebisParticleManager::setupPfxParticles(this->pHeatShimmerParticleManager, this->pPfxContext);
        }
      }
    }
    PPFX::IPfxBaseContext::SetDepthOfFieldEnable(this->pPfxContext, 0);
    if ( this->pp.godraysEnabled )
    {
      LOBYTE(v45[0]) = this->pp.godraysInCameraFustrum != 0;
      PPFX::IPfxBaseContext::SetLightShaftEnable(this->pPfxContext, v45[0]);
      if ( LOBYTE(v45[0]) )
      {
        PPFX::IPfxBaseContext::SetLightShaftPosition(this->pPfxContext, *(_QWORD *)this->pp.godraysOrigin);
        *(_OWORD *)v.center = *(_OWORD *)this->pp.godraysColor;
        PPFX::IPfxBaseContext::SetLightShaftParameters(
          (int)this->pPfxContext,
          (const __m128i *)&v,
          *(_QWORD *)&this->pp.godraysLength,
          LODWORD(this->pp.godraysDepthMaskThreshold),
          6,
          LODWORD(this->pp.godraysAngleAttenuation),
          LODWORD(this->pp.godraysNoiseMask),
          LODWORD(this->pp.godraysNoiseFrequency));
        *(_OWORD *)v.center = *(_OWORD *)this->pp.godraysDiffractionRingOuterColor;
        HIDWORD(v32) = LODWORD(this->pp.godraysDiffractionRadius);
        *(float *)&v32 = this->pp.godraysDiffractionRing;
        PPFX::IPfxBaseContext::SetLightShaftDiffractionRing(
          (int)this->pPfxContext,
          v32,
          LODWORD(this->pp.godraysDiffractionRingAttenuation),
          LODWORD(this->pp.godraysDiffractionRingSpectrumOrder),
          (const __m128i *)&v);
      }
    }
    if ( this->pp.diaphragmRotateScale != 0.0 || this->pp.diaphragmRotateOffsetRad != 0.0 )
      PPFX::IPfxBaseContext::SetDiaphragmRotate(
        this->pPfxContext,
        *(_QWORD *)&this->pp.diaphragmRotateScale,
        (enum PPFX::EPFX_DIAPHRAGMROTATE)this->pp.diaphragmRotationType);
    LOBYTE(v45[0]) = this->pp.feedbackEnabled != 0;
    PPFX::IPfxBaseContext::SetFeedbackEnable(this->pPfxContext, v45[0]);
    if ( LOBYTE(v45[0]) )
    {
      PPFX::IPfxBaseContext::SetFeedbackMatrixAspectRatio(this->pPfxContext, this->pp.feedbackAspectRatio);
      *(_QWORD *)&v37[4] = *(_QWORD *)&this->pp.feedbackCurrentWeight;
      *(float *)v37 = this->pp.feedbackWeight;
      PPFX::IPfxBaseContext::SetFeedbackWeight(this->pPfxContext, *(__int64 *)v37, this->pp.feedbackTimeInSeconds);
    }
    if ( this->pp.glareEnabled )
    {
      if ( this->pp.glareUseCustomShape )
      {
        memset(&v46, 0, sizeof(v46));
        PPFX::IPfxBaseContext::GetGlareShapeDefinition(this->pPfxContext, &v46, this->pp.glareShape);
        v20 = this->pp.glareShapeLuminance * v46.m_fGlareLuminance;
        v46.m_iBloomDispersionBaseLevel = this->pp.glareShapeBloomDispersionBaseLevel;
        v21 = this->pp.glareShapeGhostSharpeness;
        v46.m_fGlareLuminance = v20;
        v22 = this->pp.glareShapeBloomLuminance * v46.m_fBloomLuminance;
        v46.m_bGhostSharpness = v21;
        v46.m_bStarRotation = 1;
        v46.m_fBloomLuminance = v22;
        v46.m_fBloomDispersion = this->pp.glareShapeBloomDispersion * v46.m_fBloomDispersion;
        v46.m_fGhostLuminance = this->pp.glareShapeGhostLuminance * v46.m_fGhostLuminance;
        v46.m_fGhostHaloLuminance = this->pp.glareShapeGhostHaloLuminance * v46.m_fGhostHaloLuminance;
        v46.m_fGhostDistortion = this->pp.glareShapeGhostDistortion * v46.m_fGhostDistortion;
        v46.m_fStarLuminance = this->pp.glareShapeStarLuminance * v46.m_fStarLuminance;
        v46.m_fStarLength = this->pp.glareShapeStarLength * v46.m_fStarLength;
        v46.m_fStarSecondaryLength = this->pp.glareShapeStarSecondaryLength * v46.m_fStarSecondaryLength;
        v46.m_fStarInclinationAngle = this->pp.glareShapeStarInclinationAngle * v46.m_fStarInclinationAngle;
        v46.m_fStarDispersion = this->pp.glareShapeStarDispersion * v46.m_fStarDispersion;
        v46.m_fAfterimageLuminance = this->pp.glareShapeAfterimageLuminance;
        v46.m_fAfterimageLength = this->pp.glareShapeAfterimageLength;
        if ( this->pp.glareShapeStarRotation == 0.0 )
          v46.m_bStarRotation = 0;
        v23 = this->pp.glareShapeStarForceDispersion == 0;
        v46.m_nStarStreaks = this->pp.glareShapeStarStreaksNumber;
        v39 = this->pPfxContext;
        v46.m_bStarForceDispersion = !v23;
        PPFX::IPfxBaseContext::SetGlareShape(v39, (const __m128i *)&v46);
      }
      else
      {
        PPFX::IPfxBaseContext::SetGlareShape(this->pPfxContext, (enum PPFX::EPFX_GLARESHAPE)this->pp.glareShape);
      }
      PPFX::IPfxBaseContext::SetGlareGhostConcentricDistortion(
        this->pPfxContext,
        this->pp.glareGhostConcentricDistortion);
      HIDWORD(v34) = LODWORD(this->pp.glareThreshold);
      *(float *)&v34 = this->pp.glareLuminance;
      PPFX::IPfxBaseContext::SetGlareParameters(
        this->pPfxContext,
        v34,
        (enum PPFX::EPFX_GLAREBRIGHTPASS)this->pp.glareBrightPass,
        1.0);
      PPFX::IPfxBaseContext::SetGlareBloomFilterThreshold(this->pPfxContext, this->pp.glareBloomFilterThreshold);
      PPFX::IPfxBaseContext::SetGlareBloomGaussianRadiusScale(this->pPfxContext, this->pp.glareBloomGaussianRadiusScale);
      PPFX::IPfxBaseContext::SetGlareBloomLuminanceGamma(this->pPfxContext, this->pp.glareBloomLuminanceGamma);
      PPFX::IPfxBaseContext::SetGlareBloomNumLevels(this->pPfxContext, this->pp.glareBloomNumLevels);
      PPFX::IPfxBaseContext::SetGlareGenerationRangeScale(this->pPfxContext, this->pp.glareGenerationRangeScale);
      PPFX::IPfxBaseContext::SetGlareStarFilterThreshold(this->pPfxContext, this->pp.glareStarFilterThreshold);
      PPFX::IPfxBaseContext::SetGlareStarSoftness(this->pPfxContext, this->pp.glareStarSoftness);
      PPFX::IPfxBaseContext::SetGlareStarLengthFovDependence(this->pPfxContext, this->pp.glareFovDependence);
      PPFX::IPfxBaseContext::SetGlareResultBlur(this->pPfxContext, this->pp.glareBlur);
      PPFX::IPfxBaseContext::SetGlareAnamorphicLensFlareEnable(this->pPfxContext, this->pp.glareAnamorphicEnabled != 0);
    }
    else
    {
      PPFX::IPfxBaseContext::SetGlareShape(this->pPfxContext, PFXGS_DISABLE);
    }
    LOBYTE(v45[0]) = this->pp.lensdistortionEnabled != 0;
    PPFX::IPfxBaseContext::SetLensDistortionEnable(this->pPfxContext, v45[0]);
    if ( LOBYTE(v45[0]) )
      PPFX::IPfxBaseContext::SetLensDistortionEdge(this->pPfxContext, *(_QWORD *)&this->pp.lensdistortionRoundness);
    PPFX::IPfxBaseContext::InitializeMatrix(this->pPfxContext, PFXMTX_TONEMAP_COLOR_HDRSPACE);
    v24 = this->pp.hue;
    if ( v24 != 0.0 )
    {
      HIDWORD(v40) = 1;
      *(float *)&v40 = (float)(v24 * 3.1415927) * 0.0055555557;
      PPFX::IPfxBaseContext::MultiplyMatrixColorHue(this->pPfxContext, PFXMTX_TONEMAP_COLOR_HDRSPACE, v40);
    }
    v25 = FLOAT_1_0;
    if ( this->pp.saturation != 1.0 )
    {
      PPFX::IPfxBaseContext::MultiplyMatrixColorSaturation(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.saturation);
      v25 = FLOAT_1_0;
    }
    if ( this->pp.brightness != v25 )
    {
      PPFX::IPfxBaseContext::MultiplyMatrixColorBrightness(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.brightness);
      v25 = FLOAT_1_0;
    }
    if ( this->pp.contrast != v25 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorContrast(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.contrast);
    if ( this->pp.sepia != 0.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorSepiaTone(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.sepia);
    v26 = this->pp.colorTemperatureK;
    if ( v26 != 6500.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorTemperature(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        LODWORD(v26) | 0x3F80000000000000i64);
    v27 = this->pp.whiteBalanceK;
    if ( v27 != 6500.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorWhiteBalance(
        this->pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        LODWORD(v27) | 0x3F80000000000000i64);
  }
}
bool YebisPP::loadPPSet(YebisPP *this, const std::wstring *name)
{
  std::wstring *v3; // edi
  const std::wstring *v4; // eax
  bool result; // al
  PPFX::CTextureUtil *v6; // edx
  std::wstring v7; // [esp-18h] [ebp-28h] BYREF

  v3 = &this->currentPPSet;
  if ( name->_Myres < 8 )
    v4 = name;
  else
    v4 = (const std::wstring *)name->_Bx._Ptr;
  if ( std::wstring::compare(&this->currentPPSet, 0, this->currentPPSet._Mysize, v4->_Bx._Buf, name->_Mysize) )
  {
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, name, 0, 0xFFFFFFFF);
    if ( YebisPP::readPPSet(this, v7) )
    {
      YebisPP::initPP(this, v6);
      if ( v3 != name )
        std::wstring::assign(v3, name, 0, 0xFFFFFFFF);
      result = 1;
    }
    else
    {
      _printf("ERROR: Couldn't load requested PP set\n");
      result = 0;
    }
  }
  else
  {
    _printf("Requested set is the same already in use, no actions\n");
    result = 0;
  }
  return result;
}
char YebisPP::readPPSet(YebisPP *this, std::wstring name)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // ebp
  std::wstring *v11; // eax
  char v12; // bl
  std::wstring *v13; // eax
  bool v14; // al
  double v15; // st7
  bool v16; // cf
  bool v17; // al
  int v18; // eax
  bool v19; // al
  int v20; // eax
  double v21; // st7
  double v22; // st7
  int v23; // eax
  double v24; // st7
  bool v25; // al
  bool v26; // al
  bool v27; // al
  bool v28; // al
  bool v29; // al
  bool v30; // al
  bool v31; // al
  bool v32; // al
  bool v33; // al
  vec3f *v34; // eax
  bool v35; // al
  bool v36; // al
  bool v37; // al
  bool v38; // bl
  double v39; // st7
  bool v41; // [esp+1Bh] [ebp-419h]
  bool v42; // [esp+1Bh] [ebp-419h]
  bool v43; // [esp+1Bh] [ebp-419h]
  bool v44; // [esp+1Bh] [ebp-419h]
  bool v45; // [esp+1Bh] [ebp-419h]
  bool v46; // [esp+1Bh] [ebp-419h]
  bool v47; // [esp+1Bh] [ebp-419h]
  bool v48; // [esp+1Bh] [ebp-419h]
  bool v49; // [esp+1Bh] [ebp-419h]
  bool v50; // [esp+1Bh] [ebp-419h]
  bool v51; // [esp+1Bh] [ebp-419h]
  bool v52; // [esp+1Bh] [ebp-419h]
  bool v53; // [esp+1Bh] [ebp-419h]
  bool v54; // [esp+1Bh] [ebp-419h]
  std::wstring key; // [esp+1Ch] [ebp-418h] BYREF
  std::wstring v56; // [esp+34h] [ebp-400h] BYREF
  vec4f color; // [esp+4Ch] [ebp-3E8h] BYREF
  int v58; // [esp+5Ch] [ebp-3D8h]
  unsigned int v59; // [esp+60h] [ebp-3D4h]
  std::wstring section; // [esp+64h] [ebp-3D0h] BYREF
  INIReader ini; // [esp+7Ch] [ebp-3B8h] BYREF
  std::wstring v62; // [esp+C4h] [ebp-370h] BYREF
  std::wstring v63; // [esp+DCh] [ebp-358h] BYREF
  std::wstring filename; // [esp+F4h] [ebp-340h] BYREF
  vec2f lateralDispersion; // [esp+10Ch] [ebp-328h] BYREF
  int v66; // [esp+11Ch] [ebp-318h]
  unsigned int v67; // [esp+120h] [ebp-314h]
  std::wstring v68; // [esp+124h] [ebp-310h] BYREF
  std::wstring v69; // [esp+13Ch] [ebp-2F8h] BYREF
  std::wstring v70; // [esp+154h] [ebp-2E0h] BYREF
  std::wstring v71; // [esp+16Ch] [ebp-2C8h] BYREF
  std::wstring v72; // [esp+184h] [ebp-2B0h] BYREF
  std::wstring v73; // [esp+19Ch] [ebp-298h] BYREF
  std::wstring v74; // [esp+1B4h] [ebp-280h] BYREF
  std::wstring v75; // [esp+1CCh] [ebp-268h] BYREF
  std::wstring v76; // [esp+1E4h] [ebp-250h] BYREF
  std::wstring v77; // [esp+1FCh] [ebp-238h] BYREF
  std::wstring v78; // [esp+214h] [ebp-220h] BYREF
  std::wstring v79; // [esp+22Ch] [ebp-208h] BYREF
  std::wstring v80; // [esp+244h] [ebp-1F0h] BYREF
  std::wstring v81; // [esp+25Ch] [ebp-1D8h] BYREF
  std::wstring v82; // [esp+274h] [ebp-1C0h] BYREF
  std::wstring v83; // [esp+28Ch] [ebp-1A8h] BYREF
  std::wstring v84; // [esp+2A4h] [ebp-190h] BYREF
  std::wstring v85; // [esp+2BCh] [ebp-178h] BYREF
  std::wstring v86; // [esp+2D4h] [ebp-160h] BYREF
  std::wstring result; // [esp+2ECh] [ebp-148h] BYREF
  std::wstring v88; // [esp+304h] [ebp-130h] BYREF
  std::wstring v89; // [esp+31Ch] [ebp-118h] BYREF
  std::wstring v90; // [esp+334h] [ebp-100h] BYREF
  std::wstring v91; // [esp+34Ch] [ebp-E8h] BYREF
  std::wstring v92; // [esp+364h] [ebp-D0h] BYREF
  std::wstring v93; // [esp+37Ch] [ebp-B8h] BYREF
  std::wstring v94; // [esp+394h] [ebp-A0h] BYREF
  std::wstring v95; // [esp+3ACh] [ebp-88h] BYREF
  std::wstring v96; // [esp+3C4h] [ebp-70h] BYREF
  std::wstring v97; // [esp+3DCh] [ebp-58h] BYREF
  std::wstring v98; // [esp+3F4h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v99; // [esp+40Ch] [ebp-28h] BYREF
  int v100; // [esp+430h] [ebp-4h]

  v100 = 0;
  v3 = &name;
  if ( name._Myres >= 8 )
    v3 = (std::wstring *)name._Bx._Ptr;
  _printf("LOADING PP SET:%S\n", v3->_Bx._Buf);
  if ( !name._Mysize || !std::wstring::compare(&name, 0, name._Mysize, L"NONE", 4u) )
  {
    v4 = &name;
    if ( name._Myres >= 8 )
      v4 = (std::wstring *)name._Bx._Ptr;
    _printf("Changing set from: %S to default\n", v4->_Bx._Buf);
    std::wstring::assign(&name, L"default", 7u);
  }
  v5 = std::operator+<wchar_t>(&result, L"system/cfg/ppfilters/", &name);
  LOBYTE(v100) = 1;
  std::operator+<wchar_t>(&filename, v5, L".ini");
  LOBYTE(v100) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists((unsigned int)_printf, &filename, 0) )
    goto LABEL_29;
  v6 = &filename;
  if ( filename._Myres >= 8 )
    v6 = (std::wstring *)filename._Bx._Ptr;
  _printf("PP SET ini %S not found, looking in Documents\n", v6->_Bx._Buf);
  v7 = Path::getDocumentPath(&section);
  LOBYTE(v100) = 4;
  v8 = std::operator+<wchar_t>(&key, v7, L"/cfg/ppfilters/");
  LOBYTE(v100) = 5;
  v9 = std::operator+<wchar_t>((std::wstring *)&lateralDispersion, v8, &name);
  LOBYTE(v100) = 6;
  v10 = std::operator+<wchar_t>((std::wstring *)&color, v9, L".ini");
  if ( &filename != v10 )
  {
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&filename, v10);
  }
  if ( v59 >= 8 )
    operator delete((void *)LODWORD(color.x));
  v59 = 7;
  v58 = 0;
  LOWORD(color.x) = 0;
  if ( v67 >= 8 )
    operator delete((void *)LODWORD(lateralDispersion.x));
  v67 = 7;
  v66 = 0;
  LOWORD(lateralDispersion.x) = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v100) = 3;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( Path::fileExists((unsigned int)_printf, &filename, 0) )
  {
LABEL_29:
    INIReader::INIReader(&ini, &filename);
    LOBYTE(v100) = 7;
    v13 = &filename;
    if ( filename._Myres >= 8 )
      v13 = (std::wstring *)filename._Bx._Ptr;
    _printf("Loading PP set from: %S\n", v13->_Bx._Buf);
    if ( ini.ready )
    {
      v59 = 7;
      v58 = 0;
      LOWORD(color.x) = 0;
      std::wstring::assign((std::wstring *)&color, L"DEBUG", 5u);
      LOBYTE(v100) = 8;
      v14 = INIReader::hasSection(&ini, (const std::wstring *)&color);
      LOBYTE(v100) = 7;
      v41 = v14;
      if ( v59 >= 8 )
      {
        operator delete((void *)LODWORD(color.x));
        v14 = v41;
      }
      if ( v14 )
      {
        std::wstring::wstring(&key, L"DOF_FOCUS");
        LOBYTE(v100) = 9;
        std::wstring::wstring((std::wstring *)&color, L"DEBUG");
        LOBYTE(v100) = 10;
        v15 = INIReader::getFloat(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.dofFocusDistance = v15;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      v59 = 7;
      v58 = 0;
      LOWORD(color.x) = 0;
      std::wstring::assign((std::wstring *)&color, L"VARIOUS", 7u);
      LOBYTE(v100) = 11;
      v17 = INIReader::hasSection(&ini, (const std::wstring *)&color);
      LOBYTE(v100) = 7;
      v42 = v17;
      if ( v59 >= 8 )
      {
        operator delete((void *)LODWORD(color.x));
        v17 = v42;
      }
      if ( v17 )
      {
        std::wstring::wstring(&key, L"APERTURE_RESULT_BLUR_MOD");
        LOBYTE(v100) = 12;
        std::wstring::wstring((std::wstring *)&color, L"VARIOUS");
        LOBYTE(v100) = 13;
        v18 = INIReader::getInt(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.apertureResltBlurModify = v18;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      v59 = 7;
      v58 = 0;
      LOWORD(color.x) = 0;
      std::wstring::assign((std::wstring *)&color, L"TONEMAPPING", 0xBu);
      LOBYTE(v100) = 14;
      v19 = INIReader::hasSection(&ini, (const std::wstring *)&color);
      LOBYTE(v100) = 7;
      v43 = v19;
      if ( v59 >= 8 )
      {
        operator delete((void *)LODWORD(color.x));
        v19 = v43;
      }
      if ( v19 )
      {
        std::wstring::wstring(&key, L"HDR");
        LOBYTE(v100) = 15;
        std::wstring::wstring((std::wstring *)&color, L"TONEMAPPING");
        LOBYTE(v100) = 16;
        v20 = INIReader::getInt(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.tonemapUseHDRSpace = v20;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&key, L"EXPOSURE");
        LOBYTE(v100) = 17;
        std::wstring::wstring((std::wstring *)&color, L"TONEMAPPING");
        LOBYTE(v100) = 18;
        v21 = INIReader::getFloat(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.tonemapExposure = v21;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&key, L"GAMMA");
        LOBYTE(v100) = 19;
        std::wstring::wstring((std::wstring *)&color, L"TONEMAPPING");
        LOBYTE(v100) = 20;
        v22 = INIReader::getFloat(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.tonemapGamma = v22;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&key, L"FUNCTION");
        LOBYTE(v100) = 21;
        std::wstring::wstring((std::wstring *)&color, L"TONEMAPPING");
        LOBYTE(v100) = 22;
        v23 = INIReader::getInt(&ini, (const std::wstring *)&color, &key);
        v16 = v59 < 8;
        this->pp.tonemapFunc = v23;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        LOBYTE(v100) = 7;
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&section, L"SCALE_WIDTH");
        LOBYTE(v100) = 23;
        std::wstring::wstring((std::wstring *)&color, L"TONEMAPPING");
        LOBYTE(v100) = 24;
        v24 = INIReader::getFloat(&ini, (const std::wstring *)&color, &section);
        v16 = v59 < 8;
        this->pp.tonemapViewPortScaleWidth = v24;
        if ( !v16 )
          operator delete((void *)LODWORD(color.x));
        v59 = 7;
        v58 = 0;
        LOWORD(color.x) = 0;
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        std::wstring::wstring(&key, L"SCALE_HEIGHT");
        LOBYTE(v100) = 25;
        std::wstring::wstring(&section, L"TONEMAPPING");
        LOBYTE(v100) = 26;
        this->pp.tonemapViewPortScaleHeight = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"OFFSET_X");
        LOBYTE(v100) = 27;
        std::wstring::wstring(&section, L"TONEMAPPING");
        LOBYTE(v100) = 28;
        this->pp.tonemapViewPortOffsetX = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"OFFSET_Y");
        LOBYTE(v100) = 29;
        std::wstring::wstring(&section, L"TONEMAPPING");
        LOBYTE(v100) = 30;
        this->pp.tonemapViewPortOffsetY = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"MAPPING_FACTOR");
        LOBYTE(v100) = 31;
        std::wstring::wstring(&section, L"TONEMAPPING");
        LOBYTE(v100) = 32;
        this->pp.tonemapMappingFactor = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      }
      std::wstring::wstring(&key, L"AUTO_EXPOSURE");
      LOBYTE(v100) = 33;
      v25 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v44 = v25;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v25 = v44;
      }
      if ( v25 )
      {
        std::wstring::wstring(&key, L"ENABLED");
        LOBYTE(v100) = 34;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 35;
        this->pp.autoExposureEnabled = INIReader::getInt(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"DELAY");
        LOBYTE(v100) = 36;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 37;
        this->pp.autoExposureDelay = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"MIN");
        LOBYTE(v100) = 38;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 39;
        this->pp.autoExposureMin = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"MAX");
        LOBYTE(v100) = 40;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 41;
        this->pp.autoExposureMax = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"TARGET");
        LOBYTE(v100) = 42;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 43;
        this->pp.autoExposureTarget = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"INFLUENCED_BY_GLARE");
        LOBYTE(v100) = 44;
        std::wstring::wstring(&section, L"AUTO_EXPOSURE");
        LOBYTE(v100) = 45;
        this->pp.autoExposureInfluencedByGlare = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      }
      std::wstring::wstring(&key, L"AIRYDISC");
      LOBYTE(v100) = 46;
      v26 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v45 = v26;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v26 = v45;
      }
      if ( v26 )
      {
        std::wstring::wstring(&key, L"ENABLED");
        LOBYTE(v100) = 47;
        std::wstring::wstring(&section, L"AIRYDISC");
        LOBYTE(v100) = 48;
        this->pp.airydiskEnabled = INIReader::getInt(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"WAVELENGTH");
        LOBYTE(v100) = 49;
        std::wstring::wstring(&section, L"AIRYDISC");
        LOBYTE(v100) = 50;
        this->pp.airydiskWavelength = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"AIRY_DISC_DISPERSION_ENABLED");
        LOBYTE(v100) = 51;
        std::wstring::wstring(&section, L"AIRYDISC");
        LOBYTE(v100) = 52;
        this->pp.airydiskDispersion = INIReader::getInt(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      }
      std::wstring::wstring(&key, L"FEEDBACK");
      LOBYTE(v100) = 53;
      v27 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v46 = v27;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v27 = v46;
      }
      if ( v27 )
      {
        std::wstring::wstring(&key, L"ENABLED");
        LOBYTE(v100) = 54;
        std::wstring::wstring(&section, L"FEEDBACK");
        LOBYTE(v100) = 55;
        this->pp.feedbackEnabled = INIReader::getInt(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"ASPECT_RATIO");
        LOBYTE(v100) = 56;
        std::wstring::wstring(&section, L"FEEDBACK");
        LOBYTE(v100) = 57;
        this->pp.feedbackAspectRatio = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"WEIGHT");
        LOBYTE(v100) = 58;
        std::wstring::wstring(&section, L"FEEDBACK");
        LOBYTE(v100) = 59;
        this->pp.feedbackWeight = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring(&key, L"CURRENT_WEIGHT");
        LOBYTE(v100) = 60;
        std::wstring::wstring(&section, L"FEEDBACK");
        LOBYTE(v100) = 61;
        this->pp.feedbackCurrentWeight = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring((std::wstring *)&color, L"TIME");
        LOBYTE(v100) = 62;
        std::wstring::wstring(&section, L"FEEDBACK");
        LOBYTE(v100) = 63;
        this->pp.feedbackTimeInSeconds = INIReader::getFloat(&ini, &section, (const std::wstring *)&color);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&color);
      }
      std::wstring::wstring(&key, L"VIGNETTING");
      LOBYTE(v100) = 64;
      v28 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v47 = v28;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v28 = v47;
      }
      if ( v28 )
      {
        std::wstring::wstring(&key, L"STRENGTH");
        LOBYTE(v100) = 65;
        std::wstring::wstring(&section, L"VIGNETTING");
        LOBYTE(v100) = 66;
        this->pp.vignetteStrength = INIReader::getFloat(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring((std::wstring *)&color, L"FOV_DEPENDENCE");
        LOBYTE(v100) = 67;
        std::wstring::wstring(&section, L"VIGNETTING");
        LOBYTE(v100) = 68;
        this->pp.vignetteFovDependence = INIReader::getFloat(&ini, &section, (const std::wstring *)&color);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&color);
      }
      std::wstring::wstring(&key, L"CHROMATIC_ABERRATION");
      LOBYTE(v100) = 69;
      v29 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v48 = v29;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v29 = v48;
      }
      if ( v29 )
      {
        std::wstring::wstring(&key, L"ENABLED");
        LOBYTE(v100) = 70;
        std::wstring::wstring(&section, L"CHROMATIC_ABERRATION");
        LOBYTE(v100) = 71;
        this->pp.chromabEnabled = INIReader::getInt(&ini, &section, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        this->pp.chromabActive = this->pp.chromabEnabled;
        std::wstring::wstring(&v79, L"SAMPLES");
        LOBYTE(v100) = 72;
        std::wstring::wstring(&section, L"CHROMATIC_ABERRATION");
        LOBYTE(v100) = 73;
        this->pp.chromabSamples = INIReader::getInt(&ini, &section, &v79);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        std::wstring::wstring(&v75, L"LATERAL_DISPERSION");
        LOBYTE(v100) = 74;
        std::wstring::wstring(&v79, L"CHROMATIC_ABERRATION");
        LOBYTE(v100) = 75;
        INIReader::getFloat2(&ini, &lateralDispersion, &v79, &v75);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
        *(vec2f *)this->pp.chromabLateralDisp = lateralDispersion;
        std::wstring::wstring(&v62, L"UNIFORM_DISPERSION");
        LOBYTE(v100) = 76;
        std::wstring::wstring(&v75, L"CHROMATIC_ABERRATION");
        LOBYTE(v100) = 77;
        INIReader::getFloat2(&ini, (vec2f *)&color, &v75, &v62);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        this->pp.chromabUniformDisp[0] = color.x;
        this->pp.chromabUniformDisp[1] = color.y;
      }
      std::wstring::wstring(&key, L"DIAPHRAGM");
      LOBYTE(v100) = 78;
      v30 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v49 = v30;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v30 = v49;
      }
      if ( v30 )
      {
        std::wstring::wstring(&v75, L"ROTATE_SCALE");
        LOBYTE(v100) = 79;
        std::wstring::wstring(&v62, L"DIAPHRAGM");
        LOBYTE(v100) = 80;
        this->pp.diaphragmRotateScale = INIReader::getFloat(&ini, &v62, &v75);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
        std::wstring::wstring(&v79, L"ROTATE_OFFSET");
        LOBYTE(v100) = 81;
        std::wstring::wstring(&v62, L"DIAPHRAGM");
        LOBYTE(v100) = 82;
        this->pp.diaphragmRotateOffsetRad = INIReader::getFloat(&ini, &v62, &v79) * 0.017453;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        std::wstring::wstring(&section, L"TYPE");
        LOBYTE(v100) = 83;
        std::wstring::wstring(&v62, L"DIAPHRAGM");
        LOBYTE(v100) = 84;
        this->pp.diaphragmRotationType = INIReader::getInt(&ini, &v62, &section);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
      }
      std::wstring::wstring(&key, L"COLOR");
      LOBYTE(v100) = 85;
      v31 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v50 = v31;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v31 = v50;
      }
      if ( v31 )
      {
        std::wstring::wstring(&v75, L"HUE");
        LOBYTE(v100) = 86;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 87;
        this->pp.hue = INIReader::getFloat(&ini, &v62, &v75);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
        std::wstring::wstring(&v79, L"SATURATION");
        LOBYTE(v100) = 88;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 89;
        this->pp.saturation = INIReader::getFloat(&ini, &v62, &v79);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        std::wstring::wstring(&section, L"BRIGHTNESS");
        LOBYTE(v100) = 90;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 91;
        this->pp.brightness = INIReader::getFloat(&ini, &v62, &section);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        std::wstring::wstring(&key, L"CONTRAST");
        LOBYTE(v100) = 92;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 93;
        this->pp.contrast = INIReader::getFloat(&ini, &v62, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring((std::wstring *)&color, L"SEPIA");
        LOBYTE(v100) = 94;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 95;
        this->pp.sepia = INIReader::getFloat(&ini, &v62, (const std::wstring *)&color);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&color);
        std::wstring::wstring((std::wstring *)&lateralDispersion, L"COLOR_TEMP");
        LOBYTE(v100) = 96;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 97;
        this->pp.colorTemperatureK = INIReader::getFloat(&ini, &v62, (const std::wstring *)&lateralDispersion);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&lateralDispersion);
        std::wstring::wstring(&v63, L"WHITE_BALANCE");
        LOBYTE(v100) = 98;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 99;
        this->pp.whiteBalanceK = INIReader::getFloat(&ini, &v62, &v63);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
      }
      std::wstring::wstring(&key, L"GLARE");
      LOBYTE(v100) = 100;
      v32 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v51 = v32;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v32 = v51;
      }
      if ( v32 )
      {
        this->pp.glareShape = 1;
        this->pp.glareGhost = 1;
        this->pp.glareGhostConcentricDistortion = 0.5;
        this->pp.glareGhostActive = 1;
        this->pp.glareAfterImage = 0;
        this->pp.glareAnamorphicEnabled = 0;
        std::wstring::wstring(&v62, L"SHAPE");
        LOBYTE(v100) = 101;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 102;
        this->pp.glareShape = INIReader::getInt(&ini, &v63, &v62);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        std::wstring::wstring(&v75, L"GHOST");
        LOBYTE(v100) = 103;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 104;
        this->pp.glareGhost = INIReader::getInt(&ini, &v63, &v75);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
        std::wstring::wstring(&v79, L"GHOST_CONCENTRIC_DISTORTION");
        LOBYTE(v100) = 105;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 106;
        this->pp.glareGhostConcentricDistortion = INIReader::getFloat(&ini, &v63, &v79);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        this->pp.glareGhostActive = this->pp.glareGhost;
        std::wstring::wstring(&section, L"AFTER_IMAGE");
        LOBYTE(v100) = 107;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 108;
        this->pp.glareAfterImage = INIReader::getInt(&ini, &v63, &section);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
        std::wstring::wstring(&key, L"ANAMORPHIC");
        LOBYTE(v100) = 109;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 110;
        this->pp.glareAnamorphicEnabled = INIReader::getInt(&ini, &v63, &key);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
        std::wstring::wstring((std::wstring *)&color, L"LUMINANCE");
        LOBYTE(v100) = 111;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 112;
        this->pp.glareLuminance = INIReader::getFloat(&ini, &v63, (const std::wstring *)&color);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&color);
        std::wstring::wstring((std::wstring *)&lateralDispersion, L"PRECISION");
        LOBYTE(v100) = 113;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 114;
        this->pp.glarePrecision = INIReader::getInt(&ini, &v63, (const std::wstring *)&lateralDispersion);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&lateralDispersion);
        std::wstring::wstring(&v99.name, L"BLUR");
        LOBYTE(v100) = 115;
        std::wstring::wstring(&v63, L"GLARE");
        LOBYTE(v100) = 116;
        this->pp.glareBlur = INIReader::getFloat(&ini, &v63, &v99.name);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
        LOBYTE(v100) = 7;
        std::wstring::~wstring(&v99);
        std::wstring::wstring(&v86, L"BLOOM_FILTER_THRESHOLD");
        LOBYTE(v100) = 117;
        std::wstring::wstring(&v99.name, L"GLARE");
        LOBYTE(v100) = 118;
        this->pp.glareBloomFilterThreshold = INIReader::getFloat(&ini, &v99.name, &v86);
        std::wstring::~wstring(&v99);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v86);
        std::wstring::wstring(&v96, L"BLOOM_GAUSSIAN_RADIUS_SCALE");
        LOBYTE(v100) = 119;
        std::wstring::wstring(&v86, L"GLARE");
        LOBYTE(v100) = 120;
        this->pp.glareBloomGaussianRadiusScale = INIReader::getFloat(&ini, &v86, &v96);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v86);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
        std::wstring::wstring(&v88, L"BLOOM_LUMINANCE_GAMMA");
        LOBYTE(v100) = 121;
        std::wstring::wstring(&v96, L"GLARE");
        LOBYTE(v100) = 122;
        this->pp.glareBloomLuminanceGamma = INIReader::getFloat(&ini, &v96, &v88);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v88);
        std::wstring::wstring(&v94, L"BLOOM_NUM_LEVELS");
        LOBYTE(v100) = 123;
        std::wstring::wstring(&v88, L"GLARE");
        LOBYTE(v100) = 124;
        this->pp.glareBloomNumLevels = INIReader::getInt(&ini, &v88, &v94);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v88);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v94);
        std::wstring::wstring(&v90, L"GENERATION_RANGE_SCALE");
        LOBYTE(v100) = 125;
        std::wstring::wstring(&v94, L"GLARE");
        LOBYTE(v100) = 126;
        this->pp.glareGenerationRangeScale = INIReader::getFloat(&ini, &v94, &v90);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v94);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v90);
        std::wstring::wstring(&v98, L"THRESHOLD");
        LOBYTE(v100) = 127;
        std::wstring::wstring(&v90, L"GLARE");
        LOBYTE(v100) = 0x80;
        this->pp.glareThreshold = INIReader::getFloat(&ini, &v90, &v98);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v90);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v98);
        this->pp.glareBrightPass = 1;
        this->pp.glareStarFilterThreshold = 0.001;
        this->pp.glareStarSoftness = -1.0;
        this->pp.glareStarLengthFovDependence = 0.5;
        this->pp.glareUseCustomShape = 0;
        std::wstring::wstring(&v92, L"BRIGHT_PASS");
        LOBYTE(v100) = -127;
        std::wstring::wstring(&v98, L"GLARE");
        LOBYTE(v100) = -126;
        this->pp.glareBrightPass = INIReader::getInt(&ini, &v98, &v92);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v98);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v92);
        std::wstring::wstring(&v85, L"STAR_FILTER_THRESHOLD");
        LOBYTE(v100) = -125;
        std::wstring::wstring(&v92, L"GLARE");
        LOBYTE(v100) = -124;
        this->pp.glareStarFilterThreshold = INIReader::getFloat(&ini, &v92, &v85);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v92);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v85);
        std::wstring::wstring(&v84, L"STAR_SOFTNESS");
        LOBYTE(v100) = -123;
        std::wstring::wstring(&v85, L"GLARE");
        LOBYTE(v100) = -122;
        this->pp.glareStarSoftness = INIReader::getFloat(&ini, &v85, &v84);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v85);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
        std::wstring::wstring(&v89, L"STAR_LENGTH_FOV_DEPENDENCE");
        LOBYTE(v100) = -121;
        std::wstring::wstring(&v84, L"GLARE");
        LOBYTE(v100) = -120;
        this->pp.glareStarLengthFovDependence = INIReader::getFloat(&ini, &v84, &v89);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v89);
        std::wstring::wstring(&v91, L"USE_CUSTOM_SHAPE");
        LOBYTE(v100) = -119;
        std::wstring::wstring(&v89, L"GLARE");
        LOBYTE(v100) = -118;
        this->pp.glareUseCustomShape = INIReader::getInt(&ini, &v89, &v91);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v89);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v91);
        std::wstring::wstring(&v93, L"SHAPE_LUMINANCE");
        LOBYTE(v100) = -117;
        std::wstring::wstring(&v91, L"GLARE");
        LOBYTE(v100) = -116;
        this->pp.glareShapeLuminance = INIReader::getFloat(&ini, &v91, &v93);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v91);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v93);
        std::wstring::wstring(&v95, L"SHAPE_BLOOM_LUMINANCE");
        LOBYTE(v100) = -115;
        std::wstring::wstring(&v93, L"GLARE");
        LOBYTE(v100) = -114;
        this->pp.glareShapeBloomLuminance = INIReader::getFloat(&ini, &v93, &v95);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v93);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
        std::wstring::wstring(&v97, L"SHAPE_BLOOM_DISPERSION");
        LOBYTE(v100) = -113;
        std::wstring::wstring(&v95, L"GLARE");
        LOBYTE(v100) = -112;
        this->pp.glareShapeBloomDispersion = INIReader::getFloat(&ini, &v95, &v97);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
        std::wstring::wstring(&v83, L"SHAPE_BLOOM_DISPERSION_BASE_LEVEL");
        LOBYTE(v100) = -111;
        std::wstring::wstring(&v97, L"GLARE");
        LOBYTE(v100) = -110;
        this->pp.glareShapeBloomDispersionBaseLevel = INIReader::getInt(&ini, &v97, &v83);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
        std::wstring::wstring(&v80, L"SHAPE_GHOST_LUMINANCE");
        LOBYTE(v100) = -109;
        std::wstring::wstring(&v83, L"GLARE");
        LOBYTE(v100) = -108;
        this->pp.glareShapeGhostLuminance = INIReader::getFloat(&ini, &v83, &v80);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
        std::wstring::wstring(&v81, L"SHAPE_GHOST_HALO_LUMINANCE");
        LOBYTE(v100) = -107;
        std::wstring::wstring(&v80, L"GLARE");
        LOBYTE(v100) = -106;
        this->pp.glareShapeGhostHaloLuminance = INIReader::getFloat(&ini, &v80, &v81);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
        std::wstring::wstring(&v82, L"SHAPE_GHOST_DISTORTION");
        LOBYTE(v100) = -105;
        std::wstring::wstring(&v81, L"GLARE");
        LOBYTE(v100) = -104;
        this->pp.glareShapeGhostDistortion = INIReader::getFloat(&ini, &v81, &v82);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
        std::wstring::wstring(&v77, L"SHAPE_GHOST_SHARPENESS");
        LOBYTE(v100) = -103;
        std::wstring::wstring(&v82, L"GLARE");
        LOBYTE(v100) = -102;
        lateralDispersion.x = INIReader::getFloat(&ini, &v82, &v77);
        this->pp.glareShapeGhostSharpeness = lateralDispersion.x > 0.0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        std::wstring::wstring(&v71, L"SHAPE_STAR_LUMINANCE");
        LOBYTE(v100) = -101;
        std::wstring::wstring(&v77, L"GLARE");
        LOBYTE(v100) = -100;
        this->pp.glareShapeStarLuminance = INIReader::getFloat(&ini, &v77, &v71);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
        std::wstring::wstring(&v76, L"SHAPE_STAR_STREAKS_NUMBER");
        LOBYTE(v100) = -99;
        std::wstring::wstring(&v71, L"GLARE");
        LOBYTE(v100) = -98;
        this->pp.glareShapeStarStreaksNumber = INIReader::getInt(&ini, &v71, &v76);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
        std::wstring::wstring(&v74, L"SHAPE_STAR_LENGTH");
        LOBYTE(v100) = -97;
        std::wstring::wstring(&v76, L"GLARE");
        LOBYTE(v100) = -96;
        this->pp.glareShapeStarLength = INIReader::getFloat(&ini, &v76, &v74);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
        std::wstring::wstring(&v78, L"SHAPE_STAR_SECONDARY_LENGTH");
        LOBYTE(v100) = -95;
        std::wstring::wstring(&v74, L"GLARE");
        LOBYTE(v100) = -94;
        this->pp.glareShapeStarSecondaryLength = INIReader::getFloat(&ini, &v74, &v78);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
        std::wstring::wstring(&v72, L"SHAPE_STAR_ROTATION");
        LOBYTE(v100) = -93;
        std::wstring::wstring(&v78, L"GLARE");
        LOBYTE(v100) = -92;
        this->pp.glareShapeStarRotation = INIReader::getFloat(&ini, &v78, &v72);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
        std::wstring::wstring(&v73, L"SHAPE_STAR_INCLINATION_ANGLE");
        LOBYTE(v100) = -91;
        std::wstring::wstring(&v72, L"GLARE");
        LOBYTE(v100) = -90;
        this->pp.glareShapeStarInclinationAngle = INIReader::getFloat(&ini, &v72, &v73);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
        std::wstring::wstring(&v68, L"SHAPE_STAR_DISPERSION");
        LOBYTE(v100) = -89;
        std::wstring::wstring(&v73, L"GLARE");
        LOBYTE(v100) = -88;
        this->pp.glareShapeStarDispersion = INIReader::getFloat(&ini, &v73, &v68);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
        std::wstring::wstring(&v70, L"SHAPE_STAR_FORCE_DISPERSION");
        LOBYTE(v100) = -87;
        std::wstring::wstring(&v68, L"GLARE");
        LOBYTE(v100) = -86;
        this->pp.glareShapeStarForceDispersion = INIReader::getInt(&ini, &v68, &v70) > 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        std::wstring::wstring(&v69, L"SHAPE_AFTERIMAGE_LUMINANCE");
        LOBYTE(v100) = -85;
        std::wstring::wstring(&v70, L"GLARE");
        LOBYTE(v100) = -84;
        this->pp.glareShapeAfterimageLuminance = INIReader::getFloat(&ini, &v70, &v69);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::wstring(&v56, L"SHAPE_AFTERIMAGE_LENGTH");
        LOBYTE(v100) = -83;
        std::wstring::wstring(&v69, L"GLARE");
        LOBYTE(v100) = -82;
        this->pp.glareShapeAfterimageLength = INIReader::getFloat(&ini, &v69, &v56);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
      }
      std::wstring::wstring(&key, L"HEAT_SHIMMER");
      LOBYTE(v100) = -81;
      v33 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v52 = v33;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v33 = v52;
      }
      if ( v33 )
      {
        this->pp.heatParticleActive = 1;
        std::wstring::wstring(&v69, L"HEAT_PARTICLE_RADIUS");
        LOBYTE(v100) = -80;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -79;
        this->pp.heatParticleRadius = INIReader::getFloat(&ini, &v56, &v69);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::wstring(&v70, L"HEAT_PARTICLE_SHIMMER");
        LOBYTE(v100) = -78;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -77;
        this->pp.heatParticleShimmer = INIReader::getFloat(&ini, &v56, &v70);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        std::wstring::wstring(&v68, L"HEAT_PARTICLE_COORD");
        LOBYTE(v100) = -76;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -75;
        this->pp.heatParticleCoord = INIReader::getFloat(&ini, &v56, &v68);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
        std::wstring::wstring(&v73, L"HEAT_PARTICLE_FRACTAL_OCTAVES");
        LOBYTE(v100) = -74;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -73;
        this->pp.heatParticleFractalOctaves = INIReader::getFloat(&ini, &v56, &v73);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
        std::wstring::wstring(&v72, L"HEAT_PARTICLE_COLOR");
        LOBYTE(v100) = -72;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -71;
        INIReader::getFloat3(&ini, (vec3f *)&color, &v56, &v72);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
        this->pp.heatParticleColor[0] = color.x;
        this->pp.heatParticleColor[1] = color.y;
        this->pp.heatParticleColor[2] = color.z;
        std::wstring::wstring(&v78, L"HEAT_PARTICLE_MAX_NUMBER");
        LOBYTE(v100) = -70;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -69;
        this->pp.heatParticleMaxNumberPerSet = INIReader::getInt(&ini, &v56, &v78);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
        std::wstring::wstring(&v74, L"HEAT_PARTICLE_LIFE_MULT");
        LOBYTE(v100) = -68;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -67;
        this->pp.heatParticleLifeMult = INIReader::getFloat(&ini, &v56, &v74);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
        std::wstring::wstring(&v76, L"HEAT_PARTICLE_MIN_LIFE");
        LOBYTE(v100) = -66;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -65;
        this->pp.heatParticleMinLife = INIReader::getFloat(&ini, &v56, &v76);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
        std::wstring::wstring(&v71, L"HEAT_PARTICLE_INTENSITY_MULT");
        LOBYTE(v100) = -64;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -63;
        this->pp.heatParticleIntensityMult = INIReader::getFloat(&ini, &v56, &v71);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
        std::wstring::wstring(&v77, L"HEAT_PARTICLE_MIN_INTENSITY");
        LOBYTE(v100) = -62;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -61;
        this->pp.heatParticleMinIntensity = INIReader::getFloat(&ini, &v56, &v77);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        std::wstring::wstring(&v82, L"HEAT_PARTICLE_VELOCITY_MULT");
        LOBYTE(v100) = -60;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -59;
        this->pp.heatParticleIntensityVelocityMult = INIReader::getFloat(&ini, &v56, &v82);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
        std::wstring::wstring(&v81, L"HEAT_PARTICLE_MIN_VELOCITY");
        LOBYTE(v100) = -58;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -57;
        this->pp.heatParticleIntensityMinVelocity = INIReader::getFloat(&ini, &v56, &v81);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
        std::wstring::wstring(&v80, L"HEAT_PARTICLE_RADIUS_VELOCITY_MULT");
        LOBYTE(v100) = -56;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -55;
        this->pp.heatParticleRadiusVelocityMult = INIReader::getFloat(&ini, &v56, &v80);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
        std::wstring::wstring(&v83, L"HEAT_PARTICLE_POSITION_VELOCITY");
        LOBYTE(v100) = -54;
        std::wstring::wstring(&v56, L"HEAT_SHIMMER");
        LOBYTE(v100) = -53;
        v34 = INIReader::getFloat3(&ini, (vec3f *)&lateralDispersion, &v56, &v83);
        *(_QWORD *)&color.x = *(_QWORD *)&v34->x;
        color.z = v34->z;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
        *(_QWORD *)this->pp.heatParticlePositionVelocity = *(_QWORD *)&color.x;
        this->pp.heatParticlePositionVelocity[2] = color.z;
      }
      std::wstring::wstring(&key, L"GODRAYS");
      LOBYTE(v100) = -52;
      v35 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v53 = v35;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v35 = v53;
      }
      if ( v35 )
      {
        std::wstring::wstring(&v69, L"USE_SUN_LIGHT");
        LOBYTE(v100) = -51;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -50;
        this->pp.godraysUseSunLightColor = INIReader::getInt(&ini, &v56, &v69) != 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::wstring(&v70, L"DIFFRACTION_RING");
        LOBYTE(v100) = -49;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -48;
        this->pp.godraysDiffractionRing = INIReader::getFloat(&ini, &v56, &v70);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        std::wstring::wstring(&v68, L"DIFFRACTION_RING_RADIUS");
        LOBYTE(v100) = -47;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -46;
        this->pp.godraysDiffractionRadius = INIReader::getFloat(&ini, &v56, &v68) * 0.017453;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
        std::wstring::wstring(&v73, L"DIFFRACTION_RING_ATTENUATION");
        LOBYTE(v100) = -45;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -44;
        this->pp.godraysDiffractionRingAttenuation = INIReader::getFloat(&ini, &v56, &v73);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
        std::wstring::wstring(&v72, L"DIFFRACTION_RING_SPECTRUM_ORDER");
        LOBYTE(v100) = -43;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -42;
        this->pp.godraysDiffractionRingSpectrumOrder = INIReader::getFloat(&ini, &v56, &v72);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
        std::wstring::wstring(&v78, L"DIFFRACTION_RING_OUTER_COLOR");
        LOBYTE(v100) = -41;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -40;
        INIReader::getFloat4(&ini, &color, &v56, &v78);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
        *(__m128i *)this->pp.godraysDiffractionRingOuterColor = _mm_loadu_si128((const __m128i *)&color);
        std::wstring::wstring(&v74, L"COLOR");
        LOBYTE(v100) = -39;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -38;
        color = (vec4f)_mm_loadu_si128((const __m128i *)INIReader::getFloat4(
                                                          &ini,
                                                          (vec4f *)&lateralDispersion,
                                                          &v56,
                                                          &v74));
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
        *(__m128i *)this->pp.godraysColor = _mm_loadu_si128((const __m128i *)&color);
        std::wstring::wstring(&v76, L"LENGTH");
        LOBYTE(v100) = -37;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -36;
        this->pp.godraysLength = INIReader::getFloat(&ini, &v56, &v76);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
        std::wstring::wstring(&v71, L"GLARE_RATIO");
        LOBYTE(v100) = -35;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -34;
        this->pp.godraysGlareRatio = INIReader::getFloat(&ini, &v56, &v71);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
        std::wstring::wstring(&v77, L"ANGLE_ATTENUATION");
        LOBYTE(v100) = -33;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -32;
        this->pp.godraysAngleAttenuation = INIReader::getFloat(&ini, &v56, &v77);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        std::wstring::wstring(&v82, L"NOISE_MASK");
        LOBYTE(v100) = -31;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -30;
        this->pp.godraysNoiseMask = INIReader::getFloat(&ini, &v56, &v82);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v82);
        std::wstring::wstring(&v81, L"NOISE_FREQUENCY");
        LOBYTE(v100) = -29;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -28;
        this->pp.godraysNoiseFrequency = INIReader::getFloat(&ini, &v56, &v81);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v81);
        std::wstring::wstring(&v80, L"DEPTH_MASK_THRESHOLD");
        LOBYTE(v100) = -27;
        std::wstring::wstring(&v56, L"GODRAYS");
        LOBYTE(v100) = -26;
        this->pp.godraysDepthMaskThreshold = INIReader::getFloat(&ini, &v56, &v80);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v80);
      }
      std::wstring::wstring(&key, L"DOF");
      LOBYTE(v100) = -25;
      v36 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v54 = v36;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v36 = v54;
      }
      if ( v36 )
      {
        std::wstring::wstring(&v69, L"APERTURE_PARAMETER");
        LOBYTE(v100) = -24;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -23;
        this->pp.dofApertureParameter = INIReader::getInt(&ini, &v56, &v69);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::wstring(&v70, L"APERTURE_F_NUMBER");
        LOBYTE(v100) = -22;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -21;
        this->pp.dofApertureFNumber = INIReader::getFloat(&ini, &v56, &v70);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        std::wstring::wstring(&v68, L"IMAGE_SENSOR_HEIGHT");
        LOBYTE(v100) = -20;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -19;
        this->pp.dofImageSensorHeight = INIReader::getFloat(&ini, &v56, &v68);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
        std::wstring::wstring(&v73, L"BASE_FOV");
        LOBYTE(v100) = -18;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -17;
        this->pp.dofVerticalFOVBaseRad = INIReader::getFloat(&ini, &v56, &v73) * 0.017453;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
        std::wstring::wstring(&v72, L"ADAPTIVE_APERTURE_FACTOR");
        LOBYTE(v100) = -16;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -15;
        this->pp.dofAdaptiveApertureFactor = INIReader::getFloat(&ini, &v56, &v72);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v72);
        std::wstring::wstring(&v78, L"APERTURE_FRONT_LEVELS_NUMBER");
        LOBYTE(v100) = -14;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -13;
        this->pp.dofApertureFrontLevelsNumber = INIReader::getInt(&ini, &v56, &v78);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v78);
        std::wstring::wstring(&v74, L"APERTURE_BACK_LEVELS_NUMBER");
        LOBYTE(v100) = -12;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -11;
        this->pp.dofApertureBackLevelsNumber = INIReader::getInt(&ini, &v56, &v74);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
        std::wstring::wstring(&v76, L"EDGE_QUALITY");
        LOBYTE(v100) = -10;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -9;
        this->pp.dofEdgeQuality = INIReader::getInt(&ini, &v56, &v76);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v76);
        std::wstring::wstring(&v71, L"BACKGROUND_MASK_THRESHOLD");
        LOBYTE(v100) = -8;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -7;
        this->pp.dofBackgroundMaskThreshold = INIReader::getFloat(&ini, &v56, &v71);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
        std::wstring::wstring(&v77, L"APERTURE_SHAPE");
        LOBYTE(v100) = -6;
        std::wstring::wstring(&v56, L"DOF");
        LOBYTE(v100) = -5;
        this->pp.dofApertureType = INIReader::getInt(&ini, &v56, &v77);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v77);
        if ( this->pp.dofApertureType >= 6 )
        {
          _printf("WARNING: dofApertureType value %d is invalid ", this->pp.dofApertureType);
          this->pp.dofApertureType = 5;
          _printf("changed to:%d\n", 5);
        }
      }
      std::wstring::wstring(&key, L"LENSDISTORTION");
      LOBYTE(v100) = -4;
      v37 = INIReader::hasSection(&ini, &key);
      LOBYTE(v100) = 7;
      v38 = v37;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v38 )
      {
        std::wstring::wstring(&v69, L"ENABLED");
        LOBYTE(v100) = -3;
        std::wstring::wstring(&v56, L"LENSDISTORTION");
        LOBYTE(v100) = -2;
        this->pp.lensdistortionEnabled = INIReader::getInt(&ini, &v56, &v69);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
        std::wstring::wstring(&v70, L"ROUNDNESS");
        LOBYTE(v100) = -1;
        std::wstring::wstring(&v56, L"LENSDISTORTION");
        v100 = 256;
        v39 = INIReader::getFloat(&ini, &v56, &v70);
        v100 = 255;
        this->pp.lensdistortionRoundness = v39;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
        std::wstring::wstring(&v68, L"SMOOTHNESS");
        v100 = 257;
        std::wstring::wstring(&v56, L"LENSDISTORTION");
        LOBYTE(v100) = 2;
        this->pp.lensdistortionSmoothness = INIReader::getFloat(&ini, &v56, &v68);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        v100 = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
      }
      v12 = 1;
    }
    else
    {
      _printf("ERROR: YEBIS :: COULDN'T FIND INI\n");
      v12 = 0;
    }
    LOBYTE(v100) = 3;
    INIReader::~INIReader(&ini);
  }
  else
  {
    v11 = &filename;
    if ( filename._Myres >= 8 )
      v11 = (std::wstring *)filename._Bx._Ptr;
    _printf("PP SET ini %S not found in Documents, aborting\n", v11->_Bx._Buf);
    v12 = 0;
  }
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v12;
}
void __fastcall YebisPP::initPP(YebisPP *this, PPFX::CTextureUtil *a2)
{
  PPFX::CTextureUtil *v3; // edx
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  float v10; // xmm0_4
  bool v11; // zf
  int v12; // ecx
  GraphicsManager *v13; // eax
  int v14; // edi
  float v15; // xmm1_4
  int v16; // eax
  KGLYebisParticleManager *v17; // ecx
  KGLYebisParticleManager *v18; // eax
  KGLYebisParticleManager *v19; // eax
  int v20; // eax
  int v21; // ecx
  float v22; // xmm0_4
  ID3D11RenderTargetView *v23; // eax
  int v24; // eax
  __int64 v25; // rax
  int v26; // edi
  bool v27; // bl
  __int64 v28; // [esp+4h] [ebp-13Ch]
  float apertureAiryDiskEnabled; // [esp+20h] [ebp-120h]
  float v30; // [esp+24h] [ebp-11Ch]
  PPFX::PFX_DEVICEPARAM devParam; // [esp+28h] [ebp-118h] BYREF
  PPFX::PFX_INITPARAM initParam; // [esp+30h] [ebp-110h] BYREF
  int v33; // [esp+13Ch] [ebp-4h]

  if ( this->pPfxContext )
  {
    PPFX::IPfxBaseContext::Uninitialize(a2, (const char *)this, this->pPfxContext);
    PPFX::IPfxBaseContext::UninitializeDeviceResources(v4, v3, this->pPfxContext);
    this->pPfxContext->Release(this->pPfxContext);
    this->pPfxContext = 0;
  }
  if ( !this->pPfxContext )
  {
    _printf("RE-INSTANTIATE pPfxContext %p\n", 0);
    this->pPfxContext = (PPFX::IPfxContext_Dx11 *)PPFX::IPfxContext_Dx11::Instantiate();
  }
  v5 = 0x20000;
  if ( this->pp.chromabEnabled )
    v5 = 393216;
  if ( this->pp.godraysEnabled )
    v5 |= 0x10000000u;
  if ( this->pp.airydiskEnabled )
    v5 |= 0x40000u;
  v6 = this->pp.glareEnabled;
  if ( v6 && this->pp.glareAnamorphicEnabled )
    v5 |= 0x20000000u;
  if ( this->pp.feedbackEnabled )
    v5 |= (unsigned int)&loc_800000;
  if ( this->pp.lensdistortionEnabled )
    v5 |= 0x40000u;
  if ( v6 )
  {
    v7 = this->pp.glarePrecision;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( !v8 )
      {
        v5 |= 0x20u;
        goto LABEL_25;
      }
      if ( v8 == 1 )
      {
        v5 |= 0x40u;
        goto LABEL_25;
      }
    }
    v5 |= 0x10u;
  }
LABEL_25:
  PPFX::PFX_INITPARAM::PFX_INITPARAM(&initParam);
  PPFX::PFX_INITPARAM::Initialize(&initParam);
  v9 = this->pp.dofApertureType;
  v10 = this->pp.glareBlur;
  initParam.m_bGlareAfterimage = this->pp.glareAfterImage != 0;
  v11 = this->pp.glareGhost == 0;
  v12 = this->width;
  initParam.m_eApertureShape = v9;
  initParam.m_bGlareGhost = !v11;
  v13 = this->graphics;
  v14 = v5 | 0x200;
  initParam.m_fGlareResultBlur = v10;
  initParam.m_nMultisamples = 1;
  initParam.m_iMultisampleQuality = 0;
  initParam.m_eDepthOfFieldEdgeQuality = PFXDOFEDGE_AUTO;
  initParam.m_eTonemapResampleFilter = PFXRSF_AUTO;
  initParam.m_eAlphaOutput = PFXALPHAOUT_EFFECTRESULT_ALPHA;
  v15 = (float)((float)v13->videoSettings.ppQuality * 0.2) * (float)v12;
  this->pp.optFixedWidth = (int)v15;
  if ( !(int)v15 )
  {
    v16 = v12;
    if ( v12 > 640 )
      v16 = 640;
    this->pp.optFixedWidth = v16;
  }
  v11 = this->pp.heatParticleEnabled == 0;
  this->pp.optFixedWidth = v12;
  initParam.m_uiEffectBufferCriterionWidth = v12;
  if ( !v11 )
  {
    v17 = this->pHeatShimmerParticleManager;
    if ( v17 )
      KGLYebisParticleManager::`scalar deleting destructor'(v17, (unsigned int)this->pHeatShimmerParticleManager);
    v18 = (KGLYebisParticleManager *)operator new(0x10u);
    v33 = 0;
    if ( v18 )
      KGLYebisParticleManager::KGLYebisParticleManager(v18, &this->pp);
    else
      v19 = 0;
    v33 = -1;
    v14 |= 0x40000u;
    this->pHeatShimmerParticleManager = v19;
    initParam.m_uiMaxParticles = this->pp.heatParticleMaxNumberPerSet * this->pp.heatParticleSetsNumber;
  }
  v20 = this->height;
  v21 = this->width;
  devParam = 0i64;
  v22 = (float)this->pp.glareQuality;
  initParam.m_uiRenderSceneHeight = v20;
  initParam.m_uiEffectBufferHeight = v20;
  devParam.m_gpuContext = immediateContext;
  v23 = this->frameBuffer;
  initParam.m_uiRenderSceneWidth = v21;
  initParam.m_uiEffectBufferWidth = v21;
  devParam.m_gpuDeviceFramebuffer = v23;
  if ( PPFX::IPfxBaseContext::GetMaxGlareQuality() <= 5 )
    v24 = PPFX::IPfxBaseContext::GetMaxGlareQuality();
  else
    v24 = 5;
  apertureAiryDiskEnabled = (float)v24 * (float)(v22 * 0.2);
  v30 = (float)this->pp.dofQuality * 0.2;
  if ( (int)PPFX::IPfxBaseContext::GetMaxDepthOfFieldQuality() <= 5 )
    v25 = PPFX::IPfxBaseContext::GetMaxDepthOfFieldQuality();
  else
    LODWORD(v25) = 5;
  v26 = PPFX::IPfxBaseContext::Initialize(
          (int)&initParam,
          (PPFX::CTextureUtil *)HIDWORD(v25),
          this->pPfxContext,
          &devParam,
          (PPFX *)(int)apertureAiryDiskEnabled,
          (int)(float)((float)(int)v25 * v30),
          __SPAIR64__(&initParam, v14));
  if ( v26 < 0 )
    _printf("pPfxContext->Initialize failed\n");
  PPFX::IPfxBaseContext::SetDepthFactorRangeFloatOptimizeEnable(this->pPfxContext, 1);
  PPFX::IPfxBaseContext::SetVignetteParameters(this->pPfxContext, *(_QWORD *)&this->pp.vignetteStrength);
  v27 = this->pp.airydiskEnabled != 0;
  PPFX::IPfxBaseContext::SetApertureAiryDiscEnable(this->pPfxContext, v27);
  if ( v27 )
  {
    HIDWORD(v28) = this->pp.airydiskDispersion != 0;
    *(float *)&v28 = this->pp.airydiskWavelength * 9.9999997e-10;
    PPFX::IPfxBaseContext::SetApertureAiryDiscParameters(this->pPfxContext, v28);
  }
  if ( v26 < 0 )
  {
    _printf("ERROR: FAILED initializing  pPfxContext\n");
    _fflush(0);
    _exit(1);
  }
}
