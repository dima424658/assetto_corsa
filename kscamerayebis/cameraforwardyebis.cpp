#include "cameraforwardyebis.h"
void __usercall CameraForwardYebis::initPostProcessing(CameraForwardYebis *this@<ecx>, PPFX::CTextureUtil *a2@<edx>, const char *a3@<esi>)
{
  PPFX::IPfxContext_Dx11 *v4; // eax
  PPFX::CTextureUtil *v5; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  bool v13; // zf
  int v14; // eax
  int v15; // edi
  KGLYebisParticleManager *v16; // ecx
  KGLYebisParticleManager *v17; // eax
  KGLYebisParticleManager *v18; // eax
  float v19; // xmm0_4
  int v20; // esi
  float v21; // xmm0_4
  int *v22; // ecx
  int *v23; // eax
  int v24; // esi
  bool v25; // bl
  __int64 v26; // [esp+4h] [ebp-148h]
  __int64 v27; // [esp+4h] [ebp-148h]
  float apertureAiryDiskEnabled; // [esp+20h] [ebp-12Ch]
  int v29; // [esp+24h] [ebp-128h] BYREF
  int v30; // [esp+28h] [ebp-124h] BYREF
  int v31; // [esp+2Ch] [ebp-120h] BYREF
  int v32; // [esp+30h] [ebp-11Ch] BYREF
  PPFX::PFX_DEVICEPARAM devParam; // [esp+34h] [ebp-118h] BYREF
  float v34; // [esp+3Ch] [ebp-110h]
  PPFX::PFX_INITPARAM initParam; // [esp+40h] [ebp-10Ch] BYREF
  int v36; // [esp+148h] [ebp-4h]

  v4 = g_pPfxContext;
  if ( g_pPfxContext )
  {
    PPFX::IPfxBaseContext::Uninitialize(a2, a3, g_pPfxContext);
    PPFX::IPfxBaseContext::UninitializeDeviceResources(v6, v5, g_pPfxContext);
    g_pPfxContext->Release(g_pPfxContext);
    v4 = 0;
    g_pPfxContext = 0;
  }
  _printf("RE-INSTANTIATE g_pPfxContext %p\n", v4);
  v7 = 0;
  g_pPfxContext = (PPFX::IPfxContext_Dx11 *)PPFX::IPfxContext_Dx11::Instantiate();
  if ( this->pp.depthRenderTarget )
    v7 = 0x20000;
  if ( this->pp.chromabEnabled )
    v7 |= 0x40000u;
  if ( this->pp.godraysEnabled )
    v7 |= 0x10000000u;
  if ( this->pp.airydiskEnabled )
    v7 |= 0x40000u;
  v8 = this->pp.glareEnabled;
  if ( v8 && this->pp.glareAnamorphicEnabled )
    v7 |= 0x20000000u;
  if ( this->pp.feedbackEnabled )
    v7 |= (unsigned int)&loc_800000;
  if ( this->pp.lensdistortionEnabled )
    v7 |= 0x40000u;
  if ( v8 )
  {
    v9 = this->pp.glarePrecision;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( !v10 )
      {
        v7 |= 0x20u;
        goto LABEL_25;
      }
      if ( v10 == 1 )
      {
        v7 |= 0x40u;
        goto LABEL_25;
      }
    }
    v7 |= 0x10u;
  }
