#include "suspensionstrut.h
mat44f *SuspensionStrut::getHubWorldMatrix(SuspensionStrut *this, mat44f *result)
{
  int v3; // ecx
  IRigidBody *v4; // ecx
  IRigidBody_vtbl *v5; // eax
  mat44f *(*v6)(IRigidBody *, mat44f *, float); // eax
  int v7; // eax
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __int128 v11; // xmm1
  __int128 v12; // xmm2
  __int128 v13; // xmm3
  mat44f *v14; // eax
  int v15; // [esp+4h] [ebp-A0h]
  int v16; // [esp+8h] [ebp-9Ch]
  float v17; // [esp+18h] [ebp-8Ch]
  float v18; // [esp+1Ch] [ebp-88h]
  __m128 v19; // [esp+24h] [ebp-80h] BYREF
  __int128 v20; // [esp+34h] [ebp-70h]
  __int128 v21; // [esp+44h] [ebp-60h]
  __int128 v22; // [esp+54h] [ebp-50h]
  DirectX::XMMATRIX M2_8; // [esp+64h] [ebp-40h] BYREF

  mat44f::mat44f(result);
  v17 = __libm_sse2_cosf(v15, v16).m128_f32[0];
  v18 = __libm_sse2_sinf(v3).m128_f32[0];
  mat44f::mat44f((mat44f *)&v19);
  v4 = this->hub;
  HIDWORD(v22) = 1065353216;
  v5 = v4->__vftable;
  *((float *)&v21 + 2) = (float)(1.0 - v17) + v17;
  v6 = v5->getWorldMatrix;
  v19.m128_f32[0] = (float)((float)(1.0 - v17) * 0.0) + v17;
  *((float *)&v20 + 1) = v19.m128_f32[0];
  v19.m128_f32[1] = v18 + (float)((float)(1.0 - v17) * 0.0);
  *(float *)&v20 = (float)((float)(1.0 - v17) * 0.0) - v18;
  v19.m128_f32[2] = (float)((float)(1.0 - v17) * 0.0) - (float)(v18 * 0.0);
  *(float *)&v21 = (float)(v18 * 0.0) + (float)((float)(1.0 - v17) * 0.0);
  *((float *)&v20 + 2) = *(float *)&v21;
  *((float *)&v21 + 1) = v19.m128_f32[2];
  v7 = ((int (__stdcall *)(DirectX::XMMATRIX *, _DWORD))v6)(&M2_8, 0);
  v8 = *(__m128 *)(v7 + 16);
  v9 = *(__m128 *)(v7 + 32);
  v10 = *(__m128 *)(v7 + 48);
  M2_8.r[0] = *(__m128 *)v7;
  M2_8.r[1] = v8;
  v11 = v20;
  M2_8.r[2] = v9;
  v12 = v21;
  M2_8.r[3] = v10;
  v13 = v22;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2_8.r, v19);
  v14 = result;
  *(_OWORD *)&result->M21 = v11;
  *(_OWORD *)&result->M31 = v12;
  *(_OWORD *)&result->M41 = v13;
  return v14;
}
double SuspensionStrut::getPackerRange(SuspensionStrut *this)
{
  return this->packerRange;
}
vec3f *SuspensionStrut::getVelocity(SuspensionStrut *this, vec3f *result)
{
  this->hub->getVelocity(this->hub, result);
  return result;
}
void __userpurge SuspensionStrut::SuspensionStrut(SuspensionStrut *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, Car *car, int index)
{
  float v7; // xmm1_4
  IPhysicsCore *v8; // eax
  IRigidBody *v9; // eax
  PhysicsEngine *v10; // ecx
  IPhysicsCore *v11; // eax
  IRigidBody *v12; // eax
  float v13; // xmm4_4
  IRigidBody *v14; // ecx
  float v15; // eax
  float v16; // eax
  unsigned __int64 v17; // [esp+3Ch] [ebp-1Ch]
  float v18; // [esp+44h] [ebp-14h]
  float indexa; // [esp+60h] [ebp+8h]

  this->bumpStopProgressive = 0.0;
  this->baseCFM = 0.0000001;
  this->__vftable = (SuspensionStrut_vtbl *)&SuspensionStrut::`vftable';
  this->basePosition.x = 0.0;
  this->basePosition.y = 0.0;
  this->basePosition.z = 0.0;
  SStrutSuspensionData::SStrutSuspensionData(&this->dataRelToWheel);
  SStrutSuspensionData::SStrutSuspensionData(&this->dataRelToBody);
  Damper::Damper(&this->damper);
  this->status.travel = 0.0;
  this->status.damperSpeedMS = 0.0;
  this->index = index;
  this->physicsEngine = car->ksPhysics;
  this->baseCarSteerPosition.x = 0.0;
  this->baseCarSteerPosition.y = 0.0;
  this->baseCarSteerPosition.z = 0.0;
  this->damageData.damageAmount = 0.0;
  this->damageData.minVelocity = 15.0;
  this->damageData.damageGain = 0.0;
  this->damageData.maxDamage = 0.0;
  this->damageData.isDebug = 0;
  this->damageData.lastAmount = 0.0;
  this->car = car;
  this->toeOUT_Linear = 0.0;
  this->steerTorque = 0.0;
  this->carBody = car->body;
  this->k = 90000.0;
  this->steerAngle = 0.0;
  this->staticCamber = 0.0;
  this->rodLength = 0.0;
  v7 = (float)((float)_rand() * 0.000030518509) * 100.0;
  this->damageData.damageDirection = v7;
  if ( v7 >= 50.0 )
    this->damageData.damageDirection = 1.0;
  else
    this->damageData.damageDirection = -1.0;
  SuspensionStrut::loadINI(this, (__m128)LODWORD(FLOAT_50_0), index);
  if ( this->dataRelToWheel.refPoint.x > 0.0 )
  {
    LODWORD(this->dataRelToWheel.carBottomWB_F.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carBottomWB_R.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carSteer.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carStrut.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreBottomWB.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreSteer.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreStrut.x) ^= _xmm;
  }
  v8 = PhysicsEngine::getCore(this->physicsEngine);
  v9 = v8->createRigidBody(v8);
  v10 = this->physicsEngine;
  this->hub = v9;
  v11 = PhysicsEngine::getCore(v10);
  v12 = v11->createRigidBody(v11);
  v13 = this->dataRelToWheel.hubMass;
  this->strutBody = v12;
  indexa = v13;
  if ( v13 <= 0.0 )
  {
    v13 = FLOAT_20_0;
    indexa = FLOAT_20_0;
  }
  v18 = this->dataRelToWheel.hubInertiaBox.z;
  v17 = *(_QWORD *)&this->dataRelToWheel.hubInertiaBox.x;
  if ( (float)((float)((float)(this->dataRelToWheel.hubInertiaBox.x * this->dataRelToWheel.hubInertiaBox.x)
                     + (float)(this->dataRelToWheel.hubInertiaBox.y * this->dataRelToWheel.hubInertiaBox.y))
             + (float)(v18 * v18)) == 0.0 )
  {
    v17 = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_0_2), (__m128)LODWORD(FLOAT_0_60000002)).m128_u64[0];
    v18 = 0.60000002;
  }
  ((void (*)(IRigidBody *, _DWORD, _DWORD, _DWORD, _DWORD))this->hub->setMassBox)(
    this->hub,
    v13 * 0.80000001,
    v17,
    HIDWORD(v17),
    LODWORD(v18));
  v14 = this->strutBody;
  this->strutBodyLength = 0.2;
  ((void (*)(IRigidBody *, _DWORD, int, int, int))v14->setMassBox)(
    v14,
    indexa * 0.2,
    1028443341,
    1056964608,
    1045220557);
  v15 = this->dataRelToWheel.refPoint.z;
  *(_QWORD *)&this->basePosition.x = *(_QWORD *)&this->dataRelToWheel.refPoint.x;
  this->basePosition.z = v15;
  this->joints[0] = 0;
  SuspensionStrut::attach(this, a2, a3, a4);
  v16 = this->dataRelToBody.carSteer.z;
  *(_QWORD *)&this->baseCarSteerPosition.x = *(_QWORD *)&this->dataRelToBody.carSteer.x;
  this->baseCarSteerPosition.z = v16;
  SuspensionStrut::setSteerLengthOffset(this, 0.0);
}
SuspensionStrut *SuspensionStrut::`scalar deleting destructor'(SuspensionStrut *this, unsigned int a2)
{
  this->__vftable = (SuspensionStrut_vtbl *)&SuspensionStrut::`vftable';
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->damper);
  this->__vftable = (SuspensionStrut_vtbl *)&ISuspension::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionStrut::addForceAtPos(SuspensionStrut *this, const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque)
{
  SuspensionStrut_vtbl *v6; // eax
  vec3f steercentre; // [esp+10h] [ebp-18h] BYREF
  vec3f steeraxis; // [esp+1Ch] [ebp-Ch] BYREF

  this->hub->addForceAtPos(this->hub, force, pos);
  if ( addToSteerTorque )
  {
    v6 = this->__vftable;
    steeraxis.x = 0.0;
    steeraxis.y = 0.0;
    steeraxis.z = 0.0;
    steercentre.x = 0.0;
    steercentre.y = 0.0;
    steercentre.z = 0.0;
    v6->getSteerBasis(this, &steercentre, &steeraxis);
    this->steerTorque = this->steerTorque
                      - (float)((float)((float)((float)((float)(force->z * (float)(pos->x - steercentre.x))
                                                      - (float)(force->x * (float)(pos->z - steercentre.z)))
                                              * steeraxis.y)
                                      + (float)((float)((float)(force->y * (float)(pos->z - steercentre.z))
                                                      - (float)(force->z * (float)(pos->y - steercentre.y)))
                                              * steeraxis.x))
                              + (float)((float)((float)(force->x * (float)(pos->y - steercentre.y))
                                              - (float)(force->y * (float)(pos->x - steercentre.x)))
                                      * steeraxis.z));
  }
}
void SuspensionStrut::addLocalForceAndTorque(SuspensionStrut *this, const vec3f *force, const vec3f *torque, const vec3f *driveTorque)
{
  IRigidBody *v5; // ecx
  SuspensionStrut_vtbl *v6; // eax
  float *v7; // eax
  float v8; // xmm7_4
  vec3f steercentre; // [esp+24h] [ebp-24h] BYREF
  vec3f steeraxis; // [esp+30h] [ebp-18h] BYREF
  int v11[3]; // [esp+3Ch] [ebp-Ch] BYREF

  v11[0] = 0;
  v5 = this->hub;
  v11[1] = 0;
  v11[2] = 0;
  v5->addForceAtLocalPos(v5, force, (const vec3f *)v11);
  this->hub->addTorque(this->hub, torque);
  v6 = this->__vftable;
  steeraxis.x = 0.0;
  steeraxis.y = 0.0;
  steeraxis.z = 0.0;
  steercentre.x = 0.0;
  steercentre.y = 0.0;
  steercentre.z = 0.0;
  v6->getSteerBasis(this, &steercentre, &steeraxis);
  v7 = (float *)((int (*)(IRigidBody *, int *, _DWORD))this->hub->getPosition)(this->hub, v11, 0);
  v8 = (float)((float)((float)((float)((float)(force->x * (float)(v7[2] - steercentre.z))
                                     - (float)(force->z * (float)(*v7 - steercentre.x)))
                             * steeraxis.y)
                     + (float)((float)((float)(force->z * (float)(v7[1] - steercentre.y))
                                     - (float)(force->y * (float)(v7[2] - steercentre.z)))
                             * steeraxis.x))
             + (float)((float)((float)(force->y * (float)(*v7 - steercentre.x))
                             - (float)(force->x * (float)(v7[1] - steercentre.y)))
                     * steeraxis.z))
     + this->steerTorque;
  this->steerTorque = v8;
  this->steerTorque = (float)((float)((float)(torque->y * steeraxis.y) + (float)(torque->x * steeraxis.x))
                            + (float)(torque->z * steeraxis.z))
                    + v8;
  if ( driveTorque->x != 0.0 || driveTorque->y != 0.0 || driveTorque->z != 0.0 )
    this->car->body->addTorque(this->car->body, driveTorque);
}
void SuspensionStrut::addTorque(SuspensionStrut *this, const vec3f *torque)
{
  SuspensionStrut_vtbl *v3; // eax
  vec3f steeraxis; // [esp+Ch] [ebp-18h] BYREF
  vec3f steercentre; // [esp+18h] [ebp-Ch] BYREF

  this->hub->addTorque(this->hub, torque);
  v3 = this->__vftable;
  steeraxis.x = 0.0;
  steeraxis.y = 0.0;
  steeraxis.z = 0.0;
  steercentre.x = 0.0;
  steercentre.y = 0.0;
  steercentre.z = 0.0;
  v3->getSteerBasis(this, &steercentre, &steeraxis);
  this->steerTorque = (float)((float)((float)(torque->y * steeraxis.y) + (float)(torque->x * steeraxis.x))
                            + (float)(torque->z * steeraxis.z))
                    + this->steerTorque;
}
void __usercall SuspensionStrut::attach(SuspensionStrut *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  IRigidBody *v5; // ecx
  int v6; // eax
  IRigidBody *v7; // ecx
  int v8; // eax
  IRigidBody *v9; // ecx
  vec3f *v10; // ebp
  int v11; // eax
  IRigidBody *v12; // ecx
  int v13; // eax
  vec3f *v14; // ebx
  IRigidBody *v15; // ecx
  int v16; // eax
  IRigidBody *v17; // ecx
  int v18; // eax
  IRigidBody *v19; // ecx
  vec3f *v20; // edi
  int v21; // eax
  SuspensionStrut *v22; // ecx
  vec3f *v23; // esi
  IPhysicsCore *v24; // eax
  SuspensionStrut *v25; // ebp
  IPhysicsCore *v26; // eax
  int v27; // eax
  PhysicsEngine *v28; // ecx
  IPhysicsCore *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  PhysicsEngine *v33; // ecx
  IPhysicsCore *v34; // eax
  int v35; // eax
  IRigidBody *v36; // ecx
  float *v37; // esi
  float *v38; // eax
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  PhysicsEngine *v42; // ecx
  IPhysicsCore *v43; // edi
  float *v44; // esi
  float *v45; // eax
  float v46; // xmm1_4
  float v47; // xmm0_4
  int v48; // eax
  PhysicsEngine *v49; // ecx
  IPhysicsCore *v50; // esi
  IPhysicsCore_vtbl *v51; // edi
  int v52; // eax
  IRigidBody *v53; // [esp+7Ch] [ebp-44h]
  IRigidBody *v54; // [esp+80h] [ebp-40h]
  vec3f *v55; // [esp+8Ch] [ebp-34h]
  float v56; // [esp+9Ch] [ebp-24h] BYREF
  float v57; // [esp+A0h] [ebp-20h]
  SuspensionStrut *v58; // [esp+A4h] [ebp-1Ch]
  float v59; // [esp+A8h] [ebp-18h] BYREF
  float v60; // [esp+ACh] [ebp-14h]
  float v61; // [esp+B0h] [ebp-10h]
  char v62[8]; // [esp+B4h] [ebp-Ch] BYREF
  char v63; // [esp+BCh] [ebp-4h] BYREF

  SuspensionStrut::setPositions(this);
  if ( !this->joints[0] )
  {
    v5 = this->carBody;
    v56 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carBottomWB_F.x;
    v57 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carBottomWB_F.y;
    *(float *)&v58 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carBottomWB_F.z;
    v6 = ((int (*)(IRigidBody *, float *, float *, int, int, int))v5->localToWorld)(
           v5,
           &v59,
           &v56,
           a4,
           a3,
           a2);
    v7 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.carBottomWB_F.x = *(_QWORD *)v6;
    this->dataRelToBody.carBottomWB_F.z = *(float *)(v6 + 8);
    v59 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carBottomWB_R.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carBottomWB_R.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carBottomWB_R.z;
    v8 = (int)v7->localToWorld(v7, (vec3f *)v62, (const vec3f *)&v59);
    v9 = this->carBody;
    v10 = &this->dataRelToBody.carBottomWB_R;
    *(_QWORD *)&this->dataRelToBody.carBottomWB_R.x = *(_QWORD *)v8;
    this->dataRelToBody.carBottomWB_R.z = *(float *)(v8 + 8);
    v59 = this->dataRelToWheel.carStrut.x + this->dataRelToWheel.refPoint.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carStrut.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carStrut.z;
    v11 = (int)v9->localToWorld(v9, (vec3f *)v62, (const vec3f *)&v59);
    v12 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.carStrut.x = *(_QWORD *)v11;
    this->dataRelToBody.carStrut.z = *(float *)(v11 + 8);
    v59 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreBottomWB.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreBottomWB.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreBottomWB.z;
    v13 = (int)v12->localToWorld(v12, (vec3f *)v62, (const vec3f *)&v59);
    v14 = &this->dataRelToBody.tyreBottomWB;
    *(_QWORD *)&this->dataRelToBody.tyreBottomWB.x = *(_QWORD *)v13;
    v15 = this->carBody;
    this->dataRelToBody.tyreBottomWB.z = *(float *)(v13 + 8);
    v59 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreStrut.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreStrut.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreStrut.z;
    v16 = (int)v15->localToWorld(v15, (vec3f *)v62, (const vec3f *)&v59);
    v17 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.tyreStrut.x = *(_QWORD *)v16;
    this->dataRelToBody.tyreStrut.z = *(float *)(v16 + 8);
    v59 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carSteer.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carSteer.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carSteer.z;
    v18 = (int)v17->localToWorld(v17, (vec3f *)v62, (const vec3f *)&v59);
    v19 = this->carBody;
    v20 = &this->dataRelToBody.carSteer;
    *(_QWORD *)&this->dataRelToBody.carSteer.x = *(_QWORD *)v18;
    this->dataRelToBody.carSteer.z = *(float *)(v18 + 8);
    v59 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreSteer.x;
    v60 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreSteer.y;
    v61 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreSteer.z;
    v21 = (int)v19->localToWorld(v19, (vec3f *)v62, (const vec3f *)&v59);
    v22 = v58;
    v23 = &this->dataRelToBody.tyreSteer;
    *(_QWORD *)&v23->x = *(_QWORD *)v21;
    v23->z = *(float *)(v21 + 8);
    SuspensionStrut::setPositions(v22);
    v24 = PhysicsEngine::getCore(v58->physicsEngine);
    v55 = v10;
    v25 = v58;
    v25->joints[0] = v24->createDistanceJoint(v24, v58->carBody, v58->hub, v55, v14);
    v26 = PhysicsEngine::getCore(v25->physicsEngine);
    v27 = (int)v26->createDistanceJoint(v26, v25->carBody, v25->hub, &v25->dataRelToBody.carBottomWB_F, v14);
    v28 = v25->physicsEngine;
    v25->joints[1] = (IJoint *)v27;
    v29 = PhysicsEngine::getCore(v28);
    v25->joints[2] = v29->createDistanceJoint(v29, v25->carBody, v25->hub, v20, v23);
    v30 = v20->z - v23->z;
    v31 = (float)((float)((float)(v20->y - v23->y) * (float)(v20->y - v23->y))
                + (float)((float)(v20->x - v23->x) * (float)(v20->x - v23->x)))
        + (float)(v30 * v30);
    v32 = 0.0;
    if ( v31 != 0.0 )
      v32 = fsqrt(v31);
    v33 = v25->physicsEngine;
    v25->steerLinkBaseLength = v32;
    v34 = PhysicsEngine::getCore(v33);
    v35 = ((int (*)(IPhysicsCore *, IRigidBody *, IRigidBody *, vec3f *, _DWORD, _DWORD))v34->createBumpJoint)(
            v34,
            v25->carBody,
            v25->hub,
            &v25->dataRelToWheel.refPoint,
            LODWORD(v25->bumpStopUp),
            LODWORD(v25->bumpStopDn));
    v36 = v25->carBody;
    v25->bumpStopJoint = (IJoint *)v35;
    v37 = (float *)v36->localToWorld(v36, (vec3f *)v62, &v25->dataRelToBody.carStrut);
    v38 = (float *)v25->hub->localToWorld(v25->hub, (vec3f *)&v59, &v25->dataRelToWheel.tyreStrut);
    v39 = v38[2] - v37[2];
    v40 = (float)((float)((float)(v38[1] - v37[1]) * (float)(v38[1] - v37[1]))
                + (float)((float)(*v38 - *v37) * (float)(*v38 - *v37)))
        + (float)(v39 * v39);
    v41 = 0.0;
    if ( v40 != 0.0 )
      v41 = fsqrt(v40);
    v42 = v25->physicsEngine;
    v25->strutBaseLength = v41;
    v43 = PhysicsEngine::getCore(v42);
    v44 = (float *)((int (*)(IRigidBody *, char *))v25->carBody->localToWorld)(v25->carBody, v62);
    v45 = (float *)v25->hub->localToWorld(v25->hub, (vec3f *)&v63, &v25->dataRelToWheel.tyreStrut);
    v54 = v25->hub;
    v46 = v45[2] - v44[2];
    v47 = *v45 - *v44;
    v53 = v25->strutBody;
    v57 = v45[1] - v44[1];
    *(float *)&v58 = v46;
    v56 = v47;
    v48 = (int)v43->createSliderJoint(v43, v53, v54, (const vec3f *)&v56);
    v49 = v25->physicsEngine;
    v25->joints[3] = (IJoint *)v48;
    v50 = PhysicsEngine::getCore(v49);
    v51 = v50->__vftable;
    v52 = (int)v25->carBody->localToWorld(v25->carBody, (vec3f *)v62, &v25->dataRelToBody.carStrut);
    v25->joints[4] = v51->createBallJoint(v50, v25->carBody, v25->strutBody, (const vec3f *)v52);
  }
}
vec3f *SuspensionStrut::getBasePosition(SuspensionStrut *this, vec3f *result)
{
  vec3f *v2; // eax
  __int64 v3; // xmm0_8
  float v4; // ecx

  v2 = result;
  v3 = *(_QWORD *)&this->basePosition.x;
  v4 = this->basePosition.z;
  *(_QWORD *)&result->x = v3;
  result->z = v4;
  return v2;
}
double SuspensionStrut::getDamage(SuspensionStrut *this)
{
  double result; // st7

  if ( this->damageData.maxDamage == 0.0 )
    result = 0.0;
  else
    result = this->damageData.damageAmount / this->damageData.maxDamage;
  return result;
}
Damper *SuspensionStrut::getDamper(SuspensionStrut *this)
{
  return &this->damper;
}
std::vector<DebugLine> *SuspensionStrut::getDebugLines(SuspensionStrut *this, std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix)
{
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  DebugLine *v30; // eax
  float v31; // xmm5_4
  float v32; // xmm3_4
  float v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  DebugLine *v44; // eax
  float v45; // xmm3_4
  float v46; // xmm5_4
  float v47; // xmm2_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm5_4
  float v56; // xmm6_4
  float v57; // xmm2_4
  float v58; // xmm5_4
  float v59; // xmm4_4
  float v60; // xmm1_4
  float v61; // xmm5_4
  float v62; // xmm0_4
  float v63; // xmm5_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  DebugLine *v68; // eax
  float v69; // xmm5_4
  float v70; // xmm2_4
  float v71; // xmm4_4
  float v72; // xmm3_4
  float v73; // xmm1_4
  float v74; // xmm4_4
  float v75; // xmm1_4
  float v76; // xmm0_4
  float v77; // xmm5_4
  float v78; // xmm3_4
  float v79; // xmm5_4
  float v80; // xmm3_4
  float v81; // xmm2_4
  float v82; // xmm1_4
  float v83; // xmm0_4
  float v84; // xmm5_4
  float v85; // xmm4_4
  float v86; // xmm0_4
  float v87; // xmm5_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm5_4
  float v91; // xmm0_4
  DebugLine *v92; // eax
  vec3f twsh; // [esp+1Ch] [ebp-60h] BYREF
  vec3f ip0; // [esp+28h] [ebp-54h] BYREF
  vec4f ic; // [esp+34h] [ebp-48h] BYREF
  DebugLine v97; // [esp+44h] [ebp-38h] BYREF
  int v98; // [esp+78h] [ebp-4h]

  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v6 = this->dataRelToWheel.tyreBottomWB.y;
  v7 = this->dataRelToWheel.tyreBottomWB.x;
  v8 = this->dataRelToWheel.tyreBottomWB.z;
  v10 = hubMatrix->M12 * v7;
  v11 = (float)(hubMatrix->M11 * v7) + (float)(v6 * hubMatrix->M21);
  v12 = bodyMatrix->M11;
  v98 = 0;
  v13 = v11 + (float)(v8 * hubMatrix->M31);
  v14 = (float)(v10 + (float)(hubMatrix->M22 * v6)) + (float)(hubMatrix->M32 * v8);
  v15 = (float)(hubMatrix->M13 * v7) + (float)(v6 * hubMatrix->M23);
  v16 = this->dataRelToBody.carBottomWB_F.x;
  v17 = v14 + hubMatrix->M42;
  v18 = v12 * v16;
  v19 = v16 * bodyMatrix->M12;
  v20 = v15 + (float)(v8 * hubMatrix->M33);
  v21 = v16 * bodyMatrix->M13;
  v22 = this->dataRelToBody.carBottomWB_F.y;
  twsh.x = v13 + hubMatrix->M41;
  v23 = this->dataRelToBody.carBottomWB_F.z;
  v24 = v20 + hubMatrix->M43;
  twsh.y = v17;
  v25 = bodyMatrix->M23;
  twsh.z = v24;
  ic = (vec4f)_xmm;
  v26 = v19 + (float)(v22 * bodyMatrix->M22);
  v27 = v23 * bodyMatrix->M32;
  ip0.x = (float)((float)(v18 + (float)(bodyMatrix->M21 * v22)) + (float)(bodyMatrix->M31 * v23)) + bodyMatrix->M41;
  v28 = v26 + v27;
  v29 = bodyMatrix->M33 * v23;
  ip0.y = v28 + bodyMatrix->M42;
  ip0.z = (float)((float)((float)(v25 * v22) + v21) + v29) + bodyMatrix->M43;
  DebugLine::DebugLine(&v97, &ip0, &twsh, &ic, 0.0);
  std::vector<DebugLine>::push_back(result, v30);
  v31 = this->dataRelToBody.carBottomWB_R.x;
  v32 = this->dataRelToBody.carBottomWB_R.y;
  v33 = bodyMatrix->M21;
  v34 = this->dataRelToBody.carBottomWB_R.z;
  v35 = v31 * bodyMatrix->M12;
  ic = (vec4f)_xmm;
  v36 = bodyMatrix->M23;
  v37 = v31 * bodyMatrix->M11;
  v38 = v31 * bodyMatrix->M13;
  v39 = (float)((float)((float)(v33 * v32) + v37) + (float)(bodyMatrix->M31 * v34)) + bodyMatrix->M41;
  v40 = v35 + (float)(v32 * bodyMatrix->M22);
  v41 = v34 * bodyMatrix->M32;
  ip0.x = v39;
  v42 = v40 + v41;
  v43 = bodyMatrix->M33 * v34;
  ip0.y = v42 + bodyMatrix->M42;
  ip0.z = (float)((float)((float)(v36 * v32) + v38) + v43) + bodyMatrix->M43;
  DebugLine::DebugLine(&v97, &ip0, &twsh, &ic, 0.0);
  std::vector<DebugLine>::push_back(result, v44);
  v45 = this->dataRelToWheel.tyreSteer.y;
  v46 = this->dataRelToWheel.tyreSteer.x;
  v47 = this->dataRelToWheel.tyreSteer.z;
  v48 = v46 * hubMatrix->M11;
  v49 = v45 * hubMatrix->M22;
  ic = (vec4f)_xmm;
  v50 = (float)((float)(v48 + (float)(v45 * hubMatrix->M21)) + (float)(v47 * hubMatrix->M31)) + hubMatrix->M41;
  v51 = v49 + (float)(hubMatrix->M12 * v46);
  v52 = (float)(v46 * hubMatrix->M13) + (float)(v45 * hubMatrix->M23);
  v53 = (float)(v51 + (float)(v47 * hubMatrix->M32)) + hubMatrix->M42;
  v54 = this->dataRelToBody.carSteer.y;
  v55 = v52 + (float)(v47 * hubMatrix->M33);
  v56 = bodyMatrix->M21;
  v57 = v54 * bodyMatrix->M22;
  v58 = v55 + hubMatrix->M43;
  ip0.x = v50;
  v59 = this->dataRelToBody.carSteer.z;
  ip0.y = v53;
  v60 = bodyMatrix->M23;
  ip0.z = v58;
  v61 = this->dataRelToBody.carSteer.x;
  v62 = v61 * bodyMatrix->M12;
  v63 = v61 * bodyMatrix->M13;
  v64 = v57 + v62;
  v65 = v59 * bodyMatrix->M32;
  twsh.x = (float)((float)((float)(v56 * v54) + (float)(this->dataRelToBody.carSteer.x * bodyMatrix->M11))
                 + (float)(bodyMatrix->M31 * v59))
         + bodyMatrix->M41;
  v66 = v64 + v65;
  v67 = bodyMatrix->M33 * v59;
  twsh.y = v66 + bodyMatrix->M42;
  twsh.z = (float)((float)((float)(v60 * v54) + v63) + v67) + bodyMatrix->M43;
  DebugLine::DebugLine(&v97, &twsh, &ip0, &ic, 0.0);
  std::vector<DebugLine>::push_back(result, v68);
  v69 = this->dataRelToWheel.tyreStrut.y;
  v70 = this->dataRelToWheel.tyreStrut.x;
  v71 = v69 * hubMatrix->M21;
  v72 = this->dataRelToWheel.tyreStrut.z;
  v73 = v70 * hubMatrix->M12;
  ic = (vec4f)_xmm;
  v74 = (float)(v71 + (float)(v70 * hubMatrix->M11)) + (float)(v72 * hubMatrix->M31);
  v75 = v73 + (float)(v69 * hubMatrix->M22);
  v76 = v72 * hubMatrix->M32;
  v77 = (float)(v69 * hubMatrix->M23) + (float)(v70 * hubMatrix->M13);
  v78 = v72 * hubMatrix->M33;
  ip0.x = v74 + hubMatrix->M41;
  v79 = (float)(v77 + v78) + hubMatrix->M43;
  ip0.y = (float)(v75 + v76) + hubMatrix->M42;
  v80 = this->dataRelToBody.carStrut.y;
  v81 = this->dataRelToBody.carStrut.z;
  v82 = v80 * bodyMatrix->M22;
  v83 = bodyMatrix->M21 * v80;
  ip0.z = v79;
  v84 = this->dataRelToBody.carStrut.x;
  v85 = (float)((float)(v84 * bodyMatrix->M11) + v83) + (float)(bodyMatrix->M31 * v81);
  v86 = v84 * bodyMatrix->M12;
  v87 = v84 * bodyMatrix->M13;
  v88 = (float)(v82 + v86) + (float)(v81 * bodyMatrix->M32);
  v89 = bodyMatrix->M23 * v80;
  twsh.x = v85 + bodyMatrix->M41;
  v90 = v87 + v89;
  v91 = bodyMatrix->M33 * v81;
  twsh.y = v88 + bodyMatrix->M42;
  twsh.z = (float)(v90 + v91) + bodyMatrix->M43;
  DebugLine::DebugLine(&v97, &twsh, &ip0, &ic, 0.0);
  std::vector<DebugLine>::push_back(result, v92);
  return result;
}
void SuspensionStrut::getMass(SuspensionStrut *this)
{
  this->hub->getMass(this->hub);
}
SuspensionStatus *SuspensionStrut::getStatus(SuspensionStrut *this)
{
  return &this->status;
}
void __userpurge SuspensionStrut::getSteerBasis(SuspensionStrut *this@<ecx>, __m128 a2@<xmm6>, vec3f *center, vec3f *axis)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm2
  unsigned __int64 v8; // xmm6_8
  float v9; // ecx
  float v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm4_4
  float *v13; // ecx
  unsigned __int64 v14; // [esp+0h] [ebp-34h]
  float v15; // [esp+Ch] [ebp-28h]
  vec3f p1; // [esp+10h] [ebp-24h] BYREF
  vec3f p2; // [esp+1Ch] [ebp-18h]
  float *v18; // [esp+28h] [ebp-Ch]
  unsigned __int64 *v19; // [esp+2Ch] [ebp-8h]

  ((void (*)(IRigidBody *))this->carBody->localToWorld)(this->carBody);
  ((void (*)(IRigidBody *, float *))this->hub->localToWorld)(this->hub, &p1.y);
  v5 = (__m128)(unsigned int)&this->dataRelToWheel.tyreStrut;
  v6 = (__m128)(unsigned int)&p1;
  v7 = (__m128)(unsigned int)&p1;
  v7.m128_f32[0] = COERCE_FLOAT(&p1) - p1.x;
  a2.m128_f32[0] = COERCE_FLOAT((SuspensionStrut *)&this->dataRelToWheel.tyreStrut) - v15;
  v8 = _mm_unpacklo_ps(a2, v7).m128_u64[0];
  v9 = COERCE_FLOAT((SuspensionStrut *)&this->dataRelToBody) - p1.y;
  p2.y = v9;
  v10 = fsqrt(
          (float)((float)(v7.m128_f32[0] * v7.m128_f32[0])
                + (float)((float)(COERCE_FLOAT((SuspensionStrut *)&this->dataRelToWheel.tyreStrut) - v15)
                        * (float)(COERCE_FLOAT((SuspensionStrut *)&this->dataRelToWheel.tyreStrut) - v15)))
        + (float)(p2.y * p2.y));
  if ( v10 != 0.0 )
  {
    *(float *)&v14 = (float)(1.0 / v10)
                   * (float)(COERCE_FLOAT((SuspensionStrut *)&this->dataRelToWheel.tyreStrut) - v15);
    *((float *)&v14 + 1) = (float)(1.0 / v10) * *((float *)&v8 + 1);
    v8 = v14;
    v9 = (float)(1.0 / v10) * (float)(COERCE_FLOAT((SuspensionStrut *)&this->dataRelToBody) - p1.y);
  }
  v11 = (float *)v19;
  v6.m128_f32[0] = COERCE_FLOAT(&p1) + p1.x;
  v12 = COERCE_FLOAT((SuspensionStrut *)&this->dataRelToBody) + p1.y;
  *v19 = v8;
  v11[2] = v9;
  v13 = v18;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] + v15) * 0.5;
  v6.m128_f32[0] = v6.m128_f32[0] * 0.5;
  *(_QWORD *)v18 = _mm_unpacklo_ps(v5, v6).m128_u64[0];
  v13[2] = v12 * 0.5;
}
double SuspensionStrut::getSteerTorque(SuspensionStrut *this)
{
  return this->steerTorque;
}
void __userpurge SuspensionStrut::loadINI(SuspensionStrut *this@<ecx>, __m128 a2@<xmm0>, int index)
{
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const std::wstring *v6; // eax
  __m128 v7; // xmm0
  float v8; // eax
  const std::wstring *v9; // edi
  vec3f *v10; // eax
  bool v11; // cf
  vec3f *v12; // eax
  vec3f *v13; // eax
  vec3f *v14; // eax
  vec3f *v15; // eax
  vec3f *v16; // eax
  vec3f *v17; // eax
  int v18; // xmm2_4
  float v19; // xmm0_4
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  int v35; // xmm1_4
  double v36; // st7
  bool v37; // al
  double v38; // st7
  double v39; // st7
  double v40; // st7
  int v41; // eax
  float v42; // [esp+14h] [ebp-150h]
  float v43; // [esp+18h] [ebp-14Ch]
  float v44; // [esp+1Ch] [ebp-148h]
  float v45; // [esp+24h] [ebp-140h]
  float v46; // [esp+28h] [ebp-13Ch]
  float v47; // [esp+2Ch] [ebp-138h]
  float v48; // [esp+2Ch] [ebp-138h]
  bool v49; // [esp+33h] [ebp-131h]
  int v50; // [esp+34h] [ebp-130h]
  float v51; // [esp+34h] [ebp-130h]
  float v52; // [esp+34h] [ebp-130h]
  float v53; // [esp+34h] [ebp-130h]
  std::wstring result; // [esp+38h] [ebp-12Ch] BYREF
  std::wstring v55; // [esp+50h] [ebp-114h] BYREF
  INIReader v56; // [esp+68h] [ebp-FCh] BYREF
  std::wstring section; // [esp+ACh] [ebp-B8h] BYREF
  std::wstring ptr; // [esp+C4h] [ebp-A0h] BYREF
  std::wstring v59; // [esp+DCh] [ebp-88h] BYREF
  std::wstring v60; // [esp+F4h] [ebp-70h] BYREF
  std::wstring v61; // [esp+10Ch] [ebp-58h] BYREF
  unsigned __int64 v62; // [esp+124h] [ebp-40h]
  float v63; // [esp+12Ch] [ebp-38h]
  unsigned __int64 v64; // [esp+130h] [ebp-34h]
  float v65; // [esp+138h] [ebp-2Ch]
  std::wstring key; // [esp+13Ch] [ebp-28h] BYREF
  int v67; // [esp+160h] [ebp-4h]

  v4 = std::operator+<wchar_t>(&result, &this->car->carDataPath, L"suspensions.ini");
  v5 = this->car;
  v67 = 0;
  v6 = Car::getConfigPath(v5, &v55, v4);
  LOBYTE(v67) = 1;
  INIReader::INIReader(&v56, v6);
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"VERSION", 7u);
  LOBYTE(v67) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v67) = 6;
  v50 = INIReader::getInt(&v56, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WHEELBASE", 9u);
  LOBYTE(v67) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v67) = 8;
  v45 = INIReader::getFloat(&v56, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CG_LOCATION", 0xBu);
  LOBYTE(v67) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v67) = 10;
  v43 = INIReader::getFloat(&v56, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v67) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v67) = 12;
  v46 = INIReader::getFloat(&v56, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v67) = 13;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v67) = 14;
  v47 = INIReader::getFloat(&v56, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v67) = 15;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v67) = 16;
  v42 = INIReader::getFloat(&v56, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v67) = 17;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v67) = 18;
  v44 = INIReader::getFloat(&v56, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v67) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  a2.m128_f32[0] = v47;
  v7 = _mm_unpacklo_ps(a2, (__m128)LODWORD(v46));
  v63 = (float)(1.0 - v43) * v45;
  v65 = v63;
  v62 = v7.m128_u64[0];
  v7.m128_f32[0] = v44;
  *(_DWORD *)&key._Bx._Alias[8] = COERCE_UNSIGNED_INT(v43 * v45) ^ _xmm;
  section._Myres = *(_DWORD *)&key._Bx._Alias[8];
  key._Myres = *(_DWORD *)&key._Bx._Alias[8];
  v64 = _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(v47), (__m128)(unsigned int)_xmm), (__m128)LODWORD(v46)).m128_u64[0];
  *(_QWORD *)key._Bx._Buf = _mm_unpacklo_ps(v7, (__m128)LODWORD(v42)).m128_u64[0];
  *(_QWORD *)&key._Bx._Alias[12] = _mm_unpacklo_ps(
                                     _mm_xor_ps((__m128)LODWORD(v44), (__m128)(unsigned int)_xmm),
                                     (__m128)LODWORD(v42)).m128_u64[0];
  ptr._Myres = 7;
  ptr._Mysize = 0;
  ptr._Bx._Buf[0] = 0;
  std::wstring::assign(&ptr, L"FRONT", 5u);
  LOBYTE(v67) = 19;
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  std::wstring::assign(&v59, L"FRONT", 5u);
  LOBYTE(v67) = 20;
  v60._Myres = 7;
  v60._Mysize = 0;
  v60._Bx._Buf[0] = 0;
  std::wstring::assign(&v60, L"REAR", 4u);
  LOBYTE(v67) = 21;
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  std::wstring::assign(&v61, L"REAR", 4u);
  LOBYTE(v67) = 22;
  v8 = *(&v63 + 3 * index);
  *(_QWORD *)&this->dataRelToWheel.refPoint.x = *(unsigned __int64 *)((char *)&v62 + 12 * index);
  this->dataRelToWheel.refPoint.z = v8;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"STRUT_CAR", 9u);
  LOBYTE(v67) = 23;
  v9 = &ptr + index;
  v10 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.carStrut = *v10;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"STRUT_TYRE");
  LOBYTE(v67) = 24;
  v12 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.tyreStrut = *v12;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_BOTTOM_FRONT");
  LOBYTE(v67) = 25;
  v13 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.carBottomWB_F = *v13;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_BOTTOM_REAR");
  LOBYTE(v67) = 26;
  v14 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.carBottomWB_R = *v14;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBTYRE_BOTTOM");
  LOBYTE(v67) = 27;
  v15 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.tyreBottomWB = *v15;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBTYRE_STEER");
  LOBYTE(v67) = 28;
  v16 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.tyreSteer = *v16;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_STEER");
  LOBYTE(v67) = 29;
  v17 = INIReader::getFloat3(&v56, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v67) = 22;
  this->dataRelToWheel.carSteer = *v17;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  if ( v50 >= 2 )
  {
    std::wstring::wstring(&key, L"RIM_OFFSET");
    LOBYTE(v67) = 30;
    v18 = _xmm;
    v51 = INIReader::getFloat(&v56, v9, &key);
    LODWORD(v19) = LODWORD(v51) ^ _xmm;
    LOBYTE(v67) = 22;
    LODWORD(v48) = LODWORD(v51) ^ _xmm;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v18 = _xmm;
    }
    if ( v19 != 0.0 )
    {
      _printf("APPLYING RIM OFFSET:%f\n", COERCE_FLOAT(LODWORD(v19) ^ v18));
      this->dataRelToWheel.carStrut.x = this->dataRelToWheel.carStrut.x + v48;
      this->dataRelToWheel.carBottomWB_F.x = this->dataRelToWheel.carBottomWB_F.x + v48;
      this->dataRelToWheel.carBottomWB_R.x = v48 + this->dataRelToWheel.carBottomWB_R.x;
      this->dataRelToWheel.tyreStrut.x = v48 + this->dataRelToWheel.tyreStrut.x;
      this->dataRelToWheel.tyreBottomWB.x = this->dataRelToWheel.tyreBottomWB.x + v48;
      this->dataRelToWheel.tyreSteer.x = v48 + this->dataRelToWheel.tyreSteer.x;
      this->dataRelToWheel.carSteer.x = this->dataRelToWheel.carSteer.x + v48;
    }
  }
  std::wstring::wstring(&key, L"HUB_MASS");
  LOBYTE(v67) = 31;
  v20 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->dataRelToWheel.hubMass = v20;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"BUMPSTOP_UP");
  LOBYTE(v67) = 32;
  v21 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->bumpStopUp = v21;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"BUMPSTOP_DN");
  LOBYTE(v67) = 33;
  v22 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  v52 = v22;
  LODWORD(this->bumpStopDn) = LODWORD(v52) ^ _xmm;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"ROD_LENGTH");
  LOBYTE(v67) = 34;
  v23 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->rodLength = v23;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"TOE_OUT");
  LOBYTE(v67) = 35;
  v24 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->toeOUT_Linear = v24;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"SPRING_RATE");
  LOBYTE(v67) = 36;
  v25 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->k = v25;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"PROGRESSIVE_SPRING_RATE");
  LOBYTE(v67) = 37;
  v26 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->progressiveK = v26;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_BUMP");
  LOBYTE(v67) = 38;
  v27 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.bumpSlow = v27;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_REBOUND");
  LOBYTE(v67) = 39;
  v28 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.reboundSlow = v28;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_BUMP");
  LOBYTE(v67) = 40;
  v29 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.bumpFast = v29;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_REBOUND");
  LOBYTE(v67) = 41;
  v30 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.reboundFast = v30;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_BUMPTHRESHOLD");
  LOBYTE(v67) = 42;
  v31 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.fastThresholdBump = v31;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_REBOUNDTHRESHOLD");
  LOBYTE(v67) = 43;
  v32 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->damper.fastThresholdRebound = v32;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  if ( this->damper.fastThresholdBump == 0.0 )
    this->damper.fastThresholdBump = 0.2;
  if ( this->damper.fastThresholdRebound == 0.0 )
    this->damper.fastThresholdRebound = 0.2;
  if ( this->damper.bumpFast == 0.0 )
    this->damper.bumpFast = this->damper.bumpSlow;
  if ( this->damper.reboundFast == 0.0 )
    this->damper.reboundFast = this->damper.reboundSlow;
  std::wstring::wstring(&key, L"BUMP_STOP_RATE");
  LOBYTE(v67) = 44;
  v33 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->bumpStopRate = v33;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  if ( this->bumpStopRate == 0.0 )
    this->bumpStopRate = 500000.0;
  std::wstring::wstring(&key, L"STATIC_CAMBER");
  LOBYTE(v67) = 45;
  v34 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  v35 = _xmm;
  LOBYTE(v67) = 22;
  v53 = v34 * 0.017453;
  LODWORD(this->staticCamber) = LODWORD(v53) ^ _xmm;
  if ( !v11 )
  {
    operator delete(key._Bx._Ptr);
    v35 = _xmm;
  }
  if ( index % 2 )
    LODWORD(this->staticCamber) ^= v35;
  std::wstring::wstring(&key, L"PACKER_RANGE");
  LOBYTE(v67) = 46;
  v36 = INIReader::getFloat(&v56, v9, &key);
  v11 = key._Myres < 8;
  this->packerRange = v36;
  LOBYTE(v67) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMAGE");
  LOBYTE(v67) = 47;
  v37 = INIReader::hasSection(&v56, &key);
  v49 = v37;
  LOBYTE(v67) = 22;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v37 = v49;
  }
  if ( v37 )
  {
    std::wstring::wstring(&section, L"MIN_VELOCITY");
    LOBYTE(v67) = 48;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v67) = 49;
    v38 = INIReader::getFloat(&v56, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.minVelocity = v38;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v67) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"GAIN");
    LOBYTE(v67) = 50;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v67) = 51;
    v39 = INIReader::getFloat(&v56, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.damageGain = v39;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v67) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"MAX_DAMAGE");
    LOBYTE(v67) = 52;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v67) = 53;
    v40 = INIReader::getFloat(&v56, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.maxDamage = v40;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v67) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"DEBUG_LOG");
    LOBYTE(v67) = 54;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v67) = 55;
    v41 = INIReader::getInt(&v56, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.isDebug = v41 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  LOBYTE(v67) = 4;
  `eh vector destructor iterator'(&ptr, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  v67 = -1;
  INIReader::~INIReader(&v56);
}
void SuspensionStrut::resetDamage(SuspensionStrut *this)
{
  this->damageData.damageAmount = 0.0;
}
void SuspensionStrut::setDamage(SuspensionStrut *this, float amount)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4

  v2 = this->damageData.minVelocity;
  if ( amount > v2 )
  {
    v3 = amount - v2;
    v4 = this->damageData.maxDamage;
    v5 = v3 * this->damageData.damageGain;
    if ( v5 <= v4 )
      v4 = v5;
    this->damageData.damageAmount = v4;
  }
  if ( this->damageData.isDebug && amount != this->damageData.lastAmount )
    this->damageData.lastAmount = amount;
}
void SuspensionStrut::setERPCFM(SuspensionStrut *this, float erp, float cfm)
{
  IJoint **v3; // esi
  int v4; // edi

  v3 = this->joints;
  v4 = 5;
  do
  {
    ((void (*)(IJoint *, _DWORD, _DWORD))(*v3)->setERPCFM)(*v3, LODWORD(erp), LODWORD(cfm));
    ++v3;
    --v4;
  }
  while ( v4 );
}
void SuspensionStrut::setPositions(SuspensionStrut *this)
{
  vec3f *v2; // eax
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  IRigidBody *v12; // ecx
  float v13; // xmm0_4
  IRigidBody *v14; // ecx
  float v15; // [esp+2Ch] [ebp-C8h]
  float v16; // [esp+30h] [ebp-C4h]
  float v17; // [esp+34h] [ebp-C0h]
  float v18; // [esp+38h] [ebp-BCh]
  float v19; // [esp+3Ch] [ebp-B8h]
  float v20; // [esp+40h] [ebp-B4h] BYREF
  float v21; // [esp+44h] [ebp-B0h]
  float v22; // [esp+48h] [ebp-ACh]
  float v23; // [esp+4Ch] [ebp-A8h]
  int v24[3]; // [esp+50h] [ebp-A4h] BYREF
  mat44f result; // [esp+5Ch] [ebp-98h] BYREF
  char v26[12]; // [esp+9Ch] [ebp-58h] BYREF
  char v27[12]; // [esp+A8h] [ebp-4Ch] BYREF
  int v28[8]; // [esp+B4h] [ebp-40h] BYREF
  int v29; // [esp+D4h] [ebp-20h]
  int v30; // [esp+D8h] [ebp-1Ch]
  int v31; // [esp+DCh] [ebp-18h]

  ((void (*)(IRigidBody *, int *, _DWORD))this->carBody->getWorldMatrix)(this->carBody, v28, 0);
  this->carBody->localToWorld(this->carBody, (vec3f *)v26, &this->basePosition);
  this->hub->setRotation(this->hub, (const mat44f *)v28);
  this->hub->setPosition(this->hub, (const vec3f *)v26);
  this->carBody->localToWorld(this->carBody, (vec3f *)&v20, (const vec3f *)&this->dataRelToBody);
  v2 = this->hub->localToWorld(this->hub, v27, &this->dataRelToWheel.tyreStrut);
  v3 = v2->x - v20;
  v4 = v2->y - v21;
  v5 = v2->z - v22;
  v16 = v3;
  v17 = v4;
  v15 = v5;
  v6 = fsqrt((float)((float)(v4 * v4) + (float)(v3 * v3)) + (float)(v5 * v5));
  if ( v6 != 0.0 )
  {
    v16 = (float)(1.0 / v6) * v3;
    v17 = (float)(1.0 / v6) * v4;
    v15 = (float)(1.0 / v6) * v5;
  }
  mat44f::createIdentity(&result);
  v18 = (float)(COERCE_FLOAT(v31 ^ _xmm) * v17) - (float)(COERCE_FLOAT(v30 ^ _xmm) * v15);
  v23 = (float)(COERCE_FLOAT(v30 ^ _xmm) * v16) - (float)(COERCE_FLOAT(v29 ^ _xmm) * v17);
  v19 = (float)(COERCE_FLOAT(v29 ^ _xmm) * v15) - (float)(COERCE_FLOAT(v31 ^ _xmm) * v16);
  v7 = (float)(v23 * v17) - (float)(v19 * v15);
  v8 = (float)(v18 * v15) - (float)(v23 * v16);
  v9 = (float)(v19 * v16) - (float)(v18 * v17);
  v10 = fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  if ( v10 != 0.0 )
  {
    v11 = 1.0 / v10;
    v7 = v7 * v11;
    v8 = v8 * v11;
    v9 = v11 * v9;
  }
  v12 = this->strutBody;
  result.M11 = v7;
  LODWORD(result.M31) = LODWORD(v16) ^ _xmm;
  result.M12 = v8;
  LODWORD(result.M32) = LODWORD(v17) ^ _xmm;
  result.M13 = v9;
  LODWORD(result.M33) = LODWORD(v15) ^ _xmm;
  result.M21 = (float)(COERCE_FLOAT(v31 ^ _xmm) * v17) - (float)(COERCE_FLOAT(v30 ^ _xmm) * v15);
  result.M22 = (float)(COERCE_FLOAT(v29 ^ _xmm) * v15) - (float)(COERCE_FLOAT(v31 ^ _xmm) * v16);
  result.M23 = v23;
  v12->setRotation(v12, &result);
  v13 = this->strutBodyLength;
  v14 = this->strutBody;
  *(float *)v24 = (float)((float)(v16 * v13) * 0.5) + v20;
  *(float *)&v24[1] = (float)((float)(v17 * v13) * 0.5) + v21;
  *(float *)&v24[2] = (float)((float)(v15 * v13) * 0.5) + v22;
  v14->setPosition(v14, (const vec3f *)v24);
}
void SuspensionStrut::setSteerLengthOffset(SuspensionStrut *this, float o)
{
  float v2; // xmm2_4
  float v4; // xmm0_4
  PhysicsEngine *v5; // ecx
  float v6; // xmm0_4
  __m128 v7; // xmm2
  float v8; // eax
  IPhysicsCore *v9; // eax

  v2 = 0.0;
  v4 = this->dataRelToWheel.refPoint.x;
  if ( v4 <= 0.0 )
  {
    if ( v4 < 0.0 )
      v2 = FLOAT_N1_0;
  }
  else
  {
    v2 = FLOAT_1_0;
  }
  v5 = this->physicsEngine;
  v6 = this->toeOUT_Linear * v2;
  v7 = (__m128)LODWORD(this->baseCarSteerPosition.x);
  v8 = this->baseCarSteerPosition.z;
  v7.m128_f32[0] = v7.m128_f32[0]
                 + (float)((float)((float)(this->damageData.damageDirection * this->damageData.damageAmount) + o) + v6);
  *(_QWORD *)&this->dataRelToBody.carSteer.x = _mm_unpacklo_ps(v7, (__m128)LODWORD(this->baseCarSteerPosition.y)).m128_u64[0];
  this->dataRelToBody.carSteer.z = v8;
  v9 = PhysicsEngine::getCore(v5);
  v9->reseatDistanceJointLocal(v9, this->joints[2], &this->dataRelToBody.carSteer, &this->dataRelToWheel.tyreSteer);
}
void SuspensionStrut::step(SuspensionStrut *this, float dt)
{
  IRigidBody *v3; // ecx
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  bool v15; // cc
  float v16; // xmm0_4
  float v17; // xmm2_4
  SuspensionStrut_vtbl *v18; // eax
  IRigidBody *v19; // ecx
  IRigidBody_vtbl *v20; // esi
  int v21; // eax
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  int v25; // xmm2_4
  int v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  IRigidBody *v29; // ecx
  SuspensionStrut_vtbl *v30; // esi
  int v31; // xmm0_4
  int v32; // eax
  IRigidBody *v33; // ecx
  float v34; // xmm1_4
  IRigidBody *v35; // ecx
  SuspensionStrut_vtbl *v36; // esi
  float v37; // xmm0_4
  float v38; // xmm0_4
  int v39; // eax
  IRigidBody *v40; // ecx
  float v; // xmm2_4
  double v42; // st7
  SuspensionStrut_vtbl *v43; // eax
  IRigidBody *v44; // ecx
  float v45; // [esp+A0h] [ebp-C0h] BYREF
  float v46; // [esp+A4h] [ebp-BCh]
  float v47; // [esp+A8h] [ebp-B8h] BYREF
  float v48; // [esp+ACh] [ebp-B4h] BYREF
  float v49; // [esp+B0h] [ebp-B0h]
  float v50; // [esp+B4h] [ebp-ACh]
  float v51; // [esp+B8h] [ebp-A8h]
  float v52; // [esp+BCh] [ebp-A4h] BYREF
  float v53; // [esp+C0h] [ebp-A0h]
  float v54; // [esp+C4h] [ebp-9Ch] BYREF
  float v55; // [esp+C8h] [ebp-98h]
  float v56; // [esp+CCh] [ebp-94h]
  float v57; // [esp+D0h] [ebp-90h] BYREF
  float v58; // [esp+D4h] [ebp-8Ch]
  float v59; // [esp+D8h] [ebp-88h]
  float v60; // [esp+DCh] [ebp-84h] BYREF
  float v61; // [esp+E0h] [ebp-80h]
  float v62; // [esp+E4h] [ebp-7Ch]
  int v63; // [esp+E8h] [ebp-78h]
  int v64; // [esp+ECh] [ebp-74h]
  char v65; // [esp+F0h] [ebp-70h] BYREF
  float v66; // [esp+F4h] [ebp-6Ch]
  int v67[3]; // [esp+FCh] [ebp-64h] BYREF
  int v68[3]; // [esp+108h] [ebp-58h] BYREF
  char v69[12]; // [esp+114h] [ebp-4Ch] BYREF
  char v70[64]; // [esp+120h] [ebp-40h] BYREF

  v3 = this->carBody;
  this->steerTorque = 0.0;
  v3->localToWorld(v3, (vec3f *)&v60, &this->dataRelToBody.carStrut);
  this->hub->localToWorld(this->hub, (vec3f *)&v57, &this->dataRelToWheel.tyreStrut);
  v4 = v57 - v60;
  v5 = v58 - v61;
  v6 = v59 - v62;
  v50 = v57 - v60;
  v49 = v58 - v61;
  v51 = v59 - v62;
  v7 = (float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6);
  if ( v7 == 0.0 )
    v8 = 0.0;
  else
    v8 = fsqrt(v7);
  v9 = fsqrt(v7);
  if ( v9 != 0.0 )
  {
    v4 = (float)(1.0 / v9) * v4;
    v5 = (float)(1.0 / v9) * v5;
    v50 = v4;
    v49 = v5;
    v6 = (float)(1.0 / v9) * v6;
    v51 = v6;
  }
  v10 = &v48;
  v11 = this->strutBaseLength + this->rodLength;
  v12 = this->progressiveK;
  v52 = 0.0;
  v13 = v11 - v8;
  this->status.travel = v13;
  v14 = (float)((float)(v12 * v13) + this->k) * v13;
  v15 = v14 <= 0.0;
  v48 = v14;
  v16 = this->packerRange;
  if ( v15 )
    v10 = &v52;
  v17 = *v10;
  v48 = *v10;
  if ( v16 != 0.0 && v13 > v16 )
  {
    v17 = (float)((float)(v13 - v16) * this->bumpStopRate) + v17;
    v48 = v17;
  }
  if ( v17 > 0.0 )
  {
    v18 = this->__vftable;
    v45 = v4 * v17;
    v46 = v5 * v17;
    v47 = v6 * v17;
    v18->addForceAtPos(this, (const vec3f *)&v45, (const vec3f *)&v57, 0, 0);
    v19 = this->carBody;
    v45 = v50 * COERCE_FLOAT(LODWORD(v48) ^ _xmm);
    v46 = v49 * COERCE_FLOAT(LODWORD(v48) ^ _xmm);
    v47 = v51 * COERCE_FLOAT(LODWORD(v48) ^ _xmm);
    v19->addForceAtPos(v19, (const vec3f *)&v45, (const vec3f *)&v60);
  }
  v20 = this->carBody->__vftable;
  v21 = ((int (*)(IRigidBody *, float *, _DWORD))this->hub->getPosition)(this->hub, &v45, 0);
  v20->worldToLocal(this->carBody, (vec3f *)&v65, (const vec3f *)v21);
  v22 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->carBody->getWorldMatrix)(
                   this->carBody,
                   v70,
                   0);
  v23 = v66 - this->dataRelToWheel.refPoint.y;
  v24 = this->bumpStopUp;
  v25 = *((int *)v22 + 4);
  v26 = *((int *)v22 + 5);
  v27 = v22[6];
  v28 = FLOAT_500000_0;
  v64 = v25;
  v63 = v26;
  v53 = v27;
  v48 = v23;
  if ( v23 > v24 )
  {
    v29 = this->hub;
    v30 = this->__vftable;
    *(float *)&v31 = (float)(v23 - v24) * 500000.0;
    v52 = *(float *)&v31;
    v45 = *(float *)&v25 * COERCE_FLOAT(v31 ^ _xmm);
    v46 = *(float *)&v26 * COERCE_FLOAT(v31 ^ _xmm);
    v47 = v27 * COERCE_FLOAT(v31 ^ _xmm);
    v32 = ((int (*)(IRigidBody *, char *, _DWORD, _DWORD, _DWORD))v29->getPosition)(v29, v69, 0, 0, 0);
    ((void (*)(SuspensionStrut *, float *, int))v30->addForceAtPos)(this, &v47, v32);
    v33 = this->carBody;
    v45 = 0.0;
    v46 = v52;
    v47 = 0.0;
    v33->addLocalForceAtLocalPos(v33, (const vec3f *)&v45, (const vec3f *)&v65);
    v23 = v48;
    v25 = v64;
    v26 = v63;
    v27 = v53;
    v28 = FLOAT_500000_0;
  }
  v34 = this->bumpStopDn;
  if ( v34 > v23 )
  {
    v35 = this->hub;
    v36 = this->__vftable;
    v37 = (float)(v23 - v34) * v28;
    v48 = v37;
    LODWORD(v38) = LODWORD(v37) ^ _xmm;
    v45 = *(float *)&v25 * v38;
    v46 = *(float *)&v26 * v38;
    v47 = v27 * v38;
    v39 = ((int (*)(IRigidBody *, char *, _DWORD, _DWORD, _DWORD))v35->getPosition)(v35, v69, 0, 0, 0);
    ((void (*)(SuspensionStrut *, float *, int))v36->addForceAtPos)(this, &v47, v39);
    v40 = this->carBody;
    v45 = 0.0;
    v46 = v48;
    v47 = 0.0;
    v40->addLocalForceAtLocalPos(v40, (const vec3f *)&v45, (const vec3f *)&v65);
  }
  this->hub->getLocalPointVelocity(this->hub, (vec3f *)v68, &this->dataRelToWheel.tyreStrut);
  this->carBody->getLocalPointVelocity(this->carBody, (vec3f *)v67, (const vec3f *)&this->dataRelToBody);
  v = (float)((float)((float)(*(float *)&v68[1] - *(float *)&v67[1]) * v49)
            + (float)((float)(*(float *)v68 - *(float *)v67) * v50))
    + (float)((float)(*(float *)&v68[2] - *(float *)&v67[2]) * v51);
  this->status.damperSpeedMS = v;
  v42 = Damper::getForce(&this->damper, v);
  v43 = this->__vftable;
  v53 = v42;
  v54 = v50 * v53;
  v55 = v49 * v53;
  v56 = v51 * v53;
  v43->addForceAtPos(this, (const vec3f *)&v54, (const vec3f *)&v57, 0, 0);
  v44 = this->carBody;
  v45 = v54 * -1.0;
  v46 = v55 * -1.0;
  v47 = v56 * -1.0;
  v44->addForceAtPos(v44, (const vec3f *)&v45, (const vec3f *)&v60);
}
