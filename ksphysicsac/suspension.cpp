#include "suspension.h"
void __userpurge Suspension::Suspension(Suspension *this@<ecx>, int a2@<ebx>, int a3@<ebp>, Car *car, int index)
{
  float v6; // xmm1_4
  IPhysicsCore *v7; // eax
  IRigidBody *v8; // eax
  float v9; // xmm3_4
  IJoint **v10; // esi
  float v11; // eax
  float v12; // eax
  float v13; // xmm0_4
  int v14; // edi
  unsigned __int64 v15; // [esp+30h] [ebp-1Ch]
  float v16; // [esp+38h] [ebp-14h]
  int indexa; // [esp+54h] [ebp+8h]

  this->bumpStopProgressive = 0.0;
  this->baseCFM = 0.0000001;
  this->__vftable = (Suspension_vtbl *)&Suspension::`vftable';
  this->basePosition.x = 0.0;
  this->basePosition.y = 0.0;
  this->basePosition.z = 0.0;
  this->car = car;
  this->useActiveActuator = 0;
  SDWSuspensionData::SDWSuspensionData(&this->dataRelToWheel);
  SDWSuspensionData::SDWSuspensionData(&this->dataRelToBody);
  Damper::Damper(&this->damper);
  ActiveActuator::ActiveActuator(&this->activeActuator);
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
  this->toeOUT_Linear = 0.0;
  this->steerTorque = 0.0;
  this->carBody = car->body;
  this->k = 90000.0;
  this->steerAngle = 0.0;
  this->staticCamber = 0.0;
  this->rodLength = 0.0;
  v6 = (float)((float)_rand() * 0.000030518509) * 100.0;
  this->damageData.damageDirection = v6;
  if ( v6 >= 50.0 )
    this->damageData.damageDirection = 1.0;
  else
    this->damageData.damageDirection = -1.0;
  Suspension::loadINI(this, (__m128)LODWORD(FLOAT_50_0), index);
  if ( this->dataRelToWheel.refPoint.x > 0.0 )
  {
    LODWORD(this->dataRelToWheel.carBottomWB_F.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carBottomWB_R.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carSteer.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carTopWB_F.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.carTopWB_R.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreBottomWB.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreSteer.x) ^= _xmm;
    LODWORD(this->dataRelToWheel.tyreTopWB.x) ^= _xmm;
  }
  v7 = PhysicsEngine::getCore(this->physicsEngine);
  v8 = v7->createRigidBody(v7);
  v9 = this->dataRelToWheel.hubMass;
  this->hub = v8;
  if ( v9 <= 0.0 )
    v9 = FLOAT_20_0;
  v16 = this->dataRelToWheel.hubInertiaBox.z;
  v15 = *(_QWORD *)&this->dataRelToWheel.hubInertiaBox.x;
  if ( (float)((float)((float)(this->dataRelToWheel.hubInertiaBox.x * this->dataRelToWheel.hubInertiaBox.x)
                     + (float)(this->dataRelToWheel.hubInertiaBox.y * this->dataRelToWheel.hubInertiaBox.y))
             + (float)(v16 * v16)) == 0.0 )
  {
    v15 = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_0_2), (__m128)LODWORD(FLOAT_0_60000002)).m128_u64[0];
    v16 = 0.60000002;
  }
  ((void (*)(IRigidBody *, float, _DWORD, _DWORD, float))v8->setMassBox)(
    v8,
    COERCE_FLOAT(LODWORD(v9)),
    v15,
    HIDWORD(v15),
    COERCE_FLOAT(LODWORD(v16)));
  v10 = this->joints;
  v11 = this->dataRelToWheel.refPoint.z;
  *(_QWORD *)&this->basePosition.x = *(_QWORD *)&this->dataRelToWheel.refPoint.x;
  this->basePosition.z = v11;
  this->joints[0] = 0;
  Suspension::attach(this, a2, a3, (int)this->joints);
  v12 = this->dataRelToBody.carSteer.z;
  *(_QWORD *)&this->baseCarSteerPosition.x = *(_QWORD *)&this->dataRelToBody.carSteer.x;
  this->baseCarSteerPosition.z = v12;
  Suspension::setSteerLengthOffset(this, 0.0);
  v13 = this->baseCFM;
  v14 = 5;
  indexa = LODWORD(v13);
  do
  {
    ((void (*)(IJoint *, int, float))(*v10)->setERPCFM)(*v10, 1050253722, COERCE_FLOAT(LODWORD(v13)));
    v13 = *(float *)&indexa;
    ++v10;
    --v14;
  }
  while ( v14 );
}
Suspension *Suspension::`scalar deleting destructor'(Suspension *this, unsigned int a2)
{
  IRigidBody *v3; // ecx

  this->__vftable = (Suspension_vtbl *)&Suspension::`vftable';
  v3 = this->hub;
  if ( v3 )
    v3->release(v3);
  ActiveActuator::~ActiveActuator((CarControlsInput *)&this->activeActuator);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->damper);
  this->__vftable = (Suspension_vtbl *)&ISuspension::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Suspension::addForceAtPos(Suspension *this, const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque)
{
  Suspension_vtbl *v6; // eax
  vec3f steercentre; // [esp+10h] [ebp-18h] BYREF
  vec3f steeraxis; // [esp+1Ch] [ebp-Ch] BYREF

  if ( (dword_186F2DC & 1) == 0 )
  {
    perfCounter_48.name = "Suspension::addForceAtPos";
    dword_186F2DC |= 1u;
    perfCounter_48.group = Physics;
    perfCounter_48.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Suspension::addForceAtPos" | 0xFF000000;
  }
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
    this->steerTorque = (float)((float)((float)((float)((float)(force->z * (float)(pos->y - steercentre.y))
                                                      - (float)(force->y * (float)(pos->z - steercentre.z)))
                                              * steeraxis.x)
                                      + (float)((float)((float)(force->x * (float)(pos->z - steercentre.z))
                                                      - (float)(force->z * (float)(pos->x - steercentre.x)))
                                              * steeraxis.y))
                              + (float)((float)((float)(force->y * (float)(pos->x - steercentre.x))
                                              - (float)(force->x * (float)(pos->y - steercentre.y)))
                                      * steeraxis.z))
                      + this->steerTorque;
  }
}
void Suspension::addLocalForceAndTorque(Suspension *this, const vec3f *force, const vec3f *torque, const vec3f *driveTorque)
{
  IRigidBody *v5; // ecx
  Suspension_vtbl *v6; // eax
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
void Suspension::addTorque(Suspension *this, const vec3f *torque)
{
  Suspension_vtbl *v3; // eax
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
void __usercall Suspension::attach(Suspension *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  IRigidBody *v5; // ecx
  int v6; // eax
  IRigidBody *v7; // ecx
  int v8; // eax
  IRigidBody *v9; // ecx
  int v10; // eax
  IRigidBody *v11; // ecx
  int v12; // eax
  vec3f *v13; // ebp
  IRigidBody *v14; // ecx
  int v15; // eax
  IRigidBody *v16; // ecx
  int v17; // eax
  IRigidBody *v18; // ecx
  vec3f *v19; // esi
  int v20; // eax
  IRigidBody *v21; // ecx
  vec3f *v22; // ebx
  int v23; // eax
  vec3f *v24; // edi
  PhysicsEngine *v25; // ecx
  IPhysicsCore *v26; // eax
  float v27; // ebp
  IPhysicsCore *v28; // eax
  IPhysicsCore *v29; // eax
  IPhysicsCore *v30; // eax
  IPhysicsCore *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  PhysicsEngine *v35; // ecx
  IPhysicsCore *v36; // eax
  vec3f *v37; // [esp+B4h] [ebp-68h]
  int v38[2]; // [esp+C4h] [ebp-58h] BYREF
  float v39; // [esp+CCh] [ebp-50h]
  float v40; // [esp+D0h] [ebp-4Ch] BYREF
  float v41; // [esp+D4h] [ebp-48h]
  float v42; // [esp+D8h] [ebp-44h]
  char v43[64]; // [esp+DCh] [ebp-40h] BYREF

  ((void (*)(IRigidBody *, char *, _DWORD))this->carBody->getWorldMatrix)(this->carBody, v43, 0);
  this->carBody->localToWorld(this->carBody, (vec3f *)v38, &this->basePosition);
  this->hub->setRotation(this->hub, (const mat44f *)v43);
  this->hub->setPosition(this->hub, (const vec3f *)v38);
  if ( !this->joints[0] )
  {
    v5 = this->carBody;
    *(float *)v38 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carBottomWB_F.x;
    *(float *)&v38[1] = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carBottomWB_F.y;
    v39 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carBottomWB_F.z;
    v6 = ((int (*)(IRigidBody *, float *, int *, int, int, int))v5->localToWorld)(v5, &v40, v38, a4, a3, a2);
    v7 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.carBottomWB_F.x = *(_QWORD *)v6;
    this->dataRelToBody.carBottomWB_F.z = *(float *)(v6 + 8);
    v40 = this->dataRelToWheel.carBottomWB_R.x + this->dataRelToWheel.refPoint.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carBottomWB_R.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carBottomWB_R.z;
    v8 = (int)v7->localToWorld(v7, (vec3f *)v43, (const vec3f *)&v40);
    v9 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.carBottomWB_R.x = *(_QWORD *)v8;
    this->dataRelToBody.carBottomWB_R.z = *(float *)(v8 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carTopWB_F.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carTopWB_F.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carTopWB_F.z;
    v10 = (int)v9->localToWorld(v9, (vec3f *)v43, (const vec3f *)&v40);
    v11 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.carTopWB_F.x = *(_QWORD *)v10;
    this->dataRelToBody.carTopWB_F.z = *(float *)(v10 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carTopWB_R.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carTopWB_R.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carTopWB_R.z;
    v12 = (int)v11->localToWorld(v11, (vec3f *)v43, (const vec3f *)&v40);
    v13 = &this->dataRelToBody.carTopWB_R;
    *(_QWORD *)&this->dataRelToBody.carTopWB_R.x = *(_QWORD *)v12;
    v14 = this->carBody;
    this->dataRelToBody.carTopWB_R.z = *(float *)(v12 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreBottomWB.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreBottomWB.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreBottomWB.z;
    v15 = (int)v14->localToWorld(v14, (vec3f *)v43, (const vec3f *)&v40);
    v16 = this->carBody;
    *(_QWORD *)&this->dataRelToBody.tyreBottomWB.x = *(_QWORD *)v15;
    this->dataRelToBody.tyreBottomWB.z = *(float *)(v15 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreTopWB.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreTopWB.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreTopWB.z;
    v17 = (int)v16->localToWorld(v16, (vec3f *)v43, (const vec3f *)&v40);
    v18 = this->carBody;
    v19 = &this->dataRelToBody.tyreTopWB;
    *(_QWORD *)&this->dataRelToBody.tyreTopWB.x = *(_QWORD *)v17;
    this->dataRelToBody.tyreTopWB.z = *(float *)(v17 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.carSteer.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.carSteer.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.carSteer.z;
    v20 = (int)v18->localToWorld(v18, (vec3f *)v43, (const vec3f *)&v40);
    v21 = this->carBody;
    v22 = &this->dataRelToBody.carSteer;
    *(_QWORD *)&this->dataRelToBody.carSteer.x = *(_QWORD *)v20;
    this->dataRelToBody.carSteer.z = *(float *)(v20 + 8);
    v40 = this->dataRelToWheel.refPoint.x + this->dataRelToWheel.tyreSteer.x;
    v41 = this->dataRelToWheel.refPoint.y + this->dataRelToWheel.tyreSteer.y;
    v42 = this->dataRelToWheel.refPoint.z + this->dataRelToWheel.tyreSteer.z;
    v23 = (int)v21->localToWorld(v21, (vec3f *)v43, (const vec3f *)&v40);
    v24 = &this->dataRelToBody.tyreSteer;
    v25 = *(PhysicsEngine **)(LODWORD(v39) + 408);
    *(_QWORD *)&v24->x = *(_QWORD *)v23;
    v24->z = *(float *)(v23 + 8);
    v26 = PhysicsEngine::getCore(v25);
    v37 = v13;
    v27 = v39;
    *(_DWORD *)(LODWORD(v27) + 76) = v26->createDistanceJoint(
                                       v26,
                                       *(IRigidBody **)(LODWORD(v39) + 48),
                                       *(IRigidBody **)(LODWORD(v39) + 52),
                                       v37,
                                       v19);
    v28 = PhysicsEngine::getCore(*(PhysicsEngine **)(LODWORD(v27) + 408));
    *(_DWORD *)(LODWORD(v27) + 80) = v28->createDistanceJoint(
                                       v28,
                                       *(IRigidBody **)(LODWORD(v27) + 48),
                                       *(IRigidBody **)(LODWORD(v27) + 52),
                                       (const vec3f *)(LODWORD(v27) + 224),
                                       v19);
    v29 = PhysicsEngine::getCore(*(PhysicsEngine **)(LODWORD(v27) + 408));
    *(_DWORD *)(LODWORD(v27) + 84) = v29->createDistanceJoint(
                                       v29,
                                       *(IRigidBody **)(LODWORD(v27) + 48),
                                       *(IRigidBody **)(LODWORD(v27) + 52),
                                       (const vec3f *)(LODWORD(v27) + 260),
                                       (const vec3f *)(LODWORD(v27) + 284));
    v30 = PhysicsEngine::getCore(*(PhysicsEngine **)(LODWORD(v27) + 408));
    *(_DWORD *)(LODWORD(v27) + 88) = v30->createDistanceJoint(
                                       v30,
                                       *(IRigidBody **)(LODWORD(v27) + 48),
                                       *(IRigidBody **)(LODWORD(v27) + 52),
                                       (const vec3f *)(LODWORD(v27) + 248),
                                       (const vec3f *)(LODWORD(v27) + 284));
    v31 = PhysicsEngine::getCore(*(PhysicsEngine **)(LODWORD(v27) + 408));
    *(_DWORD *)(LODWORD(v27) + 92) = v31->createDistanceJoint(
                                       v31,
                                       *(IRigidBody **)(LODWORD(v27) + 48),
                                       *(IRigidBody **)(LODWORD(v27) + 52),
                                       v22,
                                       v24);
    v32 = v22->z - v24->z;
    v33 = (float)((float)((float)(v22->y - v24->y) * (float)(v22->y - v24->y))
                + (float)((float)(v22->x - v24->x) * (float)(v22->x - v24->x)))
        + (float)(v32 * v32);
    v34 = 0.0;
    if ( v33 != 0.0 )
      v34 = fsqrt(v33);
    v35 = *(PhysicsEngine **)(LODWORD(v27) + 408);
    *(float *)(LODWORD(v27) + 412) = v34;
    v36 = PhysicsEngine::getCore(v35);
    *(_DWORD *)(LODWORD(v27) + 96) = ((int (*)(IPhysicsCore *, _DWORD, _DWORD))v36->createBumpJoint)(
                                       v36,
                                       *(_DWORD *)(LODWORD(v27) + 48),
                                       *(_DWORD *)(LODWORD(v27) + 52));
  }
}
double Suspension::getDamage(Suspension *this)
{
  double result; // st7

  if ( this->damageData.maxDamage == 0.0 )
    result = 0.0;
  else
    result = this->damageData.damageAmount / this->damageData.maxDamage;
  return result;
}
Damper *Suspension::getDamper(Suspension *this)
{
  return &this->damper;
}
std::vector<DebugLine> *Suspension::getDebugLines(Suspension *this, std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix)
{
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  DebugLine *v33; // eax
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm5_4
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm5_4
  float v46; // xmm0_4
  DebugLine *v47; // eax
  float v48; // xmm3_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm3_4
  float v59; // xmm0_4
  float v60; // xmm4_4
  float v61; // xmm1_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm5_4
  float v65; // xmm6_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  float v68; // xmm2_4
  float v69; // xmm0_4
  DebugLine *v70; // eax
  float v71; // xmm3_4
  float v72; // xmm5_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  float v75; // xmm1_4
  float v76; // xmm5_4
  const mat44f *v77; // esi
  float v78; // xmm3_4
  float v79; // xmm6_4
  float v80; // xmm0_4
  float v81; // xmm5_4
  float v82; // xmm6_4
  float v83; // xmm2_4
  float v84; // xmm5_4
  float v85; // xmm6_4
  float v86; // xmm0_4
  float v87; // xmm4_4
  float v88; // xmm1_4
  float v89; // xmm6_4
  float v90; // xmm2_4
  float v91; // xmm0_4
  float v92; // xmm2_4
  float v93; // xmm0_4
  DebugLine *v94; // eax
  float v95; // xmm3_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm4_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm6_4
  float v102; // xmm0_4
  float v103; // xmm5_4
  float v104; // xmm2_4
  float v105; // xmm0_4
  float v106; // xmm2_4
  std::vector<DebugLine> *v107; // esi
  DebugLine *v108; // eax
  DebugLine *v109; // eax
  DebugLine v111; // [esp+10h] [ebp-80h] BYREF
  std::vector<DebugLine> *v112; // [esp+3Ch] [ebp-54h]
  int v113; // [esp+40h] [ebp-50h]
  vec4f v114; // [esp+44h] [ebp-4Ch] BYREF
  vec3f ip1; // [esp+54h] [ebp-3Ch] BYREF
  const mat44f *v116; // [esp+60h] [ebp-30h]
  vec4f ic; // [esp+64h] [ebp-2Ch] BYREF
  std::vector<DebugLine> *v118; // [esp+74h] [ebp-1Ch]
  vec3f ip0; // [esp+78h] [ebp-18h] BYREF
  int v120; // [esp+8Ch] [ebp-4h]

  v113 = 0;
  v118 = result;
  v112 = result;
  v116 = bodyMatrix;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v6 = this->dataRelToWheel.tyreBottomWB.y;
  v7 = this->dataRelToWheel.tyreBottomWB.x;
  v8 = hubMatrix->M21;
  v9 = this->dataRelToWheel.tyreBottomWB.z;
  v10 = hubMatrix->M11 * v7;
  v11 = hubMatrix->M12;
  v120 = 0;
  v113 = 1;
  v12 = (float)((float)(v8 * v6) + v10) + (float)(hubMatrix->M31 * v9);
  v13 = hubMatrix->M32 * v9;
  v14 = v9 * hubMatrix->M33;
  v15 = (float)((float)(v11 * v7) + (float)(hubMatrix->M22 * v6)) + v13;
  v16 = hubMatrix->M13 * v7;
  v17 = bodyMatrix->M12;
  v18 = v16 + (float)(v6 * hubMatrix->M23);
  v19 = this->dataRelToBody.carBottomWB_F.x;
  v20 = v15 + hubMatrix->M42;
  v21 = bodyMatrix->M11 * v19;
  ip1.x = v12 + hubMatrix->M41;
  v22 = v18 + v14;
  v23 = this->dataRelToBody.carBottomWB_F.z;
  v24 = this->dataRelToBody.carBottomWB_F.y;
  v25 = v17 * v19;
  v26 = v19 * bodyMatrix->M13;
  v27 = v22 + hubMatrix->M43;
  ip1.y = v20;
  v28 = bodyMatrix->M23;
  ip1.z = v27;
  ic = (vec4f)_xmm;
  v29 = v25 + (float)(v24 * bodyMatrix->M22);
  v30 = v23 * bodyMatrix->M32;
  ip0.x = (float)((float)(v21 + (float)(bodyMatrix->M21 * v24)) + (float)(bodyMatrix->M31 * v23)) + bodyMatrix->M41;
  v31 = v29 + v30;
  v32 = bodyMatrix->M33 * v23;
  ip0.y = v31 + bodyMatrix->M42;
  ip0.z = (float)((float)((float)(v28 * v24) + v26) + v32) + bodyMatrix->M43;
  DebugLine::DebugLine(&v111, &ip0, &ip1, &ic, 0.0);
  std::vector<DebugLine>::push_back(v118, v33);
  v34 = this->dataRelToBody.carBottomWB_R.y;
  v35 = this->dataRelToBody.carBottomWB_R.x;
  v36 = v116->M21;
  v37 = this->dataRelToBody.carBottomWB_R.z;
  v38 = v116->M12;
  ic = (vec4f)_xmm;
  v39 = v116->M11 * v35;
  v40 = v38 * v35;
  v41 = v35 * v116->M13;
  v42 = (float)((float)((float)(v36 * v34) + v39) + (float)(v116->M31 * v37)) + v116->M41;
  v43 = (float)(v40 + (float)(v34 * v116->M22)) + (float)(v37 * v116->M32);
  v44 = v116->M23 * v34;
  ip0.x = v42;
  v45 = v41 + v44;
  v46 = v116->M33 * v37;
  ip0.y = v43 + v116->M42;
  ip0.z = (float)(v45 + v46) + v116->M43;
  DebugLine::DebugLine(&v111, &ip0, &ip1, &ic, 0.0);
  std::vector<DebugLine>::push_back(v118, v47);
  v48 = this->dataRelToWheel.tyreSteer.y;
  v49 = this->dataRelToWheel.tyreSteer.x;
  v50 = hubMatrix->M21;
  v51 = this->dataRelToWheel.tyreSteer.z;
  v52 = v48 * hubMatrix->M22;
  v114 = (vec4f)_xmm;
  v53 = (float)((float)((float)(v50 * v48) + (float)(hubMatrix->M11 * v49)) + (float)(hubMatrix->M31 * v51))
      + hubMatrix->M41;
  v54 = (float)((float)(v52 + (float)(hubMatrix->M12 * v49)) + (float)(v51 * hubMatrix->M32)) + hubMatrix->M42;
  v55 = v51 * hubMatrix->M33;
  v56 = (float)(v49 * hubMatrix->M13) + (float)(v48 * hubMatrix->M23);
  v57 = v116->M11;
  v58 = this->dataRelToBody.carSteer.y;
  v59 = v116->M21 * v58;
  ip0.x = v53;
  v60 = this->dataRelToBody.carSteer.z;
  ip0.y = v54;
  v61 = v116->M23;
  ip0.z = (float)(v56 + v55) + hubMatrix->M43;
  v62 = this->dataRelToBody.carSteer.x;
  v63 = v57 * v62;
  v64 = v62 * v116->M13;
  v65 = (float)((float)(v63 + v59) + (float)(v116->M31 * v60)) + v116->M41;
  v66 = (float)(this->dataRelToBody.carSteer.x * v116->M12) + (float)(v58 * v116->M22);
  v67 = v60 * v116->M32;
  ic.y = v65;
  v68 = v66 + v67;
  v69 = v116->M33 * v60;
  ic.z = v68 + v116->M42;
  ic.w = (float)((float)((float)(v61 * v58) + v64) + v69) + v116->M43;
  DebugLine::DebugLine(&v111, (const vec3f *)&ic.y, &ip0, &v114, 0.0);
  std::vector<DebugLine>::push_back(v118, v70);
  v71 = this->dataRelToWheel.tyreTopWB.y;
  v72 = this->dataRelToWheel.tyreTopWB.x;
  v73 = this->dataRelToWheel.tyreTopWB.z;
  v74 = (float)((float)((float)(hubMatrix->M21 * v71) + (float)(hubMatrix->M11 * v72)) + (float)(hubMatrix->M31 * v73))
      + hubMatrix->M41;
  v75 = (float)((float)((float)(v71 * hubMatrix->M22) + (float)(hubMatrix->M12 * v72)) + (float)(v73 * hubMatrix->M32))
      + hubMatrix->M42;
  v76 = (float)((float)((float)(v72 * hubMatrix->M13) + (float)(v71 * hubMatrix->M23)) + (float)(v73 * hubMatrix->M33))
      + hubMatrix->M43;
  v77 = v116;
  v78 = this->dataRelToBody.carTopWB_F.y;
  v114 = (vec4f)_xmm;
  v79 = v116->M11;
  v80 = v116->M21 * v78;
  ip0.z = v76;
  v81 = this->dataRelToBody.carTopWB_F.x;
  v82 = v79 * v81;
  v83 = v81 * v116->M12;
  v84 = v81 * v116->M13;
  v85 = v82 + v80;
  v86 = v116->M31;
  ip0.x = v74;
  v87 = this->dataRelToBody.carTopWB_F.z;
  ip0.y = v75;
  v88 = v116->M23;
  v89 = (float)(v85 + (float)(v86 * v87)) + v116->M41;
  v90 = v83 + (float)(v78 * v116->M22);
  v91 = v87 * v116->M32;
  ic.y = v89;
  v92 = v90 + v91;
  v93 = v116->M33 * v87;
  ic.z = v92 + v116->M42;
  ic.w = (float)((float)((float)(v88 * v78) + v84) + v93) + v116->M43;
  DebugLine::DebugLine(&v111, (const vec3f *)&ic.y, &ip0, &v114, 0.0);
  std::vector<DebugLine>::push_back(v118, v94);
  v95 = this->dataRelToBody.carTopWB_R.y;
  v96 = this->dataRelToBody.carTopWB_R.x;
  v97 = v77->M11;
  v98 = this->dataRelToBody.carTopWB_R.z;
  v99 = v95 * v77->M22;
  v114 = (vec4f)_xmm;
  v100 = v77->M23;
  v101 = (float)((float)(v97 * v96) + (float)(v95 * v77->M21)) + (float)(v98 * v77->M31);
  v102 = v96 * v77->M12;
  v103 = v96 * v77->M13;
  v104 = (float)(v99 + v102) + (float)(v98 * v77->M32);
  v105 = v77->M33 * v98;
  v106 = v104 + v77->M42;
  ic.y = v101 + v77->M41;
  ic.z = v106;
  ic.w = (float)((float)((float)(v100 * v95) + v103) + v105) + v77->M43;
  DebugLine::DebugLine(&v111, (const vec3f *)&ic.y, &ip0, &v114, 0.0);
  v107 = v118;
  std::vector<DebugLine>::push_back(v118, v108);
  v114 = (vec4f)_xmm;
  DebugLine::DebugLine(&v111, &ip1, &ip0, &v114, 0.0);
  std::vector<DebugLine>::push_back(v107, v109);
  return v107;
}
vec3f *Suspension::getHubAngularVelocity(SuspensionStrut *this, vec3f *result)
{
  this->hub->getAngularVelocity(this->hub, result);
  return result;
}
vec3f *Suspension::getPointVelocity(SuspensionStrut *this, vec3f *result, const vec3f *p)
{
  this->hub->getPointVelocity(this->hub, result, p);
  return result;
}
SuspensionStatus *Suspension::getStatus(Suspension *this)
{
  return &this->status;
}
void __userpurge Suspension::getSteerBasis(Suspension *this@<ecx>, __m128 a2@<xmm6>, vec3f *centre, vec3f *axis)
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

  ((void (*)(IRigidBody *))this->hub->localToWorld)(this->hub);
  ((void (*)(IRigidBody *, float *))this->hub->localToWorld)(this->hub, &p1.y);
  v5 = (__m128)(unsigned int)&this->dataRelToWheel.tyreBottomWB;
  v6 = (__m128)(unsigned int)&p1;
  v7 = (__m128)(unsigned int)&p1;
  v7.m128_f32[0] = COERCE_FLOAT(&p1) - p1.x;
  a2.m128_f32[0] = COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreBottomWB) - v15;
  v8 = _mm_unpacklo_ps(a2, v7).m128_u64[0];
  v9 = COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreTopWB) - p1.y;
  p2.y = v9;
  v10 = fsqrt(
          (float)((float)(v7.m128_f32[0] * v7.m128_f32[0])
                + (float)((float)(COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreBottomWB) - v15)
                        * (float)(COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreBottomWB) - v15)))
        + (float)(p2.y * p2.y));
  if ( v10 != 0.0 )
  {
    *(float *)&v14 = (float)(1.0 / v10) * (float)(COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreBottomWB) - v15);
    *((float *)&v14 + 1) = (float)(1.0 / v10) * *((float *)&v8 + 1);
    v8 = v14;
    v9 = (float)(1.0 / v10) * (float)(COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreTopWB) - p1.y);
  }
  v11 = (float *)v19;
  v6.m128_f32[0] = COERCE_FLOAT(&p1) + p1.x;
  v12 = COERCE_FLOAT((Suspension *)&this->dataRelToWheel.tyreTopWB) + p1.y;
  *v19 = v8;
  v11[2] = v9;
  v13 = v18;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] + v15) * 0.5;
  v6.m128_f32[0] = v6.m128_f32[0] * 0.5;
  *(_QWORD *)v18 = _mm_unpacklo_ps(v5, v6).m128_u64[0];
  v13[2] = v12 * 0.5;
}
double Suspension::getSteerTorque(Suspension *this)
{
  return this->steerTorque;
}
void __userpurge Suspension::loadINI(Suspension *this@<ecx>, __m128 a2@<xmm0>, int index)
{
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const std::wstring *v6; // eax
  __m128 v7; // xmm0
  float v8; // eax
  std::wstring *v9; // edi
  vec3f *v10; // eax
  bool v11; // cf
  vec3f *v12; // eax
  vec3f *v13; // eax
  vec3f *v14; // eax
  vec3f *v15; // eax
  vec3f *v16; // eax
  vec3f *v17; // eax
  vec3f *v18; // eax
  int v19; // xmm2_4
  float v20; // xmm0_4
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
  char v35; // al
  double v36; // st7
  std::wstring *v37; // eax
  double v38; // st7
  int v39; // xmm1_4
  double v40; // st7
  bool v41; // al
  double v42; // st7
  double v43; // st7
  double v44; // st7
  int v45; // eax
  float v46; // [esp+18h] [ebp-150h]
  float v47; // [esp+20h] [ebp-148h]
  float v48; // [esp+24h] [ebp-144h]
  float v49; // [esp+28h] [ebp-140h]
  float v50; // [esp+2Ch] [ebp-13Ch]
  float v51; // [esp+30h] [ebp-138h]
  float v52; // [esp+30h] [ebp-138h]
  int v53; // [esp+34h] [ebp-134h]
  float v54; // [esp+34h] [ebp-134h]
  float v55; // [esp+34h] [ebp-134h]
  float v56; // [esp+34h] [ebp-134h]
  char v57; // [esp+3Bh] [ebp-12Dh]
  bool v58; // [esp+3Bh] [ebp-12Dh]
  std::wstring result; // [esp+3Ch] [ebp-12Ch] BYREF
  std::wstring v60; // [esp+54h] [ebp-114h] BYREF
  INIReader v61; // [esp+6Ch] [ebp-FCh] BYREF
  std::wstring section; // [esp+B0h] [ebp-B8h] BYREF
  std::wstring ptr; // [esp+C8h] [ebp-A0h] BYREF
  std::wstring v64; // [esp+E0h] [ebp-88h] BYREF
  std::wstring v65; // [esp+F8h] [ebp-70h] BYREF
  std::wstring v66; // [esp+110h] [ebp-58h] BYREF
  unsigned __int64 v67; // [esp+128h] [ebp-40h]
  float v68; // [esp+130h] [ebp-38h]
  unsigned __int64 v69; // [esp+134h] [ebp-34h]
  float v70; // [esp+13Ch] [ebp-2Ch]
  std::wstring key; // [esp+140h] [ebp-28h] BYREF
  int v72; // [esp+164h] [ebp-4h]

  v4 = std::operator+<wchar_t>(&result, &this->car->carDataPath, L"suspensions.ini");
  v5 = this->car;
  v72 = 0;
  v6 = Car::getConfigPath(v5, &v60, v4);
  LOBYTE(v72) = 1;
  INIReader::INIReader(&v61, v6);
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  v60._Myres = 7;
  v60._Mysize = 0;
  v60._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"VERSION", 7u);
  LOBYTE(v72) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v72) = 6;
  v53 = INIReader::getInt(&v61, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WHEELBASE", 9u);
  LOBYTE(v72) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v72) = 8;
  v50 = INIReader::getFloat(&v61, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CG_LOCATION", 0xBu);
  LOBYTE(v72) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v72) = 10;
  v48 = INIReader::getFloat(&v61, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v72) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v72) = 12;
  v46 = INIReader::getFloat(&v61, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v72) = 13;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v72) = 14;
  v51 = INIReader::getFloat(&v61, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v72) = 15;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v72) = 16;
  v47 = INIReader::getFloat(&v61, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v72) = 17;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v72) = 18;
  v49 = INIReader::getFloat(&v61, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v72) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  a2.m128_f32[0] = v51;
  v7 = _mm_unpacklo_ps(a2, (__m128)LODWORD(v46));
  v68 = (float)(1.0 - v48) * v50;
  v70 = v68;
  v67 = v7.m128_u64[0];
  v7.m128_f32[0] = v49;
  *(_DWORD *)&key._Bx._Alias[8] = COERCE_UNSIGNED_INT(v48 * v50) ^ _xmm;
  section._Myres = *(_DWORD *)&key._Bx._Alias[8];
  key._Myres = *(_DWORD *)&key._Bx._Alias[8];
  v69 = _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(v51), (__m128)(unsigned int)_xmm), (__m128)LODWORD(v46)).m128_u64[0];
  *(_QWORD *)key._Bx._Buf = _mm_unpacklo_ps(v7, (__m128)LODWORD(v47)).m128_u64[0];
  *(_QWORD *)&key._Bx._Alias[12] = _mm_unpacklo_ps(
                                     _mm_xor_ps((__m128)LODWORD(v49), (__m128)(unsigned int)_xmm),
                                     (__m128)LODWORD(v47)).m128_u64[0];
  ptr._Myres = 7;
  ptr._Mysize = 0;
  ptr._Bx._Buf[0] = 0;
  std::wstring::assign(&ptr, L"FRONT", 5u);
  LOBYTE(v72) = 19;
  v64._Myres = 7;
  v64._Mysize = 0;
  v64._Bx._Buf[0] = 0;
  std::wstring::assign(&v64, L"FRONT", 5u);
  LOBYTE(v72) = 20;
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  std::wstring::assign(&v65, L"REAR", 4u);
  LOBYTE(v72) = 21;
  v66._Myres = 7;
  v66._Mysize = 0;
  v66._Bx._Buf[0] = 0;
  std::wstring::assign(&v66, L"REAR", 4u);
  LOBYTE(v72) = 22;
  v8 = *(&v68 + 3 * index);
  *(_QWORD *)&this->dataRelToWheel.refPoint.x = *(unsigned __int64 *)((char *)&v67 + 12 * index);
  this->dataRelToWheel.refPoint.z = v8;
  std::wstring::wstring(&key, L"WBCAR_TOP_FRONT");
  LOBYTE(v72) = 23;
  v9 = &ptr + index;
  v10 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.carTopWB_F = *v10;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_TOP_REAR");
  LOBYTE(v72) = 24;
  v12 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.carTopWB_R = *v12;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_BOTTOM_FRONT");
  LOBYTE(v72) = 25;
  v13 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.carBottomWB_F = *v13;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_BOTTOM_REAR");
  LOBYTE(v72) = 26;
  v14 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.carBottomWB_R = *v14;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBTYRE_TOP");
  LOBYTE(v72) = 27;
  v15 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.tyreTopWB = *v15;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBTYRE_BOTTOM");
  LOBYTE(v72) = 28;
  v16 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.tyreBottomWB = *v16;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBTYRE_STEER");
  LOBYTE(v72) = 29;
  v17 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.tyreSteer = *v17;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"WBCAR_STEER");
  LOBYTE(v72) = 30;
  v18 = INIReader::getFloat3(&v61, (vec3f *)&section._Bx._Alias[12], v9, &key);
  v11 = key._Myres < 8;
  LOBYTE(v72) = 22;
  this->dataRelToWheel.carSteer = *v18;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  if ( v53 >= 2 )
  {
    std::wstring::wstring(&key, L"RIM_OFFSET");
    LOBYTE(v72) = 31;
    v19 = _xmm;
    v54 = INIReader::getFloat(&v61, v9, &key);
    LODWORD(v20) = LODWORD(v54) ^ _xmm;
    LOBYTE(v72) = 22;
    LODWORD(v52) = LODWORD(v54) ^ _xmm;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v19 = _xmm;
    }
    if ( v20 != 0.0 )
    {
      _printf("APPLYING RIM OFFSET: %f\n", COERCE_FLOAT(LODWORD(v20) ^ v19));
      this->dataRelToWheel.carTopWB_F.x = v52 + this->dataRelToWheel.carTopWB_F.x;
      this->dataRelToWheel.carTopWB_R.x = this->dataRelToWheel.carTopWB_R.x + v52;
      this->dataRelToWheel.carBottomWB_F.x = v52 + this->dataRelToWheel.carBottomWB_F.x;
      this->dataRelToWheel.carBottomWB_R.x = this->dataRelToWheel.carBottomWB_R.x + v52;
      this->dataRelToWheel.tyreTopWB.x = v52 + this->dataRelToWheel.tyreTopWB.x;
      this->dataRelToWheel.tyreBottomWB.x = this->dataRelToWheel.tyreBottomWB.x + v52;
      this->dataRelToWheel.tyreSteer.x = v52 + this->dataRelToWheel.tyreSteer.x;
      this->dataRelToWheel.carSteer.x = this->dataRelToWheel.carSteer.x + v52;
    }
  }
  std::wstring::wstring(&key, L"HUB_MASS");
  LOBYTE(v72) = 32;
  v21 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->dataRelToWheel.hubMass = v21;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"BUMPSTOP_UP");
  LOBYTE(v72) = 33;
  v22 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->bumpStopUp = v22;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"BUMPSTOP_DN");
  LOBYTE(v72) = 34;
  v23 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  v55 = v23;
  LODWORD(this->bumpStopDn) = LODWORD(v55) ^ _xmm;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"ROD_LENGTH");
  LOBYTE(v72) = 35;
  v24 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->rodLength = v24;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"TOE_OUT");
  LOBYTE(v72) = 36;
  v25 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->toeOUT_Linear = v25;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"SPRING_RATE");
  LOBYTE(v72) = 37;
  v26 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->k = v26;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"PROGRESSIVE_SPRING_RATE");
  LOBYTE(v72) = 38;
  v27 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->progressiveK = v27;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_BUMP");
  LOBYTE(v72) = 39;
  v28 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.bumpSlow = v28;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_REBOUND");
  LOBYTE(v72) = 40;
  v29 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.reboundSlow = v29;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_BUMP");
  LOBYTE(v72) = 41;
  v30 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.bumpFast = v30;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_REBOUND");
  LOBYTE(v72) = 42;
  v31 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.reboundFast = v31;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_BUMPTHRESHOLD");
  LOBYTE(v72) = 43;
  v32 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.fastThresholdBump = v32;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMP_FAST_REBOUNDTHRESHOLD");
  LOBYTE(v72) = 44;
  v33 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->damper.fastThresholdRebound = v33;
  LOBYTE(v72) = 22;
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
  LOBYTE(v72) = 45;
  v34 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->bumpStopRate = v34;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  if ( this->bumpStopRate == 0.0 )
    this->bumpStopRate = 500000.0;
  std::wstring::wstring(&key, L"BUMP_STOP_PROGRESSIVE");
  LOBYTE(v72) = 46;
  v35 = INIReader::hasKey(&v61, v9, &key);
  v57 = v35;
  LOBYTE(v72) = 22;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v35 = v57;
  }
  if ( v35 )
  {
    std::wstring::wstring(&key, L"BUMP_STOP_PROGRESSIVE");
    LOBYTE(v72) = 47;
    v36 = INIReader::getFloat(&v61, v9, &key);
    v11 = key._Myres < 8;
    this->bumpStopProgressive = v36;
    LOBYTE(v72) = 22;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    if ( v9->_Myres < 8 )
      v37 = &ptr + index;
    else
      v37 = (std::wstring *)v9->_Bx._Ptr;
    _printf("Using progressive bump rate %f for %S\n", this->bumpStopProgressive, v37->_Bx._Buf);
  }
  std::wstring::wstring(&key, L"STATIC_CAMBER");
  LOBYTE(v72) = 48;
  v38 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  v39 = _xmm;
  LOBYTE(v72) = 22;
  v56 = v38 * 0.017453;
  LODWORD(this->staticCamber) = LODWORD(v56) ^ _xmm;
  if ( !v11 )
  {
    operator delete(key._Bx._Ptr);
    v39 = _xmm;
  }
  if ( index % 2 )
    LODWORD(this->staticCamber) ^= v39;
  std::wstring::wstring(&key, L"PACKER_RANGE");
  LOBYTE(v72) = 49;
  v40 = INIReader::getFloat(&v61, v9, &key);
  v11 = key._Myres < 8;
  this->packerRange = v40;
  LOBYTE(v72) = 22;
  if ( !v11 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"DAMAGE");
  LOBYTE(v72) = 50;
  v41 = INIReader::hasSection(&v61, &key);
  v58 = v41;
  LOBYTE(v72) = 22;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v41 = v58;
  }
  if ( v41 )
  {
    std::wstring::wstring(&section, L"MIN_VELOCITY");
    LOBYTE(v72) = 51;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v72) = 52;
    v42 = INIReader::getFloat(&v61, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.minVelocity = v42;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v72) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"GAIN");
    LOBYTE(v72) = 53;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v72) = 54;
    v43 = INIReader::getFloat(&v61, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.damageGain = v43;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v72) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"MAX_DAMAGE");
    LOBYTE(v72) = 55;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v72) = 56;
    v44 = INIReader::getFloat(&v61, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.maxDamage = v44;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v72) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"DEBUG_LOG");
    LOBYTE(v72) = 57;
    std::wstring::wstring(&key, L"DAMAGE");
    LOBYTE(v72) = 58;
    v45 = INIReader::getInt(&v61, &key, &section);
    v11 = key._Myres < 8;
    this->damageData.isDebug = v45 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v72) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  std::wstring::wstring(&key, L"RIGIDITY");
  LOBYTE(v72) = 59;
  INIReader::hasSection(&v61, &key);
  v72 = 22;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v72) = 4;
  `eh vector destructor iterator'(&ptr, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  v72 = -1;
  INIReader::~INIReader(&v61);
}
void Suspension::resetDamage(Suspension *this)
{
  this->damageData.damageAmount = 0.0;
}
void Suspension::setDamage(Suspension *this, float amount)
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
void Suspension::setERPCFM(Suspension *this, float erp, float cfm)
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
void Suspension::setSteerLengthOffset(Suspension *this, float o)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  PhysicsEngine *v5; // ecx
  float v6; // xmm0_4
  __m128 v7; // xmm2
  float v8; // eax
  IPhysicsCore *v9; // eax

  if ( (dword_186F2CC & 1) == 0 )
  {
    perfCounter_47.name = "Suspension::setSteerLengthOffset";
    dword_186F2CC |= 1u;
    perfCounter_47.group = Physics;
    perfCounter_47.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Suspension::setSteerLengthOffset" | 0xFF000000;
  }
  v3 = this->dataRelToWheel.refPoint.x;
  v4 = 0.0;
  if ( v3 <= 0.0 )
  {
    if ( v3 < 0.0 )
      v4 = FLOAT_N1_0;
  }
  else
  {
    v4 = FLOAT_1_0;
  }
  v5 = this->physicsEngine;
  v6 = this->toeOUT_Linear * v4;
  v7 = (__m128)LODWORD(this->baseCarSteerPosition.x);
  v8 = this->baseCarSteerPosition.z;
  v7.m128_f32[0] = v7.m128_f32[0]
                 + (float)((float)((float)(this->damageData.damageDirection * this->damageData.damageAmount) + o) + v6);
  *(_QWORD *)&this->dataRelToBody.carSteer.x = _mm_unpacklo_ps(v7, (__m128)LODWORD(this->baseCarSteerPosition.y)).m128_u64[0];
  this->dataRelToBody.carSteer.z = v8;
  v9 = PhysicsEngine::getCore(v5);
  v9->reseatDistanceJointLocal(v9, this->joints[4], &this->dataRelToBody.carSteer, &this->dataRelToWheel.tyreSteer);
}
void Suspension::step(Suspension *this, float dt)
{
  IRigidBody *v3; // ecx
  float *v4; // eax
  bool v5; // zf
  float currentTravel; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  Suspension_vtbl *v15; // eax
  IRigidBody *v16; // ecx
  double v17; // st7
  Suspension_vtbl *v18; // eax
  IRigidBody *v19; // ecx
  double v20; // st7
  float v21; // xmm0_4
  Suspension_vtbl *v22; // eax
  IRigidBody *v23; // ecx
  float v24; // xmm3_4
  float v25; // xmm1_4
  Suspension_vtbl *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm1_4
  IRigidBody *v29; // ecx
  float v30; // xmm3_4
  Suspension_vtbl *v31; // eax
  float v32; // xmm0_4
  IRigidBody *v33; // ecx
  char v34[64]; // [esp+48h] [ebp-98h] BYREF
  int v35[3]; // [esp+88h] [ebp-58h] BYREF
  int v36; // [esp+94h] [ebp-4Ch] BYREF
  float v37; // [esp+98h] [ebp-48h]
  vec3f v38; // [esp+A0h] [ebp-40h] BYREF
  float v39; // [esp+ACh] [ebp-34h] BYREF
  float v40; // [esp+B0h] [ebp-30h]
  float v41; // [esp+B4h] [ebp-2Ch]
  float v42; // [esp+B8h] [ebp-28h] BYREF
  float v43; // [esp+BCh] [ebp-24h]
  float v44; // [esp+C0h] [ebp-20h]
  float v45; // [esp+C4h] [ebp-1Ch]
  float v46; // [esp+C8h] [ebp-18h]
  float v47; // [esp+CCh] [ebp-14h]
  float v48; // [esp+D0h] [ebp-10h]
  float v49; // [esp+D4h] [ebp-Ch] BYREF
  float v50; // [esp+D8h] [ebp-8h]
  float v51; // [esp+DCh] [ebp-4h]
  float dta; // [esp+E4h] [ebp+4h]
  float dtb; // [esp+E4h] [ebp+4h]
  float dtc; // [esp+E4h] [ebp+4h]
  float dtd; // [esp+E4h] [ebp+4h]

  if ( (dword_186F2BC & 1) == 0 )
  {
    perfCounter_46.name = "Suspension::step";
    dword_186F2BC |= 1u;
    perfCounter_46.group = Physics;
    perfCounter_46.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Suspension::step" | 0xFF000000;
  }
  v3 = this->hub;
  this->steerTorque = 0.0;
  ((void (*)(IRigidBody *, vec3f *, _DWORD))v3->getPosition)(v3, &v38, 0);
  this->carBody->worldToLocal(this->carBody, (vec3f *)&v36, &v38);
  v4 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->carBody->getWorldMatrix)(this->carBody, v34, 0);
  v5 = !this->useActiveActuator;
  currentTravel = v37 - this->dataRelToWheel.refPoint.y;
  v7 = v4[4];
  v8 = v4[5];
  v9 = v4[6];
  v10 = this->rodLength + currentTravel;
  v46 = v7;
  v47 = v8;
  v45 = v9;
  v48 = currentTravel;
  this->status.travel = v10;
  if ( v5 )
  {
    v11 = this->packerRange;
    v12 = this->k;
    v13 = (float)((float)(this->progressiveK * v10) + v12) * v10;
    dta = v13;
    if ( v11 != 0.0 && v10 > v11 && v12 != 0.0 )
    {
      v13 = (float)((float)((float)(this->bumpStopProgressive * (float)(v10 - v11)) + this->bumpStopRate)
                  * (float)(v10 - v11))
          + v13;
      dta = v13;
    }
    if ( v13 > 0.0 )
    {
      LODWORD(v14) = LODWORD(v13) ^ _xmm;
      v15 = this->__vftable;
      v39 = v7 * v14;
      v40 = v8 * v14;
      v41 = v9 * v14;
      v15->addForceAtPos(this, (const vec3f *)&v39, &v38, 0, 0);
      v16 = this->carBody;
      v39 = 0.0;
      v40 = dta;
      v41 = 0.0;
      v16->addLocalForceAtLocalPos(v16, (const vec3f *)&v39, &this->dataRelToWheel.refPoint);
    }
    this->hub->getVelocity(this->hub, (vec3f *)v35);
    this->carBody->getLocalPointVelocity(this->carBody, (vec3f *)&v49, &this->dataRelToWheel.refPoint);
    dtb = (float)((float)((float)(*(float *)&v35[1] - v50) * v47) + (float)((float)(*(float *)v35 - v49) * v46))
        + (float)((float)(*(float *)&v35[2] - v51) * v45);
    v17 = Damper::getForce(&this->damper, dtb);
    v18 = this->__vftable;
    this->status.damperSpeedMS = dtb;
    v48 = v17;
    v42 = v46 * v48;
    v43 = v47 * v48;
    v44 = v45 * v48;
    v18->addForceAtPos(this, (const vec3f *)&v42, &v38, 0, 0);
    v19 = this->carBody;
    LODWORD(v39) = LODWORD(v42) ^ _xmm;
    LODWORD(v40) = LODWORD(v43) ^ _xmm;
    LODWORD(v41) = LODWORD(v44) ^ _xmm;
    v19->addForceAtLocalPos(v19, (const vec3f *)&v39, &this->dataRelToWheel.refPoint);
  }
  else
  {
    this->activeActuator.targetTravel = 0.0;
    v20 = ActiveActuator::eval(&this->activeActuator, dt, currentTravel);
    v21 = v46;
    dtc = v20;
    this->car->antirollBars[0].k = 0.0;
    this->car->antirollBars[1].k = 0.0;
    v22 = this->__vftable;
    v42 = v21 * dtc;
    v43 = v47 * dtc;
    v44 = v45 * dtc;
    v22->addForceAtPos(this, (const vec3f *)&v42, &v38, 0, 0);
    v23 = this->carBody;
    LODWORD(v49) = LODWORD(v42) ^ _xmm;
    LODWORD(v50) = LODWORD(v43) ^ _xmm;
    LODWORD(v51) = LODWORD(v44) ^ _xmm;
    v23->addForceAtLocalPos(v23, (const vec3f *)&v49, &this->dataRelToWheel.refPoint);
    this->status.travel = v48;
  }
  v24 = this->bumpStopUp;
  v25 = v37 - this->dataRelToWheel.refPoint.y;
  v48 = v25;
  if ( v24 != 0.0 && v25 > v24 && this->k != 0.0 )
  {
    v26 = this->__vftable;
    v27 = (float)((float)(this->bumpStopProgressive * (float)(v25 - v24)) + this->bumpStopRate) * (float)(v25 - v24);
    dtd = v27;
    LODWORD(v28) = LODWORD(v27) ^ _xmm;
    v49 = v28 * v46;
    v50 = v47 * v28;
    v51 = v45 * v28;
    v26->addForceAtPos(this, (const vec3f *)&v49, &v38, 0, 0);
    v29 = this->carBody;
    v49 = 0.0;
    v50 = dtd;
    v51 = 0.0;
    v29->addLocalForceAtLocalPos(v29, (const vec3f *)&v49, (const vec3f *)&v36);
    v25 = v48;
  }
  v30 = this->bumpStopDn;
  if ( v30 != 0.0 && v30 > v25 && this->k != 0.0 )
  {
    v31 = this->__vftable;
    v32 = (float)((float)(this->bumpStopProgressive * (float)(v25 - v30)) + this->bumpStopRate) * (float)(v25 - v30);
    v49 = COERCE_FLOAT(LODWORD(v32) ^ _xmm) * v46;
    v50 = v47 * COERCE_FLOAT(LODWORD(v32) ^ _xmm);
    v51 = v45 * COERCE_FLOAT(LODWORD(v32) ^ _xmm);
    v31->addForceAtPos(this, (const vec3f *)&v49, &v38, 0, 0);
    v33 = this->carBody;
    v49 = 0.0;
    v50 = v32;
    v51 = 0.0;
    v33->addLocalForceAtLocalPos(v33, (const vec3f *)&v49, (const vec3f *)&v36);
  }
}
double Suspension::getK(SuspensionStrut *this)
{
  return this->k;
}
void Suspension::stop(SuspensionStrut *this)
{
  ((void (*)(IRigidBody *, int))this->hub->stop)(this->hub, 1065353216);
}