LABEL_25:
  PPFX::PFX_INITPARAM::PFX_INITPARAM(&initParam);
  v11 = this->pp.dofApertureType;
  v12 = this->pp.glareBlur;
  initParam.m_bGlareAfterimage = this->pp.glareAfterImage != 0;
  v13 = this->pp.glareGhost == 0;
  initParam.m_eApertureShape = v11;
  v14 = this->pp.optFixedWidth;
  initParam.m_bGlareGhost = !v13;
  v15 = v7 | 0x200;
  initParam.m_nMultisamples = 1;
  v13 = this->pp.heatParticleEnabled == 0;
  initParam.m_iMultisampleQuality = 0;
  initParam.m_eDepthOfFieldEdgeQuality = PFXDOFEDGE_AUTO;
  initParam.m_fGlareResultBlur = v12;
  initParam.m_eTonemapResampleFilter = PFXRSF_AUTO;
  initParam.m_eAlphaOutput = PFXALPHAOUT_EFFECTRESULT_ALPHA;
  initParam.m_uiEffectBufferCriterionWidth = v14;
  if ( !v13 )
  {
    v16 = this->g_pHeatShimmerParticleManager;
    if ( v16 )
      KGLYebisParticleManager::`scalar deleting destructor'(v16, (unsigned int)this->g_pHeatShimmerParticleManager);
    v17 = (KGLYebisParticleManager *)operator new(0x10u);
    v36 = 0;
    if ( v17 )
      KGLYebisParticleManager::KGLYebisParticleManager(v17, &this->pp);
    else
      v18 = 0;
    v36 = -1;
    v15 |= 0x40000u;
    this->g_pHeatShimmerParticleManager = v18;
    initParam.m_uiMaxParticles = this->pp.heatParticleMaxNumberPerSet * this->pp.heatParticleSetsNumber;
  }
  devParam = 0i64;
  v19 = (float)this->pp.glareQuality;
  devParam.m_gpuContext = immediateContext;
  devParam.m_gpuDeviceFramebuffer = (ID3D11View *)*((_DWORD *)this->pp.destinationRenderTarget + 1);
  apertureAiryDiskEnabled = v19 * 0.2;
  v20 = PPFX::IPfxBaseContext::GetMaxGlareQuality();
  v21 = (float)this->pp.dofQuality;
  v29 = v20;
  v30 = 5;
  v34 = v21 * 0.2;
  v32 = PPFX::IPfxBaseContext::GetMaxDepthOfFieldQuality();
  v31 = 5;
  HIDWORD(v26) = &initParam;
  v22 = &v32;
  if ( v32 >= 5 )
    v22 = &v31;
  LODWORD(v26) = v15;
  v23 = &v29;
  if ( v20 >= 5 )
    v23 = &v30;
  v24 = PPFX::IPfxBaseContext::Initialize(
          (int)&v30,
          (PPFX::CTextureUtil *)&v31,
          g_pPfxContext,
          &devParam,
          (PPFX *)(int)(float)((float)*v23 * apertureAiryDiskEnabled),
          (int)(float)((float)*v22 * v34),
          v26);
  if ( v24 < 0 )
    _printf("g_pPfxContext->Initialize failed\n");
  PPFX::IPfxBaseContext::SetDepthFactorRangeFloatOptimizeEnable(g_pPfxContext, 1);
  PPFX::IPfxBaseContext::SetVignetteParameters(g_pPfxContext, *(_QWORD *)&this->pp.vignetteStrength);
  v25 = this->pp.airydiskEnabled != 0;
  PPFX::IPfxBaseContext::SetApertureAiryDiscEnable(g_pPfxContext, v25);
  if ( v25 )
  {
    HIDWORD(v27) = this->pp.airydiskDispersion != 0;
    *(float *)&v27 = this->pp.airydiskWavelength * 9.9999997e-10;
    PPFX::IPfxBaseContext::SetApertureAiryDiscParameters(g_pPfxContext, v27);
  }
  if ( v24 < 0 )
  {
    _printf("ERROR: FAILED initializing  g_pPfxContext\n");
    _fflush(0);
    _exit(1);
  }
}
void CameraForwardYebis::setPostProcessing(CameraForwardYebis *this)
{
  char v2; // bl
  double v3; // st7
  unsigned int v4; // eax
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // ebp
  char v14; // al
  int v15; // ebx
  const __m128i *v16; // edi
  KGLYebisParticleManager *v17; // eax
  KGLYebisParticleSet *v18; // ecx
  char v19; // fl
  char v20; // bl
  char v21; // bl
  float v22; // xmm0_4
  bool v23; // al
  float v24; // xmm0_4
  bool v25; // zf
  char v26; // bl
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  _BYTE v31[12]; // [esp+8h] [ebp-C0h]
  __int64 v32; // [esp+8h] [ebp-C0h]
  int v33; // [esp+8h] [ebp-C0h]
  __int64 v34; // [esp+8h] [ebp-C0h]
  PPFX::IPfxContext_Dx11 *v35; // [esp+Ch] [ebp-BCh]
  __int64 v36; // [esp+Ch] [ebp-BCh]
  _BYTE v37[12]; // [esp+10h] [ebp-B8h]
  int v38; // [esp+10h] [ebp-B8h]
  int v39; // [esp+10h] [ebp-B8h]
  _BYTE v40[12]; // [esp+10h] [ebp-B8h]
  __int64 v41; // [esp+14h] [ebp-B4h]
  __int64 v42; // [esp+14h] [ebp-B4h]
  float v43; // [esp+18h] [ebp-B0h]
  int godraysEnabled[2]; // [esp+2Ch] [ebp-9Ch] BYREF
  __m128i v45; // [esp+34h] [ebp-94h] BYREF
  __m128i v46; // [esp+44h] [ebp-84h] BYREF
  PPFX::PFX_GLARESHAPEDEF shapeDef; // [esp+54h] [ebp-74h] BYREF
  __m128i v48; // [esp+9Ch] [ebp-2Ch] BYREF
  PPFX::VECTORT4<float> res; // [esp+ACh] [ebp-1Ch] BYREF
  __int64 v50; // [esp+BCh] [ebp-Ch]

  if ( g_pPfxContext )
  {
    *(_QWORD *)&v31[4] = *(_QWORD *)&this->pp.cameraFarPlane;
    *(float *)v31 = this->pp.cameraNearPlane;
    PPFX::IPfxBaseContext::SetRenderSceneParameters(
      (int)this,
      g_pPfxContext,
      *(__int64 *)v31,
      this->pp.cameraVerticalFOVRad,
      this->pp.dt,
      1.0);
    PPFX::IPfxBaseContext::SetRenderSceneCameraMatrix(g_pPfxContext, this->pp.cameraMatrix, 0);
    PPFX::IPfxBaseContext::SetRenderSceneViewMatrix(g_pPfxContext, (const __m128i *)this->pp.viewMatrix, 0);
    *(_QWORD *)&v37[4] = *(_QWORD *)&this->pp.cameraFarPlane;
    *(float *)v37 = this->pp.cameraNearPlane;
    PPFX::IPfxBaseContext::SetRenderScenePerspective(
      (int)this,
      g_pPfxContext,
      *(__int64 *)v37,
      this->pp.cameraVerticalFOVRad);
    LOBYTE(godraysEnabled[0]) = this->pp.autoExposureEnabled != 0;
    v2 = godraysEnabled[0];
    PPFX::IPfxBaseContext::SetAutoExposureEnable(g_pPfxContext, -1, godraysEnabled[0]);
    this->currentAutoExposure = this->pp.tonemapExposure;
    if ( v2 )
    {
      v3 = PPFX::IPfxBaseContext::GetAutoExposureAdjusted(g_pPfxContext, -1);
      v43 = this->pp.autoExposureDelay;
      v35 = g_pPfxContext;
      this->currentAutoExposure = v3;
      PPFX::IPfxBaseContext::SetAutoExposureDelay(v35, -1, PFXAAD_PHYSICALTIME, v43);
      if ( this->useAutoExposureLimits )
        PPFX::IPfxBaseContext::SetAutoExposureRange(g_pPfxContext, -1, *(_QWORD *)&this->pp.autoExposureMin);
      else
        PPFX::IPfxBaseContext::SetAutoExposureRange(g_pPfxContext, -1, 0x4120000000000000i64);
      PPFX::IPfxBaseContext::SetAutoExposureMeteringArea(g_pPfxContext, -1, 0x3F8000003F800000i64, 0.0, 0.0);
      HIDWORD(v41) = LODWORD(this->pp.autoExposureInfluencedByGlare);
      *(float *)&v41 = (float)((float)(this->exposure * 0.033333335) * this->pp.autoExposureTarget)
                     * this->graphics->exposureMultiplier;
      PPFX::IPfxBaseContext::SetAutoExposureMiddleGray(g_pPfxContext, -1, v41);
    }
    if ( this->pp.tonemapUseHDRSpace == 1 )
      v38 = this->pp.tonemapFunc;
    else
      v38 = 196610;
    HIDWORD(v32) = LODWORD(this->pp.tonemapGamma);
    *(float *)&v32 = this->currentAutoExposure;
    PPFX::IPfxBaseContext::SetTonemapParameters(
      g_pPfxContext,
      v32,
      (enum PPFX::EPFX_TONEMAP)v38,
      this->pp.tonemapMappingFactor,
      -3.4028235e38);
    PPFX::IPfxBaseContext::SetTonemapViewportScale(
      g_pPfxContext,
      *(_QWORD *)&this->pp.tonemapViewPortScaleWidth,
      this->pp.tonemapViewPortOffsetX,
      this->pp.tonemapViewPortOffsetY);
    if ( this->pp.heatParticleEnabled )
    {
      LOBYTE(godraysEnabled[0]) = this->pp.heatParticleActive != 0;
      PPFX::IPfxBaseContext::SetHeatShimmerParticleEnable(g_pPfxContext, godraysEnabled[0]);
      if ( LOBYTE(godraysEnabled[0]) )
      {
        v4 = _S10;
        if ( (_S10 & 1) != 0 )
        {
          v5 = s_vShimmerIntensity.w;
          v6 = s_vShimmerIntensity.z;
          v7 = s_vShimmerIntensity.y;
          v8 = s_vShimmerIntensity.x;
        }
        else
        {
          v4 = _S10 | 1;
          v5 = FLOAT_1_0;
          v6 = FLOAT_1_0;
          _S10 |= 1u;
          v7 = FLOAT_1_0;
          s_vShimmerIntensity.w = FLOAT_1_0;
          v8 = FLOAT_1_0;
          s_vShimmerIntensity.z = FLOAT_1_0;
          s_vShimmerIntensity.y = FLOAT_1_0;
          s_vShimmerIntensity.x = FLOAT_1_0;
        }
        if ( (v4 & 2) != 0 )
        {
          v9 = s_vShimmerScale.y;
          v10 = s_vShimmerScale.x;
        }
        else
        {
          v9 = FLOAT_1_0;
          v10 = FLOAT_1_0;
          _S10 = v4 | 2;
          s_vShimmerScale.y = FLOAT_1_0;
          s_vShimmerScale.x = FLOAT_1_0;
        }
        v11 = this->pp.heatParticleCoord;
        *(float *)godraysEnabled = v11 * v10;
        *(float *)&godraysEnabled[1] = v11 * v9;
        v12 = this->pp.heatParticleShimmer;
        *(__int64 *)((char *)v45.m128i_i64 + 4) = 0i64;
        v45.m128i_i32[0] = 0;
        *(float *)v46.m128i_i32 = v12 * v8;
        *(float *)&v46.m128i_i32[1] = v12 * v7;
        *(float *)&v46.m128i_i32[2] = v12 * v6;
        v33 = LODWORD(this->pp.heatParticleRadius);
        *(float *)&v46.m128i_i32[3] = v12 * v5;
        PPFX::IPfxBaseContext::SetHeatShimmerParticleParameters(
          (int)g_pPfxContext,
          v33,
          1065353216,
          &v46,
          godraysEnabled,
          (int)&v45);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleFractalOctave(
          g_pPfxContext,
          (int)this->pp.heatParticleFractalOctaves,
          2.7,
          0.28);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleFalloffDistance(g_pPfxContext, 1077936128i64, 1);
        PPFX::IPfxBaseContext::SetHeatShimmerParticleColor(
          g_pPfxContext,
          this->pp.heatParticleColor[0],
          this->pp.heatParticleColor[1],
          this->pp.heatParticleColor[2]);
        v13 = 0;
        v14 = 0;
        if ( this->pp.heatParticleSetsNumber > 0 )
        {
          v15 = 0;
          v16 = (const __m128i *)&this->pp.heatParticleSets[0].volume;
          do
          {
            if ( v16[-1].m128i_i32[3] )
            {
              v17 = this->g_pHeatShimmerParticleManager;
              res = (PPFX::VECTORT4<float>)_mm_loadu_si128(v16);
              v18 = &v17->sets._Myfirst[v15];
              v50 = v16[1].m128i_i64[0];
              KGLYebisParticleSet::update(v18, (const KGLVolume *)&res, &this->pp);
              v14 = 1;
            }
            ++v13;
            v16 = (const __m128i *)((char *)v16 + 28);
            ++v15;
          }
          while ( v13 < this->pp.heatParticleSetsNumber );
          if ( v14 )
            KGLYebisParticleManager::setupPfxParticles(this->g_pHeatShimmerParticleManager, g_pPfxContext);
        }
      }
    }
    if ( this->pp.dofEnabled )
    {
      PPFX::IPfxBaseContext::SetDepthOfFieldEnable(g_pPfxContext, this->pp.dofActive != 0);
      if ( this->pp.dofActive )
      {
        PPFX::IPfxBaseContext::SetDepthOfFieldParameters(
          g_pPfxContext,
          *(_QWORD *)&this->pp.dofFocusDistance,
          (enum PPFX::EPFX_DOFAPERTUREPARAM)this->pp.dofApertureParameter,
          this->pp.dofAdaptiveApertureFactor,
          this->pp.dofVerticalFOVBaseRad,
          this->pp.dofImageSensorHeight);
        PPFX::IPfxBaseContext::GetDepthFactorScaleOffset(v19, (int)g_pPfxContext, (__m128i *)&res);
        PPFX::IPfxBaseContext::SetDepthOfFieldApertureNumLevels(
          g_pPfxContext,
          this->pp.dofApertureFrontLevelsNumber,
          this->pp.dofApertureBackLevelsNumber);
        PPFX::IPfxBaseContext::SetDepthOfFieldBackgroundMaskThreshold(
          g_pPfxContext,
          this->pp.dofBackgroundMaskThreshold);
        PPFX::IPfxBaseContext::SetDepthOfFieldEdgeQuality(g_pPfxContext, (const char *)this->pp.dofEdgeQuality);
      }
    }
    if ( this->pp.godraysEnabled )
    {
      LOBYTE(godraysEnabled[0]) = this->pp.godraysInCameraFustrum != 0;
      v20 = godraysEnabled[0];
      PPFX::IPfxBaseContext::SetLightShaftEnable(g_pPfxContext, godraysEnabled[0]);
      if ( v20 )
      {
        PPFX::IPfxBaseContext::SetLightShaftPosition(g_pPfxContext, *(_QWORD *)this->pp.godraysOrigin);
        v45 = *(__m128i *)this->pp.godraysColor;
        PPFX::IPfxBaseContext::SetLightShaftParameters(
          (int)g_pPfxContext,
          &v45,
          *(_QWORD *)&this->pp.godraysLength,
          LODWORD(this->pp.godraysDepthMaskThreshold),
          6,
          LODWORD(this->pp.godraysAngleAttenuation),
          LODWORD(this->pp.godraysNoiseMask),
          LODWORD(this->pp.godraysNoiseFrequency));
        v48 = *(__m128i *)this->pp.godraysDiffractionRingOuterColor;
        HIDWORD(v34) = LODWORD(this->pp.godraysDiffractionRadius);
        *(float *)&v34 = this->pp.godraysDiffractionRing;
        PPFX::IPfxBaseContext::SetLightShaftDiffractionRing(
          (int)g_pPfxContext,
          v34,
          LODWORD(this->pp.godraysDiffractionRingAttenuation),
          LODWORD(this->pp.godraysDiffractionRingSpectrumOrder),
          &v48);
      }
    }
    if ( this->pp.chromabEnabled )
    {
      PPFX::IPfxBaseContext::SetChromaticAberrationEnable(g_pPfxContext, this->pp.chromabActive != 0);
      if ( this->pp.chromabActive )
      {
        v46.m128i_i32[0] = LODWORD(this->pp.chromabUniformDisp[0]);
        v39 = this->pp.chromabSamples;
        v46.m128i_i32[1] = LODWORD(this->pp.chromabUniformDisp[1]);
        v45.m128i_i64[0] = *(_QWORD *)this->pp.chromabLateralDisp;
        PPFX::IPfxBaseContext::SetChromaticAberrationParameters((int)g_pPfxContext, v39, &v45, &v46);
      }
    }
    if ( this->pp.diaphragmRotateScale != 0.0 || this->pp.diaphragmRotateOffsetRad != 0.0 )
      PPFX::IPfxBaseContext::SetDiaphragmRotate(
        g_pPfxContext,
        *(_QWORD *)&this->pp.diaphragmRotateScale,
        (enum PPFX::EPFX_DIAPHRAGMROTATE)this->pp.diaphragmRotationType);
    LOBYTE(godraysEnabled[0]) = this->pp.feedbackEnabled != 0;
    v21 = godraysEnabled[0];
    PPFX::IPfxBaseContext::SetFeedbackEnable(g_pPfxContext, godraysEnabled[0]);
    if ( v21 )
    {
      PPFX::IPfxBaseContext::SetFeedbackMatrixAspectRatio(g_pPfxContext, this->pp.feedbackAspectRatio);
      *(_QWORD *)&v40[4] = *(_QWORD *)&this->pp.feedbackCurrentWeight;
      *(float *)v40 = this->pp.feedbackWeight;
      PPFX::IPfxBaseContext::SetFeedbackWeight(g_pPfxContext, *(__int64 *)v40, this->pp.feedbackTimeInSeconds);
    }
    if ( this->pp.glareEnabled )
    {
      if ( this->pp.glareUseCustomShape )
      {
        memset(&shapeDef, 0, sizeof(shapeDef));
        PPFX::IPfxBaseContext::GetGlareShapeDefinition(g_pPfxContext, &shapeDef, this->pp.glareShape);
        v22 = this->pp.glareShapeLuminance * shapeDef.m_fGlareLuminance;
        shapeDef.m_iBloomDispersionBaseLevel = this->pp.glareShapeBloomDispersionBaseLevel;
        v23 = this->pp.glareShapeGhostSharpeness;
        shapeDef.m_fGlareLuminance = v22;
        v24 = this->pp.glareShapeBloomLuminance * shapeDef.m_fBloomLuminance;
        shapeDef.m_bGhostSharpness = v23;
        shapeDef.m_bStarRotation = 1;
        shapeDef.m_fBloomLuminance = v24;
        shapeDef.m_fBloomDispersion = this->pp.glareShapeBloomDispersion * shapeDef.m_fBloomDispersion;
        shapeDef.m_fGhostLuminance = this->pp.glareShapeGhostLuminance * shapeDef.m_fGhostLuminance;
        shapeDef.m_fGhostHaloLuminance = this->pp.glareShapeGhostHaloLuminance * shapeDef.m_fGhostHaloLuminance;
        shapeDef.m_fGhostDistortion = this->pp.glareShapeGhostDistortion * shapeDef.m_fGhostDistortion;
        shapeDef.m_fStarLuminance = this->pp.glareShapeStarLuminance * shapeDef.m_fStarLuminance;
        shapeDef.m_fStarLength = this->pp.glareShapeStarLength * shapeDef.m_fStarLength;
        shapeDef.m_fStarSecondaryLength = this->pp.glareShapeStarSecondaryLength * shapeDef.m_fStarSecondaryLength;
        shapeDef.m_fStarInclinationAngle = this->pp.glareShapeStarInclinationAngle * shapeDef.m_fStarInclinationAngle;
        shapeDef.m_fStarDispersion = this->pp.glareShapeStarDispersion * shapeDef.m_fStarDispersion;
        shapeDef.m_fAfterimageLuminance = this->pp.glareShapeAfterimageLuminance;
        shapeDef.m_fAfterimageLength = this->pp.glareShapeAfterimageLength;
        if ( this->pp.glareShapeStarRotation == 0.0 )
          shapeDef.m_bStarRotation = 0;
        v25 = this->pp.glareShapeStarForceDispersion == 0;
        shapeDef.m_nStarStreaks = this->pp.glareShapeStarStreaksNumber;
        shapeDef.m_bStarForceDispersion = !v25;
        PPFX::IPfxBaseContext::SetGlareShape(g_pPfxContext, (const __m128i *)&shapeDef);
      }
      else
      {
        PPFX::IPfxBaseContext::SetGlareShape(g_pPfxContext, (enum PPFX::EPFX_GLARESHAPE)this->pp.glareShape);
      }
      PPFX::IPfxBaseContext::SetGlareGhostConcentricDistortion(g_pPfxContext, this->pp.glareGhostConcentricDistortion);
      HIDWORD(v36) = LODWORD(this->pp.glareThreshold);
      *(float *)&v36 = this->pp.glareLuminance;
      PPFX::IPfxBaseContext::SetGlareParameters(
        g_pPfxContext,
        v36,
        (enum PPFX::EPFX_GLAREBRIGHTPASS)this->pp.glareBrightPass,
        1.0);
      PPFX::IPfxBaseContext::SetGlareBloomFilterThreshold(g_pPfxContext, this->pp.glareBloomFilterThreshold);
      PPFX::IPfxBaseContext::SetGlareBloomGaussianRadiusScale(g_pPfxContext, this->pp.glareBloomGaussianRadiusScale);
      PPFX::IPfxBaseContext::SetGlareBloomLuminanceGamma(g_pPfxContext, this->pp.glareBloomLuminanceGamma);
      PPFX::IPfxBaseContext::SetGlareBloomNumLevels(g_pPfxContext, this->pp.glareBloomNumLevels);
      PPFX::IPfxBaseContext::SetGlareGenerationRangeScale(g_pPfxContext, this->pp.glareGenerationRangeScale);
      PPFX::IPfxBaseContext::SetGlareStarFilterThreshold(g_pPfxContext, this->pp.glareStarFilterThreshold);
      PPFX::IPfxBaseContext::SetGlareStarSoftness(g_pPfxContext, this->pp.glareStarSoftness);
      PPFX::IPfxBaseContext::SetGlareStarLengthFovDependence(g_pPfxContext, this->pp.glareFovDependence);
      PPFX::IPfxBaseContext::SetGlareResultBlur(g_pPfxContext, this->pp.glareBlur);
      PPFX::IPfxBaseContext::SetGlareAnamorphicLensFlareEnable(g_pPfxContext, this->pp.glareAnamorphicEnabled != 0);
    }
    else
    {
      PPFX::IPfxBaseContext::SetGlareShape(g_pPfxContext, PFXGS_DISABLE);
    }
    LOBYTE(godraysEnabled[0]) = this->pp.lensdistortionEnabled != 0;
    v26 = godraysEnabled[0];
    PPFX::IPfxBaseContext::SetLensDistortionEnable(g_pPfxContext, godraysEnabled[0]);
    if ( v26 )
      PPFX::IPfxBaseContext::SetLensDistortionEdge(g_pPfxContext, *(_QWORD *)&this->pp.lensdistortionRoundness);
    PPFX::IPfxBaseContext::InitializeMatrix(g_pPfxContext, PFXMTX_TONEMAP_COLOR_HDRSPACE);
    v27 = this->pp.hue;
    if ( v27 != 0.0 )
    {
      HIDWORD(v42) = 1;
      *(float *)&v42 = (float)(v27 * 3.1415927) * 0.0055555557;
      PPFX::IPfxBaseContext::MultiplyMatrixColorHue(g_pPfxContext, PFXMTX_TONEMAP_COLOR_HDRSPACE, v42);
    }
    v28 = FLOAT_1_0;
    if ( this->pp.saturation != 1.0 )
    {
      PPFX::IPfxBaseContext::MultiplyMatrixColorSaturation(
        g_pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.saturation);
      v28 = FLOAT_1_0;
    }
    if ( this->pp.brightness != v28 )
    {
      PPFX::IPfxBaseContext::MultiplyMatrixColorBrightness(
        g_pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.brightness);
      v28 = FLOAT_1_0;
    }
    if ( this->pp.contrast != v28 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorContrast(
        g_pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        this->pp.contrast);
    if ( this->pp.sepia != 0.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorSepiaTone(g_pPfxContext, PFXMTX_TONEMAP_COLOR_HDRSPACE, this->pp.sepia);
    v29 = this->pp.colorTemperatureK;
    if ( v29 != 6500.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorTemperature(
        g_pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        LODWORD(v29) | 0x3F80000000000000i64);
    v30 = this->pp.whiteBalanceK;
    if ( v30 != 6500.0 )
      PPFX::IPfxBaseContext::MultiplyMatrixColorWhiteBalance(
        g_pPfxContext,
        PFXMTX_TONEMAP_COLOR_HDRSPACE,
        LODWORD(v30) | 0x3F80000000000000i64);
  }
}
void __usercall CameraForwardYebis::applyPostProcessing(CameraForwardYebis *this@<ecx>, _DWORD *a2@<ebx>)
{
  void *v3; // eax

  if ( g_pPfxContext )
  {
    if ( (dword_1873914 & 1) == 0 )
    {
      perfCounter_49.name = "CameraForwardYebis::applyPostProcessing";
      dword_1873914 |= 1u;
      perfCounter_49.group = Render;
      perfCounter_49.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CameraForwardYebis::applyPostProcessing" | 0xFF000000;
    }
    if ( PPFX::IPfxBaseContext::SetEffectSource(
           g_pPfxContext,
           *((struct ID3D11ShaderResourceView **)this->pp.sourceRenderTarget + 2),
           this->width,
           this->height,
           *((GPUUTIL **)this->pp.sourceRenderTarget + 4)) < 0 )
    {
      _printf("ERROR: FAILED g_pPfxContext->SetEffectSource(renderTarget\n");
      _fflush(0);
      _exit(1);
    }
    v3 = this->pp.depthRenderTarget;
    if ( v3
      && PPFX::IPfxBaseContext::SetDepthFactorSource(
           g_pPfxContext,
           PFXDFSRC_R,
           *((struct ID3D11ShaderResourceView **)v3 + 2),
           this->width,
           this->height,
           *((GPUUTIL **)v3 + 4),
           PFXDFFMT_DEPTHVALUE,
           1065353216i64) < 0 )
    {
      _printf(
        "ERROR: FAILED g_pPfxContext->SetDepthFactorSource(renderTarget) pointer is : %p\n",
        this->pp.depthRenderTarget);
      _fflush(0);
      _exit(1);
    }
    CameraForwardYebis::setPostProcessing(this);
    if ( PPFX::IPfxBaseContext::ApplyEffects(a2, g_pPfxContext, 0) < 0 )
    {
      _printf("ERROR: FAILED ApplyEffects()\n");
      _fflush(0);
      _exit(1);
    }
  }
}
void __userpurge CameraForwardYebis::CameraForwardYebis(CameraForwardYebis *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *iname, GraphicsManager *graphics, bool blur, bool isYebis, int numberOfParticleGenerators)
{
  Shader *v8; // eax
  bool v9; // cf
  RenderTarget *v10; // eax
  RenderTarget *v11; // eax
  Shader *v12; // eax
  std::wstring *v13; // eax
  _BYTE v14[28]; // [esp-1Ch] [ebp-60h] BYREF
  bool auseBlur[4]; // [esp+14h] [ebp-30h]
  CameraForwardYebis *v16; // [esp+18h] [ebp-2Ch]
  std::wstring name; // [esp+1Ch] [ebp-28h] BYREF
  int v18; // [esp+40h] [ebp-4h]

  auseBlur[0] = blur;
  v16 = this;
  CameraForward::CameraForward(this, iname, graphics, blur);
  v18 = 0;
  this->__vftable = (CameraForwardYebis_vtbl *)&CameraForwardYebis::`vftable';
  this->evOnPostYebisParametersUpdate.handlers._Myfirst = 0;
  this->evOnPostYebisParametersUpdate.handlers._Mylast = 0;
  this->evOnPostYebisParametersUpdate.handlers._Myend = 0;
  *(_WORD *)&this->debug_MotionBlurEnabled = 257;
  this->sunPosScreenSpace.x = 0.0;
  this->sunPosScreenSpace.y = 0.0;
  this->sunPosScreenSpace.z = 0.0;
  this->yebisEnabled = 0;
  this->currentAutoExposure = 0.0;
  this->currentPPSet._Myres = 7;
  this->currentPPSet._Mysize = 0;
  this->currentPPSet._Bx._Buf[0] = 0;
  this->baseBrightness = 0.0;
  this->baseSaturation = 0.0;
  Trigger::Trigger(&this->screenshotTrigger);
  LOBYTE(v18) = 3;
  this->g_pHeatShimmerParticleManager = 0;
  this->currentBufferIndex = 0;
  this->depthResolveShader = 0;
  this->fxaaShader = 0;
  this->pp.dofApertureFrontLevelsNumber = -1;
  this->pp.dofApertureBackLevelsNumber = -1;
  this->pp.dofBackgroundMaskThreshold = 0.1;
  this->pp.dofEdgeQuality = -1;
  this->width = 0;
  this->height = 0;
  this->fxaaTempRT = 0;
  *(_DWORD *)&v14[24] = 1592;
  this->yebisRT_MS._Elems[0] = 0;
  *(_DWORD *)&v14[20] = 0;
  this->yebisRT_Resolved_Color._Elems[0] = 0;
  *(_DWORD *)&v14[16] = &this->pp;
  this->yebisRT_Resolved_Depth._Elems[0] = 0;
  memset(*(void **)&v14[16], *(int *)&v14[20], *(size_t *)&v14[24]);
  if ( graphics->videoSettings.ppHDREnabled )
  {
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"ksMSDepthResolve", 0x10u);
    LOBYTE(v18) = 4;
    v8 = GraphicsManager::getShader(graphics, a2, &name);
    LOBYTE(v18) = 3;
    v9 = name._Myres < 8;
    this->depthResolveShader = v8;
    if ( !v9 )
      operator delete(name._Bx._Ptr);
    this->pp.antialiasEnabled = graphics->videoSettings.ppFXAA;
    this->pp.dofEnabled = graphics->videoSettings.ppDof != 0;
    this->pp.dofQuality = graphics->videoSettings.ppDof;
    this->pp.glareEnabled = graphics->videoSettings.ppGlare != 0;
    this->pp.glareQuality = graphics->videoSettings.ppGlare;
    this->pp.godraysEnabled = graphics->videoSettings.ppRaysOfGod;
    this->pp.heatParticleEnabled = graphics->videoSettings.ppHeatShimmer;
    this->pp.heatParticleSetsNumber = numberOfParticleGenerators;
    this->width = graphics->videoSettings.width;
    this->height = graphics->videoSettings.height;
    if ( graphics->videoSettings.ppFXAA )
    {
      v10 = (RenderTarget *)operator new(0x1Cu);
      *(_DWORD *)auseBlur = v10;
      LOBYTE(v18) = 5;
      if ( v10 )
        RenderTarget::RenderTarget(v10, graphics, eR8G8B8A8, this->width, this->height, 1, 0, 1);
      else
        v11 = 0;
      LOBYTE(v18) = 3;
      *(_DWORD *)&v14[24] = L"ksFXAA";
      this->fxaaTempRT = v11;
      std::wstring::wstring(&name, *(const wchar_t **)&v14[24]);
      LOBYTE(v18) = 6;
      v12 = GraphicsManager::getShader(graphics, (unsigned int)operator delete, &name);
      v9 = name._Myres < 8;
      this->fxaaShader = v12;
      if ( !v9 )
        operator delete(name._Bx._Ptr);
    }
    *(_DWORD *)v14 = &std::_Func_impl<std::_Callable_obj<_lambda_0b31ec168befd650aaa97b4af43d34d2_,0>,std::allocator<std::_Func_class<void,OnWindowResize const &>>,void,OnWindowResize const &>::`vftable';
    *(_DWORD *)&v14[4] = this;
    *(_DWORD *)&v14[16] = v14;
    LOBYTE(v18) = 3;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&graphics->evWindowPreResize,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v14,
      this);
    if ( !isYebis )
    {
      std::wstring::wstring((std::wstring *)&v14[4], L"default");
      if ( !CameraForwardYebis::loadPPSet(this, *(std::wstring *)&v14[4]) )
      {
        std::wstring::wstring(
          &name,
          L"Error, cannot initialize Post Processing, system/cfg/ppfilters/default.ini not found");
        LOBYTE(v18) = 8;
        v13 = &name;
        if ( name._Myres >= 8 )
          v13 = (std::wstring *)name._Bx._Ptr;
        _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v13->_Bx._Buf);
        ksGenerateCrash();
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
      }
    }
  }
}
CameraForwardYebis *__fastcall CameraForwardYebis::`vector deleting destructor'(CameraForwardYebis *this, PPFX::CTextureUtil *a2, unsigned int a3)
{
  CameraForwardYebis::~CameraForwardYebis(this, a2);
  if ( (a3 & 1) != 0 )
    operator delete(this);
  return this;
}
char CameraForwardYebis::readPPSetOptions(CameraForwardYebis *this, std::wstring name)
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
  bool v41; // [esp+17h] [ebp-415h]
  bool v42; // [esp+17h] [ebp-415h]
  bool v43; // [esp+17h] [ebp-415h]
  bool v44; // [esp+17h] [ebp-415h]
  bool v45; // [esp+17h] [ebp-415h]
  bool v46; // [esp+17h] [ebp-415h]
  bool v47; // [esp+17h] [ebp-415h]
  bool v48; // [esp+17h] [ebp-415h]
  bool v49; // [esp+17h] [ebp-415h]
  bool v50; // [esp+17h] [ebp-415h]
  bool v51; // [esp+17h] [ebp-415h]
  bool v52; // [esp+17h] [ebp-415h]
  bool v53; // [esp+17h] [ebp-415h]
  bool v54; // [esp+17h] [ebp-415h]
  std::wstring key; // [esp+18h] [ebp-414h] BYREF
  std::wstring v56; // [esp+30h] [ebp-3FCh] BYREF
  vec4f color; // [esp+48h] [ebp-3E4h] BYREF
  int v58; // [esp+58h] [ebp-3D4h]
  unsigned int v59; // [esp+5Ch] [ebp-3D0h]
  std::wstring section; // [esp+60h] [ebp-3CCh] BYREF
  INIReader ini; // [esp+78h] [ebp-3B4h] BYREF
  std::wstring v62; // [esp+BCh] [ebp-370h] BYREF
  std::wstring v63; // [esp+D4h] [ebp-358h] BYREF
  std::wstring filename; // [esp+ECh] [ebp-340h] BYREF
  vec2f lateralDispersion; // [esp+104h] [ebp-328h] BYREF
  int v66; // [esp+114h] [ebp-318h]
  unsigned int v67; // [esp+118h] [ebp-314h]
  std::wstring v68; // [esp+11Ch] [ebp-310h] BYREF
  std::wstring v69; // [esp+134h] [ebp-2F8h] BYREF
  std::wstring v70; // [esp+14Ch] [ebp-2E0h] BYREF
  std::wstring v71; // [esp+164h] [ebp-2C8h] BYREF
  std::wstring v72; // [esp+17Ch] [ebp-2B0h] BYREF
  std::wstring v73; // [esp+194h] [ebp-298h] BYREF
  std::wstring v74; // [esp+1ACh] [ebp-280h] BYREF
  std::wstring v75; // [esp+1C4h] [ebp-268h] BYREF
  std::wstring v76; // [esp+1DCh] [ebp-250h] BYREF
  std::wstring v77; // [esp+1F4h] [ebp-238h] BYREF
  std::wstring v78; // [esp+20Ch] [ebp-220h] BYREF
  std::wstring v79; // [esp+224h] [ebp-208h] BYREF
  std::wstring v80; // [esp+23Ch] [ebp-1F0h] BYREF
  std::wstring v81; // [esp+254h] [ebp-1D8h] BYREF
  std::wstring v82; // [esp+26Ch] [ebp-1C0h] BYREF
  std::wstring v83; // [esp+284h] [ebp-1A8h] BYREF
  std::wstring v84; // [esp+29Ch] [ebp-190h] BYREF
  std::wstring v85; // [esp+2B4h] [ebp-178h] BYREF
  std::wstring v86; // [esp+2CCh] [ebp-160h] BYREF
  std::wstring result; // [esp+2E4h] [ebp-148h] BYREF
  std::wstring v88; // [esp+2FCh] [ebp-130h] BYREF
  std::wstring v89; // [esp+314h] [ebp-118h] BYREF
  std::wstring v90; // [esp+32Ch] [ebp-100h] BYREF
  std::wstring v91; // [esp+344h] [ebp-E8h] BYREF
  std::wstring v92; // [esp+35Ch] [ebp-D0h] BYREF
  std::wstring v93; // [esp+374h] [ebp-B8h] BYREF
  std::wstring v94; // [esp+38Ch] [ebp-A0h] BYREF
  std::wstring v95; // [esp+3A4h] [ebp-88h] BYREF
  std::wstring v96; // [esp+3BCh] [ebp-70h] BYREF
  std::wstring v97; // [esp+3D4h] [ebp-58h] BYREF
  std::wstring v98; // [esp+3ECh] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v99; // [esp+404h] [ebp-28h] BYREF
  int v100; // [esp+428h] [ebp-4h]

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
        this->baseSaturation = INIReader::getFloat(&ini, &v62, &v79);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v62);
        LOBYTE(v100) = 7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v79);
        std::wstring::wstring(&section, L"BRIGHTNESS");
        LOBYTE(v100) = 90;
        std::wstring::wstring(&v62, L"COLOR");
        LOBYTE(v100) = 91;
        this->baseBrightness = INIReader::getFloat(&ini, &v62, &section);
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
char CameraForwardYebis::loadPPSet(CameraForwardYebis *this, std::wstring name)
{
  std::wstring *v3; // eax
  std::wstring *v4; // esi
  char v5; // bl
  std::wstring v7; // [esp-18h] [ebp-38h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  v3 = &name;
  v4 = &this->currentPPSet;
  v7._Myres = name._Mysize;
  if ( name._Myres >= 8 )
    v3 = (std::wstring *)name._Bx._Ptr;
  if ( std::wstring::compare(&this->currentPPSet, 0, this->currentPPSet._Mysize, v3->_Bx._Buf, v7._Myres) )
  {
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, &name, 0, 0xFFFFFFFF);
    if ( CameraForwardYebis::readPPSetOptions(this, v7) )
    {
      CameraForwardYebis::initRenderTargets(this);
      if ( v4 != &name )
        std::wstring::assign(v4, &name, 0, 0xFFFFFFFF);
      v5 = 1;
    }
    else
    {
      _printf("ERROR: Couldn't load requested PP set\n");
      v5 = 0;
    }
  }
  else
  {
    _printf("Requested set is the same already in use, no actions\n");
    v5 = 0;
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v5;
}
void CameraForwardYebis::initRenderTargets(CameraForwardYebis *this)
{
  RenderTarget *v2; // ecx
  RenderTarget *v3; // ecx
  RenderTarget *v4; // ecx
  RenderTarget *v5; // eax
  RenderTarget *v6; // eax
  RenderTarget *v7; // eax
  RenderTarget *v8; // eax
  RenderTarget *v9; // eax
  RenderTarget *v10; // eax
  RenderTarget *v11; // eax
  RenderTarget *v12; // eax
  int v13; // ecx
  void *v14; // eax
  void *v15; // eax
  PPFX::CTextureUtil *v16; // edx
  __m128i v17; // xmm0
  int v18; // eax
  bool v19; // cc
  int *v20; // eax
  int v21; // [esp+Ch] [ebp-10h] BYREF
  int v22; // [esp+18h] [ebp-4h]

  v2 = this->yebisRT_MS._Elems[0];
  if ( v2 )
  {
    ((void (*)(RenderTarget *, int))v2->~RenderTarget)(v2, 1);
    this->yebisRT_MS._Elems[0] = 0;
  }
  if ( this->graphics->videoSettings.aaSamples == 1 )
    this->yebisRT_Resolved_Color._Elems[0] = 0;
  v3 = this->yebisRT_Resolved_Depth._Elems[0];
  if ( v3 )
  {
    ((void (*)(RenderTarget *, int))v3->~RenderTarget)(v3, 1);
    this->yebisRT_Resolved_Depth._Elems[0] = 0;
  }
  v4 = this->yebisRT_Resolved_Color._Elems[0];
  if ( v4 )
  {
    ((void (*)(RenderTarget *, int))v4->~RenderTarget)(v4, 1);
    this->yebisRT_Resolved_Color._Elems[0] = 0;
  }
  if ( this->graphics->videoSettings.aaSamples == 1 )
  {
    v11 = (RenderTarget *)operator new(0x1Cu);
    v21 = (int)v11;
    v22 = 3;
    if ( v11 )
      RenderTarget::RenderTarget(v11, this->graphics, eR16G16B16A16, this->width, this->height, 1, 1, 1);
    else
      v12 = 0;
    v22 = -1;
    this->yebisRT_MS._Elems[0] = v12;
    this->yebisRT_Resolved_Color._Elems[0] = v12;
  }
  else
  {
    v5 = (RenderTarget *)operator new(0x1Cu);
    v21 = (int)v5;
    v22 = 0;
    if ( v5 )
      RenderTarget::RenderTarget(v5, this->graphics, eR16G16B16A16_MS, this->width, this->height, 1, 1, 1);
    else
      v6 = 0;
    this->yebisRT_MS._Elems[0] = v6;
    v7 = (RenderTarget *)operator new(0x1Cu);
    v21 = (int)v7;
    v22 = 1;
    if ( v7 )
      RenderTarget::RenderTarget(v7, this->graphics, eR16G16B16A16, this->width, this->height, 1, 0, 1);
    else
      v8 = 0;
    this->yebisRT_Resolved_Color._Elems[0] = v8;
    v9 = (RenderTarget *)operator new(0x1Cu);
    v21 = (int)v9;
    v22 = 2;
    if ( v9 )
    {
      RenderTarget::RenderTarget(v9, this->graphics, eR32F, this->width, this->height, 1, 0, 1);
      v22 = -1;
      this->yebisRT_Resolved_Depth._Elems[0] = v10;
    }
    else
    {
      v22 = -1;
      this->yebisRT_Resolved_Depth._Elems[0] = 0;
    }
  }
  v13 = this->currentBufferIndex;
  this->pp.sourceRenderTarget = this->yebisRT_Resolved_Color._Elems[v13]->kidColor;
  if ( this->graphics->videoSettings.aaSamples == 1 )
    v14 = this->yebisRT_MS._Elems[v13]->kidDepth;
  else
    v14 = this->yebisRT_Resolved_Depth._Elems[v13]->kidColor;
  this->pp.depthRenderTarget = v14;
  v15 = this->getYebisDestinationRenderTarget(this);
  v17 = _mm_cvtsi32_si128(this->width);
  this->pp.destinationRenderTarget = v15;
  v18 = (int)(float)((float)((float)this->graphics->videoSettings.ppQuality * 0.2) * _mm_cvtepi32_ps(v17).m128_f32[0]);
  this->pp.optFixedWidth = v18;
  if ( !v18 )
  {
    v19 = this->width < 640;
    v20 = &v21;
    v21 = 640;
    if ( v19 )
      v20 = &this->width;
    this->pp.optFixedWidth = *v20;
  }
  CameraForwardYebis::initPostProcessing(this, v16, (const char *)this);
}
void __userpurge CameraForwardYebis::onResize(CameraForwardYebis *this@<ecx>, unsigned int a2@<ebx>, const OnWindowResize *message)
{
  PPFX::CTextureUtil *v4; // edx
  PPFX::CTextureUtil *v5; // edx
  int v6; // ecx

  CameraForward::onResize(this, a2, message);
  *(OnWindowResize *)&this->width = *message;
  _printf("CameraForwardYebis::onResize\n");
  if ( g_pPfxContext )
  {
    PPFX::IPfxBaseContext::Uninitialize(v4, (const char *)message, g_pPfxContext);
    PPFX::IPfxBaseContext::UninitializeDeviceResources(v6, v5, g_pPfxContext);
    g_pPfxContext->Release(g_pPfxContext);
    g_pPfxContext = 0;
  }
  if ( this->graphics->videoSettings.ppHDREnabled )
    CameraForwardYebis::initRenderTargets(this);
}
void __usercall CameraForwardYebis::updateYebisParameters(CameraForwardYebis *this@<ecx>, float a2@<xmm1>)
{
  float v4; // xmm0_4
  float v5; // eax
  float v6; // xmm0_4
  bool v7; // zf
  GraphicsManager *v8; // edi
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // eax
  CameraForwardYebis_vtbl *v15; // eax
  GraphicsManager *v16; // eax
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  float v25; // xmm1_4
  mat44f *v26; // eax
  float v27; // xmm5_4
  float v28; // xmm4_4
  __m128 v29; // xmm7
  __m128 v30; // xmm6
  float v31; // xmm1_4
  float v32; // eax
  void *v33; // edi
  ID3D11RenderTargetView *v34; // edx
  int v35; // edx
  void *v36; // edi
  ID3D11RenderTargetView *v37; // edx
  int v38; // edx
  vec3f cameraUpVector; // [esp+40h] [ebp-B4h] BYREF
  vec3f cameraPosition; // [esp+4Ch] [ebp-A8h] BYREF
  float v41; // [esp+58h] [ebp-9Ch]
  float v42; // [esp+5Ch] [ebp-98h]
  float v43; // [esp+60h] [ebp-94h]
  vec3f cameraTarget; // [esp+64h] [ebp-90h] BYREF
  mat44f result; // [esp+70h] [ebp-84h] BYREF
  __m128i v46; // [esp+B0h] [ebp-44h] BYREF
  __m128i v47; // [esp+C0h] [ebp-34h] BYREF
  __m128i v48; // [esp+D0h] [ebp-24h] BYREF
  __m128i v49; // [esp+E0h] [ebp-14h] BYREF

  v4 = this->fov * 0.017453;
  v5 = this->nearPlane;
  this->pp.dt = a2;
  this->pp.cameraVerticalFOVRad = v4;
  v6 = this->farPlane;
  this->pp.cameraNearPlane = v5;
  this->pp.cameraFarPlane = v6;
  if ( v6 <= 1000.0 )
  {
    if ( v6 < 1.0 )
      v6 = FLOAT_1_0;
  }
  else
  {
    v6 = FLOAT_1000_0;
  }
  this->pp.cameraFarPlane = v6;
  v7 = !this->pp.godraysUseSunLightColor;
  v8 = this->graphics;
  this->pp.dofActive = this->dofFactor != 0.0;
  this->pp.chromabActive = this->chromaticAberrationEnabled;
  this->pp.dofFocusDistance = this->dofFocus;
  this->pp.glareGhostActive = this->lensFlare;
  this->pp.brightness = this->baseBrightness;
  this->pp.saturation = v8->lightingSettings.saturation * this->baseSaturation;
  if ( !v7 )
  {
    v9 = __libm_sse2_powf(this).m128_f32[0];
    v10 = (float)((float)(v8->lightingSettings.sunLow.x - v8->lightingSettings.sunHigh.x) * v9)
        + v8->lightingSettings.sunHigh.x;
    v11 = (float)((float)(v8->lightingSettings.sunLow.y - v8->lightingSettings.sunHigh.y) * v9)
        + v8->lightingSettings.sunHigh.y;
    v12 = (float)((float)(v8->lightingSettings.sunLow.z - v8->lightingSettings.sunHigh.z) * v9)
        + v8->lightingSettings.sunHigh.z;
    cameraUpVector.x = v10;
    cameraUpVector.y = v11;
    cameraUpVector.z = v12;
    v13 = fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
    if ( v13 != 0.0 )
    {
      cameraUpVector.x = (float)(1.0 / v13) * v10;
      cameraUpVector.y = (float)(1.0 / v13) * v11;
      cameraUpVector.z = (float)(1.0 / v13) * v12;
    }
    v14 = cameraUpVector.z;
    *(_QWORD *)this->pp.godraysColor = *(_QWORD *)&cameraUpVector.x;
    this->pp.godraysColor[2] = v14;
    this->pp.godraysColor[3] = 1.0;
  }
  v15 = this->__vftable;
  *(__m128i *)this->pp.cameraMatrix = _mm_loadu_si128((const __m128i *)&this->matrix);
  *(__m128i *)&this->pp.cameraMatrix[4] = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  *(__m128i *)&this->pp.cameraMatrix[8] = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&this->pp.cameraMatrix[12] = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  v15->getViewMatrix(this, (mat44f *)&v46);
  v16 = this->graphics;
  *(__m128i *)this->pp.viewMatrix = _mm_loadu_si128(&v46);
  *(__m128i *)&this->pp.viewMatrix[4] = _mm_loadu_si128(&v47);
  *(__m128i *)&this->pp.viewMatrix[8] = _mm_loadu_si128(&v48);
  *(__m128i *)&this->pp.viewMatrix[12] = _mm_loadu_si128(&v49);
  LODWORD(v17) = LODWORD(v16->lightingSettings.lightDirection.x) ^ _xmm;
  LODWORD(v18) = LODWORD(v16->lightingSettings.lightDirection.y) ^ _xmm;
  LODWORD(v19) = LODWORD(v16->lightingSettings.lightDirection.z) ^ _xmm;
  if ( (float)((float)((float)(COERCE_FLOAT(LODWORD(this->matrix.M32) ^ _xmm) * v18)
                     + (float)(COERCE_FLOAT(LODWORD(this->matrix.M31) ^ _xmm) * v17))
             + (float)(COERCE_FLOAT(LODWORD(this->matrix.M33) ^ _xmm) * v19)) <= 0.0 )
  {
    this->pp.godraysInCameraFustrum = 0;
  }
  else
  {
    cameraUpVector = *(vec3f *)&this->matrix.M21;
    LODWORD(v20) = LODWORD(this->matrix.M31) ^ _xmm;
    v43 = v17 * 1000.0;
    cameraTarget.x = v20;
    LODWORD(v21) = LODWORD(this->matrix.M32) ^ _xmm;
    v42 = v18 * 1000.0;
    cameraTarget.y = v21;
    v22 = _mm_xor_ps((__m128)LODWORD(this->matrix.M33), (__m128)(unsigned int)_xmm);
    v41 = v19 * 1000.0;
    LODWORD(cameraTarget.z) = v22.m128_i32[0];
    cameraPosition.x = 0.0;
    cameraPosition.y = 0.0;
    cameraPosition.z = 0.0;
    mat44f::createLookAt(v22, &result, &cameraPosition, &cameraTarget, &cameraUpVector);
    v23 = (__m128)LODWORD(result.M21);
    v24 = (__m128)LODWORD(result.M22);
    v23.m128_f32[0] = (float)((float)((float)(result.M21 * v42) + (float)(result.M11 * v43)) + (float)(result.M31 * v41))
                    + result.M41;
    v24.m128_f32[0] = (float)((float)((float)(result.M22 * v42) + (float)(result.M12 * v43)) + (float)(result.M32 * v41))
                    + result.M42;
    v25 = (float)((float)(result.M23 * v42) + (float)(result.M13 * v43)) + (float)(result.M33 * v41);
    *(_QWORD *)&this->sunPosScreenSpace.x = _mm_unpacklo_ps(v23, v24).m128_u64[0];
    cameraPosition.z = v25 + result.M43;
    this->sunPosScreenSpace.z = v25 + result.M43;
    v26 = this->getPerspectiveMatrix(this, &result);
    v27 = this->sunPosScreenSpace.y;
    v23.m128_i32[0] = LODWORD(this->sunPosScreenSpace.x);
    v28 = this->sunPosScreenSpace.z;
    v29 = (__m128)LODWORD(v26->M21);
    v30 = (__m128)LODWORD(v26->M12);
    v31 = (float)((float)((float)(v26->M14 * v23.m128_f32[0]) + (float)(v26->M24 * v27)) + (float)(v26->M34 * v28))
        + v26->M44;
    v29.m128_f32[0] = (float)((float)((float)((float)(v29.m128_f32[0] * v27) + (float)(v26->M11 * v23.m128_f32[0]))
                                    + (float)(v26->M31 * v28))
                            + v26->M41)
                    * (float)(1.0 / v31);
    v30.m128_f32[0] = (float)((float)((float)((float)(v30.m128_f32[0] * v23.m128_f32[0]) + (float)(v26->M22 * v27))
                                    + (float)(v26->M32 * v28))
                            + v26->M42)
                    * (float)(1.0 / v31);
    cameraPosition.z = (float)((float)((float)((float)(v26->M13 * v23.m128_f32[0]) + (float)(v26->M23 * v27))
                                     + (float)(v26->M33 * v28))
                             + v26->M43)
                     * (float)(1.0 / v31);
    v32 = cameraPosition.z;
    *(_QWORD *)&this->sunPosScreenSpace.x = _mm_unpacklo_ps(v29, v30).m128_u64[0];
    this->sunPosScreenSpace.z = v32;
    v24.m128_f32[0] = (float)(this->sunPosScreenSpace.x + 1.0) * 0.5;
    v23.m128_f32[0] = 1.0 - (float)((float)(this->sunPosScreenSpace.y + 1.0) * 0.5);
    LODWORD(this->sunPosScreenSpace.x) = v24.m128_i32[0];
    this->sunPosScreenSpace.y = v23.m128_f32[0];
    LODWORD(this->pp.godraysOrigin[0]) = v24.m128_i32[0];
    this->pp.godraysOrigin[1] = this->sunPosScreenSpace.y;
    this->pp.godraysInCameraFustrum = 1;
  }
  GraphicsManager::clearTextureSlot(this->graphics, 5);
  v33 = this->yebisRT_MS._Elems[this->currentBufferIndex]->kidColor;
  v34 = (ID3D11RenderTargetView *)*((_DWORD *)v33 + 1);
  if ( v34 )
    immediateContext->ClearRenderTargetView(immediateContext, v34, color);
  v35 = *((_DWORD *)v33 + 3);
  if ( v35 )
    ((void (__stdcall *)(ID3D11DeviceContext *, int, int, int, _DWORD))immediateContext->ClearDepthStencilView)(
      immediateContext,
      v35,
      1,
      1065353216,
      0);
  v36 = this->yebisRT_MS._Elems[this->currentBufferIndex]->kidDepth;
  v37 = (ID3D11RenderTargetView *)*((_DWORD *)v36 + 1);
  if ( v37 )
    immediateContext->ClearRenderTargetView(immediateContext, v37, color);
  v38 = *((_DWORD *)v36 + 3);
  if ( v38 )
    ((void (__stdcall *)(ID3D11DeviceContext *, int, int, int, _DWORD))immediateContext->ClearDepthStencilView)(
      immediateContext,
      v38,
      1,
      1065353216,
      0);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
}
void CameraForwardYebis::render(CameraForwardYebis *this, Node *blurred, Node *unblurred, Node *shadow, float dt)
{
  GraphicsManager *v6; // ecx
  bool v7; // zf
  void *v8; // eax
  OnGearRequestEvent message; // [esp+1Ch] [ebp-34h] BYREF
  std::wstring name; // [esp+24h] [ebp-2Ch] BYREF
  int v11; // [esp+4Ch] [ebp-4h]

  v6 = this->graphics;
  v7 = !v6->videoSettings.ppHDREnabled;
  message.nextGear = (int)unblurred;
  if ( v7 )
  {
    CameraForward::render(this, blurred, unblurred, shadow, dt);
  }
  else
  {
    this->currentBufferIndex = 0;
    this->pp.sourceRenderTarget = this->yebisRT_Resolved_Color._Elems[0]->kidColor;
    if ( v6->videoSettings.aaSamples == 1 )
      v8 = this->yebisRT_MS._Elems[0]->kidDepth;
    else
      v8 = this->yebisRT_Resolved_Depth._Elems[0]->kidColor;
    this->pp.depthRenderTarget = v8;
    ((void (*)(CameraForwardYebis *, Node *, _DWORD))this->shadowMapPass)(this, shadow, LODWORD(dt));
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"SHADOW_MAP", 0xAu);
    v11 = 0;
    GPUProfiler::triggerQuery(this->graphics->gpuProfiler, &name);
    v11 = -1;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    if ( blurred )
      CubeMapRenderer::render(&this->cubeMapRenderer, this->cubeMap, blurred, this);
    CameraForwardYebis::updateYebisParameters(this, dt);
    HIBYTE(message.request) = 1;
    Event<std::wstring>::trigger(
      (Event<OnGearRequestEvent> *)&this->evOnPostYebisParametersUpdate,
      (const OnGearRequestEvent *)((char *)&message.request + 3));
    CameraForwardYebis::renderApplyEffect(this, blurred, (Node *)message.nextGear, shadow, dt);
    this->resetYebisStates(this);
    if ( this->fxaaTempRT )
    {
      GraphicsManager::setTextureRT(this->graphics, 5u, this->fxaaTempRT);
      GLRenderer::fullScreenQuad(this->graphics->gl, this->fxaaShader);
    }
  }
}
KGLRenderTarget *CameraForwardYebis::getYebisDestinationRenderTarget(CameraForwardYebis *this)
{
  RenderTarget *v1; // eax
  KGLRenderTarget *result; // eax

  v1 = this->fxaaTempRT;
  if ( v1 )
    result = (KGLRenderTarget *)v1->kidColor;
  else
    result = screenRenderTarget;
  return result;
}
void CameraForwardYebis::resetYebisStates(CameraForwardYebis *this)
{
  ID3D11RenderTargetView **v2; // esi
  float v3; // xmm0_4
  int v4; // [esp+Ch] [ebp-20h] BYREF
  int v5[6]; // [esp+10h] [ebp-1Ch] BYREF

  kglSetDefaultState();
  GraphicsManager::setSamplerState(this->graphics);
  GraphicsManager::resetRenderStates(this->graphics);
  activeDepthStencilView = 0;
  if ( screenRenderTarget )
  {
    v2 = &screenRenderTarget->renderTargetView;
    immediateContext->OMSetRenderTargets(immediateContext, 1u, &screenRenderTarget->renderTargetView, 0);
    activeRenderTargetView = *v2;
  }
  else
  {
    v4 = 0;
    immediateContext->OMSetRenderTargets(immediateContext, 1u, (ID3D11RenderTargetView *const *)&v4, 0);
    activeRenderTargetView = 0;
  }
  v3 = (float)this->width;
  v5[4] = 0;
  v5[5] = 1065353216;
  v5[0] = 0;
  v5[1] = 0;
  *(float *)&v5[2] = v3;
  *(float *)&v5[3] = (float)this->height;
  immediateContext->RSSetViewports(immediateContext, 1u, (const D3D11_VIEWPORT *)v5);
}
void CameraForwardYebis::setSolveBlurRenderTarget(CameraForwardYebis *this)
{
  RenderTarget *v1; // eax

  if ( this->graphics->videoSettings.ppHDREnabled )
  {
    v1 = this->yebisRT_MS._Elems[this->currentBufferIndex];
    kglSetRenderTargets(v1->kidColor, v1->kidDepth);
  }
}
void CameraForwardYebis::renderApplyEffect(CameraForwardYebis *this, Node *blurred, Node *unblurred, Node *shadow, float dt)
{
  Node *v6; // ebx
  RenderTarget *v7; // eax
  bool v8; // zf
  GraphicsManager *v9; // ecx
  int v10; // eax
  char *v11; // esi
  ID3D11RenderTargetView **v12; // esi
  int v13; // [esp+24h] [ebp-44h]
  std::wstring name; // [esp+40h] [ebp-28h] BYREF
  int v15; // [esp+64h] [ebp-4h]

  v6 = blurred;
  v7 = this->yebisRT_MS._Elems[this->currentBufferIndex];
  kglSetRenderTargets(v7->kidColor, v7->kidDepth);
  GraphicsManager::beginMainRenderPass(this->graphics);
  v8 = !this->useBlur;
  this->renderTarget = this->yebisRT_MS._Elems[this->currentBufferIndex];
  if ( v8 || !this->debug_MotionBlurEnabled )
    ((void (*)(CameraForwardYebis *, Node *, _DWORD))this->renderPass)(this, shadow, LODWORD(dt));
  else
    CameraForward::renderBlurred(this, blurred, unblurred, shadow, dt);
  GraphicsManager::endMainRenderPass(this->graphics);
  if ( this->graphics->videoSettings.aaSamples != 1 )
  {
    ((void (__stdcall *)(ID3D11DeviceContext *, _DWORD, _DWORD, _DWORD, _DWORD, int, int))immediateContext->ResolveSubresource)(
      immediateContext,
      *(_DWORD *)this->yebisRT_Resolved_Color._Elems[this->currentBufferIndex]->kidColor,
      0,
      *(_DWORD *)this->yebisRT_MS._Elems[this->currentBufferIndex]->kidColor,
      0,
      10,
      v13);
    v9 = this->graphics;
    v6 = (Node *)v9->gl;
    GraphicsManager::setBlendMode(v9, eOpaque);
    v10 = this->currentBufferIndex;
    activeDepthStencilView = 0;
    v11 = (char *)this->yebisRT_Resolved_Depth._Elems[v10]->kidColor;
    if ( v11 )
    {
      v12 = (ID3D11RenderTargetView **)(v11 + 4);
      ((void (__stdcall *)(ID3D11DeviceContext *, int, ID3D11RenderTargetView **))immediateContext->OMSetRenderTargets)(
        immediateContext,
        1,
        v12);
      activeRenderTargetView = *v12;
    }
    else
    {
      name._Bx._Ptr = 0;
      ((void (__stdcall *)(ID3D11DeviceContext *, int, std::wstring *))immediateContext->OMSetRenderTargets)(
        immediateContext,
        1,
        &name);
      activeRenderTargetView = 0;
    }
    immediateContext->PSSetShaderResources(
      immediateContext,
      1u,
      1u,
      (ID3D11ShaderResourceView *const *)((char *)this->yebisRT_MS._Elems[this->currentBufferIndex]->kidDepth + 8));
    GraphicsManager::setViewport(this->graphics, 0, 0, this->width, this->height);
    GLRenderer::fullScreenQuad((GLRenderer *)v6, this->depthResolveShader);
  }
  CameraForwardYebis::applyPostProcessing(this, v6);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"YEBIS", 5u);
  v15 = 0;
  GPUProfiler::triggerQuery(this->graphics->gpuProfiler, &name);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void __fastcall CameraForwardYebis::~CameraForwardYebis(CameraForwardYebis *this, PPFX::CTextureUtil *a2)
{
  RenderTarget *v3; // ecx
  RenderTarget *v4; // ecx
  RenderTarget *v5; // ecx
  PPFX::CTextureUtil *v6; // edx
  int v7; // ecx
  std::pair<void *,std::function<void __cdecl(bool const &)> > *v8; // ebx
  std::pair<void *,std::function<void __cdecl(bool const &)> > *v9; // ebp
  std::_Func_base<void,bool const &> **v10; // edi

  this->__vftable = (CameraForwardYebis_vtbl *)&CameraForwardYebis::`vftable';
  v3 = this->yebisRT_MS._Elems[0];
  if ( v3 )
  {
    ((void (*)(RenderTarget *, int))v3->~RenderTarget)(v3, 1);
    this->yebisRT_MS._Elems[0] = 0;
  }
  v4 = this->yebisRT_Resolved_Depth._Elems[0];
  if ( v4 )
  {
    ((void (*)(RenderTarget *, int))v4->~RenderTarget)(v4, 1);
    this->yebisRT_Resolved_Depth._Elems[0] = 0;
  }
  v5 = this->fxaaTempRT;
  if ( v5 )
  {
    ((void (*)(RenderTarget *, int))v5->~RenderTarget)(v5, 1);
    this->fxaaTempRT = 0;
  }
  if ( g_pPfxContext )
  {
    PPFX::IPfxBaseContext::Uninitialize(a2, (const char *)this, g_pPfxContext);
    PPFX::IPfxBaseContext::UninitializeDeviceResources(v7, v6, g_pPfxContext);
    g_pPfxContext->Release(g_pPfxContext);
    g_pPfxContext = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->screenshotTrigger);
  if ( this->currentPPSet._Myres >= 8 )
    operator delete(this->currentPPSet._Bx._Ptr);
  this->currentPPSet._Myres = 7;
  this->currentPPSet._Mysize = 0;
  this->currentPPSet._Bx._Buf[0] = 0;
  v8 = this->evOnPostYebisParametersUpdate.handlers._Myfirst;
  if ( v8 )
  {
    v9 = this->evOnPostYebisParametersUpdate.handlers._Mylast;
    if ( v8 != v9 )
    {
      v10 = &v8->second._Impl;
      do
      {
        if ( *v10 )
        {
          ((void (__stdcall *)(bool))(*v10)->_Delete_this)(*v10 != (std::_Func_base<void,bool const &> *)(v10 - 4));
          *v10 = 0;
        }
        ++v8;
        v10 += 8;
      }
      while ( v8 != v9 );
    }
    operator delete(this->evOnPostYebisParametersUpdate.handlers._Myfirst);
    this->evOnPostYebisParametersUpdate.handlers._Myfirst = 0;
    this->evOnPostYebisParametersUpdate.handlers._Mylast = 0;
    this->evOnPostYebisParametersUpdate.handlers._Myend = 0;
  }
  CameraForward::~CameraForward(this);
}
